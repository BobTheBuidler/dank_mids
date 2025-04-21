#ifndef MYPYC_NATIVE_dank_mids___brownie_patch_H
#define MYPYC_NATIVE_dank_mids___brownie_patch_H
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


struct export_table_dank_mids___brownie_patch {
    char (*CPyDef___top_level__)(void);
};
#endif
