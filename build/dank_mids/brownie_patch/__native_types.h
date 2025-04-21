#ifndef MYPYC_NATIVE_dank_mids___brownie_patch___types_H
#define MYPYC_NATIVE_dank_mids___brownie_patch___types_H
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

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids___brownie_patch___types___DankContractCallObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids___brownie_patch___types___DankContractTxObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_methods;
} dank_mids___brownie_patch___types___DankOverloadedMethodObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_self;
    PyObject *_args;
    PyObject *_block_identifier;
    PyObject *_decimals;
    PyObject *_override;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *_call;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
} dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject;


struct export_table_dank_mids___brownie_patch___types {
    PyTypeObject **CPyType_DankContractCall;
    PyObject *(*CPyDef_DankContractCall)(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    PyTypeObject **CPyType_DankContractTx;
    PyObject *(*CPyDef_DankContractTx)(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    PyTypeObject **CPyType_DankOverloadedMethod;
    PyObject *(*CPyDef_DankOverloadedMethod)(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    PyTypeObject **CPyType_coroutine_DankOverloadedMethod_env;
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_env)(void);
    PyTypeObject **CPyType_coroutine_DankOverloadedMethod_gen;
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_gen)(void);
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine_DankOverloadedMethod_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_DankOverloadedMethod___coroutine)(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
    char (*CPyDef_DankOverloadedMethod____add_fn)(PyObject *cpy_r_self, PyObject *cpy_r_abi, PyObject *cpy_r_natspec);
    PyObject *(*CPyDef__get_method_object)(PyObject *cpy_r_address, PyObject *cpy_r_abi, PyObject *cpy_r_name, PyObject *cpy_r_owner, PyObject *cpy_r_natspec);
    char (*CPyDef___top_level__)(void);
};
#endif
