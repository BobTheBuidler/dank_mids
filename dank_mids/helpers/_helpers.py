
import asyncio
from functools import wraps
from importlib.metadata import version
from typing import (TYPE_CHECKING, Any, Awaitable, Callable, Coroutine,
                    Iterable, List, Literal, Optional, TypeVar)

from async_lru import alru_cache
from eth_typing import BlockNumber
from eth_utils.curried import (apply_formatter_if, apply_formatters_to_dict,
                               apply_key_map, is_null)
from eth_utils.toolz import assoc, complement, compose, merge
from hexbytes import HexBytes
from multicall.utils import get_async_w3
from typing_extensions import Concatenate, ParamSpec
from web3 import Web3
from web3.datastructures import AttributeDict
from web3._utils.rpc_abi import RPC
from web3.eth import AsyncEth
from web3.providers.async_base import AsyncBaseProvider
from web3.providers.base import BaseProvider
from web3.types import Formatters, FormattersDict, RPCEndpoint, RPCResponse

from dank_mids.types import AsyncMiddleware

if TYPE_CHECKING:
    from dank_mids._requests import _Request

dank_w3s: List[Web3] = []
sync_w3s: List[Web3] = []

T = TypeVar("T")
P = ParamSpec("P")

w3_version_major = int(version("web3").split(".")[0])

class DankEth(AsyncEth):
    @alru_cache(ttl=0)
    async def get_block_number(self) -> BlockNumber:  # type: ignore [override]
        block = await super().get_block_number()  # type: ignore [misc]
        return block
    
class DankWeb3:
    """This is just a helper for type checkers. Your object will just be a modified ``web3.Web3`` object."""
    eth: DankEth

def setup_dank_w3(async_w3: Web3) -> DankWeb3:
    """ Injects Dank Middleware into an async Web3 instance. """
    assert async_w3.eth.is_async and isinstance(async_w3.provider, AsyncBaseProvider)
    # NOTE: We use this lookup to prevent errs where 2 project dependencies both depend on dank_mids and eth-brownie.
    if async_w3 not in dank_w3s:
        # NOTE: We import here to prevent a circular import
        from dank_mids.middleware import dank_middleware
        async_w3.middleware_onion.inject(dank_middleware, layer=0)
        async_w3.middleware_onion.add(geth_poa_middleware)
        dank_w3s.append(async_w3)
    async_w3.eth = DankEth(async_w3)
    return async_w3

def setup_dank_w3_from_sync(sync_w3: Web3) -> DankWeb3:
    """ Creates a new async Web3 instance from `w3.provider.endpoint_uri` and injects it with Dank Middleware. """
    assert not sync_w3.eth.is_async and isinstance(sync_w3.provider, BaseProvider)
    if sync_w3 not in sync_w3s:
        if w3_version_major >= 6:
            from web3.middleware import attrdict_middleware
            try:
                sync_w3.middleware_onion.add(attrdict_middleware)
            except ValueError as e:
                if str(e) != "You can't add the same un-named instance twice":
                    raise e
        if w3_version_major >= 7:
            # we need to make sure our sync w3 instance is compatible with poa chains
            from web3.middleware.proof_of_authority import ExtraDataToPOAMiddleware
            sync_w3.middleware_onion.inject(ExtraDataToPOAMiddleware, layer=0)
        elif w3_version_major >= 6:
            from web3.middleware import geth_poa_middleware
            sync_w3.middleware_onion.inject(geth_poa_middleware, layer=0)
        sync_w3s.append(sync_w3)
    return setup_dank_w3(get_async_w3(sync_w3))

async def await_all(futs: Iterable[Awaitable]) -> None:
    for fut in asyncio.as_completed([*futs]):
        await fut
        del fut

def set_done(fn: Callable[Concatenate["_Request", P], Awaitable[T]]) -> Callable[Concatenate["_Request", P], Awaitable[T]]:
	@wraps(fn)
	async def set_done_wrap(self: "_Request", *args: P.args, **kwargs: P.kwargs) -> T:
		retval = await fn(self, *args, **kwargs)
		self._done.set()
		return retval
	return set_done_wrap

# Everything below is in web3.py now, but dank_mids currently needs a version that predates them.

is_not_null = complement(is_null)

FORMATTER_DEFAULTS: FormattersDict = {
    "request_formatters": {},
    "result_formatters": {},
    "error_formatters": {},
}

remap_geth_poa_fields = apply_key_map(
    {
        "extraData": "proofOfAuthorityData",
    }
)

pythonic_geth_poa = apply_formatters_to_dict(
    {
        "proofOfAuthorityData": HexBytes,
    }
)

geth_poa_cleanup = compose(pythonic_geth_poa, remap_geth_poa_fields)

async def geth_poa_middleware(make_request: Callable[[RPCEndpoint, Any], Any], w3: Web3) -> AsyncMiddleware:
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
    ]
) -> Callable[
    [Callable[[RPCEndpoint, Any], Any], "Web3"], Coroutine[Any, Any, AsyncMiddleware]
]:
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

            return _apply_response_formatters(
                method=method, response=response, **formatters
            )

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
        return assoc(
            response, response_type, method_response_formatter(appropriate_response)
        )

    if "result" in response and method in result_formatters:
        return _format_response("result", result_formatters[method])
    elif "error" in response and method in error_formatters:
        return _format_response("error", error_formatters[method])
    else:
        return response

    
def _make_hashable(obj: Any) -> Any:
    if isinstance(obj, (list, tuple)):
        return tuple((_make_hashable(o) for o in obj))
    elif isinstance(obj, dict):
        return AttributeDict({k: _make_hashable(v) for k, v in obj.items()})
    return obj
