import asyncio
import atexit
import threading
from typing import Any, Callable, Final, final, overload

from aiohttp import ClientTimeout, TCPConnector
from aiohttp.typedefs import DEFAULT_JSON_DECODER, JSONDecoder

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.helpers._codec import JSONRPCBatchResponse, RawResponse
from dank_mids.helpers._session import DankClientSession


@final
class HTTPRequesterThread(threading.Thread):
    def __init__(self):
        super().__init__(daemon=True)
        self.loop: Final = asyncio.new_event_loop()
        self._session: DankClientSession | None = None
        self.start()

    def run(self):
        asyncio.set_event_loop(self.loop)
        self.loop.run_forever()

    @property
    def session(self) -> DankClientSession:
        session = self._session
        if session is None:
            connector = TCPConnector(limit=0, enable_cleanup_closed=True)
            client_timeout = ClientTimeout(int(ENVS.AIOHTTP_TIMEOUT))
            session = self._session =  DankClientSession(
                connector=connector,
                headers={"content-type": "application/json"},
                timeout=client_timeout,
                raise_for_status=True,
                read_bufsize=2**20,
            )
        return session


    @overload
    async def post(
        self, endpoint: str, *args: Any, loads: Callable[[Any], RawResponse], **kwargs: Any
    ) -> RawResponse:
        """Returns a :class:`~RawResponse` object from `endpoint`."""
    @overload
    async def post(
        self, endpoint: str, *args: Any, loads: Callable[[Any], JSONRPCBatchResponse], **kwargs: Any
    ) -> JSONRPCBatchResponse:
        """Returns a decoded JSONRPCBatchResponse from `endpoint`."""
    async def post(
        self, endpoint: str, *args: Any, loads: JSONDecoder = DEFAULT_JSON_DECODER, **kwargs: Any
    ) -> Any:
        """Returns decoded json data from `endpoint`."""
        async def do_post():
            # we have to access self.session in the subthread first so we need this silly helper coro
            return await self.session.post(endpoint, *args, loads=loads, **kwargs)
        thread_future = asyncio.run_coroutine_threadsafe(do_post(), self.loop)
        return await asyncio.wrap_future(thread_future)

def shutdown_http_requester():
    async def close_session_and_stop():
        if session := _requester._session:
            await session.close()
        _requester.loop.stop()
    # Block until the ClientSession and loop are both closed
    asyncio.run_coroutine_threadsafe(close_session_and_stop(), _requester.loop).result()

_requester = HTTPRequesterThread()
atexit.register(shutdown_http_requester)
