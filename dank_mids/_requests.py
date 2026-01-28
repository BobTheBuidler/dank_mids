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

    def __log_set_exception(self, log_func: Callable[[str, Any], None], data: Exception) -> None:
        log_func("setting exception on %s", self)
        log_func(repr(data))

    @classmethod
    async def _spoof_or_retry(cls, request: "RPCRequest", raw: RawResponse | Exception) -> None:
        try:
            if isinstance(raw, Exception):
                raise raw
            await request.spoof_response(raw)
        except Exception as e:
            request._fut.set_exception(e)


class eth_call(RPCRequest):
    should_batch = True
    multicall_compatible = True

    __slots__ = "block", "_do_multicall"

    def __init__(
        self,
        controller: "DankMiddlewareController",
        call: JsonrpcParams,
        block: BlockId,
        uid: str | None = None,
        fut: DebuggableFuture[RPCResponse] | None = None,
    ) -> None:
        super().__init__(controller, "eth_call", [call, block], uid, fut)
        self.block = block
        self._do_multicall = True

    def __len__(self) -> int:
        # NOTE: We dont need to consider response size for each method for very small batch sizes since the requests/responses will never get too large
        return 1 if self._tiny_batches else get_len_for_method(self.method)

    async def get_response_unbatched(self) -> RPCResponse:
        return await self.controller.make_request(self.method, self.params, request_id=self.uid)


class Multicall(eth_call):
    should_batch = True
    multicall_compatible = True

    __slots__ = "calls", "mcall_executor", "_decoder", "_multicall_prepared", "_size_msx", "_reverted",

    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: Iterable[PartialRequest],
        uid: str | None = None,
    ) -> None:
        # NOTE: dont forget that multicalls can be used manually as well
        # TODO: Migrate to a better api for users.
        super().__init__(controller, None, None, uid)  # type: ignore [arg-type]
        if controller.

...