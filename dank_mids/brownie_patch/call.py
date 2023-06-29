
import asyncio
from concurrent.futures import ProcessPoolExecutor
from functools import lru_cache
from types import MethodType
from typing import Any, Dict, Optional, Tuple, Union

import eth_abi
from brownie.convert.normalize import format_input, format_output
from brownie.convert.utils import get_type_strings
from brownie.exceptions import VirtualMachineError
from brownie.network.contract import ContractCall
from brownie.project.compiler.solidity import SOLIDITY_ERROR_CODES
from hexbytes import HexBytes
from web3 import Web3

from dank_mids import _config
from dank_mids.helpers.semaphore import ThreadsafeSemaphore

brownie_call_semaphore = ThreadsafeSemaphore(_config.BROWNIE_CALL_SEMAPHORE_VAL)

def __encode_input(abi: Dict[str, Any], signature: str, *args: Tuple[Any,...]) -> str:
    data = format_input(abi, args)
    types_list = get_type_strings(abi["inputs"])
    return signature + eth_abi.encode_abi(types_list, data).hex()

def __decode_output(hexstr: str, abi: Dict[str, Any]) -> Any:
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

encoder_processes = ProcessPoolExecutor(_config.NUM_PROCESSES)
decoder_processes = ProcessPoolExecutor(_config.NUM_PROCESSES)

encode = lambda self, *args: asyncio.get_event_loop().run_in_executor(encoder_processes, __encode_input, self.abi, self.signature, *args)
decode = lambda self, data: asyncio.get_event_loop().run_in_executor(decoder_processes, __decode_output, data, self.abi)

async def _request_data_no_args(
    call: ContractCall,
    *args: Tuple[Any,...],
):
    return {"to": call._address, "data": call.signature}

async def _request_data_with_args(
    call: ContractCall,
    *args: Tuple[Any,...],
):
    return {"to": call._address, "data": await call._encode_input(*args)}

@lru_cache
def _get_coroutine_fn(w3: Web3, len_inputs: int):
    get_request_data = _request_data_with_args if len_inputs else _request_data_no_args
    
    async def coroutine(
        self: ContractCall,
        *args: Tuple[Any,...],
        block_identifier: Optional[Union[int, str, bytes]] = None,
        override: Optional[Dict[str, str]] = None
    ) -> Any:
        if override:
            raise ValueError("Cannot use state override with `coroutine`.")
            
        async with brownie_call_semaphore:
            try:
                return await self._decode_output(
                    await w3.eth.call(await get_request_data(self, *args), block_identifier)  # type: ignore
                )
            except ValueError as e:
                try:
                    raise VirtualMachineError(e) from None
                except:
                    raise e
    return coroutine

def _patch_call(call: ContractCall, w3: Web3) -> None:
    call.coroutine = MethodType(_get_coroutine_fn(w3, len(call.abi['inputs'])), call)
    call._encode_input = MethodType(encode, call)
    call._decode_output = MethodType(decode, call)
