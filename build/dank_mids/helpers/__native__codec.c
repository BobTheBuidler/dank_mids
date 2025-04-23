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
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
__mypyc_lambda__0_obj_clear(dank_mids___helpers____codec_____mypyc_lambda__0_objObject *self)
{
    PyObject_ClearManagedDict((PyObject *)self);
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
    .tp_basicsize = sizeof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject),
    .tp_vectorcall_offset = offsetof(dank_mids___helpers____codec_____mypyc_lambda__0_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
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
    CPy_XDECREF(CPyStatic_Raw);
    CPyStatic_Raw = NULL;
    CPy_XDECREF(CPyStatic_RawResponse);
    CPyStatic_RawResponse = NULL;
    CPy_XDECREF(CPyStatic_ContextFramesBytesIO);
    CPyStatic_ContextFramesBytesIO = NULL;
    CPy_XDECREF(CPyStatic_DecodeError);
    CPyStatic_DecodeError = NULL;
    CPy_XDECREF(CPyStatic_json_encode);
    CPyStatic_json_encode = NULL;
    CPy_XDECREF(CPyStatic_json_decode);
    CPyStatic_json_decode = NULL;
    CPy_XDECREF(CPyStatic_encode_uint_256);
    CPyStatic_encode_uint_256 = NULL;
    CPy_XDECREF(CPyStatic__encode_hook);
    CPyStatic__encode_hook = NULL;
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
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    tuple_T3OOO cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    cpy_r_r0 = CPyStatic_Raw;
    if (likely(cpy_r_r0 != NULL)) goto CPyL4;
    PyErr_SetString(PyExc_NameError, "value for final name \"Raw\" was not set");
    cpy_r_r1 = 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 45, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r2 = CPyStatic_json_decode;
    if (likely(cpy_r_r2 != NULL)) goto CPyL7;
    PyErr_SetString(PyExc_NameError, "value for final name \"json_decode\" was not set");
    cpy_r_r3 = 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 45, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL7: ;
    PyObject *cpy_r_r4[2] = {cpy_r_data, cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = CPyStatics[74]; /* ('type',) */
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r5, 1, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 45, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r8 = CPyStatic_RawResponse;
    if (unlikely(cpy_r_r8 == NULL)) {
        goto CPyL30;
    } else
        goto CPyL11;
CPyL9: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"RawResponse\" was not set");
    cpy_r_r9 = 0;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 45, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL11: ;
    PyObject *cpy_r_r10[1] = {cpy_r_r7};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = _PyObject_Vectorcall(cpy_r_r8, cpy_r_r11, 1, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 45, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_DECREF(cpy_r_r7);
    return cpy_r_r12;
CPyL13: ;
    cpy_r_r13 = CPy_CatchError();
    cpy_r_r14 = CPyStatic_DecodeError;
    if (likely(cpy_r_r14 != NULL)) goto CPyL16;
    PyErr_SetString(PyExc_NameError, "value for final name \"DecodeError\" was not set");
    cpy_r_r15 = 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 46, CPyStatic_globals);
        goto CPyL27;
    } else
        goto CPyL32;
CPyL15: ;
    CPy_Unreachable();
CPyL16: ;
    cpy_r_r16 = CPy_ExceptionMatches(cpy_r_r14);
    if (!cpy_r_r16) goto CPyL25;
    cpy_r_r17 = CPy_GetExcValue();
    cpy_r_r18 = CPyStatics[4]; /* 'args' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 47, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r20 = PyList_New(0);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 47, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r21 = CPyList_Extend(cpy_r_r20, cpy_r_r19);
    CPy_DecRef(cpy_r_r19);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 47, CPyStatic_globals);
        goto CPyL35;
    } else
        goto CPyL36;
CPyL20: ;
    cpy_r_r22 = PyList_Append(cpy_r_r20, cpy_r_data);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 47, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r24 = PyList_AsTuple(cpy_r_r20);
    CPy_DecRef(cpy_r_r20);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 47, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r25 = CPyStatics[4]; /* 'args' */
    cpy_r_r26 = PyObject_SetAttr(cpy_r_r17, cpy_r_r25, cpy_r_r24);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r24);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 47, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_Reraise();
    if (!0) {
        goto CPyL27;
    } else
        goto CPyL37;
CPyL24: ;
    CPy_Unreachable();
CPyL25: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL27;
    } else
        goto CPyL38;
CPyL26: ;
    CPy_Unreachable();
CPyL27: ;
    CPy_RestoreExcInfo(cpy_r_r13);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r13.f2);
    cpy_r_r28 = CPy_KeepPropagating();
    if (!cpy_r_r28) goto CPyL29;
    CPy_Unreachable();
CPyL29: ;
    cpy_r_r29 = NULL;
    return cpy_r_r29;
CPyL30: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL9;
CPyL31: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL13;
CPyL32: ;
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r13.f2);
    goto CPyL15;
CPyL33: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL27;
CPyL34: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r19);
    goto CPyL27;
CPyL35: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r20);
    goto CPyL27;
CPyL36: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL20;
CPyL37: ;
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r13.f2);
    goto CPyL24;
CPyL38: ;
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r13.f2);
    goto CPyL26;
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
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_raw", 34, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_jsonrpc_batch(PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    CPyPtr cpy_r_r14;
    int64_t cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyTagged cpy_r_r17;
    CPyPtr cpy_r_r18;
    int64_t cpy_r_r19;
    CPyTagged cpy_r_r20;
    char cpy_r_r21;
    int64_t cpy_r_r22;
    CPyPtr cpy_r_r23;
    CPyPtr cpy_r_r24;
    int64_t cpy_r_r25;
    CPyPtr cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject **cpy_r_r31;
    PyObject *cpy_r_r32;
    char cpy_r_r33;
    CPyTagged cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[5]; /* 'JSONRPCBatchResponseRaw' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 61, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r3 = CPyStatic_json_decode;
    if (unlikely(cpy_r_r3 == NULL)) {
        goto CPyL21;
    } else
        goto CPyL4;
CPyL2: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"json_decode\" was not set");
    cpy_r_r4 = 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 61, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_Unreachable();
CPyL4: ;
    PyObject *cpy_r_r5[2] = {cpy_r_data, cpy_r_r2};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = CPyStatics[74]; /* ('type',) */
    cpy_r_r8 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r6, 1, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 61, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r9 = (PyObject *)&PyList_Type;
    cpy_r_r10 = PyObject_IsInstance(cpy_r_r8, cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 62, CPyStatic_globals);
        goto CPyL23;
    }
    cpy_r_r12 = cpy_r_r10;
    if (!cpy_r_r12) goto CPyL18;
    if (likely(PyList_Check(cpy_r_r8)))
        cpy_r_r13 = cpy_r_r8;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 62, CPyStatic_globals, "list", cpy_r_r8);
        goto CPyL20;
    }
    cpy_r_r14 = (CPyPtr)&((PyVarObject *)cpy_r_r13)->ob_size;
    cpy_r_r15 = *(int64_t *)cpy_r_r14;
    cpy_r_r16 = PyList_New(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 62, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r17 = 0;
CPyL10: ;
    cpy_r_r18 = (CPyPtr)&((PyVarObject *)cpy_r_r13)->ob_size;
    cpy_r_r19 = *(int64_t *)cpy_r_r18;
    cpy_r_r20 = cpy_r_r19 << 1;
    cpy_r_r21 = (Py_ssize_t)cpy_r_r17 < (Py_ssize_t)cpy_r_r20;
    if (!cpy_r_r21) goto CPyL25;
    cpy_r_r22 = (Py_ssize_t)cpy_r_r17 >> 1;
    cpy_r_r23 = (CPyPtr)&((PyListObject *)cpy_r_r13)->ob_item;
    cpy_r_r24 = *(CPyPtr *)cpy_r_r23;
    cpy_r_r25 = cpy_r_r22 * 8;
    cpy_r_r26 = cpy_r_r24 + cpy_r_r25;
    cpy_r_r27 = *(PyObject * *)cpy_r_r26;
    CPy_INCREF(cpy_r_r27);
    cpy_r_r28 = CPyStatic_RawResponse;
    if (unlikely(cpy_r_r28 == NULL)) {
        goto CPyL26;
    } else
        goto CPyL14;
CPyL12: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"RawResponse\" was not set");
    cpy_r_r29 = 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 62, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_Unreachable();
CPyL14: ;
    PyObject *cpy_r_r30[1] = {cpy_r_r27};
    cpy_r_r31 = (PyObject **)&cpy_r_r30;
    cpy_r_r32 = _PyObject_Vectorcall(cpy_r_r28, cpy_r_r31, 1, 0);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 62, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r27);
    cpy_r_r33 = CPyList_SetItemUnsafe(cpy_r_r16, cpy_r_r17, cpy_r_r32);
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 62, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r34 = cpy_r_r17 + 2;
    cpy_r_r17 = cpy_r_r34;
    goto CPyL10;
CPyL17: ;
    cpy_r_r35 = cpy_r_r16;
    goto CPyL19;
CPyL18: ;
    cpy_r_r35 = cpy_r_r8;
CPyL19: ;
    return cpy_r_r35;
CPyL20: ;
    cpy_r_r36 = NULL;
    return cpy_r_r36;
CPyL21: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL2;
CPyL22: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL20;
CPyL23: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL20;
CPyL24: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL20;
CPyL25: ;
    CPy_DECREF(cpy_r_r13);
    goto CPyL17;
CPyL26: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r27);
    goto CPyL12;
CPyL27: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r27);
    goto CPyL20;
CPyL28: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r16);
    goto CPyL20;
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
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "decode_jsonrpc_batch", 51, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode(PyObject *cpy_r_obj) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    cpy_r_r0 = CPyStatic__encode_hook;
    if (likely(cpy_r_r0 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"_encode_hook\" was not set");
    cpy_r_r1 = 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "encode", 80, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r2 = CPyStatic_json_encode;
    if (likely(cpy_r_r2 != NULL)) goto CPyL6;
    PyErr_SetString(PyExc_NameError, "value for final name \"json_encode\" was not set");
    cpy_r_r3 = 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "encode", 80, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_Unreachable();
CPyL6: ;
    PyObject *cpy_r_r4[2] = {cpy_r_obj, cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = CPyStatics[75]; /* ('enc_hook',) */
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r5, 1, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "encode", 80, CPyStatic_globals);
        goto CPyL9;
    }
    if (likely(PyBytes_Check(cpy_r_r7) || PyByteArray_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "encode", 80, CPyStatic_globals, "bytes", cpy_r_r7);
        goto CPyL9;
    }
    return cpy_r_r8;
CPyL9: ;
    cpy_r_r9 = NULL;
    return cpy_r_r9;
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
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "encode", 65, CPyStatic_globals);
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
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "<lambda>", 92, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___encode_new(PyObject *cpy_r_values) {
    tuple_T2OI cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    cpy_r_r0 = CPyDef___encode_elements_new(cpy_r_values);
    if (unlikely(cpy_r_r0.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 96, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r1 = cpy_r_r0.f0;
    cpy_r_r2 = cpy_r_r1;
    cpy_r_r3 = cpy_r_r0.f1;
    cpy_r_r4 = cpy_r_r3;
    cpy_r_r5 = CPyStatic_encode_uint_256;
    if (unlikely(cpy_r_r5 == NULL)) {
        goto CPyL9;
    } else
        goto CPyL4;
CPyL2: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"encode_uint_256\" was not set");
    cpy_r_r6 = 0;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 97, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r7 = CPyTagged_StealAsObject(cpy_r_r4);
    PyObject *cpy_r_r8[1] = {cpy_r_r7};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r5, cpy_r_r9, 1, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 97, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r7);
    cpy_r_r11 = PyNumber_Add(cpy_r_r10, cpy_r_r2);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 97, CPyStatic_globals);
        goto CPyL8;
    }
    if (likely(PyBytes_Check(cpy_r_r11) || PyByteArray_Check(cpy_r_r11)))
        cpy_r_r12 = cpy_r_r11;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "__encode_new", 97, CPyStatic_globals, "bytes", cpy_r_r11);
        goto CPyL8;
    }
    return cpy_r_r12;
CPyL8: ;
    cpy_r_r13 = NULL;
    return cpy_r_r13;
CPyL9: ;
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r4);
    goto CPyL2;
CPyL10: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    goto CPyL8;
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
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_new", 95, CPyStatic_globals);
    return NULL;
}

tuple_T2OI CPyDef___encode_elements_new(PyObject *cpy_r_values) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    tuple_T2OO cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    CPyPtr cpy_r_r13;
    int64_t cpy_r_r14;
    CPyTagged cpy_r_r15;
    CPyTagged cpy_r_count;
    CPyTagged cpy_r_r16;
    tuple_T1I cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    CPyPtr cpy_r_r20;
    int64_t cpy_r_r21;
    PyObject *cpy_r_r22;
    CPyTagged cpy_r_r23;
    CPyPtr cpy_r_r24;
    int64_t cpy_r_r25;
    CPyTagged cpy_r_r26;
    char cpy_r_r27;
    int64_t cpy_r_r28;
    CPyPtr cpy_r_r29;
    CPyPtr cpy_r_r30;
    int64_t cpy_r_r31;
    CPyPtr cpy_r_r32;
    PyObject *cpy_r_r33;
    CPyTagged cpy_r_r34;
    PyObject *cpy_r_r35;
    char cpy_r_r36;
    CPyTagged cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject **cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    CPyTagged cpy_r_r55;
    CPyTagged cpy_r_r56;
    PyObject *cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject **cpy_r_r61;
    PyObject *cpy_r_r62;
    int32_t cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    tuple_T2OI cpy_r_r75;
    tuple_T2OI cpy_r_r76;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r1 = PyObject_GetIter(cpy_r_values);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL39;
    }
CPyL2: ;
    cpy_r_r2 = PyIter_Next(cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL40;
    PyObject *__tmp1;
    if (unlikely(!(PyTuple_Check(cpy_r_r2) && PyTuple_GET_SIZE(cpy_r_r2) == 2))) {
        __tmp1 = NULL;
        goto __LL2;
    }
    __tmp1 = PyTuple_GET_ITEM(cpy_r_r2, 0);
    if (__tmp1 == NULL) goto __LL2;
    __tmp1 = PyTuple_GET_ITEM(cpy_r_r2, 1);
    if (__tmp1 == NULL) goto __LL2;
    __tmp1 = cpy_r_r2;
__LL2: ;
    if (unlikely(__tmp1 == NULL)) {
        CPy_TypeError("tuple[object, object]", cpy_r_r2); cpy_r_r3 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp3 = PyTuple_GET_ITEM(cpy_r_r2, 0);
        CPy_INCREF(__tmp3);
        PyObject *__tmp4;
        __tmp4 = __tmp3;
        cpy_r_r3.f0 = __tmp4;
        PyObject *__tmp5 = PyTuple_GET_ITEM(cpy_r_r2, 1);
        CPy_INCREF(__tmp5);
        PyObject *__tmp6;
        __tmp6 = __tmp5;
        cpy_r_r3.f1 = __tmp6;
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r4 = CPyStatic__item_encoder;
    if (unlikely(cpy_r_r4 == NULL)) {
        goto CPyL42;
    } else
        goto CPyL7;
CPyL5: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_item_encoder\" was not set");
    cpy_r_r5 = 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_Unreachable();
CPyL7: ;
    cpy_r_r6 = PyTuple_New(2);
    if (unlikely(cpy_r_r6 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = cpy_r_r3.f0;
    PyTuple_SET_ITEM(cpy_r_r6, 0, __tmp7);
    PyObject *__tmp8 = cpy_r_r3.f1;
    PyTuple_SET_ITEM(cpy_r_r6, 1, __tmp8);
    PyObject *cpy_r_r7[1] = {cpy_r_r6};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r8, 1, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_DECREF(cpy_r_r6);
    cpy_r_r10 = PyList_Append(cpy_r_r0, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL2;
CPyL9: ;
    cpy_r_r12 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 101, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r13 = (CPyPtr)&((PyVarObject *)cpy_r_r0)->ob_size;
    cpy_r_r14 = *(int64_t *)cpy_r_r13;
    cpy_r_r15 = cpy_r_r14 << 1;
    cpy_r_count = cpy_r_r15;
    cpy_r_r16 = CPyTagged_Multiply(64, cpy_r_count);
    cpy_r_r17.f0 = 0;
    cpy_r_r18 = CPyList_GetSlice(cpy_r_r0, 0, -2);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL44;
    }
    if (likely(PyList_Check(cpy_r_r18)))
        cpy_r_r19 = cpy_r_r18;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals, "list", cpy_r_r18);
        goto CPyL44;
    }
    cpy_r_r20 = (CPyPtr)&((PyVarObject *)cpy_r_r19)->ob_size;
    cpy_r_r21 = *(int64_t *)cpy_r_r20;
    cpy_r_r22 = PyList_New(cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r23 = 0;
CPyL14: ;
    cpy_r_r24 = (CPyPtr)&((PyVarObject *)cpy_r_r19)->ob_size;
    cpy_r_r25 = *(int64_t *)cpy_r_r24;
    cpy_r_r26 = cpy_r_r25 << 1;
    cpy_r_r27 = (Py_ssize_t)cpy_r_r23 < (Py_ssize_t)cpy_r_r26;
    if (!cpy_r_r27) goto CPyL46;
    cpy_r_r28 = (Py_ssize_t)cpy_r_r23 >> 1;
    cpy_r_r29 = (CPyPtr)&((PyListObject *)cpy_r_r19)->ob_item;
    cpy_r_r30 = *(CPyPtr *)cpy_r_r29;
    cpy_r_r31 = cpy_r_r28 * 8;
    cpy_r_r32 = cpy_r_r30 + cpy_r_r31;
    cpy_r_r33 = *(PyObject * *)cpy_r_r32;
    CPy_INCREF(cpy_r_r33);
    cpy_r_r34 = CPyObject_Size(cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r35 = CPyTagged_StealAsObject(cpy_r_r34);
    cpy_r_r36 = CPyList_SetItemUnsafe(cpy_r_r22, cpy_r_r23, cpy_r_r35);
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r37 = cpy_r_r23 + 2;
    cpy_r_r23 = cpy_r_r37;
    goto CPyL14;
CPyL18: ;
    cpy_r_r38 = PyObject_GetIter(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r39 = CPyStatic_globals;
    cpy_r_r40 = CPyStatics[7]; /* 'accumulate' */
    cpy_r_r41 = CPyDict_GetItem(cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL48;
    }
    PyObject *cpy_r_r42[1] = {cpy_r_r38};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = _PyObject_Vectorcall(cpy_r_r41, cpy_r_r43, 1, 0);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_DECREF(cpy_r_r38);
    cpy_r_r45 = CPyStatic_globals;
    cpy_r_r46 = CPyStatics[8]; /* 'chain' */
    cpy_r_r47 = CPyDict_GetItem(cpy_r_r45, cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r48 = PyTuple_New(1);
    if (unlikely(cpy_r_r48 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp9 = CPyTagged_StealAsObject(cpy_r_r17.f0);
    PyTuple_SET_ITEM(cpy_r_r48, 0, __tmp9);
    PyObject *cpy_r_r49[2] = {cpy_r_r48, cpy_r_r44};
    cpy_r_r50 = (PyObject **)&cpy_r_r49;
    cpy_r_r51 = _PyObject_Vectorcall(cpy_r_r47, cpy_r_r50, 2, 0);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 104, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r44);
    cpy_r_r52 = PyList_New(0);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 105, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r53 = PyObject_GetIter(cpy_r_r51);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 105, CPyStatic_globals);
        goto CPyL52;
    }
CPyL25: ;
    cpy_r_r54 = PyIter_Next(cpy_r_r53);
    if (cpy_r_r54 == NULL) goto CPyL53;
    if (likely(PyLong_Check(cpy_r_r54)))
        cpy_r_r55 = CPyTagged_FromObject(cpy_r_r54);
    else {
        CPy_TypeError("int", cpy_r_r54); cpy_r_r55 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r55 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 105, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r56 = CPyTagged_Add(cpy_r_r16, cpy_r_r55);
    CPyTagged_DECREF(cpy_r_r55);
    cpy_r_r57 = CPyStatic_encode_uint_256;
    if (unlikely(cpy_r_r57 == NULL)) {
        goto CPyL55;
    } else
        goto CPyL30;
CPyL28: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"encode_uint_256\" was not set");
    cpy_r_r58 = 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 105, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_Unreachable();
CPyL30: ;
    cpy_r_r59 = CPyTagged_StealAsObject(cpy_r_r56);
    PyObject *cpy_r_r60[1] = {cpy_r_r59};
    cpy_r_r61 = (PyObject **)&cpy_r_r60;
    cpy_r_r62 = _PyObject_Vectorcall(cpy_r_r57, cpy_r_r61, 1, 0);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 105, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_DECREF(cpy_r_r59);
    cpy_r_r63 = PyList_Append(cpy_r_r52, cpy_r_r62);
    CPy_DECREF(cpy_r_r62);
    cpy_r_r64 = cpy_r_r63 >= 0;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 105, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL25;
CPyL32: ;
    cpy_r_r65 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 105, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r66 = PyObject_GetIter(cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 105, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r67 = CPyStatics[72]; /* b'' */
    cpy_r_r68 = CPyStatic_globals;
    cpy_r_r69 = CPyStatics[8]; /* 'chain' */
    cpy_r_r70 = CPyDict_GetItem(cpy_r_r68, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 106, CPyStatic_globals);
        goto CPyL59;
    }
    PyObject *cpy_r_r71[2] = {cpy_r_r66, cpy_r_r0};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = _PyObject_Vectorcall(cpy_r_r70, cpy_r_r72, 2, 0);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 106, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r0);
    cpy_r_r74 = CPyBytes_Join(cpy_r_r67, cpy_r_r73);
    CPy_DECREF(cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 106, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r75.f0 = cpy_r_r74;
    cpy_r_r75.f1 = cpy_r_count;
    return cpy_r_r75;
CPyL38: ;
    tuple_T2OI __tmp10 = { NULL, CPY_INT_TAG };
    cpy_r_r76 = __tmp10;
    return cpy_r_r76;
CPyL39: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL38;
CPyL40: ;
    CPy_DECREF(cpy_r_r1);
    goto CPyL9;
CPyL41: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL38;
CPyL42: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3.f0);
    CPy_DecRef(cpy_r_r3.f1);
    goto CPyL5;
CPyL43: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r6);
    goto CPyL38;
CPyL44: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r17.f0);
    goto CPyL38;
CPyL45: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r17.f0);
    CPy_DecRef(cpy_r_r19);
    goto CPyL38;
CPyL46: ;
    CPy_DECREF(cpy_r_r19);
    goto CPyL18;
CPyL47: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r17.f0);
    CPy_DecRef(cpy_r_r19);
    CPy_DecRef(cpy_r_r22);
    goto CPyL38;
CPyL48: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r17.f0);
    CPy_DecRef(cpy_r_r38);
    goto CPyL38;
CPyL49: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r17.f0);
    CPy_DecRef(cpy_r_r44);
    goto CPyL38;
CPyL50: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r44);
    CPy_DecRef(cpy_r_r48);
    goto CPyL38;
CPyL51: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r51);
    goto CPyL38;
CPyL52: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r52);
    goto CPyL38;
CPyL53: ;
    CPyTagged_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r53);
    goto CPyL32;
CPyL54: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    goto CPyL38;
CPyL55: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    CPyTagged_DecRef(cpy_r_r56);
    goto CPyL28;
CPyL56: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPyTagged_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    CPy_DecRef(cpy_r_r59);
    goto CPyL38;
CPyL57: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_r52);
    goto CPyL38;
CPyL58: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    goto CPyL38;
CPyL59: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_r66);
    goto CPyL38;
CPyL60: ;
    CPyTagged_DecRef(cpy_r_count);
    goto CPyL38;
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
    PyObject *__tmp11 = retval.f0;
    PyTuple_SET_ITEM(retbox, 0, __tmp11);
    PyObject *__tmp12 = CPyTagged_StealAsObject(retval.f1);
    PyTuple_SET_ITEM(retbox, 1, __tmp12);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "__encode_elements_new", 100, CPyStatic_globals);
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
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_encode", 119, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r3 = PyTuple_New(2);
    if (unlikely(cpy_r_r3 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp13 = cpy_r_r0.f0 ? Py_True : Py_False;
    CPy_INCREF(__tmp13);
    PyTuple_SET_ITEM(cpy_r_r3, 0, __tmp13);
    PyObject *__tmp14 = cpy_r_r0.f1;
    PyTuple_SET_ITEM(cpy_r_r3, 1, __tmp14);
    PyObject *cpy_r_r4[1] = {cpy_r_r3};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r1, cpy_r_r5, 1, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_encode", 119, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_DECREF(cpy_r_r3);
    if (likely(PyBytes_Check(cpy_r_r6) || PyByteArray_Check(cpy_r_r6)))
        cpy_r_r7 = cpy_r_r6;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "mcall_encode", 119, CPyStatic_globals, "bytes", cpy_r_r6);
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
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_encode", 118, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_mcall_decode(PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    tuple_T3IIO cpy_r_r15;
    PyObject *cpy_r_r16;
    tuple_T3OOO cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    int32_t cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    int32_t cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    int32_t cpy_r_r43;
    char cpy_r_r44;
    char cpy_r_r45;
    CPyPtr cpy_r_r46;
    int64_t cpy_r_r47;
    PyObject *cpy_r_r48;
    CPyTagged cpy_r_r49;
    CPyPtr cpy_r_r50;
    int64_t cpy_r_r51;
    CPyTagged cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    tuple_T2CO cpy_r_r55;
    PyObject *cpy_r_r56;
    char cpy_r_r57;
    CPyTagged cpy_r_r58;
    PyObject *cpy_r_r59;
    cpy_r_r0 = CPyStatics[9]; /* 'eth_call' */
    cpy_r_r1 = CPyStatics[10]; /* 'decode_result' */
    PyObject *cpy_r_r2[2] = {cpy_r_data, cpy_r_r0};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r3, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 128, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r5 = CPyStatic_ContextFramesBytesIO;
    if (unlikely(cpy_r_r5 == NULL)) {
        goto CPyL41;
    } else
        goto CPyL5;
CPyL3: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ContextFramesBytesIO\" was not set");
    cpy_r_r6 = 0;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 128, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_Unreachable();
CPyL5: ;
    PyObject *cpy_r_r7[1] = {cpy_r_r4};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r5, cpy_r_r8, 1, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 128, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_DECREF(cpy_r_r4);
    cpy_r_r10 = CPyStatic__mcall_decoder;
    if (unlikely(cpy_r_r10 == NULL)) {
        goto CPyL43;
    } else
        goto CPyL9;
CPyL7: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_mcall_decoder\" was not set");
    cpy_r_r11 = 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 128, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_Unreachable();
CPyL9: ;
    PyObject *cpy_r_r12[1] = {cpy_r_r9};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r10, cpy_r_r13, 1, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 128, CPyStatic_globals);
        goto CPyL44;
    }
    CPy_DECREF(cpy_r_r9);
    PyObject *__tmp15;
    if (unlikely(!(PyTuple_Check(cpy_r_r14) && PyTuple_GET_SIZE(cpy_r_r14) == 3))) {
        __tmp15 = NULL;
        goto __LL16;
    }
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r14, 0))))
        __tmp15 = PyTuple_GET_ITEM(cpy_r_r14, 0);
    else {
        __tmp15 = NULL;
    }
    if (__tmp15 == NULL) goto __LL16;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r14, 1))))
        __tmp15 = PyTuple_GET_ITEM(cpy_r_r14, 1);
    else {
        __tmp15 = NULL;
    }
    if (__tmp15 == NULL) goto __LL16;
    if (likely(PyTuple_Check(PyTuple_GET_ITEM(cpy_r_r14, 2))))
        __tmp15 = PyTuple_GET_ITEM(cpy_r_r14, 2);
    else {
        __tmp15 = NULL;
    }
    if (__tmp15 == NULL) goto __LL16;
    __tmp15 = cpy_r_r14;
__LL16: ;
    if (unlikely(__tmp15 == NULL)) {
        CPy_TypeError("tuple[int, int, tuple]", cpy_r_r14); cpy_r_r15 = (tuple_T3IIO) { CPY_INT_TAG, CPY_INT_TAG, NULL };
    } else {
        PyObject *__tmp17 = PyTuple_GET_ITEM(cpy_r_r14, 0);
        CPyTagged __tmp18;
        if (likely(PyLong_Check(__tmp17)))
            __tmp18 = CPyTagged_FromObject(__tmp17);
        else {
            CPy_TypeError("int", __tmp17); __tmp18 = CPY_INT_TAG;
        }
        cpy_r_r15.f0 = __tmp18;
        PyObject *__tmp19 = PyTuple_GET_ITEM(cpy_r_r14, 1);
        CPyTagged __tmp20;
        if (likely(PyLong_Check(__tmp19)))
            __tmp20 = CPyTagged_FromObject(__tmp19);
        else {
            CPy_TypeError("int", __tmp19); __tmp20 = CPY_INT_TAG;
        }
        cpy_r_r15.f1 = __tmp20;
        PyObject *__tmp21 = PyTuple_GET_ITEM(cpy_r_r14, 2);
        CPy_INCREF(__tmp21);
        PyObject * __tmp22;
        if (likely(PyTuple_Check(__tmp21)))
            __tmp22 = __tmp21;
        else {
            CPy_TypeError("tuple", __tmp21); 
            __tmp22 = NULL;
        }
        cpy_r_r15.f2 = __tmp22;
    }
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r15.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 128, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r16 = cpy_r_r15.f2;
    CPy_INCREF(cpy_r_r16);
    CPyTagged_DECREF(cpy_r_r15.f0);
    CPyTagged_DECREF(cpy_r_r15.f1);
    CPy_DECREF(cpy_r_r15.f2);
    goto CPyL32;
CPyL12: ;
    cpy_r_r17 = CPy_CatchError();
    cpy_r_r18 = CPyModule_builtins;
    cpy_r_r19 = CPyStatics[11]; /* 'Exception' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 129, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r21 = CPy_ExceptionMatches(cpy_r_r20);
    CPy_DecRef(cpy_r_r20);
    if (!cpy_r_r21) goto CPyL28;
    cpy_r_r22 = CPy_GetExcValue();
    cpy_r_r23 = CPyStatics[4]; /* 'args' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL45;
    }
    if (likely(PyTuple_Check(cpy_r_r24)))
        cpy_r_r25 = cpy_r_r24;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals, "tuple", cpy_r_r24);
        goto CPyL45;
    }
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyStatics[12]; /* 'PartialResponse' */
    cpy_r_r28 = CPyDict_GetItem(cpy_r_r26, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r29 = PyObject_IsInstance(cpy_r_data, cpy_r_r28);
    CPy_DecRef(cpy_r_r28);
    cpy_r_r30 = cpy_r_r29 >= 0;
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r31 = cpy_r_r29;
    if (!cpy_r_r31) goto CPyL21;
    cpy_r_r32 = CPyStatics[10]; /* 'decode_result' */
    PyObject *cpy_r_r33[1] = {cpy_r_data};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r34, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r36 = cpy_r_r35;
    goto CPyL22;
CPyL21: ;
    CPy_INCREF(cpy_r_data);
    cpy_r_r36 = cpy_r_data;
CPyL22: ;
    cpy_r_r37 = PyList_New(0);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r38 = CPyList_Extend(cpy_r_r37, cpy_r_r25);
    CPy_DecRef(cpy_r_r25);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL49;
CPyL24: ;
    cpy_r_r39 = PyList_Append(cpy_r_r37, cpy_r_r36);
    CPy_DecRef(cpy_r_r36);
    cpy_r_r40 = cpy_r_r39 >= 0;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r41 = PyList_AsTuple(cpy_r_r37);
    CPy_DecRef(cpy_r_r37);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r42 = CPyStatics[4]; /* 'args' */
    cpy_r_r43 = PyObject_SetAttr(cpy_r_r22, cpy_r_r42, cpy_r_r41);
    CPy_DecRef(cpy_r_r41);
    cpy_r_r44 = cpy_r_r43 >= 0;
    if (unlikely(!cpy_r_r44)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 131, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_RestoreExcInfo(cpy_r_r17);
    CPy_DecRef(cpy_r_r17.f0);
    CPy_DecRef(cpy_r_r17.f1);
    CPy_DecRef(cpy_r_r17.f2);
    return cpy_r_r22;
CPyL28: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL30;
    } else
        goto CPyL51;
CPyL29: ;
    CPy_Unreachable();
CPyL30: ;
    CPy_RestoreExcInfo(cpy_r_r17);
    CPy_DecRef(cpy_r_r17.f0);
    CPy_DecRef(cpy_r_r17.f1);
    CPy_DecRef(cpy_r_r17.f2);
    cpy_r_r45 = CPy_KeepPropagating();
    if (!cpy_r_r45) goto CPyL40;
    CPy_Unreachable();
CPyL32: ;
    cpy_r_r46 = (CPyPtr)&((PyVarObject *)cpy_r_r16)->ob_size;
    cpy_r_r47 = *(int64_t *)cpy_r_r46;
    cpy_r_r48 = PyList_New(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 134, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r49 = 0;
CPyL34: ;
    cpy_r_r50 = (CPyPtr)&((PyVarObject *)cpy_r_r16)->ob_size;
    cpy_r_r51 = *(int64_t *)cpy_r_r50;
    cpy_r_r52 = cpy_r_r51 << 1;
    cpy_r_r53 = (Py_ssize_t)cpy_r_r49 < (Py_ssize_t)cpy_r_r52;
    if (!cpy_r_r53) goto CPyL53;
    cpy_r_r54 = CPySequenceTuple_GetItem(cpy_r_r16, cpy_r_r49);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 134, CPyStatic_globals);
        goto CPyL54;
    }
    PyObject *__tmp23;
    if (unlikely(!(PyTuple_Check(cpy_r_r54) && PyTuple_GET_SIZE(cpy_r_r54) == 2))) {
        __tmp23 = NULL;
        goto __LL24;
    }
    if (likely(PyBool_Check(PyTuple_GET_ITEM(cpy_r_r54, 0))))
        __tmp23 = PyTuple_GET_ITEM(cpy_r_r54, 0);
    else {
        __tmp23 = NULL;
    }
    if (__tmp23 == NULL) goto __LL24;
    if (likely(PyBytes_Check(PyTuple_GET_ITEM(cpy_r_r54, 1)) || PyByteArray_Check(PyTuple_GET_ITEM(cpy_r_r54, 1))))
        __tmp23 = PyTuple_GET_ITEM(cpy_r_r54, 1);
    else {
        __tmp23 = NULL;
    }
    if (__tmp23 == NULL) goto __LL24;
    __tmp23 = cpy_r_r54;
__LL24: ;
    if (unlikely(__tmp23 == NULL)) {
        CPy_TypeError("tuple[bool, bytes]", cpy_r_r54); cpy_r_r55 = (tuple_T2CO) { 2, NULL };
    } else {
        PyObject *__tmp25 = PyTuple_GET_ITEM(cpy_r_r54, 0);
        char __tmp26;
        if (unlikely(!PyBool_Check(__tmp25))) {
            CPy_TypeError("bool", __tmp25); __tmp26 = 2;
        } else
            __tmp26 = __tmp25 == Py_True;
        cpy_r_r55.f0 = __tmp26;
        PyObject *__tmp27 = PyTuple_GET_ITEM(cpy_r_r54, 1);
        CPy_INCREF(__tmp27);
        PyObject *__tmp28;
        if (likely(PyBytes_Check(__tmp27) || PyByteArray_Check(__tmp27)))
            __tmp28 = __tmp27;
        else {
            CPy_TypeError("bytes", __tmp27); 
            __tmp28 = NULL;
        }
        cpy_r_r55.f1 = __tmp28;
    }
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r55.f0 == 2)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 134, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r56 = cpy_r_r55.f1;
    CPy_INCREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r55.f1);
    cpy_r_r57 = CPyList_SetItemUnsafe(cpy_r_r48, cpy_r_r49, cpy_r_r56);
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 134, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r58 = cpy_r_r49 + 2;
    cpy_r_r49 = cpy_r_r58;
    goto CPyL34;
CPyL39: ;
    return cpy_r_r48;
CPyL40: ;
    cpy_r_r59 = NULL;
    return cpy_r_r59;
CPyL41: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL3;
CPyL42: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL12;
CPyL43: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL7;
CPyL44: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL12;
CPyL45: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL30;
CPyL46: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r25);
    goto CPyL30;
CPyL47: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r36);
    goto CPyL30;
CPyL48: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r37);
    goto CPyL30;
CPyL49: ;
    CPy_DecRef(cpy_r_r38);
    goto CPyL24;
CPyL50: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r37);
    goto CPyL30;
CPyL51: ;
    CPy_DecRef(cpy_r_r17.f0);
    CPy_DecRef(cpy_r_r17.f1);
    CPy_DecRef(cpy_r_r17.f2);
    goto CPyL29;
CPyL52: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL40;
CPyL53: ;
    CPy_DECREF(cpy_r_r16);
    goto CPyL39;
CPyL54: ;
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r48);
    goto CPyL40;
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
    CPy_AddTraceback("dank_mids/helpers/_codec.py", "mcall_decode", 126, CPyStatic_globals);
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
    PyObject **cpy_r_r13;
    PyObject **cpy_r_r14;
    void *cpy_r_r16;
    void *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
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
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    int32_t cpy_r_r53;
    char cpy_r_r54;
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
    PyObject *cpy_r_r68;
    tuple_T2OO cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    CPyPtr cpy_r_r73;
    CPyPtr cpy_r_r74;
    PyObject *cpy_r_r75;
    tuple_T2OO cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    int32_t cpy_r_r81;
    char cpy_r_r82;
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
    PyObject *cpy_r_r95;
    tuple_T2OO cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    tuple_T2OO cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    tuple_T3OOO cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    int32_t cpy_r_r108;
    char cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    tuple_T2OO cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    int32_t cpy_r_r122;
    char cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    int32_t cpy_r_r131;
    char cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    int32_t cpy_r_r138;
    char cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    int32_t cpy_r_r147;
    char cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    int32_t cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    int32_t cpy_r_r167;
    char cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    int32_t cpy_r_r178;
    char cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    int32_t cpy_r_r187;
    char cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    int32_t cpy_r_r194;
    char cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject **cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    int32_t cpy_r_r208;
    char cpy_r_r209;
    PyObject *cpy_r_r210;
    char cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    int32_t cpy_r_r218;
    char cpy_r_r219;
    PyObject *cpy_r_r220;
    char cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    int32_t cpy_r_r226;
    char cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    char cpy_r_r230;
    PyObject *cpy_r_r231;
    int32_t cpy_r_r232;
    char cpy_r_r233;
    PyObject *cpy_r_r234;
    char cpy_r_r235;
    PyObject *cpy_r_r236;
    int32_t cpy_r_r237;
    char cpy_r_r238;
    PyObject *cpy_r_r239;
    char cpy_r_r240;
    PyObject *cpy_r_r241;
    int32_t cpy_r_r242;
    char cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    char cpy_r_r248;
    PyObject *cpy_r_r249;
    int32_t cpy_r_r250;
    char cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    char cpy_r_r256;
    PyObject *cpy_r_r257;
    int32_t cpy_r_r258;
    char cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject **cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    PyObject *cpy_r_r273;
    int32_t cpy_r_r274;
    char cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    int32_t cpy_r_r279;
    char cpy_r_r280;
    char cpy_r_r281;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[13]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", -1, CPyStatic_globals);
        goto CPyL103;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[76]; /* ('accumulate', 'chain') */
    cpy_r_r6 = CPyStatics[14]; /* 'itertools' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 1, CPyStatic_globals);
        goto CPyL103;
    }
    CPyModule_itertools = cpy_r_r8;
    CPy_INCREF(CPyModule_itertools);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[77]; /* ('Any', 'AnyStr', 'Callable', 'Final', 'Iterable', 'List',
                                  'Union', 'Tuple', 'TypeVar') */
    cpy_r_r10 = CPyStatics[24]; /* 'typing' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 2, CPyStatic_globals);
        goto CPyL103;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = (PyObject **)&CPyModule_msgspec;
    cpy_r_r14 = (PyObject **)&CPyModule_msgspec___json;
    PyObject **cpy_r_r15[2] = {cpy_r_r13, cpy_r_r14};
    cpy_r_r16 = (void *)&cpy_r_r15;
    int64_t cpy_r_r17[2] = {4, 5};
    cpy_r_r18 = (void *)&cpy_r_r17;
    cpy_r_r19 = CPyStatics[80]; /* (('msgspec', 'msgspec', 'msgspec'),
                                   ('msgspec.json', 'msgspec', 'msgspec')) */
    cpy_r_r20 = CPyStatic_globals;
    cpy_r_r21 = CPyStatics[27]; /* 'dank_mids/helpers/_codec.py' */
    cpy_r_r22 = CPyStatics[28]; /* '<module>' */
    cpy_r_r23 = CPyImport_ImportMany(cpy_r_r19, cpy_r_r16, cpy_r_r20, cpy_r_r21, cpy_r_r22, cpy_r_r18);
    if (!cpy_r_r23) goto CPyL103;
    cpy_r_r24 = CPyStatics[81]; /* ('decoding', 'encoding') */
    cpy_r_r25 = CPyStatics[31]; /* 'eth_abi' */
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyImport_ImportFromMany(cpy_r_r25, cpy_r_r24, cpy_r_r24, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 6, CPyStatic_globals);
        goto CPyL103;
    }
    CPyModule_eth_abi = cpy_r_r27;
    CPy_INCREF(CPyModule_eth_abi);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r28 = CPyStatics[82]; /* ('default_codec',) */
    cpy_r_r29 = CPyStatics[33]; /* 'eth_abi.abi' */
    cpy_r_r30 = CPyStatic_globals;
    cpy_r_r31 = CPyImport_ImportFromMany(cpy_r_r29, cpy_r_r28, cpy_r_r28, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 7, CPyStatic_globals);
        goto CPyL103;
    }
    CPyModule_eth_abi___abi = cpy_r_r31;
    CPy_INCREF(CPyModule_eth_abi___abi);
    CPy_DECREF(cpy_r_r31);
    cpy_r_r32 = CPyStatics[83]; /* ('DynamicArrayEncoder', 'TupleEncoder') */
    cpy_r_r33 = CPyStatics[36]; /* 'eth_abi.encoding' */
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyImport_ImportFromMany(cpy_r_r33, cpy_r_r32, cpy_r_r32, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 8, CPyStatic_globals);
        goto CPyL103;
    }
    CPyModule_eth_abi___encoding = cpy_r_r35;
    CPy_INCREF(CPyModule_eth_abi___encoding);
    CPy_DECREF(cpy_r_r35);
    cpy_r_r36 = CPyStatics[84]; /* ('types',) */
    cpy_r_r37 = CPyStatics[38]; /* 'dank_mids' */
    cpy_r_r38 = CPyStatic_globals;
    cpy_r_r39 = CPyImport_ImportFromMany(cpy_r_r37, cpy_r_r36, cpy_r_r36, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 10, CPyStatic_globals);
        goto CPyL103;
    }
    CPyModule_dank_mids = cpy_r_r39;
    CPy_INCREF(CPyModule_dank_mids);
    CPy_DECREF(cpy_r_r39);
    cpy_r_r40 = CPyStatics[85]; /* ('JSONRPCBatchResponseRaw', 'MulticallChunk',
                                   'PartialResponse') */
    cpy_r_r41 = CPyStatics[40]; /* 'dank_mids.types' */
    cpy_r_r42 = CPyStatic_globals;
    cpy_r_r43 = CPyImport_ImportFromMany(cpy_r_r41, cpy_r_r40, cpy_r_r40, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 11, CPyStatic_globals);
        goto CPyL103;
    }
    CPyModule_dank_mids___types = cpy_r_r43;
    CPy_INCREF(CPyModule_dank_mids___types);
    CPy_DECREF(cpy_r_r43);
    cpy_r_r44 = CPyStatics[41]; /* '__T' */
    cpy_r_r45 = CPyStatic_globals;
    cpy_r_r46 = CPyStatics[23]; /* 'TypeVar' */
    cpy_r_r47 = CPyDict_GetItem(cpy_r_r45, cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 14, CPyStatic_globals);
        goto CPyL103;
    }
    PyObject *cpy_r_r48[1] = {cpy_r_r44};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = _PyObject_Vectorcall(cpy_r_r47, cpy_r_r49, 1, 0);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 14, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r51 = CPyStatic_globals;
    cpy_r_r52 = CPyStatics[41]; /* '__T' */
    cpy_r_r53 = CPyDict_SetItem(cpy_r_r51, cpy_r_r52, cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    cpy_r_r54 = cpy_r_r53 >= 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 14, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r55 = CPyStatic_globals;
    cpy_r_r56 = CPyStatics[17]; /* 'Callable' */
    cpy_r_r57 = CPyDict_GetItem(cpy_r_r55, cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r58 = CPyStatic_globals;
    cpy_r_r59 = CPyStatics[22]; /* 'Tuple' */
    cpy_r_r60 = CPyDict_GetItem(cpy_r_r58, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r61 = (PyObject *)&PyBool_Type;
    cpy_r_r62 = CPyStatic_globals;
    cpy_r_r63 = CPyStatics[19]; /* 'Iterable' */
    cpy_r_r64 = CPyDict_GetItem(cpy_r_r62, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL105;
    }
    cpy_r_r65 = CPyStatic_globals;
    cpy_r_r66 = CPyStatics[39]; /* 'MulticallChunk' */
    cpy_r_r67 = CPyDict_GetItem(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL106;
    }
    cpy_r_r68 = PyObject_GetItem(cpy_r_r64, cpy_r_r67);
    CPy_DECREF(cpy_r_r64);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL105;
    }
    CPy_INCREF(cpy_r_r61);
    cpy_r_r69.f0 = cpy_r_r61;
    cpy_r_r69.f1 = cpy_r_r68;
    cpy_r_r70 = PyTuple_New(2);
    if (unlikely(cpy_r_r70 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp29 = cpy_r_r69.f0;
    PyTuple_SET_ITEM(cpy_r_r70, 0, __tmp29);
    PyObject *__tmp30 = cpy_r_r69.f1;
    PyTuple_SET_ITEM(cpy_r_r70, 1, __tmp30);
    cpy_r_r71 = PyObject_GetItem(cpy_r_r60, cpy_r_r70);
    CPy_DECREF(cpy_r_r60);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r72 = PyList_New(1);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL107;
    }
    cpy_r_r73 = (CPyPtr)&((PyListObject *)cpy_r_r72)->ob_item;
    cpy_r_r74 = *(CPyPtr *)cpy_r_r73;
    *(PyObject * *)cpy_r_r74 = cpy_r_r71;
    cpy_r_r75 = (PyObject *)&PyBytes_Type;
    CPy_INCREF(cpy_r_r75);
    cpy_r_r76.f0 = cpy_r_r72;
    cpy_r_r76.f1 = cpy_r_r75;
    cpy_r_r77 = PyTuple_New(2);
    if (unlikely(cpy_r_r77 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp31 = cpy_r_r76.f0;
    PyTuple_SET_ITEM(cpy_r_r77, 0, __tmp31);
    PyObject *__tmp32 = cpy_r_r76.f1;
    PyTuple_SET_ITEM(cpy_r_r77, 1, __tmp32);
    cpy_r_r78 = PyObject_GetItem(cpy_r_r57, cpy_r_r77);
    CPy_DECREF(cpy_r_r57);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r79 = CPyStatic_globals;
    cpy_r_r80 = CPyStatics[42]; /* 'MulticallEncoder' */
    cpy_r_r81 = CPyDict_SetItem(cpy_r_r79, cpy_r_r80, cpy_r_r78);
    CPy_DECREF(cpy_r_r78);
    cpy_r_r82 = cpy_r_r81 >= 0;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 16, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r83 = CPyStatic_globals;
    cpy_r_r84 = CPyStatics[22]; /* 'Tuple' */
    cpy_r_r85 = CPyDict_GetItem(cpy_r_r83, cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 18, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r86 = (PyObject *)&PyLong_Type;
    cpy_r_r87 = (PyObject *)&PyLong_Type;
    cpy_r_r88 = CPyStatic_globals;
    cpy_r_r89 = CPyStatics[22]; /* 'Tuple' */
    cpy_r_r90 = CPyDict_GetItem(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 18, CPyStatic_globals);
        goto CPyL108;
    }
    cpy_r_r91 = CPyStatic_globals;
    cpy_r_r92 = CPyStatics[22]; /* 'Tuple' */
    cpy_r_r93 = CPyDict_GetItem(cpy_r_r91, cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 18, CPyStatic_globals);
        goto CPyL109;
    }
    cpy_r_r94 = CPyStatics[43]; /* 'Success' */
    cpy_r_r95 = (PyObject *)&PyBytes_Type;
    CPy_INCREF(cpy_r_r94);
    CPy_INCREF(cpy_r_r95);
    cpy_r_r96.f0 = cpy_r_r94;
    cpy_r_r96.f1 = cpy_r_r95;
    cpy_r_r97 = PyTuple_New(2);
    if (unlikely(cpy_r_r97 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp33 = cpy_r_r96.f0;
    PyTuple_SET_ITEM(cpy_r_r97, 0, __tmp33);
    PyObject *__tmp34 = cpy_r_r96.f1;
    PyTuple_SET_ITEM(cpy_r_r97, 1, __tmp34);
    cpy_r_r98 = PyObject_GetItem(cpy_r_r93, cpy_r_r97);
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r97);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 18, CPyStatic_globals);
        goto CPyL109;
    }
    cpy_r_r99 = (PyObject *)&_Py_EllipsisObject;
    CPy_INCREF(cpy_r_r99);
    cpy_r_r100.f0 = cpy_r_r98;
    cpy_r_r100.f1 = cpy_r_r99;
    cpy_r_r101 = PyTuple_New(2);
    if (unlikely(cpy_r_r101 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp35 = cpy_r_r100.f0;
    PyTuple_SET_ITEM(cpy_r_r101, 0, __tmp35);
    PyObject *__tmp36 = cpy_r_r100.f1;
    PyTuple_SET_ITEM(cpy_r_r101, 1, __tmp36);
    cpy_r_r102 = PyObject_GetItem(cpy_r_r90, cpy_r_r101);
    CPy_DECREF(cpy_r_r90);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 18, CPyStatic_globals);
        goto CPyL108;
    }
    CPy_INCREF(cpy_r_r86);
    CPy_INCREF(cpy_r_r87);
    cpy_r_r103.f0 = cpy_r_r86;
    cpy_r_r103.f1 = cpy_r_r87;
    cpy_r_r103.f2 = cpy_r_r102;
    cpy_r_r104 = PyTuple_New(3);
    if (unlikely(cpy_r_r104 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp37 = cpy_r_r103.f0;
    PyTuple_SET_ITEM(cpy_r_r104, 0, __tmp37);
    PyObject *__tmp38 = cpy_r_r103.f1;
    PyTuple_SET_ITEM(cpy_r_r104, 1, __tmp38);
    PyObject *__tmp39 = cpy_r_r103.f2;
    PyTuple_SET_ITEM(cpy_r_r104, 2, __tmp39);
    cpy_r_r105 = PyObject_GetItem(cpy_r_r85, cpy_r_r104);
    CPy_DECREF(cpy_r_r85);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 18, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r106 = CPyStatic_globals;
    cpy_r_r107 = CPyStatics[44]; /* 'DecodedMulticall' */
    cpy_r_r108 = CPyDict_SetItem(cpy_r_r106, cpy_r_r107, cpy_r_r105);
    CPy_DECREF(cpy_r_r105);
    cpy_r_r109 = cpy_r_r108 >= 0;
    if (unlikely(!cpy_r_r109)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 18, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r110 = CPyStatic_globals;
    cpy_r_r111 = CPyStatics[17]; /* 'Callable' */
    cpy_r_r112 = CPyDict_GetItem(cpy_r_r110, cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 19, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r113 = (PyObject *)&_Py_EllipsisObject;
    cpy_r_r114 = CPyStatic_globals;
    cpy_r_r115 = CPyStatics[44]; /* 'DecodedMulticall' */
    cpy_r_r116 = CPyDict_GetItem(cpy_r_r114, cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 19, CPyStatic_globals);
        goto CPyL110;
    }
    CPy_INCREF(cpy_r_r113);
    cpy_r_r117.f0 = cpy_r_r113;
    cpy_r_r117.f1 = cpy_r_r116;
    cpy_r_r118 = PyTuple_New(2);
    if (unlikely(cpy_r_r118 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp40 = cpy_r_r117.f0;
    PyTuple_SET_ITEM(cpy_r_r118, 0, __tmp40);
    PyObject *__tmp41 = cpy_r_r117.f1;
    PyTuple_SET_ITEM(cpy_r_r118, 1, __tmp41);
    cpy_r_r119 = PyObject_GetItem(cpy_r_r112, cpy_r_r118);
    CPy_DECREF(cpy_r_r112);
    CPy_DECREF(cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 19, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r120 = CPyStatic_globals;
    cpy_r_r121 = CPyStatics[45]; /* 'MulticallDecoder' */
    cpy_r_r122 = CPyDict_SetItem(cpy_r_r120, cpy_r_r121, cpy_r_r119);
    CPy_DECREF(cpy_r_r119);
    cpy_r_r123 = cpy_r_r122 >= 0;
    if (unlikely(!cpy_r_r123)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 19, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r124 = CPyStatic_globals;
    cpy_r_r125 = CPyStatics[25]; /* 'msgspec' */
    cpy_r_r126 = CPyDict_GetItem(cpy_r_r124, cpy_r_r125);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r127 = CPyStatics[46]; /* 'Raw' */
    cpy_r_r128 = CPyObject_GetAttr(cpy_r_r126, cpy_r_r127);
    CPy_DECREF(cpy_r_r126);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic_Raw = cpy_r_r128;
    CPy_INCREF(CPyStatic_Raw);
    cpy_r_r129 = CPyStatic_globals;
    cpy_r_r130 = CPyStatics[46]; /* 'Raw' */
    cpy_r_r131 = CPyDict_SetItem(cpy_r_r129, cpy_r_r130, cpy_r_r128);
    CPy_DECREF(cpy_r_r128);
    cpy_r_r132 = cpy_r_r131 >= 0;
    if (unlikely(!cpy_r_r132)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 23, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r133 = CPyModule_dank_mids___types;
    cpy_r_r134 = CPyStatics[47]; /* 'RawResponse' */
    cpy_r_r135 = CPyObject_GetAttr(cpy_r_r133, cpy_r_r134);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 24, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic_RawResponse = cpy_r_r135;
    CPy_INCREF(CPyStatic_RawResponse);
    cpy_r_r136 = CPyStatic_globals;
    cpy_r_r137 = CPyStatics[47]; /* 'RawResponse' */
    cpy_r_r138 = CPyDict_SetItem(cpy_r_r136, cpy_r_r137, cpy_r_r135);
    CPy_DECREF(cpy_r_r135);
    cpy_r_r139 = cpy_r_r138 >= 0;
    if (unlikely(!cpy_r_r139)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 24, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r140 = CPyStatic_globals;
    cpy_r_r141 = CPyStatics[29]; /* 'decoding' */
    cpy_r_r142 = CPyDict_GetItem(cpy_r_r140, cpy_r_r141);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r143 = CPyStatics[48]; /* 'ContextFramesBytesIO' */
    cpy_r_r144 = CPyObject_GetAttr(cpy_r_r142, cpy_r_r143);
    CPy_DECREF(cpy_r_r142);
    if (unlikely(cpy_r_r144 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic_ContextFramesBytesIO = cpy_r_r144;
    CPy_INCREF(CPyStatic_ContextFramesBytesIO);
    cpy_r_r145 = CPyStatic_globals;
    cpy_r_r146 = CPyStatics[48]; /* 'ContextFramesBytesIO' */
    cpy_r_r147 = CPyDict_SetItem(cpy_r_r145, cpy_r_r146, cpy_r_r144);
    CPy_DECREF(cpy_r_r144);
    cpy_r_r148 = cpy_r_r147 >= 0;
    if (unlikely(!cpy_r_r148)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 25, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r149 = CPyStatic_globals;
    cpy_r_r150 = CPyStatics[25]; /* 'msgspec' */
    cpy_r_r151 = CPyDict_GetItem(cpy_r_r149, cpy_r_r150);
    if (unlikely(cpy_r_r151 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 26, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r152 = CPyStatics[49]; /* 'DecodeError' */
    cpy_r_r153 = CPyObject_GetAttr(cpy_r_r151, cpy_r_r152);
    CPy_DECREF(cpy_r_r151);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 26, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic_DecodeError = cpy_r_r153;
    CPy_INCREF(CPyStatic_DecodeError);
    cpy_r_r154 = CPyStatic_globals;
    cpy_r_r155 = CPyStatics[49]; /* 'DecodeError' */
    cpy_r_r156 = CPyDict_SetItem(cpy_r_r154, cpy_r_r155, cpy_r_r153);
    CPy_DECREF(cpy_r_r153);
    cpy_r_r157 = cpy_r_r156 >= 0;
    if (unlikely(!cpy_r_r157)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 26, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r158 = CPyStatic_globals;
    cpy_r_r159 = CPyStatics[25]; /* 'msgspec' */
    cpy_r_r160 = CPyDict_GetItem(cpy_r_r158, cpy_r_r159);
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 28, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r161 = CPyStatics[50]; /* 'json' */
    cpy_r_r162 = CPyObject_GetAttr(cpy_r_r160, cpy_r_r161);
    CPy_DECREF(cpy_r_r160);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 28, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r163 = CPyStatics[51]; /* 'encode' */
    cpy_r_r164 = CPyObject_GetAttr(cpy_r_r162, cpy_r_r163);
    CPy_DECREF(cpy_r_r162);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 28, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic_json_encode = cpy_r_r164;
    CPy_INCREF(CPyStatic_json_encode);
    cpy_r_r165 = CPyStatic_globals;
    cpy_r_r166 = CPyStatics[52]; /* 'json_encode' */
    cpy_r_r167 = CPyDict_SetItem(cpy_r_r165, cpy_r_r166, cpy_r_r164);
    CPy_DECREF(cpy_r_r164);
    cpy_r_r168 = cpy_r_r167 >= 0;
    if (unlikely(!cpy_r_r168)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 28, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r169 = CPyStatic_globals;
    cpy_r_r170 = CPyStatics[25]; /* 'msgspec' */
    cpy_r_r171 = CPyDict_GetItem(cpy_r_r169, cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 29, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r172 = CPyStatics[50]; /* 'json' */
    cpy_r_r173 = CPyObject_GetAttr(cpy_r_r171, cpy_r_r172);
    CPy_DECREF(cpy_r_r171);
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 29, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r174 = CPyStatics[53]; /* 'decode' */
    cpy_r_r175 = CPyObject_GetAttr(cpy_r_r173, cpy_r_r174);
    CPy_DECREF(cpy_r_r173);
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 29, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic_json_decode = cpy_r_r175;
    CPy_INCREF(CPyStatic_json_decode);
    cpy_r_r176 = CPyStatic_globals;
    cpy_r_r177 = CPyStatics[54]; /* 'json_decode' */
    cpy_r_r178 = CPyDict_SetItem(cpy_r_r176, cpy_r_r177, cpy_r_r175);
    CPy_DECREF(cpy_r_r175);
    cpy_r_r179 = cpy_r_r178 >= 0;
    if (unlikely(!cpy_r_r179)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 29, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r180 = CPyStatic_globals;
    cpy_r_r181 = CPyStatics[30]; /* 'encoding' */
    cpy_r_r182 = CPyDict_GetItem(cpy_r_r180, cpy_r_r181);
    if (unlikely(cpy_r_r182 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 30, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r183 = CPyStatics[55]; /* 'encode_uint_256' */
    cpy_r_r184 = CPyObject_GetAttr(cpy_r_r182, cpy_r_r183);
    CPy_DECREF(cpy_r_r182);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 30, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic_encode_uint_256 = cpy_r_r184;
    CPy_INCREF(CPyStatic_encode_uint_256);
    cpy_r_r185 = CPyStatic_globals;
    cpy_r_r186 = CPyStatics[55]; /* 'encode_uint_256' */
    cpy_r_r187 = CPyDict_SetItem(cpy_r_r185, cpy_r_r186, cpy_r_r184);
    CPy_DECREF(cpy_r_r184);
    cpy_r_r188 = cpy_r_r187 >= 0;
    if (unlikely(!cpy_r_r188)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 30, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r189 = CPyModule_dank_mids___types;
    cpy_r_r190 = CPyStatics[56]; /* '_encode_hook' */
    cpy_r_r191 = CPyObject_GetAttr(cpy_r_r189, cpy_r_r190);
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 31, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic__encode_hook = cpy_r_r191;
    CPy_INCREF(CPyStatic__encode_hook);
    cpy_r_r192 = CPyStatic_globals;
    cpy_r_r193 = CPyStatics[56]; /* '_encode_hook' */
    cpy_r_r194 = CPyDict_SetItem(cpy_r_r192, cpy_r_r193, cpy_r_r191);
    CPy_DECREF(cpy_r_r191);
    cpy_r_r195 = cpy_r_r194 >= 0;
    if (unlikely(!cpy_r_r195)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 31, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r196 = CPyStatic_globals;
    cpy_r_r197 = CPyStatics[32]; /* 'default_codec' */
    cpy_r_r198 = CPyDict_GetItem(cpy_r_r196, cpy_r_r197);
    if (unlikely(cpy_r_r198 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 85, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r199 = CPyStatics[57]; /* '_registry' */
    cpy_r_r200 = CPyObject_GetAttr(cpy_r_r198, cpy_r_r199);
    CPy_DECREF(cpy_r_r198);
    if (unlikely(cpy_r_r200 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 85, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r201 = CPyStatics[58]; /* '(bool,(address,bytes)[])' */
    cpy_r_r202 = CPyStatics[59]; /* 'get_encoder' */
    PyObject *cpy_r_r203[2] = {cpy_r_r200, cpy_r_r201};
    cpy_r_r204 = (PyObject **)&cpy_r_r203;
    cpy_r_r205 = PyObject_VectorcallMethod(cpy_r_r202, cpy_r_r204, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r205 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 85, CPyStatic_globals);
        goto CPyL111;
    }
    CPy_DECREF(cpy_r_r200);
    CPyStatic__mcall_encoder = cpy_r_r205;
    CPy_INCREF(CPyStatic__mcall_encoder);
    cpy_r_r206 = CPyStatic_globals;
    cpy_r_r207 = CPyStatics[60]; /* '_mcall_encoder' */
    cpy_r_r208 = CPyDict_SetItem(cpy_r_r206, cpy_r_r207, cpy_r_r205);
    CPy_DECREF(cpy_r_r205);
    cpy_r_r209 = cpy_r_r208 >= 0;
    if (unlikely(!cpy_r_r209)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 85, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r210 = CPyStatic__mcall_encoder;
    if (likely(cpy_r_r210 != NULL)) goto CPyL65;
    PyErr_SetString(PyExc_NameError, "value for final name \"_mcall_encoder\" was not set");
    cpy_r_r211 = 0;
    if (unlikely(!cpy_r_r211)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 88, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_Unreachable();
CPyL65: ;
    cpy_r_r212 = CPyStatics[61]; /* 'encoders' */
    cpy_r_r213 = CPyObject_GetAttr(cpy_r_r210, cpy_r_r212);
    if (unlikely(cpy_r_r213 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 88, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r214 = CPyStatics[73]; /* -1 */
    cpy_r_r215 = PyObject_GetItem(cpy_r_r213, cpy_r_r214);
    CPy_DECREF(cpy_r_r213);
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 88, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic__array_encoder = cpy_r_r215;
    CPy_INCREF(CPyStatic__array_encoder);
    cpy_r_r216 = CPyStatic_globals;
    cpy_r_r217 = CPyStatics[62]; /* '_array_encoder' */
    cpy_r_r218 = CPyDict_SetItem(cpy_r_r216, cpy_r_r217, cpy_r_r215);
    CPy_DECREF(cpy_r_r215);
    cpy_r_r219 = cpy_r_r218 >= 0;
    if (unlikely(!cpy_r_r219)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 88, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r220 = CPyStatic__array_encoder;
    if (likely(cpy_r_r220 != NULL)) goto CPyL71;
    PyErr_SetString(PyExc_NameError, "value for final name \"_array_encoder\" was not set");
    cpy_r_r221 = 0;
    if (unlikely(!cpy_r_r221)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 89, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_Unreachable();
CPyL71: ;
    cpy_r_r222 = CPyStatics[63]; /* 'item_encoder' */
    cpy_r_r223 = CPyObject_GetAttr(cpy_r_r220, cpy_r_r222);
    if (unlikely(cpy_r_r223 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 89, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic__item_encoder = cpy_r_r223;
    CPy_INCREF(CPyStatic__item_encoder);
    cpy_r_r224 = CPyStatic_globals;
    cpy_r_r225 = CPyStatics[64]; /* '_item_encoder' */
    cpy_r_r226 = CPyDict_SetItem(cpy_r_r224, cpy_r_r225, cpy_r_r223);
    CPy_DECREF(cpy_r_r223);
    cpy_r_r227 = cpy_r_r226 >= 0;
    if (unlikely(!cpy_r_r227)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 89, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r228 = CPyDef___mypyc_lambda__0_obj();
    if (unlikely(cpy_r_r228 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 92, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r229 = CPyStatic__mcall_encoder;
    if (unlikely(cpy_r_r229 == NULL)) {
        goto CPyL112;
    } else
        goto CPyL77;
CPyL75: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_mcall_encoder\" was not set");
    cpy_r_r230 = 0;
    if (unlikely(!cpy_r_r230)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 92, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_Unreachable();
CPyL77: ;
    cpy_r_r231 = CPyStatics[65]; /* 'validate_value' */
    cpy_r_r232 = PyObject_SetAttr(cpy_r_r229, cpy_r_r231, cpy_r_r228);
    cpy_r_r233 = cpy_r_r232 >= 0;
    if (unlikely(!cpy_r_r233)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 92, CPyStatic_globals);
        goto CPyL113;
    }
    cpy_r_r234 = CPyStatic__array_encoder;
    if (unlikely(cpy_r_r234 == NULL)) {
        goto CPyL114;
    } else
        goto CPyL81;
CPyL79: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_array_encoder\" was not set");
    cpy_r_r235 = 0;
    if (unlikely(!cpy_r_r235)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 92, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_Unreachable();
CPyL81: ;
    cpy_r_r236 = CPyStatics[65]; /* 'validate_value' */
    cpy_r_r237 = PyObject_SetAttr(cpy_r_r234, cpy_r_r236, cpy_r_r228);
    cpy_r_r238 = cpy_r_r237 >= 0;
    if (unlikely(!cpy_r_r238)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 92, CPyStatic_globals);
        goto CPyL113;
    }
    cpy_r_r239 = CPyStatic__item_encoder;
    if (unlikely(cpy_r_r239 == NULL)) {
        goto CPyL115;
    } else
        goto CPyL85;
CPyL83: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_item_encoder\" was not set");
    cpy_r_r240 = 0;
    if (unlikely(!cpy_r_r240)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 92, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_Unreachable();
CPyL85: ;
    cpy_r_r241 = CPyStatics[65]; /* 'validate_value' */
    cpy_r_r242 = PyObject_SetAttr(cpy_r_r239, cpy_r_r241, cpy_r_r228);
    CPy_DECREF(cpy_r_r228);
    cpy_r_r243 = cpy_r_r242 >= 0;
    if (unlikely(!cpy_r_r243)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 92, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r244 = CPyStatic_globals;
    cpy_r_r245 = CPyStatics[66]; /* '__encode_new' */
    cpy_r_r246 = CPyDict_GetItem(cpy_r_r244, cpy_r_r245);
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 109, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r247 = CPyStatic__array_encoder;
    if (unlikely(cpy_r_r247 == NULL)) {
        goto CPyL116;
    } else
        goto CPyL90;
CPyL88: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_array_encoder\" was not set");
    cpy_r_r248 = 0;
    if (unlikely(!cpy_r_r248)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 109, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_Unreachable();
CPyL90: ;
    cpy_r_r249 = CPyStatics[51]; /* 'encode' */
    cpy_r_r250 = PyObject_SetAttr(cpy_r_r247, cpy_r_r249, cpy_r_r246);
    CPy_DECREF(cpy_r_r246);
    cpy_r_r251 = cpy_r_r250 >= 0;
    if (unlikely(!cpy_r_r251)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 109, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r252 = CPyStatic_globals;
    cpy_r_r253 = CPyStatics[67]; /* '__encode_elements_new' */
    cpy_r_r254 = CPyDict_GetItem(cpy_r_r252, cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 110, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r255 = CPyStatic__array_encoder;
    if (unlikely(cpy_r_r255 == NULL)) {
        goto CPyL117;
    } else
        goto CPyL95;
CPyL93: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_array_encoder\" was not set");
    cpy_r_r256 = 0;
    if (unlikely(!cpy_r_r256)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 110, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_Unreachable();
CPyL95: ;
    cpy_r_r257 = CPyStatics[68]; /* 'encode_elements' */
    cpy_r_r258 = PyObject_SetAttr(cpy_r_r255, cpy_r_r257, cpy_r_r254);
    CPy_DECREF(cpy_r_r254);
    cpy_r_r259 = cpy_r_r258 >= 0;
    if (unlikely(!cpy_r_r259)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 110, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r260 = CPyStatic_globals;
    cpy_r_r261 = CPyStatics[32]; /* 'default_codec' */
    cpy_r_r262 = CPyDict_GetItem(cpy_r_r260, cpy_r_r261);
    if (unlikely(cpy_r_r262 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 113, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r263 = CPyStatics[57]; /* '_registry' */
    cpy_r_r264 = CPyObject_GetAttr(cpy_r_r262, cpy_r_r263);
    CPy_DECREF(cpy_r_r262);
    if (unlikely(cpy_r_r264 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 113, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r265 = CPyStatics[69]; /* '(uint256,uint256,(bool,bytes)[])' */
    cpy_r_r266 = CPyStatics[70]; /* 'get_decoder' */
    PyObject *cpy_r_r267[2] = {cpy_r_r264, cpy_r_r265};
    cpy_r_r268 = (PyObject **)&cpy_r_r267;
    cpy_r_r269 = PyObject_VectorcallMethod(cpy_r_r266, cpy_r_r268, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r269 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 113, CPyStatic_globals);
        goto CPyL118;
    }
    CPy_DECREF(cpy_r_r264);
    cpy_r_r270 = CPyStatics[53]; /* 'decode' */
    cpy_r_r271 = CPyObject_GetAttr(cpy_r_r269, cpy_r_r270);
    CPy_DECREF(cpy_r_r269);
    if (unlikely(cpy_r_r271 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 113, CPyStatic_globals);
        goto CPyL103;
    }
    CPyStatic__mcall_decoder = cpy_r_r271;
    CPy_INCREF(CPyStatic__mcall_decoder);
    cpy_r_r272 = CPyStatic_globals;
    cpy_r_r273 = CPyStatics[71]; /* '_mcall_decoder' */
    cpy_r_r274 = CPyDict_SetItem(cpy_r_r272, cpy_r_r273, cpy_r_r271);
    CPy_DECREF(cpy_r_r271);
    cpy_r_r275 = cpy_r_r274 >= 0;
    if (unlikely(!cpy_r_r275)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 113, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r276 = (PyObject *)&PyBool_Type;
    cpy_r_r277 = CPyStatic_globals;
    cpy_r_r278 = CPyStatics[43]; /* 'Success' */
    cpy_r_r279 = CPyDict_SetItem(cpy_r_r277, cpy_r_r278, cpy_r_r276);
    cpy_r_r280 = cpy_r_r279 >= 0;
    if (unlikely(!cpy_r_r280)) {
        CPy_AddTraceback("dank_mids/helpers/_codec.py", "<module>", 123, CPyStatic_globals);
        goto CPyL103;
    }
    return 1;
CPyL103: ;
    cpy_r_r281 = 2;
    return cpy_r_r281;
CPyL104: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL103;
CPyL105: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r60);
    goto CPyL103;
CPyL106: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r60);
    CPy_DecRef(cpy_r_r64);
    goto CPyL103;
CPyL107: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r71);
    goto CPyL103;
CPyL108: ;
    CPy_DecRef(cpy_r_r85);
    goto CPyL103;
CPyL109: ;
    CPy_DecRef(cpy_r_r85);
    CPy_DecRef(cpy_r_r90);
    goto CPyL103;
CPyL110: ;
    CPy_DecRef(cpy_r_r112);
    goto CPyL103;
CPyL111: ;
    CPy_DecRef(cpy_r_r200);
    goto CPyL103;
CPyL112: ;
    CPy_DecRef(cpy_r_r228);
    goto CPyL75;
CPyL113: ;
    CPy_DecRef(cpy_r_r228);
    goto CPyL103;
CPyL114: ;
    CPy_DecRef(cpy_r_r228);
    goto CPyL79;
CPyL115: ;
    CPy_DecRef(cpy_r_r228);
    goto CPyL83;
CPyL116: ;
    CPy_DecRef(cpy_r_r246);
    goto CPyL88;
CPyL117: ;
    CPy_DecRef(cpy_r_r254);
    goto CPyL93;
CPyL118: ;
    CPy_DecRef(cpy_r_r264);
    goto CPyL103;
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
    CPyModule_msgspec = Py_None;
    CPyModule_msgspec___json = Py_None;
    CPyModule_eth_abi = Py_None;
    CPyModule_eth_abi___abi = Py_None;
    CPyModule_eth_abi___encoding = Py_None;
    CPyModule_dank_mids = Py_None;
    CPyModule_dank_mids___types = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[86];
const char * const CPyLit_Str[] = {
    "\a\004type\004args\027JSONRPCBatchResponseRaw\benc_hook\naccumulate\005chain\beth_call",
    "\a\rdecode_result\tException\017PartialResponse\bbuiltins\titertools\003Any\006AnyStr",
    "\t\bCallable\005Final\bIterable\004List\005Union\005Tuple\aTypeVar\006typing\amsgspec",
    "\005\fmsgspec.json\033dank_mids/helpers/_codec.py\b<module>\bdecoding\bencoding",
    "\005\aeth_abi\rdefault_codec\veth_abi.abi\023DynamicArrayEncoder\fTupleEncoder",
    "\006\020eth_abi.encoding\005types\tdank_mids\016MulticallChunk\017dank_mids.types\003__T",
    "\005\020MulticallEncoder\aSuccess\020DecodedMulticall\020MulticallDecoder\003Raw",
    "\006\vRawResponse\024ContextFramesBytesIO\vDecodeError\004json\006encode\vjson_encode",
    "\005\006decode\vjson_decode\017encode_uint_256\f_encode_hook\t_registry",
    "\004\030(bool,(address,bytes)[])\vget_encoder\016_mcall_encoder\bencoders",
    "\005\016_array_encoder\fitem_encoder\r_item_encoder\016validate_value\f__encode_new",
    "\002\025__encode_elements_new\017encode_elements",
    "\003 (uint256,uint256,(bool,bytes)[])\vget_decoder\016_mcall_decoder",
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
    12, 1, 3, 1, 6, 2, 7, 8, 9, 15, 16, 17, 18, 19, 20, 21, 22, 23, 3,
    25, 25, 25, 3, 26, 25, 25, 2, 78, 79, 2, 29, 30, 1, 32, 2, 34, 35, 1,
    37, 3, 5, 39, 12
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___helpers____codec_internal = NULL;
CPyModule *CPyModule_dank_mids___helpers____codec;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_itertools;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_msgspec;
CPyModule *CPyModule_msgspec___json;
CPyModule *CPyModule_eth_abi;
CPyModule *CPyModule_eth_abi___abi;
CPyModule *CPyModule_eth_abi___encoding;
CPyModule *CPyModule_dank_mids;
CPyModule *CPyModule_dank_mids___types;
PyObject *CPyStatic_Raw = NULL;
PyObject *CPyStatic_RawResponse = NULL;
PyObject *CPyStatic_ContextFramesBytesIO = NULL;
PyObject *CPyStatic_DecodeError = NULL;
PyObject *CPyStatic_json_encode = NULL;
PyObject *CPyStatic_json_decode = NULL;
PyObject *CPyStatic_encode_uint_256 = NULL;
PyObject *CPyStatic__encode_hook = NULL;
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
    &CPyStatic_Raw,
    &CPyStatic_RawResponse,
    &CPyStatic_ContextFramesBytesIO,
    &CPyStatic_DecodeError,
    &CPyStatic_json_encode,
    &CPyStatic_json_decode,
    &CPyStatic_encode_uint_256,
    &CPyStatic__encode_hook,
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
