# sourcery skip: use-contextlib-suppress
from dataclasses import dataclass
from typing import Optional

from dank_mids.brownie_patch.types import (
    DankContractCall,
    DankContractMethod,
    DankContractTx,
    DankOverloadedMethod,
)
from dank_mids.helpers import setup_dank_w3_from_sync

__all__ = ["DankContractCall", "DankContractMethod", "DankContractTx", "DankOverloadedMethod"]

from dank_mids.eth import DankEth
from dank_mids.helpers._helpers import DankWeb3

@dataclass(frozen=True)
class BrowniePatchStatus:
    connected: bool
    initialized: bool
    import_error: Optional[ImportError]


_brownie_import_error: Optional[ImportError] = None
_brownie_connected: bool = False
_brownie_initialized: bool = False

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
    global _brownie_import_error
    global _brownie_connected
    global _brownie_initialized
    global dank_web3
    global dank_eth

    if _brownie_initialized or _brownie_import_error is not None:
        return get_brownie_patch_status()

    try:
        from brownie import network, web3
    except ImportError as exc:
        _brownie_import_error = exc
        _brownie_connected = False
        _brownie_initialized = False
        return get_brownie_patch_status()

    _brownie_connected = network.is_connected()
    if not _brownie_connected:
        _brownie_initialized = False
        return get_brownie_patch_status()

    try:
        from dank_mids.brownie_patch.contract import Contract, patch_contract
    except ImportError as exc:
        _brownie_import_error = exc
        _brownie_initialized = False
        return get_brownie_patch_status()

    dank_web3 = setup_dank_w3_from_sync(web3)
    dank_eth = dank_web3.eth
    __all__ += ["Contract", "patch_contract", "dank_web3", "dank_eth"]
    _brownie_initialized = True
    return get_brownie_patch_status()


def get_brownie_patch_status(refresh_connection: bool = False) -> BrowniePatchStatus:
    global _brownie_import_error
    global _brownie_connected

    if refresh_connection and _brownie_import_error is None:
        try:
            from brownie import network
        except ImportError as exc:
            _brownie_import_error = exc
            _brownie_connected = False
        else:
            _brownie_connected = network.is_connected()

    return BrowniePatchStatus(
        connected=_brownie_connected,
        initialized=_brownie_initialized,
        import_error=_brownie_import_error,
    )


# If using dank_mids with brownie, and brownie is connected when this file executes, you will get a 'dank_w3' async web3 instance with Dank Middleware here.
initialize_brownie_patch()
