from typing import Final

from typing_extensions import Self


MODES: Final = "default", "application", "infura"


class OperationMode(str):
    """
    Enum-like class that defines different operation modes for dank_mids.

    These modes affect how dank_mids optimizes requests and interacts
    with different Ethereum node providers.
    """

    def __init__(self) -> None:
        super().__init__()

        self.application: Final = self.mode == "application"
        """
        True if the current mode is 'application'.

        The 'application' mode keeps the event loop as unblocked as possible
        so an asyncio application can run as designed.
        """

        self.default: Final = self.mode == "default"
        """
        True if the current mode is 'default'.
        """

        self.infura: Final = self.mode == "infura"
        """
        True if the current mode is 'infura'.

        The 'infura' mode minimizes the total number of calls sent to the node.
        """

    @property
    def mode(self) -> Self:
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
