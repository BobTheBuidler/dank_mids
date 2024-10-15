
from functools import cached_property
from typing import List, Optional, Union

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from dank_mids.structs.data import Address, uint, _decode_hook
from dank_mids.structs.dict import DictStruct, LazyDictStruct
from dank_mids.structs.transaction import Transaction


class StakingWithdrawal(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """A Struct representing an Ethereum staking withdrawal."""
    index: uint

    amount: uint = UNSET
    """This field is not always present."""

    address: Address = UNSET
    """This field is not always present."""

    validatorIndex: uint = UNSET
    """This field is not always present."""

class Timestamped(LazyDictStruct, frozen=True):  # type: ignore [call-arg]
    timestamp: uint

class TinyBlock(Timestamped, frozen=True, kw_only=True):  # type: ignore [call-arg]
    _transactions: Raw = field(name="transactions")
    @cached_property
    def transactions(self) -> List[Union[HexBytes, Transaction]]:
        transactions = json.decode(self._transactions, type=List[Union[str, Transaction]], dec_hook=_decode_hook)
        if transactions and isinstance(transactions[0], str):
            transactions = [HexBytes(txhash) for txhash in transactions]
        return transactions

class Block(TinyBlock, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    sha3Uncles: HexBytes
    miner: Address
    stateRoot: HexBytes
    transactionsRoot: HexBytes
    receiptsRoot: HexBytes
    logsBloom: HexBytes
    number: uint
    gasLimit: uint
    gasUsed: uint
    extraData: HexBytes
    parentHash: HexBytes
    mixHash: HexBytes
    nonce: uint
    size: uint
    uncles: List[HexBytes]
    
    totalDifficulty: Optional[uint] = UNSET
    """This field is only present on Ethereum."""

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