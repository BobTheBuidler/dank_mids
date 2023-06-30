
import logging
import threading
from collections import defaultdict
from typing import Any, DefaultDict, List, Optional

import eth_retry
from eth_utils import to_checksum_address
from multicall.constants import MULTICALL2_ADDRESSES, MULTICALL_ADDRESSES
from multicall.multicall import NotSoBrightBatcher
from web3 import Web3
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse

from dank_mids import _config
from dank_mids._demo_mode import demo_logger
from dank_mids.batch import DankBatch
from dank_mids.helpers import decode, session
from dank_mids.helpers.semaphore import method_semaphores
from dank_mids.requests import JSONRPCBatch, Multicall, RPCRequest, eth_call
from dank_mids.types import BlockId, ChainId, RawResponse, Request, PartialRequest
from dank_mids.uid import UIDGenerator

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
        self.sync_w3 = _sync_w3_from_async(w3)

        self.chain_id = self.sync_w3.eth.chain_id
        self.request_type = Request if self.chain_id == 100 else PartialRequest
        self.state_override_not_supported: bool = _config.GANACHE_FORK or self.chain_id == 100  # Gnosis Chain does not support state override.

        self.endpoint = self.w3.provider.endpoint_uri
        if "tenderly" in self.endpoint:
            # NOTE: Tenderly does funky things sometimes
            logger.warning(
                "We see you're using a tenderly rpc.\n" +
                "There is a known conflict between dank and tenderly which causes issues not present with other providers.\n" + 
                "Your milage may vary. Debugging efforts welcome."
            )

        multicall = MULTICALL_ADDRESSES.get(self.chain_id)
        multicall2 = MULTICALL2_ADDRESSES.get(self.chain_id)
        if multicall2 is None:
            raise NotImplementedError("Dank Mids currently does not support this network.\nTo add support, you just need to submit a PR adding the appropriate multicall contract addresses to this file:\nhttps://github.com/banteg/multicall.py/blob/master/multicall/constants.py")
        self.multicall2 = to_checksum_address(multicall2)
        self.no_multicall = {self.multicall2} if multicall is None else {self.multicall2, to_checksum_address(multicall)}

        self.batcher = NotSoBrightBatcher()

        self.call_uid = UIDGenerator()
        self.multicall_uid: UIDGenerator = UIDGenerator()
        self.request_uid: UIDGenerator = UIDGenerator()
        self.jsonrpc_batch_uid: UIDGenerator = UIDGenerator()
        self.pools_closed_lock = self.call_uid.lock

        self.pending_eth_calls: DefaultDict[BlockId, Multicall] = defaultdict(lambda: Multicall(self))
        self.pending_rpc_calls = JSONRPCBatch(self)

        self._instance: int = sum(len(_instances) for _instances in instances.values())
        instances[self.chain_id].append(self)  # type: ignore
    
    def __repr__(self) -> str:
        return f"<DankMiddlewareController instance={self._instance} chain={self.chain_id} endpoint={self.endpoint}>"

    async def __call__(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        async with method_semaphores[method]:
            if method == "eth_call" and params[0]["to"] not in self.no_multicall:
                return await eth_call(self, params)
            return await RPCRequest(self, method, params)
    
    @eth_retry.auto_retry
    async def make_request(self, method: str, params: List[Any], request_id: Optional[int] = None) -> RawResponse:
        request = self.request_type(method=method, params=params, id=request_id or self.call_uid.next)
        return await session.post(self.endpoint, data=request, loads=decode.raw)

    async def execute_batch(self) -> None:
        # NOTE: We create this empty batch here to avoid double-locking.
        empty = JSONRPCBatch(self)
        with self.pools_closed_lock:  # Do we really need this?
            multicalls = dict(self.pending_eth_calls)
            self.pending_eth_calls.clear()
            self.num_pending_eth_calls = 0
            rpc_calls = self.pending_rpc_calls[:]
            self.pending_rpc_calls = empty
        demo_logger.info(f'executing dank batch (current cid: {self.call_uid.latest})')  # type: ignore
        batch = DankBatch(self, multicalls, rpc_calls)
        await batch
        demo_logger.info(f'{batch} done')

    @property
    def queue_is_full(self) -> bool:
        return sum(len(calls) for calls in self.pending_eth_calls.values()) >= self.batcher.step
    
    def early_start(self):
        """Used to start all queued calls when we have enough for a full batch"""
        self.pending_rpc_calls.extend(self.pending_eth_calls.values(), skip_check=True)
        self.pending_eth_calls.clear()
        self.pending_rpc_calls.start()
    
    def reduce_batch_size(self, num_calls: int) -> None:
        new_step = round(num_calls * 0.99) if num_calls >= 100 else num_calls - 1
        # NOTE: We need this check because one of the other multicalls in a batch might have already reduced `self.batcher.step`
        if new_step < self.batcher.step:
            old_step = self.batcher.step
            self.batcher.step = new_step
            logger.warning(f'Multicall batch size reduced from {old_step} to {new_step}. The failed batch had {num_calls} calls.')
