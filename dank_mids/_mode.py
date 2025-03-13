from functools import cached_property

MODES = "default", "application", "infura"


class OperationMode(str):
    """
    Enum-like class that defines different operation modes for dank_mids.

    These modes affect how dank_mids optimizes requests and interacts
    with different Ethereum node providers.
    """

    @cached_property
    def application(self):
        """
        Checks if the current mode is 'application'.

        The 'application' mode keeps the event loop as unblocked as possible
        so an asyncio application can run as designed.
        """
        return self.mode == "application"

    @cached_property
    def default(self):
        """
        Checks if the current mode is 'default'.
        """
        return self.mode == "default"

    @cached_property
    def infura(self):
        """
        Checks if the current mode is 'infura'.

        The 'infura' mode minimizes the total number of calls sent to the node.
        """
        return self.mode == "infura"

    @property
    def mode(self):
        """
        Retrieves the current operation mode.

        Raises:
            ValueError: If the mode is invalid.
        """
        if self not in MODES:
            raise ValueError(
                f"dank mids operation mode {self} is invalid", f"valid modes: {MODES}", str(self)
            )
        return self
