
import asyncio
import threading
from collections import defaultdict
from functools import lru_cache
from time import time
from typing import Any, Generator, List, Literal, Optional, Set, Union

import multicall
from aiohttp import RequestInfo
from eth_utils import to_checksum_address
from hexbytes import HexBytes
from multicall.utils import gather, run_in_subprocess
from web3 import Web3
from web3.providers import HTTPProvider
from web3.providers.async_base import AsyncBaseProvider
from web3.types import RPCEndpoint, RPCResponse

from dank_mids._config import LOOP_INTERVAL
from dank_mids.constants import BAD_HEXES, GAS_LIMIT, OVERRIDE_CODE
from dank_mids.loggers import (demo_logger, main_logger, sort_lazy_logger,
                               sort_logger)

instances: List["DankMiddlewareController"] = []

def _reattempt_call_and_return_exception(target: str, calldata: bytes, block: str, w3: Web3) -> Union[bytes, Exception]:
    """ NOTE: This runs synchronously in a subprocess in order to bypass Dank Middleware without blocking the event loop. """
    try:
        return w3.eth.call({"to": target, "data": calldata}, block)
    except Exception as e:
        return e

def _err_msg(e: Exception) -> str:
    """ Extract an error message from `e` to use in a spoof rpc response. """
    if isinstance(e.args[0], str) or isinstance(e.args[0], RequestInfo):
        err_msg = f"DankMidsError: {type(e)} {e.args}"
    elif isinstance(e.args[0], Exception):
        err_msg = f"DankMidsError: {type(e.args[0])} {e.args[0].args}"
    elif "message" in e.args[0]:
        err_msg = e.args[0]["message"]
    elif "error" in e.args[0] and "message" in e.args[0]["error"]:
        err_msg = e.args[0]["error"]["message"]
    else:
        raise e
    return err_msg

def _start_worker_event_loop(loop: asyncio.BaseEventLoop) -> None:
    """
    Used to start a second event loop in a separate thread which is used to reduce congestion on the main event loop.
    This allows dank_mids to better communicate with your node while you abuse it with heavy loads.
    """
    asyncio.set_event_loop(loop)
    loop.run_forever()


class DankMiddlewareController:
    def __init__(self, w3: Web3) -> None:
        assert w3.eth.is_async and isinstance(w3.provider, AsyncBaseProvider), "Dank Middleware can only be applied to an asycnhronous Web3 instance."
        self.w3: Web3 = w3
        self.sync_w3: Web3 = Web3(provider = HTTPProvider(self.w3.provider.endpoint_uri))
        # Can't pickle middlewares to send to process executor
        self.sync_w3.middleware_onion.clear()
        self.sync_w3.provider.middlewares = tuple()
        self.DO_NOT_BATCH: Set[str] = set()
        self.pending_calls: List[BatchedCall] = []
        self.num_pending_calls: int = 0
        self.batcher = multicall.multicall.batcher
        self.is_running = False
        self.worker_event_loop = asyncio.new_event_loop()
        threading.Thread(target=lambda: _start_worker_event_loop(self.worker_event_loop)).start()
        self._bid: int = 0   #      batch id
        self._mid: int = 0   #  multicall id
        self._cid: int = 0   #       call id
        self._bid_lock: threading.Lock = threading.Lock()
        self._mid_lock: threading.Lock = threading.Lock()
        self._cid_lock: threading.Lock = threading.Lock()
        self._initializing: bool = False
        self._is_configured: bool = False
        self._pools_closed: bool = False
        self._checkpoint: float = time()
        self._instance: int = len(instances)
        instances.append(self)
    
    def __repr__(self) -> str:
        return f"<DankMiddlewareController {self._instance}>"

    async def __call__(self, params: Any) -> RPCResponse:
        if not self._is_configured:
            await self._setup()
        call = await self.add_to_queue(params)
        return await call
    
    @property
    def next_bid(self) -> int:
        """ Returns the next unique batch id. """
        return self._increment('bid')
    
    @property
    def next_mid(self) -> int:
        """ Returns the next unique multicall id. """
        return self._increment('mid')
    
    @property
    def next_cid(self) -> int:
        """ Returns the next unique call id. """
        self._checkpoint = time()
        return self._increment('cid')
    
    
    async def taskmaster_loop(self) -> None:
        self.is_running = True
        while self.pending_calls:
            await asyncio.sleep(0)
            if (self.loop_is_ready or self.queue_is_full):
                await self.execute_multicall()
        self.is_running = False

    @sort_lazy_logger
    def should_batch(self, method: RPCEndpoint, params: Any) -> bool:
        """ Determines whether or not a call should be passed to the DankMiddlewareController. """
        if method != 'eth_call':
            sort_logger.debug(f"bypassed, method is {method}")
            return False
        elif params[0]['to'] in self.DO_NOT_BATCH:
            sort_logger.debug(f"bypassed, target is in `DO_NOT_BATCH`")
            return False
        return True
    
    async def add_to_queue(self, params: Any) -> "BatchedCall":
        """ Adds a call to the DankMiddlewareContoller's `pending_calls`. """
        while self._pools_closed:
            await asyncio.sleep(0)
        return BatchedCall(self, params)

    @property
    def loop_is_ready(self) -> bool:
        return time() - self._checkpoint > LOOP_INTERVAL
    
    @property
    def queue_is_full(self) -> bool:
        return len(self.pending_calls) >= self.batcher.step * 25
    
    async def execute_multicall(self) -> None:
        asyncio.run_coroutine_threadsafe(self._execute_multicall(), self.worker_event_loop).result()
    
    async def _execute_multicall(self) -> None:
        i = 0
        while self._cid_lock.locked():
            if i // 500 == int(i // 500):
                main_logger.debug('lock is locked')
            i += 1
            await asyncio.sleep(.1)
        self._pools_closed = True
        with self._cid_lock:
            calls_to_exec = defaultdict(list)
            for call in self.pending_calls:
                calls_to_exec[call.block].append(call)
                call.started = True
            self.pending_calls.clear()
            self.num_pending_calls = 0
        self._pools_closed = False
        demo_logger.info(f'executing multicall (current cid: {self._cid})')
        await gather([self.process_block(block, calls) for block, calls in calls_to_exec.items()])
        demo_logger.info('multicall complete')
    
    async def process_block(self, block: str, calls: List["BatchedCall"]) -> None:
        demo_logger.info(f'executing {len(calls)} calls for block {block}')
        batches = self.batcher.batch_calls(calls, self.batcher.step)
        await gather([self.process_batch(batch,block) for batch in batches])

    async def process_batch(self, batch: List["BatchedCall"], block: str, bid: Optional[int] = None) -> None:
        if bid is None:
            bid = self.next_bid
        mid = self.next_mid
        demo_logger.info(f'tryBlockAndAggregate {mid} for batch {bid} starting')
        try:
            _, _, response = await self._multicall_for_block(block).coroutine([False, [[call.target, call.calldata] for call in batch]])
            demo_logger.info(f'tryBlockAndAggregate {mid} for batch {bid} complete')
            await gather([call.spoof_response(data) for call, (_, data) in zip(batch, response)])

        except Exception as e:
            if len(batch) == 1:
                await batch[0].spoof_response(e)
                return
            elif "out of gas" in str(e):
                # TODO Remember which contracts/calls are gas guzzlers
                main_logger.debug('out of gas. cut in half, trying again')
            elif any(err in str(e).lower() for err in ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]):
                main_logger.debug('dank too loud, trying again')
                num_calls = len(batch)
                new_step = round(num_calls * 0.99) if num_calls >= 100 else num_calls - 1
                # We need this check because one of the other multicalls in a batch might have already reduced `self.batcher.step`
                if new_step < self.batcher.step:
                    old_step = self.batcher.step
                    self.batcher.step = new_step
                    main_logger.warning(f'Multicall batch size reduced from {old_step} to {new_step}. The failed batch had {len(batch)} calls.')
            else:
                main_logger.warning(f"unexpected exception: {type(e)} {str(e)}")

            halfpoint = len(batch) // 2
            await gather([
                self.process_batch(batch[:halfpoint], block, str(bid)+"_0"),
                self.process_batch(batch[halfpoint:], block, str(bid)+"_1"),
            ])
            demo_logger.info(f'tryBlockAndAggregate {mid} for batch {bid} complete')
        
    @lru_cache(maxsize=None)
    def _multicall_for_block(self, block: str) -> multicall.Call:
        return multicall.Call(
            self.MULTICALL2,
            "tryBlockAndAggregate(bool,(address,bytes)[])(uint256,uint256,(bool,bytes)[])",
            returns=None,
            block_id=block,
            gas_limit=GAS_LIMIT,
            state_override_code=OVERRIDE_CODE,
        )

    async def _setup(self) -> None:
        if self._initializing:
            while self._initializing:
                await asyncio.sleep(0)
            return
        self._initializing = True
        main_logger.info('Dank Middleware initializing... Strap on your rocket boots...')
        # NOTE use sync w3 here to prevent timeout issues with abusive scripts.
        chain_id = self.sync_w3.eth.chain_id
        MULTICALL = multicall.constants.MULTICALL_ADDRESSES.get(chain_id,None)
        self.MULTICALL2 = multicall.constants.MULTICALL2_ADDRESSES.get(chain_id,None)
        self.DO_NOT_BATCH.update(to_checksum_address(address) for address in [MULTICALL,self.MULTICALL2] if address)
        self._is_configured = True
        self._initializing = False
    
    def _increment(self, id: Literal["bid","mid","cid"]) -> int:
        attr = f"_{id}"
        with getattr(self, f"{attr}_lock"):
            new = getattr(self, attr) + 1
            setattr(self, attr, new)
            return new


class ResponseNotReady(Exception):
    pass

class BatchedCall:
    def __init__(self, controller: DankMiddlewareController, params: Any) -> None:
        """ Adds a call to the DankMiddlewareContoller's `pending_calls`. """
        self.cid = controller.next_cid
        self.block: str = params[1]
        self.controller = controller
        self.target = params[0]['to']
        self.calldata = HexBytes(params[0]['data'])
        self.controller.pending_calls.append(self)
        self.started = False
        self._response: Optional[RPCResponse] = None
        demo_logger.info(f'added to queue (cid: {self.cid})')
    
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

    async def spoof_response(self, data: Optional[Union[str,Exception]]) -> None:
        """ Creates a spoof rpc response for this BatchedCall instance using data provided by the controller. """
        if (
            # If multicall failed, try single call to get detailed error.
            data is None
            # Or, if we got a known "bad" response from the multicall, try single call.
            # Could be that target contract does not support multicall2.
            or (isinstance(data, bytes) and HexBytes(data).hex() in BAD_HEXES)
        ):
            data = await run_in_subprocess(_reattempt_call_and_return_exception, self.target, self.calldata, self.block, self.controller.sync_w3)
            # We were able to get a usable response from single call.
            # Add contract to DO_NOT_BATCH list
            if not isinstance(data, Exception):
                self.controller.DO_NOT_BATCH.add(self.target) 
        if isinstance(data, Exception):
            spoof = {"error": {'code': -32000, 'message': _err_msg(data)}}
        else:
            spoof = {"result": HexBytes(data).hex()}
        spoof.update({"id": self.cid, "jsonrpc": "dank_mids"})
        main_logger.debug(f"spoof: {spoof}")
        self._response = spoof
