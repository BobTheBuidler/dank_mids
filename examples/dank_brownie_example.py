"""
This example demonstrates how to use dank_mids with Brownie for efficient blockchain data retrieval.

The following code will send just one http call to your node.

dank_mids integrates seamlessly with Brownie, allowing for batched and optimized RPC calls.
This can significantly improve performance when fetching large amounts of data from the blockchain.

Key features of dank_mids Brownie integration:
1. Automatic batching of eth_call operations into multicalls
2. Asynchronous execution of RPC calls
3. Easy-to-use interface that mimics standard Brownie patterns

Take note of the liberal use of `asyncio.gather`, this is how you ensure that all of the various parts of your code are running at the same time, and are therefore batchable.
"""

# Import your imports, including `asyncio` and `dank_mids`.
import asyncio
from typing import List

import dank_mids
from web3.types import Timestamp

# For the purpose of this example, we will define the Uniswap pools we want to get data from 
# and the blocks at which we wish to fetch data.
blocks = [15_000_000, 15_100_000, 15_200_000, 15_300_000, 15_400_000, 15_500_000]
uniswap_pools = [
    "0xBb2b8038a1640196FbE3e38816F3e67Cba72D940",
    "0x0d4a11d5EEaaC28EC3F61d100daF4d40471f1852",
    "0xB4e16d0168e52d35CaCD2c6185b44281Ec28C9Dc",
    "0xA478c2975Ab1Ea89e8196811F51A7B7Ade33eB11",
]
    

# Define the main function and the async coroutine it will run
def main() -> None:
    """
    The main entry point for the script.

    This function sets up the asyncio event loop and runs the asynchronous :func:`_main` function that we define next.
    """
    asyncio.run(_main())

async def _main() -> None:
    """
    The main asynchronous function that demonstrates the usage of Dank Mids with Brownie.

    This function initializes :class:`dank_mids.Contract` objects for Uniswap pools and fetches data
    using asynchronous calls.
    """
    # Initialize the pools as `dank_mids.Contract` objects.
    dank_pool_contracts = [dank_mids.Contract(pool) for pool in uniswap_pools]

    # Use `asyncio.gather` to collect the data from the various pools and blocks and store them in variables.
    tokens, timestamps, balances = await asyncio.gather(
        asyncio.gather(*[get_tokens_for_pool(pool) for pool in dank_pool_contracts]),
        asyncio.gather(*[get_timestamp_at_block(block) for block in blocks]),
        asyncio.gather(*[get_balances_for_blocks(pool, blocks) for pool in dank_pool_contracts])
    )
    # Now we can do stuff with the outputs
    for pool, (token0, token1) in zip(dank_pool_contracts, tokens):
        """await do_stuff(pool, token0, token1)"""
    for block, timestamp in zip(blocks, timestamps):
        """await do_stuff(block, timestamp)"""
    for pool, balances in zip(dank_pool_contracts, tokens):
        for balance, block in zip(balances, blocks):
            """await do_stuff(pool, balance, block)"""


# Functions that we used to get the data from the pools and blocks:
async def get_balances_for_blocks(pool: dank_mids.Contract, blocks: List[int]):
    """
    Fetch balances for a pool across multiple blocks.

    Args:
        pool: The pool contract to query.
        blocks: The list of block numbers to query.

    Returns:
        List[Tuple]: A list of balance tuples for each block.

    Note:
        We call getReserves using the :meth:`~dank_mids.brownie_patch.call.DankContractCall.coroutine` method of the fetReserves DankContractMethod

    See Also:
        :meth:`dank_mids.brownie_patch.call.DankContractCall.coroutine`: The function used to asynchronously make the call via dank_mids.
    """
    return await asyncio.gather(*[pool.getReserves.coroutine(block_identifier=block) for block in blocks])

async def get_tokens_for_pool(pool: dank_mids.Contract):
    """
    Fetch token addresses for a pool using dank_mids.

    This function shows how to directly await DankContractMethods for no-arg contract calls 
    at 'latest' block. 

    Args:
        pool: The pool contract wrapped by dank_mids

    Returns:
        Tuple of token0 and token1 addresses
    """
    return await asyncio.gather(pool.token0, pool.token1)


# To batch other rpc calls, use the `dank_mids.eth` object like you would brownie's `web3.eth` object.
# This object wraps the connected brownie Web3 instance and injects the dank middleware for batching

async def get_timestamp_at_block(block: int) -> Timestamp:
    """
    Fetch the timestamp for a specific block using dank_mids.eth.

    This function demonstrates how to use dank_mids.eth for standard RPC calls,
    which will be automatically batched with other calls.
    
    It also demonstrates how to access members of multi-field responses.

    Args:
        block: The block number to fetch the timestamp for

    Returns:
        The timestamp of the block
    """
    data = await dank_mids.eth.get_block(block)
    # dank mids will turn all dict responses into attr dicts for easier key lookup
    # the syntax below will work but won't type check correctly
    not_typed = data.timestamp  # type: ignore [attr-defined]
    # the syntax below is more annoying to type out everywhere but will work with type checkers
    typed =  data['timestamp']
    return typed
