
import asyncio
import logging
from collections import defaultdict
from contextlib import suppress
from functools import cached_property
from typing import TYPE_CHECKING, DefaultDict, List, NoReturn, Optional

from dank_mids.batch import DankBatch
from dank_mids.types import BlockId

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    from dank_mids.requests import RPCRequest, eth_call

logger = logging.getLogger(__name__)

class Rebatcher:
    def __init__(self, controller: "DankMiddlewareController") -> None:
        self.controller = controller
        self.__queue = asyncio.Queue()
        self.__eth_calls: DefaultDict[BlockId, List[eth_call]] = defaultdict(list)
        self.__rpc_calls: List["RPCRequest"] = []
    
    async def rebatch(self, request: "RPCRequest") -> None:
        self._task
        self.__queue.put_nowait(request)
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
            return self.__queue.get_nowait()
        except asyncio.QueueEmpty:
            return None
    
    async def __rebatch_daemon_job(self) -> NoReturn:
        try:
            while True:
                self.__eth_calls = defaultdict(list)
                self.__rpc_calls = []
                request = await self.__queue.get()
                self.__sort_call(request)
                while request := self.__get_next():
                    self.__sort_call(request)
                logger.debug("rebatching %s calls in multicalls and %s other calls", sum(len(calls) for calls in eth_calls.values()), len(rpc_calls))
                await DankBatch(self.controller, self.__eth_calls, self.__rpc_calls)
        except Exception as e:
            self._exc = e
            raise e
        
    def __sort_call(self, request: "RPCRequest") -> None:
        # NOTE we don't need logic for single requests here because its a rebatcher. when we want to generalize it to a batcher, we will
        if isinstance(request, eth_call) and request.multicall_compatible:
            self.__eth_calls[request.block].append(request)
        else:
            self.__rpc_calls.append(request)
        