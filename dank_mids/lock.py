import threading
import time as _time
from _thread import LockType
from threading import _allocate_lock  # type: ignore [attr-defined]
from types import TracebackType
from typing import Final, TypeVar, final

from dank_mids._logging import getLogger


E = TypeVar("E", bound=Exception)

logger: Final = getLogger("dank_mids.AlertingRLock")

get_ident: Final = threading.get_ident
acquire_lock = threading._RLock.acquire

time: Final = _time.time


@final
class AlertingRLock:
    def __init__(self, name: str) -> None:
        """
        Initializes the reentrant lock with a given name.

        The name can be used for debugging and logging purposes to track lock usage.

        Examples:
            >>> lock = AlertingRLock(name="example")
            >>> lock._name
            'example'

        See Also:
            :class:`UIDGenerator`
        """
        self._block: Final[LockType] = _allocate_lock()
        self._owner: int | None = None
        self._count = 0
        self._name: Final = name

    def __enter__(self) -> bool:
        return self.acquire()

    def __exit__(self, t: type[E] | None, v: E | None, tb: TracebackType | None) -> None:
        self.release()

    def acquire(self, blocking: bool = True, timeout: float = -1.0) -> bool:
        """
        Acquire a lock, blocking or non-blocking, with alerting if not acquired within 5 seconds.

        When invoked, this method first attempts to acquire the lock with a 5-second timeout.
        If the lock is not acquired within 5 seconds, a warning is logged, and the method
        proceeds to acquire the lock using the provided `blocking` and `timeout` arguments,
        matching the semantics of the builtin RLock.

        Parameters:
            blocking: Whether to block during the acquisition attempt.
            timeout: The maximum time to wait during the acquisition attempt.

        Returns:
            bool: True if the lock is acquired, False otherwise.

        See Also:
            :meth:`_RLock.acquire`
        """
        me = get_ident()
        if self._owner == me:
            self._count += 1
            return True

        # Try to acquire with repeated 5-second timeouts, logging every 5 seconds if not acquired

        endtime: Final = None if timeout is None or timeout < 0 else (time() + timeout)

        while True:
            # Calculate the timeout for this attempt
            this_timeout = 5.0
            if endtime is not None:
                remaining = endtime - time()
                if remaining <= 0:
                    this_timeout = 0
                elif remaining < 5.0:
                    this_timeout = remaining

            if self._block.acquire(timeout=this_timeout):
                self._owner = me
                self._count = 1
                return True

            logger.warning("wtf?! %s with name %s is locked!", self, self._name)

            # If not blocking, or timeout expired, return False
            if not blocking:
                return False
            if endtime is None:
                continue
            if endtime - time() <= 0:
                return False

    def release(self) -> None:
        """Release a lock, decrementing the recursion level.

        If after the decrement it is zero, reset the lock to unlocked (not owned
        by any thread), and if any other threads are blocked waiting for the
        lock to become unlocked, allow exactly one of them to proceed. If after
        the decrement the recursion level is still nonzero, the lock remains
        locked and owned by the calling thread.

        Only call this method when the calling thread owns the lock. A
        RuntimeError is raised if this method is called when the lock is
        unlocked.

        There is no return value.

        """
        if self._owner != get_ident():
            raise RuntimeError("cannot release un-acquired lock")
        self._count = count = self._count - 1
        if not count:
            self._owner = None
            self._block.release()

    def locked(self) -> bool:
        """
        Return True if the lock is held by any thread, False otherwise.
        """
        return self._owner is not None

    # Internal methods used by condition variables

    def _acquire_restore(self, state: tuple[int, int | None]) -> None:
        self._block.acquire()
        self._count, self._owner = state

    def _release_save(self) -> tuple[int, int | None]:
        if self._count == 0:
            raise RuntimeError("cannot release un-acquired lock")
        count = self._count
        self._count = 0
        owner = self._owner
        self._owner = None
        self._block.release()
        return (count, owner)

    def _is_owned(self) -> bool:
        return self._owner == get_ident()


__all__ = ["AlertingRLock"]
