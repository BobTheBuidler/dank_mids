import pytest

import examples.dank_brownie_example
from dank_mids.brownie_patch.contract import retry_etherscan


@pytest.mark.asyncio_cooperative
@retry_etherscan
async def test_dank_brownie_example():
    await examples.dank_brownie_example._main()
