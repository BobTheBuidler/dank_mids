
from typing import Optional, Union

from brownie import Contract, network, web3
from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod
from dank_mids.brownie_patch.call import _patch_call
from dank_mids.brownie_patch.overloaded import _patch_overloaded_method
from web3 import Web3

ContractMethod = Union[ContractCall, ContractTx, OverloadedMethod]

def _patch_if_method(method: ContractMethod, w3: Web3):
    if isinstance(method, ContractCall) or isinstance(method, ContractTx):
        _patch_call(method, w3)
    elif isinstance(method, OverloadedMethod):
        _patch_overloaded_method(method, w3)


def patch_contract(contract: Contract, w3: Optional[Web3]) -> Contract:
    if w3 is None and network.is_connected():
        w3 = web3
    assert w3 is not None, "You must make sure either brownie is connected or you pass in a Web3 instance."
    for k, v in contract.__dict__.items():
        _patch_if_method(v, w3)
    return contract
