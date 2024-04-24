
import asyncio
import http
import logging
from enum import IntEnum
from itertools import chain
from threading import get_ident
from random import random
from typing import Any, Callable, List, Optional, overload

import msgspec
from aiohttp import ClientSession as DefaultClientSession
from aiohttp import ClientTimeout, TCPConnector
from aiohttp.client_exceptions import ClientResponseError
from aiohttp.typedefs import JSONDecoder
from aiolimiter import AsyncLimiter
from async_lru import alru_cache

from dank_mids import ENVIRONMENT_VARIABLES
from dank_mids.helpers import _codec
from dank_mids.types import JSONRPCBatchResponse, PartialRequest, RawResponse

logger = logging.getLogger("dank_mids.session")

# NOTE: You cannot subclass an IntEnum object so we have to do some hacky shit here.
# First, set up custom error codes we might see.
class _HTTPStatusExtension(IntEnum):
    WEB_SERVER_IS_RETURNING_AN_UNKNOWN_ERROR = (520, 'Web Server is Returning an Unknown Error',
        'HTTP response status code 520 Web server is returning an unknown error is an unofficial server error\n'
        + 'that is specific to Cloudflare. This is a catch-all error that is used in the absence of having a\n'
        + 'HTTP status code for one that is more specific.\n'
        + 'Learn more at https://http.dev/520')
    WEB_SERVER_IS_DOWN = (521, 'Web Server Is Down',
        'HTTP response status code 521 Web server is down is an unofficial server error that is specific to Cloudflare.\n'
        + 'This HTTP status code occurs when the HTTP client was able to successfully connect to Cloudflare but it was\n'
        + 'unable to connect to the origin server.'
        + 'Learn more at https://http.dev/521')
    CLOUDFLARE_CONNECTION_TIMEOUT = (522, 'Cloudflare Connection Timeout',
        'Cloudflare is a content delivery network that acts as a gateway between a user and a website server.\n'
        + 'When the 522 Connection timed out status code is received, Cloudflare attempted to connect\n'
        + 'to the origin server but was not successful due to a timeout. The HTTP Connection was not established\n'
        + 'most likely because the IP addresses of Cloudflare are blocked by the origin server,\n'
        + 'the origin server settings are misconfigured, or the origin server is overloaded.'
        + 'Learn more at https://http.dev/522')
    CLOUDFLARE_TIMEOUT = (524, 'Cloudflare Timeout',
        '"524 A timeout occurred" is an unofficial server error that is specific to Cloudflare.\n'
        + 'When the 524 A timeout occurred status code is received, it implies that a successful\n'
        + 'HTTP Connection was made between Cloudflare and the origin server, however the connection\n'
        + 'timed out before the HTTP request was completed. Cloudflare typically waits 100 seconds\n'
        + 'for an HTTP response and returns this HTTP status code if nothing is received.\n'
        + 'Learn more at https://http.dev/524')
    SITE_FROZEN = (530, 'Site Frozen',
        'HTTP response status code 530 is an unofficial server error that is specific to Cloudflare\n'
        + 'and Pantheon. In the case of Cloudflare, a second HTTP status code 1XXX error message will be\n'
        + 'included to provide a more accurate description of the problem. For Pantheon, HTTP status code\n'
        + '530 Site Frozen indicates that a site has been restricted due to inactivity.\n'
        + 'Learn more at https://http.dev/530')
    def __new__(cls, value, phrase, description=''):
        obj = int.__new__(cls, value)
        obj._value_ = value
        obj.phrase = phrase
        obj.description = description
        return obj

# Then, combine the standard HTTPStatus enum and the custom extension to get the full custom HTTPStatus enum we need.
HTTPStatusExtended = IntEnum('HTTPStatusExtended', [(i.name, i.value) for i in chain(http.HTTPStatus, _HTTPStatusExtension)])

RETRY_FOR_CODES = {
    HTTPStatusExtended.BAD_GATEWAY,
    HTTPStatusExtended.WEB_SERVER_IS_RETURNING_AN_UNKNOWN_ERROR,
    HTTPStatusExtended.CLOUDFLARE_CONNECTION_TIMEOUT,
    HTTPStatusExtended.CLOUDFLARE_TIMEOUT,
}

limiter = AsyncLimiter(5, 0.1)  # 50 requests/second

@overload
async def post(endpoint: str, *args, loads: Callable[[Any], RawResponse], **kwargs) -> RawResponse:...
@overload
async def post(endpoint: str, *args, loads: Callable[[Any], JSONRPCBatchResponse], **kwargs) -> JSONRPCBatchResponse:...
async def post(endpoint: str, *args, loads: Optional[JSONDecoder] = None, **kwargs) -> Any:
    """Returns decoded json data from `endpoint`"""
    session = await get_session()
    return await session.post(endpoint, *args, loads=loads, **kwargs)

async def get_session() -> "ClientSession":
    return await _get_session_for_thread(get_ident())

class ClientSession(DefaultClientSession):
    async def post(self, endpoint: str, *args, loads: Optional[JSONDecoder] = None, _retry_after: int = 1, **kwargs) -> bytes:  # type: ignore [override]
        # Process input arguments.
        if isinstance(kwargs.get('data'), PartialRequest):
            logger.debug("making request for %s", kwargs['data'])
            kwargs['data'] = _codec.encode(kwargs['data'])
            kwargs['data'] = msgspec.json.encode(kwargs['data'], enc_hook=_codec.encode_hook)
        logger.debug("making request with (args, kwargs): (%s %s)", tuple(endpoint, *args), kwargs)

        # Try the request until success or 5 failures.
        tried = 0
        while True:
            try:
                async with limiter:
                    async with super().post(endpoint, *args, **kwargs) as response:
                        response = await response.json(loads=loads, content_type=None)
                        logger.debug("received response %s", response)
                        return response
            except ClientResponseError as ce:
                if ce.status == HTTPStatusExtended.TOO_MANY_REQUESTS:
                    try_after = float(ce.headers.get("Retry-After", _retry_after * 1.5))
                    if self not in _limited:
                        _limited.append(self)
                        logger.info("You're being rate limited by your node provider")
                        logger.info("Its all good, dank_mids has this handled, but you might get results slower than you'd like")
                    logger.info(f"rate limited: retrying after {try_after}s")
                    await asyncio.sleep(try_after)
                    if try_after > 30:
                        logger.warning('severe rate limiting from your provider')
                    return await self.post(endpoint, *args, loads=loads, _retry_after=try_after, **kwargs)
                
                try:
                    if ce.status not in RETRY_FOR_CODES or tried >= 5:
                        logger.debug("response failed with status %s", HTTPStatusExtended(ce.status))
                        raise ce
                except ValueError as ve:
                    raise ce if str(ve).endswith("is not a valid HTTPStatusExtended") else ve from ve
                
                sleep = random()
                await asyncio.sleep(sleep)
                logger.debug("response failed with status %s, retrying in %ss", HTTPStatusExtended(ce.status), round(sleep, 2))
                tried += 1

@alru_cache(maxsize=None)
async def _get_session_for_thread(thread_ident: int) -> ClientSession:
    """
    This makes our ClientSession threadsafe just in case.
    Most everything should be run in main thread though.
    """
    return ClientSession(
        connector = TCPConnector(limit=32),
        headers = {'content-type': 'application/json'}, 
        timeout = ClientTimeout(ENVIRONMENT_VARIABLES.AIOHTTP_TIMEOUT),  # type: ignore [arg-type]
        raise_for_status = True,
    )

_limited: List[ClientSession] = []