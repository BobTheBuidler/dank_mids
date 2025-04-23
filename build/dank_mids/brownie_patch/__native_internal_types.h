#ifndef MYPYC_NATIVE_INTERNAL_dank_mids___brownie_patch___types_H
#define MYPYC_NATIVE_INTERNAL_dank_mids___brownie_patch___types_H
#include <Python.h>
#include <CPy.h>
#include "__native_types.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[58];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids___brownie_patch___types_internal;
extern CPyModule *CPyModule_dank_mids___brownie_patch___types;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_brownie___network___contract;
extern CPyModule *CPyModule_brownie___typing;
extern CPyModule *CPyModule_dank_mids___brownie_patch____method;
extern PyTypeObject *CPyType_DankContractCall;
extern PyObject *CPyDef_DankContractCall(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
extern PyTypeObject *CPyType_DankContractTx;
extern PyObject *CPyDef_DankContractTx(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
extern PyTypeObject *CPyType_DankOverloadedMethod;
extern PyObject *CPyDef_DankOverloadedMethod(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
extern PyTypeObject *CPyType_coroutine_DankOverloadedMethod_env;
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_env(void);
extern PyTypeObject *CPyType_coroutine_DankOverloadedMethod_gen;
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_gen(void);
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
extern PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____next__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
extern PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____iter__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
extern PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___close(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____await__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_DankOverloadedMethod___coroutine(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
extern PyObject *CPyPy_DankOverloadedMethod___coroutine(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_DankOverloadedMethod____add_fn(PyObject *cpy_r_self, PyObject *cpy_r_abi, PyObject *cpy_r_natspec);
extern PyObject *CPyPy_DankOverloadedMethod____add_fn(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef__get_method_object(PyObject *cpy_r_address, PyObject *cpy_r_abi, PyObject *cpy_r_name, PyObject *cpy_r_owner, PyObject *cpy_r_natspec);
extern PyObject *CPyPy__get_method_object(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
