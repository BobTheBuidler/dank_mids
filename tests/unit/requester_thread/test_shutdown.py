from __future__ import annotations

import asyncio
import threading
import time
from collections.abc import Callable, Coroutine
from concurrent.futures import Future, TimeoutError

import pytest

from dank_mids.helpers import _requester as requester_module
from dank_mids.helpers._requester import HTTPRequesterThread
from dank_mids.helpers._session import DankClientSession

from ._helpers import ClosableSession, InlineLoop, run_coroutine_now


def _make_requester_look_alive(requester: HTTPRequesterThread) -> list[float | None]:
    join_timeouts: list[float | None] = []
    requester.is_alive = lambda: True
    requester.join = lambda timeout=None: join_timeouts.append(timeout)
    return join_timeouts


def _wait_until(predicate: Callable[[], bool], *, timeout: float = 2.0) -> None:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        if predicate():
            return
        time.sleep(0.01)
    raise AssertionError("condition was not reached before timeout")


class _ScheduledCloseRaisesTimeout:
    def __init__(self, coro: Coroutine[None, None, None]) -> None:
        self._coro = coro

    def result(self, timeout: float | None = None) -> None:
        del timeout
        asyncio.run(self._coro)
        raise TimeoutError


class _ScheduledCloseRaisesRuntimeError:
    def __init__(self, coro: Coroutine[None, None, None]) -> None:
        self._coro = coro

    def result(self, timeout: float | None = None) -> None:
        del timeout
        asyncio.run(self._coro)
        raise RuntimeError("close wait failed")


def test_shutdown_does_not_schedule_noop_session_close_when_session_missing(
    monkeypatch: pytest.MonkeyPatch,
    requester_thread: HTTPRequesterThread,
) -> None:
    requester_thread.loop = InlineLoop()
    requester_thread._session = None
    join_timeouts = _make_requester_look_alive(requester_thread)
    assert requester_thread._session is None

    def fail_run_coroutine_threadsafe(
        coro: Coroutine[None, None, None],
        loop: asyncio.AbstractEventLoop,
    ) -> None:
        del loop
        coro.close()
        raise AssertionError("shutdown should not schedule a no-op session close")

    monkeypatch.setattr(
        requester_module.asyncio,
        "run_coroutine_threadsafe",
        fail_run_coroutine_threadsafe,
    )

    requester_module.shutdown_http_requester(timeout=0.2)

    assert requester_thread.loop.stopped is True
    assert join_timeouts == [0.2]


def test_shutdown_allows_queued_post_to_reach_requester_loop_before_stop(
    monkeypatch: pytest.MonkeyPatch,
    owned_requester_thread: HTTPRequesterThread,
) -> None:
    requester = owned_requester_thread
    blocker_entered = threading.Event()
    release_blocker = threading.Event()
    seen_endpoint: list[str] = []
    seen_loop: list[asyncio.AbstractEventLoop] = []
    result_future: Future[dict[str, bool]] = Future()
    shutdown_future: Future[None] = Future()

    async def fake_post(self, endpoint, *args, loads=None, **kwargs):
        del self, args, loads, kwargs
        seen_endpoint.append(endpoint)
        seen_loop.append(asyncio.get_running_loop())
        return {"ok": True}

    def block_requester_loop() -> None:
        blocker_entered.set()
        if not release_blocker.wait(timeout=2.0):
            raise AssertionError("requester loop blocker was not released")

    def call_post() -> None:
        try:
            result = asyncio.run(requester.post("https://node.example", data=b"{}"))
        except Exception as exc:
            result_future.set_exception(exc)
        else:
            result_future.set_result(result)

    def call_shutdown() -> None:
        try:
            requester_module.shutdown_http_requester(timeout=2.0)
        except Exception as exc:
            shutdown_future.set_exception(exc)
        else:
            shutdown_future.set_result(None)

    monkeypatch.setattr(DankClientSession, "post", fake_post)
    requester.loop.call_soon_threadsafe(block_requester_loop)
    assert blocker_entered.wait(timeout=2.0)

    post_thread = threading.Thread(target=call_post)
    shutdown_thread = threading.Thread(target=call_shutdown)
    try:
        post_thread.start()
        _wait_until(requester._has_active_posts)
        assert requester._session is None

        shutdown_thread.start()
        time.sleep(0.05)
        assert shutdown_thread.is_alive()

        release_blocker.set()

        assert result_future.result(timeout=2.0) == {"ok": True}
        assert shutdown_future.result(timeout=2.0) is None
        post_thread.join(timeout=2.0)
        shutdown_thread.join(timeout=2.0)

        session = requester._session
        assert seen_endpoint == ["https://node.example"]
        assert seen_loop == [requester.loop]
        assert session is not None
        assert session.closed
        assert requester._active_post_count() == 0
        assert requester._tasks == set()
        assert not post_thread.is_alive()
        assert not shutdown_thread.is_alive()
    finally:
        release_blocker.set()
        post_thread.join(timeout=2.0)
        shutdown_thread.join(timeout=2.0)


def test_shutdown_closes_existing_session_before_stopping_thread(
    monkeypatch: pytest.MonkeyPatch,
    requester_thread: HTTPRequesterThread,
) -> None:
    session = ClosableSession()
    requester_thread.loop = InlineLoop()
    requester_thread._session = session
    join_timeouts = _make_requester_look_alive(requester_thread)
    monkeypatch.setattr(
        requester_module.asyncio,
        "run_coroutine_threadsafe",
        lambda coro, loop: run_coroutine_now(coro),
    )
    assert not session.closed

    requester_module.shutdown_http_requester(timeout=1.0)

    assert session.closed
    assert requester_thread.loop.stopped is True
    assert join_timeouts == [1.0]


def test_shutdown_swallows_close_wait_timeout_and_stops_thread(
    monkeypatch: pytest.MonkeyPatch,
    requester_thread: HTTPRequesterThread,
) -> None:
    session = ClosableSession()
    requester_thread.loop = InlineLoop()
    requester_thread._session = session
    join_timeouts = _make_requester_look_alive(requester_thread)

    def run_close_and_report_timeout(
        coro: Coroutine[None, None, None],
        loop: asyncio.AbstractEventLoop,
    ) -> _ScheduledCloseRaisesTimeout:
        del loop
        return _ScheduledCloseRaisesTimeout(coro)

    monkeypatch.setattr(
        requester_module.asyncio,
        "run_coroutine_threadsafe",
        run_close_and_report_timeout,
    )

    requester_module.shutdown_http_requester(timeout=0.2)

    assert session.closed
    assert requester_thread.loop.stopped is True
    assert join_timeouts == [0.2]


def test_shutdown_swallows_close_wait_runtime_error_and_stops_thread(
    monkeypatch: pytest.MonkeyPatch,
    requester_thread: HTTPRequesterThread,
) -> None:
    session = ClosableSession()
    requester_thread.loop = InlineLoop()
    requester_thread._session = session
    join_timeouts = _make_requester_look_alive(requester_thread)

    def run_close_and_report_runtime_error(
        coro: Coroutine[None, None, None],
        loop: asyncio.AbstractEventLoop,
    ) -> _ScheduledCloseRaisesRuntimeError:
        del loop
        return _ScheduledCloseRaisesRuntimeError(coro)

    monkeypatch.setattr(
        requester_module.asyncio,
        "run_coroutine_threadsafe",
        run_close_and_report_runtime_error,
    )

    requester_module.shutdown_http_requester(timeout=0.2)

    assert session.closed
    assert requester_thread.loop.stopped is True
    assert join_timeouts == [0.2]


def test_shutdown_returns_when_loop_is_already_closed(
    monkeypatch: pytest.MonkeyPatch,
    requester_thread: HTTPRequesterThread,
) -> None:
    requester_thread.loop = InlineLoop(closed=True)
    assert requester_thread.loop.is_closed()
    monkeypatch.setattr(
        requester_module.asyncio,
        "run_coroutine_threadsafe",
        lambda coro, loop: pytest.fail("closed-loop shutdown should return before scheduling"),
    )

    requester_module.shutdown_http_requester(timeout=0.2)
