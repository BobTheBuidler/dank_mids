
import msgspec.json
from async_lru import alru_cache
from eth_typing import BlockNumber
from web3._utils.blocks import select_method_for_block_identifier
from web3.eth import AsyncEth

from dank_mids._method import MethodNoFormat, bypass_formatters, _block_selectors
from dank_mids.types import _Timestampped, uint


class DankEth(AsyncEth):
    @alru_cache(ttl=0)
    async def get_block_number(self) -> BlockNumber:  # type: ignore [override]
        return await super().get_block_number()  # type: ignore [misc]
    
    async def get_block_timestamp(self, block_identifier: int) -> uint:
        raw = await self._get_block_raw(block_identifier)
        return msgspec.json.decode(raw, typ=_Timestampped).timestamp
    
    _get_block_raw = MethodNoFormat(
        method_choice_depends_on_args=select_method_for_block_identifier(**{k:f"{v}_raw" for k, v in _block_selectors.items()}),
        mungers=[AsyncEth.get_block_munger],
    )

    
# TODO: this is super hacky, make it not.
bypass_formatters(DankEth)
