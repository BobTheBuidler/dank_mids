import asyncio
import logging
from enum import IntEnum
from functools import wraps
from typing import Awaitable, Callable, TypeVar

from typing_extensions import ParamSpec
from web3.exceptions import ContractLogicError

logger = logging.getLogger(__name__)
T = TypeVar("T")
P = ParamSpec("P")

class Status(IntEnum):
    QUEUED = 0
    ACTIVE = 1
    COMPLETE = 2
    CANCELED = 3
    FAILED = 4
    TIMED_OUT = 5
    
    @staticmethod
    def for_exc(e: Exception):
        if isinstance(e, asyncio.CancelledError):
            return Status.CANCELED
        elif isinstance(e, asyncio.TimeoutError):
            return Status.TIMED_OUT
        return Status.FAILED
    
    @staticmethod
    def set(fn: Callable[P, Awaitable[T]]):
        from dank_mids.requests import RPCRequest, _Batch
        logger = logging.getLogger(f"{__name__}.set_done.{fn.__name__}")
        @wraps(fn)
        async def set_status_wrap(self: RPCRequest, *args: P.args, **kwargs: P.kwargs) -> T:
            try:
                self._status = Status.ACTIVE
                retval = await fn(self, *args, **kwargs)
                self._done.set()
                self._status = Status.COMPLETE
                return retval
            except (asyncio.TimeoutError, asyncio.CancelledError) as e:
                if not isinstance(self, _Batch):
                    self._status = Status.for_exc(e)
                raise e
            except Exception as e:
                # TODO this if clause should live elsewhere
                # NOTE: these come from the sync w3 and will need a logic change when the sync w3 is removed
                if isinstance(self, RPCRequest) and isinstance(e, ContractLogicError):
                    # This is a successful failure response from the rpc and is handled further up the stack
                    self._status = Status.COMPLETE
                    return
                self._status = Status.FAILED
                logger.warning("%s failed due to the following exc:", self)
                logger.exception(e)
                raise e
        return set_status_wrap