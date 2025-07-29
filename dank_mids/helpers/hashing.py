from typing import Any

from web3.datastructures import AttributeDict


def make_hashable(obj: Any) -> Any:
    """
    Converts an object into a hashable type if possible.

    This function is used internally to ensure that objects can be used as
    dictionary keys or in sets.

    Args:
        obj: The object to make hashable.
    """
    if isinstance(obj, (list, tuple)):
        return tuple(make_hashable(o) for o in obj)
    elif isinstance(obj, dict):
        return AttributeDict({key: make_hashable(obj[key]) for key in obj})
    return obj
