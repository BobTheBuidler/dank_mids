
import abc
import asyncio
from collections import defaultdict
from typing import (TYPE_CHECKING, Any, DefaultDict, Dict, Generator, Generic,
                    Iterable, Iterator, List, Optional, Tuple, Type, TypeVar,
                    Union)

import eth_retry
from aiohttp import RequestInfo
from eth_abi import abi, decoding
from eth_typing import ChecksumAddress
from eth_utils import function_signature_to_4byte_selector
from hexbytes import HexBytes
from msgspec import Raw, ValidationError
from msgspec.json import decode
from multicall.utils import run_in_subprocess
from web3 import Web3
from web3.datastructures import AttributeDict
from web3.types import RPCEndpoint, RPCError, RPCResponse

from dank_mids import _config
from dank_mids._demo_mode import demo_logger
from dank_mids._exceptions import BadResponse, EmptyBatch
from dank_mids.constants import BAD_HEXES, OVERRIDE_CODE
from dank_mids.helpers import _json, _session
from dank_mids.loggers import main_logger
from dank_mids.types import BatchId, BlockId, JsonrpcParams, RpcCallJson

if TYPE_CHECKING:
    from dank_mids.controller import DankMiddlewareController
    from dank_mids.worker import DankWorker

RETRY_ERRS = ["connection reset by peer","request entity too large","server disconnected","execution aborted (timeout = 5s)"]

class ResponseNotReady(Exception):
    pass

def _call_failed(data: Union[_json.Response, Raw, bytes, Exception]) -> bool:
    # TODO: make this handle Response and Raw correctly
    """ Returns True if `data` indicates a failed response, False otherwise. """
    if data is None:
        return True
    # If we got a known "bad" response from the multicall, that is also a failure.
    # Most likely the target contract does not support multicall2.
    elif isinstance(data, bytes) and f"0x{data.hex()}" in BAD_HEXES:
        return True
    return False

def _log_exception(e: Exception) -> None:
    # NOTE: These errors are expected during normal use and are not indicative of any problem(s). No need to log them.
    # TODO: Better filter what we choose to log here
    dont_need_to_see_errs = RETRY_ERRS + ['out of gas','error processing call revert', 'non_empty_data', 'invalid ether transfer']
    stre = str(e).lower()
    if any(err in stre for err in dont_need_to_see_errs):
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
    if isinstance(e, BadResponse):
        return e.response.error.to_dict()

    # TODO: figure out which of these I still need after the above refactor
    elif isinstance(e.args[0], (str, RequestInfo)):
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
        self.uid = self.controller.call_uid.next
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
    dict_responses = set()
    str_responses = set()

    _types = set()

    def __init__(self, controller: "DankMiddlewareController", method: RPCEndpoint, params: Any):
        self.controller = controller
        self.method = method
        self.params = params
        self._started = False
        super().__init__()
        
        if isinstance(self, eth_call) and self.multicall_compatible:
            self.controller.pending_eth_calls[self.block].append(self)
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
    
    def __del__(self) -> None:
        """Just lets the user know if there is something fishy going on"""
        try:
            if not self._started and self._batch and self._batch._started:
                main_logger.warning(f'{self} was created and destroyed.')
        except AttributeError as e:
            print(e)
        except Exception as e:
            main_logger.exception(e)

    @property
    def rpc_data(self) -> RpcCallJson:
        return {'jsonrpc': '2.0', 'id': self.uid, 'method': self.method, 'params': self.params}
    
    def start(self, batch: "_Batch") -> None:
        self._started = True
        self._batch = batch

    async def get_response(self) -> RPCResponse:
        if self._started and not self._batch._started:
            # NOTE: If we're already started, we filled a batch. Let's await it now so we can send something to the node.
            await self._batch
        if not self._started:
            # NOTE: We want to force the event loop to make one full _run_once call before we execute.
            await asyncio.sleep(0)
        if not self._started:
            await self.controller.execute_batch()
        
        # TODO: Remove this
        async def debug_helper():
        #    print(f'fetching {self} from {self._batch}  started: {self._batch._started}')
            while not self._done.is_set():
                await asyncio.sleep(60)
                if not self._done.is_set() and not self._batch._started:
                    print(f"{self} from {self._batch} event not set and batch not started.")
        t = asyncio.create_task(
            asyncio.wait_for(debug_helper(), 300)
        )
        await self._done.wait()

        # JIT json decoding
        if isinstance(self.response, _json.Response):
            return self.response.to_dict(self.method)
        # Less optimal decoding
        # TODO: refactor this out
        return self.response
    
    async def spoof_response(self, data: Union[_json.Response, Raw, bytes, Exception]) -> None:
        """
        `Raw` type data comes from rpc calls executed in a jsonrpc batch
        `bytes` type data comes for individual eth_calls that were batched into multicalls and already decoded
        `Exception` type data comes from failed calls
        """
        # TODO: refactor this so Raw decoding doesn't occur until the caller requests the result.
        
        # New handler
        if isinstance(data, _json.Response):
            self._response = data
            self._done.set()
            return

        # Old handler (once we use msgspec for single multicalls all `data` will be a Response)
        spoof = {"id": self.uid, "jsonrpc": "dank_mids"}
        if isinstance(data, Exception):
            spoof["error"] = _err_response(data)
        elif isinstance(data, Raw):
            spoof["result"] = self._decode_raw(data)
        elif isinstance(data, bytes):
            spoof["result"] = data
        else:
            raise TypeError('b', type(data), data)
        
        if isinstance(self, eth_call):
            main_logger.debug(f"method: eth_call  address: {self.target}  spoof: {spoof}")
        else:
            main_logger.debug(f"method: {self.method}  spoof: {spoof}")
        self._response = spoof  # type: ignore
        self._done.set()

    def _decode_raw(self, data: Raw) -> Union[str, AttributeDict]:
        # NOTE: These must be added to the `RETURN_TYPES` constant above manually
        if typ := _json.RETURN_TYPES.get(self.method):
            try:
                decoded = decode(data, type=typ)
                return AttributeDict(decoded) if isinstance(decoded, dict) else decoded
            except ValidationError as e:
                main_logger.exception(e)

        # We have some semi-smart logic for providing decoder hints even if method not in `RETURN_TYPES`
        try:
            if self.method in self.dict_responses:
                # TODO: Refactor this
                list_of_stuff = List[Union[str, None, dict, list]]
                dict_of_stuff = Dict[str, Union[str, None, list_of_stuff, Dict[str, Optional[Any]]]]
                nested_dict_of_stuff = Dict[str, Union[str, None, list_of_stuff, dict_of_stuff]]

                decoded = AttributeDict(decode(data, type=nested_dict_of_stuff))
                types = {type(v) for v in decoded.values()}
                print(f'my method and types: {self.method} {types}')
                if list in types:
                    lists = [v for v in decoded.values() if isinstance(v, list)]
                    for lst in lists:
                        lst_types = {type(_) for _ in lst}
                        print(f"list types: {lst_types}")
                self._types.update(types)
                return decoded
            elif self.method in self.str_responses:
                print(f'Must add `{self.method}: str` to `RETURN_TYPES`')
                return decode(data, type=str)
            
            # In this case we can provide no hints, let's let the decoder figure it out
            decoded = decode(data)
            if isinstance(decoded, str):
                self.str_responses.add(self.method)
                return decoded
            elif isinstance(decoded, dict):
                self.dict_responses.add(self.method)
                return AttributeDict(decoded)
            raise TypeError('c', type(decoded), decoded)
        except ValidationError as e:
            raise ValidationError(self.rpc_data, e) from e

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
        await super().spoof_response(data)

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
        self._fut = None
        #self._len = 0
        super().__init__()
    
    def __bool__(self) -> bool:
        return bool(self.calls)
    
    def __getitem__(self, ix: int) -> _Request:
        return self.calls[ix]

    def __iter__(self) -> Iterator[_Request]:
        return iter(self.calls)
    
    def __len__(self) -> int:
        return len(self.calls)

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
    
    def append(self, call: _Request, skip_check: bool = False) -> None:
        self.calls.append(call)
        #self._len += 1
        if not skip_check:
            if self.is_full:
                self.start()
            elif sum(len(multicall) for multicall in self.controller.pending_eth_calls.values()) >= self.controller.batcher.step:
                self.controller.early_start()
    
    def extend(self, calls: Iterable[_Request], skip_check: bool = False) -> None:
        self.calls.extend(calls)
        #self._len += len(calls)
        if not skip_check:
            if self.is_full:
                self.start()
            elif sum(len(multicall) for multicall in self.controller.pending_eth_calls.values()) >= self.controller.batcher.step:
                self.controller.early_start()

    def start(self, batch: Optional["_Batch"] = None, cleanup=True) -> None:
        for call in self.calls:
            call.start(batch or self)
        if cleanup:
            self._post_future_cleanup()

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


mcall_encoder = abi.default_codec._registry.get_encoder("(bool,(address,bytes)[])")
mcall_decoder = abi.default_codec._registry.get_decoder("(uint256,uint256,(bool,bytes)[])")

class Multicall(_Batch[eth_call]):
    method = "eth_call"
    fourbyte = function_signature_to_4byte_selector("tryBlockAndAggregate(bool,(address,bytes)[])")    

    def __init__(self, worker: "DankWorker", calls: List[eth_call] = [], bid: Optional[BatchId] = None):
        super().__init__(worker, calls)
        self.bid = bid or self.controller.multicall_uid.next
        self._started = False
    
    def __repr__(self) -> str:
        return f"<Multicall mid={self.bid} block={self.block} len={len(self)}>"
    
    @property
    def block(self) -> BlockId:
        return self.calls[0].block
    
    @property
    def calldata(self) -> str:
        return (self.fourbyte + mcall_encoder([False, [[call.target, call.calldata] for call in self.calls]])).hex()
    
    @property
    def target(self) -> ChecksumAddress:
        return self.worker.target
    
    @property
    def params(self) -> JsonrpcParams:
        if self.worker.state_override_not_supported:
            return [{'to': self.target, 'data': f'0x{self.calldata}'}, self.block]  # type: ignore
        return [{'to': self.target, 'data': f'0x{self.calldata}'}, self.block, {self.target: {'code': OVERRIDE_CODE}}]  # type: ignore
    
    @property
    def rpc_data(self) -> RpcCallJson:
        return {'jsonrpc': '2.0', 'id': self.uid, 'method': self.method, 'params': self.params}
    
    @property
    def is_full(self) -> bool:
        return len(self) >= self.controller.batcher.step

    async def get_response(self) -> None:
        if self._started:
            main_logger.warning(f'{self} early exit')
            return
        self._started = True
        rid = self.controller.request_uid.next
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
    
    async def spoof_response(self, data: Union[_json.Response, Exception]) -> None:
        # This happens if an Exception takes place during a singular Multicall request.
        if isinstance(data, Exception):
            return await asyncio.gather(*[call.spoof_response(data) for call in self.calls])
        # These can either be successful or failed, received from jsonrpc batch handling.
        elif isinstance(data, _json.Response) and data.error:
            raise data.exception
        await asyncio.gather(*(call.spoof_response(data) for call, (_, data) in zip(self.calls, self.decode(data))))
    
    @staticmethod
    def decode(data: _json.Response) -> List[Tuple[bool, bytes]]:
        data = bytes.fromhex(data.decode_result("eth_call")[2:])
        return mcall_decoder(decoding.ContextFramesBytesIO(data))[2]
    
    async def bisect_and_retry(self) -> List[RPCResponse]:
        batches = [Multicall(self.worker, chunk, f"{self.bid}_{i}") for i, chunk in enumerate(self.bisected)]
        for batch in batches:
            batch.start(cleanup=False)
        await asyncio.gather(*batches)

    def _post_future_cleanup(self) -> None:
        try:
            # This will have already taken place in a full json batch of multicalls
            for call in self.controller.pending_eth_calls.pop(self.block):
                assert call._started
        except KeyError:
            pass


class JSONRPCBatch(_Batch[Union[Multicall, RPCRequest]]):
    def __init__(
        self,
        worker: "DankWorker",
        calls: List[Union[Multicall, RPCRequest]] = [], 
        jid: Optional[BatchId] = None
    ) -> None:
        super().__init__(worker, calls)
        self.jid = jid or self.controller.jsonrpc_batch_uid.next
        self._started = False

    def __repr__(self) -> str:
        return f"<JSONRPCBatch jid={self.jid} len={len(self)}>"
    
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

    @property
    def is_full(self) -> bool:
        return (self.is_multicalls_only and len(self) >= self.controller.batcher.step) or len(self) >= _config.MAX_JSONRPC_BATCH_SIZE

    def append(self, call: Union[Multicall, RPCRequest], skip_check: bool = False) -> None:
        if self._started:
            # This shouldn't happen but just in case...
            raise RuntimeError(f"{self} is already started.")
        super().append(call, skip_check=skip_check)

    def extend(self, call: Union[Multicall, RPCRequest], skip_check: bool = False) -> None:
        if self._started:
            # This shouldn't happen but just in case...
            raise RuntimeError(f"{self} is already started.")
        super().extend(call, skip_check=skip_check)
    
    async def get_response(self) -> None:
        if self._started:
            main_logger.warning(f"{self} exiting early. This shouldn't really happen bro")
            return
        self._started = True
        rid = self.controller.request_uid.next
        if _config.DEMO_MODE:
            # When demo mode is disabled, we can save some CPU time by skipping this sum
            demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} ({sum(len(batch) for batch in self.calls)} calls) starting')  # type: ignore
        try:
            # NOTE: We do this inline so we never have to allocate the response to memory
            await self.spoof_response(await self.post())
        except EmptyBatch as e:
            # NOTE: These shouldn't actually happen and this except clause can probably be removed soon.
            _log_exception(e)
        except Exception as e:
            _log_exception(e)
            await (self.bisect_and_retry() if self.should_retry(e) else self.spoof_response(e))
        demo_logger.info(f'request {rid} for jsonrpc batch {self.jid} complete')  # type: ignore
    
    @eth_retry.auto_retry
    async def post(self) -> List[RPCResponse]:
        session = await _session.get_session()
        async with session.post(self.controller.endpoint, json=self.data) as response:
            response: Union[_json.JSONRPCBatchResponse, _json.Response] = await response.json(loads=_json.decode_jsonrpc_batch)
            # A successful response will be a list of Response objects, a single Response implies an error.
            if isinstance(response, list):
                return response
            # Oops, we failed.
            main_logger.info(
                "jsonrpc batch failed\n"
                + f"json batch id: {self.jid} | len: {len(self)} | total calls: {self.total_calls}\n"
                + f"methods called: {self.method_counts}"
            )
            if 'content length too large' in response.error.message and self.is_multicalls_only:
                self.controller.reduce_batch_size(self.total_calls)
            raise response.exception
    
    def should_retry(self, e: Exception) -> bool:
        # While it might look weird, f-string is faster than `str(e)`.
        if "No state available for block" in f"{e}":
            main_logger.debug('No state available for queried block. Bisecting batch and retrying.')
            return True
        elif super().should_retry(e):
            return True
        return self.is_single_multicall
    
    async def spoof_response(self, response: Union[_json.JSONRPCBatchResponse, Exception]) -> None:
        # This means an exception occurred during the post request
        if isinstance(response, Exception):
            return await asyncio.gather(*[call.spoof_response(response) for call in self.calls])
        # This means we got results
        return await asyncio.gather(*[call.spoof_response(result) for call, result in zip(self.calls, response)])
    
    async def bisect_and_retry(self) -> None:
        batches = [
            Multicall(self.worker, chunk[0].calls, f"json{self.jid}_{i}")  # type: ignore [misc]
            if len(chunk) == 1 and isinstance(chunk[0], Multicall)
            else JSONRPCBatch(self.worker, chunk, f"{self.jid}_{i}")
            for i, chunk in enumerate(self.bisected)
            if chunk
        ]
        for batch in batches:
            batch.start(cleanup=False)
        await asyncio.gather(*batches)

    def _post_future_cleanup(self) -> None:
        self.controller.pending_rpc_calls = JSONRPCBatch(self.worker)
