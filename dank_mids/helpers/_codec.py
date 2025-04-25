from itertools import accumulate, chain
from typing import Any, AnyStr, Callable, Final, Iterable, List, Union, Tuple, TypeVar

import msgspec
import msgspec.json
from eth_abi import decoding, encoding
from eth_abi.abi import default_codec
from eth_abi.encoding import DynamicArrayEncoder, TupleEncoder

from dank_mids import types
from dank_mids.types import JSONRPCBatchResponseRaw, MulticallChunk, PartialResponse


__T = TypeVar("__T")

MulticallEncoder = Callable[[Tuple[bool, Iterable[MulticallChunk]]], bytes]

DecodedMulticall = Tuple[int, int, Tuple[Tuple["Success", bytes], ...]]
MulticallDecoder = Callable[..., DecodedMulticall]


# these compile to C constants
Raw: Final = msgspec.Raw
RawResponse: Final = types.RawResponse
ContextFramesBytesIO: Final = decoding.ContextFramesBytesIO
DecodeError: Final = msgspec.DecodeError

json_encode: Final = msgspec.json.encode
json_decode: Final = msgspec.json.decode
encode_uint_256: Final = encoding.encode_uint_256
_encode_hook: Final = types._encode_hook


def decode_raw(data: AnyStr) -> types.RawResponse:
    """
    Decode json-encoded bytes into a `msgspec.Raw` object.

    Args:
        data: The json-encoded bytes to decode.

    Returns:
        The decoded data wrapped in a RawResponse object.
    """
    try:
        return RawResponse(json_decode(data, type=Raw))
    except DecodeError as e:
        e.args = *e.args, data
        raise


def decode_jsonrpc_batch(data: AnyStr) -> Union[PartialResponse, List[types.RawResponse]]:
    """
    Decode json-encoded bytes into a list of response structs, or a single error response struct if applicable.

    Args:
        data: The json-encoded bytes that represent the batch response data.

    Returns:
        Either a PartialResponse if there's an error, or a list of RawResponse objects.
    """
    decoded = json_decode(data, type=JSONRPCBatchResponseRaw)
    return [RawResponse(d) for d in decoded] if isinstance(decoded, list) else decoded


def encode(obj: Any) -> bytes:
    """
    Encode an object to json-encoded bytes.

    This function uses a custom encoding hook defined in `_encode_hook`.

    Args:
        obj: The object to encode.

    Returns:
        The json-encoded bytes representation of the object.

    See Also:
        :func:`msgspec.json.encode`: The underlying JSON encoding function.
    """
    return json_encode(obj, enc_hook=_encode_hook)  # type: ignore [no-any-return]


# multicall specific stuff

_mcall_encoder: Final[MulticallEncoder] = default_codec._registry.get_encoder(
    "(bool,(address,bytes)[])"
)
_array_encoder: Final[DynamicArrayEncoder] = _mcall_encoder.encoders[-1]  # type: ignore [attr-defined]
_item_encoder: Final[TupleEncoder] = _array_encoder.item_encoder

# We don't need to follow the validation code from eth-abi since we guarantee the input types
_mcall_encoder.validate_value = _array_encoder.validate_value = _item_encoder.validate_value = lambda *_: ...  # type: ignore [attr-defined, method-assign]


def __encode_new(values: Iterable[MulticallChunk]) -> bytes:
    encoded_elements, num_elements = __encode_elements_new(values)
    return encode_uint_256(num_elements) + encoded_elements  # type: ignore [no-any-return]


def __encode_elements_new(values: Iterable[MulticallChunk]) -> Tuple[bytes, int]:
    tail_chunks = [_item_encoder(v) for v in values]
    count = len(tail_chunks)
    head_length = 32 * count
    tail_offsets = chain((0,), accumulate((len(chunk) for chunk in tail_chunks[:-1])))
    head_chunks = (encode_uint_256(head_length + tail_offset) for tail_offset in tail_offsets)
    return b"".join(chain(head_chunks, tail_chunks)), count


_array_encoder.encode = __encode_new  # type: ignore [method-assign]
_array_encoder.encode_elements = __encode_elements_new  # type: ignore [method-assign]


_mcall_decoder: Final[MulticallDecoder] = default_codec._registry.get_decoder(
    "(uint256,uint256,(bool,bytes)[])"
).decode


def mcall_encode(data: Iterable[MulticallChunk]) -> bytes:
    return _mcall_encoder((False, data))


# maybe use this success flag to do something later
Success = bool


def mcall_decode(data: PartialResponse) -> Union[List[bytes], Exception]:
    try:
        decoded = _mcall_decoder(ContextFramesBytesIO(data.decode_result("eth_call")))[2]  # type: ignore [arg-type]
    except Exception as e:
        # NOTE: We need to safely bring any Exceptions back out of the ProcessPool
        e.args = (*e.args, data.decode_result() if isinstance(data, PartialResponse) else data)
        return e
    else:
        return [tup[1] for tup in decoded]
