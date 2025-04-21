#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native_brownie_patch.h"
#include "__native_internal_brownie_patch.h"
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids.brownie_patch",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids___brownie_patch(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids___brownie_patch_internal) {
        Py_INCREF(CPyModule_dank_mids___brownie_patch_internal);
        return CPyModule_dank_mids___brownie_patch_internal;
    }
    CPyModule_dank_mids___brownie_patch_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids___brownie_patch_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids___brownie_patch_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids___brownie_patch_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids___brownie_patch_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids___brownie_patch_internal);
    Py_CLEAR(modname);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyPtr cpy_r_r26;
    CPyPtr cpy_r_r27;
    CPyPtr cpy_r_r28;
    CPyPtr cpy_r_r29;
    CPyPtr cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject **cpy_r_r62;
    PyObject *cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    int32_t cpy_r_r74;
    char cpy_r_r75;
    char cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject **cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    int32_t cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    int32_t cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    CPyPtr cpy_r_r111;
    CPyPtr cpy_r_r112;
    CPyPtr cpy_r_r113;
    CPyPtr cpy_r_r114;
    CPyPtr cpy_r_r115;
    PyObject *cpy_r_r116;
    int32_t cpy_r_r117;
    char cpy_r_r118;
    tuple_T3OOO cpy_r_r119;
    tuple_T3OOO cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject **cpy_r_r125;
    PyObject *cpy_r_r126;
    int32_t cpy_r_r127;
    char cpy_r_r128;
    char cpy_r_r129;
    char cpy_r_r130;
    tuple_T3OOO cpy_r_r131;
    tuple_T3OOO cpy_r_r132;
    tuple_T3OOO cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject **cpy_r_r136;
    PyObject *cpy_r_r137;
    char cpy_r_r138;
    char cpy_r_r139;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[3]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL56;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[33]; /* ('suppress',) */
    cpy_r_r6 = CPyStatics[5]; /* 'contextlib' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 1, CPyStatic_globals);
        goto CPyL56;
    }
    CPyModule_contextlib = cpy_r_r8;
    CPy_INCREF(CPyModule_contextlib);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[34]; /* ('AsyncEth',) */
    cpy_r_r10 = CPyStatics[7]; /* 'web3.eth' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 3, CPyStatic_globals);
        goto CPyL56;
    }
    CPyModule_web3___eth = cpy_r_r12;
    CPy_INCREF(CPyModule_web3___eth);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[35]; /* ('setup_dank_w3_from_sync',) */
    cpy_r_r14 = CPyStatics[9]; /* 'dank_mids.helpers' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 5, CPyStatic_globals);
        goto CPyL56;
    }
    CPyModule_dank_mids___helpers = cpy_r_r16;
    CPy_INCREF(CPyModule_dank_mids___helpers);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[36]; /* ('DankContractCall', 'DankContractMethod',
                                   'DankContractTx', 'DankOverloadedMethod') */
    cpy_r_r18 = CPyStatics[14]; /* 'dank_mids.brownie_patch.types' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 6, CPyStatic_globals);
        goto CPyL56;
    }
    CPyModule_dank_mids___brownie_patch___types = cpy_r_r20;
    CPy_INCREF(CPyModule_dank_mids___brownie_patch___types);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[10]; /* 'DankContractCall' */
    cpy_r_r22 = CPyStatics[11]; /* 'DankContractMethod' */
    cpy_r_r23 = CPyStatics[12]; /* 'DankContractTx' */
    cpy_r_r24 = CPyStatics[13]; /* 'DankOverloadedMethod' */
    cpy_r_r25 = PyList_New(4);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 13, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r26 = (CPyPtr)&((PyListObject *)cpy_r_r25)->ob_item;
    cpy_r_r27 = *(CPyPtr *)cpy_r_r26;
    CPy_INCREF(cpy_r_r21);
    *(PyObject * *)cpy_r_r27 = cpy_r_r21;
    CPy_INCREF(cpy_r_r22);
    cpy_r_r28 = cpy_r_r27 + 8;
    *(PyObject * *)cpy_r_r28 = cpy_r_r22;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r29 = cpy_r_r27 + 16;
    *(PyObject * *)cpy_r_r29 = cpy_r_r23;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r30 = cpy_r_r27 + 24;
    *(PyObject * *)cpy_r_r30 = cpy_r_r24;
    cpy_r_r31 = CPyStatic_globals;
    cpy_r_r32 = CPyStatics[15]; /* '__all__' */
    cpy_r_r33 = CPyDict_SetItem(cpy_r_r31, cpy_r_r32, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 13, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r35 = CPyStatics[37]; /* ('DankEth',) */
    cpy_r_r36 = CPyStatics[17]; /* 'dank_mids.eth' */
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyImport_ImportFromMany(cpy_r_r36, cpy_r_r35, cpy_r_r35, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 15, CPyStatic_globals);
        goto CPyL56;
    }
    CPyModule_dank_mids___eth = cpy_r_r38;
    CPy_INCREF(CPyModule_dank_mids___eth);
    CPy_DECREF(cpy_r_r38);
    cpy_r_r39 = CPyStatics[38]; /* ('DankWeb3',) */
    cpy_r_r40 = CPyStatics[19]; /* 'dank_mids.helpers._helpers' */
    cpy_r_r41 = CPyStatic_globals;
    cpy_r_r42 = CPyImport_ImportFromMany(cpy_r_r40, cpy_r_r39, cpy_r_r39, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 16, CPyStatic_globals);
        goto CPyL56;
    }
    CPyModule_dank_mids___helpers____helpers = cpy_r_r42;
    CPy_INCREF(CPyModule_dank_mids___helpers____helpers);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r43 = CPyStatic_globals;
    cpy_r_r44 = CPyStatics[20]; /* 'dank_web3' */
    cpy_r_r45 = CPyStatic_globals;
    cpy_r_r46 = CPyStatics[21]; /* 'dank_eth' */
    cpy_r_r47 = CPyModule_builtins;
    cpy_r_r48 = CPyStatics[22]; /* 'ImportError' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r50 = CPyStatic_globals;
    cpy_r_r51 = CPyStatics[4]; /* 'suppress' */
    cpy_r_r52 = CPyDict_GetItem(cpy_r_r50, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL57;
    }
    PyObject *cpy_r_r53[1] = {cpy_r_r49};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 1, 0);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_DECREF(cpy_r_r49);
    cpy_r_r56 = PyObject_Type(cpy_r_r55);
    cpy_r_r57 = CPyStatics[23]; /* '__exit__' */
    cpy_r_r58 = CPyObject_GetAttr(cpy_r_r56, cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r59 = CPyStatics[24]; /* '__enter__' */
    cpy_r_r60 = CPyObject_GetAttr(cpy_r_r56, cpy_r_r59);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL59;
    }
    PyObject *cpy_r_r61[1] = {cpy_r_r55};
    cpy_r_r62 = (PyObject **)&cpy_r_r61;
    cpy_r_r63 = _PyObject_Vectorcall(cpy_r_r60, cpy_r_r62, 1, 0);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL59;
    } else
        goto CPyL60;
CPyL17: ;
    cpy_r_r64 = 1;
    cpy_r_r65 = CPyStatics[39]; /* ('network', 'web3') */
    cpy_r_r66 = CPyStatics[27]; /* 'brownie' */
    cpy_r_r67 = CPyStatic_globals;
    cpy_r_r68 = CPyImport_ImportFromMany(cpy_r_r66, cpy_r_r65, cpy_r_r65, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 34, CPyStatic_globals);
        goto CPyL35;
    }
    CPyModule_brownie = cpy_r_r68;
    CPy_INCREF(CPyModule_brownie);
    CPy_DECREF(cpy_r_r68);
    cpy_r_r69 = CPyStatic_globals;
    cpy_r_r70 = CPyStatics[25]; /* 'network' */
    cpy_r_r71 = CPyDict_GetItem(cpy_r_r69, cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 36, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r72 = CPyStatics[28]; /* 'is_connected' */
    cpy_r_r73 = CPyObject_CallMethodObjArgs(cpy_r_r71, cpy_r_r72, NULL);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 36, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r74 = PyObject_IsTrue(cpy_r_r73);
    CPy_DECREF(cpy_r_r73);
    cpy_r_r75 = cpy_r_r74 >= 0;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 36, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r76 = cpy_r_r74;
    if (!cpy_r_r76) goto CPyL43;
    cpy_r_r77 = CPyStatics[40]; /* ('Contract', 'patch_contract') */
    cpy_r_r78 = CPyStatics[31]; /* 'dank_mids.brownie_patch.contract' */
    cpy_r_r79 = CPyStatic_globals;
    cpy_r_r80 = CPyImport_ImportFromMany(cpy_r_r78, cpy_r_r77, cpy_r_r77, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 37, CPyStatic_globals);
        goto CPyL35;
    }
    CPyModule_dank_mids___brownie_patch___contract = cpy_r_r80;
    CPy_INCREF(CPyModule_dank_mids___brownie_patch___contract);
    CPy_DECREF(cpy_r_r80);
    cpy_r_r81 = CPyStatic_globals;
    cpy_r_r82 = CPyStatics[26]; /* 'web3' */
    cpy_r_r83 = CPyDict_GetItem(cpy_r_r81, cpy_r_r82);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 39, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r84 = CPyStatic_globals;
    cpy_r_r85 = CPyStatics[8]; /* 'setup_dank_w3_from_sync' */
    cpy_r_r86 = CPyDict_GetItem(cpy_r_r84, cpy_r_r85);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 39, CPyStatic_globals);
        goto CPyL61;
    }
    PyObject *cpy_r_r87[1] = {cpy_r_r83};
    cpy_r_r88 = (PyObject **)&cpy_r_r87;
    cpy_r_r89 = _PyObject_Vectorcall(cpy_r_r86, cpy_r_r88, 1, 0);
    CPy_DECREF(cpy_r_r86);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 39, CPyStatic_globals);
        goto CPyL61;
    }
    CPy_DECREF(cpy_r_r83);
    cpy_r_r90 = CPyStatic_globals;
    cpy_r_r91 = CPyStatics[20]; /* 'dank_web3' */
    cpy_r_r92 = CPyDict_SetItem(cpy_r_r90, cpy_r_r91, cpy_r_r89);
    CPy_DECREF(cpy_r_r89);
    cpy_r_r93 = cpy_r_r92 >= 0;
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 39, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r94 = CPyStatic_globals;
    cpy_r_r95 = CPyStatics[20]; /* 'dank_web3' */
    cpy_r_r96 = CPyDict_GetItem(cpy_r_r94, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 40, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r97 = CPyStatics[32]; /* 'eth' */
    cpy_r_r98 = CPyObject_GetAttr(cpy_r_r96, cpy_r_r97);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 40, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r99 = CPyStatic_globals;
    cpy_r_r100 = CPyStatics[21]; /* 'dank_eth' */
    cpy_r_r101 = CPyDict_SetItem(cpy_r_r99, cpy_r_r100, cpy_r_r98);
    CPy_DECREF(cpy_r_r98);
    cpy_r_r102 = cpy_r_r101 >= 0;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 40, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r103 = CPyStatic_globals;
    cpy_r_r104 = CPyStatics[15]; /* '__all__' */
    cpy_r_r105 = CPyDict_GetItem(cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 41, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r106 = CPyStatics[29]; /* 'Contract' */
    cpy_r_r107 = CPyStatics[30]; /* 'patch_contract' */
    cpy_r_r108 = CPyStatics[20]; /* 'dank_web3' */
    cpy_r_r109 = CPyStatics[21]; /* 'dank_eth' */
    cpy_r_r110 = PyList_New(4);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 41, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r111 = (CPyPtr)&((PyListObject *)cpy_r_r110)->ob_item;
    cpy_r_r112 = *(CPyPtr *)cpy_r_r111;
    CPy_INCREF(cpy_r_r106);
    *(PyObject * *)cpy_r_r112 = cpy_r_r106;
    CPy_INCREF(cpy_r_r107);
    cpy_r_r113 = cpy_r_r112 + 8;
    *(PyObject * *)cpy_r_r113 = cpy_r_r107;
    CPy_INCREF(cpy_r_r108);
    cpy_r_r114 = cpy_r_r112 + 16;
    *(PyObject * *)cpy_r_r114 = cpy_r_r108;
    CPy_INCREF(cpy_r_r109);
    cpy_r_r115 = cpy_r_r112 + 24;
    *(PyObject * *)cpy_r_r115 = cpy_r_r109;
    cpy_r_r116 = PyNumber_InPlaceAdd(cpy_r_r105, cpy_r_r110);
    CPy_DECREF(cpy_r_r105);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 41, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r117 = CPyDict_SetItem(cpy_r_r103, cpy_r_r104, cpy_r_r116);
    CPy_DECREF(cpy_r_r116);
    cpy_r_r118 = cpy_r_r117 >= 0;
    if (unlikely(!cpy_r_r118)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 41, CPyStatic_globals);
    } else
        goto CPyL43;
CPyL35: ;
    cpy_r_r119 = CPy_CatchError();
    cpy_r_r64 = 0;
    cpy_r_r120 = CPy_GetExcInfo();
    cpy_r_r121 = cpy_r_r120.f0;
    CPy_INCREF(cpy_r_r121);
    cpy_r_r122 = cpy_r_r120.f1;
    CPy_INCREF(cpy_r_r122);
    cpy_r_r123 = cpy_r_r120.f2;
    CPy_INCREF(cpy_r_r123);
    CPy_DecRef(cpy_r_r120.f0);
    CPy_DecRef(cpy_r_r120.f1);
    CPy_DecRef(cpy_r_r120.f2);
    PyObject *cpy_r_r124[4] = {cpy_r_r55, cpy_r_r121, cpy_r_r122, cpy_r_r123};
    cpy_r_r125 = (PyObject **)&cpy_r_r124;
    cpy_r_r126 = _PyObject_Vectorcall(cpy_r_r58, cpy_r_r125, 4, 0);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_DecRef(cpy_r_r121);
    CPy_DecRef(cpy_r_r122);
    CPy_DecRef(cpy_r_r123);
    cpy_r_r127 = PyObject_IsTrue(cpy_r_r126);
    CPy_DecRef(cpy_r_r126);
    cpy_r_r128 = cpy_r_r127 >= 0;
    if (unlikely(!cpy_r_r128)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r129 = cpy_r_r127;
    if (cpy_r_r129) goto CPyL40;
    CPy_Reraise();
    if (!0) {
        goto CPyL41;
    } else
        goto CPyL64;
CPyL39: ;
    CPy_Unreachable();
CPyL40: ;
    CPy_RestoreExcInfo(cpy_r_r119);
    CPy_DecRef(cpy_r_r119.f0);
    CPy_DecRef(cpy_r_r119.f1);
    CPy_DecRef(cpy_r_r119.f2);
    goto CPyL43;
CPyL41: ;
    CPy_RestoreExcInfo(cpy_r_r119);
    CPy_DecRef(cpy_r_r119.f0);
    CPy_DecRef(cpy_r_r119.f1);
    CPy_DecRef(cpy_r_r119.f2);
    cpy_r_r130 = CPy_KeepPropagating();
    if (!cpy_r_r130) {
        goto CPyL44;
    } else
        goto CPyL65;
CPyL42: ;
    CPy_Unreachable();
CPyL43: ;
    tuple_T3OOO __tmp1 = { NULL, NULL, NULL };
    cpy_r_r131 = __tmp1;
    cpy_r_r132 = cpy_r_r131;
    goto CPyL45;
CPyL44: ;
    cpy_r_r133 = CPy_CatchError();
    cpy_r_r132 = cpy_r_r133;
CPyL45: ;
    if (!cpy_r_r64) goto CPyL66;
    cpy_r_r134 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r135[4] = {cpy_r_r55, cpy_r_r134, cpy_r_r134, cpy_r_r134};
    cpy_r_r136 = (PyObject **)&cpy_r_r135;
    cpy_r_r137 = _PyObject_Vectorcall(cpy_r_r58, cpy_r_r136, 4, 0);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/__init__.py", "<module>", 33, CPyStatic_globals);
        goto CPyL67;
    } else
        goto CPyL68;
CPyL47: ;
    CPy_DECREF(cpy_r_r55);
CPyL48: ;
    if (cpy_r_r132.f0 == NULL) goto CPyL55;
    CPy_Reraise();
    if (!0) {
        goto CPyL51;
    } else
        goto CPyL69;
CPyL50: ;
    CPy_Unreachable();
CPyL51: ;
    if (cpy_r_r132.f0 == NULL) goto CPyL53;
    CPy_RestoreExcInfo(cpy_r_r132);
    CPy_XDECREF(cpy_r_r132.f0);
    CPy_XDECREF(cpy_r_r132.f1);
    CPy_XDECREF(cpy_r_r132.f2);
CPyL53: ;
    cpy_r_r138 = CPy_KeepPropagating();
    if (!cpy_r_r138) goto CPyL56;
    CPy_Unreachable();
CPyL55: ;
    return 1;
CPyL56: ;
    cpy_r_r139 = 2;
    return cpy_r_r139;
CPyL57: ;
    CPy_DecRef(cpy_r_r49);
    goto CPyL56;
CPyL58: ;
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_r56);
    goto CPyL56;
CPyL59: ;
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_r58);
    goto CPyL56;
CPyL60: ;
    CPy_DECREF(cpy_r_r63);
    goto CPyL17;
CPyL61: ;
    CPy_DecRef(cpy_r_r83);
    goto CPyL35;
CPyL62: ;
    CPy_DecRef(cpy_r_r105);
    goto CPyL35;
CPyL63: ;
    CPy_DecRef(cpy_r_r121);
    CPy_DecRef(cpy_r_r122);
    CPy_DecRef(cpy_r_r123);
    goto CPyL41;
CPyL64: ;
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_r58);
    CPy_DecRef(cpy_r_r119.f0);
    CPy_DecRef(cpy_r_r119.f1);
    CPy_DecRef(cpy_r_r119.f2);
    goto CPyL39;
CPyL65: ;
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_r58);
    goto CPyL42;
CPyL66: ;
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_r58);
    goto CPyL48;
CPyL67: ;
    CPy_DecRef(cpy_r_r55);
    goto CPyL51;
CPyL68: ;
    CPy_DECREF(cpy_r_r137);
    goto CPyL47;
CPyL69: ;
    CPy_XDECREF(cpy_r_r132.f0);
    CPy_XDECREF(cpy_r_r132.f1);
    CPy_XDECREF(cpy_r_r132.f2);
    goto CPyL50;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___brownie_patch = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_contextlib = Py_None;
    CPyModule_web3___eth = Py_None;
    CPyModule_dank_mids___helpers = Py_None;
    CPyModule_dank_mids___brownie_patch___types = Py_None;
    CPyModule_dank_mids___eth = Py_None;
    CPyModule_dank_mids___helpers____helpers = Py_None;
    CPyModule_brownie = Py_None;
    CPyModule_dank_mids___brownie_patch___contract = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[41];
const char * const CPyLit_Str[] = {
    "\005\bbuiltins\bsuppress\ncontextlib\bAsyncEth\bweb3.eth",
    "\003\027setup_dank_w3_from_sync\021dank_mids.helpers\020DankContractCall",
    "\003\022DankContractMethod\016DankContractTx\024DankOverloadedMethod",
    "\005\035dank_mids.brownie_patch.types\a__all__\aDankEth\rdank_mids.eth\bDankWeb3",
    "\005\032dank_mids.helpers._helpers\tdank_web3\bdank_eth\vImportError\b__exit__",
    "\a\t__enter__\anetwork\004web3\abrownie\fis_connected\bContract\016patch_contract",
    "\002 dank_mids.brownie_patch.contract\003eth",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    8, 1, 4, 1, 6, 1, 8, 4, 10, 11, 12, 13, 1, 16, 1, 18, 2, 25, 26, 2,
    29, 30
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___brownie_patch_internal = NULL;
CPyModule *CPyModule_dank_mids___brownie_patch;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_contextlib;
CPyModule *CPyModule_web3___eth;
CPyModule *CPyModule_dank_mids___helpers;
CPyModule *CPyModule_dank_mids___brownie_patch___types;
CPyModule *CPyModule_dank_mids___eth;
CPyModule *CPyModule_dank_mids___helpers____helpers;
CPyModule *CPyModule_brownie;
CPyModule *CPyModule_dank_mids___brownie_patch___contract;
char CPyDef___top_level__(void);

static struct export_table_dank_mids___brownie_patch exports = {
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit_brownie_patch__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids.brownie_patch__mypyc", NULL, -1, NULL, NULL };
    int res;
    PyObject *capsule;
    PyObject *tmp;
    static PyObject *module;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&def);
    if (!module) {
        goto fail;
    }
    
    capsule = PyCapsule_New(&exports, "dank_mids.brownie_patch__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids___brownie_patch(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids___brownie_patch, "dank_mids.brownie_patch__mypyc.init_dank_mids___brownie_patch", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids___brownie_patch", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
