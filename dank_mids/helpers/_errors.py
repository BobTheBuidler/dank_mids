from logging import Logger, getLogger
from typing import TYPE_CHECKING

from web3.datastructures import AttributeDict

from dank_mids.types import BadResponse, PartialRequest, PartialResponse

if TYPE_CHECKING:
    from dank_mids._requests import _Batch


error_logger = getLogger("dank_mids.errors")
error_logger_debug = error_logger.debug

INDIVIDUAL_CALL_REVERT_STRINGS = {
    "invalid opcode",
    "missing trie node",
    "resource not found",
    "invalid ether transfer",
    "error processing call revert",
}


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


def format_error_response(request: PartialRequest, response: PartialResponse) -> AttributeDict:
    error = response.to_dict()
    error["dankmids_added_context"] = request
    return AttributeDict.recursive(error)


def needs_full_request_spec(response: PartialResponse):
    """
    Determine if a response indicates that the node requires the full request specification.

    By default we leave off some fields that are not always required.
    Some nodes do not like this, and they let us know via these errors.

    Args:
        response: The error response to check.

    Returns:
        True if the full request specification is needed, False otherwise.
    """
    return response.error and response.error.message.lower() in ("invalid request", "parse error")


def is_call_revert(e: BadResponse) -> bool:
    """
    Determine if a BadResponse was caused by a revert in one of the individual calls within a multicall.

    Args:
        e: The error response to check.

    Returns:
        True if the error was caused by an individual call revert, False otherwise.
    """
    return any(map(f"{e}".lower().__contains__, INDIVIDUAL_CALL_REVERT_STRINGS))


def log_request_type_switch():
    error_logger_debug(
        "your node says the partial request was invalid but its okay, we can use the full jsonrpc spec instead"
    )
