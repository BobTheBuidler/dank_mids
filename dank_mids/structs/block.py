
from functools import cached_property
from typing import List, Optional, Union

import msgspec
from hexbytes import HexBytes

from dank_mids.structs.data import Address, uint, _decode_hook
from dank_mids.structs.dict import DictStruct, LazyDictStruct
from dank_mids.structs.transaction import Transaction


class StakingWithdrawal(DictStruct, frozen=True):  # type: ignore [call-arg]
    """A Struct representing an Ethereum staking withdrawal."""
    index: uint

    amount: uint = msgspec.UNSET
    """This field is not always present."""

    address: Address = msgspec.UNSET
    """This field is not always present."""

    validatorIndex: uint = msgspec.UNSET
    """This field is not always present."""

class _Timestamped(LazyDictStruct, frozen=True):  # type: ignore [call-arg]
    timestamp: uint

class _BlockHeaderBase(_Timestamped, frozen=True):  # type: ignore [call-arg]
    parentHash: HexBytes

class TinyBlock(_BlockHeaderBase, frozen=True):  # type: ignore [call-arg]
    _transactions: msgspec.Raw = msgspec.field(name="transactions")
    @cached_property
    def transactions(self) -> List[Union[HexBytes, Transaction]]:
        transactions = msgspec.json.decode(self._transactions, type=List[Union[str, Transaction]], dec_hook=_decode_hook)
        if transactions and isinstance(transactions[0], str):
            transactions = [HexBytes(txhash) for txhash in transactions]
        return transactions

class Block(TinyBlock, frozen=True):  # type: ignore [call-arg]
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
    mixHash: HexBytes
    nonce: uint
    size: uint
    uncles: List[HexBytes]
    
    totalDifficulty: Optional[uint] = msgspec.UNSET
    """This field is only present on Ethereum."""

    _withdrawals: msgspec.Raw = msgspec.field(name="withdrawals", default=msgspec.UNSET)
    """This field is only present on Ethereum."""
    @cached_property
    def withdrawals(self) -> List[StakingWithdrawal]:
        """This field is only present on Ethereum."""
        return msgspec.json.decode(self._withdrawals, type=List[StakingWithdrawal], dec_hook=_decode_hook)
    
class ErigonHeader(_BlockHeaderBase, frozen=True):  # type: ignore [call-arg]
    uncleHash: HexBytes
    coinbase: Address
    root: HexBytes
    difficulty: uint