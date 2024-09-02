
class Revert(ValueError):
    ...

class BrownieNotConnectedError(RuntimeError):
    """
    :class:`RuntimeError` raised when brownie is not connected but needs to be in order to access functionality within :mod:`dank_mids.brownie_patch`.
    """
    def __init__(self):
        super().__init__("brownie is not connected to a network")
