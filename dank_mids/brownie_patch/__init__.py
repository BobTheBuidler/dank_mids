# sourcery skip: use-contextlib-suppress
from dataclasses import dataclass
from types import ModuleType
from typing import Optional

from dank_mids.helpers import setup_dank_w3_from_sync

_BROWNIE_TYPE_NAMES = (
    "DankContractCall",
    "DankContractMethod",
    "DankContractTx",
    "DankOverloadedMethod",
)
__all__ = list(_BROWNIE_TYPE_NAMES)

from dank_mids.eth import DankEth
from dank_mids.helpers._helpers import DankWeb3


@dataclass(frozen=True)
class BrowniePatchStatus:
    connected: bool
    initialized: bool
    import_error: ImportError | None


@dataclass
class _BrowniePatchState:
    import_error: ImportError | None = None
    connected: bool = False
    initialized: bool = False

    def status(self) -> BrowniePatchStatus:
        return BrowniePatchStatus(
            connected=self.connected,
            initialized=self.initialized,
            import_error=self.import_error,
        )

    def set_brownie_import_error(self, exc: ImportError) -> BrowniePatchStatus:
        self.import_error = exc
        self.connected = False
        self.initialized = False
        return self.status()

    def set_patch_import_error(self, exc: ImportError) -> BrowniePatchStatus:
        self.import_error = exc
        self.initialized = False
        return self.status()

    def refresh_connection(self) -> None:
        if self.import_error is not None:
            return
        try:
            from brownie import network
        except ImportError as exc:
            self.set_brownie_import_error(exc)
        else:
            self.connected = network.is_connected()


_STATE = _BrowniePatchState()

dank_web3: DankWeb3
"""
An instance of :py:class:`~DankWeb3`, which is a wrapper around brownie’s standard Web3 object with Dank Middleware injected.
This is initialized if Brownie is installed and connected when this module is loaded.
If Brownie is not installed or not connected to an RPC, this instance will not be available.
"""

dank_eth: DankEth
"""
An instance of :py:class:`~DankEth`, providing access to Ethereum blockchain methods via :py:const:`dank_web3`.
This is initialized if Brownie is installed and connected when this module is loaded.
If Brownie is not installed or not connected to an RPC, this instance will not be available.
"""


def initialize_brownie_patch() -> BrowniePatchStatus:
    global dank_web3
    global dank_eth

    state = _coerce_state()
    if state.initialized or state.import_error is not None:
        return state.status()

    try:
        from brownie import network, web3
    except ImportError as exc:
        return state.set_brownie_import_error(exc)

    state.connected = network.is_connected()
    if not state.connected:
        state.initialized = False
        return state.status()

    try:
        from dank_mids.brownie_patch.contract import Contract, patch_contract
    except ImportError as exc:
        return state.set_patch_import_error(exc)

    globals()["Contract"] = Contract
    globals()["patch_contract"] = patch_contract
    dank_web3 = setup_dank_w3_from_sync(web3)
    dank_eth = dank_web3.eth
    __all__ += ["Contract", "patch_contract", "dank_web3", "dank_eth"]
    state.initialized = True
    return state.status()


def get_brownie_patch_status(refresh_connection: bool = False) -> BrowniePatchStatus:
    state = _coerce_state()
    if refresh_connection:
        state.refresh_connection()
    return state.status()


def _coerce_state() -> _BrowniePatchState:
    raw_state = globals().get("_STATE")
    if type(raw_state) is _BrowniePatchState:
        return raw_state

    # mypyc methods require exact native-class identity for `self`.
    state = _BrowniePatchState()
    if raw_state is not None:
        import_error = getattr(raw_state, "import_error", None)
        if isinstance(import_error, ImportError):
            state.import_error = import_error
        state.connected = bool(getattr(raw_state, "connected", False))
        # A foreign state object cannot prove patch exports are initialized.
        state.initialized = False

    globals()["_STATE"] = state
    return state


def _load_types() -> ModuleType:
    from dank_mids.brownie_patch import types as _types

    return _types


def __getattr__(name: str) -> object:
    if name in _BROWNIE_TYPE_NAMES:
        _types = _load_types()
        value = getattr(_types, name)
        globals()[name] = value
        return value
    raise AttributeError(f"module '{__name__}' has no attribute '{name}'")


# If using dank_mids with brownie, and brownie is connected when this file executes, you will get a 'dank_w3' async web3 instance with Dank Middleware here.
initialize_brownie_patch()
