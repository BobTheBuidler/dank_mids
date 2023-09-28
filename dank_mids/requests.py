
import abc
import asyncio
import logging
import time
from collections import defaultdict
from concurrent.futures.process import BrokenProcessPool
from contextlib import suppress
from functools import cached_property, lru_cache
from random import random
from typing import (TYPE_CHECKING, Any, AsyncGenerator, DefaultDict, Dict,
                    Generator, Generic, Iterable, Iterator, List, Optional,
                    Tuple, TypeVar, Union)

import a_sync
import eth_retry
import msgspec
from a_sync import AsyncProcessPoolExecutor, PruningThreadPoolExecutor
from aiohttp.client_exceptions import ClientConnectorError, ClientResponseError
from eth_abi import abi, decoding
from eth_typing import ChecksumAddress
from eth_utils import function_signature_to_4byte_selector
from hexbytes import HexBytes
from web3.exceptions import ContractLogicError
from web3.types import RPCEndpoint, RPCResponse

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids import constants, stats
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import (ArchiveNodeRequired, BadGateway, BadRequest,
                                   BadResponse, BrokenPipe,
                                   DankMidsClientResponseError,
                                   DankMidsInternalError, EmptyBatch,
                                   ExceedsMaxBatchSize, GatewayPayloadTooLarge,
                                   InvalidRequest, NodePayloadTooLarge,
                                   PayloadTooLarge, ResponseNotReady, Revert,
                                   StreamReaderTimeout, _Timeout,
                                   internal_err_types)
from dank_mids.helpers import Status, decode, session, stream
from dank_mids.types import (BatchId, BlockId, JsonrpcParams, PartialRequest,
                             PartialResponse, RawResponse, Request, Response)
from dank_mids.uid import _AlertingRLock

if TYPE_CHECKING:
    from dank_mids.controller import (DankMiddlewareController,
                                      MulticallContract)
    from dank_mids.provider import DankProvider


logger = logging.getLogger(__name__)
failure_logger = logging.getLogger('dank_mids.failures')

_Response = TypeVar("_Response", Response, List[Response], RPCResponse, List[RPCResponse])

class _RequestEvent(a_sync.Event):
    def __init__(self, owner: "_RequestMeta") -> None:
        super().__init__(debug_daemon_interval=300)
        self._owner = owner
    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} object at {hex(id(self))} [{'set' if self.is_set() else 'unset'}, waiter:{self._owner}>"
    def set(self):
        # Make sure we wake up the _RequestEvent's event loop if its in another thread
        if asyncio.get_running_loop() == self._loop:
            super().set()
        else:
            self._loop.call_soon_threadsafe(super().set)

class _RequestMeta(Generic[_Response], metaclass=abc.ABCMeta):
    __slots__ = 'controller', 'uid', '_response', '_done', '_start', '_batch'
    controller: "DankMiddlewareController"
    def __init__(self) -> None:
        self.uid = self.controller.call_uid.next
        self._response: Optional[_Response] = None
        self._done = _RequestEvent(self)
        self._start = time.time()
        self._status = Status.QUEUED
    
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

    async def _debug_daemon(self) -> None:
        while self._status in {Status.ACTIVE, Status.QUEUED, Status.FAILED, Status.TIMED_OUT}:
            await asyncio.sleep(60)
            if not self._done.is_set():
                logger.debug("%s has not received data after %sm", self, round((time.time() - self._start)/60, 2))  
                if isinstance(self, Multicall):
                    if all(call._status == Status.COMPLETE for call in self.calls):
                        logger.debug('oh but wait, all calls are completed')
                        return
                    elif len(self) == 1 and self.calls[0]._status == Status.CANCELED:
                        logger.debug("but its only call was cancelled %s", call)
                        return
                    for call in self.calls[:]:
                        if call._status == Status.CANCELED:
                            logger.debug("this call was cancelled though %s", call)
                        elif call._status == Status.FAILED:
                            logger.debug("this call failed though %s", call)
                        elif call._status == Status.COMPLETE:
                            logger.debug('%s is complete, removing from %s', call, self)
                            if call._done.is_set():
                                self.calls.remove(call)
                                continue
                            logger.debug('%s status is %s but %s is not set', call, call._status.name, call._done)
                        elif call._status == Status.QUEUED:
                            logger.warning("%s is started but %s is still queued. this should not happen.", self, call)
                        else:
                            logger.debug("%s status is %s", self, self._status)
                    

### Single requests:

BYPASS_METHODS = "eth_blockNumber", "eth_getLogs", "trace_", "debug_"
Noop = Any

@lru_cache(maxsize=None)
def _should_batch_method(method: str) -> bool:
    return all(bypass not in method for bypass in BYPASS_METHODS)

class RPCRequest(_RequestMeta[RawResponse]):
    __slots__ = 'method', 'params', 'should_batch', '_started', '_retry', '_daemon'
    dict_responses = set()
    str_responses = set()

    _types = set()

    def __init__(self, controller: "DankMiddlewareController", method: RPCEndpoint, params: Any, retry: bool = False):
        self.controller = controller
        self.method = method
        self.params = params
        self.should_batch = _should_batch_method(method)
        self._started = False
        self._batch = None
        self._retry = retry
        super().__init__()

        with self.controller.pools_closed_lock:
            if isinstance(self, eth_call) and self.multicall_compatible:
                self.controller.pending_eth_calls[self.block].append(self)
            else:
                self.controller.pending_rpc_calls.append(self)
        demo_logger.info('added to queue (cid: %s)', self.uid)  # type: ignore
        if logger.isEnabledFor(logging.DEBUG):
            self._daemon = asyncio.create_task(self._debug_daemon())
    
    def __eq__(self, __o: object) -> bool:
        return self.uid == __o.uid if isinstance(__o, self.__class__) else False 
    
    def __len__(self) -> int:
        return 1
    
    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} uid={self.uid} method={self.method} status={self._status.name} batch={self._batch}>"
    
    @property
    def provider(self) -> "DankProvider":
        return self.controller.provider

    @property
    def request(self) -> Union[Request, PartialRequest]:
        return self.provider._request_selector(method=self.method, params=self.params, id=self.uid)
    
    @property
    def semaphore(self) -> a_sync.Semaphore:
        # NOTE: We cannot cache this property so the semaphore control pattern in the `duplicate` fn will work as intended
        return self.controller.method_semaphores.get_semaphore(self.method, self.params)
    
    @cached_property
    def weight(self) -> float:
        # NOTE: These are totally arbitrary for now
        if self.method in ["eth_getTransactionReceipt", "eth_getCode"]:
            return 10
        elif any(m in self.method for m in ["eth_getBlockBy", "eth_getTransaction", "erigon_getHeader"]):
            return 5
        return 0.5
    
    def start(self, batch: "_Batch", cleanup: Noop = False) -> None:
        self._status = Status.ACTIVE
        self._batch = batch

    @Status.set
    async def get_response(self) -> RPCResponse:
        try:
            if not self.should_batch:
                logger.debug("bypassed, method is %s", self.method)
                await asyncio.wait_for(self.make_request(), timeout=ENVS.STUCK_CALL_TIMEOUT)
                response = self.response.decode(partial=True)
                if self.provider._should_retry_invalid_request(response.exception):
                    return await self.create_duplicate(cancel_old=True)
                return response.to_dict(method=self.method)
            
            if self._batch and self._batch._status == Status.QUEUED:
                # NOTE: If this call has a batch assigned, we filled a batch. Let's await it now so we can send something to the node.
                await self._batch
            elif self._batch is None:
                # NOTE: We want to force the event loop to make one full _run_once call before we execute.
                await asyncio.sleep(0)
            if self._batch is None:
                await asyncio.wait_for(
                    # If this timeout fails, we go nuclear and destroy the batch.
                    # Any calls that already succeeded will have already completed on the client side.
                    # Any calls that have not yet completed with results will be recreated, rebatched (potentially bringing better results?), and retried
                    self.controller.execute_batch(),
                    timeout=ENVS.STUCK_CALL_TIMEOUT,
                )
            await asyncio.wait_for(self._done.wait(), timeout=ENVS.STUCK_CALL_TIMEOUT)
        except asyncio.TimeoutError:
            return await self.create_duplicate(timed_out=True)
        return await self.decode_response()
        # Call has results, time to decode...

    async def decode_response(self) -> Dict[str, str]:
        # JIT json decoding
        if isinstance(self.response, RawResponse):
            response = self.response.decode(partial=True)
            if self.provider._should_retry_invalid_request(response.exception):
                return await self.create_duplicate(cancel_old=True)
            response_dict = response.to_dict(method=self.method, request=self.request)
            if response.error:
                failure_logger.debug("error response for %s: %s", self, response_dict)
            return response_dict
    
        # If we have an Exception here it came from the goofy sync_call thing I need to get rid of.
        # We raise it here so it traces back up to the caller
        if isinstance(self.response, ClientResponseError):
            raise DankMidsClientResponseError(self.response, self.request) from self.response
        if isinstance(self.response, ContractLogicError):
            raise self.response
        if isinstance(self.response, Exception):
            try:
                more_detailed_exc = self.response.__class__(self.response, self.request)
            except TypeError:
                raise
            except Exception as e:
                self.response.request = self.request
                self.response._dank_mids_exception = e
                raise self.response
            raise more_detailed_exc from self.response
        # Less optimal decoding
        # TODO: refactor this out
        return self.response
    
    @Status.set
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
            # NOTE: keep this down here to save an if check for successful (most) responses      
            if self.provider._should_retry_invalid_request(data):
                logger.debug("your node says the partial request was invalid but its okay, we can use the full jsonrpc spec instead")
                self._response = await self.create_duplicate()
                return
            self._response = data.response.to_dict(request=self.request)
            failure_logger.debug("%s _response set to rpc error response %s", self, self._response)
            
        elif isinstance(data, Exception):
            self._response = data
            failure_logger.debug("%s _response set to Exception %s", self, data)
            
        # From multicalls
        elif isinstance(data, bytes):
            self._response = {"result": data}
            
        else:
            raise NotImplementedError(f'type {type(data)} not supported for spoofing.', type(data), data)
    
    @Status.set
    async def make_request(self) -> RawResponse:
        """Used to execute the request with no batching."""
        self._response = await self.provider.make_request(self.method, self.params, request_id=self.uid)
        return self._response
    
    @Status.set
    async def create_duplicate(self, timed_out: bool = False, cancel_old: bool = False) -> RPCResponse: # Not actually self, but for typing purposes it is.
        # We need to make room since the stalled call is still holding the semaphore
        self.semaphore.release()
        self.provider._pools_open.set()
        if timed_out:
            logger.warning(f"call {self.uid} got stuck, we're creating a new one")
        else:
            self._status = Status.DUPLICATED
        
        clone = self.controller(self.method, self.params)
        if cancel_old:
            response = await clone
        else:
            futs = asyncio.as_completed([clone, self._done.wait()])
            if isinstance(result := await next(futs), bool):  # the original completed first
                response = await self.decode_response()
            else:  # the clone completed first
                response = result
                # This suppresses an unawaited coroutine warning
            asyncio.create_task(next(futs))
        await self.semaphore.acquire()
        return response
        

revert_threads = PruningThreadPoolExecutor(4)

class eth_call(RPCRequest):
    __slots__ = 'block'
    def __init__(self, controller: "DankMiddlewareController", params: Any, retry: bool = False) -> None:
        """ Adds a call to the DankMiddlewareContoller's `pending_eth_calls`. """
        self.block = params[1]
        super().__init__(controller, "eth_call", params)  # type: ignore
    
    @property
    def calldata(self) -> HexBytes:
        return HexBytes(self.params[0]['data'])
    
    @property
    def multicall_compatible(self) -> bool:
        return self.target not in self.controller.no_multicall

    @property
    def target(self) -> str:
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
                data = await revert_threads.run(self.provider._sync_w3.eth.call, {"to": self.target, "data": self.calldata}, self.block)
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
        return self.controller.method_semaphores['eth_call'][self.block]
    
    

### Batch requests:

_Request = TypeVar("_Request")

class _Batch(_RequestMeta[List[RPCResponse]], Iterable[_Request]):
    __slots__ = 'calls', '_fut', '_lock', '_daemon'
    calls: List[_Request]

    def __init__(self, controller: "DankMiddlewareController", calls: Iterable[_Request]):
        self.controller = controller
        self.provider = controller.provider
        self.calls = list(calls)  # type: ignore
        self._fut = None
        self._lock = _AlertingRLock(name=self.__class__.__name__)
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
        with self._lock:
            self.calls.append(call)
            #self._len += 1
            if not skip_check:
                if self.is_full:
                    self.start()
                elif self.controller.queue_is_full:
                    self.controller.early_start()
    
    def extend(self, calls: Iterable[_Request], skip_check: bool = False) -> None:
        with self._lock:
            self.calls.extend(calls)
            #self._len += len(calls)
            if not skip_check:
                if self.is_full:
                    self.start()
                elif self.controller.queue_is_full:
                    self.controller.early_start()

    def start(self, batch: Optional["_Batch"] = None, cleanup=True) -> None:
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
            failure_logger.debug('out of gas. cut in half, trying again')
        elif any(err in f"{e}".lower() for err in constants.RETRY_ERRS):
            # TODO: use these exceptions to optimize for the user's node
            failure_logger.debug('Dank too loud. Bisecting batch and retrying.')
        elif not isinstance(e, InvalidRequest) and "error processing call Revert" not in f"{e}":
            failure_logger.warning(f"unexpected {e.__class__.__name__}: {e}")
        return len(self) > 1
    
    def delete_refs_to_completed_calls(self) -> None:
        self.calls = [call for call in self.calls if call._status not in {Status.COMPLETE, Status.CANCELED}]
    
    async def sleep_random(self, e: Exception, multiplier: int) -> None:
        sleep = random() * 2 * multiplier
        failure_logger.warning("%s failed with %s, retrying in %ss", self, e, round(sleep, 2))
        await asyncio.sleep(sleep)

mcall_encoder = abi.default_codec._registry.get_encoder("(bool,(address,bytes)[])")
mcall_decoder = abi.default_codec._registry.get_decoder("(uint256,uint256,(bool,bytes)[])")

def mcall_encode(data: List[Tuple[bool, bytes]]) -> bytes:
    return mcall_encoder([False, data])

def mcall_decode(data: PartialResponse) -> List[Tuple[bool, bytes]]:        
    try:
        # NOTE: We need to safely bring any Exceptions back out of the ProcessPool
        data = bytes.fromhex(data.decode_result("eth_call")[2:])
        return mcall_decoder(decoding.ContextFramesBytesIO(data))[2]
    except Exception as e:
        return e
    

class Multicall(_Batch[eth_call]):
    __slots__ = 'bid', '_started', '__dict__'  # We need to specify __dict__ for the cached properties to work
    method = "eth_call"
    fourbyte = function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")
    _might_want_to_reduce_batch_size_indicators = 0

    def __init__(self, controller: "DankMiddlewareController", calls: List[eth_call] = [], bid: Optional[BatchId] = None):
        # sourcery skip: default-mutable-arg
        super().__init__(controller, calls)
        self.bid = bid or self.controller.multicall_uid.next
        self._batch = None
        self._status = Status.QUEUED
    
    def __repr__(self) -> str:
        return f"<Multicall mid={self.bid} block={self.block} len={len(self)} status={self._status.name} batch={self._batch}>"
    
    @cached_property
    def block(self) -> BlockId:
        return self.calls[0].block
    
    @property
    def calldata(self) -> str:
        self.delete_refs_to_completed_calls()
        return (self.fourbyte + mcall_encode([[call.target, call.calldata] for call in self.calls])).hex()
    
    @property
    def target(self) -> ChecksumAddress:
        return self.mcall.address
    
    @cached_property
    def mcall(self) -> "MulticallContract":
        return self.controller._select_mcall_target_for_block(self.block)
    
    @property
    def params(self) -> JsonrpcParams:
        params = [{'to': self.target, 'data': f'0x{self.calldata}'}, self.block]
        if self.needs_override_code and not self.controller.state_override_not_supported:
            params.append({self.target: {'code': self.mcall.bytecode}})
        return params
    
    @property
    def request(self) -> Union[Request, PartialRequest]:
        return self.provider._request_selector(method=self.method, params=self.params, id=self.uid)
    
    @property
    def is_full(self) -> bool:
        return len(self) >= self.controller.batcher.step

    @property
    def needs_override_code(self) -> bool:
        return self.mcall.needs_override_code_for_block(self.block)
        
    @property
    def weight(self) -> float:
        return len(self) / 20

    @Status.set
    @eth_retry.auto_retry
    async def get_response(self) -> None:
        #if len(self) < 50: # TODO play with later
        #    return await JSONRPCBatch(self.controller, self.calls)
        rid = self.controller.request_uid.next
        demo_logger.info('request %s for multicall %s starting', rid, self.bid)  # type: ignore
        try:
            await self.spoof_response(await self.provider.make_request(self.method, self.params, request_id=self.uid))
        except internal_err_types.__args__ as e:
            raise DankMidsInternalError(e) from e
        except (asyncio.TimeoutError, BadRequest, BadGateway, BrokenPipe, ClientConnectorError, _Timeout) as e:
            if len(self) >= self.controller.batcher.step:
                self._might_want_to_reduce_batch_size_indicators += 1
            if (i := self._might_want_to_reduce_batch_size_indicators / 5) == int(i):
                self.controller.reduce_multicall_size(len(self))
            await self.sleep_random(e, multiplier=1 + str(self.bid).count("_"))
            await self.bisect_and_retry(e)
        except GatewayPayloadTooLarge as e:
            failure_logger.debug("multicall payload too large.  calls: %s  response headers: %s", len(self), e.headers)
            self.controller.reduce_multicall_size(len(self))
            await self.bisect_and_retry(e)
        except NodePayloadTooLarge as e:
            failure_logger.debug("multicall payload too large.  calls: %s", len(self))
            self.controller.reduce_multicall_size(len(self))
            await self.bisect_and_retry(e)
        except Exception as e:
            _log_exception(e)
            await (self.bisect_and_retry(e) if self.should_retry(e) else self.spoof_response(e))  # type: ignore [misc]
        demo_logger.info('request %s for multicall %s complete', rid, self.bid)  # type: ignore
    
    def should_retry(self, e: Exception) -> bool:
        """Should the Multicall be retried based on `e`?"""
        if any(err in f"{e}".lower() for err in constants.RETRY_ERRS):
            failure_logger.debug('dank too loud, trying again')
            return True
        elif "No state available for block" in f"{e}":  # NOTE: While it might look weird, f-string is faster than `str(e)`.
            e.args[0]["dankmids_note"] = "You're not using an archive node, and you need one for the application you are attempting to run."
            return False
        elif super().should_retry(e):
            return True
        return len(self) > 1
    
    @Status.set
    async def spoof_response(self, data: Union[RawResponse, Exception]) -> None:
        # This happens if an Exception takes place during a singular Multicall request.
        if isinstance(data, Exception):
            failure_logger.debug("%s had Exception %s", self, data)
            failure_logger.debug("propagating the %s to all %s's calls", data.__class__.__name__, self)
            await asyncio.gather(*[call.spoof_response(data) for call in self.calls])
        # A `RawResponse` represents either a successful or a failed response, stored as pre-decoded bytes.
        # It was either received as a response to a single rpc call or as a part of a batch response.
        elif isinstance(data, RawResponse):
            response = data.decode(partial=True)
            if response.error:
                # TODO: This logic should probably live somewhere else
                if isinstance(response.exception, Revert) or self.provider._should_retry_invalid_request(response.exception):
                    await self.bisect_and_retry(response.exception)
                    return
                failure_logger.debug("%s received an 'error' response from the rpc: %s", self, response.exception)
                # NOTE: We raise the exception which will be caught, call will be broken up and retried
                raise response.exception
            logger.debug("%s received valid bytes from the rpc", self)
            await asyncio.gather(*(call.spoof_response(data) for call, (_, data) in zip(self.calls, await self.decode(response))))
        else:
            raise NotImplementedError(f"type {type(data)} not supported.", data)
    
    async def decode(self, data: PartialResponse) -> List[Tuple[bool, bytes]]:
        start = time.time()
        if ENVS.OPERATION_MODE.infura:
            retval = mcall_decode(data)
        else:
            try:  # NOTE: Quickly check for length without counting each item with `len`.
                if not ENVS.OPERATION_MODE.application:
                    self[100]
                retval = await ENVS.MULTICALL_DECODER_PROCESSES.run(mcall_decode, data)
            except IndexError:
                retval = mcall_decode(data)
            except BrokenProcessPool:
                # TODO: Move this somewhere else
                logger.critical("Oh fuck, you broke the %s while decoding %s", ENVS.MULTICALL_DECODER_PROCESSES, data)
                ENVS.MULTICALL_DECODER_PROCESSES = AsyncProcessPoolExecutor(ENVS.MULTICALL_DECODER_PROCESSES._max_workers)
                retval = mcall_decode(data)
        stats.log_duration(f"multicall decoding for {len(self)} calls", start)
        # Raise any Exceptions that may have come out of the process pool.
        if isinstance(retval, Exception):
            raise retval    
        return retval
    
    @Status.set
    async def bisect_and_retry(self, e: Exception) -> List[RPCResponse]:
        """
        Splits up the calls of a `Multicall` into 2 chunks, then awaits both.
        Calls `self._done.set()` when finished.
        """
        if not isinstance(e, Revert) and len(self) <= self.controller.batcher.step * 0.2:
            failure_logger.debug("%s had exception %s, rebatching and retrying", self, e)
            return await asyncio.gather(*[self.controller.rebatcher.rebatch(call) for call in self.calls])
        failure_logger.debug("%s had exception %s, bisecting and retrying", self, e)
        batches = [Multicall(self.controller, chunk, f"{self.bid}_{i}") for i, chunk in enumerate(self.bisected) if chunk]
        for batch in batches:
            batch.start(cleanup=False)
        for batch in asyncio.as_completed(batches):
            try:
                batch = await batch
                self.delete_refs_to_completed_calls()
                del batch
            except Exception as e:
                if not isinstance(e, DankMidsInternalError):
                    failure_logger.error(f"That's not good, there was an exception in a Multicall. These are supposed to be handled.\n{e}\n", exc_info=True)
                raise e

    def _post_future_cleanup(self) -> None:
        with suppress(KeyError):
            with self.controller.pools_closed_lock:
                # This will have already taken place in a full json batch of multicalls
                self.controller.pending_eth_calls.pop(self.block)


async def _await_batch(batch) -> Tuple[str, Optional[Exception]]:
    try:
        await (batch if isinstance(batch, _Batch) else batch.make_request())
        return batch, None
    except Exception as e:
        return batch, e  

class JSONRPCBatch(_Batch[Union[Multicall, RPCRequest]]):
    __slots__ = 'jid', '_started'
    _might_want_to_reduce_batch_size_indicators = 0
    
    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: List[Union[Multicall, RPCRequest]] = [], 
        jid: Optional[BatchId] = None
    ) -> None:  # sourcery skip: default-mutable-arg
        super().__init__(controller, calls)
        self.jid = jid or self.controller.jsonrpc_batch_uid.next
        self._status = Status.QUEUED

    def __repr__(self) -> str:
        return f"<JSONRPCBatch jid={self.jid} len={len(self)} status={self._status.name}>"
    
    @property
    def data(self) -> bytes:
        self.delete_refs_to_completed_calls()
        if not self.calls:
            raise EmptyBatch(f"batch {self.uid} is empty and should not be processed.")
        return msgspec.json.encode([call.request for call in self.calls])
    
    @property
    def is_multicalls_only(self) -> bool:
        with self._lock:
            return all(isinstance(call, Multicall) for call in self.calls)

    @property
    def is_single_multicall(self) -> bool:
        with self._lock:
            return len(self) == 1 and self.is_multicalls_only

    @property
    def method_counts(self) -> Dict[RPCEndpoint, int]:
        counts: DefaultDict[RPCEndpoint, int] = defaultdict(int)
        with self._lock:
            for call in self.calls:
                if isinstance(call, Multicall):
                    counts["eth_call[multicall]"] += len(call)  # type: ignore
                else:
                    counts[call.method] += 1
            return dict(counts)
    
    @property
    def total_calls(self) -> int:
        with self._lock:
            return sum(len(call) for call in self.calls)

    @property
    def is_full(self) -> bool:
        with self._lock:
            return self.total_calls >= self.controller.batcher.step or max(len(self), self.weight) >= ENVS.MAX_JSONRPC_BATCH_SIZE
    
    @property
    def weight(self) -> int:
        # a primitive attempt to reduce bulky calls to the node
        return int(sum(call.weight for call in self.calls))

    @Status.set
    @eth_retry.auto_retry
    async def get_response(self) -> None:
        rid = self.controller.request_uid.next
        if ENVS.DEMO_MODE:
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            demo_logger.info('request %s for jsonrpc batch %s (%s calls) starting', rid, self.jid, sum(len(batch) for batch in self.calls))  # type: ignore
        try:
            # NOTE: We do this inline so we never have to allocate the response to memory
            await self.spoof_response(self.post())
            #await self.spoof_response(await self.post())
        # I want to see these asap when working on the lib.
        except internal_err_types.__args__ as e:
            raise DankMidsInternalError(e) from e
        except ArchiveNodeRequired as e:
            failure_logger.debug('No state available for one of the blocks queried. Bisecting batch and retrying.')
            await self.bisect_and_retry(e)
        except EmptyBatch as e:
            failure_logger.warning("These EmptyBatch exceptions shouldn't actually happen and this except clause can probably be removed soon.")
        except (asyncio.TimeoutError, BadRequest, BadGateway, BrokenPipe, ClientConnectorError, _Timeout) as e:
            await self.sleep_random(e, multiplier=1 + str(self.jid).count("_"))
            await self.bisect_and_retry(e)
        except (ExceedsMaxBatchSize, PayloadTooLarge) as e:
            await self.bisect_and_retry(e)
        except Exception as e:
            _log_exception(e)
            stats.log_errd_batch(self)
            if not self.should_retry(e):
                # TODO: the useful stuff in should_retry should probably be moved elsewhere
                raise e
            await self.bisect_and_retry(e)
        demo_logger.info('request %s for jsonrpc batch %s complete', rid, self.jid)  # type: ignore
    
    async def post(self) -> AsyncGenerator[RawResponse, None]:
        retries = 0
        while True:
            try:
                data_stream = stream.array.of_objects(self.provider._post(data=self.data))
                async for raw_response in decode.jsonrpc_batch(data_stream):
                    yield raw_response
                return
            except (asyncio.TimeoutError, BadRequest, BadGateway, BrokenPipe, ClientConnectorError, _Timeout) as e:
                detail = _err_details.get(e.__class__, "failed to connect")
                if isinstance(e, asyncio.TimeoutError) or len(self) > 100:
                    failure_logger.warning("This batch %s: %s", detail, self.method_counts)
                if (this := max(len(self), self.weight)) >= ENVS.MAX_JSONRPC_BATCH_SIZE:
                    self._might_want_to_reduce_batch_size_indicators += 1
                    if (i := self._might_want_to_reduce_batch_size_indicators / 5) == int(i):
                        self.controller.reduce_batch_size(this)
                elif self.total_calls >= self.controller.batcher.step:
                    Multicall._might_want_to_reduce_batch_size_indicators += 1
                    if (i := Multicall._might_want_to_reduce_batch_size_indicators / 5) == int(i):
                        self.controller.reduce_multicall_size(self.total_calls)
                raise e
            except ExceedsMaxBatchSize as e:
                failure_logger.warning("exceeded max batch size for your node")
                self.controller.set_batch_size_limit(e.limit)
                raise
            except GatewayPayloadTooLarge as e:
                failure_logger.warning("[%s] This payload was too large: %s", session.HTTPStatusExtended(e.status), self.method_counts)
                self.adjust_batch_size()
                raise  
            except NodePayloadTooLarge as e:
                # TODO: track too large payloads and do some better optimizations for batch sizing
                failure_logger.warning("This payload was too large: %s", self.method_counts)
                self.adjust_batch_size()
                raise
            except ClientResponseError as e:
                failure_logger.info(e, exc_info=True)
                if retries < 5:
                    failure_logger.debug("caught %s for %s, retrying", e, self)
                    await asyncio.sleep(0.1)
                    retries += 1
                else:
                    failure_logger.debug("caught %s for %s, reraising", e, self)
                    raise e
    
    def should_retry(self, e: Exception) -> bool:
        """Should the JSONRPCBatch be retried based on `e`?"""
        return super().should_retry(e) or self.is_single_multicall
    
    @Status.set
    async def spoof_response(self, response_stream: AsyncGenerator[RawResponse, None]) -> None:
        done = 0
        async for raw in response_stream:
            await self.calls[done].spoof_response(raw)
            done += 1
    
    @Status.set
    async def bisect_and_retry(self, e: Exception) -> None:
        """
        Splits up the calls of a `JSONRPCBatch` into 2 chunks, then awaits both.
        If one chunk is just a single multicall, it will be handled alone, not be placed into a batch.
        Calls `self._done.set()` when finished.
        """
        if max(len(self), self.weight)  <= ENVS.MAX_JSONRPC_BATCH_SIZE * 0.2:
            failure_logger.debug("%s had exception %s, rebatching and retrying", self, e)
            return await asyncio.gather(*[self.controller.rebatcher.rebatch(call) for call in self.calls])
        failure_logger.debug("%s had exception %s, bisecting and retrying", self, e)
        batches = [
            Multicall(self.controller, chunk, f"jrpcbatch{self.jid}_{i}")  # type: ignore [misc]
            if len(chunk) == 1 and isinstance(chunk[0], eth_call)
            else chunk[0]
            if len(chunk) == 1
            else JSONRPCBatch(self.controller, chunk, f"{self.jid}_{i}")
            for i, chunk in enumerate(self.bisected)
            if chunk
        ]
        for batch in batches:
            batch.start(batch=self, cleanup=False)
        for fut in asyncio.as_completed([_await_batch(batch) for batch in batches]):
            batch_cls, result = await fut
            if isinstance(result, Exception):
                if not isinstance(result, DankMidsInternalError):
                    failure_logger.error(f"That's not good, there was an exception in a {batch_cls}. These are supposed to be handled.\n{result}\n", exc_info=True)
                raise result
            self.delete_refs_to_completed_calls()
    
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

def _log_exception(e: Exception) -> None:
    # NOTE: These errors are expected during normal use and are not indicative of any problem(s). No need to log them.
    # TODO: Better filter what we choose to log here
    stre = str(e).lower()
    if any(err in stre for err in constants.RETRY_ERRS):
        return
    failure_logger.warning("The following exception is being logged for informational purposes and does not indicate failure:")
    failure_logger.warning(e, exc_info=True)

_err_details = {
    StreamReaderTimeout: "timed out mid stream",
    asyncio.TimeoutError: "timed out",
    BrokenPipe: "broke the pipe",
}
