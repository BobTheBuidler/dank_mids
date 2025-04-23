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
#include "__native_types.h"
#include "__native_internal_types.h"

static PyObject *DankContractCall_setup(PyTypeObject *type);
PyObject *CPyDef_DankContractCall(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);

static PyObject *
DankContractCall_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_DankContractCall) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return DankContractCall_setup(type);
}

static int
DankContractCall_traverse(dank_mids___brownie_patch___types___DankContractCallObject *self, visitproc visit, void *arg)
{
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
DankContractCall_clear(dank_mids___brownie_patch___types___DankContractCallObject *self)
{
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
DankContractCall_dealloc(dank_mids___brownie_patch___types___DankContractCallObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, DankContractCall_dealloc)
    DankContractCall_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem DankContractCall_vtable[1];
static bool
CPyDef_DankContractCall_trait_vtable_setup(void)
{
    CPyVTableItem DankContractCall_vtable_scratch[] = {
        NULL
    };
    memcpy(DankContractCall_vtable, DankContractCall_vtable_scratch, sizeof(DankContractCall_vtable));
    return 1;
}


static PyGetSetDef DankContractCall_getseters[] = {
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef DankContractCall_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_DankContractCall_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "DankContractCall",
    .tp_new = DankContractCall_new,
    .tp_dealloc = (destructor)DankContractCall_dealloc,
    .tp_traverse = (traverseproc)DankContractCall_traverse,
    .tp_clear = (inquiry)DankContractCall_clear,
    .tp_getset = DankContractCall_getseters,
    .tp_methods = DankContractCall_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___types___DankContractCallObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_DankContractCall_template = &CPyType_DankContractCall_template_;

static PyObject *
DankContractCall_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___types___DankContractCallObject *self;
    self = (dank_mids___brownie_patch___types___DankContractCallObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = DankContractCall_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_DankContractCall(PyObject *cpy_r_args, PyObject *cpy_r_kwargs)
{
    PyObject *self = DankContractCall_setup(CPyType_DankContractCall);
    if (self == NULL)
        return NULL;
    int res = CPyType_DankContractCall->tp_init(self, cpy_r_args, cpy_r_kwargs);
    if (res < 0) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}


static PyObject *DankContractTx_setup(PyTypeObject *type);
PyObject *CPyDef_DankContractTx(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);

static PyObject *
DankContractTx_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_DankContractTx) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return DankContractTx_setup(type);
}

static int
DankContractTx_traverse(dank_mids___brownie_patch___types___DankContractTxObject *self, visitproc visit, void *arg)
{
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
DankContractTx_clear(dank_mids___brownie_patch___types___DankContractTxObject *self)
{
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
DankContractTx_dealloc(dank_mids___brownie_patch___types___DankContractTxObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, DankContractTx_dealloc)
    DankContractTx_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem DankContractTx_vtable[1];
static bool
CPyDef_DankContractTx_trait_vtable_setup(void)
{
    CPyVTableItem DankContractTx_vtable_scratch[] = {
        NULL
    };
    memcpy(DankContractTx_vtable, DankContractTx_vtable_scratch, sizeof(DankContractTx_vtable));
    return 1;
}


static PyGetSetDef DankContractTx_getseters[] = {
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef DankContractTx_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_DankContractTx_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "DankContractTx",
    .tp_new = DankContractTx_new,
    .tp_dealloc = (destructor)DankContractTx_dealloc,
    .tp_traverse = (traverseproc)DankContractTx_traverse,
    .tp_clear = (inquiry)DankContractTx_clear,
    .tp_getset = DankContractTx_getseters,
    .tp_methods = DankContractTx_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___types___DankContractTxObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_DankContractTx_template = &CPyType_DankContractTx_template_;

static PyObject *
DankContractTx_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___types___DankContractTxObject *self;
    self = (dank_mids___brownie_patch___types___DankContractTxObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = DankContractTx_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_DankContractTx(PyObject *cpy_r_args, PyObject *cpy_r_kwargs)
{
    PyObject *self = DankContractTx_setup(CPyType_DankContractTx);
    if (self == NULL)
        return NULL;
    int res = CPyType_DankContractTx->tp_init(self, cpy_r_args, cpy_r_kwargs);
    if (res < 0) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}


static PyObject *DankOverloadedMethod_setup(PyTypeObject *type);
PyObject *CPyDef_DankOverloadedMethod(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);

static PyObject *
DankOverloadedMethod_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_DankOverloadedMethod) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return DankOverloadedMethod_setup(type);
}

static int
DankOverloadedMethod_traverse(dank_mids___brownie_patch___types___DankOverloadedMethodObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_methods);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
DankOverloadedMethod_clear(dank_mids___brownie_patch___types___DankOverloadedMethodObject *self)
{
    Py_CLEAR(self->_methods);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
DankOverloadedMethod_dealloc(dank_mids___brownie_patch___types___DankOverloadedMethodObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, DankOverloadedMethod_dealloc)
    DankOverloadedMethod_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem DankOverloadedMethod_vtable[2];
static bool
CPyDef_DankOverloadedMethod_trait_vtable_setup(void)
{
    CPyVTableItem DankOverloadedMethod_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_DankOverloadedMethod___coroutine,
        (CPyVTableItem)CPyDef_DankOverloadedMethod____add_fn,
    };
    memcpy(DankOverloadedMethod_vtable, DankOverloadedMethod_vtable_scratch, sizeof(DankOverloadedMethod_vtable));
    return 1;
}

static PyObject *
DankOverloadedMethod_get_methods(dank_mids___brownie_patch___types___DankOverloadedMethodObject *self, void *closure);
static int
DankOverloadedMethod_set_methods(dank_mids___brownie_patch___types___DankOverloadedMethodObject *self, PyObject *value, void *closure);

static PyGetSetDef DankOverloadedMethod_getseters[] = {
    {"methods",
     (getter)DankOverloadedMethod_get_methods, (setter)DankOverloadedMethod_set_methods,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef DankOverloadedMethod_methods[] = {
    {"coroutine",
     (PyCFunction)CPyPy_DankOverloadedMethod___coroutine,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"_add_fn",
     (PyCFunction)CPyPy_DankOverloadedMethod____add_fn,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_DankOverloadedMethod_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "DankOverloadedMethod",
    .tp_new = DankOverloadedMethod_new,
    .tp_dealloc = (destructor)DankOverloadedMethod_dealloc,
    .tp_traverse = (traverseproc)DankOverloadedMethod_traverse,
    .tp_clear = (inquiry)DankOverloadedMethod_clear,
    .tp_getset = DankOverloadedMethod_getseters,
    .tp_methods = DankOverloadedMethod_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___types___DankOverloadedMethodObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_DankOverloadedMethod_template = &CPyType_DankOverloadedMethod_template_;

static PyObject *
DankOverloadedMethod_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___types___DankOverloadedMethodObject *self;
    self = (dank_mids___brownie_patch___types___DankOverloadedMethodObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = DankOverloadedMethod_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_DankOverloadedMethod(PyObject *cpy_r_args, PyObject *cpy_r_kwargs)
{
    PyObject *self = DankOverloadedMethod_setup(CPyType_DankOverloadedMethod);
    if (self == NULL)
        return NULL;
    int res = CPyType_DankOverloadedMethod->tp_init(self, cpy_r_args, cpy_r_kwargs);
    if (res < 0) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
DankOverloadedMethod_get_methods(dank_mids___brownie_patch___types___DankOverloadedMethodObject *self, void *closure)
{
    if (unlikely(self->_methods == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'methods' of 'DankOverloadedMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->_methods);
    PyObject *retval = self->_methods;
    return retval;
}

static int
DankOverloadedMethod_set_methods(dank_mids___brownie_patch___types___DankOverloadedMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'DankOverloadedMethod' object attribute 'methods' cannot be deleted");
        return -1;
    }
    if (self->_methods != NULL) {
        CPy_DECREF(self->_methods);
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
    self->_methods = tmp;
    return 0;
}

static PyObject *coroutine_DankOverloadedMethod_env_setup(PyTypeObject *type);
PyObject *CPyDef_coroutine_DankOverloadedMethod_env(void);

static PyObject *
coroutine_DankOverloadedMethod_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_coroutine_DankOverloadedMethod_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return coroutine_DankOverloadedMethod_env_setup(type);
}

static int
coroutine_DankOverloadedMethod_env_traverse(dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_self);
    Py_VISIT(self->_args);
    Py_VISIT(self->_block_identifier);
    Py_VISIT(self->_decimals);
    Py_VISIT(self->_override);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->_call);
    Py_VISIT(self->___mypyc_temp__0);
    Py_VISIT(self->___mypyc_temp__1.f0);
    Py_VISIT(self->___mypyc_temp__1.f1);
    Py_VISIT(self->___mypyc_temp__1.f2);
    return 0;
}

static int
coroutine_DankOverloadedMethod_env_clear(dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_self);
    Py_CLEAR(self->_args);
    Py_CLEAR(self->_block_identifier);
    Py_CLEAR(self->_decimals);
    Py_CLEAR(self->_override);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_call);
    Py_CLEAR(self->___mypyc_temp__0);
    Py_CLEAR(self->___mypyc_temp__1.f0);
    Py_CLEAR(self->___mypyc_temp__1.f1);
    Py_CLEAR(self->___mypyc_temp__1.f2);
    return 0;
}

static void
coroutine_DankOverloadedMethod_env_dealloc(dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, coroutine_DankOverloadedMethod_env_dealloc)
    coroutine_DankOverloadedMethod_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem coroutine_DankOverloadedMethod_env_vtable[1];
static bool
CPyDef_coroutine_DankOverloadedMethod_env_trait_vtable_setup(void)
{
    CPyVTableItem coroutine_DankOverloadedMethod_env_vtable_scratch[] = {
        NULL
    };
    memcpy(coroutine_DankOverloadedMethod_env_vtable, coroutine_DankOverloadedMethod_env_vtable_scratch, sizeof(coroutine_DankOverloadedMethod_env_vtable));
    return 1;
}

static PyMethodDef coroutine_DankOverloadedMethod_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_coroutine_DankOverloadedMethod_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "coroutine_DankOverloadedMethod_env",
    .tp_new = coroutine_DankOverloadedMethod_env_new,
    .tp_dealloc = (destructor)coroutine_DankOverloadedMethod_env_dealloc,
    .tp_traverse = (traverseproc)coroutine_DankOverloadedMethod_env_traverse,
    .tp_clear = (inquiry)coroutine_DankOverloadedMethod_env_clear,
    .tp_methods = coroutine_DankOverloadedMethod_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_coroutine_DankOverloadedMethod_env_template = &CPyType_coroutine_DankOverloadedMethod_env_template_;

static PyObject *
coroutine_DankOverloadedMethod_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *self;
    self = (dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = coroutine_DankOverloadedMethod_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__1 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_env(void)
{
    PyObject *self = coroutine_DankOverloadedMethod_env_setup(CPyType_coroutine_DankOverloadedMethod_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods coroutine_DankOverloadedMethod_gen_as_async = {
    .am_await = CPyDef_coroutine_DankOverloadedMethod_gen_____await__,
};
static PyObject *coroutine_DankOverloadedMethod_gen_setup(PyTypeObject *type);
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen(void);

static PyObject *
coroutine_DankOverloadedMethod_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_coroutine_DankOverloadedMethod_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return coroutine_DankOverloadedMethod_gen_setup(type);
}

static int
coroutine_DankOverloadedMethod_gen_traverse(dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
coroutine_DankOverloadedMethod_gen_clear(dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
coroutine_DankOverloadedMethod_gen_dealloc(dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, coroutine_DankOverloadedMethod_gen_dealloc)
    coroutine_DankOverloadedMethod_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem coroutine_DankOverloadedMethod_gen_vtable[7];
static bool
CPyDef_coroutine_DankOverloadedMethod_gen_trait_vtable_setup(void)
{
    CPyVTableItem coroutine_DankOverloadedMethod_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_coroutine_DankOverloadedMethod_gen_____next__,
        (CPyVTableItem)CPyDef_coroutine_DankOverloadedMethod_gen___send,
        (CPyVTableItem)CPyDef_coroutine_DankOverloadedMethod_gen_____iter__,
        (CPyVTableItem)CPyDef_coroutine_DankOverloadedMethod_gen___throw,
        (CPyVTableItem)CPyDef_coroutine_DankOverloadedMethod_gen___close,
        (CPyVTableItem)CPyDef_coroutine_DankOverloadedMethod_gen_____await__,
    };
    memcpy(coroutine_DankOverloadedMethod_gen_vtable, coroutine_DankOverloadedMethod_gen_vtable_scratch, sizeof(coroutine_DankOverloadedMethod_gen_vtable));
    return 1;
}

static PyMethodDef coroutine_DankOverloadedMethod_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy_coroutine_DankOverloadedMethod_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy_coroutine_DankOverloadedMethod_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_coroutine_DankOverloadedMethod_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy_coroutine_DankOverloadedMethod_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy_coroutine_DankOverloadedMethod_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy_coroutine_DankOverloadedMethod_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_coroutine_DankOverloadedMethod_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "coroutine_DankOverloadedMethod_gen",
    .tp_new = coroutine_DankOverloadedMethod_gen_new,
    .tp_dealloc = (destructor)coroutine_DankOverloadedMethod_gen_dealloc,
    .tp_traverse = (traverseproc)coroutine_DankOverloadedMethod_gen_traverse,
    .tp_clear = (inquiry)coroutine_DankOverloadedMethod_gen_clear,
    .tp_methods = coroutine_DankOverloadedMethod_gen_methods,
    .tp_iter = CPyDef_coroutine_DankOverloadedMethod_gen_____iter__,
    .tp_iternext = CPyDef_coroutine_DankOverloadedMethod_gen_____next__,
    .tp_as_async = &coroutine_DankOverloadedMethod_gen_as_async,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_coroutine_DankOverloadedMethod_gen_template = &CPyType_coroutine_DankOverloadedMethod_gen_template_;

static PyObject *
coroutine_DankOverloadedMethod_gen_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *self;
    self = (dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = coroutine_DankOverloadedMethod_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_gen(void)
{
    PyObject *self = coroutine_DankOverloadedMethod_gen_setup(CPyType_coroutine_DankOverloadedMethod_gen);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {"_get_method_object", (PyCFunction)CPyPy__get_method_object, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids.brownie_patch.types",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids___brownie_patch___types(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids___brownie_patch___types_internal) {
        Py_INCREF(CPyModule_dank_mids___brownie_patch___types_internal);
        return CPyModule_dank_mids___brownie_patch___types_internal;
    }
    CPyModule_dank_mids___brownie_patch___types_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids___brownie_patch___types_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids___brownie_patch___types_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids___brownie_patch___types_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType_coroutine_DankOverloadedMethod_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_coroutine_DankOverloadedMethod_env_template, NULL, modname);
    if (unlikely(!CPyType_coroutine_DankOverloadedMethod_env))
        goto fail;
    CPyType_coroutine_DankOverloadedMethod_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_coroutine_DankOverloadedMethod_gen_template, NULL, modname);
    if (unlikely(!CPyType_coroutine_DankOverloadedMethod_gen))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids___brownie_patch___types_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids___brownie_patch___types_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_DankContractCall);
    Py_CLEAR(CPyType_DankContractTx);
    Py_CLEAR(CPyType_DankOverloadedMethod);
    Py_CLEAR(CPyType_coroutine_DankOverloadedMethod_env);
    Py_CLEAR(CPyType_coroutine_DankOverloadedMethod_gen);
    return NULL;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
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
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    tuple_T3OOO cpy_r_r39;
    char cpy_r_r40;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    char cpy_r_r43;
    char cpy_r_r44;
    tuple_T3OOO cpy_r_r45;
    char cpy_r_r46;
    tuple_T3OOO cpy_r_r47;
    tuple_T3OOO cpy_r_r48;
    char cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    char cpy_r_r53;
    char cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_gen", "__mypyc_env__", 56, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_INCREF(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_next_label__;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "__mypyc_next_label__", 56, CPyStatic_globals);
        goto CPyL65;
    }
    CPyTagged_INCREF(cpy_r_r3);
    goto CPyL59;
CPyL2: ;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_type != cpy_r_r4;
    if (cpy_r_r5) {
        goto CPyL66;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r6 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_self;
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "self", 74, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF(cpy_r_r6);
CPyL6: ;
    cpy_r_r7 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "args", 74, CPyStatic_globals);
        goto CPyL67;
    }
    CPy_INCREF(cpy_r_r7);
CPyL7: ;
    cpy_r_r8 = CPyStatics[3]; /* '_get_fn_from_args' */
    PyObject *cpy_r_r9[2] = {cpy_r_r6, cpy_r_r7};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r10, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 74, CPyStatic_globals);
        goto CPyL68;
    }
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r7);
    if (Py_TYPE(cpy_r_r11) == CPyType_DankContractCall)
        cpy_r_r12 = cpy_r_r11;
    else {
        cpy_r_r12 = NULL;
    }
    if (cpy_r_r12 != NULL) goto __LL1;
    if (Py_TYPE(cpy_r_r11) == CPyType_DankContractTx)
        cpy_r_r12 = cpy_r_r11;
    else {
        cpy_r_r12 = NULL;
    }
    if (cpy_r_r12 != NULL) goto __LL1;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/types.py", "coroutine", 74, CPyStatic_globals, "union[dank_mids.brownie_patch.types.DankContractCall, dank_mids.brownie_patch.types.DankContractTx]", cpy_r_r11);
    goto CPyL65;
__LL1: ;
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_call != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_call);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_call = cpy_r_r12;
    cpy_r_r13 = 1;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 74, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r14 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "call", 75, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF(cpy_r_r14);
CPyL11: ;
    cpy_r_r15 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "args", 76, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF(cpy_r_r15);
CPyL12: ;
    cpy_r_r16 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_block_identifier;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "block_identifier", 76, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_INCREF(cpy_r_r16);
CPyL13: ;
    cpy_r_r17 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_decimals;
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "decimals", 76, CPyStatic_globals);
        goto CPyL71;
    }
    CPy_INCREF(cpy_r_r17);
CPyL14: ;
    cpy_r_r18 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->_override;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "override", 76, CPyStatic_globals);
        goto CPyL72;
    }
    CPy_INCREF(cpy_r_r18);
CPyL15: ;
    cpy_r_r19 = CPyStatics[4]; /* 'coroutine' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r19);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r21 = PyList_New(0);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r22 = CPyList_Extend(cpy_r_r21, cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL75;
    } else
        goto CPyL76;
CPyL18: ;
    cpy_r_r23 = CPyStatics[5]; /* 'block_identifier' */
    cpy_r_r24 = CPyStatics[6]; /* 'decimals' */
    cpy_r_r25 = CPyStatics[7]; /* 'override' */
    cpy_r_r26 = PyList_AsTuple(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r27 = CPyDict_Build(3, cpy_r_r23, cpy_r_r16, cpy_r_r24, cpy_r_r17, cpy_r_r25, cpy_r_r18);
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r17);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r28 = PyObject_Call(cpy_r_r20, cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r29 = CPy_GetCoro(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL65;
    }
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__0);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__0 = cpy_r_r29;
    cpy_r_r30 = 1;
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r31 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "__mypyc_temp__0", -1, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF(cpy_r_r31);
CPyL24: ;
    cpy_r_r32 = CPyIter_Next(cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    if (cpy_r_r32 == NULL) {
        goto CPyL79;
    } else
        goto CPyL27;
CPyL25: ;
    cpy_r_r33 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r34 = cpy_r_r33;
    goto CPyL56;
CPyL27: ;
    cpy_r_r35 = cpy_r_r32;
CPyL28: ;
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_next_label__ = 2;
    cpy_r_r36 = 1;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL81;
    } else
        goto CPyL82;
CPyL29: ;
    return cpy_r_r35;
CPyL30: ;
    cpy_r_r37 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r38 = cpy_r_type != cpy_r_r37;
    if (!cpy_r_r38) goto CPyL33;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL34;
    } else
        goto CPyL83;
CPyL32: ;
    CPy_Unreachable();
CPyL33: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL51;
CPyL34: ;
    cpy_r_r39 = CPy_CatchError();
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__1.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__1.f0);
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__1.f1);
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__1.f2);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__1 = cpy_r_r39;
    cpy_r_r40 = 1;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r41 = (PyObject **)&cpy_r_r1;
    cpy_r_r42 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "__mypyc_temp__0", -1, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_INCREF(cpy_r_r42);
CPyL36: ;
    cpy_r_r43 = CPy_YieldFromErrorHandle(cpy_r_r42, cpy_r_r41);
    CPy_DecRef(cpy_r_r42);
    if (unlikely(cpy_r_r43 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL84;
    }
    if (cpy_r_r43) goto CPyL43;
    if (cpy_r_r1 != NULL) goto CPyL41;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r44 = 0;
    if (unlikely(!cpy_r_r44)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL85;
CPyL40: ;
    CPy_Unreachable();
CPyL41: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r35 = cpy_r_r1;
    cpy_r_r45 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r45.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "__mypyc_temp__1", -1, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF(cpy_r_r45.f0);
    CPy_INCREF(cpy_r_r45.f1);
    CPy_INCREF(cpy_r_r45.f2);
CPyL42: ;
    CPy_RestoreExcInfo(cpy_r_r45);
    CPy_DecRef(cpy_r_r45.f0);
    CPy_DecRef(cpy_r_r45.f1);
    CPy_DecRef(cpy_r_r45.f2);
    goto CPyL28;
CPyL43: ;
    if (cpy_r_r1 != NULL) goto CPyL46;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r46 = 0;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL87;
CPyL45: ;
    CPy_Unreachable();
CPyL46: ;
    cpy_r_r34 = cpy_r_r1;
    cpy_r_r47 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r47.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "__mypyc_temp__1", -1, CPyStatic_globals);
        goto CPyL88;
    }
    CPy_INCREF(cpy_r_r47.f0);
    CPy_INCREF(cpy_r_r47.f1);
    CPy_INCREF(cpy_r_r47.f2);
CPyL47: ;
    CPy_RestoreExcInfo(cpy_r_r47);
    CPy_DecRef(cpy_r_r47.f0);
    CPy_DecRef(cpy_r_r47.f1);
    CPy_DecRef(cpy_r_r47.f2);
    goto CPyL56;
CPyL48: ;
    cpy_r_r48 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r48.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__1' of 'coroutine_DankOverloadedMethod_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r48.f0);
        CPy_INCREF(cpy_r_r48.f1);
        CPy_INCREF(cpy_r_r48.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r48.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL63;
    }
CPyL49: ;
    CPy_RestoreExcInfo(cpy_r_r48);
    CPy_DecRef(cpy_r_r48.f0);
    CPy_DecRef(cpy_r_r48.f1);
    CPy_DecRef(cpy_r_r48.f2);
    cpy_r_r49 = CPy_KeepPropagating();
    if (!cpy_r_r49) goto CPyL63;
    CPy_Unreachable();
CPyL51: ;
    cpy_r_r50 = ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "coroutine", "coroutine_DankOverloadedMethod_env", "__mypyc_temp__0", -1, CPyStatic_globals);
        goto CPyL89;
    }
    CPy_INCREF(cpy_r_r50);
CPyL52: ;
    cpy_r_r51 = CPyIter_Send(cpy_r_r50, cpy_r_arg);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r51 == NULL) goto CPyL90;
    cpy_r_r35 = cpy_r_r51;
    goto CPyL28;
CPyL54: ;
    cpy_r_r52 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r34 = cpy_r_r52;
CPyL56: ;
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r53 = 1;
    CPy_DECREF(cpy_r_r2);
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 75, CPyStatic_globals);
        goto CPyL91;
    }
    CPyGen_SetStopIterationValue(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (!0) goto CPyL63;
    CPy_Unreachable();
CPyL59: ;
    cpy_r_r54 = cpy_r_r3 == 0;
    if (cpy_r_r54) goto CPyL92;
    cpy_r_r55 = cpy_r_r3 == 2;
    CPyTagged_DECREF(cpy_r_r3);
    if (cpy_r_r55) {
        goto CPyL30;
    } else
        goto CPyL93;
CPyL61: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_Unreachable();
CPyL63: ;
    cpy_r_r57 = NULL;
    return cpy_r_r57;
CPyL64: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL63;
CPyL65: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL63;
CPyL66: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL3;
CPyL67: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    goto CPyL63;
CPyL68: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL63;
CPyL69: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r14);
    goto CPyL63;
CPyL70: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    goto CPyL63;
CPyL71: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL63;
CPyL72: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r17);
    goto CPyL63;
CPyL73: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r18);
    goto CPyL63;
CPyL74: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r20);
    goto CPyL63;
CPyL75: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r21);
    goto CPyL63;
CPyL76: ;
    CPy_DECREF(cpy_r_r22);
    goto CPyL18;
CPyL77: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r20);
    goto CPyL63;
CPyL78: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r26);
    goto CPyL63;
CPyL79: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL25;
CPyL80: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL63;
CPyL81: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL34;
CPyL82: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL29;
CPyL83: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL32;
CPyL84: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL48;
CPyL85: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL40;
CPyL86: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r35);
    goto CPyL48;
CPyL87: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL45;
CPyL88: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL48;
CPyL89: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_arg);
    goto CPyL63;
CPyL90: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL54;
CPyL91: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL63;
CPyL92: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL2;
CPyL93: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL61;
}

PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", "arg", 0};
    static CPyArg_Parser parser = {"OOOO:__mypyc_generator_helper__", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value;
    PyObject *obj_traceback;
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_type = obj_type;
    PyObject *arg_value = obj_value;
    PyObject *arg_traceback = obj_traceback;
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine_DankOverloadedMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.types.coroutine_DankOverloadedMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine_DankOverloadedMethod_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine_DankOverloadedMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.types.coroutine_DankOverloadedMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_coroutine_DankOverloadedMethod_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine_DankOverloadedMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.types.coroutine_DankOverloadedMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine_DankOverloadedMethod_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine_DankOverloadedMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.types.coroutine_DankOverloadedMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef_coroutine_DankOverloadedMethod_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[8]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_coroutine_DankOverloadedMethod_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[9]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp2 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp2);
    PyObject *__tmp3 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp3);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine_DankOverloadedMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.types.coroutine_DankOverloadedMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine_DankOverloadedMethod_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine_DankOverloadedMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.types.coroutine_DankOverloadedMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine_DankOverloadedMethod_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_DankOverloadedMethod___coroutine(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    if (cpy_r_block_identifier != NULL) goto CPyL17;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_block_identifier = cpy_r_r0;
CPyL2: ;
    if (cpy_r_decimals != NULL) goto CPyL18;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_decimals = cpy_r_r1;
CPyL4: ;
    if (cpy_r_override != NULL) goto CPyL19;
    cpy_r_r2 = Py_None;
    CPy_INCREF(cpy_r_r2);
    cpy_r_override = cpy_r_r2;
CPyL6: ;
    cpy_r_r3 = CPyDef_coroutine_DankOverloadedMethod_env();
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_INCREF(cpy_r_self);
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_self != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_self);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_self = cpy_r_self;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_INCREF(cpy_r_args);
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_args != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_args);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_args = cpy_r_args;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL21;
    }
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_block_identifier != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_block_identifier);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_block_identifier = cpy_r_block_identifier;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL22;
    }
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_decimals != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_decimals);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_decimals = cpy_r_decimals;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL23;
    }
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_override != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_override);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->_override = cpy_r_override;
    cpy_r_r8 = 1;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r9 = CPyDef_coroutine_DankOverloadedMethod_gen();
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL24;
    }
    CPy_INCREF(cpy_r_r3);
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *)cpy_r_r9)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *)cpy_r_r9)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject *)cpy_r_r9)->___mypyc_env__ = cpy_r_r3;
    cpy_r_r10 = 1;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL25;
    }
    if (((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject *)cpy_r_r3)->___mypyc_next_label__ = 0;
    cpy_r_r11 = 1;
    CPy_DECREF(cpy_r_r3);
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
        goto CPyL26;
    }
    return cpy_r_r9;
CPyL16: ;
    cpy_r_r12 = NULL;
    return cpy_r_r12;
CPyL17: ;
    CPy_INCREF(cpy_r_block_identifier);
    goto CPyL2;
CPyL18: ;
    CPy_INCREF(cpy_r_decimals);
    goto CPyL4;
CPyL19: ;
    CPy_INCREF(cpy_r_override);
    goto CPyL6;
CPyL20: ;
    CPy_DecRef(cpy_r_block_identifier);
    CPy_DecRef(cpy_r_decimals);
    CPy_DecRef(cpy_r_override);
    goto CPyL16;
CPyL21: ;
    CPy_DecRef(cpy_r_block_identifier);
    CPy_DecRef(cpy_r_decimals);
    CPy_DecRef(cpy_r_override);
    CPy_DecRef(cpy_r_r3);
    goto CPyL16;
CPyL22: ;
    CPy_DecRef(cpy_r_decimals);
    CPy_DecRef(cpy_r_override);
    CPy_DecRef(cpy_r_r3);
    goto CPyL16;
CPyL23: ;
    CPy_DecRef(cpy_r_override);
    CPy_DecRef(cpy_r_r3);
    goto CPyL16;
CPyL24: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL16;
CPyL25: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r9);
    goto CPyL16;
CPyL26: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL16;
}

PyObject *CPyPy_DankOverloadedMethod___coroutine(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"block_identifier", "decimals", "override", 0};
    static CPyArg_Parser parser = {"%|$OOO:coroutine", kwlist, 0};
    PyObject *obj_args;
    PyObject *obj_block_identifier = NULL;
    PyObject *obj_decimals = NULL;
    PyObject *obj_override = NULL;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_args, NULL, &obj_block_identifier, &obj_decimals, &obj_override)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_DankOverloadedMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.brownie_patch.types.DankOverloadedMethod", obj_self); 
        goto fail;
    }
    PyObject *arg_args = obj_args;
    PyObject *arg_block_identifier;
    if (obj_block_identifier == NULL) {
        arg_block_identifier = NULL;
        goto __LL4;
    }
    if (PyLong_Check(obj_block_identifier))
        arg_block_identifier = obj_block_identifier;
    else {
        arg_block_identifier = NULL;
    }
    if (arg_block_identifier != NULL) goto __LL4;
    if (obj_block_identifier == Py_None)
        arg_block_identifier = obj_block_identifier;
    else {
        arg_block_identifier = NULL;
    }
    if (arg_block_identifier != NULL) goto __LL4;
    CPy_TypeError("int or None", obj_block_identifier); 
    goto fail;
__LL4: ;
    PyObject *arg_decimals;
    if (obj_decimals == NULL) {
        arg_decimals = NULL;
        goto __LL5;
    }
    if (PyLong_Check(obj_decimals))
        arg_decimals = obj_decimals;
    else {
        arg_decimals = NULL;
    }
    if (arg_decimals != NULL) goto __LL5;
    if (obj_decimals == Py_None)
        arg_decimals = obj_decimals;
    else {
        arg_decimals = NULL;
    }
    if (arg_decimals != NULL) goto __LL5;
    CPy_TypeError("int or None", obj_decimals); 
    goto fail;
__LL5: ;
    PyObject *arg_override;
    if (obj_override == NULL) {
        arg_override = NULL;
        goto __LL6;
    }
    if (PyDict_Check(obj_override))
        arg_override = obj_override;
    else {
        arg_override = NULL;
    }
    if (arg_override != NULL) goto __LL6;
    if (obj_override == Py_None)
        arg_override = obj_override;
    else {
        arg_override = NULL;
    }
    if (arg_override != NULL) goto __LL6;
    CPy_TypeError("dict or None", obj_override); 
    goto fail;
__LL6: ;
    PyObject *retval = CPyDef_DankOverloadedMethod___coroutine(arg_self, arg_args, arg_block_identifier, arg_decimals, arg_override);
    CPy_DECREF(obj_args);
    return retval;
fail: ;
    CPy_DECREF(obj_args);
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "coroutine", 56, CPyStatic_globals);
    return NULL;
}

char CPyDef_DankOverloadedMethod____add_fn(PyObject *cpy_r_self, PyObject *cpy_r_abi, PyObject *cpy_r_natspec) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
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
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    int32_t cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    cpy_r_r0 = CPyStatics[10]; /* '_address' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 90, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r2 = CPyStatics[11]; /* '_name' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_self, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 90, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r4 = CPyStatics[12]; /* '_owner' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_self, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 90, CPyStatic_globals);
        goto CPyL22;
    }
    if (likely(PyUnicode_Check(cpy_r_r1)))
        cpy_r_r6 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 90, CPyStatic_globals, "str", cpy_r_r1);
        goto CPyL23;
    }
    if (likely(PyUnicode_Check(cpy_r_r3)))
        cpy_r_r7 = cpy_r_r3;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 90, CPyStatic_globals, "str", cpy_r_r3);
        goto CPyL24;
    }
    cpy_r_r8 = CPyDef__get_method_object(cpy_r_r6, cpy_r_abi, cpy_r_r7, cpy_r_r5, cpy_r_natspec);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 90, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r9 = PyList_New(0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 91, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r10 = CPyStatics[13]; /* 'inputs' */
    cpy_r_r11 = CPyDict_GetItem(cpy_r_abi, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 91, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r12 = PyObject_GetIter(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 91, CPyStatic_globals);
        goto CPyL26;
    }
CPyL9: ;
    cpy_r_r13 = PyIter_Next(cpy_r_r12);
    if (cpy_r_r13 == NULL) goto CPyL27;
    cpy_r_r14 = CPyStatics[14]; /* 'type' */
    cpy_r_r15 = PyObject_GetItem(cpy_r_r13, cpy_r_r14);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 91, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r16 = CPyStatics[15]; /* '256' */
    cpy_r_r17 = CPyStatics[16]; /* '' */
    cpy_r_r18 = CPyStatics[17]; /* 'replace' */
    PyObject *cpy_r_r19[3] = {cpy_r_r15, cpy_r_r16, cpy_r_r17};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = PyObject_VectorcallMethod(cpy_r_r18, cpy_r_r20, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 91, CPyStatic_globals);
        goto CPyL29;
    }
    CPy_DECREF(cpy_r_r15);
    cpy_r_r22 = PyList_Append(cpy_r_r9, cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 91, CPyStatic_globals);
        goto CPyL28;
    } else
        goto CPyL9;
CPyL13: ;
    cpy_r_r24 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 91, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r25 = PyList_AsTuple(cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 91, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r26 = ((dank_mids___brownie_patch___types___DankOverloadedMethodObject *)cpy_r_self)->_methods;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/types.py", "_add_fn", "DankOverloadedMethod", "methods", 92, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_INCREF(cpy_r_r26);
CPyL16: ;
    cpy_r_r27 = CPyDict_SetItem(cpy_r_r26, cpy_r_r25, cpy_r_r8);
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r28 = cpy_r_r27 >= 0;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 92, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r29 = CPyStatics[18]; /* 'natspec' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_self, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 93, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r31 = CPyStatics[19]; /* 'update' */
    PyObject *cpy_r_r32[2] = {cpy_r_r30, cpy_r_natspec};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = PyObject_VectorcallMethod(cpy_r_r31, cpy_r_r33, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 93, CPyStatic_globals);
        goto CPyL31;
    } else
        goto CPyL32;
CPyL19: ;
    CPy_DECREF(cpy_r_r30);
    return 1;
CPyL20: ;
    cpy_r_r35 = 2;
    return cpy_r_r35;
CPyL21: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL20;
CPyL22: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    goto CPyL20;
CPyL23: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r5);
    goto CPyL20;
CPyL24: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    goto CPyL20;
CPyL25: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL20;
CPyL26: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    goto CPyL20;
CPyL27: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL13;
CPyL28: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r12);
    goto CPyL20;
CPyL29: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r15);
    goto CPyL20;
CPyL30: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r25);
    goto CPyL20;
CPyL31: ;
    CPy_DecRef(cpy_r_r30);
    goto CPyL20;
CPyL32: ;
    CPy_DECREF(cpy_r_r34);
    goto CPyL19;
}

PyObject *CPyPy_DankOverloadedMethod____add_fn(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"abi", "natspec", 0};
    static CPyArg_Parser parser = {"OO:_add_fn", kwlist, 0};
    PyObject *obj_abi;
    PyObject *obj_natspec;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi, &obj_natspec)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_DankOverloadedMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.brownie_patch.types.DankOverloadedMethod", obj_self); 
        goto fail;
    }
    PyObject *arg_abi;
    if (likely(PyDict_Check(obj_abi)))
        arg_abi = obj_abi;
    else {
        CPy_TypeError("dict", obj_abi); 
        goto fail;
    }
    PyObject *arg_natspec;
    if (likely(PyDict_Check(obj_natspec)))
        arg_natspec = obj_natspec;
    else {
        CPy_TypeError("dict", obj_natspec); 
        goto fail;
    }
    char retval = CPyDef_DankOverloadedMethod____add_fn(arg_self, arg_abi, arg_natspec);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_add_fn", 79, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__get_method_object(PyObject *cpy_r_address, PyObject *cpy_r_abi, PyObject *cpy_r_name, PyObject *cpy_r_owner, PyObject *cpy_r_natspec) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_constant;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    int32_t cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    cpy_r_r0 = CPyStatics[20]; /* 'constant' */
    cpy_r_r1 = PyDict_Contains(cpy_r_abi, cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 125, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r3 = cpy_r_r1;
    if (!cpy_r_r3) goto CPyL4;
    cpy_r_r4 = CPyStatics[20]; /* 'constant' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_abi, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 126, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_constant = cpy_r_r5;
    goto CPyL14;
CPyL4: ;
    cpy_r_r6 = CPyStatics[21]; /* 'stateMutability' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_abi, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 128, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r8 = CPyStatics[22]; /* 'view' */
    cpy_r_r9 = PyObject_RichCompare(cpy_r_r7, cpy_r_r8, 2);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", -1, CPyStatic_globals);
        goto CPyL24;
    }
    if (unlikely(!PyBool_Check(cpy_r_r9))) {
        CPy_TypeError("bool", cpy_r_r9); cpy_r_r10 = 2;
    } else
        cpy_r_r10 = cpy_r_r9 == Py_True;
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", -1, CPyStatic_globals);
        goto CPyL24;
    }
    if (!cpy_r_r10) goto CPyL9;
    cpy_r_r11 = cpy_r_r10;
    goto CPyL13;
CPyL9: ;
    cpy_r_r12 = CPyStatics[21]; /* 'stateMutability' */
    cpy_r_r13 = CPyDict_GetItem(cpy_r_abi, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 128, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r14 = CPyStatics[23]; /* 'pure' */
    cpy_r_r15 = PyObject_RichCompare(cpy_r_r13, cpy_r_r14, 2);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", -1, CPyStatic_globals);
        goto CPyL24;
    }
    if (unlikely(!PyBool_Check(cpy_r_r15))) {
        CPy_TypeError("bool", cpy_r_r15); cpy_r_r16 = 2;
    } else
        cpy_r_r16 = cpy_r_r15 == Py_True;
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", -1, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r11 = cpy_r_r16;
CPyL13: ;
    cpy_r_r17 = cpy_r_r11 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r17);
    cpy_r_constant = cpy_r_r17;
CPyL14: ;
    cpy_r_r18 = PyObject_IsTrue(cpy_r_constant);
    CPy_DECREF(cpy_r_constant);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 126, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r20 = cpy_r_r18;
    if (!cpy_r_r20) goto CPyL20;
    cpy_r_r21 = PyTuple_Pack(5, cpy_r_address, cpy_r_abi, cpy_r_name, cpy_r_owner, cpy_r_natspec);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 131, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r22 = PyDict_New();
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 131, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r23 = CPyDef_DankContractCall(cpy_r_r21, cpy_r_r22);
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 131, CPyStatic_globals);
        goto CPyL24;
    }
    return cpy_r_r23;
CPyL20: ;
    cpy_r_r24 = PyTuple_Pack(5, cpy_r_address, cpy_r_abi, cpy_r_name, cpy_r_owner, cpy_r_natspec);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 132, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r25 = PyDict_New();
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 132, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r26 = CPyDef_DankContractTx(cpy_r_r24, cpy_r_r25);
    CPy_DECREF(cpy_r_r24);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 132, CPyStatic_globals);
        goto CPyL24;
    }
    return cpy_r_r26;
CPyL24: ;
    cpy_r_r27 = NULL;
    return cpy_r_r27;
CPyL25: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL24;
CPyL26: ;
    CPy_DecRef(cpy_r_r24);
    goto CPyL24;
}

PyObject *CPyPy__get_method_object(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"address", "abi", "name", "owner", "natspec", 0};
    static CPyArg_Parser parser = {"OOOOO:_get_method_object", kwlist, 0};
    PyObject *obj_address;
    PyObject *obj_abi;
    PyObject *obj_name;
    PyObject *obj_owner;
    PyObject *obj_natspec;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_address, &obj_abi, &obj_name, &obj_owner, &obj_natspec)) {
        return NULL;
    }
    PyObject *arg_address;
    if (likely(PyUnicode_Check(obj_address)))
        arg_address = obj_address;
    else {
        CPy_TypeError("str", obj_address); 
        goto fail;
    }
    PyObject *arg_abi;
    if (likely(PyDict_Check(obj_abi)))
        arg_abi = obj_abi;
    else {
        CPy_TypeError("dict", obj_abi); 
        goto fail;
    }
    PyObject *arg_name;
    if (likely(PyUnicode_Check(obj_name)))
        arg_name = obj_name;
    else {
        CPy_TypeError("str", obj_name); 
        goto fail;
    }
    PyObject *arg_owner;
    arg_owner = obj_owner;
    if (arg_owner != NULL) goto __LL7;
    if (obj_owner == Py_None)
        arg_owner = obj_owner;
    else {
        arg_owner = NULL;
    }
    if (arg_owner != NULL) goto __LL7;
    CPy_TypeError("object or None", obj_owner); 
    goto fail;
__LL7: ;
    PyObject *arg_natspec;
    if (likely(PyDict_Check(obj_natspec)))
        arg_natspec = obj_natspec;
    else {
        CPy_TypeError("dict", obj_natspec); 
        goto fail;
    }
    PyObject *retval = CPyDef__get_method_object(arg_address, arg_abi, arg_name, arg_owner, arg_natspec);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/types.py", "_get_method_object", 106, CPyStatic_globals);
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
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    int32_t cpy_r_r30;
    char cpy_r_r31;
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
    tuple_T3OOO cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    int32_t cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    int32_t cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    int32_t cpy_r_r69;
    char cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    int32_t cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    int32_t cpy_r_r89;
    char cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    tuple_T2OO cpy_r_r96;
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
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    char cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    int32_t cpy_r_r122;
    char cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    int32_t cpy_r_r126;
    char cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    tuple_T3OOO cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    int32_t cpy_r_r139;
    char cpy_r_r140;
    char cpy_r_r141;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[24]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", -1, CPyStatic_globals);
        goto CPyL49;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[54]; /* ('Any', 'Dict', 'Optional', 'Tuple', 'TypeVar', 'Union',
                                  'final') */
    cpy_r_r6 = CPyStatics[32]; /* 'typing' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 1, CPyStatic_globals);
        goto CPyL49;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[55]; /* ('ContractCall', 'ContractTx', 'OverloadedMethod') */
    cpy_r_r10 = CPyStatics[36]; /* 'brownie.network.contract' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 3, CPyStatic_globals);
        goto CPyL49;
    }
    CPyModule_brownie___network___contract = cpy_r_r12;
    CPy_INCREF(CPyModule_brownie___network___contract);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[56]; /* ('AccountsType',) */
    cpy_r_r14 = CPyStatics[38]; /* 'brownie.typing' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 4, CPyStatic_globals);
        goto CPyL49;
    }
    CPyModule_brownie___typing = cpy_r_r16;
    CPy_INCREF(CPyModule_brownie___typing);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[57]; /* ('_DankMethod', '_DankMethodMixin', '_EVMType') */
    cpy_r_r18 = CPyStatics[42]; /* 'dank_mids.brownie_patch._method' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 6, CPyStatic_globals);
        goto CPyL49;
    }
    CPyModule_dank_mids___brownie_patch____method = cpy_r_r20;
    CPy_INCREF(CPyModule_dank_mids___brownie_patch____method);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[43]; /* '_T' */
    cpy_r_r22 = CPyStatic_globals;
    cpy_r_r23 = CPyStatics[29]; /* 'TypeVar' */
    cpy_r_r24 = CPyDict_GetItem(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 9, CPyStatic_globals);
        goto CPyL49;
    }
    PyObject *cpy_r_r25[1] = {cpy_r_r21};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = _PyObject_Vectorcall(cpy_r_r24, cpy_r_r26, 1, 0);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 9, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r28 = CPyStatic_globals;
    cpy_r_r29 = CPyStatics[43]; /* '_T' */
    cpy_r_r30 = CPyDict_SetItem(cpy_r_r28, cpy_r_r29, cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r31 = cpy_r_r30 >= 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 9, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r32 = CPyStatic_globals;
    cpy_r_r33 = CPyStatics[30]; /* 'Union' */
    cpy_r_r34 = CPyDict_GetItem(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 11, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyStatics[33]; /* 'ContractCall' */
    cpy_r_r37 = CPyDict_GetItem(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 11, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r38 = CPyStatic_globals;
    cpy_r_r39 = CPyStatics[34]; /* 'ContractTx' */
    cpy_r_r40 = CPyDict_GetItem(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 11, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r41 = CPyStatic_globals;
    cpy_r_r42 = CPyStatics[35]; /* 'OverloadedMethod' */
    cpy_r_r43 = CPyDict_GetItem(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 11, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r44.f0 = cpy_r_r37;
    cpy_r_r44.f1 = cpy_r_r40;
    cpy_r_r44.f2 = cpy_r_r43;
    cpy_r_r45 = PyTuple_New(3);
    if (unlikely(cpy_r_r45 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp8 = cpy_r_r44.f0;
    PyTuple_SET_ITEM(cpy_r_r45, 0, __tmp8);
    PyObject *__tmp9 = cpy_r_r44.f1;
    PyTuple_SET_ITEM(cpy_r_r45, 1, __tmp9);
    PyObject *__tmp10 = cpy_r_r44.f2;
    PyTuple_SET_ITEM(cpy_r_r45, 2, __tmp10);
    cpy_r_r46 = PyObject_GetItem(cpy_r_r34, cpy_r_r45);
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 11, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r47 = CPyStatic_globals;
    cpy_r_r48 = CPyStatics[44]; /* 'ContractMethod' */
    cpy_r_r49 = CPyDict_SetItem(cpy_r_r47, cpy_r_r48, cpy_r_r46);
    CPy_DECREF(cpy_r_r46);
    cpy_r_r50 = cpy_r_r49 >= 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 11, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r51 = CPyStatic_globals;
    cpy_r_r52 = CPyStatics[39]; /* '_DankMethod' */
    cpy_r_r53 = CPyDict_GetItem(cpy_r_r51, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 16, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r54 = CPyStatic_globals;
    cpy_r_r55 = CPyStatics[33]; /* 'ContractCall' */
    cpy_r_r56 = CPyDict_GetItem(cpy_r_r54, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 16, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r57 = PyTuple_Pack(2, cpy_r_r53, cpy_r_r56);
    CPy_DECREF(cpy_r_r53);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 16, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r58 = CPyStatics[45]; /* 'dank_mids.brownie_patch.types' */
    cpy_r_r59 = (PyObject *)CPyType_DankContractCall_template;
    cpy_r_r60 = CPyType_FromTemplate(cpy_r_r59, cpy_r_r57, cpy_r_r58);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 16, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r61 = CPyDef_DankContractCall_trait_vtable_setup();
    if (unlikely(cpy_r_r61 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", -1, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r62 = CPyStatics[46]; /* '__mypyc_attrs__' */
    cpy_r_r63 = CPyStatics[47]; /* '__dict__' */
    cpy_r_r64 = PyTuple_Pack(1, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 16, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r65 = PyObject_SetAttr(cpy_r_r60, cpy_r_r62, cpy_r_r64);
    CPy_DECREF(cpy_r_r64);
    cpy_r_r66 = cpy_r_r65 >= 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 16, CPyStatic_globals);
        goto CPyL54;
    }
    CPyType_DankContractCall = (PyTypeObject *)cpy_r_r60;
    CPy_INCREF(CPyType_DankContractCall);
    cpy_r_r67 = CPyStatic_globals;
    cpy_r_r68 = CPyStatics[48]; /* 'DankContractCall' */
    cpy_r_r69 = CPyDict_SetItem(cpy_r_r67, cpy_r_r68, cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r70 = cpy_r_r69 >= 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 16, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r71 = CPyStatic_globals;
    cpy_r_r72 = CPyStatics[39]; /* '_DankMethod' */
    cpy_r_r73 = CPyDict_GetItem(cpy_r_r71, cpy_r_r72);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 28, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r74 = CPyStatic_globals;
    cpy_r_r75 = CPyStatics[34]; /* 'ContractTx' */
    cpy_r_r76 = CPyDict_GetItem(cpy_r_r74, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 28, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r77 = PyTuple_Pack(2, cpy_r_r73, cpy_r_r76);
    CPy_DECREF(cpy_r_r73);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 28, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r78 = CPyStatics[45]; /* 'dank_mids.brownie_patch.types' */
    cpy_r_r79 = (PyObject *)CPyType_DankContractTx_template;
    cpy_r_r80 = CPyType_FromTemplate(cpy_r_r79, cpy_r_r77, cpy_r_r78);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 28, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r81 = CPyDef_DankContractTx_trait_vtable_setup();
    if (unlikely(cpy_r_r81 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", -1, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r82 = CPyStatics[46]; /* '__mypyc_attrs__' */
    cpy_r_r83 = CPyStatics[47]; /* '__dict__' */
    cpy_r_r84 = PyTuple_Pack(1, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 28, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r85 = PyObject_SetAttr(cpy_r_r80, cpy_r_r82, cpy_r_r84);
    CPy_DECREF(cpy_r_r84);
    cpy_r_r86 = cpy_r_r85 >= 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 28, CPyStatic_globals);
        goto CPyL56;
    }
    CPyType_DankContractTx = (PyTypeObject *)cpy_r_r80;
    CPy_INCREF(CPyType_DankContractTx);
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyStatics[49]; /* 'DankContractTx' */
    cpy_r_r89 = CPyDict_SetItem(cpy_r_r87, cpy_r_r88, cpy_r_r80);
    CPy_DECREF(cpy_r_r80);
    cpy_r_r90 = cpy_r_r89 >= 0;
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 28, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r91 = CPyStatic_globals;
    cpy_r_r92 = CPyStatics[30]; /* 'Union' */
    cpy_r_r93 = CPyDict_GetItem(cpy_r_r91, cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 39, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r94 = (PyObject *)CPyType_DankContractCall;
    cpy_r_r95 = (PyObject *)CPyType_DankContractTx;
    CPy_INCREF(cpy_r_r94);
    CPy_INCREF(cpy_r_r95);
    cpy_r_r96.f0 = cpy_r_r94;
    cpy_r_r96.f1 = cpy_r_r95;
    cpy_r_r97 = PyTuple_New(2);
    if (unlikely(cpy_r_r97 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp11 = cpy_r_r96.f0;
    PyTuple_SET_ITEM(cpy_r_r97, 0, __tmp11);
    PyObject *__tmp12 = cpy_r_r96.f1;
    PyTuple_SET_ITEM(cpy_r_r97, 1, __tmp12);
    cpy_r_r98 = PyObject_GetItem(cpy_r_r93, cpy_r_r97);
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r97);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 39, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r99 = CPyStatic_globals;
    cpy_r_r100 = CPyStatics[50]; /* '_NonOverloaded' */
    cpy_r_r101 = CPyDict_SetItem(cpy_r_r99, cpy_r_r100, cpy_r_r98);
    CPy_DECREF(cpy_r_r98);
    cpy_r_r102 = cpy_r_r101 >= 0;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 39, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r103 = CPyStatic_globals;
    cpy_r_r104 = CPyStatics[35]; /* 'OverloadedMethod' */
    cpy_r_r105 = CPyDict_GetItem(cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r106 = CPyStatic_globals;
    cpy_r_r107 = CPyStatics[40]; /* '_DankMethodMixin' */
    cpy_r_r108 = CPyDict_GetItem(cpy_r_r106, cpy_r_r107);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r109 = CPyStatic_globals;
    cpy_r_r110 = CPyStatics[43]; /* '_T' */
    cpy_r_r111 = CPyDict_GetItem(cpy_r_r109, cpy_r_r110);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r112 = PyObject_GetItem(cpy_r_r108, cpy_r_r111);
    CPy_DECREF(cpy_r_r108);
    CPy_DECREF(cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r113 = PyTuple_Pack(2, cpy_r_r105, cpy_r_r112);
    CPy_DECREF(cpy_r_r105);
    CPy_DECREF(cpy_r_r112);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r114 = CPyStatics[45]; /* 'dank_mids.brownie_patch.types' */
    cpy_r_r115 = (PyObject *)CPyType_DankOverloadedMethod_template;
    cpy_r_r116 = CPyType_FromTemplate(cpy_r_r115, cpy_r_r113, cpy_r_r114);
    CPy_DECREF(cpy_r_r113);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r117 = CPyDef_DankOverloadedMethod_trait_vtable_setup();
    if (unlikely(cpy_r_r117 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", -1, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r118 = CPyStatics[46]; /* '__mypyc_attrs__' */
    cpy_r_r119 = CPyStatics[51]; /* 'methods' */
    cpy_r_r120 = CPyStatics[47]; /* '__dict__' */
    cpy_r_r121 = PyTuple_Pack(2, cpy_r_r119, cpy_r_r120);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r122 = PyObject_SetAttr(cpy_r_r116, cpy_r_r118, cpy_r_r121);
    CPy_DECREF(cpy_r_r121);
    cpy_r_r123 = cpy_r_r122 >= 0;
    if (unlikely(!cpy_r_r123)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL59;
    }
    CPyType_DankOverloadedMethod = (PyTypeObject *)cpy_r_r116;
    CPy_INCREF(CPyType_DankOverloadedMethod);
    cpy_r_r124 = CPyStatic_globals;
    cpy_r_r125 = CPyStatics[52]; /* 'DankOverloadedMethod' */
    cpy_r_r126 = CPyDict_SetItem(cpy_r_r124, cpy_r_r125, cpy_r_r116);
    CPy_DECREF(cpy_r_r116);
    cpy_r_r127 = cpy_r_r126 >= 0;
    if (unlikely(!cpy_r_r127)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 44, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r128 = CPyStatic_globals;
    cpy_r_r129 = CPyStatics[30]; /* 'Union' */
    cpy_r_r130 = CPyDict_GetItem(cpy_r_r128, cpy_r_r129);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 96, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r131 = (PyObject *)CPyType_DankContractCall;
    cpy_r_r132 = (PyObject *)CPyType_DankContractTx;
    cpy_r_r133 = (PyObject *)CPyType_DankOverloadedMethod;
    CPy_INCREF(cpy_r_r131);
    CPy_INCREF(cpy_r_r132);
    CPy_INCREF(cpy_r_r133);
    cpy_r_r134.f0 = cpy_r_r131;
    cpy_r_r134.f1 = cpy_r_r132;
    cpy_r_r134.f2 = cpy_r_r133;
    cpy_r_r135 = PyTuple_New(3);
    if (unlikely(cpy_r_r135 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp13 = cpy_r_r134.f0;
    PyTuple_SET_ITEM(cpy_r_r135, 0, __tmp13);
    PyObject *__tmp14 = cpy_r_r134.f1;
    PyTuple_SET_ITEM(cpy_r_r135, 1, __tmp14);
    PyObject *__tmp15 = cpy_r_r134.f2;
    PyTuple_SET_ITEM(cpy_r_r135, 2, __tmp15);
    cpy_r_r136 = PyObject_GetItem(cpy_r_r130, cpy_r_r135);
    CPy_DECREF(cpy_r_r130);
    CPy_DECREF(cpy_r_r135);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 96, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r137 = CPyStatic_globals;
    cpy_r_r138 = CPyStatics[53]; /* 'DankContractMethod' */
    cpy_r_r139 = CPyDict_SetItem(cpy_r_r137, cpy_r_r138, cpy_r_r136);
    CPy_DECREF(cpy_r_r136);
    cpy_r_r140 = cpy_r_r139 >= 0;
    if (unlikely(!cpy_r_r140)) {
        CPy_AddTraceback("dank_mids/brownie_patch/types.py", "<module>", 96, CPyStatic_globals);
        goto CPyL49;
    }
    return 1;
CPyL49: ;
    cpy_r_r141 = 2;
    return cpy_r_r141;
CPyL50: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL49;
CPyL51: ;
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r37);
    goto CPyL49;
CPyL52: ;
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r40);
    goto CPyL49;
CPyL53: ;
    CPy_DecRef(cpy_r_r53);
    goto CPyL49;
CPyL54: ;
    CPy_DecRef(cpy_r_r60);
    goto CPyL49;
CPyL55: ;
    CPy_DecRef(cpy_r_r73);
    goto CPyL49;
CPyL56: ;
    CPy_DecRef(cpy_r_r80);
    goto CPyL49;
CPyL57: ;
    CPy_DecRef(cpy_r_r105);
    goto CPyL49;
CPyL58: ;
    CPy_DecRef(cpy_r_r105);
    CPy_DecRef(cpy_r_r108);
    goto CPyL49;
CPyL59: ;
    CPy_DecRef(cpy_r_r116);
    goto CPyL49;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___brownie_patch___types = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_brownie___network___contract = Py_None;
    CPyModule_brownie___typing = Py_None;
    CPyModule_dank_mids___brownie_patch____method = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[58];
const char * const CPyLit_Str[] = {
    "\005\021_get_fn_from_args\tcoroutine\020block_identifier\bdecimals\boverride",
    "\t\rGeneratorExit\rStopIteration\b_address\005_name\006_owner\006inputs\004type\003256\000",
    "\b\areplace\anatspec\006update\bconstant\017stateMutability\004view\004pure\bbuiltins",
    "\t\003Any\004Dict\bOptional\005Tuple\aTypeVar\005Union\005final\006typing\fContractCall",
    "\004\nContractTx\020OverloadedMethod\030brownie.network.contract\fAccountsType",
    "\004\016brownie.typing\v_DankMethod\020_DankMethodMixin\b_EVMType",
    "\003\037dank_mids.brownie_patch._method\002_T\016ContractMethod",
    "\003\035dank_mids.brownie_patch.types\017__mypyc_attrs__\b__dict__",
    "\004\020DankContractCall\016DankContractTx\016_NonOverloaded\amethods",
    "\002\024DankOverloadedMethod\022DankContractMethod",
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
    4, 7, 25, 26, 27, 28, 29, 30, 31, 3, 33, 34, 35, 1, 37, 3, 39, 40,
    41
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___brownie_patch___types_internal = NULL;
CPyModule *CPyModule_dank_mids___brownie_patch___types;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_brownie___network___contract;
CPyModule *CPyModule_brownie___typing;
CPyModule *CPyModule_dank_mids___brownie_patch____method;
PyTypeObject *CPyType_DankContractCall;
PyObject *CPyDef_DankContractCall(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyTypeObject *CPyType_DankContractTx;
PyObject *CPyDef_DankContractTx(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyTypeObject *CPyType_DankOverloadedMethod;
PyObject *CPyDef_DankOverloadedMethod(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyTypeObject *CPyType_coroutine_DankOverloadedMethod_env;
PyObject *CPyDef_coroutine_DankOverloadedMethod_env(void);
PyTypeObject *CPyType_coroutine_DankOverloadedMethod_gen;
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen(void);
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine_DankOverloadedMethod_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine_DankOverloadedMethod_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine_DankOverloadedMethod_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_DankOverloadedMethod___coroutine(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
PyObject *CPyPy_DankOverloadedMethod___coroutine(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_DankOverloadedMethod____add_fn(PyObject *cpy_r_self, PyObject *cpy_r_abi, PyObject *cpy_r_natspec);
PyObject *CPyPy_DankOverloadedMethod____add_fn(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__get_method_object(PyObject *cpy_r_address, PyObject *cpy_r_abi, PyObject *cpy_r_name, PyObject *cpy_r_owner, PyObject *cpy_r_natspec);
PyObject *CPyPy__get_method_object(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids___brownie_patch___types exports = {
    &CPyType_DankContractCall,
    &CPyDef_DankContractCall,
    &CPyType_DankContractTx,
    &CPyDef_DankContractTx,
    &CPyType_DankOverloadedMethod,
    &CPyDef_DankOverloadedMethod,
    &CPyType_coroutine_DankOverloadedMethod_env,
    &CPyDef_coroutine_DankOverloadedMethod_env,
    &CPyType_coroutine_DankOverloadedMethod_gen,
    &CPyDef_coroutine_DankOverloadedMethod_gen,
    &CPyDef_coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__,
    &CPyDef_coroutine_DankOverloadedMethod_gen_____next__,
    &CPyDef_coroutine_DankOverloadedMethod_gen___send,
    &CPyDef_coroutine_DankOverloadedMethod_gen_____iter__,
    &CPyDef_coroutine_DankOverloadedMethod_gen___throw,
    &CPyDef_coroutine_DankOverloadedMethod_gen___close,
    &CPyDef_coroutine_DankOverloadedMethod_gen_____await__,
    &CPyDef_DankOverloadedMethod___coroutine,
    &CPyDef_DankOverloadedMethod____add_fn,
    &CPyDef__get_method_object,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit_types__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids.brownie_patch.types__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids.brownie_patch.types__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids___brownie_patch___types(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids___brownie_patch___types, "dank_mids.brownie_patch.types__mypyc.init_dank_mids___brownie_patch___types", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids___brownie_patch___types", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
