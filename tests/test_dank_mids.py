
import asyncio
import importlib
import pytest
import sys
from brownie import chain
from multicall import Call
from web3._utils.rpc_abi import RPC

from dank_mids import dank_web3, instances

CHAI = '0x06AF07097C9Eeb7fD685c692751D5C66dB49c215'
height = chain.height
BIG_WORK = [Call(CHAI, 'totalSupply()(uint)', [[f'totalSupply{i}',None]], block_id=height - (i // 25000), _w3=dank_web3).coroutine() for i in range(100_000)]
height = chain.height
MULTIBLOCK_WORK = [Call(CHAI, 'totalSupply()(uint)', [[f'totalSupply{i}',None]], _w3=dank_web3, block_id=height-i).coroutine() for i in range(1_000)]


def _get_controller():
    brownie_version = tuple(int(x) for x in importlib.metadata.version('eth-brownie').split('.'))
    if brownie_version >= (1, 20):
        # Not sure why but 1.20 creates 2 instances
        return instances[chain.id][1]
    return instances[chain.id][0]

@pytest.mark.asyncio_cooperative
async def test_dank_middleware():
    await asyncio.gather(*BIG_WORK)
    cid = _get_controller().call_uid.latest
    mid = _get_controller().multicall_uid.latest
    rid = _get_controller().request_uid.latest
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
    assert rid < cid / 150,  f"Batched {cid} calls into {rid} requests. Performance underwhelming."
    assert mid / rid > 1,  f"Batched {mid} multicalls into {rid} requests. Performance underwhelming."

@pytest.mark.asyncio_cooperative
async def test_bad_hex_handling():
    chainlinkfeed = "0xfe67209f6FE3BA6cE36d0941700085C194e958DF"
    assert await Call(chainlinkfeed, 'latestAnswer()(uint)', block_id=14_000_000) == 15717100

@pytest.mark.asyncio_cooperative
async def test_json_batch():
    await asyncio.gather(*MULTIBLOCK_WORK)

def test_next_cid():
    assert _get_controller().call_uid.next + 1 == _get_controller().call_uid.next
    
def test_next_mid():
    assert _get_controller().request_uid.next + 1 == _get_controller().request_uid.next
    
def test_next_bid():
    assert _get_controller().multicall_uid.next + 1 == _get_controller().multicall_uid.next

@pytest.mark.asyncio_cooperative
async def test_other_methods():
    work = [dank_web3.eth.block_number for i in range(50)]
    work.append(dank_web3.eth.get_block('0xe25822'))
    work.append(dank_web3.manager.coro_request(RPC.web3_clientVersion, []))
    results = await asyncio.gather(*work)
    assert results
    assert results[-2].timestamp

@pytest.mark.asyncio_cooperative
async def test_AttributeDict():
    block = await dank_web3.eth.get_block("0xe25822")
    assert block['timestamp'] and block.timestamp and (block['timestamp'] == block.timestamp)

@pytest.mark.asyncio_cooperative
async def test_string_block():
    with pytest.raises(TypeError):
        await Call(CHAI, 'totalSupply()(uint)', block_id="14000000")
