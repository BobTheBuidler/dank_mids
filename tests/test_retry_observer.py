from dank_mids.retry_observer import (
    RetryEvent,
    emit_retry_event,
    get_retry_observers,
    register_retry_observer,
    unregister_retry_observer,
)


def test_registry_dispatches_and_unregisters() -> None:
    called = {"first": 0, "second": 0}

    def first(event: RetryEvent) -> None:
        called["first"] += 1

    def second(event: RetryEvent) -> None:
        called["second"] += 1

    register_retry_observer(first)
    register_retry_observer(second)
    event = RetryEvent(operation="eth_call", attempt=1, error=RuntimeError("boom"))

    try:
        emit_retry_event(event)
        assert called == {"first": 1, "second": 1}
    finally:
        unregister_retry_observer(first)
        unregister_retry_observer(second)

    emit_retry_event(event)
    assert called == {"first": 1, "second": 1}
    assert first not in get_retry_observers()
    assert second not in get_retry_observers()


def test_observer_exceptions_do_not_break_emit() -> None:
    called = {"ok": 0}

    def boom(event: RetryEvent) -> None:
        raise RuntimeError("boom")

    def ok(event: RetryEvent) -> None:
        called["ok"] += 1

    register_retry_observer(boom)
    register_retry_observer(ok)
    event = RetryEvent(operation="eth_call", attempt=1, error=RuntimeError("boom"))

    try:
        emit_retry_event(event)
        assert called["ok"] == 1
    finally:
        unregister_retry_observer(boom)
        unregister_retry_observer(ok)
