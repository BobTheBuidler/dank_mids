import asyncio
from typing import (
    Any,
    Coroutine,
    Final,
    Iterable,
    TypeVar,
)

import a_sync.asyncio

from dank_mids._logging import getLogger


__T = TypeVar("__T")

FinishedTasks = set["asyncio.Future[__T]"]
PendingTasks = set["asyncio.Future[__T]"]


logger: Final = getLogger("dank_mids.gather")

# These compile to C constants
CancelledError: Final = asyncio.CancelledError
Task: Final = asyncio.Task
get_running_loop: Final = asyncio.get_running_loop
wait: Final = asyncio.wait


yield_to_loop: Final = a_sync.asyncio.sleep0


async def gatherish(coros: Iterable[Coroutine[Any, Any, Any]], *, name: str | None = None) -> None:
    # sourcery skip: use-contextlib-suppress
    """
    An implementation of asyncio.gather optimized for use cases that:
        1. Have coroutines that are predomininately sync
        2. Expect occasional Exceptions but do not want to propagate them to the other tasks
        3. Do not need the results of the tasks returned"
    """
    loop = get_running_loop()

    # materialize the map into a list to make sure all the tasks start
    tasks = iter([Task(coro, loop=loop, name=name) for coro in coros])
    # sleep twice to let 99% of the tasks complete
    # NOTE: By doing this we allow any successful calls to get their results sooner without being interrupted
    #       by the first exc in the gather and having to wait for the bisect and retry process
    # TODO: stop retrying ones that succeed, that's wasteful
    await yield_to_loop()
    await yield_to_loop()
    for task in tasks:
        try:
            await _log_cancelled_error(task)
        except Exception:
            # we will only retrieve the first exc from our tasks, if any
            # this hack prevents asyncio from logging a message that the other excs were not retrieved
            for task in tasks:
                # Make sure all the remaining tasks complete before we raise the exc
                try:
                    await _log_cancelled_error(task)
                except Exception:
                    pass
            raise


async def _log_cancelled_error(task: asyncio.Task[__T]) -> __T:
    try:
        return await task
    except CancelledError:
        logger.exception("CancelledError in `gatherish`. This should not happen.")
        raise
