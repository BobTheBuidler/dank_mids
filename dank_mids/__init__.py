


from dank_mids._how_is_this_real import _the_most_absurd_fix_youve_ever_seen
from dank_mids.controller import instances
from dank_mids.helpers import setup_dank_w3, setup_dank_w3_from_sync
from dank_mids.middleware import dank_middleware


def _configure_concurrent_future_work_queue_size():
    import concurrent.futures.process as _cfp
    _cfp.EXTRA_QUEUED_CALLS = 50_000

_configure_concurrent_future_work_queue_size()
_the_most_absurd_fix_youve_ever_seen()
