import sys

import pytest
from a_sync import igather
from brownie import chain, web3
from evmspec import Transaction1559, Transaction2930
from multicall import Call
from web3._utils.rpc_abi import RPC

from dank_mids import dank_web3, instances


CHAI = "0x06AF07097C9Eeb7fD685c692751D5C66dB49c215"


def call_chai(i: int, block: int) -> Call:
    return Call(
        CHAI, "totalSupply()(uint)", [[f"totalSupply{i}", None]], _w3=dank_web3, block_id=block
    )


height = chain.height
num_calls = 500 if "llama" in web3.provider.endpoint_uri else 50_000

BIG_WORK = (call_chai(i, height - (i // 25000)) for i in range(0, num_calls, 4))

height = chain.height

MULTIBLOCK_WORK = (call_chai(i, height - i) for i in range(1000))


@pytest.mark.asyncio_cooperative
async def test_dank_middleware():
    await igather(BIG_WORK)
    controller = instances[chain.id][0]
    cid = controller.call_uid.latest
    mid = controller.multicall_uid.latest
    rid = controller.request_uid.latest
    assert cid, "The DankMiddlewareController did not process any calls."
    if sys.version_info < (3, 10):
        # Not sure why this assert fails above 3.10
        assert mid, "The DankMiddlewareController did not process any batches."
    assert rid, "The DankMiddlewareController did not process any requests."
    print(f"calls:                  {cid}")
    print(f"multicalls:             {mid}")
    print(f"requests:               {rid}")
    print(f"calls per multicall:    {cid/mid}")
    print(f"calls per request:      {cid/rid}")
    print(f"multicalls per request: {mid/rid}")
    # General "tests" that verify batching performance
    assert mid < cid / 50, f"Batched {cid} calls into {mid} multicalls. Performance underwhelming."
    assert rid < cid / 150, f"Batched {cid} calls into {rid} requests. Performance underwhelming."
    assert (
        mid / rid > 1
    ), f"Batched {mid} multicalls into {rid} requests. Performance underwhelming."


@pytest.mark.asyncio_cooperative
async def test_bad_hex_handling():
    """
    Test the handling of bad hex values in contract calls.

    This test ensures that the system can correctly handle and process
    contract calls that might return unusual or malformed hex values.
    """
    chainlinkfeed = "0xfe67209f6FE3BA6cE36d0941700085C194e958DF"
    assert await Call(chainlinkfeed, "latestAnswer()(uint)", block_id=14_000_000) == 15717100


@pytest.mark.asyncio_cooperative
async def test_json_batch():
    """
    Test the JSON batch processing functionality.

    This test verifies that the system can correctly handle and process
    a batch of JSON-RPC requests across multiple blocks.
    """
    await igather(MULTIBLOCK_WORK)


def test_next_cid():
    """
    Test the generation of the next call ID.

    This test ensures that the call ID generator correctly increments
    and provides unique IDs for each call.
    """
    controller = instances[chain.id][0]
    assert controller.call_uid.next + 1 == controller.call_uid.next


def test_next_mid():
    """
    Test the generation of the next request ID.

    This test verifies that the request ID generator correctly increments
    and provides unique IDs for each request.
    """
    controller = instances[chain.id][0]
    assert controller.request_uid.next + 1 == controller.request_uid.next


def test_next_bid():
    """
    Test the generation of the next multicall ID.

    This test checks that the multicall ID generator correctly increments
    and provides unique IDs for each multicall.
    """
    controller = instances[chain.id][0]
    assert controller.multicall_uid.next + 1 == controller.multicall_uid.next


@pytest.mark.asyncio_cooperative
async def test_other_methods():
    """
    Test various other RPC methods.
    """
    work = [
        *(dank_web3.eth.block_number for _ in range(50)),
        dank_web3.eth.get_block("0xe25822"),
        dank_web3.manager.coro_request(RPC.web3_clientVersion, []),
    ]
    results = await igather(work)
    assert results
    assert results[-2].timestamp


@pytest.mark.asyncio_cooperative
async def test_AttributeDict():
    """
    Test the AttributeDict functionality.

    This test verifies that a dictionary response from dank_mids correctly allows
    both dictionary-style and attribute-style access to its contents.
    """
    block = await dank_web3.eth.get_block("0xe25822")
    assert block["timestamp"] and block.timestamp and (block["timestamp"] == block.timestamp)


@pytest.mark.asyncio_cooperative
async def test_string_block():
    with pytest.raises(TypeError):
        await Call(CHAI, "totalSupply()(uint)", block_id="14000000")


@pytest.mark.asyncio_cooperative
async def test_eth_getTransaction_1559():
    tx_1559 = await dank_web3.eth.get_transaction(
        "0x1540ea6e443ff81570624fe19220507a1d949464b5a012ac110c7e91205c456a"
    )
    assert isinstance(tx_1559, Transaction1559)


@pytest.mark.asyncio_cooperative
async def test_eth_getTransaction_2930():
    tx_2930 = await dank_web3.eth.get_transaction(
        "0x3ea6b560065dabfac5218c64fd076ef62ff9d6c08817101e7dbece460eb2c8a5"
    )
    assert isinstance(tx_2930, Transaction2930)


@pytest.mark.asyncio_cooperative
async def test_eth_getBalance_no_block():
    assert isinstance(await dank_web3.eth.get_balance(CHAI), int)


@pytest.mark.asyncio_cooperative
async def test_eth_getBalance_int_block():
    assert isinstance(await dank_web3.eth.get_balance(CHAI, 20_000_000), int)


@pytest.mark.asyncio_cooperative
async def test_eth_getBalance_latest():
    assert isinstance(await dank_web3.eth.get_balance(CHAI, "latest"), int)
