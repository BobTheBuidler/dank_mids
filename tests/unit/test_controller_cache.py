import asyncio
import threading
from collections.abc import Iterator
from queue import Queue
from typing import Any, TypeAlias

import pytest
from web3 import AsyncWeb3

import dank_mids.helpers._controllers as controller_cache_module
import dank_mids.middleware as middleware
from tests.unit._jsonrpc import AsyncProvider, JsonRpcServer, jsonrpc_server, server_endpoint


ControllerCache: TypeAlias = dict[tuple[AsyncWeb3, threading.Thread], Any]


def _async_w3(endpoint_uri: str) -> AsyncWeb3:
    async_w3 = AsyncWeb3(AsyncProvider(endpoint_uri))
    async_w3.middleware_onion.clear()
    return async_w3


def _controller_for_request_func(request_func: Any) -> Any:
    return request_func.__self__


@pytest.fixture
def controller_cache() -> Iterator[ControllerCache]:
    controller_cache_module._controllers.clear()
    try:
        yield controller_cache_module._controllers
    finally:
        controller_cache_module._controllers.clear()


def test_controller_cache_reuses_web3_thread_pair(
    controller_cache: ControllerCache,
    jsonrpc_server: JsonRpcServer,
) -> None:
    async def run() -> None:
        async_w3 = _async_w3(server_endpoint(jsonrpc_server))

        first = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
            async_w3.provider.make_request
        )
        second = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
            async_w3.provider.make_request
        )

        assert first is second
        assert controller_cache == {
            (async_w3, threading.current_thread()): _controller_for_request_func(first)
        }

    asyncio.run(run())


def test_controller_cache_keeps_web3_thread_pairs_distinct(
    controller_cache: ControllerCache,
    jsonrpc_server: JsonRpcServer,
) -> None:
    async def run() -> None:
        endpoint_uri = server_endpoint(jsonrpc_server)
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
            (async_w3, threading.current_thread()): _controller_for_request_func(first),
            (other_async_w3, threading.current_thread()): _controller_for_request_func(
                other_web3
            ),
            (async_w3, observed_thread): _controller_for_request_func(thread_result),
        }

    asyncio.run(run())


def test_web3_v7_middleware_class_reuses_controller_for_web3_thread_pair(
    controller_cache: ControllerCache,
    jsonrpc_server: JsonRpcServer,
) -> None:
    async def run() -> None:
        endpoint_uri = server_endpoint(jsonrpc_server)
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
