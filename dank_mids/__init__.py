from contextlib import suppress

from dank_mids.brownie_patch import DankContractCall, DankContractMethod, DankContractTx, DankOverloadedMethod
from dank_mids.controller import instances
from dank_mids.exceptions import BrownieNotConnectedError
from dank_mids.helpers import setup_dank_w3, setup_dank_w3_from_sync
from dank_mids.middleware import dank_middleware
from dank_mids.semaphores import BlockSemaphore

__all__ = ["dank_middleware", "BlockSemaphore", "setup_dank_w3", "setup_dank_w3_from_sync"]


# Configure concurrent.futures.process queue size
def _configure_concurrent_future_work_queue_size():
    """
    Configures the concurrent futures process pool to allow for a larger number of queued calls.
    
    This function increases the EXTRA_QUEUED_CALLS value to 50,000, which allows for more
    concurrent operations to be queued in the process pool. This can significantly improve
    performance for applications that make heavy use of brownie.
    """
    import concurrent.futures.process as _cfp
    _cfp.EXTRA_QUEUED_CALLS = 50_000

_configure_concurrent_future_work_queue_size()


# Import brownie objects
with suppress(ImportError):
    from dank_mids.brownie_patch import Contract, dank_eth, dank_web3, patch_contract
    # aliased for cleanliness and convenience
    web3 = dank_web3
    eth = dank_eth

    _brownie_objects = ["Contract", "dank_web3", "web3", "dank_eth", "eth", "patch_contract"]
    __all__ += _brownie_objects


# Define custom getattr
def __getattr__(name: str):
    """
    Custom attribute access handler for the 'dank_mids' module.

    This method is called when an attribute that is not found in the module's namespace
    is accessed. It allows for custom error handling for brownie-specific objects.
    """
    if name in _brownie_objects:
        raise BrownieNotConnectedError(f"dank_mids.{name}")
    raise AttributeError(f"module '{__name__}' has no attribute '{name}'")


