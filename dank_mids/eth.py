
from typing import List

import msgspec.json
from async_lru import alru_cache
from eth_typing import BlockNumber
from web3._utils.blocks import select_method_for_block_identifier
from web3.eth import AsyncEth

from dank_mids._method import MethodNoFormat, bypass_formatters, _block_selectors
from dank_mids.structs import Transaction
from dank_mids.structs.block import Timestamped, TinyBlock
from dank_mids.structs.data import uint


class DankEth(AsyncEth):
    @alru_cache(ttl=0)
    async def get_block_number(self) -> BlockNumber:  # type: ignore [override]
        return await super().get_block_number()  # type: ignore [misc]
    
    _get_block_raw = MethodNoFormat(
        method_choice_depends_on_args=select_method_for_block_identifier(**{k:f"{v}_raw" for k, v in _block_selectors.items()}),
        mungers=[AsyncEth.get_block_munger],
    )
    
    async def get_block_timestamp(self, block_identifier: int) -> uint:
        """
        Retrieves only the timestamp from a specific block.
        
        This method skips decoding the rest of the Block response data.

        Args:
            block_identifier: The block number from which to retrieve the transactions.
            hashes_only: If True, only transaction hashes will be returned.

        Returns:
            A list of :class:`~Transaction` data objects from the block, or a list of transaction hashes.

        Example:
            >>> [print(tx.hash) for tx in await dank_mids.eth.get_transactions(12345678)]
        """
        return msgspec.json.decode(await self._get_block_raw(block_identifier), type=Timestamped).timestamp

    async def get_transactions(self, block_identifier: int, hashes_only: bool = False) -> List[Transaction]:
        """
        Retrieves only the transactions from a specific block. 
        
        This method skips decoding the rest of the Block response data.

        Args:
            block_identifier: The block number from which to retrieve the transactions.
            hashes_only: If True, only transaction hashes will be returned.

        Returns:
            A list of :class:`~Transaction` data objects from the block, or a list of transaction hashes.

        Example:
            >>> [print(tx.hash) for tx in await dank_mids.eth.get_transactions(12345678)]
        """
        return msgspec.json.decode(await self._get_block_raw(block_identifier, not hashes_only), type=TinyBlock).transactions

    
# TODO: this is super hacky, make it not.
bypass_formatters(DankEth)
