from __future__ import annotations

import importlib.machinery
import logging
import sys
import traceback
from collections.abc import Callable, Iterator
from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import pytest

from dank_mids import logging as dank_logging
from dank_mids.logging import CLogger, get_c_logger

CallerInfo = tuple[str, int, str, str | None]

PUBLIC_LOGGER_METHOD_AREAS = {
    "addFilter": "handlers_filters",
    "addHandler": "handlers_filters",
    "callHandlers": "handlers_filters",
    "critical": "emission",
    "debug": "emission",
    "error": "emission",
    "exception": "emission",
    "fatal": "emission",
    "filter": "handlers_filters",
    "findCaller": "caller",
    "getChild": "hierarchy",
    "getChildren": "hierarchy",
    "getEffectiveLevel": "state",
    "handle": "handlers_filters",
    "hasHandlers": "handlers_filters",
    "info": "emission",
    "isEnabledFor": "state",
    "log": "emission",
    "makeRecord": "records",
    "removeFilter": "handlers_filters",
    "removeHandler": "handlers_filters",
    "setLevel": "state",
    "warn": "emission",
    "warning": "emission",
}

CLOGGER_DEFINED_CALLABLE_AREAS = {
    "__init__": "constructor_setup_only",
    "_log": "emission",
    "critical": "emission",
    "debug": "emission",
    "error": "emission",
    "exception": "emission",
    "fatal": "emission",
    "findCaller": "caller",
    "getEffectiveLevel": "state",
    "info": "emission",
    "isEnabledFor": "state",
    "log": "emission",
    "makeRecord": "records",
    "warning": "emission",
}

FAST_LEVEL_DIVERGENCE = (
    "CLogger level inputs intentionally stay narrower than stdlib logging "
    "to preserve tight mypyc-generated C for hot logging paths"
)

LOGGER_NAME_PREFIX = "dank_mids.tests.logging"


class _ListHandler(logging.Handler):
    def __init__(self) -> None:
        super().__init__()
        self.records: list[logging.LogRecord] = []

    def emit(self, record: logging.LogRecord) -> None:
        self.records.append(record)


@dataclass
class _LoggerPair:
    c_logger: CLogger
    stdlib_logger: logging.Logger
    c_handler: _ListHandler
    stdlib_handler: _ListHandler


@pytest.fixture(autouse=True)
def _restore_logging_global_state() -> Iterator[None]:
    previous_logger_class = logging.getLoggerClass()
    previous_record_factory = logging.getLogRecordFactory()
    previous_disable = logging.root.manager.disable
    managed_loggers = logging.Logger.manager.loggerDict
    previous_test_loggers = {
        name: logger
        for name, logger in managed_loggers.items()
        if name.startswith(LOGGER_NAME_PREFIX)
    }

    yield

    logging.setLoggerClass(previous_logger_class)
    logging.setLogRecordFactory(previous_record_factory)
    logging.disable(previous_disable)
    for name in list(managed_loggers):
        if name.startswith(LOGGER_NAME_PREFIX):
            del managed_loggers[name]
    managed_loggers.update(previous_test_loggers)


def _new_logger_pair(level: int = logging.DEBUG) -> _LoggerPair:
    c_handler = _ListHandler()
    stdlib_handler = _ListHandler()
    c_logger = CLogger(f"{LOGGER_NAME_PREFIX}.parity", level)
    stdlib_logger = logging.Logger(f"{LOGGER_NAME_PREFIX}.parity", level)

    for logger, handler in (
        (c_logger, c_handler),
        (stdlib_logger, stdlib_handler),
    ):
        logger.handlers[:] = [handler]
        logger.propagate = False
        logger.disabled = False

    return _LoggerPair(c_logger, stdlib_logger, c_handler, stdlib_handler)


@contextmanager
def _frozen_logging_time(monkeypatch: pytest.MonkeyPatch) -> Iterator[None]:
    timestamp_seconds = 1_700_000_000.123
    start_seconds = 1_699_999_990.0
    monkeypatch.setattr(logging.time, "time", lambda: timestamp_seconds)
    if sys.version_info >= (3, 13):
        monkeypatch.setattr(logging.time, "time_ns", lambda: 1_700_000_000_123_000_000)
        monkeypatch.setattr(logging, "_startTime", 1_699_999_990_000_000_000)
    else:
        monkeypatch.setattr(logging, "_startTime", start_seconds)
    yield


@contextmanager
def _log_record_factory(factory: Callable[..., logging.LogRecord]) -> Iterator[None]:
    previous = logging.getLogRecordFactory()
    logging.setLogRecordFactory(factory)
    try:
        yield
    finally:
        logging.setLogRecordFactory(previous)


def _capture_exception(call: Callable[[], object]) -> BaseException | None:
    try:
        call()
    except BaseException as exc:
        return exc
    return None


def _assert_exception_parity(
    c_exc: BaseException | None,
    stdlib_exc: BaseException | None,
) -> None:
    if stdlib_exc is None:
        assert c_exc is None
        return
    assert c_exc is not None
    assert type(c_exc) is type(stdlib_exc)
    assert c_exc.args == stdlib_exc.args


def _assert_fast_level_type_divergence(call: Callable[[], object]) -> None:
    exc = _capture_exception(call)
    assert type(exc) is TypeError, FAST_LEVEL_DIVERGENCE


def _record_values(record: logging.LogRecord) -> dict[str, Any]:
    return dict(record.__dict__)


def _assert_record_parity(
    c_record: logging.LogRecord,
    stdlib_record: logging.LogRecord,
) -> None:
    assert type(c_record) is type(stdlib_record)
    assert _record_values(c_record) == _record_values(stdlib_record)
    assert c_record.getMessage() == stdlib_record.getMessage()


def _assert_handler_parity(pair: _LoggerPair) -> None:
    assert len(pair.c_handler.records) == len(pair.stdlib_handler.records)
    for c_record, stdlib_record in zip(
        pair.c_handler.records,
        pair.stdlib_handler.records,
    ):
        _assert_record_parity(c_record, stdlib_record)


def _leaf_find_caller(
    logger: logging.Logger,
    stacklevel: int,
    *,
    stack_info: bool = False,
) -> CallerInfo:
    return logger.findCaller(stack_info=stack_info, stacklevel=stacklevel)


def _middle_find_caller(
    logger: logging.Logger,
    stacklevel: int,
    *,
    stack_info: bool = False,
) -> CallerInfo:
    return _leaf_find_caller(logger, stacklevel, stack_info=stack_info)


def _caller_pair(
    stacklevel: int,
    *,
    stack_info: bool = False,
) -> tuple[CallerInfo, CallerInfo]:
    pair = _new_logger_pair()
    # Keep both calls on one physical line so exact line-number parity is meaningful.
    c_caller = _middle_find_caller(pair.c_logger, stacklevel, stack_info=stack_info); stdlib_caller = _middle_find_caller(pair.stdlib_logger, stacklevel, stack_info=stack_info)  # noqa: E702
    return c_caller, stdlib_caller


def _find_caller_with_stack_info() -> str:
    logger = get_c_logger(f"{LOGGER_NAME_PREFIX}.stack_info")
    _filename, _line, _function, stack_info = logger.findCaller(stack_info=True)
    assert stack_info is not None
    return stack_info


def _emit_pair(
    pair: _LoggerPair,
    method_name: str,
    *args: Any,
    **kwargs: Any,
) -> None:
    # Keep both calls on one physical line so exact emitted record parity includes lineno.
    getattr(pair.c_logger, method_name)(*args, **kwargs); getattr(pair.stdlib_logger, method_name)(*args, **kwargs)  # noqa: E702


def _fake_compiled_logging_path() -> str:
    suffix = importlib.machinery.EXTENSION_SUFFIXES[0]
    return str(Path(dank_logging.__file__).with_name(f"logging{suffix}"))


def _find_caller_through_internal_logging_frame(
    logger: logging.Logger,
) -> CallerInfo:
    namespace = {"logger": logger}
    code = compile(
        "def compiled_logging_wrapper():\n"
        "    return logger.findCaller()\n",
        _fake_compiled_logging_path()
        if isinstance(logger, CLogger)
        else logging._srcfile,
        "exec",
    )
    exec(code, namespace)
    return namespace["compiled_logging_wrapper"]()


def _compiled_frame_caller_pair() -> tuple[CallerInfo, CallerInfo]:
    c_logger = get_c_logger(f"{LOGGER_NAME_PREFIX}.compiled_frame")
    stdlib_logger = logging.Logger(f"{LOGGER_NAME_PREFIX}.stdlib_compiled_frame")
    # Keep both calls on one physical line so exact line-number parity is meaningful.
    c_caller = _find_caller_through_internal_logging_frame(c_logger); stdlib_caller = _find_caller_through_internal_logging_frame(stdlib_logger)  # noqa: E702
    return c_caller, stdlib_caller


def _make_record(
    logger: logging.Logger,
    *,
    extra: dict[str, object] | None = None,
) -> logging.LogRecord:
    return logger.makeRecord(
        logger.name,
        logging.WARNING,
        __file__,
        123,
        "hello %s",
        ("world",),
        None,
        "parity_func",
        extra,
        "stack text",
    )


def _make_record_pair(
    pair: _LoggerPair,
    *,
    extra: dict[str, object] | None = None,
) -> tuple[logging.LogRecord, logging.LogRecord]:
    return _make_record(pair.c_logger, extra=extra), _make_record(
        pair.stdlib_logger,
        extra=extra,
    )


@pytest.fixture
def list_handler_type() -> type[_ListHandler]:
    return _ListHandler


@pytest.fixture
def new_logger_pair() -> Callable[[int], _LoggerPair]:
    return _new_logger_pair


@pytest.fixture
def frozen_logging_time(
    monkeypatch: pytest.MonkeyPatch,
) -> Callable[[], Iterator[None]]:
    return lambda: _frozen_logging_time(monkeypatch)


@pytest.fixture
def log_record_factory() -> Callable[[Callable[..., logging.LogRecord]], Iterator[None]]:
    return _log_record_factory


@pytest.fixture
def capture_exception() -> Callable[[Callable[[], object]], BaseException | None]:
    return _capture_exception


@pytest.fixture
def assert_exception_parity() -> Callable[[BaseException | None, BaseException | None], None]:
    return _assert_exception_parity


@pytest.fixture
def assert_fast_level_type_divergence() -> Callable[[Callable[[], object]], None]:
    return _assert_fast_level_type_divergence


@pytest.fixture
def assert_record_parity() -> Callable[[logging.LogRecord, logging.LogRecord], None]:
    return _assert_record_parity


@pytest.fixture
def assert_handler_parity() -> Callable[[_LoggerPair], None]:
    return _assert_handler_parity


@pytest.fixture
def caller_pair() -> Callable[[int], tuple[CallerInfo, CallerInfo]]:
    return _caller_pair


@pytest.fixture
def find_caller_with_stack_info() -> Callable[[], str]:
    return _find_caller_with_stack_info


@pytest.fixture
def emit_pair() -> Callable[..., None]:
    return _emit_pair


@pytest.fixture
def fake_compiled_logging_path() -> Callable[[], str]:
    return _fake_compiled_logging_path


@pytest.fixture
def compiled_frame_caller_pair() -> Callable[[], tuple[CallerInfo, CallerInfo]]:
    return _compiled_frame_caller_pair


@pytest.fixture
def make_record() -> Callable[..., logging.LogRecord]:
    return _make_record


@pytest.fixture
def make_record_pair() -> Callable[..., tuple[logging.LogRecord, logging.LogRecord]]:
    return _make_record_pair


@pytest.fixture
def public_logger_method_areas() -> dict[str, str]:
    return PUBLIC_LOGGER_METHOD_AREAS


@pytest.fixture
def clogger_defined_callable_areas() -> dict[str, str]:
    return CLOGGER_DEFINED_CALLABLE_AREAS


@pytest.fixture
def logger_name_prefix() -> str:
    return LOGGER_NAME_PREFIX


@pytest.fixture
def format_stack() -> Callable[..., list[str]]:
    return traceback.format_stack
