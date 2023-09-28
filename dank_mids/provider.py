
import asyncio
import logging
from typing import TYPE_CHECKING, Any, List, Optional

import a_sync
import eth_retry
import msgspec
from aiohttp.client_exceptions import ClientConnectorError
from aiolimiter import AsyncLimiter
from msgspec.json import encode
from web3 import Web3
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider

from dank_mids._exceptions import (BadGateway, BadRequest, BrokenPipe,
                                   InvalidRequest)
from dank_mids.helpers import decode, session
from dank_mids.types import BytesStream, PartialRequest, RawResponse, Request

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    
logger = logging.getLogger(__name__)

time = lambda: asyncio.get_event_loop().time()

        
class DankProvider:
    def __init__(
        self,
        controller: "DankMiddlewareController", 
        w3: Web3, 
        min_concurrency: int = 16, 
        max_concurrency: int = 64,
    ) -> None:
        self.controller = controller
        endpoint = w3.provider.endpoint_uri
        _validate_endpoint(endpoint)
        self.endpoint = endpoint
        
        self._sync_w3 = _sync_w3_from_async(w3)
        self.chain_id = self._sync_w3.eth.chain_id
        
        self._min_concurrency = min_concurrency
        self._max_concurrency = max_concurrency
        self._semaphore = a_sync.Semaphore(max_concurrency, self)
        self._err_limiter = AsyncLimiter(max_rate=1, time_period=1)
        self._pools_open = a_sync.Event()
        self._pools_open.set()
        self._throttled_by = 0
        self._next_dethrottle = None
        
        self._successes = 0
        self._failures = 0
        
        self._request_selector = _RequestSpecSelector()
        
    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} host={self.endpoint} successes={self._successes} failures={self._failures}>"
    
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
        request = self._request_selector(method=method, params=params, id=request_id or self.controller.call_uid.next)
        async for chunk in self._post(encode(request)):
            yield chunk
    
    @property
    def _concurrency(self) -> bool:
        return self._max_concurrency - self._throttled_by
    
    @property
    def _active_requests(self) -> int:
        return self._concurrency - self._semaphore._value
    
    async def _post(self, data: bytes) -> BytesStream:
        try:
            async with self._semaphore:
                if self._semaphore._waiters:
                    self._pools_open.clear()
                async for chunk in session.post(self.endpoint, data=data):
                    yield chunk
                self._successes += 1
        except (asyncio.TimeoutError, BadRequest, BadGateway, BrokenPipe, ClientConnectorError):
            self._failures += 1
            self._throttle()
            async with self._err_limiter:
                # lets slow the pace down a bit and see if we get a better response when we handle the exc
                raise
        except Exception:
            self._failures += 1
            raise
        if not self._semaphore._waiters:
            self._pools_open.set()
    
    def _should_retry_invalid_request(self, e: Optional[Exception]) -> bool:
        return self._request_selector._should_retry_invalid_request() if isinstance(e, InvalidRequest) else False
    
    def _throttle(self) -> None:
        throttle_to = max(self._active_requests - 1, self._min_concurrency)
        if self._concurrency <= throttle_to:
            return
        throttle_by = self._concurrency - throttle_to
        self._throttled_by += throttle_by
        self._semaphore._value -= throttle_by
        for _ in range(throttle_by):
            next_dethrottle = self._next_dethrottle.when() if self._next_dethrottle else 0
            dethrottle_at = max(next_dethrottle, time()) + 5*60
            self._next_dethrottle = asyncio.get_running_loop().call_at(dethrottle_at, self._dethrottle)
        logger.info("%s max concurrency throttled to %s", self, self._concurrency)
        
    def _dethrottle(self) -> None:
        self._semaphore.release()
        self._throttled_by -= 1
        self._pools_open.set()
        logger.info('%s max concurrency raised to %s', self, self._concurrency)
    
    
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


class _RequestSpecSelector:
    """
    Contains logic to determine appropriate request type for your node.
    Some nodes will only work when we use the full spec.
    """
    def __init__(self) -> None:
        self._full_request_spec_enforced_at = 0
        self.type = PartialRequest
    
    def __call__(self, *args, **kwargs) -> PartialRequest:
        return self.type(*args, **kwargs)
    
    def _should_retry_invalid_request(self) -> bool:
        """
        Configures the RequestSpecSelector to use the fully compliant request type.
        Returns: boolean value indicating whether the request type was recently changed and the call should be retried with the full spec.
        """
        if self._full_request_spec_enforced_at == 0:
            self.type = Request
            self._full_request_spec_enforced_at = time()
        retval = time() - self._full_request_spec_enforced_at <= 600
        if retval:
            logger.debug("your node says the partial request was invalid but its okay, we can use the full jsonrpc spec instead")
        return retval
    