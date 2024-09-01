
from functools import cached_property

MODES = ["default", "application", "infura"]

class OperationMode(str):
    """
    Enum-like class to define different operation modes for dank_mids.

    These modes can affect how dank_mids optimizes requests and interacts
    with different Ethereum node providers.
    """
    @cached_property
    def application(self) -> bool:
        # This mode keeps the event loop as unblocked as possible so an asyncio application can run as designed
        return self.mode == "application"
    @cached_property
    def default(self) -> bool:
        return self.mode == "default"
    @cached_property
    def infura(self) -> bool:
        # This mode minimizes the total number of calls sent to the node
        return self.mode == "infura"
    @property
    def mode(self) -> str:
        if self not in MODES:
            raise ValueError(f'dank mids operation mode {self} is invalid', f'valid modes: {MODES}', str(self))
        return self
