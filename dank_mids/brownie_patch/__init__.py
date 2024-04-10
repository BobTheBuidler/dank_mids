
from contextlib import suppress

from dank_mids.helpers import setup_dank_w3_from_sync
from dank_mids.brownie_patch.types import DankContractCall, DankContractMethod, DankContractTx, DankOverloadedMethod

__all__ = ["DankContractCall", "DankContractMethod", "DankContractTx", "DankOverloadedMethod"]

# If using dank_mids wih brownie, and brownie is connected when this file executes, you will get a 'dank_w3' async web3 instance with Dank Middleware here.
with suppress(ImportError)
    from brownie import network, web3

    if network.is_connected():
        from dank_mids.brownie_patch.contract import Contract, patch_contract
        from web3.eth import AsyncEth as _AsyncEth

        dank_web3 = setup_dank_w3_from_sync(web3)
        dank_eth: _AsyncEth = dank_web3.eth

        __all__ += ["Contract", "patch_contract", "dank_web3", "dank_eth"]
