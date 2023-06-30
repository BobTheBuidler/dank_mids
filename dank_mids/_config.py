
import os


# Max number of rpc calls to include in one batch call
MAX_JSONRPC_BATCH_SIZE = int(os.environ.get("MAX_JSONRPC_BATCH_SIZE", 500))


# Enable Demo Mode?
DEMO_MODE = bool(os.environ.get("DANKMIDS_DEMO_MODE", os.environ.get("DANK_MIDS_DEMO_MODE")))

# Are you calling a ganache fork? Can't use state override code
GANACHE_FORK = bool(os.environ.get("DANKMIDS_GANACHE_FORK", os.environ.get("DANK_MIDS_GANACHE_FORK")))

# We set the default to 20 minutes to account for potentially long event loop times if you're doing serious work.
AIOHTTP_TIMEOUT = int(os.environ.get("AIOHTTP_TIMEOUT", 20 * 60))


# Method-specific Semaphores
semaphore_envs = {
    "eth_getBlock": int(os.environ.get("ETH_GETBLOCK_SEMAPHORE", 50)), # [eth_getBlockByNumber, eth_getBlockByHash]
    "eth_getLogs": int(os.environ.get("ETH_GETLOGS_SEMAPHORE", 64)),
    "eth_getTransaction": int(os.environ.get("ETH_GETTRANSACTION_SEMAPHORE", 100)),
}

# Brownie call Semaphore
#   Used because I experienced some OOM errs due to web3 formatters when I was batching an absurd number of brownie calls.
#   We need a separate semaphore here because the method-specific semaphores are too late in the code to prevent this OOM issue.
BROWNIE_CALL_SEMAPHORE_VAL = int(os.environ.get("DANK_MIDS_BROWNIE_CALL_SEMAPHORE", 100_000))

# Processes for decoding
NUM_PROCESSES = int(os.environ.get("DANKMIDS_PROCESSES", 1))

# NOTE: EXPORT_STATS is not implemented
# TODO: implement this
EXPORT_STATS = bool(os.environ.get("DANKMIDS_EXPORT_STATS"))
COLLECT_STATS = bool(os.environ.get("DANKMIDS_COLLECT_STATS", EXPORT_STATS))
