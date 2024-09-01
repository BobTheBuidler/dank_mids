
import logging
from threading import Thread, current_thread
from typing import Any, Callable, Dict, Tuple

from web3 import Web3
from web3.types import RPCEndpoint

from dank_mids.controller import DankMiddlewareController
from dank_mids.types import AsyncMiddleware

_controllers: Dict[Tuple[Web3, Thread], DankMiddlewareController] = {}

logger = logging.getLogger(__name__)

async def dank_middleware(
    make_request: Callable[[RPCEndpoint, Any], Any],
    web3: Web3
) -> AsyncMiddleware:
    """
    Create and return a :class:`DankMiddlewareController` instance for an asynchronous :class:`~Web3`.

    This function is used to create a middleware instance that can be added to an
    asynchronous Web3 object.

    Args:
        make_request: The next middleware in the chain or the actual request sender.
        web3: The synchronous Web3 instance this middleware is attached to.

    Returns:
        An AsyncMiddleware function that can be used with synchronous Web3.
    """
    return DankMiddlewareController(web3)
