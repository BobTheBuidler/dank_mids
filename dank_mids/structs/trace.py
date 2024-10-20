
from enum import Enum
from typing import List, Optional

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

class Action(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The action performed, parity style.
    """

    callType: CallType
    """The type of the call."""

    sender: Address = field(name="from")
    """The sender address."""

    to: Address = UNSET
    """The receiver address. If the action is a create type, this field will not be set."""

    author: Address = UNSET
    """The author of this transaction, for some transaction types."""

    input: HexBytes
    """The input data of the action (transaction)."""

    init: HexBytes = UNSET
    """The init code for the deployed contract, if the trace is a 'create' type."""
    # TODO: make separate struct defs for the diff trace types

    gas: Wei
    """The gas provided."""

    rewardType: Optional[RewardType] = None
    """The type of the reward, for reward transactions."""

    value: Wei = UNSET
    """The amount of ETH sent in this action (transaction)."""


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

class FilterTrace(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    
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

    action: Action
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
