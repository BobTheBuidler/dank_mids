
import os
import sys

import brownie
from brownie import network
from dotenv import load_dotenv


if "CI" not in os.environ:
    # running locally (not in github actions)
    load_dotenv()

sys.path.insert(0, os.path.abspath('.'))

brownie._CONFIG.settings['autofetch_sources'] = True

if not network.is_connected():
    network.connect(os.getenv("PYTEST_NETWORK"))
