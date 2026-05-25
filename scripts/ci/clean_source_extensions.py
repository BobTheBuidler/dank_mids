#!/usr/bin/env python3
"""Remove source-tree extension artifacts before source-only test runs."""

from __future__ import annotations

import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[2]
PATTERNS = (
    "*__mypyc*.pyd",
    "*__mypyc*.so",
    "dank_mids/**/*.pyd",
    "dank_mids/**/*.so",
)


def main() -> int:
    removed = 0
    for pattern in PATTERNS:
        for path in ROOT.glob(pattern):
            if path.is_file():
                path.unlink()
                removed += 1
    print(f"removed {removed} source extension artifact(s)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
