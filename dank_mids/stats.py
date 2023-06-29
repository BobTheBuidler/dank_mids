
import logging
from collections import defaultdict
from time import time
from typing import TYPE_CHECKING, Any, DefaultDict, List, Set, Type

from msgspec import ValidationError
from web3.types import RPCEndpoint

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
        super().__init__(*args, **kwargs)
    @property
    def time(self) -> float:
        return time()
    def stats(self, msg, *args, **kwargs) -> None:
        if self.isEnabledFor(STATS):
            self.debug
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
            self._log(DEVHINT, f"ValidationError when decoding response for {method}", "This *should* not impact your script. If it does, you'll know.", e)
    def log_types(self, method: RPCEndpoint, decoded: Any) -> None:
        types = {type(v) for v in decoded.values()}
        self.devhint(f'my method and types: {method} {types}')
        if list in types:
            self._log_list_types(decoded.values())
        self._types.update(types)
    def _log_list_types(self, values) -> None:
        list_types = {type(_) for v in values if isinstance(v, list) for _ in v}
        self._types.update(list_types)
        if self.isEnabledFor(DEVHINT):
            self._log(DEVHINT, f"list types: {list_types}")

logger = StatsLogger(__name__)