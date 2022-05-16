
from multicall.utils import get_async_w3
from web3 import Web3
from web3.providers.async_base import AsyncBaseProvider
from web3.providers.base import BaseProvider

from dank_mids.middleware import dank_middleware


def setup_dank_w3(async_w3: Web3) -> None:
    """ Injects Dank Middleware into an async Web3 instance. """
    assert async_w3.eth.is_async and isinstance(async_w3.provider, AsyncBaseProvider)
    async_w3.middleware_onion.inject(dank_middleware, layer=0)
    return async_w3

def setup_dank_w3_from_sync(sync_w3: Web3) -> Web3:
    """ Creates a new async Web3 instance from `w3.provider.endpoint_uri` and injects it with Dank Middleware. """
    assert not sync_w3.eth.is_async and isinstance(sync_w3.provider, BaseProvider)
    return setup_dank_w3(get_async_w3(sync_w3))
