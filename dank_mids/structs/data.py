
import logging
from typing import Type, Union

from enum import IntEnum
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
    failure = 0
    success = 1

def _enum_decode_hook(cls: Type[IntEnum], obj: Union[str, int]) -> IntEnum:
    return _decode_enum(cls, obj)

def _decode_enum(cls: Type[IntEnum], obj: Union[str, int]) -> "IntEnum":
    logger.info('decoding %s obj %s', cls.__name__, obj)
    try:
        return cls(uint._decode(obj))
    except Exception:
        return getattr(cls, obj)

def _decode_hook(typ: Type, obj: str):
    if typ is HexBytes:
        return HexBytes(obj)
    elif typ is Address:
        return checksum(obj)
    elif typ is uint:
        return uint._decode(obj)
    raise NotImplementedError(typ, obj, type(obj))

_decode_hexbytes = lambda _, obj: HexBytes(obj)
