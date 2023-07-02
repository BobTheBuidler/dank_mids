
import asyncio
from concurrent.futures import ProcessPoolExecutor
from functools import lru_cache
from pickle import PicklingError
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

from dank_mids import ENVIRONMENT_VARIABLES
from dank_mids.helpers.semaphore import ThreadsafeSemaphore

brownie_call_semaphore = ThreadsafeSemaphore(ENVIRONMENT_VARIABLES.BROWNIE_CALL_SEMAPHORE_VAL)

def __encode_input(abi: Dict[str, Any], signature: str, *args: Tuple[Any,...]) -> str:
    try:
        data = format_input(abi, args)
        types_list = get_type_strings(abi["inputs"])
        return signature + eth_abi.encode_abi(types_list, data).hex()
    except Exception as e:
        return e

def __decode_output(hexstr: str, abi: Dict[str, Any]) -> Any:
    try:
        types_list = get_type_strings(abi["outputs"])
        result = eth_abi.decode_abi(types_list, HexBytes(hexstr))
        result = format_output(abi, result)
        if len(result) == 1:
            result = result[0]
        return result
    except Exception as e:
        return e

def __validate_output(abi: Dict[str, Any], hexstr: str):
    try:
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
    except ValueError as e:
        try:
            raise VirtualMachineError(e) from None
        except:
            raise e

encoder_processes = ProcessPoolExecutor(ENVIRONMENT_VARIABLES.NUM_PROCESSES)
decoder_processes = ProcessPoolExecutor(ENVIRONMENT_VARIABLES.NUM_PROCESSES)

encode = lambda self, *args: asyncio.get_event_loop().run_in_executor(encoder_processes, __encode_input, self.abi, self.signature, *args)
decode = lambda self, data: asyncio.get_event_loop().run_in_executor(decoder_processes, __decode_output, data, self.abi)

async def _request_data_no_args(
    call: ContractCall,
    *args: Tuple[Any,...],
):
    return call.signature

async def _request_data_with_args(
    call: ContractCall,
    *args: Tuple[Any,...],
):
    return await call._encode_input(*args)

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
            try: # We're better off sending these to the subprocess so they don't clog up the event loop.
                data = await get_request_data(self, *args)
            except PicklingError:  # But if that fails, don't worry. I got you.
                data = __encode_input(self.abi, self.signature, *args) if len_inputs else self.signature
            
            # We have to do it like this so we don't break the process pool.
            if isinstance(data, Exception):
                raise data
            
            output = await w3.eth.call({"to": self._address, "data": data}, block_identifier)

            __validate_output(self.abi, output)

            decoded = await self._decode_output(output)

            # We have to do it like this so we don't break the process pool.
            if isinstance(decoded, Exception):
                raise decoded
            
            return decoded
        
    return coroutine

def _patch_call(call: ContractCall, w3: Web3) -> None:
    call.coroutine = MethodType(_get_coroutine_fn(w3, len(call.abi['inputs'])), call)
    call._encode_input = MethodType(encode, call)
    call._decode_output = MethodType(decode, call)
