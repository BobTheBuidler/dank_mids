
import asyncio
import functools
from decimal import Decimal
from typing import Any, Awaitable, Callable, Dict, Generic, Iterable, List, Optional, TypeVar

from brownie.typing import AccountsType
from brownie.convert.datatypes import EthAddress
from eth_abi.exceptions import InsufficientDataBytes
from web3 import Web3

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.brownie_patch._abi import FunctionABI
from dank_mids.helpers._helpers import _make_hashable

_EVMType = TypeVar("_EVMType")

class _DankMethodMixin(Generic[_EVMType]):
    _address: EthAddress
    _abi: FunctionABI
    """A mixin class that gives brownie objects async support and reduces memory usage"""
    __slots__ = "_address", "_abi", "_name", "_owner", "natspec", "_encode_input", "_decode_input"
    def __await__(self):
        """Asynchronously call the contract method without arguments at the latest block and await the result."""
        return self.coroutine().__await__()
    async def map(
        self, 
        args: Iterable[Any], 
        block_identifier: Optional[int] = None,
        decimals: Optional[int] = None,
    ) -> List[_EVMType]:
        return await asyncio.gather(*[self.coroutine(arg, block_identifier=block_identifier, decimals=decimals) for arg in args])
    @property
    def abi(self) -> dict:
        return self._abi.abi
    @property
    def signature(self) -> str:
        return self._abi.signature
    @property
    def _input_sig(self) -> str:
        return self._abi.input_sig
    @functools.cached_property
    def _len_inputs(self) -> int:
        return len(self.abi['inputs'])
    @functools.cached_property
    def _skip_decoder_proc_pool(self) -> bool:
        from dank_mids.brownie_patch.call import _skip_proc_pool
        return self._address in _skip_proc_pool
    @functools.cached_property
    def _web3(cls) -> Web3:
        from dank_mids import web3
        return web3
    @functools.cached_property
    def _prep_request_data(self) -> Callable[..., Awaitable[bytes]]:
        from dank_mids.brownie_patch import call
        if ENVS.OPERATION_MODE.application or self._len_inputs:
            return call.encode
        else:
            return call._request_data_no_args

class _DankMethod(_DankMethodMixin):
    __slots__ = "_address", "_abi", "_name", "_owner", "natspec", "_encode_input", "_decode_output"
    def __init__(
        self,
        address: str,
        abi: Dict,
        name: str,
        owner: Optional[AccountsType],
        natspec: Optional[Dict] = None,
    ) -> None:
        self._address = address
        self._abi = FunctionABI(**{key: _make_hashable(abi[key]) for key in sorted(abi)})
        self._name = name
        self._owner = owner
        self.natspec = natspec or {}
        # TODO: refactor this
        from dank_mids.brownie_patch import call
        self._encode_input = call.encode_input
        self._decode_output = call.decode_output
    async def coroutine(  # type: ignore [empty-body]
        self, 
        *args: Any, 
        block_identifier: Optional[int] = None, 
        decimals: Optional[int] = None,
        override: Optional[Dict[str, str]] = None,
    ) -> _EVMType:
        """
        Asynchronously call the contract method via dank mids and await the result.
        
        Arguments:
            - *args: The arguments for the contract method.
            - block_identifier (optional): The block at which the chain will be read. If not provided, will read the chain at latest block.
            - decimals (optional): if provided, the output will be `result / 10 ** decimals`
        
        Returns:
            - Whatever the node sends back as the output for this contract method.
        """
        if override:
            raise ValueError("Cannot use state override with `coroutine`.")
        async with ENVS.BROWNIE_ENCODER_SEMAPHORE[block_identifier]:  # type: ignore [attr-defined]
            data = await self._encode_input(self, self._len_inputs, self._prep_request_data, *args)
            async with ENVS.BROWNIE_CALL_SEMAPHORE[block_identifier]:  # type: ignore [attr-defined]
                output = await self._web3.eth.call({"to": self._address, "data": data}, block_identifier)
        try:
            decoded = await self._decode_output(self, output)
        except InsufficientDataBytes as e:
            raise InsufficientDataBytes(str(e), self, self._address, output) from e
        return decoded if decimals is None else decoded / 10 ** Decimal(decimals)