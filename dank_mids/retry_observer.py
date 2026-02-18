from __future__ import annotations

from dataclasses import dataclass, field
from time import time
from typing import Final, Protocol

from dank_mids.helpers._weaklist import WeakList
from dank_mids.logging import get_c_logger


@dataclass(frozen=True, slots=True)
class RetryEvent:
    """
    Represents a single retry decision emitted by Dank Mids retry logic.

    Attributes:
        operation: Human-readable identifier for the operation being retried.
        attempt: The 1-based retry attempt number (the first retry attempt is 1).
        error: The exception that triggered the retry decision.
        max_attempts: Optional maximum attempts configured by the caller.
        delay: Optional delay (seconds) before the next attempt.
        component: Optional subsystem name (for example: "jsonrpc" or "multicall").
        will_retry: Whether the caller intends to retry after this event.
        metadata: Optional key/value tags for downstream logging or metrics.
        timestamp: Unix timestamp when the event was created.
    """

    operation: str
    attempt: int
    error: BaseException
    max_attempts: int | None = None
    delay: float | None = None
    component: str | None = None
    will_retry: bool = True
    metadata: dict[str, str] | None = None
    timestamp: float = field(default_factory=time)


class RetryObserver(Protocol):
    """
    Callable observer interface for retry events.

    Implementations should be fast and side-effect safe. If you need to do IO,
    buffer the event and ship it elsewhere.
    """

    def __call__(self, event: RetryEvent) -> None:
        """Handle a retry event."""


_RETRY_OBSERVERS: Final[WeakList[RetryObserver]] = WeakList()
logger: Final = get_c_logger("dank_mids.retry_observer")


def register_retry_observer(observer: RetryObserver) -> None:
    """
    Register a retry observer.

    Observers are stored as weak references. Keep a strong reference in your
    application if you do not want it to be garbage collected.
    """

    _RETRY_OBSERVERS.append(observer)


def unregister_retry_observer(observer: RetryObserver) -> None:
    """
    Unregister a previously registered retry observer.

    Raises:
        ValueError: If the observer is not currently registered.
    """

    _RETRY_OBSERVERS.remove(observer)


def get_retry_observers() -> tuple[RetryObserver, ...]:
    """Return a snapshot of currently registered retry observers."""

    return _RETRY_OBSERVERS.snapshot()


def emit_retry_event(event: RetryEvent) -> None:
    """
    Emit a retry event to all currently registered observers.

    Observers are called in the order they were registered. A snapshot is taken
    to avoid iteration issues if observers register/unregister themselves.
    """

    for observer in _RETRY_OBSERVERS.snapshot():
        try:
            observer(event)
        except Exception:
            logger.exception("Retry observer %r failed", observer)


__all__ = [
    "RetryEvent",
    "RetryObserver",
    "emit_retry_event",
    "get_retry_observers",
    "register_retry_observer",
    "unregister_retry_observer",
]
