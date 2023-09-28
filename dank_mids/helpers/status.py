import asyncio
import logging
from enum import IntEnum
from functools import wraps
from typing import TYPE_CHECKING, Awaitable, Callable, TypeVar

from typing_extensions import ParamSpec
from web3.exceptions import ContractLogicError

from dank_mids import constants
from dank_mids._exceptions import BadRequest, BadGateway, BrokenPipe

if TYPE_CHECKING:
    from dank_mids.requests import RPCRequest

T = TypeVar("T")
P = ParamSpec("P")

logger = logging.getLogger(__name__)

class Status(IntEnum):
    QUEUED = 0
    ACTIVE = 1
    COMPLETE = 2
    CANCELED = 3
    FAILED = 4
    REBATCHED = 5
    TIMED_OUT = 6
    DUPLICATED = 7
        
    @staticmethod
    def for_exc(e: Exception):
        if isinstance(e, asyncio.CancelledError):
            return Status.CANCELED
        elif isinstance(e, asyncio.TimeoutError):
            return Status.TIMED_OUT
        return Status.FAILED
    
    @staticmethod
    def set(fn: Callable[P, Awaitable[T]]):
        logger = logging.getLogger(f"{__name__}.set.{fn.__name__}")
        @wraps(fn)
        async def set_status_wrap(self: "RPCRequest", *args: P.args, **kwargs: P.kwargs) -> T:
            try:
                self._status = Status.ACTIVE
                retval = await fn(self, *args, **kwargs)
                self._done.set()
                self._status = Status.COMPLETE
                return retval
            except (asyncio.TimeoutError, BadGateway, BadRequest, BrokenPipe, asyncio.CancelledError) as e:
                from dank_mids.requests import _Batch
                if isinstance(self, _Batch):
                    self._status = Status.REBATCHED
                else:
                    self._status = Status.for_exc(e)
                raise e
            except Exception as e:
                from dank_mids.requests import eth_call
                # TODO this if clause should live elsewhere
                # NOTE: these come from the sync w3 and will need a logic change when the sync w3 is removed
                ok = isinstance(self, eth_call) and isinstance(e, ContractLogicError)
                if ok and self._response:
                    # This is a successful failure response from the rpc and is handled further up the stack
                    self._status = Status.COMPLETE
                    raise e
                self._status = Status.FAILED
                stre = str(e).lower()
                if all(err not in stre for err in constants.RETRY_ERRS):
                    logger.warning("%s failed due to the following exc:", self)
                    logger.exception(e)
                raise e
        return set_status_wrap