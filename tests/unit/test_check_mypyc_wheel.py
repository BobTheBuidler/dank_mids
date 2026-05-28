from __future__ import annotations

import importlib.util
import zipfile
from pathlib import Path

MODULE_PATH = Path(__file__).resolve().parents[2] / "scripts" / "check_mypyc_wheel.py"
SPEC = importlib.util.spec_from_file_location("check_mypyc_wheel", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
check_mypyc_wheel = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(check_mypyc_wheel)

AIOLIMITER_INIT = "dank_mids/_vendor/aiolimiter/src/aiolimiter/__init__.py"
AIOLIMITER_LEAKYBUCKET = "dank_mids/_vendor/aiolimiter/src/aiolimiter/leakybucket.py"


def _write_wheel(tmp_path: Path, names: list[str]) -> Path:
    wheel = tmp_path / "dank_mids-0.0.0-py3-none-any.whl"
    with zipfile.ZipFile(wheel, "w") as zf:
        for name in names:
            zf.writestr(name, "")
    return wheel


def test_check_wheel_accepts_vendored_aiolimiter_compiled_artifacts(
    tmp_path: Path,
) -> None:
    wheel = _write_wheel(
        tmp_path,
        [
            "dank_mids/_vendor/aiolimiter/src/aiolimiter/"
            "__init__.cpython-312-x86_64-linux-gnu.so",
            "dank_mids/_vendor/aiolimiter/src/aiolimiter/leakybucket.cp312-win_amd64.pyd",
        ],
    )

    failures = check_mypyc_wheel.check_wheel(
        wheel, [AIOLIMITER_INIT, AIOLIMITER_LEAKYBUCKET]
    )

    assert failures == []


def test_check_wheel_reports_missing_vendored_aiolimiter_artifact(
    tmp_path: Path,
) -> None:
    wheel = _write_wheel(
        tmp_path,
        [
            "dank_mids/_vendor/aiolimiter/src/aiolimiter/"
            "__init__.cpython-312-x86_64-linux-gnu.so",
        ],
    )

    failures = check_mypyc_wheel.check_wheel(
        wheel, [AIOLIMITER_INIT, AIOLIMITER_LEAKYBUCKET]
    )

    assert failures == [
        f"{wheel.name}: missing compiled artifact for {AIOLIMITER_LEAKYBUCKET}"
    ]
