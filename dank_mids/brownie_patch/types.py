
from typing import Union

from brownie.network.contract import ContractCall, ContractTx, OverloadedMethod

ContractMethod = Union[ContractCall, ContractTx, OverloadedMethod]
