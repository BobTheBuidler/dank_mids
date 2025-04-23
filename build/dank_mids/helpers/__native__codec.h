#ifndef MYPYC_NATIVE_dank_mids___helpers____codec_H
#define MYPYC_NATIVE_dank_mids___helpers____codec_H
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

#ifndef MYPYC_DECLARED_tuple_T2OI
#define MYPYC_DECLARED_tuple_T2OI
typedef struct tuple_T2OI {
    PyObject *f0;
    CPyTagged f1;
} tuple_T2OI;
#endif

#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T1I
#define MYPYC_DECLARED_tuple_T1I
typedef struct tuple_T1I {
    CPyTagged f0;
} tuple_T1I;
#endif

#ifndef MYPYC_DECLARED_tuple_T2CO
#define MYPYC_DECLARED_tuple_T2CO
typedef struct tuple_T2CO {
    char f0;
    PyObject *f1;
} tuple_T2CO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3IIO
#define MYPYC_DECLARED_tuple_T3IIO
typedef struct tuple_T3IIO {
    CPyTagged f0;
    CPyTagged f1;
    PyObject *f2;
} tuple_T3IIO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers____codec_____mypyc_lambda__0_objObject;


struct export_table_dank_mids___helpers____codec {
    PyObject **CPyStatic_Raw;
    PyObject **CPyStatic_RawResponse;
    PyObject **CPyStatic_ContextFramesBytesIO;
    PyObject **CPyStatic_DecodeError;
    PyObject **CPyStatic_json_encode;
    PyObject **CPyStatic_json_decode;
    PyObject **CPyStatic_encode_uint_256;
    PyObject **CPyStatic__encode_hook;
    PyObject **CPyStatic__mcall_encoder;
    PyObject **CPyStatic__array_encoder;
    PyObject **CPyStatic__item_encoder;
    PyObject **CPyStatic__mcall_decoder;
    PyTypeObject **CPyType___mypyc_lambda__0_obj;
    PyObject *(*CPyDef___mypyc_lambda__0_obj)(void);
    PyObject *(*CPyDef_decode_raw)(PyObject *cpy_r_data);
    PyObject *(*CPyDef_decode_jsonrpc_batch)(PyObject *cpy_r_data);
    PyObject *(*CPyDef_encode)(PyObject *cpy_r_obj);
    PyObject *(*CPyDef___mypyc_lambda__0_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__0_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r__);
    PyObject *(*CPyDef___encode_new)(PyObject *cpy_r_values);
    tuple_T2OI (*CPyDef___encode_elements_new)(PyObject *cpy_r_values);
    PyObject *(*CPyDef_mcall_encode)(PyObject *cpy_r_data);
    PyObject *(*CPyDef_mcall_decode)(PyObject *cpy_r_data);
    char (*CPyDef___top_level__)(void);
};
#endif
