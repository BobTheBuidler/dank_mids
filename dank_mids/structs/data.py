
from typing import Type

from hexbytes import HexBytes

from cachetools.func import ttl_cache
from eth_utils import to_checksum_address


class Address(str):
    def __new__(cls, address: str):
        return super().__new__(cls, to_checksum_address(address))

@ttl_cache(ttl=600)
def checksum(address: str) -> Address:
    return Address(address)

class uint(int):
    @classmethod
    def _decode_hook(cls, typ: Type["uint"], obj: str):
        return cls(obj, 16)

def _decode_hook(typ: Type, obj: str):
    if typ is HexBytes:
        return HexBytes(obj)
    elif typ is Address:
        return checksum(obj)
    elif typ is uint:
        return uint(obj, 16)
    raise TypeError(typ)