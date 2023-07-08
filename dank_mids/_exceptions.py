
from typing import TYPE_CHECKING

from aiohttp.client_exceptions import ClientResponseError

if TYPE_CHECKING:
    from dank_mids.types import PartialRequest, PartialResponse


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
