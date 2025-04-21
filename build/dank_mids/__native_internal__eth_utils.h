#ifndef MYPYC_NATIVE_INTERNAL_dank_mids____eth_utils_H
#define MYPYC_NATIVE_INTERNAL_dank_mids____eth_utils_H
#include <Python.h>
#include <CPy.h>
#include "__native__eth_utils.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[66];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids____eth_utils_internal;
extern CPyModule *CPyModule_dank_mids____eth_utils;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_binascii;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_eth_typing;
extern CPyModule *CPyModule_eth_utils___crypto;
extern CPyModule *CPyModule_web3___main;
extern CPyModule *CPyModule_web3___middleware___filter;
extern CPyModule *CPyModule_web3___providers___base;
extern CPyModule *CPyModule_web3____utils___encoding;
extern CPyModule *CPyModule_web3____utils___events;
extern CPyModule *CPyModule_web3____utils___normalizers;
extern CPyModule *CPyModule_web3____utils___type_conversion;
extern char CPyDef_patch_eth_utils(void);
extern PyObject *CPyPy_patch_eth_utils(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_to_hex(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text);
extern PyObject *CPyPy_to_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_to_bytes(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text);
extern PyObject *CPyPy_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_decode_hex(PyObject *cpy_r_value);
extern PyObject *CPyPy_decode_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_encode_hex(PyObject *cpy_r_value);
extern PyObject *CPyPy_encode_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_is_0x_prefixed(PyObject *cpy_r_value);
extern PyObject *CPyPy_is_0x_prefixed(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_remove_0x_prefix(PyObject *cpy_r_value);
extern PyObject *CPyPy_remove_0x_prefix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_add_0x_prefix(PyObject *cpy_r_value);
extern PyObject *CPyPy_add_0x_prefix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
