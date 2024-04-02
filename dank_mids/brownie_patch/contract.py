
import functools
from typing import Dict, List, Optional, Union, overload

import brownie
from brownie.network.contract import (ContractCall, ContractTx, OverloadedMethod, 
                                      build_function_signature, _get_method_object)
from web3 import Web3

from dank_mids.brownie_patch.call import _patch_call
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
        # get rid of the contract call objects, we can materialize them on a jit basis
        for name in self.__method_names__:
            if name == "_name":
                # this is a property defined on _ContractBase and cannot be written to
                continue
            object.__setattr__(self, name, _ContractMethodPlaceholder)
    def __getattribute__(self, name: str) -> DankContractMethod:
        """This doesn't functionally do anythiing, it just enables type hints"""
        attr = super().__getattribute__(name)
        if attr is _ContractMethodPlaceholder:
            attr = self.__get_method_object__(name)
            object.__setattr__(self, name, attr)
        return attr
    @functools.cached_property
    def __method_names__(self) -> List[str]:
        return [i["name"] for i in self.abi if i["type"] == "function"]
    def __get_method_object__(self, name: str) -> DankContractMethod:
        from dank_mids import web3
        overloaded = self.__method_names__.count(name) > 1
        for abi in [i for i in self.abi if i["type"] == "function"]:
            if abi["name"] != name:
                continue
            full_name = f"{self._name}.{name}"
            sig = build_function_signature(abi)
            natspec: Dict = {}
            if self._build.get("natspec"):
                natspec = self._build["natspec"]["methods"].get(sig, {})

            if overloaded is False:
                fn = _get_method_object(self.address, abi, full_name, self._owner, natspec)
                _patch_call(fn, web3)
                return fn

            # special logic to handle function overloading
            elif overloaded is True:
                overloaded = OverloadedMethod(self.address, full_name, self._owner)
            overloaded._add_fn(abi, natspec)
        _patch_overloaded_method(overloaded, web3)
        return overloaded  # type: ignore [return-value]

    
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
        _patch_call(method, w3)
    elif isinstance(method, OverloadedMethod):
        _patch_overloaded_method(method, w3)

class _ContractMethodPlaceholder:
    """A sentinel object that indicates a Contract does have a member by a specific name."""
