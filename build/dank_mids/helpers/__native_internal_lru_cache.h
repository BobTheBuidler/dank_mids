#ifndef MYPYC_NATIVE_INTERNAL_dank_mids___helpers___lru_cache_H
#define MYPYC_NATIVE_INTERNAL_dank_mids___helpers___lru_cache_H
#include <Python.h>
#include <CPy.h>
#include "__native_lru_cache.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[23];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids___helpers___lru_cache_internal;
extern CPyModule *CPyModule_dank_mids___helpers___lru_cache;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_functools;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_typing_extensions;
extern PyTypeObject *CPyType_lru_cache_lite_env;
extern PyObject *CPyDef_lru_cache_lite_env(void);
extern PyTypeObject *CPyType_lru_cache_lite_wrap_lru_cache_lite_obj;
extern PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj(void);
extern PyTypeObject *CPyType_lru_cache_lite_nonull_env;
extern PyObject *CPyDef_lru_cache_lite_nonull_env(void);
extern PyTypeObject *CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj;
extern PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj(void);
extern PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
extern PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args);
extern PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_lru_cache_lite(PyObject *cpy_r_func);
extern PyObject *CPyPy_lru_cache_lite(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
extern PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args);
extern PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_lru_cache_lite_nonull(PyObject *cpy_r_func);
extern PyObject *CPyPy_lru_cache_lite_nonull(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
