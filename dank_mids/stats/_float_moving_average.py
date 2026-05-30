from __future__ import annotations

from collections.abc import Iterator
from typing import final

from librt.vecs import vec


@final
class FloatMovingAverage:
    __slots__ = ("_count", "_index", "_maxlen", "_total", "_values")

    _count: int
    _index: int
    _maxlen: int
    _total: float
    _values: vec[float]

    def __init__(self, maxlen: int) -> None:
        self._maxlen = maxlen
        self._values = vec[float]([0.0] * maxlen)
        self._index = 0
        self._count = 0
        self._total = 0.0

    def append(self, value: float) -> None:
        old = 0.0
        if self._count == self._maxlen:
            old = self._values[self._index]
        else:
            self._count += 1

        self._values[self._index] = value
        self._total += value - old
        self._index += 1
        if self._index == self._maxlen:
            self._index = 0

    def __len__(self) -> int:
        return self._count

    def __iter__(self) -> Iterator[float]:
        start = self._index if self._count == self._maxlen else 0
        for offset in range(self._count):
            yield self._values[(start + offset) % self._maxlen]

    def __getitem__(self, index: int) -> float:
        if index < 0:
            index += self._count
        if index < 0 or index >= self._count:
            raise IndexError("float moving average index out of range")
        start = self._index if self._count == self._maxlen else 0
        return self._values[(start + index) % self._maxlen]

    @property
    def average(self) -> float:
        return self._total / self._count
