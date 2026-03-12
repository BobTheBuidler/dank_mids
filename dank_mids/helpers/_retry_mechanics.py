from __future__ import annotations

from dataclasses import dataclass
from enum import IntEnum
from random import random
from typing import Final, final


@final
class RetryAction(IntEnum):
    """Execution choices for the next retry step."""

    RAISE = 0
    RETRY_NOW = 1
    RETRY_AFTER_DELAY = 2
    RETRY_WITH_RACE = 3
    HANDLE_RATE_LIMIT = 4


@dataclass(slots=True)
class RetryBudget:
    """
    Mutable retry budget that tracks consumed attempts.

    If ``max_attempts`` is ``None``, retries are unbounded.
    """

    attempts: int = 0
    max_attempts: int | None = None

    def can_retry(self) -> bool:
        return self.max_attempts is None or self.attempts < self.max_attempts

    def consume(self) -> int:
        self.attempts += 1
        return self.attempts


@dataclass(frozen=True, slots=True)
class RetryDecision:
    """Single retry decision outcome."""

    action: RetryAction
    attempt: int = 0
    delay: float = 0.0


NO_RETRY: Final = RetryDecision(RetryAction.RAISE)


def consume_retry(
    budget: RetryBudget,
    action: RetryAction,
    *,
    delay: float = 0.0,
) -> RetryDecision:
    """
    Consume one retry from ``budget`` and return the next decision.

    Returns ``NO_RETRY`` when the budget is exhausted.
    """

    if not budget.can_retry():
        return NO_RETRY
    return RetryDecision(action=action, attempt=budget.consume(), delay=delay)


def consume_retry_with_jitter(
    budget: RetryBudget,
    *,
    action: RetryAction = RetryAction.RETRY_AFTER_DELAY,
) -> RetryDecision:
    """Consume one retry and apply a random delay in [0.0, 1.0)."""

    return consume_retry(budget, action, delay=random())


def choose_http_status_retry(
    status: int,
    *,
    too_many_requests_status: int,
    retry_for_codes: set[int],
    rate_limit_budget: RetryBudget,
    status_retry_budget: RetryBudget,
) -> RetryDecision:
    """
    Select retry handling for an HTTP status code.

    ``429``-style handling is unlimited and tracked by ``rate_limit_budget``.
    Transient status retries are bounded by ``status_retry_budget``.
    """

    if status == too_many_requests_status:
        return consume_retry(rate_limit_budget, RetryAction.HANDLE_RATE_LIMIT)
    if status in retry_for_codes:
        return consume_retry_with_jitter(status_retry_budget)
    return NO_RETRY


def use_warning_logger(attempt: int, *, warning_after_attempt: int = 3) -> bool:
    """Return ``True`` once retry attempts should promote to warning-level logs."""

    return attempt >= warning_after_attempt
