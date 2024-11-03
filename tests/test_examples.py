import eth_retry
import pytest

import examples.dank_brownie_example


@pytest.mark.asyncio_cooperative
@eth_retry.auto_retry  # retry etherscan rate limit errors
async def test_dank_brownie_example():
    await examples.dank_brownie_example._main()
