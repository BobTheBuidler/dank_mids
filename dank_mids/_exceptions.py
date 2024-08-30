
import logging
import re
from typing import TYPE_CHECKING, List, Union

from aiohttp.client_exceptions import ClientResponseError

if TYPE_CHECKING:
    from dank_mids._requests import RPCRequest
    from dank_mids.types import PartialRequest, PartialResponse, RawResponse, Response


logger = logging.getLogger("dank_mids.exceptions")

class BadResponse(ValueError):
    def __init__(self, response: "PartialResponse") -> None:
        self.response = response
        super().__init__(response.to_dict())

class EmptyBatch(ValueError):
    pass

class ResponseNotReady(ValueError):
    pass

class PayloadTooLarge(BadResponse):
    pass

class ExceedsMaxBatchSize(BadResponse):
    """A special exception that occurs when you post a batch which exceeds the maximum batch size for the rpc."""
    @property
    def limit(self) -> int:
        return int(re.search(r'batch limit (\d+) exceeded', self.response.error.message).group(1))  # type: ignore [union-attr]

class DankMidsClientResponseError(ClientResponseError):
    """A wrapper around the standard aiohttp ClientResponseError that attaches the request that generated the error."""
    def __init__(
        self,
        exc: ClientResponseError,
        request: "PartialRequest",
    ) -> None:
        self.request = request
        super().__init__(exc.request_info, exc.history, status=exc.status, message=exc.message, headers=exc.headers)
        self.args = (*self.args, request)
        self._exception = exc

internal_err_types = Union[AttributeError, TypeError, UnboundLocalError, NotImplementedError, RuntimeError, SyntaxError]

class DankMidsInternalError(Exception):
    def __init__(self, e: Union[ValueError, internal_err_types]) -> None:
        logger.warning(f"unhandled exception inside dank mids internals: {e}", exc_info=True)
        self._original_exception = e
        super().__init__(e.__repr__())

class BatchResponseSortError(Exception):
    """A `BatchResponseSortError` indicates your rpc needs some special handling to properly handle batch calls / responses."""
    def __init__(self, calls: List["RPCRequest"], response: List["RawResponse"]) -> None:
        self.calls = calls
        self.results = [raw.decode() for raw in response]
        super().__init__([call.uid for call in calls], self.results)

class ChainstackRateLimited(BadResponse):
    """
    Chainstack doesn't use 429 for rate limiting, it sends a successful response back to the rpc with an error message so our usual rate-limiting handlers don't work and we need to handle that case with bespoke logic.
    """
    @property
    def try_again_in(self) -> float:
        decimal_string = self.response.error.data.try_again_in
        if "ms" in decimal_string:
            ms = float(decimal_string[:-2])
            s = ms / 1000
            logger.info("rate limited by chainstack, retrying in %sms", s)
            return s
        raise NotImplementedError(f"must define a handler for decimal_string {decimal_string}")
