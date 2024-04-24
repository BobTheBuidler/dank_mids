
from msgspec import Raw, json

from dank_mids.types import (Any, Callable, JSONRPCBatchResponseRaw, List, PartialResponse,
                             RawResponse, Union, nested_dict_of_stuff, _encode_hook)


raw = lambda data: RawResponse(json.decode(data, type=Raw))
"""Decode json-encoded bytes into a `msgspec.Raw` object."""

nested_dict = lambda data: json.decode(data, type=nested_dict_of_stuff)
"""Decode json-encoded bytes into a nested dictionary."""

jsonrpc_batch: Callable[[bytes], Union[PartialResponse, List[RawResponse]]] = lambda data: decoded if isinstance(decoded := json.decode(data, type=JSONRPCBatchResponseRaw), PartialResponse) else _map_raw(decoded)
"""Decode json-encoded bytes into a list of response structs, or a single error response struct if applicable."""

_map_raw = lambda decoded: list(map(RawResponse, decoded))
"""Converts a list of `msgspec.Raw` objects into a list of `RawResponse` objects."""

def encode(obj: Any) -> bytes:
    """Encode an object to json-encoded bytes."""
    return json.encode(obj, enc_hook=_encode_hook)
