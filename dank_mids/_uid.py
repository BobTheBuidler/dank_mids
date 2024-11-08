import logging
import threading

logger = logging.getLogger(__name__)


class UIDGenerator:
    def __init__(self) -> None:
        self._value: int = -1
        self.lock = _AlertingRLock(name="uid")
        """
        A custom reentrant lock used to ensure thread-safe access to the UID generator.
        """

    @property
    def latest(self) -> int:
        """Returns the latest unique id."""
        return self._value

    @property
    def next(self) -> int:
        """Returns the next unique id."""
        with self.lock:
            new: int = self._value + 1
            self._value = new
            return new


class _AlertingRLock(threading._RLock):  # type: ignore [misc]
    def __init__(self, name: str) -> None:
        super().__init__()
        self.name = name
        """
        A string identifier for the lock, used for debugging and logging purposes.
        """

    def acquire(self, blocking: bool = True, timeout: int = -1) -> bool:  # type: ignore [override]
        acquired = super().acquire(blocking=False, timeout=5)
        if not acquired:
            logger.warning("wtf?! %s with name %s is locked!", self, self.name)
            super().acquire(blocking=blocking, timeout=timeout)
