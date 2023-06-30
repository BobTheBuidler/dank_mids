
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from dank_mids.types import PartialResponse


class BadResponse(ValueError):
    def __init__(self, response: "PartialResponse") -> None:
        self.response = response
        super().__init__(response.to_dict())

class EmptyBatch(ValueError):
    pass

class PayloadTooLarge(BadResponse):
    pass
