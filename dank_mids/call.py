
import asyncio
from typing import TYPE_CHECKING, Any, Generator, Optional, Union

from aiohttp import RequestInfo
from eth_typing import ChecksumAddress
from hexbytes import HexBytes
from multicall.utils import run_in_subprocess
from web3 import Web3
from web3.types import RPCError, RPCResponse

from dank_mids._demo_mode import demo_logger
from dank_mids.constants import BAD_HEXES
from dank_mids.loggers import main_logger
from dank_mids.types import BlockId

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


class ResponseNotReady(Exception):
    pass

def _call_failed(data: Optional[Union[bytes, Exception]]) -> bool:
    """ Returns True if `data` indicates a failed response, False otherwise. """
    if data is None:
        return True
    # If we got a known "bad" response from the multicall, that is also a failure.
    # Most likely the target contract does not support multicall2.
    elif (isinstance(data, bytes) and HexBytes(data).hex() in BAD_HEXES):
        return True
    return False

def _reattempt_call_and_return_exception(target: ChecksumAddress, calldata: bytes, block: BlockId, w3: Web3) -> Union[bytes, Exception]:
    """ NOTE: This runs synchronously in a subprocess in order to bypass Dank Middleware without blocking the event loop. """
    try:
        return w3.eth.call({"to": target, "data": calldata}, block)
    except Exception as e:
        return e

def _err_response(e: Exception) -> RPCError:
    """ Extract an error message from `e` to use in a spoof rpc response. """
    if isinstance(e.args[0], str) or isinstance(e.args[0], RequestInfo):
        err_msg = f"DankMidsError: {e.__class__.__name__} {e.args}"
    elif isinstance(e.args[0], Exception):
        err_msg = f"DankMidsError: {e.args[0].__class__.__name__} {e.args[0].args}"
    elif "message" in e.args[0]:
        err_msg = e.args[0]["message"]
    elif "error" in e.args[0] and "message" in e.args[0]["error"]:
        err_msg = e.args[0]["error"]["message"]
    else:
        raise e
    return {'code': -32000, 'message': err_msg, 'data': ''}


class BatchedCall:
    def __init__(self, controller: "DankMiddlewareController", params: Any) -> None:
        """ Adds a call to the DankMiddlewareContoller's `pending_calls`. """
        self.cid = controller.call_uid.next
        self.block: BlockId = params[1]
        self.controller = controller

        self.target = params[0]['to']
        self.calldata = HexBytes(params[0]['data'])
        self.controller.pending_calls.append(self)
        self._response: Optional[RPCResponse] = None
        demo_logger.info(f'added to queue (cid: {self.cid})')  # type: ignore
    
    @property
    def is_complete(self) -> bool:
        return self._response is not None
    
    @property
    def response(self) -> RPCResponse:
        if self._response is None:
            raise ResponseNotReady(self)
        return self._response
    
    def __eq__(self, __o: object) -> bool:
        if not isinstance(__o, BatchedCall):
            return False
        return self.cid == __o.cid
    
    def __hash__(self) -> int:
        return self.cid
    
    def __await__(self) -> Generator[Any, None, RPCResponse]:
        return self.wait_for_response().__await__()
    
    async def wait_for_response(self) -> RPCResponse:
        if not self.controller.is_running:
            await self.controller.taskmaster_loop()
        while not self.is_complete:
            await asyncio.sleep(0)
        return self.response

    async def spoof_response(self, data: Optional[Union[bytes, Exception]]) -> RPCResponse:
        """ Sets and returns a spoof rpc response for this BatchedCall instance using data provided by the worker. """
        spoof: RPCResponse
        # If multicall failed, make sync call to get either:
        # - revert details
        # - successful response
        if _call_failed(data):
            data = await self.sync_call()
        
        if isinstance(data, Exception):
            spoof = {"error": _err_response(data)}
        else:
            spoof = {"result": HexBytes(data).hex()}  # type: ignore
        spoof.update({"id": self.cid, "jsonrpc": "dank_mids"})  # type: ignore
        main_logger.debug(f"spoof: {spoof}")
        self._response = spoof
        return spoof

    async def sync_call(self) -> Union[bytes, Exception]:
        """ Used to bypass DankMiddlewareController. """ 
        data = await run_in_subprocess(
            _reattempt_call_and_return_exception, self.target, self.calldata, self.block, self.controller.sync_w3
        )
        # If we were able to get a usable response from single call, add contract to `do_not_batch`.
        if not isinstance(data, Exception):
            self.controller.do_not_batch.add(self.target)
        return data
