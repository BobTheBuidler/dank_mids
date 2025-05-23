from typing import (
    Awaitable,
    Callable,
    Dict,
    Final,
    List,
    Literal,
    Optional,
    Sequence,
    Tuple,
    Type,
    TypedDict,
    Union,
    cast,
    overload,
)

from a_sync import Semaphore, igather
from async_lru import alru_cache
from async_property import async_cached_property
from eth_typing import Address, BlockNumber, ChecksumAddress, HexStr
from eth_utils.toolz import concat
from evmspec import AnyTransaction, FilterTrace, Transaction, TransactionRLP, TransactionReceipt
from evmspec.data import TransactionHash, UnixTimestamp, _decode_hook
from evmspec.data._main import DecodeHook
from evmspec.structs.block import TinyBlock
from evmspec.structs.log import Log
from evmspec.structs.receipt import Status
from hexbytes import HexBytes
from msgspec import Raw, Struct, ValidationError, json
from web3._utils.blocks import select_method_for_block_identifier
from web3._utils.rpc_abi import RPC
from web3.eth import AsyncEth, BaseEth
from web3.method import default_root_munger
from web3.types import BlockIdentifier, ENS, RPCEndpoint, TxParams, Wei

from dank_mids._web3.method import (
    WEB3_MAJOR_VERSION,
    MethodNoFormat,
    bypass_formatters,
    _block_selectors,
)
from dank_mids.types import T, Error


# These 2 type defs are in recent, but not all, web3.py versions
CallOverrideParams = TypedDict(
    "CallOverrideParams",
    {
        "balance": Optional[Wei],
        "nonce": Optional[int],
        "code": Optional[Union[bytes, HexStr]],
        "state": Optional[Dict[HexStr, HexStr]],
        "stateDiff": Optional[Dict[HexStr, HexStr]],
    },
    total=False,
)

CallOverride = Dict[ChecksumAddress, CallOverrideParams]


class TraceFilterParams(TypedDict, total=False):  # type: ignore [call-arg]
    after: int
    count: int
    fromAddress: Sequence[Union[Address, ChecksumAddress, ENS]]
    fromBlock: BlockIdentifier
    toAddress: Sequence[Union[Address, ChecksumAddress, ENS]]
    toBlock: BlockIdentifier


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

    _get_block_number: MethodNoFormat[Callable[[], Awaitable[BlockNumber]]]

    try:
        _get_block_number = MethodNoFormat(RPC.eth_blockNumber, is_property=True)
    except TypeError as e:  # NOTE: older web3.py versions cant use `is_property` kwarg
        if str(e) != "__init__() got an unexpected keyword argument 'is_property'":
            raise
        _get_block_number = MethodNoFormat(RPC.eth_blockNumber, mungers=None)

        _call: MethodNoFormat[
            Callable[
                [TxParams, Optional[BlockIdentifier], Optional[CallOverride]], Awaitable[HexBytes]
            ]
        ]
        _call = MethodNoFormat(RPC.eth_call, mungers=[BaseEth.call_munger])

    async def get_block_timestamp(self, block_identifier: int) -> UnixTimestamp:
        """
        Retrieves only the timestamp from a specific block.

        This method skips decoding the rest of the Block response data.

        Args:
            block_identifier: The block number from which to retrieve the timestamp.

        Example:
            >>> print(await dank_mids.eth.get_block_timestamp(12345678))
        """
        try:  # TypeError: 'str' object cannot be interpreted as an integer
            block_identifier = hex(block_identifier)
        finally:
            block_bytes = await self._get_block_raw(block_identifier, False)
            return decode_timestamped(block_bytes).timestamp

    async def get_balance(
        self, account: ChecksumAddress, block_identifier: Optional[BlockNumber] = None
    ):
        if isinstance(block_identifier, int):
            return await self._get_balance(account, hex(block_identifier))
        else:
            return await self._get_balance(account, block_identifier)

    async def get_transaction_count(
        self, account: ChecksumAddress, block_identifier: Optional[BlockNumber] = None
    ):
        if isinstance(block_identifier, int):
            return await self._get_transaction_count(account, hex(block_identifier))
        else:
            return await self._get_transaction_count(account, block_identifier)

    async def get_code(
        self, account: ChecksumAddress, block_identifier: Optional[BlockNumber] = None
    ):
        if isinstance(block_identifier, int):
            return await self._get_code(account, hex(block_identifier))
        else:
            return await self._get_code(account, block_identifier)

    @overload
    async def get_transactions(self, block_identifier: Union[int, HexStr]) -> List[Transaction]: ...
    @overload
    async def get_transactions(
        self, block_identifier: Union[int, HexStr], hashes_only: Literal[True]
    ) -> List[TransactionHash]: ...
    @overload
    async def get_transactions(
        self, block_identifier: Union[int, HexStr], hashes_only: Literal[False]
    ) -> List[Transaction]: ...
    async def get_transactions(
        self, block_identifier: Union[int, HexStr], hashes_only: bool = False
    ) -> Union[List[Transaction], List[TransactionHash]]:
        """
        Retrieves only the transactions from a specific block.

        This method skips decoding the rest of the Block response data.

        Args:
            block_identifier: The block number or hash from which to retrieve the transactions.
            hashes_only: If True, only transaction hashes will be returned.

        Example:
            >>> [print(tx.hash) for tx in await dank_mids.eth.get_transactions(12345678)]
        """
        try:  # TypeError: 'str' object cannot be interpreted as an integer
            block_identifier = hex(block_identifier)  # type: ignore [arg-type, assignment]
        finally:
            block_bytes = await self._get_block_raw(block_identifier, not hashes_only)
            return decode_tiny_block(block_bytes).transactions  # type: ignore [return-value]

    async def get_transaction_receipt(
        self,
        *args,
        decode_to: Type[T] = TransactionReceipt,
        decode_hook: Optional[DecodeHook[T]] = _decode_hook,
        **kwargs,
    ) -> T:
        """
        Fetches the transaction receipt and decodes it into the specified format.

        Args:
            *args: Additional positional arguments.
            decode_to: The class to which the receipt should be decoded.
            decode_hook: Hook function to assist in decoding.
            **kwargs: Additional keyword arguments.
        """
        receipt_bytes = await self._get_transaction_receipt_raw(*args, **kwargs)
        return json.decode(receipt_bytes, type=decode_to, dec_hook=decode_hook)

    async def get_transaction_status(self, transaction_hash: str) -> Status:
        """
        Retrieves the status of a transaction.

        Args:
            transaction_hash: The hash of the transaction to query.

        Returns:
            The status of the transaction.
        """
        tiny_receipt = await self.get_transaction_receipt(
            transaction_hash,
            decode_to=_Statusable,
            decode_hook=lambda enum_cls, data: enum_cls(data),
        )
        return tiny_receipt.status

    async def trace_filter(
        self,
        filter_params: TraceFilterParams,
        decode_to: Type[T] = List[FilterTrace],
        decode_hook: Optional[DecodeHook[T]] = _decode_hook,
    ) -> T:
        """
        Returns all traces matching a filter. If the decoding to the specified
        type fails, the method logs problematic traces and re-raises the
        exception as a diagnostic aid.

        Args:
            filter_params: The parameters defining the traces to filter.
            decode_to: The class to which traces should be decoded.
            decode_hook: Hook function to assist in decoding.

        Raises:
            ValidationError: If a trace cannot be decoded.
        """
        # convert block params from int to hexstr if needed
        from_block = filter_params.get("fromBlock")
        if isinstance(from_block, int):
            filter_params["fromBlock"] = hex(from_block)
        to_block = filter_params.get("toBlock")
        if isinstance(to_block, int):
            filter_params["toBlock"] = hex(to_block)

        try:
            traces_bytes = await self._trace_filter(filter_params)
        except ValueError as e:
            if "cannot unmarshal non-string into Go struct field" in str(e):
                e.args = *e.args, f"params: {filter_params}"
                raise

            block_range_err = "Block range too large; currently limited to "
            arg0, *_ = e.args
            if isinstance(arg0, Error):
                errmsg = arg0.message
                if errmsg.startswith(block_range_err) and from_block and to_block:
                    rest_of_msg = errmsg.split(block_range_err)[1]
                    max_range_size = int(
                        rest_of_msg.split(" ")[0] if " " in rest_of_msg else rest_of_msg
                    )

                    # lets break this range to the appropriate size
                    template = filter_params.copy()
                    template.pop("fromBlock")
                    template.pop("toBlock")

                    if isinstance(from_block, str):
                        from_block = int(from_block, 16)

                    if isinstance(to_block, str):
                        to_block = int(to_block, 16)

                    get_chunk = Semaphore(3)(self.trace_filter)
                    summand = max_range_size - 1
                    ranges = [[i, i + summand] for i in range(from_block, to_block, max_range_size)]
                    last_chunk = ranges[-1]
                    last_chunk[1] = min(last_chunk[1], to_block)
                    traces: List[List[FilterTrace]] = await igather(
                        get_chunk({**template, "fromBlock": start, "toBlock": end})
                        for start, end in ranges
                    )
                    return list(concat(traces))
            raise

        try:
            return json.decode(traces_bytes, type=decode_to, dec_hook=decode_hook)
        except ValidationError:
            if decode_to.__origin__ is not list:  # type: ignore [attr-defined]
                raise

            traces_raw = json.decode(traces_bytes, type=List[Raw])
            traces = []
            trace_cls = decode_to.__args__[0]  # type: ignore [attr-defined]
            decode = json.Decoder(type=trace_cls, dec_hook=decode_hook).decode
            for raw in traces_raw:
                try:
                    traces.append(decode(raw))
                except ValidationError as e:
                    e.args = *e.args, json.decode(raw)
                    raise

    async def trace_transaction(self, transaction_hash: str) -> List[FilterTrace]:
        """
        Returns all traces produced by a transaction.

        Args:
            transaction_hash: The hash of the transaction to trace.

        Example:
            >>> traces = await dank_mids.eth.trace_transaction('0x...')
        """
        return await self._trace_transaction(transaction_hash)

    _get_transaction_raw: MethodNoFormat[Callable[[HexStr], Awaitable[Raw]]] = MethodNoFormat(f"{RPC.eth_getTransactionByHash}_raw", mungers=[default_root_munger])  # type: ignore [arg-type,var-annotated]

    async def get_transaction(self, transaction_hash: HexStr) -> AnyTransaction:
        """
        Retrieves a transaction by its hash and attempts to decode it.

        Args:
            transaction_hash: The hash of the transaction to retrieve.

        Raises:
            ValidationError: If the transaction cannot be decoded into either
                             `Transaction` or `TransactionRLP` format.
        """
        transaction_bytes = await self._get_transaction_raw(transaction_hash)
        try:
            return decode_transaction(transaction_bytes)
        except ValidationError:
            try:
                return decode_transaction_rlp(transaction_bytes)
            except ValidationError as e:
                e.args = *e.args, json.decode(transaction_bytes)
                raise

    async def get_logs(
        self,
        *args,
        decode_to: Type[T] = Tuple[Log, ...],  # type: ignore [assignment]
        decode_hook: Optional[DecodeHook[T]] = _decode_hook,
        **kwargs,
    ) -> T:
        """
        Fetches logs and decodes them into the specified format.

        Args:
            *args: Additional positional arguments.
            decode_to: The class to which logs should be decoded.
            decode_hook: Hook function to assist in decoding.
            **kwargs: Additional keyword arguments.
        """
        return json.decode(
            await self._get_logs_raw(*args, **kwargs),
            type=decode_to,
            dec_hook=decode_hook,
        )

    meth = MethodNoFormat.default(RPC.eth_getTransactionReceipt)  # type: ignore [arg-type, var-annotated]
    if WEB3_MAJOR_VERSION >= 6:
        _transaction_receipt = meth
    else:
        _get_transaction_receipt = meth

    _get_transaction_receipt_raw = MethodNoFormat.default(
        cast(RPCEndpoint, f"{RPC.eth_getTransactionReceipt}_raw")
    )

    _get_block_raw: MethodNoFormat[Callable[..., Awaitable[Raw]]] = MethodNoFormat(
        method_choice_depends_on_args=select_method_for_block_identifier(
            **{k: f"{v}_raw" for k, v in _block_selectors.items()}
        ),
        mungers=[AsyncEth.get_block_munger],
    )
    _trace_filter = MethodNoFormat.default(cast(RPCEndpoint, f"{RPC.trace_filter}_raw"))
    _trace_transaction = MethodNoFormat.default(RPC.trace_transaction)


# TODO: this is super hacky, make it not.
bypass_formatters(DankEth)


class _Statusable(Struct, frozen=True):

    status: Status


class _Timestamped(Struct, frozen=True):  # type: ignore [call-arg]

    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated."""


decode_tiny_block: Final = json.Decoder(type=TinyBlock, dec_hook=_decode_hook).decode
decode_timestamped: Final = json.Decoder(
    type=_Timestamped, dec_hook=UnixTimestamp._decode_hook
).decode
decode_transaction: Final = json.Decoder(type=Transaction, dec_hook=_decode_hook).decode
decode_transaction_rlp: Final = json.Decoder(type=TransactionRLP, dec_hook=_decode_hook).decode
