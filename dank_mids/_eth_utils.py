"""eth_utils uses a decorator to ensure certain functions are called with proper args.

This is helpful for development but adds unnecessary overhead for production use.

This module lets us redefine those functions without the decorator so our scripts can go fast. Vroom.
"""

import binascii
from typing import Any, AnyStr, Final, Optional

from eth_typing import HexStr


hexlify: Final = binascii.hexlify
unhexlify: Final = binascii.unhexlify


def patch_eth_utils() -> None:
    """eth_utils uses a decorator to ensure certain functions are called with proper args.

    This is helpful for development but adds unnecessary overhead for production use.

    This function redefines those functions without the decorator so our scripts can go fast. Vroom.
    """
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


def to_hex(
    primitive: Optional[Any] = None,
    hexstr: Optional[HexStr] = None,
    text: Optional[str] = None,
) -> HexStr:
    """
    Auto converts any supported value into its hex representation.
    Trims leading zeros, as defined in:
    https://github.com/ethereum/wiki/wiki/JSON-RPC#hex-value-encoding
    """
    if hexstr is not None:
        return add_0x_prefix(hexstr.lower())  # type: ignore [arg-type]

    if text is not None:
        return encode_hex(text.encode("utf-8"))

    elif isinstance(primitive, bool):
        return "0x1" if primitive else "0x0"  # type: ignore [return-value]

    elif isinstance(primitive, (bytes, bytearray)):
        return encode_hex(primitive)  # type: ignore [type-var]

    elif isinstance(primitive, memoryview):
        return encode_hex(bytes(primitive))

    elif isinstance(primitive, str):
        raise TypeError(
            "Unsupported type: The primitive argument must be one of: bytes,"
            "bytearray, int or bool and not str"
        )

    elif isinstance(primitive, int):
        return hex(primitive)  # type: ignore [return-value]

    raise TypeError(
        f"Unsupported type: '{repr(type(primitive))}'. Must be one of: bool, str, "
        "bytes, bytearray or int."
    )


def to_bytes(
    primitive: Optional[Any] = None,
    hexstr: Optional[HexStr] = None,
    text: Optional[str] = None,
) -> bytes:
    if isinstance(primitive, bool):
        return b"\x01" if primitive else b"\x00"
    elif isinstance(primitive, (bytearray, memoryview)):
        return bytes(primitive)
    elif isinstance(primitive, bytes):
        return primitive
    elif isinstance(primitive, int):
        return to_bytes(hexstr=to_hex(primitive))
    elif hexstr is not None:
        return decode_hex(f"0x0{remove_0x_prefix(hexstr)}" if len(hexstr) % 2 else hexstr)
    elif text is not None:
        return text.encode("utf-8")
    raise TypeError(
        "expected a bool, int, byte or bytearray in first arg, " "or keyword of hexstr or text"
    )


def decode_hex(value: str) -> bytes:
    if not isinstance(value, str):
        raise TypeError("Value must be an instance of str")
    non_prefixed = remove_0x_prefix(value)  # type: ignore [arg-type]
    # unhexlify will only accept bytes type someday
    ascii_hex = non_prefixed.encode("ascii")
    return unhexlify(ascii_hex)


def encode_hex(value: AnyStr) -> HexStr:
    ascii_bytes: Any  # no need to validate bytes type in the c code
    if isinstance(value, bytes):
        ascii_bytes = value
    elif isinstance(value, str):
        ascii_bytes = value.encode("ascii")
    elif isinstance(value, bytearray):
        ascii_bytes = bytes(value)
    else:
        raise TypeError("Value must be an instance of str or unicode")
    ascii_hex = hexlify(ascii_bytes).decode("ascii")
    return add_0x_prefix(ascii_hex)  # type: ignore [arg-type]


def is_0x_prefixed(value: str) -> bool:
    if not isinstance(value, str):
        raise TypeError(f"is_0x_prefixed requires text typed arguments. Got: {repr(value)}")
    return value.startswith(("0x", "0X"))


def remove_0x_prefix(value: HexStr) -> HexStr:
    # sourcery skip: assign-if-exp, reintroduce-else
    if is_0x_prefixed(value):
        return value[2:]  # type: ignore [return-value]
    return value


def add_0x_prefix(value: HexStr) -> HexStr:
    # sourcery skip: assign-if-exp, reintroduce-else
    if is_0x_prefixed(value):
        return value
    return f"0x{value}"  # type: ignore [return-value]
