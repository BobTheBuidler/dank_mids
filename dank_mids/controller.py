
import asyncio
import threading
from collections import defaultdict
from functools import lru_cache
from time import time
from typing import Any, Dict, List, Literal, Optional, Set, Union

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

def reattempt_call_and_return_exception(target: str, calldata: bytes, block: str, w3: Web3) -> Exception:
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

def start_caller_event_loop(loop: asyncio.BaseEventLoop) -> None:
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
        self.pending_calls: defaultdict = defaultdict(dict)
        self.in_process_calls: defaultdict = defaultdict(dict)
        self.completed_calls: defaultdict = defaultdict(dict)
        self.batcher = multicall.multicall.batcher
        self.caller_event_loop = asyncio.new_event_loop()
        threading.Thread(target=lambda: start_caller_event_loop(self.caller_event_loop)).start()
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
        block = params[1]
        cid = await self.add_to_queue(params)
        return await self.await_response(block,cid)
    
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
    
    async def add_to_queue(self, params: Any) -> int:
        """ Adds a call to the DankMiddlewareContoller's `pending_calls`. """
        cid = self.next_cid
        block = params[1]
        while self._pools_closed:
            await asyncio.sleep(0)
        self.pending_calls[block][cid] = params
        demo_logger.info(f'added to queue (cid: {cid})')
        return cid
    
    async def await_response(self, block: str, cid: int) -> RPCResponse:
        while cid not in self.completed_calls[block]:
            if cid in self.in_process_calls[block]:
                while cid not in self.completed_calls[block]:
                    await asyncio.sleep(0)
                return self.fetch_response(block,cid)
            assert cid in self.pending_calls[block] or cid in self.in_process_calls[block], f"Something went wrong, call{cid} is missing from `pending_calls`."
            if self.loop_is_ready() or self.queue_is_full(block):
                asyncio.run_coroutine_threadsafe(self.execute_multicall(), self.caller_event_loop).result()
            await asyncio.sleep(LOOP_INTERVAL)
        return self.fetch_response(block,cid)

    def loop_is_ready(self) -> bool:
        return time() - self._checkpoint > LOOP_INTERVAL
    
    def queue_is_full(self, block) -> bool:
        return len(self.pending_calls[block]) >= self.batcher.step * 25
    
    def fetch_response(self, block: str, cid: int) -> RPCResponse:
        return self.completed_calls[block].pop(cid)
    
    async def execute_multicall(self) -> None:
        i = 0
        while self._cid_lock.locked():
            if i // 500 == int(i // 500):
                main_logger.debug('lock is locked')
            i += 1
            await asyncio.sleep(.1)
        self._pools_closed = True
        with self._cid_lock:
            calls_to_exec = []
            blocks = list(self.pending_calls.keys())
            for block in blocks:
                calls = self.pending_calls.pop(block)
                for cid, params in calls.items():
                    self.in_process_calls[block][cid] = params
                calls_to_exec.append((block, calls))
        self._pools_closed = False
        demo_logger.info(f'executing multicall (current cid: {self._cid})')
        await gather([self.process_block(block, calls) for block, calls in calls_to_exec])
        demo_logger.info('multicall complete')
    
    async def process_block(self, block: str, calls: Dict[int,List]) -> None:
        calls = [[cid, [params[0]['to'], HexBytes(params[0]['data'])]] for cid, params in calls.items()]
        demo_logger.info(f'executing {len(calls)} calls for block {block}')
        batches = self.batcher.batch_calls(calls, self.batcher.step)
        await gather([self.process_batch(batch,block) for batch in batches])

    async def process_batch(self, batch: List, block: str, bid: Optional[int] = None) -> None:
        if bid is None:
            bid = self.next_bid
        mid = self.next_mid
        demo_logger.info(f'tryBlockAndAggregate {mid} for batch {bid} starting')
        batch = dict(batch)
        cids = list(batch.keys())
        inputs = list(batch.values())
        try:
            _, _, response = await self._multicall_for_block(block).coroutine([False, inputs])
            demo_logger.info(f'tryBlockAndAggregate {mid} for batch {bid} complete')
            await gather([
                self.spoof_response(cid, block, params, data)
                for cid, params, (_, data) in zip(cids, inputs, response)
            ])

        except Exception as e:
            if len(inputs) == 1:
                await self.spoof_response(cids[0], block, inputs[0], e)
                return
            elif "out of gas" in str(e):
                # TODO Remember which contracts/calls are gas guzzlers
                main_logger.debug('out of gas. cut in half, trying again')
            elif any(err in str(e).lower() for err in ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]):
                main_logger.debug('dank too loud, trying again')
                new_step = round(len(inputs) * 0.99) if len(inputs) >= 100 else len(inputs) - 1
                # We need this check because one of the other multicalls in a batch might have already reduced `self.batcher.step`
                if new_step < self.batcher.step:
                    old_step = self.batcher.step
                    self.batcher.step = new_step
                    main_logger.warning(f'Multicall batch size reduced from {old_step} to {new_step}. The failed batch had {len(inputs)} calls.')
            else:
                main_logger.warning(f"unexpected exception: {type(e)} {str(e)}")

            batches = [[cid, input] for cid, input in zip(cids, inputs)]
            halfpoint = len(batches) // 2
            await gather([
                self.process_batch(batches[:halfpoint], block, str(bid)+"_0"),
                self.process_batch(batches[halfpoint:], block, str(bid)+"_1"),
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
    
    async def spoof_response(self, cid: int, block: str, params: List, data: Optional[Union[str,Exception]]) -> None:
        """ Creates a spoof rpc response for call # `cid` using data returned from multicall2. """
        if (
            # If multicall failed, try single call to get detailed error.
            data is None
            # Or, if we got a known "bad" response from the multicall, try single call.
            # Could be that target contract does not support multicall2.
            or (isinstance(data, bytes) and HexBytes(data).hex() in BAD_HEXES)
        ):
            target, calldata = params
            data = await run_in_subprocess(reattempt_call_and_return_exception, target, calldata, block, self.sync_w3)
            # We were able to get a usable response from single call.
            # Add contract to DO_NOT_BATCH list
            if not isinstance(data, Exception):
                self.DO_NOT_BATCH.add(target) 
        if isinstance(data, Exception):
            spoof = {"error": {'code': -32000, 'message': _err_msg(data)}}
        else:
            spoof = {"result": HexBytes(data).hex()}
        spoof.update({"id": cid, "jsonrpc": "dank_mids"})
        main_logger.debug(f"spoof: {spoof}")
        self.completed_calls[block][cid] = spoof

        # Pop the call from in_process_calls
        # TODO figure out why cids can be missing from in_process_calls when they haven't been popped yet
        if cid in self.in_process_calls[block]:
            self.in_process_calls[block].pop(cid)

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
