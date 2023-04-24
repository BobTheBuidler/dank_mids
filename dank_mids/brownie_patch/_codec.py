
import logging
from functools import lru_cache
from typing import Any, Tuple, Union

from async_lru import alru_cache
from brownie.convert.utils import get_type_strings
from eth_abi import abi, codec
from multicall.utils import run_in_subprocess
from web3.datastructures import AttributeDict

from dank_mids import _config

logger = logging.getLogger(__name__)

NO_CACHE_TYPES = ["uint256"]
# NOTE: cache in main process, en/decode in subprocess (if enabled)
ENCODER_CACHE = alru_cache(maxsize=_config.BROWNIE_ENCODER_CACHE_MAXSIZE, ttl=_config.BROWNIE_ENCODER_CACHE_TTL, typed=True)
DECODER_CACHE = alru_cache(maxsize=_config.BROWNIE_DECODER_CACHE_MAXSIZE, ttl=_config.BROWNIE_DECODER_CACHE_TTL)

@ENCODER_CACHE
async def format_and_encode(formatter, encoder, args):
    """Lets us cache values in main process but delegate work to subprocess if desired."""
    return (await run_in_subprocess(encoder, formatter(args))).hex()

@DECODER_CACHE
async def decode_and_format(decoder, formatter, arg):
    """Lets us cache values in main process but delegate work to subprocess if desired."""
    return formatter(await run_in_subprocess(decoder, arg))

Hashable = Union[Tuple["Hashable", ...], AttributeDict, Any]

def _make_thing_hashable(thing: Any) -> Hashable:
    """Takes a list of dicts and returns a hashable tuple of AttributeDicts."""
    if isinstance(thing, dict):
        return AttributeDict({k: _make_thing_hashable(v)for k, v in thing.items()})
    elif isinstance(thing, (list, tuple)):
        return tuple(_make_thing_hashable(x) for x in thing)
    return thing

@lru_cache(maxsize=None)
def get_encoder(abi_inputs) -> codec.TupleEncoder:
    type_strs = get_type_strings(abi_inputs)
    logger.debug(f'Building encoder for {type_strs}')
    return codec.TupleEncoder(
        encoders=[abi.default_codec._registry.get_encoder(type_str) for type_str in type_strs]
    )

@lru_cache(maxsize=None)
def get_decoder(abi_outputs) -> codec.TupleDecoder:
    type_strs = get_type_strings(abi_outputs)
    logger.debug(f'Building decoder for {type_strs}')
    return codec.TupleDecoder(
        decoders=[abi.default_codec._registry.get_decoder(type_str) for type_str in type_strs]
    )
