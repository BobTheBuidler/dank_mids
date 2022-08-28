from typing import TYPE_CHECKING, Any, Callable, Coroutine, Dict, List, NewType

from web3.types import RPCEndpoint, RPCResponse

if TYPE_CHECKING:
    from dank_mids.call import BatchedCall

BlockId = NewType("BlockId", str)
CallsToExec = Dict[BlockId, List["BatchedCall"]]

# This type alias was introduced in web3 v5.28.0 but we like loose deps here so we recreate instead of import.
AsyncMiddleware = Callable[[RPCEndpoint, Any], Coroutine[Any, Any, RPCResponse]]
