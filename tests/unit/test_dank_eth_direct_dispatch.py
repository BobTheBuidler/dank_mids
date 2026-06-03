import asyncio
import inspect
import threading
from dataclasses import dataclass
from queue import Queue
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
import dank_mids.helpers._helpers as helpers
import dank_mids.middleware as middleware
from dank_mids.eth import DankEth


ACCOUNT = "0x0000000000000000000000000000000000000001"
OTHER_ACCOUNT = "0x0000000000000000000000000000000000000002"


class _AsyncProvider(AsyncBaseProvider):
    endpoint_uri = "https://node.example"

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


@dataclass(frozen=True)
class _ProcessParamsCase:
    name: str
    descriptor_name: str
    args: tuple[Any, ...]
    expected_request: tuple[RPCEndpoint, Any]


def _async_w3() -> AsyncWeb3:
    async_w3 = AsyncWeb3(_AsyncProvider())
    async_w3.middleware_onion.clear()
    return async_w3


def _new_dank_eth() -> tuple[AsyncWeb3, DankEth]:
    async_w3 = _async_w3()
    return async_w3, DankEth(async_w3)


def _descriptor(name: str) -> Method[Any]:
    return inspect.getattr_static(DankEth, name)


def _clear_controller_cache() -> None:
    middleware._controllers.clear()


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


def test_dank_middleware_controller_cache_reuses_web3_thread_pair(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        async_w3 = _async_w3()
        _clear_controller_cache()

        try:
            first = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
                async_w3.provider.make_request
            )
            second = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
                async_w3.provider.make_request
            )

            assert first is second
            assert middleware._controllers == {
                (async_w3, threading.current_thread()): first
            }
        finally:
            _clear_controller_cache()

    asyncio.run(run())


def test_dank_middleware_controller_cache_keeps_web3_thread_pairs_distinct(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        async_w3 = _async_w3()
        other_async_w3 = _async_w3()
        result_queue: Queue[tuple[Any, threading.Thread, BaseException | None]] = Queue()
        _clear_controller_cache()

        try:
            first = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
                async_w3.provider.make_request
            )
            other_web3 = await middleware.DankMiddleware(other_async_w3).async_wrap_make_request(
                other_async_w3.provider.make_request
            )

            def run_in_thread() -> None:
                async def thread_run() -> None:
                    try:
                        result = await middleware.DankMiddleware(
                            async_w3
                        ).async_wrap_make_request(async_w3.provider.make_request)
                    except BaseException as exc:
                        result_queue.put((None, threading.current_thread(), exc))
                    else:
                        result_queue.put((result, threading.current_thread(), None))

                asyncio.run(thread_run())

            other_thread = threading.Thread(target=run_in_thread)
            other_thread.start()
            other_thread.join(timeout=5)
            assert not other_thread.is_alive()
            thread_result, observed_thread, thread_exc = result_queue.get_nowait()
            if thread_exc is not None:
                raise thread_exc

            assert other_web3 is not first
            assert thread_result is not first
            assert middleware._controllers == {
                (async_w3, threading.current_thread()): first,
                (other_async_w3, threading.current_thread()): other_web3,
                (async_w3, observed_thread): thread_result,
            }
        finally:
            _clear_controller_cache()

    asyncio.run(run())


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
        route_calls: list[tuple[RPCEndpoint, Any]] = []

        async def route_only_call(
            self: Any, method: RPCEndpoint, params: Any
        ) -> RPCResponse:
            route_calls.append((method, params))
            return {"result": 123}

        monkeypatch.setattr(
            controller_module.DankMiddlewareController,
            "__call__",
            route_only_call,
        )
        _clear_controller_cache()

        try:
            request_func = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
                async_w3.provider.make_request
            )
            response = await request_func(RPC.eth_blockNumber, ())

            assert response == {"result": 123}
            assert route_calls == [(RPC.eth_blockNumber, ())]
        finally:
            _clear_controller_cache()

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
