
from typing import Union

from a_sync.primitives import DummySemaphore, ThreadsafeSemaphore
from web3.types import RPCEndpoint


class MethodSemaphores:
    def __init__(self) -> None:
        from dank_mids import ENVIRONMENT_VARIABLES
        self.method_semaphores = {
            method: ThreadsafeSemaphore(value, name=method) 
            for method, value in ENVIRONMENT_VARIABLES.method_semaphores.items()
        }
        self.keys = self.method_semaphores.keys()
        self.dummy = DummySemaphore()
    
    def __getitem__(self, method: RPCEndpoint) -> Union[ThreadsafeSemaphore, DummySemaphore]:
        return next((self.method_semaphores[key] for key in self.keys if key in method), self.dummy)
