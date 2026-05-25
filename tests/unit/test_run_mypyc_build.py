from __future__ import annotations

import importlib.util
from pathlib import Path

MODULE_PATH = Path(__file__).resolve().parents[2] / "scripts" / "run_mypyc_build.py"
SPEC = importlib.util.spec_from_file_location("run_mypyc_build", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
run_mypyc_build = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(run_mypyc_build)


def test_build_mypyc_command_contains_targets_and_flags() -> None:
    command = run_mypyc_build.build_mypyc_command()

    assert command[0] == "mypyc"
    assert "dank_mids/_batch.py" in command
    assert "dank_mids/helpers/_retry_mechanics.py" in command
    assert "dank_mids/stats/__init__.py" in command
    assert "--strict" in command
    assert "--pretty" in command
    assert "--disable-error-code=unused-ignore" in command


def test_main_runs_compile_without_installing_dependencies(monkeypatch) -> None:
    calls: list[Path] = []

    def fake_run(root: Path) -> None:
        calls.append(root)

    monkeypatch.setattr(run_mypyc_build, "run_mypyc", fake_run)

    rc = run_mypyc_build.main([])

    assert rc == 0
    assert calls == [run_mypyc_build.ROOT]
