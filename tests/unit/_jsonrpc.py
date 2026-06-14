from __future__ import annotations

import json
import threading
from collections.abc import Iterator
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from typing import Any

import pytest
from web3._utils.rpc_abi import RPC
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse


class AsyncProvider(AsyncBaseProvider):
    endpoint_uri = "https://node.example"

    def __init__(
        self,
        endpoint_uri: str = "https://node.example",
        response: RPCResponse | None = None,
    ) -> None:
        super().__init__()
        self.endpoint_uri = endpoint_uri
        self.response = response
        self.calls: list[tuple[RPCEndpoint, Any]] = []

    async def make_request(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        self.calls.append((method, params))
        if self.response is None:
            raise AssertionError(f"unexpected provider request: {method} {params!r}")
        return self.response

    async def is_connected(self, show_traceback: bool = False) -> bool:
        return True


class JsonRpcServer(ThreadingHTTPServer):
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
        assert isinstance(server, JsonRpcServer)
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
    def _handle_request(server: JsonRpcServer, request: dict[str, Any]) -> dict[str, Any]:
        method = request["method"]
        params = request.get("params", [])
        server.calls.append((method, params))
        response = {"jsonrpc": "2.0", "id": request.get("id")}
        if error := server.errors.get(method):
            response["error"] = error
        else:
            response["result"] = server.results[method]
        return response


def server_endpoint(server: JsonRpcServer) -> str:
    return f"http://127.0.0.1:{server.server_port}"


@pytest.fixture
def jsonrpc_server() -> Iterator[JsonRpcServer]:
    server = JsonRpcServer(("127.0.0.1", 0), _JsonRpcHandler)
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
