from typing import Any, Final, final

from dank_mids import ENVIRONMENT_VARIABLES
from dank_mids.logging import get_c_logger


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
demo_logger: Final = (
    get_c_logger("dank_mids.demo") if bool(ENVIRONMENT_VARIABLES.DEMO_MODE) else DummyLogger()
)
