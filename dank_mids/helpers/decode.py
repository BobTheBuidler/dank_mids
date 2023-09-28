
import functools
import logging
from datetime import datetime
from typing import (Any, AsyncGenerator, Callable, Optional, Tuple, Type,
                    TypeVar)

import a_sync
from msgspec import Raw, json

from dank_mids.types import (PartialResponse, RawResponse,BytesStream, StreamedJSONArrayOfObjects,
                             _JSONRPCBatchResponse, nested_dict_of_stuff)

T = TypeVar("T")

raw = lambda data: RawResponse(json.decode(data, type=Raw))
partial: Callable[[bytes], PartialResponse] = functools.partial(json.decode, type=PartialResponse)
nested_dict = lambda data: json.decode(data, type=nested_dict_of_stuff)

async def streamed_json_array(stream: StreamedJSONArrayOfObjects, type: Type[T] = Any) -> AsyncGenerator[T, None]:
    async for obj_stream in stream:
        obj = b''
        async for bytes in obj_stream:
            obj += bytes
        yield json.decode(obj, type=type)

async def jsonrpc_batch(stream: StreamedJSONArrayOfObjects) -> AsyncGenerator[RawResponse, None]:
    async for raw in streamed_json_array(stream, Raw):
        yield RawResponse(raw)
