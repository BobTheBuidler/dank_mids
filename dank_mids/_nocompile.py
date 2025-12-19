# These utils are supposed to be in _tasks, but:

# theres a mypyc bug with reraising excs from other excs in async context
# TODO: make an issue for this and save a link to it here, compile this file when fixed

import asyncio
from typing import Final

from dank_mids._tasks import TIMEOUT_SECONDS_BIG, TIMEOUT_SECONDS_SMALL, shield


CancelledError: Final = asyncio.CancelledError
current_task: Final = asyncio.current_task
wait_for: Final = asyncio.wait_for


class InternalTaskCancelledError(Exception):
    """
    This is a special Exception type that we use to wrap asyncio.CancelledError
    exceptions that occur where they shouldn't, so they are raised up to the
    end-user instead of being handled by asyncio's internal CancelledError logic.
    """


async def try_for_result(fut: asyncio.Future[T]) -> T:
    # If this coroutine is cancelled, it will also cancel the underlying Future.
    try:
        return await wait_for(shield(fut), TIMEOUT_SECONDS_BIG)
    except CancelledError as e:
        waiter = current_task()
        if waiter is not None and waiter.cancelled():
            cancel_message = e.args[0] if e.args else None
            fut.cancel(
                f"{waiter} cancellation propagated by dank_mids._tasks.try_for_result: {cancel_message}"
            )
        elif fut.cancelled():
            # This shouldn't happen since we use shield here, we need to re-raise
            # it as a special exc type so the outer task isn't cancelled by asyncio
            raise InternalTaskCancelledError(*e.args) from e
        raise


async def try_for_result_quick(fut: asyncio.Future[T]) -> T:
    # If this coroutine is cancelled, it will also cancel the underlying Future.
    try:
        return await wait_for(shield(fut), TIMEOUT_SECONDS_SMALL)
    except CancelledError as e:
        waiter = current_task()
        if waiter is not None and waiter.cancelled():
            cancel_message = e.args[0] if e.args else None
            fut.cancel(
                f"{waiter} cancellation propagated by dank_mids._tasks.try_for_result_quick: {cancel_message}"
            )
        elif fut.cancelled():
            # This shouldn't happen since we use shield here, we need to re-raise
            # it as a special exc type so the outer task isn't cancelled by asyncio
            raise InternalTaskCancelledError(*e.args) from e
        raise
