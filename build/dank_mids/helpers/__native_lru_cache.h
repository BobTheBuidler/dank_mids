#ifndef MYPYC_NATIVE_dank_mids___helpers___lru_cache_H
#define MYPYC_NATIVE_dank_mids___helpers___lru_cache_H
#include <Python.h>
#include <CPy.h>
typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_func;
    PyObject *_cache;
    PyObject *_cache_miss;
    PyObject *_lru_cache_lite_wrap;
} dank_mids___helpers___lru_cache___lru_cache_lite_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_func;
    PyObject *_cache;
    PyObject *_lru_cache_lite_wrap;
} dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject;


struct export_table_dank_mids___helpers___lru_cache {
    PyTypeObject **CPyType_lru_cache_lite_env;
    PyObject *(*CPyDef_lru_cache_lite_env)(void);
    PyTypeObject **CPyType_lru_cache_lite_wrap_lru_cache_lite_obj;
    PyObject *(*CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj)(void);
    PyTypeObject **CPyType_lru_cache_lite_nonull_env;
    PyObject *(*CPyDef_lru_cache_lite_nonull_env)(void);
    PyTypeObject **CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj;
    PyObject *(*CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj)(void);
    PyObject *(*CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args);
    PyObject *(*CPyDef_lru_cache_lite)(PyObject *cpy_r_func);
    PyObject *(*CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args);
    PyObject *(*CPyDef_lru_cache_lite_nonull)(PyObject *cpy_r_func);
    char (*CPyDef___top_level__)(void);
};
#endif
