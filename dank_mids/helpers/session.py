
import asyncio
import errno
import http
import logging
from enum import IntEnum
from itertools import chain
from threading import get_ident

from aiohttp import ClientSession as DefaultClientSession
from aiohttp import ClientTimeout, DummyCookieJar, TCPConnector
from aiohttp.client_exceptions import ClientOSError, ClientResponseError
from aiolimiter import AsyncLimiter
from async_lru import alru_cache

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids._exceptions import (BadGateway, BadRequest, BrokenPipe,
                                   GatewayPayloadTooLarge, StreamReaderTimeout,
                                   TooManyRequests)
from dank_mids.types import BytesStream

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

limiter = AsyncLimiter(1, 0.05)  # 20 requests/second

async def post(endpoint: str, *args, **kwargs) -> BytesStream:
    """Returns decoded json data from `endpoint`"""
    session = await get_session()
    async for chunk in session.post(endpoint, *args, **kwargs):
        yield chunk

async def get_session() -> "ClientSession":
    return await _get_session_for_thread(get_ident())


class ClientSession(DefaultClientSession):
    async def post(self, endpoint: str, *args, _retry_after: int = 1, **kwargs) -> BytesStream:
        logger.debug("making request with (args, kwargs): (%s %s)", tuple(chain((endpoint), args)), kwargs)
        # Try the request until success or 5 failures.
        try:
            async for chunk in self._post_and_handle_excs(endpoint, *args, _retry_after=_retry_after, **kwargs):
                yield chunk
            return
        except TooManyRequests as e:
            if e.try_after > 30:
                logger.warning('severe rate limiting from your provider')
            # NOTE: This logic should probably go on the provider not the session
            # NOTE: On second thought, why do we still need ClientSession? 
            await asyncio.sleep(e.try_after)
            async for b in self.post(endpoint, *args, _retry_after=e.try_after * 2, **kwargs):
                yield b
                
    async def _post_and_handle_excs(self, endpoint: str, *args, _retry_after: int = 1, **kwargs) -> BytesStream:
        async with limiter:
            try:
                async with super().post(endpoint, *args, **kwargs) as response:
                    logger.debug("received response %s", response)
                    empty = 0
                    while not response.content.at_eof():
                        try:
                            b = await asyncio.wait_for(response.content.readany(), timeout=ENVS.STREAM_READER_TIMEOUT)
                        except asyncio.TimeoutError as e:
                            raise StreamReaderTimeout from e
                        if b == b'':
                            empty += 1
                        if empty >= 50:
                            raise Exception('can this even happen?')
                        yield b
            except ClientOSError as e:
                if e.errno == errno.EPIPE:
                    raise BrokenPipe(*e.args) from e
                raise e
            except ClientResponseError as e:
                if e.status == HTTPStatusExtended.BAD_REQUEST:
                    raise BadRequest(e)
                if e.status == HTTPStatusExtended.BAD_GATEWAY:
                    raise BadGateway(e)
                if e.status == HTTPStatusExtended.TOO_MANY_REQUESTS:
                    raise TooManyRequests(e, endpoint, _retry_after) from e
                elif e.message == "Payload Too Large":
                    raise GatewayPayloadTooLarge(e)
                raise e


@alru_cache(maxsize=None)
async def _get_session_for_thread(thread_ident: int) -> ClientSession:
    """
    This makes our ClientSession threadsafe just in case.
    Most everything should be run in main thread though.
    """
    connector = TCPConnector(
        limit=ENVS.MAX_CONCURRENCY,
        force_close=True,
    )
    timeout = ClientTimeout(ENVS.AIOHTTP_TIMEOUT)
    return ClientSession(
        connector=connector,
        cookie_jar=DummyCookieJar(),  # We don't need to waste bandwidth on junk
        headers={'content-type': 'application/json'},
        timeout=timeout,
        raise_for_status=True,
    )
