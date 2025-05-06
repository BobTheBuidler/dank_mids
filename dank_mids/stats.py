"""
stats.py

This module provides functionality for logging and collecting statistics related to the Dank Mids library.
It includes custom logging levels, a specialized logger, and classes for collecting and writing statistics.

Key components:
- Custom logging levels (STATS, DEVHINT)
- _StatsLogger: A specialized logger for Dank Mids statistics
- _Collector: Handles collection and computation of stats-related data
- _Writer: Converts collected stats into human-readable format
- _SentryExporter: Pushes metrics to Sentry

This module is crucial for debugging, performance monitoring, and optimization of the Dank Mids library.
"""

# TODO: Robust and Refactor

import logging
from asyncio import create_task
from collections import defaultdict, deque
from concurrent.futures import ProcessPoolExecutor
from time import time
from typing import (
    TYPE_CHECKING,
    Any,
    Callable,
    DefaultDict,
    Deque,
    Final,
    Set,
    Type,
    TypeVar,
    final,
)

import msgspec
from a_sync.asyncio import sleep0
from typed_envs.registry import _ENVIRONMENT_VARIABLES_SET_BY_USER
from web3.types import RPCEndpoint

from dank_mids import ENVIRONMENT_VARIABLES as ENVS

if TYPE_CHECKING:
    from dank_mids._requests import JSONRPCBatch
    from dank_mids.types import Request

_LogLevel = int

T = TypeVar("T")

# New logging levels:
# DEBUG=10, INFO=20,
STATS: Final = 13
"""Custom logging level for statistics, between DEBUG and INFO."""

DEVHINT: Final = 15
"""Custom logging level for developer hints, between STATS and INFO."""

COLLECT_STATS: bool = False  # TODO: enable this
"""Flag to enable or disable stats collection."""

_ENVS: Final = _ENVIRONMENT_VARIABLES_SET_BY_USER

yield_to_loop: Final = sleep0


# if you're both collecting data and logging something, put the function here:
# <func>


def log_errd_batch(batch: "JSONRPCBatch") -> None:
    """
    Log information about a failed JSON-RPC batch.

    Args:
        batch: The failed batch to log.
    """
    collector.errd_batches.append(batch)
    logger.devhint(
        f"jsonrpc batch failed\njson batch id: {batch.jid} | len: {len(batch)} | total calls: {batch.total_calls}\n"
        + f"methods called: {batch.method_counts}"
    )


def log_duration(work_descriptor: str, start: float, *, level: _LogLevel = STATS) -> None:
    """
    Log the duration of a specific operation.

    Args:
        work_descriptor: Description of the work being timed.
        start: Start time of the operation.
        level: Logging level to use. Defaults to STATS.
    """
    # sourcery skip: hoist-if-from-if
    enabled = logger.isEnabledFor(level)
    if COLLECT_STATS or enabled:
        duration = time() - start
        if COLLECT_STATS:
            collector.durations[work_descriptor].append(duration)
        if enabled:
            logger._log_nocheck(level, f"{work_descriptor} took {duration}")


@final
class _StatsLogger(logging.Logger):
    """
    A custom logger class for collecting and logging statistics about RPC method calls and responses.

    This logger extends the standard Python logging.Logger with methods for tracking validation errors,
    response types, and other statistics related to RPC interactions.
    """

    @property
    def enabled(self) -> bool:
        """Returns True if the logger is enabled for the STATS logging level (which is set to 13) or lower.

        This property checks if the current logging level is less than or equal to STATS and ensures the stats daemon
        is running. The STATS level is defined to be between DEBUG and INFO.

        Example:
            >>> _logger = _StatsLogger(__name__)
            >>> _logger.setLevel(STATS)
            >>> _logger.enabled
            True

        See Also:
            :meth:`isEnabledFor`
        """
        self._ensure_daemon()
        return self.isEnabledFor(STATS)

    # New logging levels

    def stats(self, msg, *args, **kwargs) -> None:
        """
        Log a message with the STATS logging level.

        Args:
            msg: The message to log.
            *args: Additional positional arguments for the logger.
            **kwargs: Additional keyword arguments for the logger.

        Example:
            >>> _logger.stats("Operation took %s seconds", 3.14)
        """
        if self.enabled:
            self._log_nocheck(STATS, msg, args, **kwargs)

    def devhint(self, msg, *args, **kwargs) -> None:
        """
        Log a message with the DEVHINT logging level.

        Args:
            msg: The message to log.
            *args: Additional positional arguments for the logger.
            **kwargs: Additional keyword arguments for the logger.

        Example:
            >>> _logger.devhint("This is a developer hint for debugging purposes")
        """
        self._log(DEVHINT, msg, args, **kwargs)

    # Functions to print stats to your logs.

    def log_brownie_stats(self, *, level: _LogLevel = STATS) -> None:
        """
        Log statistics related to Brownie operations.

        Args:
            level: The logging level to use. Defaults to STATS.

        Example:
            >>> _logger.log_brownie_stats()
        """
        self._log_fn_result(level, _Writer.brownie)

    def log_event_loop_stats(self, *, level: _LogLevel = STATS) -> None:
        """
        Log statistics about the event loop performance.

        Args:
            level: The logging level to use. Defaults to STATS.

        Example:
            >>> _logger.log_event_loop_stats()
        """
        self._log_fn_result(level, _Writer.event_loop)

    def log_subprocess_stats(self, *, level: _LogLevel = STATS) -> None:
        """
        Log statistics about subprocess pools and queues.

        Args:
            level: The logging level to use. Defaults to STATS.

        Example:
            >>> _logger.log_subprocess_stats()
        """
        for pool in {ENVS.BROWNIE_ENCODER_PROCESSES, ENVS.BROWNIE_DECODER_PROCESSES, ENVS.MULTICALL_DECODER_PROCESSES}:  # type: ignore [attr-defined]
            self._log_fn_result(level, _Writer.queue, pool)

    # Internal helpers

    def _log(self, level: _LogLevel, *args, **kwargs) -> None:
        """
        Wrapper around the standard logging method to simplify custom log level checks.

        Args:
            level: The logging level.
            *args: Additional positional arguments for the logger.
            **kwargs: Additional keyword arguments for the logger.
        """
        if self.isEnabledFor(level):
            return self._log_nocheck(level, *args, **kwargs)

    def _log_nocheck(self, level: _LogLevel, *args, **kwargs) -> None:
        """
        Perform logging without checking whether the logger is enabled for the level.

        Args:
            level: The logging level.
            *args: Additional positional arguments for the logger.
            **kwargs: Additional keyword arguments for the logger.

        Raises:
            ValueError: If no message is provided.
        """
        try:
            return super()._log(level, args[0], args[1:], **kwargs)
        except IndexError:
            raise ValueError("Both a level and a message are required.") from None

    def _log_fn_result(
        self, level: _LogLevel, callable: Callable[[T], str], *callable_args: T, **logging_kwargs
    ) -> None:
        """
        Call a function and log its result if the logger is enabled for the level.

        Args:
            level: The logging level.
            callable: A function that returns a string to log.
            *callable_args: Arguments to pass to the callable.
            **logging_kwargs: Additional keyword arguments for logging.
        """
        if self.isEnabledFor(level):
            return self._log_nocheck(level, callable(*callable_args), (), **logging_kwargs)

    # Daemon

    def _ensure_daemon(self) -> None:
        """
        Ensures that the stats daemon is running. If it's not running and conditions are met,
        it creates and starts the daemon task. If the daemon has finished, it raises any exception
        that occurred during its execution.

        Example:
            This method is automatically invoked when logger.enabled is accessed.
        """
        if (ENVS.COLLECT_STATS or self.enabled) and self._daemon is None:  # type: ignore [attr-defined,has-type]
            self._daemon = create_task(self._stats_daemon(), name="_StatsLogger debug daemon")
        elif self._daemon.done():
            raise self._daemon.exception()  # type: ignore [misc]

    async def _stats_daemon(self) -> None:
        """
        The main loop of the stats daemon. It continuously collects event loop times
        and periodically logs various statistics about the system's performance.

        Example:
            The daemon logs subprocess, brownie and event loop stats every 300 seconds.
        """
        start = time()
        time_since_notified = 0
        while True:
            await yield_to_loop()
            now = time()
            duration = now - start
            collector.event_loop_times.append(duration)
            start = time()
            time_since_notified += duration
            if time_since_notified > 300:
                self.log_subprocess_stats(level=logging.INFO)
                self.log_brownie_stats(level=logging.INFO)
                self.log_event_loop_stats(level=logging.INFO)
                time_since_notified = 0

    # TODO: MOVE COLLECTIONS UOT OF THIS CLASS

    def log_validation_error(self, method: RPCEndpoint, e: msgspec.ValidationError) -> None:
        """
        Log a validation error for a specific RPC method.

        Args:
            method: The RPC method that encountered the error.
            e: The validation error that occurred.

        Example:
            >>> _logger.log_validation_error("eth_call", some_validation_error)
        """
        enabled = self.isEnabledFor(DEVHINT)
        if COLLECT_STATS or enabled:
            collector.validation_errors[method].append(e)
        if enabled:
            self._log(
                DEVHINT,
                f"ValidationError when decoding response for {method}",
                ("This *should* not impact your script. If it does, you'll know."),
                e,
            )

    def log_types(self, method: RPCEndpoint, decoded: Any) -> None:
        """
        Log the types of decoded values for a specific RPC method.

        This method analyzes the decoded response data from an RPC call and logs
        information about the data types encountered. It's useful for understanding
        the structure of responses from different RPC methods.

        Args:
            method: The RPC method being logged.
            decoded: The decoded response data from the RPC call.

        Example:
            >>> _logger.log_types("eth_call", decoded_response)
        """
        # TODO fix this, use enabled check
        types = {type(v) for v in decoded.values()}
        self.devhint(f"my method and types: {method} {types}")
        if list in types:
            self._log_list_types(decoded.values())
        collector.types.update(types)

    def _log_list_types(self, values, level: _LogLevel = DEVHINT) -> None:
        """
        Log the types of items in a list.

        This internal method is used to analyze and log the types of elements
        found in list structures within RPC responses. It's particularly useful
        for understanding complex, nested data structures.

        Args:
            values: The list of values to analyze and log types for.
            level: The logging level to use. Defaults to DEVHINT.

        Example:
            >>> _logger._log_list_types(some_list)
        """
        list_types = {type(_) for v in values if isinstance(v, list) for _ in v}
        collector.types.update(list_types)
        if self.isEnabledFor(level):
            self._log(level, f"list types: {list_types}")


_Times = Deque[float]


@final
class _Collector:
    """Handles the collection and computation of stats-related data."""

    def __init__(self) -> None:
        self.errd_batches: Deque["JSONRPCBatch"] = deque(maxlen=500)
        """
        A deque that stores information about failed JSON-RPC batches.
        It has a maximum length of 500 to prevent unbounded memory usage.
        """

        self.durations: DefaultDict[str, _Times] = defaultdict(lambda: deque(maxlen=50_000))
        """
        A default dictionary that stores timing information for various operations.
        The keys are operation descriptors, and the values are deques of float values
        representing durations. Each deque has a maximum length of 50,000.
        """

        self.types: Set[Type] = set()
        """
        A set that stores all the types encountered during data collection.
        This is used for debugging and analysis purposes.
        """

        self.event_loop_times: _Times = deque(maxlen=50_000)
        """
        A deque that stores event loop execution times.
        It has a maximum length of 50,000 to limit memory usage.
        """

        # not implemented
        self.validation_errors: DefaultDict[RPCEndpoint, Deque[msgspec.ValidationError]] = (
            defaultdict(lambda: deque(maxlen=100))
        )
        """
        A default dictionary that stores validation errors encountered for each RPC endpoint.
        The keys are RPC endpoints, and the values are deques of ValidationError objects.
        Each deque has a maximum length of 100.
        """

    @property
    def avg_loop_time(self) -> float:
        """
        Calculates and returns the average event loop execution time.

        Returns:
            The average time taken for event loop iterations.

        Example:
            >>> avg_time = collector.avg_loop_time
        """
        return sum(collector.event_loop_times) / len(collector.event_loop_times)

    @property
    def count_active_brownie_calls(self) -> int:
        """
        Returns the number of currently active Brownie calls.

        Returns:
            The count of active Brownie calls.

        Example:
            >>> active_calls = collector.count_active_brownie_calls
        """
        return ENVS.BROWNIE_CALL_SEMAPHORE.default_value - ENVS.BROWNIE_CALL_SEMAPHORE.semaphore._value  # type: ignore [attr-defined]

    @property
    def count_queued_brownie_calls(self) -> int:
        """
        Returns the number of Brownie calls currently in the queue.

        Returns:
            The count of queued Brownie calls.

        Example:
            >>> queued_calls = collector.count_queued_brownie_calls
        """
        return len(ENVS.BROWNIE_CALL_SEMAPHORE.semaphore._waiters)  # type: ignore [attr-defined]

    @property
    def encoder_queue_len(self) -> int:
        """
        Returns the current length of the Brownie encoder queue.

        Returns:
            The number of items in the encoder queue.

        Example:
            >>> encoder_length = collector.encoder_queue_len
        """
        return ENVS.BROWNIE_ENCODER_PROCESSES._queue_count  # type: ignore [attr-defined]

    @property
    def decoder_queue_len(self) -> int:
        """
        Returns the current length of the Brownie decoder queue.

        Returns:
            The number of items in the decoder queue.

        Example:
            >>> decoder_length = collector.decoder_queue_len
        """
        return ENVS.BROWNIE_DECODER_PROCESSES._queue_count  # type: ignore [attr-defined]

    @property
    def mcall_decoder_queue_len(self) -> int:
        """
        Returns the current length of the multicall decoder queue.

        Returns:
            The number of items in the multicall decoder queue.

        Example:
            >>> mcall_length = collector.mcall_decoder_queue_len
        """
        return ENVS.MULTICALL_DECODER_PROCESSES._queue_count  # type: ignore [attr-defined]


class _Writer:
    """
    Writer is used to turn Collector stats into human readable on a as-needed, JIT basis
    without wasting compute or cluttering Collector or StatsLogger class definitions.
    """

    def event_loop(self) -> str:
        """
        Generates a human-readable string describing the average event loop time.

        Returns:
            A string containing the average event loop time.

        Example:
            >>> print(_Writer().event_loop())
        """
        return f"Average event loop time: {collector.avg_loop_time}"

    def brownie(self) -> str:
        """
        Generates a human-readable string describing the current state of Brownie calls.

        Returns:
            A string containing the number of active and queued Brownie calls.

        Example:
            >>> print(_Writer().brownie())
        """
        return f"{collector.count_active_brownie_calls} brownie calls are processing, {collector.count_queued_brownie_calls} are queued in {ENVS.BROWNIE_CALL_SEMAPHORE}."

    def queue(self, pool: ProcessPoolExecutor) -> str:
        """
        Generates a human-readable string describing the state of a process pool's queue.

        Args:
            pool: The ProcessPoolExecutor to describe.

        Returns:
            A string containing the number of items in the pool's queue.

        Example:
            >>> print(_Writer().queue(some_pool))
        """
        return f"{pool} has {pool._queue_count} items in its queue"


class _SentryExporter:
    """
    A class for exporting statistics and metrics from the :obj:`metrics` dict to Sentry.

    This class provides methods for setting tags and measurements in Sentry,
    which can be used for monitoring and debugging purposes.

    Each metric value will be fetched by calling `getattr(collector, metrics[k])`.
    If the result is a callable object, it will be called without args.

    See Also:
        :mod:`sentry_sdk`: The Sentry SDK for Python.
    """

    metrics = {
        "active_eth_calls": "count_active_brownie_calls",
        "queued_eth_calls": "count_queued_brownie_calls",
        "encoder_queue": "encoder_queue_len",
        "decoder_queue": "decoder_queue_len",
        "loop_time": "avg_loop_time",
    }
    units = {"loop_time": "seconds"}

    def push_measurements(self) -> None:
        """
        Push all metrics in `self.metrics` to Sentry.
        """
        if self._exc:
            raise self._exc
        for tag, attr_name in self.metrics.items():
            attr = getattr(collector, attr_name)
            if callable(attr):
                attr = attr()
            self.set_measurement(tag, attr, self.units.get(attr_name))

    def push_envs(self) -> None:
        """
        Push environment variables set by the user to Sentry.

        Any exceptions during tagging are logged as warnings.

        Example:
            >>> sentry.push_envs()
        """
        for env, value in _ENVS.items():
            try:
                self.set_tag(env, value)
            except Exception as e:
                logger.warning(
                    f"Unable to set sentry tag {env} to {value}. See {e.__class__.__name__} below:"
                )
                logger.info(e, exc_info=True)

    try:
        import sentry_sdk

        set_tag = sentry_sdk.set_tag
        """
        Set a tag for the current scope in Sentry.

        This is a reference to :func:`sentry_sdk.set_tag`.

        See Also:
            Sentry documentation on using tags:
            https://docs.sentry.io/platforms/python/enriching-events/tags/
        """

        set_measurement = sentry_sdk.set_measurement
        """
        Set a measurement for the current scope in Sentry.

        This is a reference to :func:`sentry_sdk.set_measurement`.

        See Also:
            Sentry documentation on using measurements:
            https://docs.sentry.io/platforms/python/enriching-events/measurements/
        """

        _exc = None
        """
        Stores any ImportError that occurred when trying to import sentry_sdk.
        If this is not None, it indicates that Sentry integration is not available.
        """
    except ImportError as e:
        _exc = e


logger: Final = _StatsLogger(__name__)
log: Final = logger.stats
devhint: Final = logger.devhint
collector: Final = _Collector()
sentry: Final = _SentryExporter()
