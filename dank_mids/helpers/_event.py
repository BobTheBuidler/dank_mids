import asyncio
import weakref
from typing import Final, final

import a_sync

from dank_mids.types import T


_get_running_loop: Final = asyncio.get_running_loop
_super_init: Final = a_sync.Event.__init__
_super_set: Final = a_sync.Event.set


@final
class RequestEvent(a_sync.Event):
    _owner: Final[weakref.ProxyType[T]]
    _owner_in_repr: Final[bool]
    
    def __init__(self, owner: T) -> None:
        _super_init(self, debug_daemon_interval=300)
        if self.debug_logs_enabled:
            self._owner_in_repr = True
            self._owner = weakref.proxy(owner)
        else:
            self._owner_in_repr = False

    def __repr__(self) -> str:
=        owner_info = ", waiter:{self._owner}" if self._owner_in_repr else ""
        return f"<{self.__class__.__name__} object at {hex(id(self))} [{'set' if self.is_set() else 'unset'}{owner_info}>"

    def set(self) -> None:
        # Make sure we wake up the _RequestEvent's event loop if its in another thread
        if self._loop is _get_running_loop():
            _super_set(self)
        else:
            self._loop.call_soon_threadsafe(_super_set, self)
