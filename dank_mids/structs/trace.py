
from decimal import Decimal
from functools import cached_property
from typing import Literal, Optional

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs.data import Address, uint, _decode_hook
from dank_mids.structs.dict import DictStruct, LazyDictStruct


class Action(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    callType: Literal["call", "delegatecall"]
    _sender: Address = field(name="from")
    _to: Address
    _author: Address = field(name="author", default=UNSET)
    input: HexBytes
    gas: uint
    rewardType: Optional[Literal["block", "uncle"]] = None
    _value: Raw = field(name="value", default=UNSET)

    @cached_property
    def sender(self) -> Address:
        return json.decode(self._sender, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def to(self) -> Address:
        return json.decode(self._to, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def author(self) -> Address:
        return json.decode(self._author, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def value(self) -> Decimal:
        return Decimal(json.decode(self._value, type=uint, dec_hook=uint._decode_hook)) / 10 ** 18

class Result(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    output: HexBytes
    gasUsed: uint

class FilterTrace(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    blockNumber: uint
    blockHash: HexBytes
    transactionHash: HexBytes
    transactionPosition: int
    _address: Raw = field(name="address", default=UNSET)
    _action: Raw = field(name="action", default=UNSET)
    _result: Raw = field(name="result", default=UNSET)

    @property
    def block(self) -> uint:
        return self.blockNumber

    @cached_property
    def address(self) -> Address:
        return json.decode(self._address, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def action(self) -> Action:
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)

    @cached_property
    def result(self) -> Result:
        return json.decode(self._result, type=Result, dec_hook=_decode_hook)
