
from functools import cached_property
from typing import List, Optional, Type

import msgspec
from hexbytes import HexBytes

from dank_mids.structs.data import Address, uint, _decode_hook
from dank_mids.structs.dict import LazyDictStruct


class TinyLog(LazyDictStruct, frozen=True):  # type: ignore [call-arg]
    _topics: msgspec.Raw = msgspec.field(name="topics")
    @cached_property
    def topics(self) -> Optional[List[HexBytes]]:
        return msgspec.json.decode(self._topics, type=Optional[List[HexBytes]], dec_hook=_decode_hook)

class SmallLog(TinyLog, frozen=True):  # type: ignore [call-arg]
    _address: msgspec.Raw = msgspec.field(name="address")
    _data: msgspec.Raw = msgspec.field(name="data")
    @cached_property
    def address(self) -> Optional[Address]:
        return msgspec.json.decode(self._address, type=Optional[Address], dec_hook=_decode_hook)
    @cached_property
    def data(self) -> Optional[HexBytes]:
        return msgspec.json.decode(self._data, type=Optional[HexBytes], dec_hook=_decode_hook)

class Log(SmallLog, frozen=True):  # type: ignore [call-arg]
    removed: Optional[bool]
    _blockNumber: msgspec.Raw = msgspec.field(name="blockNumber")
    _transactionHash: msgspec.Raw = msgspec.field(name="transactionHash")
    _logIndex: msgspec.Raw = msgspec.field(name="logIndex")
    @cached_property
    def blockNumber(self) -> Optional[uint]:
        return msgspec.json.decode(self._blockNumber, type=Optional[uint], dec_hook=_decode_hook)
    @cached_property
    def transactionHash(self) -> HexBytes:
        return msgspec.json.decode(self._transactionHash, type=HexBytes, dec_hook=_decode_hook)
    _transactionIndex: msgspec.Raw = msgspec.field(name="transactionIndex")
    @cached_property
    def transactionIndex(self) -> Optional[uint]:
        return msgspec.json.decode(self._transactionIndex, type=Optional[uint], dec_hook=_decode_hook)
    @cached_property
    def logIndex(self) -> Optional[uint]:
        return msgspec.json.decode(self._logIndex, type=Optional[uint], dec_hook=_decode_hook)
    @property
    def block(self) -> Optional[uint]:
        return self.blockNumber

class FullLog(Log, frozen=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    _blockHash: msgspec.Raw = msgspec.field(name="blockHash")
    @cached_property
    def blockHash(self) -> Optional[HexBytes]:
        return msgspec.json.decode(self._blockHash, type=Optional[HexBytes], dec_hook=_decode_hook)
