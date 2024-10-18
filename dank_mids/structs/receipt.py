
from functools import cached_property
from typing import Optional, Tuple

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs.data import (Address, BlockNumber, Decimal, TransactionHash, 
                                    Status, TransactionIndex, Wei, uint, _decode_hook)
from dank_mids.structs.dict import DictStruct, LazyDictStruct
from dank_mids.structs.log import Log

class FeeStats(DictStruct, frozen=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """Arbitrum includes this in the `feeStats` field of a tx receipt."""
    l1Calldata: Wei
    l2Storage: Wei
    l1Transaction: Wei
    l2Computation: Wei

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

    transactionHash: TransactionHash
    """The unique hash of this transaction."""

    blockNumber: BlockNumber
    """The block number that contains the transaction."""

    contractAddress: Optional[Address]
    """The contract address created, if the transaction was a contract creation, otherwise `None`."""

    transactionIndex: TransactionIndex
    """The position of this transaction within the block."""

    status: Status
    """1 if the transaction succeeded, 0 if it failed."""

    gasUsed: Wei
    """The amount of gas used by this transaction, not counting internal transactions, calls or delegate calls."""

    cumulativeGasUsed: Wei
    """The total amount of gas used during this transaction."""

    _logs: Raw = field(name="logs")
    """The logs that were generated during this transaction."""
    
    @cached_property
    def logs(self) -> Tuple[Log]:
        """The logs that were generated during this transaction."""
        return json.decode(self._logs, type=Tuple[Log], dec_hook=_decode_hook)

    # These fields are only present on Mainnet.
    effectiveGasPrice: Wei = UNSET
    """
    The actual value per gas deducted from the sender's account.
    
    This field is only present on Mainnet.
    """

    type: uint = UNSET
    """
    The transaction type.

    This field is only present on Mainnet.
    """

    blobGasUsed: Wei = UNSET
    """This field is sometimes present, only on Mainnet."""

    # These fields are only present on Optimism.
    l1FeeScalar: Decimal = UNSET
    """This field is only present on Optimism."""
    l1GasUsed: Wei = UNSET
    """This field is only present on Optimism."""
    l1GasPrice: Wei = UNSET
    """This field is only present on Optimism."""
    l1Fee: Wei = UNSET
    """This field is only present on Optimism."""

    # These fields are only present on Arbitrum.
    l1BlockNumber: BlockNumber = UNSET
    """This field is only present on Arbitrum."""
    l1InboxBatchInfo: Optional[HexBytes] = UNSET
    """This field is only present on Arbitrum."""
    _feeStats: Raw = field(name="feeStats", default=UNSET)
    """This field is only present on Arbitrum."""
    @cached_property
    def feeStats(self) -> ArbitrumFeeStats:
        return json.decode(self._feeStats, type=ArbitrumFeeStats, dec_hook=Wei._decode_hook)

class FullTransactionReceipt(TransactionReceipt, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    blockHash: HexBytes
    """The hash of the block that contains the transaction."""

    logsBloom: HexBytes
    """The bloom filter for all logs in this block."""
