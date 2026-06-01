import threading
from typing import Final

from web3 import Web3
from web3.middleware import Web3Middleware
from web3.types import AsyncMakeRequestFn

from dank_mids.controller import DankMiddlewareController
from dank_mids.logging import get_c_logger

logger: Final = get_c_logger(__name__)

__all__ = ["DankMiddleware"]

_DANK_MIDDLEWARE_REMOVAL_MESSAGE: Final = (
    "`dank_middleware` was the pre-web3 v7 function-style middleware and is no "
    "longer supported. Use `from dank_mids.middleware import DankMiddleware` and "
    "`async_w3.middleware_onion.inject(DankMiddleware, layer=0)`, or call "
    "`setup_dank_w3(async_w3)` / `setup_dank_w3_from_sync(sync_w3)`."
)

# Each web3 + thread pair gets its own controller
_controllers: Final[dict[tuple[Web3, threading.Thread], DankMiddlewareController]] = {}

_current_thread: Final = threading.current_thread


class DankMiddleware(Web3Middleware):
    """
    Web3 v7 middleware that routes async requests through a cached Dank controller.
    """

    async def async_wrap_make_request(self, make_request: AsyncMakeRequestFn) -> AsyncMakeRequestFn:
        _ = make_request
        async_w3 = self._w3
        controller_key = async_w3, _current_thread()
        controller = _controllers.get(controller_key)
        if controller is None:
            controller = DankMiddlewareController(async_w3)
            _controllers[controller_key] = controller
        return controller


def _module_getattr(name: str) -> object:
    if name == "dank_middleware":
        raise ImportError(_DANK_MIDDLEWARE_REMOVAL_MESSAGE)
    raise AttributeError(f"module '{__name__}' has no attribute '{name}'")


__getattr__ = _module_getattr  # TODO: remove when mypyc issue 1198 is resolved.
