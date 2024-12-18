import http
from asyncio import sleep
from collections import defaultdict
from enum import IntEnum
from itertools import chain
from logging import DEBUG, getLogger
from random import random
from threading import get_ident
from time import time
from typing import Any, Callable, List, Optional, overload

from aiohttp import ClientSession, ClientTimeout, TCPConnector
from aiohttp.client_exceptions import ClientResponseError
from aiohttp.typedefs import DEFAULT_JSON_DECODER, JSONDecoder
from aiolimiter import AsyncLimiter
from async_lru import alru_cache
from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.helpers._codec import encode
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


__requests_per_second = int(ENVS.REQUESTS_PER_SECOND)

for __periods_per_second in (10, 5, 2, 1):
    if __requests_per_second % __periods_per_second == 0:
        break

# default is 50 requests/second
limiters = defaultdict(
    lambda: AsyncLimiter(
        # do some math here to get requests
        ENVS.REQUESTS_PER_SECOND // __periods_per_second,
        1 / __periods_per_second,
    )
)


async def rate_limit_inactive(endpoint: str) -> None:
    if waiters := limiters[endpoint]._waiters:
        # wait until the last future has been cleared from the rate limiter
        await tuple(waiters.values())[-1]
        await rate_limit_inactive(endpoint)


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


_RETRY_AFTER = 1.0


class DankClientSession(ClientSession):
    _limited = False
    _last_rate_limited_at = 0
    _continue_requests_at = 0

    async def post(self, endpoint: str, *args, loads: JSONDecoder = DEFAULT_JSON_DECODER, **kwargs) -> bytes:  # type: ignore [override]
        if (now := time()) < self._continue_requests_at:
            await sleep(self._continue_requests_at - now)

        # Process input arguments.
        if debug_logs_enabled := logger.isEnabledFor(DEBUG):
            if isinstance(kwargs.get("data"), PartialRequest):
                logger._log(DEBUG, "making request for %s", kwargs["data"])
                kwargs["data"] = encode(kwargs["data"])
            logger._log(DEBUG, "making request to %s with (args, kwargs): (%s %s)", endpoint, args, kwargs)
        else:
            if isinstance(kwargs.get("data"), PartialRequest):
                kwargs["data"] = encode(kwargs["data"])

        # Try the request until success or 5 failures.
        tried = 0
        while True:
            try:
                async with limiters[endpoint]:
                    async with super().post(endpoint, *args, **kwargs) as response:
                        response_data = await response.json(loads=loads, content_type=None)
                        logger.debug("received response %s", response_data)
                        return response_data
            except ClientResponseError as ce:
                if ce.status == HTTPStatusExtended.TOO_MANY_REQUESTS:  # type: ignore [attr-defined]
                    await self.handle_too_many_requests(ce)
                else:
                    try:
                        if ce.status not in RETRY_FOR_CODES or tried >= 5:
                            logger.debug(
                                "response failed with status %s", 
                                HTTPStatusExtended(ce.status),
                            )
                            raise ce
                    except ValueError as ve:
                        if str(ve).endswith("is not a valid HTTPStatusExtended"):
                            raise ce from ve
                        raise
                    else:
                        tried += 1
                        if debug_logs_enabled:
                            sleep_for = random()
                            logger._log(
                                DEBUG,
                                "response failed with status %s, retrying in %ss",
                                HTTPStatusExtended(ce.status),
                                round(sleep_for, 2),
                            )
                            await sleep(sleep_for)
                        else:
                            await sleep(random())

    async def handle_too_many_requests(self, error: ClientResponseError) -> None:
        now = time()
        self._last_rate_limited_at = now
        retry_after = float(error.headers.get("Retry-After", _RETRY_AFTER))
        resume_at = max(
            self._continue_requests_at + retry_after,
            self._last_rate_limited_at + retry_after,
        )
        retry_after = resume_at - now
        self._continue_requests_at = resume_at

        self._log_rate_limited(retry_after)
        if retry_after > 30:
            logger.warning("severe rate limiting from your provider")
        await sleep(retry_after)

    def _log_rate_limited(self, try_after: float) -> None:
        if not self._limited:
            self._limited = True
            logger.info("You're being rate limited by your node provider")
            logger.info(
                "Its all good, dank_mids has this handled, but you might get results slower than you'd like"
            )
        if try_after < 5:
            logger.debug("rate limited: retrying after %.3fs", try_after)
        else:
            logger.info("rate limited: retrying after %.3fs", try_after)


@alru_cache(maxsize=None)
async def _get_session_for_thread(thread_ident: int) -> DankClientSession:
    """
    This makes our ClientSession threadsafe just in case.
    Most everything should be run in main thread though.
    """
    return DankClientSession(
        connector=TCPConnector(limit=32),
        headers={"content-type": "application/json"},
        timeout=ClientTimeout(ENVS.AIOHTTP_TIMEOUT),  # type: ignore [arg-type, attr-defined]
        raise_for_status=True,
        read_bufsize=2**20,  # 1mb
    )
