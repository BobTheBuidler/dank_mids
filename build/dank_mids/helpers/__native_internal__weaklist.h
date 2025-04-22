#ifndef MYPYC_NATIVE_INTERNAL_dank_mids___helpers____weaklist_H
#define MYPYC_NATIVE_INTERNAL_dank_mids___helpers____weaklist_H
#include <Python.h>
#include <CPy.h>
#include "__native__weaklist.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[44];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids___helpers____weaklist_internal;
extern CPyModule *CPyModule_dank_mids___helpers____weaklist;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_weakref;
extern CPyModule *CPyModule_typing;
extern PyObject *CPyStatic_ref;
extern PyObject *CPyStatic__call_ref;
extern PyTypeObject *CPyType_WeakList;
extern PyObject *CPyDef_WeakList(PyObject *cpy_r_data);
extern PyTypeObject *CPyType___iter___3_WeakList_env;
extern PyObject *CPyDef___iter___3_WeakList_env(void);
extern PyTypeObject *CPyType___iter___3_WeakList_gen;
extern PyObject *CPyDef___iter___3_WeakList_gen(void);
extern char CPyDef_WeakList_____init__(PyObject *cpy_r_self, PyObject *cpy_r_data);
extern PyObject *CPyPy_WeakList_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_WeakList_____repr__(PyObject *cpy_r_self);
extern PyObject *CPyPy_WeakList_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef_WeakList_____len__(PyObject *cpy_r_self);
extern PyObject *CPyPy_WeakList_____len__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_WeakList_____bool__(PyObject *cpy_r_self);
extern PyObject *CPyPy_WeakList_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_WeakList_____contains__(PyObject *cpy_r_self, PyObject *cpy_r_item);
extern PyObject *CPyPy_WeakList_____contains__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
extern PyObject *CPyPy___iter___3_WeakList_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___iter___3_WeakList_gen_____next__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy___iter___3_WeakList_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___iter___3_WeakList_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
extern PyObject *CPyPy___iter___3_WeakList_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___iter___3_WeakList_gen_____iter__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy___iter___3_WeakList_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___iter___3_WeakList_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
extern PyObject *CPyPy___iter___3_WeakList_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___iter___3_WeakList_gen___close(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy___iter___3_WeakList_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_WeakList_____iter__(PyObject *cpy_r_self);
extern PyObject *CPyPy_WeakList_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_WeakList___append(PyObject *cpy_r_self, PyObject *cpy_r_item);
extern PyObject *CPyPy_WeakList___append(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_WeakList___extend(PyObject *cpy_r_self, PyObject *cpy_r_items);
extern PyObject *CPyPy_WeakList___extend(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_WeakList___remove(PyObject *cpy_r_self, PyObject *cpy_r_item);
extern PyObject *CPyPy_WeakList___remove(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_WeakList____gc_callback(PyObject *cpy_r_self, PyObject *cpy_r_item);
extern PyObject *CPyPy_WeakList____gc_callback(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
