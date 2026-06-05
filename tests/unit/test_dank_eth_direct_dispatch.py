import asyncio
import inspect
import json
import threading
from collections.abc import Iterator
from dataclasses import dataclass
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from types import SimpleNamespace
from typing import Any

import pytest
from web3 import AsyncWeb3
from web3._utils.rpc_abi import RPC
from web3.eth import AsyncEth
from web3.method import Method
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse

import dank_mids
import dank_mids.controller as controller_module
import dank_mids.helpers._controllers as controller_cache_module
import dank_mids.helpers._helpers as helpers
import dank_mids.middleware as middleware
from dank_mids._exceptions import BadResponse, ExecutionReverted
from dank_mids.eth import DankEth


ACCOUNT = "0x0000000000000000000000000000000000000001"
OTHER_ACCOUNT = "0x0000000000000000000000000000000000000002"


class _AsyncProvider(AsyncBaseProvider):
    endpoint_uri = "https://node.example"

    def __init__(self, endpoint_uri: str = "https://node.example") -> None:
        super().__init__()
        self.endpoint_uri = endpoint_uri

    async def make_request(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        raise AssertionError(f"unexpected provider request: {method} {params!r}")

    async def is_connected(self, show_traceback: bool = False) -> bool:
        return True


class _NoopAsyncContext:
    async def __aenter__(self) -> None:
        return None

    async def __aexit__(self, exc_type: Any, exc: Any, traceback: Any) -> None:
        return None


class _NoopSemaphores:
    def __getitem__(self, block: Any) -> _NoopAsyncContext:
        return _NoopAsyncContext()


class _JsonRpcServer(ThreadingHTTPServer):
    calls: list[tuple[str, Any]]
    errors: dict[str, dict[str, Any]]
    results: dict[str, Any]


class _JsonRpcHandler(BaseHTTPRequestHandler):
    def do_POST(self) -> None:
        content_length = int(self.headers.get("Content-Length", "0"))
        payload = json.loads(self.rfile.read(content_length))
        is_batch = isinstance(payload, list)
        requests = payload if is_batch else [payload]
        server = self.server
        assert isinstance(server, _JsonRpcServer)
        responses = [self._handle_request(server, request) for request in requests]
        body = json.dumps(responses if is_batch else responses[0]).encode()

        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def log_message(self, _format: str, *args: Any) -> None:
        return None

    @staticmethod
    def _handle_request(server: _JsonRpcServer, request: dict[str, Any]) -> dict[str, Any]:
        method = request["method"]
        params = request.get("params", [])
        server.calls.append((method, params))
        response = {"jsonrpc": "2.0", "id": request.get("id")}
        if error := server.errors.get(method):
            response["error"] = error
        else:
            response["result"] = server.results[method]
        return response


@dataclass(frozen=True)
class _ProcessParamsCase:
    name: str
    descriptor_name: str
    args: tuple[Any, ...]
    expected_request: tuple[RPCEndpoint, Any]


def _async_w3(endpoint_uri: str = "https://node.example") -> AsyncWeb3:
    async_w3 = AsyncWeb3(_AsyncProvider(endpoint_uri))
    async_w3.middleware_onion.clear()
    return async_w3


def _new_dank_eth(endpoint_uri: str = "https://node.example") -> tuple[AsyncWeb3, DankEth]:
    async_w3 = _async_w3(endpoint_uri)
    return async_w3, DankEth(async_w3)


def _descriptor(name: str) -> Method[Any]:
    return inspect.getattr_static(DankEth, name)


@pytest.fixture
def controller_cache() -> Iterator[dict[tuple[AsyncWeb3, threading.Thread], Any]]:
    controller_cache_module._controllers.clear()
    try:
        yield controller_cache_module._controllers
    finally:
        controller_cache_module._controllers.clear()


@pytest.fixture
def jsonrpc_server() -> Iterator[_JsonRpcServer]:
    server = _JsonRpcServer(("127.0.0.1", 0), _JsonRpcHandler)
    server.calls = []
    server.errors = {}
    server.results = {
        RPC.eth_chainId: "0x1",
        RPC.web3_clientVersion: "pytest/test",
        RPC.eth_blockNumber: "0x7b",
    }
    thread = threading.Thread(target=server.serve_forever, daemon=True)
    thread.start()
    try:
        yield server
    finally:
        server.shutdown()
        thread.join(timeout=5)
        server.server_close()


def _server_endpoint(server: _JsonRpcServer) -> str:
    return f"http://127.0.0.1:{server.server_port}"


def _forbid_web3_manager(monkeypatch: pytest.MonkeyPatch, async_w3: AsyncWeb3) -> None:
    async def forbidden_coro_request(*args: Any, **kwargs: Any) -> RPCResponse:
        raise AssertionError("optimized DankEth methods must not call Web3 RequestManager")

    monkeypatch.setattr(async_w3.manager, "coro_request", forbidden_coro_request)


def _clear_controller_cache() -> None:
    controller_cache_module._controllers.clear()


def _install_inert_controller_init(monkeypatch: pytest.MonkeyPatch) -> None:
    fake_sync_w3 = SimpleNamespace(
        eth=SimpleNamespace(chain_id=999_999),
        client_version="pytest/test",
    )
    fake_multicall = SimpleNamespace(
        address="0x0000000000000000000000000000000000000001",
        bytecode="0x00",
        needs_override_code_for_block=lambda _block: False,
    )
    monkeypatch.setattr(
        controller_module, "_sync_w3_from_async", lambda _async_w3: fake_sync_w3
    )
    monkeypatch.setattr(controller_module, "_get_client_version", lambda _sync_w3: "pytest/test")
    monkeypatch.setattr(controller_module, "_get_multicall2", lambda _chainid: fake_multicall)
    monkeypatch.setattr(controller_module, "_get_multicall3", lambda _chainid: None)


def _process_param_cases() -> list[_ProcessParamsCase]:
    return [
        _ProcessParamsCase(
            "block_by_number",
            "_get_block",
            (5, False),
            (RPC.eth_getBlockByNumber, ("0x5", False)),
        ),
        _ProcessParamsCase(
            "eth_call_compact_tx_bytes_to_hex",
            "_call",
            ({"to": ACCOUNT, "data": b"\x12\x34"}, 5),
            (RPC.eth_call, ({"to": ACCOUNT, "data": "0x1234"}, "0x5")),
        ),
        _ProcessParamsCase(
            "eth_call_full_tx_uses_request_formatter_path",
            "_call",
            ({"to": ACCOUNT, "from": ACCOUNT, "data": b"\x12\x34"}, 5),
            (RPC.eth_call, ({"to": ACCOUNT, "from": ACCOUNT, "data": b"\x12\x34"}, 5)),
        ),
        _ProcessParamsCase(
            "non_eth_call_formatter_path",
            "_get_balance",
            (ACCOUNT, None),
            (RPC.eth_getBalance, (ACCOUNT, "latest")),
        ),
        _ProcessParamsCase(
            "filter_logs_default_munger",
            "get_filter_logs",
            ("0xabc",),
            (RPC.eth_getFilterLogs, ["0xabc"]),
        ),
    ]


@pytest.mark.parametrize("case", _process_param_cases(), ids=lambda case: case.name)
def test_method_no_format_process_params_matrix(case: _ProcessParamsCase) -> None:
    _async_w3, eth = _new_dank_eth()
    request, _formatters = _descriptor(case.descriptor_name).process_params(eth, *case.args)

    assert request == case.expected_request


def test_method_no_format_rejects_eth_call_state_override() -> None:
    _async_w3, eth = _new_dank_eth()

    with pytest.raises(NotImplementedError, match="state override"):
        _descriptor("_call").process_params(
            eth,
            {"to": ACCOUNT, "data": "0x1234"},
            "latest",
            {"0x0000000000000000000000000000000000000000": {}},
        )


@pytest.mark.parametrize(
    ("selected_method", "expected"),
    [
        (RPC.eth_newBlockFilter, (RPC.eth_newBlockFilter, [])),
        (RPC.eth_newPendingTransactionFilter, (RPC.eth_newPendingTransactionFilter, [])),
    ],
)
def test_method_no_format_clears_pending_and_block_filter_params(
    selected_method: RPCEndpoint,
    expected: tuple[RPCEndpoint, Any],
) -> None:
    _async_w3, eth = _new_dank_eth()
    method = type(_descriptor("_call"))(
        method_choice_depends_on_args=lambda value: selected_method,
        mungers=[lambda _module, value: [value]],
    )

    request, _formatters = method.process_params(eth, "latest")

    assert request == expected


def test_setup_dank_w3_still_injects_middleware_for_route_only_compat(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async_w3 = _async_w3()
    monkeypatch.setattr(dank_mids, "_ensure_side_effects", lambda: None)
    monkeypatch.setattr(
        helpers,
        "_sync_w3_from_async",
        lambda _w3: SimpleNamespace(eth=SimpleNamespace(chain_id=1)),
    )
    _clear_controller_cache()

    try:
        helpers.dank_w3s.clear()
        assert helpers.setup_dank_w3(async_w3) is async_w3

        assert async_w3.middleware_onion.as_tuple_of_middleware() == (middleware.DankMiddleware,)
        assert isinstance(async_w3.eth, DankEth)
    finally:
        helpers.dank_w3s.clear()
        _clear_controller_cache()


def test_middleware_route_only_request_function_reaches_dank_controller(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        async_w3 = _async_w3()
        calls: list[tuple[Any, RPCEndpoint, Any]] = []

        class FakeRPCRequest:
            def __init__(self, observed_controller: Any, method: RPCEndpoint, params: Any) -> None:
                calls.append((observed_controller, method, params))

            def __await__(self) -> Any:
                async def inner() -> RPCResponse:
                    return {"result": 123}

                return inner().__await__()

        async def noop() -> None:
            return None

        monkeypatch.setattr(controller_module, "rate_limit_inactive", lambda _endpoint: noop())
        monkeypatch.setattr(controller_module, "RPCRequest", FakeRPCRequest)

        _clear_controller_cache()

        try:
            request_func = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
                async_w3.provider.make_request
            )
            response = await request_func(RPC.eth_blockNumber, ())

            assert response == {"result": 123}
            assert calls == [(request_func, RPC.eth_blockNumber, ())]
        finally:
            _clear_controller_cache()

    asyncio.run(run())


def test_dank_eth_direct_dispatch_uses_controller_without_request_manager(
    monkeypatch: pytest.MonkeyPatch,
    controller_cache: dict[tuple[AsyncWeb3, threading.Thread], Any],
    jsonrpc_server: _JsonRpcServer,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth(_server_endpoint(jsonrpc_server))
        _forbid_web3_manager(monkeypatch, async_w3)

        assert async_w3.middleware_onion.as_tuple_of_middleware() == ()
        assert await eth.get_block_number() == 123
        assert (RPC.eth_blockNumber, []) in jsonrpc_server.calls
        assert isinstance(
            controller_cache[(async_w3, threading.current_thread())],
            controller_module.DankMiddlewareController,
        )

    asyncio.run(run())


def test_direct_dispatch_accepts_compact_result_and_applies_result_formatter(
    monkeypatch: pytest.MonkeyPatch,
    jsonrpc_server: _JsonRpcServer,
) -> None:
    async def run() -> None:
        jsonrpc_server.results[RPC.eth_blockNumber] = "0xa"
        async_w3, eth = _new_dank_eth(_server_endpoint(jsonrpc_server))
        _forbid_web3_manager(monkeypatch, async_w3)

        assert await eth.get_block_number() == 10
        assert (RPC.eth_blockNumber, []) in jsonrpc_server.calls

    asyncio.run(run())


def test_direct_dispatch_compact_error_raises_existing_dank_exception(
    monkeypatch: pytest.MonkeyPatch,
    jsonrpc_server: _JsonRpcServer,
) -> None:
    async def run() -> None:
        jsonrpc_server.errors[RPC.eth_blockNumber] = {
            "code": 3,
            "message": "execution reverted",
        }
        async_w3, eth = _new_dank_eth(_server_endpoint(jsonrpc_server))
        _forbid_web3_manager(monkeypatch, async_w3)

        with pytest.raises(ExecutionReverted):
            await eth.get_block_number()

    asyncio.run(run())


def test_direct_dispatch_preserves_compact_error_request_context(
    monkeypatch: pytest.MonkeyPatch,
    jsonrpc_server: _JsonRpcServer,
) -> None:
    async def run() -> None:
        jsonrpc_server.errors[RPC.eth_blockNumber] = {
            "code": -32000,
            "message": "weird node error",
        }
        async_w3, eth = _new_dank_eth(_server_endpoint(jsonrpc_server))
        _forbid_web3_manager(monkeypatch, async_w3)

        with pytest.raises(BadResponse) as exc_info:
            await eth.get_block_number()

        assert exc_info.value.request.method == RPC.eth_blockNumber
        assert exc_info.value.request.params == ()

    asyncio.run(run())


def test_dank_middleware_and_direct_dank_eth_share_controller_cache(
    monkeypatch: pytest.MonkeyPatch,
    controller_cache: dict[tuple[AsyncWeb3, threading.Thread], Any],
    jsonrpc_server: _JsonRpcServer,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth(_server_endpoint(jsonrpc_server))
        middleware_controller = await middleware.DankMiddleware(
            async_w3
        ).async_wrap_make_request(async_w3.provider.make_request)

        assert await eth.get_block_number() == 123
        assert controller_cache == {
            (async_w3, threading.current_thread()): middleware_controller
        }
        assert hasattr(eth, "retrieve_caller_fn")

    asyncio.run(run())


def test_controller_call_routes_eth_call_to_multicall_compatible_path(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        controller = controller_module.DankMiddlewareController(_async_w3())
        calls: list[tuple[Any, Any]] = []
        controller.eth_call_semaphores = _NoopSemaphores()

        class FakeEthCall:
            def __init__(self, observed_controller: Any, params: Any) -> None:
                calls.append((observed_controller, params))

            def __await__(self) -> Any:
                async def inner() -> RPCResponse:
                    return {"result": "multicall"}

                return inner().__await__()

        async def noop() -> None:
            return None

        monkeypatch.setattr(controller_module, "rate_limit_inactive", lambda _endpoint: noop())
        monkeypatch.setattr(controller_module, "eth_call", FakeEthCall)

        response = await asyncio.wait_for(
            controller(RPC.eth_call, ({"to": OTHER_ACCOUNT, "data": "0x1234"}, "latest")),
            timeout=1,
        )

        assert response == {"result": "multicall"}
        assert calls == [(controller, ({"to": OTHER_ACCOUNT, "data": "0x1234"}, "latest"))]

    asyncio.run(run())


def test_controller_call_routes_no_multicall_eth_call_to_rpc_request(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        controller = controller_module.DankMiddlewareController(_async_w3())
        calls: list[tuple[Any, RPCEndpoint, Any]] = []
        controller.eth_call_semaphores = _NoopSemaphores()
        controller.no_multicall = {OTHER_ACCOUNT}

        class FakeRPCRequest:
            def __init__(self, observed_controller: Any, method: RPCEndpoint, params: Any) -> None:
                calls.append((observed_controller, method, params))

            def __await__(self) -> Any:
                async def inner() -> RPCResponse:
                    return {"result": "rpc"}

                return inner().__await__()

        async def noop() -> None:
            return None

        monkeypatch.setattr(controller_module, "rate_limit_inactive", lambda _endpoint: noop())
        monkeypatch.setattr(controller_module, "RPCRequest", FakeRPCRequest)

        response = await asyncio.wait_for(
            controller(RPC.eth_call, ({"to": OTHER_ACCOUNT, "data": "0x1234"}, "latest")),
            timeout=1,
        )

        assert response == {"result": "rpc"}
        assert calls == [
            (controller, RPC.eth_call, ({"to": OTHER_ACCOUNT, "data": "0x1234"}, "latest"))
        ]

    asyncio.run(run())


def test_controller_call_routes_non_eth_call_to_rpc_request(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        controller = controller_module.DankMiddlewareController(_async_w3())
        calls: list[tuple[Any, RPCEndpoint, Any]] = []

        class FakeRPCRequest:
            def __init__(self, observed_controller: Any, method: RPCEndpoint, params: Any) -> None:
                calls.append((observed_controller, method, params))

            def __await__(self) -> Any:
                async def inner() -> RPCResponse:
                    return {"result": "rpc"}

                return inner().__await__()

        async def noop() -> None:
            return None

        monkeypatch.setattr(controller_module, "rate_limit_inactive", lambda _endpoint: noop())
        monkeypatch.setattr(controller_module, "RPCRequest", FakeRPCRequest)

        response = await asyncio.wait_for(
            controller(RPC.eth_getBalance, (ACCOUNT, "latest")),
            timeout=1,
        )

        assert response == {"result": "rpc"}
        assert calls == [(controller, RPC.eth_getBalance, (ACCOUNT, "latest"))]

    asyncio.run(run())
