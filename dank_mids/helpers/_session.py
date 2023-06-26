
from aiohttp import ClientSession, ClientTimeout
from async_lru import alru_cache

from dank_mids import _config


@alru_cache(maxsize=1)
async def get_session() -> ClientSession:
    return ClientSession(timeout=ClientTimeout(_config.AIOHTTP_TIMEOUT), raise_for_status=True)