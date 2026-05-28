#!/usr/bin/env python3
"""Build-workflow-only mypyc runner."""

from __future__ import annotations

import argparse
import pathlib
import shlex
import sys

ROOT = pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from scripts.ci.mypyc_targets import build_mypyc_command, run_mypyc  # noqa: E402


def format_command(command: list[str]) -> str:
    return shlex.join(command)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Print the mypyc command without executing it.",
    )
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    command = build_mypyc_command()
    if args.dry_run:
        print(format_command(command))
        return 0

    run_mypyc(ROOT)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
