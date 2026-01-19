from collections.abc import Iterable, Iterator
from typing import Final, Generic, TypeVar, final
from weakref import ref

_T = TypeVar("_T")


@final
class WeakList(Generic[_T]):
    def __init__(self, data: Iterable[_T] | None = None) -> None:
        # Mapping from object ID to weak reference
        self._refs: Final[dict[int, "ref[_T]"]] = {}
        if data is not None:
            self.extend(data)

    def __repr__(self) -> str:
        # Use list comprehension syntax within the repr function for clarity
        return f"{type(self).__name__}([{', '.join(map(repr, self))}])"

    def __len__(self) -> int:
        return len(self._refs)

    def __bool__(self) -> bool:
        return any(self)

    def __contains__(self, item: _T) -> bool:
        reference = self._refs.get(id(item))
        return False if reference is None else reference() is item

    def __iter__(self) -> Iterator[_T]:
        for reference in self._refs.values():
            obj = reference()
            if obj is not None:
                yield obj

    def append(self, item: _T) -> None:
        # Keep a weak reference with a callback for when the item is collected
        item_id = id(item)
        self._refs[item_id] = self._make_ref(item_id, item)

    def extend(self, items: Iterable[_T]) -> None:
        refs = self._refs
        for item in items:
            item_id = id(item)
            refs[item_id] = self._make_ref(item_id, item)

    def remove(self, item: _T) -> None:
        obj_id = id(item)
        reference = self._refs.get(obj_id)
        if reference is None or reference() is not item:
            raise ValueError("list.remove(x): x not in list")
        del self._refs[obj_id]

    def _make_ref(self, item_id: int, item: _T) -> "ref[_T]":
        def _gc_callback(_ref: "ref[_T]", item_id: int = item_id) -> None:
            self._refs.pop(item_id, None)

        return ref(item, _gc_callback)
