from asyncio import as_completed
from functools import wraps
from importlib.metadata import version
from typing import (
    TYPE_CHECKING,
    Any,
    Awaitable,
    Callable,
    Coroutine,
    Iterable,
    List,
    Literal,
    Optional,
    TypeVar,
    Union,
)

from eth_utils.curried import apply_formatter_if, apply_formatters_to_dict, apply_key_map
from eth_utils.toolz import assoc, compose, merge
from hexbytes import HexBytes
from multicall.utils import get_async_w3
from typing_extensions import Concatenate, ParamSpec
from web3 import Web3
from web3._utils.rpc_abi import RPC
from web3.datastructures import AttributeDict
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider
from web3.providers.base import BaseProvider
from web3.types import Formatters, FormattersDict, RPCEndpoint, RPCResponse

from dank_mids.eth import DankEth
from dank_mids.types import AsyncMiddleware

if TYPE_CHECKING:
    from dank_mids._requests import JSONRPCBatch, Multicall

    Batch = TypeVar("Batch", "Multicall", "JSONRPCBatch")
else:
    Batch = Union["Multicall", "JSONRPCBatch"]

dank_w3s: List[Web3] = []
"""
A list that stores instances of :class:`Web3` objects that have been set up with Dank Middleware.
This list is used to keep track of all Dank-enabled Web3 instances created in the application.
"""

sync_w3s: List[Web3] = []
"""
A list that stores instances of synchronous Web3 objects.
This list is used to keep track of all synchronous Web3 instances that have been created or modified.
"""

T = TypeVar("T")
"""Generic type variable for use in type hints."""

P = ParamSpec("P")
"""Parameter specification for use in type hints."""

w3_version_major = int(version("web3").split(".")[0])
"""
The major version number of the currently installed web3.py package.
This is extracted from the full version string and stored as an integer for easy comparison.

Example: for `web3==6.0.1`, the major version is 6.
"""


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
    # NOTE: We use this lookup to prevent errs where 2 project dependencies both depend on dank_mids and eth-brownie.
    if async_w3 not in dank_w3s:
        # NOTE: We import here to prevent a circular import
        from dank_mids.middleware import dank_middleware

        async_w3.middleware_onion.inject(dank_middleware, layer=0)
        if _sync_w3_from_async(async_w3).eth.chain_id not in skip_poa_middleware:
            async_w3.middleware_onion.add(geth_poa_middleware)
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
    if sync_w3 not in sync_w3s:
        if w3_version_major >= 6:
            # this was default in prior versions but now optional. We want it.
            __add_sync_attrdict_middleware(sync_w3)
        if sync_w3.eth.chain_id not in skip_poa_middleware:
            __add_sync_poa_middleware(sync_w3)
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


# Everything below is in web3.py now, but dank_mids currently needs a version that predates them.


def is_not_null(obj: Any) -> bool:
    """
    A function that returns True if the input is not null, False otherwise.
    This is the complement of the `is_null` function.
    """
    return obj is not None


FORMATTER_DEFAULTS: FormattersDict = {
    "request_formatters": {},
    "result_formatters": {},
    "error_formatters": {},
}
"""
Default formatters dictionary used in middleware configuration.
It provides empty dictionaries for request, result, and error formatters.
"""

remap_geth_poa_fields = apply_key_map(
    {
        "extraData": "proofOfAuthorityData",
    }
)
"""
A function that remaps Geth Proof of Authority (PoA) fields.
It changes the key 'extraData' to 'proofOfAuthorityData'.
"""

pythonic_geth_poa = apply_formatters_to_dict(
    {
        "proofOfAuthorityData": HexBytes,
    }
)
"""
A function that applies formatters to Geth Proof of Authority (PoA) fields.
It converts the 'proofOfAuthorityData' field to HexBytes.
"""

geth_poa_cleanup = compose(pythonic_geth_poa, remap_geth_poa_fields)
"""
A composed function that applies both remapping and formatting to Geth PoA fields.
It first remaps the fields and then applies the pythonic formatters.
"""


async def geth_poa_middleware(
    make_request: Callable[[RPCEndpoint, Any], Any], w3: Web3
) -> AsyncMiddleware:
    middleware = await async_construct_formatting_middleware(
        result_formatters={
            RPC.eth_getBlockByHash: apply_formatter_if(is_not_null, geth_poa_cleanup),
            RPC.eth_getBlockByNumber: apply_formatter_if(is_not_null, geth_poa_cleanup),
        },
    )
    return await middleware(make_request, w3)  # type: ignore [arg-type, return-value]


async def async_construct_formatting_middleware(
    request_formatters: Optional[Formatters] = None,
    result_formatters: Optional[Formatters] = None,
    error_formatters: Optional[Formatters] = None,
) -> AsyncMiddleware:
    async def ignore_web3_in_standard_formatters(
        _w3: "Web3",
        _method: RPCEndpoint,
    ) -> FormattersDict:
        return dict(
            request_formatters=request_formatters or {},
            result_formatters=result_formatters or {},
            error_formatters=error_formatters or {},
        )

    return await async_construct_web3_formatting_middleware(  # type: ignore [return-value]
        ignore_web3_in_standard_formatters
    )


async def async_construct_web3_formatting_middleware(
    async_web3_formatters_builder: Callable[
        ["Web3", RPCEndpoint], Coroutine[Any, Any, FormattersDict]
    ],
) -> Callable[[Callable[[RPCEndpoint, Any], Any], "Web3"], Coroutine[Any, Any, AsyncMiddleware]]:
    async def formatter_middleware(
        make_request: Callable[[RPCEndpoint, Any], Any],
        async_w3: "Web3",
    ) -> AsyncMiddleware:
        async def middleware(method: RPCEndpoint, params: Any) -> RPCResponse:
            formatters = merge(
                FORMATTER_DEFAULTS,
                await async_web3_formatters_builder(async_w3, method),
            )
            request_formatters = formatters.pop("request_formatters")

            if method in request_formatters:
                formatter = request_formatters[method]
                params = formatter(params)
            response = await make_request(method, params)

            return _apply_response_formatters(method=method, response=response, **formatters)

        return middleware

    return formatter_middleware


def _apply_response_formatters(
    method: RPCEndpoint,
    response: RPCResponse,
    result_formatters: Formatters,
    error_formatters: Formatters,
) -> RPCResponse:
    def _format_response(
        response_type: Literal["result", "error"],
        method_response_formatter: Callable[..., Any],
    ) -> RPCResponse:
        appropriate_response = response[response_type]
        return assoc(response, response_type, method_response_formatter(appropriate_response))

    if "result" in response and method in result_formatters:
        return _format_response("result", result_formatters[method])
    elif "error" in response and method in error_formatters:
        return _format_response("error", error_formatters[method])
    else:
        return response


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


def _make_hashable(obj: Any) -> Any:
    """
    Converts an object into a hashable type if possible.

    This function is used internally to ensure that objects can be used as
    dictionary keys or in sets.

    Args:
        obj: The object to make hashable.
    """
    if isinstance(obj, (list, tuple)):
        return tuple(map(_make_hashable, obj))
    elif isinstance(obj, dict):
        return AttributeDict(zip(obj.keys(), map(_make_hashable, obj.values())))  # type: ignore [arg-type]
    return obj


def __add_sync_attrdict_middleware(sync_w3: Web3) -> None:
    """
    Add the attrdict middleware to a synchronous Web3 instance.

    Args:
        sync_w3: The synchronous Web3 instance to add the middleware to.

    Raises:
        ValueError: If the provided Web3 instance is asynchronous.
    """
    # we do the import here because it is only present in web3 >= 6
    from web3.middleware import attrdict_middleware

    if sync_w3.eth.is_async:
        raise ValueError("You must pass in a sync Web3 instance.")
    try:
        sync_w3.middleware_onion.add(attrdict_middleware)
    except ValueError as e:
        if str(e) != "You can't add the same un-named instance twice":
            raise
        # The middleware is already added


def __add_sync_poa_middleware(sync_w3: Web3) -> None:
    """
    Add the Proof of Authority (PoA) middleware to a synchronous Web3 instance.

    This ensures compatibility with PoA chains.

    Args:
        sync_w3: The synchronous Web3 instance to add the middleware to.
    """
    if w3_version_major >= 7:
        from web3.middleware.proof_of_authority import ExtraDataToPOAMiddleware

        sync_w3.middleware_onion.inject(ExtraDataToPOAMiddleware, layer=0)
    elif w3_version_major >= 6:
        from web3.middleware import geth_poa_middleware

        sync_w3.middleware_onion.inject(geth_poa_middleware, layer=0)
