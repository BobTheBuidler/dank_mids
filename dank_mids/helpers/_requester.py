import asyncio
import atexit
import threading
from typing import Any, Callable, Final, final

from aiohttp import ClientTimeout, TCPConnector
from aiohttp.typedefs import DEFAULT_JSON_DECODER

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.helpers._session import DankClientSession
from dank_mids.types import T


run_coroutine_threadsafe: Final = asyncio.run_coroutine_threadsafe
wrap_future: Final = asyncio.wrap_future


@final
class HTTPRequesterThread(threading.Thread):
    def __init__(self) -> None:
        super().__init__(daemon=True)
        self.loop: Final = asyncio.new_event_loop()
        self._session: DankClientSession | None = None
        self.start()

    def run(self) -> None:
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

    async def post(
        self,
        endpoint: str,
        *args: Any,
        loads: Callable[[str], T] = DEFAULT_JSON_DECODER,
        **kwargs: Any,
    ) -> T:
        """Returns decoded json data from `endpoint`."""

        async def do_post() -> T:
            # we have to access self.session in the subthread first so we need this silly helper coro
            return await self.session.post(endpoint, *args, loads=loads, **kwargs)

        return await wrap_future(run_coroutine_threadsafe(do_post(), self.loop))

def shutdown_http_requester() -> None:
    async def close_session_and_stop() -> None:
        if session := _requester._session:
            await session.close()
        _requester.loop.stop()
    # Block until the ClientSession and loop are both closed
    asyncio.run_coroutine_threadsafe(close_session_and_stop(), _requester.loop).result()

_requester = HTTPRequesterThread()
atexit.register(shutdown_http_requester)
