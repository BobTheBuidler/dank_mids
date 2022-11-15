from typing import TYPE_CHECKING, Any, Callable, Coroutine, Dict, List, Literal, NewType, TypedDict, Union
from eth_typing import ChecksumAddress

from web3.types import RPCEndpoint, RPCResponse

if TYPE_CHECKING:
    from dank_mids.call import eth_call

ChainId = NewType("ChainId", int)
BlockId = NewType("BlockId", str)
CallsToExec = Dict[BlockId, List["eth_call"]]

eth_callParams = TypedDict("eth_callParams", {"to": ChecksumAddress, "data": str})
OverrideParams = TypedDict("OverrideParams", {"code": str})
JsonrpcParams = List[Union[eth_callParams, BlockId, OverrideParams]]

RpcCallJson = TypedDict(
    "RpcCallJson", 
    {
        "jsonrpc": str,
        "id": int,
        "method": Literal["eth_call"],
        "params": JsonrpcParams,
    }
)

# This type alias was introduced in web3 v5.28.0 but we like loose deps here so we recreate instead of import.
AsyncMiddleware = Callable[[RPCEndpoint, Any], Coroutine[Any, Any, RPCResponse]]
