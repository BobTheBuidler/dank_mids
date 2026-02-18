from dank_mids import stats
from dank_mids.retry_observer import RetryEvent
from dank_mids.stats.retry import StatsRetryObserver


def test_stats_retry_observer_updates_collector() -> None:
    observer = StatsRetryObserver()
    event = RetryEvent(
        operation="eth_call",
        attempt=2,
        delay=0.25,
        error=RuntimeError("rate limited"),
        component="jsonrpc",
    )

    observer(event)

    collector = observer._collector
    assert collector.retry_total == 1
    assert collector.retry_counts["eth_call"] == 1
    assert collector.retry_error_counts["RuntimeError"] == 1
    assert collector.retry_error_types == 1
    assert collector.retry_events[-1] is event
    assert collector.retry_delays[-1] == 0.25

    if hasattr(stats.collector, "retry_total"):
        assert stats.collector.retry_total == 1
        assert observer._using_fallback is False
    else:
        assert collector is not stats.collector
        assert observer._using_fallback is True
