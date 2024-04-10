
from msgspec import Raw, json

from dank_mids.types import (PartialResponse, RawResponse,
                             _JSONRPCBatchResponse, nested_dict_of_stuff)

raw = lambda data: RawResponse(json.decode(data, type=Raw))
nested_dict = lambda data: json.decode(data, type=nested_dict_of_stuff)
jsonrpc_batch = lambda data: decoded if isinstance(decoded := json.decode(data, type=_JSONRPCBatchResponse), PartialResponse) else _map_raw(decoded)

_map_raw = lambda decoded: list(map(RawResponse, decoded))
