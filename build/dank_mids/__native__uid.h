#ifndef MYPYC_NATIVE_dank_mids____uid_H
#define MYPYC_NATIVE_dank_mids____uid_H
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

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    CPyTagged __value;
    PyObject *__lock;
} dank_mids____uid___UIDGeneratorObject;


struct export_table_dank_mids____uid {
    PyTypeObject **CPyType_UIDGenerator;
    PyObject *(*CPyDef_UIDGenerator)(void);
    char (*CPyDef_UIDGenerator_____init__)(PyObject *cpy_r_self);
    CPyTagged (*CPyDef_UIDGenerator___latest)(PyObject *cpy_r_self);
    CPyTagged (*CPyDef_UIDGenerator___next)(PyObject *cpy_r_self);
    char (*CPyDef___top_level__)(void);
};
#endif
