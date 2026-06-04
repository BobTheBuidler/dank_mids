#!/usr/bin/env python3
"""Fail release if compiled targets are missing compiled extensions."""

from __future__ import annotations

import pathlib
import sys
import zipfile
from glob import glob

ROOT = pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from scripts.ci.mypyc_targets import MYPYC_RUNTIME_MODULE, expand_mypyc_targets  # noqa: E402

NATIVE_SUFFIXES = (".so", ".pyd")


def resolve_wheels(patterns: list[str]) -> list[pathlib.Path]:
    wheels: list[pathlib.Path] = []
    for pattern in patterns:
        matches = sorted(glob(pattern))
        if matches:
            wheels.extend(pathlib.Path(path) for path in matches if pathlib.Path(path).is_file())
            continue
        path = pathlib.Path(pattern)
        if path.is_file():
            wheels.append(path)
            continue
        print(f"FAIL: no wheels matched {pattern!r}")
    return wheels


def check_wheel(wheel_path: pathlib.Path, targets: list[str]) -> list[str]:
    failures: list[str] = []
    with zipfile.ZipFile(wheel_path) as zf:
        names = set(zf.namelist())
    if not any(
        "/" not in name and name.startswith(MYPYC_RUNTIME_MODULE) and name.endswith(NATIVE_SUFFIXES)
        for name in names
    ):
        failures.append(
            f"{wheel_path.name}: missing top-level {MYPYC_RUNTIME_MODULE} runtime artifact"
        )
    for py_path in targets:
        ext_prefix = py_path[:-3]  # strip .py
        has_compiled = any(
            name.startswith(ext_prefix) and name.endswith(NATIVE_SUFFIXES) for name in names
        )
        if not has_compiled:
            failures.append(f"{wheel_path.name}: missing compiled artifact for {py_path}")
    return failures


def main(argv: list[str]) -> int:
    if len(argv) < 2:
        print("usage: check_mypyc_wheel.py dist/*.whl")
        return 2
    targets = expand_mypyc_targets(ROOT)
    failures: list[str] = []
    wheels = resolve_wheels(argv[1:])
    if not wheels:
        return 1
    for wheel in wheels:
        failures.extend(check_wheel(wheel, targets))
    if failures:
        for failure in failures:
            print(f"FAIL: {failure}")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
