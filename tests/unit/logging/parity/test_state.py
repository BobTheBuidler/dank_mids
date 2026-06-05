from __future__ import annotations

import logging
from collections.abc import Callable

import pytest

from dank_mids.logging import CLogger, use_c_logger_class


@pytest.mark.parametrize("level", [logging.NOTSET, logging.INFO, "INFO", "NOPE"])
def test_set_level_matches_stdlib_and_clears_cache(
    level: int | str,
    logger_name_prefix: str,
    capture_exception: Callable[[Callable[[], object]], BaseException | None],
    assert_exception_parity: Callable[[BaseException | None, BaseException | None], None],
) -> None:
    with use_c_logger_class():
        c_logger = logging.getLogger(f"{logger_name_prefix}.state.c_set_level.{level!r}")
    stdlib_logger = logging.getLogger(f"{logger_name_prefix}.state.stdlib_set_level.{level!r}")
    c_logger.setLevel(logging.DEBUG)
    stdlib_logger.setLevel(logging.DEBUG)

    assert c_logger.isEnabledFor(logging.DEBUG) == stdlib_logger.isEnabledFor(
        logging.DEBUG,
    )
    assert c_logger._cache
    assert stdlib_logger._cache

    c_exc = capture_exception(lambda: c_logger.setLevel(level))
    stdlib_exc = capture_exception(lambda: stdlib_logger.setLevel(level))

    assert_exception_parity(c_exc, stdlib_exc)
    if c_exc is None:
        assert c_logger.level == stdlib_logger.level
        assert c_logger._cache == stdlib_logger._cache == {}


def test_get_effective_level_matches_stdlib_parent_chain(
    new_logger_pair: Callable[[int], object],
) -> None:
    pair = new_logger_pair(logging.NOTSET)
    c_parent = CLogger("dank_mids.tests.logging.parent", logging.ERROR)
    stdlib_parent = logging.Logger("dank_mids.tests.logging.parent", logging.ERROR)
    pair.c_logger.parent = c_parent
    pair.stdlib_logger.parent = stdlib_parent

    assert pair.c_logger.getEffectiveLevel() == pair.stdlib_logger.getEffectiveLevel()

    pair.c_logger.level = logging.DEBUG
    pair.stdlib_logger.level = logging.DEBUG
    assert pair.c_logger.getEffectiveLevel() == pair.stdlib_logger.getEffectiveLevel()

    rootless_pair = new_logger_pair(logging.NOTSET)
    assert (
        rootless_pair.c_logger.getEffectiveLevel()
        == rootless_pair.stdlib_logger.getEffectiveLevel()
        == logging.NOTSET
    )


@pytest.mark.parametrize("disabled", [False, True])
@pytest.mark.parametrize("level", [logging.DEBUG, logging.INFO, logging.WARNING])
def test_is_enabled_for_matches_stdlib_disabled_cache_and_manager_disable(
    level: int,
    disabled: bool,
    new_logger_pair: Callable[[int], object],
    capture_exception: Callable[[Callable[[], object]], BaseException | None],
    assert_exception_parity: Callable[[BaseException | None, BaseException | None], None],
) -> None:
    pair = new_logger_pair(logging.INFO)
    pair.c_logger.disabled = disabled
    pair.stdlib_logger.disabled = disabled

    c_exc = capture_exception(lambda: pair.c_logger.isEnabledFor(level))
    stdlib_exc = capture_exception(lambda: pair.stdlib_logger.isEnabledFor(level))

    assert_exception_parity(c_exc, stdlib_exc)
    if c_exc is None:
        assert pair.c_logger.isEnabledFor(level) == pair.stdlib_logger.isEnabledFor(
            level,
        )
        assert pair.c_logger.isEnabledFor(level) == pair.stdlib_logger.isEnabledFor(
            level,
        )
        assert pair.c_logger._cache == pair.stdlib_logger._cache

    manager_pair = new_logger_pair(logging.DEBUG)
    logging.disable(logging.WARNING)
    for managed_level in (
        logging.DEBUG,
        logging.INFO,
        logging.WARNING,
        logging.ERROR,
    ):
        assert manager_pair.c_logger.isEnabledFor(
            managed_level,
        ) == manager_pair.stdlib_logger.isEnabledFor(managed_level)
