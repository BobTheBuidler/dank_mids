
from functools import cached_property
from typing import Any, ClassVar, Optional, Union

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs import data
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

    address: data.Address
    """The Ethereum address of the contract whose storage is being accessed."""

    _storageKeys: Raw = field(name="storageKeys")
    """The specific storage slot keys within the contract that will be accessed."""
    
    @cached_property
    def storageKeys(self) -> data.HashableList[data.HexBytes32]:
        """The specific storage slot keys within the contract that will be accessed."""
        return json.decode(self._storageKeys, type=data.HashableList[data.HexBytes32], dec_hook=data.decode_hexbytes)

class _TransactionBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    # `type` field is omitted since it's used in the tagged union
    input: HexBytes
    """The data sent along with the transaction."""

    hash: data.TransactionHash
    """The hash of the transaction."""

    to: Optional[data.Address]
    """The address of the receiver. `None` when it's a contract creation transaction."""

    gas: data.Wei
    """The gas provided by the sender."""

    value: data.Wei
    """The value transferred in wei encoded as hexadecimal."""

    nonce: data.Nonce
    """The number of transactions made by the sender before this one."""

    chainId: Optional[data.ChainId] = UNSET  # type: ignore [assignment]
    """
    The chain id of the transaction, if any.
    
    `None` for v in {27, 28}, otherwise derived from eip-155

    This field is not included in the transactions field of a eth_getBlock response.
    """

    # details
    sender: data.Address = field(name="from")
    """The address of the sender."""

    blockHash: data.BlockHash
    """The hash of the block including this transaction. `None` when it's pending."""

    blockNumber: data.BlockNumber
    """The number of the block including this transaction. `None` when it's pending."""

    transactionIndex: data.TransactionIndex
    """The index position of the transaction in the block. `None` when it's pending."""
    
    # signature
    v: data.uint
    """ECDSA recovery ID."""

    r: HexBytes
    """The R field of the signature."""

    s: HexBytes
    """The S field of the signature."""

    def __hash__(self) -> int:
        return hash(self.hash.hex())

    def __getitem__(self, key: str) -> Any:
        try:
            return getattr(self, key)
        except AttributeError:
            if key == "from":
                return self.sender
            raise KeyError(key) from None

    gasPrice: data.Wei
    """The gas price provided by the sender in wei."""
    
    @property
    def block(self) -> data.BlockNumber:
        """
        A shorthand getter for blockNumber.
        """
        return self.blockNumber

    _accessList: Raw = field(name="accessList", default=UNSET)
    """A list of addresses and storage keys that the transaction plans to access."""
    
    @cached_property
    def accessList(self) -> data.HashableList[AccessListEntry]:
        """A list of addresses and storage keys that the transaction plans to access."""
        return json.decode(self._accessList, type=data.HashableList[AccessListEntry])


class TransactionLegacy(_TransactionBase, tag="0x0", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("0")


class Transaction2930(_TransactionBase, tag="0x1", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("1")


class Transaction1559(_TransactionBase, tag="0x2", frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("2")

    maxFeePerGas: data.Wei
    """The maximum fee per gas set in the transaction."""

    maxPriorityFeePerGas: data.Wei
    """The maximum priority gas fee set in the transaction."""


Transaction = Union[TransactionLegacy, Transaction2930, Transaction1559]
