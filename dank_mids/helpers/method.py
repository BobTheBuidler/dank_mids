from typing import Final

from dank_mids.helpers.lru_cache import lru_cache_lite_nonull


BYPASS_METHODS: Final = "eth_blockNumber", "eth_getLogs", "trace_", "debug_"
"""
A tuple of method names that should bypass batching.
These methods are typically handled separately or have special requirements.
"""


@lru_cache_lite_nonull
def get_len(method: str) -> int:
    # NOTE: These are totally arbitrary, used to reduce frequency of giant batches/responses
    if method == "eth_getTransactionReceipt":
        return 5
    elif method in {"eth_getTransaction", "eth_getCode"} or "eth_getBlockBy" in method:
        return 3
    return 1


@lru_cache_lite_nonull
def should_batch(method: str) -> bool:
    return all(bypass not in method for bypass in BYPASS_METHODS)
