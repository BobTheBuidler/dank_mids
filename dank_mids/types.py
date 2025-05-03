import re
from functools import cached_property
from logging import getLogger
from time import time
from typing import (
    TYPE_CHECKING,
    Any,
    Callable,
    ClassVar,
    Coroutine,
    Dict,
    Final,
    List,
    Literal,
    Mapping,
    NewType,
    Optional,
    Set,
    Tuple,
    Type,
    TypedDict,
    TypeVar,
    Union,
    overload,
)

import evmspec
from dictstruct import DictStruct
from eth_typing import ChecksumAddress, HexStr
from eth_utils.toolz import valmap
from evmspec.data import Address, BlockNumber, ChainId, Wei, uint, _decode_hook
from evmspec.structs.block import BaseBlock, Block, MinedBlock, ShanghaiCapellaBlock
from evmspec.structs.log import Log
from hexbytes import HexBytes
from msgspec import UNSET, Raw, ValidationError, field
from msgspec.json import Decoder
from msgspec.json import decode as json_decode
from msgspec.json import encode as json_encode
from web3.datastructures import AttributeDict
from web3.types import RPCEndpoint, RPCError, RPCResponse

from dank_mids import constants, stats
from dank_mids._exceptions import (
    BadResponse,
    ChainstackRateLimitError,
    ExceedsMaxBatchSize,
    ExecutionReverted,
    OutOfGas,
    PayloadTooLarge,
    QuiknodeRateLimitError,
)

if TYPE_CHECKING:
    from dank_mids._requests import Multicall


T = TypeVar("T")


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


decode_nested_dict: Final = Decoder(type=_nested_dict_of_stuff).decode


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
        return json_encode(self, enc_hook=_encode_hook)


class Request(PartialRequest):
    """
    Represents a complete JSON-RPC request.

    Inherits from PartialRequest and adds the JSON-RPC version.
    """

    jsonrpc: Literal["2.0"] = "2.0"
    """The JSON-RPC version, always set to "2.0"."""

    @property
    def data(self) -> bytes:
        # we have to do some hacky stuff because omit_defaults kwarg on PartialRequest
        # is preventing jsonrpc field from being included in the encoded bytes
        encoded_omit_defaults = json_encode(self, enc_hook=_encode_hook)
        return encoded_omit_defaults[:-1] + b',"jsonrpc":"2.0"}'


class RPCErrorWithContext(RPCError):
    dank_mids_added_context: PartialRequest


_getattribute = object.__getattribute__


class ChainstackRateLimitContext(DictStruct, frozen=True):  # type: ignore [call-arg]
    """Chainstack doesn't use status code 429 for rate limiting, they attach one of these objects to a 200 response."""

    logger: ClassVar = getLogger("dank_mids.chainstack")
    _try_again_in: str = field(name="try_again_in")

    @property
    def try_again_in(self) -> float:
        """
        Calculates the time to wait before retrying the request.

        Returns:
            The number of seconds to wait before retrying.

        Raises:
            NotImplementedError: If the time string is in an unrecognized format.
        """
        error: Error = self.response.error
        decimal_string = error.data.try_again_in
        if "ms" in decimal_string:
            ms = float(decimal_string[:-2])
            self.logger.warning("rate limited by chainstack, retrying in %sms", ms)
            return ms / 1000
        elif "µs" in decimal_string:
            µs = float(decimal_string[:-2])
            self.logger.warning("rate limited by chainstack, retrying in %sµs", µs)
            return µs / 1000000
        raise NotImplementedError(f"must define a handler for decimal_string {decimal_string}")


class Error(DictStruct, frozen=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Represents an error in a JSON-RPC response.
    """

    code: int
    """The error code."""

    message: str
    """The error message."""

    # evm spec
    data: Optional[Union[str, ChainstackRateLimitContext]] = UNSET  # type: ignore [assignment]
    """
    Additional error data, if any.
    
    EVM specs say it should be a string, but some providers will return a dictionary here with even more context.
    """

    @overload
    def to_dict(self, *, context: None = None) -> RPCError: ...
    @overload
    def to_dict(self, *, context: PartialRequest) -> RPCErrorWithContext: ...
    def to_dict(self, *, context: Optional[PartialRequest] = None) -> RPCError:
        data = _getattribute(self, "data")
        if context is None:
            if data is UNSET:
                return RPCError(code=self.code, message=self.message)
            else:
                return RPCError(code=self.code, message=self.message, data=data)
        elif data is UNSET:
            return RPCErrorWithContext(
                code=self.code, message=self.message, dank_mids_added_context=context
            )
        else:
            return RPCErrorWithContext(
                code=self.code, message=self.message, data=data, dank_mids_added_context=context
            )


# some devving tools that will go away eventually
_dict_responses: Set[str] = set()
_str_responses: Set[str] = set()


_RETURN_TYPES = {
    "eth_call": HexBytes,
    "eth_chainId": ChainId,
    "eth_getCode": HexBytes,
    "eth_getLogs": List[Log],
    "eth_getBalance": Wei,
    "eth_blockNumber": BlockNumber,
    "eth_accounts": List[Address],
    "eth_getBlockByNumber": Block,
    "eth_getTransactionCount": uint,
    "eth_getTransactionByHash": evmspec.Transaction,
    "eth_getTransactionReceipt": evmspec.FullTransactionReceipt,
    "erigon_getHeaderByNumber": evmspec.ErigonBlockHeader,
    "trace_filter": List[evmspec.FilterTrace],
    "trace_transaction": List[evmspec.FilterTrace],
}
"""
A dictionary mapping RPC method names to their expected return types.
Used to enable more efficient decoding and validation of RPC responses.
"""


_CHAINSTACK_429_ERR_MSG: Final = "You've exceeded the RPS limit available on the current plan."
_QUICKNODE_429_ERR_MSG: Final = (
    # the actual rate limit can vary but the err message always ends like this
    "/second request limit reached - reduce calls per second or upgrade your account at quicknode.com",
)


class PartialResponse(DictStruct, frozen=True, omit_defaults=True, repr_omit_defaults=True):
    """
    Represents a partial JSON-RPC response.

    We use these to more efficiently decode responses from the node.
    """

    result: Raw = None  # type: ignore
    """The result of the RPC call, if successful."""

    error: Optional[Error] = None
    """The error object, if the call failed."""

    @cached_property
    def exception(self) -> Exception:
        """If the rpc response contains an 'error' field, returns a specialized exception for the specified rpc error."""
        if self.error is None:
            raise AttributeError(f"{self} did not error.")

        message = self.error.message
        if "out of gas" in message:
            return OutOfGas(self)
        if "execution reverted" in message or message in {
            "invalid opcode: INVALID",
            "EVM error: InvalidFEOpcode",
        }:
            return ExecutionReverted(self)
        if self.payload_too_large:
            return PayloadTooLarge(self)
        if re.search(r"batch limit (\d+) exceeded", message):
            return ExceedsMaxBatchSize(self)
        if message == "invalid argument 1: hex string without 0x prefix":
            return TypeError(
                message,
                "DANKMIDS NOTE: You're probably passing what should be an integer type as a string type. "
                "The usual culprit is a block number.",
            )
        # chainstack doesnt return a response with status code 429 when we reach rate limits, so we need to handle it specifically here instead of in the usual place
        if _CHAINSTACK_429_ERR_MSG in message:
            return ChainstackRateLimitError(self)
        # quicknode doesnt return a response with status code 429 when we reach rate limits, so we need to handle it specifically here instead of in the usual place
        if message.endswith(_QUICKNODE_429_ERR_MSG):
            return QuiknodeRateLimitError(self)
        return BadResponse(self)

    @property
    def payload_too_large(self) -> bool:
        return any(map(self.error.message.__contains__, constants.TOO_MUCH_DATA_ERRS))

    def to_dict(self, method: Optional[RPCEndpoint] = None) -> RPCResponse:  # type: ignore [override]
        """Returns a complete dictionary representation of this response ``Struct``."""
        data: RPCResponse = {
            key: self.decode_result(method=method, caller=self) if key == "result" else value
            for key, value in self.items()
            if value is not None
        }
        return data

    def decode_result(
        self, method: Optional[RPCEndpoint] = None, *, caller=None
    ) -> Union[HexBytes, Wei, uint, ChainId, BlockNumber, AttributeDict]:
        # NOTE: These must be added to the `_RETURN_TYPES` constant above manually
        if method and (typ := _RETURN_TYPES.get(method)):
            if method in (
                "eth_call",
                "eth_blockNumber",
                "eth_getCode",
                "eth_getBlockByNumber",
                "eth_getTransactionReceipt",
                "eth_getTransactionCount",
                "eth_getBalance",
                "eth_chainId",
                "erigon_getHeaderByNumber",
            ):
                try:
                    return better_decode(
                        self.result, type=typ, dec_hook=_decode_hook, method=method
                    )
                except Exception as e:
                    if typ is not Block:
                        raise

                    if e.args[0] == "Object contains unknown field `totalDifficulty`":
                        try:
                            # NOTE should we do this??
                            # _RETURN_TYPES[method] = MinedBlock
                            return better_decode(
                                self.result, type=MinedBlock, dec_hook=_decode_hook, method=method
                            )
                        except ValidationError as e2:
                            if e2.args[0] != "Object contains unknown field `baseFeePerGas`":
                                raise
                            result = better_decode(
                                self.result, type=BaseBlock, dec_hook=_decode_hook, method=method
                            )
                            _RETURN_TYPES[method] = BaseBlock  # all blocks on base are BaseBlocks
                            return result

                    elif e.args[0] == "Object contains unknown field `withdrawals`":
                        typ = ShanghaiCapellaBlock

                    elif e.args[0] == "Object contains unknown field `difficulty`":
                        # I've only seen this on OP stack so far, not sure what difficulty means for their chain
                        typ = BaseBlock

                    else:
                        raise

                    return better_decode(
                        self.result, type=typ, dec_hook=_decode_hook, method=method
                    )

            start = time()
            try:
                decoded = better_decode(self.result, type=typ, dec_hook=_decode_hook, method=method)
            except (ValidationError, TypeError) as e:
                stats.logger.log_validation_error(self, e)
                raise

            if caller:
                stats.log_duration(f"decoding {type(caller)} {method}", start)
            return decoded

        # We have some semi-smart logic for providing decoder hints even if method not in `_RETURN_TYPES`
        if method:
            try:
                if method in _dict_responses:
                    decoded = AttributeDict(decode_nested_dict(self.result))
                    stats.logger.log_types(method, decoded)
                    return decoded
                elif method in _str_responses:
                    # TODO: finish adding methods and get rid of this
                    stats.logger.devhint("Must add `%s: str` to `_RETURN_TYPES`", method)
                    return json_decode(self.result, type=str)
            except (ValidationError, TypeError) as e:
                stats.logger.log_validation_error(method, e)

        # In this case we can provide no hints, let's let the decoder figure it out
        decoded = json_decode(self.result)
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
        raise TypeError(
            f"type {type(decoded)} is not supported.  method: {method}  decoded: {decoded}"
        )


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
    def decode(self, partial: Literal[True]) -> PartialResponse: ...
    @overload
    def decode(self, partial: Literal[False] = False) -> Response: ...
    def decode(self, partial: bool = False) -> Union[Response, PartialResponse]:
        """Decode the wrapped :class:`Raw` object into a :class:`Response` or a :class:`PartialResponse`."""
        return better_decode(self._raw, type=PartialResponse if partial else Response)

    __slots__ = ("_raw",)


MulticallChunk = Tuple[ChecksumAddress, HexBytes]

JSONRPCBatchRequest = List[Request]
# NOTE: A PartialResponse result implies a failure response from the rpc.
JSONRPCBatchResponse = Union[List[RawResponse], PartialResponse]
# We need this for proper decoding.
JSONRPCBatchResponseRaw = Union[List[Raw], PartialResponse]


StrEncodable = Union[ChecksumAddress, HexStr]
Encodable = Union[int, StrEncodable, HexBytes, bytes]

RpcThing = Union[HexStr, List[HexStr], Dict[str, HexStr]]


def _encode_hook(obj: Encodable) -> RpcThing:
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
        return hex(int(obj))  # type: ignore [return-value]
    except TypeError as e:
        # I put this here for AttributeDicts which come from eth_getLogs params
        # but I check for mapping so it can work with user custom classes
        if not isinstance(obj, Mapping):
            raise TypeError(obj, type(obj)) from e
        return valmap(_rudimentary_encode_dict_value, obj)
    except ValueError as e:
        # NOTE: The error is probably this if `obj` is a string:
        # ValueError: invalid literal for int() with base 10:"""
        if not isinstance(obj, HexBytes):
            e.args = *e.args, obj, type(obj)
            raise ValueError(obj, type(obj)) from e
        return obj.hex()  # type: ignore [return-value]


def _rudimentary_encode_dict_value(value):
    # I dont think this needs to be robust, time will tell
    return hex(value) if isinstance(value, int) else value


def better_decode(
    data: Raw,
    *,
    type: Optional[Type[T]] = None,
    dec_hook: Optional[Callable[[Type, object], T]] = None,
    method: Optional[str] = None,
) -> T:
    try:
        return json_decode(data, type=type, dec_hook=dec_hook)
    except (ValidationError, TypeError) as e:
        extra_args = [
            f"type: {type.__module__}.{type.__qualname__}",
            f"result: {json_decode(data)}",
        ]
        if method:
            extra_args.insert(0, f"method: {method}")
        e.args = (*e.args, *extra_args)
        raise
