import asyncio
import time
import weakref
from typing import TYPE_CHECKING, Any, Final, Generator, final

from dank_mids._logging import DEBUG, getLogger
from dank_mids.helpers._errors import error_logger_debug
from dank_mids.types import T

if TYPE_CHECKING:
    from dank_mids._requests import _RequestBase, _Response


logger: Final = getLogger("dank_mids.future")

_logger_is_enabled_for: Final = logger.isEnabledFor
_logger_log: Final = logger._log


InvalidStateError: Final = asyncio.InvalidStateError

_future_init: Final = asyncio.Future.__init__
_future_await: Final = asyncio.Future.__await__
_future_set_result: Final = asyncio.Future.set_result
_future_set_exc: Final = asyncio.Future.set_exception

create_task: Final = asyncio.create_task
get_running_loop: Final = asyncio.get_running_loop
sleep: Final = asyncio.sleep

gettime: Final = time.time


@final
class DebuggableFuture(asyncio.Future[T]):
    _result: T | None
    _owner: weakref.ProxyType["_RequestBase[_Response]"]  # type: ignore [valid-type]
    _debug_daemon_task: asyncio.Task[None]

    def __init__(self, owner: "_RequestBase", loop: asyncio.AbstractEventLoop) -> None:  # type: ignore [type-arg]
        _future_init(self, loop=loop)
        if _logger_is_enabled_for(DEBUG):
            self._debug_logs_enabled = True
            self._owner = weakref.proxy(owner)
        else:
            self._debug_logs_enabled = False

    def __await__(self) -> Generator[Any, None, T]:
        if self._debug_logs_enabled and not hasattr(self, "__debug_daemon_task"):
            self._debug_daemon_task = create_task(
                coro=self.__debug_daemon(),
                name="DebuggableFuture debug daemon",
            )
        return _future_await(self)

    def set_result(self, value: T) -> None:
        # sourcery skip: merge-duplicate-blocks, remove-redundant-if
        if self._loop is get_running_loop():
            try:
                _future_set_result(self, value)
            except InvalidStateError as e:
                if self._result is not None:
                    # We already have a result. We don't really care where it came from, this is fine.
                    return
                elif self._exception is not None:
                    # This can happen if 2 copies of a call are going at once, and one gets a revert as a RawResponse
                    # from a JSONRPC batch and the other gets a ContractLogicError from the single call handler
                    return
                elif self._state == "CANCELLED":
                    error_logger_debug("cannot set result: %s is cancelled", self)
                    return
                else:
                    raise NotImplementedError(f"{self._state} is not a valid state") from e

        # The rest of this code just makes it threadsafe(ish) based on an old idea that never was fully implemented
        # One day I'll fully commit to either finishing it up or ripping it out. For now it stays.
        elif self._state == "PENDING":
            self._loop.call_soon_threadsafe(_future_set_result, self, value)
        elif self._result is not None:
            # We already have a result. We don't really care where it came from, this is fine.
            return
        elif self._exception is not None:
            # This can happen if 2 copies of a call are going at once, and one gets a revert as a RawResponse
            # from a JSONRPC batch and the other gets a ContractLogicError from the single call handler
            return
        elif self._state == "CANCELLED":
            error_logger_debug("cannot set result: %s is cancelled", self)
            return
        else:
            raise NotImplementedError(f"{self._state} is not a valid state")

    def set_exception(self, exc: type | BaseException) -> None:
        if self._loop is get_running_loop():
            try:
                _future_set_exc(self, exc)
            except InvalidStateError as e:
                if self._result is not None or self._exception is not None:
                    # its kinda odd that we get here at all but who cares, the fut has a result/exception!
                    return
                elif self._state == "CANCELLED":
                    error_logger_debug("cannot set result: %s is cancelled", self)
                    return
                raise

        # The rest of this code just makes it threadsafe(ish) based on an old idea that never was fully implemented
        # One day I'll fully commit to either finishing it up or ripping it out. For now it stays.
        elif self._state == "PENDING":
            self._loop.call_soon_threadsafe(_future_set_exc, self, exc)
        elif self._result is not None or self._exception is not None:
            # its kinda odd that we get here at all but who cares, the fut has a result/exception!
            return
        elif self._state == "CANCELLED":
            error_logger_debug("cannot set result: %s is cancelled", self)
            return
        else:
            raise

    async def __debug_daemon(self) -> None:
        start = gettime()
        done = self.done
        while not done():
            await sleep(60)
            if not done():
                _logger_log(
                    DEBUG,
                    "%s has not received data after %ss",
                    (self._owner, int(gettime() - start)),
                )


del asyncio, time, weakref
