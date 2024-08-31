
from contextlib import suppress

from dank_mids.brownie_patch import DankContractCall, DankContractMethod, DankContractTx, DankOverloadedMethod
from dank_mids.controller import instances
from dank_mids.helpers import setup_dank_w3, setup_dank_w3_from_sync
from dank_mids.middleware import dank_middleware
from dank_mids.semaphores import BlockSemaphore

__all__ = ["dank_middleware", "BlockSemaphore", "setup_dank_w3", "setup_dank_w3_from_sync"]

with suppress(ImportError):
    from dank_mids.brownie_patch import Contract, dank_eth, dank_web3, patch_contract
    from web3.eth import AsyncEth as _AsyncEth
    # aliased for cleanliness and convenience
    web3: DankWeb3 = dank_web3
    eth: AsyncEth = dank_eth

    __all__ += ["Contract", "dank_web3", "web3", "dank_eth", "eth", "patch_contract"]


def _configure_concurrent_future_work_queue_size():
    """
    Configures the concurrent futures process pool to allow for a larger number of queued calls.
    
    This function increases the EXTRA_QUEUED_CALLS value to 50,000, which allows for more
    concurrent operations to be queued in the process pool.
    """
    import concurrent.futures.process as _cfp
    _cfp.EXTRA_QUEUED_CALLS = 50_000

_configure_concurrent_future_work_queue_size()
