
import asyncio
import logging
import re
from typing import TYPE_CHECKING, List, Optional, Union

from aiohttp.client_exceptions import ClientOSError, ClientResponseError

if TYPE_CHECKING:
    from dank_mids.helpers.session import ClientSession
    from dank_mids.types import PartialRequest, PartialResponse

logger = logging.getLogger("dank_mids.exceptions")

###########
# Generic #
###########

class PayloadTooLarge(Exception):
    pass

class ResponseNotReady(ValueError):
    pass

class EmptyBatch(ValueError):
    pass

class StreamReaderTimeout(asyncio.TimeoutError):
    pass

internal_err_types = Union[AttributeError, TypeError, UnboundLocalError, NotImplementedError, RuntimeError, SyntaxError]

class DankMidsInternalError(Exception):
    def __init__(self, e: internal_err_types) -> None:
        logger.warning(f"unhandled exception inside dank mids internals: {e}", exc_info=True)
        self._original_exception = e
        super().__init__(e.__repr__())

##############
# RPC Errors #
##############

class BadResponse(ValueError):
    def __init__(self, response: "PartialResponse") -> None:
        self.response = response
        super().__init__(response.to_dict())
        
class NodePayloadTooLarge(BadResponse, PayloadTooLarge):
    pass

class Revert(BadResponse):
    pass

class OutOfGas(Revert):
    pass

class InvalidRequest(BadResponse):
    pass

class ArchiveNodeRequired(BadResponse):
    pass

class ExceedsMaxBatchSize(BadResponse):
    @property
    def limit(self) -> int:
        return int(re.search(r'batch limit (\d+) exceeded', self.response.error.message).group(1))

#################
# Client Errors #
#################

class BrokenPipe(ClientOSError):
    pass

##########################
# Client Response Errors #
##########################

class _EasyInitClientResponseError(ClientResponseError):
    def __init__(
        self,
        e: ClientResponseError,
    ) -> None:
        super().__init__(e.request_info, e.history, status=e.status, message=e.message, headers=e.headers)
        self._exception = e
    
class DankMidsClientResponseError(_EasyInitClientResponseError):
    """A wrapper around the standard aiohttp ClientResponseError that attaches the request that generated the error."""
    def __init__(
        self,
        e: ClientResponseError,
        request: "PartialRequest",
    ) -> None:
        super().__init__(e)
        self.args = (e.request_info, e.history, request)
        self.request = request
        
class TooManyRequests(_EasyInitClientResponseError):
    _limited: List["ClientSession"] = []
    
    def __init__(self, e: ClientResponseError, host: str, try_after: float) -> None:
        super().__init__(e)
        self.try_after = float(self.headers.get("Retry-After", try_after * 1.5))
        if host not in self._limited:
            self._limited.append(self)
            logger.info("You're being rate limited by your node provider")
            logger.info("Its all good, dank_mids has this handled, but you might get results slower than you'd like")
        logger.info(f"rate limited: retrying after {self.try_after}s")

class GatewayPayloadTooLarge(_EasyInitClientResponseError, PayloadTooLarge):
    pass

class BadRequest(_EasyInitClientResponseError):
    pass

class BadGateway(_EasyInitClientResponseError):
    pass