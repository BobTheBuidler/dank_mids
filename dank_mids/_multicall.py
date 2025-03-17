from functools import lru_cache
from typing import Optional

from eth_typing import BlockNumber, ChecksumAddress
from eth_utils import to_checksum_address
from msgspec import Struct
from multicall.constants import MULTICALL2_ADDRESSES, MULTICALL_ADDRESSES

from dank_mids.constants import (
    MULTICALL2_DEPLOY_BLOCKS,
    MULTICALL2_OVERRIDE_CODE,
    MULTICALL3_DEPLOY_BLOCKS,
    MULTICALL3_OVERRIDE_CODE,
)

try:
    from multicall.constants import MULTICALL3_ADDRESSES
except ImportError:
    MULTICALL3_ADDRESSES = {}


class MulticallContract(Struct):
    """
    Represents a multicall contract with its address, deployment block, and bytecode.
    """

    address: ChecksumAddress
    """
    The Ethereum address of the multicall contract.
    """

    deploy_block: Optional[BlockNumber]
    """
    The block number at which the multicall contract was deployed.
    If None, it means the deployment block is unknown.
    """

    bytecode: str
    """
    The bytecode of the multicall contract.
    This is used for state override if necessary.
    """

    @lru_cache(maxsize=1024)
    def needs_override_code_for_block(self, block: BlockNumber) -> bool:
        """
        Determine if the contract needs override code for a specific block.

        Args:
            block: The block number to check.

        Returns:
            True if override code is needed, False otherwise.
        """
        if block == "latest":
            return False
        if self.deploy_block is None:
            return True
        if isinstance(block, str):
            block = int(block, 16)
        return block < self.deploy_block

    def __hash__(self) -> int:
        """
        Generates a hash for the MulticallContract instance.

        Returns:
            A hash value based on the contract's address.
        """
        return hash(self.address)


def _get_multicall2(chainid: int) -> Optional[MulticallContract]:
    if multicall2 := MULTICALL2_ADDRESSES.get(chainid):
        return MulticallContract(
            address=to_checksum_address(multicall2),
            # TODO: copypasta deploy block dict
            deploy_block=MULTICALL2_DEPLOY_BLOCKS.get(chainid),
            bytecode=MULTICALL2_OVERRIDE_CODE,
        )


def _get_multicall3(chainid: int) -> Optional[MulticallContract]:
    if multicall3 := MULTICALL3_ADDRESSES.get(chainid):
        return MulticallContract(
            address=to_checksum_address(multicall3),
            # TODO: copypasta deploy block dict
            deploy_block=MULTICALL3_DEPLOY_BLOCKS.get(chainid),
            bytecode=MULTICALL3_OVERRIDE_CODE,
        )
