
"""
The following code will send just one http call to your node.
Take note of the liberal use of `asyncio.gather`.
This is how you ensure that all of the various parts of your code are running at the same time, and are therefore batchable.
"""

# Import the necessary packages and set up the dank_w3 instance.
# This instance is used to wrap the web3 object, allowing us to make batch calls.
import asyncio

from brownie import Contract, web3
from dank_mids.brownie_patch import patch_contract
from dank_mids.helpers import setup_dank_w3_from_sync

dank_w3 = setup_dank_w3_from_sync(web3)

# Define the main function and the blocks we want to get information from.
# Also define the Uniswap pools we want to get data from.
def main():
    asyncio.run(_main())

async def _main():
    blocks = [15_000_000, 15_100_000, 15_200_000, 15_300_000, 15_400_000, 15_500_000]
    uniswap_pools = [
        "0xBb2b8038a1640196FbE3e38816F3e67Cba72D940",
        "0x0d4a11d5EEaaC28EC3F61d100daF4d40471f1852",
        "0xB4e16d0168e52d35CaCD2c6185b44281Ec28C9Dc",
        "0xA478c2975Ab1Ea89e8196811F51A7B7Ade33eB11",
    ]

# Add the contracts to the list and wrap them with the dank_w3 instance.
    uniswap_pool_contracts = [Contract(pool) for pool in uniswap_pools]
    dank_pool_contracts = [patch_contract(pool, dank_w3) for pool in uniswap_pool_contracts]

# Use asyncio.gather to collect the data from the various pools and blocks and store them in variables.
    tokens, timestamps, balances = await asyncio.gather(
        asyncio.gather(*[get_tokens_for_pool(pool) for pool in dank_pool_contracts]),
        asyncio.gather(*[get_timestamp_at_block(block) for block in blocks]),
        asyncio.gather(*[get_balances_for_blocks(pool, blocks) for pool in dank_pool_contracts])
    )

# Now we can do stuff with the outputs
# stuff = more_stuff
# do_stuff()

# Functions that we used to get the data from the pools and blocks:
async def get_balances_for_blocks(pool, blocks):
    return await asyncio.gather(*[pool.getReserves.coroutine(block_identifier=block) for block in blocks])

async def get_tokens_for_pool(pool):
    return await asyncio.gather(
        pool.token0.coroutine(),
        pool.token1.coroutine(),
    )

async def get_timestamp_at_block(block):
    block = await dank_w3.eth.get_block(block)
    return block.timestamp
