from types import SimpleNamespace

import web3.middleware as middleware

import dank_mids.helpers._helpers as helpers


class _MiddlewareOnion:
    def __init__(self) -> None:
        self.add_calls = []

    def add(self, middleware_fn) -> None:
        self.add_calls.append(middleware_fn)


def _make_sync_w3():
    return SimpleNamespace(
        eth=SimpleNamespace(is_async=False),
        middleware_onion=_MiddlewareOnion(),
    )


def _add_sync_attrdict_middleware():
    return helpers.__dict__["__add_sync_attrdict_middleware"]


def test_add_sync_attrdict_middleware_uses_legacy_symbol(monkeypatch) -> None:
    sentinel = object()
    monkeypatch.setattr(middleware, "attrdict_middleware", sentinel, raising=False)
    monkeypatch.delattr(middleware, "AttributeDictMiddleware", raising=False)

    sync_w3 = _make_sync_w3()
    _add_sync_attrdict_middleware()(sync_w3)

    assert sync_w3.middleware_onion.add_calls == [sentinel]


def test_add_sync_attrdict_middleware_falls_back_to_v7_symbol(monkeypatch) -> None:
    sentinel = object()
    monkeypatch.delattr(middleware, "attrdict_middleware", raising=False)
    monkeypatch.setattr(middleware, "AttributeDictMiddleware", sentinel, raising=False)

    sync_w3 = _make_sync_w3()
    _add_sync_attrdict_middleware()(sync_w3)

    assert sync_w3.middleware_onion.add_calls == [sentinel]
