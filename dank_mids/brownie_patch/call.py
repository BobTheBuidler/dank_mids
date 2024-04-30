
import functools
import logging
from concurrent.futures.process import BrokenProcessPool
from decimal import Decimal
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
from eth_abi.exceptions import InsufficientDataBytes
from eth_typing import HexStr
from eth_utils import to_checksum_address
from hexbytes import HexBytes
from hexbytes.main import BytesLike
from multicall.constants import MULTICALL2_ADDRESSES
from web3.types import BlockIdentifier

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.brownie_patch.types import ContractMethod
from dank_mids.exceptions import Revert
from dank_mids.helpers._helpers import DankWeb3

logger = logging.getLogger(__name__)
encode = lambda self, *args: ENVS.BROWNIE_ENCODER_PROCESSES.run(__encode_input, self.abi, self.signature, *args)  # type: ignore [attr-defined]
decode = lambda self, data: ENVS.BROWNIE_DECODER_PROCESSES.run(__decode_output, data, self.abi)  # type: ignore [attr-defined]

def _patch_call(call: ContractCall, w3: DankWeb3) -> None:
    call._skip_decoder_proc_pool = call._address in _skip_proc_pool
    call.coroutine = MethodType(_get_coroutine_fn(w3, len(call.abi['inputs'])), call)
    call.__await__ = MethodType(_call_no_args, call)
    
@functools.lru_cache
def _get_coroutine_fn(w3: DankWeb3, len_inputs: int):
    if ENVS.OPERATION_MODE.application or len_inputs:  # type: ignore [attr-defined]
        get_request_data = encode
    else:
        get_request_data = _request_data_no_args  # type: ignore [assignment]
    
    async def coroutine(
        self: ContractCall,
        *args: Tuple[Any,...],
        block_identifier: Optional[BlockIdentifier] = None,
        decimals: Optional[int] = None,
        override: Optional[Dict[str, str]] = None
    ) -> Any:
        if override:
            raise ValueError("Cannot use state override with `coroutine`.")
        async with ENVS.BROWNIE_ENCODER_SEMAPHORE[block_identifier]:  # type: ignore [attr-defined, index]
            data = await encode_input(self, len_inputs, get_request_data, *args)
            async with ENVS.BROWNIE_CALL_SEMAPHORE[block_identifier]:  # type: ignore [attr-defined, index]
                output = await w3.eth.call({"to": self._address, "data": data}, block_identifier)
        try:
            decoded = await decode_output(self, output)
        except InsufficientDataBytes as e:
            raise InsufficientDataBytes(str(e), self, self._address, output) from e
        
        return decoded if decimals is None else decoded / 10 ** Decimal(decimals)

    return coroutine

def _call_no_args(self: ContractMethod):
    """Asynchronously call `self` with no arguments at the latest block."""
    return self.coroutine().__await__()

async def encode_input(call: ContractCall, len_inputs, get_request_data, *args) -> HexStr:
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
            logger.critical("Oh fuck, you broke the %s while decoding %s with abi %s", ENVS.BROWNIE_ENCODER_PROCESSES, data, call.abi)  # type: ignore [attr-defined]
            # Let's fix that right up
            ENVS.BROWNIE_ENCODER_PROCESSES = AsyncProcessPoolExecutor(ENVS.BROWNIE_ENCODER_PROCESSES._max_workers)  # type: ignore [attr-defined,assignment]
            data = __encode_input(call.abi, call.signature, *args) if len_inputs else call.signature
        except PicklingError:  # But if that fails, don't worry. I got you.
            data = __encode_input(call.abi, call.signature, *args) if len_inputs else call.signature
    # We have to do it like this so we don't break the process pool.
    if isinstance(data, Exception):
        raise data
    return data


async def decode_output(call: ContractCall, data: bytes) -> Any:
    __validate_output(call.abi, data)
    try:
        if call._skip_decoder_proc_pool or b"Unexpected error" in data:  # Multicall3
            # This will break the process pool
            decoded = __decode_output(data, call.abi)
        else:
            try:
                decoded = await decode(call, data)
            # TODO: move this somewhere else
            except BrokenProcessPool:
                # Let's fix that right up
                logger.critical("Oh fuck, you broke the %s while decoding %s with abi %s", ENVS.BROWNIE_DECODER_PROCESSES, data, call.abi)  # type: ignore [attr-defined]
                ENVS.BROWNIE_DECODER_PROCESSES = AsyncProcessPoolExecutor(ENVS.BROWNIE_DECODER_PROCESSES._max_workers)  # type: ignore [attr-defined, assignment]
                decoded = __decode_output(data, call.abi)
        # We have to do it like this so we don't break the process pool.
        if isinstance(decoded, Exception):
            raise decoded
        return decoded
    except AttributeError as e: 
        # NOTE: Not sure why this happens as we set the attr while patching the call but w/e, this works for now
        if not str(e).endswith(" object has no attribute '_skip_decoder_proc_pool'"):
            raise e
        logger.debug("DEBUG ME BRO: %s", e)
        call._skip_decoder_proc_pool = call._address in _skip_proc_pool
        return await decode_output(call, data)

async def _request_data_no_args(call: ContractCall) -> HexStr:
    return call.signature

# These methods were renamed in eth-abi 4.0.0
__eth_abi_encode = eth_abi.encode if hasattr(eth_abi, 'encode') else eth_abi.encode_abi
__eth_abi_decode = eth_abi.decode if hasattr(eth_abi, 'decode') else eth_abi.decode_abi

def __encode_input(abi: Dict[str, Any], signature: str, *args: Tuple[Any,...]) -> Union[HexStr, Exception]:
    try:
        data = format_input(abi, args)
        types_list = get_type_strings(abi["inputs"])
        return signature + __eth_abi_encode(types_list, data).hex()
    except Exception as e:
        return e

_skip_proc_pool = {"0xcA11bde05977b3631167028862bE2a173976CA11"}  # multicall3
# NOTE: retry 429 errors if running multiple services on same rpc
while True:
    try:
        chainid = chain.id
        break
    except Exception as e:
        if "429" not in str(e):
            raise e
if multicall2 := MULTICALL2_ADDRESSES.get(chainid, None):
    _skip_proc_pool.add(to_checksum_address(multicall2))
    
def __decode_output(hexstr: BytesLike, abi: Dict[str, Any]) -> Any:
    try:
        types_list = get_type_strings(abi["outputs"])
        result = __eth_abi_decode(types_list, HexBytes(hexstr))
        result = format_output(abi, result)
        if len(result) == 1:
            result = result[0]
        return result
    except Exception as e:
        return e

def __validate_output(abi: Dict[str, Any], hexstr: BytesLike):
    try:
        selector = HexBytes(hexstr)[:4].hex()
        if selector == "0x08c379a0":
            revert_str = eth_abi.decode_abi(["string"], HexBytes(hexstr)[4:])[0]
            raise Revert(f"Call reverted: {revert_str}")
        elif selector == "0x4e487b71":
            error_code = int(HexBytes(hexstr)[4:].hex(), 16)
            if error_code in SOLIDITY_ERROR_CODES:
                revert_str = SOLIDITY_ERROR_CODES[error_code]
            else:
                revert_str = f"Panic (error code: {error_code})"
            raise Revert(f"Call reverted: {revert_str}")
        elif selector == "0xc1b84b2f":
            raise Revert(f"Call reverted: execution reverted")
        if abi["outputs"] and not hexstr:
            raise Revert("No data was returned - the call likely reverted")
    except ValueError as e:
        try:
            raise VirtualMachineError(e) from None
        except:
            raise e

