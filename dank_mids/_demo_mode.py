import logging
from typing import Any

from dank_mids import ENVIRONMENT_VARIABLES


class DummyLogger:
    """ Replace a `logging.Logger` object with a dummy to save precious time """
    def info(self, *args: Any, **kwargs: Any) -> None:
        ...

demo_logger: logging.Logger = logging.getLogger("dank_mids.demo") if ENVIRONMENT_VARIABLES.DEMO_MODE else DummyLogger()  # type: ignore [attr-defined, assignment]
