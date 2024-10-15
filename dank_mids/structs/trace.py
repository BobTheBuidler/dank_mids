
import msgspec
from hexbytes import HexBytes

from dank_mids.structs.data import Address, uint
from dank_mids.structs.dict import DictStruct, LazyDictStruct


class Action(DictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    rewardType: str

#class Result(DictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    

class Trace(LazyDictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    blockNumber: uint
    sender: Address = msgspec.field(name="from")
    to: Address
    transactionHash: HexBytes
    transactionPosition: int
    address: Address
    value: uint
    gas: uint
    action: Action = msgspec.UNSET
    #result: Result = msgspec.UNSET
    result: str = msgspec.UNSET
