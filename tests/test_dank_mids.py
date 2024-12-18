import sys
from asyncio import gather

import pytest
from brownie import chain
from dank_mids import dank_web3, instances
from multicall import Call
from web3._utils.rpc_abi import RPC

CHAI = "0x06AF07097C9Eeb7fD685c692751D5C66dB49c215"
height = chain.height
BIG_WORK = [
    Call(
        CHAI,
        "totalSupply()(uint)",
        [[f"totalSupply{i}", None]],
        block_id=height - (i // 25000),
        _w3=dank_web3,
    ).coroutine()
    for i in range(0, 100_000, 3)
]

height = chain.height
MULTIBLOCK_WORK = [
    Call(
        CHAI, "totalSupply()(uint)", [[f"totalSupply{i}", None]], _w3=dank_web3, block_id=height - i
    )
    for i in range(1_000)
]


@pytest.mark.asyncio_cooperative
async def test_dank_middleware():
    await gather(*BIG_WORK)
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
    await gather(*MULTIBLOCK_WORK)


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
    results = await gather(*work)
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
