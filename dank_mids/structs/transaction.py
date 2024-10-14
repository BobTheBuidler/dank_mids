
from functools import cached_property
from typing import List, Optional, Union

import msgspec
from hexbytes import HexBytes

from dank_mids.structs.data import Address, uint, _decode_hook
from dank_mids.structs.dict import LazyDictStruct

class AccessListEntry(LazyDictStruct, frozen=True):  # type: ignore [call-arg]
    _address: msgspec.Raw = msgspec.field(name="address")
    _storageKeys: msgspec.Raw = msgspec.field(name="storageKeys")
    @cached_property
    def address(self) -> Address:
        return msgspec.json.decode(self._address, type=Address, dec_hook=_decode_hook)
    @cached_property
    def storageKeys(self) -> List[HexBytes]:
        return msgspec.json.decode(self._storageKeys, type=List[HexBytes], dec_hook=_decode_hook)

class _TransactionBase(LazyDictStruct, frozen=True):  # type: ignore [call-arg]
    # `type` field is omitted since it's used in the tagged union
    input: HexBytes
    hash: HexBytes
    _to: msgspec.Raw = msgspec.field(name="to")  # null for contract deployments
    _gas: msgspec.Raw = msgspec.field(name="gas")
    _value: msgspec.Raw = msgspec.field(name="value")
    _nonce: msgspec.Raw = msgspec.field(name="nonce")
    _chainId: msgspec.Raw = msgspec.field(name="chainId")  # null for v in {27, 28}, otherwise derived from eip-155
    # details
    _sender: msgspec.Raw = msgspec.field(name="from")
    _blockHash: msgspec.Raw = msgspec.field(name="blockHash")
    _blockNumber: msgspec.Raw = msgspec.field(name="blockNumber")
    _transactionIndex: msgspec.Raw = msgspec.field(name="transactionIndex")
    
    # signature
    _v: msgspec.Raw = msgspec.field(name="v")
    _r: msgspec.Raw = msgspec.field(name="r")
    _s: msgspec.Raw = msgspec.field(name="s")

    @cached_property
    def blockHash(self) -> HexBytes:
        return msgspec.json.decode(self._blockHash, type=HexBytes, dec_hook=_decode_hook)

    @cached_property
    def to(self) -> Optional[Address]:
        # null for contract deployments
        return msgspec.json.decode(self._to, type=Optional[Address], dec_hook=_decode_hook)

    @cached_property
    def chainId(self) -> Optional[uint]:
        return msgspec.json.decode(self._chainId, type=Optional[uint], dec_hook=_decode_hook)

    @cached_property
    def nonce(self) -> uint:
        return msgspec.json.decode(self._nonce, type=uint, dec_hook=_decode_hook)

    @cached_property
    def gas(self) -> uint:
        return msgspec.json.decode(self._gas, type=uint, dec_hook=_decode_hook)

    @cached_property
    def value(self) -> uint:
        return msgspec.json.decode(self._value, type=uint, dec_hook=_decode_hook)

    @cached_property
    def blockNumber(self) -> uint:
        return msgspec.json.decode(self._blockNumber, type=uint, dec_hook=_decode_hook)

    @cached_property
    def transactionIndex(self) -> uint:
        return msgspec.json.decode(self._transactionIndex, type=uint, dec_hook=_decode_hook)

    @cached_property
    def sender(self) -> Address:
        return msgspec.json.decode(self._sender, type=Address, dec_hook=_decode_hook)

    @cached_property
    def v(self) -> uint:
        return msgspec.json.decode(self._v, type=uint, dec_hook=_decode_hook)

    @cached_property
    def r(self) -> HexBytes:
        return msgspec.json.decode(self._r, type=HexBytes, dec_hook=_decode_hook)

    @cached_property
    def s(self) -> HexBytes:
        return msgspec.json.decode(self._s, type=HexBytes, dec_hook=_decode_hook)



class TransactionLegacy(_TransactionBase, tag="0x0"):  # type: ignore [call-arg]
    _gasPrice: msgspec.Raw = msgspec.field(name="gasPrice")
    @cached_property
    def gasPrice(self) -> uint:
        return msgspec.json.decode(self._gasPrice, type=uint, dec_hook=_decode_hook)


class Transaction2930(_TransactionBase, tag="0x1"):  # type: ignore [call-arg]
    _gasPrice: msgspec.Raw = msgspec.field(name="gasPrice")
    _accessList: msgspec.Raw = msgspec.field(name="accessList", default=msgspec.UNSET)
    @cached_property
    def gasPrice(self) -> uint:
        return msgspec.json.decode(self._gasPrice, type=uint, dec_hook=_decode_hook)
    @cached_property
    def accessList(self) -> Optional[List[AccessListEntry]]:
        return msgspec.json.decode(self._accessList, type=Optional[List[AccessListEntry]])


class Transaction1559(_TransactionBase, tag="0x2"):  # type: ignore [call-arg]
    _maxFeePerGas: msgspec.Raw = msgspec.field(name="maxFeePerGas")
    _maxPriorityFeePerGas: msgspec.Raw = msgspec.field(name="maxPriorityFeePerGas")
    _accessList: msgspec.Raw = msgspec.field(name="accessList", default=msgspec.UNSET)
    @cached_property
    def maxFeePerGas(self) -> uint:
        return msgspec.json.decode(self._maxFeePerGas, type=uint, dec_hook=_decode_hook)
    @cached_property
    def maxPriorityFeePerGas(self) -> uint:
        return msgspec.json.decode(self._maxPriorityFeePerGas, type=uint, dec_hook=_decode_hook)
    @cached_property
    def accessList(self) -> Optional[List[AccessListEntry]]:
        return msgspec.json.decode(self._accessList, type=Optional[List[AccessListEntry]])


Transaction = Union[TransactionLegacy, Transaction2930, Transaction1559]