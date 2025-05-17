import typing
from typing import Any, Callable, Dict, Final, Iterator, List, Tuple, TypeVar, final

from eth_abi.grammar import parse
from eth_typing import TypeStr
from web3._utils import abi


_T = TypeVar("_T")


Normalizer = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]
MapperKey = Tuple[Tuple[Normalizer, ...], Tuple[TypeStr, ...]]
DataTreeFunc = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]


# cdef typing
Iterable: Final = typing.Iterable
Mapping: Final = typing.Mapping


ABITypedData: Final = abi.ABITypedData
abi_sub_tree: Final = abi.abi_sub_tree


@final
class Formatter:
    def __init__(
        self,
        normalizers: Tuple[Normalizer, ...],
        types: Tuple[TypeStr, ...],
    ):
        # TODO: vendor ABITypedData and cache some stuff from web3py
        self.normalizers: Final = tuple(get_data_tree_map(n) for n in normalizers)
        self.types: Final = [parse(t) if isinstance(t, TypeStr) else t for t in types]

    def __call__(self, data: Any) -> List[Any]:
        # 1. Decorating the data tree with types
        # TODO: vendor abi_sub_tree, its v wasteful
        data = map(abi_sub_tree, self.types, data)
        # 2. Recursively mapping each of the normalizers to the data
        for n in self.normalizers:
            data = n(data)
        # 3. Stripping the types back out of the tree
        return list(strip_abi_types(data))


_formatters: Final[Dict[MapperKey, Formatter]] = {}


# web3py builds the pipeline every call, we cache it here instead
def get_formatter(
    normalizers: Tuple[Normalizer, ...],
    types: Tuple[TypeStr, ...],
) -> Formatter:
    mapper = _formatters.get((normalizers, types))
    if mapper is None:
        mapper = _formatters[(normalizers, types)] = Formatter(normalizers, types)
    return mapper


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
        if datatype is list or datatype is map:
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
    if datatype is list or datatype is map:
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
