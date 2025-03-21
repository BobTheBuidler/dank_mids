from logging import Logger
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from dank_mids._requests import _Batch


def log_internal_error(logger: Logger, batch: "_Batch", batch_len: int, exc: Exception):
    try:
        batch_objs = list(batch)
    except TypeError:
        # 'coroutine' object is not iterable
        batch_objs = [batch]
    logger.error(
        "That's not good, there was an exception in a %s (len=%s). These are supposed to be handled.\n"
        "Exc: %s\n"
        "%s contents: %s\n\n",
        type(batch).__name__,
        batch_len,
        exc,
        type(batch).__name__,
        batch_objs,
        exc_info=True,
    )
