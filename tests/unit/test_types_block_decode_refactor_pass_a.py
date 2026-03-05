import pytest
from msgspec import ValidationError

from dank_mids import types


@pytest.fixture(autouse=True)
def _reset_block_return_type(monkeypatch):
    monkeypatch.setitem(types._RETURN_TYPES, "eth_getBlockByNumber", types.Block)


def _response():
    return types.PartialResponse(result=b"{}")


def test_eth_get_block_by_number_totaldifficulty_then_minedblock(monkeypatch) -> None:
    calls = []

    def fake_better_decode(data, *, type, dec_hook, method):  # noqa: A002
        calls.append(type)
        if type is types.Block:
            raise Exception("Object contains unknown field `totalDifficulty`")
        if type is types.MinedBlock:
            return "mined-block"
        raise AssertionError(type)

    monkeypatch.setattr(types, "better_decode", fake_better_decode)

    assert _response().decode_result("eth_getBlockByNumber") == "mined-block"
    assert calls == [types.Block, types.MinedBlock]
    assert types._RETURN_TYPES["eth_getBlockByNumber"] is types.Block


def test_eth_get_block_by_number_totaldifficulty_then_baseblock_and_mutates(monkeypatch) -> None:
    calls = []

    def fake_better_decode(data, *, type, dec_hook, method):  # noqa: A002
        calls.append(type)
        if type is types.Block:
            raise Exception("Object contains unknown field `totalDifficulty`")
        if type is types.MinedBlock:
            raise ValidationError("Object contains unknown field `baseFeePerGas`")
        if type is types.BaseBlock:
            return "base-block"
        raise AssertionError(type)

    monkeypatch.setattr(types, "better_decode", fake_better_decode)

    assert _response().decode_result("eth_getBlockByNumber") == "base-block"
    assert calls == [types.Block, types.MinedBlock, types.BaseBlock]
    assert types._RETURN_TYPES["eth_getBlockByNumber"] is types.BaseBlock


def test_eth_get_block_by_number_withdrawals_then_shanghai_capella(monkeypatch) -> None:
    calls = []

    def fake_better_decode(data, *, type, dec_hook, method):  # noqa: A002
        calls.append(type)
        if type is types.Block:
            raise Exception("Object contains unknown field `withdrawals`")
        if type is types.ShanghaiCapellaBlock:
            return "shanghai-capella"
        raise AssertionError(type)

    monkeypatch.setattr(types, "better_decode", fake_better_decode)

    assert _response().decode_result("eth_getBlockByNumber") == "shanghai-capella"
    assert calls == [types.Block, types.ShanghaiCapellaBlock]


def test_eth_get_block_by_number_difficulty_then_baseblock(monkeypatch) -> None:
    calls = []

    def fake_better_decode(data, *, type, dec_hook, method):  # noqa: A002
        calls.append(type)
        if type is types.Block:
            raise Exception("Object contains unknown field `difficulty`")
        if type is types.BaseBlock:
            return "base-block"
        raise AssertionError(type)

    monkeypatch.setattr(types, "better_decode", fake_better_decode)

    assert _response().decode_result("eth_getBlockByNumber") == "base-block"
    assert calls == [types.Block, types.BaseBlock]


def test_eth_get_block_by_number_unrecognized_unknown_field_reraises(monkeypatch) -> None:
    def fake_better_decode(data, *, type, dec_hook, method):  # noqa: A002
        raise Exception("Object contains unknown field `blobGasUsed`")

    monkeypatch.setattr(types, "better_decode", fake_better_decode)

    with pytest.raises(Exception, match="blobGasUsed"):
        _response().decode_result("eth_getBlockByNumber")


def test_eth_get_block_by_number_when_typ_not_block_does_not_fallback(monkeypatch) -> None:
    monkeypatch.setitem(types._RETURN_TYPES, "eth_getBlockByNumber", types.BaseBlock)

    def fake_better_decode(data, *, type, dec_hook, method):  # noqa: A002
        raise Exception("Object contains unknown field `withdrawals`")

    monkeypatch.setattr(types, "better_decode", fake_better_decode)

    with pytest.raises(Exception, match="withdrawals"):
        _response().decode_result("eth_getBlockByNumber")
