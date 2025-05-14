from typing import Any, Callable, Iterable, Iterator, List, Sequence, Tuple

from eth_typing import TypeStr
from eth_utils.toolz import compose, curry
from web3._utils.abi import ABITypedData, abi_sub_tree, strip_abi_type
from web3._utils.formatters import recursive_map
from web3.types import TValue


@curry
def map_abi_data(
    normalizers: Sequence[Callable[[TypeStr, Any], Tuple[TypeStr, Any]]],
    types: Sequence[TypeStr],
    data: Sequence[Any],
) -> List[Any]:
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
) -> Callable[..., List[Any]]:
    mapper = _mappers.get((normalizers, types))
    if mapper is None:
        pipeline = (
            # 1. Decorating the data tree with types
            # web3.py implementation is `abi_data_tree(types)` but a lambda is faster than a curried func call
            lambda data: map(abi_sub_tree, types, data),
            # 2. Recursively mapping each of the normalizers to the data
            IteratorProxy,
            *map(get_data_tree_map, normalizers),
            # 3. Stripping the types back out of the tree
            strip_abi_types,
            list,
        )
        mapper = _mappers[(normalizers, types)] = compose(*reversed(pipeline))
    return mapper


class IteratorProxy(Iterable[TValue]):
    """Wraps an iterator to return when iterated upon"""

    def __init__(self, iterator: Iterator[TValue]) -> None:
        self.__wrapped = iterator

    def __iter__(self) -> Iterator[TValue]:
        try:
            return self.__dict__.pop("_IteratorProxy__wrapped")
        except KeyError as e:
            raise RuntimeError(f"{type(self).__name__} has already been consumed") from e.__cause__


_data_tree_maps = {}


def get_data_tree_map(
    func: Callable[[TypeStr, Any], Tuple[TypeStr, Any]],
) -> Callable[[Any], ABITypedData]:
    f = _data_tree_maps.get(func)
    if f is None:

        def map_to_typed_data(elements: Any) -> ABITypedData:
            if isinstance(elements, ABITypedData) and elements.abi_type is not None:
                return ABITypedData(func(*elements))
            else:
                return elements

        typed_data_func = lambda data: recursive_map(map_to_typed_data, data)

        f = _data_tree_maps[func] = typed_data_func

    return f
