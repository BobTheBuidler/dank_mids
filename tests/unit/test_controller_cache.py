import asyncio
import json
import threading
from collections.abc import Iterator
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from queue import Queue
from typing import Any, TypeAlias

import pytest
from web3 import AsyncWeb3
from web3._utils.rpc_abi import RPC
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse

import dank_mids.helpers._controllers as controller_cache_module
import dank_mids.middleware as middleware


ControllerCache: TypeAlias = dict[tuple[AsyncWeb3, threading.Thread], Any]


class _AsyncProvider(AsyncBaseProvider):
    endpoint_uri = "https://node.example"

    def __init__(self, endpoint_uri: str = "https://node.example") -> None:
        super().__init__()
        self.endpoint_uri = endpoint_uri

    async def make_request(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        raise AssertionError(f"unexpected provider request: {method} {params!r}")

    async def is_connected(self, show_traceback: bool = False) -> bool:
        return True


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


def _server_endpoint(server: _JsonRpcServer) -> str:
    return f"http://127.0.0.1:{server.server_port}"


def _async_w3(endpoint_uri: str) -> AsyncWeb3:
    async_w3 = AsyncWeb3(_AsyncProvider(endpoint_uri))
    async_w3.middleware_onion.clear()
    return async_w3


@pytest.fixture
def jsonrpc_server() -> Iterator[_JsonRpcServer]:
    server = _JsonRpcServer(("127.0.0.1", 0), _JsonRpcHandler)
    server.calls = []
    server.errors = {}
    server.results = {
        RPC.eth_chainId: "0x1",
        RPC.web3_clientVersion: "pytest/test",
    }
    thread = threading.Thread(target=server.serve_forever, daemon=True)
    thread.start()
    try:
        yield server
    finally:
        server.shutdown()
        thread.join(timeout=5)
        server.server_close()


@pytest.fixture
def controller_cache() -> Iterator[ControllerCache]:
    controller_cache_module._controllers.clear()
    try:
        yield controller_cache_module._controllers
    finally:
        controller_cache_module._controllers.clear()


def test_controller_cache_reuses_web3_thread_pair(
    controller_cache: ControllerCache,
    jsonrpc_server: _JsonRpcServer,
) -> None:
    async def run() -> None:
        async_w3 = _async_w3(_server_endpoint(jsonrpc_server))

        first = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
            async_w3.provider.make_request
        )
        second = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
            async_w3.provider.make_request
        )

        assert first is second
        assert controller_cache == {(async_w3, threading.current_thread()): first}

    asyncio.run(run())


def test_controller_cache_keeps_web3_thread_pairs_distinct(
    controller_cache: ControllerCache,
    jsonrpc_server: _JsonRpcServer,
) -> None:
    async def run() -> None:
        endpoint_uri = _server_endpoint(jsonrpc_server)
        async_w3 = _async_w3(endpoint_uri)
        other_async_w3 = _async_w3(endpoint_uri)
        result_queue: Queue[tuple[Any, threading.Thread, BaseException | None]] = Queue()

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
        assert controller_cache == {
            (async_w3, threading.current_thread()): first,
            (other_async_w3, threading.current_thread()): other_web3,
            (async_w3, observed_thread): thread_result,
        }

    asyncio.run(run())


def test_web3_v7_middleware_class_reuses_controller_for_web3_thread_pair(
    controller_cache: ControllerCache,
    jsonrpc_server: _JsonRpcServer,
) -> None:
    async def run() -> None:
        endpoint_uri = _server_endpoint(jsonrpc_server)
        async_w3 = _async_w3(endpoint_uri)
        other_async_w3 = _async_w3(endpoint_uri)

        first = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
            async_w3.provider.make_request
        )
        second = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
            async_w3.provider.make_request
        )
        other_web3 = await middleware.DankMiddleware(
            other_async_w3
        ).async_wrap_make_request(other_async_w3.provider.make_request)

        result_queue: Queue[tuple[Any, threading.Thread, BaseException | None]]
        result_queue = Queue()

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
        other_thread_result, observed_thread, thread_exc = result_queue.get_nowait()
        if thread_exc is not None:
            raise thread_exc

        assert first is second
        assert other_web3 is not first
        assert other_thread_result is not first
        assert observed_thread is other_thread
        assert set(controller_cache) == {
            (async_w3, threading.current_thread()),
            (other_async_w3, threading.current_thread()),
            (async_w3, other_thread),
        }

    asyncio.run(run())
