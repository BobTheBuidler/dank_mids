import asyncio
from collections import defaultdict

from dank_mids._config import semaphore_envs


class _DummySemaphore:
    async def __aenter__(self):
        ...
    async def __aexit__(self, *args):
        ...

method_semaphores = defaultdict(lambda: _DummySemaphore())
for method, value in semaphore_envs.items():
    method_semaphores[method] = asyncio.Semaphore(value)
