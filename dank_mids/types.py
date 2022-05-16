from typing import Any, Callable, Coroutine

from web3.types import RPCEndpoint, RPCResponse

# This was introduced in web3 v5.28.0 but we like loose deps here
AsyncMiddleware = Callable[[RPCEndpoint, Any], Coroutine[Any, Any, RPCResponse]]