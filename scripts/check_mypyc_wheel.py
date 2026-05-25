#!/usr/bin/env python3
"""Fail release if compiled targets are missing compiled extensions."""

from __future__ import annotations

import pathlib
import sys
import zipfile

ROOT = pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from scripts.ci.mypyc_targets import expand_mypyc_targets  # noqa: E402


def check_wheel(wheel_path: pathlib.Path, targets: list[str]) -> list[str]:
    failures: list[str] = []
    with zipfile.ZipFile(wheel_path) as zf:
        names = set(zf.namelist())
    for py_path in targets:
        ext_prefix = py_path[:-3]  # strip .py
        has_compiled = any(
            name.startswith(ext_prefix) and name.endswith((".so", ".pyd")) for name in names
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
    for wheel in argv[1:]:
        failures.extend(check_wheel(pathlib.Path(wheel), targets))
    if failures:
        for failure in failures:
            print(f"FAIL: {failure}")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
