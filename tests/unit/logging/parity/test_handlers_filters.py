from __future__ import annotations

import logging
from collections.abc import Callable, Iterator

from dank_mids.logging import CLogger


class _MarkingFilter:
    def __init__(self, allow: bool) -> None:
        self.allow = allow

    def filter(self, record: logging.LogRecord) -> bool:
        record.filter_marker = self.allow
        return self.allow


def _handler_messages(handler: logging.Handler) -> list[str]:
    return [record.getMessage() for record in handler.records]


def test_add_and_remove_handler_match_stdlib(
    list_handler_type: type[logging.Handler],
    new_logger_pair: Callable[[int], object],
) -> None:
    pair = new_logger_pair(logging.DEBUG)
    pair.c_logger.handlers[:] = []
    pair.stdlib_logger.handlers[:] = []
    c_first = list_handler_type()
    c_second = list_handler_type()
    stdlib_first = list_handler_type()
    stdlib_second = list_handler_type()

    pair.c_logger.addHandler(c_first)
    pair.c_logger.addHandler(c_second)
    pair.c_logger.addHandler(c_first)
    pair.stdlib_logger.addHandler(stdlib_first)
    pair.stdlib_logger.addHandler(stdlib_second)
    pair.stdlib_logger.addHandler(stdlib_first)

    assert pair.c_logger.handlers == [c_first, c_second]
    assert pair.stdlib_logger.handlers == [stdlib_first, stdlib_second]

    pair.c_logger.removeHandler(c_first)
    pair.c_logger.removeHandler(c_first)
    pair.stdlib_logger.removeHandler(stdlib_first)
    pair.stdlib_logger.removeHandler(stdlib_first)

    assert pair.c_logger.handlers == [c_second]
    assert pair.stdlib_logger.handlers == [stdlib_second]


def test_has_handlers_matches_stdlib_parent_and_propagate_rules(
    list_handler_type: type[logging.Handler],
    new_logger_pair: Callable[[int], object],
) -> None:
    pair = new_logger_pair(logging.DEBUG)
    pair.c_logger.handlers[:] = []
    pair.stdlib_logger.handlers[:] = []
    assert pair.c_logger.hasHandlers() == pair.stdlib_logger.hasHandlers() == False

    pair.c_logger.addHandler(list_handler_type())
    pair.stdlib_logger.addHandler(list_handler_type())
    assert pair.c_logger.hasHandlers() == pair.stdlib_logger.hasHandlers() == True

    pair = new_logger_pair(logging.DEBUG)
    pair.c_logger.handlers[:] = []
    pair.stdlib_logger.handlers[:] = []
    pair.c_logger.propagate = True
    pair.stdlib_logger.propagate = True
    pair.c_logger.parent = CLogger("dank_mids.tests.logging.handlers.parent", logging.DEBUG)
    pair.stdlib_logger.parent = logging.Logger(
        "dank_mids.tests.logging.handlers.parent",
        logging.DEBUG,
    )
    pair.c_logger.parent.addHandler(list_handler_type())
    pair.stdlib_logger.parent.addHandler(list_handler_type())
    assert pair.c_logger.hasHandlers() == pair.stdlib_logger.hasHandlers() == True

    pair.c_logger.propagate = False
    pair.stdlib_logger.propagate = False
    assert pair.c_logger.hasHandlers() == pair.stdlib_logger.hasHandlers() == False


def test_handle_matches_stdlib_disabled_and_filter_rules(
    list_handler_type: type[logging.Handler],
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    make_record_pair: Callable[..., tuple[logging.LogRecord, logging.LogRecord]],
    assert_handler_parity: Callable[[object], None],
) -> None:
    enabled_pair = new_logger_pair(logging.DEBUG)
    with frozen_logging_time():
        c_record, stdlib_record = make_record_pair(enabled_pair)
    enabled_pair.c_logger.handle(c_record)
    enabled_pair.stdlib_logger.handle(stdlib_record)
    assert_handler_parity(enabled_pair)

    disabled_pair = new_logger_pair(logging.DEBUG)
    disabled_pair.c_logger.disabled = True
    disabled_pair.stdlib_logger.disabled = True
    with frozen_logging_time():
        c_record, stdlib_record = make_record_pair(disabled_pair)
    disabled_pair.c_logger.handle(c_record)
    disabled_pair.stdlib_logger.handle(stdlib_record)
    assert disabled_pair.c_handler.records == disabled_pair.stdlib_handler.records == []

    false_pair = new_logger_pair(logging.DEBUG)
    false_pair.c_logger.addFilter(_MarkingFilter(False))
    false_pair.stdlib_logger.addFilter(_MarkingFilter(False))
    with frozen_logging_time():
        c_record, stdlib_record = make_record_pair(false_pair)
    false_pair.c_logger.handle(c_record)
    false_pair.stdlib_logger.handle(stdlib_record)
    assert false_pair.c_handler.records == false_pair.stdlib_handler.records == []

    true_pair = new_logger_pair(logging.DEBUG)
    true_pair.c_logger.handlers[:] = [list_handler_type()]
    true_pair.stdlib_logger.handlers[:] = [list_handler_type()]
    true_pair.c_logger.addFilter(_MarkingFilter(True))
    true_pair.stdlib_logger.addFilter(_MarkingFilter(True))
    with frozen_logging_time():
        c_record, stdlib_record = make_record_pair(true_pair)
    true_pair.c_logger.handle(c_record)
    true_pair.stdlib_logger.handle(stdlib_record)
    assert_handler_parity(true_pair)


def test_call_handlers_matches_stdlib_parent_propagation(
    list_handler_type: type[logging.Handler],
    frozen_logging_time: Callable[[], Iterator[None]],
    make_record: Callable[..., logging.LogRecord],
) -> None:
    c_child = CLogger("dank_mids.tests.logging.handlers.child", logging.DEBUG)
    c_parent = CLogger("dank_mids.tests.logging.handlers.parent", logging.DEBUG)
    c_grandparent = CLogger(
        "dank_mids.tests.logging.handlers.grandparent",
        logging.DEBUG,
    )
    stdlib_child = logging.Logger("dank_mids.tests.logging.handlers.child", logging.DEBUG)
    stdlib_parent = logging.Logger("dank_mids.tests.logging.handlers.parent", logging.DEBUG)
    stdlib_grandparent = logging.Logger(
        "dank_mids.tests.logging.handlers.grandparent",
        logging.DEBUG,
    )
    c_child.parent = c_parent
    c_parent.parent = c_grandparent
    stdlib_child.parent = stdlib_parent
    stdlib_parent.parent = stdlib_grandparent
    c_parent.propagate = False
    stdlib_parent.propagate = False

    c_local = list_handler_type()
    c_parent_handler = list_handler_type()
    c_grandparent_handler = list_handler_type()
    stdlib_local = list_handler_type()
    stdlib_parent_handler = list_handler_type()
    stdlib_grandparent_handler = list_handler_type()
    c_child.handlers[:] = [c_local]
    c_parent.handlers[:] = [c_parent_handler]
    c_grandparent.handlers[:] = [c_grandparent_handler]
    stdlib_child.handlers[:] = [stdlib_local]
    stdlib_parent.handlers[:] = [stdlib_parent_handler]
    stdlib_grandparent.handlers[:] = [stdlib_grandparent_handler]

    with frozen_logging_time():
        c_record = make_record(c_child)
        stdlib_record = make_record(stdlib_child)

    c_child.callHandlers(c_record)
    stdlib_child.callHandlers(stdlib_record)

    assert _handler_messages(c_local) == _handler_messages(stdlib_local) == ["hello world"]
    assert _handler_messages(c_parent_handler) == _handler_messages(stdlib_parent_handler) == [
        "hello world",
    ]
    assert _handler_messages(c_grandparent_handler) == _handler_messages(
        stdlib_grandparent_handler,
    ) == []


def test_add_remove_filter_and_filter_result_match_stdlib(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    make_record_pair: Callable[..., tuple[logging.LogRecord, logging.LogRecord]],
) -> None:
    pair = new_logger_pair(logging.DEBUG)
    c_filter = _MarkingFilter(True)
    stdlib_filter = _MarkingFilter(True)

    pair.c_logger.addFilter(c_filter)
    pair.c_logger.addFilter(c_filter)
    pair.stdlib_logger.addFilter(stdlib_filter)
    pair.stdlib_logger.addFilter(stdlib_filter)
    assert pair.c_logger.filters == [c_filter]
    assert pair.stdlib_logger.filters == [stdlib_filter]

    with frozen_logging_time():
        c_record, stdlib_record = make_record_pair(pair)

    c_result = pair.c_logger.filter(c_record)
    stdlib_result = pair.stdlib_logger.filter(stdlib_record)
    assert bool(c_result) == bool(stdlib_result) == True
    assert c_result is c_record
    assert stdlib_result is stdlib_record
    assert c_record.filter_marker == stdlib_record.filter_marker == True

    pair.c_logger.removeFilter(c_filter)
    pair.c_logger.removeFilter(c_filter)
    pair.stdlib_logger.removeFilter(stdlib_filter)
    pair.stdlib_logger.removeFilter(stdlib_filter)
    assert pair.c_logger.filters == pair.stdlib_logger.filters == []

    pair.c_logger.addFilter(_MarkingFilter(False))
    pair.stdlib_logger.addFilter(_MarkingFilter(False))
    with frozen_logging_time():
        c_record, stdlib_record = make_record_pair(pair)
    assert pair.c_logger.filter(c_record) == pair.stdlib_logger.filter(stdlib_record) == False


def test_callable_filter_matches_stdlib(
    new_logger_pair: Callable[[int], object],
    frozen_logging_time: Callable[[], Iterator[None]],
    make_record_pair: Callable[..., tuple[logging.LogRecord, logging.LogRecord]],
) -> None:
    pair = new_logger_pair(logging.DEBUG)

    def c_filter(record: logging.LogRecord) -> bool:
        record.callable_filter_marker = "c"
        return True

    def stdlib_filter(record: logging.LogRecord) -> bool:
        record.callable_filter_marker = "c"
        return True

    pair.c_logger.addFilter(c_filter)
    pair.stdlib_logger.addFilter(stdlib_filter)

    with frozen_logging_time():
        c_record, stdlib_record = make_record_pair(pair)

    c_result = pair.c_logger.filter(c_record)
    stdlib_result = pair.stdlib_logger.filter(stdlib_record)
    assert bool(c_result) == bool(stdlib_result) == True
    assert c_result is c_record
    assert stdlib_result is stdlib_record
    assert c_record.callable_filter_marker == stdlib_record.callable_filter_marker == "c"
