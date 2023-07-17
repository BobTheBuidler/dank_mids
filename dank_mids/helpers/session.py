
import http
import logging
from enum import IntEnum
from itertools import chain
from threading import get_ident
from typing import Any, overload

import msgspec
from aiohttp import ClientSession as DefaultClientSession
from aiohttp import ClientTimeout
from aiohttp.client_exceptions import ClientResponseError
from aiohttp.typedefs import JSONDecoder
from aiolimiter import AsyncLimiter
from async_lru import alru_cache

from dank_mids import ENVIRONMENT_VARIABLES
from dank_mids.helpers import decode
from dank_mids.types import JSONRPCBatchResponse, PartialRequest, RawResponse

logger = logging.getLogger("dank_mids.session")

# NOTE: You cannot subclass an IntEnum object so we have to do some hacky shit here.
# First, set up custom error codes we might see.
class _HTTPStatusExtension(IntEnum):
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
    HTTPStatusExtended.CLOUDFLARE_CONNECTION_TIMEOUT,
    HTTPStatusExtended.CLOUDFLARE_TIMEOUT,
}

limiter = AsyncLimiter(1, 0.03)  # 33.333 requests/second

@overload
async def post(endpoint: str, *args, loads = decode.raw, **kwargs) -> RawResponse:...
@overload
async def post(endpoint: str, *args, loads = decode.jsonrpc_batch, **kwargs) -> JSONRPCBatchResponse:...
async def post(endpoint: str, *args, loads: JSONDecoder = None, **kwargs) -> Any:
    """Returns decoded json data from `endpoint`"""
    session = await get_session()
    async with limiter:
        return await session.post(endpoint, *args, loads=loads, **kwargs)

async def get_session() -> "ClientSession":
    return await _get_session_for_thread(get_ident())

class ClientSession(DefaultClientSession):
    async def post(self, endpoint: str, *args, loads: JSONDecoder = None, **kwargs) -> bytes:
        # Process input arguments.
        if isinstance(kwargs.get('data'), PartialRequest):
            # NOTE: We check this to avoid unnecessary f-string conversions.
            if logger.isEnabledFor(logging.DEBUG):
                logger.debug(f"making request for {kwargs['data']}")
            kwargs['data'] = msgspec.json.encode(kwargs['data'])
        # NOTE: We check this to avoid unnecessary f-string conversions.
        elif logger.isEnabledFor(logging.DEBUG):
            logger.debug(f"making request with (args, kwargs): {(tuple(chain((endpoint), args)), kwargs)}")

        # Try the request until success or 5 failures.
        tried = 0
        while True:
            try:
                async with super().post(endpoint, *args, **kwargs) as response:
                    response = await response.json(loads=loads)
                    # NOTE: We check this to avoid unnecessary f-string conversions.
                    if logger.isEnabledFor(logging.DEBUG):
                        logger.debug(f"received response {response}")
                    return response
            except ClientResponseError as e:
                if e.status not in RETRY_FOR_CODES or tried >= 5:
                    logger.debug(f"response failed with status {HTTPStatusExtended(e.status)}.")
                    raise e
                logger.debug(f"response failed with status {HTTPStatusExtended(e.status)}, retrying.")
                tried += 1

@alru_cache(maxsize=None)
async def _get_session_for_thread(thread_ident: int) -> ClientSession:
    """
    This makes our ClientSession threadsafe just in case.
    Most everything should be run in main thread though.
    """
    timeout = ClientTimeout(ENVIRONMENT_VARIABLES.AIOHTTP_TIMEOUT)
    return ClientSession(headers={'content-type': 'application/json'}, timeout=timeout, raise_for_status=True)
