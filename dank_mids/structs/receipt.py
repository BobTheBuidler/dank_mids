
from functools import cached_property
from typing import List, Optional

import msgspec
from hexbytes import HexBytes

from dank_mids.structs.data import Address, uint, _decode_hook
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
    unitsUsed: FeeStats = msgspec.UNSET
    """The breakdown of units of gas used for the transaction."""
    prices: FeeStats = msgspec.UNSET
    """The breakdown of gas prices for the transaction."""

class TransactionReceipt(LazyDictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    transactionHash: HexBytes
    blockHash: HexBytes
    blockNumber: uint
    logsBloom: HexBytes
    contractAddress: Optional[Address]
    transactionIndex: Optional[uint]
    gasUsed: uint
    cumulativeGasUsed: uint
    _logs: msgspec.Raw = msgspec.field(name="logs")
    
    @cached_property
    def logs(self) -> List[Log]:
        return msgspec.json.decode(self._logs, type=List[Log], dec_hook=_decode_hook)

    # These fields are only present on Mainnet.
    effectiveGasPrice: uint = msgspec.UNSET
    """This field is only present on Mainnet."""

    # These fields are only present on Optimism.
    l1FeeScalar: uint = msgspec.UNSET
    """This field is only present on Optimism."""
    l1GasUsed: uint = msgspec.UNSET
    """This field is only present on Optimism."""
    l1Fee: uint = msgspec.UNSET
    """This field is only present on Optimism."""

    # These fields are only present on Arbitrum.
    l1BlockNumber: uint = msgspec.UNSET
    """This field is only present on Arbitrum."""
    l1InboxBatchInfo: Optional[HexBytes] = msgspec.UNSET
    """This field is only present on Arbitrum."""
    _feeStats: msgspec.Raw = msgspec.field(name="feeStats", default=msgspec.UNSET)
    """This field is only present on Arbitrum."""
    @cached_property
    def feeStats(self) -> ArbitrumFeeStats:
        return msgspec.json.decode(self._feeStats, type=ArbitrumFeeStats, dec_hook=_decode_hook)