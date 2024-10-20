
from enum import Enum
from typing import ClassVar, List, Literal, Optional, Union

from hexbytes import HexBytes
from msgspec import UNSET, field
from msgspec.structs import force_setattr

from dank_mids.structs.data import Address, BlockHash, BlockNumber, StringToIntEnumMeta, TransactionHash, Wei, uint
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

    gas: Wei
    """The gas provided."""

class Call(_ActionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    
    callType: CallType
    """The type of the call."""

    to: Address
    """The receiver address."""

    value: Wei
    """The amount of ETH sent in this action (transaction)."""

class Create(_ActionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):

    init: HexBytes
    """The init code for the deployed contract."""

class Reward(_ActionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):

    author: Address
    """The author of this transaction."""

    rewardType: RewardType
    """The type of the reward, for reward transactions."""

class Suicide(_ActionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    ...

class Result(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The result object, parity style.
    """

    output: HexBytes
    """The output of this transaction."""

    gasUsed: Wei
    """The amount of gas used by this transaction."""


class Type(Enum, metaclass=StringToIntEnumMeta):
    """
    The type of internal operation (e.g., "call" for contract calls, "create" for contract creation,
    "suicide" for contract self-destruct).
    """
    call = 0
    create = 1
    reward = 2
    suicide = 3

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

    type: Type
    """The type of the transaction."""

    subtraces: uint
    """The number of traces of internal transactions that happened during this transaction."""

    action: _ActionBase
    """The action performed, parity style."""

    result: Optional[Result] = UNSET
    """The result object, parity style."""

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
    action: Call

class CreateTrace(_FilterTraceBase, tag="create", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    type: ClassVar[Literal["create"]] = "create"
    action: Create

class RewardTrace(_FilterTraceBase, tag="reward", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    type: ClassVar[Literal["reward"]] = "reward"
    action: Reward

class SuicideTrace(_FilterTraceBase, tag="suicide", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    type: ClassVar[Literal["suicide"]] = "suicide"
    action: Suicide

FilterTrace = Union[CallTrace, CreateTrace, RewardTrace, SuicideTrace]
