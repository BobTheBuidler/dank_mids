from __future__ import annotations

from cchecksum import to_checksum_address
from multicall.constants import MULTICALL2_ADDRESSES, Network

import dank_mids.helpers._multicall as multicall_module
from dank_mids.constants import (
    MULTICALL2_DEPLOY_BLOCKS,
    MULTICALL2_OVERRIDE_CODE,
    MULTICALL3_DEPLOY_BLOCKS,
    MULTICALL3_OVERRIDE_CODE,
)


def _unknown_chainid() -> int:
    chainid = 1_000_000_000
    while multicall_module._network_for_chainid(chainid) is not None:
        chainid += 1
    return chainid


def test_network_for_chainid_returns_known_network() -> None:
    assert multicall_module._network_for_chainid(Network.Mainnet.value) is Network.Mainnet


def test_network_for_chainid_returns_none_for_unknown_chainid() -> None:
    assert multicall_module._network_for_chainid(_unknown_chainid()) is None


def test_get_multicall2_uses_network_keyed_constants() -> None:
    contract = multicall_module._get_multicall2(Network.Mainnet.value)

    assert contract is not None
    assert contract.address == to_checksum_address(MULTICALL2_ADDRESSES[Network.Mainnet])
    assert contract.deploy_block == MULTICALL2_DEPLOY_BLOCKS[Network.Mainnet]
    assert contract.bytecode == MULTICALL2_OVERRIDE_CODE


def test_get_multicall3_uses_network_keyed_constants() -> None:
    contract = multicall_module._get_multicall3(Network.Mainnet.value)

    assert contract is not None
    assert contract.address == to_checksum_address(
        multicall_module.MULTICALL3_ADDRESSES[Network.Mainnet]
    )
    assert contract.deploy_block == MULTICALL3_DEPLOY_BLOCKS[Network.Mainnet]
    assert contract.bytecode == MULTICALL3_OVERRIDE_CODE


def test_get_multicalls_return_none_for_unknown_chainid() -> None:
    chainid = _unknown_chainid()

    assert multicall_module._get_multicall2(chainid) is None
    assert multicall_module._get_multicall3(chainid) is None
