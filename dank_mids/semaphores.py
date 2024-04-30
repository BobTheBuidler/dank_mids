
import functools
from decimal import Decimal
from typing import TYPE_CHECKING, Literal, Optional, Union

import a_sync
from a_sync.primitives import DummySemaphore, ThreadsafeSemaphore
from a_sync.primitives.locks.prio_semaphore import (
    _AbstractPrioritySemaphore, _PrioritySemaphoreContextManager)
from web3.types import RPCEndpoint

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


class _BlockSemaphoreContextManager(_PrioritySemaphoreContextManager):
    _priority_name = "block"
    def __init__(self, parent: "BlockSemaphore", priority: Union[int, float, Decimal], name: Optional[str] = None) -> None:
        if not isinstance(priority, (int, float, Decimal)):
            raise TypeError(priority)
        super().__init__(parent, priority, name)
    
class BlockSemaphore(_AbstractPrioritySemaphore[str, _BlockSemaphoreContextManager]):  # type: ignore [type-var]
    _context_manager_class = _BlockSemaphoreContextManager  # type: ignore [assignment]
    _top_priority: int = -1  # type: ignore [assignment]
    def __getitem__(self, block: Union[int, str, Literal["latest", None]]) -> "_BlockSemaphoreContextManager":  # type: ignore [override]
        return super().__getitem__(  # type: ignore [return-value]
            block if isinstance(block, int)  # type: ignore [index]
            else int(block.hex(), 16) if isinstance(block, bytes)  # type: ignore [union-attr]
            else int(block, 16) if isinstance(block, str) and "0x" in block
            else block if block not in [None, 'latest']  # NOTE: We do this to generate an err if an unsuitable value was provided
            else self._top_priority
        )  # type: ignore [index]


class _MethodSemaphores:
    def __init__(self, controller: "DankMiddlewareController") -> None:
        # TODO: refactor this out, just use BlockSemaphore for eth_call and SmartProcessingQueue to limit other methods
        from dank_mids import ENVIRONMENT_VARIABLES
        self.controller = controller
        self.method_semaphores = {
            method: (BlockSemaphore if method == "eth_call" else ThreadsafeSemaphore)(sem._value, name=f"{method} {controller}") 
            for method, sem in ENVIRONMENT_VARIABLES.method_semaphores.items()
        }
        self.keys = self.method_semaphores.keys()
        self.dummy = DummySemaphore()
    @functools.lru_cache(maxsize=None)
    def __getitem__(self, method: RPCEndpoint) -> Union[ThreadsafeSemaphore, DummySemaphore]:
        return next((self.method_semaphores[key] for key in self.keys if key in method), self.dummy)

class _MethodQueues:
    def __init__(self, controller: "DankMiddlewareController") -> None:
        from dank_mids import ENVIRONMENT_VARIABLES
        from dank_mids._requests import RPCRequest
        self.controller = controller
        self.method_queues = {
            method: a_sync.SmartProcessingQueue(RPCRequest, num_workers=sem._value, name=f"{method} {controller}")
            for method, sem in ENVIRONMENT_VARIABLES.method_semaphores.items()
            if method != "eth_call"
        }
        self.keys = self.method_queues.keys()
    @functools.lru_cache(maxsize=None)
    def __getitem__(self, method: RPCEndpoint) -> a_sync.SmartProcessingQueue:
        try:
            return next(self.method_queues[key] for key in self.keys if key in method)
        except StopIteration:
            raise KeyError(method) from None
