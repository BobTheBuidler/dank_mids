#!/usr/bin/env python3
"""Clean, build, and optionally stage source-tree mypyc extensions for CI."""

from __future__ import annotations

import argparse
import pathlib
import shutil
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from scripts.ci.mypyc_targets import (  # noqa: E402
    clean_compiled_artifacts,
    compiled_artifact_patterns,
    run_mypyc,
)


def clean_build_intermediates(root: pathlib.Path) -> list[pathlib.Path]:
    build_dir = root / "build"
    removed: list[pathlib.Path] = []
    for pattern in ("lib.*", "temp.*"):
        for path in sorted(build_dir.glob(pattern)):
            if path.is_dir():
                shutil.rmtree(path)
                removed.append(path.relative_to(root))
    return removed


def copy_compiled_artifacts(root: pathlib.Path, artifact_dir: pathlib.Path) -> list[pathlib.Path]:
    artifact_dir.mkdir(parents=True, exist_ok=True)
    copied: list[pathlib.Path] = []
    for pattern in compiled_artifact_patterns(root):
        for source in sorted(root.glob(pattern.removeprefix("/"))):
            if not source.is_file():
                continue
            relative = source.relative_to(root)
            destination = artifact_dir / relative
            destination.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(source, destination)
            copied.append(relative)
    return copied


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--artifact-dir",
        type=pathlib.Path,
        help="Directory where compiled source-tree extensions should be staged.",
    )
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    clean_compiled_artifacts(ROOT)
    clean_build_intermediates(ROOT)
    run_mypyc(ROOT)
    if args.artifact_dir is not None:
        copied = copy_compiled_artifacts(ROOT, args.artifact_dir)
        print(f"staged {len(copied)} compiled extension artifact(s)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
