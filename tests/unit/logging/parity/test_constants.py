from __future__ import annotations

import logging

from dank_mids import logging as dank_logging


def test_module_level_constants_match_stdlib_logging() -> None:
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
