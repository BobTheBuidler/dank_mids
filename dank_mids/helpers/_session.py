
from aiohttp import ClientSession, ClientTimeout
from async_lru import alru_cache
from threading import get_ident

from dank_mids import _config


async def get_session() -> ClientSession:
    return await _get_session_for_thread(get_ident())

@alru_cache(maxsize=None)
async def _get_session_for_thread(thread_ident: int) -> ClientSession:
    """
    This makes our ClientSession threadsafe just in case.
    Most everything should be run in main thread though.
    """
    timeout = ClientTimeout(_config.AIOHTTP_TIMEOUT)
    return ClientSession(timeout=timeout, raise_for_status=True)
