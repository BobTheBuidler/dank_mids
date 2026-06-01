import importlib.machinery
import logging
from pathlib import Path

import pytest

from dank_mids import logging as dank_logging
from dank_mids.logging import get_c_logger

CallerInfo = tuple[str, int, str, str | None]


class _ListHandler(logging.Handler):
    def __init__(self) -> None:
        super().__init__()
        self.records: list[logging.LogRecord] = []

    def emit(self, record: logging.LogRecord) -> None:
        self.records.append(record)


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


def _find_caller_with_stack_info() -> str:
    logger = get_c_logger("dank_mids.tests.logging")
    _filename, _line, _function, stack_info = logger.findCaller(stack_info=True)
    assert stack_info is not None
    return stack_info


def _emit_record(logger: logging.Logger, stacklevel: int) -> logging.LogRecord:
    handler = _ListHandler()
    original_handlers = logger.handlers[:]
    original_propagate = logger.propagate
    original_level = logger.level
    logger.handlers[:] = [handler]
    logger.propagate = False
    logger.setLevel(logging.INFO)
    try:
        logger.info("hello", stacklevel=stacklevel)
    finally:
        logger.handlers[:] = original_handlers
        logger.propagate = original_propagate
        logger.setLevel(original_level)
    assert handler.records
    return handler.records[-1]


def _fake_compiled_logging_path() -> str:
    suffix = importlib.machinery.EXTENSION_SUFFIXES[0]
    return str(Path(dank_logging.__file__).with_name(f"logging{suffix}"))


def _find_caller_through_compiled_logging_frame(logger: logging.Logger) -> CallerInfo:
    namespace = {"logger": logger}
    code = compile(
        "def compiled_logging_wrapper():\n"
        "    return logger.findCaller()\n",
        _fake_compiled_logging_path(),
        "exec",
    )
    exec(code, namespace)
    return namespace["compiled_logging_wrapper"]()


def test_find_caller_stack_info_is_plain_stack_text() -> None:
    stack_info = _find_caller_with_stack_info()

    assert stack_info.startswith("Stack (most recent call last):")
    assert "_find_caller_with_stack_info" in stack_info
    assert stack_info[-1] != "\n"


@pytest.mark.parametrize(
    ("stacklevel", "expected_function"),
    [
        (1, "_leaf_find_caller"),
        (2, "_middle_find_caller"),
        (3, "test_find_caller_stacklevel_matches_stdlib"),
    ],
)
def test_find_caller_stacklevel_matches_stdlib(
    stacklevel: int,
    expected_function: str,
) -> None:
    c_logger = get_c_logger("dank_mids.tests.logging.caller")
    stdlib_logger = logging.getLogger("dank_mids.tests.logging.stdlib")

    c_filename, _c_line, c_function, c_stack = _middle_find_caller(c_logger, stacklevel)
    std_filename, _std_line, std_function, std_stack = _middle_find_caller(
        stdlib_logger,
        stacklevel,
    )

    assert c_filename == std_filename == __file__
    assert c_function == std_function == expected_function
    assert c_stack == std_stack is None


@pytest.mark.parametrize(
    ("stacklevel", "expected_function"),
    [
        (1, "_emit_record"),
        (2, "test_log_record_caller_matches_stdlib"),
    ],
)
def test_log_record_caller_matches_stdlib(
    stacklevel: int,
    expected_function: str,
) -> None:
    c_logger = get_c_logger("dank_mids.tests.logging.record")
    stdlib_logger = logging.getLogger("dank_mids.tests.logging.stdlib_record")

    c_record = _emit_record(c_logger, stacklevel)
    stdlib_record = _emit_record(stdlib_logger, stacklevel)

    assert c_record.pathname == stdlib_record.pathname == __file__
    assert c_record.funcName == stdlib_record.funcName == expected_function


def test_find_caller_skips_compiled_logging_extension_frame() -> None:
    logger = get_c_logger("dank_mids.tests.logging.compiled_frame")

    filename, _line, function, stack_info = _find_caller_through_compiled_logging_frame(
        logger,
    )

    assert filename == __file__
    assert function == "_find_caller_through_compiled_logging_frame"
    assert stack_info is None
