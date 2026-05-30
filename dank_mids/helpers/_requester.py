import asyncio
import atexit
import threading
from collections.abc import Callable
from concurrent.futures import TimeoutError
from typing import Any, Final, final

import a_sync
from aiohttp import ClientTimeout, TCPConnector
from aiohttp.typedefs import DEFAULT_JSON_DECODER

from dank_mids import ENVIRONMENT_VARIABLES as ENVS
from dank_mids.helpers._session import DankClientSession
from dank_mids.types import T

get_running_loop: Final = asyncio.get_running_loop

create_task: Final = a_sync.create_task
SHUTDOWN_TIMEOUT: Final = 5.0


@final
class HTTPRequesterThread(threading.Thread):
    def __init__(self) -> None:
        super().__init__(daemon=True)
        self.loop: Final = asyncio.new_event_loop()
        self._session: DankClientSession | None = None
        self._tasks: Final[set[asyncio.Task[None]]] = set()
        self._active_posts = 0
        self._active_posts_lock: Final = threading.Lock()
        self.start()

    def run(self) -> None:
        asyncio.set_event_loop(self.loop)
        try:
            self.loop.run_forever()
        except Exception as e:
            self._exc = e
        finally:
            self.loop.close()

    @property
    def session(self) -> DankClientSession:
        session = self._session
        if session is None:
            connector = TCPConnector(limit=0, enable_cleanup_closed=True)
            client_timeout = ClientTimeout(int(ENVS.AIOHTTP_TIMEOUT))
            session = self._session = DankClientSession(
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
        if not self.is_alive():
            raise self._exc.with_traceback(self._exc.__traceback__)

        caller_loop = get_running_loop()
        caller_future: asyncio.Future[T] = caller_loop.create_future()

        async def run_and_set_result() -> None:
            try:
                # we have to access self.session in the subthread first so we need this silly helper coro
                result = await self.session.post(endpoint, *args, loads=loads, **kwargs)
            except Exception as exc:
                caller_loop.call_soon_threadsafe(caller_future.set_exception, exc)
            else:
                caller_loop.call_soon_threadsafe(caller_future.set_result, result)
            finally:
                self._remove_active_post()

        def start_request() -> None:
            coro = run_and_set_result()
            try:
                task: asyncio.Task[None] = create_task(coro)
            except Exception as exc:
                coro.close()
                self._remove_active_post()
                caller_loop.call_soon_threadsafe(caller_future.set_exception, exc)
                return
            self._tasks.add(task)
            task.add_done_callback(self._tasks.discard)

        self._schedule_active_post(start_request)
        return await caller_future

    def _schedule_active_post(self, callback: Callable[[], None]) -> None:
        with self._active_posts_lock:
            self._active_posts += 1
            try:
                self.loop.call_soon_threadsafe(callback)
            except Exception:
                self._active_posts -= 1
                raise

    def _remove_active_post(self) -> None:
        with self._active_posts_lock:
            self._active_posts -= 1

    def _active_post_count(self) -> int:
        with self._active_posts_lock:
            return self._active_posts

    def _has_active_posts(self) -> bool:
        return self._active_post_count() > 0


def shutdown_http_requester(timeout: float = SHUTDOWN_TIMEOUT) -> None:
    requester = _requester
    loop = requester.loop
    if loop.is_closed():
        return

    has_active_posts = requester._has_active_posts()

    async def close_session() -> None:
        if has_active_posts:
            await asyncio.sleep(0)
        if session := requester._session:
            await session.close()

    if requester.is_alive():
        try:
            if requester._session is not None or has_active_posts:
                future = asyncio.run_coroutine_threadsafe(close_session(), loop)
                future.result(timeout=timeout)
        except (RuntimeError, TimeoutError):
            pass
        try:
            loop.call_soon_threadsafe(loop.stop)
        except RuntimeError:
            return
    else:
        try:
            loop.stop()
        except RuntimeError:
            return

    if requester.is_alive() and threading.current_thread() is not requester:
        requester.join(timeout=timeout)


_requester = HTTPRequesterThread()
atexit.register(shutdown_http_requester)
