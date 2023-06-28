
from typing import Any, Callable

from web3 import Web3
from web3.types import RPCEndpoint

from dank_mids.controller import DankMiddlewareController
from dank_mids.types import AsyncMiddleware


async def dank_middleware(
    make_request: Callable[[RPCEndpoint, Any], Any],
    web3: Web3
) -> AsyncMiddleware:
    return DankMiddlewareController(web3)
