
import asyncio
import os

SEMAPHORE = asyncio.Semaphore(int(os.environ.get("DANKMIDSSEMAPHORE", 100_000)))
LOOP_INTERVAL = float(os.environ.get("DANKMIDSLOOPINTERVAL", 0.001))
