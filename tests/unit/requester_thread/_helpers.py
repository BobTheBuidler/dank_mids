from __future__ import annotations

import asyncio
import time
from collections.abc import Callable, Coroutine
from typing import TYPE_CHECKING, TypeVar

if TYPE_CHECKING:
    from dank_mids.helpers._requester import HTTPRequesterThread

T = TypeVar("T")


class InlineLoop:
    def __init__(self, *, closed: bool = False) -> None:
        self._closed = closed
        self.stopped = False
        self.callbacks: list[Callable[..., None]] = []

    def is_closed(self) -> bool:
        return self._closed

    def call_soon_threadsafe(self, callback: Callable[..., None], *args) -> None:
        self.callbacks.append(callback)
        callback(*args)

    def stop(self) -> None:
        self.stopped = True

    def close(self) -> None:
        self._closed = True


class ClosableSession:
    def __init__(self) -> None:
        self.closed = False

    async def close(self) -> None:
        self.closed = True


class CompletedFuture:
    def result(self, timeout: float | None = None) -> None:
        del timeout


def run_coroutine_now(coro: Coroutine[None, None, None]) -> CompletedFuture:
    asyncio.run(coro)
    return CompletedFuture()


async def run_on_requester_loop(
    requester: HTTPRequesterThread,
    fn: Callable[[], T],
    *,
    timeout: float = 2.0,
) -> T:
    async def run() -> T:
        return fn()

    future = asyncio.run_coroutine_threadsafe(run(), requester.loop)
    return await asyncio.wait_for(asyncio.wrap_future(future), timeout=timeout)


async def wait_for_requester_state(
    requester: HTTPRequesterThread,
    predicate: Callable[[], bool],
    *,
    timeout: float = 2.0,
) -> None:
    deadline = time.monotonic() + timeout
    while True:
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            break
        if await run_on_requester_loop(requester, predicate, timeout=remaining):
            return
        await asyncio.sleep(min(0.01, remaining))
    raise AssertionError("requester loop state did not settle before timeout")
