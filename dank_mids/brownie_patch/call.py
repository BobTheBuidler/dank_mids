from concurrent.futures.process import BrokenProcessPool
from decimal import Decimal
from logging import getLogger
from pickle import PicklingError
from types import MethodType
from typing import Any, Callable, Dict, Final, List, NewType, Optional, Sequence, Tuple, Union

import brownie.convert.normalize
import brownie.network.contract
import eth_abi
from a_sync import AsyncProcessPoolExecutor
from brownie import chain
from brownie.convert.datatypes import ReturnValue
from brownie.convert.normalize import (
    ABIType,
    HexString,
    TupleType,
    _check_array,
    _get_abi_types,
    to_bool,
    to_decimal,
    to_int,
    to_string,
    to_uint,
)
from brownie.convert.utils import get_type_strings
from brownie.exceptions import VirtualMachineError
from brownie.network.contract import Contract, ContractCall
from brownie.project.compiler.solidity import SOLIDITY_ERROR_CODES
from eth_abi.exceptions import InsufficientDataBytes
from eth_typing import HexStr
from evmspec.data import Address
from hexbytes import HexBytes
from hexbytes.main import BytesLike
from multicall.constants import MULTICALL2_ADDRESSES
from typing_extensions import Self
from web3.types import BlockIdentifier

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.brownie_patch.types import ContractMethod
from dank_mids.exceptions import Revert
from dank_mids.helpers.lru_cache import lru_cache_lite_nonull
from dank_mids.helpers._helpers import DankWeb3


TypeStr = NewType("TypeStr", str)
TypeStrList = List[TypeStr]


logger = getLogger(__name__)

encode = lambda self, *args: ENVS.BROWNIE_ENCODER_PROCESSES.run(__encode_input, self.abi, self.signature, *args)  # type: ignore [attr-defined]
"""
A lambda function that encodes input data for contract calls.

This function uses the Brownie encoder process pool (BROWNIE_ENCODER_PROCESSES) to run the
synchronous function :func:`__encode_input` in a separate process asynchronously.

Args:
    self: The contract method instance.
    *args: The arguments to be encoded.

Examples:
    >>> encoded = encode(contract_call_instance, arg1, arg2)
    >>> # encoded is a hex string that represents the ABI-encoded function call.

See Also:
    :func:`__encode_input`
"""

decode: Final[Callable[[Any, bytes], Any]] = lambda self, data: ENVS.BROWNIE_DECODER_PROCESSES.run(__decode_output, data, self.abi)  # type: ignore [attr-defined]
"""
A lambda function that decodes output data for contract calls.

This function uses the Brownie decoder process pool (BROWNIE_DECODER_PROCESSES) to run the
synchronous function :func:`__decode_output` asynchronously.

Args:
    self: The contract method instance.
    data: The raw byte data returned from a contract call.

Examples:
    >>> decoded = decode(contract_call_instance, output_data)
    >>> # decoded now holds the parsed return value from the contract call.

See Also:
    :func:`__decode_output`
"""

# We assign this variable so ypricemagic's checksum cache monkey patch will work,
# This is only relevant to you if your project uses ypricemagic as well.
to_checksum_address = Address.checksum


def _patch_call(call: ContractCall, w3: DankWeb3) -> None:
    """
    Patch a Brownie ContractCall to enable asynchronous use via dank_mids for batching.

    Args:
        call: The original Brownie ContractCall to be patched.
        w3: An instance of DankWeb3 used to create the coroutine.

    The function modifies the ContractCall in place to add asynchronous capabilities.
    """
    call._skip_decoder_proc_pool = call._address in _skip_proc_pool
    call.coroutine = MethodType(_get_coroutine_fn(w3, len(call.abi["inputs"])), call)
    call.__await__ = MethodType(_call_no_args, call)


@lru_cache_lite_nonull
def _get_coroutine_fn(w3: DankWeb3, len_inputs: int) -> Callable:  # type: ignore [type-arg]
    if ENVS.OPERATION_MODE.application or len_inputs:  # type: ignore [attr-defined]
        get_request_data = encode
    else:
        get_request_data = _request_data_no_args  # type: ignore [assignment]

    async def coroutine(
        self: ContractCall,
        *args: Any,
        block_identifier: Optional[BlockIdentifier] = None,
        decimals: Optional[int] = None,
        override: Optional[Dict[str, str]] = None,
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


def _call_no_args(self: ContractMethod) -> Any:
    """Asynchronously call `self` with no arguments at the latest block."""
    return self.coroutine().__await__()


async def encode_input(call: ContractCall, len_inputs: int, get_request_data, *args) -> HexStr:  # type: ignore [no-untyped-def]
    # We will just assume containers contain a Contract object until we have a better way to handle this
    if any(isinstance(arg, Contract) or hasattr(arg, "__contains__") for arg in args):
        # We can't unpickle these because of the added `coroutine` method.
        data = __encode_input(call.abi, call.signature, *args)
    else:
        try:  # We're better off sending these to the subprocess so they don't clog up the event loop.
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
    except InsufficientDataBytes as e:
        # Add some context to the exception for the sake of the end-user.
        e.args = *e.args, call, call._address, data
        raise
    except AttributeError as e:
        # NOTE: Not sure why this happens as we set the attr while patching the call but w/e, this works for now.
        if not str(e).endswith(" object has no attribute '_skip_decoder_proc_pool'"):
            raise
        logger.debug("DEBUG ME BRO: %s", e)
        call._skip_decoder_proc_pool = call._address in _skip_proc_pool
        return await decode_output(call, data)


async def _request_data_no_args(call: ContractCall) -> HexStr:
    return call.signature


# These methods were renamed in eth-abi 4.0.0
__eth_abi_encode: Final[Callable[[TypeStrList, List[Any]], HexStr]] = (
    eth_abi.encode if hasattr(eth_abi, "encode") else eth_abi.encode_abi
)
__eth_abi_decode: Final[Callable[[TypeStrList, HexBytes], Tuple[Any, ...]]] = (
    eth_abi.decode if hasattr(eth_abi, "decode") else eth_abi.decode_abi
)


def __encode_input(abi: Dict[str, Any], signature: str, *args: Any) -> Union[HexStr, Exception]:
    try:
        data = format_input_but_cache_checksums(abi, args)
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
            raise
if multicall2 := MULTICALL2_ADDRESSES.get(chainid, None):
    _skip_proc_pool.add(to_checksum_address(multicall2))


def __decode_output(hexstr: BytesLike, abi: Dict[str, Any]) -> Any:
    try:
        types_list = get_type_strings(abi["outputs"])
        result = __eth_abi_decode(types_list, HexBytes(hexstr))
        result = format_output_but_cache_checksums(abi, result)
        if len(result) == 1:
            result = result[0]
        return result
    except Exception as e:
        return e


def __validate_output(abi: Dict[str, Any], hexstr: BytesLike) -> None:
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
            raise Revert("Call reverted: execution reverted")
        if abi["outputs"] and not hexstr:
            raise Revert("No data was returned - the call likely reverted")
    except ValueError as e:
        try:
            raise VirtualMachineError(e) from None
        except:
            raise e from e.__cause__


# NOTE: We do a little monkey patching to save cpu cycles on checksums


def format_input_but_cache_checksums(abi: Dict, inputs: Union[List, Tuple]) -> List:  # type: ignore [type-arg]
    # Format contract inputs based on ABI types
    if len(inputs) and not len(abi["inputs"]):
        raise TypeError(f"{abi['name']} requires no arguments")
    abi_types = _get_abi_types(abi["inputs"])
    try:
        return _format_tuple_but_cache_checksums(abi_types, inputs)
    except Exception as e:
        raise type(e)(f"{abi['name']} {e}") from e


def format_output_but_cache_checksums(abi: dict, outputs: Union[List, Tuple]) -> ReturnValue:  # type: ignore [type-arg]
    # Format contract outputs based on ABI types
    abi_types = _get_abi_types(abi["outputs"])
    result = _format_tuple_but_cache_checksums(abi_types, outputs)
    return ReturnValue(result, abi["outputs"])


brownie.network.contract.format_input = format_input_but_cache_checksums
brownie.network.contract.format_output = format_output_but_cache_checksums


def _format_tuple_but_cache_checksums(
    abi_types: Sequence[ABIType], values: Union[List, Tuple]  # type: ignore [type-arg]
) -> List:  # type: ignore [type-arg]
    result = []
    _check_array(values, len(abi_types))
    for type_, value in zip(abi_types, values):
        try:
            if type_.is_array:
                result.append(_format_array_but_cache_checksums(type_, value))
            elif isinstance(type_, TupleType):
                result.append(_format_tuple_but_cache_checksums(type_.components, value))
            else:
                result.append(_format_single_but_cache_checksums(type_.to_type_str(), value))
        except Exception as e:
            raise type(e)(f"'{value}' - {e}") from e
    return result


def _format_array_but_cache_checksums(abi_type: ABIType, values: Union[List, Tuple]) -> List:  # type: ignore [type-arg]
    _check_array(values, abi_type.arrlist[-1][0] if len(abi_type.arrlist[-1]) else None)
    item_type = abi_type.item_type
    if item_type.is_array:
        return list(map(lambda v: _format_array(item_type, v), values))
    elif isinstance(item_type, TupleType):
        components = item_type.components
        return list(map(lambda v: _format_tuple(components, v), values))
    else:
        type_str = item_type.to_type_str()
        return list(map(lambda v: _format_single(type_str, v), values))


def _format_single_but_cache_checksums(type_str: str, value: Any) -> Any:
    # Apply standard formatting to a single value
    if "uint" in type_str:
        return to_uint(value, type_str)
    elif "int" in type_str:
        return to_int(value, type_str)
    elif type_str == "fixed168x10":
        return to_decimal(value)
    elif type_str == "bool":
        return to_bool(value)
    elif type_str == "address":
        # NOTE: since we skip brownie's formatter we must ensure we pass in a usable type
        return to_checksum_address(
            value if isinstance(value, (str, bytes, bytearray, int, bool)) else str(value)
        )
    elif "byte" in type_str:
        return HexString(value, type_str)
    elif "string" in type_str:
        return to_string(value)
    raise TypeError(f"Unknown type: {type_str}")


# NOTE: The monkey patches above work for call input and output but the ones below help with event decoding.


brownie.convert.normalize._format_array = _format_array_but_cache_checksums
brownie.convert.normalize._format_single = _format_single_but_cache_checksums
brownie.convert.normalize._format_tuple = _format_tuple_but_cache_checksums

_format_array = _format_array_but_cache_checksums
_format_tuple = _format_tuple_but_cache_checksums
_format_single = _format_single_but_cache_checksums
