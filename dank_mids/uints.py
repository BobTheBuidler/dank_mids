
import sys

from dank_mids.structs.data import uint


class _UintData(uint):
    bytes: int
    bits: int
    min_value = 0
    max_value: int
    def __new__(cls, v):
        new = super().__new__(cls, v)
        if new < cls.min_value:
            raise ValueError(f"{v} is smaller than {cls.__name__} max value {cls.max_value}")
        if new > cls.max_value:
            raise ValueError(f"{v} is larger than {cls.__name__} max value {cls.max_value}")
        return new

class uint8(_UintData):
    bytes = 1
    bits = bytes * 8
    max_value = 2 ** bits - 1

class uint64(_UintData):
    bytes = 8
    bits = bytes * 8
    max_value = 2 ** bits - 1

class uint128(_UintData):
    bytes = 16
    bits = bytes * 8
    max_value = 2 ** bits - 1

class uint256(_UintData):
    bytes = 32
    bits = bytes * 8
    max_value = 2 ** bits - 1


# dynamically define classes for remaining uint types
for i in range(1, 32):
    if i in [1, 8, 16, 32]:
        # I already defined these above
        continue

    bits = i*8
    cls_name = f"uint{bits}"
    new_cls = type(cls_name, (_UintData, ), {"bits": bits, "bytes": i, "max_value": 2 ** bits - 1})
    setattr(sys.modules[__name__], cls_name, new_cls)

__all__ = [f"uint{bytes*8}" for bytes in range(1, 32)]
