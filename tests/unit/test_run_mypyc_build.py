from __future__ import annotations

import importlib.util
import sys
from pathlib import Path

from scripts.ci.mypyc_targets import MYPYC_BUILD_ARGS, expand_mypyc_targets

MODULE_PATH = Path(__file__).resolve().parents[2] / "scripts" / "run_mypyc_build.py"
REPO_ROOT = Path(__file__).resolve().parents[2]
SPEC = importlib.util.spec_from_file_location("run_mypyc_build", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
run_mypyc_build = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(run_mypyc_build)


def test_build_mypyc_command_contains_targets_and_flags() -> None:
    command = run_mypyc_build.build_mypyc_command()

    assert command == [sys.executable, "build/setup.py", "build_ext", "--inplace"]
    assert "dank_mids/_batch.py" in MYPYC_BUILD_ARGS
    assert "dank_mids/helpers/_retry_mechanics.py" in MYPYC_BUILD_ARGS
    assert "dank_mids/stats/__init__.py" in MYPYC_BUILD_ARGS
    assert "dank_mids/_vendor/aiolimiter/src" in MYPYC_BUILD_ARGS
    assert "--pretty" in MYPYC_BUILD_ARGS
    assert "--disable-error-code=unused-ignore" in MYPYC_BUILD_ARGS
    assert "--disable-error-code=arg-type" in MYPYC_BUILD_ARGS
    assert "--disable-error-code=override" in MYPYC_BUILD_ARGS


def test_mypyc_targets_expand_vendored_aiolimiter_sources() -> None:
    expanded_targets = expand_mypyc_targets(REPO_ROOT)

    assert "dank_mids/_vendor/aiolimiter/src/aiolimiter/__init__.py" in expanded_targets
    assert "dank_mids/_vendor/aiolimiter/src/aiolimiter/leakybucket.py" in expanded_targets


def test_main_runs_compile_without_installing_dependencies(monkeypatch) -> None:
    calls: list[Path] = []

    def fake_run(root: Path) -> None:
        calls.append(root)

    monkeypatch.setattr(run_mypyc_build, "run_mypyc", fake_run)

    rc = run_mypyc_build.main([])

    assert rc == 0
    assert calls == [run_mypyc_build.ROOT]
