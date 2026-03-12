#!/usr/bin/env python3
"""Build-workflow-only mypyc runner."""

from __future__ import annotations

import argparse
import os
import pathlib
import shlex
import subprocess
from typing import Iterable

ROOT = pathlib.Path(__file__).resolve().parents[1]
MYPYC_DEPS_FILE = ROOT / "requirements-build.txt"

MYPYC_TARGETS = [
    "dank_mids/_batch.py",
    "dank_mids/_demo_mode.py",
    "dank_mids/_envs.py",
    "dank_mids/_eth_utils.py",
    "dank_mids/_exceptions.py",
    "dank_mids/_tasks.py",
    "dank_mids/_uid.py",
    "dank_mids/_vendor/aiolimiter/src",
    "dank_mids/_web3/abi.py",
    "dank_mids/_web3/formatters.py",
    "dank_mids/brownie_patch/__init__.py",
    "dank_mids/brownie_patch/_abi.py",
    "dank_mids/brownie_patch/call.py",
    "dank_mids/brownie_patch/overloaded.py",
    "dank_mids/brownie_patch/types.py",
    "dank_mids/constants.py",
    "dank_mids/controller.py",
    "dank_mids/ENVIRONMENT_VARIABLES.py",
    "dank_mids/helpers/__init__.py",
    "dank_mids/helpers/_codec.py",
    "dank_mids/helpers/_errors.py",
    "dank_mids/helpers/_gather.py",
    "dank_mids/helpers/_rate_limit.py",
    "dank_mids/helpers/_retry_mechanics.py",
    "dank_mids/helpers/_requester.py",
    "dank_mids/helpers/_weaklist.py",
    "dank_mids/helpers/batch_size.py",
    "dank_mids/helpers/hashing.py",
    "dank_mids/helpers/lru_cache.py",
    "dank_mids/helpers/method.py",
    "dank_mids/lock.py",
    "dank_mids/logging.py",
    "dank_mids/middleware.py",
    "dank_mids/stats/__init__.py",
]

MYPYC_FLAGS = ["--strict", "--pretty", "--disable-error-code=unused-ignore"]


def build_install_command(python_executable: str) -> list[str]:
    return [python_executable, "-m", "pip", "install", "-r", str(MYPYC_DEPS_FILE)]


def build_mypyc_command() -> list[str]:
    return ["mypyc", *MYPYC_TARGETS, *MYPYC_FLAGS]


def run_checked(command: list[str], *, env: dict[str, str] | None = None) -> None:
    subprocess.run(command, check=True, cwd=ROOT, env=env)


def format_command(command: Iterable[str]) -> str:
    return " ".join(shlex.quote(part) for part in command)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--python",
        default=os.environ.get("PYTHON", "python"),
        help="Python executable used for dependency install.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Print commands without executing them.",
    )
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    install_command = build_install_command(args.python)
    mypyc_command = build_mypyc_command()

    if args.dry_run:
        print(format_command(install_command))
        print(format_command(mypyc_command))
        return 0

    run_checked(install_command)
    compile_env = os.environ.copy()
    compile_env["MYPYC_STRICT_DUNDER_TYPING"] = "1"
    run_checked(mypyc_command, env=compile_env)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
