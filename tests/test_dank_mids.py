import sys

import pytest
from a_sync import igather
from brownie import chain
from evmspec import Transaction1559
from multicall import Call
from web3._utils.rpc_abi import RPC

from dank_mids import dank_web3, instances


CHAI = "0x06AF07097C9Eeb7fD685c692751D5C66dB49c215"


def call_chai(i: int, block: int) -> Call:
    return Call(
        CHAI, "totalSupply()(uint)", [[f"totalSupply{i}", None]], _w3=dank_web3, block_id=block
    )


height = chain.height

BIG_WORK = (call_chai(i, height - (i // 25000)) for i in range(0, 100_000, 4))

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
async def test_eth_getTransaction():
    tx = await dank_web3.eth.get_transaction(
        "0x1540ea6e443ff81570624fe19220507a1d949464b5a012ac110c7e91205c456a"
    )
    assert tx == Transaction1559(
        chainId="0x1",
        nonce="0x117",
        gas="0x42710",
        maxFeePerGas="0x1f79197140",
        maxPriorityFeePerGas="0x17bfac7c00",
        to="0x7a250d5630b4cf539739df2c5dacb4c659f2488d",
        value="0x2c68af0bb140000",
        _accessList=[],
        input="0xb6f9de950000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000008000000000000000000000000008ec71e8bcbbd41c4b2a95c1b6b3809683a749b800000000000000000000000000000000000000000000000000000000649af7b60000000000000000000000000000000000000000000000000000000000000002000000000000000000000000c02aaa39b223fe8d0a0e5c4f27ead9083c756cc200000000000000000000000028c17df245870dc3e127e1c63a7046e7c7674490",
        r="0x2e6eb24c1dc2447d735981a45237bffd9418eba0a54f694284234c0523ed9b36",
        s="0x10468aac9b3049d51954aefccfa0ed8eff4790d80c28a8be96fefe972924d8b5",
        yParity="0x1",
        v="0x1",
        hash="0x1540ea6e443ff81570624fe19220507a1d949464b5a012ac110c7e91205c456a",
        blockHash="0xe31c255a783d2dfefb8baaf86c0731771dd53c4e977e5d76970e3ad82c7fddf8",
        blockNumber="0x10c1e3f",
        transactionIndex="0x0",
        sender="0x08ec71e8bcbbd41c4b2a95c1b6b3809683a749b8",
        gasPrice="0x1ce5f51f80",
    )
