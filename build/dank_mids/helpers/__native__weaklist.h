#ifndef MYPYC_NATIVE_dank_mids___helpers____weaklist_H
#define MYPYC_NATIVE_dank_mids___helpers____weaklist_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T3CIO
#define MYPYC_DECLARED_tuple_T3CIO
typedef struct tuple_T3CIO {
    char f0;
    CPyTagged f1;
    PyObject *f2;
} tuple_T3CIO;
#endif

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

#ifndef MYPYC_DECLARED_tuple_T2IO
#define MYPYC_DECLARED_tuple_T2IO
typedef struct tuple_T2IO {
    CPyTagged f0;
    PyObject *f1;
} tuple_T2IO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *__refs;
} dank_mids___helpers____weaklist___WeakListObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_self;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    PyObject *___mypyc_temp__1;
    CPyTagged ___mypyc_temp__2;
    CPyTagged ___mypyc_temp__3;
    PyObject *___mypyc_temp__4;
    PyObject *_r;
    PyObject *_refs;
    PyObject *___mypyc_temp__5;
    PyObject *___mypyc_temp__6;
    PyObject *_obj;
} dank_mids___helpers____weaklist_____iter___3_WeakList_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___helpers____weaklist_____iter___3_WeakList_genObject;


struct export_table_dank_mids___helpers____weaklist {
    PyTypeObject **CPyType_WeakList;
    PyObject *(*CPyDef_WeakList)(PyObject *cpy_r_data);
    PyTypeObject **CPyType___iter___3_WeakList_env;
    PyObject *(*CPyDef___iter___3_WeakList_env)(void);
    PyTypeObject **CPyType___iter___3_WeakList_gen;
    PyObject *(*CPyDef___iter___3_WeakList_gen)(void);
    char (*CPyDef_WeakList_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_data);
    PyObject *(*CPyDef_WeakList_____repr__)(PyObject *cpy_r_self);
    CPyTagged (*CPyDef_WeakList_____len__)(PyObject *cpy_r_self);
    char (*CPyDef_WeakList_____bool__)(PyObject *cpy_r_self);
    char (*CPyDef_WeakList_____contains__)(PyObject *cpy_r_self, PyObject *cpy_r_item);
    PyObject *(*CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef___iter___3_WeakList_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef___iter___3_WeakList_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef___iter___3_WeakList_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef___iter___3_WeakList_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef___iter___3_WeakList_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_WeakList_____iter__)(PyObject *cpy_r_self);
    char (*CPyDef_WeakList___append)(PyObject *cpy_r_self, PyObject *cpy_r_item);
    char (*CPyDef_WeakList___extend)(PyObject *cpy_r_self, PyObject *cpy_r_items);
    char (*CPyDef_WeakList___remove)(PyObject *cpy_r_self, PyObject *cpy_r_item);
    char (*CPyDef_WeakList____gc_callback)(PyObject *cpy_r_self, PyObject *cpy_r_item);
    char (*CPyDef___top_level__)(void);
};
#endif
