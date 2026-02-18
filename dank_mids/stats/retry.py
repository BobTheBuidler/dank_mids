from __future__ import annotations

from typing import DefaultDict, Deque, Final, Protocol

from dank_mids.retry_observer import RetryEvent


class _RetryCollector(Protocol):
    retry_total: int
    retry_events: Deque[RetryEvent]
    retry_delays: Deque[float]
    retry_counts: DefaultDict[str, int]
    retry_error_counts: DefaultDict[str, int]


class StatsRetryObserver:
    """
    Retry observer that records events into a stats collector.

    This observer intentionally does not auto-register itself. Wire it up
    explicitly via :func:`dank_mids.retry_observer.register_retry_observer`.
    """

    def __init__(self, collector: _RetryCollector | None = None) -> None:
        if collector is None:
            from dank_mids.stats import collector as default_collector

            collector = default_collector
        self._collector: Final = collector

    def __call__(self, event: RetryEvent) -> None:
        collector = self._collector
        collector.retry_total += 1
        collector.retry_events.append(event)
        if event.delay is not None:
            collector.retry_delays.append(event.delay)
        collector.retry_counts[event.operation] += 1
        collector.retry_error_counts[type(event.error).__name__] += 1


__all__ = ["StatsRetryObserver"]
