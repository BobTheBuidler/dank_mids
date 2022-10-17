
import os

from aiohttp import ClientTimeout

LOOP_INTERVAL = float(os.environ.get("DANKMIDSLOOPINTERVAL", 0.01))

# Enable Demo Mode?
DEMO_MODE = bool(os.environ.get("DANKMIDS_DEMO_MODE")) or bool(os.environ.get("DANK_MIDS_DEMO_MODE"))

# With default AsyncBaseProvider settings, some dense calls will fail
#   due to aiohttp.TimeoutError where they would otherwise succeed.
#   We set the default to 30s but if you're doing serious work you may want to increase it further.
AIOHTTP_TIMEOUT = ClientTimeout(int(os.environ.get("AIOHTTP_TIMEOUT", 30)))
