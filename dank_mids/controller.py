
import asyncio
import threading
from collections import defaultdict
from functools import lru_cache
from time import time
from typing import Any, Dict, List, Literal, Optional, Union

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
    elif "message" in e.args[0]:
        err_msg = e.args[0]["message"]
    elif "error" in e.args[0] and "message" in e.args[0]["error"]:
        err_msg = e.args[0]["error"]["message"]
    else:
        raise e
    return err_msg


class DankMiddlewareController:
    def __init__(self, w3: Web3) -> None:
        assert w3.eth.is_async and isinstance(w3.provider, AsyncBaseProvider), "Dank Middleware can only be applied to an asycnhronous Web3 instance."
        self.w3 = w3
        self.sync_w3 = Web3(provider = HTTPProvider(self.w3.provider.endpoint_uri))
        # Can't pickle middlewares to send to process executor
        self.sync_w3.middleware_onion.clear()
        self.sync_w3.provider.middlewares = tuple()
        self.DO_NOT_BATCH = set()
        self.pending_calls = defaultdict(dict)
        self.completed_calls = defaultdict(dict)
        self.batcher = multicall.multicall.batcher
        self.process_executor = multicall.utils.process_pool_executor
        self._bid = 0   #      batch id
        self._mid = 0   #  multicall id
        self._cid = 0   #       call id
        self._bid_lock = threading.Lock()
        self._mid_lock = threading.Lock()
        self._cid_lock = threading.Lock()
        self._last_seen_cid = 0
        self._initializing = False
        self._is_configured = False
        self._is_executing = False
        self._pools_closed = False
        self._checkpoint = time()
        self._instance = len(instances)
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
            assert cid in self.pending_calls[block], f"Something went wrong, call{cid} is missing from `pending_calls`."
            if self.queue_is_ready() and self.loop_is_ready():
                await self.execute_multicall()
            await asyncio.sleep(LOOP_INTERVAL)
            self._last_seen_cid = self._cid
        return self.fetch_response(block,cid)

    def queue_is_ready(self) -> bool:
        if not self._is_executing and self._cid == self._last_seen_cid and len(self.pending_calls):
            return True
        return False
    
    def loop_is_ready(self) -> bool:
        return time() - self._checkpoint > LOOP_INTERVAL
    
    def fetch_response(self, block: str, cid: int) -> RPCResponse:
        response = self.completed_calls[block].pop(cid)
        if not self.completed_calls[block]:
            self.completed_calls.pop(block)
        return response
    
    async def execute_multicall(self) -> None:
        i = 0
        while self._cid_lock.locked():
            if i // 50 == int(i // 50):
                main_logger.debug('lock is locked')
            await asyncio.sleep(.1)
        if self._is_executing:
            return
        demo_logger.info(f'executing multicall (current cid: {self._cid})')
        self._is_executing = True
        self._pools_closed = True
        with self._cid_lock:
            pending_calls = list(self.pending_calls.items())
        self._pools_closed = False
        await gather([self.process_block(block, calls) for block, calls in pending_calls])
        self._is_executing = False
        demo_logger.info('multicall complete')
    
    async def process_block(self, block: str, calls: Dict[int,List]) -> None:
        calls = [[cid, [params[0]['to'], HexBytes(params[0]['data'])]] for cid, params in calls.items()]
        demo_logger.info(f'executing {len(calls)} calls for block {block}')
        batches = self.batcher.batch_calls(calls, self.batcher.step)
        batches = await gather([self.process_batch(batch,block) for batch in batches])

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
    
    async def spoof_response(self, cid: int, block: str, params: List, data: Optional[Union[str,Exception]]) -> RPCResponse:
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

        # Pop the call from pending calls
        # TODO figure out why cids can be missing from pending_calls when they haven't been popped yet
        if cid in self.pending_calls[block]:
            self.pending_calls[block].pop(cid)

        # Pop the block from pending calls if empty
        if not self.pending_calls[block]:
            self.pending_calls.pop(block)
        return data

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
