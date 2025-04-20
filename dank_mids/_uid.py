from dank_mids.helpers._lock import AlertingRLock


class UIDGenerator:
    __slots__ = "_value", "_lock"

    def __init__(self) -> None:
        """
        Initializes the UIDGenerator with the starting UID value set to -1 and a custom reentrant lock.

        This lock is used to ensure thread-safety during UID generation.

        Examples:
            >>> uid_gen = UIDGenerator()
            >>> uid_gen.latest
            -1
            >>> uid_gen.next
            0

        See Also:
            :class:`AlertingRLock`
        """
        self._value: int = -1
        self._lock = AlertingRLock(name="uid")

    @property
    def latest(self) -> int:
        """Retrieves the most recent unique ID without incrementing.

        Examples:
            >>> uid_gen = UIDGenerator()
            >>> uid_gen.latest
            -1
        """
        return self._value

    @property
    def next(self) -> int:
        """Generates and retrieves the next unique ID in a thread-safe manner.

        Examples:
            >>> uid_gen = UIDGenerator()
            >>> uid_gen.next
            0
            >>> uid_gen.latest
            0
        """
        with self._lock:
            new = self._value = self._value + 1
            return new
