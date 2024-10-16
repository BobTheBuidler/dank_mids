
import logging
import re
from functools import cached_property
from time import time
from typing import (TYPE_CHECKING, Any, Callable, Coroutine, DefaultDict, Dict,
                    Iterable, Iterator, List, Literal, Mapping, NewType, NoReturn,
                    Optional, Set, Tuple, Type, TypedDict, TypeVar, Union, overload)

from eth_typing import ChecksumAddress
from hexbytes import HexBytes
from msgspec import UNSET, Raw, ValidationError, json
from web3.datastructures import AttributeDict
from web3.types import RPCEndpoint, RPCResponse

from dank_mids import constants, stats
from dank_mids._exceptions import BadResponse, ChainstackRateLimited, ExceedsMaxBatchSize, PayloadTooLarge
from dank_mids.structs import Block, DictStruct, ErigonHeader, FilterTrace, Log, Transaction, TransactionReceipt
from dank_mids.structs.data import Address, uint, _decode_hook

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
    

class PartialRequest(DictStruct, frozen=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
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
        return json.encode(self)

class Request(PartialRequest):
    """
    Represents a complete JSON-RPC request.
    
    Inherits from PartialRequest and adds the JSON-RPC version.
    """

    jsonrpc: Literal["2.0"] = "2.0"
    """The JSON-RPC version, always set to "2.0"."""

class Error(DictStruct, frozen=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Represents an error in a JSON-RPC response.
    """

    code: int
    """The error code."""

    message: str
    """The error message."""

    data: Optional[Any] = UNSET
    """Additional error data, if any."""

# some devving tools that will go away eventually
_dict_responses: Set[str] = set()
_str_responses: Set[str] = set()


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
    "trace_filter": List[FilterTrace],
    "trace_transaction": List[FilterTrace],
}
"""
A dictionary mapping RPC method names to their expected return types.
Used to enable more efficient decoding and validation of RPC responses.
"""

decoder_logger = logging.getLogger('dank_mids.decoder')

_chainstack_429_msg = "You've exceeded the RPS limit available on the current plan."

class PartialResponse(DictStruct, frozen=True, omit_defaults=True, repr_omit_defaults=True):
    """
    Represents a partial JSON-RPC response. 
    
    We use these to more efficiently decode responses from the node.
    """

    result: Raw = None  # type: ignore
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
        data: RPCResponse = {
            key: self.decode_result(method=method, caller=self) if key == "result" else value
            for key, value in self.items()
            if value is not None
        }
        return data

    def decode_result(self, method: Optional[RPCEndpoint] = None, *, caller = None) -> Union[HexBytes, uint, AttributeDict]:
        # NOTE: These must be added to the `_RETURN_TYPES` constant above manually
        if method and (typ := _RETURN_TYPES.get(method)):
            if method in ["eth_call", "eth_blockNumber", "eth_getCode", "eth_getBlockByNumber", "eth_getTransactionReceipt", "eth_getTransactionCount", "eth_getBalance", "eth_chainId", "erigon_getHeaderByNumber"]:
                try:
                    return json.decode(self.result, type=typ, dec_hook=_decode_hook)
                except (ValidationError, TypeError) as e:
                    raise ValueError(
                        e,
                        f'method: {method}  result: {json.decode(self.result)}',
                    ).with_traceback(e.__traceback__) from e
            try:
                start = time()
                decoded = json.decode(self.result, type=typ, dec_hook=_decode_hook)
                if caller:
                    stats.log_duration(f'decoding {type(caller)} {method}', start)
                return AttributeDict(decoded) if isinstance(decoded, dict) else decoded
            except (ValidationError, TypeError) as e:
                stats.logger.log_validation_error(self, e)
                raise

        # We have some semi-smart logic for providing decoder hints even if method not in `_RETURN_TYPES`
        if method:
            try:
                if method in _dict_responses:
                    decoded = AttributeDict(json.decode(self.result, type=_nested_dict_of_stuff))
                    stats.logger.log_types(method, decoded)
                    return decoded
                elif method in _str_responses:
                    # TODO: finish adding methods and get rid of this
                    stats.logger.devhint('Must add `%s: str` to `_RETURN_TYPES`', method)
                    return json.decode(self.result, type=str)
            except (ValidationError, TypeError) as e:
                stats.logger.log_validation_error(method, e)

        # In this case we can provide no hints, let's let the decoder figure it out
        decoded = json.decode(self.result)
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
        

class Response(PartialResponse, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
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
    def __init__(self, raw: Raw) -> None:
        self._raw = raw
        """The :class:`Raw` object wrapped by this wrapper."""
    @overload
    def decode(self, partial: Literal[True]) -> PartialResponse:...
    @overload
    def decode(self, partial: Literal[False] = False) -> Response:...
    def decode(self, partial: bool = False) -> Union[Response, PartialResponse]:
        """Decode the wrapped :class:`Raw` object into a :class:`Response` or a :class:`PartialResponse`."""
        try:
            return json.decode(self._raw, type=PartialResponse if partial else Response)
        except (ValidationError, TypeError) as e:
            e.args = (*e.args, f"decoded: {json.decode(self._raw)}")
            raise

JSONRPCBatchRequest = List[Request]
# NOTE: A PartialResponse result implies a failure response from the rpc.
JSONRPCBatchResponse = Union[List[RawResponse], PartialResponse]
# We need this for proper decoding.
JSONRPCBatchResponseRaw = Union[List[Raw], PartialResponse]

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
    try:
        # We just assume `obj` is an int subclass instead of performing if checks because it usually is.
        return int(obj)
    except TypeError as e:
        if isinstance(obj, AttributeDict):
            return dict(obj)
        raise NotImplementedError(obj, type(obj)) from e
    except ValueError as e:
        # NOTE: The error is probably this if `obj` is a string:
        # ValueError: invalid literal for int() with base 10:"""
        if isinstance(obj, HexBytes):
            return str(obj)
        raise NotImplementedError(obj, type(obj)) from e

