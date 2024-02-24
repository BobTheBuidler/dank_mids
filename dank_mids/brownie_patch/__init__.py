
from dank_mids.helpers import setup_dank_w3_from_sync

# If using dank_mids wih brownie, and brownie is connected when this file executes, you will get a 'dank_w3' async web3 instance with Dank Middleware here.
try:
    from brownie import network, web3
    if network.is_connected():
        from dank_mids.brownie_patch.contract import Contract, patch_contract
        from web3.eth import AsyncEth as _AsyncEth
        dank_web3 = setup_dank_w3_from_sync(web3)
        dank_eth: _AsyncEth = dank_web3.eth
except ImportError:
    pass