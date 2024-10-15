
from functools import cached_property
from typing import List, Optional

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs.data import Address, Status, uint, _decode_hexbytes, _decode_hook
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
    _blockNumber: Raw = field(name="blockNumber")
    _contractAddress: Raw = field(name="contractAddress")
    _transactionIndex: Raw = field(name="transactionIndex")
    _status: Raw = field(name="status")
    _gasUsed: Raw = field(name="gasUsed")
    _cumulativeGasUsed: Raw = field(name="cumulativeGasUsed")
    _logs: Raw = field(name="logs")

    @cached_property
    def transactionHash(self) -> HexBytes:
        return json.decode(self._transactionHash, type=uint, dec_hook=_decode_hexbytes)

    @cached_property
    def blockNumber(self) -> uint:
        return json.decode(self._blockNumber, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def contractAddress(self) -> Optional[Address]:
        return json.decode(self._transactionIndex, type=Optional[Address], dec_hook=Address._decode_hook)

    @cached_property
    def transactionIndex(self) -> uint:
        return json.decode(self._transactionIndex, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def status(self) -> Status:
        return json.decode(self._status, type=Status, dec_hook=Status._decode_hook)

    @cached_property
    def gasUsed(self) -> uint:
        return json.decode(self._gasUsed, type=uint, dec_hook=uint._decode_hook)

    @cached_property
    def cumulativeGasUsed(self) -> uint:
        return json.decode(self._cumulativeGasUsed, type=uint, dec_hook=uint._decode_hook)
    
    @cached_property
    def logs(self) -> List[Log]:
        return json.decode(self._logs, type=List[Log], dec_hook=_decode_hook)

    # These fields are only present on Mainnet.
    effectiveGasPrice: uint = UNSET
    """This field is only present on Mainnet."""
    type: uint = UNSET
    """This field is only present on Mainnet."""
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
    logsBloom: HexBytes