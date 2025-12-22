from typing import Final, Literal

from dank_mids.logging import get_c_logger


batch_size_logger: Final = get_c_logger("dank_mids.batch_size")


def log_check(
    batch_type: Literal["multicall", "json"],
    member_type: Literal["calls", "requests"],
    num_calls: int,
) -> None:
    batch_size_logger.info(
        "checking if we should reduce %s batch size... (%s %s)", batch_type, num_calls, member_type
    )
