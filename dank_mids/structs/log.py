
from typing import Optional, Tuple

from hexbytes import HexBytes

from dank_mids import uints
from dank_mids.structs import data
from dank_mids.structs.dict import LazyDictStruct


_ADDRESS_TOPIC_PREFIX = HexBytes("0") * 12

class Data(HexBytes):
    @property
    def as_uint(self) -> data.uint:
        return data.uint(self.hex(), 16)
    @property
    def as_address(self) -> data.Address:
        if self[:12] != _ADDRESS_TOPIC_PREFIX:
            raise ValueError(f"This {type(self).__name__} does not represent an address", self)
        return data.checksum(self[-20:].hex())
    @property
    def as_uint8(self) -> uints.uint8:
        return uints.uint8(self)
    @property
    def as_uint64(self) -> uints.uint64:
        return uints.uint64(self)
    @property
    def as_uint128(self) -> uints.uint128:
        return uints.uint128(self)
    @property
    def as_uint256(self) -> uints.uint256:
        return uints.uint256(self)
    
class Topic(data.HexBytes32, Data):
    ...

"""
Dynamically define properties for all uint types.

Example:
```
Topic(bytes_data).as_uint40
Topic(bytes_data).as_uint48
Topic(bytes_data).as_uint56
```
"""
for i in range(2, 31):
    # these commonly used ones are already defined above for better use with ides
    if i in [1, 8, 16, 32]:
        continue
    bits = i * 8
    uint_cls_name = f"uint{bits}"
    uint_cls = getattr(uints, uint_cls_name)
    setattr(Topic, f"as_{uint_cls_name}", property(uint_cls))



    
class TinyLog(LazyDictStruct, frozen=True, kw_only=True):  # type: ignore [call-arg]

    topics: Tuple[Topic, ...]
    """
    An array of 0 to 4 32-byte topics. 
    The first topic is the event signature and the others are indexed filters on the event return data.
    """
    @property
    def topic0(self) -> Topic:
        return self.topics[0]
    @property
    def topic1(self) -> Topic:
        try:
            return self.topics[1]
        except IndexError:
            raise AttributeError(f"'this {type(self).__name__} object '{self}' has no attribute 'topic1'") from None
    @property
    def topic2(self) -> Topic:
        try:
            return self.topics[2]
        except IndexError:
            raise AttributeError(f"this {type(self).__name__} object '{self}' has no attribute 'topic2'") from None
    @property
    def topic3(self) -> Topic:
        try:
            return self.topics[3]
        except IndexError:
            raise AttributeError(f"this {type(self).__name__} object '{self}' has no attribute 'topic3'") from None


class SmallLog(TinyLog, frozen=True, kw_only=True):  # type: ignore [call-arg]

    address: Optional[data.Address]
    """The address of the contract that generated the log."""

    data: Optional[Data]
    """Array of 32-bytes non-indexed return data of the log."""


class Log(SmallLog, frozen=True, kw_only=True):  # type: ignore [call-arg]

    removed: Optional[bool]
    """`True` when the log was removed, due to a chain reorganization. `False` if it's a valid log."""

    blockNumber: Optional[data.BlockNumber]
    """The block where the transaction was included where the log originated from. `None` for pending transactions."""

    transactionHash: data.TransactionHash
    """The hash of the transaction that generated the log. `None` for pending transactions."""

    logIndex: data.LogIndex
    """Index position of the log in the transaction. `None` for pending transactions."""
    
    transactionIndex: data.TransactionIndex
    """The index of the transaction in the block, where the log originated from."""
    
    @property
    def block(self) -> Optional[data.BlockNumber]:
        """A shorthand getter for 'blockNumber'"""
        return self.blockNumber


class FullLog(Log, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]

    blockHash: Optional[data.BlockHash]
    """The hash of the block where the transaction was included where the log originated from. `None` for pending transactions."""
