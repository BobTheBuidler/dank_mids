from __future__ import annotations

from collections.abc import Iterator
from typing import final

from librt.vecs import vec
from mypy_extensions import mypyc_attr


@final
@mypyc_attr(acyclic=True)
class FloatMovingAverage:
    __slots__ = ("_capacity", "_count", "_index", "_total", "_values")

    _capacity: int
    _count: int
    _index: int
    _total: float
    _values: vec[float]

    def __init__(self, capacity: int) -> None:
        if capacity <= 0:
            raise ValueError("capacity must be positive")
        self._capacity = capacity
        self._values = vec[float]([0.0] * capacity)
        self._index = 0
        self._count = 0
        self._total = 0.0

    def append(self, value: float) -> None:
        index = self._index
        values = self._values
        capacity = self._capacity
        count = self._count
        if count < capacity:
            self._count = count + 1
            self._total += value
        else:
            self._total += value - values[index]

        values[index] = value
        index += 1
        if index == capacity:
            index = 0
        self._index = index

    def __len__(self) -> int:
        return self._count

    def __iter__(self) -> Iterator[float]:
        values = self._values
        count = self._count
        capacity = self._capacity
        if count < capacity:
            for index in range(count):
                yield values[index]
            return

        start = self._index
        for index in range(start, capacity):
            yield values[index]
        for index in range(start):
            yield values[index]

    def __getitem__(self, index: int) -> float:
        count = self._count
        if index < 0:
            index += count
        if index < 0 or index >= count:
            raise IndexError("float moving average index out of range")

        values = self._values
        capacity = self._capacity
        if count < capacity:
            return values[index]

        slot = self._index + index
        if slot >= capacity:
            slot -= capacity
        return values[slot]

    @property
    def average(self) -> float:
        return self._total / self._count
