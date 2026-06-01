import importlib.machinery
import logging
import sys
from collections.abc import Callable, Iterator
from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import pytest

from dank_mids import logging as dank_logging
from dank_mids.logging import CLogger, get_c_logger

CallerInfo = tuple[str, int, str, str | None]

_PARITY_COVERED_CLOGGER_METHODS = {
    "__init__",
    "_log",
    "critical",
    "debug",
    "error",
    "exception",
    "fatal",
    "findCaller",
    "getEffectiveLevel",
    "info",
    "isEnabledFor",
    "log",
    "makeRecord",
    "warning",
}

_FAST_LEVEL_DIVERGENCE = (
    "CLogger level inputs intentionally stay narrower than stdlib logging "
    "to preserve tight mypyc-generated C for hot logging paths"
)


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


def _new_logger_pair(level: int = logging.DEBUG) -> _LoggerPair:
    c_handler = _ListHandler()
    stdlib_handler = _ListHandler()
    c_logger = CLogger("dank_mids.tests.logging.parity", level)
    stdlib_logger = logging.Logger("dank_mids.tests.logging.parity", level)

    for logger, handler in (
        (c_logger, c_handler),
        (stdlib_logger, stdlib_handler),
    ):
        logger.handlers[:] = [handler]
        logger.propagate = False
        logger.disabled = False

    return _LoggerPair(c_logger, stdlib_logger, c_handler, stdlib_handler)


@contextmanager
def _frozen_logging_time(
    monkeypatch: pytest.MonkeyPatch,
) -> Iterator[None]:
    monkeypatch.setattr(logging.time, "time", lambda: 1_700_000_000.123)
    monkeypatch.setattr(logging, "_startTime", 1_699_999_990.0)
    yield


@contextmanager
def _log_record_factory(
    factory: Callable[..., logging.LogRecord],
) -> Iterator[None]:
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
    assert type(exc) is TypeError, _FAST_LEVEL_DIVERGENCE


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


def _logger_init_values(logger: logging.Logger) -> dict[str, object]:
    return {
        "name": logger.name,
        "level": logger.level,
        "parent": logger.parent,
        "propagate": logger.propagate,
        "handlers": logger.handlers,
        "disabled": logger.disabled,
        "filters": logger.filters,
        "_cache": logger._cache,
    }


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
    logger = get_c_logger("dank_mids.tests.logging")
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


def test_module_constants_match_stdlib_logging() -> None:
    for name in (
        "CRITICAL",
        "FATAL",
        "ERROR",
        "WARNING",
        "WARN",
        "INFO",
        "DEBUG",
        "NOTSET",
    ):
        assert getattr(dank_logging, name) == getattr(logging, name)


def test_vendored_c_logger_methods_have_parity_coverage() -> None:
    vendored_methods = {
        name
        for name, value in CLogger.__dict__.items()
        if callable(value) and (name == "__init__" or not name.startswith("__"))
    }

    assert vendored_methods == _PARITY_COVERED_CLOGGER_METHODS


@pytest.mark.parametrize("level", [logging.INFO, "INFO", "NOPE"])
def test_check_level_matches_stdlib(level: int | str) -> None:
    c_exc = _capture_exception(lambda: dank_logging._checkLevel(level))
    stdlib_exc = _capture_exception(lambda: logging._checkLevel(level))

    _assert_exception_parity(c_exc, stdlib_exc)
    if c_exc is None:
        assert dank_logging._checkLevel(level) == logging._checkLevel(level)


@pytest.mark.parametrize(
    "level",
    [logging.NOTSET, logging.INFO, "INFO", "NOPE"],
)
def test_c_logger_init_matches_stdlib(level: int | str) -> None:
    c_exc = _capture_exception(lambda: CLogger("dank_mids.tests.logging.init", level))
    stdlib_exc = _capture_exception(
        lambda: logging.Logger("dank_mids.tests.logging.init", level),
    )

    _assert_exception_parity(c_exc, stdlib_exc)
    if c_exc is None:
        assert _logger_init_values(
            CLogger("dank_mids.tests.logging.init", level),
        ) == _logger_init_values(
            logging.Logger("dank_mids.tests.logging.init", level),
        )


def test_find_caller_stack_info_is_plain_stack_text() -> None:
    stack_info = _find_caller_with_stack_info()

    assert stack_info.startswith("Stack (most recent call last):")
    assert "_find_caller_with_stack_info" in stack_info
    assert stack_info[-1] != "\n"


@pytest.mark.parametrize("stack_info", [False, True])
@pytest.mark.parametrize("stacklevel", [1, 2, 3])
def test_find_caller_exactly_matches_stdlib(
    stacklevel: int,
    stack_info: bool,
) -> None:
    c_caller, stdlib_caller = _caller_pair(stacklevel, stack_info=stack_info)

    assert c_caller == stdlib_caller


def test_find_caller_skips_compiled_logging_extension_frame() -> None:
    c_caller = _find_caller_through_internal_logging_frame(
        get_c_logger("dank_mids.tests.logging.compiled_frame"),
    )
    stdlib_caller = _find_caller_through_internal_logging_frame(
        logging.Logger("dank_mids.tests.logging.stdlib_compiled_frame"),
    )

    assert c_caller == stdlib_caller
    assert c_caller[0] != _fake_compiled_logging_path()
    assert stdlib_caller[0] != logging._srcfile


def test_get_effective_level_matches_stdlib() -> None:
    pair = _new_logger_pair(logging.NOTSET)
    c_parent = CLogger("dank_mids.tests.logging.parent", logging.ERROR)
    stdlib_parent = logging.Logger("dank_mids.tests.logging.parent", logging.ERROR)
    pair.c_logger.parent = c_parent
    pair.stdlib_logger.parent = stdlib_parent

    assert pair.c_logger.getEffectiveLevel() == pair.stdlib_logger.getEffectiveLevel()


@pytest.mark.parametrize("disabled", [False, True])
@pytest.mark.parametrize(
    "level",
    [logging.DEBUG, logging.INFO, logging.WARNING],
)
def test_is_enabled_for_matches_stdlib(level: int, disabled: bool) -> None:
    pair = _new_logger_pair(logging.INFO)
    pair.c_logger.disabled = disabled
    pair.stdlib_logger.disabled = disabled

    c_exc = _capture_exception(lambda: pair.c_logger.isEnabledFor(level))
    stdlib_exc = _capture_exception(lambda: pair.stdlib_logger.isEnabledFor(level))

    _assert_exception_parity(c_exc, stdlib_exc)
    if c_exc is None:
        assert pair.c_logger.isEnabledFor(level) == pair.stdlib_logger.isEnabledFor(
            level,
        )


@pytest.mark.parametrize(
    ("method_name", "args"),
    [
        ("debug", ("hello %s", "world")),
        ("info", ("hello %s", "world")),
        ("warning", ("hello %s", "world")),
        ("error", ("hello %s", "world")),
        ("critical", ("hello %s", "world")),
        ("fatal", ("hello %s", "world")),
        ("log", (logging.INFO, "hello %s", "world")),
    ],
)
def test_logging_entrypoints_emit_exact_stdlib_records(
    monkeypatch: pytest.MonkeyPatch,
    method_name: str,
    args: tuple[object, ...],
) -> None:
    pair = _new_logger_pair(logging.DEBUG)

    with _frozen_logging_time(monkeypatch):
        _emit_pair(pair, method_name, *args)

    _assert_handler_parity(pair)


def test_disabled_logging_entrypoint_matches_stdlib(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    pair = _new_logger_pair(logging.INFO)

    with _frozen_logging_time(monkeypatch):
        _emit_pair(pair, "debug", "hidden")

    _assert_handler_parity(pair)
    assert pair.c_handler.records == pair.stdlib_handler.records == []


def test_level_type_inputs_are_intentional_mypyc_fast_path_divergence() -> None:
    logger = CLogger("dank_mids.tests.logging.level_divergence", logging.DEBUG)

    _assert_fast_level_type_divergence(
        lambda: CLogger("dank_mids.tests.logging.level_divergence", object()),
    )
    _assert_fast_level_type_divergence(lambda: logger.isEnabledFor("INFO"))
    _assert_fast_level_type_divergence(lambda: logger.isEnabledFor(object()))
    _assert_fast_level_type_divergence(lambda: logger.log("INFO", "hello"))


def test_log_with_integer_level_matches_stdlib_when_disabled(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    pair = _new_logger_pair(logging.DEBUG)
    pair.c_logger.disabled = True
    pair.stdlib_logger.disabled = True

    with _frozen_logging_time(monkeypatch):
        _emit_pair(pair, "log", logging.INFO, "hidden")

    _assert_handler_parity(pair)
    assert pair.c_handler.records == pair.stdlib_handler.records == []


def test_logging_entrypoint_with_stack_info_and_extra_matches_stdlib(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    pair = _new_logger_pair(logging.DEBUG)

    with _frozen_logging_time(monkeypatch):
        _emit_pair(
            pair,
            "info",
            "hello %s",
            "world",
            extra={"request_id": "abc"},
            stack_info=True,
            stacklevel=2,
        )

    _assert_handler_parity(pair)


@pytest.mark.parametrize(
    "exc_info",
    ["true", "tuple", "exception"],
)
def test_exc_info_variants_match_stdlib(
    monkeypatch: pytest.MonkeyPatch,
    exc_info: str,
) -> None:
    pair = _new_logger_pair(logging.DEBUG)

    try:
        raise ValueError("boom")
    except ValueError as exc:
        if exc_info == "true":
            value: object = True
        elif exc_info == "tuple":
            value = sys.exc_info()
        else:
            value = exc

        with _frozen_logging_time(monkeypatch):
            _emit_pair(pair, "error", "failed", exc_info=value)

    _assert_handler_parity(pair)


def test_exception_entrypoint_matches_stdlib(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    pair = _new_logger_pair(logging.DEBUG)

    try:
        raise RuntimeError("boom")
    except RuntimeError:
        with _frozen_logging_time(monkeypatch):
            _emit_pair(pair, "exception", "failed")

    _assert_handler_parity(pair)


def test_make_record_matches_stdlib(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    pair = _new_logger_pair()

    with _frozen_logging_time(monkeypatch):
        c_record, stdlib_record = _make_record_pair(
            pair,
            extra={"request_id": "abc"},
        )

    _assert_record_parity(c_record, stdlib_record)


def test_make_record_extra_collision_matches_stdlib() -> None:
    pair = _new_logger_pair()

    c_exc = _capture_exception(
        lambda: _make_record(pair.c_logger, extra={"message": "no"}),
    )
    stdlib_exc = _capture_exception(
        lambda: _make_record(pair.stdlib_logger, extra={"message": "no"}),
    )

    _assert_exception_parity(c_exc, stdlib_exc)


def test_custom_log_record_factory_matches_stdlib(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    pair = _new_logger_pair(logging.DEBUG)
    previous = logging.getLogRecordFactory()

    def factory(*args: object, **kwargs: object) -> logging.LogRecord:
        record = previous(*args, **kwargs)
        record.from_factory = True
        return record

    with _log_record_factory(factory), _frozen_logging_time(monkeypatch):
        _emit_pair(pair, "info", "hello")

    _assert_handler_parity(pair)
