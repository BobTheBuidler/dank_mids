from collections import deque

import pytest

from dank_mids import stats
from dank_mids.stats._float_moving_average import FloatMovingAverage


def test_float_moving_average_append_before_capacity() -> None:
    average = FloatMovingAverage(3)

    average.append(1.0)
    average.append(2.0)

    assert len(average) == 2
    assert list(average) == [1.0, 2.0]
    assert average[0] == 1.0
    assert average[-1] == 2.0
    assert average.average == 1.5


@pytest.mark.parametrize("capacity", [0, -1])
def test_float_moving_average_rejects_non_positive_capacity(capacity: int) -> None:
    with pytest.raises(ValueError, match="capacity must be positive"):
        FloatMovingAverage(capacity)


def test_float_moving_average_overwrites_oldest_value() -> None:
    average = FloatMovingAverage(3)

    average.append(1.0)
    average.append(2.0)
    average.append(3.0)
    average.append(4.0)

    assert len(average) == 3
    assert list(average) == [2.0, 3.0, 4.0]
    assert average[0] == 2.0
    assert average[-1] == 4.0
    assert average.average == 3.0


def test_float_moving_average_indexes_in_iteration_order_after_multiple_wraps() -> None:
    average = FloatMovingAverage(3)

    for value in (10.0, 20.0, 30.0, 40.0, 50.0):
        average.append(value)

    assert list(average) == [30.0, 40.0, 50.0]
    assert average[0] == 30.0
    assert average[1] == 40.0
    assert average[2] == 50.0
    assert average[-1] == 50.0
    assert average[-2] == 40.0
    assert average[-3] == 30.0


def test_float_moving_average_empty_average_matches_old_zero_division_behavior() -> None:
    average = FloatMovingAverage(3)

    with pytest.raises(ZeroDivisionError):
        _ = average.average


def test_float_moving_average_matches_deque_after_wraparound() -> None:
    average = FloatMovingAverage(4)
    expected: deque[float] = deque(maxlen=4)

    for value in (1.0, -2.0, 3.5, 4.25, 5.0, -6.0, 7.75):
        average.append(value)
        expected.append(value)

        assert list(average) == list(expected)
        assert average.average == pytest.approx(sum(expected) / len(expected))


def test_float_moving_average_rejects_out_of_range_indexes() -> None:
    average = FloatMovingAverage(2)
    average.append(1.0)

    with pytest.raises(IndexError):
        _ = average[1]
    with pytest.raises(IndexError):
        _ = average[-2]


def test_collector_uses_float_moving_average_only_for_loop_average() -> None:
    collector = stats._Collector()

    collector.event_loop_times.append(0.2)
    collector.event_loop_times.append(0.4)
    collector.durations["eth_call"].append(0.1)
    collector.retry_delays.append(0.3)

    assert isinstance(collector.event_loop_times, FloatMovingAverage)
    assert collector.avg_loop_time == pytest.approx(0.3)
    assert isinstance(collector.durations["eth_call"], deque)
    assert list(collector.durations["eth_call"]) == [0.1]
    assert isinstance(collector.retry_delays, deque)
    assert list(collector.retry_delays) == [0.3]
