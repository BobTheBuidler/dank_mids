
from typing import Type

from enum import IntEnum
from hexbytes import HexBytes
from msgspec import ValidationError

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
        except ValidationError as e:
            if "int cant convert non-string with explicit base" in str(e):
                return cls(obj)
            raise

class Status(IntEnum):
    Revert = 0
    Success = 1
    @classmethod
    def _decode_hook(cls, _, obj) -> "Status":
        return cls._decode(obj)
    @classmethod
    def _decode(cls, obj) -> "Status":
        try:
            return cls(int(obj, 16))
        except TypeError as e:
            if str(e) == "int() can't convert non-string with explicit base":
                return Status(int(obj))
            raise

def _decode_hook(typ: Type, obj: str):
    if typ is HexBytes:
        return HexBytes(obj)
    elif typ is Address:
        return checksum(obj)
    elif typ is uint:
        return uint._decode(obj)
    elif typ is Status:
        return Status._decode(obj)
    raise TypeError(typ)

_decode_hexbytes = lambda _, obj: HexBytes(obj)
