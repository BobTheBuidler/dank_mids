
import logging
from collections import defaultdict
from functools import lru_cache
from typing import Any, Awaitable, DefaultDict, List, Literal, Optional

from eth_utils import to_checksum_address
from msgspec import Struct
from multicall.constants import MULTICALL2_ADDRESSES, MULTICALL_ADDRESSES
from multicall.multicall import NotSoBrightBatcher
from web3 import Web3
from web3.types import RPCEndpoint, RPCResponse

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids import constants
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import DankMidsInternalError
from dank_mids.batch import DankBatch
from dank_mids.helpers import decode, session
from dank_mids.provider import DankProvider
from dank_mids.requests import JSONRPCBatch, Multicall, RPCRequest, eth_call
from dank_mids.semaphores import MethodSemaphores
from dank_mids.types import BlockId, ChainId
from dank_mids.uid import UIDGenerator, _AlertingRLock

try:
    from multicall.constants import MULTICALL3_ADDRESSES
except ImportError:
    MULTICALL3_ADDRESSES = {}

logger = logging.getLogger(__name__)

instances: DefaultDict[ChainId, List["DankMiddlewareController"]] = defaultdict(list)


class DankMiddlewareController:
    def __init__(self, w3: Web3) -> None:
        logger.info('Dank Middleware initializing... Strap on your rocket boots...')
        self.provider = DankProvider(self, w3)
        self.chain_id = self.provider.chain_id
        self.state_override_not_supported: bool = ENVS.GANACHE_FORK or self.chain_id == 100  # Gnosis Chain does not support state override.
        
        self._instance: int = sum(len(_instances) for _instances in instances.values())
        instances[self.chain_id].append(self)  # type: ignore

        multicall = MULTICALL_ADDRESSES.get(self.chain_id)
        multicall2 = MULTICALL2_ADDRESSES.get(self.chain_id)
        multicall3 = MULTICALL3_ADDRESSES.get(self.chain_id)
        if multicall2 is None and multicall3 is None:
            raise NotImplementedError("Dank Mids currently does not support this network.\nTo add support, you just need to submit a PR adding the appropriate multicall contract addresses to this file:\nhttps://github.com/banteg/multicall.py/blob/master/multicall/constants.py")
        
        self.mc2 = MulticallContract(
            address = to_checksum_address(multicall2), 
            # TODO: copypasta deploy block dict
            deploy_block = constants.MULTICALL3_DEPLOY_BLOCKS.get(self.chain_id),
            bytecode = constants.MULTICALL2_OVERRIDE_CODE,
        ) if multicall2 else None
        
        self.mc3 = MulticallContract(
            address = to_checksum_address(multicall3), 
            # TODO: copypasta deploy block dict
            deploy_block = constants.MULTICALL3_DEPLOY_BLOCKS.get(self.chain_id),
            bytecode = constants.MULTICALL3_OVERRIDE_CODE,
        ) if multicall3 else None
                    
        self.no_multicall = set()
        if multicall:
            self.no_multicall.add(to_checksum_address(multicall))
        if self.mc2:
            self.no_multicall.add(self.mc2.address)
        if self.mc3:
            self.no_multicall.add(self.mc3.address)
        
        self.method_semaphores = MethodSemaphores(self)
        self.batcher = NotSoBrightBatcher()

        self.call_uid = UIDGenerator()
        self.multicall_uid: UIDGenerator = UIDGenerator()
        self.request_uid: UIDGenerator = UIDGenerator()
        self.jsonrpc_batch_uid: UIDGenerator = UIDGenerator()
        self.pools_closed_lock = _AlertingRLock(name='pools closed')

        self.pending_eth_calls: DefaultDict[BlockId, Multicall] = defaultdict(lambda: Multicall(self))
        self.pending_rpc_calls = JSONRPCBatch(self)
    
    def __repr__(self) -> str:
        return f"<DankMiddlewareController instance={self._instance} chain={self.chain_id} provider={self.provider}>"

    async def __call__(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        call_semaphore = self.method_semaphores[method][params[1]] if method == "eth_call" else self.method_semaphores[method]
        async with call_semaphore:
            await self.pools_open
            logger.debug(f'making {self.provider._request_type.__name__} {method} with params {params}')
            call = eth_call(self, params) if method == "eth_call" and params[0]["to"] not in self.no_multicall else RPCRequest(self, method, params)
            return await call

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
    def pools_open(self) -> Awaitable[bool]:
        return self.provider._pools_open.wait()

    @property
    def queue_is_full(self) -> bool:
        with self.pools_closed_lock:
            if ENVS.OPERATION_MODE.infura:
                return sum(len(call) for call in self.pending_rpc_calls) >= ENVS.MAX_JSONRPC_BATCH_SIZE
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
        self._reduce_chunk_size(num_calls, "jsonrpc batch")
    
    def _reduce_chunk_size(self, num_calls: int, chunk_name: Literal["multicall", "jsonrpc"]) -> None:
        new_chunk_size = round(num_calls * 0.99) if num_calls >= 100 else num_calls - 1
        if new_chunk_size < 30:
            logger.warning(f"your {chunk_name} batch size is really low, did you have some connection issue earlier? You might want to restart your script. {chunk_name} chunk size will not be further lowered.")
            return
        # NOTE: We need the 2nd check because one of the other calls in a batch might have already reduced the chunk size
        if chunk_name == "jsonrpc batch":
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
        existing_limit = ENVS.MAX_JSONRPC_BATCH_SIZE
        if new_limit < existing_limit:
            ENVS.MAX_JSONRPC_BATCH_SIZE = new_limit
            logger.warning("jsonrpc batch size limit reduced from %s to %s", existing_limit, new_limit)
        else:
            logger.info("new jsonrpc batch size limit %s is not lower than existing limit %s", new_limit, int(existing_limit))
    
    @lru_cache(maxsize=1024)
    def _select_mcall_target_for_block(self, block) -> "MulticallContract":
        if block == 'latest':
            return self.mc3 if self.mc3 else self.mc2
        if self.mc3 and not self.mc3.needs_override_code_for_block(block):
            return self.mc3
        if self.mc2:
            # We don't care if mc2 needs override code, mc2 override code is shorter
            return self.mc2
        return self.mc3

class MulticallContract(Struct):
    address: str
    deploy_block: Optional[int]
    bytecode: str
    
    @lru_cache(maxsize=1024)
    def needs_override_code_for_block(self, block: BlockId) -> bool:
        if block == 'latest':
            return False
        if self.deploy_block is None:
            return True
        if isinstance(block, str):
            block = int(block, 16)
        return block < self.deploy_block
    
    def __hash__(self) -> int:
        return hash(self.address)