
from types import MethodType
from typing import Optional, Union

from brownie import Contract, network
from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod
from web3 import Web3

from dank_mids.brownie_patch.call import _get_coroutine_fn
from dank_mids.brownie_patch.overloaded import _patch_overloaded_method

ContractMethod = Union[ContractCall, ContractTx, OverloadedMethod]

def _patch_if_method(method: ContractMethod, w3: Web3) -> None:
    if isinstance(method, (ContractCall, ContractTx)):
        method.coroutine = MethodType(_get_coroutine_fn(w3, len(method.abi['inputs'])), method)
    elif isinstance(method, OverloadedMethod):
        _patch_overloaded_method(method, w3)

def patch_contract(contract: Contract, w3: Optional[Web3] = None) -> Contract:
    if w3 is None:
        assert network.is_connected(), "You must make sure either brownie is connected or you pass in a Web3 instance."
        from dank_mids.helpers import dank_web3 as w3
    for k, v in contract.__dict__.items():
        _patch_if_method(v, w3)
    return contract
