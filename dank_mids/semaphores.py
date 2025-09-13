from decimal import Decimal
from typing import TYPE_CHECKING, Final, Literal, Optional, Type, Union

from a_sync import SmartProcessingQueue
from a_sync.primitives.locks.prio_semaphore import (
    _AbstractPrioritySemaphore,
    _PrioritySemaphoreContextManager,
)
from eth_typing import BlockNumber, HexStr
from mypy_extensions import mypyc_attr
from web3.types import RPCEndpoint

from dank_mids.helpers.lru_cache import lru_cache_lite

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


class _BlockSemaphoreContextManager(_PrioritySemaphoreContextManager):  # type: ignore [misc]
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


_TOP_PRIORITY: Final = -1


# NOTE: keep this so we can include in type stubs
# class BlockSemaphore(_AbstractPrioritySemaphore[str, _BlockSemaphoreContextManager]):  # type: ignore [type-var]
@mypyc_attr(native_class=False)
class BlockSemaphore(_AbstractPrioritySemaphore):  # type: ignore [misc]
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

    def __init__(
        self,
        value: BlockNumber = BlockNumber(1),
        *,
        name: Optional[str] = None,
    ) -> None:
        super().__init__(_BlockSemaphoreContextManager, -1, int(value), name=name)

    def __getitem__(self, block: Union[int, HexStr, Literal["latest", None]]) -> "_BlockSemaphoreContextManager":  # type: ignore [override]
        if isinstance(block, int):
            priority = block
        elif isinstance(block, bytes):
            priority = int(block.hex(), 16)
        elif isinstance(block, str) and "0x" in block:
            priority = int(block, 16)
        elif block not in {None, "latest"}:
            # NOTE: We do this to generate an err if an unsuitable value was provided
            priority = block  # type: ignore [assignment]
        else:
            priority = _TOP_PRIORITY
        return super().__getitem__(priority)  # type: ignore [return-value, no-any-return]


class _MethodQueues:
    """
    A class that manages queues for different RPC methods.

    This class creates and stores SmartProcessingQueues for various RPC methods,
    allowing for controlled processing of method calls.
    """

    def __init__(self, controller: "DankMiddlewareController") -> None:
        from dank_mids import ENVIRONMENT_VARIABLES
        from dank_mids._requests import RPCRequest

        self.controller: Final = controller
        """
        A reference to the DankMiddlewareController instance that this _MethodQueues is associated with.
        """

        self.method_queues: Final = {
            method: SmartProcessingQueue(
                RPCRequest, num_workers=sem._value, name=f"{method} {controller}"
            )
            for method, sem in ENVIRONMENT_VARIABLES.method_semaphores.items()
            if method != "eth_call"
        }
        """
        A dictionary mapping RPC method names to their corresponding SmartProcessingQueues.
        These queues are used to manage and process requests for different RPC methods.
        """

        self.keys: Final = tuple(self.method_queues.keys())
        """
        A view of the keys (RPC method names) in the method_queues dictionary.
        This allows for efficient iteration over the available method names.
        """

    @lru_cache_lite
    def __getitem__(self, method: RPCEndpoint) -> Optional[SmartProcessingQueue]:
        """
        Retrieves the queue for a given RPC method.

        Args:
            method: The RPC method to get the queue for.

        Returns:
            The queue for the method, or None if no specific queue is found.
        """
        return next(
            (self.method_queues[key] for key in self.keys if key in method),
            None,
        )
