from __future__ import annotations

import asyncio

import pytest

from dank_mids.helpers._requester import HTTPRequesterThread
from dank_mids.helpers._session import DankClientSession

from ._helpers import InlineLoop


def test_post_runs_session_request_on_requester_loop(
    monkeypatch: pytest.MonkeyPatch,
    requester_thread: HTTPRequesterThread,
) -> None:
    seen_endpoint: list[str] = []
    seen_data: list[bytes] = []
    seen_loop: list[asyncio.AbstractEventLoop] = []

    async def fake_post(self, endpoint, *args, loads=None, **kwargs):
        del self, args, loads
        seen_endpoint.append(endpoint)
        seen_data.append(kwargs["data"])
        seen_loop.append(asyncio.get_running_loop())
        return {"ok": True}

    monkeypatch.setattr(DankClientSession, "post", fake_post)

    async def run_post() -> tuple[dict[str, bool], asyncio.AbstractEventLoop]:
        caller_loop = asyncio.get_running_loop()
        created_session = requester_thread._session is None
        try:
            result = await asyncio.wait_for(
                requester_thread.post("https://node.example", data=b"{}"),
                timeout=2.0,
            )
            await asyncio.sleep(0)
            assert requester_thread._tasks == set()
            return result, caller_loop
        finally:
            session = requester_thread._session
            if created_session and session is not None and not session.closed:
                close_future = asyncio.run_coroutine_threadsafe(
                    session.close(),
                    requester_thread.loop,
                )
                await asyncio.wrap_future(close_future)

    result, caller_loop = asyncio.run(run_post())

    assert result == {"ok": True}
    assert seen_endpoint == ["https://node.example"]
    assert seen_data == [b"{}"]
    assert seen_loop == [requester_thread.loop]
    assert seen_loop[0] is not caller_loop
    assert requester_thread._active_post_count() == 0


def test_post_propagates_session_request_exception(
    monkeypatch: pytest.MonkeyPatch,
    requester_thread: HTTPRequesterThread,
) -> None:
    requester_thread.loop = InlineLoop()
    requester_thread.is_alive = lambda: True

    async def fake_post(self, endpoint, *args, loads=None, **kwargs):
        del self, endpoint, args, loads, kwargs
        raise RuntimeError("request failed")

    monkeypatch.setattr(DankClientSession, "post", fake_post)

    async def run_post() -> None:
        try:
            await requester_thread.post("https://node.example", data=b"{}")
        finally:
            if requester_thread._session is not None:
                await requester_thread._session.close()

    with pytest.raises(RuntimeError, match="request failed"):
        asyncio.run(run_post())
    assert requester_thread._active_post_count() == 0


def test_post_raises_stored_thread_exception_when_requester_is_dead(
    requester_thread: HTTPRequesterThread,
) -> None:
    requester_thread._exc = RuntimeError("requester died")
    requester_thread.is_alive = lambda: False

    async def run_post() -> None:
        await requester_thread.post("https://node.example", data=b"{}")

    with pytest.raises(RuntimeError, match="requester died"):
        asyncio.run(run_post())
    assert requester_thread._active_post_count() == 0
