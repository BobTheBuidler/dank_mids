import logging
import re
from typing import TYPE_CHECKING, Final, List, Union, final

from aiohttp.client_exceptions import ClientResponseError

if TYPE_CHECKING:
    from dank_mids._requests import RPCRequest
    from dank_mids.controller import DankMiddlewareController
    from dank_mids.types import PartialRequest, PartialResponse, RawResponse


logger: Final = logging.getLogger("dank_mids.exceptions")


class BadResponse(ValueError):
    """Exception raised when an unexpected or invalid response is received."""

    def __init__(self, response: "PartialResponse") -> None:
        self.response = response
        BaseException.__init__(self, response.error.to_dict())  # type: ignore [union-attr]


@final
class EmptyBatch(ValueError):
    """Exception raised when attempting to process an empty batch."""


@final
class ExecutionReverted(BadResponse):
    """Exception raised when the EVM reverts."""

    def __init__(self, response: "PartialResponse") -> None:
        self.response = response
        message: str = response.error.message  # type: ignore [union-attr]
        if message.count(":") == 1:
            message = message.split(":")[1]
        BaseException.__init__(self, message)


@final
class OutOfGas(BadResponse):
    """Exception raised when an eth_call request runs out of gas."""


@final
class PayloadTooLarge(BadResponse):
    """Exception raised when the payload for a request is too large."""


@final
class ExceedsMaxBatchSize(BadResponse):
    """Exception raised when a batch operation exceeds the maximum allowed size for the RPC."""

    @property
    def limit(self) -> int:
        """Get the maximum allowed batch size from the error message."""
        return int(re.search(r"batch limit (\d+) exceeded", self.response.error.message)[1])  # type: ignore [index, union-attr]


@final
class DankMidsClientResponseError(ClientResponseError):  # type: ignore [misc]
    """A wrapper around the standard aiohttp ClientResponseError that attaches the request that generated the error."""

    def __init__(
        self,
        exc: ClientResponseError,
        request: "PartialRequest",
    ) -> None:
        self.request: Final = request
        """
        The PartialRequest object associated with this error.
        It contains information about the request that led to this error.
        """

        self.args = (*self.args, request)  # type: ignore [has-type]

        self._exception: Final = exc
        """
        The original ClientResponseError that this class is wrapping.
        It contains the underlying error information from aiohttp.
        """

        super().__init__(
            exc.request_info,
            exc.history,
            status=exc.status,
            message=exc.message,
            headers=exc.headers,
        )


_internal_err_types = Union[
    AttributeError, TypeError, UnboundLocalError, NotImplementedError, RuntimeError, SyntaxError
]
internal_err_types: Final = _internal_err_types


class DankMidsInternalError(Exception):
    """Exception raised for unhandled internal errors within Dank Mids."""

    def __init__(self, exc: Union[ValueError, _internal_err_types]) -> None:
        logger.warning(f"unhandled exception inside dank mids internals: {exc}", exc_info=True)

        self._original_exception: Final = exc
        """
        The original exception that was caught and wrapped by this DankMidsInternalError.
        This attribute allows access to the underlying error for debugging purposes.
        """

        super().__init__(repr(exc))


@final
class BatchResponseSortError(Exception):
    """
    Exception raised when there is an issue with sorting batch responses.
    Indicates special handling is needed for batch calls/responses in your RPC.
    """

    def __init__(
        self,
        controller: "DankMiddlewareController",
        calls: List["RPCRequest"],
        response: List["RawResponse"],
    ) -> None:
        self.calls: Final = calls
        """
        A list of RPCRequest objects representing the calls that were made in the batch.
        This can be used to analyze which calls were included in the problematic batch.
        """

        self.results: Final = [raw.decode() for raw in response]
        """
        A list of Response objects representing the decoded results from the RPC call.
        This can be used to analyze the responses that couldn't be properly sorted.
        """

        super().__init__(
            f"This will not mess up your run but will make things needlessly slow. Please show this to Bob.\n"
            f"endpoint={controller.endpoint}\n"
            f"client_version={controller.client_version}\n"
            f"calls={[call.uid for call in calls]}\n"
            f"response={self.results}"
        )


class RateLimitError(BadResponse): ...


@final
class ChainstackRateLimitError(RateLimitError):
    """
    Exception raised when Chainstack hits a rate limit without using a 429 status code.
    Chainstack sends a 200 status code with an error message for rate limiting.
    Requires bespoke logic for handling this case.
    """

    @property
    def try_again_in(self) -> float:
        """
        Parses the response to determine the time to wait before retrying the request.

        Returns:
            The number of seconds to wait before retrying.
        """
        return self.response.error.data.try_again_in  # type: ignore [union-attr]


@final
class QuiknodeRateLimitError(RateLimitError): ...
