

from brownie import chain
from dank_mids import instances
from multicall import Call
from multicall.utils import await_awaitable, gather
from web3._utils.rpc_abi import RPC

from tests.fixtures import dank_w3

CHAI = '0x06AF07097C9Eeb7fD685c692751D5C66dB49c215'
height = chain.height
BIG_WORK = [Call(CHAI, 'totalSupply()(uint)', [[f'totalSupply{i}',None]], block_id=height - (i // 25000), _w3=dank_w3).coroutine() for i in range(100_000)]
height = chain.height
MULTIBLOCK_WORK = [Call(CHAI, 'totalSupply()(uint)', [[f'totalSupply{i}',None]], _w3=dank_w3, block_id=height-i).coroutine() for i in range(100_000)]


def _get_controller():
    return instances[chain.id][0]

def test_dank_middleware():
    await_awaitable(gather(BIG_WORK))
    cid = _get_controller().call_uid.latest
    mid = _get_controller().multicall_uid.latest
    rid = _get_controller().request_uid.latest
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
    assert chainlinkfeed in _get_controller().no_multicall

def test_json_batch():
    await_awaitable(gather(MULTIBLOCK_WORK))

def test_next_cid():
    assert _get_controller().call_uid.next + 1 == _get_controller().call_uid.next
    
def test_next_mid():
    assert _get_controller().request_uid.next + 1 == _get_controller().request_uid.next
    
def test_next_bid():
    assert _get_controller().multicall_uid.next + 1 == _get_controller().multicall_uid.next

def test_other_methods():
    work = [dank_w3.eth.get_block_number() for i in range(50)]
    work.append(dank_w3.eth.get_block('0xe25822'))
    work.append(dank_w3.manager.coro_request(RPC.web3_clientVersion, []))
    assert await_awaitable(gather(work))

def test_AttributeDict():
    block = await_awaitable(dank_w3.eth.get_block("0xe25822"))
    assert block['timestamp']
    assert block.timestamp
