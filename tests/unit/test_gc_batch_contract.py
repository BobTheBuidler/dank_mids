import asyncio
import gc
import importlib.util
from functools import lru_cache
from pathlib import Path
import sys
import weakref
from unittest.mock import patch

import pytest

import dank_mids.controller as controller_module
import dank_mids._requests as requests_module
from dank_mids._requests import JSONRPCBatch, Multicall, RPCRequest
from dank_mids._tasks import BATCH_TASKS, create_batch_task
from dank_mids._uid import UIDGenerator
from dank_mids.controller import DankMiddlewareController
from dank_mids.exceptions import GarbageCollectionError
from dank_mids.helpers.future import DebuggableFuture


class _DummyBatcher:
    step = 1000


class _DummyController:
    def __init__(self) -> None:
        self._loop = asyncio.get_running_loop()
        self.call_uid = UIDGenerator()
        self.multicall_uid = UIDGenerator()
        self.jsonrpc_batch_uid = UIDGenerator()
        self.batcher = _DummyBatcher()
        self.endpoint = "http://example.invalid"
        self.max_jsonrpc_batch_size = 1000


class _PendingEthCall:
    def __init__(self) -> None:
        self.block = "latest"
        self._fut = DebuggableFuture(self, asyncio.get_running_loop())  # type: ignore[arg-type]

    def __len__(self) -> int:
        return 1


class _InactiveCall:
    def __bool__(self) -> bool:
        return False


class _RPCBatchCall:
    def __len__(self) -> int:
        return 1

    def __bool__(self) -> bool:
        return True


class _FutureOwner:
    pass


class _DummySyncEth:
    chain_id = 1


class _DummySyncW3:
    eth = _DummySyncEth()
    client_version = "dummy-client"


class _DummyProvider:
    endpoint_uri = "http://example.invalid"


class _DummyW3:
    provider = _DummyProvider()


class _DummyMulticall:
    address = "0x0000000000000000000000000000000000000001"
    bytecode = "0x00"

    @staticmethod
    def needs_override_code_for_block(block: object) -> bool:
        del block
        return False


def _build_controller_for_early_start() -> DankMiddlewareController:
    module = _controller_module_for_tests()
    with patch.object(module, "_sync_w3_from_async", return_value=_DummySyncW3()), patch.object(
        module, "_get_client_version", return_value="dummy-client"
    ), patch.object(module, "_get_multicall2", return_value=_DummyMulticall()), patch.object(
        module, "_get_multicall3", return_value=None
    ):
        return module.DankMiddlewareController(_DummyW3())


@lru_cache(maxsize=1)
def _controller_module_for_tests():
    path = getattr(controller_module, "__file__", "")
    if not path.endswith(".so"):
        return controller_module

    source_path = Path(__file__).resolve().parents[2] / "dank_mids" / "controller.py"
    spec = importlib.util.spec_from_file_location("dank_mids._controller_test_source", source_path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"unable to load controller source module from {source_path}")

    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_create_batch_task_finishes_without_live_waiters() -> None:
    async def run() -> None:
        started = asyncio.Event()
        finished = asyncio.Event()

        async def background() -> None:
            started.set()
            await asyncio.sleep(0)
            finished.set()

        task = create_batch_task(background(), name="gc-contract-test-task")
        task_id = id(task)
        task_ref = weakref.ref(task)
        del task
        gc.collect()

        await asyncio.wait_for(started.wait(), timeout=1)
        await asyncio.wait_for(finished.wait(), timeout=1)
        await asyncio.sleep(0)

        assert task_id not in {id(active) for active in BATCH_TASKS}
        assert task_ref() is None or task_ref().done()

    asyncio.run(run())


def test_multicall_gc_sets_exception_for_active_waiters() -> None:
    async def run() -> None:
        controller = _DummyController()
        call = _PendingEthCall()
        multicall = Multicall(controller, [call], bid="mc-1")
        waiter = asyncio.create_task(asyncio.wait_for(call._fut, timeout=1))
        await asyncio.sleep(0)
        assert call._fut.has_waiters is True

        multicall.__del__()

        with pytest.raises(GarbageCollectionError):
            await waiter

        assert call._fut.has_waiters is False
        assert waiter.done()

    asyncio.run(run())


def test_multicall_gc_treats_no_waiters_as_abandoned_work() -> None:
    async def run() -> None:
        controller = _DummyController()
        call = _PendingEthCall()
        multicall = Multicall(controller, [call], bid="mc-no-waiter")

        with patch("dank_mids._requests.error_logger.error") as log_error:
            multicall.__del__()

        log_error.assert_not_called()
        assert call._fut.done() is False

    asyncio.run(run())


def test_jsonrpc_batch_gc_logs_waiter_impacting_work() -> None:
    async def run() -> None:
        controller = _DummyController()
        call = _PendingEthCall()
        batch = JSONRPCBatch(controller, [call], jid="batch-has-waiter")
        waiter = asyncio.create_task(asyncio.wait_for(call._fut, timeout=1))
        await asyncio.sleep(0)
        assert call._fut.has_waiters is True

        with patch("dank_mids._requests.error_logger.error") as log_error:
            batch.__del__()

        log_error.assert_called_once_with("%s was garbage collected before finishing", batch)
        waiter.cancel()
        with pytest.raises(asyncio.CancelledError):
            await waiter
        assert call._fut.has_waiters is False

    asyncio.run(run())


def test_jsonrpc_batch_gc_treats_no_waiters_as_abandoned_work() -> None:
    async def run() -> None:
        controller = _DummyController()
        call = _PendingEthCall()
        batch = JSONRPCBatch(controller, [call], jid="batch-no-waiter")

        with patch("dank_mids._requests.error_logger.error") as log_error:
            batch.__del__()

        log_error.assert_not_called()

    asyncio.run(run())


def test_rpc_request_gc_treats_no_waiters_as_abandoned_work() -> None:
    async def run() -> None:
        controller = _build_controller_for_early_start()
        request = RPCRequest(controller, "web3_clientVersion", [])

        request.__del__()

        assert request._fut.done() is False

    asyncio.run(run())


def test_rpc_request_gc_sets_exception_for_waiters() -> None:
    async def run() -> None:
        controller = _build_controller_for_early_start()
        request = RPCRequest(controller, "web3_clientVersion", [])
        waiter = asyncio.create_task(asyncio.wait_for(request._fut, timeout=1))
        await asyncio.sleep(0)
        assert request._fut.has_waiters is True

        request.__del__()

        with pytest.raises(GarbageCollectionError):
            await waiter
        assert request._fut.has_waiters is False

    asyncio.run(run())


def test_debuggable_future_waiter_count_updates_on_completion() -> None:
    async def run() -> None:
        future: DebuggableFuture[str] = DebuggableFuture(_FutureOwner(), asyncio.get_running_loop())  # type: ignore[arg-type]
        waiter = asyncio.create_task(asyncio.wait_for(future, timeout=1))
        await asyncio.sleep(0)

        assert future.has_waiters is True
        assert future.waiter_count == 1

        future.set_result("ok")
        result = await waiter

        assert result == "ok"
        assert future.has_waiters is False
        assert future.waiter_count == 0

    asyncio.run(run())


def test_debuggable_future_waiter_count_updates_on_cancellation() -> None:
    async def run() -> None:
        future: DebuggableFuture[str] = DebuggableFuture(_FutureOwner(), asyncio.get_running_loop())  # type: ignore[arg-type]
        waiter = asyncio.create_task(asyncio.wait_for(future, timeout=1))
        await asyncio.sleep(0)

        assert future.has_waiters is True
        assert future.waiter_count == 1

        waiter.cancel()
        with pytest.raises(asyncio.CancelledError):
            await waiter

        assert future.has_waiters is False
        assert future.waiter_count == 0

    asyncio.run(run())


def test_jsonrpc_batch_post_bails_out_when_all_calls_are_collected() -> None:
    async def run() -> None:
        controller = _DummyController()
        batch = JSONRPCBatch(controller, [_InactiveCall()], jid="batch-empty")

        with patch(
            "dank_mids._requests._requester.post",
            side_effect=AssertionError("JSONRPC post should not run for an empty batch"),
        ) as post:
            response = await asyncio.wait_for(batch.post(), timeout=1)

        assert response == []
        post.assert_not_called()

    asyncio.run(run())


def test_early_start_keeps_multicalls_alive_through_handoff_and_dispatches() -> None:
    async def run() -> None:
        controller = _build_controller_for_early_start()
        pending_call = _PendingEthCall()
        multicall = Multicall(controller, [pending_call], bid="mc-handoff")
        multicall_ref = weakref.ref(multicall)

        started_with_live = []
        dispatched = asyncio.Event()
        batch = controller.pending_rpc_calls
        original_start = type(batch).start

        def patched_start(self, batch=None, cleanup=True):
            gc.collect()
            started_with_live.append(len(self.calls.snapshot()))
            return original_start(self, batch=batch, cleanup=cleanup)

        async def patched_get_response(self) -> None:
            dispatched.set()
            self._done.set()

        with patch.object(type(batch), "start", patched_start), patch.object(
            type(batch), "get_response", patched_get_response
        ):
            controller.pending_eth_calls = {"latest": multicall}
            del multicall
            controller.early_start()
            await asyncio.wait_for(dispatched.wait(), timeout=1)

        assert controller.pending_eth_calls == {}
        assert started_with_live == [1]
        assert batch._awaited is True

    asyncio.run(run())


def test_early_start_dispatches_existing_rpc_calls_without_waiters() -> None:
    async def run() -> None:
        controller = _build_controller_for_early_start()
        batch = controller.pending_rpc_calls
        rpc_call = _RPCBatchCall()
        dispatched = asyncio.Event()

        async def patched_get_response(self) -> None:
            dispatched.set()
            self._done.set()

        with patch.object(type(batch), "get_response", patched_get_response):
            batch.append(rpc_call, skip_check=True)
            controller.early_start()
            await asyncio.wait_for(dispatched.wait(), timeout=1)

        assert batch._awaited is True
        assert rpc_call._batch is batch

    asyncio.run(run())


def test_batch_full_gate_dispatches_without_waiters() -> None:
    async def run() -> None:
        controller = _build_controller_for_early_start()
        controller.max_jsonrpc_batch_size = 1
        batch = controller.pending_rpc_calls
        rpc_call = _RPCBatchCall()
        dispatched = asyncio.Event()

        async def patched_get_response(self) -> None:
            dispatched.set()
            self._done.set()

        with patch.object(type(batch), "get_response", patched_get_response):
            batch.append(rpc_call)
            await asyncio.wait_for(dispatched.wait(), timeout=1)

        assert batch._awaited is True
        assert rpc_call._batch is batch

    asyncio.run(run())


def test_request_gate_waits_for_one_loop_tick_before_dispatch() -> None:
    async def run() -> None:
        controller = _build_controller_for_early_start()
        request = RPCRequest(controller, "web3_clientVersion", [])
        # Some other unit tests toggle global batching behavior; pin this test to the batched path.
        request.should_batch = True
        request._batch = None
        first_tick = asyncio.Event()
        release_first_tick = asyncio.Event()
        yield_calls = 0
        execute_batch_calls = 0

        async def patched_yield_to_loop() -> None:
            nonlocal yield_calls
            yield_calls += 1
            if yield_calls == 1:
                first_tick.set()
                await release_first_tick.wait()
            else:
                await asyncio.sleep(0)

        async def patched_execute_batch(self) -> None:
            nonlocal execute_batch_calls
            execute_batch_calls += 1
            if not request._fut.done():
                request._fut.set_result(
                    {"jsonrpc": "2.0", "id": request.uid, "result": "0x1"}
                )

        with patch.object(requests_module, "yield_to_loop", patched_yield_to_loop), patch.object(
            type(controller), "execute_batch", patched_execute_batch
        ):
            response_task = asyncio.create_task(request.get_response())
            await asyncio.wait_for(first_tick.wait(), timeout=1)
            assert execute_batch_calls == 0
            release_first_tick.set()
            response = await asyncio.wait_for(response_task, timeout=1)

        assert yield_calls >= 1
        assert execute_batch_calls == 1
        assert response["result"] == "0x1"

    asyncio.run(run())


def test_controller_has_pending_calls_ignores_stale_eth_entries() -> None:
    async def run() -> None:
        controller = _build_controller_for_early_start()

        stale_multicall = Multicall(controller, [], bid="mc-stale")
        controller.pending_eth_calls = {"latest": stale_multicall}
        assert bool(controller.pending_eth_calls) is True
        assert controller.has_pending_calls is False

        live_call = _PendingEthCall()
        live_multicall = Multicall(controller, [live_call], bid="mc-live")
        controller.pending_eth_calls = {"latest": live_multicall}
        assert controller.has_pending_calls is True

    asyncio.run(run())


def test_request_gate_skips_execute_batch_for_stale_eth_entries() -> None:
    async def run() -> None:
        controller = _build_controller_for_early_start()
        request = RPCRequest(controller, "web3_clientVersion", [])
        # Some other unit tests toggle global batching behavior; pin this test to the batched path.
        request.should_batch = True
        request._batch = None
        request._fut.set_result({"jsonrpc": "2.0", "id": request.uid, "result": "0x1"})

        # Remove the queued request from controller state so only stale eth entries remain.
        controller.pending_rpc_calls = JSONRPCBatch(controller)
        controller.pending_eth_calls = {"latest": Multicall(controller, [], bid="mc-stale")}
        assert bool(controller.pending_eth_calls) is True
        assert controller.has_pending_calls is False

        async def patched_execute_batch(self) -> None:
            raise AssertionError("execute_batch should not be scheduled for stale eth entries")

        with patch.object(type(controller), "execute_batch", patched_execute_batch):
            response = await asyncio.wait_for(request.get_response(), timeout=1)

        assert response["result"] == "0x1"

    asyncio.run(run())
