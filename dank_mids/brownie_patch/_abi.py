from typing import Any, Dict, Final, List, Optional, Tuple, final
from weakref import WeakValueDictionary

from eth_hash import auto

from dank_mids.brownie_patch import _nocompile
from dank_mids.helpers import _helpers


SingletonKey = Tuple[Tuple[str, Any], ...]

_singletons: Final["WeakValueDictionary[SingletonKey, FunctionABI]"] = WeakValueDictionary()


keccak: Final = auto.keccak

_make_hashable: Final = _helpers._make_hashable


# NOTE we must inherit from a python object in order for weakrefs to work, so for now we inherit from _FunctionABI
# https://github.com/python/cpython/blob/9546eeea90c8deb8570a0ef621f075c3c766bc12/Include/internal/pycore_object.h#L874
# https://github.com/python/mypy/blob/501a07b45af8e44eda665e53526fc590dc5a014e/mypyc/irbuild/vtable.py#L17
# https://github.com/python/mypy/blob/501a07b45af8e44eda665e53526fc590dc5a014e/mypyc/codegen/emitclass.py#L285
# TODO: fix the above


@final
class FunctionABI(_nocompile._FunctionABI):
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


def get_type_strings(
    abi_params: List[Dict[str, Any]], 
    substitutions: Optional[Dict[str, Any]] = None,
) -> List[str]:
    """Converts a list of parameters from an ABI into a list of type strings."""
    types_list = []
    if substitutions is None:
        substitutions = {}

    for i in abi_params:
        type_str: str = i["type"]
        if type_str.startswith("tuple"):
            params = get_type_strings(i["components"], substitutions)
            array_size = i["type"][5:]
            types_list.append(f"({','.join(params)}){array_size}")
        else:
            for orig, sub in substitutions.items():
                if type_str.startswith(orig):
                    type_str = type_str.replace(orig, sub)
            types_list.append(type_str)

    return types_list


def build_function_signature(abi: Dict[str, Any]) -> str:
    types_list = get_type_strings(abi["inputs"])
    return f"{abi['name']}({','.join(types_list)})"


def build_function_selector(abi: Dict[str, Any]) -> str:
    sig = build_function_signature(abi)
    return f"0x{keccak(sig.encode()).hex()[:8]}"
