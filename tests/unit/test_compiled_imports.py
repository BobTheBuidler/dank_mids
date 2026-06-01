from __future__ import annotations

import importlib
import importlib.util
import os
import sys
from pathlib import Path

import pytest

REPO_ROOT = Path(__file__).resolve().parents[2]

# cibuildwheel runs this file from {project} after installing a wheel, but the
# repo root is intentionally removed from sys.path before importing dank_mids.
# Load the repo-only target helper by path so installed-wheel mode can still
# compute expected modules without making source-tree package code importable.
_MYPYC_TARGETS_SPEC = importlib.util.spec_from_file_location(
    "_dank_mids_test_mypyc_targets",
    REPO_ROOT / "scripts" / "ci" / "mypyc_targets.py",
)
assert _MYPYC_TARGETS_SPEC is not None and _MYPYC_TARGETS_SPEC.loader is not None
_mypyc_targets = importlib.util.module_from_spec(_MYPYC_TARGETS_SPEC)
_MYPYC_TARGETS_SPEC.loader.exec_module(_mypyc_targets)
compiled_module_names = _mypyc_targets.compiled_module_names
extension_suffix = _mypyc_targets.extension_suffix

MODULE_NAMES = compiled_module_names(REPO_ROOT)


def _path_resolves_to_repo(path_entry: str) -> bool:
    path = Path.cwd() if path_entry == "" else Path(path_entry)
    try:
        return path.resolve() == REPO_ROOT
    except OSError:
        return False


def _prepare_imports() -> None:
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
    # Pytest collection may already hold references to imported dank_mids classes.
    # Do not unload mypyc modules in-process; stale source imports fail below.


def _native_suffixes() -> tuple[str, ...]:
    suffix = extension_suffix()
    platform_suffix = ".pyd" if os.name == "nt" else ".so"
    return tuple(dict.fromkeys((suffix, platform_suffix, ".pyd", ".so")))


def _assert_dank_middleware_removal(exc: ImportError) -> None:
    message = str(exc)
    assert "dank_middleware" in message
    assert "web3 v7" in message
    assert "DankMiddleware" in message
    assert "setup_dank_w3" in message


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


def test_compiled_middleware_rejects_legacy_dank_middleware_import() -> None:
    _prepare_imports()
    module = importlib.import_module("dank_mids.middleware")
    module_file = getattr(module, "__file__", None)

    assert isinstance(module_file, str) and module_file.endswith(_native_suffixes()), (
        f"dank_mids.middleware imported {module_file!r}; "
        f"expected native extension ending with one of {_native_suffixes()!r}"
    )

    with pytest.raises(ImportError) as getattr_exc:
        getattr(module, "dank_middleware")
    _assert_dank_middleware_removal(getattr_exc.value)

    with pytest.raises(ImportError) as import_exc:
        exec("from dank_mids.middleware import dank_middleware", {})
    _assert_dank_middleware_removal(import_exc.value)
