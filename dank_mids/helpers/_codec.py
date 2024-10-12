
from msgspec import Raw, json

from dank_mids.types import (Any, Callable, JSONRPCBatchResponseRaw, List, PartialResponse,
                             RawResponse, Union, _nested_dict_of_stuff, _encode_hook)


decode_raw = lambda data: RawResponse(json.decode(data, type=Raw))
"""
Decode json-encoded bytes into a `msgspec.Raw` object.

Args:
    data: The json-encoded bytes to decode.

Returns:
    The decoded data wrapped in a RawResponse object.
"""

decode_nested_dict = lambda data: json.decode(data, type=_nested_dict_of_stuff)
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
    decoded = json.decode(data, type=JSONRPCBatchResponseRaw)
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
    return json.encode(obj, enc_hook=_encode_hook)
