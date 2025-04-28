import logging
from typing import Final, Optional

def getLogger(name: Optional[str]) -> logging.Logger: ...

CRITICAL: Final = logging.CRITICAL
FATAL: Final = logging.FATAL
ERROR: Final = logging.ERROR
WARN: Final = logging.WARN
WARNING: Final = logging.WARNING
INFO: Final = logging.INFO
DEBUG: Final = logging.DEBUG
NOTSET: Final = logging.NOTSET
