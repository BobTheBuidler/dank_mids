import asyncio as _asyncio
from typing import Awaitable as _Awaitable
from typing import Iterable as _Iterable

from tqdm.asyncio import tqdm_asyncio as _tqdm_asyncio

from dank_mids.helpers.w3 import setup_dank_w3, setup_dank_w3_from_sync


async def await_all(futs: _Iterable[_Awaitable], verbose: bool = False) -> None:
    # NOTE: 'verbose' is mainly for debugging but feel free to have fun
    if not isinstance(verbose, bool):
        raise NotImplementedError(verbose)
    as_completed = _tqdm_asyncio.as_completed if verbose else _asyncio.as_completed
    for fut in as_completed(futs if isinstance(futs, list) else [*futs]):
        await fut