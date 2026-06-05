from __future__ import annotations

import logging
import sys
import warnings
from collections.abc import Callable, Iterator

import pytest


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
    method_name: str,
    args: tuple[object, ...],
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    emit_pair: Callable[..., None],
    assert_handler_parity: Callable[[object], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    with frozen_logging_time():
        emit_pair(pair, method_name, *args)

    assert_handler_parity(pair)


def test_disabled_debug_emits_no_records(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    emit_pair: Callable[..., None],
    assert_handler_parity: Callable[[object], None],
) -> None:
    pair = new_logger_pair(logging.INFO)

    with frozen_logging_time():
        emit_pair(pair, "debug", "hidden")

    assert_handler_parity(pair)
    assert pair.c_handler.records == pair.stdlib_handler.records == []


def test_disabled_log_with_integer_level_emits_no_records(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    emit_pair: Callable[..., None],
    assert_handler_parity: Callable[[object], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)
    pair.c_logger.disabled = True
    pair.stdlib_logger.disabled = True

    with frozen_logging_time():
        emit_pair(pair, "log", logging.INFO, "hidden")

    assert_handler_parity(pair)
    assert pair.c_handler.records == pair.stdlib_handler.records == []


def test_logging_entrypoint_with_stack_info_stacklevel_and_extra_matches_stdlib(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    emit_pair: Callable[..., None],
    assert_handler_parity: Callable[[object], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    with frozen_logging_time():
        emit_pair(
            pair,
            "info",
            "hello %s",
            "world",
            extra={"request_id": "abc"},
            stack_info=True,
            stacklevel=2,
        )

    assert_handler_parity(pair)


@pytest.mark.parametrize("exc_info", ["true", "tuple", "exception"])
def test_exc_info_variants_match_stdlib(
    exc_info: str,
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    emit_pair: Callable[..., None],
    assert_handler_parity: Callable[[object], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    try:
        raise ValueError("boom")
    except ValueError as exc:
        if exc_info == "true":
            value: object = True
        elif exc_info == "tuple":
            value = sys.exc_info()
        else:
            value = exc

        with frozen_logging_time():
            emit_pair(pair, "error", "failed", exc_info=value)

    assert_handler_parity(pair)


def test_exception_entrypoint_matches_stdlib(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    emit_pair: Callable[..., None],
    assert_handler_parity: Callable[[object], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    try:
        raise RuntimeError("boom")
    except RuntimeError:
        with frozen_logging_time():
            emit_pair(pair, "exception", "failed")

    assert_handler_parity(pair)


def test_warn_emits_warning_record_and_deprecation_warning_like_stdlib(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    emit_pair: Callable[..., None],
    assert_handler_parity: Callable[[object], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    with warnings.catch_warnings(record=True) as caught, frozen_logging_time():
        warnings.simplefilter("always")
        emit_pair(pair, "warn", "hello %s", "world")

    assert_handler_parity(pair)
    assert [warning.category for warning in caught] == [
        DeprecationWarning,
        DeprecationWarning,
    ]
    assert caught[0].message.args == caught[1].message.args
