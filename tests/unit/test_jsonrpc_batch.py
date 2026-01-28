import asyncio
from types import SimpleNamespace

import dank_mids._requests as requests
from dank_mids._requests import JSONRPCBatch
from dank_mids._uid import UIDGenerator


class _DummyBatcher:
    step = 1000


class _DummyController:
    def __init__(self) -> None:
        self._loop = asyncio.get_running_loop()
        self.call_uid = UIDGenerator()
        self.jsonrpc_batch_uid = UIDGenerator()
        self.batcher = _DummyBatcher()
        self.endpoint = "http://example.invalid"
        self.max_jsonrpc_batch_size = 1000


class _ToggleCall:
    def __init__(self) -> None:
        self.request = SimpleNamespace(data=b"{}")
        self._truthy_checks = [True, False]

    def __bool__(self) -> bool:
        if self._truthy_checks:
            return self._truthy_checks.pop(0)
        return False


def test_post_skips_empty_payload_when_calls_become_falsey(monkeypatch) -> None:
    called = False

    async def fake_post(*args: object, **kwargs: object) -> list[object]:
        nonlocal called
        called = True
        return []

    monkeypatch.setattr(requests._requester, "post", fake_post)

    async def run() -> tuple[list[object], list[object]]:
        controller = _DummyController()
        call = _ToggleCall()
        batch = JSONRPCBatch(controller, [call], jid="batch-1")
        return await batch.post()

    responses, calls = asyncio.run(run())

    assert responses == []
    assert calls == []
    assert called is False
