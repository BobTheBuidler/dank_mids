import importlib
import importlib.machinery
import os
import sys
import types

import pytest


_EXT_SUFFIXES = tuple(importlib.machinery.EXTENSION_SUFFIXES)


def _clear_modules() -> None:
    for name in list(sys.modules):
        if name == "brownie" or name.startswith("brownie.") or name.startswith("dank_mids"):
            sys.modules.pop(name, None)


def _install_brownie_stub(connected: bool) -> None:
    brownie = types.ModuleType("brownie")
    network_mod = types.ModuleType("brownie.network")
    contract_mod = types.ModuleType("brownie.network.contract")
    typing_mod = types.ModuleType("brownie.typing")

    network_mod.connected = connected

    def is_connected() -> bool:
        return network_mod.connected

    network_mod.is_connected = is_connected

    class ContractCall: ...

    class ContractTx: ...

    class OverloadedMethod: ...

    contract_mod.ContractCall = ContractCall
    contract_mod.ContractTx = ContractTx
    contract_mod.OverloadedMethod = OverloadedMethod

    typing_mod.AccountsType = object

    network_mod.contract = contract_mod
    brownie.network = network_mod
    brownie.web3 = object()
    brownie.typing = typing_mod

    sys.modules["brownie"] = brownie
    sys.modules["brownie.network"] = network_mod
    sys.modules["brownie.network.contract"] = contract_mod
    sys.modules["brownie.typing"] = typing_mod


def _is_extension(path: str | None) -> bool:
    if path is None:
        return False
    return path.endswith(_EXT_SUFFIXES)


@pytest.mark.skipif(
    os.environ.get("DANK_MIDS_REQUIRE_COMPILED") != "1",
    reason="compiled-only test",
)
def test_brownie_patch_status_compiled() -> None:
    _clear_modules()
    _install_brownie_stub(connected=False)

    module = importlib.import_module("dank_mids.brownie_patch")
    assert _is_extension(module.__file__), (
        f"expected compiled module, got {module.__file__!r}"
    )

    status = module.get_brownie_patch_status(refresh_connection=True)
    assert status.import_error is None
