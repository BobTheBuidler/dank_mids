
from types import MethodType
from typing import Optional, Union, overload

import brownie
from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod
from web3 import Web3

from dank_mids.brownie_patch.call import _get_coroutine_fn
from dank_mids.brownie_patch.overloaded import _patch_overloaded_method


class Contract(brownie.Contract):
    """a modified `brownie.Contract` with async and call batching functionalities"""
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        patch_contract(self)

@overload
def patch_contract(contract: Contract, w3: Optional[Web3] = None) -> Contract:...
@overload
def patch_contract(contract: Union[brownie.Contract, str], w3: Optional[Web3] = None) -> brownie.Contract:...
def patch_contract(contract: Union[Contract, brownie.Contract, str], w3: Optional[Web3] = None) -> Union[Contract, brownie.Contract]:
    """returns a patched version of `contract` with async and call batchings functionalities"""
    if not isinstance(contract, brownie.Contract):
        contract = brownie.Contract(contract)
    if w3 is None and brownie.network.is_connected():
        from dank_mids import dank_web3 as w3
    if w3 is None:
        raise RuntimeError("You must make sure either brownie is connected or you pass in a Web3 instance.")
    for k, v in contract.__dict__.items():
        _patch_if_method(v, w3)
    return contract

ContractMethod = Union[ContractCall, ContractTx, OverloadedMethod]

def _patch_if_method(method: ContractMethod, w3: Web3) -> None:
    if isinstance(method, (ContractCall, ContractTx)):
        method.coroutine = MethodType(_get_coroutine_fn(w3, len(method.abi['inputs'])), method)
    elif isinstance(method, OverloadedMethod):
        _patch_overloaded_method(method, w3)
