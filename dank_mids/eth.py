
from typing import Awaitable, Callable, List, Literal, Sequence, Tuple, Type, TypedDict, Union, overload

from async_lru import alru_cache
from async_property import async_cached_property
from eth_typing import BlockNumber
from msgspec import Raw, Struct, ValidationError, json
from web3._utils.blocks import select_method_for_block_identifier
from web3._utils.rpc_abi import RPC
from web3.eth import AsyncEth
from web3.method import default_root_munger
from web3.types import Address, BlockIdentifier, ChecksumAddress, ENS, HexStr

from dank_mids._method import WEB3_MAJOR_VERSION, MethodNoFormat, bypass_formatters, _block_selectors
from dank_mids.structs import FilterTrace, Log, TransactionRLP, TransactionReceipt, Transaction
from dank_mids.structs.block import Timestamped, TinyBlock
from dank_mids.structs.data import Status, TransactionHash, UnixTimestamp, _decode_hook, enum_decode_hook
from dank_mids.structs.transaction import AnyTransaction
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
    _block_cache_ttl = 0.1

    # eth_chainId

    @async_cached_property
    async def chain_id(self) -> int:
        return await self._chain_id()

    _chain_id: MethodNoFormat[Callable[[], Awaitable[int]]]

    try:
        _chain_id = MethodNoFormat(RPC.eth_chainId, is_property=True)
    except TypeError as e:  # NOTE: older web3.py versions cant use `is_property` kwarg
        if str(e) != "__init__() got an unexpected keyword argument 'is_property'":
            raise
        _chain_id = MethodNoFormat(RPC.eth_chainId, mungers=None)

    # eth_blockNumber

    @property
    @alru_cache(maxsize=None, ttl=_block_cache_ttl)
    async def block_number(self) -> BlockNumber:  # type: ignore [override]
        return await self.get_block_number()
    
    async def get_block_number(self) -> BlockNumber:  # type: ignore [override]
        return await self._get_block_number()  # type: ignore [misc]

    _get_block_number: MethodNoFormat[Callable[[], Awaitable[BlockNumber]]] = MethodNoFormat(
        RPC.eth_blockNumber,
        is_property=True,
    )
    
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
        try:  # TypeError: 'str' object cannot be interpreted as an integer
            block_identifier = hex(block_identifier)
        finally:
            block_bytes = await self._get_block_raw(block_identifier, False)
            return json.decode(block_bytes, type=Timestamped, dec_hook=UnixTimestamp._decode_hook).timestamp

    @overload
    async def get_transactions(self, block_identifier: Union[int, HexStr]) -> List[Transaction]:
        ...
    @overload
    async def get_transactions(self, block_identifier: Union[int, HexStr], hashes_only: Literal[True]) -> List[TransactionHash]:
        ...
    @overload
    async def get_transactions(self, block_identifier: Union[int, HexStr], hashes_only: Literal[False]) -> List[Transaction]:
        ...
    async def get_transactions(self, block_identifier: Union[int, HexStr], hashes_only: bool = False) -> Union[List[Transaction], List[TransactionHash]]:
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
        try:  # TypeError: 'str' object cannot be interpreted as an integer
            block_identifier = hex(block_identifier)  # type: ignore [arg-type, assignment]
        finally:
            block_bytes = await self._get_block_raw(block_identifier, not hashes_only)
            return json.decode(block_bytes, type=TinyBlock, dec_hook=_decode_hook).transactions

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

    async def trace_filter(
        self, 
        filter_params: TraceFilterParams,
        decode_to: Type[T] = List[FilterTrace], 
        decode_hook: DecodeHook = _decode_hook,
    ) -> T:
        traces_bytes = await self._trace_filter(filter_params)
        try:
            return json.decode(traces_bytes, type=decode_to, dec_hook=decode_hook)
        except ValidationError:
            if decode_to.__origin__ is not list:
                raise
            
            traces_raw = json.decode(traces_bytes, type=List[Raw])
            traces = []
            trace_cls = decode_to.__args__[0]
            for raw in traces_raw:
                try:
                    traces.append(json.decode(raw, type=trace_cls, dec_hook=decode_hook))
                except ValidationError as e:
                    e.args = *e.args, json.decode(raw)
                    raise
    
    async def trace_transaction(self, transaction_hash: str) -> List[FilterTrace]:
        return await self._trace_transaction(transaction_hash)
    
    _get_transaction_raw = MethodNoFormat(f"{RPC.eth_getTransactionByHash}_raw", mungers=[default_root_munger])  # type: ignore [arg-type,var-annotated]

    async def get_transaction(self, transaction_hash: str) -> AnyTransaction:  # type: ignore [override]
        transaction_bytes = await self._get_transaction_raw(transaction_hash)
        try:
            return json.decode(transaction_bytes, type=Transaction, dec_hook=_decode_hook)
        except ValidationError:
            try:
                return json.decode(transaction_bytes, type=TransactionRLP, dec_hook=_decode_hook)
            except ValidationError as e:
                e.args = *e.args, json.decode(transaction_bytes)
                raise
        
    async def get_logs(
        self, 
        *args, 
        decode_to: Type[T] = Tuple[Log, ...],  # type: ignore [assignment]
        decode_hook: DecodeHook = _decode_hook, 
        **kwargs,
    ) -> T:
        logs_bytes = await self._get_logs_raw(*args, **kwargs)  # type: ignore [attr-defined]
        return json.decode(logs_bytes, type=decode_to, dec_hook=decode_hook)

    meth = MethodNoFormat.default(RPC.eth_getTransactionReceipt)  # type: ignore [arg-type, var-annotated]
    if WEB3_MAJOR_VERSION >= 6:
        _transaction_receipt = meth
    else:
        _get_transaction_receipt = meth

    _get_transaction_receipt_raw = MethodNoFormat.default(f"{RPC.eth_getTransactionReceipt}_raw")
    

    _get_block_raw = MethodNoFormat(
        method_choice_depends_on_args=select_method_for_block_identifier(**{k:f"{v}_raw" for k, v in _block_selectors.items()}),
        mungers=[AsyncEth.get_block_munger],
    )
    _trace_filter = MethodNoFormat.default(f"{RPC.trace_filter}_raw")
    _trace_transaction = MethodNoFormat.default(RPC.trace_transaction)

    
# TODO: this is super hacky, make it not.
bypass_formatters(DankEth)
