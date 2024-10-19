
from typing import List, Sequence, Tuple, Type, TypedDict, TypeVar, Union

from async_lru import alru_cache
from eth_typing import BlockNumber
from msgspec import Struct, json
from web3._utils.blocks import select_method_for_block_identifier
from web3._utils.rpc_abi import RPC
from web3.eth import AsyncEth
from web3.types import Address, BlockIdentifier, ChecksumAddress, ENS

from dank_mids._method import WEB3_MAJOR_VERSION, MethodNoFormat, bypass_formatters, _block_selectors
from dank_mids.structs import FilterTrace, Log, Transaction, TransactionReceipt
from dank_mids.structs.block import Timestamped, TinyBlock
from dank_mids.structs.data import Status, UnixTimestamp, _decode_hook, enum_decode_hook
from dank_mids.types import DecodeHook, T


class TraceFilterParams(TypedDict, total=False):  # type: ignore [call-arg]
    after: int
    count: int
    fromAddress: Sequence[Union[Address, ChecksumAddress, ENS]]
    fromBlock: BlockIdentifier
    toAddress: Sequence[Union[Address, ChecksumAddress, ENS]]
    toBlock: BlockIdentifier


class _Statusable(Struct):
    status: Status
    

class DankEth(AsyncEth):
    @alru_cache(ttl=0)
    async def get_block_number(self) -> BlockNumber:  # type: ignore [override]
        return await super().get_block_number()  # type: ignore [misc]
    
    async def get_block_timestamp(self, block_identifier: int) -> UnixTimestamp:
        """
        Retrieves only the timestamp from a specific block.
        
        This method skips decoding the rest of the Block response data.

        Args:
            block_identifier: The block number from which to retrieve the transactions.
            hashes_only: If True, only transaction hashes will be returned.

        Returns:
            A list of :class:`~Transaction` data objects from the block, or a list of transaction hashes.

        Example:
            >>> [print(tx.hash) for tx in await dank_mids.eth.get_transactions(12345678)]
        """
        return json.decode(await self._get_block_raw(block_identifier), type=Timestamped, dec_hook=UnixTimestamp._decode_hook).timestamp

    async def get_transactions(self, block_identifier: int, hashes_only: bool = False) -> List[Transaction]:
        """
        Retrieves only the transactions from a specific block. 
        
        This method skips decoding the rest of the Block response data.

        Args:
            block_identifier: The block number from which to retrieve the transactions.
            hashes_only: If True, only transaction hashes will be returned.

        Returns:
            A list of :class:`~Transaction` data objects from the block, or a list of transaction hashes.

        Example:
            >>> [print(tx.hash) for tx in await dank_mids.eth.get_transactions(12345678)]
        """
        return json.decode(await self._get_block_raw(block_identifier, not hashes_only), type=TinyBlock, dec_hook=_decode_hook).transactions

    async def get_transaction_receipt(
        self, 
        *args, 
        decode_to: Type[T] = TransactionReceipt, 
        decode_hook: DecodeHook = _decode_hook,
        **kwargs,
    ) -> T:
        receipt_bytes = await self._get_transaction_receipt_raw(*args, **kwargs)
        return json.decode(receipt_bytes, type=decode_to, dec_hook=decode_hook)
    
    async def get_transaction_status(self, transaction_hash: str) -> Status:
        return (await self.get_transaction_receipt(transaction_hash, decode_to=_Statusable, decode_hook=enum_decode_hook)).status

    async def trace_filter(self, filter_params: TraceFilterParams) -> List[FilterTrace]:
        return await self._trace_filter(filter_params)
    
    async def trace_transaction(self, transaction_hash: str) -> List[FilterTrace]:
        return await self._trace_transaction(transaction_hash)
    
    async def get_logs(
        self, 
        *args, 
        decode_to: Type[T] = Tuple[Log, ...], 
        decode_hook: DecodeHook = _decode_hook, 
        **kwargs,
    ) -> T:
        logs_bytes = await self._get_logs_raw(*args, **kwargs)
        return json.decode(logs_bytes, type=decode_to, dec_hook=decode_hook)

    meth = MethodNoFormat.default(RPC.eth_getTransactionReceipt)
    if WEB3_MAJOR_VERSION >= 6:
        _transaction_receipt = meth
    else:
        _get_transaction_receipt = meth

    _get_transaction_receipt_raw = MethodNoFormat.default(f"{RPC.eth_getTransactionReceipt}_raw")
    

    _get_block_raw = MethodNoFormat(
        method_choice_depends_on_args=select_method_for_block_identifier(**{k:f"{v}_raw" for k, v in _block_selectors.items()}),
        mungers=[AsyncEth.get_block_munger],
    )
    _trace_filter = MethodNoFormat.default(RPC.trace_filter)
    _trace_transaction = MethodNoFormat.default(RPC.trace_transaction)

    
# TODO: this is super hacky, make it not.
bypass_formatters(DankEth)
