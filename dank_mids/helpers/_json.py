from functools import partial
from typing import Any, List, Literal, Optional, Union, Dict

from msgspec import Struct, Raw
from msgspec.json import decode, encode


class Error(Struct):
    code: int
    message: str
    data: Optional[Any] = None

class Response(Struct):
    result: Raw = None  # type: ignore
    error: Optional[Error] = None
    id: Optional[Union[str, int]] = None
    jsonrpc: Literal["2.0"] = "2.0"

class Request(Struct):
    method: str
    id: Union[str, int]
    params: Optional[Any] = None
    jsonrpc: Literal["2.0"] = "2.0"

JSONRPCBatchRequest = List[Request]
JSONRPCBatchResponse = List[Response]

decode_jsonrpc_batch = partial(decode, type=JSONRPCBatchResponse)
