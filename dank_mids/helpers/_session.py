import http
from asyncio import CancelledError, Task, create_task, current_task, sleep
from collections import defaultdict
from enum import IntEnum
from heapq import nlargest
from itertools import chain
from random import random
from threading import get_ident
from time import time
from typing import Any, Callable, DefaultDict, Dict, Final, Tuple, final, overload

from a_sync import Event
from a_sync._smart import shield
from a_sync.asyncio import sleep0 as yield_to_loop
from aiohttp import ClientSession, ClientTimeout, TCPConnector
from aiohttp.client_exceptions import ClientResponseError
from aiohttp.typedefs import DEFAULT_JSON_DECODER, JSONDecoder
from aiolimiter import AsyncLimiter
from async_lru import alru_cache

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids._logging import DEBUG, getLogger
from dank_mids.helpers._codec import JSONRPCBatchResponse, RawResponse
from dank_mids.types import PartialRequest


logger: Final = getLogger("dank_mids.session")


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
HTTPStatusExtended: Final = IntEnum("HTTPStatusExtended", [(i.name, i.value) for i in chain(http.HTTPStatus, _HTTPStatusExtension)])  # type: ignore [misc]
"""
An extension of :class:`http.HTTPStatus`, supporting both standard HTTP status codes as well as custom codes used by specific services like Cloudflare.

This enum includes status codes and descriptions for server errors that are not part of the standard HTTP specification.
"""

RETRY_FOR_CODES: Final = {
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
limiters: Final[DefaultDict[str, AsyncLimiter]] = defaultdict(
    lambda: AsyncLimiter(1, 1 / ENVS.REQUESTS_PER_SECOND)  # type: ignore [operator]
)

_rate_limit_waiters: Final[Dict[str, Event]] = {}


async def rate_limit_inactive(endpoint: str) -> None:
    """
    Wait until the rate limiter for `endpoint` has no remaining waiters.
    If someone's already waiting on this endpoint, just await their Event.
    Otherwise, set up our own Event and signal once no waiters remain.
    """
    # Quick exit if no queued waiters
    if not limiters[endpoint]._waiters:
        return

    # If another task is already waiting, just join it
    if existing := _rate_limit_waiters.get(endpoint):
        await existing.wait()
        return

    # Otherwise, create an Event for others to wait on
    task = _rate_limit_tasks.get(endpoint)
    if task is None:
        _rate_limit_waiters[endpoint] = Event(endpoint, 10)
        task = _rate_limit_tasks[endpoint] = create_task(__rate_limit_inactive(endpoint))
    await shield(task)


_rate_limit_tasks: Final[Dict[str, "Task[None]"]] = {}


async def __rate_limit_inactive(endpoint: str) -> None:
    # sourcery skip: use-contextlib-suppress
    waiters = limiters[endpoint]._waiters
    while waiters:
        # pop last item
        last_waiter_tuple = nlargest(1, waiters)[0]
        last_waiter = last_waiter_tuple[-1]

        if last_waiter.cancelled():
            waiters.remove(last_waiter_tuple)
            continue

        if last_waiter.done():
            # NOTE: I don't think this is possible but want to confirm
            _rate_limit_waiters.pop(endpoint).set()
            _rate_limit_tasks.pop(endpoint)
            raise RuntimeError("last waiter is done")

        # await it
        try:
            await last_waiter
        except CancelledError:
            # AsyncLimiter cancels the fut as part of regular operation
            pass

        # let recently popped waiters check the limiter for capacity, they might create new waiters
        # then, let recently popped waiters make some calls to see if we're still being limited
        for _ in range(10):
            if waiters:
                break
            await yield_to_loop()

    _rate_limit_waiters.pop(endpoint).set()
    _rate_limit_tasks.pop(endpoint)


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


@final
class DankClientSession(ClientSession):
    _limited = False
    _last_rate_limited_at = 0
    _continue_requests_at = 0

    async def post(self, endpoint: str, *args, loads: JSONDecoder = DEFAULT_JSON_DECODER, **kwargs) -> bytes:  # type: ignore [override]
        if (now := time()) < self._continue_requests_at:
            await sleep(self._continue_requests_at - now)

        # Process input arguments.
        data = kwargs.get("data")
        if debug_logs_enabled := _logger_is_enabled_for(DEBUG):
            if isinstance(data, PartialRequest):
                kwargs["data"] = data.data
                _logger_log(DEBUG, "making request for %s", (data,))
            _logger_log(
                DEBUG,
                "making request to %s with (args, kwargs): (%s %s)",
                (endpoint, args, kwargs),
            )
        elif isinstance(data, PartialRequest):
            kwargs["data"] = data.data

        # Try the request until success or 5 failures.
        tried = 0
        while True:
            try:
                async with limiters[endpoint]:
                    async with ClientSession.post(self, endpoint, *args, **kwargs) as response:
                        response_data = await response.json(loads=loads, content_type=None)
                        _logger_debug("received response %s", response_data)
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
                    if debug_logs_enabled:
                        _logger_log(
                            DEBUG,
                            "response failed with status %s  request data: %s",
                            (_get_status_enum(ce), data),
                        )
                    raise

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
                    round(current_rate, 3),
                    round(new_rate, 3),
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


def _logger_is_enabled_for(level: int) -> bool: ...
def _logger_warning(msg: str, *args: Any) -> None: ...
def _logger_info(msg: str, *args: Any) -> None: ...
def _logger_debug(msg: str, *args: Any) -> None: ...
def _logger_log(level: int, msg: str, args: Tuple[Any, ...]) -> None: ...


_logger_is_enabled_for: Final = logger.isEnabledFor
_logger_warning: Final = logger.warning
_logger_info: Final = logger.info
_logger_debug: Final = logger.debug
_logger_log: Final = logger._log
