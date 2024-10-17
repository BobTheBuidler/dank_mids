
from typing import List, Optional

from hexbytes import HexBytes

from dank_mids.structs.data import Address, HexBytes32, uint, checksum
from dank_mids.structs.dict import LazyDictStruct



class Topic(HexBytes32):
    @property
    def as_uint(self) -> uint:
        return uint(self.hex(), 16)
    @property
    def as_address(self) -> Address:
        if self[:12] != HexBytes("0"*24)
        return checksum(self[-20:].hex())
    

class TinyLog(LazyDictStruct, frozen=True, kw_only=True):  # type: ignore [call-arg]

    topics: List[Topic]
    """
    An array of 0 to 4 32-byte topics. 
    The first topicis the event signature and the others are indexed filters on the event return data.
    """

class SmallLog(TinyLog, frozen=True, kw_only=True):  # type: ignore [call-arg]

    address: Optional[Address]
    """The address of the contract that generated the log."""

    data: Optional[HexBytes]
    """Array of 32-bytes non-indexed return data of the log."""


class Log(SmallLog, frozen=True, kw_only=True):  # type: ignore [call-arg]

    removed: Optional[bool]
    """`True` when the log was removed, due to a chain reorganization. `False` if it's a valid log."""

    blockNumber: Optional[uint]
    """The block where the transaction was included where the log originated from. `None` for pending transactions."""

    transactionHash: HexBytes32
    """The hash of the transaction that generated the log. `None` for pending transactions."""

    logIndex: uint
    """Index position of the log in the transaction. `None` for pending transactions."""
    
    transactionIndex: uint
    """The index of the transaction in the block, where the log originated from."""
    
    @property
    def block(self) -> Optional[uint]:
        """A shorthand getter for 'blockNumber'"""
        return self.blockNumber


class FullLog(Log, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]

    blockHash: Optional[HexBytes32]
    """The hash of the block where the transaction was included where the log originated from. `None` for pending transactions."""
