#ifndef MYPYC_NATIVE_INTERNAL_dank_mids___brownie_patch___overloaded_H
#define MYPYC_NATIVE_INTERNAL_dank_mids___brownie_patch___overloaded_H
#include <Python.h>
#include <CPy.h>
#include "__native_overloaded.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[55];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids___brownie_patch___overloaded_internal;
extern CPyModule *CPyModule_dank_mids___brownie_patch___overloaded;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_functools;
extern CPyModule *CPyModule_types;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_brownie;
extern CPyModule *CPyModule_brownie___network___contract;
extern CPyModule *CPyModule_dank_mids___brownie_patch___call;
extern CPyModule *CPyModule_dank_mids___brownie_patch___types;
extern CPyModule *CPyModule_dank_mids___helpers____helpers;
extern PyTypeObject *CPyType__patch_overloaded_method_env;
extern PyObject *CPyDef__patch_overloaded_method_env(void);
extern PyTypeObject *CPyType_coroutine__patch_overloaded_method_env;
extern PyObject *CPyDef_coroutine__patch_overloaded_method_env(void);
extern PyTypeObject *CPyType_coroutine__patch_overloaded_method_obj;
extern PyObject *CPyDef_coroutine__patch_overloaded_method_obj(void);
extern PyTypeObject *CPyType_coroutine__patch_overloaded_method_gen;
extern PyObject *CPyDef_coroutine__patch_overloaded_method_gen(void);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____next__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____iter__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_gen___close(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____await__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine__patch_overloaded_method_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
extern PyObject *CPyPy_coroutine__patch_overloaded_method_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef__patch_overloaded_method(PyObject *cpy_r_call, PyObject *cpy_r_w3);
extern PyObject *CPyPy__patch_overloaded_method(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
