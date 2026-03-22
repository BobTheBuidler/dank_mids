from __future__ import annotations

import importlib.util
from pathlib import Path
import sys

MODULE_PATH = Path(__file__).resolve().parents[2] / "dank_mids" / "helpers" / "_retry_mechanics.py"
SPEC = importlib.util.spec_from_file_location("retry_mechanics", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
retry_mechanics = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = retry_mechanics
SPEC.loader.exec_module(retry_mechanics)


def test_consume_retry_advances_attempt_until_budget_exhausted() -> None:
    budget = retry_mechanics.RetryBudget(max_attempts=2)

    first = retry_mechanics.consume_retry(budget, retry_mechanics.RetryAction.RETRY_NOW)
    second = retry_mechanics.consume_retry(budget, retry_mechanics.RetryAction.RETRY_NOW)
    exhausted = retry_mechanics.consume_retry(budget, retry_mechanics.RetryAction.RETRY_NOW)

    assert first.action is retry_mechanics.RetryAction.RETRY_NOW
    assert first.attempt == 1
    assert second.attempt == 2
    assert exhausted.action is retry_mechanics.RetryAction.RAISE
    assert exhausted.attempt == 0


def test_consume_retry_with_jitter_uses_random_delay(monkeypatch) -> None:
    monkeypatch.setattr(retry_mechanics, "random", lambda: 0.375)
    budget = retry_mechanics.RetryBudget(max_attempts=1)

    decision = retry_mechanics.consume_retry_with_jitter(budget)

    assert decision.action is retry_mechanics.RetryAction.RETRY_AFTER_DELAY
    assert decision.attempt == 1
    assert decision.delay == 0.375


def test_choose_http_status_retry_uses_rate_limit_budget_for_429() -> None:
    rate_limit_budget = retry_mechanics.RetryBudget()
    status_retry_budget = retry_mechanics.RetryBudget(max_attempts=5)

    decision = retry_mechanics.choose_http_status_retry(
        429,
        too_many_requests_status=429,
        retry_for_codes={502, 520},
        rate_limit_budget=rate_limit_budget,
        status_retry_budget=status_retry_budget,
    )

    assert decision.action is retry_mechanics.RetryAction.HANDLE_RATE_LIMIT
    assert decision.attempt == 1
    assert status_retry_budget.attempts == 0


def test_choose_http_status_retry_retries_transient_status_with_delay(monkeypatch) -> None:
    monkeypatch.setattr(retry_mechanics, "random", lambda: 0.125)
    rate_limit_budget = retry_mechanics.RetryBudget()
    status_retry_budget = retry_mechanics.RetryBudget(max_attempts=1)

    decision = retry_mechanics.choose_http_status_retry(
        520,
        too_many_requests_status=429,
        retry_for_codes={502, 520},
        rate_limit_budget=rate_limit_budget,
        status_retry_budget=status_retry_budget,
    )
    exhausted = retry_mechanics.choose_http_status_retry(
        520,
        too_many_requests_status=429,
        retry_for_codes={502, 520},
        rate_limit_budget=rate_limit_budget,
        status_retry_budget=status_retry_budget,
    )

    assert decision.action is retry_mechanics.RetryAction.RETRY_AFTER_DELAY
    assert decision.attempt == 1
    assert decision.delay == 0.125
    assert exhausted.action is retry_mechanics.RetryAction.RAISE


def test_choose_http_status_retry_raises_for_non_retry_codes() -> None:
    decision = retry_mechanics.choose_http_status_retry(
        404,
        too_many_requests_status=429,
        retry_for_codes={502, 520},
        rate_limit_budget=retry_mechanics.RetryBudget(),
        status_retry_budget=retry_mechanics.RetryBudget(max_attempts=1),
    )

    assert decision.action is retry_mechanics.RetryAction.RAISE


def test_use_warning_logger_defaults_to_attempt_three() -> None:
    assert retry_mechanics.use_warning_logger(2) is False
    assert retry_mechanics.use_warning_logger(3) is True
