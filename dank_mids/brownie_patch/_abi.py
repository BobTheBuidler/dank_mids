
import functools
from typing import Any

from brownie.convert.utils import build_function_selector, build_function_signature


@functools.lru_cache(maxsize=None)
class FunctionABI:
    """A singleton to hold function signatures, since we only really need one copy of each func sig in memory."""
    __slots__ = "abi", "input_sig", "signature"
    def __init__(self, **abi: Any):
        self.abi = abi
        self.input_sig = build_function_signature(abi)
        self.signature = build_function_selector(abi)