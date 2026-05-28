#!/usr/bin/env python3
"""Remove source-tree extension artifacts without touching vendored binaries."""

from __future__ import annotations

import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from scripts.ci.mypyc_targets import clean_compiled_artifacts  # noqa: E402


def main() -> int:
    clean_compiled_artifacts(ROOT)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
