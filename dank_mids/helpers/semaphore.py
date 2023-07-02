from typing import Union

from a_sync import DummySemaphore, ThreadsafeSemaphore
from web3.types import RPCEndpoint

from dank_mids.ENVIRONMENT_VARIABLES import semaphore_envs


class MethodSemaphores:
    def __init__(self) -> None:
        self.method_semaphores = {key: ThreadsafeSemaphore(value) for key, value in semaphore_envs.items()}
        self.keys = self.method_semaphores.keys()
        self.dummy = DummySemaphore()
    
    def __getitem__(self, method: RPCEndpoint) -> Union[ThreadsafeSemaphore, DummySemaphore]:
        return next((self.method_semaphores[key] for key in self.keys if key in method), self.dummy)

method_semaphores = MethodSemaphores()
