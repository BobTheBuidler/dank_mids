import asyncio
import threading
from typing import TYPE_CHECKING, Any, Generator, List

import eth_retry
from eth_typing import ChecksumAddress
from multicall.multicall import NotSoBrightBatcher
from web3 import Web3

from dank_mids import _config, executor
from dank_mids.helpers import await_all
from dank_mids.requests import JSONRPCBatch, Multicall, _Batch
from dank_mids.types import Multicalls
from dank_mids.uid import UIDGenerator

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


def call(endpoint: str, *request_args):
    return Web3(endpoint).eth.call(*request_args)


class DankWorker:
    """
    Runs a second event loop in a subthread which is used to reduce congestion on the main event loop.
    A second loop with less items running in parallel allows dank_mids to get your responses back to your
      main loop faster.
    """
    def __init__(self, controller: "DankMiddlewareController") -> None:
        self.controller = controller
        self.target: ChecksumAddress = self.controller.multicall2
        self.batcher = NotSoBrightBatcher()
        self.multicall_uid: UIDGenerator = UIDGenerator()
        self.request_uid: UIDGenerator = UIDGenerator()
        self.jsonrpc_batch_uid: UIDGenerator = UIDGenerator()
        self.state_override_not_supported: bool = _config.GANACHE_FORK or self.controller.chain_id == 100  # Gnosis Chain does not support state override.
        self.event_loop = asyncio.new_event_loop()
        self.worker_thread = threading.Thread(target=self.start)
        self.worker_thread.start()
        self.executor = executor.executor
            
    def start(self) -> None:
        """ Runs in worker thread. """
        asyncio.set_event_loop(self.event_loop)
        self.event_loop.run_until_complete(self.loop())
    
    async def loop(self) -> None:
        """ Exits loop when main thread dies, killing worker thread. Runs in worker thread. """
        while threading.main_thread().is_alive():
            await asyncio.sleep(5)
    
    @eth_retry.auto_retry
    async def __call__(self, *request_args: Any) -> Any:
        # NOTE: We make the actual reuest synchronously so we can get the results from the node without waiting for the event loop
        return await self.run_in_executor(self.controller.sync_w3.eth.call, *request_args)  # type: ignore

    async def run_in_executor(self, fn, *args): #: Callable[P, T], *args: P.args) -> T:
        return await self.event_loop.run_in_executor(self.executor, fn, *args)
    
    async def execute_batch(self, calls_to_exec: Multicalls, rpc_calls: JSONRPCBatch) -> None:
        """ Runs in main thread. """
        #asyncio.run_coroutine_threadsafe(self._execute_batch(calls_to_exec, rpc_calls), loop=self.event_loop).result()
        self.controller.futs.append(
            asyncio.run_coroutine_threadsafe(
                #self._execute_batch(DankBatch(self, calls_to_exec, rpc_calls)),
                
                # NOTE we materialize the generator here so that the execution takes place in the main thread
                await_all([*DankBatch(self, calls_to_exec, rpc_calls).coroutines]),
                loop=self.event_loop
            )
        )
    
class DankBatch:
    """ A batch of jsonrpc batches. """
    def __init__(self, worker: DankWorker, eth_calls: Multicalls, rpc_calls: JSONRPCBatch):
        self.worker = worker
        for mcall in eth_calls.values():
            for call in mcall:
                call._started.set()
        for call in rpc_calls:
            call._started.set()
        self.eth_calls = eth_calls
        self.rpc_calls = rpc_calls
    
    #def __await__(self) -> Generator[Any, None, Any]:
    #    return await_all(self.coroutines).__await__()
    
    @property
    def batcher(self) -> NotSoBrightBatcher:
        return self.worker.batcher
    
    @property
    def coroutines(self) -> Generator["_Batch", None, None]:
        *full_batches, working_batch = self.batch_multicalls(list(self.eth_calls.values()))
        
        # Yield full batches then yield the rest
        yield from full_batches
        if len(working_batch) + len(self.rpc_calls) <= _config.MAX_JSONRPC_BATCH_SIZE:
            working_batch.extend(self.rpc_calls, skip_check=True)
            yield working_batch
        else:
            yield working_batch
            yield self.rpc_calls
    
    def batch_multicalls(self, multicalls: List["Multicall"]) -> Generator["JSONRPCBatch", None, None]:
        """ Used to collect multicalls into batches without overwhelming the node with oversized calls. """
        multicalls.sort(key=lambda x: len(x), reverse=True)
        eth_calls_in_batch = 0
        working_batch = JSONRPCBatch(self.worker)
        for mcall in multicalls:
            assert isinstance(mcall, Multicall)
            # This would be too many eth_calls for a single multicall, lets start a new jsonrpc batch.
            if eth_calls_in_batch + len(mcall) > self.batcher.step:
                if working_batch:
                    yield working_batch
                working_batch = JSONRPCBatch(self.worker, [mcall])
                eth_calls_in_batch = len(mcall)
            # This can be added to the current jsonrpc batch
            else:
                working_batch.append(mcall)
                eth_calls_in_batch += len(mcall)
                if len(working_batch) >= _config.MAX_JSONRPC_BATCH_SIZE:
                    # There are more than `MAX_JSONRPC_BATCH_SIZE` rpc calls packed into this batch, let's start a new one
                    yield working_batch
                    working_batch = JSONRPCBatch(self.worker)
                    eth_calls_in_batch = 0
        yield working_batch
