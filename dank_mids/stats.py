
# TODO: Robust and Refactor

import asyncio
import logging
from collections import defaultdict, deque
from concurrent.futures import ProcessPoolExecutor
from time import time
from typing import (TYPE_CHECKING, Any, Callable, DefaultDict, Deque, Set,
                    Type, Union)

import msgspec
from typed_envs.registry import _ENVIRONMENT_VARIABLES_SET_BY_USER
from web3.types import RPCEndpoint

from dank_mids import ENVIRONMENT_VARIABLES as ENVS

if TYPE_CHECKING:
    from dank_mids._requests import JSONRPCBatch
    from dank_mids.types import Request

_LogLevel = Union[int, str]

# New logging levels:
# DEBUG=10, INFO=20, 
STATS = 13
DEVHINT = 15

COLLECT_STATS: bool = False  # TODO: enable this

# if you're both collecting data and logging something, put the function here:

def log_errd_batch(batch: "JSONRPCBatch") -> None:
    collector.errd_batches.append(batch)
    logger.devhint(f"jsonrpc batch failed\njson batch id: {batch.jid} | len: {len(batch)} | total calls: {batch.total_calls}\n"
        + f"methods called: {batch.method_counts}")
    
def log_duration(work_descriptor: str, start: float, *, level=STATS) -> None:
    # sourcery skip: hoist-if-from-if
    enabled = logger.isEnabledFor(level)
    if COLLECT_STATS or enabled:
        duration = time() - start
        if COLLECT_STATS:
            collector.durations[work_descriptor].append(duration)
        if enabled:
            logger._log_nocheck(level, f"{work_descriptor} took {duration}")


class _StatsLogger(logging.Logger):
    """A specialized logger for logging stats related to dank mids"""

    @property
    def enabled(self) -> bool:
        """Returns `True` if level is set to `STATS` (`11`) or below."""
        self._ensure_daemon()
        return self.isEnabledFor(STATS)
    
    # New logging levels

    def stats(self, msg, *args, **kwargs) -> None:
        if self.enabled:
            self._log_nocheck(STATS, msg, args, **kwargs)

    def devhint(self, msg, *args, **kwargs) -> None:
        self._log(DEVHINT, msg, args, **kwargs)

    # Functions to print stats to your logs.
    
    def log_brownie_stats(self, *, level: _LogLevel = STATS) -> None:
        self._log_fn_result(level, _Writer.brownie)

    def log_event_loop_stats(self, *, level: _LogLevel = STATS) -> None:
        self._log_fn_result(level, _Writer.event_loop)

    def log_subprocess_stats(self, *, level: _LogLevel = STATS) -> None:
        for pool in {ENVS.BROWNIE_ENCODER_PROCESSES, ENVS.BROWNIE_DECODER_PROCESSES, ENVS.MULTICALL_DECODER_PROCESSES}:
            self._log_fn_result(level, _Writer.queue, pool)
    
    # Internal helpers

    def _log(self, level: _LogLevel, *args, **kwargs) -> None:
        # Saves us having to do this ourselves for each custom message
        if self.isEnabledFor(level):
            return self._log_nocheck(level, *args, **kwargs)
    
    def _log_nocheck(self, level: _LogLevel, *args, **kwargs) -> None:
        try:
            return super()._log(level, args[0], args[1:], **kwargs)
        except IndexError:
            raise ValueError("Both a level and a message are required.") from None

    def _log_fn_result(self, level: _LogLevel, callable: Callable[[], str], *callable_args, **logging_kwargs) -> None:
        """If `self.isEnabledFor(level)` is True, will call `callable` with your args and log the output."""
        if self.isEnabledFor(level):
            return self._log_nocheck(level, callable(*callable_args), (), **logging_kwargs)
    
    # Daemon

    def _ensure_daemon(self) -> None:
        if (ENVS.COLLECT_STATS or self.enabled) and self._daemon is None:
            self._daemon = asyncio.create_task(self._stats_daemon())
        elif self._daemon.done():
            raise self._daemon.exception()
        
    async def _stats_daemon(self) -> None:
        start = time()
        time_since_notified = 0
        while True:
            await asyncio.sleep(0)
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
        enabled = self.isEnabledFor(DEVHINT)
        if COLLECT_STATS or enabled:
            collector.validation_errors[method].append(e)
        if enabled:
            self._log(DEVHINT, f"ValidationError when decoding response for {method}", ("This *should* not impact your script. If it does, you'll know."), e)

    def log_types(self, method: RPCEndpoint, decoded: Any) -> None:
        # TODO fix this, use enabled check
        types = {type(v) for v in decoded.values()}
        self.devhint(f'my method and types: {method} {types}')
        if list in types:
            self._log_list_types(decoded.values())
        collector.types.update(types)

    def _log_list_types(self, values, level: _LogLevel = DEVHINT) -> None:
        list_types = {type(_) for v in values if isinstance(v, list) for _ in v}
        collector.types.update(list_types)
        if self.isEnabledFor(level):
            self._log(level, f"list types: {list_types}")


_Times = Deque[float]

class _Collector:
    def __init__(self):
        """Handles the collection and computation of stats-related data."""
        self.errd_batches = deque(maxlen=500)
        self.durations: DefaultDict[str, _Times] = defaultdict(lambda: deque(maxlen=50_000))
        self.types: Set[Type] = set()
        self.event_loop_times: _Times = deque(maxlen=50_000)
        # not implemented
        self.validation_errors: DefaultDict[RPCEndpoint, Deque["Request"]] = defaultdict(lambda: deque(maxlen=100))

    @property
    def avg_loop_time(self) -> float:
        return sum(collector.event_loop_times) / len(collector.event_loop_times)
    @property
    def count_active_brownie_calls(self) -> int:
        return ENVS.BROWNIE_CALL_SEMAPHORE.default_value - ENVS.BROWNIE_CALL_SEMAPHORE.semaphore._value
    @property
    def count_queued_brownie_calls(self) -> int:
        return len(ENVS.BROWNIE_CALL_SEMAPHORE.semaphore._waiters)
    @property
    def encoder_queue_len(self) -> int:
        return ENVS.BROWNIE_ENCODER_PROCESSES._queue_count
    @property
    def decoder_queue_len(self) -> int:
        return ENVS.BROWNIE_DECODER_PROCESSES._queue_count
    @property
    def mcall_decoder_queue_len(self) -> int:
        return ENVS.MULTICALL_DECODER_PROCESSES._queue_count
        

class _Writer:
    """
    `Writer` is used to turn `Collector` stats into human readable on a as-needed, JIT basis
    without wasting compute or cluttering `Collector` or `StatsLogger` class definitions.
    """
    def event_loop(self) -> str:
        return f"Average event loop time: {collector.avg_loop_time}"
    def brownie(self) -> str:
        return f"{collector.count_active_brownie_calls} brownie calls are processing, {collector.count_queued_brownie_calls} are queued in {ENVS.BROWNIE_CALL_SEMAPHORE}."
    def queue(self, pool: ProcessPoolExecutor) -> str:
        return f"{pool} has {pool._queue_count} items in its queue"

            
class _SentryExporter:
    """
    Pushes all metrics from the `metrics` dict to sentry.
    Each metric value will be fetched by calling `getattr(collector, metrics[k])`.
    If the result is a callable object, it will be called without args.
    """
    metrics = {
        "active_eth_calls": "count_active_brownie_calls",
        "queued_eth_calls": "count_queued_brownie_calls",
        "encoder_queue":    "encoder_queue_len",
        "decoder_queue":    "decoder_queue_len",
        "loop_time":        "avg_loop_time",
    }
    units = {"loop_time": "seconds"}

    def push_measurements(self) -> None:
        """Pushes all metrics in `self._metrics` to sentry"""
        if self._exc:
            raise self._exc
        for tag, attr_name in self.metrics.items():
            attr = getattr(collector, attr_name)
            if callable(attr):
                attr = attr()
            self.set_measurement(tag, attr, self.units.get(attr_name))

    def push_envs(self) -> None:
        for env, value in _ENVIRONMENT_VARIABLES_SET_BY_USER.items():
            try:
                self.set_tag(env, value)
            except Exception as e:
                logger.warning(f"Unable to set sentry tag {env} to {value}. See {e.__class__.__name__} below:")
                logger.info(e, exc_info=True)
    try:
        import sentry_sdk
        set_tag = sentry_sdk.set_tag
        set_measurement = sentry_sdk.set_measurement
        _exc = None
    except ImportError as e:
        _exc = e


logger = _StatsLogger(__name__)
log = logger.stats
devhint = logger.devhint
collector = _Collector()
sentry = _SentryExporter()
