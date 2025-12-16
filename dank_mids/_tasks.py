import asyncio
from logging import getLogger
from typing import Any, Final

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.types import T


TIMEOUT_SECONDS_SMALL: Final = 30.0
TIMEOUT_SECONDS_BIG: Final = float(ENVS.STUCK_CALL_TIMEOUT)  # type: ignore [arg-type]

BATCH_TASKS: Final[set[asyncio.Task[Any]]] = set()


logger: Final = getLogger("dank_mids.tasks")
log_task_exception: Final = logger.exception

CancelledError: Final = asyncio.CancelledError
shield: Final = asyncio.shield
wait_for: Final = asyncio.wait_for


async def try_for_result(fut: asyncio.Future[T]) -> T:
    try:
        return await wait_for(shield(fut), TIMEOUT_SECONDS_BIG)
    except CancelledError:
        fut.cancel()
        raise


async def try_for_result_quick(fut: asyncio.Future[T]) -> T:
    try:
        return await wait_for(shield(fut), TIMEOUT_SECONDS_SMALL)
    except CancelledError:
        fut.cancel()
        raise


def batch_done_callback(t: asyncio.Task[Any]) -> None:
    if t._exception is not None:
        log_task_exception("exception in batch task %s", t)
    elif t.cancelled():
        log_task_exception("batch task is cancelled??? %s", t)
    else:
        BATCH_TASKS.discard(t)
