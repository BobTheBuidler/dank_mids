import abc
import logging
import os
from functools import lru_cache
from typing import Any, Iterable

import aiofiles
from a_sync.functools import cached_property_unsafe as cached_property
from aiofiles.base import AiofilesContextManager
from aiofiles.threadpool.text import AsyncTextIOWrapper
from async_lru import alru_cache

logger = logging.getLogger("dank_mids.debugging")


class _FileHelper(metaclass=abc.ABCMeta):
    path = f"{os.path.expanduser('~')}/.dank_mids/debug"

    def __init__(self, chainid: int):
        if not isinstance(chainid, int):
            raise TypeError(f"`chainid` must be an integer. You passed {chainid}") from None

        self.chainid = chainid
        """The ID of the blockchain network."""

        self.path += f"/{self.chainid}"
        self.ensure_dir()

    @lru_cache(maxsize=1)
    def ensure_dir(self) -> None:
        """
        Ensure that the directory for the file exists, creating it if necessary.
        """
        os.makedirs(self.path, exist_ok=True)

    def open(self) -> "AiofilesContextManager[None, None, AsyncTextIOWrapper]":
        """
        Open the file asynchronously.

        Returns:
            An asynchronous context manager for the file.
        """
        logger.info("opening %s with mode %s", self.uri, self.mode)
        return aiofiles.open(self.uri, self.mode)

    @abc.abstractproperty
    def uri(self) -> str:
        """
        Abstract property for the file URI.

        Returns:
            The URI of the file as a string.
        """

    @abc.abstractproperty
    def mode(self) -> str:
        """
        Abstract property for the file open mode.

        Returns:
            The mode to open the file with as a string.
        """


class _CSVWriter(_FileHelper):
    mode = "a"

    @cached_property
    def uri(self) -> str:
        """
        Construct the URI for the CSV file.

        Returns:
            The URI of the CSV file as a string.
        """
        return f"{self.path}/{self.filename}"

    async def write_row(self, *values: Any) -> None:
        """
        Write a row to the CSV file after ensuring headers exist.

        Args:
            *values: The values to write as a row in the CSV file.
        """
        await self._ensure_headers()
        await self._write_row(*values)

    @alru_cache(maxsize=None)
    async def _ensure_headers(self) -> None:
        """
        Ensure that the CSV file has headers, writing them if necessary.

        Writes headers to the CSV file if they do not already exist.
        """
        await self._write_row(*self.column_names, new_line=False)

    async def _write_row(self, *values: Any, new_line: bool = True) -> None:
        """
        Write a row to the CSV file.

        Args:
            *values: The values to write as a row.
            new_line: Whether to start a new line before writing. Defaults to True.
        """
        row = ",".join(str(obj) for obj in values)
        if new_line:
            row = f"\n{row}"
        async with self.open() as file:
            logger.debug("writing row %s to file %s", row, file)
            await file.write(row)

    @abc.abstractproperty
    def filename(self) -> str:
        """
        Abstract property for the CSV file name.

        Returns:
            The filename of the CSV file as a string.
        """

    @abc.abstractproperty
    def column_names(self) -> Iterable[str]:
        """
        Abstract property for the column names in the CSV file.

        Returns:
            An iterable of column names for the CSV file.
        """
