
from typing import Type, Union

from enum import IntEnum
from hexbytes import HexBytes

from cachetools.func import ttl_cache
from eth_utils import to_checksum_address


class Address(str):
    def __new__(cls, address: str):
        return super().__new__(cls, to_checksum_address(address))
    @classmethod
    def _decode_hook(cls, typ: Type["Address"], obj: str):
        return checksum(obj)

@ttl_cache(ttl=600)
def checksum(address: str) -> Address:
    return Address(address)

class uint(int):
    @classmethod
    def _decode_hook(cls, typ: Type["uint"], obj: str):
        return cls(obj, 16)
    @classmethod
    def _decode(cls, obj) -> "uint":
        try:
            return cls(obj, 16)
        except TypeError as e:
            if "int() can't convert non-string with explicit base" in str(e):
                return cls(obj)
            raise

class Status(IntEnum):
    Revert = 0
    Success = 1

def _enum_decode_hook(cls: Type[IntEnum], obj: Union[str, int]) -> IntEnum:
    return _decode_enum(cls, obj)

def _decode_enum(cls: Type[IntEnum], obj: Union[str, int]) -> "IntEnum":
    return cls(uint._decode(obj))

def _decode_hook(typ: Type, obj: str):
    if typ is HexBytes:
        return HexBytes(obj)
    elif typ is Address:
        return checksum(obj)
    elif typ is uint:
        return uint._decode(obj)
    elif issubclass(typ, IntEnum):
        return _decode_enum(typ, obj)
    raise TypeError(typ)

_decode_hexbytes = lambda _, obj: HexBytes(obj)
