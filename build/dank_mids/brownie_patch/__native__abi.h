#ifndef MYPYC_NATIVE_dank_mids___brownie_patch____abi_H
#define MYPYC_NATIVE_dank_mids___brownie_patch____abi_H
#include <Python.h>
#include <CPy.h>
typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_abi;
    PyObject *_input_sig;
    PyObject *_signature;
} dank_mids___brownie_patch____abi___FunctionABIObject;


struct export_table_dank_mids___brownie_patch____abi {
    PyTypeObject **CPyType_FunctionABI;
    PyObject *(*CPyDef_FunctionABI)(PyObject *cpy_r_abi);
    char (*CPyDef_FunctionABI_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_abi);
    PyObject *(*CPyDef_FunctionABI___singleton)(PyObject *cpy_r_abi);
    char (*CPyDef___top_level__)(void);
};
#endif
