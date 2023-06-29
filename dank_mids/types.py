import logging
from typing import (TYPE_CHECKING, Any, Callable, Coroutine, DefaultDict, Dict,overload, 
                    List, Literal, NewType, Optional, TypedDict, TypeVar,
                    Union)

from eth_typing import ChecksumAddress
from msgspec import Raw, Struct, ValidationError
from msgspec.json import decode, encode
from web3.datastructures import AttributeDict
from web3.types import RPCEndpoint, RPCResponse

from dank_mids._exceptions import BadResponse

if TYPE_CHECKING:
    from dank_mids.requests import Multicall

ChainId = NewType("ChainId", int)
BlockId = NewType("BlockId", str)
BatchId = Union[int, str]
Multicalls = Dict[BlockId, "Multicall"]

eth_callParams = TypedDict("eth_callParams", {"to": ChecksumAddress, "data": str})
OverrideParams = TypedDict("OverrideParams", {"code": str})
JsonrpcParams = List[Union[eth_callParams, BlockId, OverrideParams]]


# This type alias was introduced in web3 v5.28.0 but we like loose deps here so we recreate instead of import.
AsyncMiddleware = Callable[[RPCEndpoint, Any], Coroutine[Any, Any, RPCResponse]]

list_of_stuff = List[Union[str, None, dict, list]]
dict_of_stuff = Dict[str, Union[str, None, list_of_stuff, Dict[str, Optional[Any]]]]
nested_dict_of_stuff = Dict[str, Union[str, None, list_of_stuff, dict_of_stuff]]

class _DictStruct(Struct):
    def __getitem__(self, attr: str) -> Any:
        return getattr(self, attr)
    def to_dict(self) -> Dict[str, Any]:
        data = {}
        for field in self.__struct_fields__:
            attr = getattr(self, field)
            data[field] = attr.to_dict() if isinstance(attr, _DictStruct) else attr
        return data
  
class PartialRequest(_DictStruct):
    method: str
    id: Union[str, int]
    params: Optional[list] = None

    @property
    def data(self) -> bytes:
        return encode(self)

class Request(PartialRequest):
    # NOTE: While technially part of a request, we can successfully make requests without including the `jsonrpc` field.
    jsonrpc: Literal["2.0"] = "2.0"

class Error(_DictStruct):
    code: int
    message: str
    data: Optional[Any] = None

# some devving tools that will go away eventually
_dict_responses = set()
_str_responses = set()
_types = set()

# TODO: use the types from snek
Log = Dict[str, Union[bool, str, None, List[str]]]
AccessList = List[Dict[str, Union[str, List[str]]]]
Transaction = Dict[str, Union[str, None, AccessList]]

RETURN_TYPES = {
    "eth_call": str,
    "eth_chainId": str,
    "eth_getCode": str,
    "eth_getLogs": List[Log],
    "eth_getBalance": str,
    "eth_blockNumber": str,  # TODO: see if we can decode this straight to an int
    "eth_accounts": List[str],
    "eth_getBlockByNumber": Dict[str, Union[str, List[Union[str, Transaction]]]],
    "eth_getTransactionCount": str,
    "eth_getTransactionByHash": Transaction,
    "eth_getTransactionReceipt": Dict[str, Union[str, None, List[Log]]], 
    "erigon_getHeaderByNumber": Dict[str, Optional[str]],
}

class PartialResponse(_DictStruct):
    result: Raw = None  # type: ignore
    error: Optional[Error] = None

    @property
    def exception(self) -> BadResponse:
        if self.error is None:
            raise AttributeError(f"{self} did not error.")
        return BadResponse(self)
        
    def to_dict(self, method: Optional[str] = None) -> Dict[str, Any]:
        data = {}
        for field in self.__struct_fields__:
            attr = getattr(self, field)
            if field == "result" and attr:
                attr = self.decode_result(method=method, _caller=self)
            if field != 'error' or attr is not None:
                data[field] = attr.to_dict() if isinstance(attr, _DictStruct) else attr
        return data

    def decode_result(self, method: Optional[str] = None, _caller = None) -> Any:
        # NOTE: These must be added to the `RETURN_TYPES` constant above manually
        if method and (typ := RETURN_TYPES.get(method)):
            if method in ["eth_call", "eth_blockNumber", "eth_getCode", "eth_getTransactionReceipt", "eth_getTransactionCount", "eth_getBalance", "eth_chainId", "erigon_getHeaderByNumber"]:
                return decode(self.result, type=typ)
            try:
                from time import time
                start = time()
                decoded = decode(self.result, type=typ)
                if _caller:
                    print(f'decoding {type(_caller)} {method} took {time() - start}')
                return AttributeDict(decoded) if isinstance(decoded, dict) else decoded
            except ValidationError as e:
                logging.getLogger('dank_mids.decoder').exception(e)

        # We have some semi-smart logic for providing decoder hints even if method not in `RETURN_TYPES`
        try:
            if method:
                if method in _dict_responses:
                    decoded = AttributeDict(decode(self.result, type=nested_dict_of_stuff))
                    types = {type(v) for v in decoded.values()}
                    print(f'my method and types: {method} {types}')
                    if list in types:
                        lists = [v for v in decoded.values() if isinstance(v, list)]
                        for lst in lists:
                            lst_types = {type(_) for _ in lst}
                            print(f"list types: {lst_types}")
                    _types.update(types)
                    return decoded
                elif method in _str_responses:
                    print(f'Must add `{method}: str` to `RETURN_TYPES`')
                    return decode(self.result, type=str)
            
            # In this case we can provide no hints, let's let the decoder figure it out
            decoded = decode(self.result)
            if isinstance(decoded, str):
                if method:
                    _str_responses.add(method)
                return decoded
            elif isinstance(decoded, dict):
                if method:
                    _dict_responses.add(method)
                return AttributeDict(decoded)
            raise TypeError(type(decoded), decoded)
        except ValidationError as e:
            raise ValidationError(method, e) from e

class Response(PartialResponse):
    id: Optional[Union[str, int]] = None
    jsonrpc: Literal["2.0"] = "2.0"

class RawResponse:
    """Wraps a Raw object that we know represents a Response with a `decode` helper method"""
    def __init__(self, raw: Raw) -> None:
        self._raw = raw
    @overload
    def decode(self, partial = True) -> PartialResponse:...
    @overload
    def decode(self, partial = False) -> Response:...
    def decode(self, partial: bool = False) -> Union[Response, PartialResponse]:
        return decode(self._raw, type=PartialResponse if partial else Response)

JSONRPCBatchRequest = List[Request]
JSONRPCBatchResponse = List[Raw]
