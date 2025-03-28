"""eth_utils uses a decorator to ensure certain functions are called with proper args.

This is helpful for development but adds unnecessary overhead for production use.

This module lets us redefine those functions without the decorator so our scripts can go fast. Vroom.
"""

from eth_typing import HexStr

from eth_utils.hexadecimal import add_0x_prefix, decode_hex, encode_hex, remove_0x_prefix
from eth_utils.types import is_boolean, is_integer, is_string


def patch_eth_utils():
    """eth_utils uses a decorator to ensure certain functions are called with proper args.

    This is helpful for development but adds unnecessary overhead for production use.

    This function redefines those functions without the decorator so our scripts can go fast. Vroom.
    """

    def to_hex(
        primitive=None,
        hexstr=None,
        text=None,
    ) -> HexStr:
        """
        Auto converts any supported value into its hex representation.
        Trims leading zeros, as defined in:
        https://github.com/ethereum/wiki/wiki/JSON-RPC#hex-value-encoding
        """
        if hexstr is not None:
            return add_0x_prefix(hexstr.lower())

        if text is not None:
            return encode_hex(text.encode("utf-8"))

        if is_boolean(primitive):
            return "0x1" if primitive else "0x0"  # type: ignore [return-value]

        if isinstance(primitive, (bytes, bytearray)):
            return encode_hex(primitive)

        if isinstance(primitive, memoryview):
            return encode_hex(bytes(primitive))

        elif is_string(primitive):
            raise TypeError(
                "Unsupported type: The primitive argument must be one of: bytes,"
                "bytearray, int or bool and not str"
            )

        if is_integer(primitive):
            return hex(primitive)  # type: ignore [return-value]

        raise TypeError(
            f"Unsupported type: '{repr(type(primitive))}'. Must be one of: bool, str, "
            "bytes, bytearray or int."
        )

    def to_bytes(primitive=None, hexstr=None, text=None) -> bytes:
        if is_boolean(primitive):
            return b"\x01" if primitive else b"\x00"
        elif isinstance(primitive, (bytearray, memoryview)):
            return bytes(primitive)
        elif isinstance(primitive, bytes):
            return primitive
        elif is_integer(primitive):
            return to_bytes(hexstr=to_hex(primitive))
        elif hexstr is not None:
            if len(hexstr) % 2:
                hexstr = f"0x0{remove_0x_prefix(hexstr)}"
            return decode_hex(hexstr)
        elif text is not None:
            return text.encode("utf-8")
        raise TypeError(
            "expected a bool, int, byte or bytearray in first arg, " "or keyword of hexstr or text"
        )

    import eth_utils.crypto

    eth_utils.crypto.to_bytes = to_bytes

    import web3.main

    web3.main.to_hex = to_hex
    web3.main.to_bytes = to_bytes

    import web3.middleware.filter

    web3.middleware.filter.to_hex = to_hex

    import web3.providers.base

    web3.providers.base.to_bytes = to_bytes

    import web3._utils.encoding

    web3._utils.encoding.to_hex = to_hex
    web3._utils.encoding.to_bytes = to_bytes

    import web3._utils.events

    web3._utils.events.to_hex = to_hex
    web3._utils.events.to_bytes = to_bytes

    import web3._utils.normalizers

    web3._utils.normalizers.to_hex = to_hex
    web3._utils.normalizers.to_bytes = to_bytes

    try:
        # only present on some versions
        import web3._utils.type_conversion
    except ModuleNotFoundError:
        pass
    else:
        web3._utils.type_conversion.to_hex = to_hex
        web3._utils.type_conversion.to_bytes = to_bytes
