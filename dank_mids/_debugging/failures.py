
from datetime import datetime
from functools import cached_property, lru_cache
from typing import TYPE_CHECKING, List, Type, Union

from a_sync import ProcessingQueue

from dank_mids._debugging._base import _CSVWriter

if TYPE_CHECKING:
    from dank_mids.types import PartialRequest, Request

@lru_cache(maxsize=None)
class FailedRequestWriter(_CSVWriter):
    column_names = "request_type", "request_uid", "error", "request_data"
    def __init__(self, chainid: int, failure_type: Type[BaseException]):
        super().__init__(chainid)
        if not issubclass(failure_type, BaseException):
            raise TypeError(f"`failure_type` must be an Exception type. You passed {failure_type}")
        self.failure_type = failure_type
        self.record_failure = ProcessingQueue(self._record_failure, num_workers=1, return_data=True)
    @cached_property
    def filename(self) -> str:
        return f"{int(datetime.now().timestamp())}_{self.failure_type.__name__}s.csv"
    async def _record_failure(self, e: Exception, request_type: str, request_uid: Union[str, int], request_data: Union[List["Request"], List["PartialRequest"], bytes]):
        if not isinstance(e, self.failure_type):
            raise TypeError(e, self.failure_type)
        await self.write_row(request_type, request_uid, e, request_data)

def record(chainid: int, e: Exception, request_type: str, request_uid: Union[int, str], request_data: Union[List["Request"], List["PartialRequest"], bytes]) -> None:
    FailedRequestWriter(chainid, type(e)).record_failure(e, request_type, request_uid, request_data)
