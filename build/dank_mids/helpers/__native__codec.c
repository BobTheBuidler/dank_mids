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
#include "__native__codec.h"
#include "__native_internal__codec.h"

static PyObject *CPyDunder___get____mypyc_lambda__0_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__0_obj_____get__(self, instance, owner);
}
PyMemberDef __mypyc_lambda__0_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
static PyObject *__mypyc_lambda__0_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__0_obj(void);

static PyObject *
__mypyc_lambda__0_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__0_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__0_obj_setup(type);
}

static int
__mypyc_lambda__0_obj_traverse(dank_mids___helpers____codec_____mypyc_lambda__0_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject))));
    return 0;
}

static int
__mypyc_lambda__0_obj_clear(dank_mids___helpers____codec_____mypyc_lambda__0_objObject *self)
{
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject))));
    return 0;
}

static void
__mypyc_lambda__0_obj_dealloc(dank_mids___helpers____codec_____mypyc_lambda__0_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__0_obj_dealloc)
    __mypyc_lambda__0_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__0_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__0_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__0_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__0_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__0_obj_____get__,
    };
    memcpy(__mypyc_lambda__0_obj_vtable, __mypyc_lambda__0_obj_vtable_scratch, sizeof(__mypyc_lambda__0_obj_vtable));
    return 1;
}


static PyGetSetDef __mypyc_lambda__0_obj_getseters[] = {
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__0_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__0_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__0_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__0_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__0_obj",
    .tp_new = __mypyc_lambda__0_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__0_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__0_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__0_obj_clear,
    .tp_getset = __mypyc_lambda__0_obj_getseters,
    .tp_methods = __mypyc_lambda__0_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__0_obj,
    .tp_members = __mypyc_lambda__0_obj_members,
    .tp_basicsize = sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
};
static PyTypeObject *CPyType___mypyc_lambda__0_obj_template = &CPyType___mypyc_lambda__0_obj_template_;

static PyObject *
__mypyc_lambda__0_obj_setup(PyTypeObject *type)
{
    dank_mids___helpers____codec_____mypyc_lambda__0_objObject *self;
    self = (dank_mids___helpers____codec_____mypyc_lambda__0_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__0_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__0_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__0_obj(void)
{
    PyObject *self = __mypyc_lambda__0_obj_setup(CPyType___mypyc_lambda__0_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {"decode_raw", (PyCFunction)CPyPy_decode_raw, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"decode_jsonrpc_batch", (PyCFunction)CPyPy_decode_jsonrpc_batch, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"encode", (PyCFunction)CPyPy_encode, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"__encode_new", (PyCFunction)CPyPy___encode_new, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"__encode_elements_new", (PyCFunction)CPyPy___encode_elements_new, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"mcall_encode", (PyCFunction)CPyPy_mcall_encode, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"mcall_decode", (PyCFunction)CPyPy_mcall_decode, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids.helpers._codec",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids___helpers____codec(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids___helpers____codec_internal) {
        Py_INCREF(CPyModule_dank_mids___helpers____codec_internal);
        return CPyModule_dank_mids___helpers____codec_internal;
    }
    CPyModule_dank_mids___helpers____codec_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids___helpers____codec_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids___helpers____codec_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids___helpers____codec_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType___mypyc_lambda__0_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__0_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__0_obj))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids___helpers____codec_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids___helpers____codec_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__mcall_encoder);
    CPyStatic__mcall_encoder = NULL;
    CPy_XDECREF(CPyStatic__array_encoder);
    CPyStatic__array_encoder = NULL;
    CPy_XDECREF(CPyStatic__item_encoder);
    CPyStatic__item_encoder = NULL;
    CPy_XDECREF(CPyStatic__mcall_decoder);
    CPyStatic__mcall_decoder = NULL;
    Py_CLEAR(CPyType___mypyc_lambda__0_obj);
    return NULL;
}

PyObject *CPyDef_decode_raw(PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    tuple_T3OOO cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    int32_t cpy_r_r30;
    char cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[3]; /* 'Raw' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 40, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r3 = CPyStatic_globals;
    cpy_r_r4 = CPyStatics[4]; /* 'json_decode' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 40, CPyStatic_globals);
        goto CPyL22;
    }
    PyObject *cpy_r_r6[2] = {cpy_r_data, cpy_r_r2};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = CPyStatics[70]; /* ('type',) */
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, cpy_r_r8);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 40, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r10 = CPyStatic_globals;
    cpy_r_r11 = CPyStatics[6]; /* 'RawResponse' */
    cpy_r_r12 = CPyDict_GetItem(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 40, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r13[1] = {cpy_r_r9};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 40, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r9);
    return cpy_r_r15;
CPyL7: ;
    cpy_r_r16 = CPy_CatchError();
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyStatics[7]; /* 'DecodeError' */
    cpy_r_r19 = CPyDict_GetItem(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 41, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r20 = CPy_ExceptionMatches(cpy_r_r19);
    CPy_DecRef(cpy_r_r19);
    if (!cpy_r_r20) goto CPyL17;
    cpy_r_r21 = CPy_GetExcValue();
    cpy_r_r22 = CPyStatics[8]; /* 'args' */
    cpy_r_r23 = CPyObject_GetAttr(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 42, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r24 = PyList_New(0);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 42, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r25 = CPyList_Extend(cpy_r_r24, cpy_r_r23);
    CPy_DecRef(cpy_r_r23);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 42, CPyStatic_globals);
        goto CPyL26;
    } else
        goto CPyL27;
CPyL12: ;
    cpy_r_r26 = PyList_Append(cpy_r_r24, cpy_r_data);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 42, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r28 = PyList_AsTuple(cpy_r_r24);
    CPy_DecRef(cpy_r_r24);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 42, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r29 = CPyStatics[8]; /* 'args' */
    cpy_r_r30 = PyObject_SetAttr(cpy_r_r21, cpy_r_r29, cpy_r_r28);
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r28);
    cpy_r_r31 = cpy_r_r30 >= 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 42, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_Reraise();
    if (!0) {
        goto CPyL19;
    } else
        goto CPyL28;
CPyL16: ;
    CPy_Unreachable();
CPyL17: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL19;
    } else
        goto CPyL29;
CPyL18: ;
    CPy_Unreachable();
CPyL19: ;
    CPy_RestoreExcInfo(cpy_r_r16);
    CPy_DecRef(cpy_r_r16.f0);
    CPy_DecRef(cpy_r_r16.f1);
    CPy_DecRef(cpy_r_r16.f2);
    cpy_r_r32 = CPy_KeepPropagating();
    if (!cpy_r_r32) goto CPyL21;
    CPy_Unreachable();
CPyL21: ;
    cpy_r_r33 = NULL;
    return cpy_r_r33;
CPyL22: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL7;
CPyL23: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL7;
CPyL24: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL19;
CPyL25: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r23);
    goto CPyL19;
CPyL26: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL19;
CPyL27: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL12;
CPyL28: ;
    CPy_DecRef(cpy_r_r16.f0);
    CPy_DecRef(cpy_r_r16.f1);
    CPy_DecRef(cpy_r_r16.f2);
    goto CPyL16;
CPyL29: ;
    CPy_DecRef(cpy_r_r16.f0);
    CPy_DecRef(cpy_r_r16.f1);
    CPy_DecRef(cpy_r_r16.f2);
    goto CPyL18;
}

PyObject *CPyPy_decode_raw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:decode_raw", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef_decode_raw(arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 29, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_jsonrpc_batch(PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[9]; /* 'JSONRPCBatchResponseRaw' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 56, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r3 = CPyStatic_globals;
    cpy_r_r4 = CPyStatics[4]; /* 'json_decode' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 56, CPyStatic_globals);
        goto CPyL14;
    }
    PyObject *cpy_r_r6[2] = {cpy_r_data, cpy_r_r2};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = CPyStatics[70]; /* ('type',) */
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, cpy_r_r8);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 56, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r10 = CPyStatic_globals;
    cpy_r_r11 = CPyStatics[10]; /* 'PartialResponse' */
    cpy_r_r12 = CPyDict_GetItem(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 57, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r13 = PyObject_IsInstance(cpy_r_r9, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 57, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r15 = cpy_r_r13;
    if (!cpy_r_r15) goto CPyL7;
    cpy_r_r16 = cpy_r_r9;
    goto CPyL12;
CPyL7: ;
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyStatics[6]; /* 'RawResponse' */
    cpy_r_r19 = CPyDict_GetItem(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 57, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r20 = CPyModule_builtins;
    cpy_r_r21 = CPyStatics[11]; /* 'map' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 57, CPyStatic_globals);
        goto CPyL16;
    }
    PyObject *cpy_r_r23[2] = {cpy_r_r19, cpy_r_r9};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = _PyObject_Vectorcall(cpy_r_r22, cpy_r_r24, 2, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 57, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r26 = PySequence_List(cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 57, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r16 = cpy_r_r26;
CPyL12: ;
    return cpy_r_r16;
CPyL13: ;
    cpy_r_r27 = NULL;
    return cpy_r_r27;
CPyL14: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL13;
CPyL15: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL13;
CPyL16: ;
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r19);
    goto CPyL13;
}

PyObject *CPyPy_decode_jsonrpc_batch(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:decode_jsonrpc_batch", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef_decode_jsonrpc_batch(arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 46, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode(PyObject *cpy_r_obj) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[12]; /* '_encode_hook' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "encode", 75, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r3 = CPyStatic_globals;
    cpy_r_r4 = CPyStatics[13]; /* 'json_encode' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "encode", 75, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r6[2] = {cpy_r_obj, cpy_r_r2};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = CPyStatics[71]; /* ('enc_hook',) */
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, cpy_r_r8);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "encode", 75, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r2);
    if (likely(PyBytes_Check(cpy_r_r9) || PyByteArray_Check(cpy_r_r9)))
        cpy_r_r10 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "encode", 75, CPyStatic_globals, "bytes", cpy_r_r9);
        goto CPyL5;
    }
    return cpy_r_r10;
CPyL5: ;
    cpy_r_r11 = NULL;
    return cpy_r_r11;
CPyL6: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL5;
}

PyObject *CPyPy_encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"obj", 0};
    static CPyArg_Parser parser = {"O:encode", kwlist, 0};
    PyObject *obj_obj;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_obj)) {
        return NULL;
    }
    PyObject *arg_obj = obj_obj;
    PyObject *retval = CPyDef_encode(arg_obj);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "encode", 60, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__0_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_instance == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
CPyL2: ;
    cpy_r_r2 = PyMethod_New(cpy_r___mypyc_self__, cpy_r_instance);
    if (cpy_r_r2 == NULL) goto CPyL4;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy___mypyc_lambda__0_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner = obj_owner;
    PyObject *retval = CPyDef___mypyc_lambda__0_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__0_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r__) {
    PyObject *cpy_r_r0;
    cpy_r_r0 = (PyObject *)&_Py_EllipsisObject;
    CPy_INCREF(cpy_r_r0);
    return cpy_r_r0;
}

PyObject *CPyPy___mypyc_lambda__0_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:__call__", kwlist, 0};
    PyObject *obj__;
    if (!CPyArg_ParseStackAndKeywords(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj__, NULL)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg__ = obj__;
    PyObject *retval = CPyDef___mypyc_lambda__0_obj_____call__(arg___mypyc_self__, arg__);
    CPy_DECREF(obj__);
    return retval;
fail: ;
    CPy_DECREF(obj__);
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "<lambda>", 87, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___encode_new(PyObject *cpy_r_values) {
    tuple_T2OI cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    cpy_r_r0 = CPyDef___encode_elements_new(cpy_r_values);
    if (unlikely(cpy_r_r0.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 91, CPyStatic_globals);
        goto CPyL6;
    }
    cpy_r_r1 = cpy_r_r0.f0;
    cpy_r_r2 = cpy_r_r1;
    cpy_r_r3 = cpy_r_r0.f1;
    cpy_r_r4 = cpy_r_r3;
    cpy_r_r5 = CPyStatic_globals;
    cpy_r_r6 = CPyStatics[15]; /* 'encode_uint_256' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 92, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r8 = CPyTagged_StealAsObject(cpy_r_r4);
    PyObject *cpy_r_r9[1] = {cpy_r_r8};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = _PyObject_Vectorcall(cpy_r_r7, cpy_r_r10, 1, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 92, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_DECREF(cpy_r_r8);
    cpy_r_r12 = PyNumber_Add(cpy_r_r11, cpy_r_r2);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 92, CPyStatic_globals);
        goto CPyL6;
    }
    if (likely(PyBytes_Check(cpy_r_r12) || PyByteArray_Check(cpy_r_r12)))
        cpy_r_r13 = cpy_r_r12;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "__encode_new", 92, CPyStatic_globals, "bytes", cpy_r_r12);
        goto CPyL6;
    }
    return cpy_r_r13;
CPyL6: ;
    cpy_r_r14 = NULL;
    return cpy_r_r14;
CPyL7: ;
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r4);
    goto CPyL6;
CPyL8: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r8);
    goto CPyL6;
}

PyObject *CPyPy___encode_new(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"values", 0};
    static CPyArg_Parser parser = {"O:__encode_new", kwlist, 0};
    PyObject *obj_values;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_values)) {
        return NULL;
    }
    PyObject *arg_values = obj_values;
    PyObject *retval = CPyDef___encode_new(arg_values);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 90, CPyStatic_globals);
    return NULL;
}

tuple_T2OI CPyDef___encode_elements_new(PyObject *cpy_r_values) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    CPyPtr cpy_r_r9;
    int64_t cpy_r_r10;
    CPyTagged cpy_r_r11;
    CPyTagged cpy_r_count;
    CPyTagged cpy_r_r12;
    tuple_T1I cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject **cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r36;
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
    PyObject **cpy_r_r48;
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
    PyObject **cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    tuple_T2OI cpy_r_r64;
    tuple_T2OI cpy_r_r65;
    cpy_r_r0 = CPyStatic__item_encoder;
    if (likely(cpy_r_r0 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"_item_encoder\" was not set");
    cpy_r_r1 = 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 96, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r2 = CPyModule_builtins;
    cpy_r_r3 = CPyStatics[11]; /* 'map' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 96, CPyStatic_globals);
        goto CPyL25;
    }
    PyObject *cpy_r_r5[2] = {cpy_r_r0, cpy_r_values};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 2, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 96, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r8 = PySequence_Tuple(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 96, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r9 = (CPyPtr)&((PyVarObject *)cpy_r_r8)->ob_size;
    cpy_r_r10 = *(int64_t *)cpy_r_r9;
    cpy_r_r11 = cpy_r_r10 << 1;
    cpy_r_count = cpy_r_r11;
    cpy_r_r12 = CPyTagged_Multiply(64, cpy_r_count);
    cpy_r_r13.f0 = 0;
    cpy_r_r14 = CPyModule_builtins;
    cpy_r_r15 = CPyStatics[16]; /* 'len' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r17 = CPySequenceTuple_GetSlice(cpy_r_r8, 0, -2);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals);
        goto CPyL27;
    }
    if (likely(PyTuple_Check(cpy_r_r17)))
        cpy_r_r18 = cpy_r_r17;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals, "tuple", cpy_r_r17);
        goto CPyL27;
    }
    cpy_r_r19 = CPyModule_builtins;
    cpy_r_r20 = CPyStatics[11]; /* 'map' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals);
        goto CPyL28;
    }
    PyObject *cpy_r_r22[2] = {cpy_r_r16, cpy_r_r18};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = _PyObject_Vectorcall(cpy_r_r21, cpy_r_r23, 2, 0);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyStatics[17]; /* 'accumulate' */
    cpy_r_r27 = CPyDict_GetItem(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r28[1] = {cpy_r_r24};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 1, 0);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals);
        goto CPyL29;
    }
    CPy_DECREF(cpy_r_r24);
    cpy_r_r31 = CPyStatic_globals;
    cpy_r_r32 = CPyStatics[18]; /* 'chain' */
    cpy_r_r33 = CPyDict_GetItem(cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r34 = PyTuple_New(1);
    if (unlikely(cpy_r_r34 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = CPyTagged_StealAsObject(cpy_r_r13.f0);
    PyTuple_SET_ITEM(cpy_r_r34, 0, __tmp1);
    PyObject *cpy_r_r35[2] = {cpy_r_r34, cpy_r_r30};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = _PyObject_Vectorcall(cpy_r_r33, cpy_r_r36, 2, 0);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 99, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r38 = CPyStatic_globals;
    cpy_r_r39 = CPyStatics[15]; /* 'encode_uint_256' */
    cpy_r_r40 = CPyDict_GetItem(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 100, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r41 = CPyStatics[19]; /* '__add__' */
    cpy_r_r42 = CPyTagged_StealAsObject(cpy_r_r12);
    cpy_r_r43 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r41);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 100, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r44 = CPyModule_builtins;
    cpy_r_r45 = CPyStatics[11]; /* 'map' */
    cpy_r_r46 = CPyObject_GetAttr(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 100, CPyStatic_globals);
        goto CPyL34;
    }
    PyObject *cpy_r_r47[2] = {cpy_r_r43, cpy_r_r37};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = _PyObject_Vectorcall(cpy_r_r46, cpy_r_r48, 2, 0);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 100, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r37);
    cpy_r_r50 = CPyModule_builtins;
    cpy_r_r51 = CPyStatics[11]; /* 'map' */
    cpy_r_r52 = CPyObject_GetAttr(cpy_r_r50, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 100, CPyStatic_globals);
        goto CPyL35;
    }
    PyObject *cpy_r_r53[2] = {cpy_r_r40, cpy_r_r49};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 2, 0);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 100, CPyStatic_globals);
        goto CPyL35;
    }
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r49);
    cpy_r_r56 = CPyStatics[68]; /* b'' */
    cpy_r_r57 = CPyStatic_globals;
    cpy_r_r58 = CPyStatics[18]; /* 'chain' */
    cpy_r_r59 = CPyDict_GetItem(cpy_r_r57, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL36;
    }
    PyObject *cpy_r_r60[2] = {cpy_r_r55, cpy_r_r8};
    cpy_r_r61 = (PyObject **)&cpy_r_r60;
    cpy_r_r62 = _PyObject_Vectorcall(cpy_r_r59, cpy_r_r61, 2, 0);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r63 = CPyBytes_Join(cpy_r_r56, cpy_r_r62);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r64.f0 = cpy_r_r63;
    cpy_r_r64.f1 = cpy_r_count;
    return cpy_r_r64;
CPyL25: ;
    tuple_T2OI __tmp2 = { NULL, CPY_INT_TAG };
    cpy_r_r65 = __tmp2;
    return cpy_r_r65;
CPyL26: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13.f0);
    goto CPyL25;
CPyL27: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r16);
    goto CPyL25;
CPyL28: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r18);
    goto CPyL25;
CPyL29: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r24);
    goto CPyL25;
CPyL30: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r30);
    goto CPyL25;
CPyL31: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r34);
    goto CPyL25;
CPyL32: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r37);
    goto CPyL25;
CPyL33: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r40);
    goto CPyL25;
CPyL34: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r40);
    CPy_DecRef(cpy_r_r43);
    goto CPyL25;
CPyL35: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_r40);
    CPy_DecRef(cpy_r_r49);
    goto CPyL25;
CPyL36: ;
    CPy_DecRef(cpy_r_r8);
    CPyTagged_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_r55);
    goto CPyL25;
CPyL37: ;
    CPyTagged_DecRef(cpy_r_count);
    goto CPyL25;
}

PyObject *CPyPy___encode_elements_new(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"values", 0};
    static CPyArg_Parser parser = {"O:__encode_elements_new", kwlist, 0};
    PyObject *obj_values;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_values)) {
        return NULL;
    }
    PyObject *arg_values = obj_values;
    tuple_T2OI retval = CPyDef___encode_elements_new(arg_values);
    if (retval.f0 == NULL) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(2);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp3 = retval.f0;
    PyTuple_SET_ITEM(retbox, 0, __tmp3);
    PyObject *__tmp4 = CPyTagged_StealAsObject(retval.f1);
    PyTuple_SET_ITEM(retbox, 1, __tmp4);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 95, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_mcall_encode(PyObject *cpy_r_data) {
    tuple_T2CO cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    CPy_INCREF(cpy_r_data);
    cpy_r_r0.f0 = 0;
    cpy_r_r0.f1 = cpy_r_data;
    cpy_r_r1 = CPyStatic__mcall_encoder;
    if (unlikely(cpy_r_r1 == NULL)) {
        goto CPyL7;
    } else
        goto CPyL3;
CPyL1: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_mcall_encoder\" was not set");
    cpy_r_r2 = 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_encode", 114, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r3 = PyTuple_New(2);
    if (unlikely(cpy_r_r3 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp5 = cpy_r_r0.f0 ? Py_True : Py_False;
    CPy_INCREF(__tmp5);
    PyTuple_SET_ITEM(cpy_r_r3, 0, __tmp5);
    PyObject *__tmp6 = cpy_r_r0.f1;
    PyTuple_SET_ITEM(cpy_r_r3, 1, __tmp6);
    PyObject *cpy_r_r4[1] = {cpy_r_r3};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r1, cpy_r_r5, 1, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_encode", 114, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_DECREF(cpy_r_r3);
    if (likely(PyBytes_Check(cpy_r_r6) || PyByteArray_Check(cpy_r_r6)))
        cpy_r_r7 = cpy_r_r6;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "mcall_encode", 114, CPyStatic_globals, "bytes", cpy_r_r6);
        goto CPyL6;
    }
    return cpy_r_r7;
CPyL6: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
CPyL7: ;
    CPy_DecRef(cpy_r_r0.f1);
    goto CPyL1;
CPyL8: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL6;
}

PyObject *CPyPy_mcall_encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:mcall_encode", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef_mcall_encode(arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_encode", 113, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_mcall_decode(PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    tuple_T3IIO cpy_r_r16;
    PyObject *cpy_r_r17;
    tuple_T3OOO cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    int32_t cpy_r_r30;
    char cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    int32_t cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    int32_t cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    CPyPtr cpy_r_r47;
    int64_t cpy_r_r48;
    PyObject *cpy_r_r49;
    CPyTagged cpy_r_r50;
    CPyPtr cpy_r_r51;
    int64_t cpy_r_r52;
    CPyTagged cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    tuple_T2CO cpy_r_r56;
    PyObject *cpy_r_r57;
    char cpy_r_r58;
    CPyTagged cpy_r_r59;
    PyObject *cpy_r_r60;
    cpy_r_r0 = CPyStatics[20]; /* 'eth_call' */
    cpy_r_r1 = CPyStatics[21]; /* 'decode_result' */
    PyObject *cpy_r_r2[2] = {cpy_r_data, cpy_r_r0};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r3, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 123, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r5 = CPyStatic_globals;
    cpy_r_r6 = CPyStatics[22]; /* 'ContextFramesBytesIO' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 123, CPyStatic_globals);
        goto CPyL39;
    }
    PyObject *cpy_r_r8[1] = {cpy_r_r4};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r7, cpy_r_r9, 1, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 123, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_DECREF(cpy_r_r4);
    cpy_r_r11 = CPyStatic__mcall_decoder;
    if (unlikely(cpy_r_r11 == NULL)) {
        goto CPyL40;
    } else
        goto CPyL7;
CPyL5: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_mcall_decoder\" was not set");
    cpy_r_r12 = 0;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 123, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_Unreachable();
CPyL7: ;
    PyObject *cpy_r_r13[1] = {cpy_r_r10};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r11, cpy_r_r14, 1, 0);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 123, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r10);
    PyObject *__tmp7;
    if (unlikely(!(PyTuple_Check(cpy_r_r15) && PyTuple_GET_SIZE(cpy_r_r15) == 3))) {
        __tmp7 = NULL;
        goto __LL8;
    }
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r15, 0))))
        __tmp7 = PyTuple_GET_ITEM(cpy_r_r15, 0);
    else {
        __tmp7 = NULL;
    }
    if (__tmp7 == NULL) goto __LL8;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r15, 1))))
        __tmp7 = PyTuple_GET_ITEM(cpy_r_r15, 1);
    else {
        __tmp7 = NULL;
    }
    if (__tmp7 == NULL) goto __LL8;
    if (likely(PyTuple_Check(PyTuple_GET_ITEM(cpy_r_r15, 2))))
        __tmp7 = PyTuple_GET_ITEM(cpy_r_r15, 2);
    else {
        __tmp7 = NULL;
    }
    if (__tmp7 == NULL) goto __LL8;
    __tmp7 = cpy_r_r15;
__LL8: ;
    if (unlikely(__tmp7 == NULL)) {
        CPy_TypeError("tuple[int, int, tuple]", cpy_r_r15); cpy_r_r16 = (tuple_T3IIO) { CPY_INT_TAG, CPY_INT_TAG, NULL };
    } else {
        PyObject *__tmp9 = PyTuple_GET_ITEM(cpy_r_r15, 0);
        CPyTagged __tmp10;
        if (likely(PyLong_Check(__tmp9)))
            __tmp10 = CPyTagged_FromObject(__tmp9);
        else {
            CPy_TypeError("int", __tmp9); __tmp10 = CPY_INT_TAG;
        }
        cpy_r_r16.f0 = __tmp10;
        PyObject *__tmp11 = PyTuple_GET_ITEM(cpy_r_r15, 1);
        CPyTagged __tmp12;
        if (likely(PyLong_Check(__tmp11)))
            __tmp12 = CPyTagged_FromObject(__tmp11);
        else {
            CPy_TypeError("int", __tmp11); __tmp12 = CPY_INT_TAG;
        }
        cpy_r_r16.f1 = __tmp12;
        PyObject *__tmp13 = PyTuple_GET_ITEM(cpy_r_r15, 2);
        CPy_INCREF(__tmp13);
        PyObject * __tmp14;
        if (likely(PyTuple_Check(__tmp13)))
            __tmp14 = __tmp13;
        else {
            CPy_TypeError("tuple", __tmp13); 
            __tmp14 = NULL;
        }
        cpy_r_r16.f2 = __tmp14;
    }
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 123, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r17 = cpy_r_r16.f2;
    CPy_INCREF(cpy_r_r17);
    CPyTagged_DECREF(cpy_r_r16.f0);
    CPyTagged_DECREF(cpy_r_r16.f1);
    CPy_DECREF(cpy_r_r16.f2);
    goto CPyL30;
CPyL10: ;
    cpy_r_r18 = CPy_CatchError();
    cpy_r_r19 = CPyModule_builtins;
    cpy_r_r20 = CPyStatics[23]; /* 'Exception' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 124, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r22 = CPy_ExceptionMatches(cpy_r_r21);
    CPy_DecRef(cpy_r_r21);
    if (!cpy_r_r22) goto CPyL26;
    cpy_r_r23 = CPy_GetExcValue();
    cpy_r_r24 = CPyStatics[8]; /* 'args' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL42;
    }
    if (likely(PyTuple_Check(cpy_r_r25)))
        cpy_r_r26 = cpy_r_r25;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals, "tuple", cpy_r_r25);
        goto CPyL42;
    }
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyStatics[10]; /* 'PartialResponse' */
    cpy_r_r29 = CPyDict_GetItem(cpy_r_r27, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r30 = PyObject_IsInstance(cpy_r_data, cpy_r_r29);
    CPy_DecRef(cpy_r_r29);
    cpy_r_r31 = cpy_r_r30 >= 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r32 = cpy_r_r30;
    if (!cpy_r_r32) goto CPyL19;
    cpy_r_r33 = CPyStatics[21]; /* 'decode_result' */
    PyObject *cpy_r_r34[1] = {cpy_r_data};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = PyObject_VectorcallMethod(cpy_r_r33, cpy_r_r35, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r37 = cpy_r_r36;
    goto CPyL20;
CPyL19: ;
    CPy_INCREF(cpy_r_data);
    cpy_r_r37 = cpy_r_data;
CPyL20: ;
    cpy_r_r38 = PyList_New(0);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r39 = CPyList_Extend(cpy_r_r38, cpy_r_r26);
    CPy_DecRef(cpy_r_r26);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL45;
    } else
        goto CPyL46;
CPyL22: ;
    cpy_r_r40 = PyList_Append(cpy_r_r38, cpy_r_r37);
    CPy_DecRef(cpy_r_r37);
    cpy_r_r41 = cpy_r_r40 >= 0;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r42 = PyList_AsTuple(cpy_r_r38);
    CPy_DecRef(cpy_r_r38);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r43 = CPyStatics[8]; /* 'args' */
    cpy_r_r44 = PyObject_SetAttr(cpy_r_r23, cpy_r_r43, cpy_r_r42);
    CPy_DecRef(cpy_r_r42);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_RestoreExcInfo(cpy_r_r18);
    CPy_DecRef(cpy_r_r18.f0);
    CPy_DecRef(cpy_r_r18.f1);
    CPy_DecRef(cpy_r_r18.f2);
    return cpy_r_r23;
CPyL26: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL28;
    } else
        goto CPyL48;
CPyL27: ;
    CPy_Unreachable();
CPyL28: ;
    CPy_RestoreExcInfo(cpy_r_r18);
    CPy_DecRef(cpy_r_r18.f0);
    CPy_DecRef(cpy_r_r18.f1);
    CPy_DecRef(cpy_r_r18.f2);
    cpy_r_r46 = CPy_KeepPropagating();
    if (!cpy_r_r46) goto CPyL38;
    CPy_Unreachable();
CPyL30: ;
    cpy_r_r47 = (CPyPtr)&((PyVarObject *)cpy_r_r17)->ob_size;
    cpy_r_r48 = *(int64_t *)cpy_r_r47;
    cpy_r_r49 = PyList_New(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 129, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r50 = 0;
CPyL32: ;
    cpy_r_r51 = (CPyPtr)&((PyVarObject *)cpy_r_r17)->ob_size;
    cpy_r_r52 = *(int64_t *)cpy_r_r51;
    cpy_r_r53 = cpy_r_r52 << 1;
    cpy_r_r54 = (Py_ssize_t)cpy_r_r50 < (Py_ssize_t)cpy_r_r53;
    if (!cpy_r_r54) goto CPyL50;
    cpy_r_r55 = CPySequenceTuple_GetItem(cpy_r_r17, cpy_r_r50);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 129, CPyStatic_globals);
        goto CPyL51;
    }
    PyObject *__tmp15;
    if (unlikely(!(PyTuple_Check(cpy_r_r55) && PyTuple_GET_SIZE(cpy_r_r55) == 2))) {
        __tmp15 = NULL;
        goto __LL16;
    }
    if (likely(PyBool_Check(PyTuple_GET_ITEM(cpy_r_r55, 0))))
        __tmp15 = PyTuple_GET_ITEM(cpy_r_r55, 0);
    else {
        __tmp15 = NULL;
    }
    if (__tmp15 == NULL) goto __LL16;
    if (likely(PyBytes_Check(PyTuple_GET_ITEM(cpy_r_r55, 1)) || PyByteArray_Check(PyTuple_GET_ITEM(cpy_r_r55, 1))))
        __tmp15 = PyTuple_GET_ITEM(cpy_r_r55, 1);
    else {
        __tmp15 = NULL;
    }
    if (__tmp15 == NULL) goto __LL16;
    __tmp15 = cpy_r_r55;
__LL16: ;
    if (unlikely(__tmp15 == NULL)) {
        CPy_TypeError("tuple[bool, bytes]", cpy_r_r55); cpy_r_r56 = (tuple_T2CO) { 2, NULL };
    } else {
        PyObject *__tmp17 = PyTuple_GET_ITEM(cpy_r_r55, 0);
        char __tmp18;
        if (unlikely(!PyBool_Check(__tmp17))) {
            CPy_TypeError("bool", __tmp17); __tmp18 = 2;
        } else
            __tmp18 = __tmp17 == Py_True;
        cpy_r_r56.f0 = __tmp18;
        PyObject *__tmp19 = PyTuple_GET_ITEM(cpy_r_r55, 1);
        CPy_INCREF(__tmp19);
        PyObject *__tmp20;
        if (likely(PyBytes_Check(__tmp19) || PyByteArray_Check(__tmp19)))
            __tmp20 = __tmp19;
        else {
            CPy_TypeError("bytes", __tmp19); 
            __tmp20 = NULL;
        }
        cpy_r_r56.f1 = __tmp20;
    }
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56.f0 == 2)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 129, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r57 = cpy_r_r56.f1;
    CPy_INCREF(cpy_r_r57);
    CPy_DECREF(cpy_r_r56.f1);
    cpy_r_r58 = CPyList_SetItemUnsafe(cpy_r_r49, cpy_r_r50, cpy_r_r57);
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 129, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r59 = cpy_r_r50 + 2;
    cpy_r_r50 = cpy_r_r59;
    goto CPyL32;
CPyL37: ;
    return cpy_r_r49;
CPyL38: ;
    cpy_r_r60 = NULL;
    return cpy_r_r60;
CPyL39: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL10;
CPyL40: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL5;
CPyL41: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL10;
CPyL42: ;
    CPy_DecRef(cpy_r_r23);
    goto CPyL28;
CPyL43: ;
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r26);
    goto CPyL28;
CPyL44: ;
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r37);
    goto CPyL28;
CPyL45: ;
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r38);
    goto CPyL28;
CPyL46: ;
    CPy_DecRef(cpy_r_r39);
    goto CPyL22;
CPyL47: ;
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r38);
    goto CPyL28;
CPyL48: ;
    CPy_DecRef(cpy_r_r18.f0);
    CPy_DecRef(cpy_r_r18.f1);
    CPy_DecRef(cpy_r_r18.f2);
    goto CPyL27;
CPyL49: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL38;
CPyL50: ;
    CPy_DECREF(cpy_r_r17);
    goto CPyL37;
CPyL51: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r49);
    goto CPyL38;
}

PyObject *CPyPy_mcall_decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:mcall_decode", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef_mcall_decode(arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 121, CPyStatic_globals);
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
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
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
    PyObject **cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    int32_t cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    tuple_T2OO cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    CPyPtr cpy_r_r72;
    CPyPtr cpy_r_r73;
    PyObject *cpy_r_r74;
    tuple_T2OO cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    int32_t cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    tuple_T2OO cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    tuple_T2OO cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    tuple_T3OOO cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    int32_t cpy_r_r107;
    char cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    tuple_T2OO cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    int32_t cpy_r_r121;
    char cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject **cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    int32_t cpy_r_r135;
    char cpy_r_r136;
    PyObject *cpy_r_r137;
    char cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    int32_t cpy_r_r145;
    char cpy_r_r146;
    PyObject *cpy_r_r147;
    char cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    int32_t cpy_r_r153;
    char cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    int32_t cpy_r_r159;
    char cpy_r_r160;
    PyObject *cpy_r_r161;
    char cpy_r_r162;
    PyObject *cpy_r_r163;
    int32_t cpy_r_r164;
    char cpy_r_r165;
    PyObject *cpy_r_r166;
    char cpy_r_r167;
    PyObject *cpy_r_r168;
    int32_t cpy_r_r169;
    char cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    char cpy_r_r175;
    PyObject *cpy_r_r176;
    int32_t cpy_r_r177;
    char cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    char cpy_r_r183;
    PyObject *cpy_r_r184;
    int32_t cpy_r_r185;
    char cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject **cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    int32_t cpy_r_r201;
    char cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    int32_t cpy_r_r206;
    char cpy_r_r207;
    char cpy_r_r208;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[24]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", -1, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[72]; /* ('accumulate', 'chain') */
    cpy_r_r6 = CPyStatics[25]; /* 'itertools' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 1, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_itertools = cpy_r_r8;
    CPy_INCREF(CPyModule_itertools);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[73]; /* ('Any', 'AnyStr', 'Callable', 'Final', 'Iterable', 'List',
                                  'Union', 'Tuple', 'TypeVar') */
    cpy_r_r10 = CPyStatics[35]; /* 'typing' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 2, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[74]; /* ('default_codec',) */
    cpy_r_r14 = CPyStatics[37]; /* 'eth_abi.abi' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 4, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_eth_abi___abi = cpy_r_r16;
    CPy_INCREF(CPyModule_eth_abi___abi);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[75]; /* ('ContextFramesBytesIO',) */
    cpy_r_r18 = CPyStatics[38]; /* 'eth_abi.decoding' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 5, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_eth_abi___decoding = cpy_r_r20;
    CPy_INCREF(CPyModule_eth_abi___decoding);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[76]; /* ('DynamicArrayEncoder', 'TupleEncoder', 'encode_uint_256') */
    cpy_r_r22 = CPyStatics[41]; /* 'eth_abi.encoding' */
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 6, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_eth_abi___encoding = cpy_r_r24;
    CPy_INCREF(CPyModule_eth_abi___encoding);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[77]; /* ('DecodeError', 'Raw') */
    cpy_r_r26 = CPyStatics[42]; /* 'msgspec' */
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyImport_ImportFromMany(cpy_r_r26, cpy_r_r25, cpy_r_r25, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 7, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_msgspec = cpy_r_r28;
    CPy_INCREF(CPyModule_msgspec);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r29 = CPyStatics[78]; /* ('decode',) */
    cpy_r_r30 = CPyStatics[79]; /* ('json_decode',) */
    cpy_r_r31 = CPyStatics[44]; /* 'msgspec.json' */
    cpy_r_r32 = CPyStatic_globals;
    cpy_r_r33 = CPyImport_ImportFromMany(cpy_r_r31, cpy_r_r29, cpy_r_r30, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 8, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_msgspec___json = cpy_r_r33;
    CPy_INCREF(CPyModule_msgspec___json);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r34 = CPyStatics[80]; /* ('encode',) */
    cpy_r_r35 = CPyStatics[81]; /* ('json_encode',) */
    cpy_r_r36 = CPyStatics[44]; /* 'msgspec.json' */
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyImport_ImportFromMany(cpy_r_r36, cpy_r_r34, cpy_r_r35, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 9, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_msgspec___json = cpy_r_r38;
    CPy_INCREF(CPyModule_msgspec___json);
    CPy_DECREF(cpy_r_r38);
    cpy_r_r39 = CPyStatics[82]; /* ('JSONRPCBatchResponseRaw', 'MulticallChunk',
                                   'PartialResponse', 'RawResponse', '_encode_hook') */
    cpy_r_r40 = CPyStatics[47]; /* 'dank_mids.types' */
    cpy_r_r41 = CPyStatic_globals;
    cpy_r_r42 = CPyImport_ImportFromMany(cpy_r_r40, cpy_r_r39, cpy_r_r39, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 11, CPyStatic_globals);
        goto CPyL80;
    }
    CPyModule_dank_mids___types = cpy_r_r42;
    CPy_INCREF(CPyModule_dank_mids___types);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r43 = CPyStatics[48]; /* '__T' */
    cpy_r_r44 = CPyStatic_globals;
    cpy_r_r45 = CPyStatics[34]; /* 'TypeVar' */
    cpy_r_r46 = CPyDict_GetItem(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 20, CPyStatic_globals);
        goto CPyL80;
    }
    PyObject *cpy_r_r47[1] = {cpy_r_r43};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = _PyObject_Vectorcall(cpy_r_r46, cpy_r_r48, 1, 0);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 20, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r50 = CPyStatic_globals;
    cpy_r_r51 = CPyStatics[48]; /* '__T' */
    cpy_r_r52 = CPyDict_SetItem(cpy_r_r50, cpy_r_r51, cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    cpy_r_r53 = cpy_r_r52 >= 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 20, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r54 = CPyStatic_globals;
    cpy_r_r55 = CPyStatics[28]; /* 'Callable' */
    cpy_r_r56 = CPyDict_GetItem(cpy_r_r54, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r57 = CPyStatic_globals;
    cpy_r_r58 = CPyStatics[33]; /* 'Tuple' */
    cpy_r_r59 = CPyDict_GetItem(cpy_r_r57, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r60 = (PyObject *)&PyBool_Type;
    cpy_r_r61 = CPyStatic_globals;
    cpy_r_r62 = CPyStatics[30]; /* 'Iterable' */
    cpy_r_r63 = CPyDict_GetItem(cpy_r_r61, cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r64 = CPyStatic_globals;
    cpy_r_r65 = CPyStatics[46]; /* 'MulticallChunk' */
    cpy_r_r66 = CPyDict_GetItem(cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r67 = PyObject_GetItem(cpy_r_r63, cpy_r_r66);
    CPy_DECREF(cpy_r_r63);
    CPy_DECREF(cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_r60);
    cpy_r_r68.f0 = cpy_r_r60;
    cpy_r_r68.f1 = cpy_r_r67;
    cpy_r_r69 = PyTuple_New(2);
    if (unlikely(cpy_r_r69 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp21 = cpy_r_r68.f0;
    PyTuple_SET_ITEM(cpy_r_r69, 0, __tmp21);
    PyObject *__tmp22 = cpy_r_r68.f1;
    PyTuple_SET_ITEM(cpy_r_r69, 1, __tmp22);
    cpy_r_r70 = PyObject_GetItem(cpy_r_r59, cpy_r_r69);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r71 = PyList_New(1);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r72 = (CPyPtr)&((PyListObject *)cpy_r_r71)->ob_item;
    cpy_r_r73 = *(CPyPtr *)cpy_r_r72;
    *(PyObject * *)cpy_r_r73 = cpy_r_r70;
    cpy_r_r74 = (PyObject *)&PyBytes_Type;
    CPy_INCREF(cpy_r_r74);
    cpy_r_r75.f0 = cpy_r_r71;
    cpy_r_r75.f1 = cpy_r_r74;
    cpy_r_r76 = PyTuple_New(2);
    if (unlikely(cpy_r_r76 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp23 = cpy_r_r75.f0;
    PyTuple_SET_ITEM(cpy_r_r76, 0, __tmp23);
    PyObject *__tmp24 = cpy_r_r75.f1;
    PyTuple_SET_ITEM(cpy_r_r76, 1, __tmp24);
    cpy_r_r77 = PyObject_GetItem(cpy_r_r56, cpy_r_r76);
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r78 = CPyStatic_globals;
    cpy_r_r79 = CPyStatics[49]; /* 'MulticallEncoder' */
    cpy_r_r80 = CPyDict_SetItem(cpy_r_r78, cpy_r_r79, cpy_r_r77);
    CPy_DECREF(cpy_r_r77);
    cpy_r_r81 = cpy_r_r80 >= 0;
    if (unlikely(!cpy_r_r81)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r82 = CPyStatic_globals;
    cpy_r_r83 = CPyStatics[33]; /* 'Tuple' */
    cpy_r_r84 = CPyDict_GetItem(cpy_r_r82, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r85 = (PyObject *)&PyLong_Type;
    cpy_r_r86 = (PyObject *)&PyLong_Type;
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyStatics[33]; /* 'Tuple' */
    cpy_r_r89 = CPyDict_GetItem(cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r90 = CPyStatic_globals;
    cpy_r_r91 = CPyStatics[33]; /* 'Tuple' */
    cpy_r_r92 = CPyDict_GetItem(cpy_r_r90, cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r93 = CPyStatics[50]; /* 'Success' */
    cpy_r_r94 = (PyObject *)&PyBytes_Type;
    CPy_INCREF(cpy_r_r93);
    CPy_INCREF(cpy_r_r94);
    cpy_r_r95.f0 = cpy_r_r93;
    cpy_r_r95.f1 = cpy_r_r94;
    cpy_r_r96 = PyTuple_New(2);
    if (unlikely(cpy_r_r96 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp25 = cpy_r_r95.f0;
    PyTuple_SET_ITEM(cpy_r_r96, 0, __tmp25);
    PyObject *__tmp26 = cpy_r_r95.f1;
    PyTuple_SET_ITEM(cpy_r_r96, 1, __tmp26);
    cpy_r_r97 = PyObject_GetItem(cpy_r_r92, cpy_r_r96);
    CPy_DECREF(cpy_r_r92);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r98 = (PyObject *)&_Py_EllipsisObject;
    CPy_INCREF(cpy_r_r98);
    cpy_r_r99.f0 = cpy_r_r97;
    cpy_r_r99.f1 = cpy_r_r98;
    cpy_r_r100 = PyTuple_New(2);
    if (unlikely(cpy_r_r100 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp27 = cpy_r_r99.f0;
    PyTuple_SET_ITEM(cpy_r_r100, 0, __tmp27);
    PyObject *__tmp28 = cpy_r_r99.f1;
    PyTuple_SET_ITEM(cpy_r_r100, 1, __tmp28);
    cpy_r_r101 = PyObject_GetItem(cpy_r_r89, cpy_r_r100);
    CPy_DECREF(cpy_r_r89);
    CPy_DECREF(cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_INCREF(cpy_r_r85);
    CPy_INCREF(cpy_r_r86);
    cpy_r_r102.f0 = cpy_r_r85;
    cpy_r_r102.f1 = cpy_r_r86;
    cpy_r_r102.f2 = cpy_r_r101;
    cpy_r_r103 = PyTuple_New(3);
    if (unlikely(cpy_r_r103 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp29 = cpy_r_r102.f0;
    PyTuple_SET_ITEM(cpy_r_r103, 0, __tmp29);
    PyObject *__tmp30 = cpy_r_r102.f1;
    PyTuple_SET_ITEM(cpy_r_r103, 1, __tmp30);
    PyObject *__tmp31 = cpy_r_r102.f2;
    PyTuple_SET_ITEM(cpy_r_r103, 2, __tmp31);
    cpy_r_r104 = PyObject_GetItem(cpy_r_r84, cpy_r_r103);
    CPy_DECREF(cpy_r_r84);
    CPy_DECREF(cpy_r_r103);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r105 = CPyStatic_globals;
    cpy_r_r106 = CPyStatics[51]; /* 'DecodedMulticall' */
    cpy_r_r107 = CPyDict_SetItem(cpy_r_r105, cpy_r_r106, cpy_r_r104);
    CPy_DECREF(cpy_r_r104);
    cpy_r_r108 = cpy_r_r107 >= 0;
    if (unlikely(!cpy_r_r108)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r109 = CPyStatic_globals;
    cpy_r_r110 = CPyStatics[28]; /* 'Callable' */
    cpy_r_r111 = CPyDict_GetItem(cpy_r_r109, cpy_r_r110);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 26, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r112 = (PyObject *)&_Py_EllipsisObject;
    cpy_r_r113 = CPyStatic_globals;
    cpy_r_r114 = CPyStatics[51]; /* 'DecodedMulticall' */
    cpy_r_r115 = CPyDict_GetItem(cpy_r_r113, cpy_r_r114);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 26, CPyStatic_globals);
        goto CPyL87;
    }
    CPy_INCREF(cpy_r_r112);
    cpy_r_r116.f0 = cpy_r_r112;
    cpy_r_r116.f1 = cpy_r_r115;
    cpy_r_r117 = PyTuple_New(2);
    if (unlikely(cpy_r_r117 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp32 = cpy_r_r116.f0;
    PyTuple_SET_ITEM(cpy_r_r117, 0, __tmp32);
    PyObject *__tmp33 = cpy_r_r116.f1;
    PyTuple_SET_ITEM(cpy_r_r117, 1, __tmp33);
    cpy_r_r118 = PyObject_GetItem(cpy_r_r111, cpy_r_r117);
    CPy_DECREF(cpy_r_r111);
    CPy_DECREF(cpy_r_r117);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 26, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r119 = CPyStatic_globals;
    cpy_r_r120 = CPyStatics[52]; /* 'MulticallDecoder' */
    cpy_r_r121 = CPyDict_SetItem(cpy_r_r119, cpy_r_r120, cpy_r_r118);
    CPy_DECREF(cpy_r_r118);
    cpy_r_r122 = cpy_r_r121 >= 0;
    if (unlikely(!cpy_r_r122)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 26, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r123 = CPyStatic_globals;
    cpy_r_r124 = CPyStatics[36]; /* 'default_codec' */
    cpy_r_r125 = CPyDict_GetItem(cpy_r_r123, cpy_r_r124);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 80, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r126 = CPyStatics[53]; /* '_registry' */
    cpy_r_r127 = CPyObject_GetAttr(cpy_r_r125, cpy_r_r126);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 80, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r128 = CPyStatics[54]; /* '(bool,(address,bytes)[])' */
    cpy_r_r129 = CPyStatics[55]; /* 'get_encoder' */
    PyObject *cpy_r_r130[2] = {cpy_r_r127, cpy_r_r128};
    cpy_r_r131 = (PyObject **)&cpy_r_r130;
    cpy_r_r132 = PyObject_VectorcallMethod(cpy_r_r129, cpy_r_r131, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 80, CPyStatic_globals);
        goto CPyL88;
    }
    CPy_DECREF(cpy_r_r127);
    CPyStatic__mcall_encoder = cpy_r_r132;
    CPy_INCREF(CPyStatic__mcall_encoder);
    cpy_r_r133 = CPyStatic_globals;
    cpy_r_r134 = CPyStatics[56]; /* '_mcall_encoder' */
    cpy_r_r135 = CPyDict_SetItem(cpy_r_r133, cpy_r_r134, cpy_r_r132);
    CPy_DECREF(cpy_r_r132);
    cpy_r_r136 = cpy_r_r135 >= 0;
    if (unlikely(!cpy_r_r136)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 80, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r137 = CPyStatic__mcall_encoder;
    if (likely(cpy_r_r137 != NULL)) goto CPyL42;
    PyErr_SetString(PyExc_NameError, "value for final name \"_mcall_encoder\" was not set");
    cpy_r_r138 = 0;
    if (unlikely(!cpy_r_r138)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 83, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_Unreachable();
CPyL42: ;
    cpy_r_r139 = CPyStatics[57]; /* 'encoders' */
    cpy_r_r140 = CPyObject_GetAttr(cpy_r_r137, cpy_r_r139);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 83, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r141 = CPyStatics[69]; /* -1 */
    cpy_r_r142 = PyObject_GetItem(cpy_r_r140, cpy_r_r141);
    CPy_DECREF(cpy_r_r140);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 83, CPyStatic_globals);
        goto CPyL80;
    }
    CPyStatic__array_encoder = cpy_r_r142;
    CPy_INCREF(CPyStatic__array_encoder);
    cpy_r_r143 = CPyStatic_globals;
    cpy_r_r144 = CPyStatics[58]; /* '_array_encoder' */
    cpy_r_r145 = CPyDict_SetItem(cpy_r_r143, cpy_r_r144, cpy_r_r142);
    CPy_DECREF(cpy_r_r142);
    cpy_r_r146 = cpy_r_r145 >= 0;
    if (unlikely(!cpy_r_r146)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 83, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r147 = CPyStatic__array_encoder;
    if (likely(cpy_r_r147 != NULL)) goto CPyL48;
    PyErr_SetString(PyExc_NameError, "value for final name \"_array_encoder\" was not set");
    cpy_r_r148 = 0;
    if (unlikely(!cpy_r_r148)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 84, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_Unreachable();
CPyL48: ;
    cpy_r_r149 = CPyStatics[59]; /* 'item_encoder' */
    cpy_r_r150 = CPyObject_GetAttr(cpy_r_r147, cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 84, CPyStatic_globals);
        goto CPyL80;
    }
    CPyStatic__item_encoder = cpy_r_r150;
    CPy_INCREF(CPyStatic__item_encoder);
    cpy_r_r151 = CPyStatic_globals;
    cpy_r_r152 = CPyStatics[60]; /* '_item_encoder' */
    cpy_r_r153 = CPyDict_SetItem(cpy_r_r151, cpy_r_r152, cpy_r_r150);
    CPy_DECREF(cpy_r_r150);
    cpy_r_r154 = cpy_r_r153 >= 0;
    if (unlikely(!cpy_r_r154)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 84, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r155 = CPyDef___mypyc_lambda__0_obj();
    if (unlikely(cpy_r_r155 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 87, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r156 = CPyStatic__mcall_encoder;
    if (unlikely(cpy_r_r156 == NULL)) {
        goto CPyL89;
    } else
        goto CPyL54;
CPyL52: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_mcall_encoder\" was not set");
    cpy_r_r157 = 0;
    if (unlikely(!cpy_r_r157)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 87, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_Unreachable();
CPyL54: ;
    cpy_r_r158 = CPyStatics[61]; /* 'validate_value' */
    cpy_r_r159 = PyObject_SetAttr(cpy_r_r156, cpy_r_r158, cpy_r_r155);
    cpy_r_r160 = cpy_r_r159 >= 0;
    if (unlikely(!cpy_r_r160)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 87, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r161 = CPyStatic__array_encoder;
    if (unlikely(cpy_r_r161 == NULL)) {
        goto CPyL91;
    } else
        goto CPyL58;
CPyL56: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_array_encoder\" was not set");
    cpy_r_r162 = 0;
    if (unlikely(!cpy_r_r162)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 87, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_Unreachable();
CPyL58: ;
    cpy_r_r163 = CPyStatics[61]; /* 'validate_value' */
    cpy_r_r164 = PyObject_SetAttr(cpy_r_r161, cpy_r_r163, cpy_r_r155);
    cpy_r_r165 = cpy_r_r164 >= 0;
    if (unlikely(!cpy_r_r165)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 87, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r166 = CPyStatic__item_encoder;
    if (unlikely(cpy_r_r166 == NULL)) {
        goto CPyL92;
    } else
        goto CPyL62;
CPyL60: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_item_encoder\" was not set");
    cpy_r_r167 = 0;
    if (unlikely(!cpy_r_r167)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 87, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_Unreachable();
CPyL62: ;
    cpy_r_r168 = CPyStatics[61]; /* 'validate_value' */
    cpy_r_r169 = PyObject_SetAttr(cpy_r_r166, cpy_r_r168, cpy_r_r155);
    CPy_DECREF(cpy_r_r155);
    cpy_r_r170 = cpy_r_r169 >= 0;
    if (unlikely(!cpy_r_r170)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 87, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r171 = CPyStatic_globals;
    cpy_r_r172 = CPyStatics[62]; /* '__encode_new' */
    cpy_r_r173 = CPyDict_GetItem(cpy_r_r171, cpy_r_r172);
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 104, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r174 = CPyStatic__array_encoder;
    if (unlikely(cpy_r_r174 == NULL)) {
        goto CPyL93;
    } else
        goto CPyL67;
CPyL65: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_array_encoder\" was not set");
    cpy_r_r175 = 0;
    if (unlikely(!cpy_r_r175)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 104, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_Unreachable();
CPyL67: ;
    cpy_r_r176 = CPyStatics[45]; /* 'encode' */
    cpy_r_r177 = PyObject_SetAttr(cpy_r_r174, cpy_r_r176, cpy_r_r173);
    CPy_DECREF(cpy_r_r173);
    cpy_r_r178 = cpy_r_r177 >= 0;
    if (unlikely(!cpy_r_r178)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 104, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r179 = CPyStatic_globals;
    cpy_r_r180 = CPyStatics[63]; /* '__encode_elements_new' */
    cpy_r_r181 = CPyDict_GetItem(cpy_r_r179, cpy_r_r180);
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 105, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r182 = CPyStatic__array_encoder;
    if (unlikely(cpy_r_r182 == NULL)) {
        goto CPyL94;
    } else
        goto CPyL72;
CPyL70: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_array_encoder\" was not set");
    cpy_r_r183 = 0;
    if (unlikely(!cpy_r_r183)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 105, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_Unreachable();
CPyL72: ;
    cpy_r_r184 = CPyStatics[64]; /* 'encode_elements' */
    cpy_r_r185 = PyObject_SetAttr(cpy_r_r182, cpy_r_r184, cpy_r_r181);
    CPy_DECREF(cpy_r_r181);
    cpy_r_r186 = cpy_r_r185 >= 0;
    if (unlikely(!cpy_r_r186)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 105, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r187 = CPyStatic_globals;
    cpy_r_r188 = CPyStatics[36]; /* 'default_codec' */
    cpy_r_r189 = CPyDict_GetItem(cpy_r_r187, cpy_r_r188);
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 108, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r190 = CPyStatics[53]; /* '_registry' */
    cpy_r_r191 = CPyObject_GetAttr(cpy_r_r189, cpy_r_r190);
    CPy_DECREF(cpy_r_r189);
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 108, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r192 = CPyStatics[65]; /* '(uint256,uint256,(bool,bytes)[])' */
    cpy_r_r193 = CPyStatics[66]; /* 'get_decoder' */
    PyObject *cpy_r_r194[2] = {cpy_r_r191, cpy_r_r192};
    cpy_r_r195 = (PyObject **)&cpy_r_r194;
    cpy_r_r196 = PyObject_VectorcallMethod(cpy_r_r193, cpy_r_r195, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 108, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_DECREF(cpy_r_r191);
    cpy_r_r197 = CPyStatics[43]; /* 'decode' */
    cpy_r_r198 = CPyObject_GetAttr(cpy_r_r196, cpy_r_r197);
    CPy_DECREF(cpy_r_r196);
    if (unlikely(cpy_r_r198 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 108, CPyStatic_globals);
        goto CPyL80;
    }
    CPyStatic__mcall_decoder = cpy_r_r198;
    CPy_INCREF(CPyStatic__mcall_decoder);
    cpy_r_r199 = CPyStatic_globals;
    cpy_r_r200 = CPyStatics[67]; /* '_mcall_decoder' */
    cpy_r_r201 = CPyDict_SetItem(cpy_r_r199, cpy_r_r200, cpy_r_r198);
    CPy_DECREF(cpy_r_r198);
    cpy_r_r202 = cpy_r_r201 >= 0;
    if (unlikely(!cpy_r_r202)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 108, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r203 = (PyObject *)&PyBool_Type;
    cpy_r_r204 = CPyStatic_globals;
    cpy_r_r205 = CPyStatics[50]; /* 'Success' */
    cpy_r_r206 = CPyDict_SetItem(cpy_r_r204, cpy_r_r205, cpy_r_r203);
    cpy_r_r207 = cpy_r_r206 >= 0;
    if (unlikely(!cpy_r_r207)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 118, CPyStatic_globals);
        goto CPyL80;
    }
    return 1;
CPyL80: ;
    cpy_r_r208 = 2;
    return cpy_r_r208;
CPyL81: ;
    CPy_DecRef(cpy_r_r56);
    goto CPyL80;
CPyL82: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r59);
    goto CPyL80;
CPyL83: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r59);
    CPy_DecRef(cpy_r_r63);
    goto CPyL80;
CPyL84: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r70);
    goto CPyL80;
CPyL85: ;
    CPy_DecRef(cpy_r_r84);
    goto CPyL80;
CPyL86: ;
    CPy_DecRef(cpy_r_r84);
    CPy_DecRef(cpy_r_r89);
    goto CPyL80;
CPyL87: ;
    CPy_DecRef(cpy_r_r111);
    goto CPyL80;
CPyL88: ;
    CPy_DecRef(cpy_r_r127);
    goto CPyL80;
CPyL89: ;
    CPy_DecRef(cpy_r_r155);
    goto CPyL52;
CPyL90: ;
    CPy_DecRef(cpy_r_r155);
    goto CPyL80;
CPyL91: ;
    CPy_DecRef(cpy_r_r155);
    goto CPyL56;
CPyL92: ;
    CPy_DecRef(cpy_r_r155);
    goto CPyL60;
CPyL93: ;
    CPy_DecRef(cpy_r_r173);
    goto CPyL65;
CPyL94: ;
    CPy_DecRef(cpy_r_r181);
    goto CPyL70;
CPyL95: ;
    CPy_DecRef(cpy_r_r191);
    goto CPyL80;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___helpers____codec = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_itertools = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_eth_abi___abi = Py_None;
    CPyModule_eth_abi___decoding = Py_None;
    CPyModule_eth_abi___encoding = Py_None;
    CPyModule_msgspec = Py_None;
    CPyModule_msgspec___json = Py_None;
    CPyModule_dank_mids___types = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[83];
const char * const CPyLit_Str[] = {
    "\006\003Raw\vjson_decode\004type\vRawResponse\vDecodeError\004args",
    "\005\027JSONRPCBatchResponseRaw\017PartialResponse\003map\f_encode_hook\vjson_encode",
    "\a\benc_hook\017encode_uint_256\003len\naccumulate\005chain\a__add__\beth_call",
    "\006\rdecode_result\024ContextFramesBytesIO\tException\bbuiltins\titertools\003Any",
    "\t\006AnyStr\bCallable\005Final\bIterable\004List\005Union\005Tuple\aTypeVar\006typing",
    "\004\rdefault_codec\veth_abi.abi\020eth_abi.decoding\023DynamicArrayEncoder",
    "\006\fTupleEncoder\020eth_abi.encoding\amsgspec\006decode\fmsgspec.json\006encode",
    "\005\016MulticallChunk\017dank_mids.types\003__T\020MulticallEncoder\aSuccess",
    "\004\020DecodedMulticall\020MulticallDecoder\t_registry\030(bool,(address,bytes)[])",
    "\005\vget_encoder\016_mcall_encoder\bencoders\016_array_encoder\fitem_encoder",
    "\004\r_item_encoder\016validate_value\f__encode_new\025__encode_elements_new",
    "\003\017encode_elements (uint256,uint256,(bool,bytes)[])\vget_decoder",
    "\001\016_mcall_decoder",
    "",
};
const char * const CPyLit_Bytes[] = {
    "\001\000",
    "",
};
const char * const CPyLit_Int[] = {
    "\001-1",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    13, 1, 5, 1, 14, 2, 17, 18, 9, 26, 27, 28, 29, 30, 31, 32, 33, 34,
    1, 36, 1, 22, 3, 39, 40, 15, 2, 7, 3, 1, 43, 1, 4, 1, 45, 1, 13, 5, 9,
    46, 10, 6, 12
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___helpers____codec_internal = NULL;
CPyModule *CPyModule_dank_mids___helpers____codec;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_itertools;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_eth_abi___abi;
CPyModule *CPyModule_eth_abi___decoding;
CPyModule *CPyModule_eth_abi___encoding;
CPyModule *CPyModule_msgspec;
CPyModule *CPyModule_msgspec___json;
CPyModule *CPyModule_dank_mids___types;
PyObject *CPyStatic__mcall_encoder = NULL;
PyObject *CPyStatic__array_encoder = NULL;
PyObject *CPyStatic__item_encoder = NULL;
PyObject *CPyStatic__mcall_decoder = NULL;
PyTypeObject *CPyType___mypyc_lambda__0_obj;
PyObject *CPyDef___mypyc_lambda__0_obj(void);
PyObject *CPyDef_decode_raw(PyObject *cpy_r_data);
PyObject *CPyPy_decode_raw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_jsonrpc_batch(PyObject *cpy_r_data);
PyObject *CPyPy_decode_jsonrpc_batch(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode(PyObject *cpy_r_obj);
PyObject *CPyPy_encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__0_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__0_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__0_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r__);
PyObject *CPyPy___mypyc_lambda__0_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___encode_new(PyObject *cpy_r_values);
PyObject *CPyPy___encode_new(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
tuple_T2OI CPyDef___encode_elements_new(PyObject *cpy_r_values);
PyObject *CPyPy___encode_elements_new(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_mcall_encode(PyObject *cpy_r_data);
PyObject *CPyPy_mcall_encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_mcall_decode(PyObject *cpy_r_data);
PyObject *CPyPy_mcall_decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids___helpers____codec exports = {
    &CPyStatic__mcall_encoder,
    &CPyStatic__array_encoder,
    &CPyStatic__item_encoder,
    &CPyStatic__mcall_decoder,
    &CPyType___mypyc_lambda__0_obj,
    &CPyDef___mypyc_lambda__0_obj,
    &CPyDef_decode_raw,
    &CPyDef_decode_jsonrpc_batch,
    &CPyDef_encode,
    &CPyDef___mypyc_lambda__0_obj_____get__,
    &CPyDef___mypyc_lambda__0_obj_____call__,
    &CPyDef___encode_new,
    &CPyDef___encode_elements_new,
    &CPyDef_mcall_encode,
    &CPyDef_mcall_decode,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit__codec__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids.helpers._codec__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids.helpers._codec__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids___helpers____codec(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids___helpers____codec, "dank_mids.helpers._codec__mypyc.init_dank_mids___helpers____codec", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids___helpers____codec", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
