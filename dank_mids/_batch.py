
import asyncio
import logging
from typing import TYPE_CHECKING, Any, Awaitable, Generator, List, Union

from dank_mids._exceptions import DankMidsInternalError
from dank_mids._requests import _Batch, JSONRPCBatch, Multicall, RPCRequest
from dank_mids.types import Multicalls, RawResponse

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController

MIN_SIZE = 1  # TODO: Play with this
"""The minimum size for a batch operation."""

CHECK = MIN_SIZE - 1
"""A constant used for checking batch sizes."""

logger = logging.getLogger(__name__)

class DankBatch:
    __slots__ = 'controller', 'multicalls', 'rpc_calls', '_started'
    """
    A batch of JSON-RPC batches.

    This class represents a collection of multicalls and RPC calls that can be executed as a batch.
    It is used internally by the DankMiddlewareController to manage and execute batches of calls.

    Note:
        This class is considered "pretty much deprecated" and needs refactoring in future versions.
    """

    def __init__(self, controller: "DankMiddlewareController", multicalls: Multicalls, rpc_calls: List[Union[Multicall, RPCRequest]]):
        self.controller = controller
        """The controller managing this batch."""

        self.multicalls = multicalls
        """A collection of multicalls to be executed."""

        self.rpc_calls = rpc_calls
        """A list of individual RPC calls or multicalls."""

        self._started = False
        """A flag indicating whether the batch has been started."""
    
    def __await__(self) -> Generator[Any, None, Any]:
        """
        Makes the DankBatch awaitable.

        This method allows the batch to be used with the `await` keyword,
        starting the batch execution if it hasn't been started yet.

        Returns:
            A generator that can be awaited to execute the batch.
        """
        self.start()
        return self._await().__await__()
    
    async def _await(self) -> None:
        """
        Internal method to await the completion of all coroutines in the batch.
        
        This method gathers all coroutines in the batch and awaits their completion,
        logging any exceptions that may occur during execution.
        """
        batches = tuple(self.coroutines)
        for batch, result in zip(batches, await asyncio.gather(*batches, return_exceptions=True)):
            if isinstance(result, Exception):
                if not isinstance(result, DankMidsInternalError):
                    logger.error(f"That's not good, there was an exception in a {batch.__class__.__name__}. These are supposed to be handled.\n{result}\n", exc_info=True)
                raise result

    def start(self) -> None:
        for mcall in self.multicalls.values():
            mcall.start(self, cleanup=False)
        for call in self.rpc_calls:
            call.start(self)
        self._started = True
    
    @property
    def coroutines(self) -> Generator[Union["_Batch", Awaitable[RawResponse]], None, None]:
        # Combine multicalls into one or more jsonrpc batches

        # Create empty batch
        working_batch = JSONRPCBatch(self.controller)

        check_len = min(CHECK, self.controller.batcher.step)
        # Go thru the multicalls and add calls to the batch
        for mcall in self.multicalls.values():
            # NOTE: If a multicall has less than `CHECK` calls, we should just throw the calls into a jsonrpc batch individually.
            try:  # NOTE: This should be faster than using len().
                mcall[check_len]
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
                yield working_batch[0].make_request()  # type: ignore [union-attr]
            else:
                yield working_batch
