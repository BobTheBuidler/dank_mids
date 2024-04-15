# sourcery skip: no-loop-in-tests
import asyncio
import pytest

import brownie
import eth_retry
from decimal import Decimal

import dank_mids
from dank_mids.brownie_patch.call import _patch_call


# must use from_explorer for gh testing workflow
# NOTE: we don't want tests to fail due to api limits
get_contract = eth_retry.auto_retry(brownie.Contract.from_explorer)
get_dank_contract = eth_retry.auto_retry(dank_mids.Contract.from_explorer)

@pytest.mark.asyncio_cooperative
async def test_patch_call():
    # must use from_explorer for gh testing workflow
    weth = get_contract('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2')
    _patch_call(weth.totalSupply, dank_mids.web3)
    assert hasattr(weth.totalSupply, 'coroutine')
    assert await weth.totalSupply.coroutine(block_identifier=13_000_000) == 6620041514474872981393155

@pytest.mark.asyncio_cooperative
async def test_gather():
    # must use from_explorer for gh testing workflow
    weth = get_contract('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2')
    _patch_call(weth.totalSupply, dank_mids.web3)
    assert hasattr(weth.totalSupply, 'coroutine')
    for result in await asyncio.gather(*[weth.totalSupply.coroutine(block_identifier=13_000_000) for _ in range(10_000)]):
        assert result == 6620041514474872981393155
    
@pytest.mark.asyncio_cooperative
async def test_patch_contract_call():
    # specify w3
    weth = dank_mids.patch_contract(get_contract('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2'), dank_mids.web3)
    assert hasattr(weth.totalSupply, 'coroutine')
    assert await weth.totalSupply.coroutine(block_identifier=13_000_000) == 6620041514474872981393155
    assert await weth.totalSupply.coroutine(block_identifier=13_000_000, decimals=18) == Decimal("6620041.514474872981393155")

@pytest.mark.asyncio_cooperative
async def test_patch_contract_tx():
    # must use from_explorer for gh testing workflow
    # dont specify w3
    uni_v3_quoter = dank_mids.patch_contract(get_contract('0xb27308f9F90D607463bb33eA1BeBb41C27CE5AB6'))
    assert hasattr(uni_v3_quoter.quoteExactInput, 'coroutine')
    assert await (
        uni_v3_quoter.quoteExactInput.coroutine(b"\xc0*\xaa9\xb2#\xfe\x8d\n\x0e\\O'\xea\xd9\x08<ul\xc2\x00\x01\xf4\xa0\xb8i\x91\xc6!\x8b6\xc1\xd1\x9dJ.\x9e\xb0\xce6\x06\xebH", 1e18, block_identifier=13_000_000)
    ) == 3169438072
    assert await (
        uni_v3_quoter.quoteExactInput.coroutine(b"\xc0*\xaa9\xb2#\xfe\x8d\n\x0e\\O'\xea\xd9\x08<ul\xc2\x00\x01\xf4\xa0\xb8i\x91\xc6!\x8b6\xc1\xd1\x9dJ.\x9e\xb0\xce6\x06\xebH", 1e18, block_identifier=13_000_000, decimals=8)
    ) == Decimal("31.69438072")

@pytest.mark.asyncio_cooperative
async def test_dank_contract_call():
    dank_weth = get_dank_contract('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2')
    assert isinstance(dank_weth, dank_mids.Contract)
    assert isinstance(dank_weth.totalSupply, dank_mids.DankContractCall)
    assert dank_weth.totalSupply(block_identifier=13_000_000) == 6620041514474872981393155
    assert await dank_weth.totalSupply.coroutine(block_identifier=13_000_000) == 6620041514474872981393155
    assert await dank_weth.totalSupply.coroutine(block_identifier=13_000_000, decimals=18) == Decimal("6620041.514474872981393155")
    assert await dank_weth.totalSupply

@pytest.mark.asyncio_cooperative
async def test_dank_contract_tx():
    # ContractTx
    # must use from_explorer for gh testing workflow
    uni_v3_quoter = get_dank_contract('0xb27308f9F90D607463bb33eA1BeBb41C27CE5AB6')
    assert isinstance(uni_v3_quoter, dank_mids.Contract)
    assert isinstance(uni_v3_quoter.quoteExactInput, dank_mids.DankContractTx)
    assert hasattr(uni_v3_quoter.quoteExactInput, 'coroutine')
    assert (
        uni_v3_quoter.quoteExactInput.call(b"\xc0*\xaa9\xb2#\xfe\x8d\n\x0e\\O'\xea\xd9\x08<ul\xc2\x00\x01\xf4\xa0\xb8i\x91\xc6!\x8b6\xc1\xd1\x9dJ.\x9e\xb0\xce6\x06\xebH", 1e18, block_identifier=13_000_000)
    ) == 3169438072
    assert await (
        uni_v3_quoter.quoteExactInput.coroutine(b"\xc0*\xaa9\xb2#\xfe\x8d\n\x0e\\O'\xea\xd9\x08<ul\xc2\x00\x01\xf4\xa0\xb8i\x91\xc6!\x8b6\xc1\xd1\x9dJ.\x9e\xb0\xce6\x06\xebH", 1e18, block_identifier=13_000_000)
    ) == 3169438072
    assert await (
        uni_v3_quoter.quoteExactInput.coroutine(b"\xc0*\xaa9\xb2#\xfe\x8d\n\x0e\\O'\xea\xd9\x08<ul\xc2\x00\x01\xf4\xa0\xb8i\x91\xc6!\x8b6\xc1\xd1\x9dJ.\x9e\xb0\xce6\x06\xebH", 1e18, block_identifier=13_000_000, decimals=8)
    ) == Decimal("31.69438072")

def test_call_setup_twice_on_same_web3():
    w3_a = dank_mids.setup_dank_w3_from_sync(brownie.web3)
    w3_a.test = True
    w3_b = dank_mids.setup_dank_w3_from_sync(brownie.web3)
    assert hasattr(w3_b, 'test')
    