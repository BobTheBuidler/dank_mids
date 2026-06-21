from __future__ import annotations

import logging
import sys
from collections.abc import Callable, Iterator

import pytest

CallerInfo = tuple[str, int, str, str | None]
CallerPair = tuple[CallerInfo, CallerInfo]


def _emit_through_public_stacklevel(
    pair: object,
    emit_pair: Callable[..., None],
) -> None:
    emit_pair(pair, "info", "stacked", stacklevel=2)


def test_find_caller_stack_info_is_plain_stack_text(
    find_caller_with_stack_info: Callable[[], str],
) -> None:
    stack_info = find_caller_with_stack_info()

    assert stack_info.startswith("Stack (most recent call last):")
    assert stack_info[-1] != "\n"


@pytest.mark.parametrize("stack_info", [False, True])
@pytest.mark.parametrize("stacklevel", [1, 2, 3])
def test_find_caller_exactly_matches_stdlib(
    stacklevel: int,
    stack_info: bool,
    caller_pair: Callable[..., CallerPair],
) -> None:
    c_caller, stdlib_caller = caller_pair(stacklevel, stack_info=stack_info)

    assert c_caller == stdlib_caller


def test_find_caller_skips_compiled_logging_extension_frame(
    compiled_frame_caller_pair: Callable[[], CallerPair],
    fake_compiled_logging_path: Callable[[], str],
) -> None:
    c_caller, stdlib_caller = compiled_frame_caller_pair()

    assert c_caller == stdlib_caller
    assert c_caller[0] != fake_compiled_logging_path()
    assert stdlib_caller[0] != logging._srcfile


@pytest.mark.skipif(
    sys.version_info >= (3, 11),
    reason="py3.10 uses the separate compiled findCaller frame helper",
)
def test_py310_find_caller_direct_call_reports_immediate_public_caller(
    new_logger_pair: Callable[[int], object],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    def user_frame() -> CallerInfo:
        return pair.c_logger.findCaller()

    filename, _lineno, func_name, _stack_info = user_frame()

    assert func_name == "user_frame"
    assert filename == __file__


def test_public_emission_stacklevel_uses_user_frame_like_stdlib(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    emit_pair: Callable[..., None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    with frozen_logging_time():
        _emit_through_public_stacklevel(pair, emit_pair)

    c_record = pair.c_handler.records[0]
    stdlib_record = pair.stdlib_handler.records[0]
    assert c_record.pathname == stdlib_record.pathname
    assert c_record.lineno == stdlib_record.lineno
    assert c_record.funcName == stdlib_record.funcName
    assert c_record.funcName == "_emit_through_public_stacklevel"
