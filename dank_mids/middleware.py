
from typing import Any, Callable

from web3 import Web3
from web3.types import RPCEndpoint, RPCResponse

from dank_mids.semaphore import method_semaphores
from dank_mids.types import AsyncMiddleware


async def dank_middleware(
    make_request: Callable[[RPCEndpoint, Any], Any],
    web3: Web3
) -> AsyncMiddleware:
    # We import here to avoid a circular import issue
    from dank_mids.controller import DankMiddlewareController
    dank_mids = DankMiddlewareController(web3)
    async def middleware(method: RPCEndpoint, params: Any) -> RPCResponse:
        async with method_semaphores[method]:
            if dank_mids.should_batch(method, params):
                return await dank_mids(method, params)
            return await make_request(method, params)
    return middleware
