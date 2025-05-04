import asyncio
from typing import (
    Coroutine,
    Final,
    Iterable,
    Literal,
    Optional,
    Set,
    Tuple,
    TypeVar,
    Union,
    overload,
)

import a_sync.asyncio


__T = TypeVar("__T")

FinishedTasks = Set["asyncio.Future[__T]"]
PendingTasks = Set["asyncio.Future[__T]"]


# These compile to C constants
CancelledError: Final = asyncio.CancelledError
Task: Final = asyncio.Task
get_running_loop: Final = asyncio.get_running_loop
wait: Final = asyncio.wait


yield_to_loop: Final = a_sync.asyncio.sleep0


async def gatherish(coros: Iterable[Coroutine], *, name: Optional[str] = None) -> None:  # type: ignore [type-arg]
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
            await task
        except Exception:
            # we will only retrieve the first exc from our tasks, if any
            # this hack prevents asyncio from logging a message that the other excs were not retrieved
            for task in tasks:
                # Make sure all the remaining tasks complete before we raise the exc
                try:
                    await task
                except Exception:
                    pass
            raise


@overload
async def first_completed(
    *fs: asyncio.Future[__T], cancel: Literal[True]
) -> FinishedTasks[__T]: ...
@overload
async def first_completed(
    *fs: asyncio.Future[__T], cancel: Literal[False] = False
) -> Tuple[FinishedTasks[__T], PendingTasks[__T]]: ...
async def first_completed(
    *fs: asyncio.Future[__T], cancel: bool = False
) -> Union[FinishedTasks[__T], Tuple[FinishedTasks[__T], PendingTasks[__T]]]:
    if not cancel:
        return await wait(fs, return_when="FIRST_COMPLETED")
    try:
        done, pending = await wait(fs, return_when="FIRST_COMPLETED")
    except CancelledError:
        for f in fs:
            f.cancel()
        raise
    for p in pending:
        p.cancel()
    return done
