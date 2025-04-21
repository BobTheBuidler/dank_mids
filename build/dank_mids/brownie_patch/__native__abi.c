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
#include "__native__abi.h"
#include "__native_internal__abi.h"

static int
FunctionABI_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *FunctionABI_setup(PyTypeObject *type);
PyObject *CPyDef_FunctionABI(PyObject *cpy_r_abi);

static PyObject *
FunctionABI_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_FunctionABI) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = FunctionABI_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_FunctionABI_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
FunctionABI_traverse(dank_mids___brownie_patch____abi___FunctionABIObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_abi);
    Py_VISIT(self->_input_sig);
    Py_VISIT(self->_signature);
    return 0;
}

static int
FunctionABI_clear(dank_mids___brownie_patch____abi___FunctionABIObject *self)
{
    Py_CLEAR(self->_abi);
    Py_CLEAR(self->_input_sig);
    Py_CLEAR(self->_signature);
    return 0;
}

static void
FunctionABI_dealloc(dank_mids___brownie_patch____abi___FunctionABIObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, FunctionABI_dealloc)
    FunctionABI_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem FunctionABI_vtable[2];
static bool
CPyDef_FunctionABI_trait_vtable_setup(void)
{
    CPyVTableItem FunctionABI_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_FunctionABI_____init__,
        (CPyVTableItem)CPyDef_FunctionABI___singleton,
    };
    memcpy(FunctionABI_vtable, FunctionABI_vtable_scratch, sizeof(FunctionABI_vtable));
    return 1;
}

static PyObject *
FunctionABI_get_abi(dank_mids___brownie_patch____abi___FunctionABIObject *self, void *closure);
static int
FunctionABI_set_abi(dank_mids___brownie_patch____abi___FunctionABIObject *self, PyObject *value, void *closure);
static PyObject *
FunctionABI_get_input_sig(dank_mids___brownie_patch____abi___FunctionABIObject *self, void *closure);
static int
FunctionABI_set_input_sig(dank_mids___brownie_patch____abi___FunctionABIObject *self, PyObject *value, void *closure);
static PyObject *
FunctionABI_get_signature(dank_mids___brownie_patch____abi___FunctionABIObject *self, void *closure);
static int
FunctionABI_set_signature(dank_mids___brownie_patch____abi___FunctionABIObject *self, PyObject *value, void *closure);

static PyGetSetDef FunctionABI_getseters[] = {
    {"abi",
     (getter)FunctionABI_get_abi, (setter)FunctionABI_set_abi,
     NULL, NULL},
    {"input_sig",
     (getter)FunctionABI_get_input_sig, (setter)FunctionABI_set_input_sig,
     NULL, NULL},
    {"signature",
     (getter)FunctionABI_get_signature, (setter)FunctionABI_set_signature,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef FunctionABI_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_FunctionABI_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"singleton",
     (PyCFunction)CPyPy_FunctionABI___singleton,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_FunctionABI_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "FunctionABI",
    .tp_new = FunctionABI_new,
    .tp_dealloc = (destructor)FunctionABI_dealloc,
    .tp_traverse = (traverseproc)FunctionABI_traverse,
    .tp_clear = (inquiry)FunctionABI_clear,
    .tp_getset = FunctionABI_getseters,
    .tp_methods = FunctionABI_methods,
    .tp_init = FunctionABI_init,
    .tp_basicsize = sizeof(dank_mids___brownie_patch____abi___FunctionABIObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_FunctionABI_template = &CPyType_FunctionABI_template_;

static PyObject *
FunctionABI_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch____abi___FunctionABIObject *self;
    self = (dank_mids___brownie_patch____abi___FunctionABIObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = FunctionABI_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_FunctionABI(PyObject *cpy_r_abi)
{
    PyObject *self = FunctionABI_setup(CPyType_FunctionABI);
    if (self == NULL)
        return NULL;
    char res = CPyDef_FunctionABI_____init__(self, cpy_r_abi);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
FunctionABI_get_abi(dank_mids___brownie_patch____abi___FunctionABIObject *self, void *closure)
{
    if (unlikely(self->_abi == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'abi' of 'FunctionABI' undefined");
        return NULL;
    }
    CPy_INCREF(self->_abi);
    PyObject *retval = self->_abi;
    return retval;
}

static int
FunctionABI_set_abi(dank_mids___brownie_patch____abi___FunctionABIObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'FunctionABI' object attribute 'abi' cannot be deleted");
        return -1;
    }
    if (self->_abi != NULL) {
        CPy_DECREF(self->_abi);
    }
    PyObject *tmp;
    if (likely(PyDict_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("dict", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_abi = tmp;
    return 0;
}

static PyObject *
FunctionABI_get_input_sig(dank_mids___brownie_patch____abi___FunctionABIObject *self, void *closure)
{
    if (unlikely(self->_input_sig == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'input_sig' of 'FunctionABI' undefined");
        return NULL;
    }
    CPy_INCREF(self->_input_sig);
    PyObject *retval = self->_input_sig;
    return retval;
}

static int
FunctionABI_set_input_sig(dank_mids___brownie_patch____abi___FunctionABIObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'FunctionABI' object attribute 'input_sig' cannot be deleted");
        return -1;
    }
    if (self->_input_sig != NULL) {
        CPy_DECREF(self->_input_sig);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_input_sig = tmp;
    return 0;
}

static PyObject *
FunctionABI_get_signature(dank_mids___brownie_patch____abi___FunctionABIObject *self, void *closure)
{
    if (unlikely(self->_signature == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'signature' of 'FunctionABI' undefined");
        return NULL;
    }
    CPy_INCREF(self->_signature);
    PyObject *retval = self->_signature;
    return retval;
}

static int
FunctionABI_set_signature(dank_mids___brownie_patch____abi___FunctionABIObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'FunctionABI' object attribute 'signature' cannot be deleted");
        return -1;
    }
    if (self->_signature != NULL) {
        CPy_DECREF(self->_signature);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_signature = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids.brownie_patch._abi",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids___brownie_patch____abi(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids___brownie_patch____abi_internal) {
        Py_INCREF(CPyModule_dank_mids___brownie_patch____abi_internal);
        return CPyModule_dank_mids___brownie_patch____abi_internal;
    }
    CPyModule_dank_mids___brownie_patch____abi_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids___brownie_patch____abi_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids___brownie_patch____abi_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids___brownie_patch____abi_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids___brownie_patch____abi_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids___brownie_patch____abi_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_FunctionABI);
    return NULL;
}

char CPyDef_FunctionABI_____init__(PyObject *cpy_r_self, PyObject *cpy_r_abi) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    CPy_INCREF(cpy_r_abi);
    ((dank_mids___brownie_patch____abi___FunctionABIObject *)cpy_r_self)->_abi = cpy_r_abi;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[3]; /* 'build_function_signature' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "__init__", 29, CPyStatic_globals);
        goto CPyL5;
    }
    PyObject *cpy_r_r3[1] = {cpy_r_abi};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 1, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "__init__", 29, CPyStatic_globals);
        goto CPyL5;
    }
    ((dank_mids___brownie_patch____abi___FunctionABIObject *)cpy_r_self)->_input_sig = cpy_r_r5;
    cpy_r_r6 = CPyStatic_globals;
    cpy_r_r7 = CPyStatics[4]; /* 'build_function_selector' */
    cpy_r_r8 = CPyDict_GetItem(cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "__init__", 35, CPyStatic_globals);
        goto CPyL5;
    }
    PyObject *cpy_r_r9[1] = {cpy_r_abi};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = _PyObject_Vectorcall(cpy_r_r8, cpy_r_r10, 1, 0);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "__init__", 35, CPyStatic_globals);
        goto CPyL5;
    }
    ((dank_mids___brownie_patch____abi___FunctionABIObject *)cpy_r_self)->_signature = cpy_r_r11;
    return 1;
CPyL5: ;
    cpy_r_r12 = 2;
    return cpy_r_r12;
}

PyObject *CPyPy_FunctionABI_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    PyObject *obj_abi;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "%", "__init__", kwlist, NULL, &obj_abi)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_FunctionABI))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.brownie_patch._abi.FunctionABI", obj_self); 
        goto fail;
    }
    PyObject *arg_abi = obj_abi;
    char retval = CPyDef_FunctionABI_____init__(arg_self, arg_abi);
    CPy_DECREF(obj_abi);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_DECREF(obj_abi);
    CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "__init__", 15, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_FunctionABI___singleton(PyObject *cpy_r_abi) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    int32_t cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    cpy_r_r0 = (PyObject *)CPyType_FunctionABI;
    cpy_r_r1 = PyDict_New();
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "singleton", 50, CPyStatic_globals);
        goto CPyL6;
    }
    cpy_r_r2 = CPyDict_UpdateInDisplay(cpy_r_r1, cpy_r_abi);
    cpy_r_r3 = cpy_r_r2 >= 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "singleton", 50, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r4 = PyTuple_Pack(0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "singleton", 50, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r5 = PyObject_Call(cpy_r_r0, cpy_r_r4, cpy_r_r1);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "singleton", 50, CPyStatic_globals);
        goto CPyL6;
    }
    if (likely(Py_TYPE(cpy_r_r5) == CPyType_FunctionABI))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/_abi.py", "singleton", 50, CPyStatic_globals, "dank_mids.brownie_patch._abi.FunctionABI", cpy_r_r5);
        goto CPyL6;
    }
    return cpy_r_r6;
CPyL6: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
CPyL7: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL6;
}

PyObject *CPyPy_FunctionABI___singleton(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:singleton", kwlist, 0};
    PyObject *obj_abi;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, NULL, &obj_abi)) {
        return NULL;
    }
    PyObject *arg_abi = obj_abi;
    PyObject *retval = CPyDef_FunctionABI___singleton(arg_abi);
    CPy_DECREF(obj_abi);
    return retval;
fail: ;
    CPy_DECREF(obj_abi);
    CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "singleton", 43, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
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
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    int32_t cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[5]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", -1, CPyStatic_globals);
        goto CPyL17;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_functools;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[22]; /* (('functools', 'functools', 'functools'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[7]; /* 'dank_mids/brownie_patch/_abi.py' */
    cpy_r_r13 = CPyStatics[8]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL17;
    cpy_r_r15 = CPyStatics[23]; /* ('Any',) */
    cpy_r_r16 = CPyStatics[10]; /* 'typing' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 2, CPyStatic_globals);
        goto CPyL17;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[24]; /* ('build_function_selector', 'build_function_signature') */
    cpy_r_r20 = CPyStatics[11]; /* 'brownie.convert.utils' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 4, CPyStatic_globals);
        goto CPyL17;
    }
    CPyModule_brownie___convert___utils = cpy_r_r22;
    CPy_INCREF(CPyModule_brownie___convert___utils);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = NULL;
    cpy_r_r24 = CPyStatics[12]; /* 'dank_mids.brownie_patch._abi' */
    cpy_r_r25 = (PyObject *)CPyType_FunctionABI_template;
    cpy_r_r26 = CPyType_FromTemplate(cpy_r_r25, cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 7, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r27 = CPyDef_FunctionABI_trait_vtable_setup();
    if (unlikely(cpy_r_r27 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", -1, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r28 = CPyStatics[13]; /* '__mypyc_attrs__' */
    cpy_r_r29 = CPyStatics[14]; /* 'abi' */
    cpy_r_r30 = CPyStatics[15]; /* 'input_sig' */
    cpy_r_r31 = CPyStatics[16]; /* 'signature' */
    cpy_r_r32 = PyTuple_Pack(3, cpy_r_r29, cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 7, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r33 = PyObject_SetAttr(cpy_r_r26, cpy_r_r28, cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 7, CPyStatic_globals);
        goto CPyL18;
    }
    CPyType_FunctionABI = (PyTypeObject *)cpy_r_r26;
    CPy_INCREF(CPyType_FunctionABI);
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyStatics[17]; /* 'FunctionABI' */
    cpy_r_r37 = CPyDict_SetItem(cpy_r_r35, cpy_r_r36, cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r38 = cpy_r_r37 >= 0;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 7, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r39 = (PyObject *)CPyType_FunctionABI;
    cpy_r_r40 = CPyStatics[18]; /* 'singleton' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 43, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r42 = CPyModule_functools;
    cpy_r_r43 = CPyStatics[19]; /* 'lru_cache' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 41, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r45 = Py_None;
    PyObject *cpy_r_r46[1] = {cpy_r_r45};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = CPyStatics[25]; /* ('maxsize',) */
    cpy_r_r49 = _PyObject_Vectorcall(cpy_r_r44, cpy_r_r47, 0, cpy_r_r48);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 41, CPyStatic_globals);
        goto CPyL19;
    }
    PyObject *cpy_r_r50[1] = {cpy_r_r41};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = _PyObject_Vectorcall(cpy_r_r49, cpy_r_r51, 1, 0);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 43, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_DECREF(cpy_r_r41);
    cpy_r_r53 = CPyStatics[18]; /* 'singleton' */
    cpy_r_r54 = PyObject_SetAttr(cpy_r_r39, cpy_r_r53, cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("dank_mids/brownie_patch/_abi.py", "<module>", 43, CPyStatic_globals);
        goto CPyL17;
    }
    return 1;
CPyL17: ;
    cpy_r_r56 = 2;
    return cpy_r_r56;
CPyL18: ;
    CPy_DecRef(cpy_r_r26);
    goto CPyL17;
CPyL19: ;
    CPy_DecRef(cpy_r_r41);
    goto CPyL17;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___brownie_patch____abi = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_functools = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_brownie___convert___utils = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[26];
const char * const CPyLit_Str[] = {
    "\004\030build_function_signature\027build_function_selector\bbuiltins\tfunctools",
    "\004\037dank_mids/brownie_patch/_abi.py\b<module>\003Any\006typing",
    "\003\025brownie.convert.utils\034dank_mids.brownie_patch._abi\017__mypyc_attrs__",
    "\a\003abi\tinput_sig\tsignature\vFunctionABI\tsingleton\tlru_cache\amaxsize",
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
const int CPyLit_Tuple[] = {5, 3, 6, 6, 6, 1, 21, 1, 9, 2, 4, 3, 1, 20};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___brownie_patch____abi_internal = NULL;
CPyModule *CPyModule_dank_mids___brownie_patch____abi;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_brownie___convert___utils;
PyTypeObject *CPyType_FunctionABI;
PyObject *CPyDef_FunctionABI(PyObject *cpy_r_abi);
char CPyDef_FunctionABI_____init__(PyObject *cpy_r_self, PyObject *cpy_r_abi);
PyObject *CPyPy_FunctionABI_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_FunctionABI___singleton(PyObject *cpy_r_abi);
PyObject *CPyPy_FunctionABI___singleton(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids___brownie_patch____abi exports = {
    &CPyType_FunctionABI,
    &CPyDef_FunctionABI,
    &CPyDef_FunctionABI_____init__,
    &CPyDef_FunctionABI___singleton,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit__abi__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids.brownie_patch._abi__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids.brownie_patch._abi__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids___brownie_patch____abi(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids___brownie_patch____abi, "dank_mids.brownie_patch._abi__mypyc.init_dank_mids___brownie_patch____abi", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids___brownie_patch____abi", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
