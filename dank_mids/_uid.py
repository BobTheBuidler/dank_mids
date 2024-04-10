
import logging
import threading

logger = logging.getLogger(__name__)

class UIDGenerator:
    def __init__(self) -> None:
        self._value: int = -1
        self.lock = _AlertingRLock(name='uid')
    
    @property
    def latest(self) -> int:
        """ Returns the latest unique id. """
        return self._value
    
    @property
    def next(self) -> int:
        """ Returns the next unique id. """
        with self.lock:
            new: int = self._value + 1
            self._value = new
            return new

class _AlertingRLock(threading._RLock):
    def __init__(self, name: str) -> None:
        super().__init__()
        self.name = name
    def acquire(self, blocking: bool = True, timeout: int = -1) -> bool:
        acquired = super().acquire(blocking=False, timeout=5)
        if not acquired:
            logger.warning("wtf?! %s with name %s is locked!", self, self.name)
            super().acquire(blocking=blocking, timeout=timeout)
