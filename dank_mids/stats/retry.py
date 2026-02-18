from __future__ import annotations

from collections import defaultdict, deque
from typing import DefaultDict, Deque, Final, Protocol, Tuple

from dank_mids.retry_observer import RetryEvent


class _RetryCollector(Protocol):
    retry_total: int
    retry_events: Deque[RetryEvent]
    retry_delays: Deque[float]
    retry_counts: DefaultDict[str, int]
    retry_error_counts: DefaultDict[str, int]

    @property
    def retry_error_types(self) -> int:
        """Return the number of distinct exception types recorded."""


class _RetryStats:
    """In-memory fallback collector for retry stats."""

    def __init__(self) -> None:
        self.retry_total = 0
        self.retry_counts: DefaultDict[str, int] = defaultdict(int)
        self.retry_error_counts: DefaultDict[str, int] = defaultdict(int)
        self.retry_events: Deque[RetryEvent] = deque(maxlen=1000)
        self.retry_delays: Deque[float] = deque(maxlen=50_000)

    @property
    def retry_error_types(self) -> int:
        return len(self.retry_error_counts)


def _ensure_retry_collector(collector: _RetryCollector) -> Tuple[_RetryCollector, bool]:
    """
    Ensure a collector has retry fields.

    Returns:
        A tuple of (collector, using_fallback).
    """

    defaults = {
        "retry_total": lambda: 0,
        "retry_counts": lambda: defaultdict(int),
        "retry_error_counts": lambda: defaultdict(int),
        "retry_events": lambda: deque(maxlen=1000),
        "retry_delays": lambda: deque(maxlen=50_000),
    }
    missing = [name for name in defaults if not hasattr(collector, name)]
    if not missing:
        return collector, False
    if hasattr(collector, "__dict__"):
        for name, factory in defaults.items():
            if not hasattr(collector, name):
                setattr(collector, name, factory())
        return collector, False
    return _RetryStats(), True


class StatsRetryObserver:
    """
    Retry observer that records events into a stats collector.

    When the provided collector lacks retry fields (for example, when the
    compiled stats module is imported), the observer falls back to an internal
    in-memory collector so retry handling does not raise AttributeError.

    This observer intentionally does not auto-register itself. Wire it up
    explicitly via :func:`dank_mids.retry_observer.register_retry_observer`.
    """

    def __init__(self, collector: _RetryCollector | None = None) -> None:
        if collector is None:
            from dank_mids.stats import collector as default_collector

            collector = default_collector
        resolved_collector, using_fallback = _ensure_retry_collector(collector)
        self._collector: Final = resolved_collector
        self._target_collector: Final = collector
        self._using_fallback: Final = using_fallback

    def __call__(self, event: RetryEvent) -> None:
        collector = self._collector
        collector.retry_total += 1
        collector.retry_events.append(event)
        if event.delay is not None:
            collector.retry_delays.append(event.delay)
        collector.retry_counts[event.operation] += 1
        collector.retry_error_counts[type(event.error).__name__] += 1


__all__ = ["StatsRetryObserver"]
