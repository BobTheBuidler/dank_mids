from __future__ import annotations

import importlib
import os
from pathlib import Path

import pytest

from scripts.ci.check_compiled_imports import configure_imports, is_native_module, native_suffixes
from scripts.ci.mypyc_targets import compiled_module_names

REPO_ROOT = Path(__file__).resolve().parents[2]
MODULE_NAMES = compiled_module_names(REPO_ROOT)


@pytest.mark.parametrize("module_name", MODULE_NAMES, ids=MODULE_NAMES)
def test_mypyc_target_imports_compiled_extension(module_name: str) -> None:
    if os.getenv("DANK_MIDS_EXPECT_COMPILED") != "1":
        pytest.skip("compiled import check is disabled for source-mode test runs")

    mode = os.getenv("DANK_MIDS_COMPILED_IMPORT_MODE", "source-tree")
    if mode not in {"source-tree", "installed-wheel"}:
        pytest.fail(f"unsupported compiled import mode: {mode!r}")

    configure_imports(source_tree=mode == "source-tree", root=REPO_ROOT)
    print(f"checking compiled import: {module_name}", flush=True)
    module = importlib.import_module(module_name)

    assert is_native_module(module), (
        f"{module_name} imported {getattr(module, '__file__', None)!r}; "
        f"expected native extension ending with one of {native_suffixes()!r}"
    )
