import asyncio
import threading
from collections.abc import Iterator
from queue import Queue
from types import SimpleNamespace
from typing import Any, TypeAlias

import pytest
from web3 import AsyncWeb3
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse

import dank_mids.controller as controller_module
import dank_mids.middleware as middleware


ControllerCache: TypeAlias = dict[tuple[AsyncWeb3, threading.Thread], Any]


class _AsyncProvider(AsyncBaseProvider):
    endpoint_uri = "https://node.example"

    async def make_request(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        raise AssertionError(f"unexpected provider request: {method} {params!r}")

    async def is_connected(self, show_traceback: bool = False) -> bool:
        return True


def _async_w3() -> AsyncWeb3:
    async_w3 = AsyncWeb3(_AsyncProvider())
    async_w3.middleware_onion.clear()
    return async_w3


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


@pytest.fixture
def controller_cache() -> Iterator[ControllerCache]:
    middleware._controllers.clear()
    try:
        yield middleware._controllers
    finally:
        middleware._controllers.clear()


def test_controller_cache_reuses_web3_thread_pair(
    monkeypatch: pytest.MonkeyPatch,
    controller_cache: ControllerCache,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        async_w3 = _async_w3()

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
    monkeypatch: pytest.MonkeyPatch,
    controller_cache: ControllerCache,
) -> None:
    async def run() -> None:
        _install_inert_controller_init(monkeypatch)
        async_w3 = _async_w3()
        other_async_w3 = _async_w3()
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
                    result = await middleware.DankMiddleware(async_w3).async_wrap_make_request(
                        async_w3.provider.make_request
                    )
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
    monkeypatch: pytest.MonkeyPatch,
    controller_cache: ControllerCache,
) -> None:
    async def run() -> None:
        try:
            async_w3 = _async_w3()
            other_async_w3 = _async_w3()
            controller_module.instances.clear()

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
        finally:
            controller_module.instances.clear()

    _install_inert_controller_init(monkeypatch)
    asyncio.run(run())
