from contextlib import suppress

from web3.eth import AsyncEth

from dank_mids.helpers import setup_dank_w3_from_sync
from dank_mids.brownie_patch.types import (
    DankContractCall,
    DankContractMethod,
    DankContractTx,
    DankOverloadedMethod,
)

__all__ = ["DankContractCall", "DankContractMethod", "DankContractTx", "DankOverloadedMethod"]

from dank_mids.helpers._helpers import DankEth, DankWeb3

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

# If using dank_mids with brownie, and brownie is connected when this file executes, you will get a 'dank_w3' async web3 instance with Dank Middleware here.
with suppress(ImportError):
    from brownie import network, web3

    if network.is_connected():
        from dank_mids.brownie_patch.contract import Contract, patch_contract

        dank_web3 = setup_dank_w3_from_sync(web3)
        dank_eth = dank_web3.eth
        __all__ += ["Contract", "patch_contract", "dank_web3", "dank_eth"]
