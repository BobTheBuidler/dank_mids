"""Keep middleware calls on the same per-Web3/thread controller."""

import threading
from typing import TYPE_CHECKING, Final

from web3 import AsyncWeb3

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


_ControllerKey = tuple[AsyncWeb3, threading.Thread]
_controllers: Final[dict[_ControllerKey, "DankMiddlewareController"]] = {}

_current_thread: Final = threading.current_thread


def get_controller_for_async_w3(async_w3: AsyncWeb3) -> "DankMiddlewareController":
    controller_key = async_w3, _current_thread()
    controller = _controllers.get(controller_key)
    if controller is None:
        from dank_mids.controller import DankMiddlewareController

        controller = DankMiddlewareController(async_w3)
        _controllers[controller_key] = controller
    return controller
