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
    make_request: Callable[[RPCEndpoint, Any], Any], web3: Web3
) -> AsyncMiddleware:
    """
    Creates and returns a DankMiddlewareController middleware function for an asynchronous Web3 instance.

    This function initializes the DankMiddlewareController that batches and processes JSON-RPC
    requests for asynchronous Web3 calls. It is intended to be added to the middleware onion
    of an asynchronous Web3 instance to optimize large-scale blockchain operations.

    Args:
        make_request: The next middleware callable in the chain or the actual request sender.
        web3: The asynchronous Web3 instance to which the middleware will be attached.
            Must be an instance of :class:`~web3.AsyncWeb3`.

    Returns:
        An asynchronous middleware callable that can be used with an asynchronous Web3 instance.

    Examples:
        Setting up Dank Mids middleware with an asynchronous Web3 instance:

        >>> from web3 import AsyncWeb3, HTTPProvider
        >>> from dank_mids.middleware import dank_middleware
        >>> w3 = AsyncWeb3(HTTPProvider("http://localhost:8545"))
        >>> # Inject Dank Mids at the lowest layer so that all calls are batched.
        >>> w3.middleware_onion.inject(dank_middleware, layer=0)
        >>> # Now calling any method uses Dank Mids batching.
        >>> block = await w3.eth.get_block("latest")

        Another example demonstrating the middleware injection:

        >>> from web3 import AsyncWeb3, WebsocketProvider
        >>> from dank_mids.middleware import dank_middleware
        >>> async_w3 = AsyncWeb3(WebsocketProvider("ws://localhost:8546"))
        >>> async_w3.middleware_onion.add(dank_middleware)
        >>> # Retrieve the latest block asynchronously with the middleware active.
        >>> latest = await async_w3.eth.get_block("latest")

    See Also:
        :class:`dank_mids.controller.DankMiddlewareController`: Manages batched JSON-RPC requests.
        :class:`~web3.AsyncWeb3`: The asynchronous Web3 class.
    """
    return DankMiddlewareController(web3)