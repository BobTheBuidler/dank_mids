
import asyncio
from typing import TYPE_CHECKING, Any, Generator, List

from dank_mids import ENVIRONMENT_VARIABLES
from dank_mids.requests import JSONRPCBatch, RPCRequest, _Batch
from dank_mids.types import Multicalls

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController

MIN_SIZE = 2
CHECK = MIN_SIZE - 1

class DankBatch:
    """ A batch of jsonrpc batches. This is pretty much deprecated and needs to be refactored away."""
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
    def coroutines(self) -> Generator["_Batch", None, None]:
        # Combine multicalls into one or more jsonrpc batches

        # Create empty batch
        working_batch = JSONRPCBatch(self.controller)

        # Go thru the multicalls and add calls to the batch
        for mcall in self.multicalls.values():
            # NOTE: If a multicall has less than `CHECK` calls, we should just throw the calls into a jsonrpc batch individually.
            try:  # NOTE: This should be faster than using len().
                mcall[CHECK]
                working_batch.append(mcall, skip_check=True)
            except IndexError:
                working_batch.extend(mcall, skip_check=True)
            if working_batch.is_full:
                yield working_batch
                working_batch = JSONRPCBatch(self.controller)
        
        rpc_calls_to_batch = self.rpc_calls[:]
        while rpc_calls_to_batch:
            if working_batch.is_full:
                yield working_batch
                working_batch = JSONRPCBatch(self.controller)
            working_batch.append(rpc_calls_to_batch.pop(), skip_check=True)
        if working_batch:
            if working_batch.is_single_multicall:
                yield working_batch[0]  # type: ignore [misc]
            elif len(working_batch) == 1:
                yield working_batch[0].make_request()
            else:
                yield working_batch
