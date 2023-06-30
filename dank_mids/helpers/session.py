
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
from async_lru import alru_cache

from dank_mids import _config
from dank_mids.helpers import decode
from dank_mids.types import JSONRPCBatchResponse, PartialRequest, RawResponse

logger = logging.getLogger("dank_mids.session")

# NOTE: You cannot subclass an IntEnum object so we have to do some hacky shit here.
# First, set up custom error codes we might see.
class _HTTPStatusExtension(IntEnum):
    CLOUDFLARE_TIMEOUT = (524, 'Cloudflare Timeout',
        '"524 A timeout occurred" is an unofficial server error that is specific to Cloudflare.\n'
        + 'When the 524 A timeout occurred status code is received, it implies that a successful\n'
        + 'HTTP Connection was made between Cloudflare and the origin server, however the connection\n'
        + 'timed out before the HTTP request was completed. Cloudflare typically waits 100 seconds\n'
        + 'for an HTTP response and returns this HTTP status code if nothing is received.\n'
        + 'Learn more at https://http.dev/524')
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
    HTTPStatusExtended.CLOUDFLARE_TIMEOUT
}

@overload
async def post(endpoint: str, *args, loads = decode.raw, **kwargs) -> RawResponse:...
@overload
async def post(endpoint: str, *args, loads = decode.jsonrpc_batch, **kwargs) -> JSONRPCBatchResponse:...
async def post(endpoint: str, *args, loads: JSONDecoder = None, **kwargs) -> Any:
    """Returns decoded json data from `endpoint`"""
    session = await get_session()
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
                if tried >= 5 or e.status not in RETRY_FOR_CODES:
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
    timeout = ClientTimeout(_config.AIOHTTP_TIMEOUT)
    return ClientSession(headers={'content-type': 'application/json'}, timeout=timeout, raise_for_status=True)
