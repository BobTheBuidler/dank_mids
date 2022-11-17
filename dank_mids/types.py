from typing import (TYPE_CHECKING, Any, Callable, Coroutine, Dict, List,
                    NewType, TypedDict, TypeVar, Union)

from eth_typing import ChecksumAddress
from web3.types import RPCEndpoint, RPCResponse

if TYPE_CHECKING:
    from dank_mids.requests import eth_call

ChainId = NewType("ChainId", int)
BlockId = NewType("BlockId", str)
BatchId = Union[int, str]
CallsToExec = Dict[BlockId, List["eth_call"]]

eth_callParams = TypedDict("eth_callParams", {"to": ChecksumAddress, "data": str})
OverrideParams = TypedDict("OverrideParams", {"code": str})
JsonrpcParams = List[Union[eth_callParams, BlockId, OverrideParams]]

RpcCallJson = TypedDict(
    "RpcCallJson", 
    {
        "jsonrpc": str,
        "id": BatchId,
        "method": str, # NOTE: must be a valid RPCEndpoint
        "params": JsonrpcParams,
    }
)

# This type alias was introduced in web3 v5.28.0 but we like loose deps here so we recreate instead of import.
AsyncMiddleware = Callable[[RPCEndpoint, Any], Coroutine[Any, Any, RPCResponse]]


_V = TypeVar("_V")

class HashableDict(Dict[str, _V]):
    def __init__(self, _dict: Dict[str, _V]) -> None:
        super().__init__()
        for k, v in _dict.items():
            self[k] = v
    def __hash__(self) -> int:  # type: ignore
        return hash((key, tuple(self[key]) if isinstance(self[key], list) else self[key]) for key in sorted(self))  # type: ignore
