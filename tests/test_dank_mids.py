
import logging

from brownie import chain
from dank_mids import instances
from dank_mids.loggers import demo_logger
from multicall import Call
from multicall.utils import await_awaitable, gather

from tests.fixtures import dank_w3

demo_logger.addHandler(logging.StreamHandler())
demo_logger.setLevel(logging.DEBUG)

CHAI = '0x06AF07097C9Eeb7fD685c692751D5C66dB49c215'
BIG_WORK = [Call(CHAI, 'totalSupply()(uint)', [[f'totalSupply{i}',None]],_w3=dank_w3).coroutine() for i in range(100_000)]

def test_dank_middleware():
    await_awaitable(gather(BIG_WORK))
    dank_mids_controller = instances[0]
    cid = dank_mids_controller.call_uid.latest
    bid = dank_mids_controller.worker.batch_uid.latest
    mid = dank_mids_controller.worker.multicall_uid.latest
    assert cid, "The DankMiddlewareController did not process any calls."
    assert bid, "The DankMiddlewareController did not process any batches."
    assert mid, "The DankMiddlewareController did not process any multicalls."
    print(f"calls:             {cid}")
    print(f"multicalls:        {mid}")
    print(f"batches:           {bid}")
    print(f"calls per batch:   {cid/bid}")
    print(f"calls per multi:   {cid/mid}")
    print(f"multis per batch:  {mid/bid}")
    # General "tests" that verify batching performance
    assert bid < cid / 10, f"Batched {cid} calls into {bid} batches. Performance underwhelming."
    assert mid < cid / 5,  f"Batched {cid} calls into {mid} multicalls. Performance underwhelming."
    assert bid < mid / 2,  f"{bid} batches required {mid} multicalls. Performance underwhelming."

def test_bad_hex_handling():
    chainlinkfeed = "0xfe67209f6FE3BA6cE36d0941700085C194e958DF"
    assert await_awaitable(Call(chainlinkfeed, 'latestAnswer()(uint)', block_id=14_000_000).coroutine()) == 15717100
    assert chainlinkfeed in instances[0].DO_NOT_BATCH

def test_next_cid():
    assert instances[0].call_uid.next + 1 == instances[0].call_uid.next
    
def test_next_mid():
    assert instances[0].worker.multicall_uid.next + 1 == instances[0].worker.multicall_uid.next
    
def test_next_bid():
    assert instances[0].worker.batch_uid.next + 1 == instances[0].worker.batch_uid.next
