import typing
from typing import Any, Callable, Dict, Final, Iterator, List, Tuple, TypeVar

from eth_typing import TypeStr
from eth_utils.toolz import compose, curry
from web3._utils.abi import abi_sub_tree
from web3._utils import abi


_T = TypeVar("_T")


Normalizer = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]
MapperKey = Tuple[Tuple[Normalizer, ...], Tuple[TypeStr, ...]]
DataTreeFunc = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]


# cdef typing
Iterable: Final = typing.Iterable
Mapping: Final = typing.Mapping


ABITypedData: Final = abi.ABITypedData


@curry  # type: ignore [misc]
def map_abi_data(
    normalizers: Tuple[Normalizer, ...],
    types: Tuple[TypeStr, ...],
    data: typing.Iterable[Any],
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


_mappers: Final[Dict[MapperKey, "_Mapper"]] = {}


# web3py builds the pipeline every call, we cache it here instead
def get_mapper(
    normalizers: Tuple[Normalizer, ...],
    types: Tuple[TypeStr, ...],
) -> "_Mapper":
    mapper = _mappers.get((normalizers, types))
    if mapper is None:
        mapper = _mappers[(normalizers, types)] = _Mapper(normalizers, types)
    return mapper


@final
class _Mapper:
    def __init__(
        self,
        normalizers: Tuple[Normalizer, ...],
        types: Tuple[TypeStr, ...],
    ):
        # TODO: vendor ABITypedData and cache some stuff from web3py
        self.normalizers: Final = tuple(get_data_tree_map(n) for n in normalizers)
        self.types: Final = types

    def __call__(self, data: Any) -> List[Any]:
        # 1. Decorating the data tree with types
        # TODO: vendor abi_sub_tree
        data = map(abi_sub_tree, self.types, self.data)
        # 2. Recursively mapping each of the normalizers to the data
        for n in self.normalizers:
            data = n(data)
        # 3. Stripping the types back out of the tree
        return list(strip_abi_types(data))


_data_tree_maps: Final[Dict[DataTreeFunc, "map_to_typed_data"]] = {}


def get_data_tree_map(
    func: DataTreeFunc,
) -> "map_to_typed_data":
    f = _data_tree_maps.get(func)
    if f is None:
        f = _data_tree_maps[func] = map_to_typed_data(func)
    return f


@final
class map_to_typed_data:
    def __init__(self, func: DataTreeFunc) -> None:
        self.func: Final = func

    def __call__(self, elements: Any) -> Any:
        datatype = type(elements)
        if datatype is map or datatype is list:
            return [self(obj) for obj in elements]
        elif datatype is tuple:
            return tuple(self(obj) for obj in elements)
        elif isinstance(elements, Mapping):
            return datatype((key, self(val)) for key, val in elements.items())  # type: ignore [call-arg]
        elif not isinstance(elements, (bytes, str, bytearray)) and isinstance(elements, Iterable):
            return datatype(map(self, elements))
        elif isinstance(elements, ABITypedData) and elements.abi_type is not None:
            return ABITypedData(self.func(*elements))
        else:
            return elements


def strip_abi_types(data: Any) -> Any:
    datatype = type(data)
    if datatype is map or datatype is list:
        return [strip_abi_types(obj) for obj in data]
    elif datatype is tuple:
        return tuple(strip_abi_types(obj) for obj in data)
    elif isinstance(data, Mapping):
        return datatype((key, strip_abi_types(val)) for key, val in data.items())  # type: ignore [call-arg]
    elif not isinstance(data, (bytes, str, bytearray)) and isinstance(data, Iterable):
        return datatype(map(strip_abi_types, data))
    elif isinstance(data, ABITypedData):
        return data.data
    else:
        return data
