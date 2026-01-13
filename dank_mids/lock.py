import asyncio
import collections
import threading
import time as _time
from asyncio import AbstractEventLoop, Future, events, mixins
from types import TracebackType
from typing import Deque, Final, Literal, TypeVar, final

from dank_mids.logging import get_c_logger


E = TypeVar("E", bound=Exception)

logger: Final = get_c_logger("dank_mids.AlertingRLock")


CancelledError: Final = asyncio.CancelledError

deque: Final = collections.deque

get_ident: Final = threading.get_ident

time: Final = _time.time


__all__ = ["AlertingRLock", "Lock"]


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
        self._lock: Final = threading.Lock()
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

        if endtime is None:
            while True:
                if self._lock.acquire(timeout=5.0):
                    self._owner = me
                    self._count = 1
                    return True

                logger.warning("wtf?! %s with name %s is locked!", self, self._name)

                # If not blocking, or timeout expired, return False
                if not blocking:
                    return False

        else:
            while True:
                # Calculate the timeout for this attempt
                remaining = endtime - time()
                if remaining <= 0:
                    this_timeout = 0.0
                elif remaining < 5.0:
                    this_timeout = remaining
                else:
                    this_timeout = 5.0

                if self._lock.acquire(timeout=this_timeout):
                    self._owner = me
                    self._count = 1
                    return True

                logger.warning("wtf?! %s with name %s is locked!", self, self._name)

                # If not blocking, or timeout expired, return False
                if not blocking:
                    return False
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
            self._lock.release()

    def locked(self) -> bool:
        """
        Return True if the lock is held by any thread, False otherwise.
        """
        return self._owner is not None

    # Internal methods used by condition variables

    def _acquire_restore(self, state: tuple[int, int | None]) -> None:
        self._lock.acquire()
        self._count, self._owner = state

    def _release_save(self) -> tuple[int, int | None]:
        if self._count == 0:
            raise RuntimeError("cannot release un-acquired lock")
        count = self._count
        self._count = 0
        owner = self._owner
        self._owner = None
        self._lock.release()
        return (count, owner)

    def _is_owned(self) -> bool:
        return self._owner == get_ident()


_get_running_loop: Final = events._get_running_loop
_global_lock: Final = mixins._global_lock


@final
class Lock:
    """Primitive lock objects.

    A primitive lock is a synchronization primitive that is not owned
    by a particular coroutine when locked.  A primitive lock is in one
    of two states, 'locked' or 'unlocked'.

    It is created in the unlocked state.  It has two basic methods,
    acquire() and release().  When the state is unlocked, acquire()
    changes the state to locked and returns immediately.  When the
    state is locked, acquire() blocks until a call to release() in
    another coroutine changes it to unlocked, then the acquire() call
    resets it to locked and returns.  The release() method should only
    be called in the locked state; it changes the state to unlocked
    and returns immediately.  If an attempt is made to release an
    unlocked lock, a RuntimeError will be raised.

    When more than one coroutine is blocked in acquire() waiting for
    the state to turn to unlocked, only one coroutine proceeds when a
    release() call resets the state to unlocked; first coroutine which
    is blocked in acquire() is being processed.

    acquire() is a coroutine and should be called with 'await'.

    Locks also support the asynchronous context management protocol.
    'async with lock' statement should be used.

    Usage:

        lock = Lock()
        ...
        await lock.acquire()
        try:
            ...
        finally:
            lock.release()

    Context manager usage:

        lock = Lock()
        ...
        async with lock:
             ...

    Lock objects can be tested for locking state:

        if not lock.locked():
           await lock.acquire()
        else:
           # lock is acquired
           ...

    """

    def __init__(self) -> None:
        self._loop: AbstractEventLoop | None = None
        self._waiters: Deque[Future[Literal[True]]] | None = None
        self._locked: bool = False

    def __repr__(self) -> str:
        res = super().__repr__()
        extra = "locked" if self._locked else "unlocked"
        if self._waiters:
            extra = f"{extra}, waiters:{len(self._waiters)}"
        return f"<{res[1:-1]} [{extra}]>"

    async def __aenter__(self) -> None:
        await self.acquire()
        # We have no use for the "as ..."  clause in the with
        # statement for locks.
        return None

    async def __aexit__(self, t: type[E] | None, v: E | None, tb: TracebackType | None) -> None:
        self.release()

    def locked(self) -> bool:
        """Return True if lock is acquired."""
        return self._locked

    async def acquire(self) -> Literal[True]:
        """Acquire a lock.

        This method blocks until the lock is unlocked, then sets it to
        locked and returns True.
        """
        if not self._locked and (
            self._waiters is None or all(w.cancelled() for w in self._waiters)
        ):
            self._locked = True
            return True

        if self._waiters is None:
            self._waiters = collections.deque()
        fut: Future[Literal[True]] = self._get_loop().create_future()
        self._waiters.append(fut)

        # Finally block should be called before the CancelledError
        # handling as we don't want CancelledError to call
        # _wake_up_first() and attempt to wake up itself.
        try:
            try:
                await fut
            finally:
                self._waiters.remove(fut)
        except CancelledError:
            if not self._locked:
                self._wake_up_first()
            raise

        self._locked = True
        return True

    def release(self) -> None:
        """Release a lock.

        When the lock is locked, reset it to unlocked, and return.
        If any other coroutines are blocked waiting for the lock to become
        unlocked, allow exactly one of them to proceed.

        When invoked on an unlocked lock, a RuntimeError is raised.

        There is no return value.
        """
        if self._locked:
            self._locked = False
            self._wake_up_first()
        else:
            raise RuntimeError("Lock is not acquired.")

    def _wake_up_first(self) -> None:
        """Wake up the first waiter if it isn't done."""
        if not self._waiters:
            return
        try:
            fut = next(iter(self._waiters))
        except StopIteration:
            return

        # .done() necessarily means that a waiter will wake up later on and
        # either take the lock, or, if it was cancelled and lock wasn't
        # taken already, will hit this again and wake up a new waiter.
        if not fut.done():
            fut.set_result(True)

    def _get_loop(self) -> AbstractEventLoop:
        loop = _get_running_loop()

        if self._loop is None:
            with _global_lock:
                if self._loop is None:
                    self._loop = loop
        if loop is not self._loop:
            raise RuntimeError(f"{self!r} is bound to a different event loop")
        return loop
