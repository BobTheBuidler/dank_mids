from __future__ import annotations

import importlib.machinery
import logging
from collections.abc import Callable

from dank_mids import logging as dank_logging
from dank_mids.logging import CLogger, get_c_logger, use_c_logger_class

_NATIVE_SUFFIXES = tuple(
    dict.fromkeys((*importlib.machinery.EXTENSION_SUFFIXES, ".so", ".pyd"))
)


def test_logging_parity_suite_runs_against_compiled_logging_extension() -> None:
    module_file = getattr(dank_logging, "__file__", None)

    assert isinstance(module_file, str) and module_file.endswith(_NATIVE_SUFFIXES), (
        "logging parity tests must run against compiled dank_mids.logging; "
        "build/download source-tree extensions before running this suite."
    )


def test_get_c_logger_returns_c_logger(logger_name_prefix: str) -> None:
    logger = get_c_logger(f"{logger_name_prefix}.public_contract.get")

    assert isinstance(logger, CLogger)


def test_get_c_logger_restores_previous_logger_class(logger_name_prefix: str) -> None:
    previous = logging.getLoggerClass()

    get_c_logger(f"{logger_name_prefix}.public_contract.restore")

    assert logging.getLoggerClass() is previous


def test_use_c_logger_class_installs_c_logger_only_inside_context() -> None:
    previous = logging.getLoggerClass()

    with use_c_logger_class():
        assert logging.getLoggerClass() is CLogger

    assert logging.getLoggerClass() is previous


def test_public_logger_callables_are_assigned_to_one_parity_area(
    public_logger_method_areas: dict[str, str],
) -> None:
    allowed_areas = {
        "caller",
        "emission",
        "handlers_filters",
        "hierarchy",
        "records",
        "state",
    }
    runtime_public_callables = {
        name
        for name in dir(logging.Logger)
        if not name.startswith("_") and callable(getattr(logging.Logger, name))
    }
    expected_public_callables = set(public_logger_method_areas)
    missing_optional = expected_public_callables - runtime_public_callables

    if hasattr(logging.Logger, "getChildren"):
        assert missing_optional == set()
    else:
        assert missing_optional == {"getChildren"}
    assert runtime_public_callables - expected_public_callables == set()
    assert set(public_logger_method_areas.values()) <= allowed_areas
    assert len(public_logger_method_areas) == len(expected_public_callables)


def test_c_logger_defined_callables_are_registered(
    clogger_defined_callable_areas: dict[str, str],
) -> None:
    defined_callables = {
        name
        for name, value in CLogger.__dict__.items()
        if callable(value) and (name == "__init__" or not name.startswith("__"))
    }

    assert defined_callables == set(clogger_defined_callable_areas)
    assert clogger_defined_callable_areas["__init__"] == "constructor_setup_only"
    assert clogger_defined_callable_areas["_log"] == "emission"
