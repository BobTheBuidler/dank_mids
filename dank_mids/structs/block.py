
import logging
from functools import cached_property
from typing import List, Optional, Union

from hexbytes import HexBytes
from msgspec import UNSET, Raw, ValidationError, field, json

from dank_mids.structs.data import Address, BlockNumber, IntId, UnixTimestamp, Wei, uint, _decode_hook
from dank_mids.structs.dict import DictStruct, LazyDictStruct
from dank_mids.structs.transaction import Transaction


logger = logging.getLogger(__name__)

class StakingWithdrawal(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """A Struct representing an Ethereum staking withdrawal."""
    index: IntId

    amount: Wei = UNSET
    """This field is not always present."""

    address: Address = UNSET
    """This field is not always present."""

    validatorIndex: IntId = UNSET
    """This field is not always present."""


class Timestamped(LazyDictStruct, frozen=True):  # type: ignore [call-arg]
    
    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated."""


class TinyBlock(Timestamped, frozen=True, kw_only=True):  # type: ignore [call-arg]

    _transactions: Raw = field(name="transactions")
    """Array of transaction objects, or 32 Bytes transaction hashes depending on the last given parameter."""

    @cached_property
    def transactions(self) -> List[Union[HexBytes, Transaction]]:
        """Array of transaction objects, or 32 Bytes transaction hashes depending on the last given parameter."""
        try:
            transactions = json.decode(self._transactions, type=List[Union[str, Transaction]], dec_hook=_decode_hook)
        except ValidationError as e:
            from dank_mids.types import better_decode
            logger.exception(e)
            transactions = [
                better_decode(raw_tx, type=Union[str, Transaction], dec_hook=_decode_hook)
                for raw_tx in json.decode(self._transactions, type=List[Raw])
            ]
        if transactions and isinstance(transactions[0], str):
            transactions = [HexBytes(txhash) for txhash in transactions]
        return transactions


class Block(TinyBlock, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    
    sha3Uncles: HexBytes
    """SHA3 of the uncles data in the block."""
    
    miner: Address
    """The address of the miner receiving the reward."""

    stateRoot: HexBytes
    """The root of the final state trie of the block."""

    transactionsRoot: HexBytes
    """The root of the transaction trie of the block."""

    receiptsRoot: HexBytes
    """The root of the receipts trie of the block."""

    logsBloom: HexBytes
    """The bloom filter for the logs of the block."""

    number: BlockNumber
    """The block number."""

    gasLimit: Wei
    """The maximum gas allowed in this block."""

    gasUsed: Wei
    """The total used gas by all transactions in this block."""
    
    extraData: HexBytes
    """The “extra data” field of this block."""

    parentHash: HexBytes
    """Hash of the parent block."""

    mixHash: HexBytes
    """A string of a 256-bit hash encoded as a hexadecimal."""
    
    nonce: IntId
    """Hash of the generated proof-of-work."""

    size: uint

    uncles: List[HexBytes]
    """An Array of uncle hashes."""
    
    totalDifficulty: Optional[uint] = UNSET
    """
    Hexadecimal of the total difficulty of the chain until this block.
    
    This field is only present on Ethereum.
    """

    _withdrawals: Raw = field(name="withdrawals", default=UNSET)
    """This field is only present on Ethereum."""
    @cached_property
    def withdrawals(self) -> List[StakingWithdrawal]:
        """This field is only present on Ethereum."""
        return json.decode(self._withdrawals, type=List[StakingWithdrawal], dec_hook=_decode_hook)
    
class ErigonHeader(Timestamped, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    parentHash: HexBytes
    uncleHash: HexBytes
    coinbase: Address
    root: HexBytes
    difficulty: uint