
import abc
import logging
import os
from functools import cached_property, lru_cache

import aiofiles
from aiofiles.base import AiofilesContextManager
from aiofiles.threadpool.text import AsyncTextIOWrapper

logger = logging.getLogger("dank_mids.debugging")

class _FileHelper(metaclass=abc.ABCMeta):
    path = "~/.dank_mids/debug"
    def __init__(self):
        self.ensure_dir()
    @lru_cache(maxsize=1)
    def ensure_dir(cls) -> None:
        os.makedirs(cls.path, exist_ok=True)
    def open(self) -> AiofilesContextManager[None, None, AsyncTextIOWrapper]:
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
        return self.path + self.filename
    async def write_row(self, row: str) -> None:
        async with self.open() as file:
            logger.info("writing row %s to file %s", row, file)
            await file.write(row)
    @abc.abstractproperty
    def filename(self) -> str:
        ...