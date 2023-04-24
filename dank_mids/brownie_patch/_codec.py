
import logging
from functools import lru_cache

from async_lru import alru_cache
from brownie.convert.utils import get_type_strings
from eth_abi import abi, codec
from multicall.utils import run_in_subprocess

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
