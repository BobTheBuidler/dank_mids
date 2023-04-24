
from typing import List

from multicall.utils import get_async_w3
from web3 import Web3
from web3.providers.async_base import AsyncBaseProvider
from web3.providers.base import BaseProvider

from dank_mids.helpers._middleware import geth_poa_middleware
from dank_mids.middleware import dank_middleware

dank_w3s: List[Web3] = []

def setup_dank_w3(async_w3: Web3) -> Web3:
    """ Injects Dank Middleware into an async Web3 instance. """
    assert async_w3.eth.is_async and isinstance(async_w3.provider, AsyncBaseProvider)
    # NOTE: We use this lookup to prevent errs where 2 project dependencies both depend on dank_mids and eth-brownie.
    if async_w3 not in dank_w3s:
        async_w3.middleware_onion.inject(dank_middleware, layer=0)
        async_w3.middleware_onion.add(geth_poa_middleware)
        dank_w3s.append(async_w3)
    return async_w3

def setup_dank_w3_from_sync(sync_w3: Web3) -> Web3:
    """ Creates a new async Web3 instance from `w3.provider.endpoint_uri` and injects it with Dank Middleware. """
    assert not sync_w3.eth.is_async and isinstance(sync_w3.provider, BaseProvider)
    return setup_dank_w3(get_async_w3(sync_w3))
