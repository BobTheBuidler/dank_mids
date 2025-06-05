# Dank Mids

Dank Mids is a EVM RPC batching library that helps reduce the number of HTTP requests to a node, saving time and resources. It automatically collects eth_call calls into [multicalls](https://github.com/makerdao/multicall#multicall-) and bundles all RPC calls together in [jsonrpc](https://www.jsonrpc.org/specification#batch) [batch](https://geth.ethereum.org/docs/interacting-with-geth/rpc/batch) calls. tl;dr: its fast as fuck.

![image](https://github.com/BobTheBuidler/dank_mids/assets/70677534/3ecb46aa-f33a-41bd-85fb-c6d2433c7154)

The goal of this tool is to reduce the workload on RPC nodes and allow users to make calls to their preferred node more efficiently. This optimization is especially useful for developers writing scripts that perform large-scale blockchain analysis, as it can save development time and resources.

![](https://i.imgur.com/o9FUmAn.jpg)

### Why is Dank so fast?

There are a number of optimizations that went into making Dank the fastest way to pull rpc data to Python.
1. Implemented (mostly) in C.
2. JSON encoding and decoding is handled by [msgspec](https://jcristharif.com/msgspec/). All responses are decoded to specialized [msgspec.Struct](https://jcristharif.com/msgspec/structs.html) objects defined by the [evmspec](https://github.com/BobTheBuidler/evmspec) library.
3. We use my C-compiled [faster-eth-utils](https://github.com/BobTheBuidler/faster-eth-utils/tree/master) instead of the original python implementation [eth-utils](https://github.com/ethereum/eth-utils)
4. Responses are decoded on a JIT (just-in-time) basis, meaning individual task cancellation works as expected even when response data is received as part of a larger batch. 
5. more stuff I'll write down later...

### Installation

To install Dank Mids, use pip:

`pip install dank-mids`

### Benchmark

We've included a [benchmark script](./examples/benchmark.py) that compares the time it takes to fetch the pool tokens (token0 and token1) for each pool on Sushiswap on Ethereum mainnet. To run it, first install the repo with `poetry install` and then run the benchmark with `brownie run examples/benchmark`.

```
Running 'examples/benchmark.py::main'...
100%|████████████████████████████████████████████████████████████████████████████████████████████████████████████████████| 4213/4213 [08:50<00:00,  7.95it/s]
brownie sync end: 2025-04-14 21:21:35.531099
brownie sync took: 0:08:50.212665
brownie 4 threads start: 2025-04-14 21:21:35.548373
100%|████████████████████████████████████████████████████████████████████████████████████████████████████████████████████| 4213/4213 [08:31<00:00,  8.23it/s]
brownie 4 threads end: 2025-04-14 21:30:08.065397
brownie 4 threads took: 0:08:32.517024
brownie 16 threads start: 2025-04-14 21:30:08.086342
100%|████████████████████████████████████████████████████████████████████████████████████████████████████████████████████| 4213/4213 [08:26<00:00,  8.32it/s]
brownie 16 threads end: 2025-04-14 21:38:38.141635
brownie 16 threads took: 0:08:30.055293
dank start: 2025-04-14 21:38:38.161024
100%|████████████████████████████████████████████████████████████████████████████████████████████████████████████████████| 4213/4213 [00:55<00:00, 75.49it/s]
dank end: 2025-04-14 21:39:33.982835
dank took: 0:00:55.821811
```

As you can see, dank_mids allowed us to save 7 minutes and 34 seconds vs brownie with 16 threads. That's an 89% reduction in runtime, or about 9x as fast as brownie!

### Usage with web3.py

The primary function you need to use Dank Mids is `setup_dank_w3_from_sync`. This function takes a sync Web3 instance and wraps it for async use. If using dank_mids with eth-brownie, you can just import the premade dank_web3 object as well

Example usage of Dank Mids with web3py:

```python
from dank_mids.helpers import setup_dank_w3_from_sync
dank_web3 = setup_dank_w3_from_sync(w3)
# OR
from dank_mids import dank_web3

# Then:
random_block = await dank_web3.eth.get_block(123)
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
