import asyncio
import threading
from functools import lru_cache
from typing import TYPE_CHECKING, Dict, List, Optional, Union

import multicall
from multicall.utils import gather

from dank_mids.call import BatchedCall
from dank_mids.constants import GAS_LIMIT, OVERRIDE_CODE
from dank_mids.loggers import demo_logger, main_logger
from dank_mids.uid import UIDGenerator

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


class DankWorker:
    """
    Runs a second event loop in a separate thread which is used to reduce congestion on the main event loop.
    This allows dank_mids to better communicate with your node while you abuse it with heavy loads.
    """
    def __init__(self, controller: "DankMiddlewareController") -> None:
        self.controller = controller
        self.batcher = multicall.multicall.batcher
        self.batch_uid = UIDGenerator()
        self.multicall_uid = UIDGenerator()
        self.event_loop = asyncio.new_event_loop()
        self.worker_thread = threading.Thread(target=self.start)
        self.worker_thread.start()
    
    def start(self) -> None:
        """ Runs in worker thread. """
        asyncio.set_event_loop(self.event_loop)
        self.event_loop.run_until_complete(self.loop())
    
    async def loop(self) -> None:
        """ Exits loop when main thread dies, killing worker thread. Runs in worker thread. """
        while threading.main_thread().is_alive():
            await asyncio.sleep(5)
    
    async def execute_multicall(self, calls_to_exec: Dict[str, List[BatchedCall]]) -> None:
        asyncio.run_coroutine_threadsafe(self._execute_multicall(calls_to_exec), self.event_loop).result()
    
    async def _execute_multicall(self, calls_to_exec: Dict[str, List[BatchedCall]]) -> None:
        await gather([self.process_block(block, calls) for block, calls in calls_to_exec.items()])
        demo_logger.info('multicall complete')
    
    async def process_block(self, block: str, calls: List[BatchedCall]) -> None:
        demo_logger.info(f'executing {len(calls)} calls for block {block}')
        batches = self.batcher.batch_calls(calls, self.batcher.step)
        await gather([self.process_batch(batch,block) for batch in batches])

    async def process_batch(self, batch: List[BatchedCall], block: str, bid: Optional[Union[int, str]] = None) -> None:
        if bid is None:
            bid = self.batch_uid.next
        mid = self.multicall_uid.next
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
                # We need this check because one of the other multicalls in a batch might have already reduced `self.batcher.step`
                if (new_step := round(num_calls * 0.99) if (num_calls := len(batch)) >= 100 else num_calls - 1) < self.batcher.step:
                    old_step = self.batcher.step
                    self.batcher.step = new_step
                    main_logger.warning(f'Multicall batch size reduced from {old_step} to {new_step}. The failed batch had {num_calls} calls.')
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
            self.controller.MULTICALL2,
            "tryBlockAndAggregate(bool,(address,bytes)[])(uint256,uint256,(bool,bytes)[])",
            returns=None,
            block_id=block,
            gas_limit=GAS_LIMIT,
            state_override_code=OVERRIDE_CODE,
        )
