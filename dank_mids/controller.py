
import logging
from collections import defaultdict
from contextlib import suppress
from functools import lru_cache
from typing import Any, DefaultDict, List, Literal, Optional, Set, Union

import eth_retry
from eth_typing import BlockNumber, ChecksumAddress
from eth_utils import to_checksum_address
from msgspec import Struct
from multicall.constants import MULTICALL2_ADDRESSES, MULTICALL_ADDRESSES
from multicall.multicall import NotSoBrightBatcher
from web3 import Web3
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids import _debugging, constants
from dank_mids._batch import DankBatch
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import DankMidsInternalError
from dank_mids._requests import JSONRPCBatch, Multicall, RPCRequest, eth_call
from dank_mids._uid import UIDGenerator, _AlertingRLock
from dank_mids.helpers import _codec, _helpers, _session
from dank_mids.semaphores import _MethodQueues, _MethodSemaphores, BlockSemaphore
from dank_mids.types import (BlockId, ChainId, PartialRequest, RawResponse,
                             Request)

try:
    from multicall.constants import MULTICALL3_ADDRESSES
except ImportError:
    MULTICALL3_ADDRESSES = {}

logger = logging.getLogger(__name__)

instances: DefaultDict[ChainId, List["DankMiddlewareController"]] = defaultdict(list)

def _sync_w3_from_async(w3: Web3) -> Web3:
    assert w3.eth.is_async and isinstance(w3.provider, AsyncBaseProvider), "Dank Middleware can only be applied to an asycnhronous Web3 instance."
    sync_provider = HTTPProvider(w3.provider.endpoint_uri)
    sync_w3: Web3 = Web3(provider = sync_provider)
    # We can't pickle middlewares to send to process executor.
    # The call has already passed thru all middlewares on the user's Web3 instance.
    sync_w3.middleware_onion.clear()
    sync_w3.provider.middlewares = ()
    return sync_w3


class DankMiddlewareController:
    def __init__(self, w3: Web3) -> None:
        logger.info('Dank Middleware initializing... Strap on your rocket boots...')

        self.w3: Web3 = w3
        """The Web3 instance used to make rpc requests."""

        if _helpers.w3_version_major >= 6:
            self.__setup_attrdict_middleware()

        self.sync_w3 = _sync_w3_from_async(w3)
        """A sync Web3 instance connected to the same rpc, used to make calls during init."""

        self.chain_id = self.sync_w3.eth.chain_id
        """The chainid for the currently connected rpc."""

        self.client_version: str = self.sync_w3.client_version if _helpers.w3_version_major >= 6 else self.sync_w3.clientVersion  # type: ignore [attr-defined]
        """The client version for the currently connected rpc."""

        # NOTE: We need this mutable for node types that require the full jsonrpc spec
        self.request_type = Request if ENVS.USE_FULL_REQUEST or "reth" in self.client_version else PartialRequest
        """The Struct class the controller will use to encode requests."""

        self._time_of_request_type_change: Union[int, float] = 0
        """The time at which the request type was automatically updated by dank's internals. Zero if never updated after init."""

        # NOTE: Ganache does not support state override. Neither does Gnosis Chain.
        self.state_override_not_supported: bool = ENVS.GANACHE_FORK or self.chain_id == 100  # type: ignore [assignment]
        """A boolean that indicates whether the connected rpc supports state override functionality."""

        self.endpoint = self.w3.provider.endpoint_uri  # type: ignore [attr-defined]
        """The uri for the connected rpc."""

        self._sort_calls = "tenderly" in self.endpoint or "chainstack" in self.endpoint
        """A boolean that indicates whether calls must be sorted by id in order for dank to work with the connected rpc."""

        if "tenderly" in self.endpoint and ENVS.MAX_JSONRPC_BATCH_SIZE > 10:  # type: ignore [operator]
            logger.info("max jsonrpc batch size for tenderly is 10, overriding existing max")
            self.set_batch_size_limit(10)
            
        self._instance: int = sum(len(_instances) for _instances in instances.values())
        instances[self.chain_id].append(self)  # type: ignore

        multicall = MULTICALL_ADDRESSES.get(self.chain_id)
        multicall2 = MULTICALL2_ADDRESSES.get(self.chain_id)
        multicall3 = MULTICALL3_ADDRESSES.get(self.chain_id)
        if multicall2 is None and multicall3 is None:
            raise NotImplementedError("Dank Mids currently does not support this network.\nTo add support, you just need to submit a PR adding the appropriate multicall contract addresses to this file:\nhttps://github.com/banteg/multicall.py/blob/master/multicall/constants.py")
        
        self.mc2 = _MulticallContract(
            address = to_checksum_address(multicall2), 
            # TODO: copypasta deploy block dict
            deploy_block = constants.MULTICALL3_DEPLOY_BLOCKS.get(self.chain_id),
            bytecode = constants.MULTICALL2_OVERRIDE_CODE,
        ) if multicall2 else None
        
        self.mc3 = _MulticallContract(
            address = to_checksum_address(multicall3), 
            # TODO: copypasta deploy block dict
            deploy_block = constants.MULTICALL3_DEPLOY_BLOCKS.get(self.chain_id),
            bytecode = constants.MULTICALL3_OVERRIDE_CODE,
        ) if multicall3 else None
                    
        self.no_multicall: Set[ChecksumAddress] = set()
        """A set of addresses that have issues when called from the multicall contract. Calls to these contracts will not be batched in multicalls."""

        if multicall:
            self.no_multicall.add(to_checksum_address(multicall))
        if self.mc2:
            self.no_multicall.add(self.mc2.address)
        if self.mc3:
            self.no_multicall.add(self.mc3.address)
        
        self.method_semaphores = _MethodSemaphores(self)  # TODO: refactor this out
        self.eth_call_semaphores: BlockSemaphore = self.method_semaphores["eth_call"]  # type: ignore [assignment]
        # semaphores soon to be deprecated for smart queue
        self.method_queues = _MethodQueues(self)
        self.batcher = NotSoBrightBatcher()
        self.batcher.step = ENVS.MAX_MULTICALL_SIZE  # type: ignore [attr-defined]

        self.call_uid = UIDGenerator()
        self.multicall_uid: UIDGenerator = UIDGenerator()
        self.request_uid: UIDGenerator = UIDGenerator()
        self.jsonrpc_batch_uid: UIDGenerator = UIDGenerator()
        self.pools_closed_lock = _AlertingRLock(name='pools closed')

        self.pending_eth_calls: DefaultDict[BlockId, Multicall] = defaultdict(lambda: Multicall(self))
        """A dictionary of pending Multicalls by block. The Multicalls hold all pending eth_calls."""

        self.pending_rpc_calls = JSONRPCBatch(self)
        """A JSONRPCBatch containing all pending rpc requests."""
    
    def __repr__(self) -> str:
        return f"<DankMiddlewareController instance={self._instance} chain={self.chain_id} endpoint={self.endpoint}>"

    async def __call__(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        
        # eth_call go thru a specialized Semaphore and other methods pass thru unblocked
        if method == "eth_call":
            async with self.eth_call_semaphores[params[1]]:
                # create a strong ref to the call that will be held until the caller completes or is cancelled
                logger.debug(f'making {self.request_type.__name__} {method} with params {params}')
                if params[0]["to"] in self.no_multicall:
                    return await RPCRequest(self, method, params)
                return await eth_call(self, params)

        # some methods go thru a SmartProcessingQueue, we check those next
        queue = self.method_queues[method]
        logger.debug(f'making {self.request_type.__name__} {method} with params {params}')

        # no queue, we can make the request normally
        if queue is None:
            return await RPCRequest(self, method, params)
        
        # queue found, queue up the call and await the future
        try:
            # NOTE: is this a strong enough ref? 
            return await queue(self, method, params)
        except TypeError as e:
            if "unhashable type" not in str(e):
                raise
        return await queue(self, method, _helpers._make_hashable(params))
    
    @eth_retry.auto_retry
    async def make_request(self, method: str, params: List[Any], request_id: Optional[int] = None) -> RawResponse:
        request = self.request_type(method=method, params=params, id=request_id or self.call_uid.next)
        try:
            return await _session.post(self.endpoint, data=request, loads=_codec.decode_raw)
        except Exception as e:
            if ENVS.DEBUG:
                _debugging.failures.record(self.chain_id, e, "eth_call" if method == "eth_call" else "RPCRequest", "unknown", "unknown", request.data)
            raise

    async def execute_batch(self) -> None:
        with self.pools_closed_lock:  # Do we really need this?  # NOTE: yes we do
            multicalls = dict(self.pending_eth_calls)
            self.pending_eth_calls.clear()
            self.num_pending_eth_calls = 0
            rpc_calls = self.pending_rpc_calls[:]
            self.pending_rpc_calls = JSONRPCBatch(self)
        demo_logger.info(f'executing dank batch (current cid: {self.call_uid.latest})')  # type: ignore
        batch = DankBatch(self, multicalls, rpc_calls)
        await batch
        demo_logger.info(f'{batch} done')

    @property
    def queue_is_full(self) -> bool:
        with self.pools_closed_lock:
            if ENVS.OPERATION_MODE.infura:  # type: ignore [attr-defined]
                return sum(len(call) for call in self.pending_rpc_calls) >= ENVS.MAX_JSONRPC_BATCH_SIZE  # type: ignore [attr-defined,operator]
            eth_calls = sum(len(calls) for calls in self.pending_eth_calls.values())
            other_calls = sum(len(call) for call in self.pending_rpc_calls)
            return eth_calls + other_calls >= self.batcher.step
    
    def early_start(self):
        """Used to start all queued calls when we have enough for a full batch"""
        with self.pools_closed_lock:
            self.pending_rpc_calls.extend(self.pending_eth_calls.values(), skip_check=True)
            self.pending_eth_calls.clear()
            self.pending_rpc_calls.start()
    
    def reduce_multicall_size(self, num_calls: int) -> None:
        self._reduce_chunk_size(num_calls, "multicall")
    
    def reduce_batch_size(self, num_calls: int) -> None:
        self._reduce_chunk_size(num_calls, "batch")
    
    def _reduce_chunk_size(self, num_calls: int, chunk_name: Literal["multicall", "batch"]) -> None:
        new_chunk_size = round(num_calls * 0.99) if num_calls >= 100 else num_calls - 1
        if new_chunk_size < 30:
            logger.warning(f"your {chunk_name} batch size is really low, did you have some connection issue earlier? You might want to restart your script. {chunk_name} chunk size will not be further lowered.")
            return
        # NOTE: We need the 2nd check because one of the other calls in a batch might have already reduced the chunk size
        if chunk_name == "batch":
            self.set_batch_size_limit(new_chunk_size)
            logger.info("The failed batch had %s calls", num_calls)
            return
        elif chunk_name == "multicall":
            self.set_multicall_size_limit(new_chunk_size)
            logger.info("The failed multicall had %s calls", num_calls)
            return
        raise DankMidsInternalError(ValueError(f"chunk name {chunk_name} is invalid"))
    
    def set_multicall_size_limit(self, new_limit: int) -> None:
        existing_limit = self.batcher.step
        if new_limit < existing_limit:
            self.batcher.step = new_limit
            logger.warning("multicall size limit reduced from %s to %s", existing_limit, new_limit)
        else:
            logger.info("new multicall size limit %s is not lower than existing limit %s", new_limit, existing_limit)
            
    def set_batch_size_limit(self, new_limit: int) -> None:
        existing_limit = ENVS.MAX_JSONRPC_BATCH_SIZE  # type: ignore [attr-defined]
        if new_limit < existing_limit:  # type: ignore [operator]
            ENVS.MAX_JSONRPC_BATCH_SIZE = new_limit  # type: ignore [attr-defined,assignment]
            logger.warning("jsonrpc batch size limit reduced from %s to %s", existing_limit, new_limit)
        else:
            logger.info("new jsonrpc batch size limit %s is not lower than existing limit %s", new_limit, int(existing_limit))  # type: ignore [call-overload]
    
    @lru_cache(maxsize=1024)
    def _select_mcall_target_for_block(self, block) -> "_MulticallContract":
        if block == 'latest':
            return self.mc3 or self.mc2  # type: ignore [return-value]
        if self.mc3 and not self.mc3.needs_override_code_for_block(block):
            return self.mc3
        # We don't care if mc2 needs override code, mc2 override code is shorter
        return self.mc2 or self.mc3  # type: ignore [return-value]
    
    def __setup_attrdict_middleware(self) -> None:
        """This will only run for web3 versions > 6.0. It runs one time when the instance is initialized."""
        from web3.middleware import async_attrdict_middleware  # type: ignore [attr-defined]
        try:
            self.w3.middleware_onion.add(async_attrdict_middleware)
        except ValueError as e:
            if str(e) != "You can't add the same un-named instance twice":
                raise
            # NOTE: the web3 instance already has the middleware


class _MulticallContract(Struct):
    address: ChecksumAddress
    deploy_block: Optional[BlockNumber]
    bytecode: str
    
    @lru_cache(maxsize=1024)
    def needs_override_code_for_block(self, block: BlockNumber) -> bool:
        if block == 'latest':
            return False
        if self.deploy_block is None:
            return True
        if isinstance(block, str):
            block = int(block, 16)
        return block < self.deploy_block
    
    def __hash__(self) -> int:
        return hash(self.address)
