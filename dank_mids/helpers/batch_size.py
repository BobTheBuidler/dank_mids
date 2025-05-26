from logging import getLogger
from typing import Final, Literal


batch_size_logger: Final = getLogger("dank_mids.batch_size")
_log_info: Final = batch_size_logger.info


def log_check(
    batch_type: Literal["multicall", "json"],
    member_type: Literal["calls", "requests"],
    num_calls: int,
) -> None:
    _log_info(
        "checking if we should reduce %s batch size... (%s %s)", batch_type, num_calls, member_type
    )
