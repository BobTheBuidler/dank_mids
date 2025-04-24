from logging import Logger, getLogger
from typing import Any, Final, final

from dank_mids import ENVIRONMENT_VARIABLES


@final
class DummyLogger:
    """
    A dummy logger class that provides a no-op implementation of the info
    method of logging.Logger.

    This class is used to replace the actual logger when demo mode is not
    enabled, saving processing time by avoiding unnecessary logging operations.
    """
    
    @staticmethod
    def info(*args: Any, **kwargs: Any) -> None:
        """
        Does nothing. Mimics the API of logging.Logger.info by accepting
        any arguments.

        Args:
            *args: Positional arguments (ignored).
            **kwargs: Keyword arguments (ignored).
        """


# Choose between a real logger and a dummy logger based on the demo mode setting
if ENVIRONMENT_VARIABLES.DEMO_MODE:  # type: ignore [has-type]
    _logger = getLogger("dank_mids.demo")
else:
    _logger = DummyLogger()  # type: ignore [assignment]

demo_logger: Final = _logger
