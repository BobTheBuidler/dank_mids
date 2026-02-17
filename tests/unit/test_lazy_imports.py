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


def test_import_applies_side_effects() -> None:
    payload = _run("""
import json
import concurrent.futures.process as cfp

before = cfp.EXTRA_QUEUED_CALLS
import dank_mids
after = cfp.EXTRA_QUEUED_CALLS

print(json.dumps({
    "queued_before": before,
    "queued_after": after,
}))
""")
    assert payload["queued_after"] == 50_000


def test_brownie_error_accessible() -> None:
    payload = _run("""
import json

import dank_mids
from dank_mids import BrownieNotConnectedError

error_cls = dank_mids.BrownieNotConnectedError

print(json.dumps({
    "error_name": BrownieNotConnectedError.__name__,
    "error_attr_name": error_cls.__name__,
}))
""")
    assert payload["error_name"] == "BrownieNotConnectedError"
    assert payload["error_attr_name"] == "BrownieNotConnectedError"


def test_helpers_import_applies_side_effects() -> None:
    payload = _run("""
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
    "queued_before": before,
    "queued_after": after,
}))
""")
    assert payload["queued_after"] == 50_000


def test_helpers_import_triggers_side_effects() -> None:
    payload = _run("""
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

print(json.dumps({
    "called": called["value"],
}))
""")
    assert payload["called"] is True


def test_eth_alias_survives_submodule_import() -> None:
    payload = _run("""
import json
import sys
import types
import importlib
from importlib.machinery import ModuleSpec

class StubEth:
    async def get_code(self, *args, **kwargs):
        return b""

stub = StubEth()
stub_module = types.ModuleType("dank_mids.brownie_patch")
stub_module.DankContractCall = object()
stub_module.DankContractMethod = object()
stub_module.DankContractTx = object()
stub_module.DankOverloadedMethod = object()
stub_module.dank_eth = stub
sys.modules["dank_mids.brownie_patch"] = stub_module

import dank_mids
dank_mids._ensure_side_effects = lambda: None

resolved = dank_mids.dank_eth

class _EthLoader:
    def create_module(self, spec):
        return None

    def exec_module(self, module):
        module.__dict__["__test_stub__"] = True


class _EthFinder:
    def find_spec(self, fullname, path, target=None):
        if fullname == "dank_mids.eth":
            return ModuleSpec(fullname, _EthLoader())
        return None


sys.meta_path.insert(0, _EthFinder())

importlib.import_module("dank_mids.eth")

eth_attr = getattr(dank_mids, "eth", None)
get_code = getattr(eth_attr, "get_code", None)

print(json.dumps({
    "same_object": eth_attr is resolved,
    "get_code_callable": callable(get_code),
    "get_code_is_bound": getattr(get_code, "__self__", None) is resolved,
}))
""")
    assert payload["same_object"] or (payload["get_code_callable"] and payload["get_code_is_bound"])
