import asyncio
import gc
import weakref
from unittest.mock import patch

import pytest

import dank_mids.controller as controller_module
from dank_mids._requests import JSONRPCBatch, Multicall
from dank_mids._tasks import BATCH_TASKS, create_batch_task
from dank_mids._uid import UIDGenerator
from dank_mids.controller import DankMiddlewareController
from dank_mids.exceptions import GarbageCollectionError


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
        self._fut = asyncio.get_running_loop().create_future()

    def __len__(self) -> int:
        return 1


class _InactiveCall:
    def __bool__(self) -> bool:
        return False


class _RPCBatchCall:
    def __bool__(self) -> bool:
        return True


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
    with patch.object(controller_module, "_sync_w3_from_async", return_value=_DummySyncW3()), patch.object(
        controller_module, "_get_client_version", return_value="dummy-client"
    ), patch.object(controller_module, "_get_multicall2", return_value=_DummyMulticall()), patch.object(
        controller_module, "_get_multicall3", return_value=None
    ):
        return DankMiddlewareController(_DummyW3())


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

        multicall.__del__()

        with pytest.raises(GarbageCollectionError):
            await waiter

        assert waiter.done()

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
        original_start = JSONRPCBatch.start

        def patched_start(self, batch=None, cleanup=True):
            gc.collect()
            started_with_live.append(len(self.calls.snapshot()))
            return original_start(self, batch=batch, cleanup=cleanup)

        async def patched_get_response(self) -> None:
            dispatched.set()
            self._done.set()

        with patch.object(JSONRPCBatch, "start", patched_start), patch.object(
            JSONRPCBatch, "get_response", patched_get_response
        ):
            controller.pending_eth_calls = {"latest": multicall}
            del multicall
            controller.early_start()
            await asyncio.wait_for(dispatched.wait(), timeout=1)

        assert controller.pending_eth_calls == {}
        assert started_with_live == [1]
        assert batch._awaited is True
        assert pending_call._batch is multicall_ref()

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

        with patch.object(JSONRPCBatch, "get_response", patched_get_response):
            batch.append(rpc_call, skip_check=True)
            controller.early_start()
            await asyncio.wait_for(dispatched.wait(), timeout=1)

        assert batch._awaited is True
        assert rpc_call._batch is batch

    asyncio.run(run())
