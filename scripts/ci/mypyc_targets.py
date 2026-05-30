"""Shared mypyc build inputs for CI, release builds, and wheel checks."""

from __future__ import annotations

import os
import pathlib
import subprocess
import sys
import sysconfig
from typing import Any

ROOT = pathlib.Path(__file__).resolve().parents[2]

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

MYPYC_FLAGS = [
    "--pretty",
    # Keep mypyc as an optimization build step; regular MyPy debt is checked separately.
    "--disable-error-code=unused-ignore",
    "--disable-error-code=arg-type",
    "--disable-error-code=assignment",
    "--disable-error-code=attr-defined",
    "--disable-error-code=call-arg",
    "--disable-error-code=empty-body",
    "--disable-error-code=index",
    "--disable-error-code=import-untyped",
    "--disable-error-code=misc",
    "--disable-error-code=name-defined",
    "--disable-error-code=no-redef",
    "--disable-error-code=operator",
    "--disable-error-code=override",
    "--disable-error-code=return-value",
    "--disable-error-code=type-arg",
    "--disable-error-code=type-var",
    "--disable-error-code=typeddict-item",
    "--disable-error-code=union-attr",
    "--disable-error-code=valid-type",
    "--disable-error-code=var-annotated",
]
MYPYC_ENV = {"MYPYC_STRICT_DUNDER_TYPING": "1"}
MYPYC_BUILD_ARGS = [*MYPYC_TARGETS, *MYPYC_FLAGS]
MYPYC_SETUP = """\
from __future__ import annotations

import os

from mypyc.build import mypycify
from setuptools import setup
from setuptools.dist import Distribution


def _ignore_project_config(self, filenames=None, ignore_option_errors=False):
    return None


Distribution.parse_config_files = _ignore_project_config

setup(
    name="mypyc_output",
    packages=[],
    ext_modules=mypycify(
        {build_args!r},
        opt_level=os.getenv("MYPYC_OPT_LEVEL", "3"),
        debug_level=os.getenv("MYPYC_DEBUG_LEVEL", "1"),
        strict_dunder_typing=bool(int(os.getenv("MYPYC_STRICT_DUNDER_TYPING", "0"))),
        log_trace=bool(int(os.getenv("MYPYC_LOG_TRACE", "0"))),
    ),
)
"""

VENDORED_AIOLIMITER_ROOT = pathlib.PurePosixPath("dank_mids/_vendor/aiolimiter")


def _load_toml(path: pathlib.Path) -> dict[str, Any]:
    if sys.version_info >= (3, 11):
        import tomllib
    else:
        import tomli as tomllib

    with path.open("rb") as file:
        return tomllib.load(file)


def build_dependencies(root: pathlib.Path = ROOT) -> list[str]:
    pyproject = _load_toml(root / "pyproject.toml")
    dependency_groups = pyproject.get("dependency-groups", {})
    if not isinstance(dependency_groups, dict):
        raise TypeError("[dependency-groups] must be a table")

    build_group = dependency_groups.get("build")
    if not isinstance(build_group, list):
        raise TypeError("[dependency-groups].build must be a list")
    if not all(isinstance(dependency, str) for dependency in build_group):
        raise TypeError("[dependency-groups].build must contain only dependency strings")
    return list(build_group)


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


def module_name_from_target(target: str) -> str:
    path = pathlib.PurePosixPath(target)
    if path.suffix != ".py":
        raise ValueError(f"Mypyc target is not a Python file: {target}")
    module_path = path.with_suffix("")
    parts = module_path.parts
    if parts[-1] == "__init__":
        parts = parts[:-1]
    return ".".join(parts)


def compiled_module_names(root: pathlib.Path) -> list[str]:
    return [module_name_from_target(target) for target in expand_mypyc_targets(root)]


def build_mypyc_command() -> list[str]:
    return [sys.executable, "build/setup.py", "build_ext", "--inplace"]


def run_mypyc(root: pathlib.Path) -> None:
    build_dir = root / "build"
    build_dir.mkdir(exist_ok=True)
    (build_dir / "setup.py").write_text(MYPYC_SETUP.format(build_args=MYPYC_BUILD_ARGS))
    env = os.environ.copy()
    env.update(MYPYC_ENV)
    subprocess.run(build_mypyc_command(), cwd=root, env=env, check=True)


def extension_suffix() -> str:
    return sysconfig.get_config_var("EXT_SUFFIX") or (".pyd" if os.name == "nt" else ".so")


def compiled_artifact_patterns(root: pathlib.Path) -> list[str]:
    suffix = extension_suffix()
    patterns = [f"/*__mypyc*{suffix}"]
    for target in expand_mypyc_targets(root):
        prefix = pathlib.PurePosixPath(target).with_suffix("")
        patterns.append(f"/{prefix}*{suffix}")
    return patterns


def mypyc_runtime_artifacts(root: pathlib.Path) -> list[pathlib.Path]:
    suffix = extension_suffix()
    return sorted(path for path in root.glob(f"*__mypyc*{suffix}") if path.is_file())


def mypyc_runtime_force_include(root: pathlib.Path) -> dict[str, str]:
    return {str(path): path.name for path in mypyc_runtime_artifacts(root)}


def clean_compiled_artifacts(root: pathlib.Path) -> None:
    suffix = extension_suffix()
    vendor_root = root / VENDORED_AIOLIMITER_ROOT
    paths: set[pathlib.Path] = set(root.glob(f"*__mypyc*{suffix}"))
    for pattern in compiled_artifact_patterns(root)[1:]:
        paths.update(root.glob(pattern.removeprefix("/")))
    for path in paths:
        if path.is_file() and not path.is_relative_to(vendor_root):
            path.unlink()
