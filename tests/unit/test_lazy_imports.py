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
error_cls = dank_mids.BrownieNotConnectedError
web3_after = "web3" in sys.modules
after = cfp.EXTRA_QUEUED_CALLS

print(json.dumps({
    "web3_before": web3_before,
    "web3_after": web3_after,
    "queued_before": before,
    "queued_after": after,
    "error_name": BrownieNotConnectedError.__name__,
    "error_attr_name": error_cls.__name__,
}))
"""
    )
    assert payload["web3_before"] is False
    assert payload["web3_after"] is False
    assert payload["queued_after"] == payload["queued_before"]
    assert payload["error_name"] == "BrownieNotConnectedError"
    assert payload["error_attr_name"] == "BrownieNotConnectedError"


def test_helpers_import_is_lazy() -> None:
    payload = _run(
        """
import json
import sys
import concurrent.futures.process as cfp
import importlib.util
from pathlib import Path

repo_root = Path.cwd()
helpers_path = repo_root / "dank_mids" / "helpers" / "__init__.py"
spec = importlib.util.spec_from_file_location("dank_mids.helpers", helpers_path)
module = importlib.util.module_from_spec(spec)
sys.modules["dank_mids.helpers"] = module

before = cfp.EXTRA_QUEUED_CALLS
spec.loader.exec_module(module)
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


def test_helpers_access_triggers_side_effects() -> None:
    payload = _run(
        """
import json
import sys
import types
import importlib.util
from pathlib import Path

import dank_mids

called = {"value": False}
def fake_side_effects():
    called["value"] = True
dank_mids._ensure_side_effects = fake_side_effects

helpers_stub = types.ModuleType("dank_mids.helpers._helpers")
helpers_stub.setup_dank_w3 = lambda *args, **kwargs: None
helpers_stub.setup_dank_w3_from_sync = lambda *args, **kwargs: None
sys.modules["dank_mids.helpers._helpers"] = helpers_stub

repo_root = Path.cwd()
helpers_path = repo_root / "dank_mids" / "helpers" / "__init__.py"
spec = importlib.util.spec_from_file_location("dank_mids.helpers", helpers_path)
module = importlib.util.module_from_spec(spec)
sys.modules["dank_mids.helpers"] = module
spec.loader.exec_module(module)

_ = module.setup_dank_w3

print(json.dumps({
    "called": called["value"],
}))
"""
    )
    assert payload["called"] is True
