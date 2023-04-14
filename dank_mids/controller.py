
import asyncio
import threading
from collections import defaultdict
from time import time
from typing import Any, DefaultDict, List

from eth_utils import to_checksum_address
from multicall.constants import MULTICALL2_ADDRESSES, MULTICALL_ADDRESSES
from multicall.multicall import NotSoBrightBatcher
from web3 import Web3
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse

from dank_mids._config import LOOP_INTERVAL
from dank_mids._demo_mode import demo_logger
from dank_mids.loggers import main_logger, sort_lazy_logger
from dank_mids.requests import JSONRPCBatch, Multicall, RPCRequest, eth_call
from dank_mids.types import BlockId, ChainId
from dank_mids.uid import UIDGenerator
from dank_mids.worker import DankWorker

BYPASS_METHODS = "eth_getLogs", "trace_", "debug_"

instances: DefaultDict[ChainId, List["DankMiddlewareController"]] = defaultdict(list)

def _sync_w3_from_async(w3: Web3) -> Web3:
    assert w3.eth.is_async and isinstance(w3.provider, AsyncBaseProvider), "Dank Middleware can only be applied to an asycnhronous Web3 instance."
    sync_provider = HTTPProvider(w3.provider.endpoint_uri)
    sync_w3: Web3 = Web3(provider = sync_provider)
    # We can't pickle middlewares to send to process executor.
    # The call has already passed thru all middlewares on the user's Web3 instance.
    sync_w3.middleware_onion.clear()
    sync_w3.provider.middlewares = tuple()
    return sync_w3


class DankMiddlewareController:
    def __init__(self, w3: Web3) -> None:
        main_logger.info('Dank Middleware initializing... Strap on your rocket boots...')
        self.w3: Web3 = w3
        self.sync_w3 = _sync_w3_from_async(w3)
        self.chain_id = self.sync_w3.eth.chain_id
        multicall = MULTICALL_ADDRESSES.get(self.chain_id)
        multicall2 = MULTICALL2_ADDRESSES.get(self.chain_id)
        if multicall2 is None:
            raise NotImplementedError("Dank Mids currently does not support this network.\nTo add support, you just need to submit a PR adding the appropriate multicall contract addresses to this file:\nhttps://github.com/banteg/multicall.py/blob/master/multicall/constants.py")
        self.multicall2 = to_checksum_address(multicall2)
        self.no_multicall = {self.multicall2} if multicall is None else {self.multicall2, to_checksum_address(multicall)}
        self.worker = DankWorker(self)
        self.call_uid = UIDGenerator()
        self.futs: List[asyncio.Future] = []
        self.pending_eth_calls: DefaultDict[BlockId, Multicall] = defaultdict(lambda: Multicall(self.worker))
        self.pools_closed_lock = threading.Lock()
        self.pending_rpc_calls = JSONRPCBatch(self.worker)
        self.is_running: bool = False
        self._first = None
        self._paused = asyncio.Event()
        self._paused._value = True
        self._checkpoint: float = time()
        self._instance: int = sum(len(_instances) for _instances in instances.values())
        instances[self.chain_id].append(self)  # type: ignore
    
    def __repr__(self) -> str:
        return f"<DankMiddlewareController instance={self._instance} chain={self.chain_id} endpoint={self.endpoint}>"

    async def __call__(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        return await (eth_call(self, params) if method == "eth_call" else RPCRequest(self, method, params))  # type: ignore [return-value]
    
    @property
    def endpoint(self) -> str:
        return self.w3.provider.endpoint_uri  # type: ignore
    
    @property
    def batcher(self) -> NotSoBrightBatcher:
        return self.worker.batcher
    
    async def taskmaster_loop(self) -> None:
        self.is_running = True
        self._paused.clear()
        while self.pending_eth_calls or self.pending_rpc_calls:
            await self.raise_exceptions()
            if (self.loop_is_ready or self.queue_is_full):
                await self.execute_multicall()
            await asyncio.sleep(0)
        self._paused.set()
        self.is_running = False
    
    async def execute_multicall(self) -> None:
        self.checkpoint = time()
        i = 0
        while self.pools_closed_lock.locked():
            if i // 500 == int(i // 500):
                main_logger.debug('lock is locked')
            i += 1
            await asyncio.sleep(.1)
        
        # NOTE we put this here to prevent a double locking issue
        empty = JSONRPCBatch(self.worker)
        with self.pools_closed_lock:
            eth_calls = dict(self.pending_eth_calls)
            self.pending_eth_calls.clear()
            rpc_calls = self.pending_rpc_calls
            self.pending_rpc_calls = empty
        demo_logger.info(f'executing multicall (current cid: {self.call_uid.latest})')  # type: ignore
        await self.worker.execute_batch(eth_calls, rpc_calls)

    @sort_lazy_logger
    def should_batch(self, method: RPCEndpoint, params: Any) -> bool:
        """ Determines whether or not a call should be passed to the DankMiddlewareController. """
        if method == "eth_call" and params[0]["to"] == self.multicall2:
            # These most likely come from dank mids internals if you're using dank mids.
            return False
        if any(bypass in method for bypass in BYPASS_METHODS):
            main_logger.debug(f"bypassed, method is {method}")
            return False
        return True

    @property
    def loop_is_ready(self) -> bool:
        return time() - self._checkpoint > LOOP_INTERVAL
    
    @property
    def queue_is_full(self) -> bool:
        return bool(sum(len(v) for v in self.pending_eth_calls.values()) >= self.batcher.step * 25)
    
    async def raise_exceptions(self) -> None:
        if futs := self.futs[:]:
            for fut in futs:
                if fut.done():
                    await fut
                    self.futs.remove(fut)

    def reduce_batch_size(self, num_calls: int) -> None:
        new_step = round(num_calls * 0.99) if num_calls >= 100 else num_calls - 1
        # NOTE: We need this check because one of the other multicalls in a batch might have already reduced `self.batcher.step`
        if new_step < self.batcher.step:
            old_step = self.batcher.step
            self.batcher.step = new_step
            main_logger.warning(f'Multicall batch size reduced from {old_step} to {new_step}. The failed batch had {num_calls} calls.')
