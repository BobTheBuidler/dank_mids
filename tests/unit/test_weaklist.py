import gc
import weakref

from dank_mids.helpers._weaklist import WeakList


class _Thing:
    pass


def test_append_iter_contains_and_len() -> None:
    items = [_Thing(), _Thing()]
    wl = WeakList()
    wl.append(items[0])
    wl.append(items[1])

    assert len(wl) == 2
    assert items[0] in wl
    assert items[1] in wl
    assert list(wl) == items


def test_extend_and_remove() -> None:
    items = [_Thing(), _Thing(), _Thing()]
    wl = WeakList(items)

    wl.remove(items[1])

    assert len(wl) == 2
    assert items[1] not in wl
    assert list(wl) == [items[0], items[2]]


def test_gc_cleans_refs() -> None:
    wl = WeakList()
    thing = _Thing()
    ref = weakref.ref(thing)

    wl.append(thing)
    assert len(wl) == 1

    del thing
    gc.collect()

    assert ref() is None
    assert len(wl) == 0
    assert list(wl) == []
