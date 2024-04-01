import functools
from types import MethodType
from typing import Any, Dict, Optional, Tuple, Union

from brownie import Contract
from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod
from dank_mids.brownie_patch.call import _get_coroutine_fn, _skip_proc_pool
from dank_mids.brownie_patch.types import ContractMethod
from web3 import Web3


def _patch_overloaded_method(call: OverloadedMethod, w3: Web3) -> None:
    # sourcery skip: avoid-builtin-shadow
    @functools.wraps(call)
    async def coroutine(
        self: Contract,
        *args: Tuple[Any,...],
        block_identifier: Optional[Union[int, str, bytes]] = None,
        decimals: Optional[int] = None,
        override: Optional[Dict[str, str]] = None,
    ) -> Any:
        try:
            fn = self._get_fn_from_args(args)
        except ValueError as e:
            if f"Contract has more than one function '.{call._name}" in str(e) and f"You must explicitly declare which function you are calling, e.g. .{call._name}" in str(e):
                exc_str = str(e)
                breakpoint = exc_str.find("(*args)")
                raise ValueError(f"{exc_str[:breakpoint]}.coroutine{exc_str[breakpoint:]}")
            raise e

        kwargs = {"block_identifier": block_identifier, "decimals": decimals, "override": override}
        kwargs = {k: v for k, v in kwargs.items() if v is not None}
        return await fn.coroutine(*args, **kwargs)

    for method in call.__dict__['methods'].values():
        if isinstance(method, (ContractCall, ContractTx)):
            method._skip_decoder_proc_pool = method._address in _skip_proc_pool
            method.coroutine = MethodType(_get_coroutine_fn(w3, len(method.abi['inputs'])), method)
    # TODO implement this properly
        #elif isinstance(call, ContractTx):
            #_patch_tx(call, w3)

    call.coroutine = MethodType(coroutine, call)
