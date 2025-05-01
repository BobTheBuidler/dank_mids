from typing import Final

import a_sync
from typed_envs import EnvVarFactory

from dank_mids.semaphores import BlockSemaphore


_factory: Final = EnvVarFactory("DANKMIDS")

# TODO: maybe have ez-a-sync do this natively for its own classes?
# TODO: maybe have typed-envs do this natively for builtin types? (asyncio.Semaphore, cf.Executor, etc...)
_factory.register_string_converter(a_sync.Semaphore, int)
_factory.register_string_converter(a_sync.ProcessPoolExecutor, int)
_factory.register_string_converter(BlockSemaphore, int)

create_env: Final = _factory.create_env

# This only applies to the oldest of dank's envs
_deprecated_format: Final = EnvVarFactory("DANK_MIDS")

