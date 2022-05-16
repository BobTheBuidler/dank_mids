
import functools
from types import MethodType
from typing import Coroutine, Dict, Tuple, Union

from brownie.network.contract import ContractTx, _get_tx
from web3 import Web3

from dank_mids.brownie_patch.account import _patch_account

def _patch_tx(call: ContractTx, w3: Web3) -> None:

    @functools.wraps(call)
    async def coroutine(
        self,
        *args: Tuple,
        block_identifier: Union[int, str, bytes] = None,
        override: Dict = None
    ) -> Coroutine:

        args, tx = _get_tx(self._owner, args)
        if not tx["from"]:
            raise AttributeError(
                "Final argument must be a dict of transaction parameters that "
                "includes a `from` field specifying the sender of the transaction"
            )
        
        if not hasattr(tx["from"], 'transfer_coro'):
           tx["from"] = _patch_account(tx["from"], w3)

        return await tx["from"].transfer_coro(
            self._address,
            tx["value"],
            gas_limit=tx["gas"],
            gas_buffer=tx.get("gas_buffer"),
            gas_price=tx.get("gas_price"),
            max_fee=tx.get("max_fee"),
            priority_fee=tx.get("priority_fee"),
            nonce=tx["nonce"],
            required_confs=tx["required_confs"],
            data=self.encode_input(*args),
            allow_revert=tx["allow_revert"],
        )

    call.coroutine = MethodType(coroutine, call)
