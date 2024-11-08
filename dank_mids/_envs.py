from typed_envs import EnvVarFactory

_factory = EnvVarFactory("DANKMIDS")
create_env = _factory.create_env

# This only applies to the oldest of dank's envs
_deprecated_format = EnvVarFactory("DANK_MIDS")
