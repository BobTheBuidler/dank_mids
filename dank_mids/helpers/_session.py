import http
from asyncio import CancelledError, sleep
from collections import defaultdict
from enum import IntEnum
from itertools import chain
from logging import DEBUG, WARNING, getLogger
from random import random
from threading import get_ident
from time import time
from typing import Any, Callable, Tuple, overload
from urllib.parse import urlparse

from a_sync import Event
from aiohttp import ClientSession, ClientTimeout, TCPConnector
from aiohttp.client_exceptions import ClientResponseError
from aiohttp.typedefs import DEFAULT_JSON_DECODER, JSONDecoder
from aiolimiter import AsyncLimiter
from async_lru import alru_cache
from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.types import JSONRPCBatchResponse, PartialRequest, RawResponse

logger = getLogger("dank_mids.session")


# NOTE: You cannot subclass an IntEnum object so we have to do some hacky shit here.
# First, set up custom error codes we might see.
class _HTTPStatusExtension(IntEnum):
    """
    A modified version of :class:`http.HTTPStatus`, for custom codes used by specific services like Cloudflare.

    This enum contains status codes and descriptions for server errors that are not part of the standard HTTP specification.
    """

    WEB_SERVER_IS_RETURNING_AN_UNKNOWN_ERROR = (
        520,
        "Web Server is Returning an Unknown Error",
        "HTTP response status code 520 Web server is returning an unknown error is an unofficial server error\n"
        + "that is specific to Cloudflare. This is a catch-all error that is used in the absence of having a\n"
        + "HTTP status code for one that is more specific.\n"
        + "Learn more at https://http.dev/520",
    )

    WEB_SERVER_IS_DOWN = (
        521,
        "Web Server Is Down",
        "HTTP response status code 521 Web server is down is an unofficial server error that is specific to Cloudflare.\n"
        + "This HTTP status code occurs when the HTTP client was able to successfully connect to Cloudflare but it was\n"
        + "unable to connect to the origin server."
        + "Learn more at https://http.dev/521",
    )

    CLOUDFLARE_CONNECTION_TIMEOUT = (
        522,
        "Cloudflare Connection Timeout",
        "Cloudflare is a content delivery network that acts as a gateway between a user and a website server.\n"
        + "When the 522 Connection timed out status code is received, Cloudflare attempted to connect\n"
        + "to the origin server but was not successful due to a timeout. The HTTP Connection was not established\n"
        + "most likely because the IP addresses of Cloudflare are blocked by the origin server,\n"
        + "the origin server settings are misconfigured, or the origin server is overloaded."
        + "Learn more at https://http.dev/522",
    )

    CLOUDFLARE_TIMEOUT = (
        524,
        "Cloudflare Timeout",
        '"524 A timeout occurred" is an unofficial server error that is specific to Cloudflare.\n'
        + "When the 524 A timeout occurred status code is received, it implies that a successful\n"
        + "HTTP Connection was made between Cloudflare and the origin server, however the connection\n"
        + "timed out before the HTTP request was completed. Cloudflare typically waits 100 seconds\n"
        + "for an HTTP response and returns this HTTP status code if nothing is received.\n"
        + "Learn more at https://http.dev/524",
    )

    SITE_FROZEN = (
        530,
        "Site Frozen",
        "HTTP response status code 530 is an unofficial server error that is specific to Cloudflare\n"
        + "and Pantheon. In the case of Cloudflare, a second HTTP status code 1XXX error message will be\n"
        + "included to provide a more accurate description of the problem. For Pantheon, HTTP status code\n"
        + "530 Site Frozen indicates that a site has been restricted due to inactivity.\n"
        + "Learn more at https://http.dev/530",
    )

    def __new__(cls, value, phrase, description=""):
        obj = int.__new__(cls, value)
        obj._value_ = value
        obj.phrase = phrase  # type: ignore [attr-defined]
        obj.description = description  # type: ignore [attr-defined]
        return obj


# Then, combine the standard HTTPStatus enum and the custom extension to get the full custom HTTPStatus enum we need.
HTTPStatusExtended = IntEnum("HTTPStatusExtended", [(i.name, i.value) for i in chain(http.HTTPStatus, _HTTPStatusExtension)])  # type: ignore [misc]
"""
An extension of :class:`http.HTTPStatus`, supporting both standard HTTP status codes as well as custom codes used by specific services like Cloudflare.

This enum includes status codes and descriptions for server errors that are not part of the standard HTTP specification.
"""

RETRY_FOR_CODES = {
    HTTPStatusExtended.BAD_GATEWAY,  # type: ignore [attr-defined]
    HTTPStatusExtended.WEB_SERVER_IS_RETURNING_AN_UNKNOWN_ERROR,  # type: ignore [attr-defined]
    HTTPStatusExtended.CLOUDFLARE_CONNECTION_TIMEOUT,  # type: ignore [attr-defined]
    HTTPStatusExtended.CLOUDFLARE_TIMEOUT,  # type: ignore [attr-defined]
}


def _get_status_enum(error: ClientResponseError) -> HTTPStatusExtended:
    try:
        return HTTPStatusExtended(error.status)
    except ValueError as ve:
        if str(ve).endswith("is not a valid HTTPStatusExtended"):
            # we still want the original exc to raise
            raise error from ve
        raise


# default is 50 requests/second
limiters = defaultdict(lambda: AsyncLimiter(1, 1 / ENVS.REQUESTS_PER_SECOND))

_rate_limit_waiters = {}


async def rate_limit_inactive(endpoint: str) -> None:
    # wait until the last future has been cleared from the rate limiter
    if not (waiters := limiters[endpoint]._waiters):
        return

    if waiter := _rate_limit_waiters.get(endpoint):
        await waiter.wait()
        return

    _rate_limit_waiters[endpoint] = Event()

    while waiters:
        # pop last item
        last_key, last_waiter = waiters.popitem()
        # replace it
        waiters[last_key] = last_waiter
        if last_waiter.done():
            break
        # await it
        try:
            await last_waiter
        except CancelledError:
            pass
        # let recently popped waiters check the limiter for capacity, they might create new waiters
        # then, let recently popped waiters make some calls to see if we're still being limited
        for _ in range(10):
            if waiters:
                break
            else:
                await sleep(0)

    _rate_limit_waiters.pop(endpoint).set()


@overload
async def post(
    endpoint: str, *args, loads: Callable[[Any], RawResponse], **kwargs
) -> RawResponse: ...
@overload
async def post(
    endpoint: str, *args, loads: Callable[[Any], JSONRPCBatchResponse], **kwargs
) -> JSONRPCBatchResponse: ...
async def post(endpoint: str, *args, loads: JSONDecoder = DEFAULT_JSON_DECODER, **kwargs) -> Any:
    """Returns decoded json data from `endpoint`"""
    session = await get_session()
    return await session.post(endpoint, *args, loads=loads, **kwargs)


async def get_session() -> "DankClientSession":
    return await _get_session_for_thread(get_ident())


class DankClientSession(ClientSession):
    _limited = False
    _last_rate_limited_at = 0
    _continue_requests_at = 0
    __max_request_size = 0
    __max_response_size = 0

    async def post(self, endpoint: str, *args, loads: JSONDecoder = DEFAULT_JSON_DECODER, **kwargs) -> bytes:  # type: ignore [override]
        if (now := time()) < self._continue_requests_at:
            await sleep(self._continue_requests_at - now)

        # Process input arguments.
        data = kwargs.get("data")
        if debug_logs_enabled := _logger_is_enabled_for(DEBUG):
            self._log_request(endpoint, args, kwargs, data)
        elif isinstance(data, PartialRequest):
            kwargs["data"] = data.data

        # Try the request until success or 5 failures.
        tried = 0
        while True:
            try:
                async with limiters[endpoint]:
                    async with ClientSession.post(self, endpoint, *args, **kwargs) as response:
                        response_data = await response.json(loads=loads, content_type=None)
                        if _logger_is_enabled_for(DEBUG):
                            self._log_response_size(response, response_data)
                        return response_data
            except ClientResponseError as ce:
                status = ce.status
                if status == HTTPStatusExtended.TOO_MANY_REQUESTS:  # type: ignore [attr-defined]
                    await self._handle_too_many_requests(endpoint, ce)

                elif status in RETRY_FOR_CODES and tried < 5:
                    tried += 1
                    if debug_logs_enabled:
                        sleep_for = random()
                        _logger_log(
                            DEBUG,
                            "response failed with status %s, retrying in %.f2s",
                            (HTTPStatusExtended(status), sleep_for),
                        )
                        await sleep(sleep_for)
                    else:
                        await sleep(random())

                else:
                    _logger_warning(
                        "response failed with status %s\n"
                        "exc: %s\n"
                        "request data: %s",
                        _get_status_enum(ce),
                        ce,
                        data,
                    )
                    raise

    async def _request(self, method, url, **kwargs):
        if _logger_is_enabled_for(DEBUG):
            self._log_request_size(method, url, kwargs)
        return await super()._request(method, url, **kwargs)

    def _log_request(self, endpoint, args, kwargs, data):
        if isinstance(data, PartialRequest):
            kwargs["data"] = data.data
            _logger_log(DEBUG, "making request for %s", (data,))
        _logger_log(
                DEBUG,
                "making request to %s with (args, kwargs): (%s %s)",
                (endpoint, args, kwargs),
            )
    
    def _log_request_size(self, method: str, url: str, kwargs: dict):
        # Calculate body size=
        body = kwargs['data']
        if isinstance(body, bytes):
            body_size = len(body)
        else:
            raise Exception('is this real')
        #elif isinstance(body, str):
        #    body_size = len(body.encode('utf-8'))

        # Log the body size
        if body_size < 1024:
            logger._log(DEBUG, "Request Body Size: %s bytes", (body_size,))
        elif body_size < 1048576:
            logger._log(DEBUG, "Request Body Size: %s kb", (round(body_size/1024,2),))
        else:
            logger._log(DEBUG, "Request Body Size: %s mb", (round(body_size/1048576,2),))

        # Calculate Total Size
        # First calculate header size
        # Parse the URL to extract components
        parsed_url = urlparse(url)
        path = parsed_url.path or '/'
        if parsed_url.query:
            path += f"?{parsed_url.query}"
        host = parsed_url.netloc

        # Prepare headers
        # Start with session headers
        headers = self.headers.copy() if self.headers else {}
        # Update with request-specific headers
        headers.update(kwargs.get('headers', {}))
        
        # Ensure Host header is present
        if 'Host' not in headers:
            headers['Host'] = host

        # Build request line
        request_line = f"{method.upper()} {path} HTTP/1.1\r\n"

        # Build headers string
        headers_str = ''.join(f"{key}: {value}\r\n" for key, value in headers.items())
        
        # Calculate headers size
        headers_size = len(request_line.encode('utf-8')) + len(headers_str.encode('utf-8')) + len(b'\r\n')

        # Total request size = headers + CRLF + body
        # CRLF after headers before body
        total_size = headers_size + len(b'\r\n') + body_size

        # Log the total size
        if total_size < 1024:
            logger._log(DEBUG, "Full Request Size (approx): %s bytes", (total_size,))
        elif total_size < 1048576:
            logger._log(DEBUG, "Full Request Size (approx): %s kb", (round(total_size/1024,2),))
        else:
            logger._log(DEBUG, "Full Request Size (approx): %s mb", (round(total_size/1048576,2),))
                        
        max_successful_request_size = self.__max_request_size
        if total_size > max_successful_request_size:
            max_successful_request_size = self.__max_request_size = total_size

        if max_successful_request_size < 1024:
            _logger_log(DEBUG, "Max successful request size %.2f bytes", (max_successful_request_size,))
        elif max_successful_request_size < 1048576:
            _logger_log(DEBUG, "Max successful request size %.2f kb", (max_successful_request_size/1024,))
        else:
            _logger_log(DEBUG, "Max successful request size %.2f mb", (max_successful_request_size/1048576,))

    def _log_response_size(self, response, response_data):
        response_len = len(response._body)
        _logger_log(DEBUG, "Received response %s", (response_data,))
        if response_len < 1024:
            _logger_log(DEBUG, "Response size %.2f bytes", (response_len,))
        elif response_len < 1048576:
            _logger_log(DEBUG, "Response size %.2f kb", (response_len/1024,))
        else:
            _logger_log(DEBUG, "Response size %.2f mb", (response_len/1048576,))
                            
        max_successful_response_size = self.__max_response_size
        if response_len > max_successful_response_size:
            max_successful_response_size = self.__max_response_size = response_len

        if max_successful_response_size < 1024:
            _logger_log(DEBUG, "Max successful response size %.2f bytes", (max_successful_response_size,))
        elif max_successful_response_size < 1048576:
            _logger_log(DEBUG, "Max successful response size %.2f kb", (max_successful_response_size/1024,))
        else:
            _logger_log(DEBUG, "Max successful response size %.2f mb", (max_successful_response_size/1048576,))
    
    async def _handle_too_many_requests(self, endpoint: str, error: ClientResponseError) -> None:
        limiter = limiters[endpoint]
        if (now := time()) > getattr(limiter, "_last_updated_at", 0) + 10:
            current_rate = limiter._rate_per_sec
            new_rate = current_rate * 0.97
            if new_rate >= ENVS.MIN_REQUESTS_PER_SECOND:
                limiter.time_period /= 0.97
                limiter._rate_per_sec = new_rate
                limiter._last_updated_at = now
                _logger_info(
                    "reduced requests per second for %s from %s to %s",
                    endpoint,
                    current_rate,
                    new_rate,
                )

        now = time()
        self._last_rate_limited_at = now
        secs_between_requests = 1 / limiter._rate_per_sec
        retry_after = float(error.headers.get("Retry-After", secs_between_requests * 5))
        resume_at = max(
            self._continue_requests_at + retry_after,
            self._last_rate_limited_at + retry_after,
        )
        retry_after = resume_at - now
        self._continue_requests_at = resume_at

        self._log_rate_limited(retry_after)
        if retry_after > 30:
            _logger_warning("severe rate limiting from your provider")
        # the limiter handles the timing
        limiter._level += 5

    def _log_rate_limited(self, try_after: float) -> None:
        if not self._limited:
            self._limited = True
            _logger_info("You're being rate limited by your node provider")
            _logger_info(
                "Its all good, dank_mids has this handled, but you might get results slower than you'd like"
            )
        if try_after < 5:
            _logger_debug("rate limited: retrying after %.3fs", try_after)
        else:
            _logger_info("rate limited: retrying after %.3fs", try_after)


@alru_cache(maxsize=None)
async def _get_session_for_thread(thread_ident: int) -> DankClientSession:
    """
    This makes our ClientSession threadsafe just in case.
    Most everything should be run in main thread though.
    """
    # I'm testing the value to use for limit, eventually will make an env var for this with an appropriate default
    connector = TCPConnector(limit=0, enable_cleanup_closed=True)
    client_timeout = ClientTimeout(  # type: ignore [arg-type, attr-defined]
        int(ENVS.AIOHTTP_TIMEOUT)
    )
    return DankClientSession(
        connector=connector,
        headers={"content-type": "application/json"},
        timeout=client_timeout,
        raise_for_status=True,
        read_bufsize=2**20,  # 1mb
    )


def _logger_is_enabled_for(msg: str, *args: Any) -> None: ...
def _logger_warning(msg: str, *args: Any) -> None: ...
def _logger_info(msg: str, *args: Any) -> None: ...
def _logger_debug(msg: str, *args: Any) -> None: ...
def _logger_log(level: int, msg: str, args: Tuple[Any, ...]) -> None: ...


_logger_is_enabled_for = logger.isEnabledFor
_logger_warning = logger.warning
_logger_info = logger.info
_logger_debug = logger.debug
_logger_log = logger._log
