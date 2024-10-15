
from functools import cached_property
from typing import Any, Iterable, Iterator, List, Tuple

from msgspec import UNSET, Struct


class DictStruct(Struct):
    """
    A base class that extends the :class:`~msgspec.Struct` class to provide dictionary-like access to struct fields.

    Allows iteration over the fields of a struct and provides a dictionary-like interface for retrieving values by field name.

    Example:
        >>> class MyStruct(DictStruct):
        ...     field1: str
        ...     field2: int
        >>> s = MyStruct(field1="value", field2=42)
        >>> list(s.keys())
        ['field1', 'field2']
        >>> s['field1']
        'value'
    """

    def __bool__(self) -> bool:
        """A Struct will always exist."""
        return True
    
    def __contains__(self, key: str) -> bool:
        return key in self._fields and getattr(self, key, UNSET) is not UNSET
    
    def get(self, key: str, default: Any = None) -> Any:
        return getattr(self, key, default)
    
    def __getitem__(self, attr: str) -> Any:
        """
        Lookup an attribute value via dictionary-style access.

        Args:
            attr: The name of the attribute to access.
        
        Raises:
            KeyError: If the provided key is not a member of the struct.

        Returns:
            The value of the attribute.
        """
        try:
            return getattr(self, attr)
        except AttributeError:
            raise KeyError(attr, self) from None
    
    def __getattribute__(self, attr: str) -> Any:
        """
        Get the value of an attribute, raising AttributeError if the value is :obj:`UNSET`.
        
        Parameters:
            attr: The name of the attribute to fetch.

        Raises:
            AttributeError: If the value is :obj:`~UNSET`.
    
        Returns:
            The value of the attribute.
        """
        value = super().__getattribute__(attr)
        if value is UNSET:
            raise AttributeError(f"'{type(self).__name__}' object has no attribute '{attr}'")
        return value

    def __iter__(self) -> Iterator[str]:
        """
        Iterate thru the keys of the Struct.

        Yields:
            Struct key.
        """
        for field in self._fields:
            value = getattr(self, field, UNSET)
            if value is not UNSET:
                yield field
    
    def __len__(self) -> int:
        """
        The number of keys in the Struct.
        
        Returns:
            The number of keys.
        """
        return len(list(self))

    def keys(self) -> Iterator[str]:
        """
        Returns an iterator over the field names of the struct.

        Returns:
            An iterator over the field names.
        """
        yield from self

    def items(self) -> Iterator[Tuple[str, Any]]:
        for key in self._fields:
            value = getattr(self, key, UNSET)
            if value is not UNSET:
                yield key, value
    
    def values(self) -> Iterator[Any]:
        """
        Returns an iterator over the struct's field values.

        Returns:
            An iterator over the field values.
        """
        for key in self._fields:
            value = getattr(self, key, UNSET)
            if value is not UNSET:
                yield value

    @property
    def _fields(self) -> Iterable[str]:
        return self.__struct_fields__


class LazyDictStruct(DictStruct, frozen=True, dict=True):  # type: ignore [call-arg]
    @cached_property
    def _fields(self) -> List[str]:
        return [field[1:] if field[0] == '_' else field for field in self.__struct_fields__]
