from collections import defaultdict, deque
from typing import DefaultDict, Deque

from dank_mids.retry_observer import RetryEvent
from dank_mids.stats.retry import StatsRetryObserver


class _StubCollector:
    def __init__(self) -> None:
        self.retry_total = 0
        self.retry_counts: DefaultDict[str, int] = defaultdict(int)
        self.retry_error_counts: DefaultDict[str, int] = defaultdict(int)
        self.retry_events: Deque[RetryEvent] = deque(maxlen=1000)
        self.retry_delays: Deque[float] = deque(maxlen=50_000)

    @property
    def retry_error_types(self) -> int:
        return len(self.retry_error_counts)


def test_stats_retry_observer_updates_collector() -> None:
    collector = _StubCollector()
    observer = StatsRetryObserver(collector)
    event = RetryEvent(
        operation="eth_call",
        attempt=2,
        delay=0.25,
        error=RuntimeError("rate limited"),
        component="jsonrpc",
    )

    observer(event)

    assert collector.retry_total == 1
    assert collector.retry_counts["eth_call"] == 1
    assert collector.retry_error_counts["RuntimeError"] == 1
    assert collector.retry_error_types == 1
    assert collector.retry_events[-1] is event
    assert collector.retry_delays[-1] == 0.25
