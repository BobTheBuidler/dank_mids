import asyncio
from contextlib import suppress
from pathlib import Path

import pytest

aiolimiter = pytest.importorskip("dank_mids._vendor.aiolimiter.src.aiolimiter")
AsyncLimiter = aiolimiter.AsyncLimiter

from dank_mids.helpers import _rate_limit  # noqa: E402


def _queued_futures(limiter: AsyncLimiter) -> list[asyncio.Future[None]]:
    return [waiter[-1] for waiter in limiter._waiters]


def test_async_limiter_comes_from_vendored_path() -> None:
    module_path = Path(aiolimiter.__file__).as_posix()

    assert "dank_mids/_vendor/aiolimiter/src/aiolimiter" in module_path
    assert AsyncLimiter.__name__ == "AsyncLimiter"


def test_acquire_throttles_after_initial_capacity() -> None:
    async def run() -> None:
        limiter = AsyncLimiter(1, 0.05)
        loop = asyncio.get_running_loop()

        started = loop.time()
        await limiter.acquire()
        await asyncio.wait_for(limiter.acquire(), timeout=1)

        assert loop.time() - started >= 0.04

    asyncio.run(run())


def test_waiters_heap_tracks_queued_acquires_until_capacity_returns() -> None:
    async def run() -> None:
        limiter = AsyncLimiter(1, 0.05)
        await limiter.acquire()

        waiter = asyncio.create_task(limiter.acquire())
        await asyncio.sleep(0)

        assert len(limiter._waiters) == 1
        amount, _, future = limiter._waiters[0]
        assert amount == 1
        assert future.done() is False

        await asyncio.wait_for(waiter, timeout=1)

        assert limiter._waiters == []

    asyncio.run(run())


def test_cancelled_waiter_is_removed_from_heap_on_next_wake() -> None:
    async def run() -> None:
        limiter = AsyncLimiter(1, 0.05)
        await limiter.acquire()

        waiter = asyncio.create_task(limiter.acquire())
        await asyncio.sleep(0)
        queued_future = _queued_futures(limiter)[0]

        waiter.cancel()
        with pytest.raises(asyncio.CancelledError):
            await waiter

        assert queued_future.cancelled() is True

        limiter._wake_next()

        assert limiter._waiters == []

    asyncio.run(run())


def test_rate_limit_inactive_waits_for_vendored_waiter_heap() -> None:
    async def run() -> None:
        endpoint = "unit-vendored-aiolimiter"
        limiter = AsyncLimiter(1, 0.05)
        _rate_limit.limiters[endpoint] = limiter
        waiter: asyncio.Task[None] | None = None

        try:
            await limiter.acquire()
            waiter = asyncio.create_task(limiter.acquire())
            await asyncio.sleep(0)

            assert limiter._waiters

            await asyncio.wait_for(_rate_limit._rate_limit_inactive(endpoint), timeout=1)
            await asyncio.wait_for(waiter, timeout=1)

            assert limiter._waiters == []
        finally:
            if waiter is not None and not waiter.done():
                waiter.cancel()
                with suppress(asyncio.CancelledError):
                    await waiter
            _rate_limit.limiters.pop(endpoint, None)
            _rate_limit._rate_limit_waiters.pop(endpoint, None)
            task = _rate_limit._rate_limit_tasks.pop(endpoint, None)
            if task is not None:
                task.cancel()
                with suppress(asyncio.CancelledError):
                    await task

    asyncio.run(run())
