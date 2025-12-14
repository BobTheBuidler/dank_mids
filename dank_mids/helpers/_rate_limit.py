import asyncio
import heapq
from collections import defaultdict
from typing import DefaultDict, Dict, Final

import a_sync
import a_sync._smart
from a_sync.asyncio import sleep0
from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids._vendor.aiolimiter.src.aiolimiter import AsyncLimiter


CancelledError: Final = asyncio.CancelledError
create_task: Final = asyncio.create_task

nlargest: Final = heapq.nlargest

Event: Final = a_sync.Event
shield: Final = a_sync._smart.shield
yield_to_loop: Final = sleep0


# default is 50 requests/second
limiters: Final[DefaultDict[str, AsyncLimiter]] = defaultdict(
    lambda: AsyncLimiter(1, 1 / ENVS.REQUESTS_PER_SECOND)  # type: ignore [has-type, operator]
)

_rate_limit_waiters: Final[Dict[str, a_sync.Event]] = {}
_rate_limit_tasks: Final[Dict[str, "asyncio.Task[None]"]] = {}


async def rate_limit_inactive(endpoint: str) -> None:
    """
    Wait until the rate limiter for `endpoint` has no remaining waiters.
    If someone's already waiting on this endpoint, just await their Event.
    Otherwise, set up our own Event and signal once no waiters remain.
    """
    # Quick exit if no queued waiters
    if not limiters[endpoint]._waiters:
        return

    # If another task is already waiting, just join it
    if existing := _rate_limit_waiters.get(endpoint):
        await existing.wait()
        return

    # Otherwise, create an Event for others to wait on
    task = _rate_limit_tasks.get(endpoint)
    if task is None:
        _rate_limit_waiters[endpoint] = Event(endpoint, 10)
        task = create_task(__rate_limit_inactive(endpoint))
        _rate_limit_tasks[endpoint] = task
    await shield(task)


async def __rate_limit_inactive(endpoint: str) -> None:
    # sourcery skip: use-contextlib-suppress
    waiters = limiters[endpoint]._waiters
    while waiters:
        # pop last item
        last_waiter_tuple = nlargest(1, waiters)[0]
        last_waiter = last_waiter_tuple[-1]

        if last_waiter.cancelled():
            waiters.remove(last_waiter_tuple)
            continue

        if last_waiter.done():
            # NOTE: I don't think this is possible but want to confirm
            _rate_limit_waiters.pop(endpoint).set()
            _rate_limit_tasks.pop(endpoint)
            raise RuntimeError("last waiter is done")

        # await it
        try:
            await last_waiter
        except CancelledError:
            # AsyncLimiter cancels the fut as part of regular operation
            pass

        # let recently popped waiters check the limiter for capacity, they might create new waiters
        # then, let recently popped waiters make some calls to see if we're still being limited
        for _ in range(10):
            if waiters:
                break
            await yield_to_loop()

    _rate_limit_waiters.pop(endpoint).set()
    _rate_limit_tasks.pop(endpoint)
