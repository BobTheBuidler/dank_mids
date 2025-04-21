from itertools import accumulate, chain
from typing import Any, AnyStr, Callable, Iterable, List, Union, Tuple

from eth_abi.abi import default_codec
from eth_abi.decoding import ContextFramesBytesIO
from eth_abi.encoding import DynamicArrayEncoder, TupleEncoder, encode_uint_256
from msgspec import DecodeError, Raw
from msgspec.json import decode as json_decode
from msgspec.json import encode as json_encode

from dank_mids.types import (
    JSONRPCBatchResponseRaw,
    MulticallChunk,
    PartialResponse,
    RawResponse,
    _encode_hook,
    _nested_dict_of_stuff,
)


def decode_raw(data: AnyStr) -> RawResponse:
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


decode_nested_dict = lambda data: json_decode(data, type=_nested_dict_of_stuff)
"""
Decode json-encoded bytes into a nested dictionary.

Args:
    data: The json-encoded bytes to decode.

Returns:
    The decoded nested dictionary.
"""


def decode_jsonrpc_batch(data: bytes) -> Union[PartialResponse, List[RawResponse]]:
    """
    Decode json-encoded bytes into a list of response structs, or a single error response struct if applicable.

    Args:
        data: The json-encoded bytes that represent the batch response data.

    Returns:
        Either a PartialResponse if there's an error, or a list of RawResponse objects.
    """
    decoded = json_decode(data, type=JSONRPCBatchResponseRaw)
    return decoded if isinstance(decoded, PartialResponse) else _map_raw(decoded)


_map_raw: Callable[[List[Raw]], List[RawResponse]] = lambda decoded: list(map(RawResponse, decoded))
"""
Converts a list of `msgspec.Raw` objects into a list of `RawResponse` objects.

Args:
    decoded: A list of msgspec.Raw objects.

Returns:
    A list of RawResponse objects.
"""


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

_mcall_encoder: Callable[[Tuple[bool, Iterable[MulticallChunk]]], bytes]  # TupleEncoder
_mcall_encoder = default_codec._registry.get_encoder("(bool,(address,bytes)[])")
_array_encoder: DynamicArrayEncoder = _mcall_encoder.encoders[-1]  # type: ignore [attr-defined]
_item_encoder: TupleEncoder = _array_encoder.item_encoder

# We don't need to follow the validation code from eth-abi since we guarantee the input types
_mcall_encoder.validate_value = _array_encoder.validate_value = _item_encoder.validate_value = lambda *_: ...  # type: ignore [attr-defined, method-assign]


def __encode_new(values: Iterable[MulticallChunk]) -> bytes:
    encoded_elements, num_elements = __encode_elements_new(values)
    return encode_uint_256(num_elements) + encoded_elements  # type: ignore [no-any-return]


def __encode_elements_new(values: Iterable[MulticallChunk]) -> Tuple[bytes, int]:
    tail_chunks = tuple(map(_item_encoder, values))
    count = len(tail_chunks)
    head_length = 32 * count
    tail_offsets = chain((0,), accumulate(map(len, tail_chunks[:-1])))
    head_chunks = map(encode_uint_256, map(head_length.__add__, tail_offsets))
    return b"".join(chain(head_chunks, tail_chunks)), count


_array_encoder.encode = __encode_new  # type: ignore [method-assign]
_array_encoder.encode_elements = __encode_elements_new  # type: ignore [method-assign]

_mcall_decoder = default_codec._registry.get_decoder("(uint256,uint256,(bool,bytes)[])").decode


def mcall_encode(data: Iterable[MulticallChunk]) -> bytes:
    return _mcall_encoder((False, data))


# maybe use this success flag to do something later
Success = bool
__get_bytes = lambda tup: tup[1]


def mcall_decode(data: PartialResponse) -> Union[List[bytes], Exception]:
    try:
        decoded: List[Tuple[Success, bytes]] = _mcall_decoder(
            ContextFramesBytesIO(data.decode_result("eth_call"))
        )[
            2
        ]  # type: ignore [arg-type]
    except Exception as e:
        # NOTE: We need to safely bring any Exceptions back out of the ProcessPool
        e.args = (*e.args, data.decode_result() if isinstance(data, PartialResponse) else data)
        return e
    else:
        return list(map(__get_bytes, decoded))
