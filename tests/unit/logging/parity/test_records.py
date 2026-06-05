from __future__ import annotations

import logging
import sys
from collections.abc import Callable, Iterator

import pytest


def test_make_record_matches_stdlib(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    make_record_pair: Callable[..., tuple[logging.LogRecord, logging.LogRecord]],
    assert_record_parity: Callable[[logging.LogRecord, logging.LogRecord], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    with frozen_logging_time():
        c_record, stdlib_record = make_record_pair(
            pair,
            extra={"request_id": "abc"},
        )

    assert_record_parity(c_record, stdlib_record)


@pytest.mark.parametrize("collision_key", ["message", "asctime", "name"])
def test_make_record_extra_collision_matches_stdlib(
    collision_key: str,
    new_logger_pair: Callable[[int], object],
    make_record: Callable[..., logging.LogRecord],
    capture_exception: Callable[[Callable[[], object]], BaseException | None],
    assert_exception_parity: Callable[[BaseException | None, BaseException | None], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    c_exc = capture_exception(
        lambda: make_record(pair.c_logger, extra={collision_key: "no"}),
    )
    stdlib_exc = capture_exception(
        lambda: make_record(pair.stdlib_logger, extra={collision_key: "no"}),
    )

    assert_exception_parity(c_exc, stdlib_exc)


def test_custom_log_record_factory_matches_stdlib(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    log_record_factory: Callable[[Callable[..., logging.LogRecord]], Iterator[None]],
    emit_pair: Callable[..., None],
    assert_handler_parity: Callable[[object], None],
) -> None:
    pair = new_logger_pair(logging.DEBUG)
    previous = logging.getLogRecordFactory()

    def factory(*args: object, **kwargs: object) -> logging.LogRecord:
        record = previous(*args, **kwargs)
        record.from_factory = True
        return record

    with log_record_factory(factory), frozen_logging_time():
        emit_pair(pair, "info", "hello")

    assert_handler_parity(pair)


def test_emitted_record_fields_match_stdlib(
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
            emit_pair(
                pair,
                "error",
                "failed %s",
                "request",
                exc_info=sys.exc_info(),
                extra={"request_id": "abc"},
                stack_info=True,
                stacklevel=2,
            )

    assert_handler_parity(pair)
    c_record = pair.c_handler.records[0]
    stdlib_record = pair.stdlib_handler.records[0]
    assert c_record.request_id == stdlib_record.request_id == "abc"
    assert c_record.getMessage() == stdlib_record.getMessage() == "failed request"
    assert c_record.exc_info == stdlib_record.exc_info
    assert c_record.stack_info == stdlib_record.stack_info
