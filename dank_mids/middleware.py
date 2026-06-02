import threading
from typing import Final, cast

from web3 import AsyncWeb3
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
_ControllerKey = tuple[AsyncWeb3, threading.Thread]
_controllers: Final[dict[_ControllerKey, DankMiddlewareController]] = {}

_current_thread: Final = threading.current_thread


class DankMiddleware(Web3Middleware):
    """
    Web3 v7 middleware that routes async requests through a cached Dank controller.
    """

    def __init__(self, w3: AsyncWeb3 | None) -> None:
        # Web3 v7 calls DankMiddleware(None) while naming unnamed class middleware.
        self._w3 = w3

    def __hash__(self) -> int:
        # Keep hashing in compiled code; Web3's base method reads __dict__.
        return hash(f"{type(self).__name__}({self._w3!r})")

    async def async_wrap_make_request(self, make_request: AsyncMakeRequestFn) -> AsyncMakeRequestFn:
        _ = make_request
        async_w3 = self._w3
        if async_w3 is None:
            raise RuntimeError(
                "DankMiddleware(None) is only valid for Web3 middleware naming"
            )
        controller_key = async_w3, _current_thread()
        controller = _controllers.get(controller_key)
        if controller is None:
            controller = DankMiddlewareController(async_w3)
            _controllers[controller_key] = controller
        return cast(AsyncMakeRequestFn, controller)


def _module_getattr(name: str) -> object:
    if name == "dank_middleware":
        raise ImportError(_DANK_MIDDLEWARE_REMOVAL_MESSAGE)
    raise AttributeError(f"module '{__name__}' has no attribute '{name}'")


__getattr__ = _module_getattr  # TODO: remove when mypyc issue 1198 is resolved.
