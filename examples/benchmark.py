import asyncio
from collections import defaultdict
from datetime import datetime

import brownie
from tqdm import tqdm

import dank_mids


brownie.config["autofetch_sources"] = True


UNISWAPV2_FACTORY = dank_mids.Contract.from_explorer("0xC0AEe478e3658e2610c5F7A4A2E1777cE9e4f2Ac")


# load the brownie contracts into memory now so we don't pollute the benchmark with irrelevant things, like reading from a sqlite db.
pool_addresses = asyncio.get_event_loop().run_until_complete(
    UNISWAPV2_FACTORY.allPairs.map(range(UNISWAPV2_FACTORY.allPairsLength()))
)
pools = list(map(dank_mids.Contract, tqdm(pool_addresses, desc="loading required contracts...")))


def web3py_sync():
    pools_by_token = defaultdict(list)

    start = datetime.now()
    print(f"brownie sync start: {start}")
    for pool in tqdm(pools):
        pools_by_token[pool.token0()].append(pool)
        pools_by_token[pool.token1()].append(pool)
    end = datetime.now()
    print(f"brownie sync end: {end}")
    duration = end - start
    print(f"brownie sync took: {duration}")


from joblib import Parallel, delayed


def web3py_threads(num_threads: int):
    pools_by_token = defaultdict(list)

    @delayed
    def process_pool(pool_contract: dank_mids.Contract) -> None:
        pools_by_token[pool_contract.token0()].append(pool_contract)
        pools_by_token[pool_contract.token1()].append(pool_contract)

    start = datetime.now()
    print(f"brownie {num_threads} threads start: {start}")
    Parallel(num_threads, "threading")(map(process_pool, tqdm(pools)))
    end = datetime.now()
    print(f"brownie {num_threads} threads end: {end}")
    duration = end - start
    print(f"brownie {num_threads} threads took: {duration}")


from tqdm.asyncio import tqdm_asyncio


async def dank():
    pools_by_token = defaultdict(list)

    async def process_pool(pool_contract: dank_mids.Contract) -> None:
        token0, token1 = await asyncio.gather(pool_contract.token0, pool_contract.token1)
        pools_by_token[token0].append(pool_contract)
        pools_by_token[token1].append(pool_contract)

    start = datetime.now()
    print(f"dank start: {start}")
    await tqdm_asyncio.gather(*map(process_pool, pools))
    end = datetime.now()
    print(f"dank end: {end}")
    duration = end - start
    print(f"dank took: {duration}")


def main():
    web3py_sync()
    web3py_threads(4)
    web3py_threads(16)
    asyncio.run(dank())
