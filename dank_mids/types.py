
import logging
import re
from cachetools.func import ttl_cache
from functools import cached_property
from time import time
from typing import (TYPE_CHECKING, Any, Callable, Coroutine, DefaultDict, Dict,
                    Iterable, Iterator, List, Literal, Mapping, NewType, Optional,
                    Set, Tuple, Type, TypedDict, TypeVar, Union, overload)

import msgspec
from eth_typing import ChecksumAddress
from eth_utils import to_checksum_address
from hexbytes import HexBytes
from web3._utils.rpc_abi import RPC
from web3._utils.method_formatters import PYTHONIC_RESULT_FORMATTERS
from web3.datastructures import AttributeDict
from web3.types import RPCEndpoint, RPCResponse

from dank_mids import constants, stats
from dank_mids._exceptions import BadResponse, ChainstackRateLimited, ExceedsMaxBatchSize, PayloadTooLarge

if TYPE_CHECKING:
    from dank_mids._requests import Multicall

ChainId = NewType("ChainId", int)
"""A type representing the unique integer identifier for a blockchain network."""

BlockId = NewType("BlockId", str)
"""A type representing the identifier for a specific block in the blockchain."""

BatchId = Union[int, str]
"""A type representing the identifier for a batch of operations, which can be either an integer or a string."""

Multicalls = Dict[BlockId, "Multicall"]
"""
A dictionary mapping BlockId to Multicall objects.

See Also:
    :class:`dank_mids._requests.Multicall`: The Multicall class used in this mapping.
"""

eth_callParams = TypedDict("eth_callParams", {"to": ChecksumAddress, "data": str})
"""
A typed dictionary representing the parameters for an eth_call.

See Also:
    :meth:`web3.eth.Eth.call`: Web3's method to perform a call without creating a transaction.
"""

OverrideParams = TypedDict("OverrideParams", {"code": str})
"""A typed dictionary representing override parameters."""

JsonrpcParams = List[Union[eth_callParams, BlockId, OverrideParams]]
"""A list of parameters for JSON-RPC calls, which should be eth_callParams, BlockId, and OverrideParams, in that order."""


# This type alias was introduced in web3 v5.28.0 but we like loose deps here so we recreate instead of import.
AsyncMiddleware = Callable[[RPCEndpoint, Any], Coroutine[Any, Any, RPCResponse]]
"""A type alias for asynchronous middleware functions."""

_list_of_stuff = List[Union[str, None, dict, list]]
"""A type alias for a list that can contain strings, None, dictionaries, or lists."""

_dict_of_stuff = Dict[str, Union[str, None, _list_of_stuff, Dict[str, Optional[Any]]]]
"""A type alias for a dictionary with string keys and values that can be strings, None, :obj:`_list_of_stuff`, or dictionaries with optional values."""

_nested_dict_of_stuff = Dict[str, Union[str, None, _list_of_stuff, _dict_of_stuff]]
"""A type alias for a nested dictionary structure."""

class _DictStruct(msgspec.Struct):
    """
    A base class that extends the :class:`~msgspec.Struct` class to provide dictionary-like access to struct fields.

    Allows iteration over the fields of a struct and provides a dictionary-like interface for retrieving values by field name.

    Example:
        >>> class MyStruct(_DictStruct):
        ...     field1: str
        ...     field2: int
        >>> s = MyStruct(field1="value", field2=42)
        >>> list(s.keys())
        ['field1', 'field2']
        >>> s['field1']
        'value'
    """

    def __bool__(self) -> bool:
        """A Struct will always exist."""
        return True
    
    def __contains__(self, key: str) -> bool:
        if key not in self._fields:
            return False
        try:
            getattr(self, key)
            return True
        except AttributeError:
            return False
    
    def __getitem__(self, attr: str) -> Any:
        """
        Lookup an attribute value via dictionary-style access.

        Args:
            attr: The name of the attribute to access.
        
        Raises:
            KeyError: If the provided key is not a member of the struct.

        Returns:
            The value of the attribute.
        """
        try:
            return getattr(self, attr)
        except AttributeError:
            raise KeyError(attr) from None
    
    def __getattribute__(self, attr: str) -> Any:
        """
        Get the value of an attribute, raising AttributeError if the value is :obj:`msgspec.UNSET`.
        
        Parameters:
            attr: The name of the attribute to fetch.

        Raises:
            AttributeError: If the value is :obj:`~msgspec.UNSET`.
    
        Returns:
            The value of the attribute.
        """
        value = super().__getattribute__(attr)
        if value is msgspec.UNSET:
            raise AttributeError(f"'{type(self).__name__}' object has no attribute '{attr}'")
        return value

    def __iter__(self) -> Iterator[str]:
        """
        Iterate thru the keys of the Struct.

        Yields:
            Struct key.
        """
        for field in self._fields:
            try:
                yield getattr(self, field)
            except AttributeError:
                # if value is msgspec.UNSET, an AttributeError is raised and we should skip.
                continue
    
    def __len__(self) -> int:
        """
        The number of keys in the Struct.
        
        Returns:
            The number of keys.
        """
        return len(list(self))

    def keys(self) -> Iterator[str]:
        """
        Returns an iterator over the field names of the struct.

        Returns:
            An iterator over the field names.
        """
        yield from self

    def items(self) -> Iterator[Tuple[str, Any]]:
        for key in self._fields:
            try:
                yield key, getattr(self, key)
            except AttributeError:
                # if value is msgspec.UNSET, an AttributeError is raised and we should skip.
                continue
    
    def values(self) -> Iterator[Any]:
        """
        Returns an iterator over the struct's field values.

        Returns:
            An iterator over the field values.
        """
        for key in self._fields:
            try:
                yield getattr(self, key)
            except AttributeError:
                # if value is msgspec.UNSET, an AttributeError is raised and we should skip.
                continue

    @property
    def _fields(self) -> Iterable[str]:
        return self.__struct_fields__

class PartialRequest(_DictStruct, frozen=True):  # type: ignore [call-arg]
    """
    Represents a partial JSON-RPC request. 
    
    While technially part of a request, we can successfully make requests to many nodes without including the `jsonrpc` field.
    
    This class leaves off the `jsonrpc` field reduce encoding burden and web traffic.

    This works with many but not all nodes.
    """

    method: str
    """The RPC method to be called."""

    id: Union[str, int]
    """The request identifier."""

    params: Optional[list] = None
    """The parameters for the RPC method call."""

    @property
    def data(self) -> bytes:
        return msgspec.json.encode(self)

class Request(PartialRequest):
    """
    Represents a complete JSON-RPC request.
    
    Inherits from PartialRequest and adds the JSON-RPC version.
    """

    jsonrpc: Literal["2.0"] = "2.0"
    """The JSON-RPC version, always set to "2.0"."""

class Error(_DictStruct, frozen=True):  # type: ignore [call-arg]
    """
    Represents an error in a JSON-RPC response.
    """

    code: int
    """The error code."""

    message: str
    """The error message."""

    data: Optional[Any] = msgspec.UNSET
    """Additional error data, if any."""

# some devving tools that will go away eventually
_dict_responses: Set[str] = set()
_str_responses: Set[str] = set()


class Address(str):
    def __new__(cls, address: str):
        return super().__new__(cls, to_checksum_address(address))

@ttl_cache(ttl=600)
def checksum(address: str) -> Address:
    return Address(address)

class uint(int):
    ...

class Log(_DictStruct, frozen=True):  # type: ignore [call-arg]
    _removed: Optional[msgspec.Raw]
    _logIndex: Optional[msgspec.Raw]
    _transactionIndex: Optional[msgspec.Raw]
    _transactionHash: msgspec.Raw
    _blockHash: Optional[msgspec.Raw]
    _blockNumber: Optional[msgspec.Raw]
    _address: Optional[msgspec.Raw]
    _data: Optional[msgspec.Raw]
    _topics: Optional[msgspec.Raw]

    @cached_property
    def topics(self) -> Optional[List[HexBytes]]:
        if self._topics:
            return msgspec.json.decode(self._topics, typ=Optional[List[HexBytes]])
    @cached_property
    def data(self) -> Optional[List[HexBytes]]:
        if self._data:
            return msgspec.json.decode(self._data, typ=Optional[HexBytes])
    @cached_property
    def address(self) -> Optional[List[HexBytes]]:
        if self._address:
            return msgspec.json.decode(self._address, typ=Optional[Address])
    @cached_property
    def removed(self) -> Optional[bool]:
        if self._removed:
            return msgspec.json.decode(self._removed, typ=Optional[bool])
    @cached_property
    def logIndex(self) -> Optional[uint]:
        if self._logIndex:
            return msgspec.json.decode(self._logIndex, typ=Optional[uint])
    @cached_property
    def transactionIndex(self) -> Optional[uint]:
        if self._transactionIndex:
            return msgspec.json.decode(self._transactionIndex, typ=Optional[uint])
    @cached_property
    def transactionHash(self) -> HexBytes:
        return msgspec.json.decode(self._transactionHash, typ=HexBytes)
    @cached_property
    def blockHash(self) -> Optional[HexBytes]:
        if self._blockHash:
            return msgspec.json.decode(self._blockHash, typ=Optional[HexBytes])
    @cached_property
    def blockNumber(self) -> Optional[uint]:
        if self._blockNumber:
            return msgspec.json.decode(self._blockNumber, typ=Optional[uint])
    
    @cached_property
    def _fields(self) -> List[str]:
        return [field[1:] for field in self.__struct_fields__]


class AccessListEntry(_DictStruct, frozen=True):  # type: ignore [call-arg]
    address: Address
    storageKeys: List[HexBytes]

class _TransactionBase(_DictStruct, frozen=True):  # type: ignore [call-arg]
    # `type` field is omitted since it's used in the tagged union
    nonce: uint
    to: Optional[Address]  # null for contract deployments
    gas: uint
    value: uint
    input: HexBytes
    chainId: Optional[uint]  # null for v in {27, 28}, otherwise derived from eip-155
    # details
    blockHash: HexBytes
    blockNumber: uint
    sender: Address = msgspec.field(name="from")
    hash: HexBytes
    transactionIndex: uint
    # signature
    v: uint
    r: HexBytes
    s: HexBytes

class TransactionLegacy(_TransactionBase, tag="0x0"):  # type: ignore [call-arg]
    gasPrice: uint

class Transaction2930(_TransactionBase, tag="0x1"):  # type: ignore [call-arg]
    gasPrice: uint
    accessList: Optional[List[AccessListEntry]] = msgspec.UNSET

class Transaction1559(_TransactionBase, tag="0x2"):  # type: ignore [call-arg]
    maxFeePerGas: uint
    maxPriorityFeePerGas: uint
    accessList: Optional[List[AccessListEntry]] = msgspec.UNSET

Transaction = Union[TransactionLegacy, Transaction2930, Transaction1559]


class FeeStats(_DictStruct, frozen=True):  # type: ignore [call-arg]
    """Arbitrum includes this in the `feeStats` field of a tx receipt."""
    l1Calldata: uint
    l2Storage: uint
    l1Transaction: uint
    l2Computation: uint

class ArbitrumFeeStats(_DictStruct, frozen=True):  # type: ignore [call-arg]
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

class TransactionReceipt(_DictStruct, frozen=True, omit_defaults=True):  # type: ignore [call-arg]
    transactionHash: HexBytes
    blockHash: HexBytes
    blockNumber: uint
    logsBloom: HexBytes
    contractAddress: Optional[Address]
    transactionIndex: Optional[uint]
    #returnCode: str
    effectiveGasPrice: uint
    gasUsed: uint
    cumulativeGasUsed: uint
    #returnData: str
    logs: List[Log]

    # These fields are only present on Arbitrum.
    l1BlockNumber: uint = msgspec.UNSET
    """This field is only present on Arbitrum."""
    l1InboxBatchInfo: Optional[HexBytes] = msgspec.UNSET
    """This field is only present on Arbitrum."""
    feeStats: ArbitrumFeeStats = msgspec.UNSET
    """This field is only present on Arbitrum."""

class StakingWithdrawal(_DictStruct, frozen=True):  # type: ignore [call-arg]
    """A Struct representing an Ethereum staking withdrawal."""
    index: str

    amount: str = msgspec.UNSET
    """This field is not always present."""

    address: str = msgspec.UNSET
    """This field is not always present."""

    validatorIndex: str = msgspec.UNSET
    """This field is not always present."""

class _Timestampped(_DictStruct, frozen=True):  # type: ignore [call-arg]
    timestamp: str

class _BlockHeaderBase(_Timestampped, frozen=True):  # type: ignore [call-arg]
    parentHash: str

class Block(_BlockHeaderBase, frozen=True):  # type: ignore [call-arg]
    sha3Uncles: str
    miner: str
    stateRoot: str
    transactionsRoot: str
    receiptsRoot: str
    logsBloom: str
    number: str
    gasLimit: str
    gasUsed: str
    timestamp: str
    extraData: str
    mixHash: str
    nonce: str
    size: str
    uncles: List[str]
    transactions: List[Union[str, Transaction]]
    
    totalDifficulty: Optional[str] = msgspec.UNSET
    """This field is only present on Ethereum."""

    withdrawals: List[StakingWithdrawal] = msgspec.UNSET
    """This field is only present on Ethereum."""
    
class ErigonHeader(_BlockHeaderBase, frozen=True):  # type: ignore [call-arg]
    uncleHash: HexBytes
    coinbase: Address
    root: HexBytes
    difficulty: uint

_RETURN_TYPES = {
    "eth_call": HexBytes,
    "eth_chainId": uint,
    "eth_getCode": HexBytes,
    "eth_getLogs": List[Log],
    "eth_getBalance": uint,
    "eth_blockNumber": uint,
    "eth_accounts": List[Address],
    "eth_getBlockByNumber": Block,
    "eth_getTransactionCount": uint,
    "eth_getTransactionByHash": Transaction,
    "eth_getTransactionReceipt": TransactionReceipt, 
    #"erigon_getHeaderByNumber": Dict[str, Union[str, int, bool, None]],
    "erigon_getHeaderByNumber": ErigonHeader,
}
"""
A dictionary mapping RPC method names to their expected return types.
Used to enable more efficient decoding and validation of RPC responses.
"""

decoder_logger = logging.getLogger('dank_mids.decoder')

_chainstack_429_msg = "You've exceeded the RPS limit available on the current plan."

class PartialResponse(_DictStruct, frozen=True):
    """
    Represents a partial JSON-RPC response. 
    
    We use these to more efficiently decode responses from the node.
    """

    result: msgspec.Raw = None  # type: ignore
    """The result of the RPC call, if successful."""

    error: Optional[Error] = None
    """The error object, if the call failed."""

    @property
    def exception(self) -> Exception:
        """If the rpc response contains an 'error' field, returns a specialized exception for the specified rpc error."""
        if self.error is None:
            raise AttributeError(f"{self} did not error.")
        return (
            PayloadTooLarge(self) if self.payload_too_large
            else ExceedsMaxBatchSize(self) if re.search(r'batch limit (\d+) exceeded', self.error.message)
            else TypeError(self.error.message, "DANKMIDS NOTE: You're probably passing what should be an integer type as a string type. The usual culprit is a block number.") if self.error.message == 'invalid argument 1: hex string without 0x prefix'
            # chainstack doesnt return a response with status code 429 when we reach rate limits, so we need to handle it specifically here instead of in the usual place
            else ChainstackRateLimited(self) if _chainstack_429_msg in self.error.message
            else BadResponse(self)
        )
    
    @property
    def payload_too_large(self) -> bool:
        return any(err in self.error.message for err in constants.TOO_MUCH_DATA_ERRS)  # type: ignore [union-attr]
        
    def to_dict(self, method: Optional[RPCEndpoint] = None) -> RPCResponse:  # type: ignore [override]
        """Returns a complete dictionary representation of this response ``Struct``."""
        data: RPCResponse = {}
        for key, value in self.items():
            if value is None:
                continue
            if key == "result":
                attr = self.decode_result(method=method, caller=self)
            data[key] = AttributeDict(attr) if isinstance(attr, dict) else attr  # type: ignore [literal-required]
        return data

    def decode_result(self, method: Optional[RPCEndpoint] = None, *, caller = None) -> Union[HexBytes, uint, AttributeDict]:
        # NOTE: These must be added to the `_RETURN_TYPES` constant above manually
        if method and (typ := _RETURN_TYPES.get(method)):
            if method in ["eth_call", "eth_blockNumber", "eth_getCode", "eth_getBlockByNumber", "eth_getTransactionReceipt", "eth_getTransactionCount", "eth_getBalance", "eth_chainId", "erigon_getHeaderByNumber"]:
                try:
                    return msgspec.json.decode(self.result, type=typ, dec_hook=_decode_hook)
                except (msgspec.ValidationError, TypeError) as e:
                    raise ValueError(
                        e,
                        f'method: {method}  result: {msgspec.json.decode(self.result)}',
                    ).with_traceback(e.__traceback__) from e
            try:
                start = time()
                decoded = msgspec.json.decode(self.result, type=typ, dec_hook=_decode_hook)
                if caller:
                    stats.log_duration(f'decoding {type(caller)} {method}', start)
                return AttributeDict(decoded) if isinstance(decoded, dict) else decoded
            except (msgspec.ValidationError, TypeError) as e:
                stats.logger.log_validation_error(self, e)

        # We have some semi-smart logic for providing decoder hints even if method not in `_RETURN_TYPES`
        if method:
            try:
                if method in _dict_responses:
                    decoded = AttributeDict(msgspec.json.decode(self.result, type=_nested_dict_of_stuff))
                    stats.logger.log_types(method, decoded)
                    return decoded
                elif method in _str_responses:
                    # TODO: finish adding methods and get rid of this
                    stats.logger.devhint('Must add `%s: str` to `_RETURN_TYPES`', method)
                    return msgspec.json.decode(self.result, type=str)
            except (msgspec.ValidationError, TypeError) as e:
                stats.logger.log_validation_error(method, e)

        # In this case we can provide no hints, let's let the decoder figure it out
        decoded = msgspec.json.decode(self.result)
        if isinstance(decoded, str):
            if method:
                _str_responses.add(method)
            return decoded
        elif isinstance(decoded, dict):
            if method:
                _dict_responses.add(method)
            return AttributeDict(decoded)
        elif isinstance(decoded, list):
            if method is None:
                return decoded
        raise TypeError(f"type {type(decoded)} is not supported.  method: {method}  decoded: {decoded}")
        

class Response(PartialResponse):
    """
    Represents a complete JSON-RPC response.
    
    Inherits from PartialResponse and adds the response identifier and JSON-RPC version.
    """

    id: Optional[Union[str, int]] = None
    """The response identifier, matching the request."""

    jsonrpc: Literal["2.0"] = "2.0"
    """The JSON-RPC version, always set to "2.0"."""

class RawResponse:
    """
    Wraps a Raw object that we know represents a Response with a `decode` helper method.
    A `RawResponse` is a properly shaped response for one rpc call, received back from a jsonrpc batch request.
    They represent either a successful or a failed response, stored as pre-decoded bytes.
    """
    def __init__(self, raw: msgspec.Raw) -> None:
        self._raw = raw
        """The `msgspec.Raw` object wrapped by this wrapper."""
    @overload
    def decode(self, partial: Literal[True]) -> PartialResponse:...
    @overload
    def decode(self, partial: Literal[False] = False) -> Response:...
    def decode(self, partial: bool = False) -> Union[Response, PartialResponse]:
        """Decode the wrapped `msgspec.Raw` object into a `Response` or a `PartialResponse`."""
        try:
            return msgspec.json.decode(self._raw, type=PartialResponse if partial else Response)
        except (msgspec.ValidationError, TypeError) as e:
            e.args = (*e.args, f"decoded: {msgspec.json.decode(self._raw)}")
            raise

JSONRPCBatchRequest = List[Request]
# NOTE: A PartialResponse result implies a failure response from the rpc.
JSONRPCBatchResponse = Union[List[RawResponse], PartialResponse]
# We need this for proper decoding.
JSONRPCBatchResponseRaw = Union[List[msgspec.Raw], PartialResponse]

def _encode_hook(obj: Any) -> Any:
    """
    A hook function for encoding objects during JSON serialization.

    Args:
        obj: The object to encode.

    Returns:
        The encoded object.

    Raises:
        NotImplementedError: If the object type is not supported for encoding.
    """
    if isinstance(obj, AttributeDict):
        return dict(obj)
    raise NotImplementedError(type(obj))

def _decode_hook(typ: Type, obj: str):
    if typ is HexBytes:
        return HexBytes(obj)
    elif typ is Address:
        return checksum(obj)
    elif typ is uint:
        return uint(obj, 16)
    raise TypeError(typ)