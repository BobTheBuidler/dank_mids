
from contextlib import suppress
from importlib.metadata import version
from typing import Any, Tuple

from typing_extensions import Self
from web3._utils.blocks import select_method_for_block_identifier
from web3._utils.rpc_abi import RPC
from web3._utils.method_formatters import PYTHONIC_RESULT_FORMATTERS
from web3.eth import AsyncEth, Eth
from web3.method import Method, _apply_request_formatters, default_root_munger


WEB3_MAJOR_VERSION = int(version('web3').split('.')[0])

return_as_is = lambda x: x

class MethodNoFormat(Method):
    """Bypasses web3py default result formatters."""
    def process_params(self, module, *args, **kwargs):
        params = self.input_munger(module, args, kwargs)

        if self.method_choice_depends_on_args:
            # If the method choice depends on the args that get passed in,
            # the first parameter determines which method needs to be called
            self.json_rpc_method = self.method_choice_depends_on_args(value=params[0])

            pending_or_latest_filter_methods = [
                RPC.eth_newPendingTransactionFilter,
                RPC.eth_newBlockFilter
            ]
            if self.json_rpc_method in pending_or_latest_filter_methods:
                # For pending or latest filter methods, use params to determine
                # which method to call, but don't pass them through with the request
                params = []

        method = self.method_selector_fn()
        response_formatters = (return_as_is,
                               self.error_formatters(method),
                               self.null_result_formatters(method),)

        request = (method,
                   _apply_request_formatters(params, self.request_formatters(method)))

        return request, response_formatters

    @classmethod
    def make(cls, method: RPC) -> Self:
        return cls(method, [default_root_munger])


def _replace(obj: Any, name: str, value: MethodNoFormat) -> None:
    if not isinstance(value, MethodNoFormat):
        raise TypeError(value, type(value))
    with suppress(TypeError):
        if not hasattr(obj, name):
            raise AttributeError(obj, name)
    setattr(obj, name, value)

def bypass_web3py_log_formatters():
    #for method in [RPC.eth_getFilterChanges, RPC.eth_getFilterLogs, RPC.eth_getLogs]:
    #    PYTHONIC_RESULT_FORMATTERS.pop(method)

    replace_on = Eth if WEB3_MAJOR_VERSION >= 6 else AsyncEth
    _replace(replace_on, '_get_logs', MethodNoFormat.make(RPC.eth_getLogs))

    _replace(Eth, 'get_filter_logs', MethodNoFormat.make(RPC.eth_getFilterLogs))
    _replace(Eth, 'get_filter_changes', MethodNoFormat.make(RPC.eth_getFilterChanges))

def bypass_web3py_transaction_receipt_formatter():
    #PYTHONIC_RESULT_FORMATTERS.pop(RPC.eth_getTransactionReceipt)
    attr_name = '_transaction_receipt' if WEB3_MAJOR_VERSION >= 6 else '_get_transaction_receipt'
    setattr(AsyncEth, attr_name, MethodNoFormat.make(RPC.eth_getTransactionReceipt))

def bypass_web3py_block_formatters():
    #PYTHONIC_RESULT_FORMATTERS.pop(RPC.eth_getBlockByHash)
    #PYTHONIC_RESULT_FORMATTERS.pop(RPC.eth_getBlockByNumber)
    if WEB3_MAJOR_VERSION >= 6:
        _replace(AsyncEth, '_get_block', MethodNoFormat(
            method_choice_depends_on_args=select_method_for_block_identifier(
                if_predefined=RPC.eth_getBlockByNumber,
                if_hash=RPC.eth_getBlockByHash,
                if_number=RPC.eth_getBlockByNumber,
            ),
            mungers=[AsyncEth.get_block_munger]
        ))
    else:
        from web3.types import BlockIdentifier

        def get_block_munger(
            self, block_identifier: BlockIdentifier, full_transactions: bool = False
        ) -> Tuple[BlockIdentifier, bool]:
            return (block_identifier, full_transactions)
        
        _replace(AsyncEth, '_get_block', MethodNoFormat(
            method_choice_depends_on_args=select_method_for_block_identifier(
                if_predefined=RPC.eth_getBlockByNumber,
                if_hash=RPC.eth_getBlockByHash,
                if_number=RPC.eth_getBlockByNumber,
            ),
            mungers=[get_block_munger]
        ))

def bypass_web3py_tx_formatters():
    #PYTHONIC_RESULT_FORMATTERS.pop(RPC.eth_getTransactionByBlockHashAndIndex)
    #PYTHONIC_RESULT_FORMATTERS.pop(RPC.eth_getTransactionByBlockNumberAndIndex)
    #PYTHONIC_RESULT_FORMATTERS.pop(RPC.eth_getTransactionByHash)
    AsyncEth._get_transaction = MethodNoFormat.make(RPC.eth_getTransactionByHash)