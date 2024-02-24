
from dank_mids.controller import instances
from dank_mids.helpers import setup_dank_w3, setup_dank_w3_from_sync
from dank_mids.middleware import dank_middleware

try:
    from dank_mids.brownie_patch import Contract, dank_web3, patch_contract
except ImportError:
    pass

def _configure_concurrent_future_work_queue_size():
    import concurrent.futures.process as _cfp
    _cfp.EXTRA_QUEUED_CALLS = 50_000

_configure_concurrent_future_work_queue_size()
