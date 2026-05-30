from __future__ import annotations

import asyncio
from collections.abc import Callable, Coroutine


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
