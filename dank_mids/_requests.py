from asyncio import (
    Future,
    Task,
    TimeoutError,
    as_completed,
    create_task,
    current_task,
    get_running_loop,
    sleep,
    wait,
    wait_for,
)
from collections import defaultdict
from collections.abc import Callable, Coroutine, Generator, Iterable, Iterator, Sequence
from itertools import chain, filterfalse, groupby
from typing import TYPE_CHECKING, Any, DefaultDict, Final, Generic, Optional, TypeVar, Union, final
from weakref import ProxyType
from weakref import proxy as weak_proxy

import a_sync
import eth_retry
from a_sync import PruningThreadPoolExecutor, igather
from a_sync.asyncio import sleep0 as yield_to_loop
from a_sync.debugging import stuck_coro_debugger
from a_sync.functools import cached_property_unsafe as cached_property
from aiohttp.client_exceptions import ClientResponseError
from eth_typing import ChecksumAddress
from eth_utils.toolz import concat
from faster_hexbytes import HexBytes
from requests.exceptions import ReadTimeout
from web3.exceptions import ContractLogicError
from web3.types import RPCEndpoint
from web3.types import RPCError as _RPCError
from web3.types import RPCResponse

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids import _debugging, constants, stats
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import (
    BadResponse,
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
from dank_mids._nocompile import try_for_result, try_for_result_quick
from dank_mids._tasks import (
    BATCH_TASKS,
    TIMEOUT_SECONDS_BIG,
    TIMEOUT_SECONDS_SMALL,
    create_batch_task,
    shield,
)
from dank_mids.exceptions import GarbageCollectionError
from dank_mids.helpers import DebuggableFuture, _codec, batch_size, gatherish
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
    format_with_errors,
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
from dank_mids.helpers._multicall import MulticallContract
from dank_mids.helpers._rate_limit import rate_limit_inactive
from dank_mids.helpers._requester import _requester
from dank_mids.helpers._weaklist import WeakList
from dank_mids.helpers.method import get_len as get_len_for_method
from dank_mids.helpers.method import should_batch as should_batch_method
from dank_mids.lock import AlertingRLock, Lock
from dank_mids.logging import DEBUG, get_c_logger
from dank_mids.types import BatchId, BlockId, JsonrpcParams, PartialRequest, Request, Response

if TYPE_CHECKING:
    from dank_mids._batch import DankBatch
    from dank_mids.controller import DankMiddlewareController


EXECUTION_LOCK: Final = Lock()

logger: Final = get_c_logger(__name__)

_Response = TypeVar(
    "_Response", Response, list[Response], RPCResponse, list[RPCResponse], RawResponse
)


@final
class RPCError(_RPCError, total=False):
    dankmids_added_context: dict[str, Any]


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
    __dict__: Final[dict[str, Any]]

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
    def request(self) -> Request | PartialRequest:
        return self.controller.request_type(method=self.method, params=self.params, id=self.uid)

    @stuck_coro_debugger
    async def get_response(self) -> RPCResponse:  # type: ignore [override]
        if not self.should_batch:
            if self._debug_logs_enabled:
                _log_debug("bypassed dank batching, method is %s", self.method)
            return await self.get_response_unbatched()

        # We do some janky stuff here to make the event loop run a few times
        # so we can collect as many requests as possible into our batch
        async with EXECUTION_LOCK:
            fut = self._fut
            if self._batch is None:
                # We want to pause here to let the event loop start any batches that have been queued up
                # We don't want to start tiny batches or start the same batch more than 1x, that's waste
                await yield_to_loop()

        current_batch = self._batch
        if current_batch is None:
            # NOTE: We want to force the event loop to make one full _run_once call before we execute.
            await yield_to_loop()

        elif current_batch._awaited is False:
            # NOTE: If current_batch is not None, that means we filled a batch. Let's await it now so we can send something to the node.
            await wait((current_batch._task, fut), return_when="FIRST_COMPLETED")

        controller = self.controller
        if self._batch is None and (controller.pending_eth_calls or controller.pending_rpc_calls):
            # self._batch used to be set earlier but now we need to check the controller because the batch might have been initialized but not started
            batch_coro = controller.execute_batch()
            batch_task = create_batch_task(batch_coro, name="batch task execute_batch")

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
                await rate_limit_inactive(controller.endpoint)
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
                    await rate_limit_inactive(controller.endpoint)

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
            return format_with_errors(response, self.method, raw_mode=self.raw)

        if needs_full_request_spec(response) and controller._check_request_type():
            method = RPCEndpoint(f"{self.method}_raw") if self.raw else self.method
            return await controller(method, self.params)
        elif revert_logger.isEnabledFor(DEBUG) and type(response.exception) is ExecutionReverted:
            revert_logger_log_debug("%s for %s", response.exception, self)
        elif error_logger.isEnabledFor(DEBUG) and type(response.exception) is not ExecutionReverted:
            error_logger_log_debug("%s for %s", response.error, self)

        return format_with_errors(response, self.method, raw_mode=self.raw, request=self.request)

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
        return format_with_errors(decoded, self.method, raw_mode=self.raw)

    async def spoof_response(self, data: RawResponse | bytes | Exception) -> None:
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
        except ClientResponseError as e:
            if e.status != 408:  # request timeout
                raise
            log_func = timeout_logger_warning if num_previous_timeouts > 1 else timeout_logger_debug
            log_func(
                "`make_request` server timeout (code 408) %s times for %s, trying again...",
                num_previous_timeouts + 1,
                self,
            )
            return await self.make_request(num_previous_timeouts + 1)
        except TimeoutError:
            log_func = timeout_logger_warning if num_previous_timeouts > 1 else timeout_logger_debug
            log_func(
                "`make_request` timed out in dank_mids (%ss) %s times for %s, trying again...",
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
            return eth_call(self.controller, self.params, dupe_uid, self._fut)
        method = RPCEndpoint(f"{self.method}_raw") if self.raw else self.method
        return RPCRequest(self.controller, method, self.params, dupe_uid, self._fut)

    def __set_exception(self, data: Exception) -> None:
        if revert_logger.isEnabledFor(DEBUG) and type(data) in _REVERT_EXC_TYPES:
            self.__log_set_exception(revert_logger_log_debug, data)
        elif error_logger.isEnabledFor(DEBUG) and type(data) not in _REVERT_EXC_TYPES:
            self.__log_set_exception(error_logger_log_debug, data)
        self._fut.set_exception(data)

    def __log_set_exception(self, log_func: Callable, data: Exception) -> None:
        try:
            log_func("RPC Request %s had exception %s", self, data)
        except (IndexError, KeyError, AttributeError):
            _log_warning("%s had exception %s", self, data)

    def _record_failure(self, e: Exception, payload: str | bytes | None = None) -> None:
        # NOTE: include -wd/--write-failures to log failures to csv file
        # NOTE: include -lv/--log-failures to print failures in logger
        _debugging.failures.record(self, e, payload)

    async def _debug_daemon(self) -> None:
        while True:
            await sleep(1)
            if self._batch is None:
                _log_debug("%s is pending, batch not initialized", self)
            elif not self._batch._awaited:
                _log_debug("%s is pending, batch still queued", self)
            elif not self._fut.done():
                _log_debug("%s is pending, batch got stuck", self)
            else:
                _log_debug("%s is complete", self)
                return


# NOTE: `BetterDict` is a generalization of a lot of the fiddling that will occur in this file
#       to ensure stuff like values are not type hinted as Any. If you need help understanding
#       just reach out to Bob
class BetterDict(dict):
    _fut: Final[DebuggableFuture]


### Multicalls:

# we put all the multicall functionality for eth_call in a subclass for ease of use
class eth_call(RPCRequest):
    def __len__(self) -> int:
        return len(self.calls)

    __slots__ = "calls", "block", "multicall_compatible", "__dict__"

    def __init__(
        self,
        controller: "DankMiddlewareController",
        params: JsonrpcParams,
        uid: str | None = None,
        fut: DebuggableFuture[RPCResponse] | None = None,
    ) -> None:
        super().__init__(controller, RPCEndpoint("eth_call"), params, uid, fut)
        try:
            # this is in try-except because any issues will resolve when it is actually called
            params[0]["data"] = HexBytes(params[0]["data"])  # type: ignore [union-attr]
        except (TypeError, KeyError):
            self.multicall_compatible = False
        else:
            self.multicall_compatible = True

        # do not actually send these to the rpc, use multicall2 contract instead
        if self.multicall_compatible:
            _demo_logger_info("moved call to multicall queue (cid: %s)", self.uid)
            self.controller.pending_eth_calls[self.block].append(self)
            # a second call was already added for this call so we can delete the first
            self.controller.pending_rpc_calls.pop()

        elif self.controller._check_request_type():
            # if multicall not compatible, remove from queue and retry as raw
            method = RPCEndpoint(f"{self.method}_raw") if self.raw else self.method
            self.controller.pending_rpc_calls.pop()
            self._fut.set_result(await RPCRequest(self.controller, method, self.params, self.uid))

    @property
    def request(self) -> PartialRequest:
        # NOTE: to bypass the validation for `data` arg of `PartialRequest`
        return PartialRequest(method=self.method, params=self.params, id=self.uid)  # type: ignore [call-arg]

    async def spoof_response(self, data: RawResponse | bytes | Exception) -> None:
        # sourcery skip: merge-duplicate-blocks
        """
        `Raw` type data comes from rpc calls executed in a jsonrpc batch
        `bytes` type data comes for individual eth_calls that were batched into multicalls and already decoded
        `Exception` type data comes from failed calls
        """

        if isinstance(data, RawResponse):
            # NOTE: for eth_call responses, this will be PartialResponse or types.Response
            data = data.decode(partial=True)
            if data.error is not None:
                exception = data.exception
                # NOTE: if we do have data then we need to reset data back to bytes or its wont format correctly
                raw_data = data.result if data.result is not None else None
                # Now we can set exception on the future. We don't need to format it later.
                self.__set_exception(exception, raw_data)
            else:
                self._fut.set_result({"result": data.result})  # type: ignore [union-attr]
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

    def __set_exception(self, exc: Exception, data: bytes | None = None) -> None:
        if is_call_revert(exc) and data is not None:
            self._fut.set_exception(
                revert_for(exc, data)
                if revert_logger.isEnabledFor(DEBUG)
                else ExecutionReverted(data)
            )
            return
        if error_logger.isEnabledFor(DEBUG) and type(exc) not in _REVERT_EXC_TYPES:
            self.__log_set_exception(exc, data)
        self._fut.set_exception(exc)

    def __log_set_exception(self, exc: Exception, data: bytes | None = None) -> None:
        try:
            log_internal_error(error_logger, self, exc, data)
        except (IndexError, KeyError, AttributeError):
            _log_warning("%s had exception %s", self, exc)

    def create_duplicate(self) -> "eth_call":
        # NOTE: we always use this method for multicalls, never use the inherited one.
        return eth_call(self.controller, self.params, f"{self.uid}_copy", self._fut)

    @cached_property
    def block(self) -> int:
        block = self.params[1]
        if block == "latest":
            return self.controller.latest_block
        if block == "pending":
            return self.controller.pending_block
        return self.controller._get_block_by_id(block)  # type: ignore [return-value]


class Multicall(RPCRequest):
    """This multicall class batches calls into a single multicall for internal use."""

    should_batch: bool = False
    """Multicalls should not be batched into jsonrpc. They are already batches!"""

    __slots__ = "calls"

    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: MulticallChunk | Iterable[MulticallChunk],
        uid: str | None = None,
        fut: DebuggableFuture[RPCResponse] | None = None,
    ) -> None:
        super().__init__(controller, RPCEndpoint("eth_call"), calls, uid, fut)
        if isinstance(calls, (list, tuple)) and isinstance(calls[0], (list, tuple)):
            self.calls = calls
        else:
            self.calls = [calls]
        self._fut._done_callbacks.clear()  # type: ignore [attr-defined]

    def __len__(self) -> int:
        if self._fut.done():
            return 0
        return len(self.calls)

    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} len={len(self)} complete={self._fut.done()}>"

    def __iter__(self) -> Iterator[MulticallChunk]:
        if self._fut.done():
            # no need to keep this strong ref to calls once done
            self._fut.mcall_calls = None  # type: ignore [attr-defined]
            return iter([])
        return iter(self.calls)

    @property
    def request(self) -> PartialRequest:
        if len(self) == 1:
            # NOTE: to bypass the validation for `data` arg of `PartialRequest`
            return PartialRequest(method=self.method, params=self.params, id=self.uid)  # type: ignore [call-arg]
        return PartialRequest(method=self.method, params=(self.params,), id=self.uid)  # type: ignore [call-arg]

    def create_duplicate(self) -> "Multicall":
        # NOTE: the duplicate should share the same _fut to avoid double processing
        return Multicall(self.controller, self.calls, f"{self.uid}_copy", self._fut)

    def start(self, batch: Optional["DankBatch"] = None, cleanup=True) -> None:
        if self._fut.done():
            return
        self._batch = batch
        if cleanup:
            self.controller._start_new_batch()

    async def get_response_unbatched(self, response: RawResponse | None = None):
        # NOTE: using an updated count of blocks between current block and latest block for repr
        _demo_logger_info("making multicall with %s calls", len(self))
        call_list = tuple(self)
        if not call_list:
            return

        if response is None:
            response = await self.make_request()

        # If response is an exception, and any call is not done, then throw it.
        # All batches or multicalls should have a result or exception by now
        if isinstance(response, Exception):
            for call in call_list:
                if call._fut.done():
                    # We don't want to overwrite any responses
                    continue
                # NOTE: this exception will be raised in the calling thread, which might
                # not be an async thread. This is fine.
                call._fut.set_exception(response)
        else:
            decoded = response.decode(partial=True)
            await self._spoof_or_retry(self, decoded)

    @staticmethod
    async def _spoof_or_retry(call: "Multicall", response: RawResponse | Response) -> None:
        if isinstance(response, RawResponse):
            response = response.decode(partial=True)
        if response.error is None:
            try:
                # the first item in decode is a boolean
                _, _, results = mcall_decode(response.result)
            except ValueError as e:
                data = response.result
                decoded = decode_revert_bytes(data) if is_revert_bytes(data) else data
                raise ExecutionReverted(decoded) from e
            for mcall, result in zip(call, results):
                if result[0]:
                    # don't decode now, let it happen when the result is awaited
                    await mcall.spoof_response(result[1])
                else:
                    await mcall.spoof_response(ExecutionReverted(result[1]))
        else:
            # Probably not something we can fix by retrying
            error_logger.error("Multicall failed. %s", response.error, exc_info=True)
            # this error will be handled in _RequestBase.get_response
            call._fut.set_result(response)


### Jsonrpc batches:


class _Batch(_RequestBase[RPCResponse]):
    _done: Final[_RequestEvent]
    _lock: Final[AlertingRLock]

    __slots__ = "_lock", "_done", "_daemon"

    def __init__(self, controller: "DankMiddlewareController") -> None:
        _request_base_init(self, controller)
        self._lock = AlertingRLock(name=self.__class__.__name__)
        self._done = _RequestEvent(self)
        self._daemon: Final = None

    def __bool__(self) -> bool:
        return not self._done.is_set()

    def __len__(self) -> int:
        raise NotImplementedError

    def __iter__(self) -> Iterator[RPCRequest]:
        raise NotImplementedError

    def __del__(self) -> None:
        if self and not self._done.is_set():
            self._log_done_callback()

    @cached_property
    def _batcher(self) -> PruningThreadPoolExecutor:
        return self.controller._batcher

    @cached_property
    def _awaited(self) -> bool:
        return self._done.is_set()

    @property
    def jid(self) -> BatchId:
        return self.uid

    @property
    def response(self) -> RPCResponse:
        return self._fut

    @property
    def calls(self) -> WeakList[Multicall | RPCRequest]:
        raise NotImplementedError

    @property
    def bisected(self) -> list[list[RPCRequest] | list[Multicall]]:
        _log_debug("bisecting %s", self)
        with self._lock:
            calls = list(self)
            if self.is_multicalls_only:
                return [list(filter(None, calls))]

            if self.is_single_multicall:
                return [calls]

            to_sort = list(self.calls)

        len_calls = len(calls)
        half = int(len_calls / 2)
        if half < 1:
            return [calls]

        first_half = calls[:half]
        second_half = calls[half:]

        return [first_half, second_half]

    def _record_failure(self, e: Exception, payload: str | bytes | None = None) -> None:
        # NOTE: include -wd/--write-failures to log failures to csv file
        # NOTE: include -lv/--log-failures to print failures in logger
        _debugging.failures.record(self, e, payload)

    def _log_done_callback(self) -> None:
        self._done.set()

    def should_retry(self, e: Exception) -> bool:
        # While it might look weird, f-string is faster than `str(e)`.
        str_e = f"{e}"
        if any(err in str_e for err in constants.RETRY_ERRS):
            return True
        elif any(map("invalid length".lower().__contains__, constants.RETRY_ERRS)):
            # If this response is multicalled, maybe we can fix it by using smaller multicalls.
            if self.is_multicalls_only:
                self.controller.reduce_multicall_size(len(self))
                return True
            # NOTE: This is happening when using trace filter and geth. Not sure if it is a geth bug.
            elif all(err not in str_e for err in constants.TOO_MUCH_DATA_ERRS):
                return True
        elif any(map(f"{e}".lower().__contains__, constants.RETRY_ERRS)):
            return True
        elif len(self) > 1:
            return True
        return False


class JSONRPCBatch(_Batch):
    """
    A batch of JSON-RPC requests.

    This class manages a collection of JSON-RPC requests that will be sent
    as a single batch to an Ethereum node, improving efficiency by reducing
    the number of separate network calls.
    """

    __slots__ = ("jid",)

    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: Iterable[Multicall | RPCRequest] = [],
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

    def __iter__(self) -> Iterator[Multicall | eth_call | RPCRequest]:
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
    def method_counts(self) -> dict[RPCEndpoint, int]:
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
            debug_daemon = create_task(self._debug_daemon(), name="JSONRPCBatch debug daemon")
            self._daemon = debug_daemon
            waiter = current_task()
            if waiter is not None:
                waiter.add_done_callback(lambda: debug_daemon.cancel("JSONRPCBatch complete"))
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
    async def post(self) -> tuple[list[RawResponse], list[Multicall | RPCRequest]]:
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
            data = self.data
            if data == b"[]":
                # Avoid sending an empty JSON-RPC batch payload.
                return [], []
            post_coro = _requester.post(
                self.controller.endpoint, data=data, loads=_codec.decode_jsonrpc_batch
            )
            task = create_task(post_coro, name=f"JSONRPCBatch-{self.uid}")
            response: JSONRPCBatchResponse = await wait_for(shield(task), timeout=30)
        except TimeoutError:
            timeout_logger_warning("JSONRPCBatch.post timed out (30s). Retrying.")
            data = self.data
            if data == b"[]":
                # Avoid sending an empty JSON-RPC batch payload.
                return [], []
            new_post_coro = _requester.post(
                self.controller.endpoint, data=data, loads=_codec.decode_jsonrpc_batch
            )
            for fut in as_completed([task, new_post_coro]):
                return await fut, calls
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

    async def _spoof_response_by_id(
        self, response: list[RawResponse], calls: tuple[RPCRequest, ...]
    ) -> list[Coroutine[Any, Any, None]]:
        call_by_id = {str(call.uid): call for call in calls}
        mcall_coros = []
        for raw in response:
            key = str(raw.decode().id)
            call = call_by_id.pop(key, None)
            if call is None or not call:
                continue
            if isinstance(call, Multicall):
                mcall_coros.append(Multicall._spoof_or_retry(call, raw))
            else:
                # These do not need to be delegated to tasks since they
                # will always complete synchronously when called here
                await call.spoof_response(raw)
        return mcall_coros

    @set_done
    @stuck_coro_debugger
    async def spoof_response(
        self, response: list[RawResponse], calls: tuple[RPCRequest, ...]
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

        mcall_coros = await self._spoof_response_by_id(response, calls)

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
