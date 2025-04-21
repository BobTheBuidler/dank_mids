#ifndef MYPYC_NATIVE_INTERNAL_dank_mids___helpers____codec_H
#define MYPYC_NATIVE_INTERNAL_dank_mids___helpers____codec_H
#include <Python.h>
#include <CPy.h>
#include "__native__codec.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[83];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids___helpers____codec_internal;
extern CPyModule *CPyModule_dank_mids___helpers____codec;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_itertools;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_eth_abi___abi;
extern CPyModule *CPyModule_eth_abi___decoding;
extern CPyModule *CPyModule_eth_abi___encoding;
extern CPyModule *CPyModule_msgspec;
extern CPyModule *CPyModule_msgspec___json;
extern CPyModule *CPyModule_dank_mids___types;
extern PyObject *CPyStatic__mcall_encoder;
extern PyObject *CPyStatic__array_encoder;
extern PyObject *CPyStatic__item_encoder;
extern PyObject *CPyStatic__mcall_decoder;
extern PyTypeObject *CPyType___mypyc_lambda__0_obj;
extern PyObject *CPyDef___mypyc_lambda__0_obj(void);
extern PyObject *CPyDef_decode_raw(PyObject *cpy_r_data);
extern PyObject *CPyPy_decode_raw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_decode_jsonrpc_batch(PyObject *cpy_r_data);
extern PyObject *CPyPy_decode_jsonrpc_batch(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_encode(PyObject *cpy_r_obj);
extern PyObject *CPyPy_encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___mypyc_lambda__0_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
extern PyObject *CPyPy___mypyc_lambda__0_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___mypyc_lambda__0_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r__);
extern PyObject *CPyPy___mypyc_lambda__0_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___encode_new(PyObject *cpy_r_values);
extern PyObject *CPyPy___encode_new(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern tuple_T2OI CPyDef___encode_elements_new(PyObject *cpy_r_values);
extern PyObject *CPyPy___encode_elements_new(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_mcall_encode(PyObject *cpy_r_data);
extern PyObject *CPyPy_mcall_encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_mcall_decode(PyObject *cpy_r_data);
extern PyObject *CPyPy_mcall_decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
