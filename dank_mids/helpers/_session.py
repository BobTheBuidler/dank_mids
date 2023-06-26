
from aiohttp import ClientSession
from async_lru import alru_cache

from dank_mids import _config


@alru_cache(maxsize=None)
async def get_session(base_url) -> ClientSession:
    return ClientSession(base_url, timeout=_config.AIOHTTP_TIMEOUT, raise_for_status=True)