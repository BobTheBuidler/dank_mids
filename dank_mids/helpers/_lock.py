from logging import getLogger
from threading import _RLock, _allocate_lock


logger = getLogger("dank_mids.AlertingRLock")
acquire_lock = _RLock.acquire


class AlertingRLock(_RLock):  # type: ignore [misc]
    __slots__ = "_block", "_owner", "_count", "_name"

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
        self._block = _allocate_lock()
        self._owner = None
        self._count = 0
        self._name = name

    def acquire(self, blocking: bool = True, timeout: float = -1.0) -> bool:  # type: ignore [override]
        """
        Attempts to acquire the lock with an initial fixed timeout.

        This method first attempts to acquire the lock in a non-blocking manner with a timeout
        of 5 seconds. If this initial attempt is unsuccessful, a warning message is logged and
        a secondary acquisition attempt is made using the provided `blocking` and `timeout`
        parameters. Note that the return value of the secondary attempt is not captured or returned;
        this method always returns the result of the initial lock acquisition attempt.

        Parameters:
            blocking: Whether to block during the secondary acquisition attempt.
            timeout: The maximum time to wait during the secondary acquisition attempt.

        Returns:
            bool: The result from the initial lock acquisition attempt.

        Examples:
            >>> lock = AlertingRLock("example")
            >>> # Attempt to acquire the lock. If the initial 5-second attempt fails,
            >>> # a warning is logged and a secondary attempt is made.
            >>> result = lock.acquire(blocking=True, timeout=10)
            >>> isinstance(result, bool)
            True

        See Also:
            :meth:`_RLock.acquire`
        """
        acquired = acquire_lock(self, blocking=False, timeout=5)
        if not acquired:
            # NOTE: I havent seen this log in a very long time, maybe we should remove the lock soon
            logger.warning("wtf?! %s with name %s is locked!", self, self._name)
            acquire_lock(self, blocking=blocking, timeout=timeout)
        return acquired
