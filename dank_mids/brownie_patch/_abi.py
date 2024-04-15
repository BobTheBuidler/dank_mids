
import functools
from typing import Any

from brownie.convert.utils import build_function_selector, build_function_signature
from web3.datastructures import AttributeDict


@functools.lru_cache(maxsize=None)
class FunctionABI:
    """A singleton to hold function signatures, since we only really need one copy of each func sig in memory."""
    __slots__ = "abi", "input_sig", "signature"
    def __init__(self, **abi: Any):
        self.abi = abi
        self.input_sig = build_function_signature(abi)
        self.signature = build_function_selector(abi)
    
def _make_hashable(obj: Any) -> Any:
    if isinstance(obj, (list, tuple)):
        return tuple((_make_hashable(o) for o in obj))
    elif isinstance(obj, dict):
        return AttributeDict({k: _make_hashable(v) for k, v in obj.items()})
    return obj