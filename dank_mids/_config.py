
import os

from aiohttp import ClientTimeout

LOOP_INTERVAL = float(os.environ.get("DANKMIDSLOOPINTERVAL", 0.01))

# Max number of rpc calls to include in one batch call
MAX_JSONRPC_BATCH_SIZE = int(os.environ.get("MAX_JSONRPC_BATCH_SIZE", 500))


# Enable Demo Mode?
DEMO_MODE = bool(os.environ.get("DANKMIDS_DEMO_MODE", os.environ.get("DANK_MIDS_DEMO_MODE")))

# Are you calling a ganache fork? Can't use state override code
GANACHE_FORK = bool(os.environ.get("DANKMIDS_GANACHE_FORK", os.environ.get("DANK_MIDS_GANACHE_FORK")))

# With default AsyncBaseProvider settings, some dense calls will fail
#  due to aiohttp.TimeoutError where they would otherwise succeed.
# This is not due to the response time from the node, but the event loop timing.
# We set the default to 5 minutes but if you're doing serious work
#  you may want to increase it further.
AIOHTTP_TIMEOUT = ClientTimeout(int(os.environ.get("AIOHTTP_TIMEOUT", 300)))


# Method-specific Semaphores
semaphore_envs = {
    "eth_getBlock": int(os.environ.get("ETH_GETBLOCK_SEMAPHORE", 50)), # [eth_getBlockByNumber, eth_getBlockByHash]
    "eth_getLogs": int(os.environ.get("ETH_GETLOGS_SEMAPHORE", 16)),
    "eth_getTransaction": int(os.environ.get("ETH_GETTRANSACTION_SEMAPHORE", 100)),
}

# Brownie call Semaphore
#   Used because I experienced some OOM errs due to web3 formatters when I was batching an absurd number of brownie calls.
#   We need a separate semaphore here because the method-specific semaphores are too late in the code to prevent this OOM issue.
BROWNIE_CALL_SEMAPHORE_VAL = int(os.environ.get("DANK_MIDS_BROWNIE_CALL_SEMAPHORE", 100_000))

_ONE_HOUR = 60 * 60
BROWNIE_ENCODER_CACHE_TTL = int(os.environ.get("DANK_MIDS_BROWNIE_ENCODER_CACHE_TTL", _ONE_HOUR))
BROWNIE_DECODER_CACHE_TTL = int(os.environ.get("DANK_MIDS_BROWNIE_DECODER_CACHE_TTL", _ONE_HOUR))
BROWNIE_ENCODER_CACHE_MAXSIZE = int(os.environ.get("DANK_MIDS_BROWNIE_ENCODER_CACHE_MAXSIZE", 10_000))
BROWNIE_DECODER_CACHE_MAXSIZE = int(os.environ.get("DANK_MIDS_BROWNIE_DECODER_CACHE_MAXSIZE", 10_000))