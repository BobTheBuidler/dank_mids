
from functools import lru_cache
from types import MethodType
from typing import Any, Callable, Dict, List, Optional, Tuple, Union

import eth_abi
from brownie.convert.normalize import ReturnValue
from brownie.convert.utils import get_type_strings
from brownie.exceptions import VirtualMachineError
from brownie.network.contract import ContractCall
from brownie.project.compiler.solidity import SOLIDITY_ERROR_CODES
from eth_abi import abi
from hexbytes import HexBytes
from multicall.utils import run_in_subprocess
from web3 import Web3
from web3.datastructures import AttributeDict

from dank_mids import _config
from dank_mids.brownie_patch import _codec, _formatters
from dank_mids.semaphore import ThreadsafeSemaphore

stream = abi.default_codec.stream_class
brownie_call_semaphore = ThreadsafeSemaphore(_config.BROWNIE_CALL_SEMAPHORE_VAL)


@lru_cache(maxsize=None)
def get_method_unaware_encode_fn(
    abi_inputs: Tuple[str, ...],
) -> str:
    formatter = _formatters.get_abi_formatter(abi_inputs)
    encoder = _codec.get_encoder(abi_inputs)
    def encode_args(args):
        return encoder(formatter(args)).hex()
    if _codec.should_cache(get_type_strings(abi_inputs)):
        encode_args = _codec.ENCODER_CACHE(encode_args)
    return encode_args

@lru_cache(maxsize=None)
def get_encode_fn(
    abi_name: str, 
    abi_inputs: Tuple[str, ...], 
    signature: str
) -> Callable[[Tuple[Any, ...]], str]:
    
    # NOTE: We define a function for each set of arg types so we don't need to parse the abi every call.
    if len(abi_inputs) == 0:
        async def encode_inputs(self: ContractCall, *args: Any):
            if len(args):
                raise TypeError(f"{abi_name} requires no arguments")
            return signature
    else:
        encode = get_method_unaware_encode_fn(abi_inputs)
        def __encode_inputs(*args) -> str:
            # Format contract inputs based on ABI types
            # NOTE: We've removed a bunch of if statements from the formatters to speed things up.
            try:
                return signature + encode(args)
            except Exception as e:
                raise type(e)(f"{abi_name} {e}") from None
            
        async def encode_inputs(self: ContractCall, *args: Any) -> str:
            # TODO: Figure out a better way to handle this
            #return await run_in_subprocess(__encode_inputs, *args)
            return __encode_inputs(*args)
        
    return encode_inputs


@lru_cache(maxsize=None)
def get_decode_fn(
    abi_outputs: Tuple[str, ...]
) -> Callable[[str], Any]:
    
    # NOTE: We define a function for each set of arg types so we don't need to parse the abi every call.
    decoder = _codec.get_decoder(abi_outputs)
    formatter = _formatters.get_abi_formatter(abi_outputs)
    
    def __decode_output(hexstr: str) -> Any:
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
        if abi_outputs and not hexstr:
            raise ValueError("No data was returned - the call likely reverted")
        
        result = ReturnValue(formatter(decoder(stream(HexBytes(hexstr)))), abi_outputs)
        if len(result) == 1:
            result = result[0]
        return result
    
    if _codec.should_cache(get_type_strings(abi_outputs)):
        __decode_output = _codec.DECODER_CACHE(__decode_output)
    
    async def decode_output(self: ContractCall, hexstr: str) -> Any:
        # TODO: Figure out a better way to handle this
        #return await run_in_subprocess(__decode_output, hexstr)
        return __decode_output(hexstr)
        
    
    return decode_output
    

@lru_cache(maxsize=None)
def get_coroutine_fn(w3: Web3):
    assert w3.eth.is_async, "You must provide a w3 instance with an async provider."
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
                    await w3.eth.call({"to": self._address, "data": await self._encode_input(*args)}, block_identifier)  # type: ignore
                )
            except ValueError as e:
                try:
                    raise VirtualMachineError(e) from None
                except:
                    raise e
    return coroutine

def _make_abi_hashable(
    abi: List[Dict[str, str]]
) -> Tuple[AttributeDict, ...]:
    """Takes a list of dicts and returns a hashable tuple of AttributeDicts."""
    return tuple(
        AttributeDict({k: _make_abi_hashable(v) if isinstance(v, list) else v for k, v in x.items()})
        for x in abi
    )

def _patch_call(call: ContractCall, w3: Web3) -> None:
    """Patch a brownie 'ContractCall' object with a 'coroutine' method for async calling."""
    # NOTE: We define abi-specific encode and decode functions in the hope that it speeds up execution.
    #       Haven't tested the impact but it definitely removes some boilerplate code from script execution which should only mean good things.
    encode_fn = get_encode_fn(call.abi['name'], _make_abi_hashable(call.abi['inputs']), call.signature)
    decode_fn = get_decode_fn(_make_abi_hashable(call.abi['outputs']))
    call._encode_input = MethodType(encode_fn, call)
    call._decode_output = MethodType(decode_fn, call)
    call.coroutine = MethodType(get_coroutine_fn(w3), call)
