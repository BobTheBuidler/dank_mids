

from typing import Any, Callable, Coroutine, Literal, Optional

from eth_utils.toolz import assoc, merge
from web3.types import Formatters, FormattersDict, RPCEndpoint, RPCResponse

from dank_mids.types import AsyncMiddleware
from web3 import Web3

FORMATTER_DEFAULTS: FormattersDict = {
    "request_formatters": {},
    "result_formatters": {},
    "error_formatters": {},
}

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

            response = await make_request(
                method,
                request_formatters[method](params) if method in request_formatters else params,
            )

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