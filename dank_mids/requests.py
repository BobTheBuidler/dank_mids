
import abc
import asyncio
import logging
from collections import defaultdict
from concurrent.futures import ProcessPoolExecutor
from functools import cached_property, partial
from typing import (TYPE_CHECKING, Any, DefaultDict, Dict, Generator, Generic,
                    Iterable, Iterator, List, Optional, Tuple, Type, TypeVar,
                    Union)

import eth_retry
from aiohttp import RequestInfo
from eth_abi import abi, decoding
from eth_typing import ChecksumAddress
from eth_utils import function_signature_to_4byte_selector
from hexbytes import HexBytes
from msgspec import Raw, ValidationError
from msgspec.json import encode
from web3 import Web3
from web3.datastructures import AttributeDict
from web3.types import RPCEndpoint, RPCError, RPCResponse

from dank_mids import _config, constants
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import BadResponse, EmptyBatch
from dank_mids.helpers import _session, decode
from dank_mids.types import (RETURN_TYPES, BatchId, BlockId,
                             JSONRPCBatchResponse, JsonrpcParams,
                             PartialRequest, PartialResponse, RawResponse,
                             Request, Response)

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController


RETRY_ERRS = ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]

logger = logging.getLogger(__name__)

subprocesses = ProcessPoolExecutor(_config.NUM_PROCESSES)
run_in_subprocess = lambda fn, *args: asyncio.get_event_loop().run_in_executor(subprocesses, fn, *args)


class ResponseNotReady(Exception):
    pass

def _call_failed(data: Union[PartialResponse, Raw, bytes, Exception]) -> bool:
    # TODO: make this handle PartialResponse and Raw correctly
    """ Returns True if `data` indicates a failed response, False otherwise. """
    if data is None:
        return True
    # If we got a known "bad" response from the multicall, that is also a failure.
    # Most likely the target contract does not support multicall2.
    elif isinstance(data, bytes) and f"0x{data.hex()}" in constants.BAD_HEXES:
        return True
    return False

def _log_exception(e: Exception) -> None:
    # NOTE: These errors are expected during normal use and are not indicative of any problem(s). No need to log them.
    # TODO: Better filter what we choose to log here
    dont_need_to_see_errs = RETRY_ERRS + ['out of gas','error processing call revert', 'non_empty_data', 'invalid ether transfer']
    stre = str(e).lower()
    if any(err in stre for err in dont_need_to_see_errs):
        return
    logger.exception(e)

def _reattempt_call_and_return_exception(target: ChecksumAddress, calldata: bytes, block: BlockId, w3: Web3) -> Union[bytes, Exception]:
    """ NOTE: This runs synchronously in a subprocess in order to bypass Dank Middleware without blocking the event loop. """
    try:
        return w3.eth.call({"to": target, "data": calldata}, block)
    except Exception as e:
        _log_exception(e)
        return e


_Response = TypeVar("_Response", Response, List[Response], RPCResponse, List[RPCResponse])

class _RequestMeta(Generic[_Response], metaclass=abc.ABCMeta):
    def __init__(self) -> None:
        self.uid = self.controller.call_uid.next
        self._response: Optional[_Response] = None
        self._done = asyncio.Event()
    
    def __await__(self) -> Generator[Any, None, Optional[_Response]]:
        return self.get_response().__await__()
    
    @abc.abstractmethod
    def __len__(self) -> int:
        pass

    @property
    def response(self) -> _Response:
        if not self._done.is_set():
            raise ResponseNotReady(self)
        return self._response

    @abc.abstractmethod
    async def get_response(self) -> Optional[_Response]:
        pass

### Single requests:

BYPASS_METHODS = "eth_getLogs", "trace_", "debug_"

class RPCRequest(_RequestMeta[RawResponse]):
    dict_responses = set()
    str_responses = set()

    _types = set()

    def __init__(self, controller: "DankMiddlewareController", method: RPCEndpoint, params: Any):
        self.controller = controller
        self.method = method
        self.params = params
        self.should_batch = all(bypass not in method for bypass in BYPASS_METHODS)
        self._started = False
        super().__init__()

        if isinstance(self, eth_call) and self.multicall_compatible:
            self.controller.pending_eth_calls[self.block].append(self)
        else:
            self.controller.pending_rpc_calls.append(self)
        demo_logger.info(f'added to queue (cid: {self.uid})')  # type: ignore
    
    def __eq__(self, __o: object) -> bool:
        return self.uid == __o.uid if isinstance(__o, self.__class__) else False 
    
    def __len__(self) -> int:
        return 1
    
    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} uid={self.uid} method={self.method}>"

    @cached_property
    def request(self) -> Union[Request, PartialRequest]:
        return self.controller.request_type(method=self.method, params=self.params, id=self.uid)
    
    def start(self, batch: "_Batch") -> None:
        self._started = True
        self._batch = batch

    async def get_response(self) -> RPCResponse:
        if not self.should_batch:
            logger.debug(f"bypassed, method is {self.method}")
            await self.make_request()
            return self.response.decode(partial=True).to_dict(self.method)
        
        if self._started and not self._batch._started:
            # NOTE: If we're already started, we filled a batch. Let's await it now so we can send something to the node.
            await self._batch
        if not self._started:
            # NOTE: We want to force the event loop to make one full _run_once call before we execute.
            await asyncio.sleep(0)
        if not self._started:
            await self.controller.execute_batch()
        
        await self._done.wait()

        # JIT json decoding
        if isinstance(self.response, RawResponse):
            return self.response.decode(partial=True).to_dict(self.method)
        # Less optimal decoding
        # TODO: refactor this out
        return self.response
    
    async def spoof_response(self, data: Union[RawResponse, bytes, Exception]) -> None:
        """
        `Raw` type data comes from rpc calls executed in a jsonrpc batch
        `bytes` type data comes for individual eth_calls that were batched into multicalls and already decoded
        `Exception` type data comes from failed calls
        """
        
        # New handler
        if isinstance(data, RawResponse):
            self._response = data
        elif isinstance(data, BadResponse):
            self._response = {"error": data.response.error.to_dict()}
        elif isinstance(data, Exception):
            raise data
        # Old handler (once we use msgspec for single multicalls all `data` will be a RawResponse object)
        elif isinstance(data, bytes):
            self._response = {"result": data}
        else:
            raise NotImplementedError(f'type {type(data)} not supported for spoofing.', type(data), data)
        self._done.set()
    
    async def make_request(self) -> RawResponse:
        """Used to execute the request with no batching."""
        self._started = True
        self._response = await self.controller.make_request(self.method, self.params, request_id=self.uid)
        self._done.set()
        return self._response

class eth_call(RPCRequest):
    def __init__(self, controller: "DankMiddlewareController", params: Any) -> None:
        """ Adds a call to the DankMiddlewareContoller's `pending_eth_calls`. """
        super().__init__(controller, "eth_call", params)  # type: ignore
    
    @property
    def block(self) -> BlockId:
        return self.params[1]
    
    @property
    def calldata(self) -> HexBytes:
        return HexBytes(self.params[0]['data'])
    
    @property
    def multicall_compatible(self) -> bool:
        return self.target not in self.controller.no_multicall

    @property
    def target(self) -> str:
        return self.params[0]["to"]

    async def spoof_response(self, data: Union[bytes, Exception]) -> None:  # type: ignore
        """ Sets and returns a spoof rpc response for this BatchedCall instance using data provided by the worker. """
        # NOTE: If multicall failed, make sync call to get either:
        # - revert details
        # - successful response
        if _call_failed(data):
            data = await self.sync_call()
        await super().spoof_response(data)

    async def sync_call(self) -> Union[bytes, Exception]:
        """ Used to bypass DankMiddlewareController. """
        # NOTE: This blocks but should be rare. still needs fixin'
        data = _reattempt_call_and_return_exception(
            self.target, self.calldata, self.block, self.controller.sync_w3
        )
        # If we were able to get a usable response from single call, add contract to `do_not_batch`.
        if not isinstance(data, Exception):
            self.controller.no_multicall.add(self.target)  # type: ignore
        return data


### Batch requests:

_Request = TypeVar("_Request")

class _Batch(_RequestMeta[List[RPCResponse]], Iterable[_Request]):
    calls: List[_Request]

    def __init__(self, controller: "DankMiddlewareController", calls: Iterable[_Request]):
        self.controller = controller
        self.calls = list(calls)  # type: ignore
        self._fut = None
        #self._len = 0
        super().__init__()
    
    def __bool__(self) -> bool:
        return bool(self.calls)
    
    def __getitem__(self, ix: int) -> _Request:
        return self.calls[ix]

    def __iter__(self) -> Iterator[_Request]:
        return iter(self.calls)
    
    def __len__(self) -> int:
        return len(self.calls)
    
    @property
    def halfpoint(self) -> int:
        return len(self) // 2
    
    @property
    def bisected(self) -> Generator[List[_Request], None, None]:
        yield self.chunk0
        yield self.chunk1
        
    @property
    def chunk0(self) -> List[_Request]:
        return self.calls[:self.halfpoint]
    
    @property
    def chunk1(self) -> List[_Request]:
        return self.calls[self.halfpoint:]
    
    def append(self, call: _Request, skip_check: bool = False) -> None:
        self.calls.append(call)
        #self._len += 1
        if not skip_check:
            if self.is_full:
                self.start()
            elif self.controller.queue_is_full:
                self.controller.early_start()
    
    def extend(self, calls: Iterable[_Request], skip_check: bool = False) -> None:
        self.calls.extend(calls)
        #self._len += len(calls)
        if not skip_check:
            if self.is_full:
                self.start()
            elif self.controller.queue_is_full:
                self.controller.early_start()

    def start(self, batch: Optional["_Batch"] = None, cleanup=True) -> None:
        for call in self.calls:
            call.start(batch or self)
        if cleanup:
            self._post_future_cleanup()

    def should_retry(self, e: Exception) -> bool:
        if "out of gas" in f"{e}":
            # TODO Remember which contracts/calls are gas guzzlers
            logger.debug('out of gas. cut in half, trying again')
        elif any(err in f"{e}".lower() for err in RETRY_ERRS):
            # TODO: use these exceptions to optimize for the user's node
            logger.debug('Dank too loud. Bisecting batch and retrying.')
        elif "error processing call Revert" not in f"{e}":
            logger.warning(f"unexpected {e.__class__.__name__}: {e}")
        return len(self) > 1

mcall_encoder = abi.default_codec._registry.get_encoder("(bool,(address,bytes)[])")
mcall_decoder = abi.default_codec._registry.get_decoder("(uint256,uint256,(bool,bytes)[])")

def mcall_encode(data: List[Tuple[bool, bytes]]) -> bytes:
    return mcall_encoder([False, data])

def mcall_decode(data: PartialResponse) -> List[Tuple[bool, bytes]]:
    data = bytes.fromhex(data.decode_result("eth_call")[2:])
    return mcall_decoder(decoding.ContextFramesBytesIO(data))[2]

class Multicall(_Batch[eth_call]):
    method = "eth_call"
    fourbyte = function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")    

    def __init__(self, controller: "DankMiddlewareController", calls: List[eth_call] = [], bid: Optional[BatchId] = None):
        super().__init__(controller, calls)
        self.bid = bid or self.controller.multicall_uid.next
        self._started = False
    
    def __repr__(self) -> str:
        return f"<Multicall mid={self.bid} block={self.block} len={len(self)}>"
    
    @property
    def block(self) -> BlockId:
        return self.calls[0].block
    
    @property
    def calldata(self) -> str:
        return (self.fourbyte + mcall_encode([[call.target, call.calldata] for call in self.calls])).hex()
    
    @property
    def target(self) -> ChecksumAddress:
        return self.controller.multicall2
    
    @property
    def params(self) -> JsonrpcParams:
        if self.controller.state_override_not_supported:
            return [{'to': self.target, 'data': f'0x{self.calldata}'}, self.block]  # type: ignore
        return [{'to': self.target, 'data': f'0x{self.calldata}'}, self.block, {self.target: {'code': constants.OVERRIDE_CODE}}]  # type: ignore
    
    @cached_property
    def request(self) -> Union[Request, PartialRequest]:
        return self.controller.request_type(method=self.method, params=self.params, id=self.uid)
    
    @property
    def is_full(self) -> bool:
        return len(self) >= self.controller.batcher.step

    async def get_response(self) -> None:
        if self._started:
            logger.warning(f'{self} early exit')
            return
        self._started = True
        rid = self.controller.request_uid.next
        demo_logger.info(f'request {rid} for multicall {self.bid} starting')  # type: ignore
        try:
            await self.spoof_response(await self.controller.make_request(self.method, self.params, request_id=self.uid))
        except Exception as e:
            _log_exception(e)
            await (self.bisect_and_retry() if self.should_retry(e) else self.spoof_response(e))  # type: ignore [misc]
        demo_logger.info(f'request {rid} for multicall {self.bid} complete')  # type: ignore
    
    def should_retry(self, e: Exception) -> bool:
        if any(err in f"{e}".lower() for err in RETRY_ERRS):
            logger.debug('dank too loud, trying again')
            self.controller.reduce_batch_size(len(self))
            return True
        elif "No state available for block" in f"{e}":  # NOTE: While it might look weird, f-string is faster than `str(e)`.
            e.args[0]["dankmids_note"] = "You're not using an archive node, and you need one for the application you are attempting to run."
            return False
        elif super().should_retry(e):
            return True
        return len(self) > 1
    
    async def spoof_response(self, data: Union[RawResponse, Exception]) -> None:
        # This happens if an Exception takes place during a singular Multicall request.
        if isinstance(data, Exception):
            return await asyncio.gather(*[call.spoof_response(data) for call in self.calls])
        # These can either be successful or failed, received from jsonrpc batch handling.
        elif isinstance(data, RawResponse):
            response = data.decode(partial=True)
            if response.error:
                raise response.exception
            return await asyncio.gather(*(call.spoof_response(data) for call, (_, data) in zip(self.calls, await self.decode(response))))
        raise NotImplementedError(f"type {type(data)} not supported.", data)
    
    async def decode(self, data: PartialResponse) -> List[Tuple[bool, bytes]]:
        import time
        try:  # NOTE: Quickly check for length without counting each item with `len`.
            self[100]
            return await run_in_subprocess(mcall_decode, data)
        except IndexError:
            start = time.time()
            retval = mcall_decode(data)
            print(f'multicall decoding took {time.time() - start} for {len(self)}')
            return retval
    
    async def bisect_and_retry(self) -> List[RPCResponse]:
        batches = [Multicall(self.controller, chunk, f"{self.bid}_{i}") for i, chunk in enumerate(self.bisected)]
        for batch in batches:
            batch.start(cleanup=False)
        await asyncio.gather(*batches)

    def _post_future_cleanup(self) -> None:
        try:
            # This will have already taken place in a full json batch of multicalls
            for call in self.controller.pending_eth_calls.pop(self.block):
                assert call._started
        except KeyError:
            pass


class JSONRPCBatch(_Batch[Union[Multicall, RPCRequest]]):
    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: List[Union[Multicall, RPCRequest]] = [], 
        jid: Optional[BatchId] = None
    ) -> None:
        super().__init__(controller, calls)
        self.jid = jid or self.controller.jsonrpc_batch_uid.next
        self._started = False

    def __repr__(self) -> str:
        return f"<JSONRPCBatch jid={self.jid} len={len(self)}>"
    
    @property
    def data(self) -> bytes:
        if not self.calls:
            raise EmptyBatch(f"batch {self.uid} is empty and should not be processed.")
        return encode([call.request for call in self.calls])
    
    @property
    def is_multicalls_only(self) -> bool:
        return all(isinstance(call, Multicall) for call in self.calls)

    @property
    def is_single_multicall(self) -> bool:
        return len(self) == 1 and self.is_multicalls_only

    @property
    def method_counts(self) -> Dict[RPCEndpoint, int]:
        counts: DefaultDict[RPCEndpoint, int] = defaultdict(int)
        for call in self.calls:
            counts[call.method] += len(call)  # type: ignore
        return dict(counts)
    
    @property
    def total_calls(self) -> int:
        return sum(len(call) for call in self.calls)

    @property
    def is_full(self) -> bool:
        return (self.is_multicalls_only and len(self) >= self.controller.batcher.step) or len(self) >= _config.MAX_JSONRPC_BATCH_SIZE

    async def get_response(self) -> None:
        if self._started:
            logger.warning(f"{self} exiting early. This shouldn't really happen bro")
            return
        self._started = True
        rid = self.controller.request_uid.next
        if _config.DEMO_MODE:
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} ({sum(len(batch) for batch in self.calls)} calls) starting')  # type: ignore
        try:
            # NOTE: We do this inline so we never have to allocate the response to memory
            await self.spoof_response(await self.post())
        except EmptyBatch as e:
            # NOTE: These shouldn't actually happen and this except clause can probably be removed soon.
            _log_exception(e)
        except Exception as e:
            _log_exception(e)
            await (self.bisect_and_retry() if self.should_retry(e) else self.spoof_response(e))
        demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} complete')  # type: ignore
    
    @eth_retry.auto_retry
    async def post(self) -> List[RawResponse]:
        session = await _session.get_session()
        async with session.post(self.controller.endpoint, data=self.data) as response:
            response: Union[JSONRPCBatchResponse, PartialResponse] = await response.json(loads=decode.jsonrpc_batch)
            # A successful response will be a list of Raw objects, a single PartialResponse implies an error.
            if isinstance(response, list):
                return [RawResponse(raw) for raw in response]
            # Oops, we failed.
            logger.info(
                "jsonrpc batch failed\n"
                + f"json batch id: {self.jid} | len: {len(self)} | total calls: {self.total_calls}\n"
                + f"methods called: {self.method_counts}"
            )
            if 'content length too large' in response.error.message and self.is_multicalls_only:
                self.controller.reduce_batch_size(self.total_calls)
            raise response.exception
    
    def should_retry(self, e: Exception) -> bool:
        # While it might look weird, f-string is faster than `str(e)`.
        if "No state available for block" in f"{e}":
            logger.debug('No state available for queried block. Bisecting batch and retrying.')
            return True
        elif super().should_retry(e):
            return True
        return self.is_single_multicall
    
    async def spoof_response(self, response: Union[List[RawResponse], Exception]) -> None:
        # This means an exception occurred during the post request
        if isinstance(response, Exception):
            return await asyncio.gather(*[call.spoof_response(response) for call in self.calls])
        # This means we got results
        return await asyncio.gather(*[call.spoof_response(raw) for call, raw in zip(self.calls, response)])
    
    async def bisect_and_retry(self) -> None:
        batches = [
            Multicall(self.controller, chunk[0].calls, f"json{self.jid}_{i}")  # type: ignore [misc]
            if len(chunk) == 1 and isinstance(chunk[0], Multicall)
            else JSONRPCBatch(self.controller, chunk, f"{self.jid}_{i}")
            for i, chunk in enumerate(self.bisected)
            if chunk
        ]
        for batch in batches:
            batch.start(cleanup=False)
        await asyncio.gather(*batches)

    def _post_future_cleanup(self) -> None:
        self.controller.pending_rpc_calls = JSONRPCBatch(self.controller)
