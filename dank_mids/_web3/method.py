from collections.abc import Callable, Coroutine
from typing import Any, cast

from typing_extensions import Self
from web3._utils.blocks import select_method_for_block_identifier
from web3._utils.rpc_abi import RPC
from web3.eth import BaseEth
from web3.manager import NULL_RESPONSES, apply_null_result_formatters
from web3.method import Method, TFunc, default_root_munger
from web3.module import AsyncLogFilter, _UseExistingFilter, apply_result_formatters
from web3.types import RPCEndpoint, RPCResponse

from dank_mids._web3.formatters import (
    _get_response_formatters,
    _response_formatters,
    get_request_formatters,
)
from dank_mids.helpers._controllers import get_controller_for_async_w3
from dank_mids.types import Error, PartialResponse


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
        request_formatters = get_request_formatters(method)
        if method == "eth_call":
            # we will only format the TxParams
            if len(params) > 2:
                raise NotImplementedError("You can not use state override with dank mids")
            tx, block = params
            if len(tx) > 2:
                params = request_formatters(params)
            else:
                params = tx, hex(block) if isinstance(block, int) else block
                if isinstance(tx["data"], bytes):
                    tx["data"] = f"0x{bytes.hex(tx['data'])}"
        else:
            params = request_formatters(params)
        request = method, params
        return request, _response_formatters.get(self.json_rpc_method) or _get_response_formatters(
            self.json_rpc_method
        )

    @classmethod
    def default(cls, method: RPCEndpoint) -> Self:
        """Creates a default instance of MethodNoFormat.

        Args:
            method: The RPC method for which a MethodNoFormat instance should be created.
        """
        return cls(method, [default_root_munger])


def _raise_dank_error_response(response: RPCResponse) -> None:
    error = response["error"]
    if isinstance(error, Error):
        dank_error = error
        request_context = None
    else:
        error_payload = dict(error)
        request_context = error_payload.pop("dankmids_added_context", None)
        dank_error = Error(**error_payload)

    exc = PartialResponse(error=dank_error).exception
    if request_context is not None and not hasattr(exc, "request"):
        exc.request = request_context  # type: ignore[attr-defined]
    raise exc


def _extract_dank_result(
    response: RPCResponse,
    params: Any,
    null_result_formatters: Callable[..., Any],
) -> Any:
    if "error" in response:
        _raise_dank_error_response(response)

    if response.get("result", False) in NULL_RESPONSES:
        apply_null_result_formatters(null_result_formatters, response, params)
    return response.get("result")


def retrieve_dank_method_call_fn(async_w3: Any, module: Any) -> Callable[
    [Method[Callable[..., Any]]],
    Callable[..., Coroutine[Any, Any, Any]],
]:
    def retrieve(method: Method[Callable[..., Any]]) -> Callable[..., Coroutine[Any, Any, Any]]:
        async def caller(*args: Any, **kwargs: Any) -> Any:
            try:
                (method_str, params), response_formatters = method.process_params(
                    module, *args, **kwargs
                )
            except _UseExistingFilter as err:
                return AsyncLogFilter(eth_module=module, filter_id=err.filter_id)

            (
                result_formatters,
                _error_formatters,
                null_result_formatters,
            ) = response_formatters
            controller = get_controller_for_async_w3(async_w3)
            response = await controller(cast(RPCEndpoint, method_str), params)
            result = _extract_dank_result(response, params, null_result_formatters)
            return apply_result_formatters(result_formatters, result)

        return caller

    return retrieve


def bypass_chainid_formatter(eth: type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_chainId method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._chain_id = MethodNoFormat(RPC.eth_chainId)


def bypass_getbalance_formatter(eth: type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_getBalance method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._get_balance = MethodNoFormat(RPC.eth_getBalance, mungers=[eth.block_id_munger])


def bypass_transaction_count_formatter(eth: type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_getTransactionCount method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._get_transaction_count = MethodNoFormat(
        RPC.eth_getTransactionCount, mungers=[eth.block_id_munger]
    )


def bypass_log_formatter(eth: type[BaseEth]) -> None:
    """Bypasses formatters for log-related methods such as eth_getLogs.

    Args:
        eth: The Ethereum base class instance whose methods are to be modified.
    """
    eth._get_logs = MethodNoFormat.default(RPC.eth_getLogs)
    eth._get_logs_raw = MethodNoFormat.default(f"{RPC.eth_getLogs}_raw")
    eth.get_filter_logs = MethodNoFormat.default(RPC.eth_getFilterLogs)
    eth.get_filter_changes = MethodNoFormat.default(RPC.eth_getFilterChanges)


def bypass_transaction_receipt_formatter(eth: type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_getTransactionReceipt method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._transaction_receipt = MethodNoFormat.default(RPC.eth_getTransactionReceipt)


def bypass_transaction_formatter(eth: type[BaseEth]) -> None:
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


def bypass_block_formatters(eth: type[BaseEth]) -> None:
    """Bypasses the formatter for block-related methods such as eth_getBlockByNumber.

    Args:
        eth: The Ethereum base class instance whose methods are to be modified.
    """
    eth._get_block = MethodNoFormat(
        method_choice_depends_on_args=select_method_for_block_identifier(**_block_selectors),
        mungers=[eth.get_block_munger],
    )


def bypass_eth_call_formatter(eth: type[BaseEth]) -> None:
    """Bypasses the formatter for the eth_call method.

    Args:
        eth: The Ethereum base class instance whose method is to be modified.
    """
    eth._call = MethodNoFormat(RPC.eth_call, mungers=[eth.call_munger])


def bypass_get_code_formatter(eth: type[BaseEth]) -> None:
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


def bypass_formatters(eth) -> None:
    """Executes a sequence of bypass methods to remove default formatters for ETH methods.

    Utilizes a predefined list of bypass methods to systematically modify the corresponding
    methods in the Ethereum base class instance.

    Args:
        eth: The Ethereum base class instance whose methods are to be modified.
    """
    for bypass in skip_formatters:
        bypass(eth)
