import logging
import re
from typing import TYPE_CHECKING, List, Union

from aiohttp.client_exceptions import ClientResponseError

if TYPE_CHECKING:
    from dank_mids._requests import RPCRequest
    from dank_mids.controller import DankMiddlewareController
    from dank_mids.types import PartialRequest, PartialResponse, RawResponse, Response


logger = logging.getLogger("dank_mids.exceptions")


class BadResponse(ValueError):
    """Exception raised when an unexpected or invalid response is received."""

    def __init__(self, response: "PartialResponse") -> None:
        self.response = response
        super().__init__(response.to_dict())


class EmptyBatch(ValueError):
    """Exception raised when attempting to process an empty batch."""


class OutOfGas(BadResponse):
    """Exception raised when an eth_call request runs out of gas."""


class PayloadTooLarge(BadResponse):
    """Exception raised when the payload for a request is too large."""


class ExceedsMaxBatchSize(BadResponse):
    """Exception raised when a batch operation exceeds the maximum allowed size for the RPC."""

    @property
    def limit(self) -> int:
        """Get the maximum allowed batch size from the error message."""
        return int(re.search(r"batch limit (\d+) exceeded", self.response.error.message)[1])  # type: ignore [index, union-attr]


class DankMidsClientResponseError(ClientResponseError):
    """A wrapper around the standard aiohttp ClientResponseError that attaches the request that generated the error."""

    def __init__(
        self,
        exc: ClientResponseError,
        request: "PartialRequest",
    ) -> None:
        self.request = request
        """
        The PartialRequest object associated with this error.
        It contains information about the request that led to this error.
        """

        super().__init__(
            exc.request_info,
            exc.history,
            status=exc.status,
            message=exc.message,
            headers=exc.headers,
        )
        self.args = (*self.args, request)  # type: ignore [has-type]

        self._exception = exc
        """
        The original ClientResponseError that this class is wrapping.
        It contains the underlying error information from aiohttp.
        """


internal_err_types = Union[
    AttributeError, TypeError, UnboundLocalError, NotImplementedError, RuntimeError, SyntaxError
]


class DankMidsInternalError(Exception):
    """Exception raised for unhandled internal errors within Dank Mids."""

    def __init__(self, e: Union[ValueError, internal_err_types]) -> None:
        logger.warning(f"unhandled exception inside dank mids internals: {e}", exc_info=True)

        self._original_exception = e
        """
        The original exception that was caught and wrapped by this DankMidsInternalError.
        This attribute allows access to the underlying error for debugging purposes.
        """

        super().__init__(e.__repr__())


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
        self.calls = calls
        """
        A list of RPCRequest objects representing the calls that were made in the batch.
        This can be used to analyze which calls were included in the problematic batch.
        """

        self.results = [raw.decode() for raw in response]
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


class ChainstackRateLimited(BadResponse):
    """
    Exception raised when Chainstack hits a rate limit without using a 429 status code.
    Chainstack sends a 200 status code with an error message for rate limiting.
    Requires bespoke logic for handling this case.
    """

    @property
    def try_again_in(self) -> float:
        """
        Calculates the time to wait before retrying the request.

        Returns:
            The number of seconds to wait before retrying.

        Raises:
            NotImplementedError: If the time format is not recognized.
        """
        decimal_string = self.response.error.data["try_again_in"]
        if "ms" in decimal_string:
            ms = float(decimal_string[:-2])
            logger.warning("rate limited by chainstack, retrying in %sms", ms)
            return ms / 1000
        elif "µs" in decimal_string:
            µs = float(decimal_string[:-2])
            logger.warning("rate limited by chainstack, retrying in %sµs", µs)
            return µs / 1000000
        raise NotImplementedError(f"must define a handler for decimal_string {decimal_string}")
