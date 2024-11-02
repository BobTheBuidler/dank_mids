import logging
from typing import Any

from dank_mids import ENVIRONMENT_VARIABLES


class DummyLogger:
    """
    A dummy logger class that mimics the interface of logging.Logger but does nothing.

    This class is used to replace the actual logger when demo mode is not active,
    saving processing time by avoiding unnecessary logging operations.
    """

    def info(self, *args: Any, **kwargs: Any) -> None:
        """
        A no-op method that mimics the API of :meth:`logging.Logger.info`.

        Args:
            *args: Positional arguments (ignored).
            **kwargs: Keyword arguments (ignored).
        """

# Choose between a real logger and a dummy logger based on the demo mode setting
demo_logger: logging.Logger = logging.getLogger("dank_mids.demo") if ENVIRONMENT_VARIABLES.DEMO_MODE else DummyLogger()  # type: ignore [attr-defined, assignment]
