
from functools import cached_property
from typing import ClassVar, List, Literal, Optional, Union

from msgspec import UNSET, Raw, json, field
from msgspec.structs import force_setattr

from dank_mids.structs.data import BlockHash, BlockNumber, TransactionHash, uint, _decode_hook
from dank_mids.structs.dict import LazyDictStruct
from dank_mids.structs.trace.action import *
from dank_mids.structs.trace.result import *


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

FilterTrace = Union[CallTrace, CreateTrace, RewardTrace, SuicideTrace]

__all__ = ["CallTrace", "CreateTrace", "RewardTrace", "SuicideTrace", "FilterTrace"]