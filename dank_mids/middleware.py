from typing import Final, cast

from mypy_extensions import mypyc_attr
from web3 import AsyncWeb3
from web3.middleware.base import Web3Middleware
from web3.types import AsyncMakeRequestFn

from dank_mids.helpers._controllers import get_controller_for_async_w3
from dank_mids.logging import get_c_logger

logger: Final = get_c_logger(__name__)

__all__ = ["DankMiddleware"]

_DANK_MIDDLEWARE_REMOVAL_MESSAGE: Final = (
    "`dank_middleware` was the pre-web3 v7 function-style middleware and is no "
    "longer supported. Use `from dank_mids.middleware import DankMiddleware` and "
    "`async_w3.middleware_onion.inject(DankMiddleware, layer=0)`, or call "
    "`setup_dank_w3(async_w3)` / `setup_dank_w3_from_sync(sync_w3)`."
)

# TODO: Remove native_class=False once https://github.com/mypyc/mypyc/issues/1200 is fixed.
@mypyc_attr(native_class=False)
class DankMiddleware(Web3Middleware):
    """
    Web3 v7 middleware that routes async requests through a cached Dank controller.
    """

    # Web3 v7 constructs unnamed middleware with None while building middleware names.
    _w3: AsyncWeb3 | None

    def __init__(self, w3: AsyncWeb3 | None) -> None:
        # TODO: Remove this override with native_class=False once mypyc issue #1200 is fixed.
        # The non-native compiled wrapper otherwise exposes a no-arg constructor.
        self._w3 = w3

    def __hash__(self) -> int:
        # TODO: Remove this override with native_class=False once mypyc issue #1200 is fixed.
        # Web3's base hash reads __dict__, which is the fragile compiled-layout path.
        return hash(f"{type(self).__name__}({self._w3!r})")

    async def async_wrap_make_request(self, make_request: AsyncMakeRequestFn) -> AsyncMakeRequestFn:
        async_w3 = self._w3
        if async_w3 is None:
            raise RuntimeError(
                "DankMiddleware(None) is only valid for Web3 middleware naming"
            )
        return cast(AsyncMakeRequestFn, get_controller_for_async_w3(async_w3))


def _module_getattr(name: str) -> object:
    if name == "dank_middleware":
        raise ImportError(_DANK_MIDDLEWARE_REMOVAL_MESSAGE)
    raise AttributeError(f"module '{__name__}' has no attribute '{name}'")


__getattr__ = _module_getattr  # TODO: remove when mypyc issue 1198 is resolved.
