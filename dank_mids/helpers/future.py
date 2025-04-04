from asyncio import (
    AbstractEventLoop,
    Future,
    InvalidStateError,
    Task,
    create_task,
    get_running_loop,
    sleep,
)
from logging import DEBUG, getLogger
from time import time
from typing import TYPE_CHECKING, Any, Generator, Optional
from weakref import ProxyType, proxy

from web3.types import RPCResponse

if TYPE_CHECKING:
    from dank_mids._requests import _RequestBase, _Response


logger = getLogger("dank_mids.future")

_logger_is_enabled_for = logger.isEnabledFor

_future_init = Future.__init__
_future_await = Future.__await__
_future_set_result = Future.set_result
_future_set_exc = Future.set_exception


class DebuggableFuture(Future):
    # default values
    _debug_logs_enabled: bool = False
    __debug_daemon_task: Optional["Task[None]"] = None

    # type hints
    _result: Optional[RPCResponse]

    def __init__(self, owner: "_RequestBase", loop: AbstractEventLoop) -> None:
        _future_init(self, loop=loop)
        if _logger_is_enabled_for(DEBUG):
            self._debug_logs_enabled = True
            self._owner: ProxyType["_RequestBase[_Response]"] = proxy(owner)

    def __await__(self) -> Generator[Any, None, RPCResponse]:
        if self._debug_logs_enabled and self.__debug_daemon_task is None:
            self.__debug_daemon_task = create_task(
                coro=self.__debug_daemon(),
                name="DebuggableFuture debug daemon",
            )
        return _future_await(self)

    def set_result(self, value: RPCResponse) -> None:
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
                    raise InvalidStateError(f"{self} is cancelled") from e
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
            raise InvalidStateError(f"{self} is cancelled") from e
        else:
            raise NotImplementedError(f"{self._state} is not a valid state")

    def set_exception(self, exc: Exception) -> None:
        if self._loop is get_running_loop():
            try:
                _future_set_exc(self, exc)
            except InvalidStateError as e:
                if self._result is not None or self._exception is not None:
                    # its kinda odd that we get here at all but who cares, the fut has a result/exception!
                    return
                elif self._state == "CANCELLED":
                    raise InvalidStateError(f"{self} is cancelled") from e
                raise

        # The rest of this code just makes it threadsafe(ish) based on an old idea that never was fully implemented
        # One day I'll fully commit to either finishing it up or ripping it out. For now it stays.
        elif self._state == "PENDING":
            self._loop.call_soon_threadsafe(_future_set_exc, self, exc)
        elif self._result is not None or self._exception is not None:
            # its kinda odd that we get here at all but who cares, the fut has a result/exception!
            return
        elif self._state == "CANCELLED":
            raise InvalidStateError(f"{self} is cancelled") from e
        else:
            raise

    async def __debug_daemon(self) -> None:
        start = time()
        done = self.done
        # NOTE: _resonse works for RPCRequst and eth_call, _done works for _Batch classes
        while not done():
            await sleep(60)
            if not done():
                logger.debug("%s has not received data after %ss", self._owner, int(time() - start))


def _check_match(first: Exception, second: Exception):
    """Check if two exceptions are similar enough to be considered matching"""
    return (
        type(first) is type(second)
        # Sometimes we add extra info to the back of `exc.args` in various places in this lib.
        # We might get the same exc for the same reason but it might not match exactly since
        # we might have already added the context to the first Exception set to the Future.
        and len(first.args) <= len(second.args)
        # so we check for a match with this goofy map instead...
        and all(map(lambda a, b: a == b, first.args, second.args))
    )
