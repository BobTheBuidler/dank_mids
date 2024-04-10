
from dank_mids.brownie_patch import DankContractCall, DankContractMethod, DankContractTx, DankOverloadedMethod
from dank_mids.controller import instances
from dank_mids.helpers import setup_dank_w3, setup_dank_w3_from_sync
from dank_mids.middleware import dank_middleware
from dank_mids.semaphores import BlockSemaphore

__all__ = ["dank_middleware", "BlockSemaphore", "setup_dank_w3", "setup_dank_w3_from_sync"]

try:
    from dank_mids.brownie_patch import Contract, dank_eth, dank_web3, patch_contract
    from web3.eth import AsyncEth as _AsyncEth
    # aliased for cleanliness and convenience
    web3 = dank_web3
    eth = dank_eth

    __all__ += ["Contract", "dank_web3", "web3", "dank_eth", "eth", "patch_contract"]

except ImportError:
    pass

def _configure_concurrent_future_work_queue_size():
    import concurrent.futures.process as _cfp
    _cfp.EXTRA_QUEUED_CALLS = 50_000

_configure_concurrent_future_work_queue_size()
