
# TODO: Robust and Refactor

import asyncio
import logging
from collections import defaultdict, deque
from concurrent.futures import ProcessPoolExecutor
from time import time
from typing import (TYPE_CHECKING, Any, Callable, DefaultDict, Deque, Set,
                    Type, Union)

from msgspec import ValidationError
from web3.types import RPCEndpoint

from dank_mids import _config
from dank_mids.brownie_patch import call

if TYPE_CHECKING:
    from dank_mids.requests import JSONRPCBatch
    from dank_mids.types import Request

Level = Union[int, str]

# New `Level`s:
# NOTE: DEBUG == 10
STATS = 12
DEVHINT = 11

Times = Deque[float]

COLLECT_STATS: bool = False  # TODO: enable this

class StatsLogger(logging.Logger):
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
    
    def log_brownie_stats(self, *, level: Level = STATS) -> None:
        self._log_fn_result(level, Writer.brownie)

    def log_event_loop_stats(self, *, level: Level = STATS) -> None:
        self._log_fn_result(level, Writer.event_loop)

    def log_subprocess_stats(self, *, level: Level = STATS) -> None:
        for pool in collector._subprocesses:
            self._log_fn_result(level, Writer.queue, pool)
    
    # Internal helpers

    def _log(self, level: Level, *args, **kwargs) -> None:
        # Saves us having to do this ourselves for each custom message
        if self.isEnabledFor(level):
            return self._log_nocheck(level, *args, **kwargs)
    
    def _log_nocheck(self, level: Level, *args, **kwargs) -> None:
        try:
            return super()._log(level, args[0], args[1:], **kwargs)
        except IndexError:
            raise ValueError("Both a level and a message are required.") from None

    def _log_fn_result(self, level: Level, callable: Callable[[], str], *callable_args, **logging_kwargs) -> None:
        """If `self.isEnabledFor(level)` is True, will call `callable` with your args and log the output."""
        if self.isEnabledFor(level):
            return self._log_nocheck(level, callable(*callable_args), (), **logging_kwargs)
    
    # Daemon

    def _ensure_daemon(self) -> None:
        if (_config.COLLECT_STATS or self.enabled) and self._daemon is None:
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

    def log_validation_error(self, method: RPCEndpoint, e: ValidationError) -> None:
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

    def _log_list_types(self, values, level: Level = DEVHINT) -> None:
        list_types = {type(_) for v in values if isinstance(v, list) for _ in v}
        collector.types.update(list_types)
        if self.isEnabledFor(level):
            self._log(level, f"list types: {list_types}")

logger = StatsLogger(__name__)
log = logger.stats
devhint = logger.devhint

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

class _Collector:
    errd_batches = deque(maxlen=500)
    durations: DefaultDict[str, Times] = defaultdict(lambda: deque(maxlen=50_000))
    types: Set[Type] = set()
    event_loop_times: Times = deque(maxlen=50_000)
    _brownie_semaphore = call.brownie_call_semaphore
    encoder_processes = call.encoder_processes
    decoder_processes = call.decoder_processes
    validation_errors: DefaultDict[RPCEndpoint, Deque["Request"]] = defaultdict(lambda: deque(maxlen=100))
    _subprocesses = {encoder_processes, decoder_processes}

    @property
    def avg_loop_time(self) -> float:
        return sum(collector.event_loop_times) / len(collector.event_loop_times)
    @property
    def count_active_brownie_calls(self) -> int:
        return self._brownie_semaphore.default_value - self._brownie_semaphore.semaphore._value
    @property
    def count_queued_brownie_calls(self) -> int:
        return len(self._brownie_semaphore.semaphore._waiters)
    @property
    def encoder_queue_len(self) -> int:
        return self.encoder_processes._queue_count
    @property
    def decoder_queue_len(self) -> int:
        return self.encoder_processes._queue_count
        

collector = _Collector()

class Writer:
    """
    `Writer` is used to turn `Collector` stats into human readable on a as-needed,
    JIT basis without wasting compute or cluttering `Collector` or `StatsLogger`.
    """
    def event_loop(self) -> str:
        return f"Average event loop time: {collector.avg_loop_time}"
    def brownie(self) -> str:
        return f"{collector.count_active_brownie_calls} brownie calls are processing, {collector.count_queued_brownie_calls} are queued in {collector._brownie_semaphore}."
    def queue(self, pool: ProcessPoolExecutor) -> str:
        return f"{pool} has {pool._queue_count} items in its queue"
