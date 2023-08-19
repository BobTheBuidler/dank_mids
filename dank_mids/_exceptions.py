
import logging
import re
from typing import TYPE_CHECKING, Union

from aiohttp.client_exceptions import ClientResponseError

if TYPE_CHECKING:
    from dank_mids.types import PartialRequest, PartialResponse


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
    @property
    def limit(self) -> int:
        return int(re.search(r'batch limit (\d+) exceeded', self.response.error.message).group(1))        

class DankMidsClientResponseError(ClientResponseError):
    """A wrapper around the standard aiohttp ClientResponseError that attaches the request that generated the error."""
    def __init__(
        self,
        exc: ClientResponseError,
        request: "PartialRequest",
    ) -> None:
        self.request = request
        super().__init__(exc.request_info, exc.history, code=exc.code, status=exc.status, message=exc.message, headers=exc.headers)
        self.args = (*exc.request_info, exc.history, request)
        self._exception = exc

internal_err_types = Union[AttributeError, TypeError, UnboundLocalError, NotImplementedError, RuntimeError, SyntaxError]

class DankMidsInternalError(Exception):
    def __init__(self, e: internal_err_types) -> None:
        logger.warning(f"unhandled exception inside dank mids internals: {e}", exc_info=True)
        self._original_exception = e
        super().__init__(e.__repr__())
