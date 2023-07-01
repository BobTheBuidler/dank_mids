
from dank_mids.envs import create_env


# Max number of rpc calls to include in one batch call
MAX_JSONRPC_BATCH_SIZE = create_env("MAX_JSONRPC_BATCH_SIZE", int, default=500)

# Enable Demo Mode?
demo_mode_helper = create_env("DANK_MIDS_DEMO_MODE", bool, default=False)
DEMO_MODE = create_env("DANKMIDS_DEMO_MODE", bool, default=demo_mode_helper)

# Are you calling a ganache fork? Can't use state override code
ganache_helper = create_env("DANK_MIDS_DEMO_MODE", bool, default=False)
GANACHE_FORK = create_env("DANKMIDS_GANACHE_FORK", bool, default=ganache_helper)

# We set the default to 20 minutes to account for potentially long event loop times if you're doing serious work.
AIOHTTP_TIMEOUT = create_env("AIOHTTP_TIMEOUT", int, default=20*60)

# Brownie call Semaphore
#   Used because I experienced some OOM errs due to web3 formatters when I was batching an absurd number of brownie calls.
#   We need a separate semaphore here because the method-specific semaphores are too late in the code to prevent this OOM issue.
BROWNIE_CALL_SEMAPHORE_VAL = create_env("DANK_MIDS_BROWNIE_CALL_SEMAPHORE", int, default=100_000)

# Processes for decoding
NUM_PROCESSES = create_env("DANKMIDS_PROCESSES", int, default=1)

# NOTE: EXPORT_STATS is not implemented
# TODO: implement this
EXPORT_STATS = create_env("DANKMIDS_EXPORT_STATS", bool, default=False)
COLLECT_STATS = create_env("DANKMIDS_COLLECT_STATS", bool, default=EXPORT_STATS)

# Method-specific Semaphores
semaphore_envs = {
    "eth_getBlock": create_env("ETH_GETBLOCK_SEMAPHORE", int, default=50), # [eth_getBlockByNumber, eth_getBlockByHash]
    "eth_getLogs": create_env("ETH_GETLOGS_SEMAPHORE", int, default=64),
    "eth_getTransaction": create_env("ETH_GETTRANSACTION_SEMAPHORE", int, default=100),
}
