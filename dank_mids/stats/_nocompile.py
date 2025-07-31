"""
This helper file lets us conditionally define some imports,
based on whether or not the user has `sentry_sdk` installed.

Mypyc does not currently handle conditional imports like this well.
"""

from typing import Any, Callable, Optional


set_tag: Optional[Callable[[str, Any], None]]
"""
Set a tag for the current scope in Sentry.

This is a reference to :func:`sentry_sdk.set_tag`.

See Also:
    Sentry documentation on using tags:
    https://docs.sentry.io/platforms/python/enriching-events/tags/
"""


set_measurement: Optional[Callable]
"""
Set a measurement for the current scope in Sentry.

This is a reference to :func:`sentry_sdk.set_measurement`.

See Also:
    Sentry documentation on using measurements:
    https://docs.sentry.io/platforms/python/enriching-events/measurements/
"""


exc: Optional[ImportError]
"""
Stores any ImportError that occurred when trying to import sentry_sdk.
If this is not None, it indicates that Sentry integration is not available.
"""


try:
    import sentry_sdk

    set_tag = sentry_sdk.set_tag
    set_measurement = sentry_sdk.set_measurement
    exc = None
except ImportError as e:
    exc = e
    set_tag = None
    set_measurement = None
