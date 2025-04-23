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
#include "__native__eth_utils.h"
#include "__native_internal__eth_utils.h"
static PyMethodDef module_methods[] = {
    {"patch_eth_utils", (PyCFunction)CPyPy_patch_eth_utils, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"to_hex", (PyCFunction)CPyPy_to_hex, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"to_bytes", (PyCFunction)CPyPy_to_bytes, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"decode_hex", (PyCFunction)CPyPy_decode_hex, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"encode_hex", (PyCFunction)CPyPy_encode_hex, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"is_0x_prefixed", (PyCFunction)CPyPy_is_0x_prefixed, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"remove_0x_prefix", (PyCFunction)CPyPy_remove_0x_prefix, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"add_0x_prefix", (PyCFunction)CPyPy_add_0x_prefix, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids._eth_utils",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids____eth_utils(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids____eth_utils_internal) {
        Py_INCREF(CPyModule_dank_mids____eth_utils_internal);
        return CPyModule_dank_mids____eth_utils_internal;
    }
    CPyModule_dank_mids____eth_utils_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids____eth_utils_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids____eth_utils_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids____eth_utils_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids____eth_utils_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids____eth_utils_internal);
    Py_CLEAR(modname);
    return NULL;
}

char CPyDef_patch_eth_utils(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    int32_t cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
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
    int32_t cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    int32_t cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    int32_t cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    int32_t cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
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
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    int32_t cpy_r_r105;
    char cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    char cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    int32_t cpy_r_r117;
    char cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    int32_t cpy_r_r130;
    char cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    int32_t cpy_r_r143;
    char cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    char cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    int32_t cpy_r_r155;
    char cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    int32_t cpy_r_r168;
    char cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    int32_t cpy_r_r181;
    char cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    char cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    int32_t cpy_r_r193;
    char cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    int32_t cpy_r_r206;
    char cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    int32_t cpy_r_r219;
    char cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    char cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    int32_t cpy_r_r231;
    char cpy_r_r232;
    tuple_T3OOO cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    char cpy_r_r237;
    char cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    int32_t cpy_r_r250;
    char cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    int32_t cpy_r_r263;
    char cpy_r_r264;
    char cpy_r_r265;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyModule_eth_utils___crypto;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = cpy_r_r1 != cpy_r_r2;
    if (cpy_r_r3) goto CPyL3;
    cpy_r_r4 = CPyStatics[3]; /* 'eth_utils.crypto' */
    cpy_r_r5 = PyImport_Import(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 21, CPyStatic_globals);
        goto CPyL110;
    }
    CPyModule_eth_utils___crypto = cpy_r_r5;
    CPy_INCREF(CPyModule_eth_utils___crypto);
    CPy_DECREF(cpy_r_r5);
CPyL3: ;
    cpy_r_r6 = CPyStatics[4]; /* 'eth_utils' */
    cpy_r_r7 = PyImport_GetModuleDict();
    cpy_r_r8 = CPyStatics[4]; /* 'eth_utils' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 21, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r10 = CPyDict_SetItem(cpy_r_r0, cpy_r_r6, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 21, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r12 = CPyStatic_globals;
    cpy_r_r13 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r14 = CPyDict_GetItem(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 23, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[4]; /* 'eth_utils' */
    cpy_r_r17 = CPyDict_GetItem(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 23, CPyStatic_globals);
        goto CPyL111;
    }
    cpy_r_r18 = CPyStatics[6]; /* 'crypto' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 23, CPyStatic_globals);
        goto CPyL111;
    }
    cpy_r_r20 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r21 = PyObject_SetAttr(cpy_r_r19, cpy_r_r20, cpy_r_r14);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r14);
    cpy_r_r22 = cpy_r_r21 >= 0;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 23, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyModule_web3___main;
    cpy_r_r25 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r26 = cpy_r_r24 != cpy_r_r25;
    if (cpy_r_r26) goto CPyL12;
    cpy_r_r27 = CPyStatics[7]; /* 'web3.main' */
    cpy_r_r28 = PyImport_Import(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 25, CPyStatic_globals);
        goto CPyL110;
    }
    CPyModule_web3___main = cpy_r_r28;
    CPy_INCREF(CPyModule_web3___main);
    CPy_DECREF(cpy_r_r28);
CPyL12: ;
    cpy_r_r29 = CPyStatics[8]; /* 'web3' */
    cpy_r_r30 = PyImport_GetModuleDict();
    cpy_r_r31 = CPyStatics[8]; /* 'web3' */
    cpy_r_r32 = CPyDict_GetItem(cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 25, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r33 = CPyDict_SetItem(cpy_r_r23, cpy_r_r29, cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 25, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r37 = CPyDict_GetItem(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 27, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r38 = CPyStatic_globals;
    cpy_r_r39 = CPyStatics[8]; /* 'web3' */
    cpy_r_r40 = CPyDict_GetItem(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 27, CPyStatic_globals);
        goto CPyL112;
    }
    cpy_r_r41 = CPyStatics[10]; /* 'main' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 27, CPyStatic_globals);
        goto CPyL112;
    }
    cpy_r_r43 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r44 = PyObject_SetAttr(cpy_r_r42, cpy_r_r43, cpy_r_r37);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r37);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 27, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r46 = CPyStatic_globals;
    cpy_r_r47 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r48 = CPyDict_GetItem(cpy_r_r46, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 28, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r49 = CPyStatic_globals;
    cpy_r_r50 = CPyStatics[8]; /* 'web3' */
    cpy_r_r51 = CPyDict_GetItem(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 28, CPyStatic_globals);
        goto CPyL113;
    }
    cpy_r_r52 = CPyStatics[10]; /* 'main' */
    cpy_r_r53 = CPyObject_GetAttr(cpy_r_r51, cpy_r_r52);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 28, CPyStatic_globals);
        goto CPyL113;
    }
    cpy_r_r54 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r55 = PyObject_SetAttr(cpy_r_r53, cpy_r_r54, cpy_r_r48);
    CPy_DECREF(cpy_r_r53);
    CPy_DECREF(cpy_r_r48);
    cpy_r_r56 = cpy_r_r55 >= 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 28, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r57 = CPyStatic_globals;
    cpy_r_r58 = CPyModule_web3___middleware___filter;
    cpy_r_r59 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r60 = cpy_r_r58 != cpy_r_r59;
    if (cpy_r_r60) goto CPyL25;
    cpy_r_r61 = CPyStatics[11]; /* 'web3.middleware.filter' */
    cpy_r_r62 = PyImport_Import(cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 30, CPyStatic_globals);
        goto CPyL110;
    }
    CPyModule_web3___middleware___filter = cpy_r_r62;
    CPy_INCREF(CPyModule_web3___middleware___filter);
    CPy_DECREF(cpy_r_r62);
CPyL25: ;
    cpy_r_r63 = CPyStatics[8]; /* 'web3' */
    cpy_r_r64 = PyImport_GetModuleDict();
    cpy_r_r65 = CPyStatics[8]; /* 'web3' */
    cpy_r_r66 = CPyDict_GetItem(cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 30, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r67 = CPyDict_SetItem(cpy_r_r57, cpy_r_r63, cpy_r_r66);
    CPy_DECREF(cpy_r_r66);
    cpy_r_r68 = cpy_r_r67 >= 0;
    if (unlikely(!cpy_r_r68)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 30, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r69 = CPyStatic_globals;
    cpy_r_r70 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r71 = CPyDict_GetItem(cpy_r_r69, cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 32, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r72 = CPyStatic_globals;
    cpy_r_r73 = CPyStatics[8]; /* 'web3' */
    cpy_r_r74 = CPyDict_GetItem(cpy_r_r72, cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 32, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r75 = CPyStatics[12]; /* 'middleware' */
    cpy_r_r76 = CPyObject_GetAttr(cpy_r_r74, cpy_r_r75);
    CPy_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 32, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r77 = CPyStatics[13]; /* 'filter' */
    cpy_r_r78 = CPyObject_GetAttr(cpy_r_r76, cpy_r_r77);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 32, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r79 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r80 = PyObject_SetAttr(cpy_r_r78, cpy_r_r79, cpy_r_r71);
    CPy_DECREF(cpy_r_r78);
    CPy_DECREF(cpy_r_r71);
    cpy_r_r81 = cpy_r_r80 >= 0;
    if (unlikely(!cpy_r_r81)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 32, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r82 = CPyStatic_globals;
    cpy_r_r83 = CPyModule_web3___providers___base;
    cpy_r_r84 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r85 = cpy_r_r83 != cpy_r_r84;
    if (cpy_r_r85) goto CPyL35;
    cpy_r_r86 = CPyStatics[14]; /* 'web3.providers.base' */
    cpy_r_r87 = PyImport_Import(cpy_r_r86);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 34, CPyStatic_globals);
        goto CPyL110;
    }
    CPyModule_web3___providers___base = cpy_r_r87;
    CPy_INCREF(CPyModule_web3___providers___base);
    CPy_DECREF(cpy_r_r87);
CPyL35: ;
    cpy_r_r88 = CPyStatics[8]; /* 'web3' */
    cpy_r_r89 = PyImport_GetModuleDict();
    cpy_r_r90 = CPyStatics[8]; /* 'web3' */
    cpy_r_r91 = CPyDict_GetItem(cpy_r_r89, cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 34, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r92 = CPyDict_SetItem(cpy_r_r82, cpy_r_r88, cpy_r_r91);
    CPy_DECREF(cpy_r_r91);
    cpy_r_r93 = cpy_r_r92 >= 0;
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 34, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r94 = CPyStatic_globals;
    cpy_r_r95 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r96 = CPyDict_GetItem(cpy_r_r94, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 36, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r97 = CPyStatic_globals;
    cpy_r_r98 = CPyStatics[8]; /* 'web3' */
    cpy_r_r99 = CPyDict_GetItem(cpy_r_r97, cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 36, CPyStatic_globals);
        goto CPyL115;
    }
    cpy_r_r100 = CPyStatics[15]; /* 'providers' */
    cpy_r_r101 = CPyObject_GetAttr(cpy_r_r99, cpy_r_r100);
    CPy_DECREF(cpy_r_r99);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 36, CPyStatic_globals);
        goto CPyL115;
    }
    cpy_r_r102 = CPyStatics[16]; /* 'base' */
    cpy_r_r103 = CPyObject_GetAttr(cpy_r_r101, cpy_r_r102);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 36, CPyStatic_globals);
        goto CPyL115;
    }
    cpy_r_r104 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r105 = PyObject_SetAttr(cpy_r_r103, cpy_r_r104, cpy_r_r96);
    CPy_DECREF(cpy_r_r103);
    CPy_DECREF(cpy_r_r96);
    cpy_r_r106 = cpy_r_r105 >= 0;
    if (unlikely(!cpy_r_r106)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 36, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r107 = CPyStatic_globals;
    cpy_r_r108 = CPyModule_web3____utils___encoding;
    cpy_r_r109 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r110 = cpy_r_r108 != cpy_r_r109;
    if (cpy_r_r110) goto CPyL45;
    cpy_r_r111 = CPyStatics[17]; /* 'web3._utils.encoding' */
    cpy_r_r112 = PyImport_Import(cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 38, CPyStatic_globals);
        goto CPyL110;
    }
    CPyModule_web3____utils___encoding = cpy_r_r112;
    CPy_INCREF(CPyModule_web3____utils___encoding);
    CPy_DECREF(cpy_r_r112);
CPyL45: ;
    cpy_r_r113 = CPyStatics[8]; /* 'web3' */
    cpy_r_r114 = PyImport_GetModuleDict();
    cpy_r_r115 = CPyStatics[8]; /* 'web3' */
    cpy_r_r116 = CPyDict_GetItem(cpy_r_r114, cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 38, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r117 = CPyDict_SetItem(cpy_r_r107, cpy_r_r113, cpy_r_r116);
    CPy_DECREF(cpy_r_r116);
    cpy_r_r118 = cpy_r_r117 >= 0;
    if (unlikely(!cpy_r_r118)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 38, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r119 = CPyStatic_globals;
    cpy_r_r120 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r121 = CPyDict_GetItem(cpy_r_r119, cpy_r_r120);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 40, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r122 = CPyStatic_globals;
    cpy_r_r123 = CPyStatics[8]; /* 'web3' */
    cpy_r_r124 = CPyDict_GetItem(cpy_r_r122, cpy_r_r123);
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 40, CPyStatic_globals);
        goto CPyL116;
    }
    cpy_r_r125 = CPyStatics[18]; /* '_utils' */
    cpy_r_r126 = CPyObject_GetAttr(cpy_r_r124, cpy_r_r125);
    CPy_DECREF(cpy_r_r124);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 40, CPyStatic_globals);
        goto CPyL116;
    }
    cpy_r_r127 = CPyStatics[19]; /* 'encoding' */
    cpy_r_r128 = CPyObject_GetAttr(cpy_r_r126, cpy_r_r127);
    CPy_DECREF(cpy_r_r126);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 40, CPyStatic_globals);
        goto CPyL116;
    }
    cpy_r_r129 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r130 = PyObject_SetAttr(cpy_r_r128, cpy_r_r129, cpy_r_r121);
    CPy_DECREF(cpy_r_r128);
    CPy_DECREF(cpy_r_r121);
    cpy_r_r131 = cpy_r_r130 >= 0;
    if (unlikely(!cpy_r_r131)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 40, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r132 = CPyStatic_globals;
    cpy_r_r133 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r134 = CPyDict_GetItem(cpy_r_r132, cpy_r_r133);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 41, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r135 = CPyStatic_globals;
    cpy_r_r136 = CPyStatics[8]; /* 'web3' */
    cpy_r_r137 = CPyDict_GetItem(cpy_r_r135, cpy_r_r136);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 41, CPyStatic_globals);
        goto CPyL117;
    }
    cpy_r_r138 = CPyStatics[18]; /* '_utils' */
    cpy_r_r139 = CPyObject_GetAttr(cpy_r_r137, cpy_r_r138);
    CPy_DECREF(cpy_r_r137);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 41, CPyStatic_globals);
        goto CPyL117;
    }
    cpy_r_r140 = CPyStatics[19]; /* 'encoding' */
    cpy_r_r141 = CPyObject_GetAttr(cpy_r_r139, cpy_r_r140);
    CPy_DECREF(cpy_r_r139);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 41, CPyStatic_globals);
        goto CPyL117;
    }
    cpy_r_r142 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r143 = PyObject_SetAttr(cpy_r_r141, cpy_r_r142, cpy_r_r134);
    CPy_DECREF(cpy_r_r141);
    CPy_DECREF(cpy_r_r134);
    cpy_r_r144 = cpy_r_r143 >= 0;
    if (unlikely(!cpy_r_r144)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 41, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r145 = CPyStatic_globals;
    cpy_r_r146 = CPyModule_web3____utils___events;
    cpy_r_r147 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r148 = cpy_r_r146 != cpy_r_r147;
    if (cpy_r_r148) goto CPyL60;
    cpy_r_r149 = CPyStatics[20]; /* 'web3._utils.events' */
    cpy_r_r150 = PyImport_Import(cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 43, CPyStatic_globals);
        goto CPyL110;
    }
    CPyModule_web3____utils___events = cpy_r_r150;
    CPy_INCREF(CPyModule_web3____utils___events);
    CPy_DECREF(cpy_r_r150);
CPyL60: ;
    cpy_r_r151 = CPyStatics[8]; /* 'web3' */
    cpy_r_r152 = PyImport_GetModuleDict();
    cpy_r_r153 = CPyStatics[8]; /* 'web3' */
    cpy_r_r154 = CPyDict_GetItem(cpy_r_r152, cpy_r_r153);
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 43, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r155 = CPyDict_SetItem(cpy_r_r145, cpy_r_r151, cpy_r_r154);
    CPy_DECREF(cpy_r_r154);
    cpy_r_r156 = cpy_r_r155 >= 0;
    if (unlikely(!cpy_r_r156)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 43, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r157 = CPyStatic_globals;
    cpy_r_r158 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r159 = CPyDict_GetItem(cpy_r_r157, cpy_r_r158);
    if (unlikely(cpy_r_r159 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 45, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r160 = CPyStatic_globals;
    cpy_r_r161 = CPyStatics[8]; /* 'web3' */
    cpy_r_r162 = CPyDict_GetItem(cpy_r_r160, cpy_r_r161);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 45, CPyStatic_globals);
        goto CPyL118;
    }
    cpy_r_r163 = CPyStatics[18]; /* '_utils' */
    cpy_r_r164 = CPyObject_GetAttr(cpy_r_r162, cpy_r_r163);
    CPy_DECREF(cpy_r_r162);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 45, CPyStatic_globals);
        goto CPyL118;
    }
    cpy_r_r165 = CPyStatics[21]; /* 'events' */
    cpy_r_r166 = CPyObject_GetAttr(cpy_r_r164, cpy_r_r165);
    CPy_DECREF(cpy_r_r164);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 45, CPyStatic_globals);
        goto CPyL118;
    }
    cpy_r_r167 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r168 = PyObject_SetAttr(cpy_r_r166, cpy_r_r167, cpy_r_r159);
    CPy_DECREF(cpy_r_r166);
    CPy_DECREF(cpy_r_r159);
    cpy_r_r169 = cpy_r_r168 >= 0;
    if (unlikely(!cpy_r_r169)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 45, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r170 = CPyStatic_globals;
    cpy_r_r171 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r172 = CPyDict_GetItem(cpy_r_r170, cpy_r_r171);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 46, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r173 = CPyStatic_globals;
    cpy_r_r174 = CPyStatics[8]; /* 'web3' */
    cpy_r_r175 = CPyDict_GetItem(cpy_r_r173, cpy_r_r174);
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 46, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r176 = CPyStatics[18]; /* '_utils' */
    cpy_r_r177 = CPyObject_GetAttr(cpy_r_r175, cpy_r_r176);
    CPy_DECREF(cpy_r_r175);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 46, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r178 = CPyStatics[21]; /* 'events' */
    cpy_r_r179 = CPyObject_GetAttr(cpy_r_r177, cpy_r_r178);
    CPy_DECREF(cpy_r_r177);
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 46, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r180 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r181 = PyObject_SetAttr(cpy_r_r179, cpy_r_r180, cpy_r_r172);
    CPy_DECREF(cpy_r_r179);
    CPy_DECREF(cpy_r_r172);
    cpy_r_r182 = cpy_r_r181 >= 0;
    if (unlikely(!cpy_r_r182)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 46, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r183 = CPyStatic_globals;
    cpy_r_r184 = CPyModule_web3____utils___normalizers;
    cpy_r_r185 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r186 = cpy_r_r184 != cpy_r_r185;
    if (cpy_r_r186) goto CPyL75;
    cpy_r_r187 = CPyStatics[22]; /* 'web3._utils.normalizers' */
    cpy_r_r188 = PyImport_Import(cpy_r_r187);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 48, CPyStatic_globals);
        goto CPyL110;
    }
    CPyModule_web3____utils___normalizers = cpy_r_r188;
    CPy_INCREF(CPyModule_web3____utils___normalizers);
    CPy_DECREF(cpy_r_r188);
CPyL75: ;
    cpy_r_r189 = CPyStatics[8]; /* 'web3' */
    cpy_r_r190 = PyImport_GetModuleDict();
    cpy_r_r191 = CPyStatics[8]; /* 'web3' */
    cpy_r_r192 = CPyDict_GetItem(cpy_r_r190, cpy_r_r191);
    if (unlikely(cpy_r_r192 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 48, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r193 = CPyDict_SetItem(cpy_r_r183, cpy_r_r189, cpy_r_r192);
    CPy_DECREF(cpy_r_r192);
    cpy_r_r194 = cpy_r_r193 >= 0;
    if (unlikely(!cpy_r_r194)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 48, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r195 = CPyStatic_globals;
    cpy_r_r196 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r197 = CPyDict_GetItem(cpy_r_r195, cpy_r_r196);
    if (unlikely(cpy_r_r197 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 50, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r198 = CPyStatic_globals;
    cpy_r_r199 = CPyStatics[8]; /* 'web3' */
    cpy_r_r200 = CPyDict_GetItem(cpy_r_r198, cpy_r_r199);
    if (unlikely(cpy_r_r200 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 50, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r201 = CPyStatics[18]; /* '_utils' */
    cpy_r_r202 = CPyObject_GetAttr(cpy_r_r200, cpy_r_r201);
    CPy_DECREF(cpy_r_r200);
    if (unlikely(cpy_r_r202 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 50, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r203 = CPyStatics[23]; /* 'normalizers' */
    cpy_r_r204 = CPyObject_GetAttr(cpy_r_r202, cpy_r_r203);
    CPy_DECREF(cpy_r_r202);
    if (unlikely(cpy_r_r204 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 50, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r205 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r206 = PyObject_SetAttr(cpy_r_r204, cpy_r_r205, cpy_r_r197);
    CPy_DECREF(cpy_r_r204);
    CPy_DECREF(cpy_r_r197);
    cpy_r_r207 = cpy_r_r206 >= 0;
    if (unlikely(!cpy_r_r207)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 50, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r208 = CPyStatic_globals;
    cpy_r_r209 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r210 = CPyDict_GetItem(cpy_r_r208, cpy_r_r209);
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 51, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r211 = CPyStatic_globals;
    cpy_r_r212 = CPyStatics[8]; /* 'web3' */
    cpy_r_r213 = CPyDict_GetItem(cpy_r_r211, cpy_r_r212);
    if (unlikely(cpy_r_r213 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 51, CPyStatic_globals);
        goto CPyL121;
    }
    cpy_r_r214 = CPyStatics[18]; /* '_utils' */
    cpy_r_r215 = CPyObject_GetAttr(cpy_r_r213, cpy_r_r214);
    CPy_DECREF(cpy_r_r213);
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 51, CPyStatic_globals);
        goto CPyL121;
    }
    cpy_r_r216 = CPyStatics[23]; /* 'normalizers' */
    cpy_r_r217 = CPyObject_GetAttr(cpy_r_r215, cpy_r_r216);
    CPy_DECREF(cpy_r_r215);
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 51, CPyStatic_globals);
        goto CPyL121;
    }
    cpy_r_r218 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r219 = PyObject_SetAttr(cpy_r_r217, cpy_r_r218, cpy_r_r210);
    CPy_DECREF(cpy_r_r217);
    CPy_DECREF(cpy_r_r210);
    cpy_r_r220 = cpy_r_r219 >= 0;
    if (unlikely(!cpy_r_r220)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 51, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r221 = CPyStatic_globals;
    cpy_r_r222 = CPyModule_web3____utils___type_conversion;
    cpy_r_r223 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r224 = cpy_r_r222 != cpy_r_r223;
    if (cpy_r_r224) goto CPyL90;
    cpy_r_r225 = CPyStatics[24]; /* 'web3._utils.type_conversion' */
    cpy_r_r226 = PyImport_Import(cpy_r_r225);
    if (unlikely(cpy_r_r226 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 55, CPyStatic_globals);
        goto CPyL92;
    }
    CPyModule_web3____utils___type_conversion = cpy_r_r226;
    CPy_INCREF(CPyModule_web3____utils___type_conversion);
    CPy_DECREF(cpy_r_r226);
CPyL90: ;
    cpy_r_r227 = CPyStatics[8]; /* 'web3' */
    cpy_r_r228 = PyImport_GetModuleDict();
    cpy_r_r229 = CPyStatics[8]; /* 'web3' */
    cpy_r_r230 = CPyDict_GetItem(cpy_r_r228, cpy_r_r229);
    if (unlikely(cpy_r_r230 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 55, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r231 = CPyDict_SetItem(cpy_r_r221, cpy_r_r227, cpy_r_r230);
    CPy_DECREF(cpy_r_r230);
    cpy_r_r232 = cpy_r_r231 >= 0;
    if (unlikely(!cpy_r_r232)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 55, CPyStatic_globals);
    } else
        goto CPyL99;
CPyL92: ;
    cpy_r_r233 = CPy_CatchError();
    cpy_r_r234 = CPyModule_builtins;
    cpy_r_r235 = CPyStatics[25]; /* 'ModuleNotFoundError' */
    cpy_r_r236 = CPyObject_GetAttr(cpy_r_r234, cpy_r_r235);
    if (unlikely(cpy_r_r236 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 56, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r237 = CPy_ExceptionMatches(cpy_r_r236);
    CPy_DecRef(cpy_r_r236);
    if (cpy_r_r237) goto CPyL96;
    CPy_Reraise();
    if (!0) {
        goto CPyL97;
    } else
        goto CPyL122;
CPyL95: ;
    CPy_Unreachable();
CPyL96: ;
    CPy_RestoreExcInfo(cpy_r_r233);
    CPy_DecRef(cpy_r_r233.f0);
    CPy_DecRef(cpy_r_r233.f1);
    CPy_DecRef(cpy_r_r233.f2);
    goto CPyL109;
CPyL97: ;
    CPy_RestoreExcInfo(cpy_r_r233);
    CPy_DecRef(cpy_r_r233.f0);
    CPy_DecRef(cpy_r_r233.f1);
    CPy_DecRef(cpy_r_r233.f2);
    cpy_r_r238 = CPy_KeepPropagating();
    if (!cpy_r_r238) goto CPyL110;
    CPy_Unreachable();
CPyL99: ;
    cpy_r_r239 = CPyStatic_globals;
    cpy_r_r240 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r241 = CPyDict_GetItem(cpy_r_r239, cpy_r_r240);
    if (unlikely(cpy_r_r241 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 59, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r242 = CPyStatic_globals;
    cpy_r_r243 = CPyStatics[8]; /* 'web3' */
    cpy_r_r244 = CPyDict_GetItem(cpy_r_r242, cpy_r_r243);
    if (unlikely(cpy_r_r244 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 59, CPyStatic_globals);
        goto CPyL123;
    }
    cpy_r_r245 = CPyStatics[18]; /* '_utils' */
    cpy_r_r246 = CPyObject_GetAttr(cpy_r_r244, cpy_r_r245);
    CPy_DECREF(cpy_r_r244);
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 59, CPyStatic_globals);
        goto CPyL123;
    }
    cpy_r_r247 = CPyStatics[26]; /* 'type_conversion' */
    cpy_r_r248 = CPyObject_GetAttr(cpy_r_r246, cpy_r_r247);
    CPy_DECREF(cpy_r_r246);
    if (unlikely(cpy_r_r248 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 59, CPyStatic_globals);
        goto CPyL123;
    }
    cpy_r_r249 = CPyStatics[9]; /* 'to_hex' */
    cpy_r_r250 = PyObject_SetAttr(cpy_r_r248, cpy_r_r249, cpy_r_r241);
    CPy_DECREF(cpy_r_r248);
    CPy_DECREF(cpy_r_r241);
    cpy_r_r251 = cpy_r_r250 >= 0;
    if (unlikely(!cpy_r_r251)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 59, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r252 = CPyStatic_globals;
    cpy_r_r253 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r254 = CPyDict_GetItem(cpy_r_r252, cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 60, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r255 = CPyStatic_globals;
    cpy_r_r256 = CPyStatics[8]; /* 'web3' */
    cpy_r_r257 = CPyDict_GetItem(cpy_r_r255, cpy_r_r256);
    if (unlikely(cpy_r_r257 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 60, CPyStatic_globals);
        goto CPyL124;
    }
    cpy_r_r258 = CPyStatics[18]; /* '_utils' */
    cpy_r_r259 = CPyObject_GetAttr(cpy_r_r257, cpy_r_r258);
    CPy_DECREF(cpy_r_r257);
    if (unlikely(cpy_r_r259 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 60, CPyStatic_globals);
        goto CPyL124;
    }
    cpy_r_r260 = CPyStatics[26]; /* 'type_conversion' */
    cpy_r_r261 = CPyObject_GetAttr(cpy_r_r259, cpy_r_r260);
    CPy_DECREF(cpy_r_r259);
    if (unlikely(cpy_r_r261 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 60, CPyStatic_globals);
        goto CPyL124;
    }
    cpy_r_r262 = CPyStatics[5]; /* 'to_bytes' */
    cpy_r_r263 = PyObject_SetAttr(cpy_r_r261, cpy_r_r262, cpy_r_r254);
    CPy_DECREF(cpy_r_r261);
    CPy_DECREF(cpy_r_r254);
    cpy_r_r264 = cpy_r_r263 >= 0;
    if (unlikely(!cpy_r_r264)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 60, CPyStatic_globals);
        goto CPyL110;
    }
CPyL109: ;
    return 1;
CPyL110: ;
    cpy_r_r265 = 2;
    return cpy_r_r265;
CPyL111: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL110;
CPyL112: ;
    CPy_DecRef(cpy_r_r37);
    goto CPyL110;
CPyL113: ;
    CPy_DecRef(cpy_r_r48);
    goto CPyL110;
CPyL114: ;
    CPy_DecRef(cpy_r_r71);
    goto CPyL110;
CPyL115: ;
    CPy_DecRef(cpy_r_r96);
    goto CPyL110;
CPyL116: ;
    CPy_DecRef(cpy_r_r121);
    goto CPyL110;
CPyL117: ;
    CPy_DecRef(cpy_r_r134);
    goto CPyL110;
CPyL118: ;
    CPy_DecRef(cpy_r_r159);
    goto CPyL110;
CPyL119: ;
    CPy_DecRef(cpy_r_r172);
    goto CPyL110;
CPyL120: ;
    CPy_DecRef(cpy_r_r197);
    goto CPyL110;
CPyL121: ;
    CPy_DecRef(cpy_r_r210);
    goto CPyL110;
CPyL122: ;
    CPy_DecRef(cpy_r_r233.f0);
    CPy_DecRef(cpy_r_r233.f1);
    CPy_DecRef(cpy_r_r233.f2);
    goto CPyL95;
CPyL123: ;
    CPy_DecRef(cpy_r_r241);
    goto CPyL110;
CPyL124: ;
    CPy_DecRef(cpy_r_r254);
    goto CPyL110;
}

PyObject *CPyPy_patch_eth_utils(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":patch_eth_utils", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    char retval = CPyDef_patch_eth_utils();
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/_eth_utils.py", "patch_eth_utils", 14, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_to_hex(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    int32_t cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    tuple_T2OO cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    int32_t cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    int32_t cpy_r_r45;
    char cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    int32_t cpy_r_r56;
    char cpy_r_r57;
    char cpy_r_r58;
    CPyTagged cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject **cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject **cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject **cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    if (cpy_r_primitive != NULL) goto CPyL57;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_primitive = cpy_r_r0;
CPyL2: ;
    if (cpy_r_hexstr != NULL) goto CPyL58;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_hexstr = cpy_r_r1;
CPyL4: ;
    if (cpy_r_text != NULL) goto CPyL59;
    cpy_r_r2 = Py_None;
    CPy_INCREF(cpy_r_r2);
    cpy_r_text = cpy_r_r2;
CPyL6: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_hexstr != cpy_r_r3;
    if (cpy_r_r4) {
        goto CPyL60;
    } else
        goto CPyL61;
CPyL7: ;
    cpy_r_r5 = cpy_r_hexstr;
    cpy_r_r6 = CPyStatics[27]; /* 'lower' */
    cpy_r_r7 = CPyObject_CallMethodObjArgs(cpy_r_r5, cpy_r_r6, NULL);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 74, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r8 = CPyDef_add_0x_prefix(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 74, CPyStatic_globals);
        goto CPyL56;
    }
    return cpy_r_r8;
CPyL11: ;
    cpy_r_r9 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r10 = cpy_r_text != cpy_r_r9;
    if (cpy_r_r10) {
        goto CPyL62;
    } else
        goto CPyL63;
CPyL12: ;
    if (likely(cpy_r_text != Py_None))
        cpy_r_r11 = cpy_r_text;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "to_hex", 77, CPyStatic_globals, "str", cpy_r_text);
        goto CPyL56;
    }
    cpy_r_r12 = PyUnicode_AsUTF8String(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 77, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r13 = CPyDef_encode_hex(cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 77, CPyStatic_globals);
        goto CPyL56;
    }
    return cpy_r_r13;
CPyL16: ;
    cpy_r_r14 = (PyObject *)&PyBool_Type;
    cpy_r_r15 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r14);
    cpy_r_r16 = cpy_r_r15 >= 0;
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 79, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r17 = cpy_r_r15;
    if (!cpy_r_r17) goto CPyL23;
    if (unlikely(!PyBool_Check(cpy_r_primitive))) {
        CPy_TypeError("bool", cpy_r_primitive); cpy_r_r18 = 2;
    } else
        cpy_r_r18 = cpy_r_primitive == Py_True;
    CPy_DECREF(cpy_r_primitive);
    if (unlikely(cpy_r_r18 == 2)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 80, CPyStatic_globals);
        goto CPyL56;
    }
    if (!cpy_r_r18) goto CPyL21;
    cpy_r_r19 = CPyStatics[28]; /* '0x1' */
    CPy_INCREF(cpy_r_r19);
    cpy_r_r20 = cpy_r_r19;
    goto CPyL22;
CPyL21: ;
    cpy_r_r21 = CPyStatics[29]; /* '0x0' */
    CPy_INCREF(cpy_r_r21);
    cpy_r_r20 = cpy_r_r21;
CPyL22: ;
    return cpy_r_r20;
CPyL23: ;
    cpy_r_r22 = (PyObject *)&PyBytes_Type;
    cpy_r_r23 = CPyModule_builtins;
    cpy_r_r24 = CPyStatics[30]; /* 'bytearray' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 82, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_INCREF(cpy_r_r22);
    cpy_r_r26.f0 = cpy_r_r22;
    cpy_r_r26.f1 = cpy_r_r25;
    cpy_r_r27 = PyTuple_New(2);
    if (unlikely(cpy_r_r27 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = cpy_r_r26.f0;
    PyTuple_SET_ITEM(cpy_r_r27, 0, __tmp1);
    PyObject *__tmp2 = cpy_r_r26.f1;
    PyTuple_SET_ITEM(cpy_r_r27, 1, __tmp2);
    cpy_r_r28 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 82, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r30 = cpy_r_r28;
    if (!cpy_r_r30) goto CPyL28;
    cpy_r_r31 = CPyDef_encode_hex(cpy_r_primitive);
    CPy_DECREF(cpy_r_primitive);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 83, CPyStatic_globals);
        goto CPyL56;
    }
    return cpy_r_r31;
CPyL28: ;
    cpy_r_r32 = CPyModule_builtins;
    cpy_r_r33 = CPyStatics[31]; /* 'memoryview' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 85, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r35 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r36 = cpy_r_r35 >= 0;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 85, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r37 = cpy_r_r35;
    if (!cpy_r_r37) goto CPyL35;
    cpy_r_r38 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r39[1] = {cpy_r_primitive};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = _PyObject_Vectorcall(cpy_r_r38, cpy_r_r40, 1, 0);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 86, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_DECREF(cpy_r_primitive);
    if (likely(PyBytes_Check(cpy_r_r41) || PyByteArray_Check(cpy_r_r41)))
        cpy_r_r42 = cpy_r_r41;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "to_hex", 86, CPyStatic_globals, "bytes", cpy_r_r41);
        goto CPyL56;
    }
    cpy_r_r43 = CPyDef_encode_hex(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 86, CPyStatic_globals);
        goto CPyL56;
    }
    return cpy_r_r43;
CPyL35: ;
    cpy_r_r44 = (PyObject *)&PyUnicode_Type;
    cpy_r_r45 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r44);
    cpy_r_r46 = cpy_r_r45 >= 0;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 88, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r47 = cpy_r_r45;
    if (cpy_r_r47) {
        goto CPyL65;
    } else
        goto CPyL41;
CPyL37: ;
    cpy_r_r48 = CPyStatics[32]; /* ('Unsupported type: The primitive argument must be one '
                                   'of: bytes,bytearray, int or bool and not str') */
    cpy_r_r49 = CPyModule_builtins;
    cpy_r_r50 = CPyStatics[33]; /* 'TypeError' */
    cpy_r_r51 = CPyObject_GetAttr(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 89, CPyStatic_globals);
        goto CPyL56;
    }
    PyObject *cpy_r_r52[1] = {cpy_r_r48};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = _PyObject_Vectorcall(cpy_r_r51, cpy_r_r53, 1, 0);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 89, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Raise(cpy_r_r54);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 89, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL41: ;
    cpy_r_r55 = (PyObject *)&PyLong_Type;
    cpy_r_r56 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r55);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 94, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r58 = cpy_r_r56;
    if (!cpy_r_r58) goto CPyL48;
    if (likely(PyLong_Check(cpy_r_primitive)))
        cpy_r_r59 = CPyTagged_FromObject(cpy_r_primitive);
    else {
        CPy_TypeError("int", cpy_r_primitive); cpy_r_r59 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_primitive);
    if (unlikely(cpy_r_r59 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 95, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r60 = CPyModule_builtins;
    cpy_r_r61 = CPyStatics[34]; /* 'hex' */
    cpy_r_r62 = CPyObject_GetAttr(cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 95, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r63 = CPyTagged_StealAsObject(cpy_r_r59);
    PyObject *cpy_r_r64[1] = {cpy_r_r63};
    cpy_r_r65 = (PyObject **)&cpy_r_r64;
    cpy_r_r66 = _PyObject_Vectorcall(cpy_r_r62, cpy_r_r65, 1, 0);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 95, CPyStatic_globals);
        goto CPyL67;
    }
    CPy_DECREF(cpy_r_r63);
    if (likely(PyUnicode_Check(cpy_r_r66)))
        cpy_r_r67 = cpy_r_r66;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "to_hex", 95, CPyStatic_globals, "str", cpy_r_r66);
        goto CPyL56;
    }
    return cpy_r_r67;
CPyL48: ;
    cpy_r_r68 = CPyStatics[35]; /* "Unsupported type: '" */
    cpy_r_r69 = PyObject_Type(cpy_r_primitive);
    CPy_DECREF(cpy_r_primitive);
    cpy_r_r70 = CPyModule_builtins;
    cpy_r_r71 = CPyStatics[36]; /* 'repr' */
    cpy_r_r72 = CPyObject_GetAttr(cpy_r_r70, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 98, CPyStatic_globals);
        goto CPyL68;
    }
    PyObject *cpy_r_r73[1] = {cpy_r_r69};
    cpy_r_r74 = (PyObject **)&cpy_r_r73;
    cpy_r_r75 = _PyObject_Vectorcall(cpy_r_r72, cpy_r_r74, 1, 0);
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 98, CPyStatic_globals);
        goto CPyL68;
    }
    CPy_DECREF(cpy_r_r69);
    if (likely(PyUnicode_Check(cpy_r_r75)))
        cpy_r_r76 = cpy_r_r75;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "to_hex", 98, CPyStatic_globals, "str", cpy_r_r75);
        goto CPyL56;
    }
    cpy_r_r77 = CPyStatics[37]; /* "'. Must be one of: bool, str, bytes, bytearray or int." */
    cpy_r_r78 = CPyStr_Build(3, cpy_r_r68, cpy_r_r76, cpy_r_r77);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 98, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r79 = CPyModule_builtins;
    cpy_r_r80 = CPyStatics[33]; /* 'TypeError' */
    cpy_r_r81 = CPyObject_GetAttr(cpy_r_r79, cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 97, CPyStatic_globals);
        goto CPyL69;
    }
    PyObject *cpy_r_r82[1] = {cpy_r_r78};
    cpy_r_r83 = (PyObject **)&cpy_r_r82;
    cpy_r_r84 = _PyObject_Vectorcall(cpy_r_r81, cpy_r_r83, 1, 0);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 97, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_DECREF(cpy_r_r78);
    CPy_Raise(cpy_r_r84);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 97, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL56: ;
    cpy_r_r85 = NULL;
    return cpy_r_r85;
CPyL57: ;
    CPy_INCREF(cpy_r_primitive);
    goto CPyL2;
CPyL58: ;
    CPy_INCREF(cpy_r_hexstr);
    goto CPyL4;
CPyL59: ;
    CPy_INCREF(cpy_r_text);
    goto CPyL6;
CPyL60: ;
    CPy_DECREF(cpy_r_primitive);
    CPy_DECREF(cpy_r_text);
    goto CPyL7;
CPyL61: ;
    CPy_DECREF(cpy_r_hexstr);
    goto CPyL11;
CPyL62: ;
    CPy_DECREF(cpy_r_primitive);
    goto CPyL12;
CPyL63: ;
    CPy_DECREF(cpy_r_text);
    goto CPyL16;
CPyL64: ;
    CPy_DecRef(cpy_r_primitive);
    goto CPyL56;
CPyL65: ;
    CPy_DECREF(cpy_r_primitive);
    goto CPyL37;
CPyL66: ;
    CPyTagged_DecRef(cpy_r_r59);
    goto CPyL56;
CPyL67: ;
    CPy_DecRef(cpy_r_r63);
    goto CPyL56;
CPyL68: ;
    CPy_DecRef(cpy_r_r69);
    goto CPyL56;
CPyL69: ;
    CPy_DecRef(cpy_r_r78);
    goto CPyL56;
}

PyObject *CPyPy_to_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"primitive", "hexstr", "text", 0};
    static CPyArg_Parser parser = {"|OOO:to_hex", kwlist, 0};
    PyObject *obj_primitive = NULL;
    PyObject *obj_hexstr = NULL;
    PyObject *obj_text = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_primitive, &obj_hexstr, &obj_text)) {
        return NULL;
    }
    PyObject *arg_primitive;
    if (obj_primitive == NULL) {
        arg_primitive = NULL;
        goto __LL3;
    }
    arg_primitive = obj_primitive;
    if (arg_primitive != NULL) goto __LL3;
    if (obj_primitive == Py_None)
        arg_primitive = obj_primitive;
    else {
        arg_primitive = NULL;
    }
    if (arg_primitive != NULL) goto __LL3;
    CPy_TypeError("object or None", obj_primitive); 
    goto fail;
__LL3: ;
    PyObject *arg_hexstr;
    if (obj_hexstr == NULL) {
        arg_hexstr = NULL;
        goto __LL4;
    }
    arg_hexstr = obj_hexstr;
    if (arg_hexstr != NULL) goto __LL4;
    if (obj_hexstr == Py_None)
        arg_hexstr = obj_hexstr;
    else {
        arg_hexstr = NULL;
    }
    if (arg_hexstr != NULL) goto __LL4;
    CPy_TypeError("object or None", obj_hexstr); 
    goto fail;
__LL4: ;
    PyObject *arg_text;
    if (obj_text == NULL) {
        arg_text = NULL;
        goto __LL5;
    }
    if (PyUnicode_Check(obj_text))
        arg_text = obj_text;
    else {
        arg_text = NULL;
    }
    if (arg_text != NULL) goto __LL5;
    if (obj_text == Py_None)
        arg_text = obj_text;
    else {
        arg_text = NULL;
    }
    if (arg_text != NULL) goto __LL5;
    CPy_TypeError("str or None", obj_text); 
    goto fail;
__LL5: ;
    PyObject *retval = CPyDef_to_hex(arg_primitive, arg_hexstr, arg_text);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/_eth_utils.py", "to_hex", 63, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_to_bytes(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    int32_t cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    tuple_T2OO cpy_r_r17;
    PyObject *cpy_r_r18;
    int32_t cpy_r_r19;
    char cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    char cpy_r_r35;
    CPyTagged cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    CPyTagged cpy_r_r46;
    CPyTagged cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    char cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject **cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    if (cpy_r_primitive != NULL) goto CPyL51;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_primitive = cpy_r_r0;
CPyL2: ;
    if (cpy_r_hexstr != NULL) goto CPyL52;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_hexstr = cpy_r_r1;
CPyL4: ;
    if (cpy_r_text != NULL) goto CPyL53;
    cpy_r_r2 = Py_None;
    CPy_INCREF(cpy_r_r2);
    cpy_r_text = cpy_r_r2;
CPyL6: ;
    cpy_r_r3 = (PyObject *)&PyBool_Type;
    cpy_r_r4 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 >= 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 108, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r6 = cpy_r_r4;
    if (cpy_r_r6) {
        goto CPyL55;
    } else
        goto CPyL13;
CPyL8: ;
    if (unlikely(!PyBool_Check(cpy_r_primitive))) {
        CPy_TypeError("bool", cpy_r_primitive); cpy_r_r7 = 2;
    } else
        cpy_r_r7 = cpy_r_primitive == Py_True;
    CPy_DECREF(cpy_r_primitive);
    if (unlikely(cpy_r_r7 == 2)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 109, CPyStatic_globals);
        goto CPyL50;
    }
    if (!cpy_r_r7) goto CPyL11;
    cpy_r_r8 = CPyStatics[60]; /* b'\x01' */
    CPy_INCREF(cpy_r_r8);
    cpy_r_r9 = cpy_r_r8;
    goto CPyL12;
CPyL11: ;
    cpy_r_r10 = CPyStatics[61]; /* b'\x00' */
    CPy_INCREF(cpy_r_r10);
    cpy_r_r9 = cpy_r_r10;
CPyL12: ;
    return cpy_r_r9;
CPyL13: ;
    cpy_r_r11 = CPyModule_builtins;
    cpy_r_r12 = CPyStatics[30]; /* 'bytearray' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 110, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r14 = CPyModule_builtins;
    cpy_r_r15 = CPyStatics[31]; /* 'memoryview' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 110, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r17.f0 = cpy_r_r13;
    cpy_r_r17.f1 = cpy_r_r16;
    cpy_r_r18 = PyTuple_New(2);
    if (unlikely(cpy_r_r18 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp6 = cpy_r_r17.f0;
    PyTuple_SET_ITEM(cpy_r_r18, 0, __tmp6);
    PyObject *__tmp7 = cpy_r_r17.f1;
    PyTuple_SET_ITEM(cpy_r_r18, 1, __tmp7);
    cpy_r_r19 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r20 = cpy_r_r19 >= 0;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 110, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r21 = cpy_r_r19;
    if (cpy_r_r21) {
        goto CPyL57;
    } else
        goto CPyL20;
CPyL17: ;
    cpy_r_r22 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r23[1] = {cpy_r_primitive};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = _PyObject_Vectorcall(cpy_r_r22, cpy_r_r24, 1, 0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 111, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_DECREF(cpy_r_primitive);
    if (likely(PyBytes_Check(cpy_r_r25) || PyByteArray_Check(cpy_r_r25)))
        cpy_r_r26 = cpy_r_r25;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "to_bytes", 111, CPyStatic_globals, "bytes", cpy_r_r25);
        goto CPyL50;
    }
    return cpy_r_r26;
CPyL20: ;
    cpy_r_r27 = (PyObject *)&PyBytes_Type;
    cpy_r_r28 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r27);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 112, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r30 = cpy_r_r28;
    if (cpy_r_r30) {
        goto CPyL59;
    } else
        goto CPyL24;
CPyL22: ;
    if (likely(PyBytes_Check(cpy_r_primitive) || PyByteArray_Check(cpy_r_primitive)))
        cpy_r_r31 = cpy_r_primitive;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "to_bytes", 113, CPyStatic_globals, "bytes", cpy_r_primitive);
        goto CPyL50;
    }
    return cpy_r_r31;
CPyL24: ;
    cpy_r_r32 = (PyObject *)&PyLong_Type;
    cpy_r_r33 = PyObject_IsInstance(cpy_r_primitive, cpy_r_r32);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 114, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r35 = cpy_r_r33;
    if (cpy_r_r35) {
        goto CPyL60;
    } else
        goto CPyL61;
CPyL26: ;
    if (likely(PyLong_Check(cpy_r_primitive)))
        cpy_r_r36 = CPyTagged_FromObject(cpy_r_primitive);
    else {
        CPy_TypeError("int", cpy_r_primitive); cpy_r_r36 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_primitive);
    if (unlikely(cpy_r_r36 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 115, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r37 = CPyTagged_StealAsObject(cpy_r_r36);
    cpy_r_r38 = NULL;
    cpy_r_r39 = NULL;
    cpy_r_r40 = CPyDef_to_hex(cpy_r_r37, cpy_r_r38, cpy_r_r39);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 115, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r41 = NULL;
    cpy_r_r42 = NULL;
    cpy_r_r43 = CPyDef_to_bytes(cpy_r_r41, cpy_r_r40, cpy_r_r42);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 115, CPyStatic_globals);
        goto CPyL50;
    }
    return cpy_r_r43;
CPyL30: ;
    cpy_r_r44 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r45 = cpy_r_hexstr != cpy_r_r44;
    if (cpy_r_r45) {
        goto CPyL62;
    } else
        goto CPyL63;
CPyL31: ;
    cpy_r_r46 = CPyObject_Size(cpy_r_hexstr);
    if (unlikely(cpy_r_r46 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 117, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r47 = CPyTagged_Remainder(cpy_r_r46, 4);
    CPyTagged_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r47 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 117, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r48 = cpy_r_r47 != 0;
    CPyTagged_DECREF(cpy_r_r47);
    if (!cpy_r_r48) goto CPyL38;
    cpy_r_r49 = CPyStatics[29]; /* '0x0' */
    cpy_r_r50 = CPyDef_remove_0x_prefix(cpy_r_hexstr);
    CPy_DECREF(cpy_r_hexstr);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 117, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r51 = PyObject_Str(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 117, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r52 = CPyStr_Build(2, cpy_r_r49, cpy_r_r51);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 117, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r53 = cpy_r_r52;
    goto CPyL39;
CPyL38: ;
    cpy_r_r53 = cpy_r_hexstr;
CPyL39: ;
    if (likely(PyUnicode_Check(cpy_r_r53)))
        cpy_r_r54 = cpy_r_r53;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "to_bytes", 117, CPyStatic_globals, "str", cpy_r_r53);
        goto CPyL50;
    }
    cpy_r_r55 = CPyDef_decode_hex(cpy_r_r54);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 117, CPyStatic_globals);
        goto CPyL50;
    }
    return cpy_r_r55;
CPyL42: ;
    cpy_r_r56 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r57 = cpy_r_text != cpy_r_r56;
    if (!cpy_r_r57) goto CPyL65;
    if (likely(cpy_r_text != Py_None))
        cpy_r_r58 = cpy_r_text;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "to_bytes", 119, CPyStatic_globals, "str", cpy_r_text);
        goto CPyL50;
    }
    cpy_r_r59 = PyUnicode_AsUTF8String(cpy_r_r58);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 119, CPyStatic_globals);
        goto CPyL50;
    }
    return cpy_r_r59;
CPyL46: ;
    cpy_r_r60 = CPyStatics[38]; /* ('expected a bool, int, byte or bytearray in first arg, '
                                   'or keyword of hexstr or text') */
    cpy_r_r61 = CPyModule_builtins;
    cpy_r_r62 = CPyStatics[33]; /* 'TypeError' */
    cpy_r_r63 = CPyObject_GetAttr(cpy_r_r61, cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 120, CPyStatic_globals);
        goto CPyL50;
    }
    PyObject *cpy_r_r64[1] = {cpy_r_r60};
    cpy_r_r65 = (PyObject **)&cpy_r_r64;
    cpy_r_r66 = _PyObject_Vectorcall(cpy_r_r63, cpy_r_r65, 1, 0);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 120, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Raise(cpy_r_r66);
    CPy_DECREF(cpy_r_r66);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 120, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL50: ;
    cpy_r_r67 = NULL;
    return cpy_r_r67;
CPyL51: ;
    CPy_INCREF(cpy_r_primitive);
    goto CPyL2;
CPyL52: ;
    CPy_INCREF(cpy_r_hexstr);
    goto CPyL4;
CPyL53: ;
    CPy_INCREF(cpy_r_text);
    goto CPyL6;
CPyL54: ;
    CPy_DecRef(cpy_r_primitive);
    CPy_DecRef(cpy_r_hexstr);
    CPy_DecRef(cpy_r_text);
    goto CPyL50;
CPyL55: ;
    CPy_DECREF(cpy_r_hexstr);
    CPy_DECREF(cpy_r_text);
    goto CPyL8;
CPyL56: ;
    CPy_DecRef(cpy_r_primitive);
    CPy_DecRef(cpy_r_hexstr);
    CPy_DecRef(cpy_r_text);
    CPy_DecRef(cpy_r_r13);
    goto CPyL50;
CPyL57: ;
    CPy_DECREF(cpy_r_hexstr);
    CPy_DECREF(cpy_r_text);
    goto CPyL17;
CPyL58: ;
    CPy_DecRef(cpy_r_primitive);
    goto CPyL50;
CPyL59: ;
    CPy_DECREF(cpy_r_hexstr);
    CPy_DECREF(cpy_r_text);
    goto CPyL22;
CPyL60: ;
    CPy_DECREF(cpy_r_hexstr);
    CPy_DECREF(cpy_r_text);
    goto CPyL26;
CPyL61: ;
    CPy_DECREF(cpy_r_primitive);
    goto CPyL30;
CPyL62: ;
    CPy_DECREF(cpy_r_text);
    goto CPyL31;
CPyL63: ;
    CPy_DECREF(cpy_r_hexstr);
    goto CPyL42;
CPyL64: ;
    CPy_DecRef(cpy_r_hexstr);
    goto CPyL50;
CPyL65: ;
    CPy_DECREF(cpy_r_text);
    goto CPyL46;
}

PyObject *CPyPy_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"primitive", "hexstr", "text", 0};
    static CPyArg_Parser parser = {"|OOO:to_bytes", kwlist, 0};
    PyObject *obj_primitive = NULL;
    PyObject *obj_hexstr = NULL;
    PyObject *obj_text = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_primitive, &obj_hexstr, &obj_text)) {
        return NULL;
    }
    PyObject *arg_primitive;
    if (obj_primitive == NULL) {
        arg_primitive = NULL;
        goto __LL8;
    }
    arg_primitive = obj_primitive;
    if (arg_primitive != NULL) goto __LL8;
    if (obj_primitive == Py_None)
        arg_primitive = obj_primitive;
    else {
        arg_primitive = NULL;
    }
    if (arg_primitive != NULL) goto __LL8;
    CPy_TypeError("object or None", obj_primitive); 
    goto fail;
__LL8: ;
    PyObject *arg_hexstr;
    if (obj_hexstr == NULL) {
        arg_hexstr = NULL;
        goto __LL9;
    }
    arg_hexstr = obj_hexstr;
    if (arg_hexstr != NULL) goto __LL9;
    if (obj_hexstr == Py_None)
        arg_hexstr = obj_hexstr;
    else {
        arg_hexstr = NULL;
    }
    if (arg_hexstr != NULL) goto __LL9;
    CPy_TypeError("object or None", obj_hexstr); 
    goto fail;
__LL9: ;
    PyObject *arg_text;
    if (obj_text == NULL) {
        arg_text = NULL;
        goto __LL10;
    }
    if (PyUnicode_Check(obj_text))
        arg_text = obj_text;
    else {
        arg_text = NULL;
    }
    if (arg_text != NULL) goto __LL10;
    if (obj_text == Py_None)
        arg_text = obj_text;
    else {
        arg_text = NULL;
    }
    if (arg_text != NULL) goto __LL10;
    CPy_TypeError("str or None", obj_text); 
    goto fail;
__LL10: ;
    PyObject *retval = CPyDef_to_bytes(arg_primitive, arg_hexstr, arg_text);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/_eth_utils.py", "to_bytes", 103, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_hex(PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    cpy_r_r0 = (PyObject *)&PyUnicode_Type;
    cpy_r_r1 = PyObject_IsInstance(cpy_r_value, cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 126, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r3 = cpy_r_r1;
    if (cpy_r_r3) goto CPyL6;
    cpy_r_r4 = CPyStatics[39]; /* 'Value must be an instance of str' */
    cpy_r_r5 = CPyModule_builtins;
    cpy_r_r6 = CPyStatics[33]; /* 'TypeError' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 127, CPyStatic_globals);
        goto CPyL12;
    }
    PyObject *cpy_r_r8[1] = {cpy_r_r4};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r7, cpy_r_r9, 1, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 127, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_Raise(cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 127, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_Unreachable();
CPyL6: ;
    cpy_r_r11 = CPyDef_remove_0x_prefix(cpy_r_value);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 128, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r12 = CPyStatics[40]; /* 'ascii' */
    cpy_r_r13 = CPyStatics[41]; /* 'encode' */
    cpy_r_r14 = CPyObject_CallMethodObjArgs(cpy_r_r11, cpy_r_r13, cpy_r_r12, NULL);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 130, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[42]; /* 'unhexlify' */
    cpy_r_r17 = CPyDict_GetItem(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 131, CPyStatic_globals);
        goto CPyL13;
    }
    PyObject *cpy_r_r18[1] = {cpy_r_r14};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = _PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 1, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 131, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_DECREF(cpy_r_r14);
    if (likely(PyBytes_Check(cpy_r_r20) || PyByteArray_Check(cpy_r_r20)))
        cpy_r_r21 = cpy_r_r20;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "decode_hex", 131, CPyStatic_globals, "bytes", cpy_r_r20);
        goto CPyL12;
    }
    return cpy_r_r21;
CPyL12: ;
    cpy_r_r22 = NULL;
    return cpy_r_r22;
CPyL13: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL12;
}

PyObject *CPyPy_decode_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:decode_hex", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    PyObject *arg_value;
    if (likely(PyUnicode_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("str", obj_value); 
        goto fail;
    }
    PyObject *retval = CPyDef_decode_hex(arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/_eth_utils.py", "decode_hex", 125, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_hex(PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    tuple_T2OO cpy_r_r4;
    PyObject *cpy_r_r5;
    int32_t cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_ascii_bytes;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    cpy_r_r0 = (PyObject *)&PyBytes_Type;
    cpy_r_r1 = CPyModule_builtins;
    cpy_r_r2 = CPyStatics[30]; /* 'bytearray' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 135, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_INCREF(cpy_r_r0);
    cpy_r_r4.f0 = cpy_r_r0;
    cpy_r_r4.f1 = cpy_r_r3;
    cpy_r_r5 = PyTuple_New(2);
    if (unlikely(cpy_r_r5 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp11 = cpy_r_r4.f0;
    PyTuple_SET_ITEM(cpy_r_r5, 0, __tmp11);
    PyObject *__tmp12 = cpy_r_r4.f1;
    PyTuple_SET_ITEM(cpy_r_r5, 1, __tmp12);
    cpy_r_r6 = PyObject_IsInstance(cpy_r_value, cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    cpy_r_r7 = cpy_r_r6 >= 0;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 135, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r8 = cpy_r_r6;
    if (!cpy_r_r8) goto CPyL4;
    CPy_INCREF(cpy_r_value);
    cpy_r_ascii_bytes = cpy_r_value;
    goto CPyL13;
CPyL4: ;
    cpy_r_r9 = (PyObject *)&PyUnicode_Type;
    cpy_r_r10 = PyObject_IsInstance(cpy_r_value, cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 137, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r12 = cpy_r_r10;
    if (!cpy_r_r12) goto CPyL9;
    CPy_INCREF(cpy_r_value);
    if (likely(PyUnicode_Check(cpy_r_value)))
        cpy_r_r13 = cpy_r_value;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "encode_hex", 138, CPyStatic_globals, "str", cpy_r_value);
        goto CPyL19;
    }
    cpy_r_r14 = PyUnicode_AsASCIIString(cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 138, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_ascii_bytes = cpy_r_r14;
    goto CPyL13;
CPyL9: ;
    cpy_r_r15 = CPyStatics[43]; /* 'Value must be an instance of str or unicode' */
    cpy_r_r16 = CPyModule_builtins;
    cpy_r_r17 = CPyStatics[33]; /* 'TypeError' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 140, CPyStatic_globals);
        goto CPyL19;
    }
    PyObject *cpy_r_r19[1] = {cpy_r_r15};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = _PyObject_Vectorcall(cpy_r_r18, cpy_r_r20, 1, 0);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 140, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_Raise(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 140, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_Unreachable();
CPyL13: ;
    cpy_r_r22 = CPyStatic_globals;
    cpy_r_r23 = CPyStatics[44]; /* 'hexlify' */
    cpy_r_r24 = CPyDict_GetItem(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 141, CPyStatic_globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r25[1] = {cpy_r_ascii_bytes};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = _PyObject_Vectorcall(cpy_r_r24, cpy_r_r26, 1, 0);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 141, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_DECREF(cpy_r_ascii_bytes);
    if (likely(PyBytes_Check(cpy_r_r27) || PyByteArray_Check(cpy_r_r27)))
        cpy_r_r28 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "encode_hex", 141, CPyStatic_globals, "bytes", cpy_r_r27);
        goto CPyL19;
    }
    cpy_r_r29 = CPyStatics[40]; /* 'ascii' */
    cpy_r_r30 = CPy_Decode(cpy_r_r28, cpy_r_r29, NULL);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 141, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r31 = CPyDef_add_0x_prefix(cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 141, CPyStatic_globals);
        goto CPyL19;
    }
    return cpy_r_r31;
CPyL19: ;
    cpy_r_r32 = NULL;
    return cpy_r_r32;
CPyL20: ;
    CPy_DecRef(cpy_r_ascii_bytes);
    goto CPyL19;
}

PyObject *CPyPy_encode_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:encode_hex", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    PyObject *arg_value = obj_value;
    PyObject *retval = CPyDef_encode_hex(arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/_eth_utils.py", "encode_hex", 134, CPyStatic_globals);
    return NULL;
}

char CPyDef_is_0x_prefixed(PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyPtr cpy_r_r17;
    CPyPtr cpy_r_r18;
    CPyPtr cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject **cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    tuple_T2OO cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    char cpy_r_r33;
    char cpy_r_r34;
    cpy_r_r0 = (PyObject *)&PyUnicode_Type;
    cpy_r_r1 = PyObject_IsInstance(cpy_r_value, cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 145, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r3 = cpy_r_r1;
    if (cpy_r_r3) goto CPyL11;
    cpy_r_r4 = CPyStatics[45]; /* '' */
    cpy_r_r5 = CPyStatics[46]; /* 'is_0x_prefixed requires text typed arguments. Got: ' */
    cpy_r_r6 = CPyStatics[47]; /* '{:{}}' */
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[36]; /* 'repr' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 146, CPyStatic_globals);
        goto CPyL14;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_value};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 146, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r13 = CPyStatics[45]; /* '' */
    cpy_r_r14 = CPyStatics[48]; /* 'format' */
    cpy_r_r15 = CPyObject_CallMethodObjArgs(cpy_r_r6, cpy_r_r14, cpy_r_r12, cpy_r_r13, NULL);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 146, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r16 = PyList_New(2);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 146, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r17 = (CPyPtr)&((PyListObject *)cpy_r_r16)->ob_item;
    cpy_r_r18 = *(CPyPtr *)cpy_r_r17;
    CPy_INCREF(cpy_r_r5);
    *(PyObject * *)cpy_r_r18 = cpy_r_r5;
    cpy_r_r19 = cpy_r_r18 + 8;
    *(PyObject * *)cpy_r_r19 = cpy_r_r15;
    cpy_r_r20 = PyUnicode_Join(cpy_r_r4, cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 146, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r21 = CPyModule_builtins;
    cpy_r_r22 = CPyStatics[33]; /* 'TypeError' */
    cpy_r_r23 = CPyObject_GetAttr(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 146, CPyStatic_globals);
        goto CPyL16;
    }
    PyObject *cpy_r_r24[1] = {cpy_r_r20};
    cpy_r_r25 = (PyObject **)&cpy_r_r24;
    cpy_r_r26 = _PyObject_Vectorcall(cpy_r_r23, cpy_r_r25, 1, 0);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 146, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_DECREF(cpy_r_r20);
    CPy_Raise(cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 146, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r27 = CPyStatics[49]; /* '0x' */
    cpy_r_r28 = CPyStatics[50]; /* '0X' */
    CPy_INCREF(cpy_r_r27);
    CPy_INCREF(cpy_r_r28);
    cpy_r_r29.f0 = cpy_r_r27;
    cpy_r_r29.f1 = cpy_r_r28;
    cpy_r_r30 = CPyStatics[51]; /* 'startswith' */
    cpy_r_r31 = PyTuple_New(2);
    if (unlikely(cpy_r_r31 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp13 = cpy_r_r29.f0;
    PyTuple_SET_ITEM(cpy_r_r31, 0, __tmp13);
    PyObject *__tmp14 = cpy_r_r29.f1;
    PyTuple_SET_ITEM(cpy_r_r31, 1, __tmp14);
    cpy_r_r32 = CPyObject_CallMethodObjArgs(cpy_r_value, cpy_r_r30, cpy_r_r31, NULL);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 147, CPyStatic_globals);
        goto CPyL14;
    }
    if (unlikely(!PyBool_Check(cpy_r_r32))) {
        CPy_TypeError("bool", cpy_r_r32); cpy_r_r33 = 2;
    } else
        cpy_r_r33 = cpy_r_r32 == Py_True;
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r33 == 2)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 147, CPyStatic_globals);
        goto CPyL14;
    }
    return cpy_r_r33;
CPyL14: ;
    cpy_r_r34 = 2;
    return cpy_r_r34;
CPyL15: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL14;
CPyL16: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL14;
}

PyObject *CPyPy_is_0x_prefixed(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:is_0x_prefixed", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    PyObject *arg_value;
    if (likely(PyUnicode_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("str", obj_value); 
        goto fail;
    }
    char retval = CPyDef_is_0x_prefixed(arg_value);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/_eth_utils.py", "is_0x_prefixed", 144, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_remove_0x_prefix(PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPy_INCREF(cpy_r_value);
    if (likely(PyUnicode_Check(cpy_r_value)))
        cpy_r_r0 = cpy_r_value;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "remove_0x_prefix", 152, CPyStatic_globals, "str", cpy_r_value);
        goto CPyL7;
    }
    cpy_r_r1 = CPyDef_is_0x_prefixed(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "remove_0x_prefix", 152, CPyStatic_globals);
        goto CPyL7;
    }
    if (!cpy_r_r1) goto CPyL6;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = CPyStatics[62]; /* 2 */
    cpy_r_r5 = PySlice_New(cpy_r_r4, cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "remove_0x_prefix", 153, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r6 = PyObject_GetItem(cpy_r_value, cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "remove_0x_prefix", 153, CPyStatic_globals);
        goto CPyL7;
    }
    return cpy_r_r6;
CPyL6: ;
    CPy_INCREF(cpy_r_value);
    return cpy_r_value;
CPyL7: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
}

PyObject *CPyPy_remove_0x_prefix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:remove_0x_prefix", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    PyObject *arg_value = obj_value;
    PyObject *retval = CPyDef_remove_0x_prefix(arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/_eth_utils.py", "remove_0x_prefix", 150, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_add_0x_prefix(PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    CPy_INCREF(cpy_r_value);
    if (likely(PyUnicode_Check(cpy_r_value)))
        cpy_r_r0 = cpy_r_value;
    else {
        CPy_TypeErrorTraceback("dank_mids/_eth_utils.py", "add_0x_prefix", 159, CPyStatic_globals, "str", cpy_r_value);
        goto CPyL7;
    }
    cpy_r_r1 = CPyDef_is_0x_prefixed(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "add_0x_prefix", 159, CPyStatic_globals);
        goto CPyL7;
    }
    if (!cpy_r_r1) goto CPyL4;
    CPy_INCREF(cpy_r_value);
    return cpy_r_value;
CPyL4: ;
    cpy_r_r2 = CPyStatics[49]; /* '0x' */
    cpy_r_r3 = PyObject_Str(cpy_r_value);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "add_0x_prefix", 161, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r4 = CPyStr_Build(2, cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "add_0x_prefix", 161, CPyStatic_globals);
        goto CPyL7;
    }
    return cpy_r_r4;
CPyL7: ;
    cpy_r_r5 = NULL;
    return cpy_r_r5;
}

PyObject *CPyPy_add_0x_prefix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:add_0x_prefix", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    PyObject *arg_value = obj_value;
    PyObject *retval = CPyDef_add_0x_prefix(arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/_eth_utils.py", "add_0x_prefix", 157, CPyStatic_globals);
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
    char cpy_r_r17;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[52]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "<module>", -1, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[63]; /* ('hexlify', 'unhexlify') */
    cpy_r_r6 = CPyStatics[53]; /* 'binascii' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "<module>", 8, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_binascii = cpy_r_r8;
    CPy_INCREF(CPyModule_binascii);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[64]; /* ('Any', 'AnyStr', 'Optional') */
    cpy_r_r10 = CPyStatics[57]; /* 'typing' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "<module>", 9, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[65]; /* ('HexStr',) */
    cpy_r_r14 = CPyStatics[59]; /* 'eth_typing' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/_eth_utils.py", "<module>", 11, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_eth_typing = cpy_r_r16;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r16);
    return 1;
CPyL7: ;
    cpy_r_r17 = 2;
    return cpy_r_r17;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids____eth_utils = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_binascii = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_eth_utils___crypto = Py_None;
    CPyModule_web3___main = Py_None;
    CPyModule_web3___middleware___filter = Py_None;
    CPyModule_web3___providers___base = Py_None;
    CPyModule_web3____utils___encoding = Py_None;
    CPyModule_web3____utils___events = Py_None;
    CPyModule_web3____utils___normalizers = Py_None;
    CPyModule_web3____utils___type_conversion = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[66];
const char * const CPyLit_Str[] = {
    "\b\020eth_utils.crypto\teth_utils\bto_bytes\006crypto\tweb3.main\004web3\006to_hex\004main",
    "\004\026web3.middleware.filter\nmiddleware\006filter\023web3.providers.base",
    "\005\tproviders\004base\024web3._utils.encoding\006_utils\bencoding",
    "\004\022web3._utils.events\006events\027web3._utils.normalizers\vnormalizers",
    "\004\033web3._utils.type_conversion\023ModuleNotFoundError\017type_conversion\005lower",
    "\004\0030x1\0030x0\tbytearray\nmemoryview",
    "\001aUnsupported type: The primitive argument must be one of: bytes,bytearray, int or bool and not str",
    "\004\tTypeError\003hex\023Unsupported type: \'\004repr",
    "\0016\'. Must be one of: bool, str, bytes, bytearray or int.",
    "\001Rexpected a bool, int, byte or bytearray in first arg, or keyword of hexstr or text",
    "\004 Value must be an instance of str\005ascii\006encode\tunhexlify",
    "\003+Value must be an instance of str or unicode\ahexlify\000",
    "\0043is_0x_prefixed requires text typed arguments. Got: \005{:{}}\006format\0020x",
    "\t\0020X\nstartswith\bbuiltins\bbinascii\003Any\006AnyStr\bOptional\006typing\006HexStr",
    "\001\neth_typing",
    "",
};
const char * const CPyLit_Bytes[] = {
    "\002\001\001\001\000",
    "",
};
const char * const CPyLit_Int[] = {
    "\0012",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {3, 2, 44, 42, 3, 54, 55, 56, 1, 58};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids____eth_utils_internal = NULL;
CPyModule *CPyModule_dank_mids____eth_utils;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_binascii;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_eth_utils___crypto;
CPyModule *CPyModule_web3___main;
CPyModule *CPyModule_web3___middleware___filter;
CPyModule *CPyModule_web3___providers___base;
CPyModule *CPyModule_web3____utils___encoding;
CPyModule *CPyModule_web3____utils___events;
CPyModule *CPyModule_web3____utils___normalizers;
CPyModule *CPyModule_web3____utils___type_conversion;
char CPyDef_patch_eth_utils(void);
PyObject *CPyPy_patch_eth_utils(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_to_hex(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text);
PyObject *CPyPy_to_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_to_bytes(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text);
PyObject *CPyPy_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_hex(PyObject *cpy_r_value);
PyObject *CPyPy_decode_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_hex(PyObject *cpy_r_value);
PyObject *CPyPy_encode_hex(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_is_0x_prefixed(PyObject *cpy_r_value);
PyObject *CPyPy_is_0x_prefixed(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_remove_0x_prefix(PyObject *cpy_r_value);
PyObject *CPyPy_remove_0x_prefix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_add_0x_prefix(PyObject *cpy_r_value);
PyObject *CPyPy_add_0x_prefix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids____eth_utils exports = {
    &CPyDef_patch_eth_utils,
    &CPyDef_to_hex,
    &CPyDef_to_bytes,
    &CPyDef_decode_hex,
    &CPyDef_encode_hex,
    &CPyDef_is_0x_prefixed,
    &CPyDef_remove_0x_prefix,
    &CPyDef_add_0x_prefix,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit__eth_utils__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids._eth_utils__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids._eth_utils__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids____eth_utils(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids____eth_utils, "dank_mids._eth_utils__mypyc.init_dank_mids____eth_utils", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids____eth_utils", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
