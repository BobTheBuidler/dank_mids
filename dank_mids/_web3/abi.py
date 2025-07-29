import typing
from dataclasses import dataclass
from typing import Any, Callable, Dict, Final, List, Tuple, TypeVar, final

from eth_abi import grammar
from eth_abi.grammar import ABIType, TupleType
from eth_typing import TypeStr


_T = TypeVar("_T")


Normalizer = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]
MapperKey = Tuple[Tuple[Normalizer, ...], Tuple[TypeStr, ...]]
DataTreeFunc = Callable[[TypeStr, Any], Tuple[TypeStr, Any]]


# cdef typing
Iterable: Final = typing.Iterable
Mapping: Final = typing.Mapping


parse: Final[Callable[[TypeStr], ABIType]] = grammar.parse


@final
class Formatter:
    def __init__(
        self,
        normalizers: Tuple[Normalizer, ...],
        types: Tuple[TypeStr, ...],
    ):
        self.normalizers: Final = tuple(get_data_tree_map(n) for n in normalizers)
        self.types: Final[Tuple[ABIType, ...]] = tuple(
            parse(t) if isinstance(t, TypeStr) else t for t in types
        )

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
    """Returns a cached :class:`~Formatter` for the unique combination of normalizers and types."""
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
            return ABITypedData(*self.func(*elements))  # type: ignore [misc]
        else:
            return elements


def strip_abi_types(data: Any) -> Any:
    datatype = type(data)
    if datatype is list or datatype is map:
        return [strip_abi_types(obj) for obj in data]
    elif isinstance(data, tuple):
        return tuple(strip_abi_types(obj) for obj in data)
    elif isinstance(data, Mapping):
        return datatype((key, strip_abi_types(val)) for key, val in data.items())  # type: ignore [call-arg]
    elif not isinstance(data, (bytes, str, bytearray)) and isinstance(data, Iterable):
        return datatype(map(strip_abi_types, data))
    elif isinstance(data, ABITypedData):
        return data.data
    else:
        return data


# vendored from web3.py so we can compile it


@final
@dataclass(frozen=True)
class ABITypedData:
    """
    This class marks data as having a certain ABI-type.

    >>> a1 = ABITypedData('address', addr1)
    >>> a2 = ABITypedData('address', addr2)
    >>> addrs = ABITypedData('address[]', [a1, a2])

    You can access the fields using tuple() interface, or with
    attributes:

    >>> assert a1.abi_type == a1[0]
    >>> assert a1.data == a1[1]

    Unlike a typical `namedtuple`, you initialize with a single
    positional argument that is iterable, to match the init
    interface of all other relevant collections.
    """

    # NOTE this class was changed to a dataclass so it compiles to C better

    abi_type: TypeStr
    data: Any


def abi_sub_tree(abi_type: ABIType, data_value: Any) -> ABITypedData:
    # TODO: specialize this function, possibly with functools.singledispatch

    # In the two special cases below, we rebuild the given data structures with
    # annotated items
    if abi_type.is_array:
        # If type is array, determine item type and annotate all
        # items in iterable with that type
        item_type = abi_type.item_type
        value_to_annotate = [abi_sub_tree(item_type, item_value) for item_value in data_value]
    elif isinstance(abi_type, TupleType):
        # Otherwise, if type is tuple, determine component types and annotate
        # tuple components in iterable respectively with those types
        value_to_annotate = type(data_value)(
            abi_sub_tree(comp_type, comp_value)
            for comp_type, comp_value in zip(abi_type.components, data_value)
        )
    else:
        value_to_annotate = data_value

    return ABITypedData(abi_type.to_type_str(), value_to_annotate)
