from __future__ import annotations

from importlib import import_module
from typing import TYPE_CHECKING, Any, Final

__all__ = [
    "setup_dank_w3",
    "setup_dank_w3_from_sync",
    "DebuggableFuture",
    "lru_cache_lite",
    "lru_cache_lite_nonull",
    "make_hashable",
    "gatherish",
]

_LAZY_IMPORTS: Final[dict[str, tuple[str, str]]] = {
    "setup_dank_w3": ("dank_mids.helpers._helpers", "setup_dank_w3"),
    "setup_dank_w3_from_sync": ("dank_mids.helpers._helpers", "setup_dank_w3_from_sync"),
    "gatherish": ("dank_mids.helpers._gather", "gatherish"),
    "DebuggableFuture": ("dank_mids.helpers.future", "DebuggableFuture"),
    "make_hashable": ("dank_mids.helpers.hashing", "make_hashable"),
    "lru_cache_lite": ("dank_mids.helpers.lru_cache", "lru_cache_lite"),
    "lru_cache_lite_nonull": ("dank_mids.helpers.lru_cache", "lru_cache_lite_nonull"),
}

_NEEDS_SIDE_EFFECTS: Final[set[str]] = {
    "setup_dank_w3",
    "setup_dank_w3_from_sync",
}

if TYPE_CHECKING:
    from dank_mids.helpers._gather import gatherish
    from dank_mids.helpers._helpers import setup_dank_w3, setup_dank_w3_from_sync
    from dank_mids.helpers.future import DebuggableFuture
    from dank_mids.helpers.hashing import make_hashable
    from dank_mids.helpers.lru_cache import lru_cache_lite, lru_cache_lite_nonull


def _load_attribute(name: str) -> Any:
    if name in _NEEDS_SIDE_EFFECTS:
        from dank_mids import _ensure_side_effects

        _ensure_side_effects()
    module_name, attr_name = _LAZY_IMPORTS[name]
    module = import_module(module_name)
    value = getattr(module, attr_name)
    globals()[name] = value
    return value


def __getattr__(name: str) -> Any:
    if name in _LAZY_IMPORTS:
        return _load_attribute(name)
    raise AttributeError(f"module '{__name__}' has no attribute '{name}'")


def __dir__() -> list[str]:
    return sorted(set(globals()) | set(_LAZY_IMPORTS))
