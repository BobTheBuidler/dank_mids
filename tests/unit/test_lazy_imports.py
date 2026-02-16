import json
import os
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[2]


def _run(code: str) -> dict[str, object]:
    env = os.environ.copy()
    pythonpath = env.get("PYTHONPATH")
    if pythonpath:
        env["PYTHONPATH"] = f"{REPO_ROOT}{os.pathsep}{pythonpath}"
    else:
        env["PYTHONPATH"] = str(REPO_ROOT)
    result = subprocess.run(
        [sys.executable, "-c", code],
        cwd=REPO_ROOT,
        env=env,
        check=True,
        capture_output=True,
        text=True,
    )
    return json.loads(result.stdout)


def test_import_is_lazy() -> None:
    payload = _run(
        """
import json
import sys
import concurrent.futures.process as cfp

before = cfp.EXTRA_QUEUED_CALLS
import dank_mids
after = cfp.EXTRA_QUEUED_CALLS

print(json.dumps({
    "web3_loaded": "web3" in sys.modules,
    "brownie_loaded": "brownie" in sys.modules,
    "queued_before": before,
    "queued_after": after,
}))
"""
    )
    assert payload["web3_loaded"] is False
    assert payload["brownie_loaded"] is False
    assert payload["queued_before"] == payload["queued_after"]


def test_symbol_access_is_lazy() -> None:
    payload = _run(
        """
import json
import sys
import concurrent.futures.process as cfp

before = cfp.EXTRA_QUEUED_CALLS
import dank_mids
from dank_mids import BrownieNotConnectedError

web3_before = "web3" in sys.modules
block_semaphore = dank_mids.BlockSemaphore
web3_after = "web3" in sys.modules
after = cfp.EXTRA_QUEUED_CALLS

print(json.dumps({
    "web3_before": web3_before,
    "web3_after": web3_after,
    "queued_before": before,
    "queued_after": after,
    "error_name": BrownieNotConnectedError.__name__,
    "block_semaphore_name": block_semaphore.__name__,
}))
"""
    )
    assert payload["web3_before"] is False
    assert payload["web3_after"] is False
    assert payload["queued_after"] == payload["queued_before"]
    assert payload["error_name"] == "BrownieNotConnectedError"
    assert payload["block_semaphore_name"] == "BlockSemaphore"


def test_helpers_import_triggers_side_effects() -> None:
    helpers_source = (REPO_ROOT / "dank_mids" / "helpers" / "_helpers.py").read_text()
    assert "from dank_mids import _ensure_side_effects" in helpers_source
    assert "_ensure_side_effects()" in helpers_source
