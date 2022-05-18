
import sys
import threading
import time
from types import MethodType
from typing import Any, Dict, Optional, Tuple

from brownie._config import CONFIG
from brownie.convert import Wei
from brownie.exceptions import VirtualMachineError
from brownie.network.account import Account
from brownie.network.rpc import Rpc
from brownie.network.state import Chain
from brownie.network.transaction import TransactionReceipt
from web3 import Web3

rpc = Rpc()

def _patch_account(account: Account, w3: Web3) -> Account:
    async def transfer_coro(
        self,
        to: Account = None,
        amount: int = 0,
        gas_limit: Optional[int] = None,
        gas_buffer: Optional[float] = None,
        gas_price: Optional[int] = None,
        max_fee: Optional[int] = None,
        priority_fee: Optional[int] = None,
        data: str = None,
        nonce: Optional[int] = None,
        required_confs: int = 1,
        allow_revert: bool = None,
        silent: bool = None,
    ) -> TransactionReceipt:
        """
        Broadcast a transaction from this account.
        Kwargs:
            to: Account instance or address string to transfer to.
            amount: Amount of ether to send, in wei.
            gas_limit: Gas limit of the transaction.
            gas_buffer: Multiplier to apply to gas limit.
            gas_price: Gas price of legacy transaction.
            max_fee: Max fee per gas of dynamic fee transaction.
            priority_fee: Max priority fee per gas of dynamic fee transaction.
            nonce: Nonce to use for the transaction.
            data: Hexstring of data to include in transaction.
            silent: Toggles console verbosity.
        Returns:
            TransactionReceipt object
        """

        receipt, exc = await self._make_transaction_coro(
            to,
            amount,
            gas_limit,
            gas_buffer,
            gas_price,
            max_fee,
            priority_fee,
            data or "",
            nonce,
            "",
            required_confs,
            allow_revert,
            silent,
        )

        if rpc.is_active():
            undo_thread = threading.Thread(
                target=Chain()._add_to_undo_buffer,
                args=(
                    receipt,
                    self.transfer,
                    [],
                    {
                        "to": to,
                        "amount": amount,
                        "gas_limit": gas_limit,
                        "gas_buffer": gas_buffer,
                        "gas_price": gas_price,
                        "max_fee": max_fee,
                        "priority_fee": priority_fee,
                        "data": data,
                    },
                ),
                daemon=True,
            )
            undo_thread.start()

        receipt._raise_if_reverted(exc)
        return receipt
    
    async def _make_transaction_coro(
        self,
        to: Optional["Account"],
        amount: int,
        gas_limit: Optional[int],
        gas_buffer: Optional[float],
        gas_price: Optional[int],
        max_fee: Optional[int],
        priority_fee: Optional[int],
        data: str,
        nonce: Optional[int],
        fn_name: str,
        required_confs: int,
        allow_revert: Optional[bool],
        silent: Optional[bool],
    ) -> Tuple[TransactionReceipt, Optional[Exception]]:
        # shared logic for `transfer` and `deploy`
        if gas_limit and gas_buffer:
            raise ValueError("Cannot set gas_limit and gas_buffer together")
        if silent is None:
            silent = bool(CONFIG.mode == "test" or CONFIG.argv["silent"])

        if gas_price is None:
            # if gas price is not explicitly set, load the default max fee and priority fee
            if max_fee is None:
                max_fee = CONFIG.active_network["settings"]["max_fee"] or None
            if priority_fee is None:
                priority_fee = CONFIG.active_network["settings"]["priority_fee"] or None

        if priority_fee == "auto":
            priority_fee = Chain().priority_fee

        try:
            # if max fee and priority fee are not set, use gas price
            if max_fee is None and priority_fee is None:
                gas_price, gas_strategy, gas_iter = self._gas_price(gas_price)
            else:
                gas_strategy, gas_iter = None, None
            gas_limit = Wei(gas_limit) or self._gas_limit(
                to, amount, gas_price or max_fee, gas_buffer, data
            )
        except ValueError as e:
            raise VirtualMachineError(e) from None

        with self._lock:
            # we use a lock here to prevent nonce issues when sending many tx's at once
            tx = {
                "from": self.address,
                "value": Wei(amount),
                "nonce": nonce if nonce is not None else self._pending_nonce(),
                "gas": web3.toHex(gas_limit),
                "data": HexBytes(data),
            }
            if to:
                tx["to"] = to_address(str(to))
            tx = _apply_fee_to_tx(tx, gas_price, max_fee, priority_fee)
            txid = None
            while True:
                try:
                    response = await self._transact(tx, allow_revert)  # type: ignore
                    exc, revert_data = None, None
                    if txid is None:
                        txid = HexBytes(response).hex()
                        if not silent:
                            print(f"\rTransaction sent: {color('bright blue')}{txid}{color}")
                except ValueError as e:
                    if txid is None:
                        exc = VirtualMachineError(e)
                        if not hasattr(exc, "txid"):
                            raise exc from None
                        txid = exc.txid
                        print(f"\rTransaction sent: {color('bright blue')}{txid}{color}")
                        revert_data = (exc.revert_msg, exc.pc, exc.revert_type)
                try:
                    receipt = TransactionReceipt(
                        txid,
                        self,
                        silent=silent,
                        required_confs=required_confs,
                        is_blocking=False,
                        name=fn_name,
                        revert_data=revert_data,
                    )  # type: ignore
                    break
                except (TransactionNotFound, ValueError):
                    if not silent:
                        sys.stdout.write(f"  Awaiting transaction in the mempool... {_marker[0]}\r")
                        sys.stdout.flush()
                        _marker.rotate(1)
                    time.sleep(1)

        receipt = self._await_confirmation(receipt, required_confs, gas_strategy, gas_iter)
        if receipt.status != 1 and exc is None:
            error_data = {
                "message": (
                    f"VM Exception while processing transaction: revert {receipt.revert_msg}"
                ),
                "code": -32000,
                "data": {
                    receipt.txid: {
                        "error": "revert",
                        "program_counter": receipt._revert_pc,
                        "return": receipt.return_value,
                        "reason": receipt.revert_msg,
                    },
                },
            }
            exc = VirtualMachineError(ValueError(error_data))

        return receipt, exc
    
    async def _transact_coro(self, tx: Dict, allow_revert: bool) -> Any:
        if allow_revert is None:
            allow_revert = bool(CONFIG.network_type == "development")
        if not allow_revert:
            await self._check_for_revert_coro(tx)
        return await w3.eth.send_transaction(tx)
    
    async def _check_for_revert_coro(self, tx: Dict) -> None:
        try:
            # remove gas price related values to avoid issues post-EIP1559
            # https://github.com/ethereum/go-ethereum/pull/23027
            skip_keys = {"gasPrice", "maxFeePerGas", "maxPriorityFeePerGas"}
            await w3.eth.call({k: v for k, v in tx.items() if k not in skip_keys and v})
        except ValueError as exc:
            msg = exc.args[0]["message"] if isinstance(exc.args[0], dict) else str(exc)
            raise ValueError(
                f"Execution reverted during call: '{msg}'. This transaction will likely revert. "
                "If you wish to broadcast, include `allow_revert:True` as a transaction parameter.",
            ) from None
    
    account.transfer_coro = MethodType(transfer_coro, account)
    account._make_transaction_coro = MethodType(_make_transaction_coro, account)
    account._transact_coro = MethodType(_transact_coro, account)
    account._check_for_revert_coro = MethodType(_check_for_revert_coro, account)
    return account
