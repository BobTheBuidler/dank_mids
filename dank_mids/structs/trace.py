
from functools import cached_property

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs.data import Address, uint, _decode_hook
from dank_mids.structs.dict import DictStruct, LazyDictStruct


class Action(DictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    rewardType: str

#class Result(DictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    

class FilterTrace(LazyDictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    blockNumber: uint
    transactionHash: HexBytes
    transactionPosition: int
    _sender: Address = field(name="from")
    _to: Address
    _address: Raw = field(name="address", default=UNSET)
    _value: Raw = field(name="value", default=UNSET)
    _gas: Raw = field(name="gas", default=UNSET)
    _action: Raw = field(name="action", default=UNSET)
    _result: Raw = field(name="result", default=UNSET)

    @property
    def block(self) -> uint:
        return self.blockNumber

    @cached_property
    def sender(self) -> Address:
        return json.decode(self._sender, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def to(self) -> Address:
        return json.decode(self._to, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def address(self) -> Address:
        return json.decode(self._address, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def value(self) -> uint:
        return json.decode(self._value, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def gas(self) -> uint:
        return json.decode(self._gas, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def action(self) -> Action:
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)

    @cached_property
    def result(self) -> str:
        return json.decode(self._result, type=str, dec_hook=_decode_hook)
