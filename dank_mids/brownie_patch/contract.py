import functools
from typing import Dict, List, Literal, NewType, Optional, Union, overload

import brownie
from brownie.network.contract import (ContractCall, ContractTx, OverloadedMethod, 
                                      build_function_signature)
from brownie.typing import AccountsType
from web3 import Web3

from dank_mids.brownie_patch.call import _patch_call
from dank_mids.brownie_patch.overloaded import _patch_overloaded_method
from dank_mids.brownie_patch.types import ContractMethod, DankContractMethod, DankOverloadedMethod, _get_method_object
from dank_mids.helpers._helpers import DankWeb3
    

EventName = NewType("EventName", str)
"""A type representing the name of an event in a smart contract."""

LogTopic = NewType("LogTopic", str)
"""A type representing a log topic in Ethereum transactions."""

Method = NewType("Method", str)
"""A type representing the name of a method in a smart contract."""

Signature = NewType("Signature", str)
"""A type representing the signature of a method in a smart contract."""

class Contract(brownie.Contract):
    """
    An extended version of brownie.Contract with additional functionality for Dank Mids.

    This class provides lazy initialization of contract methods and supports
    asynchronous operations through Dank Mids middleware.
    """

    @classmethod
    def from_abi(
        cls, 
        name: str, 
        address: str, 
        abi: List[dict], 
        owner: Optional[AccountsType] = None, 
        persist: bool = True,
    ) -> "Contract":
        """
        Create a new Contract instance from an ABI.

        This method allows for the creation of a Contract instance using a provided ABI,
        which is useful when working with contracts that are not in the project's build
        files and not verified on a block explorer.

        Args:
            name: The name of the contract.
            address: The address of the deployed contract.
            abi: The ABI (Application Binary Interface) of the contract.
            owner: The account that owns this contract instance.
            persist: Whether to persist the contract data to brownie's local db for future use.

        Returns:
            A new Contract instance.
        """
        persisted = brownie.Contract.from_abi(name, address, abi, owner, _check_persist(persist))
        return Contract(persisted.address)

    @classmethod
    def from_ethpm(
        cls, 
        name: str, 
        manifest_uri: str, 
        address: Optional[str] = None, 
        owner: Optional[AccountsType] = None, 
        persist: bool = True,
    ) -> "Contract":
        """
        Create a new Contract instance from an ethPM manifest.

        This method allows for the creation of a Contract instance using an ethPM manifest,
        which is a standardized format for Ethereum smart contract packages.

        Args:
            name: The name of the contract.
            manifest_uri: The URI of the ethPM manifest.
            address: The address of the deployed contract (optional).
            owner: The account that owns this contract instance.
            persist: Whether to persist the contract data to brownie's local db for future use.

        Returns:
            A new Contract instance.
        """
        persisted = brownie.Contract.from_ethpm(name, manifest_uri, address, owner, _check_persist(persist))
        return Contract(persisted.address)

    @classmethod
    def from_explorer(
        cls, 
        address: str, 
        as_proxy_for: Optional[str] = None, 
        owner: Optional[AccountsType] = None, 
        silent: bool = False, 
        persist: bool = True,
    ) -> "Contract":
        """
        Create a new Contract instance by fetching the ABI from a block explorer.

        This method is useful for interacting with contracts that are not part of the current project,
        as it automatically fetches the contract's ABI from a block explorer.

        Args:
            address: The address of the deployed contract.
            as_proxy_for: The address of the implementation contract if this is a proxy contract.
            owner: The account that owns this contract instance.
            silent: Whether to suppress console output during the process.
            persist: Whether to persist the contract data to brownie's db for future use.

        Returns:
            A new Contract instance.
        """
        persisted = brownie.Contract.from_explorer(address, as_proxy_for, owner, silent, _check_persist(persist))
        return Contract(persisted.address)

    topics: Dict[str, str]
    """A dictionary mapping event names to their corresponding topics."""

    signatures: Dict[Method, Signature]
    """A dictionary mapping method names to their corresponding signatures."""

    def __init__(self, *args, **kwargs):
        """
        Initialize the Contract instance.

        This method sets up lazy initialization for contract methods.
        """
        super().__init__(*args, **kwargs)
        # get rid of the contract call objects, we can materialize them on a jit basis
        for name in self.__method_names__:
            if name in {"_name", "_owner"}:
                # this is a property defined on _ContractBase and cannot be written to
                continue
            object.__setattr__(self, name, _ContractMethodPlaceholder)

    def __getattribute__(self, name: str) -> DankContractMethod:
        """
        Get a contract method attribute.

        This method implements lazy initialization of contract methods. 
        If a method object does not yet exist, it is created and cached.

        Args:
            name: The name of the attribute to get.

        Returns:
            The contract method object.
        """
        attr = super().__getattribute__(name)
        if attr is _ContractMethodPlaceholder:
            attr = self.__get_method_object__(name)
            object.__setattr__(self, name, attr)
        return attr

    @functools.cached_property
    def __method_names__(self) -> List[str]:
        """List of method names defined in the contract ABI."""
        return [i["name"] for i in self.abi if i["type"] == "function"]

    def __get_method_object__(self, name: str) -> DankContractMethod:
        """
        Get a method object for the given method name.

        This method handles both regular and overloaded contract methods,
        returning an appropriate DankContractMethod object.

        Args:
            name: The name of the method to get.

        Returns:
            The initialized contract method object.
        """
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
                return _get_method_object(self.address, abi, full_name, self._owner, natspec)

            # special logic to handle function overloading
            elif overloaded is True:
                overloaded = DankOverloadedMethod(self.address, full_name, self._owner)
            overloaded._add_fn(abi, natspec)
        return overloaded  # type: ignore [return-value]

    
@overload
def patch_contract(contract: Contract, w3: Optional[DankWeb3] = None) -> Contract:...
@overload
def patch_contract(contract: Union[brownie.Contract, str], w3: Optional[DankWeb3] = None) -> brownie.Contract:...
def patch_contract(contract: Union[Contract, brownie.Contract, str], w3: Optional[DankWeb3] = None) -> Union[Contract, brownie.Contract]:
    """
    Patch a contract with async and call batching functionalities.

    Args:
        contract: The contract to patch.
        w3: Optional DankWeb3 instance.

    Returns:
        The patched contract.
    """
    if not isinstance(contract, brownie.Contract):
        contract = brownie.Contract(contract)
    if w3 is None and brownie.network.is_connected():
        from dank_mids import dank_web3 as w3
    if w3 is None:
        raise RuntimeError("You must make sure either brownie is connected or you pass in a Web3 instance.")
    for k, v in contract.__dict__.items():
        _patch_if_method(v, w3)
    return contract

def _patch_if_method(method: ContractMethod, w3: DankWeb3) -> None:
    """
    Patch a contract method if it's a ContractCall, ContractTx, or OverloadedMethod.

    Args:
        method: The contract method to patch.
        w3: The DankWeb3 instance to use for async calls.
    """
    if isinstance(method, (ContractCall, ContractTx)):
        _patch_call(method, w3)
    elif isinstance(method, OverloadedMethod):
        _patch_overloaded_method(method, w3)

class _ContractMethodPlaceholder:
    """
    A sentinel object that indicates a Contract has a member by a specific name.

    This class is used internally to represent methods that exist on a contract
    but haven't been fully initialized yet, allowing for lazy loading of method objects.
    """

def _check_persist(persist: bool) -> Literal[True]:
    """
    Check if persistence is enabled and raise an error if it's not.

    This function is used to ensure that contract data persistence is enabled.

    Args:
        persist: Boolean indicating whether to persist a :class:`~Contract` to brownie's local db.

    Returns:
        True if persist is True.

    Raises:
        NotImplementedError: If persist is False, indicating that dank_mids
                             requires persistence to be enabled.
    """
    if not persist:
        raise NotImplementedError("persist: False")
    return persist
