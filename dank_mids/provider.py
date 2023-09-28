
import asyncio
import logging
import time
from typing import TYPE_CHECKING, Any, List, Optional

import a_sync
import eth_retry
from aiohttp.client_exceptions import ClientConnectorError
from msgspec.json import encode
from web3 import Web3
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider

from dank_mids._exceptions import BrokenPipe
from dank_mids.helpers import decode, session
from dank_mids.types import BytesStream, PartialRequest, RawResponse, Request

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    
logger = logging.getLogger(__name__)

class DankProvider:
    def __init__(self, controller: "DankMiddlewareController", w3: Web3, min_concurrency: int = 4, max_concurrency: int = 64) -> None:
        self.controller = controller
        endpoint = w3.provider.endpoint_uri
        _validate_endpoint(endpoint)
        self.endpoint = endpoint
        
        self._sync_w3 = _sync_w3_from_async(w3)
        self.chain_id = self._sync_w3.eth.chain_id
        
        self._min_concurrency = min_concurrency
        self._max_concurrency = max_concurrency
        self._semaphore = a_sync.Semaphore(max_concurrency, self)
        self._pools_open = a_sync.Event()
        self._pools_open.set()
        self._throttled_by = 0
        self._next_dethrottle = None
        
        self._successes = 0
        self._failures = 0
        
        # NOTE: We need this mutable for node types that require the full jsonrpc spec
        self._request_type = PartialRequest
        self._request_type_changed_at = 0
        
    def __repr__(self) -> str:
        return f"<Provider host={self.endpoint} successes={self._successes} failures={self._failures}>"
    
    @property
    def total_requests(self) -> int:
        return self._successes + self._failures
    
    @eth_retry.auto_retry
    async def make_request(self, method: str, params: List[Any], request_id: Optional[int] = None) -> RawResponse:
        response = b''
        async for chunk in self.stream_request(method, params, request_id=request_id):
            response += chunk
        return decode.raw(response)
    
    async def stream_request(self, method: str, params: List[Any], request_id: Optional[int] = None) -> BytesStream:
        request = self._request_type(method=method, params=params, id=request_id or self.controller.call_uid.next)
        async for chunk in self._post(encode(request)):
            yield chunk
    
    @property
    def _at_min_speed(self) -> bool:
        if self._concurrency > self._min_concurrency:
            return False
        elif self._concurrency == self._min_concurrency:
            return True
        raise ValueError(f'concurrency ({self._concurrency}) should never be less than minimum ({self._min_concurrency})')
    
    @property
    def _concurrency(self) -> bool:
        return self._max_concurrency - self._throttled_by
    
    @property
    def _should_retry_invalid_request(self):
        if self._request_type_changed_at == 0:
            self._request_type = Request
            self._request_type_changed_at = time.time()
        return time.time() - self._request_type_changed_at <= 600
    
    async def _post(self, data: bytes) -> BytesStream: 
        async with self._semaphore:
            if self._semaphore._waiters:
                self._pools_open.clear()
            try:
                async for chunk in session.post(self.endpoint, data=data):
                    yield chunk
                self._successes += 1
            except (asyncio.TimeoutError, BrokenPipe, ClientConnectorError):
                self._failures += 1
                await self._throttle()
                raise
            except Exception:
                self._failures += 1
                raise
    
    async def _throttle(self):
        if self._at_min_speed:
            return
        self._throttled_by += 1
        await self._semaphore.acquire()
        def release():
            self._semaphore.release()
            self._throttled_by -= 1
            logger.info('%s max conncurrency raised to %s', self, self._concurrency)
        if self._next_dethrottle:
            dethrottle_at = max(time.time(), self._next_dethrottle.when()) + 5*60
        else:
            dethrottle_at = time.time() + 5*60
        self._next_dethrottle = asyncio.get_running_loop().call_at(dethrottle_at, release)
        
    
    
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