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
    seen: dict[str, bytes | str | asyncio.AbstractEventLoop] = {}
    requester_thread.loop = InlineLoop()
    requester_thread.is_alive = lambda: True

    async def fake_post(self, endpoint, *args, loads=None, **kwargs):
        del self, args, loads
        seen["endpoint"] = endpoint
        seen["data"] = kwargs["data"]
        seen["loop"] = asyncio.get_running_loop()
        return {"ok": True}

    monkeypatch.setattr(DankClientSession, "post", fake_post)

    async def run_post() -> tuple[dict[str, bool], bool]:
        caller_loop = asyncio.get_running_loop()
        try:
            result = await requester_thread.post("https://node.example", data=b"{}")
            await asyncio.sleep(0)
            assert requester_thread._tasks == set()
            return result, seen["loop"] is caller_loop
        finally:
            if requester_thread._session is not None:
                await requester_thread._session.close()

    result, ran_on_caller_loop = asyncio.run(run_post())

    assert result == {"ok": True}
    assert ran_on_caller_loop is True
    assert seen["endpoint"] == "https://node.example"
    assert seen["data"] == b"{}"
    assert isinstance(seen["loop"], asyncio.AbstractEventLoop)
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
