# sourcery skip: no-loop-in-tests
import asyncio

from brownie import Contract, web3
from multicall.utils import await_awaitable

from dank_mids import dank_web3, patch_contract, setup_dank_w3_from_sync
from dank_mids.brownie_patch.call import _patch_call


def test_patch_call():
    # must use from_explorer for gh testing workflow
    weth = Contract.from_explorer('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2')
    _patch_call(weth.totalSupply, dank_web3)
    assert hasattr(weth.totalSupply, 'coroutine')
    assert await_awaitable(weth.totalSupply.coroutine(block_identifier=13_000_000)) == 6620041514474872981393155

def test_gather():
    # must use from_explorer for gh testing workflow
    weth = Contract.from_explorer('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2')
    _patch_call(weth.totalSupply, dank_web3)
    assert hasattr(weth.totalSupply, 'coroutine')
    for result in await_awaitable(asyncio.gather(*[weth.totalSupply.coroutine(block_identifier=13_000_000) for _ in range(10_000)])):
        assert result == 6620041514474872981393155
    
def test_patch_contract():
    # ContractCall
    # must use from_explorer for gh testing workflow
    weth = patch_contract(Contract.from_explorer('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2'), dank_web3)
    assert hasattr(weth.totalSupply, 'coroutine')
    assert await_awaitable(weth.totalSupply.coroutine(block_identifier=13_000_000)) == 6620041514474872981393155

    # ContractTx
    # must use from_explorer for gh testing workflow
    uni_v3_quoter = patch_contract(Contract.from_explorer('0xb27308f9F90D607463bb33eA1BeBb41C27CE5AB6'), dank_web3)
    assert hasattr(uni_v3_quoter.quoteExactInput, 'coroutine')
    assert await_awaitable(
        uni_v3_quoter.quoteExactInput.coroutine(b"\xc0*\xaa9\xb2#\xfe\x8d\n\x0e\\O'\xea\xd9\x08<ul\xc2\x00\x01\xf4\xa0\xb8i\x91\xc6!\x8b6\xc1\xd1\x9dJ.\x9e\xb0\xce6\x06\xebH", 1e18, block_identifier=13_000_000)
    ) == 3169438072

def test_call_setup_twice_on_same_web3():
    w3_a = setup_dank_w3_from_sync(web3)
    w3_a.test = True
    w3_b = setup_dank_w3_from_sync(web3)
    assert hasattr(w3_b, 'test')
    