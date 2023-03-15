
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
from multicall.utils import gather, run_in_subprocess
from web3 import Web3
from web3.datastructures import AttributeDict
from web3.types import RPCEndpoint, RPCError, RPCResponse

from dank_mids._config import (AIOHTTP_TIMEOUT, DEMO_MODE,
                               MAX_JSONRPC_BATCH_SIZE)
from dank_mids._demo_mode import demo_logger
from dank_mids.constants import BAD_HEXES, OVERRIDE_CODE
from dank_mids.loggers import main_logger
from dank_mids.types import (BatchId, BlockId, JsonrpcParams,
                             RpcCallJson)

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    from dank_mids.worker import DankWorker


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

def _reattempt_call_and_return_exception(target: ChecksumAddress, calldata: bytes, block: BlockId, w3: Web3) -> Union[bytes, Exception]:
    """ NOTE: This runs synchronously in a subprocess in order to bypass Dank Middleware without blocking the event loop. """
    try:
        return w3.eth.call({"to": target, "data": calldata}, block)
    except Exception as e:
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
    
    def __await__(self) -> Generator[Any, None, _Response]:
        return self.get_response().__await__()
    
    @abc.abstractmethod
    def __len__(self) -> int:
        pass

    @property
    def is_complete(self) -> bool:
        return self._response is not None
    
    @property
    def response(self) -> _Response:
        if self._response is None:
            raise ResponseNotReady(self)
        return self._response

    @abc.abstractmethod
    async def get_response(self) -> _Response:
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
        if not isinstance(__o, self.__class__):
            return False
        return self.uid == __o.uid 
    
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
        while not self.is_complete:
            await asyncio.sleep(0)
        return self.response
    
    async def spoof_response(self, data: Union[str, AttributeDict, Exception]) -> RPCResponse:
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
        return spoof  # type: ignore


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

    async def spoof_response(self, data: Union[bytes, Exception]) -> RPCResponse:  # type: ignore
        """ Sets and returns a spoof rpc response for this BatchedCall instance using data provided by the worker. """
        # NOTE: If multicall failed, make sync call to get either:
        # - revert details
        # - successful response
        if _call_failed(data):
            data = await self.sync_call()
        return await super().spoof_response(data.hex() if isinstance(data, bytes) else data)

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
    def chunk0(self) -> List[_Request]:
        return self.calls[:self.halfpoint]
    
    @property
    def chunk1(self) -> List[_Request]:
        return self.calls[self.halfpoint:]
    
    def should_retry(self, e: Exception) -> bool:
        if "out of gas" in f"{e}":
            # TODO Remember which contracts/calls are gas guzzlers
            main_logger.debug('out of gas. cut in half, trying again')
        elif any(err in f"{e}".lower() for err in ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]):
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
        multicall_args = [False, [[call.target, call.calldata] for call in self.calls]]
        data = self.fourbyte + encode_single(self.input_types, multicall_args)
        return data.hex()
    
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
            response = await self.worker(*self.params)
            response = await self.spoof_response(response)
        except Exception as e:
            response = await (self.bisect_and_retry() if self.should_retry(e) else self.spoof_response(e))                
        demo_logger.info(f'request {rid} for multicall {self.bid} complete')  # type: ignore
        return response
    
    def should_retry(self, e: Exception) -> bool:
        if any(err in f"{e}".lower() for err in ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]):
            main_logger.debug('dank too loud, trying again')
            self.controller.reduce_batch_size(len(self))
            return True
        elif "No state available for block" in f"{e}":  # NOTE: While it might look weird, f-string is faster than `str(e)`.
            e.args[0]["dankmids_note"] = "You're not using an archive node, and you need one for the application you are attempting to run."
            return False
        elif super().should_retry(e):
            return True
        return len(self) > 1
    
    async def spoof_response(self, data: Union[bytes, str, Exception]) -> List[RPCResponse]:
        """
        If called from `self`, `response` will be bytes type.
        if called from a JSONRPCBatch, `response` will be str type.
        """ 
        if isinstance(data, Exception):
            self._response = await gather([call.spoof_response(data) for call in self.calls])
        else:
            decoded: List[Tuple[bool, bytes]]
            _, _, decoded = await run_in_subprocess(decode_single, self.output_types, to_bytes(data))
            self._response = await gather([call.spoof_response(data) for call, (_, data) in zip(self.calls, decoded)])
        return self._response  # type: ignore
    
    async def bisect_and_retry(self) -> List[RPCResponse]:
        return await gather([Multicall(self.worker, self.chunk0, f"{self.bid}_0"), Multicall(self.worker, self.chunk1, f"{self.bid}_1")])


class JSONRPCBatch(_Batch[Union[Multicall, RPCRequest]]):
    def __init__(self, worker: "DankWorker", calls: List[Union[Multicall, RPCRequest]] = [], jid: Optional[BatchId] = None) -> None:
        super().__init__(worker, calls)
        self.jid = jid or self.worker.jsonrpc_batch_uid.next
        self._locked = False
    
    @property
    def data(self) -> List[RpcCallJson]:
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
    
    async def get_response(self) -> List[RPCResponse]:
        """ Runs in worker thread. """
        self._locked = True
        rid = self.worker.request_uid.next
        if DEMO_MODE:
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} ({sum(len(batch) for batch in self.calls)} calls) starting')  # type: ignore
        try:
            responses = await self.post()
            self.validate_responses(responses)
            response = await self.spoof_response(responses)
        except Exception as e:
            response = await (self.bisect_and_retry() if self.should_retry(e) else self.spoof_response(e))
        demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} complete')  # type: ignore
        return response
    
    @eth_retry.auto_retry
    async def post(self) -> Union[Dict, List[bytes]]:
        """ Posts `jsonrpc_batch` to your node. A successful call returns a list. """
        async with aiohttp.ClientSession(timeout=AIOHTTP_TIMEOUT) as session:
            responses = await session.post(self.worker.endpoint, json=self.data)  # type: ignore
            try:
                return await responses.json(content_type=responses.content_type)
            except:
                counts = self.method_counts
                decoded = responses._body.decode()
                main_logger.info(f"json batch id: {self.jid} | len: {len(self)} | total calls: {self.total_calls}", )
                main_logger.info(f"methods called: {counts}")
                if 'content length too large' in decoded or decoded == "":
                    if self.is_multicalls_only:
                        self.controller.reduce_batch_size(self.total_calls)
                    raise ValueError(decoded)
                # This shouldn't run unless there are issues. I'll probably delete it later.
                main_logger.info(f"decoded body: {decoded}")
                main_logger.info(f"exception: {responses.content._exception}")
                raise 
    
    def should_retry(self, e: Exception) -> bool:
        # While it might look weird, f-string is faster than `str(e)`.
        if "No state available for block" in f"{e}":
            main_logger.debug('No state available for queried block. Bisecting batch and retrying.')
            return True
        elif f"{e}" == "jsonrpc":
            # TODO Figure out what this means and how we can prevent it.
            # For now, we simply bisect and retry.
            return True
        elif super().should_retry(e):
            return True
        return self.is_single_multicall
    
    async def spoof_response(self, response: Union[List[RPCResponse], Exception]) -> List[RPCResponse]:
        if isinstance(response, Exception):
            return await gather(call.spoof_response(response) for call in self.calls)
        return await gather([
            # NOTE: For some rpc methods, the result will be a dict we can't hash during the gather.
            call.spoof_response(AttributeDict(result["result"]) if isinstance(result["result"], dict) else result["result"])  # type: ignore
            for call, result in zip(self.calls, response)
        ])
    
    def validate_responses(self, responses) -> None:
        # A successful response will be a list
        if isinstance(responses, dict) and 'result' in responses and isinstance(responses['result'], dict) and 'message' in responses['result']:
            raise ValueError(responses['result']['message'])
        for response in responses:
            if 'result' not in response:
                raise ValueError(response)
    
    async def bisect_and_retry(self) -> List[RPCResponse]:
        response = await gather([
            Multicall(self.worker, chunk[0].calls, f"json{self.jid}_{i}")
            if len(chunk) == 1 and isinstance(chunk[0], Multicall)
            else JSONRPCBatch(self.worker, chunk, f"{self.jid}_{i}")
            for i, chunk in enumerate([self.chunk0, self.chunk1])
            if chunk
        ])
        return response
