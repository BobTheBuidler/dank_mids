Retry Observer
==============

Overview
--------
Dank Mids exposes a retry observer API so applications can record retry decisions
into logs or metrics backends. Observers are callables that accept a
:class:`dank_mids.retry_observer.RetryEvent`.

.. note::
   Internal retry logic does not emit events yet. Emit points are planned for a
   follow-up PR. For now, emit from your own wrappers using
   :func:`dank_mids.retry_observer.emit_retry_event`.

RetryEvent
----------

Fields:

- ``operation`` (str): Human-readable identifier for the retried operation.
- ``attempt`` (int): 1-based retry attempt number.
- ``error`` (BaseException): Exception that triggered the retry.
- ``max_attempts`` (int | None): Optional configured limit.
- ``delay`` (float | None): Optional delay before next attempt.
- ``component`` (str | None): Optional subsystem name.
- ``will_retry`` (bool): Whether the caller intends to retry.
- ``metadata`` (dict[str, str] | None): Optional key/value tags.
- ``timestamp`` (float): Unix timestamp when the event was created.

Registration
------------
Register observers with :func:`dank_mids.retry_observer.register_retry_observer` and
remove them with :func:`dank_mids.retry_observer.unregister_retry_observer`.

.. code-block:: python

   from dank_mids import RetryEvent, emit_retry_event, register_retry_observer

   def log_retry(event: RetryEvent) -> None:
       print(
           f"retrying {event.operation} attempt={event.attempt} "
           f"delay={event.delay} error={event.error}"
       )

   register_retry_observer(log_retry)

   emit_retry_event(
       RetryEvent(
           operation="eth_call",
           attempt=1,
           delay=0.5,
           error=RuntimeError("rate limited"),
           component="jsonrpc",
       )
   )

Usage Examples
--------------
Structured logging
~~~~~~~~~~~~~~~~~~
.. code-block:: python

   import logging

   from dank_mids import RetryEvent, register_retry_observer

   logger = logging.getLogger("dank_mids.retry")

   def log_retry(event: RetryEvent) -> None:
       logger.warning(
           "retrying %s attempt=%s delay=%s error=%s",
           event.operation,
           event.attempt,
           event.delay,
           event.error,
       )

   register_retry_observer(log_retry)

Prometheus counters
~~~~~~~~~~~~~~~~~~~
.. code-block:: python

   from prometheus_client import Counter

   from dank_mids import RetryEvent, register_retry_observer

   retry_total = Counter(
       "dank_mids_retry_total",
       "Retry events emitted by Dank Mids",
       ["operation", "error_type"],
   )

   def record_retry(event: RetryEvent) -> None:
       retry_total.labels(event.operation, type(event.error).__name__).inc()

   register_retry_observer(record_retry)

Sentry + stats collector
~~~~~~~~~~~~~~~~~~~~~~~~
.. code-block:: python

   from dank_mids import StatsRetryObserver, register_retry_observer
   from dank_mids import stats

   register_retry_observer(StatsRetryObserver())

   # When you want to push metrics to Sentry.
   stats.sentry.push_measurements()

   # New metrics include: retry_total, retry_error_types
