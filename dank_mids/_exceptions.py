
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from dank_mids.types import Response


class BadResponse(Exception):
    def __init__(self, response: "Response") -> None:
        self.response = response
        super().__init__(response.to_dict())

class EmptyBatch(Exception):
    pass
