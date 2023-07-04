import functools
from types import MethodType
from typing import Any, Dict, Optional, Tuple, Union

from brownie import Contract
from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod
from dank_mids.brownie_patch.call import _get_coroutine_fn
from web3 import Web3


def _patch_overloaded_method(call: OverloadedMethod, w3: Web3) -> None:
    @functools.wraps(call)
    async def coroutine(
        self: Contract,
        *args: Tuple[Any,...],
        block_identifier: Optional[Union[int, str, bytes]] = None,
        override: Optional[Dict[str, str]] = None
    ) -> Any:
        try:
            fn = self._get_fn_from_args(args)
        except ValueError as e:
            if f"Contract has more than one function '.{call._name}" in str(e) and f"You must explicitly declare which function you are calling, e.g. .{call._name}" in str(e):
                e = str(e)                    
                breakpoint = e.find("(*args)")
                raise ValueError(f"{e[:breakpoint]}.coroutine{e[breakpoint:]}")
            raise e
                                        
        kwargs = {"block_identifier": block_identifier, "override": override}
        kwargs = {k: v for k, v in kwargs.items() if v is not None}
        return await fn.coroutine(*args, **kwargs)

    for method in call.__dict__['methods'].values():
        if isinstance(method, ContractCall) or isinstance(method, ContractTx):
            method.coroutine = MethodType(_get_coroutine_fn(w3, len(method.abi['inputs'])), method)
    # TODO implement this properly
        #elif isinstance(call, ContractTx):
            #_patch_tx(call, w3)
    
    call.coroutine = MethodType(coroutine, call)
