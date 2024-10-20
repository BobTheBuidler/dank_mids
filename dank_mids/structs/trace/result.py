
from typing import Literal, Union

from hexbytes import HexBytes

from dank_mids.structs.dict import DictStruct
from dank_mids.structs.data import Address, Wei


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

Result = Union[CallResult, CreateResult, Literal[None]]

__all__ = ["CallResult", "CreateResult"]