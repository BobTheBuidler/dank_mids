from datetime import datetime
from typing import TYPE_CHECKING, List, Literal, Type, Union

from a_sync import ProcessingQueue
from a_sync.functools import cached_property_unsafe as cached_property

from dank_mids._debugging._base import _CSVWriter
from dank_mids.helpers.lru_cache import lru_cache_lite_nonull

if TYPE_CHECKING:
    from dank_mids.types import PartialRequest, Request


@lru_cache_lite_nonull
class FailedRequestWriter(_CSVWriter):
    """
    A class for logging failed requests to a CSV file.

    This class provides functionality to record details of failed requests,
    including the request type, unique identifier, length, error, and request data.

    Usage:
        writer = FailedRequestWriter(1, Exception)
        await writer.record_failure.put((error, "request_type", "request_uid", 10, request_data))
    """

    column_names = "request_type", "request_uid", "request_length", "error", "request_data"
    """The names of the columns in the CSV file."""

    def __init__(self, chainid: int, failure_type: Type[BaseException]) -> None:
        """
        Initialize the FailedRequestWriter.

        Args:
            chainid: The ID of the blockchain network.
            failure_type: The type of exception to record.

        Raises:
            TypeError: If chainid is not an integer or failure_type is not a subclass of BaseException.
        """
        super().__init__(chainid)
        if not issubclass(failure_type, BaseException):
            raise TypeError(f"`failure_type` must be an Exception type. You passed {failure_type}")

        self.failure_type = failure_type
        """The type of exception to record."""

        self.record_failure = ProcessingQueue(
            self._record_failure, num_workers=1, return_data=False
        )
        """
        A ProcessingQueue instance used to record failed requests asynchronously.
        It processes failures using the :meth:`FailedRequestWriter._record_failure` method with a single worker.
        """

    @cached_property
    def filename(self) -> str:
        """Generate a unique filename for the CSV file, then cache it for subsequent use."""
        return f"{int(datetime.now().timestamp())}_{self.failure_type.__name__}s.csv"

    async def _record_failure(
        self,
        e: Exception,
        request_type: str,
        request_uid: Union[str, int],
        request_length: Union[int, Literal["unknown"]],
        request_data: Union[List["Request"], List["PartialRequest"], bytes],
    ) -> None:
        """
        Record a failed request to the CSV file.

        Args:
            e: The exception that occurred.
            request_type: The type of the request.
            request_uid: The unique identifier of the request.
            request_length: The length of the request.
            request_data: The request data.

        Raises:
            TypeError: If the exception is not of the specified failure_type.
        """
        if not isinstance(e, self.failure_type):
            raise TypeError(e, self.failure_type)
        await self.write_row(request_type, request_uid, request_length, e, request_data)


def record(
    chainid: int,
    e: Exception,
    request_type: str,
    request_uid: Union[int, str],
    request_length: Union[int, Literal["unknown"]],
    request_data: Union[List["Request"], List["PartialRequest"], bytes],
) -> None:
    """
    Record a failed request using a new FailedRequestWriter instance.

    Args:
        chainid: The ID of the blockchain network.
        e: The exception that occurred.
        request_type: The type of the request.
        request_uid: The unique identifier of the request.
        request_length: The length of the request.
        request_data: The request data.
    """
    FailedRequestWriter(chainid, type(e)).record_failure(
        e, request_type, request_uid, request_length, request_data
    )
