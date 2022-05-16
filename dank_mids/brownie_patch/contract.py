
from typing import Optional

from dank_mids.brownie_patch.call import _patch_call
from dank_mids.brownie_patch.tx import _patch_tx
from web3 import Web3

from brownie import Contract, network, web3
from brownie.network.contract import ContractCall, ContractTx


def patch_contract(contract: Contract, w3: Optional[Web3]) -> Contract:
    if w3 is None and network.is_connected():
        w3 = web3
    assert w3 is not None, "You must make sure either brownie is connected or you pass in a Web3 instance."
    for k, v in contract.__dict__.items():
        if isinstance(v, ContractCall):
            _patch_call(v, w3)
        # TODO implement this properly
        #elif isinstance(v, ContractTx):
        #    _patch_tx(v, w3)
    return contract
