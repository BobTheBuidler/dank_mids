from typing import Any, Dict, Final, Tuple, final
from weakref import WeakValueDictionary

from brownie.convert import utils

from dank_mids.helpers import _helpers


SingletonKey = Tuple[Tuple[str, Any], ...]

_singletons: Final["WeakValueDictionary[SingletonKey, FunctionABI]"] = WeakValueDictionary()


build_function_selector: Final = utils.build_function_selector
build_function_signature: Final = utils.build_function_signature

_make_hashable: Final = _helpers._make_hashable


@final
class FunctionABI:
    """
    A class to hold function ABI information.

    This class uses the lru_cache decorator to ensure only one instance is created
    for each unique set of ABI parameters, optimizing memory usage and performance.
    """

    def __init__(self, **abi: Any) -> None:
        """
        Initialize a FunctionABI instance with the given ABI information.

        Args:
            **abi: Keyword arguments representing the ABI of the function.
        """

        self.abi: Final = abi
        """
        The complete ABI (Application Binary Interface) of the function.
        This contains all the information about the function's interface.
        """

        self.input_sig: Final = build_function_signature(abi)
        """
        The input signature of the function.
        This is a string representation of the function's parameters and their types.
        """

        self.signature: Final = build_function_selector(abi)
        """
        The function selector (4-byte signature) of the function.
        This is used in Ethereum transactions to identify which function to call.
        """

        self.__dict__: Final[Dict[str, Any]] = {}
        """This __dict__ attr is needed for weakrefs to work."""
        #self.__weakref__: Optional["ReferenceType[FunctionABI]"] = None

    @staticmethod
    def singleton(**abi: Any) -> "FunctionABI":
        """
        Get a singleton FunctionABI to hold function ABI information.

        This class uses the lru_cache decorator to ensure only one instance is created
        for each unique set of ABI parameters, optimizing memory usage and performance.
        """
        key = tuple((k, _make_hashable(abi[k])) for k in sorted(abi))
        try:
            return _singletons[key]
        except KeyError:
            singleton = _singletons[key] = FunctionABI(**abi)
            return singleton
