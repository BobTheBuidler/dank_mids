import functools
from collections.abc import Hashable
from typing import (
    Any,
    Dict,
    Final,
    Generic,
    ItemsView,
    Iterator,
    KeysView,
    List,
    Mapping,
    Optional,
    Sequence,
    Tuple,
    TypeVar,
    Union,
    ValuesView,
    cast,
    final,
)

from mypy_extensions import mypyc_attr


TKey = TypeVar("TKey", bound=Hashable)
TValue = TypeVar("TValue")


def make_hashable(obj: Any) -> Hashable:
    """
    Converts an object into a hashable type if possible.

    This function is used internally to ensure that objects can be used as
    dictionary keys or in sets.

    Args:
        obj: The object to make hashable.
    """
    if isinstance(obj, (list, tuple)):
        return tuple(map(make_hashable, obj))
    elif isinstance(obj, dict):
        return AttributeDict({key: make_hashable(obj[key]) for key in obj})
    return cast(Hashable, obj)


@final
@mypyc_attr(native_class=False)
class AttributeDict(Generic[TKey, TValue]):
    """
    Provides superficial immutability, someone could hack around it
    """

    def __init__(self, dictionary: Dict[TKey, TValue], *args: TKey, **kwargs: TValue) -> None:
        self_dict = dict(dictionary)
        if args or kwargs:
            self_dict.update(dict(*args, **kwargs))  # type: ignore [arg-type]
        self.__dict__: Final = self_dict  # type: ignore [assignment]
        self.__hash: Optional[int] = None

    def __hash__(self) -> int:
        retval = self.__hash
        if retval is None:
            retval = hash(tuple(sorted(tupleize_lists_nested(self).items())))
            self.__hash = retval
        return retval

    def __eq__(self, other: Any) -> bool:
        if isinstance(other, AttributeDict):
            return hash(self) == hash(other)
        elif isinstance(other, Mapping):
            return self.__dict__ == dict(other)
        else:
            return False

    def __setattr__(self, attr: str, val: TValue) -> None:
        if attr in ("__dict__", "__hash"):
            super().__setattr__(attr, val)
        else:
            raise TypeError("This data is immutable -- create a copy instead of modifying")

    def __delattr__(self, key: str) -> None:
        raise TypeError("This data is immutable -- create a copy instead of modifying")

    def __getitem__(self, key: TKey) -> TValue:
        return self.__dict__[key]  # type: ignore [index, no-any-return]

    def __iter__(self) -> Iterator[Any]:
        return iter(self.__dict__)

    def __len__(self) -> int:
        return len(self.__dict__)

    def __repr__(self) -> str:
        return f"{self.__class__.__name__}({self.__dict__!r})"

    def _repr_pretty_(self, builder: Any, cycle: bool) -> None:
        """
        Custom pretty output for the IPython console
        https://ipython.readthedocs.io/en/stable/api/generated/IPython.lib.pretty.html#extending  # noqa: E501
        """
        builder.text(self.__class__.__name__ + "(")
        if cycle:
            builder.text("<cycle>")
        else:
            builder.pretty(self.__dict__)
        builder.text(")")

    @classmethod
    def recursive(cls, value: TValue) -> Any:
        """
        Recursively convert mappings to ReadableAttributeDict instances and
        process nested collections (e.g., lists, sets, and dictionaries).
        """
        if isinstance(value, tuple):
            return tuple(AttributeDict.recursive(v) for v in value)
        elif isinstance(value, list):
            return [AttributeDict.recursive(v) for v in value]
        elif isinstance(value, Mapping):
            return AttributeDict({k: AttributeDict.recursive(v) for k, v in value.items()})
        elif isinstance(value, set):
            return {AttributeDict.recursive(v) for v in value}
        elif isinstance(value, Sequence) and not isinstance(value, (str, bytes)):
            return type(value)(map(AttributeDict.recursive, value))  # type: ignore [call-arg]
        return value

    def keys(self) -> KeysView[TKey]:
        return self.__dict__.keys()  # type: ignore [return-value]

    def values(self) -> ValuesView[TValue]:
        return self.__dict__.values()

    def items(self) -> ItemsView[TKey, TValue]:
        return self.__dict__.items()  # type: ignore [return-value]


Hashable.register(AttributeDict)


def tupleize_lists_nested(
    d: Union[AttributeDict[TKey, TValue], Mapping[TKey, TValue]],
) -> AttributeDict[TKey, TValue]:
    """
    Unhashable types inside dicts will throw an error if attempted to be hashed.
    This method converts lists to tuples, rendering them hashable.
    Other unhashable types found will raise a TypeError
    """

    ret = {}
    for k, v in d.items():
        if isinstance(v, (list, tuple)):
            ret[k] = _to_tuple(v)
        elif isinstance(v, dict) or isinstance(v, AttributeDict) or isinstance(v, Mapping):
            ret[k] = tupleize_lists_nested(v)
        else:
            try:
                ret[k] = v
            except TypeError:
                raise TypeError(f"Found unhashable type '{type(v).__name__}': {v}") from None

    return AttributeDict(ret)


@functools.singledispatch
def _to_tuple(value: Union[List[Any], Tuple[Any, ...]]) -> Any:
    return tuple(_to_tuple(i) if isinstance(i, (list, tuple)) else i for i in value)


@_to_tuple.register(list)
def _(value: List[Any]) -> Any:
    return tuple(_to_tuple(i) if isinstance(i, (list, tuple)) else i for i in value)


@_to_tuple.register(tuple)
def _(value: Tuple[Any, ...]) -> Any:
    return tuple(_to_tuple(i) if isinstance(i, (list, tuple)) else i for i in value)
