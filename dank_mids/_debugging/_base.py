
import abc
import logging
import os
from functools import cached_property, lru_cache
from typing import Any, Iterable

import aiofiles
from aiofiles.base import AiofilesContextManager
from aiofiles.threadpool.text import AsyncTextIOWrapper
from async_lru import alru_cache

logger = logging.getLogger("dank_mids.debugging")

class _FileHelper(metaclass=abc.ABCMeta):
    path = f"{os.path.expanduser( '~' )}/.dank_mids/debug"
    def __init__(self, chainid: int):
        if not isinstance(chainid, int):
            raise TypeError(f"`chainid` must be an integer. You passed {chainid}") from None
        self.chainid = chainid
        self.path = self.path + f"/{self.chainid}"
        self.ensure_dir()
    @lru_cache(maxsize=1)
    def ensure_dir(self) -> None:
        os.makedirs(self.path, exist_ok=True)
    def open(self) -> "AiofilesContextManager[None, None, AsyncTextIOWrapper]":
        logger.info("opening %s with mode %s", self.uri, self.mode)
        return aiofiles.open(self.uri, self.mode)
    @abc.abstractproperty
    def uri(self) -> str:
        ...
    @abc.abstractproperty
    def mode(self) -> str:
        ...

class _CSVWriter(_FileHelper):
    mode = "a"
    @cached_property
    def uri(self) -> str:
        return f"{self.path}/{self.filename}"
    async def write_row(self, *values: Any) -> None:
        await self._ensure_headers()
        await self._write_row(*values)
    @alru_cache(maxsize=None)
    async def _ensure_headers(self) -> None:
        await self._write_row(*self.column_names, new_line=False)
    async def _write_row(self, *values: Any, new_line: bool = True) -> None:
        row = ','.join(str(obj) for obj in values)
        if new_line:
            row = f'\n{row}'
        async with self.open() as file:
            logger.debug("writing row %s to file %s", row, file)
            await file.write(row)
    @abc.abstractproperty
    def filename(self) -> str:
        ...
    @abc.abstractproperty
    def column_names(self) -> Iterable[str]:
        ...