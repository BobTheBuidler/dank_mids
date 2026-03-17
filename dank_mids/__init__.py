from __future__ import annotations

from importlib import import_module
from typing import TYPE_CHECKING, Any, Final

__all__ = [
    "dank_middleware",
    "BlockSemaphore",
    "setup_dank_w3",
    "setup_dank_w3_from_sync",
    "RetryEvent",
    "RetryObserver",
    "emit_retry_event",
    "get_retry_observers",
    "register_retry_observer",
    "unregister_retry_observer",
    "StatsRetryObserver",
]

_BROWNIE_OBJECTS: Final[tuple[str, ...]] = (
    "Contract",
    "dank_web3",
    "web3",
    "dank_eth",
    "eth",
    "patch_contract",
)

_BROWNIE_TYPE_OBJECTS: Final[tuple[str, ...]] = (
    "DankContractCall",
    "DankContractMethod",
    "DankContractTx",
    "DankOverloadedMethod",
)

_ALIASES: Final[dict[str, str]] = {
    "web3": "dank_web3",
    "eth": "dank_eth",
}

_LAZY_IMPORTS: Final[dict[str, tuple[str, str]]] = {
    "patch_eth_utils": ("dank_mids._eth_utils", "patch_eth_utils"),
    "DankContractCall": ("dank_mids.brownie_patch.types", "DankContractCall"),
    "DankContractMethod": ("dank_mids.brownie_patch.types", "DankContractMethod"),
    "DankContractTx": ("dank_mids.brownie_patch.types", "DankContractTx"),
    "DankOverloadedMethod": ("dank_mids.brownie_patch.types", "DankOverloadedMethod"),
    "instances": ("dank_mids.controller", "instances"),
    "BrownieNotConnectedError": ("dank_mids.exceptions", "BrownieNotConnectedError"),
    "setup_dank_w3": ("dank_mids.helpers", "setup_dank_w3"),
    "setup_dank_w3_from_sync": ("dank_mids.helpers", "setup_dank_w3_from_sync"),
    "dank_middleware": ("dank_mids.middleware", "dank_middleware"),
    "BlockSemaphore": ("dank_mids.semaphores", "BlockSemaphore"),
    "RetryEvent": ("dank_mids.retry_observer", "RetryEvent"),
    "RetryObserver": ("dank_mids.retry_observer", "RetryObserver"),
    "emit_retry_event": ("dank_mids.retry_observer", "emit_retry_event"),
    "get_retry_observers": ("dank_mids.retry_observer", "get_retry_observers"),
    "register_retry_observer": ("dank_mids.retry_observer", "register_retry_observer"),
    "unregister_retry_observer": ("dank_mids.retry_observer", "unregister_retry_observer"),
    "StatsRetryObserver": ("dank_mids.stats.retry", "StatsRetryObserver"),
    "Contract": ("dank_mids.brownie_patch", "Contract"),
    "dank_web3": ("dank_mids.brownie_patch", "dank_web3"),
    "dank_eth": ("dank_mids.brownie_patch", "dank_eth"),
    "patch_contract": ("dank_mids.brownie_patch", "patch_contract"),
}

_NEEDS_SIDE_EFFECTS: Final[set[str]] = {
    "DankContractCall",
    "DankContractMethod",
    "DankContractTx",
    "DankOverloadedMethod",
    "instances",
    "setup_dank_w3",
    "setup_dank_w3_from_sync",
    "dank_middleware",
    "Contract",
    "dank_web3",
    "dank_eth",
    "patch_contract",
    "web3",
    "eth",
}

_lazy_initialized = False

if TYPE_CHECKING:
    from dank_mids._eth_utils import patch_eth_utils as patch_eth_utils
    from dank_mids.brownie_patch import Contract, dank_eth, dank_web3, patch_contract
    from dank_mids.brownie_patch.types import (
        DankContractCall,
        DankContractMethod,
        DankContractTx,
        DankOverloadedMethod,
    )
    from dank_mids.controller import instances
    from dank_mids.exceptions import (
        BrownieNotConnectedError,
        BrowniePatchImportError,
        BrowniePatchNotInitializedError,
    )
    from dank_mids.helpers import setup_dank_w3, setup_dank_w3_from_sync
    from dank_mids.middleware import dank_middleware
    from dank_mids.retry_observer import (
        RetryEvent,
        RetryObserver,
        emit_retry_event,
        get_retry_observers,
        register_retry_observer,
        unregister_retry_observer,
    )
    from dank_mids.semaphores import BlockSemaphore
    from dank_mids.stats.retry import StatsRetryObserver


def _configure_concurrent_future_work_queue_size() -> None:
    """
    Configures the concurrent futures process pool to allow for a larger number of queued calls.

    This function increases the EXTRA_QUEUED_CALLS value to 50,000, which allows for more
    concurrent operations to be queued in the process pool. This can significantly improve
    performance for applications that make heavy use of brownie.

    The value is capped so that ProcessPoolExecutor's internal queue
    (queue_size = max_workers + EXTRA_QUEUED_CALLS) does not create a
    BoundedSemaphore that exceeds the system's SEM_VALUE_MAX.  We reserve
    os.cpu_count() slots for max_workers since that is the default.
    """
    import concurrent.futures.process as _cfp
    import os

    from multiprocessing.synchronize import SEM_VALUE_MAX

    max_workers_headroom = os.cpu_count() or 1
    _cfp.EXTRA_QUEUED_CALLS = min(50_000, SEM_VALUE_MAX - max_workers_headroom)


def _ensure_side_effects() -> None:
    global _lazy_initialized
    if _lazy_initialized:
        return
    from dank_mids._eth_utils import patch_eth_utils

    patch_eth_utils()
    _configure_concurrent_future_work_queue_size()
    _lazy_initialized = True


def _raise_brownie_not_connected(name: str, exc: BaseException) -> None:
    from dank_mids.brownie_patch import get_brownie_patch_status
    from dank_mids.exceptions import (
        BrownieNotConnectedError,
        BrowniePatchImportError,
        BrowniePatchNotInitializedError,
    )

    try:
        status = get_brownie_patch_status(refresh_connection=True)
    except TypeError as state_error:
        raise BrowniePatchNotInitializedError(name) from state_error
    if status.import_error is not None:
        raise BrowniePatchImportError(name, status.import_error) from status.import_error
    if not status.connected:
        raise BrownieNotConnectedError(name) from exc
    if not status.initialized:
        raise BrowniePatchNotInitializedError(name) from exc
    # If brownie objects are still missing, state is stale or inconsistent.
    raise BrowniePatchNotInitializedError(name) from exc


def _expose_brownie_objects() -> None:
    for obj in _BROWNIE_OBJECTS:
        if obj not in __all__:
            __all__.append(obj)


def _load_attribute(name: str, *, alias: str | None = None) -> Any:
    if name in _NEEDS_SIDE_EFFECTS:
        _ensure_side_effects()
    module_name, attr_name = _LAZY_IMPORTS[name]
    try:
        module = import_module(module_name)
        value = getattr(module, attr_name)
    except (ImportError, AttributeError) as exc:
        if name in _BROWNIE_TYPE_OBJECTS and isinstance(exc, ImportError):
            from dank_mids.exceptions import BrowniePatchImportError

            raise BrowniePatchImportError(alias or name, exc) from exc
        if name in _BROWNIE_OBJECTS:
            _raise_brownie_not_connected(alias or name, exc)
        raise
    globals()[name] = value
    if alias:
        globals()[alias] = value
    if name in _BROWNIE_OBJECTS:
        _expose_brownie_objects()
    return value


_ensure_side_effects()


def __getattr__(name: str) -> Any:
    """
    Handles custom attribute access for the 'dank_mids' module.

    This function lazily imports attributes on first access to avoid importing heavy
    dependencies or triggering side effects during `import dank_mids`.

    Raises:
        BrowniePatchImportError: If brownie integration failed to import.
        BrownieNotConnectedError: If brownie is not connected.
        BrowniePatchNotInitializedError: If brownie is connected but patch is not initialized.
        AttributeError: If the attribute is not found.
    """
    if name in _ALIASES:
        return _load_attribute(_ALIASES[name], alias=name)
    if name in _LAZY_IMPORTS:
        return _load_attribute(name)
    if name in _BROWNIE_OBJECTS:
        _raise_brownie_not_connected(name, AttributeError(name))
    raise AttributeError(f"module '{__name__}' has no attribute '{name}'")


def __dir__() -> list[str]:
    return sorted(set(globals()) | set(_LAZY_IMPORTS) | set(_ALIASES))


def _install_alias_guard() -> None:
    import sys
    import types

    module = sys.modules.get(__name__)
    if module is None:
        return

    class _DankModule(types.ModuleType):
        def __getattribute__(self, name: str) -> Any:  # type: ignore[override]
            if name in _ALIASES:
                try:
                    value = types.ModuleType.__getattribute__(self, name)
                except AttributeError:
                    return types.ModuleType.__getattribute__(self, "__getattr__")(name)
                if getattr(value, "__name__", None) == f"{__name__}.{name}":
                    return types.ModuleType.__getattribute__(self, "__getattr__")(name)
                return value
            return types.ModuleType.__getattribute__(self, name)

    module.__class__ = _DankModule


_install_alias_guard()
