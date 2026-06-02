import asyncio
import importlib
import importlib.util
import inspect
import sys
import threading
from dataclasses import dataclass
from pathlib import Path
from queue import Queue
from types import SimpleNamespace
from typing import Any
from unittest.mock import patch

import pytest
from eth_typing import BlockNumber
from hexbytes import HexBytes
from web3 import AsyncWeb3
from web3._utils.rpc_abi import RPC
from web3.eth import AsyncEth
from web3.method import Method
from web3.module import AsyncLogFilter, _UseExistingFilter
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse

import dank_mids


def _load_source_module(name: str, path: Path, package_dir: Path | None = None) -> None:
    spec = importlib.util.spec_from_file_location(
        name,
        path,
        submodule_search_locations=[str(package_dir)] if package_dir else None,
    )
    if spec is None or spec.loader is None:
        raise RuntimeError(f"unable to load {name} from {path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)


def _preload_vendored_aiolimiter_source() -> None:
    package = "dank_mids._vendor.aiolimiter.src.aiolimiter"
    package_dir = (
        Path(__file__).resolve().parents[2]
        / "dank_mids"
        / "_vendor"
        / "aiolimiter"
        / "src"
        / "aiolimiter"
    )
    package_spec = importlib.util.spec_from_file_location(
        package,
        package_dir / "__init__.py",
        submodule_search_locations=[str(package_dir)],
    )
    if package_spec is None or package_spec.loader is None:
        raise RuntimeError(f"unable to load {package} from {package_dir}")
    package_module = importlib.util.module_from_spec(package_spec)
    sys.modules[package] = package_module
    _load_source_module(f"{package}.leakybucket", package_dir / "leakybucket.py")
    package_spec.loader.exec_module(package_module)


_preload_vendored_aiolimiter_source()

import dank_mids._web3.method as method_module
import dank_mids.controller as controller_module
import dank_mids.helpers._helpers as helpers
import dank_mids.middleware as middleware
from dank_mids._exceptions import (
    BadResponse,
    ChainstackRateLimitError,
    ExecutionReverted,
    ExceedsMaxBatchSize,
    OutOfGas,
    PayloadTooLarge,
    QuiknodeRateLimitError,
)
from dank_mids.eth import DankEth
from dank_mids.types import Error


ACCOUNT = "0x0000000000000000000000000000000000000001"
OTHER_ACCOUNT = "0x0000000000000000000000000000000000000002"
TX_HASH = "0x" + "11" * 32
BLOCK_HASH = "0x" + "22" * 32
TRACE_HASH = "0x" + "33" * 32
CHAINSTACK_RATE_LIMIT = "You've exceeded the RPS limit available on the current plan."
QUICKNODE_RATE_LIMIT = (
    "endpoint hit 30/second request limit reached - reduce calls per second or upgrade "
    "your account at quicknode.com"
)


class _AsyncProvider(AsyncBaseProvider):
    endpoint_uri = "http://example.invalid"

    async def make_request(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        return {"jsonrpc": "2.0", "id": 1, "result": "provider"}

    async def is_connected(self, show_traceback: bool = False) -> bool:
        return True


class _RecordingController:
    def __init__(self, responses: list[RPCResponse]) -> None:
        self.responses = responses
        self.calls: list[tuple[RPCEndpoint, Any]] = []

    async def __call__(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        self.calls.append((method, params))
        if not self.responses:
            raise AssertionError(f"no fake response queued for {method} {params!r}")
        return self.responses.pop(0)


class _NoopAsyncContext:
    async def __aenter__(self) -> None:
        return None

    async def __aexit__(self, exc_type: Any, exc: Any, traceback: Any) -> None:
        return None


class _NoopSemaphores:
    def __getitem__(self, block: Any) -> _NoopAsyncContext:
        return _NoopAsyncContext()


@dataclass(frozen=True)
class _DispatchCase:
    name: str
    call: Any
    responses: list[RPCResponse]
    expected_calls: list[tuple[RPCEndpoint, Any]]
    expected_result: Any


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


def _install_controller(
    monkeypatch: pytest.MonkeyPatch,
    async_w3: AsyncWeb3,
    controller: _RecordingController,
) -> None:
    def get_controller_for_async_w3(observed_w3: AsyncWeb3) -> _RecordingController:
        assert observed_w3 is async_w3
        return controller

    monkeypatch.setattr(
        method_module,
        "get_controller_for_async_w3",
        get_controller_for_async_w3,
        raising=False,
    )


def _forbid_web3_manager(monkeypatch: pytest.MonkeyPatch, async_w3: AsyncWeb3) -> None:
    async def forbidden_coro_request(*args: Any, **kwargs: Any) -> RPCResponse:
        raise AssertionError("optimized DankEth methods must not call Web3 RequestManager")

    monkeypatch.setattr(async_w3.manager, "coro_request", forbidden_coro_request)


def _controller_cache_module() -> Any:
    try:
        return importlib.import_module("dank_mids.helpers._controllers")
    except ModuleNotFoundError:
        return middleware


def _clear_controller_cache() -> None:
    cache_module = _controller_cache_module()
    cache_module._controllers.clear()
    if hasattr(middleware, "_controllers"):
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


def _dispatch_cases() -> list[_DispatchCase]:
    return [
        _DispatchCase(
            "chain_id",
            lambda eth: eth.chain_id,
            [{"result": 1}],
            [(RPC.eth_chainId, [])],
            1,
        ),
        _DispatchCase(
            "block_number_property",
            lambda eth: eth.block_number,
            [{"result": BlockNumber(123)}],
            [(RPC.eth_blockNumber, ())],
            BlockNumber(123),
        ),
        _DispatchCase(
            "get_block_number_method",
            lambda eth: eth.get_block_number(),
            [{"result": BlockNumber(124)}],
            [(RPC.eth_blockNumber, ())],
            BlockNumber(124),
        ),
        _DispatchCase(
            "get_balance_default_block",
            lambda eth: eth.get_balance(ACCOUNT),
            [{"result": 456}],
            [(RPC.eth_getBalance, (ACCOUNT, "latest"))],
            456,
        ),
        _DispatchCase(
            "get_balance_latest",
            lambda eth: eth.get_balance(ACCOUNT, "latest"),
            [{"result": 457}],
            [(RPC.eth_getBalance, (ACCOUNT, "latest"))],
            457,
        ),
        _DispatchCase(
            "get_balance_int_block",
            lambda eth: eth.get_balance(ACCOUNT, BlockNumber(6)),
            [{"result": 458}],
            [(RPC.eth_getBalance, (ACCOUNT, "0x6"))],
            458,
        ),
        _DispatchCase(
            "get_transaction_count",
            lambda eth: eth.get_transaction_count(ACCOUNT, BlockNumber(7)),
            [{"result": 8}],
            [(RPC.eth_getTransactionCount, (ACCOUNT, "0x7"))],
            8,
        ),
        _DispatchCase(
            "get_code",
            lambda eth: eth.get_code(ACCOUNT, BlockNumber(8)),
            [{"result": HexBytes("0x1234")}],
            [(RPC.eth_getCode, (ACCOUNT, "0x8"))],
            HexBytes("0x1234"),
        ),
        _DispatchCase(
            "eth_call_bytes_int_block",
            lambda eth: eth.call({"to": ACCOUNT, "data": b"\x12\x34"}, 5),
            [{"result": HexBytes("0x1234")}],
            [(RPC.eth_call, ({"to": ACCOUNT, "data": "0x1234"}, "0x5"))],
            HexBytes("0x1234"),
        ),
        _DispatchCase(
            "eth_call_hex_latest",
            lambda eth: eth.call({"to": ACCOUNT, "data": "0x1234"}, "latest"),
            [{"result": HexBytes("0x5678")}],
            [(RPC.eth_call, ({"to": ACCOUNT, "data": "0x1234"}, "latest"))],
            HexBytes("0x5678"),
        ),
        _DispatchCase(
            "get_logs_decodes_raw",
            lambda eth: eth.get_logs(
                {"fromBlock": 1, "toBlock": 2, "address": ACCOUNT},
                decode_to=list[dict[str, Any]],
                decode_hook=None,
            ),
            [{"result": b"[]"}],
            [(RPCEndpoint("eth_getLogs_raw"), [{"fromBlock": 1, "toBlock": 2, "address": ACCOUNT}])],
            [],
        ),
        _DispatchCase(
            "get_filter_logs",
            lambda eth: eth.get_filter_logs("0xabc"),
            [{"result": []}],
            [(RPC.eth_getFilterLogs, ["0xabc"])],
            [],
        ),
        _DispatchCase(
            "get_filter_changes",
            lambda eth: eth.get_filter_changes("0xabc"),
            [{"result": []}],
            [(RPC.eth_getFilterChanges, ["0xabc"])],
            [],
        ),
        _DispatchCase(
            "transaction_receipt_raw",
            lambda eth: eth._get_transaction_receipt_raw(TX_HASH),
            [{"result": b'{"status":1}'}],
            [(RPCEndpoint("eth_getTransactionReceipt_raw"), [TX_HASH])],
            b'{"status":1}',
        ),
        _DispatchCase(
            "transaction_raw",
            lambda eth: eth._get_transaction_raw(TX_HASH),
            [{"result": b'{"hash":"0x11"}'}],
            [(RPCEndpoint("eth_getTransactionByHash_raw"), [TX_HASH])],
            b'{"hash":"0x11"}',
        ),
        _DispatchCase(
            "block_raw_number",
            lambda eth: eth._get_block_raw(5, False),
            [{"result": b'{"timestamp":1,"transactions":[]}'}],
            [(RPCEndpoint("eth_getBlockByNumber_raw"), (5, False))],
            b'{"timestamp":1,"transactions":[]}',
        ),
        _DispatchCase(
            "block_raw_hash",
            lambda eth: eth._get_block_raw(BLOCK_HASH, True),
            [{"result": b'{"timestamp":1,"transactions":[]}'}],
            [(RPCEndpoint("eth_getBlockByHash_raw"), (BLOCK_HASH, True))],
            b'{"timestamp":1,"transactions":[]}',
        ),
        _DispatchCase(
            "block_raw_latest",
            lambda eth: eth._get_block_raw("latest", True),
            [{"result": b'{"timestamp":1,"transactions":[]}'}],
            [(RPCEndpoint("eth_getBlockByNumber_raw"), ("latest", True))],
            b'{"timestamp":1,"transactions":[]}',
        ),
        _DispatchCase(
            "trace_filter_decodes_raw",
            lambda eth: eth.trace_filter(
                {"fromBlock": 1, "toBlock": 2},
                decode_to=list[dict[str, Any]],
                decode_hook=None,
            ),
            [{"result": b"[]"}],
            [(RPCEndpoint("trace_filter_raw"), [{"fromBlock": "0x1", "toBlock": "0x2"}])],
            [],
        ),
        _DispatchCase(
            "trace_transaction",
            lambda eth: eth.trace_transaction(TRACE_HASH),
            [{"result": []}],
            [(RPC.trace_transaction, [TRACE_HASH])],
            [],
        ),
    ]


@pytest.mark.parametrize("case", _dispatch_cases(), ids=lambda case: case.name)
def test_dank_eth_direct_dispatch_method_matrix(
    monkeypatch: pytest.MonkeyPatch,
    case: _DispatchCase,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth()
        controller = _RecordingController(list(case.responses))
        _install_controller(monkeypatch, async_w3, controller)
        _forbid_web3_manager(monkeypatch, async_w3)

        assert async_w3.middleware_onion.as_tuple_of_middleware() == ()
        assert await case.call(eth) == case.expected_result
        assert controller.calls == case.expected_calls

    asyncio.run(run())


def _process_param_cases() -> list[_ProcessParamsCase]:
    return [
        _ProcessParamsCase(
            "block_by_number",
            "_get_block",
            (5, False),
            (RPC.eth_getBlockByNumber, ("0x5", False)),
        ),
        _ProcessParamsCase(
            "raw_block_by_latest",
            "_get_block_raw",
            ("latest", True),
            (RPCEndpoint("eth_getBlockByNumber_raw"), ("latest", True)),
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
    method = method_module.MethodNoFormat(
        method_choice_depends_on_args=lambda value: selected_method,
        mungers=[lambda _module, value: [value]],
    )

    request, _formatters = method.process_params(eth, "latest")

    assert request == expected


def test_direct_dispatch_accepts_compact_result_and_applies_result_formatter(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth()
        controller = _RecordingController([{"result": 10}])
        _install_controller(monkeypatch, async_w3, controller)
        _forbid_web3_manager(monkeypatch, async_w3)
        monkeypatch.setitem(
            method_module._response_formatters,
            RPC.eth_blockNumber,
            (lambda result: result + 5, lambda response: response, lambda response: response),
        )

        assert await eth.get_block_number() == 15
        assert controller.calls == [(RPC.eth_blockNumber, ())]

    asyncio.run(run())


def test_direct_dispatch_applies_null_result_formatters(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth()
        controller = _RecordingController([{"result": None}])
        null_calls: list[tuple[Any, RPCResponse, Any]] = []
        _install_controller(monkeypatch, async_w3, controller)
        _forbid_web3_manager(monkeypatch, async_w3)

        def record_null_formatter(formatters: Any, response: RPCResponse, params: Any) -> None:
            null_calls.append((formatters, response, params))

        monkeypatch.setattr(
            method_module,
            "apply_null_result_formatters",
            record_null_formatter,
            raising=False,
        )

        assert await eth.get_block_number() is None
        assert len(null_calls) == 1
        _formatters, response, params = null_calls[0]
        assert response == {"result": None}
        assert params == ()

    asyncio.run(run())


def test_direct_dispatch_existing_filter_short_circuit_does_not_call_controller(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth()
        controller = _RecordingController([{"result": "unexpected"}])
        retrieve = getattr(method_module, "retrieve_dank_method_call_fn", None)
        assert retrieve is not None, "DankEth must expose the direct Method caller"
        _install_controller(monkeypatch, async_w3, controller)

        class ExistingFilterMethod:
            def process_params(self, module: Any, *args: Any, **kwargs: Any) -> None:
                raise _UseExistingFilter("0xfeed")

        result = await retrieve(async_w3, eth)(ExistingFilterMethod())()

        assert isinstance(result, AsyncLogFilter)
        assert result.filter_id == "0xfeed"
        assert controller.calls == []

    asyncio.run(run())


@pytest.mark.parametrize(
    ("error_payload", "expected_exception"),
    [
        ({"code": 3, "message": "execution reverted"}, ExecutionReverted),
        ({"code": -32000, "message": "out of gas"}, OutOfGas),
        ({"code": -32000, "message": "weird node error"}, BadResponse),
        (
            {"code": -32000, "message": "invalid argument 1: hex string without 0x prefix"},
            TypeError,
        ),
        ({"code": -32000, "message": "batch limit 100 exceeded"}, ExceedsMaxBatchSize),
        ({"code": -32000, "message": "payload too large"}, PayloadTooLarge),
        ({"code": -32000, "message": CHAINSTACK_RATE_LIMIT}, ChainstackRateLimitError),
        ({"code": -32000, "message": QUICKNODE_RATE_LIMIT}, QuiknodeRateLimitError),
        (Error(code=3, message="execution reverted"), ExecutionReverted),
    ],
)
def test_direct_dispatch_compact_errors_raise_existing_dank_exceptions(
    monkeypatch: pytest.MonkeyPatch,
    error_payload: dict[str, Any] | Error,
    expected_exception: type[BaseException],
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth()
        controller = _RecordingController([{"error": error_payload}])
        _install_controller(monkeypatch, async_w3, controller)
        _forbid_web3_manager(monkeypatch, async_w3)

        with pytest.raises(expected_exception):
            await eth.get_block_number()

    asyncio.run(run())


def test_direct_dispatch_preserves_error_request_context(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        async_w3, eth = _new_dank_eth()
        request_context = {"method": RPC.eth_blockNumber, "params": ()}
        controller = _RecordingController(
            [
                {
                    "error": {
                        "code": -32000,
                        "message": "weird node error",
                        "dankmids_added_context": request_context,
                    }
                }
            ]
        )
        _install_controller(monkeypatch, async_w3, controller)
        _forbid_web3_manager(monkeypatch, async_w3)

        with pytest.raises(BadResponse) as exc_info:
            await eth.get_block_number()

        assert exc_info.value.request == request_context

    asyncio.run(run())


def test_dank_middleware_and_direct_dank_eth_share_controller_cache(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        async_w3, eth = _new_dank_eth()
        cache_module = _controller_cache_module()
        _clear_controller_cache()

        try:
            middleware_controller = await middleware.DankMiddleware(
                async_w3
            ).async_wrap_make_request(async_w3.provider.make_request)
            direct_get_controller = getattr(method_module, "get_controller_for_async_w3", None)
            assert direct_get_controller is not None, "direct DankEth must use shared controller cache"
            direct_controller = direct_get_controller(async_w3)

            assert middleware_controller is direct_controller
            assert cache_module._controllers == {
                (async_w3, threading.current_thread()): middleware_controller
            }
            assert hasattr(eth, "retrieve_caller_fn")
        finally:
            _clear_controller_cache()

    asyncio.run(run())


def test_controller_cache_keeps_web3_thread_pairs_distinct(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        cache_module = _controller_cache_module()
        _clear_controller_cache()
        async_w3 = _async_w3()
        other_async_w3 = _async_w3()
        get_controller = getattr(cache_module, "get_controller_for_async_w3", None)
        assert get_controller is not None, "controller cache helper must be shared"

        try:
            first = get_controller(async_w3)
            second = get_controller(async_w3)
            other_web3 = get_controller(other_async_w3)
            result_queue: Queue[tuple[Any, threading.Thread, BaseException | None]] = Queue()

            def run_in_thread() -> None:
                try:
                    result = get_controller(async_w3)
                except BaseException as exc:
                    result_queue.put((None, threading.current_thread(), exc))
                else:
                    result_queue.put((result, threading.current_thread(), None))

            other_thread = threading.Thread(target=run_in_thread)
            other_thread.start()
            other_thread.join(timeout=5)
            assert not other_thread.is_alive()
            thread_result, observed_thread, thread_exc = result_queue.get_nowait()
            if thread_exc is not None:
                raise thread_exc

            assert first is second
            assert other_web3 is not first
            assert thread_result is not first
            assert cache_module._controllers == {
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
    monkeypatch.setattr(helpers, "_sync_w3_from_async", lambda _w3: SimpleNamespace(eth=SimpleNamespace(chain_id=1)))
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
        async_w3 = _async_w3()
        route_calls: list[tuple[RPCEndpoint, Any]] = []

        class RouteOnlyController:
            async def __call__(self, method: RPCEndpoint, params: Any) -> RPCResponse:
                route_calls.append((method, params))
                return {"result": BlockNumber(123)}

        route_controller = RouteOnlyController()
        cache_module = _controller_cache_module()
        monkeypatch.setattr(
            cache_module,
            "get_controller_for_async_w3",
            lambda _w3: route_controller,
            raising=False,
        )
        monkeypatch.setattr(
            middleware,
            "get_controller_for_async_w3",
            lambda _w3: route_controller,
            raising=False,
        )
        monkeypatch.setattr(
            middleware,
            "DankMiddlewareController",
            lambda _w3: route_controller,
            raising=False,
        )

        request_func = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
            async_w3.provider.make_request
        )
        response = await request_func(RPC.eth_blockNumber, ())

        assert response == {"result": BlockNumber(123)}
        assert route_calls == [(RPC.eth_blockNumber, ())]

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

        monkeypatch.setattr(controller_module, "rate_limit_inactive", lambda _endpoint: _noop())
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

        monkeypatch.setattr(controller_module, "rate_limit_inactive", lambda _endpoint: _noop())
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

        monkeypatch.setattr(controller_module, "rate_limit_inactive", lambda _endpoint: _noop())
        monkeypatch.setattr(controller_module, "RPCRequest", FakeRPCRequest)

        response = await asyncio.wait_for(controller(RPC.eth_getBalance, (ACCOUNT, "latest")), timeout=1)

        assert response == {"result": "rpc"}
        assert calls == [(controller, RPC.eth_getBalance, (ACCOUNT, "latest"))]

    asyncio.run(run())


async def _noop() -> None:
    return None
