from __future__ import annotations

from collections.abc import Iterator

import pytest

from dank_mids.helpers import _requester as requester_module
from dank_mids.helpers._requester import HTTPRequesterThread


@pytest.fixture
def requester_thread() -> Iterator[HTTPRequesterThread]:
    requester = requester_module._requester
    original_loop = requester.loop
    original_session = requester._session
    missing = object()
    original_exc = getattr(requester, "_exc", missing)
    try:
        yield requester
    finally:
        requester.loop = original_loop
        requester._session = original_session
        for attr in ("is_alive", "join"):
            try:
                delattr(requester, attr)
            except AttributeError:
                pass
        if original_exc is missing:
            try:
                delattr(requester, "_exc")
            except AttributeError:
                pass
        else:
            requester._exc = original_exc


@pytest.fixture
def owned_requester_thread(monkeypatch: pytest.MonkeyPatch) -> Iterator[HTTPRequesterThread]:
    requester = HTTPRequesterThread()
    monkeypatch.setattr(requester_module, "_requester", requester)
    try:
        yield requester
    finally:
        requester_module.shutdown_http_requester(timeout=1.0)
