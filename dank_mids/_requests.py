from asyncio import (
    CancelledError,
    Future,
    Task,
    TimeoutError,
    create_task,
    current_task,
    get_running_loop,
    shield,
    sleep,
    wait_for,
)
from collections import defaultdict
from concurrent.futures.process import BrokenProcessPool
from itertools import accumulate, chain, filterfalse, groupby
from logging import DEBUG, getLogger
from time import time
from typing import (
    TYPE_CHECKING,
    Any,
    Callable,
    DefaultDict,
    Dict,
    Generator,
    Generic,
    Iterable,
    Iterator,
    List,
    Literal,
    Optional,
    Sequence,
    Set,
    Tuple,
    TypeVar,
    Union,
    final,
)
from weakref import ProxyType
from weakref import proxy as weak_proxy

import a_sync
import eth_retry
from a_sync import AsyncProcessPoolExecutor, PruningThreadPoolExecutor, igather
from a_sync.asyncio import sleep0 as yield_to_loop
from a_sync.functools import cached_property_unsafe as cached_property
from aiohttp.client_exceptions import ClientResponseError
from eth_abi import abi, decoding
from eth_abi.encoding import DynamicArrayEncoder, TupleEncoder, encode_uint_256
from eth_typing import ChecksumAddress, HexStr
from eth_utils import function_signature_to_4byte_selector
from eth_utils.toolz import concat
from hexbytes import HexBytes
from web3.exceptions import ContractLogicError
from web3.types import RPCEndpoint, RPCResponse
from web3.types import RPCError as _RPCError

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids import _debugging, constants, stats
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import (
    BadResponse,
    BatchResponseSortError,
    ChainstackRateLimited,
    DankMidsClientResponseError,
    DankMidsInternalError,
    EmptyBatch,
    ExceedsMaxBatchSize,
    ExecutionReverted,
    GarbageCollectionError,
    OutOfGas,
    PayloadTooLarge,
    internal_err_types,
)
from dank_mids._uid import _AlertingRLock
from dank_mids.helpers import DebuggableFuture, _codec, _session, gatherish, lru_cache_lite_nonull
from dank_mids.helpers._errors import (
    INDIVIDUAL_CALL_REVERT_STRINGS,
    error_logger,
    error_logger_debug,
    error_logger_log_debug,
    format_error_response,
    gas_logger_debug,
    is_call_revert,
    log_internal_error,
    needs_full_request_spec,
    revert_logger,
    revert_logger_log_debug,
    timeout_logger_debug,
    timeout_logger_warning,
)
from dank_mids.helpers._gather import first_completed
from dank_mids.helpers._helpers import set_done
from dank_mids.helpers._multicall import MulticallContract
from dank_mids.helpers._weaklist import WeakList
from dank_mids.types import (
    BatchId,
    BlockId,
    JSONRPCBatchResponse,
    JsonrpcParams,
    PartialRequest,
    PartialResponse,
    RawResponse,
    Request,
    Response,
)

if TYPE_CHECKING:
    from dank_mids._batch import DankBatch
    from dank_mids.controller import DankMiddlewareController


TIMEOUT_SECONDS_SMALL = 15
TIMEOUT_SECONDS_BIG = float(ENVS.STUCK_CALL_TIMEOUT)  # type: ignore [arg-type]

logger = getLogger(__name__)
batch_size_logger = getLogger("dank_mids.batch_size")


_Response = TypeVar(
    "_Response", Response, List[Response], RPCResponse, List[RPCResponse], RawResponse
)

MulticallChunk = Tuple[ChecksumAddress, HexStr]


class RPCError(_RPCError, total=False):
    dankmids_added_context: Dict[str, Any]


_super_init = a_sync.Event.__init__
_super_set = a_sync.Event.set


class _RequestEvent(a_sync.Event):
    def __init__(self, owner: "_RequestBase[_Response]") -> None:
        _super_init(self, debug_daemon_interval=300)
        if self.debug_logs_enabled:
            self._owner: ProxyType[_RequestBase[_Response]] = weak_proxy(owner)

    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} object at {hex(id(self))} [{'set' if self.is_set() else 'unset'}, waiter:{self._owner}>"

    def set(self) -> None:
        # Make sure we wake up the _RequestEvent's event loop if its in another thread
        if self._loop is get_running_loop():
            _super_set(self)
        else:
            self._loop.call_soon_threadsafe(_super_set, self)

    # default if no debug logs enabled
    _owner = "[not displayed...]"


class _RequestBase(Generic[_Response]):
    _fut: DebuggableFuture
    _batch: Optional["_Batch"] = None

    __slots__ = "controller", "uid", "_fut", "__weakref__"

    def __init__(self, controller: "DankMiddlewareController", uid: Optional[str] = None) -> None:
        self.controller: "DankMiddlewareController" = controller
        """The DankMiddlewareController that created this request."""

        self.uid = controller.call_uid.next if uid is None else uid
        """The unique id for this request."""

        self._fut = DebuggableFuture(self, controller._loop)

    def __await__(self) -> Generator[Any, None, _Response]:
        return self.get_response().__await__()

    # Abstract methods to be implemented by subclasses

    def __len__(self) -> int:
        raise NotImplementedError

    async def get_response(self) -> _Response:
        raise NotImplementedError


### Single requests:

BYPASS_METHODS = "eth_blockNumber", "eth_getLogs", "trace_", "debug_"
"""
A tuple of method names that should bypass batching.
These methods are typically handled separately or have special requirements.
"""


@lru_cache_lite_nonull
def _get_len_for_method(method: str) -> int:
    # NOTE: These are totally arbitrary, used to reduce frequency of giant batches/responses
    if method == "eth_getTransactionReceipt":
        return 5
    elif method in {"eth_getTransaction", "eth_getCode"} or "eth_getBlockBy" in method:
        return 3
    return 1


@lru_cache_lite_nonull
def _should_batch_method(method: str) -> bool:
    return all(bypass not in method for bypass in BYPASS_METHODS)


_REVERT_EXC_TYPES = ContractLogicError, ExecutionReverted

_request_base_init = _RequestBase.__init__


class RPCRequest(_RequestBase[RPCResponse]):
    should_batch: bool = True
    """`True` if this request should be batched with others into a jsonrpc batch request, `False` if it should be sent as an individual request."""

    _tiny_batches: bool = False
    """`True` if the max jsonrpc batch size is 50 or lower."""

    _debug_logs_enabled: bool = False
    """`True` if debug logging is currently enabled."""

    method: RPCEndpoint
    _fut: DebuggableFuture

    __slots__ = "method", "params", "raw", "_daemon", "__dict__"

    def __init__(
        self,
        controller: "DankMiddlewareController",
        method: RPCEndpoint,
        params: Any,
        uid: Optional[str] = None,
    ):  # sourcery skip: hoist-statement-from-if
        _request_base_init(self, controller, uid)
        if method[-4:] == "_raw":
            self.method = method[:-4]
            """The rpc method for this request."""
            self.raw = True
        else:
            self.method = method
            """The rpc method for this request."""
            self.raw = False

        self.params = params
        """The parameters to send with this request, if any."""

        if not _should_batch_method(method):
            self.should_batch = False

        if logger.isEnabledFor(DEBUG):
            self._debug_logs_enabled = True

        if controller.max_jsonrpc_batch_size <= 50:
            self._tiny_batches = True

        if self.should_batch:
            with controller.pools_closed_lock:
                if isinstance(self, eth_call) and self.multicall_compatible:
                    controller.pending_eth_calls[self.block].append(self)
                elif self.method.startswith(("trace", "debug")):
                    raise NotImplementedError("we should not get here", self)
                else:
                    controller._pending_rpc_calls_append(self)
        _demo_logger_info("added to queue (cid: %s)", self.uid)
        if _logger_is_enabled_for(DEBUG):
            self._daemon = create_task(self._debug_daemon(), name="RPCRequest debug daemon")

    def __hash__(self) -> int:
        return id(self)

    def __eq__(self, __o: object) -> bool:
        return (self.uid == __o.uid) if type(__o) is type(self) else False

    def __len__(self) -> int:
        # NOTE: We dont need to consider this for very small batch sizes since the requests/responses will never get too large
        return _get_len_for_method(self.method) if self._tiny_batches else 1

    def __repr__(self) -> str:
        batch = self._batch
        batch_info = "" if batch is None else f" batch={batch}"
        return f"<{self.__class__.__name__} uid={self.uid} method={self.method} params={self.params}{batch_info}>"

    def __del__(self) -> None:
        if not self._fut.done():
            logger.error("%s was garbage collected before finishing", self)
            self._fut.set_exception(
                GarbageCollectionError(
                    f"{self} was garbage collected before finishing.\n"
                    "This exception exists to help debug an issue inside of dank mids. Please show it to Bob."
                )
            )

    @property
    def request(self) -> Union[Request, PartialRequest]:
        return self.controller.request_type(method=self.method, params=self.params, id=self.uid)

    async def get_response(self) -> RPCResponse:  # type: ignore [override]
        if not self.should_batch:
            if self._debug_logs_enabled:
                _log_debug("bypassed dank batching, method is %s", self.method)
            return await self.get_response_unbatched()

        current_batch = self._batch
        if current_batch is None:
            # NOTE: We want to force the event loop to make one full _run_once call before we execute.
            await yield_to_loop()

        elif current_batch._awaited is False:
            # NOTE: If the batch was already awaited, we filled a batch. Let's await it now so we can send something to the node.
            done_strongref, _ = await first_completed(current_batch.get_response(), self._fut)
            for fut in done_strongref:
                if fut.exception():
                    # we do this because a few RPCRequests can reach this point at the 'same time'
                    # TODO: refactor this so only 1 waiter can await get_response so RuntimeError stops happening
                    if not (
                        isinstance(exc := fut.exception(), RuntimeError)
                        and "already awaited" in str(exc)
                    ):
                        # raise it
                        fut.result()

        if self._batch is None:
            try:
                batch_task = create_task(self.controller.execute_batch(), name="batch task")
                # If this timeout fails, we go nuclear and destroy the batch.
                # Any calls that already succeeded will have already completed on the client side.
                # Any calls that have not yet completed with results will be recreated, rebatched (potentially bringing better results?), and retried
                await wait_for(shield(batch_task), timeout=TIMEOUT_SECONDS_BIG)
            except TimeoutError:
                _log_warning(
                    "%s got stuck awaiting its batch, we're creating a new one",
                    self,
                )
                done, pending = await first_completed(
                    batch_task, self._fut, self.create_duplicate()
                )
                for d in done:
                    if d in (batch_task, self._fut):
                        # we'll get and decode the value below
                        pass
                    else:
                        return d.result()

        fut = self._fut
        try:
            if fut.done():
                response = fut.result()
            else:
                try:
                    response = await wait_for(shield(fut), timeout=TIMEOUT_SECONDS_BIG)  # type: ignore [arg-type]
                except CancelledError:
                    fut.cancel()
                    raise
                except TimeoutError:
                    _log_warning(
                        "%s got stuck waiting for its fut, we're creating a new one",
                        self,
                    )
                    duplicate = self.create_duplicate()
                    duplicate_task = create_task(
                        duplicate.get_response(), name="duplicate.get_response"
                    )
                    for d in await first_completed(fut, duplicate_task, cancel=True):
                        response = d.result()
                        if d is not fut:
                            # this means duplicate_task finished first
                            return response
                    # this means the original finished first
                    duplicate._fut.cancel()

        except ClientResponseError as e:
            # TODO think about getting rid of this
            raise DankMidsClientResponseError(e, self.request) from e
        except Exception as e:
            if not hasattr(e, "request"):
                e.request = request = self.request  # type: ignore [attr-defined]
                e.args = *e.args, request
            raise

        if not isinstance(response, RawResponse):
            return response

        # JIT json decoding
        response = response.decode(partial=True)

        if response.error is None:
            if self.raw and response.result:
                return {"result": response.result}
            return response.to_dict(self.method)

        if needs_full_request_spec(response) and self.controller._check_request_type():
            method: RPCEndpoint = f"{self.method}_raw" if self.raw else self.method  # type: ignore [assignment]
            return await self.controller(method, self.params)
        elif revert_logger.isEnabledFor(DEBUG) and type(response.exception) is ExecutionReverted:
            revert_logger_log_debug("%s for %s", response.exception, self)
        elif error_logger.isEnabledFor(DEBUG) and type(response.exception) is not ExecutionReverted:
            error_logger_log_debug("%s for %s", response.error, self)

        response = response.to_dict(self.method)
        response["error"] = dict(response["error"].items(), dankmids_added_context=self.request)
        return response

    async def get_response_unbatched(self) -> RPCResponse:  # type: ignore [override]
        task = create_task(self.make_request(), name="RPCRequest.get_response_unbatched")
        try:
            await wait_for(shield(task), timeout=TIMEOUT_SECONDS_BIG)
        except CancelledError:
            task.cancel()
            raise
        except TimeoutError:
            # looks like its stuck for some reason, let's try another one
            _log_warning(
                "%s got stuck in `get_response_unbatched`, we're creating a new one...",
                self,
            )
            duplicate = self.create_duplicate()
            duplicate_task = create_task(
                duplicate.get_response_unbatched(), name="duplicate.get_response_unbatched"
            )
            done: Set[Task] = await first_completed(task, duplicate_task, cancel=True)
            for fut in done:
                if fut is not task:
                    # this means the duplicate completed first
                    return fut.result()
            # cancel the duplicate if it wasn't the one that completed first
            duplicate._fut.cancel()
        response: RawResponse = await self._fut
        decoded = response.decode(partial=True)
        return (
            {"result": decoded.result}
            if self.raw and decoded.result
            else decoded.to_dict(self.method)
        )

    async def spoof_response(self, data: Union[RawResponse, bytes, Exception]) -> None:
        # sourcery skip: merge-duplicate-blocks
        """
        `Raw` type data comes from rpc calls executed in a jsonrpc batch
        `bytes` type data comes for individual eth_calls that were batched into multicalls and already decoded
        `Exception` type data comes from failed calls
        """

        # New handler
        if isinstance(data, RawResponse):
            self._fut.set_result(data)
        elif isinstance(data, BadResponse):
            if needs_full_request_spec(data.response) and self.controller._check_request_type():
                self._fut.set_result(await self.create_duplicate())
                return
            formatted = format_error_response(self.request, data.response.error)
            self._fut.set_result({"error": formatted})
            if error_logger.isEnabledFor(DEBUG):
                error_logger_log_debug("RPC Error for %s", self)
                error_logger_log_debug("response set: %s", formatted)
        elif isinstance(data, Exception):
            self.__set_exception(data)
        # From multicalls
        elif isinstance(data, bytes):
            self._fut.set_result({"result": data})
        else:
            dtype = type(data)
            exc = TypeError(f"{dtype.__name__} not supported for spoofing.", dtype, data)
            self.__set_exception(exc)

    async def make_request(self, num_previous_timeouts: int = 0) -> RawResponse:
        """
        Used to execute the request with no batching.

        NOTE: There is some hanging behavior happening here. Not sure if specific to this func or somewhere else.
        """
        task = create_task(
            coro=self.controller.make_request(self.method, self.params, request_id=self.uid),
            name=f"RPCRequest.make_request attempt {num_previous_timeouts+1}",
        )
        try:
            response = await wait_for(shield(task), TIMEOUT_SECONDS_SMALL)
        except CancelledError:
            task.cancel()
            raise
        except TimeoutError:
            log_func = timeout_logger_warning if num_previous_timeouts > 1 else timeout_logger_debug
            log_func(
                "`make_request` timed out (%ss) %s times for %s, trying again...",
                TIMEOUT_SECONDS_SMALL,
                num_previous_timeouts + 1,
                self,
            )
            done: Set[Task] = await first_completed(
                task, self.make_request(num_previous_timeouts + 1), cancel=True
            )
            response = done.pop().result()
        self._fut.set_result(response)
        return response

    def create_duplicate(self) -> Union["RPCRequest", "eth_call"]:
        dupe_uid = f"{self.uid}_copy"
        if type(self) is eth_call:
            duplicate = eth_call(self.controller, self.params, dupe_uid)
        else:
            method: RPCEndpoint = f"{self.method}_raw" if self.raw else self.method  # type: ignore [assignment]
            duplicate = RPCRequest(self.controller, method, self.params, dupe_uid)

        selffut = self._fut
        dupefut = duplicate._fut

        def _self_done_callback(selffut):
            if selffut.cancelled():
                dupefut.cancel()
            elif (exc := selffut.exception()) is not None:
                dupefut.set_exception(exc)
            else:
                dupefut.set_result(selffut.result())

        def _dupe_done_callback(dupefut):
            if dupefut.cancelled():
                selffut.cancel()
            elif (exc := dupefut.exception()) is not None:
                selffut.set_exception(exc)
            else:
                selffut.set_result(dupefut.result())

        selffut.add_done_callback(_self_done_callback)
        dupefut.add_done_callback(_dupe_done_callback)

        return duplicate

    def __set_exception(self, data: Exception) -> None:
        if revert_logger.isEnabledFor(DEBUG) and type(data) in _REVERT_EXC_TYPES:
            self.__log_set_exception(revert_logger_log_debug, data)
        elif error_logger.isEnabledFor(DEBUG) and type(data) not in _REVERT_EXC_TYPES:
            self.__log_set_exception(error_logger_log_debug, data)
        self._fut.set_exception(data)

    def __log_set_exception(self, log_func: Callable[..., None], exc: Exception):
        exc_type = type(exc).__name__
        log_func("%s for %s", exc_type, self)
        log_func("exception set: %s", repr(exc))


_is_revert_bytes = lambda data: isinstance(data, bytes) and any(
    filter(data.startswith, constants.REVERT_SELECTORS)
)


_rpcrequest_init = RPCRequest.__init__


@final
class eth_call(RPCRequest):
    revert_threads = PruningThreadPoolExecutor(4)

    __slots__ = "target", "calldata", "block"

    def __init__(
        self, controller: "DankMiddlewareController", params: Any, uid: Optional[str] = None
    ) -> None:
        """Adds a call to the DankMiddlewareContoller's `pending_eth_calls`."""

        call_dict, block = params

        self.target: ChecksumAddress = call_dict["to"]
        """The contract address for the call."""

        self.calldata: HexBytes = HexBytes(call_dict["data"])
        """The calldata for the call."""

        self.block: BlockId = block
        """The block height at which the contract will be called."""

        _rpcrequest_init(self, controller, "eth_call", params, uid)

    def __repr__(self) -> str:
        tx, block = self.params
        batch = self._batch
        batch_info = "" if batch is None else f" batch={batch}"
        if batch is None or type(batch) is not Multicall:
            if block.startswith("0x"):
                block = int(block, 16)
            block_info = f" block={block}"
        else:
            block_info = ""
        return f"<{self.__class__.__name__} uid={self.uid}{block_info} to={tx['to']} data={tx['data']}{batch_info}>"

    @property
    def multicall_compatible(self) -> bool:
        """True if this contract is multicall compatible, False if not."""
        return self.target not in self.controller.no_multicall

    async def spoof_response(self, data: Union[bytes, Exception, RawResponse]) -> None:  # type: ignore
        """Sets and returns a spoof rpc response for this BatchedCall instance using data provided by the worker."""

        # NOTE: If `type(data)` is `bytes`, it is a result from a multicall. If not, `data` comes from a jsonrpc batch.
        # If this if clause is True, it means the call reverted inside of a multicall but returned a result, without causing the multicall to revert.
        if _is_revert_bytes(data):
            # TODO figure out how to include method selector in no_multicall key
            try:
                # NOTE: If call response from multicall indicates failure, make sync call to get either:
                # - successful response
                # - revert details from exception
                # If we get a successful response, most likely the target contract does not support multicall2.
                # TODO: Get rid of the sync executor and just use `make_request`
                controller = self.controller
                target = self.target
                data = await self.revert_threads.run(
                    controller.sync_w3.eth.call,
                    {"to": target, "data": self.calldata},
                    self.block,
                )
                # The single call was successful. We don't want to include this contract in more multicalls
                controller.no_multicall.add(target)
            except Exception as e:
                # NOTE: The call still returns a revert when it's not packed in a multicall
                data = e

        # The above revert catching logic fails to account for pre-decoding RawResponse objects.
        await RPCRequest.spoof_response(self, data)

    def _get_mc_data(self) -> MulticallChunk:
        return self.target, self.calldata


### Batch requests:

_Request = TypeVar("_Request", bound=_RequestBase)


class _Batch(_RequestBase[List[_Response]], Iterable[_Request]):
    calls: WeakList[_Request]
    _done: _RequestEvent

    _awaited: bool = False
    """A flag indicating whether the batch has been awaited."""

    __slots__ = "calls", "_batcher", "_lock", "_done", "_daemon", "__dict__"

    def __init__(self, controller: "DankMiddlewareController", calls: Iterable[_Request]):
        _request_base_init(self, controller)
        self.calls = WeakList(calls)
        self._batcher = controller.batcher
        self._lock = _AlertingRLock(name=self.__class__.__name__)
        self._done = _RequestEvent(self)

    def __len__(self) -> int:
        return len(self.calls)

    @property
    def bisected(self) -> Generator[Tuple[_Request, ...], None, None]:
        # set `self.calls` output to var so its only computed once
        calls = tuple(self.calls)
        half = len(calls) // 2
        yield calls[:half]
        yield calls[half:]

    @property
    def is_full(self) -> bool:
        raise NotImplementedError(type(self).__name__)

    def append(self, call: _Request, skip_check: bool = False) -> None:
        if self._awaited is True:
            raise RuntimeError(f"{self} was already awaited")
        with self._lock:
            self.calls.append(call)
            # self._len += 1
            if not skip_check:
                if self.is_full:
                    self.start()
                elif self.controller.queue_is_full:
                    self.controller.early_start()

    def extend(self, calls: Iterable[_Request], skip_check: bool = False) -> None:
        if self._awaited is True:
            raise RuntimeError(f"{self} was already awaited")
        with self._lock:
            self.calls.extend(calls)
            if not skip_check:
                if self.is_full:
                    self.start()
                elif self.controller.queue_is_full:
                    self.controller.early_start()

    def should_retry(self, e: Exception) -> bool:
        """Should the _Batch be retried based on `e`?"""
        if type(e) is OutOfGas:
            # TODO Remember which contracts/calls are gas guzzlers
            if len(self) > 1:
                gas_logger_debug("%s out of gas. cut in half, trying again...", self)
                return True
            return False

        str_e = f"{e}".lower()
        if any(err in str_e for err in constants.RETRY_ERRS):
            # TODO: use these exceptions to optimize for the user's node
            if len(self) > 1 and error_logger.isEnabledFor(DEBUG):
                error_logger_log_debug(
                    "Dank too loud. Bisecting %s and retrying.", type(self).__name__
                )
        elif isinstance(e, BadResponse) and (
            needs_full_request_spec(e.response) or is_call_revert(e)
        ):
            pass
        elif "429" not in str_e and all(err not in str_e for err in constants.TOO_MUCH_DATA_ERRS):
            _log_warning("unexpected %s in a %s: %s", type(e).__name__, type(self).__name__, e)
        return len(self) > 1

    def _record_failure(self, e: Exception, data: str) -> None:
        _debugging.failures.record(
            self.controller.chain_id,
            e,
            type(self).__name__,
            self.uid,
            len(self),
            data,
        )

    async def _debug_daemon(self) -> None:
        done = self._done.is_set
        # NOTE: _resonse works for RPCRequst and eth_call, _done works for _Batch classes
        i = 1
        while self and not done():
            await sleep(60)
            if self and not done():
                _log_debug(
                    "%s has not received data after %s minute%s", self, i, "" if i == 1 else "s"
                )
                i += 1


_batch_init = _Batch.__init__


_mcall_encoder: TupleEncoder = abi.default_codec._registry.get_encoder("(bool,(address,bytes)[])")
_mcall_encoder.validate_value = lambda *_: ...  # type: ignore [method-assign]


_array_encoder: DynamicArrayEncoder = _mcall_encoder.encoders[-1]  # type: ignore [index]
_array_encoder.validate_value = lambda *_: ...  # type: ignore [method-assign]


_item_encoder: TupleEncoder = _array_encoder.item_encoder
_item_encoder.validate_value = lambda *_: ...  # type: ignore [method-assign]


def __encode_new(values: Iterable[MulticallChunk]) -> bytes:
    encoded_elements, num_elements = __encode_elements_new(values)
    return encode_uint_256(num_elements) + encoded_elements


def __encode_elements_new(values: Iterable[MulticallChunk]) -> Tuple[bytes, int]:
    tail_chunks = tuple(map(_item_encoder, values))
    count = len(tail_chunks)
    head_length = 32 * count
    tail_offsets = chain((0,), accumulate(map(len, tail_chunks[:-1])))
    head_chunks = map(encode_uint_256, map(head_length.__add__, tail_offsets))
    return b"".join(chain(head_chunks, tail_chunks)), count


_array_encoder.encode = __encode_new  # type: ignore [method-assign]
_array_encoder.encode_elements = __encode_elements_new  # type: ignore [method-assign]

_mcall_decoder = abi.default_codec._registry.get_decoder("(uint256,uint256,(bool,bytes)[])").decode


def mcall_encode(data: Iterable[MulticallChunk]) -> bytes:
    return _mcall_encoder((False, data))


# maybe use this success flag to do something later
Success = bool
__get_bytes = lambda tup: tup[1]


def mcall_decode(data: PartialResponse) -> Union[List[bytes], Exception]:
    decoded: List[Tuple[Success, bytes]]
    try:
        decoded = _mcall_decoder(decoding.ContextFramesBytesIO(data.decode_result("eth_call")))[2]  # type: ignore [arg-type]
    except Exception as e:
        # NOTE: We need to safely bring any Exceptions back out of the ProcessPool
        e.args = (*e.args, data.decode_result() if isinstance(data, PartialResponse) else data)
        return e
    else:
        return list(map(__get_bytes, decoded))


@final
class Multicall(_Batch[RPCResponse, eth_call]):
    method = "eth_call"
    fourbyte = function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")

    _awaited: bool
    """A flag indicating whether the Multicall has been awaited."""

    __slots__ = ("bid",)

    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: Iterable[eth_call] = [],
        bid: Optional[BatchId] = None,
    ):
        # sourcery skip: default-mutable-arg
        _batch_init(self, controller, calls)
        self.bid = bid or self.controller.multicall_uid.next

    def __repr__(self) -> str:
        block = self.block
        if block.startswith("0x"):
            block = int(block, 16)
        batch = self._batch
        batch_info = "" if batch is None else f" batch={batch}"
        return f"<Multicall mid={self.bid} block={block} len={len(self)}{batch_info} awaited={self._awaited}>"

    def __iter__(self) -> Iterator[eth_call]:
        return iter(self.calls)

    def __bool__(self) -> bool:
        return bool(self.calls)

    def __del__(self) -> None:
        if self.calls and not self._done.is_set():
            logged = False
            for call in self.calls:
                if not call._fut.done():
                    if logged is False:
                        error_logger.error("%s was garbage collected before finishing", self)
                        logged = True
                    call._fut.set_exception(
                        GarbageCollectionError(
                            f"{self} was garbage collected before finishing.",
                            f"{call} might hang indefinitely if I don't raise this exception, "
                            "which only exists to help debug an issue inside of dank mids. "
                            "Please show it to Bob.",
                        )
                    )

    @cached_property
    def block(self) -> BlockId:
        return next(iter(self.calls)).block

    @property
    def calldata(self) -> str:
        return (self.fourbyte + mcall_encode(map(eth_call._get_mc_data, self.calls))).hex()  # type: ignore [misc]

    @cached_property
    def mcall(self) -> MulticallContract:
        return self.controller._select_mcall_target_for_block(self.block)

    @property
    def target(self) -> ChecksumAddress:
        return self.mcall.address

    @property
    def params(self) -> JsonrpcParams:
        target = self.target
        params = [{"to": target, "data": f"0x{self.calldata}"}, self.block]
        if self.needs_override_code and not self.controller.state_override_not_supported:
            params.append({target: {"code": self.mcall.bytecode}})
        return params  # type: ignore [return-value]

    @property
    def request(self) -> Union[Request, PartialRequest]:
        return self.controller.request_type(method=self.method, params=self.params, id=self.uid)

    @property
    def is_full(self) -> bool:
        return len(self) >= self._batcher.step

    @property
    def needs_override_code(self) -> bool:
        return self.mcall.needs_override_code_for_block(self.block)

    def start(self, batch: Optional[Union["_Batch", "DankBatch"]] = None, cleanup=True) -> None:
        batch = batch or self
        if _logger_is_enabled_for(DEBUG):
            self._daemon = create_task(self._debug_daemon(), name="Multicall debug daemon")
        with self._lock:
            for call in self.calls:
                call._batch = self
            if cleanup:
                controller = self.controller
                with controller.pools_closed_lock:
                    controller._pending_eth_calls_pop(self.block, None)

    async def get_response(self) -> None:  # type: ignore [override]
        if self._awaited:
            raise RuntimeError(f"{self} already awaited", current_task())

        self._awaited = True
        if (l := len(self)) == 1:
            return await self._exec_single_call()
        # elif l < 50: # TODO play with later
        #    return await JSONRPCBatch(self.controller, self.calls)

        # create a strong ref to all calls we will execute so they cant get gced mid execution and mess up response ordering
        calls = tuple(self.calls)
        if not calls:
            # TODO: figure out how we get into this function without any calls
            return

        controller = self.controller
        rid = controller.request_uid.next
        _demo_logger_info("request %s for multicall %s starting", rid, self.bid)
        try:
            await self.spoof_response(
                await controller.make_request(self.method, self.params, request_id=self.uid),
                calls,
            )
        except internal_err_types.__args__ as e:  # type: ignore [attr-defined]
            raise e if "invalid argument" in str(e) else DankMidsInternalError(e) from e
        except Exception as e:
            if isinstance(e, ClientResponseError) and e.message == "Payload Too Large":
                _log_info("Payload too large. response headers: %s", e.headers)
                controller.reduce_multicall_size(len(self))
                self._record_failure(e, self.request.data.decode())
            elif _log_exception(e):
                self._record_failure(e, self.request.data.decode())

            if self.should_retry(e):
                await self.bisect_and_retry(e)
            elif len(self) == 1:
                await next(iter(self.calls)).get_response_unbatched()
            else:
                await self.spoof_response(e)

        _demo_logger_info("request %s for multicall %s complete", rid, self.bid)

    def should_retry(self, e: Exception) -> bool:
        """Should the Multicall be retried based on `e`?"""
        # NOTE: While it might look weird, f-string is faster than `str(e)`.
        if any(map(f"{e}".lower().__contains__, constants.RETRY_ERRS)):
            msg = "dank too loud, multicall %s got exc%s\ntrying again..."
            error_logger_debug(msg, self.bid, e)
            return True
        elif "No state available for block" in f"{e}":
            note = "You're not using an archive node, and you need one for the application you are attempting to run."
            e.args[0]["dankmids_note"] = note
            return False
        elif _Batch.should_retry(self, e):
            return True
        return len(self) > 1

    @set_done
    async def spoof_response(
        self, data: Union[RawResponse, Exception], calls: Optional[Sequence[eth_call]] = None
    ) -> None:
        # This happens if an Exception takes place during a non-batched Multicall request.
        if isinstance(data, Exception):
            if error_logger.isEnabledFor(DEBUG):
                exc_type = type(data).__name__
                error_logger_log_debug("%s had %s %s", self, exc_type, data)
                error_logger_log_debug("propagating the %s to all %s's calls", exc_type, self)

            # No need to gather this, `spoof_response` with an Exception input will complete synchronously
            for call in calls or self.calls:
                await call.spoof_response(data)

        # A `RawResponse` represents either a successful or a failed response, stored as pre-decoded bytes.
        # It was either received as a response to a single rpc call or as a part of a batch response.
        elif isinstance(data, RawResponse):
            response = data.decode(partial=True)
            if response.error is not None:
                exc = response.exception
                if error_logger.isEnabledFor(DEBUG) and type(exc) is not OutOfGas:
                    error_logger_log_debug(
                        "%s for %s",
                        response.error if type(exc) is BadResponse else repr(exc),
                        self,
                    )
                # NOTE: We raise the exception which will be caught, call will be broken up and retried
                raise exc
            _log_debug("%s received valid bytes from the rpc", self)

            # We write some ugly code to separate successes from reverts
            # For successful calls, we can set the result right away
            # For reverts, we asynchronously attempt to handle the revert

            # NOTE: we pass in the calls to create a strong reference so when we zip up the results everything gets to the right place
            if calls is None:
                calls = tuple(self.calls)

            to_gather = []
            for call, result in zip(calls, await self.decode(response)):
                if _is_revert_bytes(result):
                    # We will asynchronously handle this revert
                    to_gather.append(eth_call.spoof_response(call, result))
                else:
                    # `spoof_response` with a successful call result will complete synchronously
                    await eth_call.spoof_response(call, result)

            await gatherish(to_gather, name="Multicall.spoof_response gatherish")

        else:
            raise NotImplementedError(f"type {type(data)} not supported.", data)

    async def decode(self, data: PartialResponse) -> List[bytes]:
        start = time()
        if ENVS.OPERATION_MODE.infura or len(self) < 100:
            # decode synchronously
            retval = mcall_decode(data)
        else:
            try:
                retval = await ENVS.MULTICALL_DECODER_PROCESSES.run(mcall_decode, data)  # type: ignore [attr-defined]
            except BrokenProcessPool:
                # TODO: Move this somewhere else
                logger.critical("Oh fuck, you broke the %s while decoding %s", ENVS.MULTICALL_DECODER_PROCESSES, data)  # type: ignore [attr-defined]
                ENVS.MULTICALL_DECODER_PROCESSES = AsyncProcessPoolExecutor(ENVS.MULTICALL_DECODER_PROCESSES._max_workers)  # type: ignore [attr-defined,assignment]
                retval = mcall_decode(data)

        stats.log_duration(f"multicall decoding for {len(self)} calls", start)
        # Raise any Exceptions that may have come out of the process pool.
        if isinstance(retval, Exception):
            raise retval.__class__(
                *retval.args,
                self.request,
                f"response: {data}",
            )
        return retval

    @set_done
    async def bisect_and_retry(self, e: Exception) -> None:
        """
        Split the :class:`~Multicall` into 2 chunks, then await both.

        Calls `self._done.set()` when finished.

        Args:
            e: The Exception that occured to cause the retry.
        """
        if error_logger.isEnabledFor(DEBUG) and type(e) is not OutOfGas:
            error_logger_log_debug(
                "%s had %s, bisecting and retrying...",
                self,
                e.response.error if type(e) is BadResponse else repr(e),
            )
        controller = self.controller
        # we need to create strong refs to the multicalls here so they dont disappear as soon as the JSONRPCBatch inits
        bisected = [
            Multicall(controller, chunk, f"{self.bid}_{i}") for i, chunk in enumerate(self.bisected)
        ]
        if controller.pending_rpc_calls:
            batch0, batch1 = bisected
            controller._pending_rpc_calls_append(batch0)
            if batch1:
                if controller.pending_rpc_calls:
                    controller._pending_rpc_calls_append(batch1)
                else:
                    await batch1
            await controller.pending_rpc_calls._done.wait()
        else:
            batch = JSONRPCBatch(controller, bisected, f"{self.uid}_bisected")
            batch.start(self, cleanup=False)
            await batch

    @set_done
    async def _exec_single_call(self) -> None:
        """NOTE: There is some hanging behavior happening here. Not sure if specific to this func or somewhere in make_request."""
        await next(iter(self.calls)).make_request()

    async def _spoof_or_retry(self, response: RawResponse) -> None:
        try:
            await self.spoof_response(response)
        except Exception as e:
            if not self.should_retry(e):
                raise
            await self.bisect_and_retry(e)


def _log_checking_batch_size(
    batch_type: Literal["multicall", "json"],
    member_type: Literal["calls", "requests"],
    num_calls: int,
) -> None:
    batch_size_logger.info(
        "checking if we should reduce %s batch size... (%s %s)", batch_type, num_calls, member_type
    )


@final
class JSONRPCBatch(_Batch[RPCResponse, Union[Multicall, eth_call, RPCRequest]]):
    """
    Represents a batch of JSON-RPC requests.

    This class manages a collection of JSON-RPC requests that will be sent
    as a single batch to an Ethereum node, improving efficiency by reducing
    the number of separate network calls.
    """

    __slots__ = ("jid",)

    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: Iterable[Union[Multicall, RPCRequest]] = [],
        jid: Optional[BatchId] = None,
    ) -> None:  # sourcery skip: default-mutable-arg
        """
        Initialize a new JSONRPCBatch.

        Args:
            controller: The :class:`~DankMiddlewareController` instance that manages this batch.
            calls: A list of :class:`~RPCRequest` or :class:`~Multicall` objects to be included in the batch.
            jid: A unique identifier for this batch. If none is provided, one will be created.
        """
        _batch_init(self, controller, calls)
        self.jid = jid or self.controller.jsonrpc_batch_uid.next

    def __repr__(self) -> str:
        batch = self._batch
        batch_info = "" if batch is None else f" batch={batch}"
        return f"<JSONRPCBatch jid={self.jid} len={len(self)}{batch_info} awaited={self._awaited}>"

    def __iter__(self) -> Iterator[Union[Multicall, eth_call, RPCRequest]]:
        return filter(None, self.calls)

    def __bool__(self) -> bool:
        for _ in self:
            return True
        return False

    def __del__(self) -> None:
        if any(self) and not self._done.is_set():
            for cls, calls in groupby(self.calls, type):
                if cls is Multicall:
                    calls = concat(filter(None, calls))
                if any(filterfalse(Future.done, (call._fut for call in calls))):
                    error_logger.error("%s was garbage collected before finishing", self)
                    return

    @property
    def data(self) -> bytes:
        if not self:
            raise EmptyBatch(f"batch {self.uid} is empty and should not be processed.")
        try:
            return b"[" + b",".join(call.request.data for call in self) + b"]"
        except TypeError:
            # If we can't encode one of the calls, lets figure out which one and pass some useful info downstream
            for call in self:
                try:
                    call.request.data
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
        """
        Count the occurrences of each method in the batch.

        Returns:
            A dictionary where keys are method names and values are their counts.
        """
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
        """
        Get the total number of calls across all requests in the batch.

        This may differ from __len__ if the batch includes multicalls.

        Returns:
            The total number of individual calls in the batch.
        """
        with self._lock:
            return sum(map(len, self))

    @property
    def is_full(self) -> bool:
        with self._lock:
            return (
                self.total_calls >= self._batcher.step
                or len(self) >= self.controller.max_jsonrpc_batch_size
            )

    def start(self, batch: Optional["DankBatch"] = None, cleanup=True) -> None:
        # sourcery skip: hoist-loop-from-if
        batch = batch or self
        if _logger_is_enabled_for(DEBUG):
            self._daemon = create_task(self._debug_daemon(), name="JSONRPCBatch debug daemon")
        with self._lock:
            for typ, calls in groupby(self.calls, type):
                if typ is Multicall:
                    for call in calls:
                        call.start(batch, cleanup=cleanup)
                else:
                    for call in calls:
                        call._batch = self
            if cleanup:
                self.controller._start_new_batch()

    async def get_response(self) -> None:  # type: ignore [override]
        if self._awaited:
            raise RuntimeError(
                f"{self} was already awaited. This shouldn't really happen bro",
                f"task that awaited the 2nd time: {current_task()}",
            )

        self._awaited = True

        if self.is_single_multicall:
            await next(iter(self.calls))
            self._done.set()
            return

        rid = self.controller.request_uid.next
        if ENVS.DEMO_MODE:  # type: ignore [attr-defined]
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            _demo_logger_info(
                "request %s for jsonrpc batch %s (%s calls) starting",
                rid,
                self.jid,
                sum(map(len, self)),
            )
        try:
            while True:
                try:
                    # NOTE: We do this inline so we never have to allocate the response to memory
                    await self.spoof_response(*await self.post())
                    break
                except ChainstackRateLimited as e:
                    # Chainstack doesn't use 429 for rate limiting, it sends a successful response back to the rpc
                    # with an error message so our usual rate-limiting handlers don't work and we need to handle that case with bespoke logic.
                    await sleep(e.try_again_in)

        # I want to see these asap when working on the lib.
        except internal_err_types.__args__ as e:  # type: ignore [attr-defined]
            raise e if "invalid argument" in str(e) else DankMidsInternalError(e) from e
        except EmptyBatch as e:
            _log_warning(
                "These EmptyBatch exceptions shouldn't actually happen and this except clause can probably be removed soon."
            )
        except ExceedsMaxBatchSize as e:
            _log_warning("exceeded max batch size for your node")
            self.controller.set_batch_size_limit(e.limit)
            await self.bisect_and_retry(e)
        except PayloadTooLarge as e:
            # TODO: track too large payloads and do some better optimizations for batch sizing
            self.adjust_batch_size()
            await self.bisect_and_retry(e)
        except Exception as e:
            if _log_exception(e):
                self._record_failure(e, self.data)
            stats.log_errd_batch(self)

            if self.should_retry(e):
                # should_retry will always return True if there is more than 1 call in this batch
                await self.bisect_and_retry(e)

            else:
                # NOTE: This means an exception occurred during the post request
                # AND that the json batch is made of just one rpc request that is not a multicall.
                error_logger_debug(
                    "%s had exception %s, aborting and sending Exception to waiters", self, e
                )
                await igather(call.spoof_response(e) for call in self.calls)

        _demo_logger_info("request %s for jsonrpc batch %s complete", rid, self.jid)  # type: ignore

    @eth_retry.auto_retry
    async def post(self) -> Tuple[List[RawResponse], List[Union[Multicall, RPCRequest]]]:
        """
        Send the batch of requests to the Ethereum node and process the responses.

        This method sends the batch of requests to the Ethereum node and
        processes the responses.

        Returns:
            A tuple containing the raw responses and the list of calls in the batch.

        Raises:
            BadResponse: If a successful 'error' response was received from the rpc.
            ClientResponseError: If there was an error with the HTTP request.
            Exception: For other unexpected errors.
        """
        try:
            # we need strong refs so the results all get to the right place
            calls = tuple(self)
            # for the multicalls too
            mcall_calls_strong_refs = tuple(tuple(call.calls) for call in calls if type(call) is Multicall)  # type: ignore [union-attr]
            response: JSONRPCBatchResponse = await _session.post(
                self.controller.endpoint, data=self.data, loads=_codec.decode_jsonrpc_batch
            )
        except ClientResponseError as e:
            if e.message == "Payload Too Large":
                _log_warning("Payload too large: %s", self.method_counts)
                self.adjust_batch_size()
            elif "broken pipe" in str(e).lower():
                _log_warning("This is what broke the pipe: %s", self.method_counts)
            error_logger_debug("caught %s for %s, reraising", e, self)
            if ENVS.DEBUG:  # type: ignore [attr-defined]
                self._record_failure(e, self.data.decode())
            raise
        except Exception as e:
            if "broken pipe" in str(e).lower():
                _log_warning("This is what broke the pipe: %s", self.method_counts)
            if ENVS.DEBUG:  # type: ignore [attr-defined]
                self._record_failure(e, self.data.decode())
            raise

        # NOTE: A successful response will be a list of `RawResponse` objects.
        #       A single `PartialResponse` implies an error.
        if isinstance(response, list):
            return response, calls

        # Oops, we failed.
        errmsg = response.error.message
        if errmsg.lower() in ("invalid request", "parse error"):  # type: ignore [union-attr]
            # NOT SURE IF THIS ACTUALLY RUNS, CAN WE RECEIVE THIS TYPE RESPONSE FOR A JSON BATCH?
            self.controller._check_request_type()
        elif errmsg == "batch limit exceeded":  # type: ignore [union-attr]
            self.adjust_batch_size()

        if ENVS.DEBUG:
            self._record_failure(response.exception)

        raise response.exception

    def should_retry(self, e: Exception) -> bool:
        """
        Determine whether the JSONRPCBatch should be retried based on the exception.

        Args:
            e: The exception that occurred during the batch request.

        Returns:
            True if the batch should be retried, False otherwise.
        """
        # While it might look weird, f-string is faster than `str(e)`.
        if "No state available for block" in f"{e}":
            error_logger_debug(
                "No state available for one of the blocks queried. Bisecting batch and retrying."
            )
            return True
        elif self.is_single_multicall:
            # TODO: delete this eventually if it doesn't trigger
            raise RuntimeError(
                "pretty sure we can't get here anymore now that I check this in the beginning of JSONRPCBatch.get_response"
            )
        return _Batch.should_retry(self, e)

    @set_done
    async def spoof_response(
        self, response: List[RawResponse], calls: Tuple[RPCRequest, ...]
    ) -> None:
        """
        Process the responses from the Ethereum node and set the results for each call.

        This method processes the responses from the Ethereum node and sets the results
        for each call in the batch. It also handles any exceptions that occurred during
        the processing.

        Args:
            response: A list of RawResponse objects containing the responses from the node.
            calls: A list of RPCRequest objects that were included in the batch.
        """
        # Reaching this point means we made a batch call and we got results. That doesn't mean they're good, but we got 'em.

        controller = self.controller

        if controller._sort_calls:
            # NOTE: these providers don't always return batch results in the correct ordering
            # NOTE: is it maybe because they
            calls = sorted(calls, key=lambda call: call.uid)  # type: ignore [assignment]

        if controller._sort_response:
            response.sort(key=lambda raw: raw.decode().id)
        else:
            for call, raw in zip(calls, response):
                # TODO: make sure this doesn't ever raise and then delete it
                if call.uid != raw.decode().id:
                    # Not sure why it works this way
                    raise BatchResponseSortError(controller, calls, response)

        responses = iter(response)
        mcall_coros = []
        for request_type, requests in groupby(calls, type):
            if request_type is Multicall:
                mcall_coros.extend(map(Multicall._spoof_or_retry, requests, responses))
            else:
                # These do not need to be delegated to asks since they
                # will always complete synchronously when called here
                for coro in map(request_type.spoof_response, requests, responses):
                    await coro

        if mcall_coros:
            await gatherish(mcall_coros, name="JSONRPCBatch.spoof_response gatherish")

    @set_done
    async def bisect_and_retry(self, e: Exception) -> None:
        """
        Split the batch into two halves and retry each half separately.

        This method splits the batch of calls into two halves and retries each half
        separately. If one half is just a single multicall, it will be handled alone,
        not placed into a batch.

        Sets :attr:`~JSONRPCBatch._done` on the batch when finished.

        Args:
            e: The exception that occurred during the batch request.
        """
        if error_logger.isEnabledFor(DEBUG):
            exc_str = e.response.error if type(e) is BadResponse else repr(e)
            error_logger_log_debug("%s had %s", self, exc_str)
            error_logger_log_debug("retrying...")

        controller = self.controller
        batches = [
            (
                Multicall(controller, first_call, f"json{self.jid}_{i}")  # type: ignore [misc]
                if len(chunk) == 1 and isinstance(first_call := next(iter(chunk)), Multicall)
                else JSONRPCBatch(controller, chunk, f"{self.jid}_{i}")
            )
            for i, chunk in enumerate(self.bisected)
            if chunk
        ]
        for batch in batches:
            batch.start(self, cleanup=False)
        for batch, result in zip(batches, await igather(batches, return_exceptions=True)):
            if isinstance(result, Exception):
                if not isinstance(result, DankMidsInternalError):
                    log_internal_error(logger, batch, result)
                raise result

    def adjust_batch_size(self) -> None:
        """
        Adjust the batch size on the controller based on the type of calls in the batch.

        This method adjusts the batch size based on whether the batch contains
        multicalls or regular JSON-RPC calls. It logs appropriate messages and
        updates the batch size accordingly.
        """
        if self.is_multicalls_only:
            num_calls = self.total_calls
            _log_checking_batch_size("multicall", "calls", num_calls)
            self.controller.reduce_multicall_size(num_calls)
        else:
            _log_checking_batch_size("json", "requests", len(self))
            self.controller.reduce_batch_size(len(self))
            _log_devhint(
                "We still need some better logic for catching these errors and using them to better optimize the batching process"
            )


def _log_exception(e: Exception) -> bool:
    """
    Log exceptions that occur during a multicall or batch.

    This function logs exceptions that are unexpected and considered errors,
    allowing for better debugging and monitoring.

    Args:
        e: The exception to log.

    Returns:
        True if the exception should be logged, False otherwise.
    """
    # NOTE: These errors are expected during normal use and are not indicative of any problem(s). No need to log them.
    if type(e) is OutOfGas:
        return ENVS.DEBUG

    # NOTE: These errors are expected during normal use and are not indicative of any problem(s). No need to log them.
    # TODO: Better filter what we choose to log here
    dont_need_to_see_errs = [
        "non_empty_data",
        "exceeding --rpc.returndata.limit",
        "'code': 429",
    ]

    dont_need_to_see_errs += [
        # We catch and correct these
        "invalid request",
        # We pass these down to the call they originated from
        *INDIVIDUAL_CALL_REVERT_STRINGS,
    ]

    stre = str(e).lower()
    if all(
        err not in stre
        for err in chain(dont_need_to_see_errs, constants.RETRY_ERRS, constants.TOO_MUCH_DATA_ERRS)
    ):
        _log_warning(
            "The following exception is being logged for informational purposes and does not indicate failure:"
        )
        _log_warning(e, exc_info=True)
    return ENVS.DEBUG  # type: ignore [attr-defined,return-value]


_log_debug = logger.debug
_log_info = logger.info
_log_warning = logger.warning
_logger_is_enabled_for = logger.isEnabledFor
_log_devhint = stats.logger.devhint
_demo_logger_info = demo_logger.info
