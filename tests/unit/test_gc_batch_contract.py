import asyncio
import gc
import weakref
from unittest.mock import patch

import pytest

from dank_mids._requests import JSONRPCBatch, Multicall
from dank_mids._tasks import BATCH_TASKS, create_batch_task
from dank_mids._uid import UIDGenerator
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
