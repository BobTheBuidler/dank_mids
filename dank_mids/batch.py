
import asyncio
from typing import TYPE_CHECKING, Any, Generator, List

from multicall.multicall import NotSoBrightBatcher

from dank_mids._config import MAX_JSONRPC_BATCH_SIZE
from dank_mids.requests import JSONRPCBatch, Multicall, RPCRequest, _Batch
from dank_mids.types import Multicalls

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController

    
class DankBatch:
    """ A batch of jsonrpc batches. """
    def __init__(self, controller: "DankMiddlewareController", multicalls: Multicalls, rpc_calls: List[RPCRequest]):
        self.controller = controller
        self.multicalls = multicalls
        self.rpc_calls = rpc_calls
        self._started = False
    
    def __await__(self) -> Generator[Any, None, Any]:
        self.start()
        return asyncio.gather(*self.coroutines).__await__()

    def start(self) -> None:
        for mcall in self.multicalls.values():
            mcall.start(self, cleanup=False)
        for call in self.rpc_calls:
            call.start(self)
        self._started = True
    
    @property
    def batcher(self) -> NotSoBrightBatcher:
        return self.controller.batcher
    
    @property
    def coroutines(self) -> Generator["_Batch", None, None]:
        multicalls_to_batch: List["Multicall"] = []
        for *full_batches, remaining_calls in (self.batcher.batch_calls(calls, self.batcher.step) for calls in self.multicalls.values()):
            yield from (Multicall(self.controller, batch) for batch in full_batches)
            multicalls_to_batch.append(Multicall(self.controller, remaining_calls))
        # Combine multicalls into one or more jsonrpc batches
        *full_batches, working_batch = self.batch_multicalls(multicalls_to_batch)
        
        # Yield full batches then prepare the rest
        yield from full_batches
        rpc_calls_to_batch = self.rpc_calls[:]
        while rpc_calls_to_batch:
            if len(working_batch) >= MAX_JSONRPC_BATCH_SIZE:
                yield working_batch
                working_batch = JSONRPCBatch(self.controller)
            working_batch.append(rpc_calls_to_batch.pop())
        if working_batch:
            if working_batch.is_single_multicall:
                yield working_batch[0]  # type: ignore [misc]
            else:
                yield working_batch
    
    def batch_multicalls(self, multicalls: List["Multicall"]) -> Generator["JSONRPCBatch", None, None]:
        """ Used to collect multicalls into batches without overwhelming the node with oversized calls. """
        multicalls.sort(key=lambda x: len(x), reverse=True)
        eth_calls_in_batch = 0
        working_batch = JSONRPCBatch(self.controller)
        for mcall in multicalls:
            assert isinstance(mcall, Multicall)
            # This would be too many eth_calls for a single multicall, lets start a new jsonrpc batch.
            if eth_calls_in_batch + len(mcall) > self.batcher.step:
                if working_batch:
                    yield working_batch
                working_batch = JSONRPCBatch(self.controller, [mcall])
                eth_calls_in_batch = len(mcall)
            # This can be added to the current jsonrpc batch
            else:
                working_batch.append(mcall)
                eth_calls_in_batch += len(mcall)
                if len(working_batch) >= MAX_JSONRPC_BATCH_SIZE:
                    # There are more than `MAX_JSONRPC_BATCH_SIZE` rpc calls packed into this batch, let's start a new one
                    yield working_batch
                    working_batch = JSONRPCBatch(self.controller)
                    eth_calls_in_batch = 0
        yield working_batch
