from importlib.metadata import version
from typing import Any, Callable, Dict, Tuple, Type, Union

from eth_utils.toolz import compose
from typing_extensions import Self
from web3.eth import BaseEth
from web3._utils.method_formatters import (
    ABI_REQUEST_FORMATTERS,
    ERROR_FORMATTERS,
    METHOD_NORMALIZERS,
    NULL_RESULT_FORMATTERS,
    PYTHONIC_REQUEST_FORMATTERS,
    combine_formatters,
)
from web3._utils.blocks import select_method_for_block_identifier
from web3._utils.rpc_abi import RPC
from web3.method import Method, TFunc, TReturn, default_root_munger
from web3.types import BlockIdentifier, RPCEndpoint

WEB3_MAJOR_VERSION = int(version("web3").split(".")[0])

return_as_is = lambda x: x


ResponseFormatters = Tuple[Callable, Callable, Callable]


class MethodNoFormat(Method[TFunc]):
    """Custom method class to bypass web3py's default result formatters.

    This class processes parameters, makes conditional adjustments to the parameters,
    and selects specific methods to call based on those parameters. It bypasses the
    standard result formatters by applying a no-operation formatter, effectively
    returning responses as-is or using predefined formatters based on the RPC call.
    """

    def process_params(self, module, *args, **kwargs):
        """Prepare and return request parameters and response formatters.

        Adjusts parameters based on the method choice logic and avoids standard request
        param forwarding for specific filter methods. Defines response formatters to
        bypass usual formatting processes.

        Args:
            module: The module where the method belongs.
            args: Positional arguments for the method.
            kwargs: Keyword arguments for the method.
        """
        params = self.input_munger(module, args, kwargs)

        if self.method_choice_depends_on_args:
            self.json_rpc_method = self.method_choice_depends_on_args(value=params[0])

            pending_or_latest_filter_methods = (
                RPC.eth_newPendingTransactionFilter,
                RPC.eth_newBlockFilter,
            )
            if self.json_rpc_method in pending_or_latest_filter_methods:
                params = []

        method = self.method_selector_fn()
        request = method, get_request_formatters(method)(params)
        return request, _response_formatters.get(self.json_rpc_method) or _get_response_formatters(
            self.json_rpc_method
        )

    @classmethod
    def default(cls, method: RPC) -> Self:
        """Creates a default instance of MethodNoFormat.

        Args:
            method: The RPC method for which a MethodNoFormat instance should be created.
        """
        return cls(method, [default_root_munger])


_request_formatters: Dict[RPCEndpoint, Callable]

REQUEST_FORMATTER_MAPS = (
    ABI_REQUEST_FORMATTERS,
    # METHOD_NORMALIZERS needs to be after ABI_REQUEST_FORMATTERS
    # so that eth_getLogs's apply_formatter_at_index formatter
    # is applied to the whole address
    # rather than on the first byte of the address
    METHOD_NORMALIZERS,
    PYTHONIC_REQUEST_FORMATTERS,
)


def get_request_formatters(
    method_name: Union[RPCEndpoint, Callable[..., RPCEndpoint]],
) -> Callable[..., Any]:
    formatters = _request_formatters.get(method_name)
    if formatters is None:
        combined: Tuple[Callable] = combine_formatters(REQUEST_FORMATTER_MAPS, method_name)
        if not combined:
            formatters = lambda x: x
        elif len(formatters) == 1:
            formatters = combined[0]
        else:
            # NOTE the web3 implementation uses both pipe and compose which I think is unnecessary
            # even compose by itself adds unnecessary overhead if used for only 1 formatter
            formatters = compose(*combined)
        _request_formatters[method_name] = formatters
    return formatters


_response_formatters: Dict[RPCEndpoint, ResponseFormatters] = {}


def _get_response_formatters(method: RPCEndpoint) -> ResponseFormatters:
    formatters = _response_formatters[method] = (
        return_as_is,
        ERROR_FORMATTERS.get(method, return_as_is),
        NULL_RESULT_FORMATTERS.get(method, return_as_is),
    )
    return formatters


def bypass_chainid_formatter(eth: Type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_chainId method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._chain_id = MethodNoFormat(RPC.eth_chainId)


def bypass_getbalance_formatter(eth: Type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_getBalance method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._get_balance = MethodNoFormat(RPC.eth_getBalance, mungers=[eth.block_id_munger])


def bypass_transaction_count_formatter(eth: Type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_getTransactionCount method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._get_transaction_count = MethodNoFormat(
        RPC.eth_getTransactionCount, mungers=[eth.block_id_munger]
    )


def bypass_log_formatter(eth: Type[BaseEth]) -> None:
    """Bypasses formatters for log-related methods such as eth_getLogs.

    Args:
        eth: The Ethereum base class instance whose methods are to be modified.
    """
    eth._get_logs = MethodNoFormat.default(RPC.eth_getLogs)
    eth._get_logs_raw = MethodNoFormat.default(f"{RPC.eth_getLogs}_raw")
    eth.get_filter_logs = MethodNoFormat.default(RPC.eth_getFilterLogs)
    eth.get_filter_changes = MethodNoFormat.default(RPC.eth_getFilterChanges)


def bypass_transaction_receipt_formatter(eth: Type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_getTransactionReceipt method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    attr_name = "_transaction_receipt" if WEB3_MAJOR_VERSION >= 6 else "_get_transaction_receipt"
    setattr(eth, attr_name, MethodNoFormat.default(RPC.eth_getTransactionReceipt))


def bypass_transaction_formatter(eth: Type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_getTransactionByHash method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._get_transaction = MethodNoFormat.default(RPC.eth_getTransactionByHash)


_block_selectors = dict(
    if_predefined=RPC.eth_getBlockByNumber,
    if_hash=RPC.eth_getBlockByHash,
    if_number=RPC.eth_getBlockByNumber,
)


def bypass_block_formatters(eth: Type[BaseEth]) -> None:
    """Bypasses the formatter for block-related methods such as eth_getBlockByNumber.

    Adjusts the mungers definition based on the major version of the web3 library.

    Args:
        eth: The Ethereum base class instance whose methods are to be modified.
    """
    if WEB3_MAJOR_VERSION >= 6:
        get_block_munger = eth.get_block_munger
    else:

        def get_block_munger(
            self, block_identifier: BlockIdentifier, full_transactions: bool = False
        ) -> Tuple[BlockIdentifier, bool]:
            return (block_identifier, full_transactions)

    eth._get_block = MethodNoFormat(
        method_choice_depends_on_args=select_method_for_block_identifier(**_block_selectors),
        mungers=[get_block_munger],
    )


def bypass_eth_call_formatter(eth: Type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_call method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._call = MethodNoFormat(RPC.eth_call, mungers=[eth.call_munger])


def bypass_get_code_formatter(eth: Type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_getCode method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._get_code = MethodNoFormat(RPC.eth_getCode, mungers=[eth.block_id_munger])


skip_formatters = (
    bypass_chainid_formatter,
    bypass_getbalance_formatter,
    bypass_transaction_count_formatter,
    bypass_eth_call_formatter,
    bypass_get_code_formatter,
    bypass_log_formatter,
    bypass_transaction_receipt_formatter,
    bypass_transaction_formatter,
    bypass_block_formatters,
)


def bypass_formatters(eth):
    """Executes a sequence of bypass methods to remove default formatters for ETH methods.

    Utilizes a predefined list of bypass methods to systematically modify the corresponding
    methods in the Ethereum base class instance.

    Args:
        eth: The Ethereum base class instance whose methods are to be modified.
    """
    for bypass in skip_formatters:
        bypass(eth)
