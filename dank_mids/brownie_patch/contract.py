
from types import MethodType
from typing import Any, Optional, Union, overload

import brownie
from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod
from web3 import Web3

from dank_mids.brownie_patch.call import _get_coroutine_fn
from dank_mids.brownie_patch.overloaded import _patch_overloaded_method
from dank_mids.brownie_patch.types import ContractMethod, DankContractMethod


class Contract(brownie.Contract):
    """a modified `brownie.Contract` with async and call batching functionalities"""
    @classmethod
    def from_abi(cls, *args, **kwargs) -> "Contract":
        # NOTE: just forces type checkers to work
        return super().from_abi(*args, **kwargs)
    @classmethod
    def from_ethpm(cls, *args, **kwargs) -> "Contract":
        # NOTE: just forces type checkers to work
        return super().from_ethpm(*args, **kwargs)
    @classmethod
    def from_explorer(cls, *args, **kwargs) -> "Contract":
        # NOTE: just forces type checkers to work
        return super().from_explorer(*args, **kwargs)
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        patch_contract(self)
    def __getattr__(self, name: str) -> DankContractMethod:
        """This doesn't functionally do anythiing, it just enables type hints"""
        return super().__getattr__(name)

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

def _patch_if_method(method: ContractMethod, w3: Web3) -> None:
    if isinstance(method, (ContractCall, ContractTx)):
        method.coroutine = MethodType(_get_coroutine_fn(w3, len(method.abi['inputs'])), method)
    elif isinstance(method, OverloadedMethod):
        _patch_overloaded_method(method, w3)
