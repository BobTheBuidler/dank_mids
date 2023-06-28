from functools import partial

from dank_mids.types import *
from msgspec.json import decode

jsonrpc_batch = partial(decode, type=Union[JSONRPCBatchResponse, Response])
response = partial(decode, type=Response)
nested_dict = partial(decode, type=nested_dict_of_stuff)
