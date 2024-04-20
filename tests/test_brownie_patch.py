# sourcery skip: no-loop-in-tests
import asyncio
import pytest

import brownie
import eth_retry
from decimal import Decimal

import dank_mids
from dank_mids.brownie_patch.call import _patch_call


# NOTE: we don't want tests to fail due to api limits
get_contract = eth_retry.auto_retry(brownie.Contract)
# must try from_explorer too
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
    args = b"\xc0*\xaa9\xb2#\xfe\x8d\n\x0e\\O'\xea\xd9\x08<ul\xc2\x00\x01\xf4\xa0\xb8i\x91\xc6!\x8b6\xc1\xd1\x9dJ.\x9e\xb0\xce6\x06\xebH", 1e18
    assert uni_v3_quoter.quoteExactInput.call(*args, block_identifier=13_000_000) == 3169438072
    assert await uni_v3_quoter.quoteExactInput.coroutine(*args, block_identifier=13_000_000) == 3169438072
    assert await uni_v3_quoter.quoteExactInput.coroutine(*args, block_identifier=13_000_000, decimals=8) == Decimal("31.69438072")

def test_call_setup_twice_on_same_web3():
    w3_a = dank_mids.setup_dank_w3_from_sync(brownie.web3)
    w3_a.test = True
    w3_b = dank_mids.setup_dank_w3_from_sync(brownie.web3)
    assert hasattr(w3_b, 'test')

@pytest.mark.asyncio_cooperative
async def test_dank_overloaded_method():
    curve_factory = dank_mids.Contract.from_abi('Vyper_contract', '0xF98B45FA17DE75FB1aD0e7aFD971b0ca00e379fC', abi=_CURVE_FACTORY_ABI)
    pool = '0x9432242D9Dc10AD5e2Fe570b8FC053A16597Caf6'
    assert isinstance(curve_factory, dank_mids.Contract)
    assert isinstance(curve_factory.get_lp_token, dank_mids.DankOverloadedMethod)
    assert hasattr(curve_factory.get_lp_token, 'coroutine')
    assert len(curve_factory.get_lp_token.methods) == 2
    call = curve_factory.get_lp_token._get_fn_from_args((pool,))
    assert isinstance(call, dank_mids.DankContractCall)
    assert call(pool) == curve_factory.get_lp_token(pool) == await curve_factory.get_lp_token.coroutine(pool) == "0x9432242D9Dc10AD5e2Fe570b8FC053A16597Caf6"
    
_CURVE_FACTORY_ABI = [{"name":"CommitNewAdmin","inputs":[{"name":"deadline","type":"uint256","indexed":True},{"name":"admin","type":"address","indexed":True}],"anonymous":False,"type":"event"},{"name":"NewAdmin","inputs":[{"name":"admin","type":"address","indexed":True}],"anonymous":False,"type":"event"},{"stateMutability":"nonpayable","type":"constructor","inputs":[{"name":"_address_provider","type":"address"}],"outputs":[]},{"stateMutability":"nonpayable","type":"function","name":"add_registry_handler","inputs":[{"name":"_registry_handler","type":"address"}],"outputs":[]},{"stateMutability":"nonpayable","type":"function","name":"update_registry_handler","inputs":[{"name":"_index","type":"uint256"},{"name":"_registry_handler","type":"address"}],"outputs":[]},{"stateMutability":"view","type":"function","name":"get_registry_handlers_from_pool","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"address[10]"}]},{"stateMutability":"view","type":"function","name":"get_base_registry","inputs":[{"name":"registry_handler","type":"address"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"find_pool_for_coins","inputs":[{"name":"_from","type":"address"},{"name":"_to","type":"address"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"find_pool_for_coins","inputs":[{"name":"_from","type":"address"},{"name":"_to","type":"address"},{"name":"i","type":"uint256"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"find_pools_for_coins","inputs":[{"name":"_from","type":"address"},{"name":"_to","type":"address"}],"outputs":[{"name":"","type":"address[]"}]},{"stateMutability":"view","type":"function","name":"get_admin_balances","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_admin_balances","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_balances","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_balances","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_base_pool","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_base_pool","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_coin_indices","inputs":[{"name":"_pool","type":"address"},{"name":"_from","type":"address"},{"name":"_to","type":"address"}],"outputs":[{"name":"","type":"int128"},{"name":"","type":"int128"},{"name":"","type":"bool"}]},{"stateMutability":"view","type":"function","name":"get_coin_indices","inputs":[{"name":"_pool","type":"address"},{"name":"_from","type":"address"},{"name":"_to","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"int128"},{"name":"","type":"int128"},{"name":"","type":"bool"}]},{"stateMutability":"view","type":"function","name":"get_coins","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"address[8]"}]},{"stateMutability":"view","type":"function","name":"get_coins","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"address[8]"}]},{"stateMutability":"view","type":"function","name":"get_decimals","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_decimals","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_fees","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256[10]"}]},{"stateMutability":"view","type":"function","name":"get_fees","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256[10]"}]},{"stateMutability":"view","type":"function","name":"get_gauge","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_gauge","inputs":[{"name":"_pool","type":"address"},{"name":"gauge_idx","type":"uint256"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_gauge","inputs":[{"name":"_pool","type":"address"},{"name":"gauge_idx","type":"uint256"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_gauge_type","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"int128"}]},{"stateMutability":"view","type":"function","name":"get_gauge_type","inputs":[{"name":"_pool","type":"address"},{"name":"gauge_idx","type":"uint256"}],"outputs":[{"name":"","type":"int128"}]},{"stateMutability":"view","type":"function","name":"get_gauge_type","inputs":[{"name":"_pool","type":"address"},{"name":"gauge_idx","type":"uint256"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"int128"}]},{"stateMutability":"view","type":"function","name":"get_lp_token","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_lp_token","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_n_coins","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"get_n_coins","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"get_n_underlying_coins","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"get_n_underlying_coins","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"get_pool_asset_type","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"get_pool_asset_type","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"get_pool_from_lp_token","inputs":[{"name":"_token","type":"address"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_pool_from_lp_token","inputs":[{"name":"_token","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_pool_params","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256[20]"}]},{"stateMutability":"view","type":"function","name":"get_pool_params","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256[20]"}]},{"stateMutability":"view","type":"function","name":"get_pool_name","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"string"}]},{"stateMutability":"view","type":"function","name":"get_pool_name","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"string"}]},{"stateMutability":"view","type":"function","name":"get_underlying_balances","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_underlying_balances","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_underlying_coins","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"address[8]"}]},{"stateMutability":"view","type":"function","name":"get_underlying_coins","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"address[8]"}]},{"stateMutability":"view","type":"function","name":"get_underlying_decimals","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_underlying_decimals","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256[8]"}]},{"stateMutability":"view","type":"function","name":"get_virtual_price_from_lp_token","inputs":[{"name":"_token","type":"address"}],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"get_virtual_price_from_lp_token","inputs":[{"name":"_token","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"is_meta","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"bool"}]},{"stateMutability":"view","type":"function","name":"is_meta","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"bool"}]},{"stateMutability":"view","type":"function","name":"is_registered","inputs":[{"name":"_pool","type":"address"}],"outputs":[{"name":"","type":"bool"}]},{"stateMutability":"view","type":"function","name":"is_registered","inputs":[{"name":"_pool","type":"address"},{"name":"_handler_id","type":"uint256"}],"outputs":[{"name":"","type":"bool"}]},{"stateMutability":"view","type":"function","name":"pool_count","inputs":[],"outputs":[{"name":"","type":"uint256"}]},{"stateMutability":"view","type":"function","name":"pool_list","inputs":[{"name":"_index","type":"uint256"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"address_provider","inputs":[],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"owner","inputs":[],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"get_registry","inputs":[{"name":"arg0","type":"uint256"}],"outputs":[{"name":"","type":"address"}]},{"stateMutability":"view","type":"function","name":"registry_length","inputs":[],"outputs":[{"name":"","type":"uint256"}]}]
