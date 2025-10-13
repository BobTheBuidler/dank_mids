# mypy: disable-error-code="attr-defined, dict-item"
from typing import Dict, Final

import multicall.constants
from eth_typing import BlockNumber
from multicall.constants import Network

TOO_MUCH_DATA_ERRS: Final = {
    "payload too large",
    "content length too large",
    "request entity too large",
    "batch limit exceeded",
}
"""A list of error messages indicating that the request sent to the RPC was too large and must be split up.

These error messages are used to identify when a request needs to be broken into smaller chunks.
"""

RETRY_ERRS: Final = {
    "connection reset by peer",
    "server disconnected",
    "execution aborted (timeout =",
    "batch limit exceeded",
    "request timed out",
    "evm timeout",
    "evm error",
}
"""A list of error messages that are expected during normal use and are not indicative of any problem(s).

These errors will be automatically retried until success is achieved.
"""

GAS_LIMIT: Final = multicall.constants.GAS_LIMIT
"""The gas limit constant imported from the :mod:`multicall` library.

This value is used as the default gas limit for multicall operations.
"""

MULTICALL2_OVERRIDE_CODE: Final = multicall.constants.MULTICALL2_BYTECODE
"""The bytecode for the Multicall2 contract.

This is used for state override on blocks before the Multicall2 contract was deployed.
"""

try:
    __MULTICALL3_OVERRIDE_CODE = multicall.constants.MULTICALL3_BYTECODE
    """The bytecode for the Multicall3 contract, if it is available in the multicall library.

    If the constant is not available, this will fall back to the Multicall2 bytecode.
    """
except AttributeError:
    __MULTICALL3_OVERRIDE_CODE = multicall.constants.MULTICALL2_BYTECODE
finally:
    MULTICALL3_OVERRIDE_CODE: Final = __MULTICALL3_OVERRIDE_CODE

MULTICALL2_DEPLOY_BLOCKS: Final[Dict[Network, BlockNumber]] = {
    Network.Mainnet: 12336033,
    Network.Fantom: 16572242,
    Network.Arbitrum: 821923,
    Network.Optimism: 722566,
}
"""A dictionary mapping networks to the block numbers where Multicall2 was deployed."""

MULTICALL3_DEPLOY_BLOCKS: Final[Dict[Network, BlockNumber]] = {
    Network.Mainnet: 14353601,
    Network.Fantom: 33001987,
    Network.Arbitrum: 7654707,
    Network.Optimism: 4286263,
    Network.Base: 5022,
}
"""A dictionary mapping networks to the block numbers where Multicall3 was deployed."""

# When you get these call responses back from the multicall, we know there was some problem with execution.
# If you make the exact same calls without multicall, you will get an Exception not a response.
# TODO: Delete these
BAD_HEXES: Final = (
    # Chainlink feeds no access
    "0x08c379a0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000094e6f206163636573730000000000000000000000000000000000000000000000",
    # Mint is paused, ironbank
    "0x08c379a00000000000000000000000000000000000000000000000000000000000000020000000000000000000000000000000000000000000000000000000000000000e6d696e7420697320706175736564000000000000000000000000000000000000",
    # Invalid Ether transfer
    "0x08c379a000000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000016496e76616c6964206574686572207472616e7366657200000000000000000000",
    # Non Empty Data
    "0x08c379a00000000000000000000000000000000000000000000000000000000000000020000000000000000000000000000000000000000000000000000000000000000e4e4f4e5f454d5054595f44415441000000000000000000000000000000000000",
    # msg.sig is not assigned to submodule
    "0x08c379a0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000246d73672e736967206973206e6f742061737369676e656420746f207375626d6f64756c6500000000000000000000000000000000000000000000000000000000",
    # only wrapped native contract could send native token
    "0x08c379a0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000346f6e6c792077726170706564206e617469766520636f6e747261637420636f756c642073656e64206e617469766520746f6b656e000000000000000000000000",
    # Controller Rejected
    "0x08c379a000000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000013434f4e54524f4c4c45525f52454a454354454400000000000000000000000000",
    # Diamond: Function does not exist
    "0x08c379a0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000204469616d6f6e643a2046756e6374696f6e20646f6573206e6f74206578697374",
    # function should be allowed
    "0x08c379a00000000000000000000000000000000000000000000000000000000000000020000000000000000000000000000000000000000000000000000000000000001a66756e6374696f6e2073686f756c6420626520616c6c6f776564000000000000",
    # Function does not exist
    "0x08c379a00000000000000000000000000000000000000000000000000000000000000020000000000000000000000000000000000000000000000000000000000000001846756e6374696f6e20646f6573206e6f742065786973742e0000000000000000",
)

# Not sure why yet but sometimes a multicall will succeed but one of the results will be a failure for one call that doesn't interrupt the rest of the mcall.
# NOTE: we leave off the '0x' so we can compare raw bytes
# NOTE: The 2nd one here needs to be converted to the first format but I need to encounter one in the wild before I can do that
REVERT_SELECTORS: Final = (b"\x08\xc3y\xa0", b"4e487b71")
"""A list of byte strings representing revert selectors.

These selectors are used to identify specific types of revert errors in Ethereum transactions.
"""
