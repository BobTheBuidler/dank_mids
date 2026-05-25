"""Shared mypyc build inputs for CI, release builds, and wheel checks."""

from __future__ import annotations

import os
import pathlib
import subprocess

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
MYPYC_ENV = {"MYPYC_STRICT_DUNDER_TYPING": "1"}

BUILD_DEPENDENCIES = [
    "eth-retry==0.3.7",
    "eth-typing==5.2.1",
    "ez-a-sync==0.34.2",
    "faster-eth-abi==5.2.27",
    "faster-hexbytes==1.3.6",
    "mypy[mypyc]==1.20.2",
    "setuptools",
    "typed-envs==0.2.4",
    "types-requests",
]

COMPILED_ARTIFACT_PATTERNS = [
    "*__mypyc*.pyd",
    "*__mypyc*.so",
    "dank_mids/**/*.pyd",
    "dank_mids/**/*.so",
]


def expand_mypyc_targets(root: pathlib.Path) -> list[str]:
    targets: set[str] = set()
    for target in MYPYC_TARGETS:
        path = root / target
        if target.endswith(".py"):
            if not path.is_file():
                raise FileNotFoundError(f"Mypyc target not found: {target}")
            targets.add(target)
            continue
        if path.is_dir():
            py_files = sorted(p for p in path.rglob("*.py") if p.is_file())
            if not py_files:
                raise FileNotFoundError(f"Mypyc directory target has no .py files: {target}")
            targets.update(py_file.relative_to(root).as_posix() for py_file in py_files)
            continue
        raise FileNotFoundError(f"Unsupported mypyc target: {target}")
    return sorted(targets)


def build_mypyc_command() -> list[str]:
    return ["mypyc", *MYPYC_TARGETS, *MYPYC_FLAGS]


def run_mypyc(root: pathlib.Path) -> None:
    env = os.environ.copy()
    env.update(MYPYC_ENV)
    subprocess.run(build_mypyc_command(), cwd=root, env=env, check=True)


def clean_compiled_artifacts(root: pathlib.Path) -> None:
    for pattern in COMPILED_ARTIFACT_PATTERNS:
        for path in root.glob(pattern):
            if path.is_file():
                path.unlink()


def compiled_artifact_patterns() -> list[str]:
    return [f"/{pattern}" for pattern in COMPILED_ARTIFACT_PATTERNS]
