
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
    return DankMiddlewareController(web3)
""" testing something
    cache_key = web3, current_thread()
    if (cache_key) not in _controllers:
        logger.debug(f"cache key {cache_key} not known to dank mids, starting new controller")
        _controllers[(cache_key)] = DankMiddlewareController(web3)
    return _controllers[(cache_key)]"""
