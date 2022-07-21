
from typing import Any, Callable

from web3 import Web3
from web3.types import RPCEndpoint, RPCResponse

from dank_mids.controller import DankMiddlewareController
from dank_mids.types import AsyncMiddleware


async def dank_middleware(
    make_request: Callable[[RPCEndpoint, Any], Any],
    web3: Web3
) -> AsyncMiddleware:
    dank_mids = DankMiddlewareController(web3)
    async def middleware(method: RPCEndpoint, params: Any) -> RPCResponse:
        if not dank_mids._is_configured and dank_mids.should_batch(method, params):
            await dank_mids._setup()
        if dank_mids.should_batch(method, params):
            return await dank_mids(params)
        return await make_request(method, params)
    return middleware
