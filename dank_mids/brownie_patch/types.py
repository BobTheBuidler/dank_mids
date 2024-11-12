from typing import Any, Dict, Optional, Tuple, Union

from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod
from brownie.typing import AccountsType

from dank_mids.brownie_patch._method import _DankMethod, _DankMethodMixin, _EVMType

ContractMethod = Union[ContractCall, ContractTx, OverloadedMethod]
"""Type alias for Brownie contract methods."""


class DankContractCall(_DankMethod, ContractCall):
    """
    A subclass of `brownie.network.contract.ContractCall` with async support via the `coroutine` method.

    This class uses less memory than a typical `ContractTx` by employing the `__slots__` functionality alongside
    the `FunctionABI` singleton to manage the function ABI and related logic.

    You can await an instance of this class directly to call the contract method without arguments at the latest block.
    """


class DankContractTx(_DankMethod, ContractTx):
    """
    A subclass of `brownie.network.contract.ContractTx` with async support via the `coroutine` method.

    This class is optimized for memory use compared to a standard `ContractTx`, by using `__slots__` in combination
    with the `FunctionABI` singleton to handle the function ABI and associated logic.

    Awaiting an instance of this class directly executes the contract method without arguments at the latest block.
    """


_NonOverloaded = Union[DankContractCall, DankContractTx]
"""Type alias for non-overloaded Dank contract methods."""


class DankOverloadedMethod(OverloadedMethod, _DankMethodMixin):
    """
    A subclass of `brownie.network.contract.OverloadedMethod` with async support via the `coroutine` method.

    This class is designed to be memory efficient compared to a typical `OverloadedMethod`, employing `__slots__`
    and the `FunctionABI` singleton to manage the function ABI and related logic.

    You can await instances of this class directly to call the contract method without arguments at the latest block.
    """

    methods: Dict[Tuple[str, ...], _NonOverloaded]
    __slots__ = "_address", "_name", "_owner", "methods", "natspec"

    async def coroutine(
        self,
        *args: Any,
        block_identifier: Optional[int] = None,
        decimals: Optional[int] = None,
        override: Optional[Dict[str, str]] = None,
    ) -> _EVMType:
        """
        Asynchronously call the contract method using dank mids and await the result.

        Args:
            *args: The arguments for the contract method.
            block_identifier (optional): Specifies the block at which the chain will be read. Defaults to the latest block if not provided.
            decimals (optional): If specified, the output will be `result / 10 ** decimals`.

        Returns:
            Whatever the node sends back as the output for this contract method.
        """
        call: Union[DankContractCall, DankContractTx] = self._get_fn_from_args(args)
        return await call.coroutine(
            *args, block_identifier=block_identifier, decimals=decimals, override=override
        )

    def _add_fn(self, abi: Dict, natspec: Dict) -> None:
        """
        Add a function to the overloaded method.

        This method creates a new function object using the provided ABI and NatSpec,
        then adds it to the collection of functions in the overloaded method.

        Args:
            abi: The ABI of the function to be added.
            natspec: The NatSpec documentation for the function.
        """
        fn = _get_method_object(self._address, abi, self._name, self._owner, natspec)
        key = tuple(i["type"].replace("256", "") for i in abi["inputs"])
        self.methods[key] = fn
        self.natspec.update(natspec)


DankContractMethod = Union[DankContractCall, DankContractTx, DankOverloadedMethod]
"""
Alias for `ContractMethod` objects with async support via an additional `coroutine` method.

These objects consume less memory than standard `ContractMethod` objects by utilizing the `FunctionABI` singleton to handle the function ABI and associated logic.

Instances of this class can be awaited directly to call the contract method without arguments at the latest block.
"""


def _get_method_object(
    address: str, abi: Dict, name: str, owner: Optional[AccountsType], natspec: Dict
) -> Union["ContractCall", "ContractTx"]:
    """
    Retrieve an appropriate method object based on the ABI.

    Determines whether the ABI specifies a constant function and returns a corresponding DankContractCall
    or DankContractTx object.

    Args:
        address: The contract address associated with the method.
        abi: The ABI of the function.
        name: The name of the method.
        owner: The account that owns the method, if applicable.
        natspec: The NatSpec documentation associated with the function.

    Returns:
        A DankContractCall or DankContractTx object depending on the function's mutability state.
    """
    if "constant" in abi:
        constant = abi["constant"]
    else:
        constant = abi["stateMutability"] in ("view", "pure")

    if constant:
        return DankContractCall(address, abi, name, owner, natspec)
    return DankContractTx(address, abi, name, owner, natspec)
