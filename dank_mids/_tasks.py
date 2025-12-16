from asyncio import Task
from logging import getLogger
from typing import Any, Final


BATCH_TASKS: Final[set[Task[Any]]] = set()


logger: Final = getLogger("dank_mids.tasks")

log_task_exception: Final = logger.exception


def batch_done_callback(t: Task[Any]) -> None:
    if t._exception is not None:
        log_task_exception("exception in batch task %s", t)
    elif t.cancelled():
        log_task_exception("batch task is cancelled??? %s", t)
    else:
        BATCH_TASKS.discard(t)
