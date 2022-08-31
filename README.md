Dank Mids automatically collects your async `eth_call`s and batch them into multicalls in the background.

Now also supports jsonrpc batching for batching across multiple blocks.
<hr>
You only need to know one thing to use Dank Mids - `setup_dank_w3_from_sync`.

Use `setup_dank_w3_from_sync` to wrap a sync Web3 instance for async use.

Brownie's `web3` object, for example, is a sync Web3 instance. You can patch brownie Contracts with `patch_contract` for use with Dank Mids.
<hr>

using with brownie:
```
from brownie import Contract, web3
from dank_mids.brownie_patch import patch_contract
from dank_mids import setup_dank_w3_from_sync

dank_w3 = setup_dank_w3_from_sync(web3)
weth = patch_contract(Contract(0x1234), dank_w3)
total_supply = await weth.totalSupply.coroutine(block_identifier=12345)
```

using with web3py:
```
from dank_mids import setup_dank_w3_from_sync
dank_w3 = setup_dank_w3_from_sync(w3)
random_block = await dank_w3.eth.get_block(123)
```

COMING SOON:
using with ape
