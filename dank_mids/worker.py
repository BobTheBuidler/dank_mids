import asyncio
import threading
from typing import (TYPE_CHECKING, Any, Dict, List, Optional, Tuple, TypeVar,
                    Union)

import aiohttp
import eth_retry
from eth_abi import decode_single, encode_single
from eth_utils import function_signature_to_4byte_selector
from hexbytes._utils import to_bytes
from multicall.multicall import batcher
from multicall.utils import gather, run_in_subprocess

from dank_mids._config import AIOHTTP_TIMEOUT, DEMO_MODE
from dank_mids._demo_mode import demo_logger
from dank_mids.call import BatchedCall
from dank_mids.constants import OVERRIDE_CODE
from dank_mids.loggers import main_logger
from dank_mids.types import (BlockId, CallsToExec, JsonrpcBatch, JsonrpcCall,
                             JsonrpcParams, MulticallBatch)
from dank_mids.uid import UIDGenerator

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController

BatchId = Union[int, str]


FOURBYTE = function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")
INPUT_TYPES = "(bool,(address,bytes)[])"
OUTPUT_TYPES = "(uint256,uint256,(bool,bytes)[])"

T = TypeVar("T")

def bisect(collection: List[T]) -> Tuple[List[T], List[T]]:
    halfpoint = len(collection) // 2
    left = collection[:halfpoint]
    right = collection[halfpoint:]
    return left, right

class DankWorker:
    """
    Runs a second event loop in a subthread which is used to reduce congestion on the main event loop.
    This allows dank_mids to better communicate with your node while you abuse it with heavy loads.
    """
    def __init__(self, controller: "DankMiddlewareController") -> None:
        self.controller = controller
        self.target = self.controller.multicall2
        self.batcher = batcher
        self.multicall_uid = UIDGenerator()
        self.request_uid = UIDGenerator()
        self.jsonrpc_batch_uid = UIDGenerator()
        self.state_override_not_supported: bool = self.controller.chain_id == 100  # Gnosis Chain does not support state override.
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
    
    @eth_retry.auto_retry
    async def __call__(self, *request_args: Any) -> Any:
        return await self.controller.w3.eth.call(*request_args)  # type: ignore
    
    async def execute_multicall(self, calls_to_exec: CallsToExec) -> None:
        """ Runs in main thread. """
        asyncio.run_coroutine_threadsafe(self._execute_multicall(calls_to_exec), self.event_loop).result()
    
    async def _execute_multicall(self, calls_to_exec: CallsToExec) -> None:
        """ Runs in worker thread. """
        full_batches: List[MulticallBatch] = []
        partial_batches: List[MulticallBatch] = []
        for *batches, partial_batch in [self.batcher.batch_calls(calls, self.batcher.step) for calls in calls_to_exec.values()]:
            full_batches.extend(batches)  # type: ignore
            partial_batches.append(partial_batch)  # type: ignore
        
        ### Combine multicalls into one or more jsonrpc batches
        partial_batches.sort(key=lambda x: len(x), reverse=True)
        num_calls_in_batch = 0
        jsonrpc_batch: JsonrpcBatch = []
        jsonrpc_batches: List[JsonrpcBatch] = []
        for partial_batch in partial_batches:
            # This would make the batch too large, lets start a new jsonrpc batch
            if num_calls_in_batch + len(partial_batch) > self.batcher.step:
                if jsonrpc_batch:
                    jsonrpc_batches.append(jsonrpc_batch)
                jsonrpc_batch = [partial_batch]
                num_calls_in_batch = len(partial_batch)
            # This can be added to the current jsonrpc batch
            else:
                jsonrpc_batch.append(partial_batch)
                num_calls_in_batch += len(partial_batch)
                if len(jsonrpc_batch) >= 500:
                    jsonrpc_batches.append(jsonrpc_batch)
                    jsonrpc_batch = []
                    num_calls_in_batch = 0
                
        if jsonrpc_batch:
            jsonrpc_batches.append(jsonrpc_batch)

        coros = [gather(self.process_single_multicall(batch, batch[0].block) for batch in full_batches)]

        if jsonrpc_batches:
            # If the only combined partial batch only contains calls for one block, we can add it to the full batches and process it like any single-block multicall
            if len(jsonrpc_batches) == 1 and len(jsonrpc_batch := jsonrpc_batches[0]) == 1:
                single_batch = jsonrpc_batch[0]
                coros.append(self.process_single_multicall(single_batch, single_batch[0].block))
            else:
                for jsonrpc_batch in jsonrpc_batches:
                    coros.append(self.process_batch_multicall(jsonrpc_batch))
        await gather(coros)
        demo_logger.info('multicall complete')  # type: ignore

    def prepare_jsonrpc_batch(self, batches: List[List[BatchedCall]]) -> List[JsonrpcCall]:
        return [{'jsonrpc': '2.0', 'id': i, 'method': 'eth_call', 'params': self.prepare_multicall_request(batch)} for i, batch in enumerate(batches)]
    
    async def process_batch_multicall(self, batches: List[List[BatchedCall]], jid: Optional[BatchId] = None) -> None:
        """ Runs in worker thread. """
        if jid is None:
            jid = self.jsonrpc_batch_uid.next
        rid = self.request_uid.next
        if DEMO_MODE:
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            demo_logger.info(f'executing {sum(len(batch) for batch in batches)} calls for {len(batches)} blocks')  # type: ignore
            demo_logger.info(f'request {rid} for jsonrpc batch {jid} starting')  # type: ignore
        jsonrpc_batch = self.prepare_jsonrpc_batch(batches)
        try:
            responses = await self._post_jsonrpc_batch(jsonrpc_batch)

            # A successful response will be a list
            if isinstance(responses, dict) and 'result' in responses and isinstance(responses['result'], dict) and 'message' in responses['result']:
                raise ValueError(responses['result']['message'])

            for response in responses:
                if 'result' not in response:
                    raise ValueError(response)
            
            await gather([self.process_multicall_response(batch, to_bytes(response)) for batch, response in zip(batches, [response['result'] for response in responses])])
            demo_logger.info(f'request {rid} for jsonrpc batch {jid} complete')  # type: ignore
        except Exception as e:
            # While it might look weird, f-string is faster than `str(e)`.
            if "out of gas" in f"{e}":
                # TODO Remember which contracts/calls are gas guzzlers
                main_logger.debug('out of gas. cut in half, trying again')
            elif any(err in f"{e}".lower() for err in ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]):
                main_logger.debug('dank too loud, trying again')
            else:
                main_logger.warning(f"unexpected exception: {type(e)} {e}")

            chunk0, chunk1 = bisect(batches)
            await gather([
                self.process_batch_multicall(chunk0, f"{jid}_0") if len(chunk0) > 1 else self.process_single_multicall(chunk0[0], chunk0[0][0].block),
                self.process_batch_multicall(chunk1, f"{jid}_1") if len(chunk1) > 1 else self.process_single_multicall(chunk1[0], chunk1[0][0].block),
            ])
            demo_logger.info(f'request {rid} for jsonrpc batch {jid} complete')  # type: ignore
    
    async def process_single_multicall(self, batch: List[BatchedCall], block: BlockId, bid: Optional[BatchId] = None) -> None:
        """ Runs in worker thread. """
        if bid is None:
            bid = self.multicall_uid.next
        rid = self.request_uid.next
        demo_logger.info(f'request {rid} for multicall {bid} starting')  # type: ignore
        request_args = self.prepare_multicall_request(batch)
        try:
            response = await self(*request_args)
            await self.process_multicall_response(batch, response)
            demo_logger.info(f'request {rid} for multicall {bid} complete')  # type: ignore
        except Exception as e:
            if len(batch) == 1:
                await batch[0].spoof_response(e)
                return
            # While it might look weird, f-string is faster than `str(e)`.
            elif "out of gas" in f"{e}":
                # TODO Remember which contracts/calls are gas guzzlers
                main_logger.debug('out of gas. cut in half, trying again')
            elif any(err in f"{e}".lower() for err in ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]):
                main_logger.debug('dank too loud, trying again')
                # We need this check because one of the other multicalls in a batch might have already reduced `self.batcher.step`
                if (new_step := round(num_calls * 0.99) if (num_calls := len(batch)) >= 100 else num_calls - 1) < self.batcher.step:
                    old_step = self.batcher.step
                    self.batcher.step = new_step
                    main_logger.warning(f'Multicall batch size reduced from {old_step} to {new_step}. The failed batch had {num_calls} calls.')
            else:
                main_logger.warning(f"unexpected exception: {type(e)} {e}")

            chunk0, chunk1 = bisect(batch)
            await gather([
                self.process_single_multicall(chunk0, block, f"{bid}_0"),
                self.process_single_multicall(chunk1, block, f"{bid}_1"),
            ])
            demo_logger.info(f'request {rid} for multicall {bid} complete')  # type: ignore
    
    def prepare_multicall_request(self, batch: List[BatchedCall]) -> JsonrpcParams:
        fn_args = [False, [[call.target, call.calldata] for call in batch]]
        calldata = FOURBYTE + encode_single(INPUT_TYPES, fn_args)
        if self.state_override_not_supported:
            return [{'to': self.target, 'data': '0x' + calldata.hex()}, batch[0].block]  # type: ignore
        return [{'to': self.target, 'data': '0x' + calldata.hex()}, batch[0].block, {self.target: {'code': OVERRIDE_CODE}}]  # type: ignore

    async def process_multicall_response(self, batch: List[BatchedCall], response: bytes) -> None:
        decoded: List[Tuple[bool, bytes]]
        _, _, decoded = await run_in_subprocess(decode_single, OUTPUT_TYPES, response)
        await gather([call.spoof_response(data) for call, (_, data) in zip(batch, decoded)])
    
    @eth_retry.auto_retry
    async def _post_jsonrpc_batch(self, jsonrpc_batch: List[JsonrpcCall]) -> Union[Dict, List[bytes]]:
        """ Posts `jsonrpc_batch` to your node. A successful call returns a list. """
        async with aiohttp.ClientSession(timeout=AIOHTTP_TIMEOUT) as session:
            responses = await session.post(self.controller.w3.provider.endpoint_uri, json=jsonrpc_batch)  # type: ignore
            return await responses.json()

