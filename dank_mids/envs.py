import os
from functools import lru_cache
from types import new_class
from typing import Any, Callable, Generic, Optional, Type, TypeVar, Dict

"""
This module is used to create specialized EnvironmentVariable objects.
that behave exactly the same as any other instance of the provided `typ`.

EnvironmentVariable class is used for:
 - enhancing type hints for the returned instances
 - enhancing __repr__ of the returned instance that hold values you set with env vars.
    NOTE: This is just a helper class to create custom wrapper classes on the fly.
You must never initialize these directly. You must use the provided `create_env` function to initialize your env vars.
"""

_Envs = Dict[str, "EnvironmentVariable"]

ENVIRONMENT_VARIABLES: _Envs = {}
ENVIRONMENT_VARIABLES_SET_BY_USER: _Envs = {}
ENVIRONMENT_VARIABLES_USING_DEFAULTS: _Envs = {}

T = TypeVar('T')

def create_env(
    name: str, 
    typ: Type[T], 
    default: Optional[T], 
    *init_args, 
    string_converter: Optional[Callable[[str], Any]] = None, 
    **init_kwargs
) -> "EnvironmentVariable[T]":
    var_value = os.environ.get(name)
    using_default = var_value is None
    var_value = var_value or default
    if string_converter:
        var_value = string_converter(var_value)

    subclass = _create_subclass(typ)
    instance = subclass(var_value, *init_args, **init_kwargs)

    # Set additional attributes
    if not hasattr(instance, 'name'):
        instance.name = name
    else:
        instance.env_name = name
    instance._default_value = default
    instance._using_default = using_default

    # This code will print envs on startup for your convenience
    if not using_default:
        print(instance.__repr__())

    # Save new env to registry dicts
    ENVIRONMENT_VARIABLES[name] = instance
    if using_default:
        ENVIRONMENT_VARIABLES_USING_DEFAULTS[name] = instance
    else:
        ENVIRONMENT_VARIABLES_SET_BY_USER[name] = instance
    return instance

class EnvironmentVariable(Generic[T]):
    """
    Useful for enhancing type hints and __repr__ of variables that hold values you set with env vars.
    NOTE: This is just a helper class to create custom wrapper classes on the fly.
    You should never initialize these directly.
    """
    def __str__(self) -> str:
        base_type = self._base_type
        # Hacky workaround for booleans
        #if base_type is bool:
        #    base_type = int
        string_from_base = base_type.__str__(self)
        if string_from_base == self.__repr__():
            # base type's string method calls __repr__ and we break it.
            return str(bool(self)) if base_type is bool else self._base_type.__repr__(self)
        return string_from_base
    def __repr__(self) -> str:
        env_name = self.env_name if hasattr(self, 'env_name') else self.name
        representation = bool(self) if self._base_type is bool else self.__class__.__base__.__repr__(self)
        default = 'NOT_SET' if self._default_value is None else self._default_value 
        return f"EnvironmentVariable[type={self._base_type.__name__}, name=`{env_name}`, default_value={default}, current_value={representation}, using_default={self._using_default}]"

@lru_cache(maxsize=None)
def _create_subclass(typ: Type[T]) -> Type["EnvironmentVariable[T]"]:
    """
    Returns a subclass of `typ` that does 2 things:
     - modifies the __repr__ method so its clear the instance is an env var
     - ensures the instance will type check as an EnvironmentVariable object

    Aside from these two things, subclass instances will function exactly the same as any other instance of `typ`.

    """
    subclass_name = f'EnvironmentVariable_{typ.__name__}'
    subclass_bases = (int if typ is bool else typ, EnvironmentVariable[typ])
    cls = new_class(subclass_name, subclass_bases, {})
    cls.__repr__ = EnvironmentVariable.__repr__
    cls.__str__ = EnvironmentVariable.__str__
    cls._base_type = typ
    return cls

def _validate_args(var_value, default, args):
    if default and not args:
        
        args = (var_value or default, )
    elif args and not default:
        used_default = False
        args = args
    elif not args and not default:
        used_default = False
        args = args
    elif args and default:
        raise NotImplementedError()