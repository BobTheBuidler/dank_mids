#ifndef MYPYC_NATIVE_INTERNAL_dank_mids___brownie_patch_H
#define MYPYC_NATIVE_INTERNAL_dank_mids___brownie_patch_H
#include <Python.h>
#include <CPy.h>
#include "__native_brownie_patch.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[41];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_dank_mids___brownie_patch_internal;
extern CPyModule *CPyModule_dank_mids___brownie_patch;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_contextlib;
extern CPyModule *CPyModule_web3___eth;
extern CPyModule *CPyModule_dank_mids___helpers;
extern CPyModule *CPyModule_dank_mids___brownie_patch___types;
extern CPyModule *CPyModule_dank_mids___eth;
extern CPyModule *CPyModule_dank_mids___helpers____helpers;
extern CPyModule *CPyModule_brownie;
extern CPyModule *CPyModule_dank_mids___brownie_patch___contract;
extern char CPyDef___top_level__(void);
#endif
