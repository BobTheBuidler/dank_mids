
using with brownie:
`
from brownie import Contract, web3
from dank_mids.brownie_patch import patch_contract
from dank_mids import setup_dank_w3_from_sync

dank_w3 = setup_dank_w3_from_sync(web3)
weth = patch_contract(Contract(0x1234), dank_w3)
total_supply = await weth.totalSupply.coroutine(block_identifier=12345)
`

using with web3py:
`
I'll add this later
`

using with multicall:
`
I'll add this later
`
