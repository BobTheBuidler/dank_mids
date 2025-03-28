from functools import partial
from typing import Any, Callable, Sequence, Tuple

from eth_typing import TypeStr
from eth_utils.toolz import compose, curry
from web3._utils.abi import abi_sub_tree, data_tree_map, strip_abi_type
from web3._utils.formatters import recursive_map


@curry
def map_abi_data(
    normalizers: Sequence[Callable[[TypeStr, Any], Tuple[TypeStr, Any]]],
    types: Sequence[TypeStr],
    data: Sequence[Any],
) -> Any:
    """
    This function will apply normalizers to your data, in the
    context of the relevant types. Each normalizer is in the format:

    def normalizer(datatype, data):
        # Conditionally modify data
        return (datatype, data)

    Where datatype is a valid ABI type string, like "uint".

    In case of an array, like "bool[2]", normalizer will receive `data`
    as an iterable of typed data, like `[("bool", True), ("bool", False)]`.

    Internals
    ---

    This is accomplished by:

    1. Decorating the data tree with types
    2. Recursively mapping each of the normalizers to the data
    3. Stripping the types back out of the tree
    """
    return get_mapper(normalizers, types)(data)


_mappers = {}


def strip_abi_types(data):
    return recursive_map(strip_abi_type, data)


# web3py builds the pipeline every call, we cache it here instead
def get_mapper(
    normalizers: Tuple[Callable[[TypeStr, Any], Tuple[TypeStr, Any]], ...],
    types: Tuple[TypeStr, ...],
) -> Tuple[Callable, ...]:
    mapper = _mappers.get((normalizers, types))
    if mapper is None:
        pipeline = [
            # 1. Decorating the data tree with types
            # web3.py implementation is `abi_data_tree(types)` but a lambda is faster than a curried func call
            lambda data: map(abi_sub_tree, types, data),
            # 2. Recursively mapping each of the normalizers to the data
            *map(data_tree_map, normalizers),
            # 3. Stripping the types back out of the tree
            strip_abi_types,
        ]
        mapper = _mappers[(normalizers, types)] = compose(*pipeline.__reversed__())
    return mapper
