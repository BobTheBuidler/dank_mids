from logging import getLogger
from threading import _RLock, _allocate_lock


class UIDGenerator:
    __slots__ = "_value", "_lock"

    def __init__(self) -> None:
        """
        Initializes the UIDGenerator with the starting UID value set to -1
        and a custom reentrant lock to ensure thread-safety.
        """
        self._value: int = -1
        self._lock = _AlertingRLock(name="uid")

    @property
    def latest(self) -> int:
        """Retrieves the most recent unique ID without incrementing."""
        return self._value

    @property
    def next(self) -> int:
        """Generates and retrieves the next unique ID in a thread-safe manner."""
        with self._lock:
            new = self._value = self._value + 1
            return new


logger = getLogger("dank_mids._AlertingRLock")
acquire_lock = _RLock.acquire


class _AlertingRLock(_RLock):  # type: ignore [misc]
    __slots__ = "_block", "_owner", "_count", "_name"

    def __init__(self, name: str) -> None:
        """
        Initializes the reentrant lock with a given name, which can be used
        for debugging and logging to track lock usage.
        """
        self._block = _allocate_lock()
        self._owner = None
        self._count = 0
        self._name = name

    def acquire(self, blocking: bool = True, timeout: int = -1) -> bool:  # type: ignore [override]
        """
        Attempts to acquire the lock. The initial attempt will block for
        up to 5 seconds. If the lock cannot be acquired immediately within
        that timeframe, logs a warning message and retries the acquisition
        with the specified blocking and timeout parameters.

        Args:
            blocking: Whether this method should block until the lock is acquired.
            timeout: The maximum time to wait for acquiring the lock.
        """
        acquired = acquire_lock(self, blocking=False, timeout=5)
        if not acquired:
            # NOTE: I havent seen this log in a very long time, maybe we should remove the lock soon
            logger.warning("wtf?! %s with name %s is locked!", self, self._name)
            acquire_lock(self, blocking=blocking, timeout=timeout)
