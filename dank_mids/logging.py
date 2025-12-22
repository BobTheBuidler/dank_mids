import io
import logging
import os
import sys
import traceback
from collections.abc import Iterator, Mapping
from contextlib import contextmanager
from types import FrameType
from typing import Any, Final, cast


Level = int
CallerInfo = tuple[str, int, str, str | None]

CRITICAL: Final = logging.CRITICAL
FATAL: Final = logging.FATAL
ERROR: Final = logging.ERROR
WARNING: Final = logging.WARNING
WARN: Final = logging.WARN
INFO: Final = logging.INFO
DEBUG: Final = logging.DEBUG
NOTSET: Final = logging.NOTSET


StringIO: Final = io.StringIO

print_stack: Final = traceback.print_stack

_nameToLevel: Final = logging._nameToLevel
_acquireLock: Final = logging._acquireLock  # type: ignore [attr-defined]
_releaseLock: Final = logging._releaseLock  # type: ignore [attr-defined]
_srcfile: Final = logging._srcfile


@contextmanager
def use_c_logger_class() -> Iterator[None]:
    """Any logger created inside the `with` block will use our faster `CLogger` implementation."""
    logging.setLoggerClass(CLogger)
    yield
    logging.setLoggerClass(logging.Logger)


def get_c_logger(name: str) -> "CLogger":
    with use_c_logger_class():
        return cast(CLogger, logging.getLogger(name))


def _checkLevel(level: Level | str) -> Level:
    if isinstance(level, int):
        rv = level
    elif str(level) == level:
        if level not in _nameToLevel:
            raise ValueError("Unknown level: %r" % level)
        rv = _nameToLevel[level]
    else:
        raise TypeError("Level not an integer or a valid string: %r" % (level,))
    return rv


class CLogger(logging.Logger):
    def __init__(self, name: str, level: Level | str = logging.NOTSET) -> None:
        """
        Initialize the logger with a name and an optional level.
        """
        logging.Filterer.__init__(self)
        self.name: Final = name
        self.level: Level = _checkLevel(level)
        self.parent: logging.Logger | None = None
        self.propagate: bool = True
        self.handlers: list[logging.Handler] = []
        self.disabled: bool = False
        self._cache: Final[dict[Level, bool]] = {}

    def getEffectiveLevel(self) -> int:
        """
        Get the effective level for this logger.

        Loop through this logger and its parents in the logger hierarchy,
        looking for a non-zero logging level. Return the first one found.
        """
        logger: logging.Logger | None

        logger = self
        while logger:
            if logger.level:
                return logger.level
            logger = logger.parent
        return NOTSET

    def isEnabledFor(self, level: Level) -> bool:
        """
        Is this logger enabled for level 'level'?
        """
        if self.disabled:
            return False

        try:
            return self._cache[level]
        except KeyError:
            _acquireLock()
            try:
                if self.manager.disable >= level:
                    is_enabled = self._cache[level] = False
                else:
                    is_enabled = self._cache[level] = level >= self.getEffectiveLevel()
            finally:
                _releaseLock()
            return is_enabled

    def debug(self, msg: object, *args: Any, **kwargs: Any) -> None:
        """
        Log 'msg % args' with severity 'DEBUG'.

        To pass exception information, use the keyword argument exc_info with
        a true value, e.g.

        logger.debug("Houston, we have a %s", "thorny problem", exc_info=1)
        """
        if self.isEnabledFor(DEBUG):
            self._log(DEBUG, msg, args, **kwargs)

    def info(self, msg: object, *args: Any, **kwargs: Any) -> None:
        """
        Log 'msg % args' with severity 'INFO'.

        To pass exception information, use the keyword argument exc_info with
        a true value, e.g.

        logger.info("Houston, we have a %s", "interesting problem", exc_info=1)
        """
        if self.isEnabledFor(INFO):
            self._log(INFO, msg, args, **kwargs)

    def warning(self, msg: object, *args: Any, **kwargs: Any) -> None:
        """
        Log 'msg % args' with severity 'WARNING'.

        To pass exception information, use the keyword argument exc_info with
        a true value, e.g.

        logger.warning("Houston, we have a %s", "bit of a problem", exc_info=1)
        """
        if self.isEnabledFor(WARNING):
            self._log(WARNING, msg, args, **kwargs)

    def error(self, msg: object, *args: Any, **kwargs: Any) -> None:
        """
        Log 'msg % args' with severity 'ERROR'.

        To pass exception information, use the keyword argument exc_info with
        a true value, e.g.

        logger.error("Houston, we have a %s", "major problem", exc_info=1)
        """
        if self.isEnabledFor(ERROR):
            self._log(ERROR, msg, args, **kwargs)

    def exception(
        self,
        msg: object,
        *args: Any,
        exc_info: logging._ExcInfoType = True,
        **kwargs: Any,
    ) -> None:
        """
        Convenience method for logging an ERROR with exception information.
        """
        self.error(msg, *args, exc_info=exc_info, **kwargs)

    def critical(self, msg: object, *args: Any, **kwargs: Any) -> None:
        """
        Log 'msg % args' with severity 'CRITICAL'.

        To pass exception information, use the keyword argument exc_info with
        a true value, e.g.

        logger.critical("Houston, we have a %s", "major disaster", exc_info=1)
        """
        if self.isEnabledFor(CRITICAL):
            self._log(CRITICAL, msg, args, **kwargs)

    def fatal(self, msg: object, *args: Any, **kwargs: Any) -> None:
        """
        Don't use this method, use critical() instead.
        """
        self.critical(msg, *args, **kwargs)

    def log(self, level: Level, msg: object, *args: Any, **kwargs: Any) -> None:
        """
        Log 'msg % args' with the integer severity 'level'.

        To pass exception information, use the keyword argument exc_info with
        a true value, e.g.

        logger.log(level, "We have a %s", "mysterious problem", exc_info=1)
        """
        if self.isEnabledFor(level):
            self._log(level, msg, args, **kwargs)

    def findCaller(self, stack_info: bool = False, stacklevel: int = 1) -> CallerInfo:
        """
        Find the stack frame of the caller so that we can note the source
        file name, line number and function name.
        """
        f: FrameType | None
        rv: CallerInfo

        f = logging.currentframe()
        # On some versions of IronPython, currentframe() returns None if
        # IronPython isn't run with -X:Frames.
        if f is not None:
            f = f.f_back
        orig_f = cast(FrameType, f)
        while f and stacklevel > 1:
            f = f.f_back
            stacklevel -= 1
        if not f:
            f = orig_f
        rv = "(unknown file)", 0, "(unknown function)", None
        while hasattr(f, "f_code"):
            frame = cast(FrameType, f)
            co = frame.f_code
            co_filename = co.co_filename
            filename = os.path.normcase(co_filename)
            if filename == _srcfile:
                f = frame.f_back
                continue
            sinfo = None
            if stack_info:
                sio = StringIO()
                sio.write("Stack (most recent call last):\n")
                print_stack(frame, file=sio)
                sinfo = sio.getvalue()
                if sinfo[-1] == "\n":
                    sinfo = sinfo[:-1]
                sio.close()
            rv = (co_filename, cast(int, frame.f_lineno), co.co_name, sinfo)
            break
        return rv

    def makeRecord(
        self,
        name: str,
        level: Level,
        fn: str,
        lno: int,
        msg: object,
        args: logging._ArgsType,
        exc_info: logging._SysExcInfoType | None,
        func: str | None = None,
        extra: Mapping[str, object] | None = None,
        sinfo: str | None = None,
    ) -> logging.LogRecord:
        """
        A factory method which can be overridden in subclasses to create
        specialized LogRecords.
        """
        # TODO: set a C-based LogRecord to the logging module, dont use it here
        rv = logging._logRecordFactory(  # type: ignore [attr-defined]
            name, level, fn, lno, msg, args, exc_info, func, sinfo
        )
        if extra is not None:
            for key in extra:
                if (key in ["message", "asctime"]) or (key in rv.__dict__):
                    raise KeyError("Attempt to overwrite %r in LogRecord" % key)
                rv.__dict__[key] = extra[key]
        return rv  # type: ignore [no-any-return]

    def _log(
        self,
        level: Level,
        msg: object,
        args: logging._ArgsType,
        exc_info: logging._ExcInfoType = None,
        extra: Mapping[str, object] | None = None,
        stack_info: bool = False,
        stacklevel: int = 1,
    ) -> None:
        """
        Low-level logging routine which creates a LogRecord and then calls
        all the handlers of this logger to handle the record.
        """
        sinfo = None
        if _srcfile:
            # IronPython doesn't track Python frames, so findCaller raises an
            # exception on some versions of IronPython. We trap it here so that
            # IronPython can use logging.
            try:
                fn, lno, func, sinfo = self.findCaller(stack_info, stacklevel)
            except ValueError:  # pragma: no cover
                fn, lno, func = "(unknown file)", 0, "(unknown function)"
        else:  # pragma: no cover
            fn, lno, func = "(unknown file)", 0, "(unknown function)"
        if exc_info:
            if isinstance(exc_info, BaseException):
                exc_info = (type(exc_info), exc_info, exc_info.__traceback__)
            elif not isinstance(exc_info, tuple):
                exc_info = sys.exc_info()
        record = self.makeRecord(
            self.name,
            level,
            fn,
            lno,
            msg,
            args,
            cast(logging._SysExcInfoType | None, exc_info),
            func,
            extra,
            sinfo,
        )
        self.handle(record)
