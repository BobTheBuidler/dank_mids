import asyncio
from typing import Union
from web3.types import RPCEndpoint
from dank_mids._config import semaphore_envs
from threading import current_thread
from typing import Dict


class ThreadsafeSemaphore:
    """
    While its a bit weird to run multiple event loops, sometimes either you or a lib you're using must do so. 
    When in use in threaded applications, the semaphore will not work as intended but at least your program will function.
    You may need to reduce the semaphore value for multi-threaded applications.
    """

    def __init__(self, value: int) -> None:
        self.default_value = value
        self.semaphores: Dict[int, asyncio.Semaphore] = {}
    
    @property
    def semaphore(self) -> asyncio.Semaphore:
        tid = current_thread()
        if tid not in self.semaphores:
            self.semaphores[tid] = asyncio.Semaphore(self.default_value)  # type: ignore [index]
        return self.semaphores[tid]  # type: ignore [index]
    
    async def __aenter__(self):
        await self.semaphore.acquire()
    
    async def __aexit__(self, *args):
        self.semaphore.release()


class _DummySemaphore:
    async def __aenter__(self):
        ...
    async def __aexit__(self, *args):
        ...

class Semaphores:
    def __init__(self) -> None:
        self.method_semaphores = {key: ThreadsafeSemaphore(value) for key, value in semaphore_envs.items()}
        self.keys = self.method_semaphores.keys()
        self.dummy = _DummySemaphore()
    
    def __getitem__(self, method: RPCEndpoint) -> Union[ThreadsafeSemaphore, _DummySemaphore]:
        for key in self.keys:
            if key in method:
                return self.method_semaphores[key]
        return self.dummy

method_semaphores = Semaphores()
