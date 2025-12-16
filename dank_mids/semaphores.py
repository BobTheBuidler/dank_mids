from decimal import Decimal
from typing import Final, Literal, Optional, Type, Union, final

from a_sync.primitives.locks.prio_semaphore import (
    _AbstractPrioritySemaphore,
    _PrioritySemaphoreContextManager,
)
from eth_typing import BlockNumber, HexStr


_TOP_PRIORITY: Final = -1


@final
class _BlockSemaphoreContextManager(_PrioritySemaphoreContextManager):  # type: ignore [type-arg]
    """
    A context manager for block-specific semaphores.

    This class is used internally to manage concurrency for operations
    related to specific blockchain blocks.
    """

    _priority_name: Final = "block"
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


@final
class BlockSemaphore(_AbstractPrioritySemaphore[str, _BlockSemaphoreContextManager]):
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

    _top_priority: Literal[-1]  # type: ignore [assignment]
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
        return super().__getitem__(priority)
