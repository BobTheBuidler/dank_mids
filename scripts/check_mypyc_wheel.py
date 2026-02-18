#!/usr/bin/env python3
"""Fail release if compiled targets ship source .py alongside extensions."""

from __future__ import annotations

import pathlib
import shlex
import sys
import zipfile

ROOT = pathlib.Path(__file__).resolve().parents[1]
MAKEFILE = ROOT / "Makefile"


def load_mypyc_targets() -> list[str]:
    marker = "MYPYC_STRICT_DUNDER_TYPING=1 mypyc"
    lines = MAKEFILE.read_text().splitlines()
    cmd_lines: list[str] = []
    in_cmd = False
    for line in lines:
        if marker in line:
            in_cmd = True
            cmd_lines.append(line)
            continue
        if in_cmd:
            if not line.startswith(("\t", " ")):
                break
            cmd_lines.append(line)
            if not line.strip():
                break
    if not cmd_lines:
        raise SystemExit("Could not find mypyc command in Makefile")
    joined = " ".join(part.strip().rstrip("\\") for part in cmd_lines)
    after = joined.split(marker, 1)[1].strip()
    if not after:
        raise SystemExit("Mypyc command has no targets")
    tokens = shlex.split(after)
    targets: set[str] = set()
    for tok in tokens:
        if tok.startswith("-"):
            continue
        norm = tok.replace("\\", "/")
        path = ROOT / norm
        if norm.endswith(".py"):
            if not path.is_file():
                raise SystemExit(f"Mypyc target not found: {norm}")
            targets.add(norm)
            continue
        if path.is_dir():
            py_files = sorted(p for p in path.rglob("*.py") if p.is_file())
            if not py_files:
                raise SystemExit(f"Mypyc directory target has no .py files: {norm}")
            for py_file in py_files:
                targets.add(py_file.relative_to(ROOT).as_posix())
            continue
        raise SystemExit(f"Unsupported mypyc target: {norm}")
    return sorted(targets)


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
        if py_path in names:
            failures.append(
                f"{wheel_path.name}: source .py present for compiled target {py_path}"
            )
    return failures


def main(argv: list[str]) -> int:
    if len(argv) < 2:
        print("usage: check_mypyc_wheel.py dist/*.whl")
        return 2
    targets = load_mypyc_targets()
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
