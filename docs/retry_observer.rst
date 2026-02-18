Retry Observer
==============

Overview
--------
Dank Mids exposes a retry observer API so applications can record retry decisions
into logs or metrics backends. Observers are callables that accept a
:class:`dank_mids.retry_observer.RetryEvent`.

.. note::
   Internal retry logic emits events for built-in retry paths. You can still
   emit from your own wrappers using :func:`dank_mids.retry_observer.emit_retry_event`.

Internal emit points
--------------------
Retry events are emitted in the following internal locations:

- RPC request timeouts and 408 responses (``RPCRequest.make_request``)
- Multicall bisect retries (``Multicall.bisect_and_retry``)
- JSON-RPC batch bisect retries (``JSONRPCBatch.bisect_and_retry``)
- HTTP 429 and retryable status codes (``DankClientSession.post``)

Attempt semantics
-----------------
``attempt`` is 1-based. For batch retries, the attempt number increments each
time a batch is bisected and retried. For ``will_retry=False`` events, the
attempt number reflects the retry decision that would have occurred next.

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

   observer = StatsRetryObserver()
   register_retry_observer(observer)

   # When you want to push metrics to Sentry.
   stats.sentry.push_measurements()

   # New metrics include: retry_total, retry_error_types
