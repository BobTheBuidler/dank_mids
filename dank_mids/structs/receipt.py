
from functools import cached_property
from typing import List, Optional

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs.data import (Address, Status, uint, _decode_hexbytes, _decode_hook,
                                    enum_decode_hook)
from dank_mids.structs.dict import DictStruct, LazyDictStruct
from dank_mids.structs.log import Log

class FeeStats(DictStruct, frozen=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """Arbitrum includes this in the `feeStats` field of a tx receipt."""
    l1Calldata: uint
    l2Storage: uint
    l1Transaction: uint
    l2Computation: uint

class ArbitrumFeeStats(DictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """Arbitrum includes these with a tx receipt."""
    paid: FeeStats
    """
    The breakdown of gas paid for the transaction.
    
    (price * unitsUsed)
    """
    # These 2 attributes do not always exist
    unitsUsed: FeeStats = UNSET
    """The breakdown of units of gas used for the transaction."""
    prices: FeeStats = UNSET
    """The breakdown of gas prices for the transaction."""


class TransactionReceipt(LazyDictStruct, frozen=True, kw_only=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    _transactionHash: Raw = field(name="transactionHash")
    """The position of this transaction."""

    _blockNumber: Raw = field(name="blockNumber")
    """The block number that contains the transaction."""

    _contractAddress: Raw = field(name="contractAddress")
    """The contract address created, if the transaction was a contract creation, otherwise `None`."""

    _transactionIndex: Raw = field(name="transactionIndex")
    """The position of the transaction where this log originates from. `None` when it's a pending transaction."""

    _status: Raw = field(name="status")
    """1 if the transaction succeeded, 0 if it failed."""

    _gasUsed: Raw = field(name="gasUsed")
    """The amount of gas used by this transaction, not counting internal transactions, calls or delegate calls."""

    _cumulativeGasUsed: Raw = field(name="cumulativeGasUsed")
    """The total amount of gas used during this transaction."""

    _logs: Raw = field(name="logs")
    """The logs that were generated during this transaction."""

    @cached_property
    def transactionHash(self) -> HexBytes:
        """The position of this transaction."""
        return json.decode(self._transactionHash, type=uint, dec_hook=_decode_hexbytes)

    @cached_property
    def blockNumber(self) -> uint:
        """The block number that contains the transaction."""
        return json.decode(self._blockNumber, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def contractAddress(self) -> Optional[Address]:
        """The contract address created, if the transaction was a contract creation, otherwise `None`."""
        return json.decode(self._transactionIndex, type=Optional[Address], dec_hook=Address._decode_hook)

    @cached_property
    def transactionIndex(self) -> uint:
        """The position of the transaction where this log originates from. `None` when it's a pending transaction."""
        return json.decode(self._transactionIndex, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def status(self) -> Status:
        """1 if the transaction succeeded, 0 if it failed."""
        return json.decode(self._status, type=Status, dec_hook=enum_decode_hook)

    @cached_property
    def gasUsed(self) -> uint:
        """The amount of gas used by this transaction, not counting internal transactions, calls or delegate calls."""
        return json.decode(self._gasUsed, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def cumulativeGasUsed(self) -> uint:
        """The total amount of gas used during this transaction."""
        return json.decode(self._cumulativeGasUsed, type=uint, dec_hook=uint._decode_hook)
    
    @cached_property
    def logs(self) -> List[Log]:
        """The logs that were generated during this transaction."""
        return json.decode(self._logs, type=List[Log], dec_hook=_decode_hook)

    # These fields are only present on Mainnet.
    effectiveGasPrice: uint = UNSET
    """
    The actual value per gas deducted from the sender's account.
    
    This field is only present on Mainnet.
    """

    type: uint = UNSET
    """
    The transaction type.

    This field is only present on Mainnet.
    """

    blobGasUsed: uint = UNSET
    """This field is sometimes present, only on Mainnet."""

    # These fields are only present on Optimism.
    l1FeeScalar: uint = UNSET
    """This field is only present on Optimism."""
    l1GasUsed: uint = UNSET
    """This field is only present on Optimism."""
    l1GasPrice: uint = UNSET
    """This field is only present on Optimism."""
    l1Fee: uint = UNSET
    """This field is only present on Optimism."""

    # These fields are only present on Arbitrum.
    l1BlockNumber: uint = UNSET
    """This field is only present on Arbitrum."""
    l1InboxBatchInfo: Optional[HexBytes] = UNSET
    """This field is only present on Arbitrum."""
    _feeStats: Raw = field(name="feeStats", default=UNSET)
    """This field is only present on Arbitrum."""
    @cached_property
    def feeStats(self) -> ArbitrumFeeStats:
        return json.decode(self._feeStats, type=ArbitrumFeeStats, dec_hook=uint._decode_hook)

class FullTransactionReceipt(TransactionReceipt, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    blockHash: HexBytes
    """The hash of the block that contains the transaction."""

    logsBloom: HexBytes
    """The bloom filter for all logs in this block."""
