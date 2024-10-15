
from functools import cached_property
from typing import List, Optional

from hexbytes import HexBytes
from msgspec import Raw, field, json

from dank_mids.structs.data import Address, uint, _decode_hexbytes
from dank_mids.structs.dict import LazyDictStruct


class TinyLog(LazyDictStruct, frozen=True, kw_only=True):  # type: ignore [call-arg]

    _topics: Raw = field(name="topics")
    """
    An array of 0 to 4 32-byte topics. 
    The first topicis the event signature and the others are indexed filters on the event return data.
    """

    @cached_property
    def topics(self) -> Optional[List[HexBytes]]:
        """
        An array of 0 to 4 32-byte topics. 
        The first topicis the event signature and the others are indexed filters on the event return data.
        """
        return json.decode(self._topics, type=Optional[List[HexBytes]], dec_hook=_decode_hexbytes)

class SmallLog(TinyLog, frozen=True, kw_only=True):  # type: ignore [call-arg]

    _address: Raw = field(name="address")
    """The address of the contract that generated the log."""

    _data: Raw = field(name="data")
    """Array of 32-bytes non-indexed return data of the log."""

    @cached_property
    def address(self) -> Optional[Address]:
        """The address of the contract that generated the log."""
        return json.decode(self._address, type=Optional[Address], dec_hook=Address._decode_hook)
    
    @cached_property
    def data(self) -> Optional[HexBytes]:
        """Array of 32-bytes non-indexed return data of the log."""
        return json.decode(self._data, type=Optional[HexBytes], dec_hook=_decode_hexbytes)


class Log(SmallLog, frozen=True, kw_only=True):  # type: ignore [call-arg]

    removed: Optional[bool]
    """`True` when the log was removed, due to a chain reorganization. `False` if it's a valid log."""

    _blockNumber: Raw = field(name="blockNumber")
    """The block where the transaction was included where the log originated from. `None` for pending transactions."""

    _transactionHash: Raw = field(name="transactionHash")
    """The hash of the transaction that generated the log. `None` for pending transactions."""

    _logIndex: Raw = field(name="logIndex")
    """Index position of the log in the transaction. `None` for pending transactions."""

    @cached_property
    def blockNumber(self) -> Optional[uint]:
        """The block where the transaction was included where the log originated from. `None` for pending transactions."""
        return json.decode(self._blockNumber, type=Optional[uint], dec_hook=uint._decode_hook)
    
    @cached_property
    def transactionHash(self) -> HexBytes:
        """The hash of the transaction that generated the log. `None` for pending transactions."""
        return json.decode(self._transactionHash, type=HexBytes, dec_hook=_decode_hexbytes)
    
    _transactionIndex: Raw = field(name="transactionIndex")
    """The index of the transaction in the block, where the log originated from."""

    @cached_property
    def transactionIndex(self) -> Optional[uint]:
        """The index of the transaction in the block, where the log originated from."""
        return json.decode(self._transactionIndex, type=Optional[uint], dec_hook=uint._decode_hook)
    
    @cached_property
    def logIndex(self) -> Optional[uint]:
        """Index position of the log in the transaction. `None` for pending transactions."""
        return json.decode(self._logIndex, type=Optional[uint], dec_hook=uint._decode_hook)
    
    @property
    def block(self) -> Optional[uint]:
        """A shorthand getter for 'blockNumber'"""
        return self.blockNumber


class FullLog(Log, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]

    _blockHash: Raw = field(name="blockHash")
    """The hash of the block where the transaction was included where the log originated from. `None` for pending transactions."""

    @cached_property
    def blockHash(self) -> Optional[HexBytes]:
        """The hash of the block where the transaction was included where the log originated from. `None` for pending transactions."""
        return json.decode(self._blockHash, type=Optional[HexBytes], dec_hook=_decode_hexbytes)
