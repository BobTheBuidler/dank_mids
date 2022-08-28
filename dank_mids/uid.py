
import threading

class UIDGenerator:
    def __init__(self) -> None:
        self._value: int = -1
        self.lock = threading.Lock()
    
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
