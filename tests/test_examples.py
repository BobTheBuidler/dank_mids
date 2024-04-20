
import pytest

import examples.dank_brownie_example

@pytest.mark.asyncio_cooperative
async def test_dank_brownie_example():
    await examples.dank_brownie_example._main()
