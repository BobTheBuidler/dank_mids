
import os
import sys

import brownie
from brownie import network

sys.path.insert(0, os.path.abspath('.'))

brownie._CONFIG.settings['autofetch_sources'] = True

if not network.is_connected():
    network.connect(os.environ["PYTEST_NETWORK"])
