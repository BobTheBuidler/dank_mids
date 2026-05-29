from __future__ import annotations

import importlib
import os
import sys
from pathlib import Path

import pytest

from scripts.ci.mypyc_targets import compiled_module_names, extension_suffix

REPO_ROOT = Path(__file__).resolve().parents[2]
MODULE_NAMES = compiled_module_names(REPO_ROOT)
_STALE_DANK_MIDS_MODULES_CLEARED = False


def _path_resolves_to_repo(path_entry: str) -> bool:
    path = Path.cwd() if path_entry == "" else Path(path_entry)
    try:
        return path.resolve() == REPO_ROOT
    except OSError:
        return False


def _prepare_imports() -> None:
    global _STALE_DANK_MIDS_MODULES_CLEARED

    mode = os.getenv("DANK_MIDS_COMPILED_IMPORT_MODE", "source-tree")
    if mode == "source-tree":
        sys.path[:] = [path_entry for path_entry in sys.path if path_entry != str(REPO_ROOT)]
        sys.path.insert(0, str(REPO_ROOT))
    elif mode == "installed-wheel":
        sys.path[:] = [
            path_entry for path_entry in sys.path if not _path_resolves_to_repo(path_entry)
        ]
    else:
        pytest.fail(f"unsupported compiled import mode: {mode!r}")
    importlib.invalidate_caches()
    if not _STALE_DANK_MIDS_MODULES_CLEARED:
        for loaded_name in list(sys.modules):
            if loaded_name == "dank_mids" or loaded_name.startswith("dank_mids."):
                del sys.modules[loaded_name]
        _STALE_DANK_MIDS_MODULES_CLEARED = True
    # Mypyc native modules keep C-level module state; after the one-time stale
    # cleanup, do not unload and reimport them between parameterized cases.


def _native_suffixes() -> tuple[str, ...]:
    suffix = extension_suffix()
    platform_suffix = ".pyd" if os.name == "nt" else ".so"
    return tuple(dict.fromkeys((suffix, platform_suffix, ".pyd", ".so")))


@pytest.mark.parametrize("module_name", MODULE_NAMES, ids=MODULE_NAMES)
def test_mypyc_target_imports_compiled_extension(module_name: str) -> None:
    _prepare_imports()
    print(f"checking compiled import: {module_name}", flush=True)
    module = importlib.import_module(module_name)
    module_file = getattr(module, "__file__", None)

    assert isinstance(module_file, str) and module_file.endswith(_native_suffixes()), (
        f"{module_name} imported {module_file!r}; "
        f"expected native extension ending with one of {_native_suffixes()!r}"
    )
