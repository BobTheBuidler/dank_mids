from typing import Any, Callable, Final, Iterable, Iterator, List, Mapping, Sequence, Tuple, TypeVar

from eth_typing import TypeStr
from eth_utils.toolz import compose, curry
from web3._utils.abi import ABITypedData, abi_sub_tree, strip_abi_type


_T = TypeVar("_T")

Normalizer = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]
MapperKey = Tuple[Tuple[Normalizer, ...], Tuple[TypeStr, ...]]
DataTreeFunc = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]


@curry  # type: ignore [misc]
def map_abi_data(
    normalizers: Sequence[Normalizer],
    types: Tuple[TypeStr, ...],
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


_mappers: Final[Dict[MapperKey, Callable[..., List[Any]]]] = {}


def strip_abi_types(data: Any) -> Any:
    return recursive_map(strip_abi_type, data)


# web3py builds the pipeline every call, we cache it here instead
def get_mapper(
    normalizers: Tuple[Normalizer, ...],
    types: Tuple[TypeStr, ...],
) -> Callable[..., List[Any]]:
    mapper = _mappers.get((normalizers, types))
    if mapper is None:
        pipeline = (
            # 1. Decorating the data tree with types
            # web3.py implementation is `abi_data_tree(types)` but a lambda is faster than a curried func call
            lambda data: map(abi_sub_tree, types, data),
            # 2. Recursively mapping each of the normalizers to the data
            *map(get_data_tree_map, normalizers),
            # 3. Stripping the types back out of the tree
            strip_abi_types,
            list,
        )
        mapper = _mappers[(normalizers, types)] = compose(*reversed(pipeline))
    return mapper


_data_tree_maps: Final[Dict[DataTreeFunc, Callable[[Any], ABITypedData]]] = {}


def get_data_tree_map(
    func: DataTreeFunc,
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


def recursive_map(func: Callable[..., _T], data: Any) -> _T:
    """
    Apply func to data, and any collection items inside data (using map_collection).
    Define func so that it only applies to the type of value that you
    want it to apply to.
    """

    def recurse(item: Any) -> _T:
        return recursive_map(func, item)

    items_mapped = map_collection(recurse, data)
    return func(items_mapped)


def map_collection(func: Callable[..., _T], collection: Any) -> Any:
    """
    Apply func to each element of a collection, or value of a dictionary.
    If the value is not a collection, return it unmodified
    """
    if isinstance(collection, map):
        return map(func, collection)
    elif isinstance(collection, Mapping):
        return type(collection)((key, func(val)) for key, val in collection.items())
    elif not isinstance(collection, (bytes, str, bytearray)) and isinstance(collection, Iterable):
        return type(collection)(map(func, collection))
    else:
        return collection
