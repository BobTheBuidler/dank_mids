from collections.abc import Awaitable, Callable
from functools import wraps
from typing import TYPE_CHECKING, Concatenate, TypeVar, Union

from multicall.utils import get_async_w3
from typing_extensions import ParamSpec
from web3 import Web3
from web3.middleware import AttributeDictMiddleware, ExtraDataToPOAMiddleware
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider
from web3.providers.base import BaseProvider

from dank_mids.eth import DankEth

if TYPE_CHECKING:
    from dank_mids._requests import JSONRPCBatch, Multicall

    Batch = TypeVar("Batch", "Multicall", "JSONRPCBatch")
else:
    Batch = Union["Multicall", "JSONRPCBatch"]

dank_w3s: list[Web3] = []
"""
A list that stores instances of :class:`Web3` objects that have been set up with Dank Middleware.
This list is used to keep track of all Dank-enabled Web3 instances created in the application.
"""

sync_w3s: list[Web3] = []
"""
A list that stores instances of synchronous Web3 objects.
This list is used to keep track of all synchronous Web3 instances that have been created or modified.
"""

T = TypeVar("T")
"""Generic type variable for use in type hints."""

P = ParamSpec("P")
"""Parameter specification for use in type hints."""


class DankWeb3:
    """This is just a helper for type checkers. Your object will just be a modified :class:`~web3.Web3` object."""

    eth: DankEth


skip_poa_middleware = {
    1,  # eth mainnet
}
"""
By default, we include the poa middleware on all chains to prevent issues. 
But when we don't need it, we can remove it by adding the chainid to this set.
"""


def setup_dank_w3(async_w3: Web3) -> DankWeb3:
    """
    Sets up a DankWeb3 instance from a given Web3 instance.

    Args:
        async_w3: The Web3 instance to be wrapped.

    Returns:
        A new DankWeb3 instance with Dank Middleware injected.
    """
    assert async_w3.eth.is_async and isinstance(async_w3.provider, AsyncBaseProvider)
    from dank_mids import _ensure_side_effects

    _ensure_side_effects()
    # NOTE: We use this lookup to prevent errs where 2 project dependencies both depend on dank_mids and eth-brownie.
    if async_w3 not in dank_w3s:
        # NOTE: We import here to prevent a circular import
        from dank_mids.middleware import DankMiddleware

        if _sync_w3_from_async(async_w3).eth.chain_id not in skip_poa_middleware:
            async_w3.middleware_onion.inject(ExtraDataToPOAMiddleware, layer=0)
        async_w3.middleware_onion.inject(DankMiddleware, layer=0)
        dank_w3s.append(async_w3)
    async_w3.eth = DankEth(async_w3)
    return async_w3


def setup_dank_w3_from_sync(sync_w3: Web3) -> DankWeb3:
    """
    Sets up a DankWeb3 instance from a given synchronous Web3 instance.

    Args:
        sync_w3: The synchronous Web3 instance to be wrapped.

    Returns:
        A new DankWeb3 instance with Dank Middleware injected, supporting batched asynchronous operations.
    """
    assert not sync_w3.eth.is_async and isinstance(sync_w3.provider, BaseProvider)
    from dank_mids import _ensure_side_effects

    _ensure_side_effects()
    if sync_w3 not in sync_w3s:
        middleware_onion = sync_w3.middleware_onion
        if AttributeDictMiddleware not in middleware_onion:
            middleware_onion.add(AttributeDictMiddleware)
        if (
            sync_w3.eth.chain_id not in skip_poa_middleware
            and ExtraDataToPOAMiddleware not in middleware_onion
        ):
            middleware_onion.inject(ExtraDataToPOAMiddleware, layer=0)
        sync_w3s.append(sync_w3)
    return setup_dank_w3(get_async_w3(sync_w3))


def set_done(
    fn: Callable[Concatenate[Batch, P], Awaitable[T]],
) -> Callable[Concatenate[Batch, P], Awaitable[T]]:
    """
    A decorator that sets the '_done' flag of a _Request object after the decorated function completes.

    Args:
        fn: The function to be decorated.

    Returns:
        A wrapped version of the input function that sets the '_done' flag.
    """

    @wraps(fn)
    async def set_done_wrap(self: Batch, *args: P.args, **kwargs: P.kwargs) -> T:
        retval = await fn(self, *args, **kwargs)
        self._done.set()
        return retval

    return set_done_wrap


def _sync_w3_from_async(w3: Web3) -> Web3:
    """
    Creates a synchronous Web3 instance from an asynchronous one.

    This function is used internally to create a sync Web3 instance
    for operations that require synchronous execution.

    Args:
        w3: An asynchronous Web3 instance.

    Returns:
        A synchronous Web3 instance with the same endpoint URI.

    Raises:
        ValueError: If the input Web3 instance is not asynchronous.
    """
    if not w3.eth.is_async or not isinstance(w3.provider, AsyncBaseProvider):
        raise ValueError("Dank Middleware can only be applied to an asynchronous Web3 instance.")
    sync_provider = HTTPProvider(w3.provider.endpoint_uri)
    sync_w3: Web3 = Web3(provider=sync_provider)
    # We can't pickle middlewares to send to process executor.
    # The call has already passed thru all middlewares on the user's Web3 instance.
    sync_w3.middleware_onion.clear()
    sync_w3.provider.middlewares = ()
    return sync_w3
