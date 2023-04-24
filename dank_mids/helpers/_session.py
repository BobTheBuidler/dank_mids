
from functools import lru_cache

from requests import Session
from requests.adapters import HTTPAdapter


@lru_cache(maxsize=1)
def get_session() -> Session:
    adapter = HTTPAdapter(pool_connections=100, pool_maxsize=100)
    session = Session()
    session.mount("http://", adapter)
    session.mount("https://", adapter)
    return session