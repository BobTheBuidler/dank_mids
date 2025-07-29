from typing import (
    TYPE_CHECKING,
    Any,
    AnyStr,
    Callable,
    Dict,
    Final,
    Iterable,
    List,
    Literal,
    Mapping,
    Optional,
    Union,
    Tuple,
    Type,
    TypeVar,
    Union,
    final,
    overload,
)

import hexbytes
import msgspec
from eth_abi import decoding
from eth_abi.abi import default_codec
from eth_abi.encoding import DynamicArrayEncoder, TupleEncoder
from eth_typing import ChecksumAddress, HexStr
from evmspec.data import Address
from msgspec.json import Decoder, Encoder

if TYPE_CHECKING:
    from dank_mids import types


# due to a circ import issue we will import these later
PartialResponse: Optional[Type["types.PartialResponse"]] = None
Request: Optional[Type["types.Request"]] = None
Response: Optional[Type["types.Response"]] = None
better_decode: Optional[Callable[..., Any]] = None  # type: ignore [type-arg]


__T = TypeVar("__T")


StrEncodable = Union[ChecksumAddress, HexStr, Address]
Encodable = Union[int, StrEncodable, hexbytes.HexBytes, bytes]

RpcThing = Union[HexStr, List[HexStr], Dict[str, HexStr]]


MulticallChunk = Union[
    Tuple[ChecksumAddress, hexbytes.HexBytes],
    List[Union[ChecksumAddress, hexbytes.HexBytes]],
]
MulticallEncoder = Callable[[Tuple[bool, Iterable[MulticallChunk]]], bytes]

DecodedMulticall = Tuple[int, int, Tuple[Tuple["Success", bytes], ...]]
MulticallDecoder = Callable[..., DecodedMulticall]


JSONRPCBatchRequest = List["types.Request"]
# NOTE: A PartialResponse result implies a failure response from the rpc.
JSONRPCBatchResponse = Union[List["RawResponse"], "types.PartialResponse"]
BatchDecoder = Callable[[Union[str, bytes]], Union[List[msgspec.Raw], "types.PartialResponse"]]

# these compile to C constants
HexBytes: Final = hexbytes.HexBytes
Raw: Final = msgspec.Raw
ContextFramesBytesIO: Final = decoding.ContextFramesBytesIO
DecodeError: Final = msgspec.DecodeError

decode_string: Final = Decoder(type=str).decode
_decode_raw: Final = Decoder(type=Raw).decode
# due to a forward reference issue we will populate this later
_decode_batch: Optional[BatchDecoder] = None


@final
class RawResponse:
    """
    Wraps a Raw object that we know represents a Response with a `decode` helper method.
    A `RawResponse` is a properly shaped response for one rpc call, received back from a jsonrpc batch request.
    They represent either a successful or a failed response, stored as pre-decoded bytes.
    """

    def __init__(self, raw: msgspec.Raw) -> None:
        self._raw: Final = raw
        """The :class:`Raw` object wrapped by this wrapper."""

    @overload
    def decode(self, partial: Literal[True]) -> "types.PartialResponse": ...
    @overload
    def decode(self, partial: Literal[False] = False) -> "types.Response": ...
    def decode(self, partial: bool = False) -> Union["types.Response", "types.PartialResponse"]:
        """Decode the wrapped :class:`Raw` object into a :class:`Response` or a :class:`PartialResponse`."""
        if better_decode is None:
            __import_from_types()
        return better_decode(self._raw, type=PartialResponse if partial else Response)  # type: ignore [no-any-return, misc]

    __slots__ = ("_raw",)


def decode_raw(data: AnyStr) -> RawResponse:
    """
    Decode json-encoded bytes into a `msgspec.Raw` object.

    Args:
        data: The json-encoded bytes to decode.

    Returns:
        The decoded data wrapped in a RawResponse object.
    """
    try:
        return RawResponse(_decode_raw(data))
    except DecodeError as e:
        e.args = *e.args, data  # type: ignore [has-type]
        raise


def decode_jsonrpc_batch(data: AnyStr) -> Union["types.PartialResponse", List[RawResponse]]:
    """
    Decode json-encoded bytes into a list of response structs, or a single error response struct if applicable.

    Args:
        data: The json-encoded bytes that represent the batch response data.

    Returns:
        Either a PartialResponse if there's an error, or a list of RawResponse objects.
    """
    if _decode_batch is None:
        __make_decode_batch()

    decoded = _decode_batch(data)  # type: ignore [misc]
    return [RawResponse(d) for d in decoded] if isinstance(decoded, list) else decoded


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
        if isinstance(obj, Mapping):
            return {k: _rudimentary_encode_dict_value(v) for k, v in obj.items()}
        else:
            raise TypeError(*e.args, obj, type(obj)) from e
    except ValueError as e:
        # NOTE: The error is probably this if `obj` is a string:
        # ValueError: invalid literal for int() with base 10:"""
        if isinstance(obj, HexBytes):
            return obj.hex()  # type: ignore [return-value]
        elif isinstance(obj, Address):
            return str(obj)  # type: ignore [return-value]
        else:
            raise ValueError(*e.args, obj, type(obj)) from e


@overload
def _rudimentary_encode_dict_value(value: int) -> HexStr: ...
@overload
def _rudimentary_encode_dict_value(value: __T) -> __T: ...
def _rudimentary_encode_dict_value(value: Union[int, __T]) -> Union[HexStr, __T]:
    # I dont think this needs to be robust, time will tell
    return hex(value) if isinstance(value, int) else value  # type: ignore [return-value]


encode: Final = Encoder(enc_hook=_encode_hook).encode
"""
Encode an object to json-encoded bytes.

This function uses a custom encoding hook defined in `_encode_hook`.

Args:
    obj: The object to encode.

Returns:
    The json-encoded bytes representation of the object.

See Also:
    :class:`msgspec.json.Encoder`: The class that contains underlying JSON encoding function.
"""


# multicall specific stuff

_mcall_encoder: Final[MulticallEncoder] = default_codec._registry.get_encoder(
    "(bool,(address,bytes)[])"
)
_array_encoder: Final[DynamicArrayEncoder] = _mcall_encoder.encoders[-1]  # type: ignore [attr-defined]
_item_encoder: Final[TupleEncoder] = _array_encoder.item_encoder  # type: ignore [assignment]

# We don't need to follow the validation code from eth-abi since we guarantee the input types
_mcall_encoder.validate_value = _array_encoder.validate_value = _item_encoder.validate_value = lambda *_: ...  # type: ignore [attr-defined, method-assign]


def _int_to_big_endian(value: int) -> bytes:
    return value.to_bytes((value.bit_length() + 7) // 8 or 1, "big")


def _encode_uint_256(i: int) -> bytes:
    big_endian = _int_to_big_endian(i)
    return big_endian.rjust(32, b"\x00")


def __encode_new(values: Iterable[MulticallChunk]) -> bytes:
    encoded_elements, num_elements = __encode_elements_new(values)
    return _encode_uint_256(num_elements) + encoded_elements  # type: ignore [no-any-return]


def __encode_elements_new(values: Iterable[MulticallChunk]) -> Tuple[bytes, int]:
    tail_chunks = [_item_encoder(v) for v in values]
    count = len(tail_chunks)
    head_length = 32 * count
    tail_offsets = [0]
    offset = 0
    for chunk in tail_chunks[:-1]:
        offset += len(chunk)
        tail_offsets.append(offset)
    head_chunks = (_encode_uint_256(head_length + tail_offset) for tail_offset in tail_offsets)
    return b"".join((*head_chunks, *tail_chunks)), count


_array_encoder.encode = __encode_new  # type: ignore [method-assign]
_array_encoder.encode_elements = __encode_elements_new  # type: ignore [method-assign]


_mcall_decoder: Final[MulticallDecoder] = default_codec._registry.get_decoder(
    "(uint256,uint256,(bool,bytes)[])"
).decode


def mcall_encode(data: Iterable[MulticallChunk]) -> bytes:
    return _mcall_encoder((False, data))


# maybe use this success flag to do something later
Success = bool


def mcall_decode(data: "types.PartialResponse") -> Union[List[bytes], Exception]:
    try:
        decoded = _mcall_decoder(ContextFramesBytesIO(data.decode_result("eth_call")))[2]  # type: ignore [arg-type, no-untyped-call]
    except Exception as e:
        if PartialResponse is None:
            __import_from_types()
        # NOTE: We need to safely bring any Exceptions back out of the ProcessPool
        e.args = (*e.args, data.decode_result() if isinstance(data, PartialResponse) else data)  # type: ignore [arg-type]
        return e
    else:
        return [tup[1] for tup in decoded]


def __import_from_types() -> None:
    """This helper function is called once to import PartialResponse, Request, Response, and better_decode."""
    global PartialResponse, Request, Response, better_decode
    from dank_mids.types import PartialResponse, Request, Response, better_decode


def __make_decode_batch() -> None:
    from dank_mids.types import PartialResponse

    global _decode_batch
    _decode_batch = Decoder(type=Union[List[msgspec.Raw], PartialResponse]).decode
