#ifndef MYPYC_NATIVE_INTERNAL_dank_mids___brownie_patch____abi_H
#define MYPYC_NATIVE_INTERNAL_dank_mids___brownie_patch____abi_H
#include <Python.h>
#include <CPy.h>
#include "__native__abi.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[26];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids___brownie_patch____abi_internal;
extern CPyModule *CPyModule_dank_mids___brownie_patch____abi;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_functools;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_brownie___convert___utils;
extern PyTypeObject *CPyType_FunctionABI;
extern PyObject *CPyDef_FunctionABI(PyObject *cpy_r_abi);
extern char CPyDef_FunctionABI_____init__(PyObject *cpy_r_self, PyObject *cpy_r_abi);
extern PyObject *CPyPy_FunctionABI_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_FunctionABI___singleton(PyObject *cpy_r_abi);
extern PyObject *CPyPy_FunctionABI___singleton(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
