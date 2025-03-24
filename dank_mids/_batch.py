from itertools import tee
from logging import getLogger
from typing import TYPE_CHECKING, Any, Awaitable, Generator, List, Union

from a_sync import create_task

from dank_mids._exceptions import DankMidsInternalError
from dank_mids._requests import _Batch, JSONRPCBatch, Multicall, RPCRequest
from dank_mids.helpers._errors import log_internal_error
from dank_mids.types import Multicalls, RawResponse

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController

MIN_SIZE = 1  # TODO: Play with this
"""The minimum size for a batch operation."""

CHECK = MIN_SIZE - 1
"""A constant used for checking batch sizes."""

logger = getLogger(__name__)


class DankBatch:
    """
    A batch of JSON-RPC batches.

    This class represents a collection of multicalls and RPC calls that can be executed as a batch.
    It is used internally by the :class:`DankMiddlewareController` to manage and execute batches of calls.

    Note:
        This class is considered "pretty much deprecated" and needs refactoring in future versions.

    See Also:
        :class:`dank_mids._requests.Multicall`: The Multicall class used in this batch.
        :class:`dank_mids._requests.RPCRequest`: The RPCRequest class used in this batch.
    """

    _started: bool = False
    """A flag indicating whether the batch has been started."""

    __slots__ = "controller", "multicalls", "rpc_calls", "__dict__"

    def __init__(
        self,
        controller: "DankMiddlewareController",
        multicalls: Multicalls,
        rpc_calls: List[Union[Multicall, RPCRequest]],
    ):
        self.controller = controller
        """The controller managing this batch."""

        self.multicalls = multicalls
        """A collection of multicalls to be executed."""

        self.rpc_calls = rpc_calls
        """A list of individual RPC calls or multicalls."""

    def __await__(self) -> Generator[Any, None, None]:
        """
        Executes all operations in the batch.

        This method starts the processing of all multicalls and individual RPC calls
        that have been added to the batch. It marks the batch as started to prevent
        duplicate executions.

        Note:
            This method does not wait for the operations to complete. Use the `await` statement
            on the DankBatch instance to wait for completion and handle results.

        Returns a generator that can be awaited to execute the batch.
        """
        if self._started:
            raise RuntimeError("The batch has already been awaited")
        self._started = True
        for mcall in self.multicalls.values():
            mcall.start(self, cleanup=False)
        for call in self.rpc_calls:
            call._batch = self
        return self._await().__await__()

    async def _await(self) -> None:
        """
        Internal method to await the completion of all coroutines in the batch.

        This method gathers all coroutines in the batch and awaits their completion,
        logging any exceptions that may occur during execution. It's designed to
        handle both successful completions and potential errors gracefully.

        Raises:
            Exception: If any of the coroutines in the batch raise an exception,
                       it will be re-raised after all coroutines have been processed.
        """
        # tee turns 1 iterator into 2
        batches0, batches1 = tee(self.coroutines, 2)
        tasks = map(create_task, batches0)
        for batch, task in zip(batches1, list(tasks)):
            try:
                await task
            except DankMidsInternalError:
                raise
            except Exception as e:
                try:
                    log_internal_error(logger, batch, len(batch), e)
                except TypeError:
                    # object of type 'coroutine' has no len()
                    log_internal_error(logger, batch, 1, e)
                raise

    @property
    def coroutines(self) -> Generator[Union[_Batch, Awaitable[RawResponse]], None, None]:
        """
        Generator that prepares RPC calls and multicalls for batch processing.

        This method combines multicalls and individual RPC calls into one or more JSON-RPC batches,
        considering the batch size limits. The process involves appending calls to a working batch
        and yielding batches when they reach the defined size or when all calls are included.

        Yields:
            A combination of JSON-RPC batches ready for execution.
        """
        # Combine multicalls into one or more jsonrpc batches

        # Create empty batch
        working_batch = JSONRPCBatch(self.controller)

        # alias since this code runs in tight loops
        batch_append = working_batch.append

        check_len = min(CHECK, self.controller.batcher.step)
        # Go thru the multicalls and add calls to the batch
        for mcall in self.multicalls.values():
            if len(mcall) >= check_len:
                batch_append(mcall, skip_check=True)
            else:
                # NOTE: If a multicall has less than `check_len` calls, we should
                #       just throw the calls into a jsonrpc batch individually.
                working_batch.extend(mcall, skip_check=True)
            if working_batch.is_full:
                yield working_batch
                working_batch = JSONRPCBatch(self.controller)
                batch_append = working_batch.append

        rpc_calls_to_batch = list(self.rpc_calls)
        pop_next = rpc_calls_to_batch.pop
        while rpc_calls_to_batch:
            if working_batch.is_full:
                yield working_batch
                working_batch = JSONRPCBatch(self.controller)
                batch_append = working_batch.append
            batch_append(pop_next(), skip_check=True)
        if working_batch:
            if working_batch.is_single_multicall:
                yield next(iter(working_batch))  # type: ignore [misc]
            elif len(working_batch) == 1:
                yield next(iter(working_batch)).make_request()  # type: ignore [union-attr]
            else:
                yield working_batch
