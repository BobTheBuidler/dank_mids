import asyncio
import inspect
import threading
from collections.abc import Iterator
from dataclasses import dataclass
from types import SimpleNamespace
from typing import Any, ClassVar

from eth_abi import encode
import pytest
from web3 import AsyncWeb3
from web3._utils.error_formatters_utils import OFFCHAIN_LOOKUP_FUNC_SELECTOR
from web3._utils.rpc_abi import RPC
from web3.eth import AsyncEth
from web3.exceptions import OffchainLookup
from web3.method import Method
from web3.middleware.base import Web3Middleware
from web3.types import RPCEndpoint, RPCResponse

import dank_mids
import dank_mids.controller as controller_module
import dank_mids.helpers._controllers as controller_cache_module
import dank_mids.helpers._helpers as helpers
import dank_mids.middleware as middleware
from dank_mids.eth import DankEth
from tests.unit._jsonrpc import (
    AsyncProvider,
    JsonRpcServer,
    jsonrpc_server,
    server_endpoint,
)


ACCOUNT = "0x0000000000000000000000000000000000000001"
OTHER_ACCOUNT = "0x0000000000000000000000000000000000000002"


class _NoopAsyncContext:
    async def __aenter__(self) -> None:
        return None

    async def __aexit__(self, exc_type: Any, exc: Any, traceback: Any) -> None:
        return None


class _NoopSemaphores:
    def __getitem__(self, block: Any) -> _NoopAsyncContext:
        return _NoopAsyncContext()


@dataclass(frozen=True)
class _ProcessParamsCase:
    name: str
    descriptor_name: str
    args: tuple[Any, ...]
    expected_request: tuple[RPCEndpoint, Any]


def _async_w3(endpoint_uri: str = "https://node.example") -> AsyncWeb3:
    async_w3 = AsyncWeb3(AsyncProvider(endpoint_uri))
    async_w3.middleware_onion.clear()
    return async_w3


def _new_dank_eth(
    endpoint_uri: str = "https://node.example",
) -> tuple[AsyncWeb3, DankEth]:
    async_w3 = _async_w3(endpoint_uri)
    return async_w3, DankEth(async_w3)


def _descriptor(name: str) -> Method[Any]:
    return inspect.getattr_static(DankEth, name)


def _offchain_lookup_error_data() -> str:
    encoded_args = encode(
        ["address", "string[]", "bytes", "bytes4", "bytes"],
        [
            ACCOUNT,
            ["https://example.invalid/{data}"],
            b"\x12\x34",
            b"\x12\x34\x56\x78",
            b"\x99",
        ],
    )
    return f"{OFFCHAIN_LOOKUP_FUNC_SELECTOR}{encoded_args.hex()}"


@pytest.fixture
def controller_cache() -> Iterator[dict[tuple[AsyncWeb3, threading.Thread], Any]]:
    controller_cache_module._controllers.clear()
    try:
        yield controller_cache_module._controllers
    finally:
        controller_cache_module._controllers.clear()


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

        assert async_w3.middleware_onion.as_tuple_of_middleware() == (
            middleware.DankMiddleware,
        )
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


def test_dank_eth_get_block_number_preserves_non_dank_async_middleware() -> None:
    class RewriteBlockNumberMiddleware(Web3Middleware):
        observed_methods: ClassVar[list[RPCEndpoint]] = []

        async def async_request_processor(
            self,
            method: RPCEndpoint,
            params: Any,
        ) -> tuple[RPCEndpoint, Any]:
            self.observed_methods.append(method)
            return method, params

        async def async_response_processor(
            self,
            method: RPCEndpoint,
            response: RPCResponse,
        ) -> RPCResponse:
            if method == RPC.eth_blockNumber:
                return {**response, "result": "0x7c"}
            return response

    async def run() -> None:
        provider = AsyncProvider(response={"jsonrpc": "2.0", "id": 1, "result": "0x7b"})
        async_w3 = AsyncWeb3(provider)
        async_w3.middleware_onion.clear()
        async_w3.middleware_onion.add(RewriteBlockNumberMiddleware)

        assert await DankEth(async_w3).get_block_number() == "0x7c"
        assert provider.calls == [(RPC.eth_blockNumber, ())]
        assert RewriteBlockNumberMiddleware.observed_methods == [RPC.eth_blockNumber]

    asyncio.run(run())


def test_dank_eth_direct_dispatch_uses_controller_without_request_manager(
    monkeypatch: pytest.MonkeyPatch,
    controller_cache: dict[tuple[AsyncWeb3, threading.Thread], Any],
    jsonrpc_server: JsonRpcServer,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth(server_endpoint(jsonrpc_server))
        _forbid_web3_manager(monkeypatch, async_w3)

        assert async_w3.middleware_onion.as_tuple_of_middleware() == ()
        assert await eth.get_block_number() == 123
        assert (RPC.eth_blockNumber, []) in jsonrpc_server.calls
        assert isinstance(
            controller_cache[(async_w3, threading.current_thread())],
            controller_module.DankMiddlewareController,
        )

    asyncio.run(run())


def test_dank_eth_direct_dispatch_allows_dank_middleware_only(
    monkeypatch: pytest.MonkeyPatch,
    controller_cache: dict[tuple[AsyncWeb3, threading.Thread], Any],
    jsonrpc_server: JsonRpcServer,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth(server_endpoint(jsonrpc_server))
        async_w3.middleware_onion.add(middleware.DankMiddleware)
        _forbid_web3_manager(monkeypatch, async_w3)
        middleware_controller = await middleware.DankMiddleware(
            async_w3
        ).async_wrap_make_request(async_w3.provider.make_request)

        assert async_w3.middleware_onion.as_tuple_of_middleware() == (middleware.DankMiddleware,)
        assert await eth.get_block_number() == 123
        assert controller_cache == {
            (async_w3, threading.current_thread()): middleware_controller
        }

    asyncio.run(run())


def test_inherited_syncing_falls_back_to_web3_caller(
    controller_cache: dict[tuple[AsyncWeb3, threading.Thread], Any],
) -> None:
    async def run() -> None:
        provider = AsyncProvider(response={"jsonrpc": "2.0", "id": 1, "result": False})
        async_w3 = AsyncWeb3(provider)
        async_w3.middleware_onion.clear()
        eth = DankEth(async_w3)

        result = await eth.syncing

        assert result is False
        assert provider.calls == [(RPC.eth_syncing, ())]
        assert controller_cache == {}

    asyncio.run(run())


def test_inherited_uninstall_filter_falls_back_to_web3_caller(
    controller_cache: dict[tuple[AsyncWeb3, threading.Thread], Any],
) -> None:
    async def run() -> None:
        provider = AsyncProvider(response={"jsonrpc": "2.0", "id": 1, "result": True})
        async_w3 = AsyncWeb3(provider)
        async_w3.middleware_onion.clear()
        eth = DankEth(async_w3)

        result = await eth.uninstall_filter("0x1")

        assert result is True
        assert provider.calls[0][0] == RPC.eth_uninstallFilter
        assert controller_cache == {}

    asyncio.run(run())


def test_direct_dispatch_applies_eth_call_error_formatter(
    monkeypatch: pytest.MonkeyPatch,
    controller_cache: dict[tuple[AsyncWeb3, threading.Thread], Any],
    jsonrpc_server: JsonRpcServer,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth(server_endpoint(jsonrpc_server))
        controller = controller_cache_module.get_controller_for_async_w3(async_w3)
        _forbid_web3_manager(monkeypatch, async_w3)
        no_multicall_address = next(iter(controller.no_multicall))
        jsonrpc_server.errors[RPC.eth_call] = {
            "code": 3,
            "message": "execution reverted",
            "data": _offchain_lookup_error_data(),
        }

        with pytest.raises(OffchainLookup):
            await eth.call(
                {"to": no_multicall_address, "data": "0x1234"},
                ccip_read_enabled=False,
            )

        assert any(method == RPC.eth_call for method, _params in jsonrpc_server.calls)

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
