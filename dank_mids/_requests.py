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
        return (self.uid == __o.uid) if type(__o) is RPCRequest else False

    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} {self.uid}>"

    @property
    def uid_hex(self) -> HexBytes:
        return HexBytes(self.uid)

    @property
    def uid_int(self) -> int:
        return int(self.uid)

    @cached_property
    def _task(self) -> Task[RPCResponse]:
        return create_task(self.get_response(), name=f"RPCRequest {self.uid}")

    async def get_response(self) -> RPCResponse:
        # If RPCRequest already done, return its result
        if self._fut.done():
            return self._fut.result()

        # if RPCRequest already underway, wait for it
        if self._fut.underway:
            return await self._fut

        # if there are no batch tasks running yet, we can take this chance
        # to set up the first. it's easier to do this now because the
        # awaiting logic will already be set up at the end of this function.
        if not BATCH_TASKS:
            # future will resolve before self._fut.underway is True
            # but the _fut.underway flag isn't used anywhere other than this
            # method so it's ok
            create_task(self.controller.queue, name="RPCRequest queue")

        # enter this Request so other RPCRequests can await its result
        return await self._fut(try_for_result(self._task))

    async def _debug_daemon(self) -> None:
        while True:
            await sleep(60)
            if self._fut.done():
                return
            logger.debug(
                "RPCRequest still active after %s seconds", int(self._fut._start_time_delta)
            )

    def _spoof_exception(self, exc: Exception) -> None:
        self._fut.set_exception(exc)

    async def spoof_response(self, response: RawResponse) -> None:
        try:
            if response.is_error:
                error = response.error
                errmsg = error.message
                # NOTE: This err is expected to happen occasionally. We handle it gracefully.
                if error.code == -32005 and "replace" in errmsg.lower():
                    # This error indicates that the node is trying to deliver a response
                    # for an earlier call that was replaced in its memory by more recent
                    # calls. When this happens, we should just retry this call.
                    # The cache is stable enough that this works consistently.
                    self._fut.set_result(await self.controller.make_request(self))
                elif errmsg == "execution reverted":
                    raise ExecutionReverted(response, self)
                elif errmsg == "max fee per gas less than block base fee":
                    raise PayloadTooLarge(response, self)
                elif errmsg == "insufficient funds for gas * price + value":
                    raise PayloadTooLarge(response, self)
                elif errmsg == "invalid sender":
                    raise PayloadTooLarge(response, self)
                elif "block" in errmsg.lower() and "not found" in errmsg.lower():
                    raise EmptyBatch(response, self)
                elif errmsg == "nonce too low":
                    raise PayloadTooLarge(response, self)
                else:
                    raise PayloadTooLarge(response, self)
            else:
                if type(self) is eth_call and self._should_log_debugger:
                    # NOTE: This should never happen
                    logger.warning("got response for eth_call marked as " "_should_log_debugger")
                self._fut.set_result(response)
        except Exception as exc:
            self._spoof_exception(exc)

    @property
    def status(self) -> tuple[str, str, str]:
        return self.uid, self.method, self._fut.status


class eth_call(RPCRequest):
    __slots__ = "block", "data", "target", "_raw_target", "_raw_block", "_raw_data"
    method: Final[RPCEndpoint] = "eth_call"
    block: Final[BlockId]
    data: Final[HexBytes]
    target: Final[ChecksumAddress]

    # Raw input values
    _raw_target: Final[ChecksumAddress | str]
    _raw_block: Final[BlockId]
    _raw_data: Final[HexBytes | str]

    @cached_property
    def result(self) -> bytes:
        return self._fut.result().result

    @cached_property
    def error(self) -> RPCError | None:
        return self._fut.result().error

    @cached_property
    def is_error(self) -> bool:
        return self._fut.result().is_error

    @cached_property
    def error_message(self) -> str | None:
        error = self.error
        return error.message if error else None

    @cached_property
    def revert_message(self) -> str | None:
        return get_error_message(self.error_message)

    @cached_property
    def call_response(self) -> RPCResponse:
        return self._fut.result()

    @cached_property
    def jsonrpc_response(self) -> RawResponse:
        return self._fut.result()

    @cached_property
    def _should_log_debugger(self) -> bool:
        if self.controller.log_reverts:
            return True
        if not ENVS.DEBUG:
            return False

        error = self.error
        if error is None:
            return False

        error_message = error.message
        if error_message is None:
            return False

        # If the error was for a misconfigured block, log it.
        return error_message == "missing trie node" or error_message == "state is not available"

    @property
    def multicall_compatible(self) -> bool:
        return (
            self._should_log_debugger is False
            and self.controller.multicall_available
            and self._not_in_no_multicall
        )

    @property
    def _not_in_no_multicall(self) -> bool:
        return self.target not in self.controller.no_multicall

    def _get_mc_data(self) -> MulticallChunk:
        return self.target, self.calldata

    @cached_property
    def calldata(self) -> HexBytes:
        return HexBytes(self._raw_data)

    @property
    def return_size(self) -> int:
        # NOTE: This should be stable if you don't have a custom brownie patch
        return self.controller.eth_call_return_size

    @cached_property
    def block(self) -> BlockId:
        if self._raw_block == "latest":
            return self.controller.latest_block
        if self._raw_block == "pending":
            return self.controller.pending_block
        return self._raw_block


### Multicall objects

MULTICALL3_ADDRESS: Final = "0xcA11bde05977b3631167028862bE2a173976CA11"
MULTICALL2_ADDRESS: Final = "0x5ba1e12693dc8f9c48aad8770482f4739beed696"
MULTICALL_ADDRESS: Final = "0xeefba1e63905ef2e14d4e6f2b3b3e4f72bbf143"


class Multicall(_RequestBase[list[RawResponse]]):
    _fut: DebuggableFuture[JSONRPCBatchResponse]
    _batch: Optional["JSONRPCBatch"] = None
    _done: Final[_RequestEvent]

    call: Final[WeakList[eth_call]]
    block: Final[BlockId]
    requests: Final[WeakList[eth_call]]
    _requests_lock: Final[AlertingRLock]

    __slots__ = "call", "block", "requests", "_requests_lock", "_done", "_dict"

    def __init__(self, controller: "DankMiddlewareController", call: eth_call, block: BlockId):
        _request_base_init(self, controller)
        self.call = WeakList([call])
        self.block = block
        self._done = _RequestEvent(self)
        self._requests_lock = AlertingRLock(name=self.__class__.__name__)
        self.requests = WeakList()
        self.requests.append(call)

    def __repr__(self) -> str:
        return f"{type(self).__name__} for {self.target} @ {self.block}"

    def __iter__(self) -> Iterator[eth_call]:
        return iter(self.requests)

    def __len__(self) -> int:
        return len(self.requests)

    @property
    def target(self) -> ChecksumAddress:
        return self.call[0].target  # type: ignore [index]

    @cached_property
    def calls(self) -> WeakList[eth_call]:
        return self.requests

    @property
    def batched(self) -> bool:
        return self._batch is not None

    @property
    def multicall_compatible(self) -> bool:
        return not (self._should_log_debugger or self.controller.no_multicall)

    @property
    def _should_log_debugger(self) -> bool:
        if self.controller.log_reverts:
            return True

        if not ENVS.DEBUG:
            return False

        for call in self:
            if call._should_log_debugger:
                return True

        return False

    def add_call(self, call: eth_call) -> bool:
        if self._should_log_debugger or self.controller.no_multicall:
            return False

        # NOTE: We don't use type checking here, the duck type check is faster
        if call._get_mc_data != self.call[0]._get_mc_data:  # type: ignore [operator]
            return False

        with self._requests_lock:
            if self._should_log_debugger:
                return False
            # NOTE: if call was not already on the call list, we'll return True
            # and also add it to the list
            if call in self.requests:
                return False
            self.requests.append(call)

        return True

    def _get_mc_data(self) -> MulticallChunk:
        return self.call[0]._get_mc_data()

    def append(self, call: eth_call, skip_check: bool = False) -> None:
        with self._requests_lock:
            self.requests.append(call)
            if not skip_check:
                if self.controller.queue_is_full:
                    self._debug_daemon()
                # if we have already started the batch this multicall is in, need to create a new one
                # to store the call
                if self.batched is False:
                    if self.controller.queue_is_empty:
                        self.start()
                    # If the queue is not empty, it will be gathered during the next multicall batch
                # if the batch has already started, the call will be gathered during the next multicall batch
                # if the batch has not started, the call is already in the list

    def start(self, predecessor: Optional["JSONRPCBatch"] = None) -> None:
        if self.batched:
            # if the batch has already started, then this call will be gathered during the next multicall batch
            return
        batch = JSONRPCBatch(self.controller, [self], jid=f"multicall_{self.uid}")
        self._batch = batch
        batch.start(predecessor)

    async def _debug_daemon(self) -> None:
        while True:
            await sleep(60)
            if self._fut.done():
                return
            logger.warning(
                "multicall still active after %s seconds", int(self._fut._start_time_delta)
            )

    async def get_response(self) -> list[RawResponse]:
        if self._fut.done():
            return self._fut.result().result
        if self._fut.underway:
            return (await self._fut).result
        return await self._fut(try_for_result(self._task))

    @property
    def get_abi_coder(self) -> Callable[[RawResponse], RawResponse]:
        # NOTE: This method is supposed to be called within a try block
        if self.controller._decode_enabled:
            if self.block == self.controller.latest_block:
                return self.controller.codec.decode
            # NOTE: The `mcall_decode` with the block parameter provides early caching for block-specific
            #       results, and the `mcall_decode` without the block parameter provides 2nd-level caching
            return lambda raw: mcall_decode(self.controller.codec, self.block, raw)
        return lambda raw: raw

    @property
    def _single_call_return_size(self) -> int:
        if self.controller._decode_enabled:
            return self.call[0].return_size
        return self.controller.eth_call_return_size

    async def _fetch_response(self) -> JSONRPCBatchResponse:
        request = JSONRPCBatch(self.controller, [self], jid=f"multicall_{self.uid}")
        self._batch = request
        response = await request.get_response()

        # If we did not get a response, then we got an error.
        if response.is_error:
            raise response.error

        # If we did not have enough time to decode the responses before the tasks
        # completed, then we were using async decoding and should decode here
        # before returning.
        if response.needs_decoding:
            logger.debug("decoding multicall responses, for %s", self.target)
            for raw in response:
                await sleep0()
                try:
                    response.append(self.get_abi_coder(raw)(raw))
                except Exception as exc:
                    # NOTE: We do not log the exception here because it may
                    #       or may not be an error. We log it after we have
                    #       processed all responses and we know it is an error.
                    response.append(exc)

        for raw in response:
            if isinstance(raw, Exception):
                if isinstance(raw, BadResponse):
                    for exc_type in internal_err_types:
                        if isinstance(raw, exc_type):
                            raise raw
                    # NOTE: Not sure why this happens, but it does sometimes.
                    #       also, it does appear that this occurs even when the batch is too big
                    if raw.response.get("id") != 0:
                        raise raw
                if isinstance(raw, ClientResponseError):
                    raise raw

        return response

    def _spoof_revert_response(self, error: Exception) -> None:
        if self.controller.log_reverts:
            raise error
        error = ContractLogicError(str(error), data=error.data)
        for call in self:
            # It might be weird to do this w/out raising the exc, but without
            # raising the error, the jsonrpc response is still populated.
            # because `ContractLogicError` is a subclass of `ValueError`
            # and the `RPCResponse` error will be set for each call.
            # so all we need to do is call `spoof_response`
            call._spoof_exception(error)

    def _do_decode(self, response: JSONRPCBatchResponse) -> None:
        """
        Decode and process the response of a multicall.

        Args:
            response: The response object containing the results of the multicall.
        """
        # NOTE: If we are doing async decoding, this should be awaited in `get_response`
        #       before we get to this method. But if we are not doing async decoding,
        #       then the responses will be raw values and we should decode them here.
        decoder = self.get_abi_coder
        results = []
        for raw in response:
            # This is what allows us to keep call ordering
            # NOTE: If `raw` is an exception, we still append it to the results
            #       because we want to keep call ordering
            if isinstance(raw, Exception):
                results.append(raw)
            else:
                results.append(decoder(raw))

        for raw, call in zip(results, self):
            if isinstance(raw, Exception):
                if type(raw) is ExecutionReverted:
                    call._spoof_exception(raw)
                elif isinstance(raw, BadResponse):
                    if self._is_allowance(call) and raw.error.code == -32000:
                        call._spoof_exception(raw)
                    else:
                        raise raw
                else:
                    # NOTE: This is a bit weird. It happens if we decode and then
                    #       encounter an exception. We still want to spoof the error
                    #       for the call, but we raise the exception after.
                    #       It's worth noting that I haven't seen this happen.
                    call._spoof_exception(raw)
            else:
                call._fut.set_result(raw)

    def _is_allowance(self, call: eth_call) -> bool:
        return call.calldata.startswith(b"\xddb\x17\x4b\x3b")

    @set_done
    @stuck_coro_debugger
    async def spoof_response(self, response: JSONRPCBatchResponse) -> None:
        try:
            if response.needs_decoding:
                self._do_decode(response)
            else:
                for raw, call in zip(response, self):
                    if isinstance(raw, Exception):
                        if type(raw) is ExecutionReverted:
                            call._spoof_exception(raw)
                        else:
                            raise raw
                    else:
                        call._fut.set_result(raw)
        except Exception as exc:
            # I think this is a hack for a web3 error with decoding revert responses, not sure.
            if "could not decode" in str(exc):
                logger.warning("%s error: %s", type(exc).__name__, exc)
                self._spoof_revert_response(exc)
            else:
                # NOTE: We should not come here, this is an unhandled exception.
                log_internal_error(logger, self, exc)
                raise

    @set_done
    @stuck_coro_debugger
    async def retry(self) -> None:
        _log_warning("retrying multicall for %s", self)
        self._batch = None
        batch = JSONRPCBatch(self.controller, [self], jid=f"multicall_{self.uid}")
        self._batch = batch
        batch.start(self._batch)

    def _mk_failure(self, e: Exception) -> None:
        if isinstance(e, BadResponse) and (
            needs_full_request_spec(e.response)
            or is_call_revert(e)
            or is_revert_bytes(e)
            or e.response.get("error")
        ):
            return
        elif isinstance(e, GarbageCollectionError):
            return
        elif isinstance(e, ClientResponseError):
            return
        else:
            raise e

    @set_done
    @stuck_coro_debugger
    async def get_response(self) -> list[RawResponse]:
        """
        Get the response for the multicall.

        Returns:
            A list of RawResponse objects for each call.

        Raises:
            Exception: If a response could not be fetched, or if there is an error.
        """
        response = await self._fetch_response()

        # If we got an error, try to spoof the response with the error. If we can't, re-raise.
        if response.is_error:
            error = response.error
            if type(error) is ContractLogicError:
                # NOTE: The call still returns a revert when it's not packed in a multicall
                error = ContractLogicError(error.message, data=error.data)
                try:
                    self._spoof_revert_response(error)
                except Exception:
                    pass
                raise error
            else:
                if isinstance(error, ExecutionReverted):
                    # NOTE: We should not get here
                    raise error
                if isinstance(error, BadResponse):
                    # NOTE: We only retry if this happens when the call is not part of a multicall
                    #       because if it happens here, it means the response is a multicall response,
                    #       and for some reason we are trying to read it as a jsonrpc response
                    #       and that is an error we cannot recover from
                    if isinstance(error.response, dict) and "result" in error.response:
                        raise error
                    return await self.retry()
                raise error

        # If we got a multicall response, decode it and set the results for each call
        if response.needs_decoding:
            await self.spoof_response(response)
        else:
            await self.spoof_response(response)

        # NOTE: We need to return the response to satisfy return typing, but it is not used
        return response

    async def _await_calls(self, calls: list[eth_call]) -> None:
        futs = [call._fut for call in calls]
        await wait(futs)

    async def _await_mc_tasks(self, batches: list["JSONRPCBatch"]) -> None:
        batch_futs = [batch._done for batch in batches]
        await wait(batch_futs)


### Multicall batching logic


class MulticallTypeError(TypeError):
    pass


class MulticallBuilder(Generic[_RequestBase[_Response]]):
    """
    This class is used to build and manage multicall batches.

    It keeps track of the `Multicall` objects it has created, and it
    handles their lifecycle, including creating new ones, adding calls,
    and cleaning up when they are done.

    Attributes:
        controller: The `DankMiddlewareController` instance.
        is_single_block: Whether the builder is for a single block.
        _calls: The list of `Multicall` objects.
        _lock: The lock used to ensure thread safety.
    """

    __slots__ = "controller", "is_single_block", "_calls", "_lock"

    def __init__(self, controller: "DankMiddlewareController", is_single_block: bool):
        self.controller = controller
        self.is_single_block = is_single_block
        self._calls = WeakList()
        self._lock = AlertingRLock(name=self.__class__.__name__)

    def __iter__(self) -> Iterator[Multicall]:
        return iter(self._calls)

    def __len__(self) -> int:
        return len(self._calls)

    def append(self, call: Multicall) -> None:
        if call._should_log_debugger is True:
            return
        with self._lock:
            self._calls.append(call)

    def extend(self, calls: Iterable[Multicall]) -> None:
        if self._calls.is_empty:
            return
        with self._lock:
            self._calls.extend(calls)

    def reset(self) -> None:
        self._calls = WeakList()

    def cleanup(self) -> None:
        if self._calls.is_empty:
            return
        with self._lock:
            self._calls = WeakList()

    @property
    def pending_calls(self) -> list[Multicall]:
        calls = self._calls
        if calls.is_empty:
            return []
        return list(calls)

    def _filter_batches(self, batches: Iterable[JSONRPCBatch]) -> list[JSONRPCBatch]:
        # We accept any iterable here for convenience
        batches = [batch for batch in batches if batch]
        # Batching logic may mutate _calls while iterating, so this needs to be done
        # by snapshotting the list before running any user code
        calls = self._calls.snapshot()
        for batch in batches:
            for call in batch:
                if call in calls:
                    calls.remove(call)
        if calls:
            # NOTE: There are pending calls that were not included in the batch
            #       This can happen when a call is GC'd or when a call is cancelled
            for call in calls:
                error = GarbageCollectionError(call)
                call._spoof_exception(error)
        return batches

    async def _batch_calls(self) -> list[JSONRPCBatch]:
        if self._calls.is_empty:
            return []
        batches = self.controller._build_multicall_batches(self._calls)
        return self._filter_batches(batches)

    async def _spawn_multicall(self, calls: list[Multicall]) -> list[JSONRPCBatch]:
        if not calls:
            return []
        # If there is only one call, it should be just that call.
        if len(calls) == 1:
            call = calls[0]
            call.start()
            return [call._batch]  # type: ignore [list-item]
        batches = []
        for call in calls:
            call.start()
            batches.append(call._batch)  # type: ignore [list-item]
        return batches

    async def _batch_by_equal_call_data(self) -> list[JSONRPCBatch]:
        # We accept any iterable here for convenience
        batches: list[JSONRPCBatch] = []
        calls = self._calls
        if calls.is_empty:
            return []
        for call_data, call_list in groupby(calls, lambda c: c._get_mc_data()):
            call_list = list(call_list)
            if len(call_list) == 1:
                call = call_list[0]
                call.start()
                batches.append(call._batch)  # type: ignore [list-item]
            else:
                batches += await self._spawn_multicall(call_list)
        return batches

    async def _gather_multicall_batch_futures(self, batch: JSONRPCBatch) -> JSONRPCBatch:
        # There should be no waiting when we get here; the only thing that could be
        # in _calls is new calls
        if self._calls:
            raise NotImplementedError
        try:
            await batch
        except Exception as e:
            return e
        return batch

    @cached_property
    def _batch_waiter(self) -> a_sync.Queue[Multicall]:
        return a_sync.Queue()

    async def queue_calls(self, calls: Iterable[Multicall]) -> list[JSONRPCBatch]:
        if calls:
            for call in calls:
                self._batch_waiter.put_nowait(call)

        if self._batch_waiter.qsize <= 1:
            return []

        # We get this opportunity to drain the queue in order to allow more calls to be queued
        calls = await self._batch_waiter.get_all()

        # If we have zero calls, we should not attempt to batch.
        if not calls:
            return []

        # We have more than one call, so we can make a multicall batch.
        # Calls need to be grouped by call data and paired with a multicall.
        calls = sorted(calls, key=lambda c: c._get_mc_data())

        # There should only be one call left over, so skip it
        return await self._batch_by_equal_call_data()

    async def _queue_multicall_batches(self, call_list: list[Multicall]) -> list[JSONRPCBatch]:
        if call_list:
            for call in call_list:
                self._batch_waiter.put_nowait(call)

        # If there's only one call, it should be processed elsewhere.
        if self._batch_waiter.qsize == 1:
            return []

        # We get this opportunity to drain the queue in order to allow more calls to be queued
        calls = await self._batch_waiter.get_all()

        # If we have zero calls, we should not attempt to batch.
        if not calls:
            return []

        # We have more than one call, so we can make a multicall batch.
        # Calls need to be grouped by call data and paired with a multicall.
        calls = sorted(calls, key=lambda c: c._get_mc_data())

        # There should only be one call left over, so skip it
        return await self._batch_by_equal_call_data()


### Batch requests:

_Request = TypeVar("_Request", bound=_RequestBase)


class _Batch(_RequestBase[list[_Response]], Iterable[_Request]):
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
    def bisected(self) -> Generator[tuple[_Request, ...], None, None]:
        # set `self.calls` output to var so its only computed once
        calls = self.calls.snapshot()
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
        return create_batch_task(
            self.get_response(), name=f"{type(self).__name__} {self.uid} get_response"
        )

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
        while True:
            await sleep(60)
            if self._fut.done():
                return
            logger.warning(
                "%s still active after %s seconds",
                type(self).__name__,
                int(self._fut._start_time_delta),
            )

    def start(self, predecessor: Optional["_Batch"] = None, cleanup: bool = True) -> None:
        if self._awaited is True:
            raise RuntimeError(f"{self} has already been awaited")
        self._fut.underway = True
        # _RequestEvent has its own loop set and if its in another thread, we need
        # to set the done method in that loop for it to wake up properly
        if self._done._loop is get_running_loop():
            self._done._loop.call_soon_threadsafe(self._done.set)
        else:
            self._done._loop.call_soon_threadsafe(self._done.set)

        # start a task that will batch other requests (this task) can take
        if not BATCH_TASKS:
            # future will resolve before self._fut.underway is True
            # but the _fut.underway flag isn't used anywhere other than this
            # method so it's ok
            create_task(self.controller.queue, name="_Batch queue")

        task = self._task

        if cleanup and predecessor is not None:
            predecessor.cleanup()

        task.set_name(f"{type(self).__name__} {self.uid} get_response")

    def cleanup(self) -> None:
        if not self._done.done() and self._done._loop.is_running():
            _log_warning("%s's done event was not set, scheduling it now", self)
            self._done._loop.call_soon_threadsafe(self._done.set)
        self._done._loop.call_soon_threadsafe(self._done._owner, "cleanup")

    @property
    def _daemon_name(self) -> str:
        return f"{type(self).__name__} {self.uid} debug daemon"


class _BatchCollection(Generic[_Request]):
    """
    This is a base class for all batch collections. It handles the shared logic for them.

    Attributes:
        controller: The `DankMiddlewareController` instance.
        _requests: A list of _Request objects.
        _batches: A list of _Batch objects.
        _lock: The lock used to ensure thread safety.
    """

    __slots__ = "controller", "_requests", "_batches", "_lock"

    def __init__(self, controller: "DankMiddlewareController") -> None:
        self.controller = controller
        self._requests: list[_Request] = []
        self._batches: list[_Batch] = []
        self._lock = AlertingRLock(name=type(self).__name__)

    def __len__(self) -> int:
        return len(self._requests)

    def _record_failure(self, e: Exception, data: str) -> None:
        _debugging.failures.record(
            self.controller.chain_id,
            e,
            type(self).__name__,
            self.uid,
            len(self._batches),
            data,
        )

    def _await_batches(self, batches: Sequence[_Batch]) -> None:
        # We need to make sure all batches are done
        wait([batch._done for batch in batches])

    def _process_batches(self, batches: list[_Batch]) -> None:
        # Clear out the requests so we can still batch requests while we are doing this
        # we want to do this as quickly as possible
        if batches:
            self._requests.clear()
        else:
            return

        # We want to keep any new requests that we might not process here
        self._requests += [request for request in batches if not request._fut.done()]

        # Once all requests are complete, we can reset this collection
        if all(batch._fut.done() for batch in self._requests):
            self._requests.clear()

    def _get_batches_to_run(self, requests: Iterable[_Request]) -> list[_Batch]:
        # We only allow batches with the same request method (i.e. for multicall vs normal
        # JSON-RPC requests)
        return [
            self._batcher(self.controller, batch)
            for batch in requests
            if batch
        ]

    def _split_batches(self, batches: list[_Batch]) -> list[_Batch]:
        """
        Split batches into smaller batches if necessary.

        Args:
            batches: The list of batches to split.

        Returns:
            A list of batches, split to a smaller size if needed.
        """
        # NOTE: We need to do this because sometimes we have a batch with a single item
        # that's a multicall. We can't have a batch with a single multicall item.
        if not batches:
            return []

        # We need to separate out the requests that are multicalls, since they need
        # to be handled differently than JSON-RPC batches.
        multicalls = [call for call in batches if isinstance(call, Multicall)]
        jsonrpc = [call for call in batches if not isinstance(call, Multicall)]

        # Split batches into multicall batches
        multicall_batches = []
        for batch in multicalls:
            if len(batch) == 1:
                call = batch.calls[0]  # type: ignore [index]
                # Make a new multicall batch with this call
                multicall_batches.append(Multicall(self.controller, call, call.block))
            else:
                multicall_batches.append(batch)

        # Split jsonrpc batches into smaller batches
        jsonrpc_batches = []
        for batch in jsonrpc:
            if len(batch) == 1:
                jsonrpc_batches.append(batch)
            else:
                # Split into two
                jsonrpc_batches.extend(batch.bisected)

        return multicall_batches + jsonrpc_batches

    async def _handle_batches(self, batches: list[_Batch]) -> None:
        if not batches:
            return

        # We make sure the number of items in each batch is within the desired range.
        # We do this to avoid small or big batches that can be slow or cause errors.
        if len(batches) > 1:
            # bisect into smaller batches
            batches = self._split_batches(batches)

        # If any batch is empty, raise an error to avoid making an empty request
        # to the node, which can happen if a request is garbage collected.
        for batch in batches:
            if not batch:
                raise EmptyBatch(batch)

        # We need to handle multicalls separately from jsonrpc batches.
        for batch in batches:
            if isinstance(batch, Multicall):
                await batch.get_response()
            else:
                await batch.get_response()


class _MulticallBatcher(Generic[_Request]):
    """
    Batch multicalls to optimize network usage and reduce latency.

    Attributes:
        controller: The `DankMiddlewareController` instance.
        _calls: A list of multicall requests.
        _lock: The lock used to ensure thread safety.
        _done: The event to signal when processing is complete.
    """

    def __init__(self, controller: "DankMiddlewareController") -> None:
        self.controller = controller
        self._calls = WeakList()
        self._lock = AlertingRLock(name=self.__class__.__name__)
        self._done = _RequestEvent(self)

    def __iter__(self) -> Iterator[Multicall]:
        return iter(self._calls)

    def __len__(self) -> int:
        return len(self._calls)

    def append(self, call: Multicall) -> None:
        if not call.multicall_compatible:
            return
        self._calls.append(call)

    def extend(self, calls: Iterable[Multicall]) -> None:
        self._calls.extend(calls)

    def _group_calls(self) -> Iterator[list[Multicall]]:
        # Use `self.calls` output to prevent modification while iterating.
        calls = self._calls.snapshot()
        # NOTE: We are _not_ clearing `self._calls` here because
        #       we still need to track the calls in case the batch
        #       fails and we need to retry.
        # NOTE: We're using `filterfalse` to skip calls that are
        #       already in a batch.
        return groupby(
            (call for call in calls if not call.batched),
            lambda call: call._get_mc_data(),
        )

    async def _create_batches(self) -> list[JSONRPCBatch]:
        if self._calls.is_empty:
            return []

        # Use `self.calls` output to prevent modification while iterating.
        calls = self._calls.snapshot()
        # for each group of calls, spawn a Multicall for the group
        batches = [
            Multicall(self.controller, next(call_iter), f"multi{self.uid}_{i}")  # type: ignore [misc]
            if (call_iter := iter(call_group))
            else None
            for i, call_group in enumerate(self._group_calls())
        ]
        return [batch for batch in batches if batch]

    def cleanup(self) -> None:
        # NOTE: We need to call `self._calls.reset()` here because
        #       this codepath never triggers the calls to the controller
        #       that clean up the calls with weakrefs.
        self._calls.reset()


### JSON RPC batching logic


class JSONRPCBatch(_Batch[RPCRequest]):
    method_counts: DefaultDict[str, int]
    method_error_counts: DefaultDict[str, int]
    method_error_counts_json: DefaultDict[str, dict[str, int]]
    method_error_counts_raw: DefaultDict[str, dict[str, int]]
    method_total_call_time: DefaultDict[str, list[float]]

    batch_size: int
    _open: bool
    _closed: bool

    __slots__ = "method_counts", "method_error_counts", "method_error_counts_json", "method_error_counts_raw", "method_total_call_time", "batch_size", "_open", "_closed", "_error_type"

    def __init__(self, controller: "DankMiddlewareController", calls: Iterable[RPCRequest], jid: str):
        super().__init__(controller, calls)
        self.method_counts = defaultdict(int)
        self.method_error_counts = defaultdict(int)
        self.method_error_counts_json = defaultdict(lambda: defaultdict(int))
        self.method_error_counts_raw = defaultdict(lambda: defaultdict(int))
        self.method_total_call_time = defaultdict(list)

        # Keep track of the number of method calls in the batch
        if self._fut.underway:
            self.method_counts = defaultdict(int)
        else:
            for call in self.calls:
                self.method_counts[call.method] += 1

        self.method_error_counts = defaultdict(int)
        self._open = True
        self._closed = False

        # NOTE: this is a one-off property, used to determine the optimal
        #       batch size for this call to the controller, based on
        #       how quickly the call is returning vs how long it takes to
        #       process the responses. If we have a batch with only a
        #       single call, this is meaningless.
        self.batch_size = 0
        self._error_type = None

    @property
    def is_full(self) -> bool:
        # NOTE: this is a one-off property, used to determine the optimal
        #       batch size for this call to the controller, based on
        #       how quickly the call is returning vs how long it takes to
        #       process the responses. If we have a batch with only a
        #       single call, this is meaningless.
        return len(self) >= self.controller.max_jsonrpc_batch_size

    @property
    def is_closed(self) -> bool:
        return self._closed

    @property
    def is_open(self) -> bool:
        return self._open

    def close(self) -> None:
        if self._closed:
            return
        self._closed = True

    def __repr__(self) -> str:
        return f"{type(self).__name__}({len(self.calls)})"

    async def _request(self) -> list[RawResponse]:
        if self._fut.underway is False:
            self._fut.underway = True

        if not self._fut.done():
            # `mcall_encode` when passed an iterable returns a tuple
            data = mcall_encode(call.to_jsonrpc() for call in self.calls)
            self.data = data

            try:
                self._fut.set_result(await self.controller.make_request(self))
            except Exception as e:
                # NOTE: If this is an exception, then it could be a variety of
                # issues. There are a few different types that can be raised here,
                # so it is important to check the error message in `e`.

                # NOTE: The contents of e may include our custom error type. If it
                # is, we should re-raise the error so that we can try again.
                if isinstance(e, BadResponse):
                    if e.response is None:
                        raise e
                    if isinstance(e.response, list):
                        for response in e.response:
                            if isinstance(response, RawResponse):
                                response = response.decode()
                            if response["id"] is None:
                                continue
                            error = response["error"]
                            if error is None:
                                continue
                            if error["code"] == -32005 and "replace" in error["message"].lower():
                                # This error indicates that the node is trying to deliver a response
                                # for an earlier call that was replaced in its memory by more recent
                                # calls. When this happens, we should just retry this call.
                                # The cache is stable enough that this works consistently.
                                raise e
                    # NOTE: If this is an exception but it isn't in error or it is an error
                    # but doesn't match our custom error type, then we should just log it.
                    self._fut.set_exception(e)
                    if isinstance(e, EmptyBatch):
                        return []
                else:
                    self._fut.set_exception(e)
            else:
                # NOTE: It is expected that we might get an empty response here,
                # because the jsonrpc request might be empty if all of the calls
                # are garbage collected.
                if not self._fut.result():
                    raise EmptyBatch(self)

        # At this point, we should have a result in `_fut`. We need to check if
        # it is an error and handle it accordingly.
        response = self._fut.result()
        # If we were awaiting this future and it errored, then it would raise
        # the exception here. If it was not awaited, then it would return the
        # error object.
        if response.is_error:
            error = response.error
            if error is None:
                raise response
            # NOTE: We handle these in `get_response`, no need to handle them here
            if isinstance(error, BadResponse):
                return response
            raise error
        return response

    async def _handle_response(self, response: list[RawResponse]) -> list[RawResponse]:
        # NOTE: We should not come here if `_request` has returned an EmptyBatch error.
        if not response:
            raise EmptyBatch(self)

        # NOTE: A successful response will be a list of `RawResponse` objects.
        #       A single `PartialResponse` implies an error.
        if isinstance(response, list):
            return response

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

    async def _spoof_response_by_id(self, response: list[RawResponse]) -> list[Coroutine[Any, Any, None]]:
        call_by_id = {str(call.uid): call for call in self}
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
    async def spoof_response(self, response: list[RawResponse]) -> None:
        """
        Process the responses from the Ethereum node and set the results for each call.

        This method processes the responses from the Ethereum node and sets the results
        for each call in the batch. It also handles any exceptions that occurred during
        the processing.

        Args:
            response: A list of RawResponse objects containing the responses from the node.
        """
        # Reaching this point means we made a batch call and we got results. That doesn't mean they're good, but we got 'em.

        mcall_coros = await self._spoof_response_by_id(response)

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
