
import os
import sys

from brownie import network

sys.path.insert(0, os.path.abspath('.'))

if not network.is_connected():
    network.connect(os.environ["PYTEST_NETWORK"])
