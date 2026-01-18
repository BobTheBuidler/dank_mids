from collections.abc import Callable, Iterable, Iterator
from typing import Any, Final, Generic, TypeVar, final
from weakref import ref

_T = TypeVar("_T")

GCCallback = Callable[[Any], None]


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
        obj_id = id(item)
        self._refs[obj_id] = ref(item, self._gc_callback(obj_id))

    def extend(self, items: Iterable[_T]) -> None:
        make_callback = self._gc_callback
        for obj in items:
            obj_id = id(obj)
            self._refs[obj_id] = ref(obj, make_callback(obj_id))

    def remove(self, item: _T) -> None:
        obj_id = id(item)
        reference = self._refs.get(obj_id)
        if reference is None or reference() is not item:
            raise ValueError("list.remove(x): x not in list")
        del self._refs[obj_id]

    def _gc_callback(self, obj_id: int) -> GCCallback:
        # Callback factory so we can remove entries by the original object id.
        def _remove(_ref: Any) -> None:
            self._refs.pop(obj_id, None)

        return _remove
