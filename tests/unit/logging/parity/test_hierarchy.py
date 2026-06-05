from __future__ import annotations

import logging
import sys

import pytest

from dank_mids.logging import CLogger, use_c_logger_class


def test_get_child_matches_stdlib_name_parent_and_type_contract(
    logger_name_prefix: str,
) -> None:
    with use_c_logger_class():
        c_parent = logging.getLogger(f"{logger_name_prefix}.hierarchy.c_parent")
        c_child = c_parent.getChild("leaf")

    stdlib_parent = logging.getLogger(f"{logger_name_prefix}.hierarchy.stdlib_parent")
    stdlib_child = stdlib_parent.getChild("leaf")

    assert c_child.name == f"{c_parent.name}.leaf"
    assert stdlib_child.name == f"{stdlib_parent.name}.leaf"
    assert c_child.parent is c_parent
    assert stdlib_child.parent is stdlib_parent
    assert isinstance(c_parent, CLogger)
    assert isinstance(c_child, CLogger)
    assert type(stdlib_parent) is logging.Logger
    assert type(stdlib_child) is logging.Logger


@pytest.mark.skipif(
    not hasattr(logging.Logger, "getChildren"),
    reason="logging.Logger.getChildren is a Python 3.12+ public API",
)
def test_get_children_matches_stdlib_immediate_children_on_py312_plus(
    logger_name_prefix: str,
) -> None:
    with use_c_logger_class():
        c_parent = logging.getLogger(f"{logger_name_prefix}.children.c_parent")
        c_leaf = c_parent.getChild("leaf")
        c_sibling = c_parent.getChild("sibling")
        c_grandchild = c_leaf.getChild("grandchild")

    stdlib_parent = logging.getLogger(f"{logger_name_prefix}.children.stdlib_parent")
    stdlib_leaf = stdlib_parent.getChild("leaf")
    stdlib_sibling = stdlib_parent.getChild("sibling")
    stdlib_grandchild = stdlib_leaf.getChild("grandchild")

    assert {child.name.removeprefix(f"{c_parent.name}.") for child in c_parent.getChildren()} == {
        "leaf",
        "sibling",
    }
    assert {
        child.name.removeprefix(f"{stdlib_parent.name}.")
        for child in stdlib_parent.getChildren()
    } == {"leaf", "sibling"}
    assert c_grandchild not in c_parent.getChildren()
    assert stdlib_grandchild not in stdlib_parent.getChildren()
    assert {type(child) for child in c_parent.getChildren()} == {CLogger}
    assert {type(child) for child in stdlib_parent.getChildren()} == {logging.Logger}


@pytest.mark.skipif(
    hasattr(logging.Logger, "getChildren"),
    reason="logging.Logger.getChildren is present on this Python runtime",
)
def test_get_children_is_registered_absent_public_api_on_py310_py311(
    public_logger_method_areas: dict[str, str],
) -> None:
    assert sys.version_info[:2] in {(3, 10), (3, 11)}
    assert public_logger_method_areas["getChildren"] == "hierarchy"
