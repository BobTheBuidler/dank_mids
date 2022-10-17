
import os

LOOP_INTERVAL = float(os.environ.get("DANKMIDSLOOPINTERVAL", 0.01))

# Enable Demo Mode?
DEMO_MODE = bool(os.environ.get("DANKMIDS_DEMO_MODE")) or bool(os.environ.get("DANK_MIDS_DEMO_MODE"))
