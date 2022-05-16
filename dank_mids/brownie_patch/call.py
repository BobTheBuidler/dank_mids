
import functools
from types import MethodType
from typing import Coroutine, Dict, Tuple, Union

import eth_abi
from hexbytes import HexBytes
from web3 import Web3

from brownie.exceptions import VirtualMachineError
from brownie.network.contract import ContractCall, _get_tx
from brownie.project.compiler.solidity import SOLIDITY_ERROR_CODES


def _patch_call(call: ContractCall, w3: Web3) -> None:
    @functools.wraps(call)
    async def coroutine(
        self,
        *args: Tuple,
        block_identifier: Union[int, str, bytes] = None,
        override: Dict = None
    ) -> Coroutine:

        args, tx = _get_tx(self._owner, args)
        if tx["from"]:
            tx["from"] = str(tx["from"])
        del tx["required_confs"]
        tx.update({"to": self._address, "data": self.encode_input(*args)})

        try:
            data = await w3.eth.call({k: v for k, v in tx.items() if v}, block_identifier, override)
        except ValueError as e:
            raise VirtualMachineError(e) from None

        selector = HexBytes(data)[:4].hex()

        if selector == "0x08c379a0":
            revert_str = eth_abi.decode_abi(["string"], HexBytes(data)[4:])[0]
            raise ValueError(f"Call reverted: {revert_str}")
        elif selector == "0x4e487b71":
            error_code = int(HexBytes(data)[4:].hex(), 16)
            if error_code in SOLIDITY_ERROR_CODES:
                revert_str = SOLIDITY_ERROR_CODES[error_code]
            else:
                revert_str = f"Panic (error code: {error_code})"
            raise ValueError(f"Call reverted: {revert_str}")
        if self.abi["outputs"] and not data:
            raise ValueError("No data was returned - the call likely reverted")
        return self.decode_output(data)

    call.coroutine = MethodType(coroutine, call)
