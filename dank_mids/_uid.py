import logging
import threading

logger = logging.getLogger(__name__)


class UIDGenerator:
    def __init__(self) -> None:
        """
        Initializes the UIDGenerator with the starting UID value set to -1 
        and a custom reentrant lock to ensure thread-safety.
        """
        self._value: int = -1
        self.lock = _AlertingRLock(name="uid")

    @property
    def latest(self) -> int:
        """Retrieves the most recent unique ID without incrementing."""
        return self._value

    @property
    def next(self) -> int:
        """Generates and retrieves the next unique ID in a thread-safe manner."""
        with self.lock:
            new: int = self._value + 1
            self._value = new
            return new


class _AlertingRLock(threading._RLock):  # type: ignore [misc]
    def __init__(self, name: str) -> None:
        """
        Initializes the reentrant lock with a given name, which can be used 
        for debugging and logging to track lock usage.
        """
        super().__init__()
        self.name = name

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
        acquired = super().acquire(blocking=False, timeout=5)
        if not acquired:
            logger.warning("wtf?! %s with name %s is locked!", self, self.name)
            super().acquire(blocking=blocking, timeout=timeout)