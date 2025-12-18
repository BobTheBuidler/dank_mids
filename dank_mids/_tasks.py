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
current_task: Final = asyncio.current_task
shield: Final = asyncio.shield
wait_for: Final = asyncio.wait_for

create_task: Final = a_sync.create_task


async def try_for_result(fut: asyncio.Future[T]) -> T:
    # If this coroutine is cancelled, it will also cancel the underlying Future.
    try:
        return await wait_for(shield(fut), TIMEOUT_SECONDS_BIG)
    except CancelledError as e:
        task = current_task()
        cancel_message = e.args[0] if e.args else None
        fut.cancel(
            f"{task} cancellation propagated by dank_mids._tasks.try_for_result: {cancel_message}"
        )
        raise


async def try_for_result_quick(fut: asyncio.Future[T]) -> T:
    # If this coroutine is cancelled, it will also cancel the underlying Future.
    try:
        return await wait_for(shield(fut), TIMEOUT_SECONDS_SMALL)
    except CancelledError as e:
        task = current_task()
        cancel_message = e.args[0] if e.args else None
        fut.cancel(
            f"{task} cancellation propagated by dank_mids._tasks.try_for_result_quick: {cancel_message}"
        )
        raise


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
