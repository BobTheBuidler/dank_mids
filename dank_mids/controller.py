from asyncio import get_running_loop
from collections import defaultdict
from functools import lru_cache
from time import time
from typing import (
    Any,
    DefaultDict,
    Final,
    List,
    Literal,
    Optional,
    Sequence,
    Set,
    Union,
    cast,
    final,
)

import eth_retry
from cchecksum import to_checksum_address
from eth_typing import BlockNumber, ChecksumAddress, HexStr
from eth_typing.evm import BlockParams
from evmspec.data import ChainId
from multicall.constants import MULTICALL_ADDRESSES
from multicall.multicall import NotSoBrightBatcher
from web3 import Web3
from web3.types import RPCEndpoint, RPCResponse

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids import _debugging
from dank_mids._batch import DankBatch
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import DankMidsInternalError
from dank_mids._logging import getLogger
from dank_mids._requests import JSONRPCBatch, Multicall, RPCRequest, eth_call
from dank_mids._uid import UIDGenerator
from dank_mids.exceptions import GarbageCollectionError
from dank_mids.helpers._codec import RawResponse, decode_raw
from dank_mids.helpers._errors import log_request_type_switch
from dank_mids.helpers._helpers import w3_version_major, _sync_w3_from_async
from dank_mids.helpers._lock import AlertingRLock
from dank_mids.helpers._multicall import MulticallContract, _get_multicall2, _get_multicall3
from dank_mids.helpers._rate_limit import rate_limit_inactive
from dank_mids.helpers._session import post
from dank_mids.semaphores import BlockSemaphore
from dank_mids.types import BlockId, PartialRequest, Request

logger = getLogger(__name__)
# our new logger logs the same stuff plus more
getLogger("web3.RequestManager").disabled = True
getLogger("web3.RequestManager").propagate = False

instances: Final[DefaultDict[ChainId, List["DankMiddlewareController"]]] = defaultdict(list)


@final
class DankMiddlewareController:
    """
    Controller for managing Dank Middleware operations.

    This class handles the core functionality of Dank Mids, including request batching,
    call execution, and error handling.

    See Also:
        :class:`dank_mids.semaphores.BlockSemaphore`: Used for managing concurrency of eth_calls made with the controller.
    """

    pending_rpc_calls: JSONRPCBatch
    """A :class:`~JSONRPCBatch` containing all pending rpc requests."""

    def __init__(self, w3: Web3) -> None:
        """
        Initialize the DankMiddlewareController.

        Args:
            w3: The Web3 instance used to make RPC requests.
        """
        logger.info("Dank Middleware initializing... Strap on your rocket boots...")

        self._loop: Final = get_running_loop()

        self.w3: Final[Web3] = w3
        """The Web3 instance used to make rpc requests."""

        self.max_jsonrpc_batch_size = int(ENVS.MAX_JSONRPC_BATCH_SIZE)  # type: ignore [call-overload]

        self.sync_w3: Final = _sync_w3_from_async(w3)
        """A sync Web3 instance connected to the same rpc, used to make calls during init."""

        chainid = self.sync_w3.eth.chain_id
        self.chain_id: Final = chainid
        """The chainid for the currently connected rpc."""

        self.client_version: Final[str] = _get_client_version(self.sync_w3)
        """The client version for the currently connected rpc."""

        using_reth_client = "reth" in self.client_version
        using_tenderly_client = self.client_version == "Tenderly/1.0"

        # NOTE: We need this mutable for node types that require the full jsonrpc spec
        self.request_type = (
            Request if ENVS.USE_FULL_REQUEST or using_reth_client else PartialRequest
        )
        """The Struct class the controller will use to encode requests."""

        self._request_type_changed_ts: float = 0.0
        """The time at which the request type was automatically updated by dank's internals. Zero if never updated after init."""

        # NOTE: Ganache does not support state override. Neither does Gnosis Chain.
        self.state_override_not_supported: Final = bool(ENVS.GANACHE_FORK or chainid == 100)
        """A boolean that indicates whether the connected rpc supports state override functionality."""

        self.endpoint: Final[str] = self.w3.provider.endpoint_uri  # type: ignore [attr-defined]
        """The uri for the connected rpc."""

        using_chainstack_rpc = "chainstack" in self.endpoint

        self._sort_calls: bool = using_tenderly_client or using_chainstack_rpc
        """A boolean that indicates whether calls must be sorted by id in order for dank to work with the connected rpc."""

        self._sort_response: bool = using_tenderly_client or using_chainstack_rpc
        """A boolean that indicates whether a jsonrpc batch response must be sorted by id in order for dank to work with the connected rpc."""

        if using_tenderly_client and self.max_jsonrpc_batch_size > 10:
            logger.info("max jsonrpc batch size for Tenderly is 10, overriding existing max")
            self.set_batch_size_limit(10)

        self._instance: Final = sum(map(len, instances.values()))
        instances[chainid].append(self)

        self.mc2: Final = _get_multicall2(chainid)
        self.mc3: Final = _get_multicall3(chainid)
        if self.mc2 is None and self.mc3 is None:
            raise NotImplementedError(
                "Dank Mids currently does not support this network.\nTo add support, you just need to submit a PR adding the appropriate multicall contract addresses to this file:\nhttps://github.com/banteg/multicall.py/blob/master/multicall/constants.py"
            )

        self.no_multicall: Final[Set[ChecksumAddress]] = set()
        """A set of addresses that have issues when called from the multicall contract. Calls to these contracts will not be batched in multicalls."""

        if multicall := MULTICALL_ADDRESSES.get(chainid):
            self.no_multicall.add(to_checksum_address(multicall))
        if self.mc2:
            self.no_multicall.add(self.mc2.address)
        if self.mc3:
            self.no_multicall.add(self.mc3.address)
        self._latest_mc: Final = self.mc3 or self.mc2

        self.eth_call_semaphores: Final = BlockSemaphore(
            BlockNumber(ENVS.method_semaphores["eth_call"]._value),
            name=f"eth_call {self}",
        )
        """Used for managing concurrency of eth_calls."""

        self.batcher: Final[NotSoBrightBatcher] = NotSoBrightBatcher()
        """Batcher for RPC calls."""

        self.batcher.step = ENVS.MAX_MULTICALL_SIZE  # type: ignore [attr-defined]

        self.call_uid: Final[UIDGenerator] = UIDGenerator()
        """Unique identifier generator for individual calls."""

        self.multicall_uid: Final[UIDGenerator] = UIDGenerator()
        """Unique identifier generator for multicall operations."""

        self.request_uid: Final[UIDGenerator] = UIDGenerator()
        """Unique identifier generator for RPC requests."""

        self.jsonrpc_batch_uid: Final[UIDGenerator] = UIDGenerator()
        self.pools_closed_lock: Final[AlertingRLock] = AlertingRLock(name="pools closed")

        self.pending_eth_calls: Final[DefaultDict[BlockId, Multicall]] = defaultdict(
            lambda: Multicall(self)
        )
        """A dictionary of pending :class:`~Multicall` objects by block. The Multicalls hold all pending eth_calls."""

        self._start_new_batch()

    def __repr__(self) -> str:
        """
        Returns a string representation of the DankMiddlewareController instance.

        Returns:
            str: A string containing the instance number, chain ID, and endpoint.
        """
        return f"<DankMiddlewareController instance={self._instance} chain={self.chain_id} endpoint={self.endpoint}>"

    async def __call__(self, method: RPCEndpoint, params: Any) -> RPCResponse:
        """
        Asynchronous method to handle RPC calls.

        This method routes different types of RPC calls to appropriate handlers,
        including specialized handling for eth_call and other methods that may use queues.

        Args:
            method: The RPC method to be called.
            params: The parameters for the RPC call.

        Returns:
            The response from the RPC call.
        """

        await rate_limit_inactive(self.endpoint)

        try:
            # eth_call go thru a specialized Semaphore and other methods pass thru unblocked
            if method == "eth_call":
                async with self.eth_call_semaphores[params[1]]:
                    # create a strong ref to the call that will be held until the caller completes or is cancelled
                    _logger_debug(
                        "making %s %s with params %s", self.request_type.__name__, method, params
                    )
                    if params[0]["to"] in self.no_multicall:
                        return await RPCRequest(self, method, params)
                    return await eth_call(self, params)

            _logger_debug("making %s %s with params %s", self.request_type.__name__, method, params)
            return await RPCRequest(self, method, params)
        except GarbageCollectionError:
            # this exc shouldn't be exposed to the user so let's try this again
            return await self(method, params)

    @eth_retry.auto_retry(min_sleep_time=0, max_sleep_time=1)
    async def make_request(
        self, method: str, params: Sequence[Any], request_id: int | str | None = None
    ) -> RawResponse:
        """
        Makes an RPC request to the Ethereum node.

        This method creates an RPC request with the given method and parameters,
        sends it to the node, and returns the raw response.

        Args:
            method: The RPC method to call.
            params: The parameters for the RPC method.
            request_id: An optional request ID. If not provided, a new ID will be generated.

        Returns:
            The raw response from the Ethereum node.

        Raises:
            Exception: If DEBUG environment variable is set, any exception that occurs during the request is logged and re-raised.
        """
        request = self.request_type(
            method=method, params=params, id=request_id or self.call_uid.next
        )
        try:
            return await post(self.endpoint, data=request, loads=decode_raw)
        except Exception as e:
            if ENVS.DEBUG:
                _debugging.failures.record(
                    self.chain_id,
                    e,
                    "eth_call" if method == "eth_call" else "RPCRequest",
                    "unknown",
                    "unknown",
                    request.data,
                )
            raise

    async def execute_batch(self) -> None:
        """
        Execute a batch of pending calls.

        This method collects all pending eth calls and RPC calls, clears the pending queues,
        and executes them as a single batch.
        """
        with self.pools_closed_lock:  # Do we really need this?  # NOTE: yes we do
            multicalls = self.pending_eth_calls.copy()
            self.pending_eth_calls.clear()
            rpc_calls = self.pending_rpc_calls
        self._start_new_batch()
        demo_logger.info("executing dank batch (current cid: %s)", self.call_uid.latest)
        batch = DankBatch(self, multicalls, rpc_calls)
        await batch
        demo_logger.info("%s done", batch)

    @property
    def queue_is_full(self) -> bool:
        """
        Check if the queue of pending calls is full.

        Returns:
            True if the queue is full, False otherwise.
        """
        with self.pools_closed_lock:
            if ENVS.OPERATION_MODE.infura:  # type: ignore [attr-defined]
                return sum(map(len, self.pending_rpc_calls)) >= self.max_jsonrpc_batch_size  # type: ignore [no-any-return]
            eth_calls = sum(map(len, self.pending_eth_calls.values()))
            other_calls = sum(map(len, self.pending_rpc_calls))
            return eth_calls + other_calls >= cast(int, self.batcher.step)

    def _check_request_type(self) -> bool:
        """
        If the controller is still using the PartialRequest type, it will change over to the Request type.

        Returns:
            True if the request type was updated, either now or any time in the past 10 minutes. False otherwise.
        """
        if not self._request_type_changed_ts:
            self.request_type = Request
            self._request_type_changed_ts = time()
            log_request_type_switch()
            return True
        return time() - self._request_type_changed_ts <= 600

    def early_start(self) -> None:
        """
        Initiate processing of queued calls when a full batch is available.

        This method combines pending eth_calls and other RPC calls into a single batch,
        clears the pending Ethereum calls queue, and starts processing the combined
        batch. It's used to optimize processing by starting as soon as enough calls
        are queued to form a full batch.
        """
        with self.pools_closed_lock:
            self.pending_rpc_calls.extend(self.pending_eth_calls.values(), skip_check=True)
            self.pending_eth_calls.clear()
            self.pending_rpc_calls.start()

    def reduce_multicall_size(self, num_calls: int) -> None:
        """
        Decrease the size of multicall batches in response to failures.

        This method is called when a multicall operation fails, allowing the system
        to dynamically adjust the batch size to prevent future failures.

        Args:
            num_calls: The number of calls in the failed multicall operation.
        """
        self._reduce_chunk_size(num_calls, "multicall")

    def reduce_batch_size(self, num_calls: int) -> None:
        """
        Decrease the size of JSON-RPC batches in response to failures.

        Similar to :meth:`reduce_multicall_size`, this method is called when a JSON-RPC
        batch operation fails, allowing for dynamic adjustment of batch sizes.

        Args:
            num_calls: The number of calls in the failed batch operation.
        """
        self._reduce_chunk_size(num_calls, "batch")

    def _reduce_chunk_size(self, num_calls: int, chunk_name: Literal["multicall", "batch"]) -> None:
        """
        Internal method to reduce the size of processing chunks.

        This method is used by both reduce_multicall_size and reduce_batch_size
        to implement the actual size reduction logic.

        Args:
            num_calls: The number of calls in the failed chunk.
            chunk_name: The type of chunk to reduce, either "multicall" or "batch".

        Raises:
            DankMidsInternalError: If an invalid chunk_name is provided.
        """
        new_chunk_size = round(num_calls * 0.99) if num_calls >= 100 else num_calls - 1
        if new_chunk_size < 30:
            logger.warning(
                f"your {chunk_name} batch size is really low, did you have some connection issue earlier? You might want to restart your script. {chunk_name} chunk size will not be further lowered."
            )
            return
        # NOTE: We need the 2nd check because one of the other calls in a batch might have already reduced the chunk size
        if chunk_name == "batch":
            self.set_batch_size_limit(new_chunk_size)
            logger.info("The failed batch had %s calls", num_calls)
            return
        elif chunk_name == "multicall":
            self.set_multicall_size_limit(new_chunk_size)
            logger.info("The failed multicall had %s calls", num_calls)
            return
        raise DankMidsInternalError(ValueError(f"chunk name {chunk_name} is invalid"))

    def set_multicall_size_limit(self, new_limit: int) -> None:
        """
        Set a new limit for the multicall size.

        Args:
            new_limit: The new maximum number of calls in a multicall.
        """
        existing_limit = self.batcher.step
        if new_limit < existing_limit:
            self.batcher.step = new_limit
            logger.warning("multicall size limit reduced from %s to %s", existing_limit, new_limit)
        else:
            logger.info(
                "new multicall size limit %s is not lower than existing limit %s",
                new_limit,
                existing_limit,
            )

    def set_batch_size_limit(self, new_limit: int) -> None:
        """
        Set a new limit for the JSON-RPC batch size.

        Args:
            new_limit: The new maximum number of calls in a JSON-RPC batch.
        """
        existing_limit = self.max_jsonrpc_batch_size
        if new_limit < existing_limit:
            self.max_jsonrpc_batch_size = new_limit
            logger.warning(
                "jsonrpc batch size limit reduced from %s to %s", existing_limit, new_limit
            )
        else:
            logger.info(
                "new jsonrpc batch size limit %s is not lower than existing limit %s",
                new_limit,
                existing_limit,
            )

    @lru_cache(maxsize=1024)
    def _select_mcall_target_for_block(
        self, block: Union[BlockNumber, Literal["latest"], HexStr]
    ) -> MulticallContract:
        """
        Select the appropriate multicall contract for a given block.

        Args:
            block: The block number or 'latest'.

        Returns:
            The selected multicall contract.
        """
        if block == "latest":
            return cast(MulticallContract, self._latest_mc)
        mc3 = self.mc3
        if mc3 and not mc3.needs_override_code_for_block(block):
            return mc3
        # We don't care if mc2 needs override code, mc2 override code is shorter
        return cast(MulticallContract, self.mc2 or mc3)

    def _start_new_batch(self) -> None:
        """Creates a new :class:`~JSONRPCBatch`."""
        with self.pools_closed_lock:  # Do we really need this?  # NOTE: yes we do
            self.pending_rpc_calls = JSONRPCBatch(self)


@eth_retry.auto_retry(min_sleep_time=0, max_sleep_time=0)
def _get_client_version(sync_w3: Web3) -> str:
    return cast(str, sync_w3.client_version if w3_version_major >= 6 else sync_w3.clientVersion)  # type: ignore [attr-defined]


def _logger_debug(msg: str, *args: Any) -> None: ...


_logger_debug = logger.debug
