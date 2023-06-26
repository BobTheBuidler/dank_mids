
import abc
import asyncio
from collections import defaultdict
from typing import (TYPE_CHECKING, Any, DefaultDict, Dict, Generator, Generic,
                    Iterable, Iterator, List, Optional, Tuple, TypeVar, Union)

import aiohttp
import eth_retry
from aiohttp import RequestInfo
from eth_abi import decode_single, encode_single
from eth_typing import ChecksumAddress
from eth_utils import function_signature_to_4byte_selector
from hexbytes import HexBytes
from hexbytes._utils import to_bytes
from multicall.utils import run_in_subprocess
from web3 import Web3
from web3.datastructures import AttributeDict
from web3.types import RPCEndpoint, RPCError, RPCResponse

from dank_mids import _config
from dank_mids._demo_mode import demo_logger
from dank_mids.constants import BAD_HEXES, OVERRIDE_CODE
from dank_mids.helpers import _session, await_all
from dank_mids.loggers import main_logger
from dank_mids.types import BatchId, BlockId, JsonrpcParams, RpcCallJson

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    from dank_mids.worker import DankWorker

RETRY_ERRS = ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]

class ResponseNotReady(Exception):
    pass

def _call_failed(data: Optional[Union[bytes, Exception]]) -> bool:
    """ Returns True if `data` indicates a failed response, False otherwise. """
    if data is None:
        return True
    # If we got a known "bad" response from the multicall, that is also a failure.
    # Most likely the target contract does not support multicall2.
    elif (isinstance(data, bytes) and HexBytes(data).hex() in BAD_HEXES):
        return True
    return False

def _log_exception(e: Exception) -> None:
    # NOTE: These errors are expected during normal use and are not indicative of any problem(s). No need to log them.
    # TODO: Better filter what we choose to log here
    retry_errs = RETRY_ERRS + ['out of gas','error processing call revert']
    stre = str(e).lower()
    if any(err in stre for err in retry_errs):
        return
    main_logger.exception(e)

def _reattempt_call_and_return_exception(target: ChecksumAddress, calldata: bytes, block: BlockId, w3: Web3) -> Union[bytes, Exception]:
    """ NOTE: This runs synchronously in a subprocess in order to bypass Dank Middleware without blocking the event loop. """
    try:
        return w3.eth.call({"to": target, "data": calldata}, block)
    except Exception as e:
        _log_exception(e)
        return e

def _err_response(e: Exception) -> RPCError:
    """ Extract an error message from `e` to use in a spoof rpc response. """
    if isinstance(e.args[0], str) or isinstance(e.args[0], RequestInfo):
        err_msg = f"DankMidsError: {e.__class__.__name__}: {e.args}"
    elif isinstance(e.args[0], Exception):
        err_msg = f"DankMidsError: {e.args[0].__class__.__name__}: {e.args[0].args}"
    elif not hasattr(e.args[0], '__contains__'):
        err_msg = f"DankMidsError: {e.__class__.__name__}: {e.args}"
    elif "message" in e.args[0]:
        err_msg = e.args[0]["message"]
    elif "error" in e.args[0] and hasattr(e.args[0]["error"], '__contains__') and "message" in e.args[0]["error"]:
        err_msg = e.args[0]["error"]["message"]
    else:
        raise e
    return {'code': -32000, 'message': err_msg, 'data': ''}


_Response = TypeVar("_Response", RPCResponse, List[RPCResponse])

class _RequestMeta(Generic[_Response], metaclass=abc.ABCMeta):
    def __init__(self) -> None:
        if isinstance(self, RPCRequest):
            self.uid = self.controller.call_uid.next
        elif isinstance(self, _Batch):
            self.uid = self.worker.controller.call_uid.next
        self._response: Optional[_Response] = None
        self._done = asyncio.Event()
    
    def __await__(self) -> Generator[Any, None, Optional[_Response]]:
        return self.get_response().__await__()
    
    @abc.abstractmethod
    def __len__(self) -> int:
        pass

    @property
    def response(self) -> _Response:
        if not self._done.is_set():
            raise ResponseNotReady(self)
        return self._response

    @abc.abstractmethod
    async def get_response(self) -> Optional[_Response]:
        pass

### Single requests:

class RPCRequest(_RequestMeta[RPCResponse]):
    def __init__(self, controller: "DankMiddlewareController", method: RPCEndpoint, params: Any):
        self.controller = controller
        self.method = method
        self.params = params
        super().__init__()
        
        if isinstance(self, eth_call) and self.multicall_compatible:
            self.controller.pending_eth_calls.append(self)
        else:
            self.controller.pending_rpc_calls.append(self)
        demo_logger.info(f'added to queue (cid: {self.uid})')  # type: ignore
    
    def __eq__(self, __o: object) -> bool:
        return self.uid == __o.uid if isinstance(__o, self.__class__) else False 
    
    def __hash__(self) -> int:
        return self.uid
    
    def __len__(self) -> int:
        return 1
    
    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} uid={self.uid} method={self.method}>"

    @property
    def rpc_data(self) -> RpcCallJson:
        return {'jsonrpc': '2.0', 'id': self.uid, 'method': self.method, 'params': self.params}

    async def get_response(self) -> RPCResponse:
        if not self.controller.is_running:
            await self.controller.taskmaster_loop()
        await self._done.wait()
        return self.response
    
    async def spoof_response(self, data: Union[str, AttributeDict, Exception]) -> None:
        spoof = {"id": self.uid, "jsonrpc": "dank_mids"}
        if isinstance(data, Exception):
            spoof["error"] = _err_response(data)
        else:
            spoof["result"] = data  # type: ignore
        if isinstance(self, eth_call):
            main_logger.debug(f"method: eth_call  address: {self.target}  spoof: {spoof}")
        else:
            main_logger.debug(f"method: {self.method}  spoof: {spoof}")
        self._response = spoof  # type: ignore
        self._done.set()

class eth_call(RPCRequest):
    def __init__(self, controller: "DankMiddlewareController", params: Any) -> None:
        """ Adds a call to the DankMiddlewareContoller's `pending_eth_calls`. """
        super().__init__(controller, "eth_call", params)  # type: ignore
    
    @property
    def block(self) -> BlockId:
        return self.params[1]
    
    @property
    def calldata(self) -> HexBytes:
        return HexBytes(self.params[0]['data'])
    
    @property
    def multicall_compatible(self) -> bool:
        return self.target not in self.controller.no_multicall

    @property
    def target(self) -> str:
        return self.params[0]["to"]

    async def spoof_response(self, data: Union[bytes, Exception]) -> None:  # type: ignore
        """ Sets and returns a spoof rpc response for this BatchedCall instance using data provided by the worker. """
        # NOTE: If multicall failed, make sync call to get either:
        # - revert details
        # - successful response
        if _call_failed(data):
            data = await self.sync_call()
        await super().spoof_response(data.hex() if isinstance(data, bytes) else data)

    async def sync_call(self) -> Union[bytes, Exception]:
        """ Used to bypass DankMiddlewareController. """
        data = await run_in_subprocess(
            _reattempt_call_and_return_exception, self.target, self.calldata, self.block, self.controller.sync_w3
        )
        # If we were able to get a usable response from single call, add contract to `do_not_batch`.
        if not isinstance(data, Exception):
            self.controller.no_multicall.add(self.target)  # type: ignore
        return data


### Batch requests:

_Request = TypeVar("_Request")

class _Batch(_RequestMeta[List[RPCResponse]], Iterable[_Request]):
    calls: List[_Request]

    def __init__(self, worker: "DankWorker", calls: Iterable[_Request]):
        self.worker: DankWorker = worker
        self.calls = list(calls)  # type: ignore
        super().__init__()
    
    def __bool__(self) -> bool:
        return bool(self.calls)
    
    def __getitem__(self, ix: int) -> _Request:
        return self.calls[ix]

    def __iter__(self) -> Iterator[_Request]:
        return iter(self.calls)
    
    def __len__(self) -> int:
        return len(self.calls)
    
    def append(self, call: _Request) -> None:
        self.calls.append(call)
    
    @property
    def controller(self) -> "DankMiddlewareController":
        return self.worker.controller
    
    @property
    def halfpoint(self) -> int:
        return len(self) // 2
    
    @property
    def bisected(self) -> Generator[List[_Request], None, None]:
        yield self.chunk0
        yield self.chunk1
        
    @property
    def chunk0(self) -> List[_Request]:
        return self.calls[:self.halfpoint]
    
    @property
    def chunk1(self) -> List[_Request]:
        return self.calls[self.halfpoint:]
    
    def should_retry(self, e: Exception) -> bool:
        if "out of gas" in f"{e}":
            # TODO Remember which contracts/calls are gas guzzlers
            main_logger.debug('out of gas. cut in half, trying again')
        elif any(err in f"{e}".lower() for err in RETRY_ERRS):
            # TODO: use these exceptions to optimize for the user's node
            main_logger.debug('Dank too loud. Bisecting batch and retrying.')
        elif "error processing call Revert" not in f"{e}":
            main_logger.warning(f"unexpected {e.__class__.__name__}: {e}")
        return len(self) > 1


class Multicall(_Batch[eth_call]):
    """ Runs in worker thread. """
    method = "eth_call"
    fourbyte = function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")
    input_types = "(bool,(address,bytes)[])"
    output_types = "(uint256,uint256,(bool,bytes)[])"

    def __init__(self, worker: "DankWorker", calls: List[eth_call] = [], bid: Optional[BatchId] = None):
        super().__init__(worker, calls)
        self.bid = bid or self.worker.multicall_uid.next
    
    def __repr__(self) -> str:
        return f"<Multicall mid={self.bid} block={self.block} len={len(self)}>"
    
    @property
    def block(self) -> BlockId:
        return self.calls[0].block
    
    @property
    def calldata(self) -> str:
        return (self.fourbyte + encode_single(self.input_types, [False, [[call.target, call.calldata] for call in self.calls]])).hex()
    
    @property
    def target(self) -> ChecksumAddress:
        return self.worker.target
    
    @property
    def params(self) -> JsonrpcParams:
        if self.worker.state_override_not_supported:
            return [{'to': self.target, 'data': '0x' + self.calldata}, self.block]  # type: ignore
        return [{'to': self.target, 'data': '0x' + self.calldata}, self.block, {self.target: {'code': OVERRIDE_CODE}}]  # type: ignore
    
    @property
    def rpc_data(self) -> RpcCallJson:
        return {'jsonrpc': '2.0', 'id': self.uid, 'method': self.method, 'params': self.params}

    async def get_response(self) -> List[RPCResponse]:
        rid = self.worker.request_uid.next
        demo_logger.info(f'request {rid} for multicall {self.bid} starting')  # type: ignore
        try:
            await self.spoof_response(await self.worker(*self.params))
        except Exception as e:
            _log_exception(e)
            await (self.bisect_and_retry() if self.should_retry(e) else self.spoof_response(e))  # type: ignore [misc]
        demo_logger.info(f'request {rid} for multicall {self.bid} complete')  # type: ignore
    
    def should_retry(self, e: Exception) -> bool:
        if any(err in f"{e}".lower() for err in RETRY_ERRS):
            main_logger.debug('dank too loud, trying again')
            self.controller.reduce_batch_size(len(self))
            return True
        elif "No state available for block" in f"{e}":  # NOTE: While it might look weird, f-string is faster than `str(e)`.
            e.args[0]["dankmids_note"] = "You're not using an archive node, and you need one for the application you are attempting to run."
            return False
        elif super().should_retry(e):
            return True
        return len(self) > 1
    
    async def spoof_response(self, data: Union[bytes, str, Exception]) -> None:
        """
        If called from `self`, `response` will be bytes type.
        if called from a JSONRPCBatch, `response` will be str type.
        """ 
        if isinstance(data, Exception):
            await await_all(call.spoof_response(data) for call in self.calls)
        else:
            decoded: List[Tuple[bool, bytes]]
            _, _, decoded = await run_in_subprocess(decode_single, self.output_types, to_bytes(data))
            await await_all(call.spoof_response(data) for call, (_, data) in zip(self.calls, decoded))
    
    async def bisect_and_retry(self) -> List[RPCResponse]:
        await await_all((Multicall(self.worker, chunk, f"{self.bid}_{i}") for i, chunk in enumerate(self.bisected)))


class BadResponse(Exception):
    pass

class EmptyBatch(Exception):
    pass

class JSONRPCBatch(_Batch[Union[Multicall, RPCRequest]]):
    def __init__(
        self,
        worker: "DankWorker",
        calls: List[Union[Multicall, RPCRequest]] = [], 
        jid: Optional[BatchId] = None
    ) -> None:
        super().__init__(worker, calls)
        self.jid = jid or self.worker.jsonrpc_batch_uid.next
        self._locked = False
    
    @property
    def data(self) -> List[RpcCallJson]:
        if not self.calls:
            raise EmptyBatch(f"batch {self.uid} is empty and should not be processed.")
        return [call.rpc_data for call in self.calls]
    
    @property
    def is_multicalls_only(self) -> bool:
        return all(isinstance(call, Multicall) for call in self.calls)

    @property
    def is_single_multicall(self) -> bool:
        return len(self) == 1 and self.is_multicalls_only

    @property
    def method_counts(self) -> Dict[RPCEndpoint, int]:
        counts: DefaultDict[RPCEndpoint, int] = defaultdict(int)
        for call in self.calls:
            counts[call.method] += len(call)  # type: ignore
        return dict(counts)
    
    @property
    def total_calls(self) -> int:
        return sum(len(call) for call in self.calls)

    def append(self, call: Union[Multicall, RPCRequest]) -> None:
        if self._locked:
            raise Exception(f"{self} is locked.")
        self.calls.append(call)
    
    async def get_response(self) -> None:
        """ Runs in worker thread. """
        self._locked = True
        rid = self.worker.request_uid.next
        if _config.DEMO_MODE:
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} ({sum(len(batch) for batch in self.calls)} calls) starting')  # type: ignore
        try:
            # NOTE: We do this inline so we never have to allocate the response to memory
            await self.spoof_response(self.validate_responses(await self.post()))
        except EmptyBatch as e:
            _log_exception(e)
        except Exception as e:
            _log_exception(e)
            await (self.bisect_and_retry() if self.should_retry(e) else self.spoof_response(e))
        demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} complete')  # type: ignore
    
    @eth_retry.auto_retry
    async def post(self) -> Union[Dict, List[bytes]]:
        session = await _session.get_session()
        async with session.post(self.controller.endpoint, json=self.data) as response:
            response = await response.json()
            if isinstance(response, List):
                return response
            elif isinstance(response, Tuple):
                reason, e = response
                counts = self.method_counts
                main_logger.warning(f"{e.__class__.__name__}: {e}")
                main_logger.info(f"json batch id: {self.jid} | len: {len(self)} | total calls: {self.total_calls}", )
                main_logger.info(f"methods called: {counts}")
                if 'content length too large' in str(e) and self.is_multicalls_only:
                    self.controller.reduce_batch_size(self.total_calls)
                raise e
            raise NotImplementedError(response.__class__.__name__, response)
    
    def should_retry(self, e: Exception) -> bool:
        # While it might look weird, f-string is faster than `str(e)`.
        if "No state available for block" in f"{e}":
            main_logger.debug('No state available for queried block. Bisecting batch and retrying.')
            return True
        elif super().should_retry(e):
            return True
        return self.is_single_multicall
    
    async def spoof_response(self, response: Union[List[RPCResponse], Exception]) -> None:
        if isinstance(response, Exception):
            return await await_all(call.spoof_response(response) for call in self.calls)
        return await await_all(
            # NOTE: For some rpc methods, the result will be a dict we can't hash during the gather.
            call.spoof_response(AttributeDict(result["result"]) if isinstance(result["result"], dict) else result["result"])  # type: ignore
            for call, result in zip(self.calls, response)
        )
    
    def validate_responses(self, responses) -> None:
        # A successful response will be a list
        if isinstance(responses, dict):
            err = responses
            if 'result' in err:
                err = responses['result']
            if isinstance(err, dict) and 'message' in err:
                err = err['message']
            raise BadResponse(err)
        for i, error in enumerate(responses):
            if 'result' not in error:
                error = error['error'] if 'error' in error else error
                raise BadResponse(self.calls[i], self.calls[i].params, error)
        return responses
    
    async def bisect_and_retry(self) -> None:
        await await_all(
            Multicall(self.worker, chunk[0].calls, f"json{self.jid}_{i}")  # type: ignore [misc]
            if len(chunk) == 1 and isinstance(chunk[0], Multicall)
            else JSONRPCBatch(self.worker, chunk, f"{self.jid}_{i}")
            for i, chunk in enumerate(self.bisected)
            if chunk
        )
