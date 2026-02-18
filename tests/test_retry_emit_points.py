import asyncio
import sys
import types

from aiohttp import ClientResponseError
from multidict import CIMultiDict

from dank_mids.retry_observer import RetryEvent, register_retry_observer, unregister_retry_observer


def _install_aiolimiter_stub() -> None:
    from aiolimiter import AsyncLimiter

    for name in (
        "dank_mids._vendor",
        "dank_mids._vendor.aiolimiter",
        "dank_mids._vendor.aiolimiter.src",
        "dank_mids._vendor.aiolimiter.src.aiolimiter",
    ):
        sys.modules.setdefault(name, types.ModuleType(name))

    sys.modules["dank_mids._vendor.aiolimiter.src.aiolimiter"].AsyncLimiter = AsyncLimiter


def test_session_429_emits_retry_event() -> None:
    _install_aiolimiter_stub()
    from dank_mids.helpers import _session
    from dank_mids.helpers._session import DankClientSession

    events: list[RetryEvent] = []

    def observer(event: RetryEvent) -> None:
        events.append(event)

    register_retry_observer(observer)
    endpoint = "https://example.com"
    limiter = _session.AsyncLimiter(1, 1)
    old_limiters = _session.limiters
    error = ClientResponseError(
        request_info=None,
        history=(),
        status=429,
        message="too many requests",
        headers=CIMultiDict({"Retry-After": "0.25"}),
    )

    async def run() -> None:
        _session.limiters = {endpoint: limiter}
        session = DankClientSession()
        try:
            await session._handle_too_many_requests(endpoint, error, attempt=1)
        finally:
            await session.close()
            _session.limiters = old_limiters

    try:
        asyncio.run(run())
    finally:
        unregister_retry_observer(observer)

    assert events
    event = events[-1]
    assert event.operation == "http_post"
    assert event.component == "session"
    assert event.attempt == 1
    assert event.delay == 0.25
    assert event.will_retry is True
    assert event.metadata == {"status": "429"}
