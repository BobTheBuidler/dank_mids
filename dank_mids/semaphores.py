
import logging
from typing import TYPE_CHECKING, Literal, Union

from a_sync.primitives import DummySemaphore, ThreadsafeSemaphore
from a_sync.primitives.locks.prio_semaphore import (
    _AbstractPrioritySemaphore, _PrioritySemaphoreContextManager)
from web3.types import RPCEndpoint

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


class _BlockSemaphoreContextManager(_PrioritySemaphoreContextManager):
    _priority_name = "block"
    
class BlockSemaphore(_AbstractPrioritySemaphore[str, _BlockSemaphoreContextManager]):
    _context_manager_class = _BlockSemaphoreContextManager
    _top_priority = -1
    def __getitem__(self, block: Union[int, str, Literal["latest", None]]) -> "_BlockSemaphoreContextManager":
        return super().__getitem__(
            block if isinstance(block, int)
            else int(block.hex(), 16) if isinstance(block, bytes)
            else int(block, 16) if isinstance(block, str) and "0x" in block
            else block if block not in [None, 'latest']  # NOTE: We do this to generate an err if an unsuitable value was provided
            else self._top_priority
        )


class _MethodSemaphores:
    def __init__(self, controller: "DankMiddlewareController") -> None:
        from dank_mids import ENVIRONMENT_VARIABLES
        self.controller = controller
        self.method_semaphores = {
            method: (BlockSemaphore if method == "eth_call" else ThreadsafeSemaphore)(sem._value, name=f"{method} {controller}") 
            for method, sem in ENVIRONMENT_VARIABLES.method_semaphores.items()
        }
        self.keys = self.method_semaphores.keys()
        self.dummy = DummySemaphore()
    
    def __getitem__(self, method: RPCEndpoint) -> Union[ThreadsafeSemaphore, DummySemaphore]:
        return next((self.method_semaphores[key] for key in self.keys if key in method), self.dummy)
