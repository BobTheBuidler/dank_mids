import asyncio

from web3._utils.rpc_abi import RPC

from dank_mids._requests import JSONRPCBatch, RPCRequest
from dank_mids._uid import UIDGenerator
from dank_mids.helpers._codec import decode_raw
from dank_mids.types import PartialRequest


class _DummyBatcher:
    step = 1000


class _DummyController:
    request_type = PartialRequest

    def __init__(self) -> None:
        self._loop = asyncio.get_running_loop()
        self.call_uid = UIDGenerator()
        self.jsonrpc_batch_uid = UIDGenerator()
        self.batcher = _DummyBatcher()
        self.endpoint = "http://example.invalid"
        self.max_jsonrpc_batch_size = 1000
        self._sort_calls = False
        self._sort_response = False
        self.requests = []
        self.response = None

    async def make_request(self, method, params, request_id=None):
        self.requests.append((method, params, request_id))
        assert self.response is not None
        return self.response


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
        mcall_coros = await batch._spoof_response_by_id(response)
        return call1, call2, mcall_coros, response

    call1, call2, mcall_coros, response = asyncio.run(run())

    assert call1.responses == [response[1]]
    assert call2.responses == []
    assert mcall_coros == []


def test_unbatched_rpc_request_error_includes_request_context() -> None:
    async def run():
        controller = _DummyController()
        controller.response = decode_raw(
            b'{"jsonrpc":"2.0","id":1,"error":{"code":-32000,"message":"weird node error"}}'
        )
        request = RPCRequest(controller, RPC.eth_blockNumber, [])

        response = await request.get_response_unbatched()
        return controller, request, response

    controller, request, response = asyncio.run(run())
    context = response["error"]["dankmids_added_context"]

    assert controller.requests == [(RPC.eth_blockNumber, [], request.uid)]
    assert context.method == request.method == RPC.eth_blockNumber
    assert context.params == request.params == []
    assert context.id == request.uid
