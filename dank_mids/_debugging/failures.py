
from datetime import datetime
from functools import cached_property, lru_cache

from a_sync import ProcessingQueue

from dank_mids._debugging._base import _CSVWriter

@lru_cache(maxsize=None)
class FailedRequestWriter(_CSVWriter):
    def __init__(self, chainid: int):
        super().__init__()
        self.chainid = chainid
        self.record_failure = ProcessingQueue(self._record_failure, num_workers=1, return_data=True)
    @cached_property
    def filename(self) -> str:
        return f"/{self.chainid}_{int(datetime.now().timestamp())}_failed_requests.csv"
    async def _record_failure(self, e: Exception, request_data: bytes):
        row = type(e).__name__, str(e), request_data.hex()
        await self.write_row(','.join(row))

def record(chainid: int, e: Exception, request_data: bytes) -> None:
    return FailedRequestWriter(chainid).record_failure(e, request_data)
