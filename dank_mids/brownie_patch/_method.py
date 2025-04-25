from decimal import Decimal
from typing import (
    Any,
    Awaitable,
    Callable,
    Dict,
    Generator,
    Generic,
    Iterable,
    List,
    Optional,
    TypeVar,
)

from a_sync import igather
from brownie.convert.datatypes import EthAddress
from brownie.typing import AccountsType
from hexbytes.main import BytesLike

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.brownie_patch._abi import FunctionABI
from dank_mids.helpers._helpers import _make_hashable

_EVMType = TypeVar("_EVMType")


class _DankMethodMixin(Generic[_EVMType]):
    """
    A mixin class that is used internally to enhance Brownie's contract methods
    with asynchronous support and memory optimization.
    """

    _address: EthAddress
    """The address of the contract."""

    _abi: FunctionABI
    """The ABI (Application Binary Interface) of the contract function."""

    _prep_request_data: Callable[..., Awaitable[BytesLike]]

    def __init__(self) -> None:
        self._len_inputs = len(self.abi["inputs"])

        # cache `_call` on this object to prevent repeated imports due to circ import
        import dank_mids

        self._call = dank_mids.eth._call

        from dank_mids.brownie_patch import call

        if ENVS.OPERATION_MODE.application or self._len_inputs:  # type: ignore [attr-defined]
            self._prep_request_data = call.encode
        else:
            self._prep_request_data = call._request_data_no_args

        self._skip_decoder_proc_pool = self._address in call._skip_proc_pool

    def __await__(self) -> Generator[Any, None, _EVMType]:
        """
        Allow the contract method to be awaited.

        This method enables using 'await' on the contract method, which will call
        the method without arguments at the latest block and return the result.
        """
        return self.coroutine().__await__()

    async def map(
        self,
        args: Iterable[Any],
        block_identifier: Optional[int] = None,
        *,
        iter_args: bool = False,
        decimals: Optional[int] = None,
    ) -> List[_EVMType]:
        """
        Asynchronously call the contract method with multiple sets of arguments.

        This method allows for efficient batch calling of the contract method
        with different arguments.

        Args:
            args: An iterable of argument sets to be passed to the method.
            block_identifier: The block number or identifier for the calls.
            iter_args: True if you are passing an Iterable of Iterables, False otherwise.
            decimals: The number of decimal places by which to scale numeric results.
        """
        if iter_args:
            return await igather(
                self.coroutine(*call_args, block_identifier=block_identifier, decimals=decimals)
                for call_args in args
            )
        else:
            return await igather(
                self.coroutine(call_arg, block_identifier=block_identifier, decimals=decimals)
                for call_arg in args
            )

    @property
    def abi(self) -> dict:
        """
        The ABI of the contract function.

        This property provides access to the complete ABI dictionary of the function.
        """
        return self._abi.abi

    @property
    def signature(self) -> str:
        """
        The function signature.

        This property returns the unique signature of the contract function,
        which is used to identify the function in transactions.
        """
        return self._abi.signature

    async def coroutine(
        self,
        *args: Any,
        block_identifier: Optional[int] = None,
        decimals: Optional[int] = None,
        override: Optional[Dict[str, str]] = None,
    ) -> _EVMType:
        """
        Asynchronously call the contract method with the given arguments.

        This method is the core of the asynchronous functionality while using dank_mids with eth_brownie.

        Args:
            *args: Variable length argument list for the contract method.
            block_identifier: The block number or identifier for the call.
            decimals: The number of decimals by which to scale numeric results.
            override: Optional parameters to override chain state in the call.

        Note:
            This is a generic method and should be implemented in subclasses.
        """
        raise NotImplementedError

    @property
    def _input_sig(self) -> str:
        return self._abi.input_sig


get_function_abi = FunctionABI.singleton


class _DankMethod(_DankMethodMixin):
    def __init__(
        self,
        address: str,
        abi: Dict,
        name: str,
        owner: Optional[AccountsType],
        natspec: Optional[Dict] = None,
    ) -> None:
        self._address = address
        self._abi = get_function_abi(**{key: _make_hashable(abi[key]) for key in sorted(abi)})

        self._name = name
        """The name of the contract method."""

        self._owner = owner
        """The owner of the contract."""

        self.natspec = natspec or {}
        """The NatSpec documentation for the function."""

        super().__init__()

        # TODO: refactor this
        from dank_mids.brownie_patch import call

        self._encode_input = call.encode_input
        self._decode_output = call.decode_output

    async def coroutine(
        self,
        *args: Any,
        block_identifier: Optional[int] = None,
        decimals: Optional[int] = None,
        override: Optional[Dict[str, str]] = None,
    ) -> _EVMType:
        """
        Asynchronously call the contract method via dank mids and await the result.

        Args:
            *args: The arguments for the contract method.
            block_identifier: The block at which the chain will be read. If not provided, will read the chain at latest block.
            decimals: If provided, the output will be `result / 10 ** decimals`.

        Raises:
            ValueError: If the `override` parameter is used, as state overrides are not supported.

        Returns:
            The result of the contract method call.
        """
        if override:
            raise ValueError("Cannot use state override with `coroutine`.")

        encode_input_coro = self._encode_input(
            self, self._len_inputs, self._prep_request_data, *args
        )

        async with ENVS.BROWNIE_ENCODER_SEMAPHORE[block_identifier]:  # type: ignore [attr-defined,index]
            output_coro = self._call(  # type: ignore [call-arg]
                {"to": self._address, "data": await encode_input_coro},
                block_identifier,
            )
            async with ENVS.BROWNIE_CALL_SEMAPHORE[block_identifier]:  # type: ignore [attr-defined,index]
                decode_output_coro = self._decode_output(self, await output_coro)

        return (
            await decode_output_coro
            if decimals is None
            else await decode_output_coro / 10 ** Decimal(decimals)
        )
