
import os

from aiohttp import ClientTimeout

LOOP_INTERVAL = float(os.environ.get("DANKMIDSLOOPINTERVAL", 0.01))


# Enable Demo Mode?
DEMO_MODE = bool(os.environ.get("DANKMIDS_DEMO_MODE", os.environ.get("DANK_MIDS_DEMO_MODE")))


# With default AsyncBaseProvider settings, some dense calls will fail
#  due to aiohttp.TimeoutError where they would otherwise succeed.
# We set the default to 2 minutes but if you're doing serious work
#  you may want to increase it further.
AIOHTTP_TIMEOUT = ClientTimeout(int(os.environ.get("AIOHTTP_TIMEOUT", 120)))


# Method-specific Semaphores
semaphore_envs = {
    "eth_getBlock": int(os.environ.get("ETH_GETBLOCK_SEMAPHORE", 50)),
    "eth_getLogs": int(os.environ.get("ETH_GETLOGS_SEMAPHORE", 16)),
    "eth_getTransaction": int(os.environ.get("ETH_GETTRANSACTION_SEMAPHORE", 100)),
}
