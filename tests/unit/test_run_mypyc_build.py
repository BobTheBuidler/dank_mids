from __future__ import annotations

import importlib.util
import os
from pathlib import Path

MODULE_PATH = Path(__file__).resolve().parents[2] / "scripts" / "run_mypyc_build.py"
SPEC = importlib.util.spec_from_file_location("run_mypyc_build", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
run_mypyc_build = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(run_mypyc_build)


def test_build_install_command_uses_requirements_file() -> None:
    command = run_mypyc_build.build_install_command("python3")

    assert command[:4] == ["python3", "-m", "pip", "install"]
    assert command[-2] == "-r"
    assert command[-1].endswith("requirements-build.txt")


def test_build_mypyc_command_contains_targets_and_flags() -> None:
    command = run_mypyc_build.build_mypyc_command()

    assert command[0] == "mypyc"
    assert "dank_mids/_batch.py" in command
    assert "dank_mids/helpers/_retry_mechanics.py" in command
    assert "dank_mids/stats/__init__.py" in command
    assert "--strict" in command
    assert "--pretty" in command
    assert "--disable-error-code=unused-ignore" in command


def test_main_runs_install_then_compile(monkeypatch) -> None:
    calls: list[tuple[list[str], dict[str, str] | None]] = []

    def fake_run(command: list[str], *, env: dict[str, str] | None = None) -> None:
        calls.append((command, env))

    monkeypatch.setattr(run_mypyc_build, "run_checked", fake_run)

    rc = run_mypyc_build.main(["--python", "py"])

    assert rc == 0
    assert len(calls) == 2
    assert calls[0][0][:2] == ["py", "-m"]
    assert calls[1][0][0] == "mypyc"
    assert calls[1][1] is not None
    assert calls[1][1]["MYPYC_STRICT_DUNDER_TYPING"] == "1"
    assert calls[1][1]["PATH"] == os.environ["PATH"]
