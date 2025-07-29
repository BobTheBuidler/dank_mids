import asyncio

from typing import TYPE_CHECKING, Final, Generic, Union, final
from weakref import ProxyType, proxy

import a_sync

if TYPE_CHECKING:
    from dank_mids._requests import _RequestBase, _Response


_get_running_loop: Final = asyncio.get_running_loop
_super_init: Final = a_sync.Event.__init__
_super_set: Final = a_sync.Event.set


@final
class RequestEvent(a_sync.Event, Generic["_RequestBase[_Response]"]):  # type: ignore [misc]
    # default if no debug logs enabled
    _owner: Union[str, ProxyType["_RequestBase[_Response]"]] = "[not displayed...]"  # type: ignore [valid-type]

    def __init__(self, owner: "_RequestBase[_Response]") -> None:
        _super_init(self, debug_daemon_interval=300)
        if self.debug_logs_enabled:
            self._owner = proxy(owner)

    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} object at {hex(id(self))} [{'set' if self.is_set() else 'unset'}, waiter:{self._owner}>"

    def set(self) -> None:
        # Make sure we wake up the _RequestEvent's event loop if its in another thread
        if self._loop is _get_running_loop():
            _super_set(self)
        else:
            self._loop.call_soon_threadsafe(_super_set, self)
