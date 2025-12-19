import asyncio
from logging import getLogger
from typing import Any, Awaitable, Final

import a_sync

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.types import T


TIMEOUT_SECONDS_SMALL: Final = 30.0
TIMEOUT_SECONDS_BIG: Final = float(ENVS.STUCK_CALL_TIMEOUT)  # type: ignore [arg-type]

BATCH_TASKS: Final[set[asyncio.Task[Any]]] = set()


logger: Final = getLogger("dank_mids.tasks")
log_task_exception: Final = logger.exception

CancelledError: Final = asyncio.CancelledError
ensure_future: Final = asyncio.tasks.ensure_future
wait_for: Final = asyncio.wait_for

create_task: Final = a_sync.create_task


def create_batch_task(a: Awaitable[T], name: str) -> asyncio.Task[T]:
    batch_task: asyncio.Task[T] = create_task(a, name=name)
    # create a strong reference since we might exit when a result
    # is received for the first waiters but the batch is still running
    BATCH_TASKS.add(batch_task)
    # discard the strong reference when the task completes successfully
    batch_task.add_done_callback(batch_done_callback)
    return batch_task


def batch_done_callback(t: asyncio.Task[Any]) -> None:
    if t._exception is not None:
        log_task_exception("exception in batch task %s", t)
    elif t.cancelled():
        # Make the CancelledError so we can get the cancel message, if any.
        try:
            t.result()
        except CancelledError as e:
            cancel_message = e.args[0] if e.args else None

        # Now log the exception because something is fucked up and the user needs to know.
        log_task_exception("batch task %s is cancelled???\nreason: %s", t, cancel_message)
    else:
        BATCH_TASKS.discard(t)


# Vendored from asyncio:


def shield(arg: asyncio.tasks._FutureLike[T]) -> asyncio.Future[T]:
    """Wait for a future, shielding it from cancellation.

    The statement

        task = asyncio.create_task(something())
        res = await shield(task)

    is exactly equivalent to the statement

        res = await something()

    *except* that if the coroutine containing it is cancelled, the
    task running in something() is not cancelled.  From the POV of
    something(), the cancellation did not happen.  But its caller is
    still cancelled, so the yield-from expression still raises
    CancelledError.  Note: If something() is cancelled by other means
    this will still cancel shield().

    If you want to completely ignore cancellation (not recommended)
    you can combine shield() with a try/except clause, as follows:

        task = asyncio.create_task(something())
        try:
            res = await shield(task)
        except CancelledError:
            res = None

    Save a reference to tasks passed to this function, to avoid
    a task disappearing mid-execution. The event loop only keeps
    weak references to tasks. A task that isn't referenced elsewhere
    may get garbage collected at any time, even before it's done.
    """
    # TODO: add a fastpath here for Multicall and JSONRPCBatch types (maybe DankBatch too?)
    inner: asyncio.Future[T] = ensure_future(arg)  # type: ignore [arg-type]
    if inner.done():
        # Shortcut.
        return inner
    loop = _get_loop(inner)
    outer: asyncio.Future[T] = loop.create_future()

    def _inner_done_callback(inner: asyncio.Future[T]) -> None:
        if outer.cancelled():
            if not inner.cancelled():
                # Mark inner's result as retrieved.
                inner.exception()
            return

        if inner.cancelled():
            outer.cancel(f"inner task {inner} was cancelled")
        else:
            exc = inner.exception()
            if exc is not None:
                outer.set_exception(exc)
            else:
                outer.set_result(inner.result())

    def _outer_done_callback(outer: asyncio.Future[T]) -> None:
        if not inner.done():
            inner.remove_done_callback(_inner_done_callback)

    inner.add_done_callback(_inner_done_callback)
    outer.add_done_callback(_outer_done_callback)
    return outer


def _get_loop(fut: asyncio.Future[Any]) -> asyncio.AbstractEventLoop:
    # Tries to call Future.get_loop() if it's available.
    # Otherwise fallbacks to using the old '_loop' property.
    try:
        get_loop = fut.get_loop
    except AttributeError:
        return fut._loop
    else:
        return get_loop()
