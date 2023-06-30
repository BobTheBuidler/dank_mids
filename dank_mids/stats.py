
import asyncio
import logging
from collections import defaultdict
from time import time
from typing import TYPE_CHECKING, Any, DefaultDict, List, Set, Type

from msgspec import ValidationError
from web3.types import RPCEndpoint

from dank_mids.brownie_patch import call

if TYPE_CHECKING:
    from dank_mids.types import Request

# DEBUG is 10
STATS = 12
DEVHINT = 11

class StatsLogger(logging.Logger):
    def __init__(self, *args, **kwargs) -> None:
        self._durations: DefaultDict[str, List[float]] = defaultdict(list)
        self._validation_errors: DefaultDict[RPCEndpoint, List[Request]] = defaultdict(list)
        self._types: Set[Type] = set()
        self._event_loop_times = List
        self._brownie_semaphore = call.brownie_call_semaphore
        super().__init__(*args, **kwargs)
    
    def stats(self, msg, *args, **kwargs) -> None:
        if self.isEnabledFor(STATS):
            self._ensure_daemon()
            self._log(STATS, msg, args, **kwargs)

    def devhint(self, msg, *args, **kwargs) -> None:
        if self.isEnabledFor(DEVHINT):
            self._log(DEVHINT, msg, args, **kwargs)
            
    def log_duration(self, work_descriptor: str, start: float) -> None:
        duration = time() - start
        self._durations[work_descriptor].append(duration)
        if self.isEnabledFor(STATS):
            self._log(STATS, f"{work_descriptor} took {duration}", ())
            
    def log_validation_error(self, method: RPCEndpoint, e: ValidationError) -> None:
        self._validation_errors[method].append(e)
        if self.isEnabledFor(DEVHINT):
            self._log(DEVHINT, f"ValidationError when decoding response for {method}", ("This *should* not impact your script. If it does, you'll know."), e)

    def log_types(self, method: RPCEndpoint, decoded: Any) -> None:
        types = {type(v) for v in decoded.values()}
        self.devhint(f'my method and types: {method} {types}')
        if list in types:
            self._log_list_types(decoded.values())
        self._types.update(types)

    def log_semaphore_stats(self) -> None:
        self.stats(
            f"{self._brownie_semaphore.default_value - self._brownie_semaphore.semaphore._value} brownie calls are processing, "
            + f"{len(self._brownie_semaphore.semaphore._waiters)} are queued."
        )

    def log_event_loop_stats(self) -> None:
        self.stats(f"Average event loop time: {sum(self._event_loop_times) / len(self._event_loop_times)}")

    def log_subprocess_stats(self) -> None:
        for pool in [call.encoder_processes, call.decoder_processes]:
            self.stats(f"{pool.__name__} has {pool._queue_count} items in its queue")

    def _ensure_daemon(self) -> None:
        if self._daemon is None:
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
            self._event_loop_times.append(duration)
            start = time()
            time_since_notified += duration
            if time_since_notified > 300:
                self.log_subprocess_stats()
                self.log_semaphore_stats()
                self.log_event_loop_stats()
                time_since_notified = 0

    def _log_list_types(self, values) -> None:
        list_types = {type(_) for v in values if isinstance(v, list) for _ in v}
        self._types.update(list_types)
        if self.isEnabledFor(DEVHINT):
            self._log(DEVHINT, f"list types: {list_types}")

logger = StatsLogger(__name__)
log = logger.stats
devhint = logger.devhint
