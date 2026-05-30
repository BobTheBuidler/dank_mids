from __future__ import annotations

import asyncio
from collections.abc import Coroutine
from concurrent.futures import TimeoutError

import pytest

from dank_mids.helpers import _requester as requester_module
from dank_mids.helpers._requester import HTTPRequesterThread

from ._helpers import ClosableSession, InlineLoop, run_coroutine_now


def _make_requester_look_alive(requester: HTTPRequesterThread) -> list[float | None]:
    join_timeouts: list[float | None] = []
    requester.is_alive = lambda: True
    requester.join = lambda timeout=None: join_timeouts.append(timeout)
    return join_timeouts


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
