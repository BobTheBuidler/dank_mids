
from http import HTTPStatus
from threading import get_ident

from aiohttp import ClientSession as DefaultClientSession
from aiohttp import ClientTimeout
from aiohttp.client_exceptions import ClientResponseError
from aiohttp.typedefs import JSONDecoder
from async_lru import alru_cache

import logging
from dank_mids import _config
from dank_mids.types import PartialRequest
from msgspec.json import encode

logger = logging.getLogger("dank_mids.session")

# Set up custom error codes we might see
HTTPStatus.CLOUDFLARE_TIMEOUT = 524

async def get_session() -> "ClientSession":
    return await _get_session_for_thread(get_ident())

class ClientSession(DefaultClientSession):
    async def post(self, *args, loads: JSONDecoder = None, **kwargs) -> bytes:

        # Process input arguments.
        if "data" in kwargs and isinstance(kwargs['data'], PartialRequest):
            # NOTE: We check this to avoid unnecessary f-string conversions.
            if logger.isEnabledFor(logging.DEBUG):
                logger.debug(f"making request for {kwargs['data']}")
            kwargs['data'] = encode(kwargs['data'])
        # NOTE: We check this to avoid unnecessary f-string conversions.
        elif logger.isEnabledFor(logging.DEBUG):
            logger.debug(f"making request with (args, kwargs): {(args, kwargs)}")

        # Try the request until success or 5 failures.
        tried = 0
        while True:
            try:
                async with super().post(*args, **kwargs) as response:
                    response = await response.json(loads=loads)
                    # NOTE: We check this to avoid unnecessary f-string conversions.
                    if logger.isEnabledFor(logging.DEBUG):
                        logger.debug(f"received response {response}")
                    return response
            except ClientResponseError as e:
                if tried >= 5 or e.status not in {HTTPStatus.BAD_GATEWAY, HTTPStatus.CLOUDFLARE_TIMEOUT}:
                    logger.debug(f"response failed with status {HTTPStatus(e.status)}.")
                    raise e
                logger.debug(f"response failed with status {HTTPStatus(e.status)}, retrying.")
                tried += 1

@alru_cache(maxsize=None)
async def _get_session_for_thread(thread_ident: int) -> ClientSession:
    """
    This makes our ClientSession threadsafe just in case.
    Most everything should be run in main thread though.
    """
    timeout = ClientTimeout(_config.AIOHTTP_TIMEOUT)
    return ClientSession(headers={'content-type': 'application/json'}, timeout=timeout, raise_for_status=True)
