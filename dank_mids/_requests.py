from asyncio import (
    Future,
    Task,
    TimeoutError,
    create_task,
    get_running_loop,
    shield,
    sleep,
    wait,
    wait_for,
)
from collections import defaultdict
from concurrent.futures.process import BrokenProcessPool
from itertools import chain, filterfalse, groupby
from time import time
from typing import (
    TYPE_CHECKING,
    Any,
    Callable,
    DefaultDict,
    Dict,
    Final,
    Generator,
    Generic,
    Iterable,
    Iterator,
    List,
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
from a_sync.debugging import stuck_coro_debugger
from a_sync.functools import cached_property_unsafe as cached_property
from aiohttp.client_exceptions import ClientResponseError
from eth_typing import ChecksumAddress
from eth_utils.toolz import concat
from faster_hexbytes import HexBytes
from requests.exceptions import ReadTimeout
from web3.exceptions import ContractLogicError
from web3.types import RPCEndpoint, RPCResponse
from web3.types import RPCError as _RPCError

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids import _debugging, constants, stats
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import (
    BadResponse,
    BatchResponseSortError,
    ChainstackRateLimitError,
    DankMidsInternalError,
    EmptyBatch,
    ExceedsMaxBatchSize,
    ExecutionReverted,
    OutOfGas,
    PayloadTooLarge,
    RateLimitError,
    internal_err_types,
)
from dank_mids._logging import DEBUG, getLogger
from dank_mids._tasks import (
    BATCH_TASKS,
    TIMEOUT_SECONDS_BIG,
    TIMEOUT_SECONDS_SMALL,
    batch_done_callback,
    try_for_result,
    try_for_result_quick,
)
from dank_mids.exceptions import GarbageCollectionError
from dank_mids.helpers import DebuggableFuture, _codec, _session, batch_size, gatherish
from dank_mids.helpers._codec import (
    JSONRPCBatchResponse,
    MulticallChunk,
    RawResponse,
    mcall_decode,
    mcall_encode,
)
from dank_mids.helpers._errors import (
    INDIVIDUAL_CALL_REVERT_STRINGS,
    error_logger,
    error_logger_debug,
    error_logger_log_debug,
    gas_logger_debug,
    is_call_revert,
    is_revert_bytes,
    log_internal_error,
    needs_full_request_spec,
    revert_logger,
    revert_logger_log_debug,
    timeout_logger_debug,
    timeout_logger_warning,
)
from dank_mids.helpers._helpers import set_done
from dank_mids.helpers._lock import AlertingRLock
from dank_mids.helpers._multicall import MulticallContract
from dank_mids.helpers._rate_limit import rate_limit_inactive
from dank_mids.helpers._weaklist import WeakList
from dank_mids.helpers.method import get_len as get_len_for_method
from dank_mids.helpers.method import should_batch as should_batch_method
from dank_mids.types import (
    BatchId,
    BlockId,
    JsonrpcParams,
    PartialRequest,
    PartialResponse,
    Request,
    Response,
)

if TYPE_CHECKING:
    from dank_mids._batch import DankBatch
    from dank_mids.controller import DankMiddlewareController


logger: Final = getLogger(__name__)

_Response = TypeVar(
    "_Response", Response, List[Response], RPCResponse, List[RPCResponse], RawResponse
)


@final
class RPCError(_RPCError, total=False):
    dankmids_added_context: Dict[str, Any]


_super_init: Final = a_sync.Event.__init__
_super_set: Final = a_sync.Event.set


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

    def __init__(
        self,
        controller: "DankMiddlewareController",
        uid: str | None = None,
        fut: DebuggableFuture[RPCResponse] | None = None,
    ) -> None:
        self.controller: Final = controller
        """The DankMiddlewareController that created this request."""

        self.uid: Final = controller.call_uid.next if uid is None else uid
        """The unique id for this request."""

        self._fut: Final = DebuggableFuture(self, controller._loop) if fut is None else fut

    def __bool__(self) -> bool:
        """Return True if the request is active, False if complete."""
        return not self._fut.done()

    def __await__(self) -> Generator[Any, None, _Response]:
        return self.get_response().__await__()

    # Abstract methods to be implemented by subclasses

    def __len__(self) -> int:
        raise NotImplementedError

    async def get_response(self) -> _Response:
        raise NotImplementedError


### Single requests:
_REVERT_EXC_TYPES: Final = ContractLogicError, ExecutionReverted

_request_base_init: Final = _RequestBase.__init__


class RPCRequest(_RequestBase[RPCResponse]):
    should_batch: bool = True
    """`True` if this request should be batched with others into a jsonrpc batch request, `False` if it should be sent as an individual request."""

    _tiny_batches: bool = False
    """`True` if the max jsonrpc batch size is 50 or lower."""

    _debug_logs_enabled: bool = False
    """`True` if debug logging is currently enabled."""

    method: Final[RPCEndpoint]
    params: Final[Any]
    raw: Final[bool]
    _fut: Final[DebuggableFuture[RPCResponse]]
    _daemon: Final[Task[None] | None]
    __dict__: Final[Dict[str, Any]]

    __slots__ = "method", "params", "raw", "_daemon", "__dict__"

    def __init__(
        self,
        controller: "DankMiddlewareController",
        method: RPCEndpoint,
        params: Any,
        uid: str | None = None,
        fut: DebuggableFuture[RPCResponse] | None = None,
    ) -> None:  # sourcery skip: hoist-statement-from-if
        _request_base_init(self, controller, uid, fut)
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

        if not should_batch_method(method):
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
                    controller.pending_rpc_calls.append(self)
        _demo_logger_info("added to queue (cid: %s)", self.uid)
        if _logger_is_enabled_for(DEBUG):
            self._daemon = create_task(self._debug_daemon(), name="RPCRequest debug daemon")

    def __hash__(self) -> int:
        return id(self)

    def __eq__(self, __o: object) -> bool:
        return (self.uid == __o.uid) if type(__o) is type(self) else False

    def __len__(self) -> int:
        # NOTE: We dont need to consider response size for each method for very small batch sizes since the requests/responses will never get too large
        return 1 if self._tiny_batches else get_len_for_method(self.method)

    def __repr__(self) -> str:
        batch = self._batch
        batch_info = "" if batch is None else f" batch={batch}"
        return f"<{self.__class__.__name__} uid={self.uid} method={self.method} params={self.params}{batch_info}>"

    def __del__(self) -> None:
        """Log an error if this call is not complete it is deleted."""
        fut = self._fut
        if not fut.done() and not fut._loop.is_closed():
            try:
                fut.set_exception(
                    GarbageCollectionError(
                        f"{self} was garbage collected before finishing.\n"
                        "This exception exists to help debug an issue inside of dank mids. Please show it to Bob."
                    )
                )
            except RuntimeError as e:
                if str(e) != "no running event loop":
                    raise
            else:
                # mark exception as retrieved, if its really relevant to the user it will be raised by their waiter
                fut.exception()

    @property
    def request(self) -> Union[Request, PartialRequest]:
        return self.controller.request_type(method=self.method, params=self.params, id=self.uid)

    @stuck_coro_debugger
    async def get_response(self) -> RPCResponse:  # type: ignore [override]
        if not self.should_batch:
            if self._debug_logs_enabled:
                _log_debug("bypassed dank batching, method is %s", self.method)
            return await self.get_response_unbatched()

        fut = self._fut
        current_batch = self._batch
        if current_batch is None:
            # NOTE: We want to force the event loop to make one full _run_once call before we execute.
            await yield_to_loop()

        elif current_batch._awaited is False:
            # NOTE: If current_batch is not None, that means we filled a batch. Let's await it now so we can send something to the node.
            await wait((current_batch._task, fut), return_when="FIRST_COMPLETED")

        if self._batch is None:

            batch_coro = self.controller.execute_batch()
            batch_task = create_task(batch_coro, name="batch task execute_batch")

            # create a strong reference since we might exit when a result is received but the batch is incomplete
            BATCH_TASKS.add(batch_task)

            # discard the strong reference when the task completes successfully
            batch_task.add_done_callback(batch_done_callback)

            try:
                # If this timeout fails, we go nuclear and destroy the batch.
                # Any calls that already succeeded will have already completed on the client side.
                # Any calls that have not yet completed with results will be recreated,
                # rebatched (potentially bringing better results?), and retried
                await wait_for(shield(batch_task), timeout=TIMEOUT_SECONDS_BIG)
            except TimeoutError:
                batch_complete = False
                _log_debug(
                    "%s got stuck awaiting its batch, we're creating a new one",
                    self,
                )
            else:
                batch_complete = True
                BATCH_TASKS.discard(batch_task)

            if not batch_complete:
                # Create the duplicate before checking the rate limiter
                # so it can be added to any pending batch that might exist
                duplicate = self.create_duplicate()
                await rate_limit_inactive(self.controller.endpoint)
                return await duplicate.get_response()

        try:
            if fut.done():
                response = fut.result()
            else:
                try:
                    response = await try_for_result(fut)
                except TimeoutError:
                    _log_debug(
                        "%s got stuck waiting for its fut, we're creating a new one",
                        self,
                    )
                    done = False
                else:
                    done = True

                if not done:
                    # Create the duplicate before checking on the rate limit so it can join an existing batch if available
                    duplicate = self.create_duplicate()

                    # don't start counting for the timeout while we still have a queue of requests to send
                    await rate_limit_inactive(self.controller.endpoint)

                    # The the original request and the duplicate request share the same underlying future so we can just await the duplicate
                    return await duplicate.get_response()

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
            method = RPCEndpoint(f"{self.method}_raw") if self.raw else self.method
            return await self.controller(method, self.params)
        elif revert_logger.isEnabledFor(DEBUG) and type(response.exception) is ExecutionReverted:
            revert_logger_log_debug("%s for %s", response.exception, self)
        elif error_logger.isEnabledFor(DEBUG) and type(response.exception) is not ExecutionReverted:
            error_logger_log_debug("%s for %s", response.error, self)

        response = response.to_dict(self.method)
        response["error"] = dict(response["error"].items(), dankmids_added_context=self.request)
        return response

    @stuck_coro_debugger
    async def get_response_unbatched(self) -> RPCResponse:  # type: ignore [override]
        task = create_task(self.make_request(), name="RPCRequest.get_response_unbatched")
        try:
            await try_for_result(task)
        except TimeoutError:
            # looks like its stuck for some reason, let's try another one
            _log_debug(
                "%s got stuck in `get_response_unbatched`, we're creating a new one...",
                self,
            )

            # don't start counting for the timeout while we still have a queue of requests to send
            await rate_limit_inactive(self.controller.endpoint)

            # The the original request and the duplicate request share the same underlying future so we can just await the duplicate
            # NOTE: Now that this has been refactored do we actually even need the duplicate task?
            return await self.create_duplicate().get_response_unbatched()

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
            formatted = data.response.error.to_dict(context=self.request)  # type: ignore [union-attr]
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

    @stuck_coro_debugger
    async def make_request(self, num_previous_timeouts: int = 0) -> RawResponse:
        """
        Execute the request with no batching.

        Args:
            num_previous_timeouts (optional): the number of times this request has already been attempted and timed out. Default 0.
        """
        task = create_task(
            coro=self.controller.make_request(self.method, self.params, request_id=self.uid),
            name=f"RPCRequest.make_request attempt {num_previous_timeouts+1}",
        )

        try:
            response = await try_for_result_quick(task)
        except TimeoutError:
            log_func = timeout_logger_warning if num_previous_timeouts > 1 else timeout_logger_debug
            log_func(
                "`make_request` timed out (%ss) %s times for %s, trying again...",
                TIMEOUT_SECONDS_SMALL,
                num_previous_timeouts + 1,
                self,
            )
            next_attempt_coro = self.make_request(num_previous_timeouts + 1)
            next_attempt_task = create_task(next_attempt_coro, name="next attempt task")
            done, _ = await wait((task, next_attempt_task), return_when="FIRST_COMPLETED")
            first_done = done.pop()
            response = first_done.result()
            if first_done is not next_attempt_task:
                # `next_attempt_task` would have already set the fut result, but `task` would not have
                self._fut.set_result(response)
        else:
            self._fut.set_result(response)

        return response

    def create_duplicate(self) -> Union["RPCRequest", "eth_call"]:
        dupe_uid = f"{self.uid}_copy"
        if type(self) is eth_call:
            duplicate = eth_call(self.controller, self.params, dupe_uid, self._fut)
        else:
            method = RPCEndpoint(f"{self.method}_raw") if self.raw else self.method
            duplicate = RPCRequest(self.controller, method, self.params, dupe_uid, self._fut)

        return duplicate

    def __set_exception(self, data: Exception) -> None:
        if revert_logger.isEnabledFor(DEBUG) and type(data) in _REVERT_EXC_TYPES:
            self.__log_set_exception(revert_logger_log_debug, data)
        elif error_logger.isEnabledFor(DEBUG) and type(data) not in _REVERT_EXC_TYPES:
            self.__log_set_exception(error_logger_log_debug, data)
        self._fut.set_exception(data)

    def __log_set_exception(self, log_func: Callable[..., None], exc: Exception) -> None:
        exc_type = type(exc).__name__
        log_func("%s for %s", exc_type, self)
        log_func("exception set: %s", repr(exc))


_rpcrequest_init: Final = RPCRequest.__init__


@final
class eth_call(RPCRequest):
    revert_threads = PruningThreadPoolExecutor(4)

    __slots__ = "target", "calldata", "block"

    def __init__(
        self,
        controller: "DankMiddlewareController",
        params: Any,
        uid: str | None = None,
        fut: DebuggableFuture[RPCResponse] | None = None,
    ) -> None:
        """Adds a call to the DankMiddlewareContoller's `pending_eth_calls`."""

        call_dict, block = params

        self.target: ChecksumAddress = call_dict["to"]
        """The contract address for the call."""

        self.calldata: HexBytes = HexBytes(call_dict["data"])
        """The calldata for the call."""

        self.block: BlockId = block
        """The block height at which the contract will be called."""

        _rpcrequest_init(self, controller, "eth_call", params, uid, fut)

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

    @stuck_coro_debugger
    async def spoof_response(self, data: Union[bytes, Exception, RawResponse]) -> None:  # type: ignore
        """Sets and returns a spoof rpc response for this BatchedCall instance using data provided by the worker."""

        # NOTE: If `type(data)` is `bytes`, it is a result from a multicall. If not, `data` comes from a jsonrpc batch.
        # If this if clause is True, it means the call reverted inside of a multicall but returned a result, without causing the multicall to revert.
        if is_revert_bytes(data):
            # TODO figure out how to include method selector in no_multicall key
            try:
                # NOTE: If call response from multicall indicates failure, make sync call to get either:
                # - successful response
                # - revert details from exception
                # If we get a successful response, most likely the target contract does not support multicall2.
                # TODO: Get rid of the sync executor and just use `make_request`
                controller = self.controller
                target = self.target
                failures = 0
                while failures < 5:
                    try:
                        data = await self.revert_threads.run(
                            controller.sync_w3.eth.call,
                            {"to": target, "data": self.calldata},
                            self.block,
                        )
                    except ReadTimeout:
                        failures += 1
                    else:
                        break
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
    calls: Final[WeakList[_Request]]
    _done: Final[_RequestEvent]

    _awaited: bool = False
    """A flag indicating whether the batch has been awaited."""

    __slots__ = "calls", "_batcher", "_lock", "_done", "_daemon", "__dict__"

    def __init__(self, controller: "DankMiddlewareController", calls: Iterable[_Request]) -> None:
        _request_base_init(self, controller)
        self.calls = WeakList(calls)
        self._batcher = controller.batcher
        self._lock = AlertingRLock(name=self.__class__.__name__)
        self._done = _RequestEvent(self)

    def __len__(self) -> int:
        return len(self.calls)

    def __await__(self) -> Generator[Any, None, _Response]:
        return self._task.__await__()

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

    @property
    def _task(self) -> Future[None]:
        """Shield the actual Task from cancellation if the caller is cancelled."""
        return shield(self.__task)

    @cached_property
    def __task(self) -> Task[None]:
        self._awaited = True
        task = create_task(
            self.get_response(), name=f"{type(self).__name__} {self.uid} get_response"
        )
        BATCH_TASKS.add(task)
        task.add_done_callback(batch_done_callback)
        return task

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
        elif "429" in str_e or isinstance(e, ChainstackRateLimitError):
            pass
        elif isinstance(e, BadResponse) and (
            needs_full_request_spec(e.response) or is_call_revert(e)
        ):
            pass
        elif all(err not in str_e for err in constants.TOO_MUCH_DATA_ERRS):
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


_batch_init: Final = _Batch.__init__


@final
class Multicall(_Batch[RPCResponse, eth_call]):
    method: Final = "eth_call"

    # NOTE: value comes from eth_utils.function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")
    fourbyte: Final = b"9\x95B\xe9"

    _awaited: bool
    """A flag indicating whether the Multicall has been awaited."""

    __slots__ = ("bid",)

    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: Iterable[eth_call] = [],
        bid: BatchId | None = None,
    ) -> None:
        # sourcery skip: default-mutable-arg
        _batch_init(self, controller, calls)
        self.bid: Final = bid or self.controller.multicall_uid.next

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
        """Return True if the multicall contains at least one active request, False if complete."""
        return any(self.calls)

    def __del__(self) -> None:
        """Log an error if any call in this multicall is not complete when the multicall is deleted."""
        calls = list(self.calls)
        if not calls or self._done.is_set():
            return

        # The Multicall still has calls that haven't been garbage collected
        loop_is_closed = None
        logged = False
        for call in calls:
            if not call._fut.done():
                if loop_is_closed is None:
                    loop_is_closed = call._fut._loop.is_closed()

                if loop_is_closed:
                    return

                if logged is False:
                    error_logger.error("%s was garbage collected before finishing", self)
                    logged = True

                try:
                    call._fut.set_exception(
                        GarbageCollectionError(
                            f"{self} was garbage collected before finishing.",
                            f"{call} might hang indefinitely if I don't raise this exception, "
                            "which only exists to help debug an issue inside of dank mids. "
                            "Please show it to Bob.",
                        )
                    )
                except RuntimeError as e:
                    if str(e) != "no running event loop":
                        raise

    @cached_property
    def block(self) -> BlockId:
        try:
            return next(iter(self.calls)).block
        except StopIteration as e:
            raise EmptyBatch(
                f"{type(self).__name__} {self.uid} is empty and should not be processed."
            ) from e.__cause__

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
                    controller.pending_eth_calls.pop(self.block, None)

    @stuck_coro_debugger
    async def get_response(self) -> None:  # type: ignore [override]
        # create a strong ref to all calls we will execute so they cant get gced mid execution and mess up response ordering
        calls = tuple(self.calls)

        if not calls:
            # TODO: figure out how we get into this function without any calls
            self._done.set()
            return

        elif len(calls) == 1:
            await self._exec_single_call()
            self._done.set()
            return

        # elif l < 50: # TODO play with later
        #    return await JSONRPCBatch(self.controller, self.calls)

        controller = self.controller
        rid = controller.request_uid.next
        _demo_logger_info("request %s for multicall %s starting", rid, self.bid)
        try:
            await self.spoof_response(
                await controller.make_request(self.method, self.params, request_id=self.uid),
                calls,
            )
        except internal_err_types.__args__ as e:  # type: ignore [attr-defined]
            stre = str(e)
            if "invalid argument" in stre:
                raise
            elif "iteration" in stre:
                error_logger.error("ERROR: stop iteration in dank mids:")
                error_logger.exception(e)
            raise DankMidsInternalError(e) from e
        except Exception as e:
            if isinstance(e, ClientResponseError) and e.message == "Payload Too Large":
                _log_info("Payload too large. response headers: %s", e.headers)
                controller.reduce_multicall_size(len(self))
                self._record_failure(e, self.request.data.decode())
            elif _log_exception(e):
                self._record_failure(e, self.request.data.decode())

            if len(calls) == 1:
                await self._exec_single_call()
                self._done.set()
            elif self.should_retry(e):
                await self.bisect_and_retry(e)
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
    @stuck_coro_debugger
    async def spoof_response(
        self, data: RawResponse | Exception, calls: Sequence[eth_call] | None = None
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
                if is_revert_bytes(result):
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
    @stuck_coro_debugger
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
        bisected = (batch0, batch1) = [
            Multicall(controller, chunk, f"{self.bid}_{i}") for i, chunk in enumerate(self.bisected)
        ]
        if controller.pending_rpc_calls:
            controller.pending_rpc_calls.append(batch0)
            if batch1:
                if controller.pending_rpc_calls:
                    controller.pending_rpc_calls.append(batch1)
                else:
                    await batch1
            await controller.pending_rpc_calls._done.wait()
        elif batch1:
            batch = JSONRPCBatch(controller, bisected, f"{self.uid}_bisected")
            batch.start(self, cleanup=False)
            await batch
        elif batch0:
            batch0.start(self, cleanup=False)
            await batch0

    async def _exec_single_call(self) -> None:
        await next(iter(self.calls)).make_request()

    async def _spoof_or_retry(self, response: RawResponse) -> None:
        try:
            await self.spoof_response(response)
        except Exception as e:
            if not self.should_retry(e):
                raise
            await self.bisect_and_retry(e)


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
        jid: BatchId | None = None,
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
        """Return True if the batch contains at least one active request, False if complete."""
        return any(self.calls)

    def __del__(self) -> None:
        """Log an error if any call in this batch is not complete when the batch is deleted."""
        if self and not self._done.is_set():
            for cls, calls in groupby(self.calls, type):
                if cls is Multicall:
                    calls = concat(filter(None, calls))
                if any(filterfalse(Future.done, (call._fut for call in calls))):
                    error_logger.error("%s was garbage collected before finishing", self)
                    return

    @property
    def data(self) -> bytes:
        try:
            return b"[" + b",".join(call.request.data for call in self) + b"]"
        except TypeError as e0:
            # If we can't encode one of the calls, lets figure out which one and pass some useful info downstream
            for call in self:
                try:
                    call.request.data
                except TypeError as e1:
                    raise TypeError(e1, call.request) from e0.__cause__
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
                        call.start(batch, cleanup=False)
                else:
                    for call in calls:
                        call._batch = self
            if cleanup:
                self.controller._start_new_batch()

    @stuck_coro_debugger
    async def get_response(self) -> None:  # type: ignore [override]
        if not self.calls:
            # TODO: figure out why this can happen and prevent it upstream
            self._done.set()
            return

        if self.is_single_multicall:
            multicall = next(iter(self.calls))
            await multicall
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
                except ChainstackRateLimitError as e:
                    # Chainstack doesn't use 429 for rate limiting, it sends a successful response back to the rpc with an error
                    # message so our usual rate-limiting handlers don't work and we need to handle that case with bespoke logic.
                    await sleep(e.try_again_in)
                except RateLimitError:
                    # Quiknode doesn't use 429 for rate limiting, it sends a successful response back to the rpc with an error
                    # message so our usual rate-limiting handlers don't work and we need to handle that case with bespoke logic.
                    logger.warning("rate limited by quiknode")
                    await sleep(5)

        # I want to see these asap when working on the lib.
        except internal_err_types.__args__ as e:  # type: ignore [attr-defined]
            raise e if "invalid argument" in str(e) else DankMidsInternalError(e) from e
        except EmptyBatch:
            self._done.set()
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

    @stuck_coro_debugger
    @eth_retry.auto_retry(min_sleep_time=0, max_sleep_time=1, suppress_logs=2)
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
            if not calls:
                # TODO: figure out why this can happen and prevent it elsewhere
                return [], []

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
    @stuck_coro_debugger
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
            try:
                calls = sorted(calls, key=lambda call: call.uid)  # type: ignore [assignment]
            except TypeError:
                # '<' not supported between instances of 'int' and 'str'
                # This happens when a multicall or jsonrpc batch was split in half.
                # Those bisected batches have a string uid to associate them with
                # the original.
                calls = sorted(calls, key=lambda call: str(call.uid))

        if controller._sort_response:
            try:
                response.sort(key=lambda raw: raw.decode().id)
            except TypeError:
                # '<' not supported between instances of 'int' and 'str'
                # This happens when a multicall or jsonrpc batch was split in half.
                # Those bisected batches have a string uid to associate them with
                # the original.
                response.sort(key=lambda raw: str(raw.decode().id))
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
    @stuck_coro_debugger
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
            batch_size.log_check("multicall", "calls", num_calls)
            self.controller.reduce_multicall_size(num_calls)
        else:
            batch_size.log_check("json", "requests", len(self))
            self.controller.reduce_batch_size(len(self))
            _log_devhint(
                "We still need some better logic for catching these errors and using them to better optimize the batching process"
            )


# NOTE: These errors are expected during normal use and are not indicative of any problem(s). No need to log them.
_DONT_NEED_TO_SEE_ERRS = [
    "non_empty_data",
    "exceeding --rpc.returndata.limit",
    "'code': 429",
]


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

    # TODO: Better filter what we choose to log here

    dont_need_to_see_errs = [
        *_DONT_NEED_TO_SEE_ERRS,
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


_log_debug: Final = logger.debug
_log_info: Final = logger.info
_log_warning: Final = logger.warning
_logger_is_enabled_for: Final = logger.isEnabledFor
_log_devhint: Final = stats.logger.devhint
_demo_logger_info: Final = demo_logger.info
