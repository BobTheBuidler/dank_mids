from typing import Any, Dict, Generic, Iterable, Iterator, TypeVar
from weakref import ReferenceType, ref


__T = TypeVar("__T")

_get_obj_from_ref = ref.__call__


class WeakList(Generic[__T]):
    def __init__(self, data=None):
        # Mapping from object ID to weak reference
        self._refs: Dict[int, ReferenceType[__T]] = {}
        if data is not None:
            self.extend(data)

    def __repr__(self) -> str:
        # Use list comprehension syntax within the repr function for clarity
        return f"{type(self).__name__}([{', '.join(map(repr, self))}])"

    def __len__(self) -> int:
        return len(self._refs)

    def __bool__(self) -> bool:
        return bool(self._refs)

    def __contains__(self, item: __T) -> bool:
        ref = self._refs.get(id(item))
        return False if ref is None else ref() is item

    def __iter__(self) -> Iterator[__T]:
        # sourcery skip: use-contextlib-suppress
        refs = (r for r in self._refs.values() if r is not None)
        try:
            for obj in map(_get_obj_from_ref, refs):
                if obj is not None:
                    yield obj
        except TypeError:
            # if this happens even with `refs` filtering the Nones,
            # that means python is shutting down and we can ignore it.
            # Otherwise, we can get ugly logs on shutdown as Multicall
            # and JSONRPCBatch objects have their __del__ method called.
            pass

    def append(self, item: __T) -> None:
        # Keep a weak reference with a callback for when the item is collected
        self._refs[id(item)] = ref(item, self._gc_callback)

    def extend(self, items: Iterable[__T]) -> None:
        callback = self._gc_callback
        self._refs.update((id(obj), ref(obj, callback)) for obj in items)

    def remove(self, item: __T) -> None:
        obj_id = id(item)
        ref = self._refs.get(obj_id)
        if ref is None or ref() is not item:
            raise ValueError("list.remove(x): x not in list")
        del self._refs[obj_id]

    def _gc_callback(self, item: Any) -> None:
        # Callback when a weakly-referenced object is garbage collected
        self._refs.pop(id(item), None)  # Safely remove the item if it exists
