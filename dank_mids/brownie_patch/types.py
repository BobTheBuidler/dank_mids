
from typing import Any, Dict, Optional, Tuple, Union

from brownie.typing import AccountsType
from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod

from dank_mids.brownie_patch._method import _DankMethod, _DankMethodMixin, _EVMType


ContractMethod = Union[ContractCall, ContractTx, OverloadedMethod]

class DankContractCall(_DankMethod, ContractCall):
    """
    A `brownie.network.contract.ContractCall` subclass with async support via the `coroutine` method.

    It uses less memory than a `ContractTx` by using __slots__ along with the `FunctionABI` singleton to hold the function abi and related logic.

    You can await this object directly to call the contract method with no arguments at the latest block.
    """
class DankContractTx(_DankMethod, ContractTx):
    """
    A `brownie.network.contract.ContractTx` subclass with async support via the `coroutine` method.

    It uses less memory than a `ContractTx` by using __slots__ along with the `FunctionABI` singleton to hold the function abi and related logic.

    You can await this object directly to call the contract method with no arguments at the latest block.
    """

_NonOverloaded = Union[DankContractCall, DankContractTx]

class DankOverloadedMethod(OverloadedMethod, _DankMethodMixin):
    """
    A `brownie.network.contract.OverloadedMethod` subclass with async support via the `coroutine` method.

    It uses less memory than a `OverloadedMethod` by using __slots__ along with the `FunctionABI` singleton to hold the function abi and related logic.

    You can await this object directly to call the contract method with no arguments at the latest block.
    """
    methods: Dict[Tuple[str], _NonOverloaded]
    __slots__ = "_address", "_name", "_owner", "methods", "natspec"
    async def coroutine(  # type: ignore [empty-body]
        self, 
        *args: Any, 
        block_identifier: Optional[int] = None, 
        decimals: Optional[int] = None,
        override: Optional[Dict[str, str]] = None,
    ) -> _EVMType:
        """
        Asynchronously call the contract method via dank mids and await the result.
        
        Arguments:
            - *args: The arguments for the contract method.
            - block_identifier (optional): The block at which the chain will be read. If not provided, will read the chain at latest block.
            - decimals (optional): if provided, the output will be `result / 10 ** decimals`
        
        Returns:
            - Whatever the node sends back as the output for this contract method.
        """
        call: Union[DankContractCall, DankContractTx] = self._get_fn_from_args(args)
        return await call.coroutine(*args, block_identifier=block_identifier, decimals=decimals, override=override)
    def _add_fn(self, abi: Dict, natspec: Dict) -> None:
        fn = _get_method_object(self._address, abi, self._name, self._owner, natspec)
        key = tuple(i["type"].replace("256", "") for i in abi["inputs"])
        self.methods[key] = fn
        self.natspec.update(natspec)

DankContractMethod = Union[DankContractCall, DankContractTx, DankOverloadedMethod]
"""
These are `ContractMethod` objects with async support via an added `coroutine` method.

They use less memory than `ContractMethod` objects by using `FunctionABI` singleton to hold the function abi and related logic.

You can await this object directly to call the contract method with no arguments at the latest block.
"""

def _get_method_object(
    address: str, abi: Dict, name: str, owner: Optional[AccountsType], natspec: Dict
) -> Union["ContractCall", "ContractTx"]:
    if "constant" in abi:
        constant = abi["constant"]
    else:
        constant = abi["stateMutability"] in ("view", "pure")

    if constant:
        return DankContractCall(address, abi, name, owner, natspec)
    return DankContractTx(address, abi, name, owner, natspec)