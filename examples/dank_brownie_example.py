
"""
The following code will send just one http call to your node.
Take note of the liberal use of `asyncio.gather`.
This is how you ensure that all of the various parts of your code are running at the same time, and are therefore batchable.
"""

import asyncio


# Define the main function and the blocks we want to get information from.
# Also define the Uniswap pools we want to get data from.
def main():
    asyncio.run(_main())

# Import dank's modified Contract class
from dank_mids import Contract

async def _main():
    blocks = [15_000_000, 15_100_000, 15_200_000, 15_300_000, 15_400_000, 15_500_000]
    uniswap_pools = [
        "0xBb2b8038a1640196FbE3e38816F3e67Cba72D940",
        "0x0d4a11d5EEaaC28EC3F61d100daF4d40471f1852",
        "0xB4e16d0168e52d35CaCD2c6185b44281Ec28C9Dc",
        "0xA478c2975Ab1Ea89e8196811F51A7B7Ade33eB11",
    ]

    # Initialize the pools as `dank_mids.Contract` objects.
    dank_pool_contracts = [Contract(pool) for pool in uniswap_pools]

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


# To batch other rpc calls, import and use the dank_web3 instance.
# This instance wraps the connected brownie Web3 instance and injects the dank middleware for batching
from dank_mids import dank_web3

async def get_timestamp_at_block(block):
    block = await dank_web3.eth.get_block(block)
    return block.timestamp
