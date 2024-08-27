
import abc
import asyncio
import logging
import time
import weakref
from collections import defaultdict
from concurrent.futures.process import BrokenProcessPool
from contextlib import suppress
from functools import cached_property, lru_cache
from typing import (TYPE_CHECKING, Any, DefaultDict, Dict, Generator, Generic,
                    Iterable, Iterator, List, Optional, Tuple, TypeVar, Union,
                    overload)

import a_sync
import eth_retry
from a_sync import AsyncProcessPoolExecutor, PruningThreadPoolExecutor
from aiohttp.client_exceptions import ClientResponseError
from eth_abi import abi, decoding
from eth_typing import ChecksumAddress
from eth_utils import function_signature_to_4byte_selector
from hexbytes import HexBytes
from web3.types import RPCEndpoint, RPCResponse
from web3.types import RPCError as _RPCError

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids import _debugging, constants, stats
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import (BadResponse, BatchResponseSortError,
                                   DankMidsClientResponseError, DankMidsInternalError, 
                                   EmptyBatch, ExceedsMaxBatchSize, PayloadTooLarge,
                                   ResponseNotReady, internal_err_types)
from dank_mids._uid import _AlertingRLock
from dank_mids.helpers import _codec, _session
from dank_mids.helpers._helpers import set_done
from dank_mids.types import (BatchId, BlockId, JSONRPCBatchResponse,
                             JsonrpcParams, PartialRequest, PartialResponse,
                             RawResponse, Request, Response)

if TYPE_CHECKING:
    from dank_mids._batch import DankBatch
    from dank_mids.controller import (DankMiddlewareController,
                                      _MulticallContract)


logger = logging.getLogger(__name__)

_Response = TypeVar("_Response", Response, List[Response], RPCResponse, List[RPCResponse], RawResponse)

class RPCError(_RPCError, total=False):
    dankmids_added_context: Dict[str, Any]

class _RequestEvent(a_sync.Event):
    def __init__(self, owner: "_RequestMeta") -> None:
        super().__init__(debug_daemon_interval=300)
        self._owner = weakref.proxy(owner)
    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} object at {hex(id(self))} [{'set' if self.is_set() else 'unset'}, waiter:{self._owner}>"
    def set(self):
        # Make sure we wake up the _RequestEvent's event loop if its in another thread
        if asyncio.get_running_loop() == self._loop:
            super().set()
        else:
            self._loop.call_soon_threadsafe(super().set)

class _RequestMeta(Generic[_Response], metaclass=abc.ABCMeta):
    __slots__ = 'controller', 'uid', '_response', '_done', '_start', '_batch', '__weakref__'
    controller: "DankMiddlewareController"
    def __init__(self) -> None:
        self.uid = self.controller.call_uid.next
        self._response: Union[_Response, RPCResponse, Exception, None] = None
        self._done = _RequestEvent(self)
        self._start = time.time()
    
    def __await__(self) -> Generator[Any, None, _Response]:
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
    async def get_response(self) -> _Response:
        pass
    
    @abc.abstractmethod
    def start(self, batch: Union["_Batch", "DankBatch", None] = None) -> None:
        pass

    async def _debug_daemon(self) -> None:
        # NOTE: _resonse works for RPCRequst and eth_call, _done works for _Batch classes
        while self and self._response is None and not self._done.is_set():
            await asyncio.sleep(60)
            if not self._done.is_set():
                logger.debug(f"{self} has not received data after {time.time() - self._start}s")
            

### Single requests:

BYPASS_METHODS = "eth_blockNumber", "eth_getLogs", "trace_", "debug_"

@lru_cache(maxsize=None)
def _should_batch_method(method: str) -> bool:
    return all(bypass not in method for bypass in BYPASS_METHODS)

class RPCRequest(_RequestMeta[RawResponse]):
    __slots__ = 'method', 'params', 'should_batch', '_started', '_retry', '_daemon'
    def __init__(self, controller: "DankMiddlewareController", method: RPCEndpoint, params: Any, retry: bool = False):
        self.controller = controller
        """The DankMiddlewareController that created this request."""
        self.method = method
        """The rpc method for this request."""
        self.params = params
        """The parameters to send with this request, if any."""
        self.should_batch = _should_batch_method(method)
        """Returns `True` if this request should be batched with others into a jsonrpc batch request, `False` if it should be sent as an individual request."""
        self._started = False
        self._retry = retry
        super().__init__()

        with self.controller.pools_closed_lock:
            if isinstance(self, eth_call) and self.multicall_compatible:
                self.controller.pending_eth_calls[self.block].append(self)
            else:
                self.controller.pending_rpc_calls.append(self)
        demo_logger.info(f'added to queue (cid: {self.uid})')  # type: ignore
        if logger.isEnabledFor(logging.DEBUG):
            self._daemon = asyncio.create_task(self._debug_daemon())
    
    def __eq__(self, __o: object) -> bool:
        return self.uid == __o.uid if isinstance(__o, self.__class__) else False 
    
    def __len__(self) -> int:
        # we dont need to consider this for v small batch sizes
        if ENVS.MAX_JSONRPC_BATCH_SIZE > 50:  # type: ignore [operator]
            # NOTE: These are totally arbitrary
            if self.method == "eth_getTransactionReceipt":
                return 10
            elif any(m in self.method for m in ["eth_getCode" "eth_getBlockBy", "eth_getTransaction"]):
                return 6
        return 1
    
    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} uid={self.uid} method={self.method} params={self.params}>"

    @property
    def request(self) -> Union[Request, PartialRequest]:
        return self.controller.request_type(method=self.method, params=self.params, id=self.uid)
    
    def start(self, batch: Union["_Batch", "DankBatch"]) -> None:  # type: ignore [override]
        self._started = True
        self._batch = batch

    @set_done
    async def get_response(self) -> RPCResponse:  # type: ignore [override]
        if not self.should_batch:
            logger.debug(f"bypassed, method is {self.method}")
            try:
                await asyncio.wait_for(self.make_request(), timeout=ENVS.STUCK_CALL_TIMEOUT)  # type: ignore [arg-type]
            except asyncio.TimeoutError:
                return await self.create_duplicate()
            return self.response.decode(partial=True).to_dict(self.method)
        
        if self._started and not self._batch._started:
            # NOTE: If we're already started, we filled a batch. Let's await it now so we can send something to the node.
            await self._batch
        if not self._started:
            # NOTE: We want to force the event loop to make one full _run_once call before we execute.
            await asyncio.sleep(0)
        if not self._started:
            try:
                await asyncio.wait_for(
                    # If this timeout fails, we go nuclear and destroy the batch.
                    # Any calls that already succeeded will have already completed on the client side.
                    # Any calls that have not yet completed with results will be recreated, rebatched (potentially bringing better results?), and retried
                    self.controller.execute_batch(),
                    timeout=ENVS.STUCK_CALL_TIMEOUT,  # type: ignore [arg-type]
                )
            except asyncio.TimeoutError:
                return await self.create_duplicate()
        
        try:
            await asyncio.wait_for(self._done.wait(), timeout=ENVS.STUCK_CALL_TIMEOUT)  # type: ignore [arg-type]
        except asyncio.TimeoutError:
            return await self.create_duplicate()

        # JIT json decoding
        if isinstance(self.response, RawResponse):
            response = self.response.decode(partial=True).to_dict(self.method)
            error: Optional[RPCError]
            if error := response.get('error'):  # type: ignore [assignment]
                if error['message'].lower() in ['invalid request', 'parse error']:
                    if self.controller._time_of_request_type_change == 0:
                        self.controller.request_type = Request
                        self.controller._time_of_request_type_change = time.time()
                    if time.time() - self.controller._time_of_request_type_change <= 600:
                        logger.debug("your node says the partial request was invalid but its okay, we can use the full jsonrpc spec instead")
                        return await self.controller(self.method, self.params)
                error['dankmids_added_context'] = self.request.to_dict()
                # I'm 99.99999% sure that any errd call has no result and we only get this field from mscspec object defs
                # But I'll check it anyway to be safe
                if result := response.pop('result', None):
                    response['result'] = result
                logger.debug("error response for %s: %s", self, response)
            return response
    
        # If we have an Exception here it came from the goofy sync_call thing I need to get rid of.
        # We raise it here so it traces back up to the caller
        if isinstance(self.response, ClientResponseError):
            raise DankMidsClientResponseError(self.response, self.request) from self.response
        if isinstance(self.response, Exception):
            try:
                more_detailed_exc = self.response.__class__(self.response, self.request)
            except Exception as e:
                self.response.request = self.request
                self.response._dank_mids_exception = e
                raise self.response
            raise more_detailed_exc from None
        # Less optimal decoding
        # TODO: refactor this out
        return self.response
    
    @set_done
    async def spoof_response(self, data: Union[RawResponse, bytes, Exception]) -> None:
        # sourcery skip: merge-duplicate-blocks
        """
        `Raw` type data comes from rpc calls executed in a jsonrpc batch
        `bytes` type data comes for individual eth_calls that were batched into multicalls and already decoded
        `Exception` type data comes from failed calls
        """
        
        # New handler
        if isinstance(data, RawResponse):
            self._response = data
        elif isinstance(data, BadResponse):
            if data.response.error.message.lower() in ['invalid request', 'parse error']:  # type: ignore [union-attr]
                if self.controller._time_of_request_type_change == 0:
                    self.controller.request_type = Request
                    self.controller._time_of_request_type_change = int(time.time())
                if time.time() - self.controller._time_of_request_type_change <= 600:
                    logger.debug("your node says the partial request was invalid but its okay, we can use the full jsonrpc spec instead")
                    self._response = await self.create_duplicate()
                    return
            error = data.response.error.to_dict()  # type: ignore [union-attr]
            error['dankmids_added_context'] = self.request.to_dict()
            self._response = {"error": error}
            logger.debug("%s _response set to rpc error response %s", self, self._response)
        elif isinstance(data, Exception):
            logger.debug("%s _response set to Exception %s", self, data)
            self._response = data
        # From multicalls
        elif isinstance(data, bytes):
            self._response = {"result": data}
        else:
            raise NotImplementedError(f'type {type(data)} not supported for spoofing.', type(data), data)
    
    @set_done
    async def make_request(self) -> RawResponse:
        """Used to execute the request with no batching."""
        self._started = True
        self._response = await self.controller.make_request(self.method, self.params, request_id=self.uid)
        return self._response
    
    @property
    def semaphore(self) -> a_sync.Semaphore:
        # NOTE: We cannot cache this property so the semaphore control pattern in the `duplicate` fn will work as intended
        if self.method == 'eth_call':
            return self.controller.eth_call_semaphores[self.params[1]]
        return self.controller.method_semaphores[self.method]  # type: ignore [return-value]
    
    async def create_duplicate(self) -> RPCResponse: # Not actually self, but for typing purposes it is.
        # We need to make room since the stalled call is still holding the semaphore
        self.semaphore.release()
        # We need to check the semaphore again to ensure we have the right context manager, soon but not right away.
        # Creating the task before awaiting the new call ensures the new call will grab the semaphore immediately
        # and then the task will try to acquire at the very next event loop _run_once cycle
        logger.warning("%s got stuck, we're creating a new one", self)
        retval = await self.controller(self.method, self.params)
        await self.semaphore.acquire()
        return retval


INDIVIDUAL_CALL_REVERT_STRINGS = {
    "invalid opcode",
    "missing trie node",
    "resource not found",
    "invalid ether transfer", 
    "error processing call revert", 
}
    
revert_threads = PruningThreadPoolExecutor(4)

def _is_call_revert(e: BadResponse) -> bool:
    """Returns True if a particular `BadResponse` for a multicall was caused by a failure in one of the individual calls it contained, False for any other reason"""
    stre = f"{e}"
    return any(s in stre for s in INDIVIDUAL_CALL_REVERT_STRINGS)

def _needs_full_request_spec(e: BadResponse):
    """Returns True if this particular `BadResponse` indicates that the node we are using requires the full request spec. Dank mids will detect this and changeover automagically."""


class eth_call(RPCRequest):
    __slots__ = 'block'
    def __init__(self, controller: "DankMiddlewareController", params: Any, retry: bool = False) -> None:
        """ Adds a call to the DankMiddlewareContoller's `pending_eth_calls`. """
        self.block: BlockId = params[1]
        """The block height at which the contract will be called."""
        super().__init__(controller, "eth_call", params)  # type: ignore
    
    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} uid={self.uid} params={self.params}>"
    
    @property
    def calldata(self) -> HexBytes:
        """The calldata for the call."""
        return HexBytes(self.params[0]['data'])
    
    @property
    def multicall_compatible(self) -> bool:
        """True if this contract is multicall compatible, False if not."""
        return self.target not in self.controller.no_multicall

    @property
    def target(self) -> ChecksumAddress:
        """The contract address for the call."""
        return self.params[0]["to"]

    async def spoof_response(self, data: Union[bytes, Exception, RawResponse]) -> None:  # type: ignore
        """ Sets and returns a spoof rpc response for this BatchedCall instance using data provided by the worker. """

        # NOTE: If `type(data)` is `bytes`, it is a result from a multicall. If not, `data` comes from a jsonrpc batch.
        # If this if clause is True, it means the call reverted inside of a multicall but returned a result, without causing the multicall to revert.
        if isinstance(data, bytes) and any(data.startswith(selector) for selector in constants.REVERT_SELECTORS):
            # TODO figure out how to include method selector in no_multicall key
            try:
                # NOTE: If call response from multicall indicates failure, make sync call to get either:
                # - successful response
                # - revert details from exception
                # If we get a successful response, most likely the target contract does not support multicall2.
                # TODO: Get rid of the sync executor and just use `make_request`
                data = await asyncio.get_event_loop().run_in_executor(revert_threads, self.controller.sync_w3.eth.call, {"to": self.target, "data": self.calldata}, self.block)
                # The single call was successful. We don't want to include this contract in more multicalls
                self.controller.no_multicall.add(self.target)
            except Exception as e:
                # NOTE: The call still returns a revert when it's not packed in a multicall
                data = e
        # The above revert catching logic fails to account for pre-decoding RawResponse objects.
        await super().spoof_response(data)
    
    @property
    def semaphore(self) -> a_sync.Semaphore:
        # NOTE: We cannot cache this property so the semaphore control pattern in the `duplicate` fn will work as intended
        return self.controller.eth_call_semaphores[self.block]
    
    

### Batch requests:

_Request = TypeVar("_Request", bound=_RequestMeta)

class _Batch(_RequestMeta[List[_Response]], Iterable[_Request]):
    __slots__ = '_calls', '_lock', '_daemon'
    _calls: List["weakref.ref[_Request]"]
    def __init__(self, controller: "DankMiddlewareController", calls: Iterable[_Request]):
        self.controller = controller
        self._calls = [weakref.ref(call) for call in calls]
        self._lock = _AlertingRLock(name=self.__class__.__name__)
        super().__init__()
    
    def __bool__(self) -> bool:
        return bool(self.calls)
    
    @overload
    def __getitem__(self, ix: int) -> _Request:...
    @overload
    def __getitem__(self, ix: slice) -> List[_Request]:...
    def __getitem__(self, ix: Union[int, slice]) -> Union[_Request, List[_Request]]:
        return self.calls[ix]

    def __iter__(self) -> Iterator[_Request]:
        return iter(self.calls)
    
    def __len__(self) -> int:
        return len(self.calls)
    
    @property
    def calls(self) -> List[_Request]:
        "Returns a list of calls. Creates a temporary strong reference to each call in the batch, if it still exists."
        return [call for ref in self._calls if (call := ref())]

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

    @property
    def is_full(self) -> bool:
        raise NotImplementedError(type(self).__name__)
    
    def append(self, call: _Request, skip_check: bool = False) -> None:
        with self._lock:
            self._calls.append(weakref.ref(call))
            #self._len += 1
            if not skip_check:
                if self.is_full:
                    self.start()
                elif self.controller.queue_is_full:
                    self.controller.early_start()
    
    def extend(self, calls: Iterable[_Request], skip_check: bool = False) -> None:
        with self._lock:
            self._calls.extend(weakref.ref(call) for call in calls)
            if not skip_check:
                if self.is_full:
                    self.start()
                elif self.controller.queue_is_full:
                    self.controller.early_start()

    def start(self, batch: Optional[Union["_Batch", "DankBatch"]] = None, cleanup=True) -> None:
        if logger.isEnabledFor(logging.DEBUG):
            self._daemon = asyncio.create_task(self._debug_daemon())
        with self._lock:
            for call in self.calls:
                call.start(batch or self)
            if cleanup:
                self._post_future_cleanup()

    def should_retry(self, e: Exception) -> bool:
        """Should the _Batch be retried based on `e`?"""
        if "out of gas" in f"{e}":
            # TODO Remember which contracts/calls are gas guzzlers
            logger.debug('out of gas. cut in half, trying again')
        elif any(err in f"{e}".lower() for err in constants.RETRY_ERRS):
            # TODO: use these exceptions to optimize for the user's node
            logger.debug('Dank too loud. Bisecting batch and retrying.')
        elif isinstance(e, BadResponse) and (_needs_full_request_spec(e) or _is_call_revert(e)):
            pass
        elif "429" not in f"{e}":
            logger.warning(f"unexpected {e.__class__.__name__}: {e}")
        return len(self) > 1
      
    def _post_future_cleanup(self) -> None:
        raise NotImplementedError

mcall_encoder = abi.default_codec._registry.get_encoder("(bool,(address,bytes)[])")
mcall_decoder = abi.default_codec._registry.get_decoder("(uint256,uint256,(bool,bytes)[])")

def mcall_encode(data: List[Tuple[bool, bytes]]) -> bytes:
    return mcall_encoder([False, data])

def mcall_decode(data: PartialResponse) -> Union[List[Tuple[bool, bytes]], Exception]:        
    try:
        decoded = data.decode_result("eth_call")[2:]  # type: ignore [arg-type]
        decoded = bytes.fromhex(decoded)
        return mcall_decoder(decoding.ContextFramesBytesIO(decoded))[2]
    except Exception as e:
        # NOTE: We need to safely bring any Exceptions back out of the ProcessPool
        try:
            # We do this goofy thing since we can't `return Exc() from e`
            raise e.__class__(*e.args, data.decode_result() if isinstance(data, PartialResponse) else data) from e
        except Exception as new_e:
            return new_e
    

class Multicall(_Batch[RPCResponse, eth_call]):
    __slots__ = 'bid', '_started', '__dict__'  # We need to specify __dict__ for the cached properties to work
    method = "eth_call"
    fourbyte = function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")    

    def __init__(self, controller: "DankMiddlewareController", calls: List[eth_call] = [], bid: Optional[BatchId] = None):
        # sourcery skip: default-mutable-arg
        super().__init__(controller, calls)
        self.bid = bid or self.controller.multicall_uid.next
        self._started = False
    
    def __repr__(self) -> str:
        return f"<Multicall mid={self.bid} block={self.block} len={len(self)}>"
    
    @cached_property
    def block(self) -> BlockId:
        return self.calls[0].block
    
    @property
    def calldata(self) -> str:
        return (self.fourbyte + mcall_encode([[call.target, call.calldata] for call in self.calls])).hex()  # type: ignore [misc]
    
    @property
    def target(self) -> ChecksumAddress:
        return self.mcall.address
    
    @cached_property
    def mcall(self) -> "_MulticallContract":
        return self.controller._select_mcall_target_for_block(self.block)
    
    @property
    def params(self) -> JsonrpcParams:
        params = [{'to': self.target, 'data': f'0x{self.calldata}'}, self.block]
        if self.needs_override_code and not self.controller.state_override_not_supported:
            params.append({self.target: {'code': self.mcall.bytecode}})
        return params  # type: ignore [return-value]
    
    @property
    def request(self) -> Union[Request, PartialRequest]:
        return self.controller.request_type(method=self.method, params=self.params, id=self.uid)
    
    @property
    def is_full(self) -> bool:
        return len(self) >= self.controller.batcher.step

    @property
    def needs_override_code(self) -> bool:
        return self.mcall.needs_override_code_for_block(self.block)
        
    async def get_response(self) -> None:  # type: ignore [override]
        if self._started:
            logger.error(f'{self} early exit')
            return
        self._started = True
        if (l := len(self)) == 1:
            return await self._exec_single_call()
        #elif l < 50: # TODO play with later
        #    return await JSONRPCBatch(self.controller, self.calls)
        rid = self.controller.request_uid.next
        demo_logger.info(f'request {rid} for multicall {self.bid} starting')  # type: ignore
        try:
            # create a strong ref to all calls we will execute so they cant get gced mid execution and mess up response ordering
            calls = self.calls
            await self.spoof_response(await self.controller.make_request(self.method, self.params, request_id=self.uid), calls)
        except internal_err_types.__args__ as e:  # type: ignore [attr-defined]
            raise e if 'invalid argument' in str(e) else DankMidsInternalError(e) from e
        except ClientResponseError as e:
            if e.message == "Payload Too Large":
                logger.info("Payload too large. response headers: %s", e.headers)
                self.controller.reduce_multicall_size(len(self))
                _debugging.failures.record(self.controller.chain_id, e, type(self).__name__, self.uid, len(self), self.request.data)
            else:
                if _log_exception(e):
                    _debugging.failures.record(self.controller.chain_id, e, type(self).__name__, self.uid, len(self), self.request.data)
            await (self.bisect_and_retry(e) if self.should_retry(e) else self.spoof_response(e))  # type: ignore [misc]
        except Exception as e:
            if _log_exception(e):
                _debugging.failures.record(self.controller.chain_id, e, type(self).__name__, self.uid, len(self), self.request.data)
            await (self.bisect_and_retry(e) if self.should_retry(e) else self.spoof_response(e))  # type: ignore [misc]
        demo_logger.info(f'request {rid} for multicall {self.bid} complete')  # type: ignore
    
    def should_retry(self, e: Exception) -> bool:
        """Should the Multicall be retried based on `e`?"""
        if any(err in f"{e}".lower() for err in constants.RETRY_ERRS):
            logger.debug('dank too loud, trying again')
            return True
        elif "No state available for block" in f"{e}":  # NOTE: While it might look weird, f-string is faster than `str(e)`.
            e.args[0]["dankmids_note"] = "You're not using an archive node, and you need one for the application you are attempting to run."
            return False
        elif super().should_retry(e):
            return True
        return len(self) > 1
    
    @set_done
    async def spoof_response(self, data: Union[RawResponse, Exception], calls: Optional[List[eth_call]] = None) -> None:
        # NOTE: we pass in the calls to create a strong reference so when we zip up the results everything gets to the right place
        if calls is None:
            calls = self.calls
        # This happens if an Exception takes place during a singular Multicall request.
        if isinstance(data, Exception):
            logger.debug("%s had Exception %s", self, data)
            logger.debug("propagating the %s to all %s's calls", data.__class__.__name__, self)
            await asyncio.gather(*[call.spoof_response(data) for call in calls])
        # A `RawResponse` represents either a successful or a failed response, stored as pre-decoded bytes.
        # It was either received as a response to a single rpc call or as a part of a batch response.
        elif isinstance(data, RawResponse):
            response = data.decode(partial=True)
            if response.error:
                logger.debug("%s received an 'error' response from the rpc: %s", self, response.exception)
                # NOTE: We raise the exception which will be caught, call will be broken up and retried
                raise response.exception
            logger.debug("%s received valid bytes from the rpc", self)
            await asyncio.gather(*(call.spoof_response(data) for call, (_, data) in zip(calls, await self.decode(response))))
        else:
            raise NotImplementedError(f"type {type(data)} not supported.", data)
    
    async def decode(self, data: PartialResponse) -> List[Tuple[bool, bytes]]:
        start = time.time()
        if ENVS.OPERATION_MODE.infura:  # type: ignore [attr-defined]
            retval = mcall_decode(data)
        else:
            try:  # NOTE: Quickly check for length without counting each item with `len`.
                if not ENVS.OPERATION_MODE.application:  # type: ignore [attr-defined]
                    self[100]
                retval = await ENVS.MULTICALL_DECODER_PROCESSES.run(mcall_decode, data)  # type: ignore [attr-defined]
            except IndexError:
                retval = mcall_decode(data)
            except BrokenProcessPool:
                # TODO: Move this somewhere else
                logger.critical("Oh fuck, you broke the %s while decoding %s", ENVS.MULTICALL_DECODER_PROCESSES, data)  # type: ignore [attr-defined]
                ENVS.MULTICALL_DECODER_PROCESSES = AsyncProcessPoolExecutor(ENVS.MULTICALL_DECODER_PROCESSES._max_workers)  # type: ignore [attr-defined,assignment]
                retval = mcall_decode(data)
        stats.log_duration(f"multicall decoding for {len(self)} calls", start)
        # Raise any Exceptions that may have come out of the process pool.
        if isinstance(retval, Exception):
            raise retval.__class__(*retval.args, self.request.to_dict(), f"response: {data.to_dict()}", f"error: {data.error.to_dict() if data.error else None}")
        return retval
    
    @set_done
    async def bisect_and_retry(self, e: Exception) -> List[RPCResponse]:
        """
        Splits up the calls of a `Multicall` into 2 chunks, then awaits both.
        Calls `self._done.set()` when finished.
        """
        logger.debug("%s had exception %s, bisecting and retrying", self, e)
        batches = [Multicall(self.controller, chunk, f"{self.bid}_{i}") for i, chunk in enumerate(self.bisected)]
        for batch in batches:
            batch.start(cleanup=False)
        for batch, result in zip(batches, await asyncio.gather(*batches, return_exceptions=True)):
            if isinstance(result, Exception):
                if not isinstance(result, DankMidsInternalError):
                    logger.error(f"That's not good, there was an exception in a {batch.__class__.__name__}. These are supposed to be handled.\n{result}\n", exc_info=True)
                raise result

    @set_done
    async def _exec_single_call(self) -> None:
        await self.calls[0].make_request()

    def _post_future_cleanup(self) -> None:
        with suppress(KeyError):
            with self.controller.pools_closed_lock:
                # This will have already taken place in a full json batch of multicalls
                self.controller.pending_eth_calls.pop(self.block)


class JSONRPCBatch(_Batch[RPCResponse, Union[Multicall, RPCRequest]]):
    __slots__ = 'jid', '_started'
    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: List[Union[Multicall, RPCRequest]] = [], 
        jid: Optional[BatchId] = None
    ) -> None:  # sourcery skip: default-mutable-arg
        super().__init__(controller, calls)
        self.jid = jid or self.controller.jsonrpc_batch_uid.next
        self._started = False

    def __repr__(self) -> str:
        return f"<JSONRPCBatch jid={self.jid} len={len(self)}>"
    
    @property
    def data(self) -> bytes:
        if not self:
            raise EmptyBatch(f"batch {self.uid} is empty and should not be processed.")
        try:
            return _codec.encode([call.request for call in self])
        except TypeError:
            # If we can't encode one of the calls, lets figure out which one and pass some useful info downstream
            for call in self:
                try:
                    _codec.encode(call.request)
                except TypeError as e:
                    raise TypeError(e, call.request) from None
            raise
    
    @property
    def is_multicalls_only(self) -> bool:
        with self._lock:
            return all(isinstance(call, Multicall) for call in self)

    @property
    def is_single_multicall(self) -> bool:
        with self._lock:
            return len(self) == 1 and self.is_multicalls_only

    @property
    def method_counts(self) -> Dict[RPCEndpoint, int]:
        counts: DefaultDict[RPCEndpoint, int] = defaultdict(int)
        with self._lock:
            for call in self:
                if isinstance(call, Multicall):
                    counts["eth_call[multicall]"] += len(call)  # type: ignore
                else:
                    counts[call.method] += 1
            return dict(counts)
    
    @property
    def total_calls(self) -> int:
        with self._lock:
            return sum(len(call) for call in self)

    @property
    def is_full(self) -> bool:
        with self._lock:
            return self.total_calls >= self.controller.batcher.step or len(self) >= ENVS.MAX_JSONRPC_BATCH_SIZE  # type: ignore [attr-defined,operator]

    async def get_response(self) -> None:  # type: ignore [override]
        if self._started:
            logger.warning(f"{self} exiting early. This shouldn't really happen bro")
            return
        self._started = True
        rid = self.controller.request_uid.next
        if ENVS.DEMO_MODE:  # type: ignore [attr-defined]
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} ({sum(len(batch) for batch in self)} calls) starting')  # type: ignore
        try:
            # NOTE: We do this inline so we never have to allocate the response to memory
            await self.spoof_response(*await self.post())
        except BatchResponseSortError:
            raise
        # I want to see these asap when working on the lib.
        except internal_err_types.__args__ as e:  # type: ignore [attr-defined]
            raise e if 'invalid argument' in str(e) else DankMidsInternalError(e) from e
        except EmptyBatch as e:
            logger.warning("These EmptyBatch exceptions shouldn't actually happen and this except clause can probably be removed soon.")
        except ExceedsMaxBatchSize as e:
            logger.warning("exceeded max batch size for your node")
            self.controller.set_batch_size_limit(e.limit)
            await self.bisect_and_retry(e)
        except PayloadTooLarge as e:
            # TODO: track too large payloads and do some better optimizations for batch sizing
            self.adjust_batch_size()
            await self.bisect_and_retry(e)
        except Exception as e:
            if _log_exception(e):
                _debugging.failures.record(self.controller.chain_id, e, type(self).__name__, self.uid, len(self), self.data)
            stats.log_errd_batch(self)
            if self.should_retry(e):
                await self.bisect_and_retry(e)
            # NOTE: `self.should_retry(e)` can only return False here if the json batch is comprised of just one rpc request that is not a multicall.
            #       I include this elif clause as a failsafe. This is rare and should not impact performance.
            elif not self.is_single_multicall:
                # Just to force my IDE to resolve types correctly
                calls : List[RPCRequest] = self.calls # type: ignore [assignment]
                logger.debug("%s had exception %s, aborting and setting Exception as call._response", self, e)
                # NOTE: This means an exception occurred during the post request
                # AND that the json batch is made of just one rpc request that is not a multicall.
                logger.info('does this ever actually run? pretty sure a single-multicall json batch is not possible. can I delete this?')
                await asyncio.gather(*[call.spoof_response(e) for call in calls])
            else:
                raise NotImplementedError('and you may ask yourself, well, how did I get here?')
        demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} complete')  # type: ignore
    
    @eth_retry.auto_retry
    async def post(self) -> Tuple[List[RawResponse], List[Union[Multicall, RPCRequest]]]:
        "this function raises `BadResponse` if a successful 'error' response was received from the rpc"
        try:
            # we need strong refs so the results all get to the right place
            calls = self.calls
            # for the multicalls too
            mcall_calls_strong_refs = [call.calls for call in filter(lambda x: isinstance(x, Multicall), calls)]  # type: ignore [union-attr]
            response: JSONRPCBatchResponse = await _session.post(self.controller.endpoint, data=self.data, loads=_codec.decode_jsonrpc_batch)
        except ClientResponseError as e:
            if e.message == "Payload Too Large":
                logger.warning("Payload Too Large")
                logger.warning("This is what was too large: %s", self.method_counts)
                self.adjust_batch_size()
            elif 'broken pipe' in str(e).lower():
                logger.warning("This is what broke the pipe: %s", self.method_counts)
            logger.debug("caught %s for %s, reraising", e, self)
            if ENVS.DEBUG:  # type: ignore [attr-defined]
                _debugging.failures.record(self.controller.chain_id, e, type(self).__name__, self.uid, len(self), self.data)
            raise e
        except Exception as e:
            if 'broken pipe' in str(e).lower():
                logger.warning("This is what broke the pipe: %s", self.method_counts)
            if ENVS.DEBUG:  # type: ignore [attr-defined]
                _debugging.failures.record(self.controller.chain_id, e, type(self).__name__, self.uid, len(self), self.data)
            raise e
        # NOTE: A successful response will be a list of `RawResponse` objects.
        #       A single `PartialResponse` implies an error.
        if isinstance(response, list):
            return response, calls
        # Oops, we failed.
        if response.error.message.lower() in ['invalid request', 'parse error']:  # type: ignore [union-attr]
            # NOT SURE IF THIS ACTUALLY RUNS, CAN WE RECEIVE THIS TYPE RESPONSE FOR A JSON BATCH?
            if self.controller._time_of_request_type_change == 0:
                self.controller.request_type = Request
                self.controller._time_of_request_type_change = time.time()
            if time.time() - self.controller._time_of_request_type_change <= 600:
                logger.debug("your node says the partial request was invalid but its okay, we can use the full jsonrpc spec instead")
        elif response.error.message == "batch limit exceeded":  # type: ignore [union-attr]
            self.adjust_batch_size()
            
        if ENVS.DEBUG:
            _debugging.failures.record(self.controller.chain_id, response.exception, type(self).__name__, self.uid, len(self), self.data)
        raise response.exception
    
    def should_retry(self, e: Exception) -> bool:
        """Should the JSONRPCBatch be retried based on `e`?"""
        # While it might look weird, f-string is faster than `str(e)`.
        if "No state available for block" in f"{e}":
            logger.debug('No state available for one of the blocks queried. Bisecting batch and retrying.')
            return True
        elif super().should_retry(e):
            return True
        return self.is_single_multicall
    
    @set_done
    async def spoof_response(self, response: List[RawResponse], calls: List[RPCRequest]) -> None:
        # This means we got results. That doesn't mean they're good, but we got 'em.
        
        if self.controller._sort_calls:
            # NOTE: these providers don't always return batch results in the correct ordering
            # NOTE: is it maybe because they 
            calls = sorted(calls, key=lambda call: call.uid)
            for call, raw in zip(calls, response):
                # TODO: make sure this doesn't ever raise and then delete it
                decoded = raw.decode()
                if call.uid != decoded.id:
                    raise BatchResponseSortError(calls, response)
            
        for r in await asyncio.gather(*[call.spoof_response(raw) for call, raw in zip(calls, response)], return_exceptions=True):
            # NOTE: By doing this with the exceptions we allow any successful calls to get their results sooner
            #       without being interrupted by the first exc in the gather and having to wait for the bisect and retry process
            # TODO: stop retrying ones that succeed, that's wasteful
            if isinstance(r, Exception):
                raise r
    
    @set_done
    async def bisect_and_retry(self, e: Exception) -> None:
        """
        Splits up the calls of a `JSONRPCBatch` into 2 chunks, then awaits both.
        If one chunk is just a single multicall, it will be handled alone, not be placed into a batch.
        Calls `self._done.set()` when finished.
        """
        logger.debug("%s had exception %s, retrying", self, e)
        batches = [
            Multicall(self.controller, chunk[0].calls, f"json{self.jid}_{i}")  # type: ignore [misc]
            if len(chunk) == 1 and isinstance(chunk[0], Multicall)
            else JSONRPCBatch(self.controller, chunk, f"{self.jid}_{i}")
            for i, chunk in enumerate(self.bisected)
            if chunk
        ]
        for batch in batches:
            batch.start(cleanup=False)
        for batch, result in zip(batches, await asyncio.gather(*batches, return_exceptions=True)):
            if isinstance(result, Exception):
                if not isinstance(result, DankMidsInternalError):
                    logger.error(f"That's not good, there was an exception in a {batch.__class__.__name__}. These are supposed to be handled.\n{result}\n", exc_info=True)
                raise result
    
    def adjust_batch_size(self) -> None:
        if self.is_multicalls_only:
            logger.info('checking if we should reduce multicall batch size... (%s calls)', self.total_calls)
            self.controller.reduce_multicall_size(self.total_calls)
        else:
            logger.info('checking if we should reduce json batch size... (%s requests)', len(self))
            self.controller.reduce_batch_size(len(self))
            stats.logger.devhint(
                "We still need some better logic for catching these errors and using them to better optimize the batching process"
            )

    def _post_future_cleanup(self) -> None:
        with self.controller.pools_closed_lock:
            self.controller.pending_rpc_calls = JSONRPCBatch(self.controller)

def _log_exception(e: Exception) -> bool:
    # NOTE: These errors are expected during normal use and are not indicative of any problem(s). No need to log them.
    # TODO: Better filter what we choose to log here
    dont_need_to_see_errs = constants.RETRY_ERRS + ['out of gas', 'non_empty_data', 'exceeding --rpc.returndata.limit', "'code': 429", 'payload too large']
    
    dont_need_to_see_errs += [
        # We catch and correct these
        "invalid request",
        # We pass these down to the call they originated from
        *INDIVIDUAL_CALL_REVERT_STRINGS
    ]

    
    
    stre = str(e).lower()
    if any(err in stre for err in dont_need_to_see_errs):
        return ENVS.DEBUG  # type: ignore [attr-defined,return-value]
    logger.warning("The following exception is being logged for informational purposes and does not indicate failure:")
    logger.warning(e, exc_info=True)
    return ENVS.DEBUG  # type: ignore [attr-defined,return-value]
