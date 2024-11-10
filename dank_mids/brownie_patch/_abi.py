import functools
from typing import Any

from brownie.convert.utils import build_function_selector, build_function_signature


class FunctionABI:
    """
    A singleton class to hold function ABI information.

    This class uses the lru_cache decorator to ensure only one instance is created
    for each unique set of ABI parameters, optimizing memory usage and performance.
    """

    __slots__ = "abi", "input_sig", "signature"

    def __init__(self, **abi: Any):
        """
        Initialize a FunctionABI instance with the given ABI information.

        Args:
            **abi: Keyword arguments representing the ABI of the function.
        """

        self.abi = abi
        """
        The complete ABI (Application Binary Interface) of the function.
        This contains all the information about the function's interface.
        """

        self.input_sig = build_function_signature(abi)
        """
        The input signature of the function.
        This is a string representation of the function's parameters and their types.
        """

        self.signature = build_function_selector(abi)
        """
        The function selector (4-byte signature) of the function.
        This is used in Ethereum transactions to identify which function to call.
        """


@functools.lru_cache(maxsize=None)
def build_abi(**abi: Any) -> FunctionABI:
    return FunctionABI(**abi)
