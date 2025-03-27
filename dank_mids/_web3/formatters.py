from typing import Any, Callable, Dict, Iterable, Sequence, Tuple, Union

from eth_typing import TypeStr
from eth_utils import to_dict
from eth_utils.curried import apply_formatter_at_index
from eth_utils.toolz import compose
from web3._utils.method_formatters import (
    ABI_REQUEST_FORMATTERS,
    ERROR_FORMATTERS,
    METHOD_NORMALIZERS,
    NULL_RESULT_FORMATTERS,
    PYTHONIC_REQUEST_FORMATTERS,
    STANDARD_NORMALIZERS,
)
from web3._utils.rpc_abi import RPC_ABIS, apply_abi_formatters_to_dict
from web3.types import Formatters, RPCEndpoint, RPCResponse


from dank_mids._web3.abi import get_mapper


return_as_is = lambda x: x


@to_dict
def abi_request_formatters(
    normalizers: Sequence[Callable[[TypeStr, Any], Tuple[TypeStr, Any]]],
    abis: Dict[RPCEndpoint, Union[list, dict]],
) -> Iterable[Tuple[RPCEndpoint, Callable[..., Any]]]:
    for method, abi_types in abis.items():
        if isinstance(abi_types, list):
            yield method, get_mapper(tuple(normalizers), tuple(abi_types))
        elif isinstance(abi_types, dict):
            single_dict_formatter = apply_abi_formatters_to_dict(normalizers, abi_types)
            yield method, apply_formatter_at_index(single_dict_formatter, 0)
        else:
            raise TypeError(f"ABI definitions must be a list or dictionary, got {abi_types!r}")


ABI_REQUEST_FORMATTERS: Formatters = abi_request_formatters(STANDARD_NORMALIZERS, RPC_ABIS)

REQUEST_FORMATTER_MAPS = (
    ABI_REQUEST_FORMATTERS,
    # METHOD_NORMALIZERS needs to be after ABI_REQUEST_FORMATTERS
    # so that eth_getLogs's apply_formatter_at_index formatter
    # is applied to the whole address
    # rather than on the first byte of the address
    METHOD_NORMALIZERS,
    PYTHONIC_REQUEST_FORMATTERS,
)

_request_formatters: Dict[RPCEndpoint, Callable] = {}


def get_request_formatters(
    method_name: Union[RPCEndpoint, Callable[..., RPCEndpoint]],
) -> Callable[..., Any]:
    formatters = _request_formatters.get(method_name)
    if formatters is None:
        combined = (formatter_map.get(method_name) for formatter_map in REQUEST_FORMATTER_MAPS)
        combined = list(filter(None, combined))
        if not combined:
            formatters = return_as_is
        elif len(combined) == 1:
            formatters = combined[0]
        else:
            # NOTE the web3 implementation uses both pipe and compose which I think is unnecessary
            # even compose by itself adds unnecessary overhead if used for only 1 formatter
            formatters = compose(*combined)
        _request_formatters[method_name] = formatters
    return formatters


SuccessFormatter = Callable[[RPCResponse], Any]
ErrorFormatter = Callable[[RPCResponse], Any]
NullFormatter = Callable[[RPCResponse], Any]

ResponseFormatters = Tuple[SuccessFormatter, ErrorFormatter, NullFormatter]

_response_formatters: Dict[RPCEndpoint, ResponseFormatters] = {}


def _get_response_formatters(method: RPCEndpoint) -> ResponseFormatters:
    formatters = _response_formatters[method] = (
        return_as_is,
        ERROR_FORMATTERS.get(method, return_as_is),
        NULL_RESULT_FORMATTERS.get(method, return_as_is),
    )
    return formatters
