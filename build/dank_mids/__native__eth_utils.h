#ifndef MYPYC_NATIVE_dank_mids____eth_utils_H
#define MYPYC_NATIVE_dank_mids____eth_utils_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif


struct export_table_dank_mids____eth_utils {
    char (*CPyDef_patch_eth_utils)(void);
    PyObject *(*CPyDef_to_hex)(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text);
    PyObject *(*CPyDef_to_bytes)(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text);
    PyObject *(*CPyDef_decode_hex)(PyObject *cpy_r_value);
    PyObject *(*CPyDef_encode_hex)(PyObject *cpy_r_value);
    char (*CPyDef_is_0x_prefixed)(PyObject *cpy_r_value);
    PyObject *(*CPyDef_remove_0x_prefix)(PyObject *cpy_r_value);
    PyObject *(*CPyDef_add_0x_prefix)(PyObject *cpy_r_value);
    char (*CPyDef___top_level__)(void);
};
#endif
