
import pytest

import brownie
import eth_retry

import examples.dank_brownie_example


@pytest.mark.asyncio_cooperative
@eth_retry.auto_retry  # retry etherscan rate limit errors
async def test_dank_brownie_example():
    with pytest.raises(ValueError):
        await examples.dank_brownie_example._main()
    brownie._CONFIG.settings['autofetch_sources'] = True
    await examples.dank_brownie_example._main()
