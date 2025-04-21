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
#include "__native__uid.h"
#include "__native_internal__uid.h"

static int
UIDGenerator_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *UIDGenerator_setup(PyTypeObject *type);
PyObject *CPyDef_UIDGenerator(void);

static PyObject *
UIDGenerator_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_UIDGenerator) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = UIDGenerator_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_UIDGenerator_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
UIDGenerator_traverse(dank_mids____uid___UIDGeneratorObject *self, visitproc visit, void *arg)
{
    if (CPyTagged_CheckLong(self->__value)) {
        Py_VISIT(CPyTagged_LongAsObject(self->__value));
    }
    Py_VISIT(self->__lock);
    return 0;
}

static int
UIDGenerator_clear(dank_mids____uid___UIDGeneratorObject *self)
{
    if (CPyTagged_CheckLong(self->__value)) {
        CPyTagged __tmp = self->__value;
        self->__value = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->__lock);
    return 0;
}

static void
UIDGenerator_dealloc(dank_mids____uid___UIDGeneratorObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, UIDGenerator_dealloc)
    UIDGenerator_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem UIDGenerator_vtable[3];
static bool
CPyDef_UIDGenerator_trait_vtable_setup(void)
{
    CPyVTableItem UIDGenerator_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_UIDGenerator_____init__,
        (CPyVTableItem)CPyDef_UIDGenerator___latest,
        (CPyVTableItem)CPyDef_UIDGenerator___next,
    };
    memcpy(UIDGenerator_vtable, UIDGenerator_vtable_scratch, sizeof(UIDGenerator_vtable));
    return 1;
}

static PyObject *
UIDGenerator_get__value(dank_mids____uid___UIDGeneratorObject *self, void *closure);
static int
UIDGenerator_set__value(dank_mids____uid___UIDGeneratorObject *self, PyObject *value, void *closure);
static PyObject *
UIDGenerator_get__lock(dank_mids____uid___UIDGeneratorObject *self, void *closure);
static int
UIDGenerator_set__lock(dank_mids____uid___UIDGeneratorObject *self, PyObject *value, void *closure);
static PyObject *
UIDGenerator_get_latest(dank_mids____uid___UIDGeneratorObject *self, void *closure);
static PyObject *
UIDGenerator_get_next(dank_mids____uid___UIDGeneratorObject *self, void *closure);

static PyGetSetDef UIDGenerator_getseters[] = {
    {"_value",
     (getter)UIDGenerator_get__value, (setter)UIDGenerator_set__value,
     NULL, NULL},
    {"_lock",
     (getter)UIDGenerator_get__lock, (setter)UIDGenerator_set__lock,
     NULL, NULL},
    {"latest",
     (getter)UIDGenerator_get_latest,
    NULL, NULL, NULL},
    {"next",
     (getter)UIDGenerator_get_next,
    NULL, NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef UIDGenerator_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_UIDGenerator_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_UIDGenerator_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "UIDGenerator",
    .tp_new = UIDGenerator_new,
    .tp_dealloc = (destructor)UIDGenerator_dealloc,
    .tp_traverse = (traverseproc)UIDGenerator_traverse,
    .tp_clear = (inquiry)UIDGenerator_clear,
    .tp_getset = UIDGenerator_getseters,
    .tp_methods = UIDGenerator_methods,
    .tp_init = UIDGenerator_init,
    .tp_basicsize = sizeof(dank_mids____uid___UIDGeneratorObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_UIDGenerator_template = &CPyType_UIDGenerator_template_;

static PyObject *
UIDGenerator_setup(PyTypeObject *type)
{
    dank_mids____uid___UIDGeneratorObject *self;
    self = (dank_mids____uid___UIDGeneratorObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = UIDGenerator_vtable;
    self->__value = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef_UIDGenerator(void)
{
    PyObject *self = UIDGenerator_setup(CPyType_UIDGenerator);
    if (self == NULL)
        return NULL;
    char res = CPyDef_UIDGenerator_____init__(self);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
UIDGenerator_get__value(dank_mids____uid___UIDGeneratorObject *self, void *closure)
{
    if (unlikely(self->__value == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_value' of 'UIDGenerator' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->__value);
    PyObject *retval = CPyTagged_StealAsObject(self->__value);
    return retval;
}

static int
UIDGenerator_set__value(dank_mids____uid___UIDGeneratorObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'UIDGenerator' object attribute '_value' cannot be deleted");
        return -1;
    }
    if (self->__value != CPY_INT_TAG) {
        CPyTagged_DECREF(self->__value);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->__value = tmp;
    return 0;
}

static PyObject *
UIDGenerator_get__lock(dank_mids____uid___UIDGeneratorObject *self, void *closure)
{
    if (unlikely(self->__lock == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_lock' of 'UIDGenerator' undefined");
        return NULL;
    }
    CPy_INCREF(self->__lock);
    PyObject *retval = self->__lock;
    return retval;
}

static int
UIDGenerator_set__lock(dank_mids____uid___UIDGeneratorObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'UIDGenerator' object attribute '_lock' cannot be deleted");
        return -1;
    }
    if (self->__lock != NULL) {
        CPy_DECREF(self->__lock);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->__lock = tmp;
    return 0;
}

static PyObject *
UIDGenerator_get_latest(dank_mids____uid___UIDGeneratorObject *self, void *closure)
{
    CPyTagged retval = CPyDef_UIDGenerator___latest((PyObject *) self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
}

static PyObject *
UIDGenerator_get_next(dank_mids____uid___UIDGeneratorObject *self, void *closure)
{
    CPyTagged retval = CPyDef_UIDGenerator___next((PyObject *) self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids._uid",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids____uid(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids____uid_internal) {
        Py_INCREF(CPyModule_dank_mids____uid_internal);
        return CPyModule_dank_mids____uid_internal;
    }
    CPyModule_dank_mids____uid_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids____uid_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids____uid_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids____uid_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids____uid_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids____uid_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_UIDGenerator);
    return NULL;
}

char CPyDef_UIDGenerator_____init__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    ((dank_mids____uid___UIDGeneratorObject *)cpy_r_self)->__value = -2;
    cpy_r_r0 = CPyStatics[3]; /* 'uid' */
    cpy_r_r1 = CPyStatic_globals;
    cpy_r_r2 = CPyStatics[4]; /* 'AlertingRLock' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "__init__", 24, CPyStatic_globals);
        goto CPyL3;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = CPyStatics[15]; /* ('name',) */
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 0, cpy_r_r6);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "__init__", 24, CPyStatic_globals);
        goto CPyL3;
    }
    ((dank_mids____uid___UIDGeneratorObject *)cpy_r_self)->__lock = cpy_r_r7;
    return 1;
CPyL3: ;
    cpy_r_r8 = 2;
    return cpy_r_r8;
}

PyObject *CPyPy_UIDGenerator_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "", "__init__", kwlist)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_UIDGenerator))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids._uid.UIDGenerator", obj_self); 
        goto fail;
    }
    char retval = CPyDef_UIDGenerator_____init__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/_uid.py", "__init__", 7, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_UIDGenerator___latest(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    cpy_r_r0 = ((dank_mids____uid___UIDGeneratorObject *)cpy_r_self)->__value;
    CPyTagged_INCREF(cpy_r_r0);
    return cpy_r_r0;
}

PyObject *CPyPy_UIDGenerator___latest(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":latest", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_UIDGenerator))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids._uid.UIDGenerator", obj_self); 
        goto fail;
    }
    CPyTagged retval = CPyDef_UIDGenerator___latest(arg_self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/_uid.py", "latest", 27, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_UIDGenerator___next(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    CPyTagged cpy_r_r9;
    CPyTagged cpy_r_r10;
    char cpy_r_r11;
    tuple_T3OOO cpy_r_r12;
    tuple_T3OOO cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    CPyTagged cpy_r_r19;
    cpy_r_r0 = ((dank_mids____uid___UIDGeneratorObject *)cpy_r_self)->__lock;
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = PyObject_Type(cpy_r_r0);
    cpy_r_r2 = CPyStatics[6]; /* '__exit__' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "next", 48, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r4 = CPyStatics[7]; /* '__enter__' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r4);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "next", 48, CPyStatic_globals);
        goto CPyL21;
    }
    PyObject *cpy_r_r6[1] = {cpy_r_r0};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = _PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "next", 48, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL22;
CPyL3: ;
    cpy_r_r9 = ((dank_mids____uid___UIDGeneratorObject *)cpy_r_self)->__value;
    cpy_r_r10 = CPyTagged_Add(cpy_r_r9, 2);
    CPyTagged_INCREF(cpy_r_r10);
    CPyTagged_DECREF(((dank_mids____uid___UIDGeneratorObject *)cpy_r_self)->__value);
    ((dank_mids____uid___UIDGeneratorObject *)cpy_r_self)->__value = cpy_r_r10;
    tuple_T3OOO __tmp1 = { NULL, NULL, NULL };
    cpy_r_r12 = __tmp1;
    cpy_r_r13 = cpy_r_r12;
    if (!1) goto CPyL23;
    cpy_r_r14 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r15[4] = {cpy_r_r0, cpy_r_r14, cpy_r_r14, cpy_r_r14};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r16, 4, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "next", 48, CPyStatic_globals);
        goto CPyL24;
    } else
        goto CPyL25;
CPyL8: ;
    CPy_DECREF(cpy_r_r0);
CPyL9: ;
    if (cpy_r_r13.f0 == NULL) {
        goto CPyL12;
    } else
        goto CPyL26;
CPyL10: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL14;
    } else
        goto CPyL27;
CPyL11: ;
    CPy_Unreachable();
CPyL12: ;
    if (cpy_r_r10 == CPY_INT_TAG) goto CPyL18;
    return cpy_r_r10;
CPyL14: ;
    if (cpy_r_r13.f0 == NULL) goto CPyL16;
    CPy_RestoreExcInfo(cpy_r_r13);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
CPyL16: ;
    cpy_r_r18 = CPy_KeepPropagating();
    if (!cpy_r_r18) goto CPyL19;
    CPy_Unreachable();
CPyL18: ;
    CPy_Unreachable();
CPyL19: ;
    cpy_r_r19 = CPY_INT_TAG;
    return cpy_r_r19;
CPyL20: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL19;
CPyL21: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r3);
    goto CPyL19;
CPyL22: ;
    CPy_DECREF(cpy_r_r8);
    goto CPyL3;
CPyL23: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r3);
    goto CPyL9;
CPyL24: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_XDecRef(cpy_r_r10);
    goto CPyL14;
CPyL25: ;
    CPy_DECREF(cpy_r_r17);
    goto CPyL8;
CPyL26: ;
    CPyTagged_XDECREF(cpy_r_r10);
    goto CPyL10;
CPyL27: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    goto CPyL11;
}

PyObject *CPyPy_UIDGenerator___next(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":next", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_UIDGenerator))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids._uid.UIDGenerator", obj_self); 
        goto fail;
    }
    CPyTagged retval = CPyDef_UIDGenerator___next(arg_self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/_uid.py", "next", 38, CPyStatic_globals);
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
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    int32_t cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[8]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "<module>", -1, CPyStatic_globals);
        goto CPyL10;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[16]; /* ('AlertingRLock',) */
    cpy_r_r6 = CPyStatics[9]; /* 'dank_mids.helpers._lock' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "<module>", 1, CPyStatic_globals);
        goto CPyL10;
    }
    CPyModule_dank_mids___helpers____lock = cpy_r_r8;
    CPy_INCREF(CPyModule_dank_mids___helpers____lock);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = NULL;
    cpy_r_r10 = CPyStatics[10]; /* 'dank_mids._uid' */
    cpy_r_r11 = (PyObject *)CPyType_UIDGenerator_template;
    cpy_r_r12 = CPyType_FromTemplate(cpy_r_r11, cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "<module>", 4, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r13 = CPyDef_UIDGenerator_trait_vtable_setup();
    if (unlikely(cpy_r_r13 == 2)) {
        CPy_AddTraceback("dank_mids/_uid.py", "<module>", -1, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r14 = CPyStatics[11]; /* '__mypyc_attrs__' */
    cpy_r_r15 = CPyStatics[12]; /* '_value' */
    cpy_r_r16 = CPyStatics[13]; /* '_lock' */
    cpy_r_r17 = PyTuple_Pack(2, cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/_uid.py", "<module>", 4, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r18 = PyObject_SetAttr(cpy_r_r12, cpy_r_r14, cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("dank_mids/_uid.py", "<module>", 4, CPyStatic_globals);
        goto CPyL11;
    }
    CPyType_UIDGenerator = (PyTypeObject *)cpy_r_r12;
    CPy_INCREF(CPyType_UIDGenerator);
    cpy_r_r20 = CPyStatic_globals;
    cpy_r_r21 = CPyStatics[14]; /* 'UIDGenerator' */
    cpy_r_r22 = CPyDict_SetItem(cpy_r_r20, cpy_r_r21, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/_uid.py", "<module>", 4, CPyStatic_globals);
        goto CPyL10;
    }
    return 1;
CPyL10: ;
    cpy_r_r24 = 2;
    return cpy_r_r24;
CPyL11: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL10;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids____uid = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_dank_mids___helpers____lock = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[17];
const char * const CPyLit_Str[] = {
    "\006\003uid\rAlertingRLock\004name\b__exit__\t__enter__\bbuiltins",
    "\005\027dank_mids.helpers._lock\016dank_mids._uid\017__mypyc_attrs__\006_value\005_lock",
    "\001\fUIDGenerator",
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
const int CPyLit_Tuple[] = {2, 1, 5, 1, 4};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids____uid_internal = NULL;
CPyModule *CPyModule_dank_mids____uid;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_dank_mids___helpers____lock;
PyTypeObject *CPyType_UIDGenerator;
PyObject *CPyDef_UIDGenerator(void);
char CPyDef_UIDGenerator_____init__(PyObject *cpy_r_self);
PyObject *CPyPy_UIDGenerator_____init__(PyObject *self, PyObject *args, PyObject *kw);
CPyTagged CPyDef_UIDGenerator___latest(PyObject *cpy_r_self);
PyObject *CPyPy_UIDGenerator___latest(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_UIDGenerator___next(PyObject *cpy_r_self);
PyObject *CPyPy_UIDGenerator___next(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids____uid exports = {
    &CPyType_UIDGenerator,
    &CPyDef_UIDGenerator,
    &CPyDef_UIDGenerator_____init__,
    &CPyDef_UIDGenerator___latest,
    &CPyDef_UIDGenerator___next,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit__uid__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids._uid__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids._uid__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids____uid(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids____uid, "dank_mids._uid__mypyc.init_dank_mids____uid", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids____uid", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
