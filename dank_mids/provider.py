
import logging
import time
from typing import TYPE_CHECKING, Any, List, Optional

import eth_retry
from msgspec.json import encode
from web3 import Web3
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider

from dank_mids.helpers import decode, session
from dank_mids.types import BytesStream, PartialRequest, RawResponse, Request

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    
logger = logging.getLogger(__name__)

class DankProvider:
    def __init__(self, controller: "DankMiddlewareController", w3: Web3) -> None:
        self.controller = controller
        endpoint = w3.provider.endpoint_uri
        _validate_endpoint(endpoint)
        self.endpoint = endpoint
        
        self.sync_w3 = _sync_w3_from_async(w3)
        self.chain_id = self.sync_w3.eth.chain_id
        
        self.successes = 0
        self.failures = 0
        
        # NOTE: We need this mutable for node types that require the full jsonrpc spec
        self.request_type = PartialRequest
        self._request_type_changed_at = 0
        
    def __repr__(self) -> str:
        return f"<Provider host={self.endpoint} successes={self.successes} failures={self.failures}>"
    
    @property
    def total_requests(self) -> int:
        return self.successes + self.failures
    
    @eth_retry.auto_retry
    async def make_request(self, method: str, params: List[Any], request_id: Optional[int] = None) -> RawResponse:
        response = b''
        async for chunk in self.stream_request(method, params, request_id=request_id):
            response += chunk
        return decode.raw(response)
    
    async def stream_request(self, method: str, params: List[Any], request_id: Optional[int] = None) -> BytesStream:
        request = self.request_type(method=method, params=params, id=request_id or self.controller.call_uid.next)
        async for chunk in self._post(encode(request)):
            yield chunk
    
    @property
    def _should_retry_invalid_request(self):
        if self._request_type_changed_at == 0:
            self.request_type = Request
            self._request_type_changed_at = time.time()
        return time.time() - self._request_type_changed_at <= 600
    
    async def _post(self, data: bytes) -> BytesStream:
        try:
            async for chunk in session.post(self.endpoint, data=data):
                yield chunk
            self.successes += 1
        except Exception:
            self.failures += 1
            raise
    
    
def _validate_endpoint(endpoint: str) -> None:
    if "tenderly" in endpoint:
        # NOTE: Tenderly does funky things sometimes
        logger.warning(
            "We see you're using a tenderly rpc.\n" +
            "There is a known conflict between dank and tenderly which causes issues not present with other providers.\n" + 
            "Your milage may vary. Debugging efforts welcome."
        )

def _sync_w3_from_async(w3: Web3) -> Web3:
    assert w3.eth.is_async and isinstance(w3.provider, AsyncBaseProvider), "Dank Middleware can only be applied to an asycnhronous Web3 instance."
    sync_provider = HTTPProvider(w3.provider.endpoint_uri)
    sync_w3: Web3 = Web3(provider = sync_provider)
    # We can't pickle middlewares to send to process executor.
    # The call has already passed thru all middlewares on the user's Web3 instance.
    sync_w3.middleware_onion.clear()
    sync_w3.provider.middlewares = ()
    return sync_w3