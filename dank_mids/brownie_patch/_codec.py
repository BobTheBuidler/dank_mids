
import logging
from functools import lru_cache
from typing import List

from brownie.convert.utils import get_type_strings
from cachetools.func import ttl_cache
from eth_abi import abi, codec

from dank_mids import _config

logger = logging.getLogger(__name__)

NO_CACHE_TYPES = ["uint256"]
ENCODER_CACHE = ttl_cache(maxsize=_config.BROWNIE_ENCODER_CACHE_MAXSIZE, ttl=_config.BROWNIE_ENCODER_CACHE_TTL, typed=True)
DECODER_CACHE = ttl_cache(maxsize=_config.BROWNIE_DECODER_CACHE_MAXSIZE, ttl=_config.BROWNIE_DECODER_CACHE_TTL, typed=True)

def should_cache(type_strs: List[str]) -> bool:
    for dont_cache in NO_CACHE_TYPES:
        if dont_cache in type_strs or any(dont_cache in typ for typ in type_strs):
            logger.debug(f'Should not cache {type_strs}')
            return False
    logger.debug(f'Should cache {type_strs}')
    return True
    
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
