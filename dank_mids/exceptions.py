"""
.. automodule:: exceptions
    :exclude-members: __init__, __new__, args, with_traceback
"""

class Revert(ValueError):
    ...

class BrownieNotConnectedError(RuntimeError):
    """
    :class:`RuntimeError` raised when brownie is not connected but needs to be in order to access functionality within :mod:`dank_mids.brownie_patch`.
    """
    def __init__(self, obj_name: str):
        """
        Initializes a new BrownieNotConnectedError.
        
        Params:
            obj_name: The name of the object the user attempted to access, which requires brownie to be connected.
        """
        super().__init__(f"Brownie is not connected to a network. You must be connected to a network in order to access `dank_mids.{obj_name}`.")
