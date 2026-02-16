class Revert(ValueError): ...


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
        super().__init__(
            f"Brownie is not connected to a network. You must be connected to a network in order to access `dank_mids.{obj_name}`."
        )


class BrowniePatchImportError(ImportError):
    """
    :class:`ImportError` raised when brownie integration cannot be imported or initialized.
    """

    def __init__(self, obj_name: str, exc: ImportError) -> None:
        super().__init__(
            f"Failed to import brownie integration while accessing `dank_mids.{obj_name}`: {exc}"
        )
        self._original_exception = exc


class BrowniePatchNotInitializedError(RuntimeError):
    """
    :class:`RuntimeError` raised when brownie is connected but brownie patch was not initialized.
    """

    def __init__(self, obj_name: str) -> None:
        super().__init__(
            "Brownie is connected but dank_mids brownie patch was not initialized. "
            f"This can happen if `dank_mids` was imported before connecting. "
            f"Restart the process after connecting to access `dank_mids.{obj_name}`."
        )


class GarbageCollectionError(RuntimeError):
    """Exception raised when an object is garbage collected prematurely."""
