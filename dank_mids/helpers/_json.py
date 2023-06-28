from functools import lru_cache, partial
from typing import Any, Dict, List, Literal, Optional, Union

from msgspec import Raw, Struct, ValidationError
from msgspec.json import decode
from web3.datastructures import AttributeDict

from dank_mids._exceptions import BadResponse
from dank_mids.loggers import main_logger

# TODO: use the types from snek
Log = Dict[str, Union[bool, str, None, List[str]]]
AccessList = List[Dict[str, Union[str, List[str]]]]

RETURN_TYPES = {
    "eth_call": str,
    "eth_chainId": str,
    "eth_getCode": str,
    "eth_getBalance": str,
    "eth_blockNumber": str,  # TODO: see if we can decode this straight to an int
    "eth_getBlockByNumber": Dict[str, Union[str, List[str]]],
    "eth_getTransactionCount": str,
    "eth_getTransactionByHash": Dict[str, Union[str, None, AccessList]],
    "eth_getTransactionReceipt": Dict[str, Union[str, None, List[Log]]], 
    "erigon_getHeaderByNumber": Dict[str, Optional[str]],
}

class DictStruct(Struct):
    def to_dict(self) -> Dict[str, Any]:
        data = {}
        for field in self.__struct_fields__:
            attr = getattr(self, field)
            data[field] = attr.to_dict() if isinstance(attr, DictStruct) else attr
        return data
    
class Error(DictStruct):
    code: int
    message: str
    data: Optional[Any] = None


# some devving tools that will go away eventually
_dict_responses = set()
_str_responses = set()
_types = set()

class Response(DictStruct):
    result: Raw = None  # type: ignore
    error: Optional[Error] = None
    id: Optional[Union[str, int]] = None
    jsonrpc: Literal["2.0"] = "2.0"

    @property
    def exception(self) -> BadResponse:
        if self.error is None:
            raise AttributeError(f"{self} did not error.")
        return BadResponse(self)
        
    def to_dict(self, method: str) -> Dict[str, Any]:
        data = {}
        for field in self.__struct_fields__:
            attr = self.decode_result(method) if field == "result" else getattr(self, field)
            if field != 'error' or attr is not None:
                data[field] = attr.to_dict() if isinstance(attr, DictStruct) else attr
        return data
    
    @lru_cache
    def decode_result(self, method: str) -> Any:
        # NOTE: These must be added to the `RETURN_TYPES` constant above manually
        if typ := RETURN_TYPES.get(method):
            try:
                decoded = decode(self.result, type=typ)
                return AttributeDict(decoded) if isinstance(decoded, dict) else decoded
            except ValidationError as e:
                main_logger.exception(e)

        # We have some semi-smart logic for providing decoder hints even if method not in `RETURN_TYPES`
        try:
            if method in _dict_responses:
                # TODO: Refactor this
                list_of_stuff = List[Union[str, None, dict, list]]
                dict_of_stuff = Dict[str, Union[str, None, list_of_stuff, Dict[str, Optional[Any]]]]
                nested_dict_of_stuff = Dict[str, Union[str, None, list_of_stuff, dict_of_stuff]]

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
                _str_responses.add(method)
                return decoded
            elif isinstance(decoded, dict):
                _dict_responses.add(method)
                return AttributeDict(decoded)
            raise TypeError(type(decoded), decoded)
        except ValidationError as e:
            raise ValidationError(method, e) from e


class Request(DictStruct):
    method: str
    id: Union[str, int]
    params: Optional[list] = None
    jsonrpc: Literal["2.0"] = "2.0"

JSONRPCBatchRequest = List[Request]
JSONRPCBatchResponse = List[Response]

decode_jsonrpc_batch = partial(decode, type=Union[JSONRPCBatchResponse, Response])
decode_response = partial(decode, type=Response)
