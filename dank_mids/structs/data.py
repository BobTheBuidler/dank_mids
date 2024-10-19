
import decimal
import logging
from datetime import datetime, timezone
from functools import cached_property
from typing import TYPE_CHECKING, List, Tuple, Type, TypeVar, Union

from a_sync import a_sync
from cachetools.func import ttl_cache
from enum import Enum, EnumMeta
from eth_utils import to_checksum_address
from hexbytes import HexBytes
from msgspec import json
from typing_extensions import Self

if TYPE_CHECKING:
    from dank_mids.structs.log import Log
    from dank_mids.structs.receipt import TransactionReceipt
    from dank_mids.types import T, DecodeHook


logger = logging.getLogger(__name__)

_T = TypeVar("_T")

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
    def fromhex(cls, hexstr: str) -> Self:
        return cls(hexstr, 16)
    
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
    
    def __repr__(self) -> str:
        return f"{type(self).__name__}({int.__repr__(self)})"
    
    # we dont want str to use our new repr
    __str__ = int.__repr__
    
    @classmethod
    def _decode_hook(cls, typ: Type["uint"], obj: str):
        return typ(obj, 16)
    @classmethod
    def _decode(cls, obj) -> "uint":
        try:
            return cls.fromhex(obj)
        except TypeError as e:
            if "int() can't convert non-string with explicit base" in str(e):
                return cls(obj)
            raise
    @classmethod
    def fromhex(cls, hexstr: str):
        return cls(hexstr, 16)


class Wei(uint):
    @cached_property
    def scaled(self) -> "Decimal":
        return Decimal(self) / 10 ** 18


class UnixTimestamp(uint):
    @cached_property
    def datetime(self) -> datetime:
        return datetime.fromtimestamp(self, tz=timezone.utc)


class BlockNumber(uint):
    ...

class Nonce(uint):
    ...

class IntId(uint):
    def __add__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __sub__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __mul__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __truediv__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __floordiv__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __pow__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __radd__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __rsub__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __rmul__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __rtruediv__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __rfloordiv__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")
    def __rpow__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")


class ChainId(IntId):
    ...

class TransactionIndex(IntId):
    ...

class LogIndex(IntId):
    ...


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


def _decode_hook(typ: Type, obj: object):
    if issubclass(typ, (HexBytes, Enum, Decimal)):
        return typ(obj)  # type: ignore [arg-type]
    elif typ is Address:
        return checksum(obj)
    elif issubclass(typ, uint):
        return (typ.fromhex if isinstance(obj, str) and obj.startswith("0x") else typ)(obj)
    elif getattr(typ, "__origin__", None) is HashableList:
        assert len(typ.__args__) == 1, typ.__args__
        obj_cls = typ.__args__[0]
        return HashableList(_decode_hook(obj_cls, o) for o in obj)
    raise NotImplementedError(typ, obj, type(obj))


ONE_EMPTY_BYTE = bytes(HexBytes("0x00"))

class HexBytes32(HexBytes):
    def __new__(cls, v):
        # if it has 0x prefix it came from the chain or a user and we should validate the size
        # when it doesnt have the prefix it came out of one of my dbs in a downstream lib and we can trust the size.
        if isinstance(v, str) and v.startswith("0x"):
            cls._check_hexstr(v)
        input_bytes = HexBytes(v)
        return super().__new__(cls, cls._get_missing_bytes(input_bytes) + input_bytes)

    def __repr__(self) -> str:
        return f"{type(self).__name__}({self.hex()})"
    
    # TODO: keep the instance small and just task on the length for operations as needed
    #def __len__(self) -> Literal[32]:
    #    return 32

    @staticmethod
    def _get_missing_bytes(input_bytes: HexBytes) -> bytes:
        missing_length = 32 - len(input_bytes)
        return missing_length * ONE_EMPTY_BYTE

    def __hash__(self) -> int:
        return hash(self.hex())
    
    def strip(self) -> str:
        """Returns self.hex() with leading zeroes removed."""
        # we trim all leading zeroes since we know how many we need to put back later
        return hex(int(self.hex(), 16))[2:]
    
    @staticmethod
    def _check_hexstr(hexstr: str):
        l = len(hexstr)
        if l > 66:
            raise ValueError('too high', len(hexstr), hexstr)
        elif l < 66:
            raise ValueError('too smol', len(hexstr), hexstr)

class TransactionHash(HexBytes32):
    @a_sync("async")
    async def get_receipt(self, decode_to: Type["T"], decode_hook: "DecodeHook" = _decode_hook) -> "TransactionReceipt":
        import dank_mids
        return await dank_mids.eth.get_transaction_receipt(self, decode_to=decode_to, decode_hook=decode_hook)
    @a_sync  # TODO; compare how these type check, they both function the same
    async def get_logs(self) -> Tuple["Log", ...]:
        import dank_mids
        from dank_mids.structs.log import Log
        receipt = await dank_mids.eth._get_transaction_receipt_raw(self)
        return json.decode(receipt, type=Tuple[Log, ...], dec_hook=_decode_hook)

class BlockHash(HexBytes32):
    ...

def hexbytes_storage_encode_hook(obj):
    return hex(int(obj.hex(), 16))[2:]

decode_hexbytes = lambda hexbytes_type, obj: hexbytes_type(obj)


class Decimal(decimal.Decimal):
    def jsonify(self) -> Union[str, int]:
        string = str(self)
        integer = int(self)
        scientific_notation = '%E' % self
        string_len = len(string)
        scientific_notation_len = len(scientific_notation)
        if integer == self:
            return integer if len(str(integer)) <= scientific_notation_len + 2 else scientific_notation
        while string[-1] == "0":
            string = string[:-1]
        if Decimal(scientific_notation) == self and scientific_notation_len < string_len:
            raise Exception('will this ever actually run?', self, scientific_notation)
            return scientific_notation
        else:
            string

    def __add__(self, other):
        return type(self)(super().__add__(other))
    def __radd__(self, other):
        return type(self)(super().__radd__(other))
    def __sub__(self, other):
        return type(self)(super().__sub__(other))
    def __rsub__(self, other):
        return type(self)(super().__rsub__(other))
    def __mul__(self, other):
        return type(self)(super().__mul__(other))
    def __rmul__(self, other):
        return type(self)(super().__rmul__(other))
    def __truediv__(self, other):
        return type(self)(super().__truediv__(other))
    def __rtruediv__(self, other):
        return type(self)(super().__rtruediv__(other))
    def __floordiv__(self, other):
        return type(self)(super().__floordiv__(other))
    def __rfloordiv__(self, other):
        return type(self)(super().__rfloordiv__(other))

class HashableList(List[_T]):
    def __hash__(self):
        return hash(tuple(self))
    def __setitem__(self, *_):
        raise RuntimeError("You cannot modify this hashable list")
