
from decimal import Decimal
from enum import EnumMeta, Enum
from functools import cached_property
from typing import List, Optional

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs.data import Address, uint, _decode_hook
from dank_mids.structs.dict import DictStruct, LazyDictStruct


class StringToIntEnumMeta(EnumMeta):
    def __call__(cls, value, *args, **kw):
        return super().__call__(cls._member_map_.get(value, value), *args, **kw)
    
class CallType(Enum, metaclass=StringToIntEnumMeta):
    call = 0
    delegatecall = 1

class RewardType(Enum, metaclass=StringToIntEnumMeta):
    block = 0
    uncle = 1

class Action(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The action performed, parity style.
    """

    callType: CallType
    """The type of the call."""

    _sender: Raw = field(name="from")
    """The sender address."""

    _to: Raw
    """The receiver address."""

    _author: Raw = field(name="author", default=UNSET)
    """The author of this transaction, for some transaction types."""

    input: HexBytes
    """The input data of the action (transaction)."""

    gas: uint
    """The gas provided."""

    rewardType: Optional[RewardType] = None
    """The type of the reward, for reward transactions."""

    _value: Raw = field(name="value", default=UNSET)
    """The amount of ETH sent in this action (transaction)."""

    @cached_property
    def sender(self) -> Address:
        """The sender address."""
        return json.decode(self._sender, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def to(self) -> Address:
        """The receiver address."""
        return json.decode(self._to, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def author(self) -> Address:
        """The author of this transaction, for some transaction types."""
        return json.decode(self._author, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def value(self) -> Decimal:
        """The amount of ETH sent in this action (transaction)."""
        return Decimal(json.decode(self._value, type=uint, dec_hook=uint._decode_hook)) / 10 ** 18


class Result(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The result object, parity style.
    """

    output: HexBytes
    """The output of this transaction."""

    gasUsed: uint
    """The amount of gas used by this transaction."""


class Type(Enum, metaclass=StringToIntEnumMeta):
    call = 0
    create = 1
    reward = 2

class FilterTrace(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    
    blockNumber: uint
    """The number of the block where this action happened."""

    blockHash: HexBytes
    """The hash of the block where this action happened."""

    transactionHash: HexBytes
    """The hash of the transaction being traced."""

    transactionPosition: int
    """The position of the transaction in the block."""

    traceAddress: List[uint]
    """The trace addresses (array) where the call executed (every contract where code was executed)."""

    type: Type
    """The type of the transaction."""

    _subtraces: Raw = field(name="subtraces")
    """The number of traces of internal transactions that happened during this transaction."""

    _action: Raw = field(name="action", default=UNSET)
    """The action performed, parity style."""

    _result: Raw = field(name="result", default=UNSET)
    """The result object, parity style."""

    @property
    def block(self) -> uint:
        """A shorthand getter for 'blockNumber'."""
        return self.blockNumber

    @cached_property
    def subtraces(self) -> Address:
        """The number of traces of internal transactions that happened during this transaction."""
        return json.decode(self._subtraces, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def action(self) -> Action:
        """The action performed, parity style."""
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)

    @cached_property
    def result(self) -> Result:
        """The result object, parity style."""
        return json.decode(self._result, type=Result, dec_hook=_decode_hook)
