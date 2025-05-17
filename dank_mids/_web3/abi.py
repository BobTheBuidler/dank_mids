from typing import Any, Callable, Dict, Final, Iterable, Iterator, List, Mapping, Tuple, TypeVar

from eth_typing import TypeStr
from eth_utils.toolz import compose, curry
from web3._utils.abi import abi_sub_tree
from web3._utils import abi


_T = TypeVar("_T")

Normalizer = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]
MapperKey = Tuple[Tuple[Normalizer, ...], Tuple[TypeStr, ...]]
DataTreeFunc = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]

ABITypedData: Final = abi.ABITypedData


@curry  # type: ignore [misc]
def map_abi_data(
    normalizers: Tuple[Normalizer, ...],
    types: Tuple[TypeStr, ...],
    data: Iterable[Any],
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


_data_tree_maps: Final[Dict[DataTreeFunc, Callable[[Any], abi.ABITypedData]]] = {}


def get_data_tree_map(
    func: DataTreeFunc,
) -> Callable[[Any], abi.ABITypedData]:
    f = _data_tree_maps.get(func)
    if f is None:

        def map_to_typed_data(elements: Any) -> abi.ABITypedData:
            datatype = type(elements)
            if datatype is map or datatype is list:
                return [map_to_typed_data(obj) for obj in elements]
            elif datatype is tuple:
                return tuple(map_to_typed_data(obj) for obj in elements)
            elif isinstance(elements, Mapping):
                return type(elements)((key, map_to_typed_data(val)) for key, val in elements.items())  # type: ignore [call-arg]
            elif not isinstance(elements, (bytes, str, bytearray)) and isinstance(
                elements, Iterable
            ):
                return type(elements)(map(map_to_typed_data, elements))
            elif isinstance(elements, ABITypedData) and elements.abi_type is not None:
                return ABITypedData(func(*elements))
            else:
                return elements

        f = _data_tree_maps[func] = map_to_typed_data

    return f


def strip_abi_types(data: Any) -> Any:
    datatype = type(data)
    if datatype is map or datatype is list:
        return [strip_abi_types(obj) for obj in data]
    elif datatype is tuple:
        return tuple(strip_abi_types(obj) for obj in data)
    elif isinstance(data, Mapping):
        return type(data)((key, strip_abi_types(val)) for key, val in data.items())  # type: ignore [call-arg]
    elif not isinstance(elements, (bytes, str, bytearray)) and isinstance(elements, Iterable):
        return type(elements)(map(strip_abi_types, elements))
    else:
        return strip_abi_type(data)


def strip_abi_type(elements: Any) -> Any:
    if isinstance(elements, ABITypedData):
        return elements.data
    else:
        return elements
