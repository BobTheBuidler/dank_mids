#ifndef MYPYC_NATIVE_INTERNAL_dank_mids____uid_H
#define MYPYC_NATIVE_INTERNAL_dank_mids____uid_H
#include <Python.h>
#include <CPy.h>
#include "__native__uid.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[17];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids____uid_internal;
extern CPyModule *CPyModule_dank_mids____uid;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_dank_mids___helpers____lock;
extern PyTypeObject *CPyType_UIDGenerator;
extern PyObject *CPyDef_UIDGenerator(void);
extern char CPyDef_UIDGenerator_____init__(PyObject *cpy_r_self);
extern PyObject *CPyPy_UIDGenerator_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern CPyTagged CPyDef_UIDGenerator___latest(PyObject *cpy_r_self);
extern PyObject *CPyPy_UIDGenerator___latest(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef_UIDGenerator___next(PyObject *cpy_r_self);
extern PyObject *CPyPy_UIDGenerator___next(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
