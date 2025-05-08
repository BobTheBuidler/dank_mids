# NOTE: `FunctionABI` must inherit from a python object in order for weakrefs to work, so for now we inherit from _FunctionABI
# https://github.com/python/cpython/blob/9546eeea90c8deb8570a0ef621f075c3c766bc12/Include/internal/pycore_object.h#L874
# https://github.com/python/mypy/blob/501a07b45af8e44eda665e53526fc590dc5a014e/mypyc/irbuild/vtable.py#L17
# https://github.com/python/mypy/blob/501a07b45af8e44eda665e53526fc590dc5a014e/mypyc/codegen/emitclass.py#L285
# TODO: fix the above


class _FunctionABI: ...
