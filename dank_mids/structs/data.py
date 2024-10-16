
import logging
from typing import Type, Union

from enum import Enum, EnumMeta
from hexbytes import HexBytes

from cachetools.func import ttl_cache
from eth_utils import to_checksum_address


logger = logging.getLogger(__name__)

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
    """
    NOTE: Storing encoded data as string is cheaper than ints when integer value is sufficiently high:
    
    string: 0x1  integer: 1
    string: 0x10  integer: 16
    string: 0x100  integer: 256
    string: 0x1000  integer: 4096
    string: 0x10000  integer: 65536
    string: 0x100000  integer: 1048576
    string: 0x1000000  integer: 16777216
    string: 0x10000000  integer: 268435456
    string: 0x100000000  integer: 4294967296
    string: 0x1000000000  integer: 68719476736
    string: 0x10000000000  integer: 1099511627776
"""
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


class StringToIntEnumMeta(EnumMeta):
    def __call__(cls, value: Union[str, int], *args, **kw):
        return super().__call__(cls._member_map_.get(value, value), *args, **kw)  # type: ignore [arg-type]
    
class HexStringToIntEnumMeta(EnumMeta):
    def __call__(cls, value: str, *args, **kw):
        return super().__call__(int(value, 16), *args, **kw)
    
class Status(Enum, metaclass=HexStringToIntEnumMeta):
    failure = 0
    success = 1

enum_decode_hook = lambda cls, data: cls(data)


def _decode_hook(typ: Type, obj: str):
    if typ is HexBytes:
        return HexBytes(obj)
    elif typ is Address:
        return checksum(obj)
    elif typ is uint:
        return uint._decode(obj)
    elif issubclass(typ, Enum):
        return typ(obj)
    raise NotImplementedError(typ, obj, type(obj))

_decode_hexbytes = lambda _, obj: HexBytes(obj)
