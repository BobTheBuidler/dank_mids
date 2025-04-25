from logging import DEBUG, Logger, getLogger
from typing import TYPE_CHECKING, Any, Final

from dank_mids._exceptions import BadResponse
from dank_mids.types import PartialResponse

if TYPE_CHECKING:
    from dank_mids._requests import _Batch


error_logger: Final = getLogger("dank_mids.errors")
error_logger_debug: Final = error_logger.debug
error_logger_log: Final = error_logger._log


def error_logger_log_debug(msg: str, *args: Any) -> None:
    error_logger_log(DEBUG, msg, args)


revert_logger: Final = error_logger.getChild("reverts")
revert_logger_log: Final = revert_logger._log


def revert_logger_log_debug(msg: str, *args: Any) -> None:
    revert_logger_log(DEBUG, msg, args)


timeout_logger: Final = error_logger.getChild("timeouts")
timeout_logger_debug: Final = timeout_logger.debug
timeout_logger_warning: Final = timeout_logger.warning


gas_logger: Final = error_logger.getChild("gas")
gas_logger_debug: Final = gas_logger.debug

INDIVIDUAL_CALL_REVERT_STRINGS: Final = {
    "invalid opcode",
    "missing trie node",
    "resource not found",
    "invalid ether transfer",
    "error processing call revert",
}


def log_internal_error(logger: Logger, batch: "_Batch", exc: Exception) -> None:  # type: ignore [type-arg]
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
        len(batch_objs),
        exc,
        type(batch).__name__,
        batch_objs,
        exc_info=True,
    )


def needs_full_request_spec(response: PartialResponse) -> bool:
    """
    Determine if a response indicates that the node requires the full request specification.

    By default we leave off some fields that are not always required.
    Some nodes do not like this, and they let us know via these errors.

    Args:
        response: The error response to check.

    Returns:
        True if the full request specification is needed, False otherwise.
    """
    return response.error is not None and response.error.message.lower() in (
        "invalid request",
        "parse error",
    )


def is_call_revert(e: BadResponse) -> bool:
    """
    Determine if a BadResponse was caused by a revert in one of the individual calls within a multicall.

    Args:
        e: The error response to check.

    Returns:
        True if the error was caused by an individual call revert, False otherwise.
    """
    return any(map(f"{e}".lower().__contains__, INDIVIDUAL_CALL_REVERT_STRINGS))


def log_request_type_switch() -> None:
    error_logger_debug(
        "your node says the partial request was invalid but its okay, we can use the full jsonrpc spec instead"
    )
