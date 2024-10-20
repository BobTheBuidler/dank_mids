
from enum import Enum

from hexbytes import HexBytes
from msgspec import field

from dank_mids.structs.data import Address, StringToIntEnumMeta, Wei
from dank_mids.structs.dict import LazyDictStruct

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

    input: HexBytes
    """The input data of the action (transaction)."""

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

__all__ = ["Call", "Create", "Reward", "Suicide"]