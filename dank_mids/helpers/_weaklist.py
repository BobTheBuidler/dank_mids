import weakref
from typing import Any, Callable, Dict, Final, Generic, Iterable, Iterator, Optional, TypeVar


_T = TypeVar("_T")

Ref = weakref.ReferenceType[_T]
GCCallback = Callable[[Ref[Any]], None]

ref: Final[Callable[[_T, GCCallback], Ref[_T]]] = weakref.ref
_call_ref: Final[Callable[[Ref[_T]], _T]] = ref.__call__


class WeakList(Generic[_T]):
    def __init__(self, data: Optional[Iterable[_T]] = None) -> None:
        # Mapping from object ID to weak reference
        self._refs: Dict[int, Ref[_T]] = {}
        if data is not None:
            self.extend(data)

    def __repr__(self) -> str:
        # Use list comprehension syntax within the repr function for clarity
        return f"{type(self).__name__}([{', '.join(map(repr, self))}])"

    def __len__(self) -> int:
        return len(self._refs)

    def __bool__(self) -> bool:
        return bool(self._refs)

    def __contains__(self, item: _T) -> bool:
        ref = self._refs.get(id(item))
        return False if ref is None else ref() is item

    def __iter__(self) -> Iterator[_T]:
        for r in self._refs.values():
            if r is not None:
                obj = _call_ref(r)
                if obj is not None:
                    yield obj

    def append(self, item: _T) -> None:
        # Keep a weak reference with a callback for when the item is collected
        self._refs[id(item)] = ref(item, self._gc_callback)

    def extend(self, items: Iterable[_T]) -> None:
        callback = self._gc_callback
        self._refs.update((id(obj), ref(obj, callback)) for obj in items)

    def remove(self, item: _T) -> None:
        obj_id = id(item)
        ref = self._refs.get(obj_id)
        if ref is None or ref() is not item:
            raise ValueError("list.remove(x): x not in list")
        del self._refs[obj_id]

    def _gc_callback(self, item: Any) -> None:
        # Callback when a weakly-referenced object is garbage collected
        self._refs.pop(id(item), None)  # Safely remove the item if it exists
