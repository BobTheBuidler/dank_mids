# type: ignore
"""
This example demonstrates how to use dank_mids with Brownie for efficient blockchain data retrieval.

The following code will send just one HTTP request to your node.

dank_mids integrates seamlessly with Brownie, allowing for batched and optimized RPC calls.
This can significantly improve performance when fetching large amounts of data from the blockchain.

Key features of dank_mids Brownie integration:
1. Automatic batching of eth_call operations into multicalls
2. Asynchronous execution of RPC calls
3. Easy-to-use interface that mimics standard Brownie patterns

Take note of the liberal use of `asyncio.gather`; this is how you ensure that all of the various parts of your code 
are running concurrently so that batching is possible.

See Also:
    :func:`get_tokens_for_pool`, :func:`get_timestamp_at_block`, and :func:`get_balances_for_blocks`
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
    """The main entry point of this example script.

    This function sets up the asyncio event loop and executes the asynchronous
    :func:`_main` function to demonstrate the use of dank_mids with Brownie.
    """
    asyncio.run(_main())


async def _main() -> None:
    """Demonstrate the usage of Dank Mids with Brownie by concurrently fetching token addresses,
    block timestamps, and balance (reserve) information.

    This coroutine proceeds with the following steps:
      1. Convert a list of Uniswap pool addresses into dank_mids :class:`Contract` objects.
      2. Concurrently fetch:
         - the token addresses (token0 and token1) for each pool at the 'latest' block,
         - the timestamp for each specified block,
         - and the balance (reserve) information for each pool at each specified block.
      3. Process the outputs concurrently using ``asyncio.gather``.
      4. Iterate over the results using separate loops for tokens, timestamps, and balances.

    Examples:
        >>> await _main()
        >>> # Iterate over fetched token addresses for each pool:
        >>> for pool, (token0, token1) in zip(dank_pool_contracts, tokens):
        ...     await do_stuff(pool, token0, token1)
        >>>
        >>> # Iterate over fetched timestamps for each block:
        >>> for block, timestamp in zip(blocks, timestamps):
        ...     await do_stuff(block, timestamp)
        >>>
        >>> # Iterate over fetched balance information for each pool:
        >>> for pool, pool_balances in zip(dank_pool_contracts, balances):
        ...     for balance, block in zip(pool_balances, blocks):
        ...         await do_stuff(pool, balance, block)

    See Also:
        :func:`get_tokens_for_pool`, :func:`get_timestamp_at_block`, :func:`get_balances_for_blocks`
    """
    # Initialize the pools as `dank_mids.Contract` objects.
    dank_pool_contracts = tuple(map(dank_mids.Contract, uniswap_pools))

    # Use `asyncio.gather` to collect the data from the various pools and blocks and store them in variables.
    tokens, timestamps, balances = await asyncio.gather(
        asyncio.gather(*(get_tokens_for_pool(pool) for pool in dank_pool_contracts)),
        asyncio.gather(*(get_timestamp_at_block(block) for block in blocks)),
        asyncio.gather(*(get_balances_for_blocks(pool, blocks) for pool in dank_pool_contracts)),
    )
    # Now we can do stuff with the outputs
    for pool, (token0, token1) in zip(dank_pool_contracts, tokens):
        """await do_stuff(pool, token0, token1)"""
    for block, timestamp in zip(blocks, timestamps):
        """await do_stuff(block, timestamp)"""
    for pool, pool_balances in zip(dank_pool_contracts, balances):
        for balance, block in zip(pool_balances, blocks):
            """await do_stuff(pool, balance, block)"""


# Functions that we used to get the data from the pools and blocks:
async def get_balances_for_blocks(pool: dank_mids.Contract, blocks: List[int]):
    """Fetch balances for a pool across multiple blocks.

    This function asynchronously fetches balance (reserve) information for the
    specified pool contract at each block number in the provided list by calling
    the pool’s ``getReserves.coroutine`` method.

    Args:
        pool: The pool contract instance wrapped by dank_mids.
        blocks: A list of block numbers where the balances should be fetched.

    Returns:
        A list of tuples, each containing the balance (reserve) data for a block.

    Note:
        This function uses the :meth:`~dank_mids.brownie_patch.call.DankContractCall.coroutine`
        method to perform the asynchronous RPC call to ``getReserves``.

    Example:
        >>> # Assume `pool` is a dank_mids.Contract instance representing a liquidity pool.
        >>> blocks = [15000000, 15001000, 15002000]
        >>> balances = await get_balances_for_blocks(pool, blocks)
        >>> for reserve in balances:
        ...     print(reserve)

    See Also:
        :meth:`dank_mids.brownie_patch.call.DankContractCall.coroutine`
    """
    return await asyncio.gather(
        *(pool.getReserves.coroutine(block_identifier=block) for block in blocks)
    )


async def get_tokens_for_pool(pool: dank_mids.Contract):
    """Fetch token addresses for a pool using dank_mids.

    This function demonstrates how to directly await DankContractMethods for no-argument contract calls
    at the 'latest' block.

    Args:
        pool: The pool contract wrapped by dank_mids.

    Returns:
        A tuple containing token0 and token1 addresses.

    Example:
        >>> token0, token1 = await get_tokens_for_pool(pool)
        >>> print(token0, token1)

    See Also:
        :meth:`dank_mids.brownie_patch.call.DankContractCall.coroutine`
    """
    return await asyncio.gather(pool.token0, pool.token1)


# To batch other RPC calls, use the `dank_mids.eth` object like you would brownie's `web3.eth` object.
# This object wraps the connected brownie Web3 instance and injects the dank middleware for batching


async def get_timestamp_at_block(block: int) -> Timestamp:
    """Fetch the timestamp for a specific block using dank_mids.eth.

    This function demonstrates how to use dank_mids.eth for standard RPC calls,
    which will be automatically batched with other calls.

    It also demonstrates how to access members of multi-field responses. It accesses the `timestamp`
    field from the decoded block response.

    Args:
        block: The block number to fetch the timestamp for.

    Returns:
        The timestamp of the block.

    Example:
        >>> timestamp = await get_timestamp_at_block(15000000)
        >>> print(timestamp)

    See Also:
        :meth:`dank_mids.eth.get_block`
    """
    data = await dank_mids.eth.get_block(block)
    # dank mids decodes responses into evmspec Struct objects for convenient access and mypy support
    typed = data.timestamp
    # the syntax below will still work for compatibility with legacy tools
    not_typed = data["timestamp"]
    return typed
