
from typing import Any, Dict, Generic, Optional, TypeVar, Union

from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod

_EVMType = TypeVar("_EVMType")

ContractMethod = Union[ContractCall, ContractTx, OverloadedMethod]


class _DankMethodMixin(Generic[_EVMType]):
    """A mixin class that gives brownie objects async support"""
    async def __await__(self):
        """Asynchronously call the contract method without arguments at the latest block and await the result."""
        return self.coroutine().__await__()
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

class DankContractCall(ContractCall, _DankMethodMixin):
    """This class serves only to enable proper type checking, you will not encounter a `DankContractCall` instance. Instead, you will have a money-patched `ContractCall`."""
class DankContractTx(ContractTx, _DankMethodMixin):
    """This class serves only to enable proper type checking, you will not encounter a `DankContractTx` instance. Instead, you will have a money-patched `ContractTx`."""
class DankOverloadedMethod(OverloadedMethod, _DankMethodMixin):
    """This class serves only to enable proper type checking, you will not encounter a `DankOverloadedMethod` instance. Instead, you will have a money-patched `OverloadedMethod`."""

DankContractMethod = Union[DankContractCall, DankContractTx, DankOverloadedMethod]
"""These classes serve only to enable proper type checking, you will not encounter a `DankContractCall`, `DankContractTx`, or `DankOverloadedMethod` instance. Instead, you will have a money-patched `ContractCall`, `ContractTx`, or `OverloadedMethod`."""