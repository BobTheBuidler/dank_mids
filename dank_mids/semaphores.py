import functools
from decimal import Decimal
from typing import TYPE_CHECKING, Literal, Optional, Type, Union

import a_sync
from a_sync.primitives import DummySemaphore, ThreadsafeSemaphore
from a_sync.primitives.locks.prio_semaphore import (
    _AbstractPrioritySemaphore,
    _PrioritySemaphoreContextManager,
)
from eth_typing import HexStr
from web3.types import RPCEndpoint

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


class _BlockSemaphoreContextManager(_PrioritySemaphoreContextManager):
    """
    A context manager for block-specific semaphores.

    This class is used internally to manage concurrency for operations
    related to specific blockchain blocks.
    """

    _priority_name = "block"
    """The noun that describes the priority, set to "block"."""

    def __init__(
        self,
        parent: "BlockSemaphore",
        priority: Union[int, float, Decimal],
        name: Optional[str] = None,
    ) -> None:
        if not isinstance(priority, (int, float, Decimal)):
            raise TypeError(priority)
        super().__init__(parent, priority, name)


_TOP_PRIORITY = -1

# NOTE: keep this so we can include in type stubs
# class BlockSemaphore(_AbstractPrioritySemaphore[str, _BlockSemaphoreContextManager]):  # type: ignore [type-var]
class BlockSemaphore(_AbstractPrioritySemaphore):
    """A semaphore for managing concurrency based on block numbers.

    This class extends :class:`_AbstractPrioritySemaphore` to provide block-specific concurrency control.

    Args:
        value: The initial value of the semaphore.
        name: An optional name for the semaphore.

    See Also:
        :class:`_BlockSemaphoreContextManager`: The context manager used by this semaphore.
    """

    _context_manager_class: Type[_BlockSemaphoreContextManager]
    """The context manager class used by this semaphore."""

    _top_priority: Literal[-1]
    """The highest priority value, set to -1."""
    
    def __init__(self, value = 1, *, name = None):
        super().__init__(_BlockSemaphoreContextManager, -1, value, name=name)

    def __getitem__(self, block: Union[int, HexStr, Literal["latest", None]]) -> "_BlockSemaphoreContextManager":  # type: ignore [override]
        if isinstance(block, int):
            priority = block
        elif isinstance(block, bytes):
            priority = int(block.hex(), 16)
        elif isinstance(block, str) and "0x" in block:
            priority = int(block, 16)
        elif block not in [None, "latest"]:
            # NOTE: We do this to generate an err if an unsuitable value was provided
            priority = block
        else:
            priority = _TOP_PRIORITY
        return super().__getitem__(priority)


class _MethodSemaphores:
    """
    A class that manages semaphores for different RPC methods.

    This class creates and stores semaphores for various RPC methods,
    allowing for controlled concurrency in method execution.
    """

    def __init__(self, controller: "DankMiddlewareController") -> None:
        # TODO: refactor this out, just use BlockSemaphore for eth_call and SmartProcessingQueue to limit other methods
        from dank_mids import ENVIRONMENT_VARIABLES

        self.controller = controller
        semaphore_types = {"eth_call": BlockSemaphore}
        self.method_semaphores = {
            method: semaphore_types.get(method, ThreadsafeSemaphore)(
                sem._value, name=f"{method} {controller}"
            )
            for method, sem in ENVIRONMENT_VARIABLES.method_semaphores.items()
        }
        self.keys = self.method_semaphores.keys()
        self.dummy = DummySemaphore()

    @functools.lru_cache(maxsize=None)
    def __getitem__(self, method: RPCEndpoint) -> Union[ThreadsafeSemaphore, DummySemaphore]:
        """
        Retrieves the semaphore for a given RPC method.

        Args:
            method: The RPC method to get the semaphore for.

        Returns:
            The semaphore for the method, or a DummySemaphore if no semaphore matching any substring in
            the method string is found.
        """
        return next((self.method_semaphores[key] for key in self.keys if key in method), self.dummy)


class _MethodQueues:
    """
    A class that manages queues for different RPC methods.

    This class creates and stores SmartProcessingQueues for various RPC methods,
    allowing for controlled processing of method calls.
    """

    def __init__(self, controller: "DankMiddlewareController") -> None:
        from dank_mids import ENVIRONMENT_VARIABLES
        from dank_mids._requests import RPCRequest

        self.controller = controller
        """
        A reference to the DankMiddlewareController instance that this _MethodQueues is associated with.
        """

        self.method_queues = {
            method: a_sync.SmartProcessingQueue(
                RPCRequest, num_workers=sem._value, name=f"{method} {controller}"
            )
            for method, sem in ENVIRONMENT_VARIABLES.method_semaphores.items()
            if method != "eth_call"
        }
        """
        A dictionary mapping RPC method names to their corresponding SmartProcessingQueues.
        These queues are used to manage and process requests for different RPC methods.
        """

        self.keys = self.method_queues.keys()
        """
        A view of the keys (RPC method names) in the method_queues dictionary.
        This allows for efficient iteration over the available method names.
        """

    @functools.lru_cache(maxsize=None)
    def __getitem__(self, method: RPCEndpoint) -> Optional[a_sync.SmartProcessingQueue]:
        """
        Retrieves the queue for a given RPC method.

        Args:
            method: The RPC method to get the queue for.

        Returns:
            The queue for the method, or None if no specific queue is found.
        """
        try:
            return next(self.method_queues[key] for key in self.keys if key in method)
        except StopIteration:
            return None
