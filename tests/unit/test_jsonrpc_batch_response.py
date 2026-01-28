import asyncio
import atexit

from dank_mids._requests import JSONRPCBatch
from dank_mids._uid import UIDGenerator
from dank_mids.helpers._codec import decode_raw
from dank_mids.helpers._requester import shutdown_http_requester

atexit.unregister(shutdown_http_requester)


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
        self._sort_calls = False
        self._sort_response = False


class _DummyCall:
    def __init__(self, uid: int, truthy: bool = True) -> None:
        self.uid = uid
        self._truthy = truthy
        self._fut = asyncio.get_running_loop().create_future()
        self._fut.set_result(None)
        self.responses = []

    def __bool__(self) -> bool:
        return self._truthy

    async def spoof_response(self, raw: object) -> None:
        self.responses.append(raw)


class _DummyRequest:
    def __init__(self, data: bytes) -> None:
        self.data = data


class _DummyDataCall:
    def __init__(self, uid: int, data: bytes, truthy: bool = True) -> None:
        self.uid = uid
        self._truthy = truthy
        self.request = _DummyRequest(data)
        self._fut = asyncio.get_running_loop().create_future()
        self._fut.set_result(None)

    def __bool__(self) -> bool:
        return self._truthy


def test_spoof_response_by_id_matches_and_skips_falsey() -> None:
    async def run():
        controller = _DummyController()
        call1 = _DummyCall(1)
        call2 = _DummyCall(2, truthy=False)
        batch = JSONRPCBatch(controller, [call1, call2], jid="batch-1")
        response = [
            decode_raw(b'{"jsonrpc":"2.0","id":2,"result":"0x02"}'),
            decode_raw(b'{"jsonrpc":"2.0","id":1,"result":"0x01"}'),
        ]
        mcall_coros = await batch._spoof_response_by_id(response, (call1, call2))
        return call1, call2, mcall_coros, response

    call1, call2, mcall_coros, response = asyncio.run(run())

    assert call1.responses == [response[1]]
    assert call2.responses == []
    assert mcall_coros == []


def test_calls_and_data_snapshot_filters_falsey_and_handles_empty() -> None:
    async def run():
        controller = _DummyController()
        call1 = _DummyDataCall(1, b"{}")
        call2 = _DummyDataCall(2, b"{}", truthy=False)
        batch = JSONRPCBatch(controller, [call1, call2], jid="batch-1")
        calls, data = batch._calls_and_data()
        empty_call = _DummyDataCall(3, b"{}", truthy=False)
        empty_batch = JSONRPCBatch(controller, [empty_call], jid="batch-2")
        empty_calls, empty_data = empty_batch._calls_and_data()
        return call1, calls, data, empty_calls, empty_data

    call1, calls, data, empty_calls, empty_data = asyncio.run(run())

    assert calls == (call1,)
    assert data == b"[{}]"
    assert empty_calls == ()
    assert empty_data == b"[]"
