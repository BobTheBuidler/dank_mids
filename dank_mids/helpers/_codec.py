
from msgspec import Raw, json

from dank_mids.types import (Any, PartialResponse, RawResponse,
                             JSONRPCBatchResponseRaw, nested_dict_of_stuff, _encode_hook)

raw = lambda data: RawResponse(json.decode(data, type=Raw))
nested_dict = lambda data: json.decode(data, type=nested_dict_of_stuff)
jsonrpc_batch = lambda data: decoded if isinstance(decoded := json.decode(data, type=JSONRPCBatchResponseRaw), PartialResponse) else _map_raw(decoded)

_map_raw = lambda decoded: list(map(RawResponse, decoded))

def encode(obj: Any) -> bytes:
    return json.encode(obj, enc_hook=_encode_hook)
