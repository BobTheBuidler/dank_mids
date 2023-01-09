# Dank Mids

Dank Mids is a EVM RPC batching library that helps reduce the number of HTTP requests to a node, saving time and resources. It automatically collects eth_call calls into multicalls and bundles all RPC calls together in jsonrpc batch calls.

The goal of this tool is to reduce the workload on RPC nodes and allow users to make calls to their preferred node more efficiently. This optimization is especially useful for developers writing scripts that perform large-scale blockchain analysis, as it can save development time and resources.

![](https://i.imgur.com/o9FUmAn.jpg)

### Installation

To install Dank Mids, use pip:

`pip install dank-mids`

### Usage with web3.py

The primary function you need to use Dank Mids is `setup_dank_w3_from_sync`. This function takes a sync Web3 instance and wraps it for async use.

Example usage of Dank Mids with web3py:

```python
from dank_mids import setup_dank_w3_from_sync
dank_w3 = setup_dank_w3_from_sync(w3)
random_block = await dank_w3.eth.get_block(123)
```

### Usage with eth-brownie

- [Dank Brownie Example Commented Code](./examples/dank_brownie_example.py)

### Usage with ape

- COMING SOON: Dank Mids will also work with [ape](https://github.com/ApeWorX/ape).

### Testimonials

[Yearn](https://yearn.finance) big brain [Tonkers Kuma](https://github.com/tonkers-kuma) had this to say:

![image](https://user-images.githubusercontent.com/70677534/211255488-e76e641c-a0fe-461c-a4e5-27c45a3fea5b.png)

### Notes

You can also set `DANK_MIDS_DEMO_MODE=True` to see a visual representation of the batching in real time on your console.
