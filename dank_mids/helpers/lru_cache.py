from functools import wraps
from typing import Callable, Dict, TypeVar

from typing_extensions import ParamSpec


__P = ParamSpec("__P")
__T = TypeVar("__T")

def lru_cache_lite(func: Callable[__P, __T]) -> Callable[__P, __T]:
    """A faster implementation of functools.lru_cache with no maxsize"""
    cache: Dict[__P.args, __T] = {}
    cache_miss = object()
    cache_get = cache.get
    @wraps(func)
    def lru_cache_lite_wrap(*args: __P.args):
        retval = cache_get(args, cache_miss)
        if retval is cache_miss:
            retval = func(*args)
            cache[args] = retval
        return retval
    lru_cache_lite_wrap.cache = cache
    return lru_cache_lite_wrap

def lru_cache_lite_nonull(func: Callable[__P, __T]) -> Callable[__P, __T]:
    """A faster implementation of functools.lru_cache with no maxsize"""
    cache: Dict[__P.args, __T] = {}
    cache_get = cache.get
    @wraps(func)
    def lru_cache_lite_wrap(*args: __P.args):
        retval = cache_get(args, None)
        if retval is None:
            retval = func(*args)
            cache[args] = retval
        return retval
    lru_cache_lite_wrap.cache = cache
    return lru_cache_lite_wrap