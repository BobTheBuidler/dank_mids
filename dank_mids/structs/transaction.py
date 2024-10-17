
from decimal import Decimal
from functools import cached_property
from typing import Any, ClassVar, List, Optional, Union

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

    address: Address
    """The Ethereum address of the contract whose storage is being accessed."""

    _storageKeys: Raw = field(name="storageKeys")
    """The specific storage slot keys within the contract that will be accessed."""
    
    @cached_property
    def storageKeys(self) -> List[HexBytes]:
        """The specific storage slot keys within the contract that will be accessed."""
        return json.decode(self._storageKeys, type=List[HexBytes], dec_hook=_decode_hexbytes)

class _TransactionBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    # `type` field is omitted since it's used in the tagged union
    input: HexBytes
    """The data sent along with the transaction."""

    hash: HexBytes
    """The hash of the transaction."""

    _to: Raw = field(name="to")
    """The address of the receiver. `None` when it's a contract creation transaction."""

    gas: uint
    """The gas provided by the sender."""

    value: uint
    """The value transferred in wei encoded as hexadecimal."""

    nonce: uint
    """The number of transactions made by the sender before this one."""

    chainId: Optional[uint]
    """
    The chain id of the transaction, if any.
    
    `None` for v in {27, 28}, otherwise derived from eip-155
    """

    # details
    _sender: Raw = field(name="from")
    """The address of the sender."""

    _blockHash: Raw = field(name="blockHash")
    """The hash of the block including this transaction. `None` when it's pending."""

    blockNumber: uint
    """The number of the block including this transaction. `None` when it's pending."""

    transactionIndex: uint
    """The index position of the transaction in the block. `None` when it's pending."""
    
    # signature
    v: uint
    """ECDSA recovery ID."""

    _r: Raw = field(name="r")
    """The R field of the signature."""

    _s: Raw = field(name="s")
    """The S field of the signature."""

    def __getitem__(self, key: str) -> Any:
        try:
            return getattr(self, key)
        except AttributeError:
            if key == "from":
                return self.sender
            raise KeyError(key) from None

    @cached_property
    def blockHash(self) -> Optional[HexBytes]:
        """The hash of the block including this transaction. `None` when it's pending."""
        return json.decode(self._blockHash, type=Optional[HexBytes], dec_hook=_decode_hexbytes)

    @cached_property
    def to(self) -> Optional[Address]:
        """The address of the receiver. `None` when it's a contract creation transaction."""
        return json.decode(self._to, type=Optional[Address], dec_hook=Address._decode_hook)

    @cached_property
    def value_scaled(self) -> Decimal:
        """The value transferred in wei."""
        return Decimal(self.value) / 10 ** 18

    @cached_property
    def sender(self) -> Address:
        """The address of the sender."""
        return json.decode(self._sender, type=Address, dec_hook=Address._decode_hook)

    gasPrice: uint
    """The gas price provided by the sender in wei."""

    @cached_property
    def r(self) -> HexBytes:
        """The R field of the signature."""
        return json.decode(self._r, type=HexBytes, dec_hook=_decode_hexbytes)

    @cached_property
    def s(self) -> HexBytes:
        """The S field of the signature."""
        return json.decode(self._s, type=HexBytes, dec_hook=_decode_hexbytes)
    
    @property
    def block(self) -> uint:
        """
        A shorthand getter for blockNumber.
        """
        return self.blockNumber

    _accessList: Raw = field(name="accessList", default=UNSET)
    """A list of addresses and storage keys that the transaction plans to access."""
    
    @cached_property
    def accessList(self) -> List[AccessListEntry]:
        """A list of addresses and storage keys that the transaction plans to access."""
        return json.decode(self._accessList, type=List[AccessListEntry])


class TransactionLegacy(_TransactionBase, tag="0x0", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("0")


class Transaction2930(_TransactionBase, tag="0x1", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("1")


class Transaction1559(_TransactionBase, tag="0x2", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("2")

    maxFeePerGas: uint
    """The maximum fee per gas set in the transaction."""

    maxPriorityFeePerGas: uint
    """The maximum priority gas fee set in the transaction."""


Transaction = Union[TransactionLegacy, Transaction2930, Transaction1559]
