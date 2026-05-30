from __future__ import annotations

import asyncio

from dank_mids.helpers._requester import HTTPRequesterThread
from dank_mids.helpers._session import DankClientSession


def test_session_is_created_lazily(
    requester_thread: HTTPRequesterThread,
) -> None:
    assert requester_thread._session is None

    async def get_and_close_session() -> DankClientSession:
        session = requester_thread.session
        await session.close()
        return session

    session = asyncio.run(get_and_close_session())

    assert isinstance(session, DankClientSession)
    assert requester_thread._session is session


def test_session_property_reuses_existing_session(
    requester_thread: HTTPRequesterThread,
) -> None:
    async def get_session_ids_and_close() -> tuple[int, int]:
        first = requester_thread.session
        second = requester_thread.session
        await first.close()
        return id(first), id(second)

    first_id, second_id = asyncio.run(get_session_ids_and_close())

    assert first_id == second_id
