# mypy: disable-error-code="attr-defined, has-type, dict-item"
from logging import StreamHandler
from typing import Dict, Final

import a_sync
import typed_envs
from a_sync import AsyncProcessPoolExecutor

from dank_mids import _envs
from dank_mids._logging import INFO, getLogger
from dank_mids._mode import OperationMode
from dank_mids.semaphores import BlockSemaphore


logger: Final = getLogger("dank_mids.envs")

if not typed_envs.logger.disabled:
    if not logger.hasHandlers():
        logger.addHandler(StreamHandler())
    if not logger.isEnabledFor(INFO):
        logger.setLevel(INFO)
    logger.info(
        "For your information, you can tweak your configuration for optimal performance using any of the envs below:"
    )


###############
# ENVIRONMENT #
###############

# What mode should dank mids operate in?
# NOTE: infura mode is required for now
# TODO: fix the other modes, set default='default', and make this verbose again
OPERATION_MODE: Final[OperationMode] = _envs.create_env(
    "OPERATION_MODE", OperationMode, default="infura", verbose=False
)  # type: ignore [assignment]

# Max number of eth calls to include in one multicall
MAX_MULTICALL_SIZE: Final = _envs.create_env("MAX_MULTICALL_SIZE", int, default=10_000)
# Max number of rpc calls to include in one batch call
MAX_JSONRPC_BATCH_SIZE: Final = _envs.create_env("MAX_JSONRPC_BATCH_SIZE", int, default=500)
# Maximum amount of requests per second
REQUESTS_PER_SECOND: Final = _envs.create_env("REQUESTS_PER_SECOND", int, default=50)
# Minimum amount of requests per second after rate limit reduction
MIN_REQUESTS_PER_SECOND: Final = _envs.create_env("MIN_REQUESTS_PER_SECOND", int, default=10)

# Enable Demo Mode?
demo_mode: Final = _envs._deprecated_format.create_env(
    "DEMO_MODE", bool, default=False, verbose=False
)
DEMO_MODE: Final = _envs.create_env("DEMO_MODE", bool, default=bool(demo_mode), verbose=False)

# Are you calling a ganache fork? Can't use state override code
ganache_fork: Final = _envs._deprecated_format.create_env(
    "GANACHE_FORK", bool, default=False, verbose=False
)
GANACHE_FORK: Final = _envs.create_env("GANACHE_FORK", bool, default=bool(ganache_fork))
"""Flag indicating whether the current environment is a Ganache fork."""

# We set the default to 20 minutes to account for potentially long event loop times if you're doing serious work.
AIOHTTP_TIMEOUT: Final = _envs.create_env("AIOHTTP_TIMEOUT", int, default=20 * 60)
"""Timeout value in seconds for aiohttp requests."""

# Brownie call Semaphore
#   Used because I experienced some OOM errs due to web3 formatters when I was batching an absurd number of brownie calls.
#   We need a separate semaphore here because the method-specific semaphores are too late in the code to prevent this OOM issue.
brownie_semaphore: Final = _envs._deprecated_format.create_env(
    "BROWNIE_CALL_SEMAPHORE", int, default=100_000, verbose=False
)
BROWNIE_CALL_SEMAPHORE: Final = _envs.create_env(
    "BROWNIE_CALL_SEMAPHORE",
    BlockSemaphore,
    default=brownie_semaphore,
    verbose=not OPERATION_MODE.infura,
)
"""
Semaphore for limiting concurrent Brownie calls.

See Also:
    :class:`dank_mids.semaphores.BlockSemaphore`: The semaphore class used for concurrency control.
"""

BROWNIE_ENCODER_SEMAPHORE: Final = _envs.create_env(
    "BROWNIE_ENCODER_SEMAPHORE",
    BlockSemaphore,
    default=BROWNIE_CALL_SEMAPHORE._default_value * 2,
    verbose=not OPERATION_MODE.infura,
)
"""
Semaphore for limiting concurrent Brownie encoding operations. This limits memory consumption.

See Also:
    :class:`dank_mids.semaphores.BlockSemaphore`: The semaphore class used for concurrency control.
"""

# Processes for decoding. This determines process pool size, not total subprocess count.
# There are 3 pools, each initialized with the same value.
# NOTE: Don't stress, these are good for you and will not hog your cpu. You can disable them by setting the var = 0.
BROWNIE_ENCODER_PROCESSES = _envs.create_env(
    "BROWNIE_ENCODER_PROCESSES",
    AsyncProcessPoolExecutor,
    default=0 if OPERATION_MODE.infura else 1,
    verbose=not OPERATION_MODE.infura,
)
"""
Process pool for Brownie encoding operations.

See Also:
    :class:`a_sync.AsyncProcessPoolExecutor`: The executor class used for managing asynchronous processes.
"""

BROWNIE_DECODER_PROCESSES = _envs.create_env(
    "BROWNIE_DECODER_PROCESSES",
    AsyncProcessPoolExecutor,
    default=0 if OPERATION_MODE.infura else 1,
    verbose=not OPERATION_MODE.infura,
)
"""
Process pool for Brownie decoding operations.

See Also:
    :class:`a_sync.AsyncProcessPoolExecutor`: The executor class used for managing asynchronous processes.
"""

MULTICALL_DECODER_PROCESSES = _envs.create_env(
    "MULTICALL_DECODER_PROCESSES",
    AsyncProcessPoolExecutor,
    default=0 if OPERATION_MODE.infura else 1,
    verbose=not OPERATION_MODE.infura,
)
"""
Process pool for Multicall decoding operations.

See Also:
    :class:`a_sync.AsyncProcessPoolExecutor`: The executor class used for managing asynchronous processes.
"""

COLLECTION_FACTOR: Final = _envs.create_env(
    "COLLECTION_FACTOR",
    int,
    default=10 if OPERATION_MODE.infura else 1,
    verbose=not OPERATION_MODE.infura,
)
"""Factor determining the size of data collection operations."""

# We use a modified version of the request spec that doesn't contain unnecessary fields, and switch to the full spec if necessary for your node.
# Set this env var to any value to force the full request spec always
USE_FULL_REQUEST: Final = _envs.create_env("USE_FULL_REQUEST", bool, default=False, verbose=False)
"""Flag indicating whether to use the full request specification."""

DEBUG: Final = _envs.create_env("DEBUG", bool, default=False, verbose=False)
# NOTE: EXPORT_STATS is not implemented
# TODO: implement this
EXPORT_STATS: Final = _envs.create_env("EXPORT_STATS", bool, default=False, verbose=False)
# NOTE: COLLECT_STATS is implemented
COLLECT_STATS: Final = _envs.create_env(
    "COLLECT_STATS", bool, default=EXPORT_STATS, verbose=not EXPORT_STATS
)

# You probably don't need to use this unless you know you need to
STUCK_CALL_TIMEOUT: Final = _envs.create_env("STUCK_CALL_TIMEOUT", int, default=60 * 2)

# Method-specific Semaphores
method_semaphores: Final[Dict[str, a_sync.Semaphore]] = {
    "eth_call": _envs.create_env(
        "ETH_CALL_SEMAPHORE",
        BlockSemaphore,
        default=BROWNIE_CALL_SEMAPHORE._value,
        verbose=False,
    ),
    "eth_getCode": _envs.create_env(
        "ETH_GETCODE_SEMAPHORE",
        a_sync.Semaphore,
        default=5_000,
        verbose=False,
    ),
}

if not typed_envs.logger.disabled:
    logger.info("More details can be found in dank_mids/ENVIRONMENT_VARIABLES.py")
    logger.info(
        "NOTE: You can disable these logs by setting the `TYPEDENVS_SHUTUP` env var to any value."
    )


# Validate some stuffs

# NOTE: The other modes are (probably) bugging out right now. More investigation needed. For now you use infura mode.
if not OPERATION_MODE.infura:
    logger.warning(
        "Unless you know what you're doing, dank mids should be run in infura mode for now"
    )

if OPERATION_MODE.infura:
    for process_pool in {
        MULTICALL_DECODER_PROCESSES,
        BROWNIE_DECODER_PROCESSES,
        BROWNIE_ENCODER_PROCESSES,
    }:
        if process_pool._max_workers:
            raise ValueError(
                f"You cannot set env var {process_pool.name} while running dank in infura mode."
            )
