import asyncio
from collections import defaultdict
from typing import Union
from web3.types import RPCEndpoint
from dank_mids._config import semaphore_envs


class _DummySemaphore:
    async def __aenter__(self):
        ...
    async def __aexit__(self, *args):
        ...

class Semaphores:
    def __init__(self) -> None:
        self.method_semaphores = defaultdict(lambda: _DummySemaphore())
        for method, value in semaphore_envs.items():
            self.method_semaphores[method] = asyncio.Semaphore(value)
        self.keys = self.method_semaphores.keys()
    
    def __getitem__(self, method: RPCEndpoint) -> Union[asyncio.Semaphore, _DummySemaphore]:
        for key in self.keys:
            if key in method:
                return self.method_semaphores[key]
        return self.method_semaphores[method]

method_semaphores = Semaphores()
