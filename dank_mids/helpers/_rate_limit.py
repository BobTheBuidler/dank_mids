import asyncio
import heapq
from collections import defaultdict
from typing import Dict, Final

import a_sync
import a_sync.asyncio
from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids._tasks import shield
from dank_mids._vendor.aiolimiter.src.aiolimiter import AsyncLimiter
from dank_mids.helpers._requester import _requester
from dank_mids.types import RateLimiters


TASKS: Final[set[asyncio.Task[None]]] = set()

CancelledError: Final = asyncio.CancelledError
create_task: Final = asyncio.create_task
get_running_loop: Final = asyncio.get_running_loop

nlargest: Final = heapq.nlargest

Event: Final = a_sync.Event
sleep0: Final = a_sync.asyncio.sleep0


# default is 50 requests/second
limiters: Final[RateLimiters] = defaultdict(
    lambda: AsyncLimiter(1, 1 / int(ENVS.REQUESTS_PER_SECOND))
)

_rate_limit_waiters: Final[dict[str, a_sync.Event]] = {}
_rate_limit_tasks: Final[dict[str, "asyncio.Task[None]"]] = {}


async def rate_limit_inactive(endpoint: str) -> None:
    """
    Wait until the rate limiter for `endpoint` has no remaining waiters.
    If someone's already waiting on this endpoint, just await their Event.
    Otherwise, set up our own Event and signal once no waiters remain.
    """
    # Quick exit if no queued waiters
    if not limiters[endpoint]._waiters:
        return

    caller_loop = get_running_loop()
    caller_future: asyncio.Future[None] = caller_loop.create_future()

    async def chained_result_callback(t: asyncio.Task[None]) -> None:
        exc = t.exception()
        if exc is None:
            caller_loop.call_soon_threadsafe(caller_future.set_result, None)
        else:
            caller_loop.call_soon_threadsafe(caller_future.set_exception, exc)

    def start_check() -> None:
        task = create_task(_rate_limit_inactive(endpoint))
        task.add_done_callback(chained_result_callback)
        tasks = TASKS  # one globals lookup is better than two
        tasks.add(task)
        task.add_done_callback(tasks.discard)

    _requester.loop.call_soon_threadsafe(start_check)
    await caller_future


async def _rate_limit_inactive(endpoint: str) -> None:
    """
    Wait until the rate limiter for `endpoint` has no remaining waiters.
    If someone's already waiting on this endpoint, just await their Event.
    Otherwise, set up our own Event and signal once no waiters remain.
    """
    # Quick exit if no queued waiters (2nd check)
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

    # alias this global var so we only look it up 1x
    yield_to_loop = sleep0

    # get the waiters for this particular endpoint
    waiters = limiters[endpoint]._waiters

    # run it
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
            # This cannot be cancelled from above due to use of `asyncio.shield` in `rate_limit_inactive`
            pass

        # let recently popped waiters check the limiter for capacity, they might create new waiters
        # then, let recently popped waiters make some calls to see if we're still being limited
        for _ in range(10):
            if waiters:
                break
            await yield_to_loop()

    _rate_limit_waiters.pop(endpoint).set()
    _rate_limit_tasks.pop(endpoint)
