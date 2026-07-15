import asyncio
import sys
from collections.abc import Iterator
from types import SimpleNamespace
from typing import Any

import pytest
from hexbytes import HexBytes
from web3 import AsyncWeb3
from web3._utils.rpc_abi import RPC
from web3.exceptions import BadResponseFormat, Web3RPCError
from web3.middleware import AttributeDictMiddleware, ExtraDataToPOAMiddleware
from web3.providers.async_base import AsyncBaseProvider
from web3.providers.base import BaseProvider
from web3.types import RPCEndpoint, RPCResponse

import dank_mids
import dank_mids.helpers._controllers as controller_cache_module
import dank_mids.helpers._helpers as helpers
from dank_mids.helpers import _requester as requester_module
import dank_mids.middleware as middleware  # Keep source/compiled imports identical.
from tests.unit._jsonrpc import (
    AsyncProvider as JsonRpcAsyncProvider,
    JsonRpcServer,
    jsonrpc_server,
    server_endpoint,
)


CLIENT_VERSION = "reth/v1.10.2-8e3b5e6/x86_64-unknown-linux-gnu"


class _AsyncProvider(AsyncBaseProvider):
    endpoint_uri = "http://example.invalid"

    def __init__(self, response: RPCResponse | None = None) -> None:
        super().__init__()
        self.response = response or {"jsonrpc": "2.0", "id": 1, "result": "ok"}
        self.calls: list[tuple[RPCEndpoint, Any]] = []

    async def make_request(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        self.calls.append((method, params))
        return self.response

    async def is_connected(self, show_traceback: bool = False) -> bool:
        return True


class _SyncProvider(BaseProvider):
    endpoint_uri = "http://example.invalid"

    def make_request(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        return {"jsonrpc": "2.0", "id": 1, "result": "ok"}

    def is_connected(self, show_traceback: bool = False) -> bool:
        return True


class _RecordingOnion:
    def __init__(self, existing: tuple[Any, ...] = ()) -> None:
        self.existing = existing
        self.add_calls: list[Any] = []
        self.inject_calls: list[tuple[Any, int]] = []

    def __contains__(self, middleware_class: Any) -> bool:
        return (
            middleware_class in self.existing
            or middleware_class in self.add_calls
            or middleware_class in (call[0] for call in self.inject_calls)
        )

    def add(self, middleware_class: Any) -> None:
        self.add_calls.append(middleware_class)

    def inject(self, middleware_class: Any, layer: int) -> None:
        self.inject_calls.append((middleware_class, layer))


def _async_w3(response: RPCResponse | None = None) -> AsyncWeb3:
    async_w3 = AsyncWeb3(_AsyncProvider(response))
    async_w3.middleware_onion.clear()
    return async_w3


def _jsonrpc_async_w3(jsonrpc_server: JsonRpcServer) -> AsyncWeb3:
    async_w3 = AsyncWeb3(JsonRpcAsyncProvider(server_endpoint(jsonrpc_server)))
    async_w3.middleware_onion.clear()
    async_w3.middleware_onion.inject(middleware.DankMiddleware, layer=0)
    return async_w3


def _last_payload_for_method(
    jsonrpc_server: JsonRpcServer, method: RPCEndpoint
) -> dict[str, Any]:
    return next(
        payload
        for payload in reversed(jsonrpc_server.payloads)
        if payload["method"] == method
    )


@pytest.fixture
def requester_session_cleanup() -> Iterator[None]:
    try:
        yield
    finally:
        requester = requester_module._requester
        session = requester._session
        if session is None:
            return
        if not session.closed:
            future = asyncio.run_coroutine_threadsafe(session.close(), requester.loop)
            future.result(timeout=2)
        requester._session = None


def _assert_dank_middleware_removal(exc: ImportError) -> None:
    message = str(exc)
    assert "dank_middleware" in message
    assert "web3 v7" in message
    assert "DankMiddleware" in message
    assert "setup_dank_w3" in message


def test_dank_middleware_naming_instance_keeps_python_attr_layout() -> None:
    instance = middleware.DankMiddleware(None)

    # Guards Web3's unnamed-class naming path until mypyc issue #1200 is fixed.
    assert instance.__dict__["_w3"] is None
    assert hash(instance) == instance.__hash__()


def test_web3_v7_middleware_class_composes_with_async_onion() -> None:
    try:
        async_w3 = _async_w3()
        controller_cache_module._controllers.clear()

        # This is setup_dank_w3's runtime path: unnamed Web3 v7 class injection.
        async_w3.middleware_onion.inject(middleware.DankMiddleware, layer=0)

        assert async_w3.middleware_onion.as_tuple_of_middleware() == (
            middleware.DankMiddleware,
        )
        assert controller_cache_module._controllers == {}
    finally:
        controller_cache_module._controllers.clear()


def test_web3_v7_setup_dank_w3_injects_class_with_real_async_onion(monkeypatch) -> None:
    dank_eth = object()
    async_w3 = _async_w3()
    monkeypatch.setattr(dank_mids, "_ensure_side_effects", lambda: None)
    monkeypatch.setattr(helpers, "DankEth", lambda _async_w3: dank_eth)
    monkeypatch.setattr(
        helpers,
        "_sync_w3_from_async",
        lambda _async_w3: SimpleNamespace(eth=SimpleNamespace(chain_id=1)),
    )
    try:
        helpers.dank_w3s.clear()
        controller_cache_module._controllers.clear()
        assert helpers.setup_dank_w3(async_w3) is async_w3

        assert async_w3.middleware_onion.as_tuple_of_middleware() == (
            middleware.DankMiddleware,
        )
        assert async_w3.eth is dank_eth
        assert controller_cache_module._controllers == {}
    finally:
        helpers.dank_w3s.clear()
        controller_cache_module._controllers.clear()


def test_non_mainnet_setup_injects_web3_v7_poa_middleware_before_dank(monkeypatch) -> None:
    dank_eth = object()
    async_w3 = SimpleNamespace(
        eth=SimpleNamespace(is_async=True),
        provider=_AsyncProvider(),
        middleware_onion=_RecordingOnion(),
    )
    monkeypatch.setattr(dank_mids, "_ensure_side_effects", lambda: None)
    monkeypatch.setattr(helpers, "DankEth", lambda _async_w3: dank_eth)
    monkeypatch.setattr(
        helpers,
        "_sync_w3_from_async",
        lambda _async_w3: SimpleNamespace(eth=SimpleNamespace(chain_id=137)),
    )
    try:
        helpers.dank_w3s.clear()
        helpers.setup_dank_w3(async_w3)

        assert async_w3.middleware_onion.inject_calls == [
            (ExtraDataToPOAMiddleware, 0),
            (middleware.DankMiddleware, 0),
        ]
        assert async_w3.eth is dank_eth
    finally:
        helpers.dank_w3s.clear()


def test_non_mainnet_setup_skips_existing_async_poa_and_dank_middleware(monkeypatch) -> None:
    """Async setup is idempotent when POA and Dank middleware are already installed."""
    dank_eth = object()
    async_w3 = SimpleNamespace(
        eth=SimpleNamespace(is_async=True),
        provider=_AsyncProvider(),
        middleware_onion=_RecordingOnion(
            existing=(ExtraDataToPOAMiddleware, middleware.DankMiddleware)
        ),
    )
    monkeypatch.setattr(dank_mids, "_ensure_side_effects", lambda: None)
    monkeypatch.setattr(helpers, "DankEth", lambda _async_w3: dank_eth)
    monkeypatch.setattr(
        helpers,
        "_sync_w3_from_async",
        lambda _async_w3: SimpleNamespace(eth=SimpleNamespace(chain_id=137)),
    )
    try:
        helpers.dank_w3s.clear()
        helpers.setup_dank_w3(async_w3)

        assert async_w3.middleware_onion.inject_calls == []
        assert async_w3.eth is dank_eth
    finally:
        helpers.dank_w3s.clear()


def test_non_mainnet_setup_injects_only_missing_async_dank_middleware(monkeypatch) -> None:
    """Async setup preserves existing POA middleware and adds missing Dank middleware."""
    dank_eth = object()
    async_w3 = SimpleNamespace(
        eth=SimpleNamespace(is_async=True),
        provider=_AsyncProvider(),
        middleware_onion=_RecordingOnion(existing=(ExtraDataToPOAMiddleware,)),
    )
    monkeypatch.setattr(dank_mids, "_ensure_side_effects", lambda: None)
    monkeypatch.setattr(helpers, "DankEth", lambda _async_w3: dank_eth)
    monkeypatch.setattr(
        helpers,
        "_sync_w3_from_async",
        lambda _async_w3: SimpleNamespace(eth=SimpleNamespace(chain_id=137)),
    )
    try:
        helpers.dank_w3s.clear()
        helpers.setup_dank_w3(async_w3)

        assert async_w3.middleware_onion.inject_calls == [(middleware.DankMiddleware, 0)]
        assert async_w3.eth is dank_eth
    finally:
        helpers.dank_w3s.clear()


def test_dank_middleware_attribute_raises_migration_error() -> None:
    with pytest.raises(ImportError) as exc_info:
        getattr(middleware, "dank_middleware")

    _assert_dank_middleware_removal(exc_info.value)


def test_dank_middleware_import_raises_migration_error(monkeypatch) -> None:
    monkeypatch.setitem(sys.modules, "dank_mids.middleware", middleware)
    monkeypatch.setattr(dank_mids, "middleware", middleware, raising=False)

    with pytest.raises(ImportError) as exc_info:
        exec("from dank_mids.middleware import dank_middleware", {})

    _assert_dank_middleware_removal(exc_info.value)


def test_top_level_dank_middleware_import_raises_migration_error() -> None:
    dank_mids.__dict__.pop("dank_middleware", None)

    with pytest.raises(ImportError) as exc_info:
        exec("from dank_mids import dank_middleware", {})

    _assert_dank_middleware_removal(exc_info.value)


def test_web3_manager_accepts_dank_client_version_response(
    jsonrpc_server: JsonRpcServer,
    requester_session_cleanup: None,
) -> None:
    async def run() -> None:
        jsonrpc_server.results[RPC.web3_clientVersion] = CLIENT_VERSION
        async_w3 = _jsonrpc_async_w3(jsonrpc_server)

        try:
            result = await async_w3.manager.coro_request(RPC.web3_clientVersion, [])
        except BadResponseFormat as exc:
            pytest.fail(f"Dank returned a partial response across the Web3 boundary: {exc}")

        assert result == CLIENT_VERSION

    try:
        asyncio.run(run())
    finally:
        controller_cache_module._controllers.clear()


def test_web3_boundary_normalizes_success_response_envelope(
    jsonrpc_server: JsonRpcServer,
    requester_session_cleanup: None,
) -> None:
    async def run() -> None:
        jsonrpc_server.results[RPC.web3_clientVersion] = CLIENT_VERSION
        async_w3 = _jsonrpc_async_w3(jsonrpc_server)
        request_func = await async_w3.provider.request_func(
            async_w3, async_w3.middleware_onion
        )

        response = await request_func(RPC.web3_clientVersion, [])
        payload = _last_payload_for_method(jsonrpc_server, RPC.web3_clientVersion)

        assert response["jsonrpc"] == "2.0"
        assert response["id"] == payload["id"]
        assert response["result"] == CLIENT_VERSION

    try:
        asyncio.run(run())
    finally:
        controller_cache_module._controllers.clear()


def test_web3_boundary_normalizes_error_response_envelope(
    jsonrpc_server: JsonRpcServer,
    requester_session_cleanup: None,
) -> None:
    async def run() -> None:
        error = {"code": -32000, "message": "weird node error"}
        jsonrpc_server.errors[RPC.eth_blockNumber] = error
        async_w3 = _jsonrpc_async_w3(jsonrpc_server)
        request_func = await async_w3.provider.request_func(
            async_w3, async_w3.middleware_onion
        )

        response = await request_func(RPC.eth_blockNumber, [])
        payload = _last_payload_for_method(jsonrpc_server, RPC.eth_blockNumber)

        assert response["jsonrpc"] == "2.0"
        assert response["id"] == payload["id"]
        assert response["error"]["code"] == error["code"]
        assert response["error"]["message"] == error["message"]

        with pytest.raises(Web3RPCError):
            await async_w3.manager.coro_request(RPC.eth_blockNumber, [])

    try:
        asyncio.run(run())
    finally:
        controller_cache_module._controllers.clear()


def test_controller_make_request_preserves_zero_request_id(
    jsonrpc_server: JsonRpcServer,
    requester_session_cleanup: None,
) -> None:
    async def run() -> None:
        async_w3 = _jsonrpc_async_w3(jsonrpc_server)
        request_func = await async_w3.provider.request_func(
            async_w3, async_w3.middleware_onion
        )
        controller = request_func

        await controller.make_request(RPC.eth_blockNumber, [], request_id=0)
        payload = _last_payload_for_method(jsonrpc_server, RPC.eth_blockNumber)

        assert payload["id"] == 0

    try:
        asyncio.run(run())
    finally:
        controller_cache_module._controllers.clear()


def test_web3_v7_poa_middleware_formats_async_block_response() -> None:
    async def run() -> None:
        async_w3 = _async_w3(
            {
                "jsonrpc": "2.0",
                "id": 1,
                "result": {"number": "0x1", "extraData": "0x1234"},
            }
        )
        async_w3.middleware_onion.add(ExtraDataToPOAMiddleware)
        request_func = await async_w3.provider.request_func(
            async_w3, async_w3.middleware_onion
        )

        response = await request_func(
            RPCEndpoint("eth_getBlockByNumber"), ["latest", False]
        )

        assert "extraData" not in response["result"]
        assert response["result"]["proofOfAuthorityData"] == HexBytes("0x1234")

    asyncio.run(run())


def test_sync_setup_uses_web3_v7_middleware_classes(monkeypatch) -> None:
    sync_w3 = SimpleNamespace(
        eth=SimpleNamespace(is_async=False, chain_id=137),
        provider=_SyncProvider(),
        middleware_onion=_RecordingOnion(),
    )
    async_w3 = object()
    setup_result = object()
    monkeypatch.setattr(dank_mids, "_ensure_side_effects", lambda: None)
    monkeypatch.setattr(helpers, "get_async_w3", lambda _sync_w3: async_w3)
    monkeypatch.setattr(helpers, "setup_dank_w3", lambda _async_w3: setup_result)
    try:
        helpers.sync_w3s.clear()
        assert helpers.setup_dank_w3_from_sync(sync_w3) is setup_result

        assert sync_w3.middleware_onion.add_calls == [AttributeDictMiddleware]
        assert sync_w3.middleware_onion.inject_calls == [(ExtraDataToPOAMiddleware, 0)]
    finally:
        helpers.sync_w3s.clear()


def test_sync_setup_skips_existing_web3_v7_middleware(monkeypatch) -> None:
    sync_w3 = SimpleNamespace(
        eth=SimpleNamespace(is_async=False, chain_id=137),
        provider=_SyncProvider(),
        middleware_onion=_RecordingOnion(
            existing=(AttributeDictMiddleware, ExtraDataToPOAMiddleware)
        ),
    )
    async_w3 = object()
    setup_result = object()
    monkeypatch.setattr(dank_mids, "_ensure_side_effects", lambda: None)
    monkeypatch.setattr(helpers, "get_async_w3", lambda _sync_w3: async_w3)
    monkeypatch.setattr(helpers, "setup_dank_w3", lambda _async_w3: setup_result)
    try:
        helpers.sync_w3s.clear()
        assert helpers.setup_dank_w3_from_sync(sync_w3) is setup_result

        assert sync_w3.middleware_onion.add_calls == []
        assert sync_w3.middleware_onion.inject_calls == []
    finally:
        helpers.sync_w3s.clear()
