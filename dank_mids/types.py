from typing import (TYPE_CHECKING, Any, Callable, Coroutine, Dict, List,
                    NewType, TypedDict, TypeVar, Union)

from eth_typing import ChecksumAddress
from web3.types import RPCEndpoint, RPCResponse

if TYPE_CHECKING:
    from dank_mids.requests import Multicall
    
T = TypeVar("T")

ChainId = NewType("ChainId", int)
BlockId = NewType("BlockId", str)
BatchId = Union[int, str]
Multicalls = Dict[BlockId, "Multicall"]

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
