
import logging
from concurrent.futures.process import BrokenProcessPool
from functools import lru_cache
from pickle import PicklingError
from types import MethodType
from typing import Any, Dict, Optional, Tuple, Union

import eth_abi
from a_sync import AsyncProcessPoolExecutor
from brownie import chain
from brownie.convert.normalize import format_input, format_output
from brownie.convert.utils import get_type_strings
from brownie.exceptions import VirtualMachineError
from brownie.network.contract import Contract, ContractCall
from brownie.project.compiler.solidity import SOLIDITY_ERROR_CODES
from hexbytes import HexBytes
from multicall.constants import MULTICALL2_ADDRESSES
from web3 import Web3

from dank_mids import ENVIRONMENT_VARIABLES as ENVS

logger = logging.getLogger(__name__)
encode = lambda self, *args: ENVS.BROWNIE_ENCODER_PROCESSES.run(__encode_input, self.abi, self.signature, *args)
decode = lambda self, data: ENVS.BROWNIE_DECODER_PROCESSES.run(__decode_output, data, self.abi)

def _patch_call(call: ContractCall, w3: Web3) -> None:
    call._skip_decoder_proc_pool = call._address in _skip_proc_pool
    call.coroutine = MethodType(_get_coroutine_fn(w3, len(call.abi['inputs'])), call)
    
@lru_cache
def _get_coroutine_fn(w3: Web3, len_inputs: int):
    if ENVS.OPERATION_MODE.application:
        get_request_data = encode
    else:
        get_request_data = encode if len_inputs else __request_data_no_args
    
    async def coroutine(
        self: ContractCall,
        *args: Tuple[Any,...],
        block_identifier: Optional[Union[int, str, bytes]] = None,
        override: Optional[Dict[str, str]] = None
    ) -> Any:
        if override:
            raise ValueError("Cannot use state override with `coroutine`.")
        async with ENVS.BROWNIE_ENCODER_SEMAPHORE[block_identifier]:
            data = await encode_input(self, len_inputs, get_request_data, *args)
            async with ENVS.BROWNIE_CALL_SEMAPHORE[block_identifier]:
                output = await w3.eth.call({"to": self._address, "data": data}, block_identifier)
        return await decode_output(self, output)
        
    return coroutine

async def encode_input(call: ContractCall, len_inputs, get_request_data, *args) -> bytes:
    if any(isinstance(arg, Contract) for arg in args) or any(hasattr(arg, "__contains__") for arg in args): # We will just assume containers contain a Contract object until we have a better way to handle this
        # We can't unpickle these because of the added `coroutine` method.
        data = __encode_input(call.abi, call.signature, *args)
    else:
        try: # We're better off sending these to the subprocess so they don't clog up the event loop.
            data = await get_request_data(call, *args)
        except (AttributeError, TypeError):
            # These occur when we have issues pickling an object, but that's fine, we can do it sync.
            data = __encode_input(call.abi, call.signature, *args)
        # TODO: move this somewhere else
        except BrokenProcessPool:
            logger.critical("Oh fuck, you broke the %s while decoding %s with abi %s", ENVS.BROWNIE_ENCODER_PROCESSES, data, call.abi)
            # Let's fix that right up
            ENVS.BROWNIE_ENCODER_PROCESSES = AsyncProcessPoolExecutor(ENVS.BROWNIE_ENCODER_PROCESSES._max_workers)
            data = __encode_input(call.abi, call.signature, *args) if len_inputs else call.signature
        except PicklingError:  # But if that fails, don't worry. I got you.
            data = __encode_input(call.abi, call.signature, *args) if len_inputs else call.signature
    # We have to do it like this so we don't break the process pool.
    if isinstance(data, Exception):
        raise data
    return data


async def decode_output(call: ContractCall, data: bytes) -> Any:
    __validate_output(call.abi, data)
    if hasattr(call, '_skip_decoder_proc_pool'):
        skip_proc_pool = call._skip_decoder_proc_pool
    else:
        logger.info('%s is missing attr `_skip_decoder_proc_pool`', call)
        skip_proc_pool = call._address in _skip_proc_pool
    if skip_proc_pool or b"Unexpected error" in data:  # Multicall3
        # This will break the process pool
        decoded = __decode_output(data, call.abi)
    else:
        try:
            decoded = await decode(call, data)
        # TODO: move this somewhere else
        except BrokenProcessPool:
            # Let's fix that right up
            logger.critical("Oh fuck, you broke the %s while decoding %s with abi %s", ENVS.BROWNIE_DECODER_PROCESSES, data, call.abi)
            ENVS.BROWNIE_DECODER_PROCESSES = AsyncProcessPoolExecutor(ENVS.BROWNIE_DECODER_PROCESSES._max_workers)
            decoded = __decode_output(data, call.abi)
    # We have to do it like this so we don't break the process pool.
    if isinstance(decoded, Exception):
        raise decoded
    return decoded

async def __request_data_no_args(call: ContractCall) -> str:
    return call.signature

def __encode_input(abi: Dict[str, Any], signature: str, *args: Tuple[Any,...]) -> str:
    try:
        data = format_input(abi, args)
        types_list = get_type_strings(abi["inputs"])
        return signature + eth_abi.encode_abi(types_list, data).hex()
    except Exception as e:
        return e

_skip_proc_pool = {"0xcA11bde05977b3631167028862bE2a173976CA11"}  # multicall3
if multicall2 := MULTICALL2_ADDRESSES.get(chain.id, None):
    _skip_proc_pool.add(multicall2)
    
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

