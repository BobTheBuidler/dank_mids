import asyncio
import threading
from typing import (TYPE_CHECKING, Any, Dict, Iterable, Iterator, List,
                    Literal, Optional, Tuple, TypeVar, Union)

import aiohttp
import eth_retry
from eth_abi import decode_single, encode_single
from eth_typing import ChecksumAddress
from eth_utils import function_signature_to_4byte_selector
from hexbytes._utils import to_bytes
from multicall.multicall import NotSoBrightBatcher, batcher
from multicall.utils import gather, run_in_subprocess
from web3.types import RPCResponse

from dank_mids._config import AIOHTTP_TIMEOUT, DEMO_MODE
from dank_mids._demo_mode import demo_logger
from dank_mids.call import HashableDict, RPCCall, eth_call
from dank_mids.constants import OVERRIDE_CODE
from dank_mids.loggers import main_logger
from dank_mids.types import BlockId, CallsToExec, JsonrpcParams, RpcCallJson
from dank_mids.uid import UIDGenerator

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController

BatchId = Union[int, str]

MAX_JSONRPC_BATCH_SIZE = 500

FOURBYTE = function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")
INPUT_TYPES = "(bool,(address,bytes)[])"
OUTPUT_TYPES = "(uint256,uint256,(bool,bytes)[])"

_T = TypeVar("_T")


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
    
    @property
    def endpoint(self) -> str:
        return self.controller.w3.provider.endpoint_uri
    
    async def execute_batch(self, calls_to_exec: CallsToExec, rpc_calls: List[RPCCall]) -> None:
        """ Runs in main thread. """
        asyncio.run_coroutine_threadsafe(self._execute_batch(calls_to_exec, rpc_calls), self.event_loop).result()

    async def _execute_batch(self, calls_to_exec: CallsToExec, rpc_calls: List[RPCCall]) -> None:
        """ Runs in worker thread. """
        await DankBatch(self, calls_to_exec, rpc_calls)
    
    
class DankBatch:
    """ A batch of jsonrpc batches. """
    def __init__(self, worker: DankWorker, eth_calls: CallsToExec, rpc_calls: List[RPCCall]):
        self.worker = worker
        self.eth_calls = eth_calls
        self.rpc_calls = rpc_calls
    
    def __await__(self) -> None:
        return gather(self.coroutines).__await__()
    
    @property
    def batcher(self) -> NotSoBrightBatcher:
        return self.worker.batcher
    
    @property
    def coroutines(self) -> List["_Batch"]:
        request_coros: List[_Batch] = []
        multicalls_to_batch: List["Multicall"] = []
        for *full_batches, remaining_calls in [self.batcher.batch_calls(calls, self.batcher.step) for calls in self.eth_calls.values()]:
            request_coros.extend(Multicall(self.worker, full_batches))  # type: ignore
            multicalls_to_batch.append(Multicall(self.worker, remaining_calls))  # type: ignore
        # Combine multicalls into one or more jsonrpc batches
        full_batches, working_batch = self.batch_multicalls(multicalls_to_batch)
        request_coros.extend(full_batches)
        rpc_calls_to_batch = self.rpc_calls[:]
        while rpc_calls_to_batch:
            if len(working_batch) >= MAX_JSONRPC_BATCH_SIZE:
                request_coros.append(working_batch)
                working_batch = JSONRPCBatch(self.worker)
            working_batch.append(rpc_calls_to_batch.pop())
        if len(working_batch) == 1 and isinstance(working_batch[0], Multicall):
            request_coros.append(working_batch[0])
        else:
            request_coros.append(working_batch)
        return request_coros
    
    def batch_multicalls(self, multicalls: List["Multicall"]) -> Tuple[List["JSONRPCBatch"], "JSONRPCBatch"]:
        """ Used to collect multicalls into batches without overwhelming the node with oversized calls. """
        full_batches = []
        multicalls.sort(key=lambda x: len(x), reverse=True)
        eth_calls_in_batch = 0
        working_batch = JSONRPCBatch(self.worker)
        for mcall in multicalls:
            # This would be too many eth_calls for a single multicall, lets start a new jsonrpc batch.
            if eth_calls_in_batch + len(mcall) > self.batcher.step:
                if working_batch:
                    full_batches.append(working_batch)
                working_batch = JSONRPCBatch(self.worker, [mcall])
                eth_calls_in_batch = len(mcall)
            # This can be added to the current jsonrpc batch
            else:
                working_batch.append(mcall)
                eth_calls_in_batch += len(mcall)
                if len(working_batch) >= MAX_JSONRPC_BATCH_SIZE:
                    # There are more than `MAX_JSONRPC_BATCH_SIZE` rpc calls packed into this batch, let's start a new one
                    full_batches.append(working_batch)
                    working_batch = JSONRPCBatch(self.worker)
                    eth_calls_in_batch = 0
        return full_batches, working_batch


class _Batch:
    def __init__(self, worker: "DankWorker", calls: Iterable[_T]):
        self.worker: DankWorker = worker
        self.calls: List[_T] = calls
        
    def __await__(self) -> None:
        return self.execute().__await__()
    
    def __bool__(self) -> bool:
        return bool(self.calls)
    
    def __getitem__(self, ix: int) -> _T:
        return self.calls[ix]

    def __iter__(self) -> Iterator[Iterable[_T]]:
        return iter(self.calls)
    
    def __len__(self) -> int:
        return len(self.calls)
    
    def append(self, call: _T) -> None:
        self.calls.append(call)
    
    @property
    def halfpoint(self) -> int:
        return len(self) // 2
    
    @property
    def chunk0(self) -> List[_T]:
        return self.calls[:self.halfpoint]
    
    @property
    def chunk1(self) -> List[_T]:
        return self.calls[self.halfpoint:]
    
    def should_retry(self, e: Exception) -> bool:
        if "out of gas" in f"{e}":
            # TODO Remember which contracts/calls are gas guzzlers
            main_logger.debug('out of gas. cut in half, trying again')
        elif any(err in f"{e}".lower() for err in ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]):
            main_logger.debug('Dank too loud. Bisecting batch and retrying.')
        else:
            main_logger.warning(f"unexpected {e.__class__.__name__}: {e}")
        return len(self) > 1



class Multicall(_Batch):
    """ Runs in worker thread. """
    method = "eth_call"
    calls: List[eth_call]

    def __init__(self, worker: DankWorker, calls: List[eth_call] = [], bid: Optional[BatchId] = None):
        super().__init__(worker, calls)
        self.bid = bid or self.worker.multicall_uid.next
    
    @property
    def block(self) -> BlockId:
        return self.calls[0].block
    
    @property
    def calldata(self) -> bytes:
        multicall_args = [False, [[call.target, call.calldata] for call in self.calls]]
        data = FOURBYTE + encode_single(INPUT_TYPES, multicall_args)
        return data.hex()
    
    @property
    def controller(self) -> "DankMiddlewareController":
        return self.worker.controller
    
    @property
    def target(self) -> ChecksumAddress:
        return self.worker.target
    
    @property
    def params(self) -> JsonrpcParams:
        if self.worker.state_override_not_supported:
            return [{'to': self.target, 'data': '0x' + self.calldata}, self.block]  # type: ignore
        return [{'to': self.target, 'data': '0x' + self.calldata}, self.block, {self.target: {'code': OVERRIDE_CODE}}]  # type: ignore
    
    @property
    def rpc_data(self) -> RpcCallJson:
        return {'jsonrpc': '2.0', 'id': self.bid, 'method': self.method, 'params': self.params}

    async def execute(self) -> None:
        rid = self.worker.request_uid.next
        demo_logger.info(f'request {rid} for multicall {self.bid} starting')  # type: ignore
        try:
            response = await self.worker(*self.params)
            await self.spoof_response(response)
        except Exception as e:
            if self.should_retry(e):
                await self.bisect_and_retry()
            else:
                await gather([call.spoof_response(e) for call in self.calls])
        demo_logger.info(f'request {rid} for multicall {self.bid} complete')  # type: ignore
    
    def should_retry(self, e: Exception) -> bool:
        if any(err in f"{e}".lower() for err in ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]):
            main_logger.debug('dank too loud, trying again')
            self.controller.reduce_batch_size(len(self))
            return True
        elif "No state available for block" in f"{e}":  # NOTE: While it might look weird, f-string is faster than `str(e)`.
            e.args[0]["dankmids_note"] = "You're not using an archive node, and you need one for the application you are attempting to run."
            return False
        elif super().should_retry(e):
            return True
        return len(self) > 1
    
    async def spoof_response(self, response: Union[bytes, str]) -> None:
        """
        If called from `self`, `response` will be bytes type.
        if called from a JSONRPCBatch, `response` will be str type.
        """ 
        decoded: List[Tuple[bool, bytes]]
        _, _, decoded = await run_in_subprocess(decode_single, OUTPUT_TYPES, to_bytes(response))
        await gather([call.spoof_response(data) for call, (_, data) in zip(self.calls, decoded)])
    
    async def bisect_and_retry(self) -> None:
        await gather([Multicall(self.worker, self.chunk0, f"{self.bid}_0"), Multicall(self.worker, self.chunk1, f"{self.bid}_1")])



class JSONRPCBatch(_Batch):
    calls: List[Union[Multicall, RPCCall]]

    def __init__(self, worker: DankWorker, calls: List[Union[Multicall, RPCCall]] = [], jid: Optional[BatchId] = None) -> None:
        super().__init__(worker, calls)
        self.jid = jid or self.worker.jsonrpc_batch_uid.next
    
    @property
    def data(self) -> List[RpcCallJson]:
        return [call.rpc_data for call in self.calls]
    
    async def execute(self) -> None:
        """ Runs in worker thread. """
        rid = self.worker.request_uid.next
        if DEMO_MODE:
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} ({sum(len(batch) for batch in self.calls)} calls) starting')  # type: ignore
        try:
            responses = await self.post()
            self.validate_responses(responses)
            await self.spoof_response(responses)
        except Exception as e:
            if not self.should_retry(e):
                raise e
            await self.bisect_and_retry()
        demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} complete')  # type: ignore
    
    @eth_retry.auto_retry
    async def post(self) -> Union[Dict, List[bytes]]:
        """ Posts `jsonrpc_batch` to your node. A successful call returns a list. """
        async with aiohttp.ClientSession(timeout=AIOHTTP_TIMEOUT) as session:
            responses = await session.post(self.worker.endpoint, json=self.data)  # type: ignore
            return await responses.json()
    
    def should_retry(self, e: Exception) -> bool:
        # While it might look weird, f-string is faster than `str(e)`.
        if "No state available for block" in f"{e}":
            main_logger.debug('No state available for queried block. Bisecting batch and retrying.')
            return True
        else:
            return super().should_retry(e)
    
    async def spoof_response(self, response: List[RPCResponse]) -> List[RPCResponse]:
        await gather([
            # NOTE: For some rpc methods, the result will be a dict we can't hash during the gather.
            call.spoof_response(HashableDict(result["result"]) if isinstance(result["result"], dict) else result["result"])
            for call, result in zip(self.calls, response)
        ])
    
    def validate_responses(self, responses) -> None:
        # A successful response will be a list
        if isinstance(responses, dict) and 'result' in responses and isinstance(responses['result'], dict) and 'message' in responses['result']:
            raise ValueError(responses['result']['message'])
        for response in responses:
            if 'result' not in response:
                raise ValueError(response)
    
    async def bisect_and_retry(self) -> None:
        chunks = self.chunk0, self.chunk1
        await gather([JSONRPCBatch(self.worker, chunk, f"{self.jid}_{i}") for i, chunk in enumerate(chunks)])
