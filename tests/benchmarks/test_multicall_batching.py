import pytest
from a_sync import igather
from brownie import chain, web3
from multicall import Call

from dank_mids import dank_web3

CHAI = "0x06AF07097C9Eeb7fD685c692751D5C66dB49c215"


def call_chai(i: int, block: int) -> Call:
    return Call(
        CHAI, "totalSupply()(uint)", [[f"totalSupply{i}", None]], _w3=dank_web3, block_id=block
    )


@pytest.mark.benchmark
@pytest.mark.asyncio_cooperative
async def test_batch_multicall_performance():
    """Benchmark batching performance of dank_mids middleware."""
    height = chain.height
    num_calls = 500 if "llama" in web3.provider.endpoint_uri else 10_000
    
    work = (call_chai(i, height - (i // 25000)) for i in range(0, num_calls, 4))
    await igather(work)


@pytest.mark.benchmark
@pytest.mark.asyncio_cooperative
async def test_multiblock_batch_performance():
    """Benchmark batching performance across multiple blocks."""
    height = chain.height
    work = (call_chai(i, height - i) for i in range(500))
    await igather(work)


@pytest.mark.benchmark
@pytest.mark.asyncio_cooperative
async def test_eth_methods_performance():
    """Benchmark various eth_* RPC methods."""
    work = [
        *(dank_web3.eth.block_number for _ in range(50)),
        dank_web3.eth.get_block("0xe25822"),
    ]
    await igather(work)


@pytest.mark.benchmark
@pytest.mark.asyncio_cooperative
async def test_contract_call_performance():
    """Benchmark single contract calls."""
    chainlinkfeed = "0xfe67209f6FE3BA6cE36d0941700085C194e958DF"
    result = await Call(chainlinkfeed, "latestAnswer()(uint)", block_id=14_000_000)
    assert result == 15717100


@pytest.mark.benchmark
@pytest.mark.asyncio_cooperative
async def test_eth_getBalance_performance():
    """Benchmark eth_getBalance calls."""
    work = [
        dank_web3.eth.get_balance(CHAI),
        dank_web3.eth.get_balance(CHAI, 20_000_000),
        dank_web3.eth.get_balance(CHAI, "latest"),
    ]
    await igather(work)


@pytest.mark.benchmark
@pytest.mark.asyncio_cooperative
async def test_eth_getCode_performance():
    """Benchmark eth_getCode calls."""
    work = [
        dank_web3.eth.get_code(CHAI),
        dank_web3.eth.get_code(CHAI, 20_000_000),
        dank_web3.eth.get_code(CHAI, "latest"),
    ]
    await igather(work)
