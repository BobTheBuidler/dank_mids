
from importlib.metadata import version
from typing import Tuple, Type

from typing_extensions import Self
from web3.eth import BaseEth
from web3._utils.method_formatters import ERROR_FORMATTERS, NULL_RESULT_FORMATTERS
from web3._utils.blocks import select_method_for_block_identifier
from web3._utils.rpc_abi import RPC
from web3.method import Method, _apply_request_formatters, default_root_munger
from web3.types import BlockIdentifier


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
        request = (method, _apply_request_formatters(params, self.request_formatters(method)))
        response_formatters = (
            return_as_is, 
            ERROR_FORMATTERS.get(self.json_rpc_method, return_as_is), 
            NULL_RESULT_FORMATTERS.get(self.json_rpc_method, return_as_is),
        )
        return request, response_formatters

    @classmethod
    def make(cls, method: RPC) -> Self:
        return cls(method, [default_root_munger])


def bypass_chainid_formatter(eth: Type[BaseEth]) -> None:
    eth._chain_id = MethodNoFormat(RPC.eth_chainId)

def bypass_getbalance_formatter(eth: Type[BaseEth]) -> None:
    eth._get_balance = MethodNoFormat(RPC.eth_getBalance, mungers=[eth.block_id_munger])

def bypass_blocknumber_formatter(eth: Type[BaseEth]) -> None:
    eth.get_block_number = MethodNoFormat(RPC.eth_blockNumber)

def bypass_transaction_count_formatter(eth: Type[BaseEth]) -> None:
    eth._get_transaction_count = MethodNoFormat(RPC.eth_getTransactionCount, mungers=[eth.block_id_munger])

def bypass_log_formatter(eth: Type[BaseEth]) -> None:
    eth._get_logs = MethodNoFormat.make(RPC.eth_getLogs)
    eth.get_filter_logs = MethodNoFormat.make(RPC.eth_getFilterLogs)
    eth.get_filter_changes = MethodNoFormat.make(RPC.eth_getFilterChanges)

def bypass_transaction_receipt_formatter(eth: Type[BaseEth]) -> None:
    attr_name = '_transaction_receipt' if WEB3_MAJOR_VERSION >= 6 else '_get_transaction_receipt'
    setattr(eth, attr_name, MethodNoFormat.make(RPC.eth_getTransactionReceipt))

def bypass_transaction_formatter(eth: Type[BaseEth]) -> None:
    eth._get_transaction = MethodNoFormat.make(RPC.eth_getTransactionByHash)

_block_selectors = dict(
    if_predefined=RPC.eth_getBlockByNumber,
    if_hash=RPC.eth_getBlockByHash,
    if_number=RPC.eth_getBlockByNumber
)

def bypass_block_formatters(eth: Type[BaseEth]) -> None:
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
    eth._call = MethodNoFormat(RPC.eth_call, mungers=[eth.call_munger])

def bypass_get_code_formatter(eth: Type[BaseEth]) -> None:
    eth._get_code = MethodNoFormat(RPC.eth_getCode, mungers=[eth.block_id_munger])


skip_formatters = (
    bypass_chainid_formatter, 
    bypass_getbalance_formatter, 
    bypass_blocknumber_formatter, 
    bypass_transaction_count_formatter, 
    bypass_eth_call_formatter,
    bypass_get_code_formatter,
    bypass_log_formatter,
    bypass_transaction_receipt_formatter,
    bypass_transaction_formatter,
    bypass_block_formatters, 
)

def bypass_formatters(eth):
    for bypass in skip_formatters:
        bypass(eth)
