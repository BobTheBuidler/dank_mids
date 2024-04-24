
from msgspec import Raw, json

from dank_mids.types import (Any, Callable, JSONRPCBatchResponseRaw, List, PartialResponse,
                             RawResponse, Union, nested_dict_of_stuff, _encode_hook)


decode_raw = lambda data: RawResponse(json.decode(data, type=Raw))
"""Decode json-encoded bytes into a `msgspec.Raw` object."""

decode_nested_dict = lambda data: json.decode(data, type=nested_dict_of_stuff)
"""Decode json-encoded bytes into a nested dictionary."""

def decode_jsonrpc_batch(data: bytes) -> Union[PartialResponse, List[RawResponse]]:
    """Decode json-encoded bytes into a list of response structs, or a single error response struct if applicable."""
    decoded = json.decode(data, type=JSONRPCBatchResponseRaw)
    return decoded if isinstance(decoded, PartialResponse) else _map_raw(decoded)

_map_raw: Callable[[List[Raw]], List[RawResponse]] = lambda decoded: list(map(RawResponse, decoded))
"""Converts a list of `msgspec.Raw` objects into a list of `RawResponse` objects."""

def encode(obj: Any) -> bytes:
    """Encode an object to json-encoded bytes."""
    return json.encode(obj, enc_hook=_encode_hook)
