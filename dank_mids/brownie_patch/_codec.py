
from functools import lru_cache
from brownie.convert.utils import get_type_strings

from eth_abi import abi, codec


@lru_cache(maxsize=None)
def get_encoder(abi_inputs) -> codec.TupleEncoder:
    return codec.TupleEncoder(
        encoders=[abi.default_codec._registry.get_encoder(type_str) for type_str in get_type_strings(abi_inputs)]
    )

@lru_cache(maxsize=None)
def get_decoder(abi_inputs) -> codec.TupleDecoder:
    return codec.TupleDecoder(
        decoders=[abi.default_codec._registry.get_decoder(type_str) for type_str in get_type_strings(abi_inputs)]
    )