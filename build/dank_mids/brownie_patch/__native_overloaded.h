#ifndef MYPYC_NATIVE_dank_mids___brownie_patch___overloaded_H
#define MYPYC_NATIVE_dank_mids___brownie_patch___overloaded_H
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

#ifndef MYPYC_DECLARED_tuple_T4CIOO
#define MYPYC_DECLARED_tuple_T4CIOO
typedef struct tuple_T4CIOO {
    char f0;
    CPyTagged f1;
    PyObject *f2;
    PyObject *f3;
} tuple_T4CIOO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_call;
    PyObject *_coroutine;
    PyObject *_w3;
} dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *___mypyc_env__;
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
    PyObject *_fn;
    tuple_T3OOO ___mypyc_temp__0;
    PyObject *_e;
    PyObject *_exc_str;
    tuple_T2OO _match_on;
    tuple_T2OO ___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
    PyObject *_s;
    CPyTagged _breakpoint;
    PyObject *_kwargs;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_temp__4;
    CPyTagged ___mypyc_temp__5;
    CPyTagged ___mypyc_temp__6;
    PyObject *___mypyc_temp__7;
    PyObject *_k;
    PyObject *_v;
    PyObject *___mypyc_temp__8;
    tuple_T3OOO ___mypyc_temp__9;
} dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject;


struct export_table_dank_mids___brownie_patch___overloaded {
    PyTypeObject **CPyType__patch_overloaded_method_env;
    PyObject *(*CPyDef__patch_overloaded_method_env)(void);
    PyTypeObject **CPyType_coroutine__patch_overloaded_method_env;
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_env)(void);
    PyTypeObject **CPyType_coroutine__patch_overloaded_method_obj;
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_obj)(void);
    PyTypeObject **CPyType_coroutine__patch_overloaded_method_gen;
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_gen)(void);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine__patch_overloaded_method_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
    char (*CPyDef__patch_overloaded_method)(PyObject *cpy_r_call, PyObject *cpy_r_w3);
    char (*CPyDef___top_level__)(void);
};
#endif
