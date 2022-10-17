

from brownie import chain
from dank_mids import instances
from multicall import Call
from multicall.utils import await_awaitable, gather

from tests.fixtures import dank_w3

CHAI = '0x06AF07097C9Eeb7fD685c692751D5C66dB49c215'
height = chain.height
BIG_WORK = [Call(CHAI, 'totalSupply()(uint)', [[f'totalSupply{i}',None]], block_id=height - (i // 25000), _w3=dank_w3).coroutine() for i in range(100_000)]
height = chain.height
MULTIBLOCK_WORK = [Call(CHAI, 'totalSupply()(uint)', [[f'totalSupply{i}',None]], _w3=dank_w3, block_id=height-i).coroutine() for i in range(100_000)]

def test_dank_middleware():
    await_awaitable(gather(BIG_WORK))
    dank_mids_controller = instances[0]
    cid = dank_mids_controller.call_uid.latest
    mid = dank_mids_controller.worker.multicall_uid.latest
    rid = dank_mids_controller.worker.request_uid.latest
    assert cid, "The DankMiddlewareController did not process any calls."
    assert mid, "The DankMiddlewareController did not process any batches."
    assert rid, "The DankMiddlewareController did not process any requests."
    print(f"calls:                  {cid}")
    print(f"multicalls:             {mid}")
    print(f"requests:               {rid}")
    print(f"calls per multicall:    {cid/mid}")
    print(f"calls per request:      {cid/rid}")
    print(f"multicalls per request: {mid/rid}")
    # General "tests" that verify batching performance
    assert mid < cid / 100, f"Batched {cid} calls into {mid} multicalls. Performance underwhelming."
    assert rid < cid / 150,  f"Batched {cid} calls into {rid} requests. Performance underwhelming."
    assert mid / rid > 1,  f"Batched {mid} multicalls into {rid} requests. Performance underwhelming."

def test_bad_hex_handling():
    chainlinkfeed = "0xfe67209f6FE3BA6cE36d0941700085C194e958DF"
    assert await_awaitable(Call(chainlinkfeed, 'latestAnswer()(uint)', block_id=14_000_000).coroutine()) == 15717100
    assert chainlinkfeed in instances[0].do_not_batch

def test_next_cid():
    assert instances[0].call_uid.next + 1 == instances[0].call_uid.next
    
def test_next_mid():
    assert instances[0].worker.request_uid.next + 1 == instances[0].worker.request_uid.next
    
def test_next_bid():
    assert instances[0].worker.multicall_uid.next + 1 == instances[0].worker.multicall_uid.next
