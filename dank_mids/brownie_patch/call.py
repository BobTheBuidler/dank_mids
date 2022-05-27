
import functools
from types import MethodType
from typing import Any, Coroutine, Dict, Tuple, Union

import eth_abi
from brownie.convert.normalize import format_input, format_output
from brownie.convert.utils import get_type_strings
from brownie.exceptions import VirtualMachineError
from brownie.network.contract import ContractCall
from brownie.project.compiler.solidity import SOLIDITY_ERROR_CODES
from hexbytes import HexBytes
from multicall.utils import run_in_subprocess
from web3 import Web3


def __encode_input(abi: Dict, signature: str, *args: Tuple) -> str:
    data = format_input(abi, args)
    types_list = get_type_strings(abi["inputs"])
    return signature + eth_abi.encode_abi(types_list, data).hex()

def __decode_output(hexstr: str, abi: Dict) -> Any:
    selector = HexBytes(hexstr)[:4].hex()
    if selector == "0x08c379a0":
        revert_str = eth_abi.decode_abi(["string"], HexBytes(hexstr)[4:])[0]
        raise ValueError(f"Call reverted: {revert_str}")
    elif selector == "0x4e487b71":
        error_code = int(HexBytes(hexstr)[4:].hex(), 16)
        if error_code in SOLIDITY_ERROR_CODES:
            revert_str = SOLIDITY_ERROR_CODES[error_code]
        else:
            revert_str = f"Panic (error code: {error_code})"
        raise ValueError(f"Call reverted: {revert_str}")
    if abi["outputs"] and not hexstr:
        raise ValueError("No data was returned - the call likely reverted")

    types_list = get_type_strings(abi["outputs"])
    result = eth_abi.decode_abi(types_list, HexBytes(hexstr))
    result = format_output(abi, result)
    if len(result) == 1:
        result = result[0]
    return result

def _patch_call(call: ContractCall, w3: Web3) -> None:
    async def _encode_input(self, *args):
        return await run_in_subprocess(
            __encode_input,
            self.abi,
            self.signature,
            *(arg if not hasattr(arg, 'address') else arg.address for arg in args)
        )
    
    async def _decode_output(self, data):
        return await run_in_subprocess(__decode_output, data, self.abi)

    @functools.wraps(call)
    async def coroutine(
        self,
        *args: Tuple,
        block_identifier: Union[int, str, bytes] = None,
        override: Dict = None
    ) -> Coroutine:
        if override:
            raise ValueError("Cannot use state override with `coroutine`.")
        
        calldata = await self._encode_input(*args)

        try:
            data = await w3.eth.call({"to": self._address, "data": calldata}, block_identifier, override)
        except ValueError as e:
            raise VirtualMachineError(e) from None

        return await self._decode_output(data)

    call.coroutine = MethodType(coroutine, call)
    call._encode_input = MethodType(_encode_input, call)
    call._decode_output = MethodType(_decode_output, call)
