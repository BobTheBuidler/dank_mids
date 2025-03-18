from typing import TYPE_CHECKING, Generic, Iterable, Iterator, TypeVar
from weakref import ref

if TYPE_CHECKING:
    from dank_mids._requests import _Request
else:
    _Request = TypeVar("_Request")


class WeakList(Generic[_Request]):
    def __init__(self, data=None):
        self._refs = {}  # Mapping from object ID to weak reference
        if data is not None:
            self.extend(data)

    def __repr__(self) -> str:
        # Use list comprehension syntax within the repr function for clarity
        return f"{type(self).__name__}([{', '.join(map(repr, self))}])"

    def __len__(self) -> int:
        return len(self._refs)

    def __bool__(self) -> bool:
        return bool(self._refs)

    def __contains__(self, item: _Request) -> bool:
        ref = self._refs.get(id(item))
        return False if ref is None else ref() is item

    def __iter__(self) -> Iterator[_Request]:
        for ref in self._refs.values():
            item = ref()
            if item is not None:
                yield item

    def append(self, item: _Request) -> None:
        # Keep a weak reference with a callback for when the item is collected
        self._refs[id(item)] = ref(item, self._gc_callback)

    def extend(self, items: Iterable[_Request]) -> None:
        self._refs.update((id(obj), ref(obj, self._gc_callback)) for obj in items)

    def remove(self, item: _Request) -> None:
        obj_id = id(item)
        ref = self._refs.get(obj_id)
        if ref is not None and ref() is item:
            del self._refs[obj_id]
        else:
            raise ValueError("list.remove(x): x not in list")

    def _gc_callback(self, item: _Request) -> None:
        # Callback when a weakly-referenced object is garbage collected
        self._refs.pop(id(item), None)  # Safely remove the item if it exists
