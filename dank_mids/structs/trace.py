
from enum import Enum
from functools import cached_property
from typing import ClassVar, List, Literal, Optional, Union

from hexbytes import HexBytes
from msgspec import UNSET, Raw, json, field
from msgspec.structs import force_setattr

from dank_mids.structs.data import Address, BlockHash, BlockNumber, StringToIntEnumMeta, TransactionHash, Wei, uint, _decode_hook
from dank_mids.structs.dict import DictStruct, LazyDictStruct

    
class CallType(Enum, metaclass=StringToIntEnumMeta):
    call = 0
    delegatecall = 1
    staticcall = 2

class RewardType(Enum, metaclass=StringToIntEnumMeta):
    block = 0
    uncle = 1

class _ActionBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The action performed, parity style.
    """

    sender: Address = field(name="from")
    """The sender address."""

    input: HexBytes
    """The input data of the action (transaction)."""

    value: Wei
    """The amount of ETH sent in this action (transaction)."""

    gas: Wei
    """The gas provided."""

class Call(_ActionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    """
    Action type for contract calls.
    """

    callType: CallType
    """The type of the call."""

    to: Address
    """The receiver address."""

class Create(_ActionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    """
    Action type for contract creations.
    """

    init: HexBytes
    """The init code for the deployed contract."""

class Reward(_ActionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    """
    Action type for rewards.
    """

    author: Address
    """The author of this transaction."""

    rewardType: RewardType
    """The type of the reward, for reward transactions."""

class Suicide(_ActionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    """
    Action type for contract suicides.
    """


class _ResultBase(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The result object, parity style.
    """

    gasUsed: Wei
    """The amount of gas used by this transaction."""

class CallResult(_ResultBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    output: HexBytes
    """The output of this transaction."""

class CreateResult(_ResultBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    address: Address
    """The address of the deployed contract."""

    code: HexBytes
    """The bytecode of the deployed contract."""


class _FilterTraceBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    
    blockNumber: BlockNumber
    """The number of the block where this action happened."""

    blockHash: BlockHash
    """The hash of the block where this action happened."""

    transactionHash: TransactionHash
    """The hash of the transaction being traced."""

    transactionPosition: int
    """The position of the transaction in the block."""

    traceAddress: List[uint]
    """The trace addresses (array) where the call executed (every contract where code was executed)."""

    subtraces: uint
    """The number of traces of internal transactions that happened during this transaction."""

    error: str = UNSET

    @property
    def block(self) -> BlockNumber:
        """A shorthand getter for 'blockNumber'."""
        return self.blockNumber
    
    def __post_init__(self):
        # make sure the obj is hashable
        force_setattr(self, "traceAddress", tuple(self.traceAddress))

class CallTrace(_FilterTraceBase, tag="call", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    type: ClassVar[Literal["call"]] = "call"

    _action: Raw = field(name="action")
    """The call action, parity style."""

    @cached_property
    def action(self) -> Call:
        """The call action, parity style."""
        return json.decode(self._action, type=Call, dec_hook=_decode_hook)
    
    result: Optional[CallResult]
    """
    The result object, parity style.
    
    None if the call errored. Error details will be included in the error field.
    """

    error: str = UNSET
    """The error message, if an error occurred."""

class CreateTrace(_FilterTraceBase, tag="create", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    type: ClassVar[Literal["create"]] = "create"

    _action: Raw = field(name="action")
    """The create action, parity style."""

    @cached_property
    def action(self) -> Create:
        """The create action, parity style."""
        return json.decode(self._action, type=Create, dec_hook=_decode_hook)
    
    result: CreateResult
    """The result object, parity style."""

class RewardTrace(_FilterTraceBase, tag="reward", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):

    type: ClassVar[Literal["reward"]] = "reward"

    _action: Raw = field(name="action")
    """The reward action, parity style."""

    @cached_property
    def action(self) -> Reward:
        """The reward action, parity style."""
        return json.decode(self._action, type=Reward, dec_hook=_decode_hook)

class SuicideTrace(_FilterTraceBase, tag="suicide", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):

    type: ClassVar[Literal["suicide"]] = "suicide"

    action: Suicide
    """The suicide action, parity style."""
    
    result: Literal[None]

Result = Union[CallResult, CreateResult, Literal[None]]

FilterTrace = Union[CallTrace, CreateTrace, RewardTrace, SuicideTrace]
