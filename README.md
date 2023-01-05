# Dank Mids

Dank Mids is a EVM RPC batching library that helps reduce the number of HTTP requests to a node, saving time and resources. It automatically collects eth_call calls into multicalls and bundles all RPC calls together in jsonrpc batch calls.

The goal of this tool is to reduce the workload on RPC nodes and allow users to make calls to their preferred node more efficiently. This optimization is especially useful for developers writing scripts that make multiple calls to blockchain networks, as it can save development time and resources.

### Installation

To install Dank Mids, use pip:

`pip install dank-mids`

### Usage with web3.py

The primary function you need to use Dank Mids is `setup_dank_w3_from_sync`. This function takes a sync Web3 instance and wraps it for async use.

To use Dank Mids with web3py:

```python
from dank_mids import setup_dank_w3_from_sync
dank_w3 = setup_dank_w3_from_sync(w3)
random_block = await dank_w3.eth.get_block(123)
```

### Usage with eth-brownie

- see [Dank Brownie Example Commented Code](./examples/dank_brownie_example.py)

### Usage with ape

- COMING SOON: Dank Mids will also work with [ape](https://github.com/ApeWorX/ape).

### Notes

You can also set `DANK_MIDS_DEMO_MODE=True` to see a visual representation of the batching in real time on your console.
