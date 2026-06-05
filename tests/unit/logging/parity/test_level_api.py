from __future__ import annotations

import logging
from collections.abc import Callable

import pytest

from dank_mids import logging as dank_logging
from dank_mids.logging import CLogger


@pytest.mark.parametrize(
    "level",
    [
        logging.NOTSET,
        logging.DEBUG,
        logging.INFO,
        logging.WARNING,
        logging.ERROR,
        logging.CRITICAL,
        "NOTSET",
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
        "CRITICAL",
        "NOPE",
    ],
)
def test_check_level_matches_stdlib_for_supported_inputs(
    level: int | str,
    capture_exception: Callable[[Callable[[], object]], BaseException | None],
    assert_exception_parity: Callable[[BaseException | None, BaseException | None], None],
) -> None:
    c_exc = capture_exception(lambda: dank_logging._checkLevel(level))
    stdlib_exc = capture_exception(lambda: logging._checkLevel(level))

    assert_exception_parity(c_exc, stdlib_exc)
    if c_exc is None:
        assert dank_logging._checkLevel(level) == logging._checkLevel(level)


def test_fast_level_inputs_keep_documented_mypyc_type_divergence(
    assert_fast_level_type_divergence: Callable[[Callable[[], object]], None],
) -> None:
    logger = CLogger("dank_mids.tests.logging.level_divergence", logging.DEBUG)

    assert_fast_level_type_divergence(
        lambda: CLogger("dank_mids.tests.logging.level_divergence", object()),
    )
    assert_fast_level_type_divergence(lambda: logger.isEnabledFor("INFO"))
    assert_fast_level_type_divergence(lambda: logger.isEnabledFor(object()))
    assert_fast_level_type_divergence(lambda: logger.log("INFO", "hello"))
