from typing import TYPE_CHECKING, Any, Final, Generator, Generic, Optional, Union

from mypy_extensions import mypyc_attr

from dank_mids.helpers import DebuggableFuture

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    from dank_mids._batch import DankBatch
    from dank_mids._requests import _Response, JSONRPCBatch, Multicall


__all__ = ["_RequestBase"]


Batch = Union["Multicall", "JSONRPCBatch", "DankBatch"]


@mypyc_attr(native_class=False)
# TODO: replace `native_class` with `supports_weakref` once PR is merged
class _RequestBase(Generic[_Response]):

    __slots__ = "controller", "uid", "_batch", "_fut", "__weakref__"

    def __init__(self, controller: "DankMiddlewareController", uid: Optional[str] = None) -> None:
        self.controller: Final = controller
        """The DankMiddlewareController that created this request."""

        self.uid: Final = controller.call_uid.next if uid is None else uid
        """The unique id for this request."""

        self._batch: Optional[Batch] = None
        self._fut: Final = DebuggableFuture(self, controller._loop)

    def __await__(self) -> Generator[Any, None, _Response]:
        return self.get_response().__await__()

    # Abstract methods to be implemented by subclasses

    def __len__(self) -> int:
        raise NotImplementedError

    async def get_response(self) -> _Response:
        raise NotImplementedError
