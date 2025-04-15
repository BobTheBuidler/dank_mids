from functools import wraps
from typing import Callable, Dict, TypeVar

from typing_extensions import ParamSpec


__P = ParamSpec("__P")
__T = TypeVar("__T")


def lru_cache_lite(func: Callable[__P, __T]) -> Callable[__P, __T]:
    """A faster implementation of functools.lru_cache with no maxsize.

    This decorator caches the results of the decorated function without imposing a
    maximum cache size. It uses a unique internal cache-miss marker to determine if a
    result is cached.

    **Example:**

        .. code-block:: python

            @lru_cache_lite
            def add(x: int, y: int) -> int:
                print("Computing add...")
                return x + y

            # First call with same arguments results in function execution.
            print(add(2, 3))  # prints "Computing add..." then 5

            # Subsequent calls with the same arguments return the cached result.
            print(add(2, 3))  # prints 5 without "Computing add..."

    **See Also:**
        - `functools.lru_cache <https://docs.python.org/3/library/functools.html#functools.lru_cache>`_
        - :func:`~dank_mids.lru_cache_lite_nonull` for a variant using ``None`` as the cache-miss marker.
    """
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
    """A faster implementation of functools.lru_cache with no maxsize that uses None as the cache miss indicator.

    This decorator behaves similarly to :func:`~dank_mids.lru_cache_lite` but differs by using
    ``None`` as the default value returned by the cache when a key is missing.
    Consequently, if the decorated function legitimately returns ``None`` for a given input,
    the cache will interpret the cached ``None`` as a miss and will re-evaluate the function.

    **Example:**

        .. code-block:: python

            @lru_cache_lite_nonull
            def might_return_none(x: int) -> int:
                print("Executing might_return_none...")
                return x if x > 0 else None

            # First call with x = -1 triggers a cache miss and function execution.
            result = might_return_none(-1)
            print(result)  # prints "Executing might_return_none..." then None

            # Second call with x = -1 also triggers a cache miss because None is used as the cache-miss marker.
            result = might_return_none(-1)
            print(result)  # prints "Executing might_return_none..." then None

    **Warnings:**
        Use :func:`~dank_mids.lru_cache_lite_nonull` only when it is acceptable that a cached return value
        of ``None`` results in re-execution of the decorated function. If the function may validly return ``None``,
        consider using :func:`~dank_mids.lru_cache_lite` instead.

    **See Also:**
        - :func:`~dank_mids.lru_cache_lite` which uses a unique cache-miss marker.
        - `functools.lru_cache <https://docs.python.org/3/library/functools.html#functools.lru_cache>`_
    """
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