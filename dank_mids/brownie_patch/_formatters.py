
from functools import lru_cache, partial
from typing import Any, Callable, List, Tuple, Union

from brownie.convert.normalize import (ABIType, TupleType, _check_array,
                                       _format_single, _get_abi_types)


@lru_cache(maxsize=None)
def get_abi_formatter(abi_inputs: List[dict]) -> Callable[[tuple], tuple]:
    formatters = [_get_formatter_fn(arg_type) for arg_type in _get_abi_types(abi_inputs)]
    def abi_formatter(args):
        return [formatter(arg) for arg, formatter in zip(args, formatters)]
    return abi_formatter

_formatters = {}
def _get_formatter_fn(_type: ABIType) -> Callable[[Any], Any]:
    """This eliminates some of the standard web3.py formatter logic without sacrificing uality."""
    type_str = _type.to_type_str()
    if type_str not in _formatters:
        if _type.is_array:
            _formatters[type_str] = _get_array_formatter(_type)
        elif isinstance(_type, TupleType):
            _formatters[type_str] = _get_tuple_formatter(_type)
        else:
            _formatters[type_str] = partial(_format_single, _type.to_type_str())
    return _formatters[type_str]

_array_formatters = {}
def _get_array_formatter(typ: ABIType) -> Callable[[Any], Any]:
    item_type = typ.item_type
    type_str = typ.to_type_str()
    if type_str not in _array_formatters:
        check_array = partial(_check_array, length=typ.arrlist[-1][0] if len(typ.arrlist[-1]) else None)
        
        if item_type.is_array:
            array_formatter = _get_array_formatter(item_type)
            def _format_array(values: Union[List, Tuple]) -> List:
                check_array(values)
                return [array_formatter(i) for i in values]
            
        elif isinstance(item_type, TupleType):
            tuple_formatter = _get_tuple_formatter(item_type)
            def _format_array(values: Union[List, Tuple]) -> List:
                check_array(values)
                return [tuple_formatter(i) for i in values]
        else:
            def _format_array(values: Union[List, Tuple]) -> List:
                check_array(values)
                return [_format_single(item_type.to_type_str(), i) for i in values]
        _array_formatters[type_str] = _format_array
    return _array_formatters[type_str]

_tuple_formatters = {}
def _get_tuple_formatter(typ: TupleType):
    if not isinstance(typ, TupleType):
        raise TypeError(typ) 
    type_str = typ.to_type_str()
    if type_str not in _tuple_formatters:
        formatters = [_get_formatter_fn(_) for _ in typ.components]
        check_array = partial(_check_array, length=len(formatters))
        def _format_tuple(values: Union[List, Tuple]) -> List:
            result = []
            check_array(values)
            for formatter, value in zip(formatters, values):
                try:
                    result.append(formatter(value))
                except Exception as e:
                    raise type(e)(f"'{value}' - {e}") from None
            return result
        _tuple_formatters[type_str] = _format_tuple
    return _tuple_formatters[type_str]
