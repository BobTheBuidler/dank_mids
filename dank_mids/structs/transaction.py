
from decimal import Decimal
from functools import cached_property
from typing import Any, List, Optional, Union

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs.data import Address, uint, _decode_hexbytes
from dank_mids.structs.dict import LazyDictStruct


class AccessListEntry(LazyDictStruct, frozen=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """
    The :class:`~structs.AccessListEntry` class represents an entry in an Ethereum transaction access list.

    Access lists are used in EIP-2930 and EIP-1559 transactions to specify storage slots
    that the transaction plans to access, potentially reducing gas costs.

    Example:
        >>> entry = AccessListEntry(...)
        >>> access_list_entry.address
        '0x742d35Cc6634C0532925a3b844Bc454e4438f44e'
        >>> len(access_list_entry.storage_keys)
        2
    """
    _address: Raw = field(name="address")
    _storageKeys: Raw = field(name="storageKeys")
    @cached_property
    def address(self) -> Address:
        """
        The Ethereum address of the contract whose storage is being accessed.
        """
        return json.decode(self._address, type=Address, dec_hook=Address._decode_hook)
    @cached_property
    def storageKeys(self) -> List[HexBytes]:
        """
        The specific storage slot keys within the contract that will be accessed.
        """
        return json.decode(self._storageKeys, type=List[HexBytes], dec_hook=_decode_hexbytes)

class _TransactionBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    # `type` field is omitted since it's used in the tagged union
    input: HexBytes
    hash: HexBytes
    _to: Raw = field(name="to")  # null for contract deployments
    _gas: Raw = field(name="gas")
    _value: Raw = field(name="value")
    _nonce: Raw = field(name="nonce")
    _chainId: Raw = field(name="chainId")  # null for v in {27, 28}, otherwise derived from eip-155
    # details
    _sender: Raw = field(name="from")
    _blockHash: Raw = field(name="blockHash")
    _blockNumber: Raw = field(name="blockNumber")
    _transactionIndex: Raw = field(name="transactionIndex")
    
    # signature
    _v: Raw = field(name="v")
    _r: Raw = field(name="r")
    _s: Raw = field(name="s")

    def __getitem__(self, key: str) -> Any:
        try:
            return getattr(self, key)
        except AttributeError:
            if key == "from":
                return self.sender
            raise KeyError(key) from None

    @cached_property
    def blockHash(self) -> HexBytes:
        return json.decode(self._blockHash, type=HexBytes, dec_hook=_decode_hexbytes)

    @cached_property
    def to(self) -> Optional[Address]:
        # null for contract deployments
        return json.decode(self._to, type=Optional[Address], dec_hook=Address._decode_hook)

    @cached_property
    def chainId(self) -> Optional[uint]:
        return json.decode(self._chainId, type=Optional[uint], dec_hook=uint._decode_hook)

    @cached_property
    def nonce(self) -> uint:
        return json.decode(self._nonce, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def gas(self) -> uint:
        return json.decode(self._gas, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def value(self) -> Decimal:
        return Decimal(json.decode(self._value, type=uint, dec_hook=uint._decode_hook)) / 10 ** 18

    @cached_property
    def blockNumber(self) -> uint:
        return json.decode(self._blockNumber, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def transactionIndex(self) -> uint:
        return json.decode(self._transactionIndex, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def sender(self) -> Address:
        return json.decode(self._sender, type=Address, dec_hook=Address._decode_hook)

    @cached_property
    def v(self) -> uint:
        return json.decode(self._v, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def r(self) -> HexBytes:
        return json.decode(self._r, type=HexBytes, dec_hook=_decode_hexbytes)

    @cached_property
    def s(self) -> HexBytes:
        return json.decode(self._s, type=HexBytes, dec_hook=_decode_hexbytes)



class TransactionLegacy(_TransactionBase, tag="0x0", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    _gasPrice: Raw = field(name="gasPrice")
    @cached_property
    def gasPrice(self) -> uint:
        return json.decode(self._gasPrice, type=uint, dec_hook=uint._decode_hook)


class Transaction2930(_TransactionBase, tag="0x1", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    _gasPrice: Raw = field(name="gasPrice")
    _accessList: Raw = field(name="accessList", default=UNSET)
    @cached_property
    def gasPrice(self) -> uint:
        return json.decode(self._gasPrice, type=uint, dec_hook=uint._decode_hook)
    @cached_property
    def accessList(self) -> Optional[List[AccessListEntry]]:
        return json.decode(self._accessList, type=Optional[List[AccessListEntry]])


class Transaction1559(_TransactionBase, tag="0x2", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    _maxFeePerGas: Raw = field(name="maxFeePerGas")
    _maxPriorityFeePerGas: Raw = field(name="maxPriorityFeePerGas")
    _accessList: Raw = field(name="accessList", default=UNSET)
    @cached_property
    def maxFeePerGas(self) -> uint:
        return json.decode(self._maxFeePerGas, type=uint, dec_hook=uint._decode_hook)
    @cached_property
    def maxPriorityFeePerGas(self) -> uint:
        return json.decode(self._maxPriorityFeePerGas, type=uint, dec_hook=uint._decode_hook)
    @cached_property
    def accessList(self) -> Optional[List[AccessListEntry]]:
        return json.decode(self._accessList, type=Optional[List[AccessListEntry]])
    
    # TODO: make sure this actually should go here
    _gasPrice: Raw = field(name="gasPrice")
    @cached_property
    def gasPrice(self) -> uint:
        return json.decode(self._gasPrice, type=uint, dec_hook=uint._decode_hook)


Transaction = Union[TransactionLegacy, Transaction2930, Transaction1559]
