#!/usr/bin/env python3
"""Fail if mypyc targets import as Python source instead of native extensions."""

from __future__ import annotations

import argparse
import importlib
import os
import pathlib
import sys
from types import ModuleType
from typing import Iterable

ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from scripts.ci.mypyc_targets import compiled_module_names, extension_suffix  # noqa: E402


def _path_resolves_to_root(path_entry: str, root: pathlib.Path) -> bool:
    try:
        path = pathlib.Path.cwd() if path_entry == "" else pathlib.Path(path_entry)
        return path.resolve() == root.resolve()
    except OSError:
        return False


def _drop_repo_import_path(root: pathlib.Path) -> None:
    sys.path[:] = [
        path_entry
        for path_entry in sys.path
        if not _path_resolves_to_root(path_entry, root)
    ]
    importlib.invalidate_caches()


def _prefer_source_tree_imports(root: pathlib.Path) -> None:
    root_str = str(root)
    sys.path[:] = [path_entry for path_entry in sys.path if path_entry != root_str]
    sys.path.insert(0, root_str)
    importlib.invalidate_caches()


def _clear_dank_mids_modules() -> None:
    for module_name in list(sys.modules):
        if module_name == "dank_mids" or module_name.startswith("dank_mids."):
            del sys.modules[module_name]


def configure_imports(*, source_tree: bool, root: pathlib.Path = ROOT) -> None:
    if source_tree:
        _prefer_source_tree_imports(root)
    else:
        _drop_repo_import_path(root)
    _clear_dank_mids_modules()


def native_suffixes() -> tuple[str, ...]:
    suffix = extension_suffix()
    return tuple(dict.fromkeys((suffix, ".pyd" if os.name == "nt" else ".so", ".pyd", ".so")))


def is_native_module(module: ModuleType) -> bool:
    module_file = getattr(module, "__file__", None)
    return isinstance(module_file, str) and module_file.endswith(native_suffixes())


def check_modules(module_names: Iterable[str], *, verbose: bool = False) -> list[str]:
    failures: list[str] = []
    for module_name in module_names:
        if verbose:
            print(f"checking compiled import: {module_name}", flush=True)
        try:
            module = importlib.import_module(module_name)
        except Exception as exc:
            failures.append(f"{module_name}: import failed: {type(exc).__name__}: {exc}")
            continue

        module_file = getattr(module, "__file__", None)
        if not is_native_module(module):
            failures.append(
                f"{module_name}: imported {module_file!r}, expected native extension "
                f"ending with one of {native_suffixes()!r}"
            )
    return failures


def check_compiled_imports(root: pathlib.Path = ROOT, *, verbose: bool = False) -> list[str]:
    return check_modules(compiled_module_names(root), verbose=verbose)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument(
        "--source-tree",
        action="store_true",
        help="Verify compiled extensions built in-place in the repository checkout.",
    )
    mode.add_argument(
        "--installed-wheel",
        action="store_true",
        help="Verify imports resolve from the installed wheel, not the repository checkout.",
    )
    parser.add_argument(
        "--verbose",
        action="store_true",
        help="Print each module name before importing it.",
    )
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    configure_imports(source_tree=not args.installed_wheel)
    failures = check_compiled_imports(verbose=args.verbose)
    if failures:
        for failure in failures:
            print(f"FAIL: {failure}")
        return 1
    print("verified compiled imports for all mypyc targets")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
