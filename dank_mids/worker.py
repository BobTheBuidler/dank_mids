import asyncio
import threading
from typing import TYPE_CHECKING, Any, Generator, List, Tuple

import eth_retry
from eth_typing import ChecksumAddress
from multicall.multicall import NotSoBrightBatcher
from multicall.utils import gather

from dank_mids._config import GANACHE_FORK, MAX_JSONRPC_BATCH_SIZE
from dank_mids.requests import JSONRPCBatch, Multicall, RPCRequest, _Batch
from dank_mids.types import CallsToExec
from dank_mids.uid import UIDGenerator

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


class DankWorker:
    """
    Runs a second event loop in a subthread which is used to reduce congestion on the main event loop.
    This allows dank_mids to better communicate with your node while you abuse it with heavy loads.
    """
    def __init__(self, controller: "DankMiddlewareController") -> None:
        self.controller = controller
        self.target: ChecksumAddress = self.controller.multicall2
        self.batcher = NotSoBrightBatcher()
        self.multicall_uid: UIDGenerator = UIDGenerator()
        self.request_uid: UIDGenerator = UIDGenerator()
        self.jsonrpc_batch_uid: UIDGenerator = UIDGenerator()
        self.state_override_not_supported: bool = GANACHE_FORK or self.controller.chain_id == 100  # Gnosis Chain does not support state override.
        self.event_loop = asyncio.new_event_loop()
        self.worker_thread = threading.Thread(target=self.start)
        self.worker_thread.start()
    
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
        return await self.controller.w3.eth.call(*request_args)  # type: ignore
    
    @property
    def endpoint(self) -> str:
        return self.controller.w3.provider.endpoint_uri  # type: ignore
    
    async def execute_batch(self, calls_to_exec: CallsToExec, rpc_calls: List[RPCRequest]) -> None:
        """ Runs in main thread. """
        asyncio.run_coroutine_threadsafe(self._execute_batch(calls_to_exec, rpc_calls), self.event_loop).result()

    async def _execute_batch(self, calls_to_exec: CallsToExec, rpc_calls: List[RPCRequest]) -> None:
        """ Runs in worker thread. """
        await DankBatch(self, calls_to_exec, rpc_calls)
    
    
class DankBatch:
    """ A batch of jsonrpc batches. """
    def __init__(self, worker: DankWorker, eth_calls: CallsToExec, rpc_calls: List[RPCRequest]):
        self.worker = worker
        self.eth_calls = eth_calls
        self.rpc_calls = rpc_calls
    
    def __await__(self) -> Generator[Any, None, Any]:
        return gather(self.coroutines).__await__()
    
    @property
    def batcher(self) -> NotSoBrightBatcher:
        return self.worker.batcher
    
    @property
    def coroutines(self) -> List["_Batch"]:
        request_coros: List[_Batch] = []
        multicalls_to_batch: List["Multicall"] = []
        for *full_batches, remaining_calls in [self.batcher.batch_calls(calls, self.batcher.step) for calls in self.eth_calls.values()]:
            request_coros.extend([Multicall(self.worker, batch) for batch in full_batches])
            multicalls_to_batch.append(Multicall(self.worker, remaining_calls))
        # Combine multicalls into one or more jsonrpc batches
        full_batches, working_batch = self.batch_multicalls(multicalls_to_batch)
        request_coros.extend(full_batches)
        rpc_calls_to_batch = self.rpc_calls[:]
        while rpc_calls_to_batch:
            if len(working_batch) >= MAX_JSONRPC_BATCH_SIZE:
                request_coros.append(working_batch)
                working_batch = JSONRPCBatch(self.worker)
            working_batch.append(rpc_calls_to_batch.pop())
        if working_batch:
            if working_batch.is_single_multicall:
                request_coros.append(working_batch[0])  # type: ignore
            else:
                request_coros.append(working_batch)
        return request_coros
    
    def batch_multicalls(self, multicalls: List["Multicall"]) -> Tuple[List["JSONRPCBatch"], "JSONRPCBatch"]:
        """ Used to collect multicalls into batches without overwhelming the node with oversized calls. """
        full_batches: List[JSONRPCBatch] = []
        multicalls.sort(key=lambda x: len(x), reverse=True)
        eth_calls_in_batch = 0
        working_batch = JSONRPCBatch(self.worker)
        for mcall in multicalls:
            assert isinstance(mcall, Multicall)
            # This would be too many eth_calls for a single multicall, lets start a new jsonrpc batch.
            if eth_calls_in_batch + len(mcall) > self.batcher.step:
                if working_batch:
                    full_batches.append(working_batch)
                working_batch = JSONRPCBatch(self.worker, [mcall])
                eth_calls_in_batch = len(mcall)
            # This can be added to the current jsonrpc batch
            else:
                working_batch.append(mcall)
                eth_calls_in_batch += len(mcall)
                if len(working_batch) >= MAX_JSONRPC_BATCH_SIZE:
                    # There are more than `MAX_JSONRPC_BATCH_SIZE` rpc calls packed into this batch, let's start a new one
                    full_batches.append(working_batch)
                    working_batch = JSONRPCBatch(self.worker)
                    eth_calls_in_batch = 0
        return full_batches, working_batch
