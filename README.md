# Dank Mids

Dank Mids is an Ethereum RPC batching library that helps reduce the number of HTTP requests to a node, saving time and resources. It automatically collects RPC calls and bundles them together in jsonrpc batch calls while batching eth_call calls into multicalls.

The goal of this tool is to reduce the workload on RPC nodes and allow users to make calls to the Ethereum network more efficiently. This optimization is especially useful for developers writing scripts that make multiple calls to blockchain networks, as it can save development time and resources.

## Installation

To install Dank Mids, use pip:

`pip install dank-mids`

## Usage

The primary function you need to use Dank Mids is `setup_dank_w3_from_sync`. This function takes a sync Web3 instance and wraps it for async use.

Here is an example usage of Dank Mids with web3py:

```python
from dank_mids import setup_dank_w3_from_sync
dank_w3 = setup_dank_w3_from_sync(w3)
random_block = await dank_w3.eth.get_block(123)
```

COMING SOON: Dank Mids will also work with [apeworx](https://www.apeworx.io/).

You can also set `DANK_MIDS_DEMO_MODE=True` to see a visual representation of the batching in real time on your console.

## Example

- [Dank Brownie Example Commented Code](./examples/dank_brownie_example.py)