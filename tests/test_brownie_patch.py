
from brownie import Contract
from dank_mids.brownie_patch import patch_contract
from dank_mids.brownie_patch.contractcall import _patch_call
from dank_mids.brownie_patch.tx import _patch_tx
from multicall.utils import await_awaitable

from tests.fixtures import dank_w3

def test_patch_call():
    # must use from_explorer for gh testing workflow
    weth = Contract.from_explorer('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2')
    _patch_call(weth.totalSupply, dank_w3)
    assert hasattr(weth.totalSupply, 'coroutine')
    assert await_awaitable(weth.totalSupply.coroutine(block_identifier=13_000_000)) == 6620041514474872981393155

# TODO implement this test once _patch_tx is implemented
#def test_patch_tx():
    # must use from_explorer for gh testing workflow
#    uni_v3_quoter = Contract.from_explorer('0xb27308f9F90D607463bb33eA1BeBb41C27CE5AB6')
#    _patch_tx(uni_v3_quoter.quoteExactInput, dank_w3)
#    assert hasattr(uni_v3_quoter.quoteExactInput, 'coroutine')
#    assert await_awaitable(uni_v3_quoter.quoteExactInput.coroutine(block_identifier=13_000_000)) == 0

def test_patch_contract():
    # ContractCall
    # must use from_explorer for gh testing workflow
    weth = patch_contract(Contract.from_explorer('0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2'), dank_w3)
    assert hasattr(weth.totalSupply, 'coroutine')
    assert await_awaitable(weth.totalSupply.coroutine(block_identifier=13_000_000)) == 6620041514474872981393155

    # ContractTx
    # TODO implement this part of the test once _patch_tx is implemented
    # must use from_explorer for gh testing workflow
    #uni_v3_quoter = patch_contract(Contract.from_explorer('0xb27308f9F90D607463bb33eA1BeBb41C27CE5AB6'), dank_w3)
    #assert hasattr(uni_v3_quoter.quoteExactInput, 'coroutine')
    #assert await_awaitable(uni_v3_quoter.quoteExactInput.coroutine(block_identifier=13_000_000)) == 0
