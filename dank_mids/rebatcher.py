
import asyncio
from collections import defaultdict
from contextlib import suppress
from functools import cached_property
from typing import TYPE_CHECKING, DefaultDict, List, NoReturn, Optional

from dank_mids.batch import DankBatch
from dank_mids.types import BlockId

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    from dank_mids.requests import RPCRequest, eth_call

class Rebatcher:
    def __init__(self, controller: "DankMiddlewareController") -> None:
        self.controller = controller
        self.queue = asyncio.Queue()
    
    async def rebatch(self, request: "RPCRequest") -> None:
        self._task
        self.queue.put_nowait(request)
        while True:
            with suppress(asyncio.TimeoutError):
                await asyncio.wait_for(request._done.wait(), 30)
                return
            if self._exc:
                raise self._exc
            
    @cached_property
    def _task(self) -> asyncio.Task:
        return asyncio.create_task(self.__rebatch_daemon_job())
    
    def __get_next(self) -> Optional["RPCRequest"]:
        try:
            return self.queue.get_nowait()
        except asyncio.QueueEmpty:
            return None
    
    async def __rebatch_daemon_job(self) -> NoReturn:
        eth_calls: DefaultDict[BlockId, List[eth_call]]
        rpc_calls: List[RPCRequest]
        try:
            while True:
                eth_calls = defaultdict(list)
                rpc_calls = []
                while request := self.__get_next():
                    # NOTE we don't need logic for single requests here because its a rebatcher. when we want to generalize it to a batcher, we will
                    if isinstance(request, eth_call) and request.multicall_compatible:
                        eth_calls[request.block].append(request)
                    else:
                        rpc_calls.append(request)
                if eth_calls or rpc_calls:
                    await DankBatch(self.controller, eth_calls, rpc_calls=rpc_calls)
                await asyncio.sleep(1)
                        
        except Exception as e:
            self._exc = e
            raise e
            
        
        
        