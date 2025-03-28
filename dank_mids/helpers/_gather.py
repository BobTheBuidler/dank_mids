from asyncio import Task, get_running_loop
from typing import Coroutine, Iterable, Optional

from a_sync.asyncio import sleep0 as yield_to_loop


async def gatherish(coros: Iterable[Coroutine], *, name: Optional[str] = None) -> None:
    # sourcery skip: use-contextlib-suppress
    """
    An implementation of asyncio.gather optimized for use cases that:
        1. Have coroutines that are predomininately sync
        2. Expect occasional Exceptions but do not want to propagate them to the other tasks
        3. Do not need the results of the tasks returned"
    """
    loop = get_running_loop()

    create_task = lambda coro: Task(coro, loop=loop, name=name)

    # materialize the map into a list to make sure all the tasks start
    tasks = iter(list(map(create_task, coros)))
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
