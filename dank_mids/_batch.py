from asyncio import Task
from itertools import tee
from logging import getLogger
from typing import TYPE_CHECKING, Any, Awaitable, Generator, TypeVar, Union, final

from a_sync import create_task

from dank_mids._exceptions import DankMidsInternalError
from dank_mids._requests import _Batch, JSONRPCBatch, Multicall
from dank_mids.helpers._errors import log_internal_error
from dank_mids.types import Multicalls, RawResponse

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController

__T = TypeVar("__T")

MIN_SIZE = 1  # TODO: Play with this
"""The minimum size for a batch operation."""

CHECK = MIN_SIZE - 1
"""A constant used for checking batch sizes."""

logger = getLogger(__name__)


def _create_named_task(awaitable: Awaitable[__T]) -> Task[__T]:
    return create_task(awaitable, name=f"{type(awaitable).__name__} via DankBatch")


@final
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

    _awaited: bool = False
    """A flag indicating whether the batch has been awaited."""

    __slots__ = "controller", "multicalls", "rpc_calls", "__dict__"

    def __init__(
        self,
        controller: "DankMiddlewareController",
        multicalls: Multicalls,
        rpc_calls: JSONRPCBatch,
    ):
        self.controller = controller
        """The controller managing this batch."""

        self.multicalls = multicalls
        """A collection of multicalls to be executed."""

        self.rpc_calls = rpc_calls
        """A list of individual RPC calls or multicalls."""
    
    def __repr__(self):
        return f"<dank_mids.DankBatch object at {hex(id(self))}>"

    def __await__(self) -> Generator[Any, None, None]:
        """
        Executes all operations in the batch.

        This method starts the processing of all multicalls and individual RPC calls
        that have been added to the batch. It marks the batch as awaited to prevent
        duplicate executions.

        Note:
            This method does not wait for the operations to complete. Use the `await` statement
            on the DankBatch instance to wait for completion and handle results.

        Returns a generator that can be awaited to execute the batch.
        """
        if self._awaited:
            raise RuntimeError("The batch has already been awaited")
        self._awaited = True
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

        tasks = map(_create_named_task, batches0)
        last_failure = None
        for batch, task in zip(batches1, list(tasks)):
            try:
                await task
            except Exception as e:
                # we just collect the exceptions for now, we raise later if applicable
                if not isinstance(e, DankMidsInternalError):
                    log_internal_error(logger, batch, e)
                last_failure = task

        if last_failure is not None:
            # raise the last exception if any
            await last_failure

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

        # Start with our existing batch
        working_batch = self.rpc_calls

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

        if working_batch:
            if len(working_batch) == 1:
                call = next(iter(working_batch))
                # since we're not going thru the batch code we'll do this here
                working_batch._done.set()
                yield call if type(call) is Multicall else call.make_request()
            else:
                yield working_batch
