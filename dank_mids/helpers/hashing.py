from collections.abc import Hashable
from typing import Any, Mapping, TypeVar, final

from web3.datastructures import AttributeDict


TKey = TypeVar("TKey", bound=Hashable)
TValue = TypeVar("TValue")


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


@final
class AttributeDict(Mapping[TKey, TValue], Hashable):
    """
    Provides superficial immutability, someone could hack around it
    """

    def __init__(
        self, dictionary: Dict[TKey, TValue], *args: TKey, **kwargs: TValue
    ) -> None:
        self.__dict__: Final = dict(dictionary)
        self.__dict__.update(dict(*args, **kwargs))

    def __hash__(self) -> int:
        return hash(tuple(sorted(tupleize_lists_nested(self).items())))

    def __eq__(self, other: Any) -> bool:
        if isinstance(other, AttributeDict):
            return hash(self) == hash(other)
        elif isinstance(other, Mapping):
            return self.__dict__ == dict(other)
        else:
            return False

    def __setattr__(self, attr: str, val: TValue) -> None:
        if attr == "__dict__":
            super().__setattr__(attr, val)
        raise Web3TypeError(
            "This data is immutable -- create a copy instead of modifying"
        )

    def __delattr__(self, key: str) -> None:
        raise Web3TypeError(
            "This data is immutable -- create a copy instead of modifying"
        )

    def __getitem__(self, key: TKey) -> TValue:
        return self.__dict__[key]

    def __iter__(self) -> Iterator[Any]:
        return iter(self.__dict__)

    def __len__(self) -> int:
        return len(self.__dict__)

    def __repr__(self) -> str:
        return self.__class__.__name__ + f"({self.__dict__!r})"

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
        if isinstance(value, Mapping):
            return AttributeDict({k: AttributeDict.recursive(v) for k, v in value.items()})
        elif isinstance(value, Sequence) and not isinstance(value, (str, bytes)):
            return type(value)([AttributeDict.recursive(v) for v in value])  # type: ignore
        elif isinstance(value, set):
            return {AttributeDict.recursive(v) for v in value}
        return value
