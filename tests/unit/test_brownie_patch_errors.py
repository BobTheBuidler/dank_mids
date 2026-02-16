import builtins
import importlib
import importlib.util
from pathlib import Path
import sys
import types

import pytest


def _clear_modules() -> None:
    for name in list(sys.modules):
        if name == "brownie" or name.startswith("brownie.") or name.startswith("dank_mids"):
            sys.modules.pop(name, None)


def _load_package(name: str, package_dir: Path) -> types.ModuleType:
    init_path = package_dir / "__init__.py"
    spec = importlib.util.spec_from_file_location(
        name,
        init_path,
        submodule_search_locations=[str(package_dir)],
    )
    if spec is None or spec.loader is None:
        raise RuntimeError(f"unable to load package spec for {name} from {init_path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


def _load_module(name: str, path: Path) -> types.ModuleType:
    spec = importlib.util.spec_from_file_location(name, path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"unable to load module spec for {name} from {path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


def _install_logging_stub() -> None:
    stub = types.ModuleType("dank_mids.logging")

    class _Logger:
        def exception(self, *args, **kwargs) -> None:
            return None

    def get_c_logger(name: str) -> _Logger:
        return _Logger()

    stub.get_c_logger = get_c_logger
    sys.modules["dank_mids.logging"] = stub


def _install_dank_mids_stubs() -> None:
    _eth_utils = types.ModuleType("dank_mids._eth_utils")

    def patch_eth_utils() -> None:
        return None

    _eth_utils.patch_eth_utils = patch_eth_utils
    sys.modules["dank_mids._eth_utils"] = _eth_utils

    controller = types.ModuleType("dank_mids.controller")
    controller.instances = object()
    sys.modules["dank_mids.controller"] = controller

    helpers_helpers = types.ModuleType("dank_mids.helpers._helpers")

    class DankWeb3: ...

    helpers_helpers.DankWeb3 = DankWeb3
    sys.modules["dank_mids.helpers._helpers"] = helpers_helpers

    eth = types.ModuleType("dank_mids.eth")

    class DankEth: ...

    eth.DankEth = DankEth
    sys.modules["dank_mids.eth"] = eth

    helpers = types.ModuleType("dank_mids.helpers")

    def setup_dank_w3(*args, **kwargs):
        return None

    def setup_dank_w3_from_sync(*args, **kwargs):
        class _StubW3:
            eth = DankEth()

        return _StubW3()

    helpers.setup_dank_w3 = setup_dank_w3
    helpers.setup_dank_w3_from_sync = setup_dank_w3_from_sync
    sys.modules["dank_mids.helpers"] = helpers

    middleware = types.ModuleType("dank_mids.middleware")
    middleware.dank_middleware = object()
    sys.modules["dank_mids.middleware"] = middleware

    semaphores = types.ModuleType("dank_mids.semaphores")

    class BlockSemaphore: ...

    semaphores.BlockSemaphore = BlockSemaphore
    sys.modules["dank_mids.semaphores"] = semaphores

    brownie_method = types.ModuleType("dank_mids.brownie_patch._method")
    from typing import Generic, TypeVar

    _EVMType = TypeVar("_EVMType")

    class _DankMethod: ...

    class _DankMethodMixin(Generic[_EVMType]): ...

    brownie_method._DankMethod = _DankMethod
    brownie_method._DankMethodMixin = _DankMethodMixin
    brownie_method._EVMType = _EVMType
    sys.modules["dank_mids.brownie_patch._method"] = brownie_method


def _make_import_blocker(block_name: str):
    original_import = builtins.__import__

    def _blocked(name, globals=None, locals=None, fromlist=(), level=0):
        if name == block_name:
            raise ImportError(f"blocked import: {block_name}")
        return original_import(name, globals, locals, fromlist, level)

    return _blocked


def _install_brownie_package(connected: bool) -> types.ModuleType:
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
    return network_mod


def _reload_dank_mids(monkeypatch, brownie_connected: bool | None = None, import_hook=None):
    _clear_modules()
    network_mod = None
    if brownie_connected is not None:
        network_mod = _install_brownie_package(brownie_connected)
    if import_hook is not None:
        monkeypatch.setattr(builtins, "__import__", import_hook)

    _install_logging_stub()
    _install_dank_mids_stubs()

    # Load pure-Python modules directly to avoid compiled extensions during tests.
    root = Path(__file__).resolve().parents[2]
    package_root = root / "dank_mids"
    brownie_patch_root = package_root / "brownie_patch"

    dank_pkg = types.ModuleType("dank_mids")
    dank_pkg.__path__ = [str(package_root)]
    sys.modules["dank_mids"] = dank_pkg

    brownie_pkg = types.ModuleType("dank_mids.brownie_patch")
    brownie_pkg.__path__ = [str(brownie_patch_root)]
    sys.modules["dank_mids.brownie_patch"] = brownie_pkg

    _load_module("dank_mids.exceptions", package_root / "exceptions.py")
    _load_package("dank_mids.brownie_patch", brownie_patch_root)
    return _load_package("dank_mids", package_root), network_mod


def test_getattr_raises_import_error_for_missing_brownie(monkeypatch) -> None:
    import_hook = _make_import_blocker("brownie")
    dank_mids, _ = _reload_dank_mids(monkeypatch, import_hook=import_hook)
    exc_types = importlib.import_module("dank_mids.exceptions")

    with pytest.raises(exc_types.BrowniePatchImportError) as excinfo:
        _ = dank_mids.dank_web3

    assert isinstance(excinfo.value.__cause__, ImportError)


def test_getattr_raises_not_connected(monkeypatch) -> None:
    dank_mids, _ = _reload_dank_mids(monkeypatch, brownie_connected=False)
    exc_types = importlib.import_module("dank_mids.exceptions")

    with pytest.raises(exc_types.BrownieNotConnectedError):
        _ = dank_mids.dank_web3


def test_getattr_raises_not_initialized_when_connected_after_import(monkeypatch) -> None:
    dank_mids, network = _reload_dank_mids(monkeypatch, brownie_connected=False)
    exc_types = importlib.import_module("dank_mids.exceptions")

    assert network is not None
    network.connected = True

    with pytest.raises(exc_types.BrowniePatchNotInitializedError):
        _ = dank_mids.dank_web3


def test_getattr_raises_import_error_when_patch_import_fails(monkeypatch) -> None:
    import_hook = _make_import_blocker("dank_mids.brownie_patch.contract")
    dank_mids, _ = _reload_dank_mids(
        monkeypatch,
        brownie_connected=True,
        import_hook=import_hook,
    )
    exc_types = importlib.import_module("dank_mids.exceptions")

    with pytest.raises(exc_types.BrowniePatchImportError) as excinfo:
        _ = dank_mids.dank_web3

    assert isinstance(excinfo.value.__cause__, ImportError)


def test_getattr_raises_import_error_for_missing_brownie_types(monkeypatch) -> None:
    import_hook = _make_import_blocker("brownie")
    dank_mids, _ = _reload_dank_mids(monkeypatch, import_hook=import_hook)
    exc_types = importlib.import_module("dank_mids.exceptions")

    with pytest.raises(exc_types.BrowniePatchImportError) as excinfo:
        _ = dank_mids.DankContractCall

    assert isinstance(excinfo.value.__cause__, ImportError)


def test_getattr_resolves_brownie_types(monkeypatch) -> None:
    dank_mids, _ = _reload_dank_mids(monkeypatch, brownie_connected=False)

    assert isinstance(dank_mids.DankContractCall, type)
