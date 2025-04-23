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
#include "__native_call.h"
#include "__native_internal_call.h"

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
__mypyc_lambda__0_obj_traverse(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject *self, visitproc visit, void *arg)
{
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
__mypyc_lambda__0_obj_clear(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject *self)
{
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
__mypyc_lambda__0_obj_dealloc(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject *self)
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
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType___mypyc_lambda__0_obj_template = &CPyType___mypyc_lambda__0_obj_template_;

static PyObject *
__mypyc_lambda__0_obj_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject *self;
    self = (dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject *)type->tp_alloc(type, 0);
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


static PyObject *CPyDunder___get____mypyc_lambda__1_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__1_obj_____get__(self, instance, owner);
}
static PyObject *__mypyc_lambda__1_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__1_obj(void);

static PyObject *
__mypyc_lambda__1_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__1_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__1_obj_setup(type);
}

static int
__mypyc_lambda__1_obj_traverse(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject *self, visitproc visit, void *arg)
{
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
__mypyc_lambda__1_obj_clear(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject *self)
{
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
__mypyc_lambda__1_obj_dealloc(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__1_obj_dealloc)
    __mypyc_lambda__1_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__1_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__1_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__1_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__1_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__1_obj_____get__,
    };
    memcpy(__mypyc_lambda__1_obj_vtable, __mypyc_lambda__1_obj_vtable_scratch, sizeof(__mypyc_lambda__1_obj_vtable));
    return 1;
}


static PyGetSetDef __mypyc_lambda__1_obj_getseters[] = {
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__1_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__1_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__1_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__1_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__1_obj",
    .tp_new = __mypyc_lambda__1_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__1_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__1_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__1_obj_clear,
    .tp_getset = __mypyc_lambda__1_obj_getseters,
    .tp_methods = __mypyc_lambda__1_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__1_obj,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType___mypyc_lambda__1_obj_template = &CPyType___mypyc_lambda__1_obj_template_;

static PyObject *
__mypyc_lambda__1_obj_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject *self;
    self = (dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__1_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__1_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__1_obj(void)
{
    PyObject *self = __mypyc_lambda__1_obj_setup(CPyType___mypyc_lambda__1_obj);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *_get_coroutine_fn_env_setup(PyTypeObject *type);
PyObject *CPyDef__get_coroutine_fn_env(void);

static PyObject *
_get_coroutine_fn_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__get_coroutine_fn_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _get_coroutine_fn_env_setup(type);
}

static int
_get_coroutine_fn_env_traverse(dank_mids___brownie_patch___call____get_coroutine_fn_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_w3);
    if (CPyTagged_CheckLong(self->_len_inputs)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_len_inputs));
    }
    Py_VISIT(self->_get_request_data);
    Py_VISIT(self->_coroutine);
    return 0;
}

static int
_get_coroutine_fn_env_clear(dank_mids___brownie_patch___call____get_coroutine_fn_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_w3);
    if (CPyTagged_CheckLong(self->_len_inputs)) {
        CPyTagged __tmp = self->_len_inputs;
        self->_len_inputs = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_get_request_data);
    Py_CLEAR(self->_coroutine);
    return 0;
}

static void
_get_coroutine_fn_env_dealloc(dank_mids___brownie_patch___call____get_coroutine_fn_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _get_coroutine_fn_env_dealloc)
    _get_coroutine_fn_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _get_coroutine_fn_env_vtable[1];
static bool
CPyDef__get_coroutine_fn_env_trait_vtable_setup(void)
{
    CPyVTableItem _get_coroutine_fn_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_get_coroutine_fn_env_vtable, _get_coroutine_fn_env_vtable_scratch, sizeof(_get_coroutine_fn_env_vtable));
    return 1;
}

static PyMethodDef _get_coroutine_fn_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__get_coroutine_fn_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_get_coroutine_fn_env",
    .tp_new = _get_coroutine_fn_env_new,
    .tp_dealloc = (destructor)_get_coroutine_fn_env_dealloc,
    .tp_traverse = (traverseproc)_get_coroutine_fn_env_traverse,
    .tp_clear = (inquiry)_get_coroutine_fn_env_clear,
    .tp_methods = _get_coroutine_fn_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call____get_coroutine_fn_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__get_coroutine_fn_env_template = &CPyType__get_coroutine_fn_env_template_;

static PyObject *
_get_coroutine_fn_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call____get_coroutine_fn_envObject *self;
    self = (dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _get_coroutine_fn_env_vtable;
    self->_len_inputs = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef__get_coroutine_fn_env(void)
{
    PyObject *self = _get_coroutine_fn_env_setup(CPyType__get_coroutine_fn_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *coroutine__get_coroutine_fn_env_setup(PyTypeObject *type);
PyObject *CPyDef_coroutine__get_coroutine_fn_env(void);

static PyObject *
coroutine__get_coroutine_fn_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_coroutine__get_coroutine_fn_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return coroutine__get_coroutine_fn_env_setup(type);
}

static int
coroutine__get_coroutine_fn_env_traverse(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->___mypyc_env__);
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
    Py_VISIT(self->___mypyc_temp__0);
    Py_VISIT(self->___mypyc_temp__1);
    Py_VISIT(self->___mypyc_temp__3);
    Py_VISIT(self->___mypyc_temp__4.f0);
    Py_VISIT(self->___mypyc_temp__4.f1);
    Py_VISIT(self->___mypyc_temp__4.f2);
    Py_VISIT(self->___mypyc_temp__5);
    Py_VISIT(self->___mypyc_temp__6.f0);
    Py_VISIT(self->___mypyc_temp__6.f1);
    Py_VISIT(self->___mypyc_temp__6.f2);
    Py_VISIT(self->_data);
    Py_VISIT(self->___mypyc_temp__7);
    Py_VISIT(self->___mypyc_temp__8);
    Py_VISIT(self->___mypyc_temp__10);
    Py_VISIT(self->___mypyc_temp__11.f0);
    Py_VISIT(self->___mypyc_temp__11.f1);
    Py_VISIT(self->___mypyc_temp__11.f2);
    Py_VISIT(self->___mypyc_temp__12);
    Py_VISIT(self->___mypyc_temp__13.f0);
    Py_VISIT(self->___mypyc_temp__13.f1);
    Py_VISIT(self->___mypyc_temp__13.f2);
    Py_VISIT(self->_output);
    Py_VISIT(self->___mypyc_temp__14.f0);
    Py_VISIT(self->___mypyc_temp__14.f1);
    Py_VISIT(self->___mypyc_temp__14.f2);
    Py_VISIT(self->___mypyc_temp__15);
    Py_VISIT(self->___mypyc_temp__16.f0);
    Py_VISIT(self->___mypyc_temp__16.f1);
    Py_VISIT(self->___mypyc_temp__16.f2);
    Py_VISIT(self->___mypyc_temp__17);
    Py_VISIT(self->___mypyc_temp__18.f0);
    Py_VISIT(self->___mypyc_temp__18.f1);
    Py_VISIT(self->___mypyc_temp__18.f2);
    Py_VISIT(self->___mypyc_temp__19.f0);
    Py_VISIT(self->___mypyc_temp__19.f1);
    Py_VISIT(self->___mypyc_temp__19.f2);
    Py_VISIT(self->___mypyc_temp__20);
    Py_VISIT(self->___mypyc_temp__21.f0);
    Py_VISIT(self->___mypyc_temp__21.f1);
    Py_VISIT(self->___mypyc_temp__21.f2);
    Py_VISIT(self->___mypyc_temp__22);
    Py_VISIT(self->___mypyc_temp__23.f0);
    Py_VISIT(self->___mypyc_temp__23.f1);
    Py_VISIT(self->___mypyc_temp__23.f2);
    Py_VISIT(self->___mypyc_temp__24);
    Py_VISIT(self->___mypyc_temp__25.f0);
    Py_VISIT(self->___mypyc_temp__25.f1);
    Py_VISIT(self->___mypyc_temp__25.f2);
    Py_VISIT(self->_decoded);
    Py_VISIT(self->___mypyc_temp__26.f0);
    Py_VISIT(self->___mypyc_temp__26.f1);
    Py_VISIT(self->___mypyc_temp__26.f2);
    Py_VISIT(self->_e);
    return 0;
}

static int
coroutine__get_coroutine_fn_env_clear(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->___mypyc_env__);
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
    Py_CLEAR(self->___mypyc_temp__0);
    Py_CLEAR(self->___mypyc_temp__1);
    Py_CLEAR(self->___mypyc_temp__3);
    Py_CLEAR(self->___mypyc_temp__4.f0);
    Py_CLEAR(self->___mypyc_temp__4.f1);
    Py_CLEAR(self->___mypyc_temp__4.f2);
    Py_CLEAR(self->___mypyc_temp__5);
    Py_CLEAR(self->___mypyc_temp__6.f0);
    Py_CLEAR(self->___mypyc_temp__6.f1);
    Py_CLEAR(self->___mypyc_temp__6.f2);
    Py_CLEAR(self->_data);
    Py_CLEAR(self->___mypyc_temp__7);
    Py_CLEAR(self->___mypyc_temp__8);
    Py_CLEAR(self->___mypyc_temp__10);
    Py_CLEAR(self->___mypyc_temp__11.f0);
    Py_CLEAR(self->___mypyc_temp__11.f1);
    Py_CLEAR(self->___mypyc_temp__11.f2);
    Py_CLEAR(self->___mypyc_temp__12);
    Py_CLEAR(self->___mypyc_temp__13.f0);
    Py_CLEAR(self->___mypyc_temp__13.f1);
    Py_CLEAR(self->___mypyc_temp__13.f2);
    Py_CLEAR(self->_output);
    Py_CLEAR(self->___mypyc_temp__14.f0);
    Py_CLEAR(self->___mypyc_temp__14.f1);
    Py_CLEAR(self->___mypyc_temp__14.f2);
    Py_CLEAR(self->___mypyc_temp__15);
    Py_CLEAR(self->___mypyc_temp__16.f0);
    Py_CLEAR(self->___mypyc_temp__16.f1);
    Py_CLEAR(self->___mypyc_temp__16.f2);
    Py_CLEAR(self->___mypyc_temp__17);
    Py_CLEAR(self->___mypyc_temp__18.f0);
    Py_CLEAR(self->___mypyc_temp__18.f1);
    Py_CLEAR(self->___mypyc_temp__18.f2);
    Py_CLEAR(self->___mypyc_temp__19.f0);
    Py_CLEAR(self->___mypyc_temp__19.f1);
    Py_CLEAR(self->___mypyc_temp__19.f2);
    Py_CLEAR(self->___mypyc_temp__20);
    Py_CLEAR(self->___mypyc_temp__21.f0);
    Py_CLEAR(self->___mypyc_temp__21.f1);
    Py_CLEAR(self->___mypyc_temp__21.f2);
    Py_CLEAR(self->___mypyc_temp__22);
    Py_CLEAR(self->___mypyc_temp__23.f0);
    Py_CLEAR(self->___mypyc_temp__23.f1);
    Py_CLEAR(self->___mypyc_temp__23.f2);
    Py_CLEAR(self->___mypyc_temp__24);
    Py_CLEAR(self->___mypyc_temp__25.f0);
    Py_CLEAR(self->___mypyc_temp__25.f1);
    Py_CLEAR(self->___mypyc_temp__25.f2);
    Py_CLEAR(self->_decoded);
    Py_CLEAR(self->___mypyc_temp__26.f0);
    Py_CLEAR(self->___mypyc_temp__26.f1);
    Py_CLEAR(self->___mypyc_temp__26.f2);
    Py_CLEAR(self->_e);
    return 0;
}

static void
coroutine__get_coroutine_fn_env_dealloc(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, coroutine__get_coroutine_fn_env_dealloc)
    coroutine__get_coroutine_fn_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem coroutine__get_coroutine_fn_env_vtable[1];
static bool
CPyDef_coroutine__get_coroutine_fn_env_trait_vtable_setup(void)
{
    CPyVTableItem coroutine__get_coroutine_fn_env_vtable_scratch[] = {
        NULL
    };
    memcpy(coroutine__get_coroutine_fn_env_vtable, coroutine__get_coroutine_fn_env_vtable_scratch, sizeof(coroutine__get_coroutine_fn_env_vtable));
    return 1;
}

static PyMethodDef coroutine__get_coroutine_fn_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_coroutine__get_coroutine_fn_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "coroutine__get_coroutine_fn_env",
    .tp_new = coroutine__get_coroutine_fn_env_new,
    .tp_dealloc = (destructor)coroutine__get_coroutine_fn_env_dealloc,
    .tp_traverse = (traverseproc)coroutine__get_coroutine_fn_env_traverse,
    .tp_clear = (inquiry)coroutine__get_coroutine_fn_env_clear,
    .tp_methods = coroutine__get_coroutine_fn_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_coroutine__get_coroutine_fn_env_template = &CPyType_coroutine__get_coroutine_fn_env_template_;

static PyObject *
coroutine__get_coroutine_fn_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *self;
    self = (dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = coroutine__get_coroutine_fn_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__2 = 2;
    self->___mypyc_temp__4 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__6 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__9 = 2;
    self->___mypyc_temp__11 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__13 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__14 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__16 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__18 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__19 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__21 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__23 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__25 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__26 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_env(void)
{
    PyObject *self = coroutine__get_coroutine_fn_env_setup(CPyType_coroutine__get_coroutine_fn_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get__coroutine__get_coroutine_fn_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_coroutine__get_coroutine_fn_obj_____get__(self, instance, owner);
}
static PyObject *coroutine__get_coroutine_fn_obj_setup(PyTypeObject *type);
PyObject *CPyDef_coroutine__get_coroutine_fn_obj(void);

static PyObject *
coroutine__get_coroutine_fn_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_coroutine__get_coroutine_fn_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return coroutine__get_coroutine_fn_obj_setup(type);
}

static int
coroutine__get_coroutine_fn_obj_traverse(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
coroutine__get_coroutine_fn_obj_clear(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
coroutine__get_coroutine_fn_obj_dealloc(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, coroutine__get_coroutine_fn_obj_dealloc)
    coroutine__get_coroutine_fn_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem coroutine__get_coroutine_fn_obj_vtable[2];
static bool
CPyDef_coroutine__get_coroutine_fn_obj_trait_vtable_setup(void)
{
    CPyVTableItem coroutine__get_coroutine_fn_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_obj_____call__,
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_obj_____get__,
    };
    memcpy(coroutine__get_coroutine_fn_obj_vtable, coroutine__get_coroutine_fn_obj_vtable_scratch, sizeof(coroutine__get_coroutine_fn_obj_vtable));
    return 1;
}

static PyObject *
coroutine__get_coroutine_fn_obj_get___3_mypyc_env__(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self, void *closure);
static int
coroutine__get_coroutine_fn_obj_set___3_mypyc_env__(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self, PyObject *value, void *closure);

static PyGetSetDef coroutine__get_coroutine_fn_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)coroutine__get_coroutine_fn_obj_get___3_mypyc_env__, (setter)coroutine__get_coroutine_fn_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef coroutine__get_coroutine_fn_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_coroutine__get_coroutine_fn_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "coroutine__get_coroutine_fn_obj",
    .tp_new = coroutine__get_coroutine_fn_obj_new,
    .tp_dealloc = (destructor)coroutine__get_coroutine_fn_obj_dealloc,
    .tp_traverse = (traverseproc)coroutine__get_coroutine_fn_obj_traverse,
    .tp_clear = (inquiry)coroutine__get_coroutine_fn_obj_clear,
    .tp_getset = coroutine__get_coroutine_fn_obj_getseters,
    .tp_methods = coroutine__get_coroutine_fn_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__coroutine__get_coroutine_fn_obj,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_coroutine__get_coroutine_fn_obj_template = &CPyType_coroutine__get_coroutine_fn_obj_template_;

static PyObject *
coroutine__get_coroutine_fn_obj_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self;
    self = (dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = coroutine__get_coroutine_fn_obj_vtable;
    self->vectorcall = CPyPy_coroutine__get_coroutine_fn_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_obj(void)
{
    PyObject *self = coroutine__get_coroutine_fn_obj_setup(CPyType_coroutine__get_coroutine_fn_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
coroutine__get_coroutine_fn_obj_get___3_mypyc_env__(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'coroutine__get_coroutine_fn_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
coroutine__get_coroutine_fn_obj_set___3_mypyc_env__(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'coroutine__get_coroutine_fn_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType__get_coroutine_fn_env))
        tmp = value;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._get_coroutine_fn_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyAsyncMethods coroutine__get_coroutine_fn_gen_as_async = {
    .am_await = CPyDef_coroutine__get_coroutine_fn_gen_____await__,
};
static PyObject *coroutine__get_coroutine_fn_gen_setup(PyTypeObject *type);
PyObject *CPyDef_coroutine__get_coroutine_fn_gen(void);

static PyObject *
coroutine__get_coroutine_fn_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_coroutine__get_coroutine_fn_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return coroutine__get_coroutine_fn_gen_setup(type);
}

static int
coroutine__get_coroutine_fn_gen_traverse(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
coroutine__get_coroutine_fn_gen_clear(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
coroutine__get_coroutine_fn_gen_dealloc(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, coroutine__get_coroutine_fn_gen_dealloc)
    coroutine__get_coroutine_fn_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem coroutine__get_coroutine_fn_gen_vtable[7];
static bool
CPyDef_coroutine__get_coroutine_fn_gen_trait_vtable_setup(void)
{
    CPyVTableItem coroutine__get_coroutine_fn_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_gen_____next__,
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_gen___send,
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_gen_____iter__,
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_gen___throw,
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_gen___close,
        (CPyVTableItem)CPyDef_coroutine__get_coroutine_fn_gen_____await__,
    };
    memcpy(coroutine__get_coroutine_fn_gen_vtable, coroutine__get_coroutine_fn_gen_vtable_scratch, sizeof(coroutine__get_coroutine_fn_gen_vtable));
    return 1;
}

static PyMethodDef coroutine__get_coroutine_fn_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy_coroutine__get_coroutine_fn_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_coroutine__get_coroutine_fn_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "coroutine__get_coroutine_fn_gen",
    .tp_new = coroutine__get_coroutine_fn_gen_new,
    .tp_dealloc = (destructor)coroutine__get_coroutine_fn_gen_dealloc,
    .tp_traverse = (traverseproc)coroutine__get_coroutine_fn_gen_traverse,
    .tp_clear = (inquiry)coroutine__get_coroutine_fn_gen_clear,
    .tp_methods = coroutine__get_coroutine_fn_gen_methods,
    .tp_iter = CPyDef_coroutine__get_coroutine_fn_gen_____iter__,
    .tp_iternext = CPyDef_coroutine__get_coroutine_fn_gen_____next__,
    .tp_as_async = &coroutine__get_coroutine_fn_gen_as_async,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_coroutine__get_coroutine_fn_gen_template = &CPyType_coroutine__get_coroutine_fn_gen_template_;

static PyObject *
coroutine__get_coroutine_fn_gen_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *self;
    self = (dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = coroutine__get_coroutine_fn_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_gen(void)
{
    PyObject *self = coroutine__get_coroutine_fn_gen_setup(CPyType_coroutine__get_coroutine_fn_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *encode_input_env_setup(PyTypeObject *type);
PyObject *CPyDef_encode_input_env(void);

static PyObject *
encode_input_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_encode_input_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return encode_input_env_setup(type);
}

static int
encode_input_env_traverse(dank_mids___brownie_patch___call___encode_input_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_call);
    if (CPyTagged_CheckLong(self->_len_inputs)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_len_inputs));
    }
    Py_VISIT(self->_get_request_data);
    Py_VISIT(self->_args);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->___mypyc_temp__27);
    Py_VISIT(self->_data);
    Py_VISIT(self->___mypyc_temp__29);
    Py_VISIT(self->___mypyc_temp__30.f0);
    Py_VISIT(self->___mypyc_temp__30.f1);
    Py_VISIT(self->___mypyc_temp__30.f2);
    Py_VISIT(self->___mypyc_temp__31.f0);
    Py_VISIT(self->___mypyc_temp__31.f1);
    Py_VISIT(self->___mypyc_temp__31.f2);
    return 0;
}

static int
encode_input_env_clear(dank_mids___brownie_patch___call___encode_input_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_call);
    if (CPyTagged_CheckLong(self->_len_inputs)) {
        CPyTagged __tmp = self->_len_inputs;
        self->_len_inputs = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_get_request_data);
    Py_CLEAR(self->_args);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__27);
    Py_CLEAR(self->_data);
    Py_CLEAR(self->___mypyc_temp__29);
    Py_CLEAR(self->___mypyc_temp__30.f0);
    Py_CLEAR(self->___mypyc_temp__30.f1);
    Py_CLEAR(self->___mypyc_temp__30.f2);
    Py_CLEAR(self->___mypyc_temp__31.f0);
    Py_CLEAR(self->___mypyc_temp__31.f1);
    Py_CLEAR(self->___mypyc_temp__31.f2);
    return 0;
}

static void
encode_input_env_dealloc(dank_mids___brownie_patch___call___encode_input_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, encode_input_env_dealloc)
    encode_input_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem encode_input_env_vtable[1];
static bool
CPyDef_encode_input_env_trait_vtable_setup(void)
{
    CPyVTableItem encode_input_env_vtable_scratch[] = {
        NULL
    };
    memcpy(encode_input_env_vtable, encode_input_env_vtable_scratch, sizeof(encode_input_env_vtable));
    return 1;
}

static PyMethodDef encode_input_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_encode_input_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "encode_input_env",
    .tp_new = encode_input_env_new,
    .tp_dealloc = (destructor)encode_input_env_dealloc,
    .tp_traverse = (traverseproc)encode_input_env_traverse,
    .tp_clear = (inquiry)encode_input_env_clear,
    .tp_methods = encode_input_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call___encode_input_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_encode_input_env_template = &CPyType_encode_input_env_template_;

static PyObject *
encode_input_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call___encode_input_envObject *self;
    self = (dank_mids___brownie_patch___call___encode_input_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = encode_input_env_vtable;
    self->_len_inputs = CPY_INT_TAG;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__28 = CPY_INT_TAG;
    self->___mypyc_temp__30 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__31 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_encode_input_env(void)
{
    PyObject *self = encode_input_env_setup(CPyType_encode_input_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods encode_input_gen_as_async = {
    .am_await = CPyDef_encode_input_gen_____await__,
};
static PyObject *encode_input_gen_setup(PyTypeObject *type);
PyObject *CPyDef_encode_input_gen(void);

static PyObject *
encode_input_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_encode_input_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return encode_input_gen_setup(type);
}

static int
encode_input_gen_traverse(dank_mids___brownie_patch___call___encode_input_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
encode_input_gen_clear(dank_mids___brownie_patch___call___encode_input_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
encode_input_gen_dealloc(dank_mids___brownie_patch___call___encode_input_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, encode_input_gen_dealloc)
    encode_input_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem encode_input_gen_vtable[7];
static bool
CPyDef_encode_input_gen_trait_vtable_setup(void)
{
    CPyVTableItem encode_input_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_encode_input_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_encode_input_gen_____next__,
        (CPyVTableItem)CPyDef_encode_input_gen___send,
        (CPyVTableItem)CPyDef_encode_input_gen_____iter__,
        (CPyVTableItem)CPyDef_encode_input_gen___throw,
        (CPyVTableItem)CPyDef_encode_input_gen___close,
        (CPyVTableItem)CPyDef_encode_input_gen_____await__,
    };
    memcpy(encode_input_gen_vtable, encode_input_gen_vtable_scratch, sizeof(encode_input_gen_vtable));
    return 1;
}

static PyMethodDef encode_input_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy_encode_input_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy_encode_input_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy_encode_input_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_encode_input_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy_encode_input_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy_encode_input_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy_encode_input_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_encode_input_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "encode_input_gen",
    .tp_new = encode_input_gen_new,
    .tp_dealloc = (destructor)encode_input_gen_dealloc,
    .tp_traverse = (traverseproc)encode_input_gen_traverse,
    .tp_clear = (inquiry)encode_input_gen_clear,
    .tp_methods = encode_input_gen_methods,
    .tp_iter = CPyDef_encode_input_gen_____iter__,
    .tp_iternext = CPyDef_encode_input_gen_____next__,
    .tp_as_async = &encode_input_gen_as_async,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call___encode_input_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_encode_input_gen_template = &CPyType_encode_input_gen_template_;

static PyObject *
encode_input_gen_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call___encode_input_genObject *self;
    self = (dank_mids___brownie_patch___call___encode_input_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = encode_input_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_encode_input_gen(void)
{
    PyObject *self = encode_input_gen_setup(CPyType_encode_input_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *decode_output_env_setup(PyTypeObject *type);
PyObject *CPyDef_decode_output_env(void);

static PyObject *
decode_output_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_decode_output_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return decode_output_env_setup(type);
}

static int
decode_output_env_traverse(dank_mids___brownie_patch___call___decode_output_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_call);
    Py_VISIT(self->_data);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->_decoded);
    Py_VISIT(self->___mypyc_temp__32);
    Py_VISIT(self->___mypyc_temp__33.f0);
    Py_VISIT(self->___mypyc_temp__33.f1);
    Py_VISIT(self->___mypyc_temp__33.f2);
    Py_VISIT(self->___mypyc_temp__34.f0);
    Py_VISIT(self->___mypyc_temp__34.f1);
    Py_VISIT(self->___mypyc_temp__34.f2);
    Py_VISIT(self->___mypyc_temp__35.f0);
    Py_VISIT(self->___mypyc_temp__35.f1);
    Py_VISIT(self->___mypyc_temp__35.f2);
    Py_VISIT(self->_e);
    Py_VISIT(self->___mypyc_temp__36);
    Py_VISIT(self->___mypyc_temp__37.f0);
    Py_VISIT(self->___mypyc_temp__37.f1);
    Py_VISIT(self->___mypyc_temp__37.f2);
    return 0;
}

static int
decode_output_env_clear(dank_mids___brownie_patch___call___decode_output_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_call);
    Py_CLEAR(self->_data);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_decoded);
    Py_CLEAR(self->___mypyc_temp__32);
    Py_CLEAR(self->___mypyc_temp__33.f0);
    Py_CLEAR(self->___mypyc_temp__33.f1);
    Py_CLEAR(self->___mypyc_temp__33.f2);
    Py_CLEAR(self->___mypyc_temp__34.f0);
    Py_CLEAR(self->___mypyc_temp__34.f1);
    Py_CLEAR(self->___mypyc_temp__34.f2);
    Py_CLEAR(self->___mypyc_temp__35.f0);
    Py_CLEAR(self->___mypyc_temp__35.f1);
    Py_CLEAR(self->___mypyc_temp__35.f2);
    Py_CLEAR(self->_e);
    Py_CLEAR(self->___mypyc_temp__36);
    Py_CLEAR(self->___mypyc_temp__37.f0);
    Py_CLEAR(self->___mypyc_temp__37.f1);
    Py_CLEAR(self->___mypyc_temp__37.f2);
    return 0;
}

static void
decode_output_env_dealloc(dank_mids___brownie_patch___call___decode_output_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, decode_output_env_dealloc)
    decode_output_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem decode_output_env_vtable[1];
static bool
CPyDef_decode_output_env_trait_vtable_setup(void)
{
    CPyVTableItem decode_output_env_vtable_scratch[] = {
        NULL
    };
    memcpy(decode_output_env_vtable, decode_output_env_vtable_scratch, sizeof(decode_output_env_vtable));
    return 1;
}

static PyMethodDef decode_output_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_decode_output_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "decode_output_env",
    .tp_new = decode_output_env_new,
    .tp_dealloc = (destructor)decode_output_env_dealloc,
    .tp_traverse = (traverseproc)decode_output_env_traverse,
    .tp_clear = (inquiry)decode_output_env_clear,
    .tp_methods = decode_output_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call___decode_output_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_decode_output_env_template = &CPyType_decode_output_env_template_;

static PyObject *
decode_output_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call___decode_output_envObject *self;
    self = (dank_mids___brownie_patch___call___decode_output_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = decode_output_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__33 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__34 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__35 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__37 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_decode_output_env(void)
{
    PyObject *self = decode_output_env_setup(CPyType_decode_output_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods decode_output_gen_as_async = {
    .am_await = CPyDef_decode_output_gen_____await__,
};
static PyObject *decode_output_gen_setup(PyTypeObject *type);
PyObject *CPyDef_decode_output_gen(void);

static PyObject *
decode_output_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_decode_output_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return decode_output_gen_setup(type);
}

static int
decode_output_gen_traverse(dank_mids___brownie_patch___call___decode_output_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
decode_output_gen_clear(dank_mids___brownie_patch___call___decode_output_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
decode_output_gen_dealloc(dank_mids___brownie_patch___call___decode_output_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, decode_output_gen_dealloc)
    decode_output_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem decode_output_gen_vtable[7];
static bool
CPyDef_decode_output_gen_trait_vtable_setup(void)
{
    CPyVTableItem decode_output_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_decode_output_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_decode_output_gen_____next__,
        (CPyVTableItem)CPyDef_decode_output_gen___send,
        (CPyVTableItem)CPyDef_decode_output_gen_____iter__,
        (CPyVTableItem)CPyDef_decode_output_gen___throw,
        (CPyVTableItem)CPyDef_decode_output_gen___close,
        (CPyVTableItem)CPyDef_decode_output_gen_____await__,
    };
    memcpy(decode_output_gen_vtable, decode_output_gen_vtable_scratch, sizeof(decode_output_gen_vtable));
    return 1;
}

static PyMethodDef decode_output_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy_decode_output_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy_decode_output_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy_decode_output_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_decode_output_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy_decode_output_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy_decode_output_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy_decode_output_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_decode_output_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "decode_output_gen",
    .tp_new = decode_output_gen_new,
    .tp_dealloc = (destructor)decode_output_gen_dealloc,
    .tp_traverse = (traverseproc)decode_output_gen_traverse,
    .tp_clear = (inquiry)decode_output_gen_clear,
    .tp_methods = decode_output_gen_methods,
    .tp_iter = CPyDef_decode_output_gen_____iter__,
    .tp_iternext = CPyDef_decode_output_gen_____next__,
    .tp_as_async = &decode_output_gen_as_async,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call___decode_output_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_decode_output_gen_template = &CPyType_decode_output_gen_template_;

static PyObject *
decode_output_gen_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call___decode_output_genObject *self;
    self = (dank_mids___brownie_patch___call___decode_output_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = decode_output_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_decode_output_gen(void)
{
    PyObject *self = decode_output_gen_setup(CPyType_decode_output_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *_request_data_no_args_env_setup(PyTypeObject *type);
PyObject *CPyDef__request_data_no_args_env(void);

static PyObject *
_request_data_no_args_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__request_data_no_args_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _request_data_no_args_env_setup(type);
}

static int
_request_data_no_args_env_traverse(dank_mids___brownie_patch___call____request_data_no_args_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_call);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    return 0;
}

static int
_request_data_no_args_env_clear(dank_mids___brownie_patch___call____request_data_no_args_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_call);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    return 0;
}

static void
_request_data_no_args_env_dealloc(dank_mids___brownie_patch___call____request_data_no_args_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _request_data_no_args_env_dealloc)
    _request_data_no_args_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _request_data_no_args_env_vtable[1];
static bool
CPyDef__request_data_no_args_env_trait_vtable_setup(void)
{
    CPyVTableItem _request_data_no_args_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_request_data_no_args_env_vtable, _request_data_no_args_env_vtable_scratch, sizeof(_request_data_no_args_env_vtable));
    return 1;
}

static PyMethodDef _request_data_no_args_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__request_data_no_args_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_request_data_no_args_env",
    .tp_new = _request_data_no_args_env_new,
    .tp_dealloc = (destructor)_request_data_no_args_env_dealloc,
    .tp_traverse = (traverseproc)_request_data_no_args_env_traverse,
    .tp_clear = (inquiry)_request_data_no_args_env_clear,
    .tp_methods = _request_data_no_args_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call____request_data_no_args_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__request_data_no_args_env_template = &CPyType__request_data_no_args_env_template_;

static PyObject *
_request_data_no_args_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call____request_data_no_args_envObject *self;
    self = (dank_mids___brownie_patch___call____request_data_no_args_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _request_data_no_args_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef__request_data_no_args_env(void)
{
    PyObject *self = _request_data_no_args_env_setup(CPyType__request_data_no_args_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods _request_data_no_args_gen_as_async = {
    .am_await = CPyDef__request_data_no_args_gen_____await__,
};
static PyObject *_request_data_no_args_gen_setup(PyTypeObject *type);
PyObject *CPyDef__request_data_no_args_gen(void);

static PyObject *
_request_data_no_args_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__request_data_no_args_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _request_data_no_args_gen_setup(type);
}

static int
_request_data_no_args_gen_traverse(dank_mids___brownie_patch___call____request_data_no_args_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
_request_data_no_args_gen_clear(dank_mids___brownie_patch___call____request_data_no_args_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
_request_data_no_args_gen_dealloc(dank_mids___brownie_patch___call____request_data_no_args_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _request_data_no_args_gen_dealloc)
    _request_data_no_args_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _request_data_no_args_gen_vtable[7];
static bool
CPyDef__request_data_no_args_gen_trait_vtable_setup(void)
{
    CPyVTableItem _request_data_no_args_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__request_data_no_args_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef__request_data_no_args_gen_____next__,
        (CPyVTableItem)CPyDef__request_data_no_args_gen___send,
        (CPyVTableItem)CPyDef__request_data_no_args_gen_____iter__,
        (CPyVTableItem)CPyDef__request_data_no_args_gen___throw,
        (CPyVTableItem)CPyDef__request_data_no_args_gen___close,
        (CPyVTableItem)CPyDef__request_data_no_args_gen_____await__,
    };
    memcpy(_request_data_no_args_gen_vtable, _request_data_no_args_gen_vtable_scratch, sizeof(_request_data_no_args_gen_vtable));
    return 1;
}

static PyMethodDef _request_data_no_args_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy__request_data_no_args_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy__request_data_no_args_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy__request_data_no_args_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy__request_data_no_args_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy__request_data_no_args_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy__request_data_no_args_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy__request_data_no_args_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__request_data_no_args_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_request_data_no_args_gen",
    .tp_new = _request_data_no_args_gen_new,
    .tp_dealloc = (destructor)_request_data_no_args_gen_dealloc,
    .tp_traverse = (traverseproc)_request_data_no_args_gen_traverse,
    .tp_clear = (inquiry)_request_data_no_args_gen_clear,
    .tp_methods = _request_data_no_args_gen_methods,
    .tp_iter = CPyDef__request_data_no_args_gen_____iter__,
    .tp_iternext = CPyDef__request_data_no_args_gen_____next__,
    .tp_as_async = &_request_data_no_args_gen_as_async,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call____request_data_no_args_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__request_data_no_args_gen_template = &CPyType__request_data_no_args_gen_template_;

static PyObject *
_request_data_no_args_gen_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call____request_data_no_args_genObject *self;
    self = (dank_mids___brownie_patch___call____request_data_no_args_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _request_data_no_args_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__request_data_no_args_gen(void)
{
    PyObject *self = _request_data_no_args_gen_setup(CPyType__request_data_no_args_gen);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {"_patch_call", (PyCFunction)CPyPy__patch_call, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_get_coroutine_fn", (PyCFunction)CPyPy__get_coroutine_fn, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_call_no_args", (PyCFunction)CPyPy__call_no_args, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"encode_input", (PyCFunction)CPyPy_encode_input, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"decode_output", (PyCFunction)CPyPy_decode_output, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_request_data_no_args", (PyCFunction)CPyPy__request_data_no_args, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"__encode_input", (PyCFunction)CPyPy___encode_input, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"__decode_output", (PyCFunction)CPyPy___decode_output, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"__validate_output", (PyCFunction)CPyPy___validate_output, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"format_input_but_cache_checksums", (PyCFunction)CPyPy_format_input_but_cache_checksums, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"format_output_but_cache_checksums", (PyCFunction)CPyPy_format_output_but_cache_checksums, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_format_tuple_but_cache_checksums", (PyCFunction)CPyPy__format_tuple_but_cache_checksums, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_format_array_but_cache_checksums", (PyCFunction)CPyPy__format_array_but_cache_checksums, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_format_single_but_cache_checksums", (PyCFunction)CPyPy__format_single_but_cache_checksums, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids.brownie_patch.call",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids___brownie_patch___call(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids___brownie_patch___call_internal) {
        Py_INCREF(CPyModule_dank_mids___brownie_patch___call_internal);
        return CPyModule_dank_mids___brownie_patch___call_internal;
    }
    CPyModule_dank_mids___brownie_patch___call_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids___brownie_patch___call_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids___brownie_patch___call_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids___brownie_patch___call_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType___mypyc_lambda__0_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__0_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__0_obj))
        goto fail;
    CPyType___mypyc_lambda__1_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__1_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__1_obj))
        goto fail;
    CPyType__get_coroutine_fn_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__get_coroutine_fn_env_template, NULL, modname);
    if (unlikely(!CPyType__get_coroutine_fn_env))
        goto fail;
    CPyType_coroutine__get_coroutine_fn_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_coroutine__get_coroutine_fn_env_template, NULL, modname);
    if (unlikely(!CPyType_coroutine__get_coroutine_fn_env))
        goto fail;
    CPyType_coroutine__get_coroutine_fn_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_coroutine__get_coroutine_fn_obj_template, NULL, modname);
    if (unlikely(!CPyType_coroutine__get_coroutine_fn_obj))
        goto fail;
    CPyType_coroutine__get_coroutine_fn_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_coroutine__get_coroutine_fn_gen_template, NULL, modname);
    if (unlikely(!CPyType_coroutine__get_coroutine_fn_gen))
        goto fail;
    CPyType_encode_input_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_encode_input_env_template, NULL, modname);
    if (unlikely(!CPyType_encode_input_env))
        goto fail;
    CPyType_encode_input_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_encode_input_gen_template, NULL, modname);
    if (unlikely(!CPyType_encode_input_gen))
        goto fail;
    CPyType_decode_output_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_decode_output_env_template, NULL, modname);
    if (unlikely(!CPyType_decode_output_env))
        goto fail;
    CPyType_decode_output_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_decode_output_gen_template, NULL, modname);
    if (unlikely(!CPyType_decode_output_gen))
        goto fail;
    CPyType__request_data_no_args_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__request_data_no_args_env_template, NULL, modname);
    if (unlikely(!CPyType__request_data_no_args_env))
        goto fail;
    CPyType__request_data_no_args_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__request_data_no_args_gen_template, NULL, modname);
    if (unlikely(!CPyType__request_data_no_args_gen))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids___brownie_patch___call_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids___brownie_patch___call_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_ENVS);
    CPyStatic_ENVS = NULL;
    CPyStatic_APPLICATION_MODE = 2;
    CPy_XDECREF(CPyStatic_Decimal);
    CPyStatic_Decimal = NULL;
    CPy_XDECREF(CPyStatic_HexBytes);
    CPyStatic_HexBytes = NULL;
    CPy_XDECREF(CPyStatic_Contract);
    CPyStatic_Contract = NULL;
    CPy_XDECREF(CPyStatic_ReturnValue);
    CPyStatic_ReturnValue = NULL;
    CPy_XDECREF(CPyStatic_HexString);
    CPyStatic_HexString = NULL;
    CPy_XDECREF(CPyStatic_TupleType);
    CPyStatic_TupleType = NULL;
    CPy_XDECREF(CPyStatic_Revert);
    CPyStatic_Revert = NULL;
    CPy_XDECREF(CPyStatic_to_bool);
    CPyStatic_to_bool = NULL;
    CPy_XDECREF(CPyStatic_to_decimal);
    CPyStatic_to_decimal = NULL;
    CPy_XDECREF(CPyStatic_to_int);
    CPyStatic_to_int = NULL;
    CPy_XDECREF(CPyStatic_to_string);
    CPyStatic_to_string = NULL;
    CPy_XDECREF(CPyStatic_to_uint);
    CPyStatic_to_uint = NULL;
    CPy_XDECREF(CPyStatic__check_array);
    CPyStatic__check_array = NULL;
    CPy_XDECREF(CPyStatic__get_abi_types);
    CPyStatic__get_abi_types = NULL;
    CPy_XDECREF(CPyStatic_logger);
    CPyStatic_logger = NULL;
    CPy_XDECREF(CPyStatic_encode);
    CPyStatic_encode = NULL;
    CPy_XDECREF(CPyStatic_decode);
    CPyStatic_decode = NULL;
    CPy_XDECREF(CPyStatic_to_checksum_address);
    CPyStatic_to_checksum_address = NULL;
    CPy_XDECREF(CPyStatic___eth_abi_encode);
    CPyStatic___eth_abi_encode = NULL;
    CPy_XDECREF(CPyStatic___eth_abi_decode);
    CPyStatic___eth_abi_decode = NULL;
    Py_CLEAR(CPyType___mypyc_lambda__0_obj);
    Py_CLEAR(CPyType___mypyc_lambda__1_obj);
    Py_CLEAR(CPyType__get_coroutine_fn_env);
    Py_CLEAR(CPyType_coroutine__get_coroutine_fn_env);
    Py_CLEAR(CPyType_coroutine__get_coroutine_fn_obj);
    Py_CLEAR(CPyType_coroutine__get_coroutine_fn_gen);
    Py_CLEAR(CPyType_encode_input_env);
    Py_CLEAR(CPyType_encode_input_gen);
    Py_CLEAR(CPyType_decode_output_env);
    Py_CLEAR(CPyType_decode_output_gen);
    Py_CLEAR(CPyType__request_data_no_args_env);
    Py_CLEAR(CPyType__request_data_no_args_gen);
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__0_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
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
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    CPyPtr cpy_r_r16;
    CPyPtr cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    cpy_r_r0 = CPyStatic_ENVS;
    if (likely(cpy_r_r0 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r1 = 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r2 = CPyStatics[3]; /* 'BROWNIE_ENCODER_PROCESSES' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r4 = CPyStatic_globals;
    cpy_r_r5 = CPyStatics[4]; /* '__encode_input' */
    cpy_r_r6 = CPyDict_GetItem(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r7 = CPyStatics[5]; /* 'abi' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_self, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r9 = CPyStatics[6]; /* 'signature' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_self, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r11 = CPyStatics[7]; /* 'run' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r11);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r13 = PyList_New(3);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r14 = (CPyPtr)&((PyListObject *)cpy_r_r13)->ob_item;
    cpy_r_r15 = *(CPyPtr *)cpy_r_r14;
    *(PyObject * *)cpy_r_r15 = cpy_r_r6;
    cpy_r_r16 = cpy_r_r15 + 8;
    *(PyObject * *)cpy_r_r16 = cpy_r_r8;
    cpy_r_r17 = cpy_r_r15 + 16;
    *(PyObject * *)cpy_r_r17 = cpy_r_r10;
    cpy_r_r18 = CPyList_Extend(cpy_r_r13, cpy_r_args);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL21;
CPyL10: ;
    cpy_r_r19 = PyList_AsTuple(cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r20 = PyDict_New();
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL23;
    }
    cpy_r_r21 = PyObject_Call(cpy_r_r12, cpy_r_r19, cpy_r_r20);
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
        goto CPyL14;
    }
    return cpy_r_r21;
CPyL14: ;
    cpy_r_r22 = NULL;
    return cpy_r_r22;
CPyL15: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL14;
CPyL16: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r6);
    goto CPyL14;
CPyL17: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    goto CPyL14;
CPyL18: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    goto CPyL14;
CPyL19: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r12);
    goto CPyL14;
CPyL20: ;
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r13);
    goto CPyL14;
CPyL21: ;
    CPy_DECREF(cpy_r_r18);
    goto CPyL10;
CPyL22: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL14;
CPyL23: ;
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r19);
    goto CPyL14;
}

PyObject *CPyPy___mypyc_lambda__0_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"self", 0};
    static CPyArg_Parser parser = {"%O:__call__", kwlist, 0};
    PyObject *obj_self;
    PyObject *obj_args;
    if (!CPyArg_ParseStackAndKeywords(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_args, NULL, &obj_self)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_self = obj_self;
    PyObject *arg_args = obj_args;
    PyObject *retval = CPyDef___mypyc_lambda__0_obj_____call__(arg___mypyc_self__, arg_self, arg_args);
    CPy_DECREF(obj_args);
    return retval;
fail: ;
    CPy_DECREF(obj_args);
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 78, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__1_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___mypyc_lambda__1_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___mypyc_lambda__1_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__1_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    cpy_r_r0 = CPyStatic_ENVS;
    if (likely(cpy_r_r0 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r1 = 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 97, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r2 = CPyStatics[8]; /* 'BROWNIE_DECODER_PROCESSES' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 97, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r4 = CPyStatic_globals;
    cpy_r_r5 = CPyStatics[9]; /* '__decode_output' */
    cpy_r_r6 = CPyDict_GetItem(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 97, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r7 = CPyStatics[5]; /* 'abi' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_self, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 97, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r9 = CPyStatics[7]; /* 'run' */
    PyObject *cpy_r_r10[4] = {cpy_r_r3, cpy_r_r6, cpy_r_data, cpy_r_r8};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_VectorcallMethod(cpy_r_r9, cpy_r_r11, 9223372036854775812ULL, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 97, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r8);
    return cpy_r_r12;
CPyL8: ;
    cpy_r_r13 = NULL;
    return cpy_r_r13;
CPyL9: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r6);
    goto CPyL8;
CPyL11: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    goto CPyL8;
}

PyObject *CPyPy___mypyc_lambda__1_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"self", "data", 0};
    static CPyArg_Parser parser = {"OO:__call__", kwlist, 0};
    PyObject *obj_self;
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_self, &obj_data)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_self = obj_self;
    PyObject *arg_data;
    if (likely(PyBytes_Check(obj_data) || PyByteArray_Check(obj_data)))
        arg_data = obj_data;
    else {
        CPy_TypeError("bytes", obj_data); 
        goto fail;
    }
    PyObject *retval = CPyDef___mypyc_lambda__1_obj_____call__(arg___mypyc_self__, arg_self, arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 97, CPyStatic_globals);
    return NULL;
}

char CPyDef__patch_call(PyObject *cpy_r_call, PyObject *cpy_r_w3) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    int32_t cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    int32_t cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyTagged cpy_r_r17;
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
    int32_t cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    int32_t cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    cpy_r_r0 = CPyStatics[10]; /* '_address' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_call, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 131, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[11]; /* '_skip_proc_pool' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 131, CPyStatic_globals);
        goto CPyL19;
    }
    if (likely(PySet_Check(cpy_r_r4)))
        cpy_r_r5 = cpy_r_r4;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 131, CPyStatic_globals, "set", cpy_r_r4);
        goto CPyL19;
    }
    cpy_r_r6 = PySet_Contains(cpy_r_r5, cpy_r_r1);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r1);
    cpy_r_r7 = cpy_r_r6 >= 0;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 131, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r8 = cpy_r_r6;
    cpy_r_r9 = CPyStatics[12]; /* '_skip_decoder_proc_pool' */
    cpy_r_r10 = cpy_r_r8 ? Py_True : Py_False;
    cpy_r_r11 = PyObject_SetAttr(cpy_r_call, cpy_r_r9, cpy_r_r10);
    cpy_r_r12 = cpy_r_r11 >= 0;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 131, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r13 = CPyStatics[5]; /* 'abi' */
    cpy_r_r14 = CPyObject_GetAttr(cpy_r_call, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 132, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r15 = CPyStatics[13]; /* 'inputs' */
    cpy_r_r16 = PyObject_GetItem(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 132, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r17 = CPyObject_Size(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 132, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r18 = CPyStatic_globals;
    cpy_r_r19 = CPyStatics[14]; /* '_get_coroutine_fn' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 132, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r21 = CPyTagged_StealAsObject(cpy_r_r17);
    PyObject *cpy_r_r22[2] = {cpy_r_w3, cpy_r_r21};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = _PyObject_Vectorcall(cpy_r_r20, cpy_r_r23, 2, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 132, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(cpy_r_r21);
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyStatics[15]; /* 'MethodType' */
    cpy_r_r27 = CPyDict_GetItem(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 132, CPyStatic_globals);
        goto CPyL22;
    }
    PyObject *cpy_r_r28[2] = {cpy_r_r24, cpy_r_call};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 2, 0);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 132, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r24);
    cpy_r_r31 = CPyStatics[16]; /* 'coroutine' */
    cpy_r_r32 = PyObject_SetAttr(cpy_r_call, cpy_r_r31, cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r33 = cpy_r_r32 >= 0;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 132, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyStatics[17]; /* '_call_no_args' */
    cpy_r_r36 = CPyDict_GetItem(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 133, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyStatics[15]; /* 'MethodType' */
    cpy_r_r39 = CPyDict_GetItem(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 133, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r40[2] = {cpy_r_r36, cpy_r_call};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = _PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 2, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 133, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r36);
    cpy_r_r43 = CPyStatics[18]; /* '__await__' */
    cpy_r_r44 = PyObject_SetAttr(cpy_r_call, cpy_r_r43, cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 133, CPyStatic_globals);
        goto CPyL18;
    }
    return 1;
CPyL18: ;
    cpy_r_r46 = 2;
    return cpy_r_r46;
CPyL19: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL18;
CPyL20: ;
    CPyTagged_DecRef(cpy_r_r17);
    goto CPyL18;
CPyL21: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL18;
CPyL22: ;
    CPy_DecRef(cpy_r_r24);
    goto CPyL18;
CPyL23: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL18;
}

PyObject *CPyPy__patch_call(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"call", "w3", 0};
    static CPyArg_Parser parser = {"OO:_patch_call", kwlist, 0};
    PyObject *obj_call;
    PyObject *obj_w3;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_call, &obj_w3)) {
        return NULL;
    }
    PyObject *arg_call = obj_call;
    PyObject *arg_w3 = obj_w3;
    char retval = CPyDef__patch_call(arg_call, arg_w3);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 121, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy_coroutine__get_coroutine_fn_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
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
    tuple_T3OOO cpy_r_r12;
    tuple_T3OOO cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    tuple_T3OOO cpy_r_r18;
    tuple_T3OOO cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    CPyTagged cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    int64_t cpy_r_r31;
    CPyTagged cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    char cpy_r_r57;
    PyObject *cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    tuple_T3OOO cpy_r_r68;
    char cpy_r_r69;
    PyObject **cpy_r_r70;
    PyObject *cpy_r_r71;
    char cpy_r_r72;
    char cpy_r_r73;
    tuple_T3OOO cpy_r_r74;
    char cpy_r_r75;
    tuple_T3OOO cpy_r_r76;
    tuple_T3OOO cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    CPyTagged cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    CPyPtr cpy_r_r91;
    CPyPtr cpy_r_r92;
    CPyPtr cpy_r_r93;
    CPyPtr cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    char cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    char cpy_r_r106;
    PyObject *cpy_r_r107;
    char cpy_r_r108;
    tuple_T3OOO cpy_r_r109;
    char cpy_r_r110;
    PyObject **cpy_r_r111;
    PyObject *cpy_r_r112;
    char cpy_r_r113;
    char cpy_r_r114;
    tuple_T3OOO cpy_r_r115;
    char cpy_r_r116;
    tuple_T3OOO cpy_r_r117;
    tuple_T3OOO cpy_r_r118;
    char cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    char cpy_r_r123;
    PyObject *cpy_r_r124;
    char cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    char cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject **cpy_r_r137;
    PyObject *cpy_r_r138;
    char cpy_r_r139;
    char cpy_r_r140;
    PyObject *cpy_r_r141;
    char cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    char cpy_r_r148;
    PyObject *cpy_r_r149;
    char cpy_r_r150;
    tuple_T3OOO cpy_r_r151;
    char cpy_r_r152;
    PyObject **cpy_r_r153;
    PyObject *cpy_r_r154;
    char cpy_r_r155;
    char cpy_r_r156;
    tuple_T3OOO cpy_r_r157;
    char cpy_r_r158;
    tuple_T3OOO cpy_r_r159;
    tuple_T3OOO cpy_r_r160;
    char cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject **cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    char cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    char cpy_r_r187;
    PyObject *cpy_r_r188;
    char cpy_r_r189;
    tuple_T3OOO cpy_r_r190;
    char cpy_r_r191;
    PyObject **cpy_r_r192;
    PyObject *cpy_r_r193;
    char cpy_r_r194;
    char cpy_r_r195;
    tuple_T3OOO cpy_r_r196;
    char cpy_r_r197;
    tuple_T3OOO cpy_r_r198;
    tuple_T3OOO cpy_r_r199;
    char cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    char cpy_r_r204;
    tuple_T3OOO cpy_r_r205;
    char cpy_r_r206;
    char cpy_r_r207;
    tuple_T3OOO cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject **cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    char cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    char cpy_r_r224;
    PyObject *cpy_r_r225;
    char cpy_r_r226;
    tuple_T3OOO cpy_r_r227;
    char cpy_r_r228;
    PyObject **cpy_r_r229;
    PyObject *cpy_r_r230;
    char cpy_r_r231;
    char cpy_r_r232;
    tuple_T3OOO cpy_r_r233;
    char cpy_r_r234;
    tuple_T3OOO cpy_r_r235;
    tuple_T3OOO cpy_r_r236;
    char cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    int32_t cpy_r_r241;
    char cpy_r_r242;
    char cpy_r_r243;
    tuple_T3OOO cpy_r_r244;
    tuple_T3OOO cpy_r_r245;
    char cpy_r_r246;
    tuple_T3OOO cpy_r_r247;
    tuple_T3OOO cpy_r_r248;
    char cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject **cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    char cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    char cpy_r_r263;
    PyObject *cpy_r_r264;
    char cpy_r_r265;
    tuple_T3OOO cpy_r_r266;
    char cpy_r_r267;
    PyObject **cpy_r_r268;
    PyObject *cpy_r_r269;
    char cpy_r_r270;
    char cpy_r_r271;
    tuple_T3OOO cpy_r_r272;
    char cpy_r_r273;
    tuple_T3OOO cpy_r_r274;
    tuple_T3OOO cpy_r_r275;
    char cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    char cpy_r_r280;
    char cpy_r_r281;
    tuple_T3OOO cpy_r_r282;
    char cpy_r_r283;
    char cpy_r_r284;
    tuple_T3OOO cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject **cpy_r_r292;
    PyObject *cpy_r_r293;
    PyObject *cpy_r_r294;
    char cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    char cpy_r_r301;
    PyObject *cpy_r_r302;
    char cpy_r_r303;
    tuple_T3OOO cpy_r_r304;
    char cpy_r_r305;
    PyObject **cpy_r_r306;
    PyObject *cpy_r_r307;
    char cpy_r_r308;
    char cpy_r_r309;
    tuple_T3OOO cpy_r_r310;
    char cpy_r_r311;
    tuple_T3OOO cpy_r_r312;
    tuple_T3OOO cpy_r_r313;
    char cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    int32_t cpy_r_r318;
    char cpy_r_r319;
    char cpy_r_r320;
    tuple_T3OOO cpy_r_r321;
    tuple_T3OOO cpy_r_r322;
    char cpy_r_r323;
    tuple_T3OOO cpy_r_r324;
    tuple_T3OOO cpy_r_r325;
    char cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject **cpy_r_r331;
    PyObject *cpy_r_r332;
    PyObject *cpy_r_r333;
    char cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    char cpy_r_r340;
    PyObject *cpy_r_r341;
    char cpy_r_r342;
    tuple_T3OOO cpy_r_r343;
    char cpy_r_r344;
    PyObject **cpy_r_r345;
    PyObject *cpy_r_r346;
    char cpy_r_r347;
    char cpy_r_r348;
    tuple_T3OOO cpy_r_r349;
    char cpy_r_r350;
    tuple_T3OOO cpy_r_r351;
    tuple_T3OOO cpy_r_r352;
    char cpy_r_r353;
    PyObject *cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_r356;
    char cpy_r_r357;
    char cpy_r_r358;
    PyObject *cpy_r_r359;
    PyObject *cpy_r_r360;
    PyObject *cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_r363;
    char cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject *cpy_r_r369;
    char cpy_r_r370;
    PyObject *cpy_r_r371;
    char cpy_r_r372;
    tuple_T3OOO cpy_r_r373;
    char cpy_r_r374;
    PyObject **cpy_r_r375;
    PyObject *cpy_r_r376;
    char cpy_r_r377;
    char cpy_r_r378;
    tuple_T3OOO cpy_r_r379;
    char cpy_r_r380;
    tuple_T3OOO cpy_r_r381;
    tuple_T3OOO cpy_r_r382;
    char cpy_r_r383;
    PyObject *cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    char cpy_r_r387;
    tuple_T3OOO cpy_r_r388;
    char cpy_r_r389;
    PyObject *cpy_r_r390;
    PyObject *cpy_r_r391;
    PyObject *cpy_r_r392;
    char cpy_r_r393;
    PyObject *cpy_r_r394;
    char cpy_r_r395;
    PyObject *cpy_r_r396;
    PyObject *cpy_r_r397;
    PyObject *cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject *cpy_r_r400;
    PyObject *cpy_r_r401;
    PyObject *cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    PyObject *cpy_r_r405;
    PyObject **cpy_r_r407;
    PyObject *cpy_r_r408;
    tuple_T3OOO cpy_r_r409;
    char cpy_r_r410;
    PyObject *cpy_r_r411;
    PyObject *cpy_r_r412;
    char cpy_r_r413;
    PyObject *cpy_r_r414;
    PyObject *cpy_r_r415;
    PyObject *cpy_r_r416;
    PyObject *cpy_r_r417;
    CPyTagged cpy_r_r418;
    PyObject *cpy_r_r419;
    char cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject **cpy_r_r423;
    PyObject *cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    PyObject *cpy_r_r427;
    char cpy_r_r428;
    char cpy_r_r429;
    char cpy_r_r430;
    char cpy_r_r431;
    char cpy_r_r432;
    char cpy_r_r433;
    char cpy_r_r434;
    char cpy_r_r435;
    char cpy_r_r436;
    char cpy_r_r437;
    char cpy_r_r438;
    char cpy_r_r439;
    PyObject *cpy_r_r440;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = NULL;
    cpy_r_r3 = cpy_r_r2;
    cpy_r_r4 = NULL;
    cpy_r_r5 = cpy_r_r4;
    cpy_r_r6 = NULL;
    cpy_r_r7 = cpy_r_r6;
    cpy_r_r8 = NULL;
    cpy_r_r9 = cpy_r_r8;
    cpy_r_r10 = NULL;
    cpy_r_r11 = cpy_r_r10;
    tuple_T3OOO __tmp1 = { NULL, NULL, NULL };
    cpy_r_r12 = __tmp1;
    cpy_r_r13 = cpy_r_r12;
    cpy_r_r14 = NULL;
    cpy_r_r15 = cpy_r_r14;
    cpy_r_r16 = NULL;
    cpy_r_r17 = cpy_r_r16;
    tuple_T3OOO __tmp2 = { NULL, NULL, NULL };
    cpy_r_r18 = __tmp2;
    cpy_r_r19 = cpy_r_r18;
    cpy_r_r20 = NULL;
    cpy_r_r21 = cpy_r_r20;
    cpy_r_r22 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_gen", "__mypyc_env__", 143, CPyStatic_globals);
        goto CPyL489;
    }
    CPy_INCREF(cpy_r_r22);
CPyL1: ;
    cpy_r_r23 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__;
    if (unlikely(cpy_r_r23 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_next_label__", 143, CPyStatic_globals);
        goto CPyL490;
    }
    CPyTagged_INCREF(cpy_r_r23);
CPyL2: ;
    cpy_r_r24 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_env__;
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_env__", 143, CPyStatic_globals);
        goto CPyL491;
    }
    CPy_INCREF(cpy_r_r24);
    goto CPyL476;
CPyL3: ;
    cpy_r_r25 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r26 = cpy_r_type != cpy_r_r25;
    if (cpy_r_r26) {
        goto CPyL492;
    } else
        goto CPyL6;
CPyL4: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL488;
    }
    CPy_Unreachable();
CPyL6: ;
    cpy_r_r27 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_override;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "override", 150, CPyStatic_globals);
        goto CPyL493;
    }
    CPy_INCREF(cpy_r_r27);
CPyL7: ;
    cpy_r_r28 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r29 = cpy_r_r27 != cpy_r_r28;
    if (!cpy_r_r29) goto CPyL494;
    if (likely(cpy_r_r27 != Py_None))
        cpy_r_r30 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "coroutine", 150, CPyStatic_globals, "dict", cpy_r_r27);
        goto CPyL493;
    }
    cpy_r_r31 = PyDict_Size(cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r32 = cpy_r_r31 << 1;
    cpy_r_r33 = cpy_r_r32 != 0;
    if (cpy_r_r33) {
        goto CPyL495;
    } else
        goto CPyL14;
CPyL10: ;
    cpy_r_r34 = CPyStatics[19]; /* 'Cannot use state override with `coroutine`.' */
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[20]; /* 'ValueError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 151, CPyStatic_globals);
        goto CPyL488;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r34};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 1, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 151, CPyStatic_globals);
        goto CPyL488;
    }
    CPy_Raise(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 151, CPyStatic_globals);
        goto CPyL488;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r41 = CPyStatic_ENVS;
    if (unlikely(cpy_r_r41 == NULL)) {
        goto CPyL496;
    } else
        goto CPyL17;
CPyL15: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r42 = 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL488;
    }
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r43 = CPyStatics[21]; /* 'BROWNIE_ENCODER_SEMAPHORE' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r41, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL493;
    }
    cpy_r_r45 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_block_identifier;
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "block_identifier", 152, CPyStatic_globals);
        goto CPyL497;
    }
    CPy_INCREF(cpy_r_r45);
CPyL19: ;
    cpy_r_r46 = PyObject_GetItem(cpy_r_r44, cpy_r_r45);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL493;
    }
    cpy_r_r47 = PyObject_Type(cpy_r_r46);
    cpy_r_r48 = CPyStatics[22]; /* '__aexit__' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL498;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0 = cpy_r_r49;
    cpy_r_r50 = 1;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL498;
    }
    cpy_r_r51 = CPyStatics[23]; /* '__aenter__' */
    cpy_r_r52 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r51);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL499;
    }
    PyObject *cpy_r_r53[1] = {cpy_r_r46};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 1, 0);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL499;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1 = cpy_r_r46;
    cpy_r_r56 = 1;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL500;
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__2 = 1;
    cpy_r_r57 = 1;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL500;
    }
    cpy_r_r58 = CPy_GetCoro(cpy_r_r55);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL493;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3 = cpy_r_r58;
    cpy_r_r59 = 1;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL493;
    }
    cpy_r_r60 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL493;
    }
    CPy_INCREF(cpy_r_r60);
CPyL29: ;
    cpy_r_r61 = CPyIter_Next(cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    if (cpy_r_r61 == NULL) {
        goto CPyL501;
    } else
        goto CPyL32;
CPyL30: ;
    cpy_r_r62 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL502;
    }
    cpy_r_r63 = cpy_r_r62;
    CPy_DECREF(cpy_r_r63);
    goto CPyL61;
CPyL32: ;
    cpy_r_r64 = cpy_r_r61;
CPyL33: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 2;
    cpy_r_r65 = 1;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL503;
    } else
        goto CPyL504;
CPyL34: ;
    return cpy_r_r64;
CPyL35: ;
    cpy_r_r66 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r67 = cpy_r_type != cpy_r_r66;
    if (!cpy_r_r67) goto CPyL38;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL505;
CPyL37: ;
    CPy_Unreachable();
CPyL38: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL56;
CPyL39: ;
    cpy_r_r68 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4 = cpy_r_r68;
    cpy_r_r69 = 1;
    if (unlikely(!cpy_r_r69)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL506;
    }
    cpy_r_r70 = (PyObject **)&cpy_r_r1;
    cpy_r_r71 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3;
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL506;
    }
    CPy_INCREF(cpy_r_r71);
CPyL41: ;
    cpy_r_r72 = CPy_YieldFromErrorHandle(cpy_r_r71, cpy_r_r70);
    CPy_DecRef(cpy_r_r71);
    if (unlikely(cpy_r_r72 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL506;
    }
    if (cpy_r_r72) goto CPyL48;
    if (cpy_r_r1 == NULL) {
        goto CPyL507;
    } else
        goto CPyL46;
CPyL44: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r73 = 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL53;
    } else
        goto CPyL508;
CPyL45: ;
    CPy_Unreachable();
CPyL46: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r64 = cpy_r_r1;
    cpy_r_r74 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4;
    if (unlikely(cpy_r_r74.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL509;
    }
    CPy_INCREF(cpy_r_r74.f0);
    CPy_INCREF(cpy_r_r74.f1);
    CPy_INCREF(cpy_r_r74.f2);
CPyL47: ;
    CPy_RestoreExcInfo(cpy_r_r74);
    CPy_DecRef(cpy_r_r74.f0);
    CPy_DecRef(cpy_r_r74.f1);
    CPy_DecRef(cpy_r_r74.f2);
    goto CPyL33;
CPyL48: ;
    if (cpy_r_r1 == NULL) {
        goto CPyL510;
    } else
        goto CPyL51;
CPyL49: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r75 = 0;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL53;
    } else
        goto CPyL511;
CPyL50: ;
    CPy_Unreachable();
CPyL51: ;
    cpy_r_r63 = cpy_r_r1;
    CPy_DecRef(cpy_r_r63);
    cpy_r_r76 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4;
    if (unlikely(cpy_r_r76.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL512;
    }
    CPy_INCREF(cpy_r_r76.f0);
    CPy_INCREF(cpy_r_r76.f1);
    CPy_INCREF(cpy_r_r76.f2);
CPyL52: ;
    CPy_RestoreExcInfo(cpy_r_r76);
    CPy_DecRef(cpy_r_r76.f0);
    CPy_DecRef(cpy_r_r76.f1);
    CPy_DecRef(cpy_r_r76.f2);
    goto CPyL61;
CPyL53: ;
    cpy_r_r77 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4;
    if (unlikely(cpy_r_r77.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__4' of 'coroutine__get_coroutine_fn_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r77.f0);
        CPy_INCREF(cpy_r_r77.f1);
        CPy_INCREF(cpy_r_r77.f2);
    }
    CPy_DecRef(cpy_r_r22);
    if (unlikely(cpy_r_r77.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL488;
    }
CPyL54: ;
    CPy_RestoreExcInfo(cpy_r_r77);
    CPy_DecRef(cpy_r_r77.f0);
    CPy_DecRef(cpy_r_r77.f1);
    CPy_DecRef(cpy_r_r77.f2);
    cpy_r_r78 = CPy_KeepPropagating();
    if (!cpy_r_r78) goto CPyL488;
    CPy_Unreachable();
CPyL56: ;
    cpy_r_r79 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3;
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL513;
    }
    CPy_INCREF(cpy_r_r79);
CPyL57: ;
    cpy_r_r80 = CPyIter_Send(cpy_r_r79, cpy_r_arg);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r80 == NULL) goto CPyL514;
    cpy_r_r64 = cpy_r_r80;
    goto CPyL33;
CPyL59: ;
    cpy_r_r81 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL502;
    }
    cpy_r_r63 = cpy_r_r81;
    CPy_DECREF(cpy_r_r63);
CPyL61: ;
    cpy_r_r82 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 153, CPyStatic_globals);
        goto CPyL515;
    }
    CPy_INCREF(cpy_r_r82);
CPyL62: ;
    cpy_r_r83 = ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r24)->_len_inputs;
    if (unlikely(cpy_r_r83 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "_get_coroutine_fn_env", "len_inputs", 153, CPyStatic_globals);
        goto CPyL516;
    }
    CPyTagged_INCREF(cpy_r_r83);
CPyL63: ;
    cpy_r_r84 = ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r24)->_get_request_data;
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "_get_coroutine_fn_env", "get_request_data", 153, CPyStatic_globals);
        goto CPyL517;
    }
    CPy_INCREF(cpy_r_r84);
CPyL64: ;
    cpy_r_r85 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_args;
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "args", 153, CPyStatic_globals);
        goto CPyL518;
    }
    CPy_INCREF(cpy_r_r85);
CPyL65: ;
    cpy_r_r86 = CPyStatic_globals;
    cpy_r_r87 = CPyStatics[24]; /* 'encode_input' */
    cpy_r_r88 = CPyDict_GetItem(cpy_r_r86, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL519;
    }
    cpy_r_r89 = PyList_New(3);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL520;
    }
    cpy_r_r90 = CPyTagged_StealAsObject(cpy_r_r83);
    cpy_r_r91 = (CPyPtr)&((PyListObject *)cpy_r_r89)->ob_item;
    cpy_r_r92 = *(CPyPtr *)cpy_r_r91;
    *(PyObject * *)cpy_r_r92 = cpy_r_r82;
    cpy_r_r93 = cpy_r_r92 + 8;
    *(PyObject * *)cpy_r_r93 = cpy_r_r90;
    cpy_r_r94 = cpy_r_r92 + 16;
    *(PyObject * *)cpy_r_r94 = cpy_r_r84;
    cpy_r_r95 = CPyList_Extend(cpy_r_r89, cpy_r_r85);
    CPy_DECREF(cpy_r_r85);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL521;
    } else
        goto CPyL522;
CPyL68: ;
    cpy_r_r96 = PyList_AsTuple(cpy_r_r89);
    CPy_DECREF(cpy_r_r89);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL523;
    }
    cpy_r_r97 = PyDict_New();
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL524;
    }
    cpy_r_r98 = PyObject_Call(cpy_r_r88, cpy_r_r96, cpy_r_r97);
    CPy_DECREF(cpy_r_r88);
    CPy_DECREF(cpy_r_r96);
    CPy_DECREF(cpy_r_r97);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL515;
    }
    cpy_r_r99 = CPy_GetCoro(cpy_r_r98);
    CPy_DECREF(cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL515;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5 = cpy_r_r99;
    cpy_r_r100 = 1;
    if (unlikely(!cpy_r_r100)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL515;
    }
    cpy_r_r101 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5;
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL515;
    }
    CPy_INCREF(cpy_r_r101);
CPyL74: ;
    cpy_r_r102 = CPyIter_Next(cpy_r_r101);
    CPy_DECREF(cpy_r_r101);
    if (cpy_r_r102 == NULL) {
        goto CPyL525;
    } else
        goto CPyL77;
CPyL75: ;
    cpy_r_r103 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL526;
    }
    cpy_r_r104 = cpy_r_r103;
    goto CPyL106;
CPyL77: ;
    cpy_r_r105 = cpy_r_r102;
CPyL78: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 4;
    cpy_r_r106 = 1;
    if (unlikely(!cpy_r_r106)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL527;
    } else
        goto CPyL528;
CPyL79: ;
    return cpy_r_r105;
CPyL80: ;
    cpy_r_r107 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r108 = cpy_r_type != cpy_r_r107;
    if (!cpy_r_r108) goto CPyL83;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL84;
    } else
        goto CPyL529;
CPyL82: ;
    CPy_Unreachable();
CPyL83: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL101;
CPyL84: ;
    cpy_r_r109 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6 = cpy_r_r109;
    cpy_r_r110 = 1;
    if (unlikely(!cpy_r_r110)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL530;
    }
    cpy_r_r111 = (PyObject **)&cpy_r_r3;
    cpy_r_r112 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5;
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL530;
    }
    CPy_INCREF(cpy_r_r112);
CPyL86: ;
    cpy_r_r113 = CPy_YieldFromErrorHandle(cpy_r_r112, cpy_r_r111);
    CPy_DecRef(cpy_r_r112);
    if (unlikely(cpy_r_r113 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL530;
    }
    if (cpy_r_r113) goto CPyL93;
    if (cpy_r_r3 == NULL) {
        goto CPyL531;
    } else
        goto CPyL91;
CPyL89: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r114 = 0;
    if (unlikely(!cpy_r_r114)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL98;
    } else
        goto CPyL532;
CPyL90: ;
    CPy_Unreachable();
CPyL91: ;
    CPy_INCREF(cpy_r_r3);
    cpy_r_r105 = cpy_r_r3;
    cpy_r_r115 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6;
    if (unlikely(cpy_r_r115.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__6", -1, CPyStatic_globals);
        goto CPyL533;
    }
    CPy_INCREF(cpy_r_r115.f0);
    CPy_INCREF(cpy_r_r115.f1);
    CPy_INCREF(cpy_r_r115.f2);
CPyL92: ;
    CPy_RestoreExcInfo(cpy_r_r115);
    CPy_DecRef(cpy_r_r115.f0);
    CPy_DecRef(cpy_r_r115.f1);
    CPy_DecRef(cpy_r_r115.f2);
    goto CPyL78;
CPyL93: ;
    if (cpy_r_r3 == NULL) {
        goto CPyL534;
    } else
        goto CPyL96;
CPyL94: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r116 = 0;
    if (unlikely(!cpy_r_r116)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL98;
    } else
        goto CPyL535;
CPyL95: ;
    CPy_Unreachable();
CPyL96: ;
    cpy_r_r104 = cpy_r_r3;
    cpy_r_r117 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6;
    if (unlikely(cpy_r_r117.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__6", -1, CPyStatic_globals);
        goto CPyL536;
    }
    CPy_INCREF(cpy_r_r117.f0);
    CPy_INCREF(cpy_r_r117.f1);
    CPy_INCREF(cpy_r_r117.f2);
CPyL97: ;
    CPy_RestoreExcInfo(cpy_r_r117);
    CPy_DecRef(cpy_r_r117.f0);
    CPy_DecRef(cpy_r_r117.f1);
    CPy_DecRef(cpy_r_r117.f2);
    goto CPyL106;
CPyL98: ;
    cpy_r_r118 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6;
    if (unlikely(cpy_r_r118.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__6", -1, CPyStatic_globals);
        goto CPyL299;
    }
    CPy_INCREF(cpy_r_r118.f0);
    CPy_INCREF(cpy_r_r118.f1);
    CPy_INCREF(cpy_r_r118.f2);
CPyL99: ;
    CPy_RestoreExcInfo(cpy_r_r118);
    CPy_DecRef(cpy_r_r118.f0);
    CPy_DecRef(cpy_r_r118.f1);
    CPy_DecRef(cpy_r_r118.f2);
    cpy_r_r119 = CPy_KeepPropagating();
    if (!cpy_r_r119) {
        goto CPyL299;
    } else
        goto CPyL537;
CPyL100: ;
    CPy_Unreachable();
CPyL101: ;
    cpy_r_r120 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5;
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL538;
    }
    CPy_INCREF(cpy_r_r120);
CPyL102: ;
    cpy_r_r121 = CPyIter_Send(cpy_r_r120, cpy_r_arg);
    CPy_DECREF(cpy_r_r120);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r121 == NULL) goto CPyL539;
    cpy_r_r105 = cpy_r_r121;
    goto CPyL78;
CPyL104: ;
    cpy_r_r122 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL526;
    }
    cpy_r_r104 = cpy_r_r122;
CPyL106: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_data);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_data = cpy_r_r104;
    cpy_r_r123 = 1;
    if (unlikely(!cpy_r_r123)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 153, CPyStatic_globals);
        goto CPyL526;
    }
    cpy_r_r124 = CPyStatic_ENVS;
    if (unlikely(cpy_r_r124 == NULL)) {
        goto CPyL540;
    } else
        goto CPyL110;
CPyL108: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r125 = 0;
    if (unlikely(!cpy_r_r125)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL299;
    } else
        goto CPyL541;
CPyL109: ;
    CPy_Unreachable();
CPyL110: ;
    cpy_r_r126 = CPyStatics[25]; /* 'BROWNIE_CALL_SEMAPHORE' */
    cpy_r_r127 = CPyObject_GetAttr(cpy_r_r124, cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL526;
    }
    cpy_r_r128 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_block_identifier;
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "block_identifier", 154, CPyStatic_globals);
        goto CPyL542;
    }
    CPy_INCREF(cpy_r_r128);
CPyL112: ;
    cpy_r_r129 = PyObject_GetItem(cpy_r_r127, cpy_r_r128);
    CPy_DECREF(cpy_r_r127);
    CPy_DECREF(cpy_r_r128);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL526;
    }
    cpy_r_r130 = PyObject_Type(cpy_r_r129);
    cpy_r_r131 = CPyStatics[22]; /* '__aexit__' */
    cpy_r_r132 = CPyObject_GetAttr(cpy_r_r130, cpy_r_r131);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL543;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7 = cpy_r_r132;
    cpy_r_r133 = 1;
    if (unlikely(!cpy_r_r133)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL543;
    }
    cpy_r_r134 = CPyStatics[23]; /* '__aenter__' */
    cpy_r_r135 = CPyObject_GetAttr(cpy_r_r130, cpy_r_r134);
    CPy_DECREF(cpy_r_r130);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL544;
    }
    PyObject *cpy_r_r136[1] = {cpy_r_r129};
    cpy_r_r137 = (PyObject **)&cpy_r_r136;
    cpy_r_r138 = _PyObject_Vectorcall(cpy_r_r135, cpy_r_r137, 1, 0);
    CPy_DECREF(cpy_r_r135);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL544;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8 = cpy_r_r129;
    cpy_r_r139 = 1;
    if (unlikely(!cpy_r_r139)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL545;
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__9 = 1;
    cpy_r_r140 = 1;
    if (unlikely(!cpy_r_r140)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL545;
    }
    cpy_r_r141 = CPy_GetCoro(cpy_r_r138);
    CPy_DECREF(cpy_r_r138);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL526;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10 = cpy_r_r141;
    cpy_r_r142 = 1;
    if (unlikely(!cpy_r_r142)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL526;
    }
    cpy_r_r143 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10;
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL526;
    }
    CPy_INCREF(cpy_r_r143);
CPyL122: ;
    cpy_r_r144 = CPyIter_Next(cpy_r_r143);
    CPy_DECREF(cpy_r_r143);
    if (cpy_r_r144 == NULL) {
        goto CPyL546;
    } else
        goto CPyL125;
CPyL123: ;
    cpy_r_r145 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL547;
    }
    cpy_r_r146 = cpy_r_r145;
    CPy_DECREF(cpy_r_r146);
    goto CPyL154;
CPyL125: ;
    cpy_r_r147 = cpy_r_r144;
CPyL126: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 6;
    cpy_r_r148 = 1;
    if (unlikely(!cpy_r_r148)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL548;
    } else
        goto CPyL549;
CPyL127: ;
    return cpy_r_r147;
CPyL128: ;
    cpy_r_r149 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r150 = cpy_r_type != cpy_r_r149;
    if (!cpy_r_r150) goto CPyL131;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL132;
    } else
        goto CPyL550;
CPyL130: ;
    CPy_Unreachable();
CPyL131: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL149;
CPyL132: ;
    cpy_r_r151 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11 = cpy_r_r151;
    cpy_r_r152 = 1;
    if (unlikely(!cpy_r_r152)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL551;
    }
    cpy_r_r153 = (PyObject **)&cpy_r_r5;
    cpy_r_r154 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10;
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL551;
    }
    CPy_INCREF(cpy_r_r154);
CPyL134: ;
    cpy_r_r155 = CPy_YieldFromErrorHandle(cpy_r_r154, cpy_r_r153);
    CPy_DecRef(cpy_r_r154);
    if (unlikely(cpy_r_r155 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL551;
    }
    if (cpy_r_r155) goto CPyL141;
    if (cpy_r_r5 == NULL) {
        goto CPyL552;
    } else
        goto CPyL139;
CPyL137: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r156 = 0;
    if (unlikely(!cpy_r_r156)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL146;
    } else
        goto CPyL553;
CPyL138: ;
    CPy_Unreachable();
CPyL139: ;
    CPy_INCREF(cpy_r_r5);
    cpy_r_r147 = cpy_r_r5;
    cpy_r_r157 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11;
    if (unlikely(cpy_r_r157.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL554;
    }
    CPy_INCREF(cpy_r_r157.f0);
    CPy_INCREF(cpy_r_r157.f1);
    CPy_INCREF(cpy_r_r157.f2);
CPyL140: ;
    CPy_RestoreExcInfo(cpy_r_r157);
    CPy_DecRef(cpy_r_r157.f0);
    CPy_DecRef(cpy_r_r157.f1);
    CPy_DecRef(cpy_r_r157.f2);
    goto CPyL126;
CPyL141: ;
    if (cpy_r_r5 == NULL) {
        goto CPyL555;
    } else
        goto CPyL144;
CPyL142: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r158 = 0;
    if (unlikely(!cpy_r_r158)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL146;
    } else
        goto CPyL556;
CPyL143: ;
    CPy_Unreachable();
CPyL144: ;
    cpy_r_r146 = cpy_r_r5;
    CPy_DecRef(cpy_r_r146);
    cpy_r_r159 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11;
    if (unlikely(cpy_r_r159.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL557;
    }
    CPy_INCREF(cpy_r_r159.f0);
    CPy_INCREF(cpy_r_r159.f1);
    CPy_INCREF(cpy_r_r159.f2);
CPyL145: ;
    CPy_RestoreExcInfo(cpy_r_r159);
    CPy_DecRef(cpy_r_r159.f0);
    CPy_DecRef(cpy_r_r159.f1);
    CPy_DecRef(cpy_r_r159.f2);
    goto CPyL154;
CPyL146: ;
    cpy_r_r160 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11;
    if (unlikely(cpy_r_r160.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL299;
    }
    CPy_INCREF(cpy_r_r160.f0);
    CPy_INCREF(cpy_r_r160.f1);
    CPy_INCREF(cpy_r_r160.f2);
CPyL147: ;
    CPy_RestoreExcInfo(cpy_r_r160);
    CPy_DecRef(cpy_r_r160.f0);
    CPy_DecRef(cpy_r_r160.f1);
    CPy_DecRef(cpy_r_r160.f2);
    cpy_r_r161 = CPy_KeepPropagating();
    if (!cpy_r_r161) {
        goto CPyL299;
    } else
        goto CPyL558;
CPyL148: ;
    CPy_Unreachable();
CPyL149: ;
    cpy_r_r162 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10;
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL559;
    }
    CPy_INCREF(cpy_r_r162);
CPyL150: ;
    cpy_r_r163 = CPyIter_Send(cpy_r_r162, cpy_r_arg);
    CPy_DECREF(cpy_r_r162);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r163 == NULL) goto CPyL560;
    cpy_r_r147 = cpy_r_r163;
    goto CPyL126;
CPyL152: ;
    cpy_r_r164 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL547;
    }
    cpy_r_r146 = cpy_r_r164;
    CPy_DECREF(cpy_r_r146);
CPyL154: ;
    cpy_r_r165 = ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r24)->_w3;
    if (unlikely(cpy_r_r165 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'w3' of '_get_coroutine_fn_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r165);
    }
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r165 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL561;
    }
CPyL155: ;
    cpy_r_r166 = CPyStatics[26]; /* 'eth' */
    cpy_r_r167 = CPyObject_GetAttr(cpy_r_r165, cpy_r_r166);
    CPy_DECREF(cpy_r_r165);
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL561;
    }
    cpy_r_r168 = CPyStatics[27]; /* 'to' */
    cpy_r_r169 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 155, CPyStatic_globals);
        goto CPyL562;
    }
    CPy_INCREF(cpy_r_r169);
CPyL157: ;
    cpy_r_r170 = CPyStatics[10]; /* '_address' */
    cpy_r_r171 = CPyObject_GetAttr(cpy_r_r169, cpy_r_r170);
    CPy_DECREF(cpy_r_r169);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL562;
    }
    cpy_r_r172 = CPyStatics[28]; /* 'data' */
    cpy_r_r173 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_data;
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "data", 155, CPyStatic_globals);
        goto CPyL563;
    }
    CPy_INCREF(cpy_r_r173);
CPyL159: ;
    cpy_r_r174 = CPyDict_Build(2, cpy_r_r168, cpy_r_r171, cpy_r_r172, cpy_r_r173);
    CPy_DECREF(cpy_r_r171);
    CPy_DECREF(cpy_r_r173);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL562;
    }
    cpy_r_r175 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_block_identifier;
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "block_identifier", 155, CPyStatic_globals);
        goto CPyL564;
    }
    CPy_INCREF(cpy_r_r175);
CPyL161: ;
    cpy_r_r176 = CPyStatics[29]; /* 'call' */
    PyObject *cpy_r_r177[3] = {cpy_r_r167, cpy_r_r174, cpy_r_r175};
    cpy_r_r178 = (PyObject **)&cpy_r_r177;
    cpy_r_r179 = PyObject_VectorcallMethod(cpy_r_r176, cpy_r_r178, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL565;
    }
    CPy_DECREF(cpy_r_r167);
    CPy_DECREF(cpy_r_r174);
    CPy_DECREF(cpy_r_r175);
    cpy_r_r180 = CPy_GetCoro(cpy_r_r179);
    CPy_DECREF(cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL561;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12 = cpy_r_r180;
    cpy_r_r181 = 1;
    if (unlikely(!cpy_r_r181)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL561;
    }
    cpy_r_r182 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12;
    if (unlikely(cpy_r_r182 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL561;
    }
    CPy_INCREF(cpy_r_r182);
CPyL165: ;
    cpy_r_r183 = CPyIter_Next(cpy_r_r182);
    CPy_DECREF(cpy_r_r182);
    if (cpy_r_r183 == NULL) {
        goto CPyL566;
    } else
        goto CPyL168;
CPyL166: ;
    cpy_r_r184 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r185 = cpy_r_r184;
    goto CPyL197;
CPyL168: ;
    cpy_r_r186 = cpy_r_r183;
CPyL169: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 8;
    cpy_r_r187 = 1;
    if (unlikely(!cpy_r_r187)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL567;
    } else
        goto CPyL568;
CPyL170: ;
    return cpy_r_r186;
CPyL171: ;
    cpy_r_r188 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r189 = cpy_r_type != cpy_r_r188;
    if (!cpy_r_r189) goto CPyL174;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL175;
    } else
        goto CPyL569;
CPyL173: ;
    CPy_Unreachable();
CPyL174: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL192;
CPyL175: ;
    cpy_r_r190 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13 = cpy_r_r190;
    cpy_r_r191 = 1;
    if (unlikely(!cpy_r_r191)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL570;
    }
    cpy_r_r192 = (PyObject **)&cpy_r_r7;
    cpy_r_r193 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12;
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL570;
    }
    CPy_INCREF(cpy_r_r193);
CPyL177: ;
    cpy_r_r194 = CPy_YieldFromErrorHandle(cpy_r_r193, cpy_r_r192);
    CPy_DecRef(cpy_r_r193);
    if (unlikely(cpy_r_r194 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL570;
    }
    if (cpy_r_r194) goto CPyL184;
    if (cpy_r_r7 != NULL) goto CPyL182;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r195 = 0;
    if (unlikely(!cpy_r_r195)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL189;
    } else
        goto CPyL571;
CPyL181: ;
    CPy_Unreachable();
CPyL182: ;
    CPy_INCREF(cpy_r_r7);
    cpy_r_r186 = cpy_r_r7;
    cpy_r_r196 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13;
    if (unlikely(cpy_r_r196.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL572;
    }
    CPy_INCREF(cpy_r_r196.f0);
    CPy_INCREF(cpy_r_r196.f1);
    CPy_INCREF(cpy_r_r196.f2);
CPyL183: ;
    CPy_RestoreExcInfo(cpy_r_r196);
    CPy_DecRef(cpy_r_r196.f0);
    CPy_DecRef(cpy_r_r196.f1);
    CPy_DecRef(cpy_r_r196.f2);
    goto CPyL169;
CPyL184: ;
    if (cpy_r_r7 != NULL) goto CPyL187;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r197 = 0;
    if (unlikely(!cpy_r_r197)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL189;
    } else
        goto CPyL573;
CPyL186: ;
    CPy_Unreachable();
CPyL187: ;
    cpy_r_r185 = cpy_r_r7;
    cpy_r_r198 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13;
    if (unlikely(cpy_r_r198.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL574;
    }
    CPy_INCREF(cpy_r_r198.f0);
    CPy_INCREF(cpy_r_r198.f1);
    CPy_INCREF(cpy_r_r198.f2);
CPyL188: ;
    CPy_RestoreExcInfo(cpy_r_r198);
    CPy_DecRef(cpy_r_r198.f0);
    CPy_DecRef(cpy_r_r198.f1);
    CPy_DecRef(cpy_r_r198.f2);
    goto CPyL197;
CPyL189: ;
    cpy_r_r199 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13;
    if (unlikely(cpy_r_r199.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_INCREF(cpy_r_r199.f0);
    CPy_INCREF(cpy_r_r199.f1);
    CPy_INCREF(cpy_r_r199.f2);
CPyL190: ;
    CPy_RestoreExcInfo(cpy_r_r199);
    CPy_DecRef(cpy_r_r199.f0);
    CPy_DecRef(cpy_r_r199.f1);
    CPy_DecRef(cpy_r_r199.f2);
    cpy_r_r200 = CPy_KeepPropagating();
    if (!cpy_r_r200) {
        goto CPyL198;
    } else
        goto CPyL575;
CPyL191: ;
    CPy_Unreachable();
CPyL192: ;
    cpy_r_r201 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12;
    if (unlikely(cpy_r_r201 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL576;
    }
    CPy_INCREF(cpy_r_r201);
CPyL193: ;
    cpy_r_r202 = CPyIter_Send(cpy_r_r201, cpy_r_arg);
    CPy_DECREF(cpy_r_r201);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r202 == NULL) goto CPyL577;
    cpy_r_r186 = cpy_r_r202;
    goto CPyL169;
CPyL195: ;
    cpy_r_r203 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r185 = cpy_r_r203;
CPyL197: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output = cpy_r_r185;
    cpy_r_r204 = 1;
    if (unlikely(!cpy_r_r204)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 155, CPyStatic_globals);
    } else
        goto CPyL578;
CPyL198: ;
    cpy_r_r205 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14 = cpy_r_r205;
    cpy_r_r206 = 1;
    if (unlikely(!cpy_r_r206)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL579;
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__9 = 0;
    cpy_r_r207 = 1;
    if (unlikely(!cpy_r_r207)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL579;
    }
    cpy_r_r208 = CPy_GetExcInfo();
    cpy_r_r209 = cpy_r_r208.f0;
    CPy_INCREF(cpy_r_r209);
    cpy_r_r210 = cpy_r_r208.f1;
    CPy_INCREF(cpy_r_r210);
    cpy_r_r211 = cpy_r_r208.f2;
    CPy_INCREF(cpy_r_r211);
    CPy_DecRef(cpy_r_r208.f0);
    CPy_DecRef(cpy_r_r208.f1);
    CPy_DecRef(cpy_r_r208.f2);
    cpy_r_r212 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7;
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__7", -1, CPyStatic_globals);
        goto CPyL580;
    }
    CPy_INCREF(cpy_r_r212);
CPyL201: ;
    cpy_r_r213 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8;
    if (unlikely(cpy_r_r213 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL581;
    }
    CPy_INCREF(cpy_r_r213);
CPyL202: ;
    PyObject *cpy_r_r214[4] = {cpy_r_r213, cpy_r_r209, cpy_r_r210, cpy_r_r211};
    cpy_r_r215 = (PyObject **)&cpy_r_r214;
    cpy_r_r216 = _PyObject_Vectorcall(cpy_r_r212, cpy_r_r215, 4, 0);
    CPy_DecRef(cpy_r_r212);
    if (unlikely(cpy_r_r216 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL582;
    }
    CPy_DecRef(cpy_r_r213);
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    cpy_r_r217 = CPy_GetCoro(cpy_r_r216);
    CPy_DecRef(cpy_r_r216);
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL579;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15 = cpy_r_r217;
    cpy_r_r218 = 1;
    if (unlikely(!cpy_r_r218)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL579;
    }
    cpy_r_r219 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15;
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL579;
    }
    CPy_INCREF(cpy_r_r219);
CPyL206: ;
    cpy_r_r220 = CPyIter_Next(cpy_r_r219);
    CPy_DecRef(cpy_r_r219);
    if (cpy_r_r220 == NULL) {
        goto CPyL583;
    } else
        goto CPyL209;
CPyL207: ;
    cpy_r_r221 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r221 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL244;
    }
    cpy_r_r222 = cpy_r_r221;
    goto CPyL238;
CPyL209: ;
    cpy_r_r223 = cpy_r_r220;
CPyL210: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 10;
    cpy_r_r224 = 1;
    if (unlikely(!cpy_r_r224)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL584;
    } else
        goto CPyL585;
CPyL211: ;
    return cpy_r_r223;
CPyL212: ;
    cpy_r_r225 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r226 = cpy_r_type != cpy_r_r225;
    if (!cpy_r_r226) goto CPyL215;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL216;
    } else
        goto CPyL586;
CPyL214: ;
    CPy_Unreachable();
CPyL215: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL233;
CPyL216: ;
    cpy_r_r227 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16 = cpy_r_r227;
    cpy_r_r228 = 1;
    if (unlikely(!cpy_r_r228)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL587;
    }
    cpy_r_r229 = (PyObject **)&cpy_r_r9;
    cpy_r_r230 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15;
    if (unlikely(cpy_r_r230 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL587;
    }
    CPy_INCREF(cpy_r_r230);
CPyL218: ;
    cpy_r_r231 = CPy_YieldFromErrorHandle(cpy_r_r230, cpy_r_r229);
    CPy_DecRef(cpy_r_r230);
    if (unlikely(cpy_r_r231 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL587;
    }
    if (cpy_r_r231) goto CPyL225;
    if (cpy_r_r9 != NULL) goto CPyL223;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r232 = 0;
    if (unlikely(!cpy_r_r232)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL230;
    } else
        goto CPyL588;
CPyL222: ;
    CPy_Unreachable();
CPyL223: ;
    CPy_INCREF(cpy_r_r9);
    cpy_r_r223 = cpy_r_r9;
    cpy_r_r233 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16;
    if (unlikely(cpy_r_r233.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__16", -1, CPyStatic_globals);
        goto CPyL589;
    }
    CPy_INCREF(cpy_r_r233.f0);
    CPy_INCREF(cpy_r_r233.f1);
    CPy_INCREF(cpy_r_r233.f2);
CPyL224: ;
    CPy_RestoreExcInfo(cpy_r_r233);
    CPy_DecRef(cpy_r_r233.f0);
    CPy_DecRef(cpy_r_r233.f1);
    CPy_DecRef(cpy_r_r233.f2);
    goto CPyL210;
CPyL225: ;
    if (cpy_r_r9 != NULL) goto CPyL228;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r234 = 0;
    if (unlikely(!cpy_r_r234)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL230;
    } else
        goto CPyL590;
CPyL227: ;
    CPy_Unreachable();
CPyL228: ;
    cpy_r_r222 = cpy_r_r9;
    cpy_r_r235 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16;
    if (unlikely(cpy_r_r235.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__16", -1, CPyStatic_globals);
        goto CPyL591;
    }
    CPy_INCREF(cpy_r_r235.f0);
    CPy_INCREF(cpy_r_r235.f1);
    CPy_INCREF(cpy_r_r235.f2);
CPyL229: ;
    CPy_RestoreExcInfo(cpy_r_r235);
    CPy_DecRef(cpy_r_r235.f0);
    CPy_DecRef(cpy_r_r235.f1);
    CPy_DecRef(cpy_r_r235.f2);
    goto CPyL238;
CPyL230: ;
    cpy_r_r236 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16;
    if (unlikely(cpy_r_r236.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__16", -1, CPyStatic_globals);
        goto CPyL244;
    }
    CPy_INCREF(cpy_r_r236.f0);
    CPy_INCREF(cpy_r_r236.f1);
    CPy_INCREF(cpy_r_r236.f2);
CPyL231: ;
    CPy_RestoreExcInfo(cpy_r_r236);
    CPy_DecRef(cpy_r_r236.f0);
    CPy_DecRef(cpy_r_r236.f1);
    CPy_DecRef(cpy_r_r236.f2);
    cpy_r_r237 = CPy_KeepPropagating();
    if (!cpy_r_r237) {
        goto CPyL244;
    } else
        goto CPyL592;
CPyL232: ;
    CPy_Unreachable();
CPyL233: ;
    cpy_r_r238 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15;
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL593;
    }
    CPy_INCREF(cpy_r_r238);
CPyL234: ;
    cpy_r_r239 = CPyIter_Send(cpy_r_r238, cpy_r_arg);
    CPy_DECREF(cpy_r_r238);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r239 == NULL) goto CPyL594;
    cpy_r_r223 = cpy_r_r239;
    goto CPyL210;
CPyL236: ;
    cpy_r_r240 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL244;
    }
    cpy_r_r222 = cpy_r_r240;
CPyL238: ;
    cpy_r_r241 = PyObject_IsTrue(cpy_r_r222);
    CPy_DECREF(cpy_r_r222);
    cpy_r_r242 = cpy_r_r241 >= 0;
    if (unlikely(!cpy_r_r242)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL244;
    }
    cpy_r_r243 = cpy_r_r241;
    if (cpy_r_r243) goto CPyL242;
    CPy_Reraise();
    if (!0) {
        goto CPyL244;
    } else
        goto CPyL595;
CPyL241: ;
    CPy_Unreachable();
CPyL242: ;
    cpy_r_r244 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14;
    if (unlikely(cpy_r_r244.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL248;
    }
    CPy_INCREF(cpy_r_r244.f0);
    CPy_INCREF(cpy_r_r244.f1);
    CPy_INCREF(cpy_r_r244.f2);
CPyL243: ;
    CPy_RestoreExcInfo(cpy_r_r244);
    CPy_DECREF(cpy_r_r244.f0);
    CPy_DECREF(cpy_r_r244.f1);
    CPy_DECREF(cpy_r_r244.f2);
    goto CPyL247;
CPyL244: ;
    cpy_r_r245 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14;
    if (unlikely(cpy_r_r245.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL248;
    }
    CPy_INCREF(cpy_r_r245.f0);
    CPy_INCREF(cpy_r_r245.f1);
    CPy_INCREF(cpy_r_r245.f2);
CPyL245: ;
    CPy_RestoreExcInfo(cpy_r_r245);
    CPy_DECREF(cpy_r_r245.f0);
    CPy_DECREF(cpy_r_r245.f1);
    CPy_DECREF(cpy_r_r245.f2);
    cpy_r_r246 = CPy_KeepPropagating();
    if (!cpy_r_r246) {
        goto CPyL248;
    } else
        goto CPyL596;
CPyL246: ;
    CPy_Unreachable();
CPyL247: ;
    tuple_T3OOO __tmp3 = { NULL, NULL, NULL };
    cpy_r_r247 = __tmp3;
    cpy_r_r13 = cpy_r_r247;
    goto CPyL249;
CPyL248: ;
    cpy_r_r248 = CPy_CatchError();
    cpy_r_r13 = cpy_r_r248;
CPyL249: ;
    cpy_r_r249 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__9;
    if (unlikely(cpy_r_r249 == 2)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL597;
    }
CPyL250: ;
    if (!cpy_r_r249) goto CPyL598;
CPyL251: ;
    cpy_r_r250 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r251 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7;
    if (unlikely(cpy_r_r251 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__7", -1, CPyStatic_globals);
        goto CPyL597;
    }
    CPy_INCREF(cpy_r_r251);
CPyL252: ;
    cpy_r_r252 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8;
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL599;
    }
    CPy_INCREF(cpy_r_r252);
CPyL253: ;
    PyObject *cpy_r_r253[4] = {cpy_r_r252, cpy_r_r250, cpy_r_r250, cpy_r_r250};
    cpy_r_r254 = (PyObject **)&cpy_r_r253;
    cpy_r_r255 = _PyObject_Vectorcall(cpy_r_r251, cpy_r_r254, 4, 0);
    CPy_DECREF(cpy_r_r251);
    if (unlikely(cpy_r_r255 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL600;
    }
    CPy_DECREF(cpy_r_r252);
    cpy_r_r256 = CPy_GetCoro(cpy_r_r255);
    CPy_DECREF(cpy_r_r255);
    if (unlikely(cpy_r_r256 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL597;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17 = cpy_r_r256;
    cpy_r_r257 = 1;
    if (unlikely(!cpy_r_r257)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL597;
    }
    cpy_r_r258 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17;
    if (unlikely(cpy_r_r258 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__17", -1, CPyStatic_globals);
        goto CPyL597;
    }
    CPy_INCREF(cpy_r_r258);
CPyL257: ;
    cpy_r_r259 = CPyIter_Next(cpy_r_r258);
    CPy_DECREF(cpy_r_r258);
    if (cpy_r_r259 == NULL) {
        goto CPyL601;
    } else
        goto CPyL260;
CPyL258: ;
    cpy_r_r260 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r260 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL292;
    }
    cpy_r_r261 = cpy_r_r260;
    CPy_DECREF(cpy_r_r261);
    goto CPyL289;
CPyL260: ;
    cpy_r_r262 = cpy_r_r259;
CPyL261: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 12;
    cpy_r_r263 = 1;
    if (unlikely(!cpy_r_r263)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL602;
    } else
        goto CPyL603;
CPyL262: ;
    return cpy_r_r262;
CPyL263: ;
    cpy_r_r264 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r265 = cpy_r_type != cpy_r_r264;
    if (!cpy_r_r265) goto CPyL266;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL267;
    } else
        goto CPyL604;
CPyL265: ;
    CPy_Unreachable();
CPyL266: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL284;
CPyL267: ;
    cpy_r_r266 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18 = cpy_r_r266;
    cpy_r_r267 = 1;
    if (unlikely(!cpy_r_r267)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL605;
    }
    cpy_r_r268 = (PyObject **)&cpy_r_r11;
    cpy_r_r269 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17;
    if (unlikely(cpy_r_r269 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__17", -1, CPyStatic_globals);
        goto CPyL605;
    }
    CPy_INCREF(cpy_r_r269);
CPyL269: ;
    cpy_r_r270 = CPy_YieldFromErrorHandle(cpy_r_r269, cpy_r_r268);
    CPy_DecRef(cpy_r_r269);
    if (unlikely(cpy_r_r270 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL605;
    }
    if (cpy_r_r270) goto CPyL276;
    if (cpy_r_r11 != NULL) goto CPyL274;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r271 = 0;
    if (unlikely(!cpy_r_r271)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL281;
    } else
        goto CPyL606;
CPyL273: ;
    CPy_Unreachable();
CPyL274: ;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r262 = cpy_r_r11;
    cpy_r_r272 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18;
    if (unlikely(cpy_r_r272.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__18", -1, CPyStatic_globals);
        goto CPyL607;
    }
    CPy_INCREF(cpy_r_r272.f0);
    CPy_INCREF(cpy_r_r272.f1);
    CPy_INCREF(cpy_r_r272.f2);
CPyL275: ;
    CPy_RestoreExcInfo(cpy_r_r272);
    CPy_DecRef(cpy_r_r272.f0);
    CPy_DecRef(cpy_r_r272.f1);
    CPy_DecRef(cpy_r_r272.f2);
    goto CPyL261;
CPyL276: ;
    if (cpy_r_r11 != NULL) goto CPyL279;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r273 = 0;
    if (unlikely(!cpy_r_r273)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL281;
    } else
        goto CPyL608;
CPyL278: ;
    CPy_Unreachable();
CPyL279: ;
    cpy_r_r261 = cpy_r_r11;
    CPy_DecRef(cpy_r_r261);
    cpy_r_r274 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18;
    if (unlikely(cpy_r_r274.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__18", -1, CPyStatic_globals);
        goto CPyL281;
    }
    CPy_INCREF(cpy_r_r274.f0);
    CPy_INCREF(cpy_r_r274.f1);
    CPy_INCREF(cpy_r_r274.f2);
CPyL280: ;
    CPy_RestoreExcInfo(cpy_r_r274);
    CPy_DecRef(cpy_r_r274.f0);
    CPy_DecRef(cpy_r_r274.f1);
    CPy_DecRef(cpy_r_r274.f2);
    goto CPyL289;
CPyL281: ;
    cpy_r_r275 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18;
    if (unlikely(cpy_r_r275.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__18", -1, CPyStatic_globals);
        goto CPyL292;
    }
    CPy_INCREF(cpy_r_r275.f0);
    CPy_INCREF(cpy_r_r275.f1);
    CPy_INCREF(cpy_r_r275.f2);
CPyL282: ;
    CPy_RestoreExcInfo(cpy_r_r275);
    CPy_DecRef(cpy_r_r275.f0);
    CPy_DecRef(cpy_r_r275.f1);
    CPy_DecRef(cpy_r_r275.f2);
    cpy_r_r276 = CPy_KeepPropagating();
    if (!cpy_r_r276) {
        goto CPyL292;
    } else
        goto CPyL609;
CPyL283: ;
    CPy_Unreachable();
CPyL284: ;
    cpy_r_r277 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17;
    if (unlikely(cpy_r_r277 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__17", -1, CPyStatic_globals);
        goto CPyL610;
    }
    CPy_INCREF(cpy_r_r277);
CPyL285: ;
    cpy_r_r278 = CPyIter_Send(cpy_r_r277, cpy_r_arg);
    CPy_DECREF(cpy_r_r277);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r278 == NULL) goto CPyL611;
    cpy_r_r262 = cpy_r_r278;
    goto CPyL261;
CPyL287: ;
    cpy_r_r279 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r279 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 154, CPyStatic_globals);
        goto CPyL292;
    }
    cpy_r_r261 = cpy_r_r279;
    CPy_DECREF(cpy_r_r261);
CPyL289: ;
    if (cpy_r_r13.f0 == NULL) goto CPyL612;
    CPy_Reraise();
    if (!0) {
        goto CPyL292;
    } else
        goto CPyL613;
CPyL291: ;
    CPy_Unreachable();
CPyL292: ;
    if (cpy_r_r13.f0 == NULL) goto CPyL297;
    if (cpy_r_r13.f0 != NULL) goto CPyL296;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r280 = 0;
    if (unlikely(!cpy_r_r280)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL299;
    } else
        goto CPyL614;
CPyL295: ;
    CPy_Unreachable();
CPyL296: ;
    CPy_RestoreExcInfo(cpy_r_r13);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
CPyL297: ;
    cpy_r_r281 = CPy_KeepPropagating();
    if (!cpy_r_r281) {
        goto CPyL299;
    } else
        goto CPyL615;
CPyL298: ;
    CPy_Unreachable();
CPyL299: ;
    cpy_r_r282 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19 = cpy_r_r282;
    cpy_r_r283 = 1;
    if (unlikely(!cpy_r_r283)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL616;
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__2 = 0;
    cpy_r_r284 = 1;
    if (unlikely(!cpy_r_r284)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL616;
    }
    cpy_r_r285 = CPy_GetExcInfo();
    cpy_r_r286 = cpy_r_r285.f0;
    CPy_INCREF(cpy_r_r286);
    cpy_r_r287 = cpy_r_r285.f1;
    CPy_INCREF(cpy_r_r287);
    cpy_r_r288 = cpy_r_r285.f2;
    CPy_INCREF(cpy_r_r288);
    CPy_DECREF(cpy_r_r285.f0);
    CPy_DECREF(cpy_r_r285.f1);
    CPy_DECREF(cpy_r_r285.f2);
    cpy_r_r289 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0;
    if (unlikely(cpy_r_r289 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__0", -1, CPyStatic_globals);
        goto CPyL617;
    }
    CPy_INCREF(cpy_r_r289);
CPyL302: ;
    cpy_r_r290 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1;
    if (unlikely(cpy_r_r290 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__1", -1, CPyStatic_globals);
        goto CPyL618;
    }
    CPy_INCREF(cpy_r_r290);
CPyL303: ;
    PyObject *cpy_r_r291[4] = {cpy_r_r290, cpy_r_r286, cpy_r_r287, cpy_r_r288};
    cpy_r_r292 = (PyObject **)&cpy_r_r291;
    cpy_r_r293 = _PyObject_Vectorcall(cpy_r_r289, cpy_r_r292, 4, 0);
    CPy_DECREF(cpy_r_r289);
    if (unlikely(cpy_r_r293 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL619;
    }
    CPy_DECREF(cpy_r_r290);
    CPy_DECREF(cpy_r_r286);
    CPy_DECREF(cpy_r_r287);
    CPy_DECREF(cpy_r_r288);
    cpy_r_r294 = CPy_GetCoro(cpy_r_r293);
    CPy_DECREF(cpy_r_r293);
    if (unlikely(cpy_r_r294 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL616;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20 = cpy_r_r294;
    cpy_r_r295 = 1;
    if (unlikely(!cpy_r_r295)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL616;
    }
    cpy_r_r296 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20;
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__20", -1, CPyStatic_globals);
        goto CPyL616;
    }
    CPy_INCREF(cpy_r_r296);
CPyL307: ;
    cpy_r_r297 = CPyIter_Next(cpy_r_r296);
    CPy_DECREF(cpy_r_r296);
    if (cpy_r_r297 == NULL) {
        goto CPyL620;
    } else
        goto CPyL310;
CPyL308: ;
    cpy_r_r298 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r298 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL345;
    }
    cpy_r_r299 = cpy_r_r298;
    goto CPyL339;
CPyL310: ;
    cpy_r_r300 = cpy_r_r297;
CPyL311: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 14;
    cpy_r_r301 = 1;
    if (unlikely(!cpy_r_r301)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL621;
    } else
        goto CPyL622;
CPyL312: ;
    return cpy_r_r300;
CPyL313: ;
    cpy_r_r302 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r303 = cpy_r_type != cpy_r_r302;
    if (!cpy_r_r303) goto CPyL316;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL317;
    } else
        goto CPyL623;
CPyL315: ;
    CPy_Unreachable();
CPyL316: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL334;
CPyL317: ;
    cpy_r_r304 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21 = cpy_r_r304;
    cpy_r_r305 = 1;
    if (unlikely(!cpy_r_r305)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL624;
    }
    cpy_r_r306 = (PyObject **)&cpy_r_r15;
    cpy_r_r307 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20;
    if (unlikely(cpy_r_r307 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__20", -1, CPyStatic_globals);
        goto CPyL624;
    }
    CPy_INCREF(cpy_r_r307);
CPyL319: ;
    cpy_r_r308 = CPy_YieldFromErrorHandle(cpy_r_r307, cpy_r_r306);
    CPy_DecRef(cpy_r_r307);
    if (unlikely(cpy_r_r308 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL624;
    }
    if (cpy_r_r308) goto CPyL326;
    if (cpy_r_r15 != NULL) goto CPyL324;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r309 = 0;
    if (unlikely(!cpy_r_r309)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL331;
    } else
        goto CPyL625;
CPyL323: ;
    CPy_Unreachable();
CPyL324: ;
    CPy_INCREF(cpy_r_r15);
    cpy_r_r300 = cpy_r_r15;
    cpy_r_r310 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21;
    if (unlikely(cpy_r_r310.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__21", -1, CPyStatic_globals);
        goto CPyL626;
    }
    CPy_INCREF(cpy_r_r310.f0);
    CPy_INCREF(cpy_r_r310.f1);
    CPy_INCREF(cpy_r_r310.f2);
CPyL325: ;
    CPy_RestoreExcInfo(cpy_r_r310);
    CPy_DecRef(cpy_r_r310.f0);
    CPy_DecRef(cpy_r_r310.f1);
    CPy_DecRef(cpy_r_r310.f2);
    goto CPyL311;
CPyL326: ;
    if (cpy_r_r15 != NULL) goto CPyL329;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r311 = 0;
    if (unlikely(!cpy_r_r311)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL331;
    } else
        goto CPyL627;
CPyL328: ;
    CPy_Unreachable();
CPyL329: ;
    cpy_r_r299 = cpy_r_r15;
    cpy_r_r312 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21;
    if (unlikely(cpy_r_r312.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__21", -1, CPyStatic_globals);
        goto CPyL628;
    }
    CPy_INCREF(cpy_r_r312.f0);
    CPy_INCREF(cpy_r_r312.f1);
    CPy_INCREF(cpy_r_r312.f2);
CPyL330: ;
    CPy_RestoreExcInfo(cpy_r_r312);
    CPy_DecRef(cpy_r_r312.f0);
    CPy_DecRef(cpy_r_r312.f1);
    CPy_DecRef(cpy_r_r312.f2);
    goto CPyL339;
CPyL331: ;
    cpy_r_r313 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21;
    if (unlikely(cpy_r_r313.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__21", -1, CPyStatic_globals);
        goto CPyL345;
    }
    CPy_INCREF(cpy_r_r313.f0);
    CPy_INCREF(cpy_r_r313.f1);
    CPy_INCREF(cpy_r_r313.f2);
CPyL332: ;
    CPy_RestoreExcInfo(cpy_r_r313);
    CPy_DecRef(cpy_r_r313.f0);
    CPy_DecRef(cpy_r_r313.f1);
    CPy_DecRef(cpy_r_r313.f2);
    cpy_r_r314 = CPy_KeepPropagating();
    if (!cpy_r_r314) {
        goto CPyL345;
    } else
        goto CPyL629;
CPyL333: ;
    CPy_Unreachable();
CPyL334: ;
    cpy_r_r315 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20;
    if (unlikely(cpy_r_r315 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__20", -1, CPyStatic_globals);
        goto CPyL630;
    }
    CPy_INCREF(cpy_r_r315);
CPyL335: ;
    cpy_r_r316 = CPyIter_Send(cpy_r_r315, cpy_r_arg);
    CPy_DECREF(cpy_r_r315);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r316 == NULL) goto CPyL631;
    cpy_r_r300 = cpy_r_r316;
    goto CPyL311;
CPyL337: ;
    cpy_r_r317 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r317 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL345;
    }
    cpy_r_r299 = cpy_r_r317;
CPyL339: ;
    cpy_r_r318 = PyObject_IsTrue(cpy_r_r299);
    CPy_DECREF(cpy_r_r299);
    cpy_r_r319 = cpy_r_r318 >= 0;
    if (unlikely(!cpy_r_r319)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL345;
    }
    cpy_r_r320 = cpy_r_r318;
    if (cpy_r_r320) goto CPyL343;
    CPy_Reraise();
    if (!0) {
        goto CPyL345;
    } else
        goto CPyL632;
CPyL342: ;
    CPy_Unreachable();
CPyL343: ;
    cpy_r_r321 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19;
    if (unlikely(cpy_r_r321.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__19", -1, CPyStatic_globals);
        goto CPyL349;
    }
    CPy_INCREF(cpy_r_r321.f0);
    CPy_INCREF(cpy_r_r321.f1);
    CPy_INCREF(cpy_r_r321.f2);
CPyL344: ;
    CPy_RestoreExcInfo(cpy_r_r321);
    CPy_DECREF(cpy_r_r321.f0);
    CPy_DECREF(cpy_r_r321.f1);
    CPy_DECREF(cpy_r_r321.f2);
    goto CPyL348;
CPyL345: ;
    cpy_r_r322 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19;
    if (unlikely(cpy_r_r322.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__19", -1, CPyStatic_globals);
        goto CPyL349;
    }
    CPy_INCREF(cpy_r_r322.f0);
    CPy_INCREF(cpy_r_r322.f1);
    CPy_INCREF(cpy_r_r322.f2);
CPyL346: ;
    CPy_RestoreExcInfo(cpy_r_r322);
    CPy_DECREF(cpy_r_r322.f0);
    CPy_DECREF(cpy_r_r322.f1);
    CPy_DECREF(cpy_r_r322.f2);
    cpy_r_r323 = CPy_KeepPropagating();
    if (!cpy_r_r323) {
        goto CPyL349;
    } else
        goto CPyL633;
CPyL347: ;
    CPy_Unreachable();
CPyL348: ;
    tuple_T3OOO __tmp4 = { NULL, NULL, NULL };
    cpy_r_r324 = __tmp4;
    cpy_r_r19 = cpy_r_r324;
    goto CPyL350;
CPyL349: ;
    cpy_r_r325 = CPy_CatchError();
    cpy_r_r19 = cpy_r_r325;
CPyL350: ;
    cpy_r_r326 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__2;
    if (unlikely(cpy_r_r326 == 2)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL634;
    }
CPyL351: ;
    if (!cpy_r_r326) goto CPyL635;
CPyL352: ;
    cpy_r_r327 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r328 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0;
    if (unlikely(cpy_r_r328 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__0", -1, CPyStatic_globals);
        goto CPyL634;
    }
    CPy_INCREF(cpy_r_r328);
CPyL353: ;
    cpy_r_r329 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1;
    if (unlikely(cpy_r_r329 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__1", -1, CPyStatic_globals);
        goto CPyL636;
    }
    CPy_INCREF(cpy_r_r329);
CPyL354: ;
    PyObject *cpy_r_r330[4] = {cpy_r_r329, cpy_r_r327, cpy_r_r327, cpy_r_r327};
    cpy_r_r331 = (PyObject **)&cpy_r_r330;
    cpy_r_r332 = _PyObject_Vectorcall(cpy_r_r328, cpy_r_r331, 4, 0);
    CPy_DECREF(cpy_r_r328);
    if (unlikely(cpy_r_r332 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL637;
    }
    CPy_DECREF(cpy_r_r329);
    cpy_r_r333 = CPy_GetCoro(cpy_r_r332);
    CPy_DECREF(cpy_r_r332);
    if (unlikely(cpy_r_r333 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL634;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22 = cpy_r_r333;
    cpy_r_r334 = 1;
    if (unlikely(!cpy_r_r334)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL634;
    }
    cpy_r_r335 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22;
    if (unlikely(cpy_r_r335 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__22", -1, CPyStatic_globals);
        goto CPyL634;
    }
    CPy_INCREF(cpy_r_r335);
CPyL358: ;
    cpy_r_r336 = CPyIter_Next(cpy_r_r335);
    CPy_DECREF(cpy_r_r335);
    if (cpy_r_r336 == NULL) {
        goto CPyL638;
    } else
        goto CPyL361;
CPyL359: ;
    cpy_r_r337 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r337 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL639;
    }
    cpy_r_r338 = cpy_r_r337;
    CPy_DECREF(cpy_r_r338);
    goto CPyL390;
CPyL361: ;
    cpy_r_r339 = cpy_r_r336;
CPyL362: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 16;
    cpy_r_r340 = 1;
    if (unlikely(!cpy_r_r340)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL640;
    } else
        goto CPyL641;
CPyL363: ;
    return cpy_r_r339;
CPyL364: ;
    cpy_r_r341 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r342 = cpy_r_type != cpy_r_r341;
    if (!cpy_r_r342) goto CPyL367;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL368;
    } else
        goto CPyL642;
CPyL366: ;
    CPy_Unreachable();
CPyL367: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL385;
CPyL368: ;
    cpy_r_r343 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23 = cpy_r_r343;
    cpy_r_r344 = 1;
    if (unlikely(!cpy_r_r344)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL643;
    }
    cpy_r_r345 = (PyObject **)&cpy_r_r17;
    cpy_r_r346 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22;
    if (unlikely(cpy_r_r346 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__22", -1, CPyStatic_globals);
        goto CPyL643;
    }
    CPy_INCREF(cpy_r_r346);
CPyL370: ;
    cpy_r_r347 = CPy_YieldFromErrorHandle(cpy_r_r346, cpy_r_r345);
    CPy_DecRef(cpy_r_r346);
    if (unlikely(cpy_r_r347 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL643;
    }
    if (cpy_r_r347) goto CPyL377;
    if (cpy_r_r17 == NULL) {
        goto CPyL644;
    } else
        goto CPyL375;
CPyL373: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r348 = 0;
    if (unlikely(!cpy_r_r348)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL382;
    } else
        goto CPyL645;
CPyL374: ;
    CPy_Unreachable();
CPyL375: ;
    CPy_INCREF(cpy_r_r17);
    cpy_r_r339 = cpy_r_r17;
    cpy_r_r349 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23;
    if (unlikely(cpy_r_r349.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__23", -1, CPyStatic_globals);
        goto CPyL646;
    }
    CPy_INCREF(cpy_r_r349.f0);
    CPy_INCREF(cpy_r_r349.f1);
    CPy_INCREF(cpy_r_r349.f2);
CPyL376: ;
    CPy_RestoreExcInfo(cpy_r_r349);
    CPy_DecRef(cpy_r_r349.f0);
    CPy_DecRef(cpy_r_r349.f1);
    CPy_DecRef(cpy_r_r349.f2);
    goto CPyL362;
CPyL377: ;
    if (cpy_r_r17 == NULL) {
        goto CPyL647;
    } else
        goto CPyL380;
CPyL378: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r350 = 0;
    if (unlikely(!cpy_r_r350)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL382;
    } else
        goto CPyL648;
CPyL379: ;
    CPy_Unreachable();
CPyL380: ;
    cpy_r_r338 = cpy_r_r17;
    CPy_DecRef(cpy_r_r338);
    cpy_r_r351 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23;
    if (unlikely(cpy_r_r351.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__23", -1, CPyStatic_globals);
        goto CPyL649;
    }
    CPy_INCREF(cpy_r_r351.f0);
    CPy_INCREF(cpy_r_r351.f1);
    CPy_INCREF(cpy_r_r351.f2);
CPyL381: ;
    CPy_RestoreExcInfo(cpy_r_r351);
    CPy_DecRef(cpy_r_r351.f0);
    CPy_DecRef(cpy_r_r351.f1);
    CPy_DecRef(cpy_r_r351.f2);
    goto CPyL390;
CPyL382: ;
    cpy_r_r352 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23;
    if (unlikely(cpy_r_r352.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__23' of 'coroutine__get_coroutine_fn_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r352.f0);
        CPy_INCREF(cpy_r_r352.f1);
        CPy_INCREF(cpy_r_r352.f2);
    }
    CPy_DecRef(cpy_r_r22);
    if (unlikely(cpy_r_r352.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL393;
    }
CPyL383: ;
    CPy_RestoreExcInfo(cpy_r_r352);
    CPy_DecRef(cpy_r_r352.f0);
    CPy_DecRef(cpy_r_r352.f1);
    CPy_DecRef(cpy_r_r352.f2);
    cpy_r_r353 = CPy_KeepPropagating();
    if (!cpy_r_r353) {
        goto CPyL393;
    } else
        goto CPyL650;
CPyL384: ;
    CPy_Unreachable();
CPyL385: ;
    cpy_r_r354 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22;
    if (unlikely(cpy_r_r354 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__22", -1, CPyStatic_globals);
        goto CPyL651;
    }
    CPy_INCREF(cpy_r_r354);
CPyL386: ;
    cpy_r_r355 = CPyIter_Send(cpy_r_r354, cpy_r_arg);
    CPy_DECREF(cpy_r_r354);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r355 == NULL) goto CPyL652;
    cpy_r_r339 = cpy_r_r355;
    goto CPyL362;
CPyL388: ;
    cpy_r_r356 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r356 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 152, CPyStatic_globals);
        goto CPyL639;
    }
    cpy_r_r338 = cpy_r_r356;
    CPy_DECREF(cpy_r_r338);
CPyL390: ;
    if (cpy_r_r19.f0 == NULL) {
        goto CPyL400;
    } else
        goto CPyL653;
CPyL391: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL393;
    } else
        goto CPyL654;
CPyL392: ;
    CPy_Unreachable();
CPyL393: ;
    if (cpy_r_r19.f0 == NULL) goto CPyL398;
    if (cpy_r_r19.f0 != NULL) goto CPyL397;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r357 = 0;
    if (unlikely(!cpy_r_r357)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL488;
    }
    CPy_Unreachable();
CPyL397: ;
    CPy_RestoreExcInfo(cpy_r_r19);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
CPyL398: ;
    cpy_r_r358 = CPy_KeepPropagating();
    if (!cpy_r_r358) goto CPyL488;
    CPy_Unreachable();
CPyL400: ;
    cpy_r_r359 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r359 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 157, CPyStatic_globals);
        goto CPyL655;
    }
    CPy_INCREF(cpy_r_r359);
CPyL401: ;
    cpy_r_r360 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output;
    if (unlikely(cpy_r_r360 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "output", 157, CPyStatic_globals);
        goto CPyL656;
    }
    CPy_INCREF(cpy_r_r360);
CPyL402: ;
    if (likely(PyBytes_Check(cpy_r_r360) || PyByteArray_Check(cpy_r_r360)))
        cpy_r_r361 = cpy_r_r360;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals, "bytes", cpy_r_r360);
        goto CPyL656;
    }
    cpy_r_r362 = CPyDef_decode_output(cpy_r_r359, cpy_r_r361);
    CPy_DECREF(cpy_r_r359);
    CPy_DECREF(cpy_r_r361);
    if (unlikely(cpy_r_r362 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals);
        goto CPyL655;
    }
    cpy_r_r363 = CPy_GetCoro(cpy_r_r362);
    CPy_DECREF(cpy_r_r362);
    if (unlikely(cpy_r_r363 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals);
        goto CPyL655;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24 = cpy_r_r363;
    cpy_r_r364 = 1;
    if (unlikely(!cpy_r_r364)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL655;
    }
    cpy_r_r365 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24;
    if (unlikely(cpy_r_r365 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__24", -1, CPyStatic_globals);
        goto CPyL655;
    }
    CPy_INCREF(cpy_r_r365);
CPyL407: ;
    cpy_r_r366 = CPyIter_Next(cpy_r_r365);
    CPy_DECREF(cpy_r_r365);
    if (cpy_r_r366 == NULL) {
        goto CPyL657;
    } else
        goto CPyL410;
CPyL408: ;
    cpy_r_r367 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r367 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals);
        goto CPyL440;
    }
    cpy_r_r368 = cpy_r_r367;
    goto CPyL439;
CPyL410: ;
    cpy_r_r369 = cpy_r_r366;
CPyL411: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 18;
    cpy_r_r370 = 1;
    if (unlikely(!cpy_r_r370)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals);
        goto CPyL658;
    } else
        goto CPyL659;
CPyL412: ;
    return cpy_r_r369;
CPyL413: ;
    cpy_r_r371 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r372 = cpy_r_type != cpy_r_r371;
    if (!cpy_r_r372) goto CPyL416;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals);
        goto CPyL417;
    } else
        goto CPyL660;
CPyL415: ;
    CPy_Unreachable();
CPyL416: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL434;
CPyL417: ;
    cpy_r_r373 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25 = cpy_r_r373;
    cpy_r_r374 = 1;
    if (unlikely(!cpy_r_r374)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL661;
    }
    cpy_r_r375 = (PyObject **)&cpy_r_r21;
    cpy_r_r376 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24;
    if (unlikely(cpy_r_r376 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__24", -1, CPyStatic_globals);
        goto CPyL661;
    }
    CPy_INCREF(cpy_r_r376);
CPyL419: ;
    cpy_r_r377 = CPy_YieldFromErrorHandle(cpy_r_r376, cpy_r_r375);
    CPy_DecRef(cpy_r_r376);
    if (unlikely(cpy_r_r377 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals);
        goto CPyL661;
    }
    if (cpy_r_r377) goto CPyL426;
    if (cpy_r_r21 != NULL) goto CPyL424;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r378 = 0;
    if (unlikely(!cpy_r_r378)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL431;
    } else
        goto CPyL662;
CPyL423: ;
    CPy_Unreachable();
CPyL424: ;
    CPy_INCREF(cpy_r_r21);
    cpy_r_r369 = cpy_r_r21;
    cpy_r_r379 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25;
    if (unlikely(cpy_r_r379.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__25", -1, CPyStatic_globals);
        goto CPyL663;
    }
    CPy_INCREF(cpy_r_r379.f0);
    CPy_INCREF(cpy_r_r379.f1);
    CPy_INCREF(cpy_r_r379.f2);
CPyL425: ;
    CPy_RestoreExcInfo(cpy_r_r379);
    CPy_DecRef(cpy_r_r379.f0);
    CPy_DecRef(cpy_r_r379.f1);
    CPy_DecRef(cpy_r_r379.f2);
    goto CPyL411;
CPyL426: ;
    if (cpy_r_r21 != NULL) goto CPyL429;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r380 = 0;
    if (unlikely(!cpy_r_r380)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL431;
    } else
        goto CPyL664;
CPyL428: ;
    CPy_Unreachable();
CPyL429: ;
    cpy_r_r368 = cpy_r_r21;
    cpy_r_r381 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25;
    if (unlikely(cpy_r_r381.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__25", -1, CPyStatic_globals);
        goto CPyL665;
    }
    CPy_INCREF(cpy_r_r381.f0);
    CPy_INCREF(cpy_r_r381.f1);
    CPy_INCREF(cpy_r_r381.f2);
CPyL430: ;
    CPy_RestoreExcInfo(cpy_r_r381);
    CPy_DecRef(cpy_r_r381.f0);
    CPy_DecRef(cpy_r_r381.f1);
    CPy_DecRef(cpy_r_r381.f2);
    goto CPyL439;
CPyL431: ;
    cpy_r_r382 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25;
    if (unlikely(cpy_r_r382.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__25", -1, CPyStatic_globals);
        goto CPyL440;
    }
    CPy_INCREF(cpy_r_r382.f0);
    CPy_INCREF(cpy_r_r382.f1);
    CPy_INCREF(cpy_r_r382.f2);
CPyL432: ;
    CPy_RestoreExcInfo(cpy_r_r382);
    CPy_DecRef(cpy_r_r382.f0);
    CPy_DecRef(cpy_r_r382.f1);
    CPy_DecRef(cpy_r_r382.f2);
    cpy_r_r383 = CPy_KeepPropagating();
    if (!cpy_r_r383) {
        goto CPyL440;
    } else
        goto CPyL666;
CPyL433: ;
    CPy_Unreachable();
CPyL434: ;
    cpy_r_r384 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24;
    if (unlikely(cpy_r_r384 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__24", -1, CPyStatic_globals);
        goto CPyL667;
    }
    CPy_INCREF(cpy_r_r384);
CPyL435: ;
    cpy_r_r385 = CPyIter_Send(cpy_r_r384, cpy_r_arg);
    CPy_DECREF(cpy_r_r384);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r385 == NULL) goto CPyL668;
    cpy_r_r369 = cpy_r_r385;
    goto CPyL411;
CPyL437: ;
    cpy_r_r386 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r386 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals);
        goto CPyL440;
    }
    cpy_r_r368 = cpy_r_r386;
CPyL439: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded = cpy_r_r368;
    cpy_r_r387 = 1;
    if (unlikely(!cpy_r_r387)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 157, CPyStatic_globals);
    } else
        goto CPyL459;
CPyL440: ;
    cpy_r_r388 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__26.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__26.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__26.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__26.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__26 = cpy_r_r388;
    cpy_r_r389 = 1;
    if (unlikely(!cpy_r_r389)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL456;
    }
    cpy_r_r390 = CPyStatic_globals;
    cpy_r_r391 = CPyStatics[30]; /* 'InsufficientDataBytes' */
    cpy_r_r392 = CPyDict_GetItem(cpy_r_r390, cpy_r_r391);
    if (unlikely(cpy_r_r392 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 158, CPyStatic_globals);
        goto CPyL456;
    }
    cpy_r_r393 = CPy_ExceptionMatches(cpy_r_r392);
    CPy_DecRef(cpy_r_r392);
    if (!cpy_r_r393) goto CPyL454;
    cpy_r_r394 = CPy_GetExcValue();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_e != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_e);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_e = cpy_r_r394;
    cpy_r_r395 = 1;
    if (unlikely(!cpy_r_r395)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 158, CPyStatic_globals);
        goto CPyL456;
    }
    cpy_r_r396 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_e;
    if (unlikely(cpy_r_r396 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "e", 159, CPyStatic_globals);
        goto CPyL456;
    }
    CPy_INCREF(cpy_r_r396);
CPyL445: ;
    cpy_r_r397 = PyObject_Str(cpy_r_r396);
    CPy_DecRef(cpy_r_r396);
    if (unlikely(cpy_r_r397 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 159, CPyStatic_globals);
        goto CPyL456;
    }
    cpy_r_r398 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r398 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 159, CPyStatic_globals);
        goto CPyL669;
    }
    CPy_INCREF(cpy_r_r398);
CPyL447: ;
    cpy_r_r399 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r399 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 159, CPyStatic_globals);
        goto CPyL670;
    }
    CPy_INCREF(cpy_r_r399);
CPyL448: ;
    cpy_r_r400 = CPyStatics[10]; /* '_address' */
    cpy_r_r401 = CPyObject_GetAttr(cpy_r_r399, cpy_r_r400);
    CPy_DecRef(cpy_r_r399);
    if (unlikely(cpy_r_r401 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 159, CPyStatic_globals);
        goto CPyL670;
    }
    cpy_r_r402 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output;
    if (unlikely(cpy_r_r402 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "output", 159, CPyStatic_globals);
        goto CPyL671;
    }
    CPy_INCREF(cpy_r_r402);
CPyL450: ;
    cpy_r_r403 = CPyStatic_globals;
    cpy_r_r404 = CPyStatics[30]; /* 'InsufficientDataBytes' */
    cpy_r_r405 = CPyDict_GetItem(cpy_r_r403, cpy_r_r404);
    if (unlikely(cpy_r_r405 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 159, CPyStatic_globals);
        goto CPyL672;
    }
    PyObject *cpy_r_r406[4] = {cpy_r_r397, cpy_r_r398, cpy_r_r401, cpy_r_r402};
    cpy_r_r407 = (PyObject **)&cpy_r_r406;
    cpy_r_r408 = _PyObject_Vectorcall(cpy_r_r405, cpy_r_r407, 4, 0);
    CPy_DecRef(cpy_r_r405);
    if (unlikely(cpy_r_r408 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 159, CPyStatic_globals);
        goto CPyL672;
    }
    CPy_DecRef(cpy_r_r397);
    CPy_DecRef(cpy_r_r398);
    CPy_DecRef(cpy_r_r401);
    CPy_DecRef(cpy_r_r402);
    CPy_Raise(cpy_r_r408);
    CPy_DecRef(cpy_r_r408);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 159, CPyStatic_globals);
        goto CPyL456;
    } else
        goto CPyL673;
CPyL453: ;
    CPy_Unreachable();
CPyL454: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL456;
    } else
        goto CPyL674;
CPyL455: ;
    CPy_Unreachable();
CPyL456: ;
    cpy_r_r409 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__26;
    if (unlikely(cpy_r_r409.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__26' of 'coroutine__get_coroutine_fn_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r409.f0);
        CPy_INCREF(cpy_r_r409.f1);
        CPy_INCREF(cpy_r_r409.f2);
    }
    CPy_DecRef(cpy_r_r22);
    if (unlikely(cpy_r_r409.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL488;
    }
CPyL457: ;
    CPy_RestoreExcInfo(cpy_r_r409);
    CPy_DecRef(cpy_r_r409.f0);
    CPy_DecRef(cpy_r_r409.f1);
    CPy_DecRef(cpy_r_r409.f2);
    cpy_r_r410 = CPy_KeepPropagating();
    if (!cpy_r_r410) goto CPyL488;
    CPy_Unreachable();
CPyL459: ;
    cpy_r_r411 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decimals;
    if (unlikely(cpy_r_r411 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "decimals", 161, CPyStatic_globals);
        goto CPyL675;
    }
    CPy_INCREF(cpy_r_r411);
CPyL460: ;
    cpy_r_r412 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r413 = cpy_r_r411 == cpy_r_r412;
    CPy_DECREF(cpy_r_r411);
    if (!cpy_r_r413) goto CPyL463;
    cpy_r_r414 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded;
    if (unlikely(cpy_r_r414 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "decoded", 161, CPyStatic_globals);
        goto CPyL675;
    }
    CPy_INCREF(cpy_r_r414);
CPyL462: ;
    cpy_r_r415 = cpy_r_r414;
    goto CPyL473;
CPyL463: ;
    cpy_r_r416 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded;
    if (unlikely(cpy_r_r416 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "decoded", 161, CPyStatic_globals);
        goto CPyL675;
    }
    CPy_INCREF(cpy_r_r416);
CPyL464: ;
    cpy_r_r417 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decimals;
    if (unlikely(cpy_r_r417 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "decimals", 161, CPyStatic_globals);
        goto CPyL676;
    }
    CPy_INCREF(cpy_r_r417);
CPyL465: ;
    if (likely(PyLong_Check(cpy_r_r417)))
        cpy_r_r418 = CPyTagged_FromObject(cpy_r_r417);
    else {
        CPy_TypeError("int", cpy_r_r417); cpy_r_r418 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r417);
    if (unlikely(cpy_r_r418 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 161, CPyStatic_globals);
        goto CPyL676;
    }
    cpy_r_r419 = CPyStatic_Decimal;
    if (unlikely(cpy_r_r419 == NULL)) {
        goto CPyL677;
    } else
        goto CPyL469;
CPyL467: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"Decimal\" was not set");
    cpy_r_r420 = 0;
    if (unlikely(!cpy_r_r420)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 161, CPyStatic_globals);
        goto CPyL488;
    }
    CPy_Unreachable();
CPyL469: ;
    cpy_r_r421 = CPyTagged_StealAsObject(cpy_r_r418);
    PyObject *cpy_r_r422[1] = {cpy_r_r421};
    cpy_r_r423 = (PyObject **)&cpy_r_r422;
    cpy_r_r424 = _PyObject_Vectorcall(cpy_r_r419, cpy_r_r423, 1, 0);
    if (unlikely(cpy_r_r424 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 161, CPyStatic_globals);
        goto CPyL678;
    }
    CPy_DECREF(cpy_r_r421);
    cpy_r_r425 = CPyStatics[192]; /* 10 */
    cpy_r_r426 = CPyNumber_Power(cpy_r_r425, cpy_r_r424);
    CPy_DECREF(cpy_r_r424);
    if (unlikely(cpy_r_r426 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 161, CPyStatic_globals);
        goto CPyL676;
    }
    cpy_r_r427 = PyNumber_TrueDivide(cpy_r_r416, cpy_r_r426);
    CPy_DECREF(cpy_r_r416);
    CPy_DECREF(cpy_r_r426);
    if (unlikely(cpy_r_r427 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 161, CPyStatic_globals);
        goto CPyL675;
    }
    cpy_r_r415 = cpy_r_r427;
CPyL473: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = -2;
    cpy_r_r428 = 1;
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!cpy_r_r428)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 161, CPyStatic_globals);
        goto CPyL679;
    }
    CPyGen_SetStopIterationValue(cpy_r_r415);
    CPy_DECREF(cpy_r_r415);
    if (!0) goto CPyL488;
    CPy_Unreachable();
CPyL476: ;
    cpy_r_r429 = cpy_r_r23 == 0;
    if (cpy_r_r429) goto CPyL680;
    cpy_r_r430 = cpy_r_r23 == 2;
    if (cpy_r_r430) {
        goto CPyL681;
    } else
        goto CPyL682;
CPyL478: ;
    cpy_r_r431 = cpy_r_r23 == 4;
    if (cpy_r_r431) {
        goto CPyL683;
    } else
        goto CPyL684;
CPyL479: ;
    cpy_r_r432 = cpy_r_r23 == 6;
    if (cpy_r_r432) {
        goto CPyL685;
    } else
        goto CPyL686;
CPyL480: ;
    cpy_r_r433 = cpy_r_r23 == 8;
    if (cpy_r_r433) {
        goto CPyL687;
    } else
        goto CPyL688;
CPyL481: ;
    cpy_r_r434 = cpy_r_r23 == 10;
    if (cpy_r_r434) {
        goto CPyL689;
    } else
        goto CPyL690;
CPyL482: ;
    cpy_r_r435 = cpy_r_r23 == 12;
    if (cpy_r_r435) {
        goto CPyL691;
    } else
        goto CPyL692;
CPyL483: ;
    cpy_r_r436 = cpy_r_r23 == 14;
    if (cpy_r_r436) {
        goto CPyL693;
    } else
        goto CPyL694;
CPyL484: ;
    cpy_r_r437 = cpy_r_r23 == 16;
    if (cpy_r_r437) {
        goto CPyL695;
    } else
        goto CPyL696;
CPyL485: ;
    cpy_r_r438 = cpy_r_r23 == 18;
    CPyTagged_DECREF(cpy_r_r23);
    if (cpy_r_r438) {
        goto CPyL413;
    } else
        goto CPyL697;
CPyL486: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r439 = 0;
    if (unlikely(!cpy_r_r439)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL488;
    }
    CPy_Unreachable();
CPyL488: ;
    cpy_r_r440 = NULL;
    return cpy_r_r440;
CPyL489: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    CPy_XDecRef(cpy_r_r21);
    goto CPyL488;
CPyL490: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL488;
CPyL491: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    goto CPyL488;
CPyL492: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL4;
CPyL493: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    goto CPyL488;
CPyL494: ;
    CPy_DECREF(cpy_r_r27);
    goto CPyL14;
CPyL495: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL10;
CPyL496: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    goto CPyL15;
CPyL497: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r44);
    goto CPyL488;
CPyL498: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r47);
    goto CPyL488;
CPyL499: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r46);
    goto CPyL488;
CPyL500: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r55);
    goto CPyL488;
CPyL501: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL30;
CPyL502: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    goto CPyL488;
CPyL503: ;
    CPy_DecRef(cpy_r_r64);
    goto CPyL39;
CPyL504: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL34;
CPyL505: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL37;
CPyL506: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL53;
CPyL507: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL44;
CPyL508: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL45;
CPyL509: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r64);
    goto CPyL53;
CPyL510: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL49;
CPyL511: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL50;
CPyL512: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL53;
CPyL513: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_arg);
    goto CPyL488;
CPyL514: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL59;
CPyL515: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL299;
CPyL516: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r82);
    goto CPyL299;
CPyL517: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r82);
    CPyTagged_DecRef(cpy_r_r83);
    goto CPyL299;
CPyL518: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r82);
    CPyTagged_DecRef(cpy_r_r83);
    CPy_DecRef(cpy_r_r84);
    goto CPyL299;
CPyL519: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r82);
    CPyTagged_DecRef(cpy_r_r83);
    CPy_DecRef(cpy_r_r84);
    CPy_DecRef(cpy_r_r85);
    goto CPyL299;
CPyL520: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r82);
    CPyTagged_DecRef(cpy_r_r83);
    CPy_DecRef(cpy_r_r84);
    CPy_DecRef(cpy_r_r85);
    CPy_DecRef(cpy_r_r88);
    goto CPyL299;
CPyL521: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r88);
    CPy_DecRef(cpy_r_r89);
    goto CPyL299;
CPyL522: ;
    CPy_DECREF(cpy_r_r95);
    goto CPyL68;
CPyL523: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r88);
    goto CPyL299;
CPyL524: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r88);
    CPy_DecRef(cpy_r_r96);
    goto CPyL299;
CPyL525: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL75;
CPyL526: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL299;
CPyL527: ;
    CPy_DecRef(cpy_r_r105);
    goto CPyL84;
CPyL528: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL79;
CPyL529: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL82;
CPyL530: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL98;
CPyL531: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL89;
CPyL532: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL90;
CPyL533: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r105);
    goto CPyL98;
CPyL534: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL94;
CPyL535: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL95;
CPyL536: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r104);
    goto CPyL98;
CPyL537: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL100;
CPyL538: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_arg);
    goto CPyL299;
CPyL539: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL104;
CPyL540: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL108;
CPyL541: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL109;
CPyL542: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r127);
    goto CPyL299;
CPyL543: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r129);
    CPy_DecRef(cpy_r_r130);
    goto CPyL299;
CPyL544: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r129);
    goto CPyL299;
CPyL545: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r138);
    goto CPyL299;
CPyL546: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL123;
CPyL547: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL299;
CPyL548: ;
    CPy_DecRef(cpy_r_r147);
    goto CPyL132;
CPyL549: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL127;
CPyL550: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL130;
CPyL551: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL146;
CPyL552: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL137;
CPyL553: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL138;
CPyL554: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r147);
    goto CPyL146;
CPyL555: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL142;
CPyL556: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL143;
CPyL557: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL146;
CPyL558: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL148;
CPyL559: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_arg);
    goto CPyL299;
CPyL560: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL152;
CPyL561: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL198;
CPyL562: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r167);
    goto CPyL198;
CPyL563: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r167);
    CPy_DecRef(cpy_r_r171);
    goto CPyL198;
CPyL564: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r167);
    CPy_DecRef(cpy_r_r174);
    goto CPyL198;
CPyL565: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r167);
    CPy_DecRef(cpy_r_r174);
    CPy_DecRef(cpy_r_r175);
    goto CPyL198;
CPyL566: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL166;
CPyL567: ;
    CPy_DecRef(cpy_r_r186);
    goto CPyL175;
CPyL568: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL170;
CPyL569: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL173;
CPyL570: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL189;
CPyL571: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL181;
CPyL572: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r186);
    goto CPyL189;
CPyL573: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL186;
CPyL574: ;
    CPy_DecRef(cpy_r_r185);
    goto CPyL189;
CPyL575: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL191;
CPyL576: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_arg);
    goto CPyL198;
CPyL577: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL195;
CPyL578: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL247;
CPyL579: ;
    CPy_XDecRef(cpy_r_r9);
    goto CPyL244;
CPyL580: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    goto CPyL244;
CPyL581: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    CPy_DecRef(cpy_r_r212);
    goto CPyL244;
CPyL582: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    CPy_DecRef(cpy_r_r213);
    goto CPyL244;
CPyL583: ;
    CPy_XDecRef(cpy_r_r9);
    goto CPyL207;
CPyL584: ;
    CPy_DecRef(cpy_r_r223);
    goto CPyL216;
CPyL585: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL211;
CPyL586: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL214;
CPyL587: ;
    CPy_XDecRef(cpy_r_r9);
    goto CPyL230;
CPyL588: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL222;
CPyL589: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r223);
    goto CPyL230;
CPyL590: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL227;
CPyL591: ;
    CPy_DecRef(cpy_r_r222);
    goto CPyL230;
CPyL592: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL232;
CPyL593: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_arg);
    goto CPyL244;
CPyL594: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL236;
CPyL595: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL241;
CPyL596: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL246;
CPyL597: ;
    CPy_XDecRef(cpy_r_r11);
    goto CPyL292;
CPyL598: ;
    CPy_XDECREF(cpy_r_r11);
    goto CPyL289;
CPyL599: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r251);
    goto CPyL292;
CPyL600: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r252);
    goto CPyL292;
CPyL601: ;
    CPy_XDECREF(cpy_r_r11);
    goto CPyL258;
CPyL602: ;
    CPy_DecRef(cpy_r_r262);
    goto CPyL267;
CPyL603: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL262;
CPyL604: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL265;
CPyL605: ;
    CPy_XDecRef(cpy_r_r11);
    goto CPyL281;
CPyL606: ;
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL273;
CPyL607: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r262);
    goto CPyL281;
CPyL608: ;
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL278;
CPyL609: ;
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL283;
CPyL610: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_arg);
    goto CPyL292;
CPyL611: ;
    CPy_XDECREF(cpy_r_r11);
    goto CPyL287;
CPyL612: ;
    CPy_XDECREF(cpy_r_r15);
    goto CPyL348;
CPyL613: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL291;
CPyL614: ;
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL295;
CPyL615: ;
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL298;
CPyL616: ;
    CPy_XDecRef(cpy_r_r15);
    goto CPyL345;
CPyL617: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r287);
    CPy_DecRef(cpy_r_r288);
    goto CPyL345;
CPyL618: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r287);
    CPy_DecRef(cpy_r_r288);
    CPy_DecRef(cpy_r_r289);
    goto CPyL345;
CPyL619: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r287);
    CPy_DecRef(cpy_r_r288);
    CPy_DecRef(cpy_r_r290);
    goto CPyL345;
CPyL620: ;
    CPy_XDECREF(cpy_r_r15);
    goto CPyL308;
CPyL621: ;
    CPy_DecRef(cpy_r_r300);
    goto CPyL317;
CPyL622: ;
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL312;
CPyL623: ;
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL315;
CPyL624: ;
    CPy_XDecRef(cpy_r_r15);
    goto CPyL331;
CPyL625: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL323;
CPyL626: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r300);
    goto CPyL331;
CPyL627: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL328;
CPyL628: ;
    CPy_DecRef(cpy_r_r299);
    goto CPyL331;
CPyL629: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL333;
CPyL630: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_arg);
    goto CPyL345;
CPyL631: ;
    CPy_XDECREF(cpy_r_r15);
    goto CPyL337;
CPyL632: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL342;
CPyL633: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL347;
CPyL634: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL393;
CPyL635: ;
    CPy_XDECREF(cpy_r_r17);
    goto CPyL390;
CPyL636: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r328);
    goto CPyL393;
CPyL637: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r329);
    goto CPyL393;
CPyL638: ;
    CPy_XDECREF(cpy_r_r17);
    goto CPyL359;
CPyL639: ;
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL393;
CPyL640: ;
    CPy_DecRef(cpy_r_r339);
    goto CPyL368;
CPyL641: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL363;
CPyL642: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL366;
CPyL643: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    goto CPyL382;
CPyL644: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL373;
CPyL645: ;
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    CPy_DecRef(cpy_r_r22);
    goto CPyL374;
CPyL646: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r339);
    goto CPyL382;
CPyL647: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL378;
CPyL648: ;
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    CPy_DecRef(cpy_r_r22);
    goto CPyL379;
CPyL649: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL382;
CPyL650: ;
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    goto CPyL384;
CPyL651: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_arg);
    goto CPyL393;
CPyL652: ;
    CPy_XDECREF(cpy_r_r17);
    goto CPyL388;
CPyL653: ;
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL391;
CPyL654: ;
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    goto CPyL392;
CPyL655: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL440;
CPyL656: ;
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r359);
    goto CPyL440;
CPyL657: ;
    CPy_XDECREF(cpy_r_r21);
    goto CPyL408;
CPyL658: ;
    CPy_DecRef(cpy_r_r369);
    goto CPyL417;
CPyL659: ;
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL412;
CPyL660: ;
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL415;
CPyL661: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL431;
CPyL662: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL423;
CPyL663: ;
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r369);
    goto CPyL431;
CPyL664: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL428;
CPyL665: ;
    CPy_DecRef(cpy_r_r368);
    goto CPyL431;
CPyL666: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL433;
CPyL667: ;
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_arg);
    goto CPyL440;
CPyL668: ;
    CPy_XDECREF(cpy_r_r21);
    goto CPyL437;
CPyL669: ;
    CPy_DecRef(cpy_r_r397);
    goto CPyL456;
CPyL670: ;
    CPy_DecRef(cpy_r_r397);
    CPy_DecRef(cpy_r_r398);
    goto CPyL456;
CPyL671: ;
    CPy_DecRef(cpy_r_r397);
    CPy_DecRef(cpy_r_r398);
    CPy_DecRef(cpy_r_r401);
    goto CPyL456;
CPyL672: ;
    CPy_DecRef(cpy_r_r397);
    CPy_DecRef(cpy_r_r398);
    CPy_DecRef(cpy_r_r401);
    CPy_DecRef(cpy_r_r402);
    goto CPyL456;
CPyL673: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL453;
CPyL674: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL455;
CPyL675: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL488;
CPyL676: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r416);
    goto CPyL488;
CPyL677: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r416);
    CPyTagged_DecRef(cpy_r_r418);
    goto CPyL467;
CPyL678: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r416);
    CPy_DecRef(cpy_r_r421);
    goto CPyL488;
CPyL679: ;
    CPy_DecRef(cpy_r_r415);
    goto CPyL488;
CPyL680: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL3;
CPyL681: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL35;
CPyL682: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL478;
CPyL683: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL80;
CPyL684: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL479;
CPyL685: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL128;
CPyL686: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r24);
    goto CPyL480;
CPyL687: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL171;
CPyL688: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL481;
CPyL689: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL212;
CPyL690: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL482;
CPyL691: ;
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL263;
CPyL692: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    goto CPyL483;
CPyL693: ;
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL313;
CPyL694: ;
    CPy_XDECREF(cpy_r_r15);
    goto CPyL484;
CPyL695: ;
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL364;
CPyL696: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    goto CPyL485;
CPyL697: ;
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL486;
}

PyObject *CPyPy_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_coroutine__get_coroutine_fn_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__get_coroutine_fn_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.coroutine__get_coroutine_fn_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_coroutine__get_coroutine_fn_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__get_coroutine_fn_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.coroutine__get_coroutine_fn_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_coroutine__get_coroutine_fn_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__get_coroutine_fn_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.coroutine__get_coroutine_fn_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
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
    cpy_r_r1 = CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
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

PyObject *CPyPy_coroutine__get_coroutine_fn_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__get_coroutine_fn_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.coroutine__get_coroutine_fn_gen", obj___mypyc_self__); 
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
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_gen___close(PyObject *cpy_r___mypyc_self__) {
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
    cpy_r_r1 = CPyStatics[31]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_coroutine__get_coroutine_fn_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[32]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp5 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp5);
    PyObject *__tmp6 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp6);
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

PyObject *CPyPy_coroutine__get_coroutine_fn_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__get_coroutine_fn_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.coroutine__get_coroutine_fn_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_coroutine__get_coroutine_fn_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__get_coroutine_fn_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.coroutine__get_coroutine_fn_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__get_coroutine_fn_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    cpy_r_r0 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_obj", "__mypyc_env__", 143, CPyStatic_globals);
        goto CPyL18;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    if (cpy_r_block_identifier != NULL) goto CPyL19;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_block_identifier = cpy_r_r1;
CPyL3: ;
    if (cpy_r_decimals != NULL) goto CPyL20;
    cpy_r_r2 = Py_None;
    CPy_INCREF(cpy_r_r2);
    cpy_r_decimals = cpy_r_r2;
CPyL5: ;
    if (cpy_r_override != NULL) goto CPyL21;
    cpy_r_r3 = Py_None;
    CPy_INCREF(cpy_r_r3);
    cpy_r_override = cpy_r_r3;
CPyL7: ;
    cpy_r_r4 = CPyDef_coroutine__get_coroutine_fn_env();
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL22;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_INCREF(cpy_r_self);
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_self != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_self);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_self = cpy_r_self;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_INCREF(cpy_r_args);
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_args != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_args);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_args = cpy_r_args;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL23;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_block_identifier != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_block_identifier);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_block_identifier = cpy_r_block_identifier;
    cpy_r_r8 = 1;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL24;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_decimals != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_decimals);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_decimals = cpy_r_decimals;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL25;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_override != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_override);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_override = cpy_r_override;
    cpy_r_r10 = 1;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r11 = CPyDef_coroutine__get_coroutine_fn_gen();
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_INCREF(cpy_r_r4);
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *)cpy_r_r11)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *)cpy_r_r11)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *)cpy_r_r11)->___mypyc_env__ = cpy_r_r4;
    cpy_r_r12 = 1;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL27;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_next_label__ = 0;
    cpy_r_r13 = 1;
    CPy_DECREF(cpy_r_r4);
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL28;
    }
    return cpy_r_r11;
CPyL18: ;
    cpy_r_r14 = NULL;
    return cpy_r_r14;
CPyL19: ;
    CPy_INCREF(cpy_r_block_identifier);
    goto CPyL3;
CPyL20: ;
    CPy_INCREF(cpy_r_decimals);
    goto CPyL5;
CPyL21: ;
    CPy_INCREF(cpy_r_override);
    goto CPyL7;
CPyL22: ;
    CPy_DecRef(cpy_r_block_identifier);
    CPy_DecRef(cpy_r_decimals);
    CPy_DecRef(cpy_r_override);
    CPy_DecRef(cpy_r_r0);
    goto CPyL18;
CPyL23: ;
    CPy_DecRef(cpy_r_block_identifier);
    CPy_DecRef(cpy_r_decimals);
    CPy_DecRef(cpy_r_override);
    CPy_DecRef(cpy_r_r4);
    goto CPyL18;
CPyL24: ;
    CPy_DecRef(cpy_r_decimals);
    CPy_DecRef(cpy_r_override);
    CPy_DecRef(cpy_r_r4);
    goto CPyL18;
CPyL25: ;
    CPy_DecRef(cpy_r_override);
    CPy_DecRef(cpy_r_r4);
    goto CPyL18;
CPyL26: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL18;
CPyL27: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r11);
    goto CPyL18;
CPyL28: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL18;
}

PyObject *CPyPy_coroutine__get_coroutine_fn_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"self", "block_identifier", "decimals", "override", 0};
    static CPyArg_Parser parser = {"%O|$OOO:__call__", kwlist, 0};
    PyObject *obj_self;
    PyObject *obj_args;
    PyObject *obj_block_identifier = NULL;
    PyObject *obj_decimals = NULL;
    PyObject *obj_override = NULL;
    if (!CPyArg_ParseStackAndKeywords(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_args, NULL, &obj_self, &obj_block_identifier, &obj_decimals, &obj_override)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_self = obj_self;
    PyObject *arg_args = obj_args;
    PyObject *arg_block_identifier;
    if (obj_block_identifier == NULL) {
        arg_block_identifier = NULL;
        goto __LL7;
    }
    arg_block_identifier = obj_block_identifier;
    if (arg_block_identifier != NULL) goto __LL7;
    if (obj_block_identifier == Py_None)
        arg_block_identifier = obj_block_identifier;
    else {
        arg_block_identifier = NULL;
    }
    if (arg_block_identifier != NULL) goto __LL7;
    CPy_TypeError("object or None", obj_block_identifier); 
    goto fail;
__LL7: ;
    PyObject *arg_decimals;
    if (obj_decimals == NULL) {
        arg_decimals = NULL;
        goto __LL8;
    }
    if (PyLong_Check(obj_decimals))
        arg_decimals = obj_decimals;
    else {
        arg_decimals = NULL;
    }
    if (arg_decimals != NULL) goto __LL8;
    if (obj_decimals == Py_None)
        arg_decimals = obj_decimals;
    else {
        arg_decimals = NULL;
    }
    if (arg_decimals != NULL) goto __LL8;
    CPy_TypeError("int or None", obj_decimals); 
    goto fail;
__LL8: ;
    PyObject *arg_override;
    if (obj_override == NULL) {
        arg_override = NULL;
        goto __LL9;
    }
    if (PyDict_Check(obj_override))
        arg_override = obj_override;
    else {
        arg_override = NULL;
    }
    if (arg_override != NULL) goto __LL9;
    if (obj_override == Py_None)
        arg_override = obj_override;
    else {
        arg_override = NULL;
    }
    if (arg_override != NULL) goto __LL9;
    CPy_TypeError("dict or None", obj_override); 
    goto fail;
__LL9: ;
    PyObject *retval = CPyDef_coroutine__get_coroutine_fn_obj_____call__(arg___mypyc_self__, arg_self, arg_args, arg_block_identifier, arg_decimals, arg_override);
    CPy_DECREF(obj_args);
    return retval;
fail: ;
    CPy_DECREF(obj_args);
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__get_coroutine_fn(PyObject *cpy_r_w3, CPyTagged cpy_r_len_inputs) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    CPyTagged cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_coroutine;
    PyObject *cpy_r_r16;
    cpy_r_r0 = CPyDef__get_coroutine_fn_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 137, CPyStatic_globals);
        goto CPyL18;
    }
    CPy_INCREF(cpy_r_w3);
    if (((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_w3 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_w3);
    }
    ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_w3 = cpy_r_w3;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 137, CPyStatic_globals);
        goto CPyL19;
    }
    CPyTagged_INCREF(cpy_r_len_inputs);
    if (((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_len_inputs != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_len_inputs);
    }
    ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_len_inputs = cpy_r_len_inputs;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 137, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r3 = CPyStatic_APPLICATION_MODE;
    if (unlikely(cpy_r_r3 == 2)) {
        goto CPyL20;
    } else
        goto CPyL6;
CPyL4: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"APPLICATION_MODE\" was not set");
    cpy_r_r4 = 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 138, CPyStatic_globals);
        goto CPyL18;
    }
    CPy_Unreachable();
CPyL6: ;
    if (cpy_r_r3) goto CPyL9;
    cpy_r_r5 = ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_len_inputs;
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", "_get_coroutine_fn_env", "len_inputs", 138, CPyStatic_globals);
        goto CPyL19;
    }
    CPyTagged_INCREF(cpy_r_r5);
CPyL8: ;
    cpy_r_r6 = cpy_r_r5 != 0;
    CPyTagged_DECREF(cpy_r_r5);
    if (!cpy_r_r6) goto CPyL13;
CPyL9: ;
    cpy_r_r7 = CPyStatic_encode;
    if (unlikely(cpy_r_r7 == NULL)) {
        goto CPyL21;
    } else
        goto CPyL12;
CPyL10: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"encode\" was not set");
    cpy_r_r8 = 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 139, CPyStatic_globals);
        goto CPyL18;
    }
    CPy_Unreachable();
CPyL12: ;
    CPy_INCREF(cpy_r_r7);
    if (((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data);
    }
    ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data = cpy_r_r7;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 139, CPyStatic_globals);
        goto CPyL19;
    } else
        goto CPyL15;
CPyL13: ;
    cpy_r_r10 = CPyStatic_globals;
    cpy_r_r11 = CPyStatics[33]; /* '_request_data_no_args' */
    cpy_r_r12 = CPyDict_GetItem(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 141, CPyStatic_globals);
        goto CPyL19;
    }
    if (((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data);
    }
    ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data = cpy_r_r12;
    cpy_r_r13 = 1;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 141, CPyStatic_globals);
        goto CPyL19;
    }
CPyL15: ;
    cpy_r_r14 = CPyDef_coroutine__get_coroutine_fn_obj();
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 143, CPyStatic_globals);
        goto CPyL19;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *)cpy_r_r14)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *)cpy_r_r14)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *)cpy_r_r14)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r15 = 1;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 143, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_coroutine = cpy_r_r14;
    return cpy_r_coroutine;
CPyL18: ;
    cpy_r_r16 = NULL;
    return cpy_r_r16;
CPyL19: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL18;
CPyL20: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL4;
CPyL21: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL10;
CPyL22: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL18;
}

PyObject *CPyPy__get_coroutine_fn(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"w3", "len_inputs", 0};
    static CPyArg_Parser parser = {"OO:_get_coroutine_fn", kwlist, 0};
    PyObject *obj_w3;
    PyObject *obj_len_inputs;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_w3, &obj_len_inputs)) {
        return NULL;
    }
    PyObject *arg_w3 = obj_w3;
    CPyTagged arg_len_inputs;
    if (likely(PyLong_Check(obj_len_inputs)))
        arg_len_inputs = CPyTagged_BorrowFromObject(obj_len_inputs);
    else {
        CPy_TypeError("int", obj_len_inputs); goto fail;
    }
    PyObject *retval = CPyDef__get_coroutine_fn(arg_w3, arg_len_inputs);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 137, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__call_no_args(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = CPyStatics[16]; /* 'coroutine' */
    PyObject *cpy_r_r1[1] = {cpy_r_self};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_call_no_args", 168, CPyStatic_globals);
        goto CPyL3;
    }
    cpy_r_r4 = CPyStatics[18]; /* '__await__' */
    PyObject *cpy_r_r5[1] = {cpy_r_r3};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r4, cpy_r_r6, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_call_no_args", 168, CPyStatic_globals);
        goto CPyL4;
    }
    CPy_DECREF(cpy_r_r3);
    return cpy_r_r7;
CPyL3: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
CPyL4: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL3;
}

PyObject *CPyPy__call_no_args(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"self", 0};
    static CPyArg_Parser parser = {"O:_call_no_args", kwlist, 0};
    PyObject *obj_self;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_self)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *retval = CPyDef__call_no_args(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_call_no_args", 166, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_input_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    CPyPtr cpy_r_r11;
    int64_t cpy_r_r12;
    CPyTagged cpy_r_r13;
    CPyTagged cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyTagged cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    CPyTagged cpy_r_r29;
    CPyTagged cpy_r_r30;
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
    CPyPtr cpy_r_r43;
    CPyPtr cpy_r_r44;
    CPyPtr cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    CPyPtr cpy_r_r55;
    CPyPtr cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    char cpy_r_r70;
    tuple_T3OOO cpy_r_r71;
    char cpy_r_r72;
    PyObject **cpy_r_r73;
    PyObject *cpy_r_r74;
    char cpy_r_r75;
    char cpy_r_r76;
    tuple_T3OOO cpy_r_r77;
    char cpy_r_r78;
    tuple_T3OOO cpy_r_r79;
    tuple_T3OOO cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    char cpy_r_r85;
    tuple_T3OOO cpy_r_r86;
    char cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    tuple_T2OO cpy_r_r94;
    PyObject *cpy_r_r95;
    char cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    CPyPtr cpy_r_r108;
    CPyPtr cpy_r_r109;
    CPyPtr cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    char cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    char cpy_r_r119;
    PyObject *cpy_r_r120;
    char cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    char cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject **cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    char cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject **cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    char cpy_r_r148;
    PyObject *cpy_r_r149;
    int32_t cpy_r_r150;
    char cpy_r_r151;
    CPyTagged cpy_r_r152;
    char cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    CPyPtr cpy_r_r165;
    CPyPtr cpy_r_r166;
    CPyPtr cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    char cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    char cpy_r_r180;
    CPyTagged cpy_r_r181;
    char cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    CPyPtr cpy_r_r194;
    CPyPtr cpy_r_r195;
    CPyPtr cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    char cpy_r_r205;
    tuple_T3OOO cpy_r_r206;
    tuple_T3OOO cpy_r_r207;
    char cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    int32_t cpy_r_r213;
    char cpy_r_r214;
    char cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    char cpy_r_r218;
    char cpy_r_r219;
    char cpy_r_r220;
    char cpy_r_r221;
    PyObject *cpy_r_r222;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((dank_mids___brownie_patch___call___encode_input_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_gen", "__mypyc_env__", 171, CPyStatic_globals);
        goto CPyL185;
    }
    CPy_INCREF(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_next_label__", 171, CPyStatic_globals);
        goto CPyL186;
    }
    CPyTagged_INCREF(cpy_r_r3);
    goto CPyL180;
CPyL2: ;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_type != cpy_r_r4;
    if (cpy_r_r5) {
        goto CPyL187;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL184;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r6 = 0;
    cpy_r_r7 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 173, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_INCREF(cpy_r_r7);
CPyL6: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__27 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__27);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__27 = cpy_r_r7;
    cpy_r_r8 = 1;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL186;
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28 = 0;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL186;
    }
CPyL8: ;
    cpy_r_r10 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__27;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__27", 173, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_INCREF(cpy_r_r10);
CPyL9: ;
    cpy_r_r11 = (CPyPtr)&((PyVarObject *)cpy_r_r10)->ob_size;
    cpy_r_r12 = *(int64_t *)cpy_r_r11;
    CPy_DECREF(cpy_r_r10);
    cpy_r_r13 = cpy_r_r12 << 1;
    cpy_r_r14 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28;
    if (unlikely(cpy_r_r14 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__28", 173, CPyStatic_globals);
        goto CPyL186;
    }
CPyL10: ;
    cpy_r_r15 = (Py_ssize_t)cpy_r_r14 < (Py_ssize_t)cpy_r_r13;
    if (!cpy_r_r15) goto CPyL27;
    cpy_r_r16 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__27;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__27", 173, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_INCREF(cpy_r_r16);
CPyL12: ;
    cpy_r_r17 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28;
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__28", 173, CPyStatic_globals);
        goto CPyL188;
    }
CPyL13: ;
    cpy_r_r18 = CPySequenceTuple_GetItem(cpy_r_r16, cpy_r_r17);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 173, CPyStatic_globals);
        goto CPyL186;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg = cpy_r_r18;
    cpy_r_r19 = 1;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 173, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r20 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg;
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "arg", 173, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_INCREF(cpy_r_r20);
CPyL16: ;
    cpy_r_r21 = CPyStatic_Contract;
    if (unlikely(cpy_r_r21 == NULL)) {
        goto CPyL189;
    } else
        goto CPyL19;
CPyL17: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"Contract\" was not set");
    cpy_r_r22 = 0;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 173, CPyStatic_globals);
        goto CPyL184;
    }
    CPy_Unreachable();
CPyL19: ;
    cpy_r_r23 = PyObject_IsInstance(cpy_r_r20, cpy_r_r21);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r24 = cpy_r_r23 >= 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 173, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r25 = cpy_r_r23;
    if (!cpy_r_r25) goto CPyL22;
    if (cpy_r_r25) {
        goto CPyL24;
    } else
        goto CPyL25;
CPyL22: ;
    cpy_r_r26 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "arg", 173, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_INCREF(cpy_r_r26);
CPyL23: ;
    cpy_r_r27 = CPyStatics[34]; /* '__contains__' */
    cpy_r_r28 = PyObject_HasAttr(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (!cpy_r_r28) goto CPyL25;
CPyL24: ;
    cpy_r_r6 = 1;
    goto CPyL27;
CPyL25: ;
    cpy_r_r29 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28;
    if (unlikely(cpy_r_r29 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__28", 173, CPyStatic_globals);
        goto CPyL186;
    }
CPyL26: ;
    cpy_r_r30 = cpy_r_r29 + 2;
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28 = cpy_r_r30;
    cpy_r_r31 = 1;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 173, CPyStatic_globals);
        goto CPyL186;
    } else
        goto CPyL8;
CPyL27: ;
    if (cpy_r_r6) {
        goto CPyL190;
    } else
        goto CPyL40;
CPyL28: ;
    cpy_r_r32 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 175, CPyStatic_globals);
        goto CPyL191;
    }
    CPy_INCREF(cpy_r_r32);
CPyL29: ;
    cpy_r_r33 = CPyStatics[5]; /* 'abi' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r35 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 175, CPyStatic_globals);
        goto CPyL192;
    }
    CPy_INCREF(cpy_r_r35);
CPyL31: ;
    cpy_r_r36 = CPyStatics[6]; /* 'signature' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL192;
    }
    cpy_r_r38 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 175, CPyStatic_globals);
        goto CPyL193;
    }
    CPy_INCREF(cpy_r_r38);
CPyL33: ;
    cpy_r_r39 = CPyStatic_globals;
    cpy_r_r40 = CPyStatics[4]; /* '__encode_input' */
    cpy_r_r41 = CPyDict_GetItem(cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r42 = PyList_New(2);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL195;
    }
    cpy_r_r43 = (CPyPtr)&((PyListObject *)cpy_r_r42)->ob_item;
    cpy_r_r44 = *(CPyPtr *)cpy_r_r43;
    *(PyObject * *)cpy_r_r44 = cpy_r_r34;
    cpy_r_r45 = cpy_r_r44 + 8;
    *(PyObject * *)cpy_r_r45 = cpy_r_r37;
    cpy_r_r46 = CPyList_Extend(cpy_r_r42, cpy_r_r38);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL196;
    } else
        goto CPyL197;
CPyL36: ;
    cpy_r_r47 = PyList_AsTuple(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r48 = PyDict_New();
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL199;
    }
    cpy_r_r49 = PyObject_Call(cpy_r_r41, cpy_r_r47, cpy_r_r48);
    CPy_DECREF(cpy_r_r41);
    CPy_DECREF(cpy_r_r47);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL191;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r49;
    cpy_r_r50 = 1;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL191;
    } else
        goto CPyL169;
CPyL40: ;
    cpy_r_r51 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 178, CPyStatic_globals);
        goto CPyL200;
    }
    CPy_INCREF(cpy_r_r51);
CPyL41: ;
    cpy_r_r52 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 178, CPyStatic_globals);
        goto CPyL201;
    }
    CPy_INCREF(cpy_r_r52);
CPyL42: ;
    cpy_r_r53 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_get_request_data;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "get_request_data", 178, CPyStatic_globals);
        goto CPyL202;
    }
    CPy_INCREF(cpy_r_r53);
CPyL43: ;
    cpy_r_r54 = PyList_New(1);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL203;
    }
    cpy_r_r55 = (CPyPtr)&((PyListObject *)cpy_r_r54)->ob_item;
    cpy_r_r56 = *(CPyPtr *)cpy_r_r55;
    *(PyObject * *)cpy_r_r56 = cpy_r_r51;
    cpy_r_r57 = CPyList_Extend(cpy_r_r54, cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL204;
    } else
        goto CPyL205;
CPyL45: ;
    cpy_r_r58 = PyList_AsTuple(cpy_r_r54);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL206;
    }
    cpy_r_r59 = PyDict_New();
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL207;
    }
    cpy_r_r60 = PyObject_Call(cpy_r_r53, cpy_r_r58, cpy_r_r59);
    CPy_DECREF(cpy_r_r53);
    CPy_DECREF(cpy_r_r58);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r61 = CPy_GetCoro(cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL200;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29 = cpy_r_r61;
    cpy_r_r62 = 1;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r63 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__29", -1, CPyStatic_globals);
        goto CPyL200;
    }
    CPy_INCREF(cpy_r_r63);
CPyL51: ;
    cpy_r_r64 = CPyIter_Next(cpy_r_r63);
    CPy_DECREF(cpy_r_r63);
    if (cpy_r_r64 == NULL) {
        goto CPyL208;
    } else
        goto CPyL54;
CPyL52: ;
    cpy_r_r65 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r66 = cpy_r_r65;
    goto CPyL83;
CPyL54: ;
    cpy_r_r67 = cpy_r_r64;
CPyL55: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__ = 2;
    cpy_r_r68 = 1;
    if (unlikely(!cpy_r_r68)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL209;
    } else
        goto CPyL210;
CPyL56: ;
    return cpy_r_r67;
CPyL57: ;
    cpy_r_r69 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r70 = cpy_r_type != cpy_r_r69;
    if (!cpy_r_r70) goto CPyL60;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL61;
    } else
        goto CPyL211;
CPyL59: ;
    CPy_Unreachable();
CPyL60: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL78;
CPyL61: ;
    cpy_r_r71 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30.f2);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30 = cpy_r_r71;
    cpy_r_r72 = 1;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r73 = (PyObject **)&cpy_r_r1;
    cpy_r_r74 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__29", -1, CPyStatic_globals);
        goto CPyL212;
    }
    CPy_INCREF(cpy_r_r74);
CPyL63: ;
    cpy_r_r75 = CPy_YieldFromErrorHandle(cpy_r_r74, cpy_r_r73);
    CPy_DecRef(cpy_r_r74);
    if (unlikely(cpy_r_r75 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL212;
    }
    if (cpy_r_r75) goto CPyL70;
    if (cpy_r_r1 != NULL) goto CPyL68;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r76 = 0;
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL75;
    } else
        goto CPyL213;
CPyL67: ;
    CPy_Unreachable();
CPyL68: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r67 = cpy_r_r1;
    cpy_r_r77 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r77.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__30", -1, CPyStatic_globals);
        goto CPyL214;
    }
    CPy_INCREF(cpy_r_r77.f0);
    CPy_INCREF(cpy_r_r77.f1);
    CPy_INCREF(cpy_r_r77.f2);
CPyL69: ;
    CPy_RestoreExcInfo(cpy_r_r77);
    CPy_DecRef(cpy_r_r77.f0);
    CPy_DecRef(cpy_r_r77.f1);
    CPy_DecRef(cpy_r_r77.f2);
    goto CPyL55;
CPyL70: ;
    if (cpy_r_r1 != NULL) goto CPyL73;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r78 = 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL75;
    } else
        goto CPyL215;
CPyL72: ;
    CPy_Unreachable();
CPyL73: ;
    cpy_r_r66 = cpy_r_r1;
    cpy_r_r79 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r79.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__30", -1, CPyStatic_globals);
        goto CPyL216;
    }
    CPy_INCREF(cpy_r_r79.f0);
    CPy_INCREF(cpy_r_r79.f1);
    CPy_INCREF(cpy_r_r79.f2);
CPyL74: ;
    CPy_RestoreExcInfo(cpy_r_r79);
    CPy_DecRef(cpy_r_r79.f0);
    CPy_DecRef(cpy_r_r79.f1);
    CPy_DecRef(cpy_r_r79.f2);
    goto CPyL83;
CPyL75: ;
    cpy_r_r80 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r80.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__30", -1, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_INCREF(cpy_r_r80.f0);
    CPy_INCREF(cpy_r_r80.f1);
    CPy_INCREF(cpy_r_r80.f2);
CPyL76: ;
    CPy_RestoreExcInfo(cpy_r_r80);
    CPy_DecRef(cpy_r_r80.f0);
    CPy_DecRef(cpy_r_r80.f1);
    CPy_DecRef(cpy_r_r80.f2);
    cpy_r_r81 = CPy_KeepPropagating();
    if (!cpy_r_r81) {
        goto CPyL84;
    } else
        goto CPyL217;
CPyL77: ;
    CPy_Unreachable();
CPyL78: ;
    cpy_r_r82 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__29", -1, CPyStatic_globals);
        goto CPyL218;
    }
    CPy_INCREF(cpy_r_r82);
CPyL79: ;
    cpy_r_r83 = CPyIter_Send(cpy_r_r82, cpy_r_arg);
    CPy_DECREF(cpy_r_r82);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r83 == NULL) goto CPyL219;
    cpy_r_r67 = cpy_r_r83;
    goto CPyL55;
CPyL81: ;
    cpy_r_r84 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r66 = cpy_r_r84;
CPyL83: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r66;
    cpy_r_r85 = 1;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 178, CPyStatic_globals);
    } else
        goto CPyL169;
CPyL84: ;
    cpy_r_r86 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31.f2);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31 = cpy_r_r86;
    cpy_r_r87 = 1;
    if (unlikely(!cpy_r_r87)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r88 = CPyModule_builtins;
    cpy_r_r89 = CPyStatics[35]; /* 'AttributeError' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 179, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r91 = CPyModule_builtins;
    cpy_r_r92 = CPyStatics[36]; /* 'TypeError' */
    cpy_r_r93 = CPyObject_GetAttr(cpy_r_r91, cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 179, CPyStatic_globals);
        goto CPyL220;
    }
    cpy_r_r94.f0 = cpy_r_r90;
    cpy_r_r94.f1 = cpy_r_r93;
    cpy_r_r95 = PyTuple_New(2);
    if (unlikely(cpy_r_r95 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp10 = cpy_r_r94.f0;
    PyTuple_SET_ITEM(cpy_r_r95, 0, __tmp10);
    PyObject *__tmp11 = cpy_r_r94.f1;
    PyTuple_SET_ITEM(cpy_r_r95, 1, __tmp11);
    cpy_r_r96 = CPy_ExceptionMatches(cpy_r_r95);
    CPy_DecRef(cpy_r_r95);
    if (!cpy_r_r96) goto CPyL100;
    cpy_r_r97 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 181, CPyStatic_globals);
        goto CPyL166;
    }
    CPy_INCREF(cpy_r_r97);
CPyL89: ;
    cpy_r_r98 = CPyStatics[5]; /* 'abi' */
    cpy_r_r99 = CPyObject_GetAttr(cpy_r_r97, cpy_r_r98);
    CPy_DecRef(cpy_r_r97);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r100 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 181, CPyStatic_globals);
        goto CPyL221;
    }
    CPy_INCREF(cpy_r_r100);
CPyL91: ;
    cpy_r_r101 = CPyStatics[6]; /* 'signature' */
    cpy_r_r102 = CPyObject_GetAttr(cpy_r_r100, cpy_r_r101);
    CPy_DecRef(cpy_r_r100);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL221;
    }
    cpy_r_r103 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 181, CPyStatic_globals);
        goto CPyL222;
    }
    CPy_INCREF(cpy_r_r103);
CPyL93: ;
    cpy_r_r104 = CPyStatic_globals;
    cpy_r_r105 = CPyStatics[4]; /* '__encode_input' */
    cpy_r_r106 = CPyDict_GetItem(cpy_r_r104, cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL223;
    }
    cpy_r_r107 = PyList_New(2);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL224;
    }
    cpy_r_r108 = (CPyPtr)&((PyListObject *)cpy_r_r107)->ob_item;
    cpy_r_r109 = *(CPyPtr *)cpy_r_r108;
    *(PyObject * *)cpy_r_r109 = cpy_r_r99;
    cpy_r_r110 = cpy_r_r109 + 8;
    *(PyObject * *)cpy_r_r110 = cpy_r_r102;
    cpy_r_r111 = CPyList_Extend(cpy_r_r107, cpy_r_r103);
    CPy_DecRef(cpy_r_r103);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL225;
    } else
        goto CPyL226;
CPyL96: ;
    cpy_r_r112 = PyList_AsTuple(cpy_r_r107);
    CPy_DecRef(cpy_r_r107);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL227;
    }
    cpy_r_r113 = PyDict_New();
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL228;
    }
    cpy_r_r114 = PyObject_Call(cpy_r_r106, cpy_r_r112, cpy_r_r113);
    CPy_DecRef(cpy_r_r106);
    CPy_DecRef(cpy_r_r112);
    CPy_DecRef(cpy_r_r113);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL166;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r114;
    cpy_r_r115 = 1;
    if (unlikely(!cpy_r_r115)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL166;
    } else
        goto CPyL164;
CPyL100: ;
    cpy_r_r116 = CPyStatic_globals;
    cpy_r_r117 = CPyStatics[37]; /* 'BrokenProcessPool' */
    cpy_r_r118 = CPyDict_GetItem(cpy_r_r116, cpy_r_r117);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 183, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r119 = CPy_ExceptionMatches(cpy_r_r118);
    CPy_DecRef(cpy_r_r118);
    if (!cpy_r_r119) goto CPyL142;
    cpy_r_r120 = CPyStatic_logger;
    if (likely(cpy_r_r120 != NULL)) goto CPyL105;
    PyErr_SetString(PyExc_NameError, "value for final name \"logger\" was not set");
    cpy_r_r121 = 0;
    if (unlikely(!cpy_r_r121)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 184, CPyStatic_globals);
        goto CPyL166;
    } else
        goto CPyL229;
CPyL104: ;
    CPy_Unreachable();
CPyL105: ;
    cpy_r_r122 = CPyStatics[38]; /* 'Oh fuck, you broke the %s while decoding %s with abi %s' */
    cpy_r_r123 = CPyStatic_ENVS;
    if (likely(cpy_r_r123 != NULL)) goto CPyL108;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r124 = 0;
    if (unlikely(!cpy_r_r124)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 184, CPyStatic_globals);
        goto CPyL166;
    } else
        goto CPyL230;
CPyL107: ;
    CPy_Unreachable();
CPyL108: ;
    cpy_r_r125 = CPyStatics[3]; /* 'BROWNIE_ENCODER_PROCESSES' */
    cpy_r_r126 = CPyObject_GetAttr(cpy_r_r123, cpy_r_r125);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 184, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r127 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data;
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "data", 184, CPyStatic_globals);
        goto CPyL231;
    }
    CPy_INCREF(cpy_r_r127);
CPyL110: ;
    cpy_r_r128 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 184, CPyStatic_globals);
        goto CPyL232;
    }
    CPy_INCREF(cpy_r_r128);
CPyL111: ;
    cpy_r_r129 = CPyStatics[5]; /* 'abi' */
    cpy_r_r130 = CPyObject_GetAttr(cpy_r_r128, cpy_r_r129);
    CPy_DecRef(cpy_r_r128);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 184, CPyStatic_globals);
        goto CPyL232;
    }
    cpy_r_r131 = CPyStatics[39]; /* 'critical' */
    PyObject *cpy_r_r132[5] = {cpy_r_r120, cpy_r_r122, cpy_r_r126, cpy_r_r127, cpy_r_r130};
    cpy_r_r133 = (PyObject **)&cpy_r_r132;
    cpy_r_r134 = PyObject_VectorcallMethod(cpy_r_r131, cpy_r_r133, 9223372036854775813ULL, 0);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 184, CPyStatic_globals);
        goto CPyL233;
    } else
        goto CPyL234;
CPyL113: ;
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r127);
    CPy_DecRef(cpy_r_r130);
    cpy_r_r135 = CPyStatic_ENVS;
    if (likely(cpy_r_r135 != NULL)) goto CPyL116;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r136 = 0;
    if (unlikely(!cpy_r_r136)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 186, CPyStatic_globals);
        goto CPyL166;
    } else
        goto CPyL235;
CPyL115: ;
    CPy_Unreachable();
CPyL116: ;
    cpy_r_r137 = CPyStatics[3]; /* 'BROWNIE_ENCODER_PROCESSES' */
    cpy_r_r138 = CPyObject_GetAttr(cpy_r_r135, cpy_r_r137);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 186, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r139 = CPyStatics[40]; /* '_max_workers' */
    cpy_r_r140 = CPyObject_GetAttr(cpy_r_r138, cpy_r_r139);
    CPy_DecRef(cpy_r_r138);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 186, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r141 = CPyStatic_globals;
    cpy_r_r142 = CPyStatics[41]; /* 'AsyncProcessPoolExecutor' */
    cpy_r_r143 = CPyDict_GetItem(cpy_r_r141, cpy_r_r142);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 186, CPyStatic_globals);
        goto CPyL236;
    }
    PyObject *cpy_r_r144[1] = {cpy_r_r140};
    cpy_r_r145 = (PyObject **)&cpy_r_r144;
    cpy_r_r146 = _PyObject_Vectorcall(cpy_r_r143, cpy_r_r145, 1, 0);
    CPy_DecRef(cpy_r_r143);
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 186, CPyStatic_globals);
        goto CPyL236;
    }
    CPy_DecRef(cpy_r_r140);
    cpy_r_r147 = CPyStatic_ENVS;
    if (unlikely(cpy_r_r147 == NULL)) {
        goto CPyL237;
    } else
        goto CPyL123;
CPyL121: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r148 = 0;
    if (unlikely(!cpy_r_r148)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 186, CPyStatic_globals);
        goto CPyL166;
    } else
        goto CPyL238;
CPyL122: ;
    CPy_Unreachable();
CPyL123: ;
    cpy_r_r149 = CPyStatics[3]; /* 'BROWNIE_ENCODER_PROCESSES' */
    cpy_r_r150 = PyObject_SetAttr(cpy_r_r147, cpy_r_r149, cpy_r_r146);
    CPy_DecRef(cpy_r_r146);
    cpy_r_r151 = cpy_r_r150 >= 0;
    if (unlikely(!cpy_r_r151)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 186, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r152 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_len_inputs;
    if (unlikely(cpy_r_r152 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "len_inputs", 187, CPyStatic_globals);
        goto CPyL166;
    }
    CPyTagged_INCREF(cpy_r_r152);
CPyL125: ;
    cpy_r_r153 = cpy_r_r152 != 0;
    CPyTagged_DecRef(cpy_r_r152);
    if (!cpy_r_r153) goto CPyL138;
    cpy_r_r154 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 187, CPyStatic_globals);
        goto CPyL166;
    }
    CPy_INCREF(cpy_r_r154);
CPyL127: ;
    cpy_r_r155 = CPyStatics[5]; /* 'abi' */
    cpy_r_r156 = CPyObject_GetAttr(cpy_r_r154, cpy_r_r155);
    CPy_DecRef(cpy_r_r154);
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r157 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 187, CPyStatic_globals);
        goto CPyL239;
    }
    CPy_INCREF(cpy_r_r157);
CPyL129: ;
    cpy_r_r158 = CPyStatics[6]; /* 'signature' */
    cpy_r_r159 = CPyObject_GetAttr(cpy_r_r157, cpy_r_r158);
    CPy_DecRef(cpy_r_r157);
    if (unlikely(cpy_r_r159 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL239;
    }
    cpy_r_r160 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 187, CPyStatic_globals);
        goto CPyL240;
    }
    CPy_INCREF(cpy_r_r160);
CPyL131: ;
    cpy_r_r161 = CPyStatic_globals;
    cpy_r_r162 = CPyStatics[4]; /* '__encode_input' */
    cpy_r_r163 = CPyDict_GetItem(cpy_r_r161, cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL241;
    }
    cpy_r_r164 = PyList_New(2);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r165 = (CPyPtr)&((PyListObject *)cpy_r_r164)->ob_item;
    cpy_r_r166 = *(CPyPtr *)cpy_r_r165;
    *(PyObject * *)cpy_r_r166 = cpy_r_r156;
    cpy_r_r167 = cpy_r_r166 + 8;
    *(PyObject * *)cpy_r_r167 = cpy_r_r159;
    cpy_r_r168 = CPyList_Extend(cpy_r_r164, cpy_r_r160);
    CPy_DecRef(cpy_r_r160);
    if (unlikely(cpy_r_r168 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL243;
    } else
        goto CPyL244;
CPyL134: ;
    cpy_r_r169 = PyList_AsTuple(cpy_r_r164);
    CPy_DecRef(cpy_r_r164);
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL245;
    }
    cpy_r_r170 = PyDict_New();
    if (unlikely(cpy_r_r170 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL246;
    }
    cpy_r_r171 = PyObject_Call(cpy_r_r163, cpy_r_r169, cpy_r_r170);
    CPy_DecRef(cpy_r_r163);
    CPy_DecRef(cpy_r_r169);
    CPy_DecRef(cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r172 = cpy_r_r171;
    goto CPyL141;
CPyL138: ;
    cpy_r_r173 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 187, CPyStatic_globals);
        goto CPyL166;
    }
    CPy_INCREF(cpy_r_r173);
CPyL139: ;
    cpy_r_r174 = CPyStatics[6]; /* 'signature' */
    cpy_r_r175 = CPyObject_GetAttr(cpy_r_r173, cpy_r_r174);
    CPy_DecRef(cpy_r_r173);
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r172 = cpy_r_r175;
CPyL141: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r172;
    cpy_r_r176 = 1;
    if (unlikely(!cpy_r_r176)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 187, CPyStatic_globals);
        goto CPyL166;
    } else
        goto CPyL164;
CPyL142: ;
    cpy_r_r177 = CPyStatic_globals;
    cpy_r_r178 = CPyStatics[42]; /* 'PicklingError' */
    cpy_r_r179 = CPyDict_GetItem(cpy_r_r177, cpy_r_r178);
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 188, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r180 = CPy_ExceptionMatches(cpy_r_r179);
    CPy_DecRef(cpy_r_r179);
    if (!cpy_r_r180) goto CPyL162;
    cpy_r_r181 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_len_inputs;
    if (unlikely(cpy_r_r181 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "len_inputs", 189, CPyStatic_globals);
        goto CPyL166;
    }
    CPyTagged_INCREF(cpy_r_r181);
CPyL145: ;
    cpy_r_r182 = cpy_r_r181 != 0;
    CPyTagged_DecRef(cpy_r_r181);
    if (!cpy_r_r182) goto CPyL158;
    cpy_r_r183 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r183 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 189, CPyStatic_globals);
        goto CPyL166;
    }
    CPy_INCREF(cpy_r_r183);
CPyL147: ;
    cpy_r_r184 = CPyStatics[5]; /* 'abi' */
    cpy_r_r185 = CPyObject_GetAttr(cpy_r_r183, cpy_r_r184);
    CPy_DecRef(cpy_r_r183);
    if (unlikely(cpy_r_r185 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r186 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 189, CPyStatic_globals);
        goto CPyL247;
    }
    CPy_INCREF(cpy_r_r186);
CPyL149: ;
    cpy_r_r187 = CPyStatics[6]; /* 'signature' */
    cpy_r_r188 = CPyObject_GetAttr(cpy_r_r186, cpy_r_r187);
    CPy_DecRef(cpy_r_r186);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL247;
    }
    cpy_r_r189 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 189, CPyStatic_globals);
        goto CPyL248;
    }
    CPy_INCREF(cpy_r_r189);
CPyL151: ;
    cpy_r_r190 = CPyStatic_globals;
    cpy_r_r191 = CPyStatics[4]; /* '__encode_input' */
    cpy_r_r192 = CPyDict_GetItem(cpy_r_r190, cpy_r_r191);
    if (unlikely(cpy_r_r192 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r193 = PyList_New(2);
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL250;
    }
    cpy_r_r194 = (CPyPtr)&((PyListObject *)cpy_r_r193)->ob_item;
    cpy_r_r195 = *(CPyPtr *)cpy_r_r194;
    *(PyObject * *)cpy_r_r195 = cpy_r_r185;
    cpy_r_r196 = cpy_r_r195 + 8;
    *(PyObject * *)cpy_r_r196 = cpy_r_r188;
    cpy_r_r197 = CPyList_Extend(cpy_r_r193, cpy_r_r189);
    CPy_DecRef(cpy_r_r189);
    if (unlikely(cpy_r_r197 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL251;
    } else
        goto CPyL252;
CPyL154: ;
    cpy_r_r198 = PyList_AsTuple(cpy_r_r193);
    CPy_DecRef(cpy_r_r193);
    if (unlikely(cpy_r_r198 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL253;
    }
    cpy_r_r199 = PyDict_New();
    if (unlikely(cpy_r_r199 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL254;
    }
    cpy_r_r200 = PyObject_Call(cpy_r_r192, cpy_r_r198, cpy_r_r199);
    CPy_DecRef(cpy_r_r192);
    CPy_DecRef(cpy_r_r198);
    CPy_DecRef(cpy_r_r199);
    if (unlikely(cpy_r_r200 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r201 = cpy_r_r200;
    goto CPyL161;
CPyL158: ;
    cpy_r_r202 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r202 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 189, CPyStatic_globals);
        goto CPyL166;
    }
    CPy_INCREF(cpy_r_r202);
CPyL159: ;
    cpy_r_r203 = CPyStatics[6]; /* 'signature' */
    cpy_r_r204 = CPyObject_GetAttr(cpy_r_r202, cpy_r_r203);
    CPy_DecRef(cpy_r_r202);
    if (unlikely(cpy_r_r204 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r201 = cpy_r_r204;
CPyL161: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r201;
    cpy_r_r205 = 1;
    if (unlikely(!cpy_r_r205)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 189, CPyStatic_globals);
        goto CPyL166;
    } else
        goto CPyL164;
CPyL162: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL166;
    } else
        goto CPyL255;
CPyL163: ;
    CPy_Unreachable();
CPyL164: ;
    cpy_r_r206 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31;
    if (unlikely(cpy_r_r206.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__31", -1, CPyStatic_globals);
        goto CPyL191;
    }
    CPy_INCREF(cpy_r_r206.f0);
    CPy_INCREF(cpy_r_r206.f1);
    CPy_INCREF(cpy_r_r206.f2);
CPyL165: ;
    CPy_RestoreExcInfo(cpy_r_r206);
    CPy_DecRef(cpy_r_r206.f0);
    CPy_DecRef(cpy_r_r206.f1);
    CPy_DecRef(cpy_r_r206.f2);
    goto CPyL169;
CPyL166: ;
    cpy_r_r207 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31;
    if (unlikely(cpy_r_r207.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__31' of 'encode_input_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r207.f0);
        CPy_INCREF(cpy_r_r207.f1);
        CPy_INCREF(cpy_r_r207.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r207.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL184;
    }
CPyL167: ;
    CPy_RestoreExcInfo(cpy_r_r207);
    CPy_DecRef(cpy_r_r207.f0);
    CPy_DecRef(cpy_r_r207.f1);
    CPy_DecRef(cpy_r_r207.f2);
    cpy_r_r208 = CPy_KeepPropagating();
    if (!cpy_r_r208) goto CPyL184;
    CPy_Unreachable();
CPyL169: ;
    cpy_r_r209 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data;
    if (unlikely(cpy_r_r209 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "data", 191, CPyStatic_globals);
        goto CPyL191;
    }
    CPy_INCREF(cpy_r_r209);
CPyL170: ;
    cpy_r_r210 = CPyModule_builtins;
    cpy_r_r211 = CPyStatics[43]; /* 'Exception' */
    cpy_r_r212 = CPyObject_GetAttr(cpy_r_r210, cpy_r_r211);
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 191, CPyStatic_globals);
        goto CPyL256;
    }
    cpy_r_r213 = PyObject_IsInstance(cpy_r_r209, cpy_r_r212);
    CPy_DECREF(cpy_r_r209);
    CPy_DECREF(cpy_r_r212);
    cpy_r_r214 = cpy_r_r213 >= 0;
    if (unlikely(!cpy_r_r214)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 191, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r215 = cpy_r_r213;
    if (!cpy_r_r215) goto CPyL176;
    cpy_r_r216 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data;
    if (unlikely(cpy_r_r216 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'data' of 'encode_input_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r216);
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r216 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 192, CPyStatic_globals);
        goto CPyL184;
    }
CPyL174: ;
    CPy_Raise(cpy_r_r216);
    CPy_DECREF(cpy_r_r216);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 192, CPyStatic_globals);
        goto CPyL184;
    }
    CPy_Unreachable();
CPyL176: ;
    cpy_r_r217 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data;
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "data", 193, CPyStatic_globals);
        goto CPyL191;
    }
    CPy_INCREF(cpy_r_r217);
CPyL177: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r218 = 1;
    CPy_DECREF(cpy_r_r2);
    if (unlikely(!cpy_r_r218)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 193, CPyStatic_globals);
        goto CPyL257;
    }
    CPyGen_SetStopIterationValue(cpy_r_r217);
    CPy_DECREF(cpy_r_r217);
    if (!0) goto CPyL184;
    CPy_Unreachable();
CPyL180: ;
    cpy_r_r219 = cpy_r_r3 == 0;
    if (cpy_r_r219) goto CPyL258;
    cpy_r_r220 = cpy_r_r3 == 2;
    CPyTagged_DECREF(cpy_r_r3);
    if (cpy_r_r220) {
        goto CPyL57;
    } else
        goto CPyL259;
CPyL182: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r221 = 0;
    if (unlikely(!cpy_r_r221)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL184;
    }
    CPy_Unreachable();
CPyL184: ;
    cpy_r_r222 = NULL;
    return cpy_r_r222;
CPyL185: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL184;
CPyL186: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL184;
CPyL187: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL3;
CPyL188: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r16);
    goto CPyL184;
CPyL189: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r20);
    goto CPyL17;
CPyL190: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL28;
CPyL191: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL184;
CPyL192: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r34);
    goto CPyL184;
CPyL193: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r37);
    goto CPyL184;
CPyL194: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r38);
    goto CPyL184;
CPyL195: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r38);
    CPy_DecRef(cpy_r_r41);
    goto CPyL184;
CPyL196: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r42);
    goto CPyL184;
CPyL197: ;
    CPy_DECREF(cpy_r_r46);
    goto CPyL36;
CPyL198: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r41);
    goto CPyL184;
CPyL199: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r47);
    goto CPyL184;
CPyL200: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL84;
CPyL201: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r51);
    goto CPyL84;
CPyL202: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r52);
    goto CPyL84;
CPyL203: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    goto CPyL84;
CPyL204: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r53);
    CPy_DecRef(cpy_r_r54);
    goto CPyL84;
CPyL205: ;
    CPy_DECREF(cpy_r_r57);
    goto CPyL45;
CPyL206: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r53);
    goto CPyL84;
CPyL207: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r53);
    CPy_DecRef(cpy_r_r58);
    goto CPyL84;
CPyL208: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL52;
CPyL209: ;
    CPy_DecRef(cpy_r_r67);
    goto CPyL61;
CPyL210: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL56;
CPyL211: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL59;
CPyL212: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL75;
CPyL213: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL67;
CPyL214: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r67);
    goto CPyL75;
CPyL215: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL72;
CPyL216: ;
    CPy_DecRef(cpy_r_r66);
    goto CPyL75;
CPyL217: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL77;
CPyL218: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_arg);
    goto CPyL84;
CPyL219: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL81;
CPyL220: ;
    CPy_DecRef(cpy_r_r90);
    goto CPyL166;
CPyL221: ;
    CPy_DecRef(cpy_r_r99);
    goto CPyL166;
CPyL222: ;
    CPy_DecRef(cpy_r_r99);
    CPy_DecRef(cpy_r_r102);
    goto CPyL166;
CPyL223: ;
    CPy_DecRef(cpy_r_r99);
    CPy_DecRef(cpy_r_r102);
    CPy_DecRef(cpy_r_r103);
    goto CPyL166;
CPyL224: ;
    CPy_DecRef(cpy_r_r99);
    CPy_DecRef(cpy_r_r102);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r106);
    goto CPyL166;
CPyL225: ;
    CPy_DecRef(cpy_r_r106);
    CPy_DecRef(cpy_r_r107);
    goto CPyL166;
CPyL226: ;
    CPy_DecRef(cpy_r_r111);
    goto CPyL96;
CPyL227: ;
    CPy_DecRef(cpy_r_r106);
    goto CPyL166;
CPyL228: ;
    CPy_DecRef(cpy_r_r106);
    CPy_DecRef(cpy_r_r112);
    goto CPyL166;
CPyL229: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL104;
CPyL230: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL107;
CPyL231: ;
    CPy_DecRef(cpy_r_r126);
    goto CPyL166;
CPyL232: ;
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r127);
    goto CPyL166;
CPyL233: ;
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r127);
    CPy_DecRef(cpy_r_r130);
    goto CPyL166;
CPyL234: ;
    CPy_DecRef(cpy_r_r134);
    goto CPyL113;
CPyL235: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL115;
CPyL236: ;
    CPy_DecRef(cpy_r_r140);
    goto CPyL166;
CPyL237: ;
    CPy_DecRef(cpy_r_r146);
    goto CPyL121;
CPyL238: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL122;
CPyL239: ;
    CPy_DecRef(cpy_r_r156);
    goto CPyL166;
CPyL240: ;
    CPy_DecRef(cpy_r_r156);
    CPy_DecRef(cpy_r_r159);
    goto CPyL166;
CPyL241: ;
    CPy_DecRef(cpy_r_r156);
    CPy_DecRef(cpy_r_r159);
    CPy_DecRef(cpy_r_r160);
    goto CPyL166;
CPyL242: ;
    CPy_DecRef(cpy_r_r156);
    CPy_DecRef(cpy_r_r159);
    CPy_DecRef(cpy_r_r160);
    CPy_DecRef(cpy_r_r163);
    goto CPyL166;
CPyL243: ;
    CPy_DecRef(cpy_r_r163);
    CPy_DecRef(cpy_r_r164);
    goto CPyL166;
CPyL244: ;
    CPy_DecRef(cpy_r_r168);
    goto CPyL134;
CPyL245: ;
    CPy_DecRef(cpy_r_r163);
    goto CPyL166;
CPyL246: ;
    CPy_DecRef(cpy_r_r163);
    CPy_DecRef(cpy_r_r169);
    goto CPyL166;
CPyL247: ;
    CPy_DecRef(cpy_r_r185);
    goto CPyL166;
CPyL248: ;
    CPy_DecRef(cpy_r_r185);
    CPy_DecRef(cpy_r_r188);
    goto CPyL166;
CPyL249: ;
    CPy_DecRef(cpy_r_r185);
    CPy_DecRef(cpy_r_r188);
    CPy_DecRef(cpy_r_r189);
    goto CPyL166;
CPyL250: ;
    CPy_DecRef(cpy_r_r185);
    CPy_DecRef(cpy_r_r188);
    CPy_DecRef(cpy_r_r189);
    CPy_DecRef(cpy_r_r192);
    goto CPyL166;
CPyL251: ;
    CPy_DecRef(cpy_r_r192);
    CPy_DecRef(cpy_r_r193);
    goto CPyL166;
CPyL252: ;
    CPy_DecRef(cpy_r_r197);
    goto CPyL154;
CPyL253: ;
    CPy_DecRef(cpy_r_r192);
    goto CPyL166;
CPyL254: ;
    CPy_DecRef(cpy_r_r192);
    CPy_DecRef(cpy_r_r198);
    goto CPyL166;
CPyL255: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL163;
CPyL256: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r209);
    goto CPyL184;
CPyL257: ;
    CPy_DecRef(cpy_r_r217);
    goto CPyL184;
CPyL258: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL2;
CPyL259: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL182;
}

PyObject *CPyPy_encode_input_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef_encode_input_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_input_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_encode_input_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_encode_input_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_encode_input_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.encode_input_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_encode_input_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_input_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_encode_input_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_encode_input_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_encode_input_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.encode_input_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_encode_input_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_input_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_encode_input_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_encode_input_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.encode_input_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_encode_input_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_input_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
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
    cpy_r_r1 = CPyDef_encode_input_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
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

PyObject *CPyPy_encode_input_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_encode_input_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.encode_input_gen", obj___mypyc_self__); 
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
    PyObject *retval = CPyDef_encode_input_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_input_gen___close(PyObject *cpy_r___mypyc_self__) {
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
    cpy_r_r1 = CPyStatics[31]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_encode_input_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[32]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp12 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp12);
    PyObject *__tmp13 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp13);
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

PyObject *CPyPy_encode_input_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_encode_input_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.encode_input_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_encode_input_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_input_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_encode_input_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_encode_input_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.encode_input_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_encode_input_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_encode_input(PyObject *cpy_r_call, CPyTagged cpy_r_len_inputs, PyObject *cpy_r_get_request_data, PyObject *cpy_r_args) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = CPyDef_encode_input_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_INCREF(cpy_r_call);
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_call != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_call);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_call = cpy_r_call;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL10;
    }
    CPyTagged_INCREF(cpy_r_len_inputs);
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_len_inputs != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_len_inputs);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_len_inputs = cpy_r_len_inputs;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_get_request_data);
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_get_request_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_get_request_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_get_request_data = cpy_r_get_request_data;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_args);
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_args != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_args);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_args = cpy_r_args;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r5 = CPyDef_encode_input_gen();
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___brownie_patch___call___encode_input_genObject *)cpy_r_r5)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_genObject *)cpy_r_r5)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___encode_input_genObject *)cpy_r_r5)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL11;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r7 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL12;
    }
    return cpy_r_r5;
CPyL9: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
CPyL10: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL9;
CPyL11: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    goto CPyL9;
CPyL12: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL9;
}

PyObject *CPyPy_encode_input(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"call", "len_inputs", "get_request_data", 0};
    static CPyArg_Parser parser = {"%OOO:encode_input", kwlist, 0};
    PyObject *obj_call;
    PyObject *obj_len_inputs;
    PyObject *obj_get_request_data;
    PyObject *obj_args;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_args, NULL, &obj_call, &obj_len_inputs, &obj_get_request_data)) {
        return NULL;
    }
    PyObject *arg_call = obj_call;
    CPyTagged arg_len_inputs;
    if (likely(PyLong_Check(obj_len_inputs)))
        arg_len_inputs = CPyTagged_BorrowFromObject(obj_len_inputs);
    else {
        CPy_TypeError("int", obj_len_inputs); goto fail;
    }
    PyObject *arg_get_request_data = obj_get_request_data;
    PyObject *arg_args = obj_args;
    PyObject *retval = CPyDef_encode_input(arg_call, arg_len_inputs, arg_get_request_data, arg_args);
    CPy_DECREF(obj_args);
    return retval;
fail: ;
    CPy_DECREF(obj_args);
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_output_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPyTagged cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    int32_t cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    char cpy_r_r48;
    tuple_T3OOO cpy_r_r49;
    char cpy_r_r50;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    char cpy_r_r53;
    char cpy_r_r54;
    tuple_T3OOO cpy_r_r55;
    char cpy_r_r56;
    tuple_T3OOO cpy_r_r57;
    tuple_T3OOO cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    char cpy_r_r63;
    tuple_T3OOO cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    char cpy_r_r69;
    PyObject *cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    char cpy_r_r74;
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
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject **cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    char cpy_r_r98;
    PyObject *cpy_r_r99;
    int32_t cpy_r_r100;
    char cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    char cpy_r_r108;
    tuple_T3OOO cpy_r_r109;
    tuple_T3OOO cpy_r_r110;
    char cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    int32_t cpy_r_r116;
    char cpy_r_r117;
    char cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    char cpy_r_r121;
    tuple_T3OOO cpy_r_r122;
    char cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    char cpy_r_r127;
    PyObject *cpy_r_r128;
    char cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    int32_t cpy_r_r140;
    char cpy_r_r141;
    int32_t cpy_r_r142;
    char cpy_r_r143;
    int32_t cpy_r_r144;
    char cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    int32_t cpy_r_r149;
    char cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    char cpy_r_r154;
    PyObject *cpy_r_r155;
    char cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    char cpy_r_r160;
    PyObject *cpy_r_r161;
    char cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject **cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    int32_t cpy_r_r176;
    char cpy_r_r177;
    char cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    int32_t cpy_r_r182;
    char cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    char cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    char cpy_r_r194;
    PyObject *cpy_r_r195;
    char cpy_r_r196;
    tuple_T3OOO cpy_r_r197;
    char cpy_r_r198;
    PyObject **cpy_r_r199;
    PyObject *cpy_r_r200;
    char cpy_r_r201;
    char cpy_r_r202;
    tuple_T3OOO cpy_r_r203;
    char cpy_r_r204;
    tuple_T3OOO cpy_r_r205;
    tuple_T3OOO cpy_r_r206;
    char cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    tuple_T3OOO cpy_r_r211;
    char cpy_r_r212;
    tuple_T3OOO cpy_r_r213;
    char cpy_r_r214;
    char cpy_r_r215;
    char cpy_r_r216;
    char cpy_r_r217;
    char cpy_r_r218;
    PyObject *cpy_r_r219;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = NULL;
    cpy_r_r3 = cpy_r_r2;
    cpy_r_r4 = ((dank_mids___brownie_patch___call___decode_output_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_gen", "__mypyc_env__", 196, CPyStatic_globals);
        goto CPyL207;
    }
    CPy_INCREF(cpy_r_r4);
CPyL1: ;
    cpy_r_r5 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__;
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_next_label__", 196, CPyStatic_globals);
        goto CPyL208;
    }
    CPyTagged_INCREF(cpy_r_r5);
    goto CPyL201;
CPyL2: ;
    cpy_r_r6 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r7 = cpy_r_type != cpy_r_r6;
    if (cpy_r_r7) {
        goto CPyL209;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL206;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r8 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 197, CPyStatic_globals);
        goto CPyL208;
    }
    CPy_INCREF(cpy_r_r8);
CPyL6: ;
    cpy_r_r9 = CPyStatics[5]; /* 'abi' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL208;
    }
    cpy_r_r11 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 197, CPyStatic_globals);
        goto CPyL210;
    }
    CPy_INCREF(cpy_r_r11);
CPyL8: ;
    if (likely(PyDict_Check(cpy_r_r10)))
        cpy_r_r12 = cpy_r_r10;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals, "dict", cpy_r_r10);
        goto CPyL211;
    }
    cpy_r_r13 = CPyDef___validate_output(cpy_r_r12, cpy_r_r11);
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r13 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL208;
    }
    cpy_r_r14 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 199, CPyStatic_globals);
        goto CPyL212;
    }
    CPy_INCREF(cpy_r_r14);
CPyL11: ;
    cpy_r_r15 = CPyStatics[12]; /* '_skip_decoder_proc_pool' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 199, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r17 = PyObject_IsTrue(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r18 = cpy_r_r17 >= 0;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 199, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r19 = cpy_r_r17;
    if (cpy_r_r19) goto CPyL213;
    cpy_r_r20 = CPyStatics[191]; /* b'Unexpected error' */
    cpy_r_r21 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 199, CPyStatic_globals);
        goto CPyL212;
    }
    CPy_INCREF(cpy_r_r21);
CPyL15: ;
    cpy_r_r22 = PySequence_Contains(cpy_r_r21, cpy_r_r20);
    CPy_DECREF(cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 199, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r24 = cpy_r_r22;
    if (cpy_r_r24) {
        goto CPyL213;
    } else
        goto CPyL23;
CPyL17: ;
    cpy_r_r25 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 201, CPyStatic_globals);
        goto CPyL114;
    }
    CPy_INCREF(cpy_r_r25);
CPyL18: ;
    cpy_r_r26 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 201, CPyStatic_globals);
        goto CPyL214;
    }
    CPy_INCREF(cpy_r_r26);
CPyL19: ;
    cpy_r_r27 = CPyStatics[5]; /* 'abi' */
    cpy_r_r28 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 201, CPyStatic_globals);
        goto CPyL214;
    }
    if (likely(PyDict_Check(cpy_r_r28)))
        cpy_r_r29 = cpy_r_r28;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "decode_output", 201, CPyStatic_globals, "dict", cpy_r_r28);
        goto CPyL214;
    }
    cpy_r_r30 = CPyDef___decode_output(cpy_r_r25, cpy_r_r29);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 201, CPyStatic_globals);
        goto CPyL114;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded = cpy_r_r30;
    cpy_r_r31 = 1;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 201, CPyStatic_globals);
        goto CPyL114;
    } else
        goto CPyL103;
CPyL23: ;
    cpy_r_r32 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 204, CPyStatic_globals);
        goto CPyL215;
    }
    CPy_INCREF(cpy_r_r32);
CPyL24: ;
    cpy_r_r33 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 204, CPyStatic_globals);
        goto CPyL216;
    }
    CPy_INCREF(cpy_r_r33);
CPyL25: ;
    cpy_r_r34 = CPyStatic_decode;
    if (unlikely(cpy_r_r34 == NULL)) {
        goto CPyL217;
    } else
        goto CPyL28;
CPyL26: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"decode\" was not set");
    cpy_r_r35 = 0;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
        goto CPyL65;
    } else
        goto CPyL218;
CPyL27: ;
    CPy_Unreachable();
CPyL28: ;
    PyObject *cpy_r_r36[2] = {cpy_r_r32, cpy_r_r33};
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = _PyObject_Vectorcall(cpy_r_r34, cpy_r_r37, 2, 0);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
        goto CPyL219;
    }
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r39 = CPy_GetCoro(cpy_r_r38);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
        goto CPyL215;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32 = cpy_r_r39;
    cpy_r_r40 = 1;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r41 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32;
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__32", -1, CPyStatic_globals);
        goto CPyL215;
    }
    CPy_INCREF(cpy_r_r41);
CPyL32: ;
    cpy_r_r42 = CPyIter_Next(cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (cpy_r_r42 == NULL) {
        goto CPyL220;
    } else
        goto CPyL35;
CPyL33: ;
    cpy_r_r43 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r44 = cpy_r_r43;
    goto CPyL64;
CPyL35: ;
    cpy_r_r45 = cpy_r_r42;
CPyL36: ;
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ = 2;
    cpy_r_r46 = 1;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
        goto CPyL221;
    } else
        goto CPyL222;
CPyL37: ;
    return cpy_r_r45;
CPyL38: ;
    cpy_r_r47 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r48 = cpy_r_type != cpy_r_r47;
    if (!cpy_r_r48) goto CPyL41;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
        goto CPyL42;
    } else
        goto CPyL223;
CPyL40: ;
    CPy_Unreachable();
CPyL41: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL59;
CPyL42: ;
    cpy_r_r49 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33.f2);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33 = cpy_r_r49;
    cpy_r_r50 = 1;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL224;
    }
    cpy_r_r51 = (PyObject **)&cpy_r_r1;
    cpy_r_r52 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32;
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__32", -1, CPyStatic_globals);
        goto CPyL224;
    }
    CPy_INCREF(cpy_r_r52);
CPyL44: ;
    cpy_r_r53 = CPy_YieldFromErrorHandle(cpy_r_r52, cpy_r_r51);
    CPy_DecRef(cpy_r_r52);
    if (unlikely(cpy_r_r53 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
        goto CPyL224;
    }
    if (cpy_r_r53) goto CPyL51;
    if (cpy_r_r1 != NULL) goto CPyL49;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r54 = 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL56;
    } else
        goto CPyL225;
CPyL48: ;
    CPy_Unreachable();
CPyL49: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r45 = cpy_r_r1;
    cpy_r_r55 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33;
    if (unlikely(cpy_r_r55.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__33", -1, CPyStatic_globals);
        goto CPyL226;
    }
    CPy_INCREF(cpy_r_r55.f0);
    CPy_INCREF(cpy_r_r55.f1);
    CPy_INCREF(cpy_r_r55.f2);
CPyL50: ;
    CPy_RestoreExcInfo(cpy_r_r55);
    CPy_DecRef(cpy_r_r55.f0);
    CPy_DecRef(cpy_r_r55.f1);
    CPy_DecRef(cpy_r_r55.f2);
    goto CPyL36;
CPyL51: ;
    if (cpy_r_r1 != NULL) goto CPyL54;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL56;
    } else
        goto CPyL227;
CPyL53: ;
    CPy_Unreachable();
CPyL54: ;
    cpy_r_r44 = cpy_r_r1;
    cpy_r_r57 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33;
    if (unlikely(cpy_r_r57.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__33", -1, CPyStatic_globals);
        goto CPyL228;
    }
    CPy_INCREF(cpy_r_r57.f0);
    CPy_INCREF(cpy_r_r57.f1);
    CPy_INCREF(cpy_r_r57.f2);
CPyL55: ;
    CPy_RestoreExcInfo(cpy_r_r57);
    CPy_DecRef(cpy_r_r57.f0);
    CPy_DecRef(cpy_r_r57.f1);
    CPy_DecRef(cpy_r_r57.f2);
    goto CPyL64;
CPyL56: ;
    cpy_r_r58 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33;
    if (unlikely(cpy_r_r58.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__33", -1, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF(cpy_r_r58.f0);
    CPy_INCREF(cpy_r_r58.f1);
    CPy_INCREF(cpy_r_r58.f2);
CPyL57: ;
    CPy_RestoreExcInfo(cpy_r_r58);
    CPy_DecRef(cpy_r_r58.f0);
    CPy_DecRef(cpy_r_r58.f1);
    CPy_DecRef(cpy_r_r58.f2);
    cpy_r_r59 = CPy_KeepPropagating();
    if (!cpy_r_r59) {
        goto CPyL65;
    } else
        goto CPyL229;
CPyL58: ;
    CPy_Unreachable();
CPyL59: ;
    cpy_r_r60 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__32", -1, CPyStatic_globals);
        goto CPyL230;
    }
    CPy_INCREF(cpy_r_r60);
CPyL60: ;
    cpy_r_r61 = CPyIter_Send(cpy_r_r60, cpy_r_arg);
    CPy_DECREF(cpy_r_r60);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r61 == NULL) goto CPyL231;
    cpy_r_r45 = cpy_r_r61;
    goto CPyL36;
CPyL62: ;
    cpy_r_r62 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r44 = cpy_r_r62;
CPyL64: ;
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded = cpy_r_r44;
    cpy_r_r63 = 1;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 204, CPyStatic_globals);
    } else
        goto CPyL103;
CPyL65: ;
    cpy_r_r64 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34.f2);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34 = cpy_r_r64;
    cpy_r_r65 = 1;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r66 = CPyStatic_globals;
    cpy_r_r67 = CPyStatics[37]; /* 'BrokenProcessPool' */
    cpy_r_r68 = CPyDict_GetItem(cpy_r_r66, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 206, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r69 = CPy_ExceptionMatches(cpy_r_r68);
    CPy_DecRef(cpy_r_r68);
    if (!cpy_r_r69) goto CPyL96;
    cpy_r_r70 = CPyStatic_logger;
    if (likely(cpy_r_r70 != NULL)) goto CPyL71;
    PyErr_SetString(PyExc_NameError, "value for final name \"logger\" was not set");
    cpy_r_r71 = 0;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 208, CPyStatic_globals);
        goto CPyL100;
    } else
        goto CPyL232;
CPyL70: ;
    CPy_Unreachable();
CPyL71: ;
    cpy_r_r72 = CPyStatics[38]; /* 'Oh fuck, you broke the %s while decoding %s with abi %s' */
    cpy_r_r73 = CPyStatic_ENVS;
    if (likely(cpy_r_r73 != NULL)) goto CPyL74;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r74 = 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 208, CPyStatic_globals);
        goto CPyL100;
    } else
        goto CPyL233;
CPyL73: ;
    CPy_Unreachable();
CPyL74: ;
    cpy_r_r75 = CPyStatics[8]; /* 'BROWNIE_DECODER_PROCESSES' */
    cpy_r_r76 = CPyObject_GetAttr(cpy_r_r73, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 208, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r77 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 208, CPyStatic_globals);
        goto CPyL234;
    }
    CPy_INCREF(cpy_r_r77);
CPyL76: ;
    cpy_r_r78 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 208, CPyStatic_globals);
        goto CPyL235;
    }
    CPy_INCREF(cpy_r_r78);
CPyL77: ;
    cpy_r_r79 = CPyStatics[5]; /* 'abi' */
    cpy_r_r80 = CPyObject_GetAttr(cpy_r_r78, cpy_r_r79);
    CPy_DecRef(cpy_r_r78);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 208, CPyStatic_globals);
        goto CPyL235;
    }
    cpy_r_r81 = CPyStatics[39]; /* 'critical' */
    PyObject *cpy_r_r82[5] = {cpy_r_r70, cpy_r_r72, cpy_r_r76, cpy_r_r77, cpy_r_r80};
    cpy_r_r83 = (PyObject **)&cpy_r_r82;
    cpy_r_r84 = PyObject_VectorcallMethod(cpy_r_r81, cpy_r_r83, 9223372036854775813ULL, 0);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 208, CPyStatic_globals);
        goto CPyL236;
    } else
        goto CPyL237;
CPyL79: ;
    CPy_DecRef(cpy_r_r76);
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r80);
    cpy_r_r85 = CPyStatic_ENVS;
    if (likely(cpy_r_r85 != NULL)) goto CPyL82;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r86 = 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 209, CPyStatic_globals);
        goto CPyL100;
    } else
        goto CPyL238;
CPyL81: ;
    CPy_Unreachable();
CPyL82: ;
    cpy_r_r87 = CPyStatics[8]; /* 'BROWNIE_DECODER_PROCESSES' */
    cpy_r_r88 = CPyObject_GetAttr(cpy_r_r85, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 209, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r89 = CPyStatics[40]; /* '_max_workers' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r89);
    CPy_DecRef(cpy_r_r88);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 209, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r91 = CPyStatic_globals;
    cpy_r_r92 = CPyStatics[41]; /* 'AsyncProcessPoolExecutor' */
    cpy_r_r93 = CPyDict_GetItem(cpy_r_r91, cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 209, CPyStatic_globals);
        goto CPyL239;
    }
    PyObject *cpy_r_r94[1] = {cpy_r_r90};
    cpy_r_r95 = (PyObject **)&cpy_r_r94;
    cpy_r_r96 = _PyObject_Vectorcall(cpy_r_r93, cpy_r_r95, 1, 0);
    CPy_DecRef(cpy_r_r93);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 209, CPyStatic_globals);
        goto CPyL239;
    }
    CPy_DecRef(cpy_r_r90);
    cpy_r_r97 = CPyStatic_ENVS;
    if (unlikely(cpy_r_r97 == NULL)) {
        goto CPyL240;
    } else
        goto CPyL89;
CPyL87: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r98 = 0;
    if (unlikely(!cpy_r_r98)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 209, CPyStatic_globals);
        goto CPyL100;
    } else
        goto CPyL241;
CPyL88: ;
    CPy_Unreachable();
CPyL89: ;
    cpy_r_r99 = CPyStatics[8]; /* 'BROWNIE_DECODER_PROCESSES' */
    cpy_r_r100 = PyObject_SetAttr(cpy_r_r97, cpy_r_r99, cpy_r_r96);
    CPy_DecRef(cpy_r_r96);
    cpy_r_r101 = cpy_r_r100 >= 0;
    if (unlikely(!cpy_r_r101)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 209, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r102 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 210, CPyStatic_globals);
        goto CPyL100;
    }
    CPy_INCREF(cpy_r_r102);
CPyL91: ;
    cpy_r_r103 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 210, CPyStatic_globals);
        goto CPyL242;
    }
    CPy_INCREF(cpy_r_r103);
CPyL92: ;
    cpy_r_r104 = CPyStatics[5]; /* 'abi' */
    cpy_r_r105 = CPyObject_GetAttr(cpy_r_r103, cpy_r_r104);
    CPy_DecRef(cpy_r_r103);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 210, CPyStatic_globals);
        goto CPyL242;
    }
    if (likely(PyDict_Check(cpy_r_r105)))
        cpy_r_r106 = cpy_r_r105;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "decode_output", 210, CPyStatic_globals, "dict", cpy_r_r105);
        goto CPyL242;
    }
    cpy_r_r107 = CPyDef___decode_output(cpy_r_r102, cpy_r_r106);
    CPy_DecRef(cpy_r_r102);
    CPy_DecRef(cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 210, CPyStatic_globals);
        goto CPyL100;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded = cpy_r_r107;
    cpy_r_r108 = 1;
    if (unlikely(!cpy_r_r108)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 210, CPyStatic_globals);
        goto CPyL100;
    } else
        goto CPyL98;
CPyL96: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL100;
    } else
        goto CPyL243;
CPyL97: ;
    CPy_Unreachable();
CPyL98: ;
    cpy_r_r109 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34;
    if (unlikely(cpy_r_r109.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__34", -1, CPyStatic_globals);
        goto CPyL114;
    }
    CPy_INCREF(cpy_r_r109.f0);
    CPy_INCREF(cpy_r_r109.f1);
    CPy_INCREF(cpy_r_r109.f2);
CPyL99: ;
    CPy_RestoreExcInfo(cpy_r_r109);
    CPy_DecRef(cpy_r_r109.f0);
    CPy_DecRef(cpy_r_r109.f1);
    CPy_DecRef(cpy_r_r109.f2);
    goto CPyL103;
CPyL100: ;
    cpy_r_r110 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34;
    if (unlikely(cpy_r_r110.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__34", -1, CPyStatic_globals);
        goto CPyL114;
    }
    CPy_INCREF(cpy_r_r110.f0);
    CPy_INCREF(cpy_r_r110.f1);
    CPy_INCREF(cpy_r_r110.f2);
CPyL101: ;
    CPy_RestoreExcInfo(cpy_r_r110);
    CPy_DecRef(cpy_r_r110.f0);
    CPy_DecRef(cpy_r_r110.f1);
    CPy_DecRef(cpy_r_r110.f2);
    cpy_r_r111 = CPy_KeepPropagating();
    if (!cpy_r_r111) {
        goto CPyL114;
    } else
        goto CPyL244;
CPyL102: ;
    CPy_Unreachable();
CPyL103: ;
    cpy_r_r112 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded;
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "decoded", 212, CPyStatic_globals);
        goto CPyL114;
    }
    CPy_INCREF(cpy_r_r112);
CPyL104: ;
    cpy_r_r113 = CPyModule_builtins;
    cpy_r_r114 = CPyStatics[43]; /* 'Exception' */
    cpy_r_r115 = CPyObject_GetAttr(cpy_r_r113, cpy_r_r114);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 212, CPyStatic_globals);
        goto CPyL245;
    }
    cpy_r_r116 = PyObject_IsInstance(cpy_r_r112, cpy_r_r115);
    CPy_DECREF(cpy_r_r112);
    CPy_DECREF(cpy_r_r115);
    cpy_r_r117 = cpy_r_r116 >= 0;
    if (unlikely(!cpy_r_r117)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 212, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r118 = cpy_r_r116;
    if (!cpy_r_r118) goto CPyL110;
    cpy_r_r119 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded;
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "decoded", 213, CPyStatic_globals);
        goto CPyL114;
    }
    CPy_INCREF(cpy_r_r119);
CPyL108: ;
    CPy_Raise(cpy_r_r119);
    CPy_DECREF(cpy_r_r119);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL114;
    } else
        goto CPyL246;
CPyL109: ;
    CPy_Unreachable();
CPyL110: ;
    cpy_r_r120 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded;
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "decoded", 214, CPyStatic_globals);
        goto CPyL114;
    }
    CPy_INCREF(cpy_r_r120);
CPyL111: ;
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ = -2;
    cpy_r_r121 = 1;
    if (unlikely(!cpy_r_r121)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 214, CPyStatic_globals);
        goto CPyL247;
    } else
        goto CPyL248;
CPyL112: ;
    CPyGen_SetStopIterationValue(cpy_r_r120);
    CPy_DECREF(cpy_r_r120);
    if (!0) goto CPyL206;
    CPy_Unreachable();
CPyL114: ;
    cpy_r_r122 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35.f2);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35 = cpy_r_r122;
    cpy_r_r123 = 1;
    if (unlikely(!cpy_r_r123)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r124 = CPyStatic_globals;
    cpy_r_r125 = CPyStatics[30]; /* 'InsufficientDataBytes' */
    cpy_r_r126 = CPyDict_GetItem(cpy_r_r124, cpy_r_r125);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 215, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r127 = CPy_ExceptionMatches(cpy_r_r126);
    CPy_DecRef(cpy_r_r126);
    if (cpy_r_r127) {
        goto CPyL250;
    } else
        goto CPyL134;
CPyL117: ;
    cpy_r_r128 = CPy_GetExcValue();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e = cpy_r_r128;
    cpy_r_r129 = 1;
    if (unlikely(!cpy_r_r129)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 215, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r130 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e;
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "e", 217, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_INCREF(cpy_r_r130);
CPyL119: ;
    cpy_r_r131 = CPyStatics[44]; /* 'args' */
    cpy_r_r132 = CPyObject_GetAttr(cpy_r_r130, cpy_r_r131);
    CPy_DecRef(cpy_r_r130);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r133 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 217, CPyStatic_globals);
        goto CPyL251;
    }
    CPy_INCREF(cpy_r_r133);
CPyL121: ;
    cpy_r_r134 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 217, CPyStatic_globals);
        goto CPyL252;
    }
    CPy_INCREF(cpy_r_r134);
CPyL122: ;
    cpy_r_r135 = CPyStatics[10]; /* '_address' */
    cpy_r_r136 = CPyObject_GetAttr(cpy_r_r134, cpy_r_r135);
    CPy_DecRef(cpy_r_r134);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL252;
    }
    cpy_r_r137 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 217, CPyStatic_globals);
        goto CPyL253;
    }
    CPy_INCREF(cpy_r_r137);
CPyL124: ;
    cpy_r_r138 = PyList_New(0);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL254;
    }
    cpy_r_r139 = CPyList_Extend(cpy_r_r138, cpy_r_r132);
    CPy_DecRef(cpy_r_r132);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL255;
    } else
        goto CPyL256;
CPyL126: ;
    cpy_r_r140 = PyList_Append(cpy_r_r138, cpy_r_r133);
    CPy_DecRef(cpy_r_r133);
    cpy_r_r141 = cpy_r_r140 >= 0;
    if (unlikely(!cpy_r_r141)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL257;
    }
    cpy_r_r142 = PyList_Append(cpy_r_r138, cpy_r_r136);
    CPy_DecRef(cpy_r_r136);
    cpy_r_r143 = cpy_r_r142 >= 0;
    if (unlikely(!cpy_r_r143)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL258;
    }
    cpy_r_r144 = PyList_Append(cpy_r_r138, cpy_r_r137);
    CPy_DecRef(cpy_r_r137);
    cpy_r_r145 = cpy_r_r144 >= 0;
    if (unlikely(!cpy_r_r145)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL259;
    }
    cpy_r_r146 = PyList_AsTuple(cpy_r_r138);
    CPy_DecRef(cpy_r_r138);
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r147 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e;
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "e", 217, CPyStatic_globals);
        goto CPyL260;
    }
    CPy_INCREF(cpy_r_r147);
CPyL131: ;
    cpy_r_r148 = CPyStatics[44]; /* 'args' */
    cpy_r_r149 = PyObject_SetAttr(cpy_r_r147, cpy_r_r148, cpy_r_r146);
    CPy_DecRef(cpy_r_r147);
    CPy_DecRef(cpy_r_r146);
    cpy_r_r150 = cpy_r_r149 >= 0;
    if (unlikely(!cpy_r_r150)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 217, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_Reraise();
    if (!0) {
        goto CPyL198;
    } else
        goto CPyL261;
CPyL133: ;
    CPy_Unreachable();
CPyL134: ;
    cpy_r_r151 = CPyModule_builtins;
    cpy_r_r152 = CPyStatics[35]; /* 'AttributeError' */
    cpy_r_r153 = CPyObject_GetAttr(cpy_r_r151, cpy_r_r152);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 219, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r154 = CPy_ExceptionMatches(cpy_r_r153);
    CPy_DecRef(cpy_r_r153);
    if (!cpy_r_r154) goto CPyL262;
    cpy_r_r155 = CPy_GetExcValue();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e = cpy_r_r155;
    cpy_r_r156 = 1;
    if (unlikely(!cpy_r_r156)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 219, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r157 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e;
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "e", 221, CPyStatic_globals);
        goto CPyL249;
    }
    CPy_INCREF(cpy_r_r157);
CPyL138: ;
    cpy_r_r158 = PyObject_Str(cpy_r_r157);
    CPy_DecRef(cpy_r_r157);
    if (unlikely(cpy_r_r158 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 221, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r159 = CPyStatics[45]; /* " object has no attribute '_skip_decoder_proc_pool'" */
    cpy_r_r160 = CPyStr_Endswith(cpy_r_r158, cpy_r_r159);
    CPy_DecRef(cpy_r_r158);
    if (cpy_r_r160) {
        goto CPyL142;
    } else
        goto CPyL263;
CPyL140: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL198;
    } else
        goto CPyL264;
CPyL141: ;
    CPy_Unreachable();
CPyL142: ;
    cpy_r_r161 = CPyStatic_logger;
    if (unlikely(cpy_r_r161 == NULL)) {
        goto CPyL265;
    } else
        goto CPyL145;
CPyL143: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"logger\" was not set");
    cpy_r_r162 = 0;
    if (unlikely(!cpy_r_r162)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 223, CPyStatic_globals);
        goto CPyL198;
    } else
        goto CPyL266;
CPyL144: ;
    CPy_Unreachable();
CPyL145: ;
    cpy_r_r163 = CPyStatics[46]; /* 'DEBUG ME BRO: %s' */
    cpy_r_r164 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e;
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "e", 223, CPyStatic_globals);
        goto CPyL249;
    }
    CPy_INCREF(cpy_r_r164);
CPyL146: ;
    cpy_r_r165 = CPyStatics[47]; /* 'debug' */
    PyObject *cpy_r_r166[3] = {cpy_r_r161, cpy_r_r163, cpy_r_r164};
    cpy_r_r167 = (PyObject **)&cpy_r_r166;
    cpy_r_r168 = PyObject_VectorcallMethod(cpy_r_r165, cpy_r_r167, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r168 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 223, CPyStatic_globals);
        goto CPyL267;
    } else
        goto CPyL268;
CPyL147: ;
    CPy_DecRef(cpy_r_r164);
    cpy_r_r169 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 224, CPyStatic_globals);
        goto CPyL249;
    }
    CPy_INCREF(cpy_r_r169);
CPyL148: ;
    cpy_r_r170 = CPyStatics[10]; /* '_address' */
    cpy_r_r171 = CPyObject_GetAttr(cpy_r_r169, cpy_r_r170);
    CPy_DecRef(cpy_r_r169);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 224, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r172 = CPyStatic_globals;
    cpy_r_r173 = CPyStatics[11]; /* '_skip_proc_pool' */
    cpy_r_r174 = CPyDict_GetItem(cpy_r_r172, cpy_r_r173);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 224, CPyStatic_globals);
        goto CPyL269;
    }
    if (likely(PySet_Check(cpy_r_r174)))
        cpy_r_r175 = cpy_r_r174;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "decode_output", 224, CPyStatic_globals, "set", cpy_r_r174);
        goto CPyL269;
    }
    cpy_r_r176 = PySet_Contains(cpy_r_r175, cpy_r_r171);
    CPy_DecRef(cpy_r_r175);
    CPy_DecRef(cpy_r_r171);
    cpy_r_r177 = cpy_r_r176 >= 0;
    if (unlikely(!cpy_r_r177)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 224, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r178 = cpy_r_r176;
    cpy_r_r179 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 224, CPyStatic_globals);
        goto CPyL249;
    }
    CPy_INCREF(cpy_r_r179);
CPyL153: ;
    cpy_r_r180 = CPyStatics[12]; /* '_skip_decoder_proc_pool' */
    cpy_r_r181 = cpy_r_r178 ? Py_True : Py_False;
    cpy_r_r182 = PyObject_SetAttr(cpy_r_r179, cpy_r_r180, cpy_r_r181);
    CPy_DecRef(cpy_r_r179);
    cpy_r_r183 = cpy_r_r182 >= 0;
    if (unlikely(!cpy_r_r183)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 224, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r184 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 225, CPyStatic_globals);
        goto CPyL249;
    }
    CPy_INCREF(cpy_r_r184);
CPyL155: ;
    cpy_r_r185 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r185 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 225, CPyStatic_globals);
        goto CPyL270;
    }
    CPy_INCREF(cpy_r_r185);
CPyL156: ;
    cpy_r_r186 = CPyDef_decode_output(cpy_r_r184, cpy_r_r185);
    CPy_DecRef(cpy_r_r184);
    CPy_DecRef(cpy_r_r185);
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 225, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r187 = CPy_GetCoro(cpy_r_r186);
    CPy_DecRef(cpy_r_r186);
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 225, CPyStatic_globals);
        goto CPyL249;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36 = cpy_r_r187;
    cpy_r_r188 = 1;
    if (unlikely(!cpy_r_r188)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r189 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36;
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__36", -1, CPyStatic_globals);
        goto CPyL249;
    }
    CPy_INCREF(cpy_r_r189);
CPyL160: ;
    cpy_r_r190 = CPyIter_Next(cpy_r_r189);
    CPy_DecRef(cpy_r_r189);
    if (cpy_r_r190 == NULL) {
        goto CPyL271;
    } else
        goto CPyL163;
CPyL161: ;
    cpy_r_r191 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 225, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r192 = cpy_r_r191;
    goto CPyL192;
CPyL163: ;
    cpy_r_r193 = cpy_r_r190;
CPyL164: ;
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ = 4;
    cpy_r_r194 = 1;
    if (unlikely(!cpy_r_r194)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 225, CPyStatic_globals);
        goto CPyL272;
    } else
        goto CPyL273;
CPyL165: ;
    return cpy_r_r193;
CPyL166: ;
    cpy_r_r195 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r196 = cpy_r_type != cpy_r_r195;
    if (!cpy_r_r196) goto CPyL169;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 225, CPyStatic_globals);
        goto CPyL170;
    } else
        goto CPyL274;
CPyL168: ;
    CPy_Unreachable();
CPyL169: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL187;
CPyL170: ;
    cpy_r_r197 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37.f2);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37 = cpy_r_r197;
    cpy_r_r198 = 1;
    if (unlikely(!cpy_r_r198)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL275;
    }
    cpy_r_r199 = (PyObject **)&cpy_r_r3;
    cpy_r_r200 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36;
    if (unlikely(cpy_r_r200 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__36", -1, CPyStatic_globals);
        goto CPyL275;
    }
    CPy_INCREF(cpy_r_r200);
CPyL172: ;
    cpy_r_r201 = CPy_YieldFromErrorHandle(cpy_r_r200, cpy_r_r199);
    CPy_DecRef(cpy_r_r200);
    if (unlikely(cpy_r_r201 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 225, CPyStatic_globals);
        goto CPyL275;
    }
    if (cpy_r_r201) goto CPyL179;
    if (cpy_r_r3 != NULL) goto CPyL177;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r202 = 0;
    if (unlikely(!cpy_r_r202)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL184;
    } else
        goto CPyL276;
CPyL176: ;
    CPy_Unreachable();
CPyL177: ;
    CPy_INCREF(cpy_r_r3);
    cpy_r_r193 = cpy_r_r3;
    cpy_r_r203 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37;
    if (unlikely(cpy_r_r203.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__37", -1, CPyStatic_globals);
        goto CPyL277;
    }
    CPy_INCREF(cpy_r_r203.f0);
    CPy_INCREF(cpy_r_r203.f1);
    CPy_INCREF(cpy_r_r203.f2);
CPyL178: ;
    CPy_RestoreExcInfo(cpy_r_r203);
    CPy_DecRef(cpy_r_r203.f0);
    CPy_DecRef(cpy_r_r203.f1);
    CPy_DecRef(cpy_r_r203.f2);
    goto CPyL164;
CPyL179: ;
    if (cpy_r_r3 != NULL) goto CPyL182;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r204 = 0;
    if (unlikely(!cpy_r_r204)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL184;
    } else
        goto CPyL278;
CPyL181: ;
    CPy_Unreachable();
CPyL182: ;
    cpy_r_r192 = cpy_r_r3;
    cpy_r_r205 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37;
    if (unlikely(cpy_r_r205.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__37", -1, CPyStatic_globals);
        goto CPyL279;
    }
    CPy_INCREF(cpy_r_r205.f0);
    CPy_INCREF(cpy_r_r205.f1);
    CPy_INCREF(cpy_r_r205.f2);
CPyL183: ;
    CPy_RestoreExcInfo(cpy_r_r205);
    CPy_DecRef(cpy_r_r205.f0);
    CPy_DecRef(cpy_r_r205.f1);
    CPy_DecRef(cpy_r_r205.f2);
    goto CPyL192;
CPyL184: ;
    cpy_r_r206 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37;
    if (unlikely(cpy_r_r206.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__37", -1, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_INCREF(cpy_r_r206.f0);
    CPy_INCREF(cpy_r_r206.f1);
    CPy_INCREF(cpy_r_r206.f2);
CPyL185: ;
    CPy_RestoreExcInfo(cpy_r_r206);
    CPy_DecRef(cpy_r_r206.f0);
    CPy_DecRef(cpy_r_r206.f1);
    CPy_DecRef(cpy_r_r206.f2);
    cpy_r_r207 = CPy_KeepPropagating();
    if (!cpy_r_r207) {
        goto CPyL198;
    } else
        goto CPyL280;
CPyL186: ;
    CPy_Unreachable();
CPyL187: ;
    cpy_r_r208 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36;
    if (unlikely(cpy_r_r208 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__36", -1, CPyStatic_globals);
        goto CPyL281;
    }
    CPy_INCREF(cpy_r_r208);
CPyL188: ;
    cpy_r_r209 = CPyIter_Send(cpy_r_r208, cpy_r_arg);
    CPy_DECREF(cpy_r_r208);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r209 == NULL) goto CPyL282;
    cpy_r_r193 = cpy_r_r209;
    goto CPyL164;
CPyL190: ;
    cpy_r_r210 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 225, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r192 = cpy_r_r210;
CPyL192: ;
    cpy_r_r211 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35;
    if (unlikely(cpy_r_r211.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__35", -1, CPyStatic_globals);
        goto CPyL283;
    }
    CPy_INCREF(cpy_r_r211.f0);
    CPy_INCREF(cpy_r_r211.f1);
    CPy_INCREF(cpy_r_r211.f2);
CPyL193: ;
    CPy_RestoreExcInfo(cpy_r_r211);
    CPy_DECREF(cpy_r_r211.f0);
    CPy_DECREF(cpy_r_r211.f1);
    CPy_DECREF(cpy_r_r211.f2);
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ = -2;
    cpy_r_r212 = 1;
    if (unlikely(!cpy_r_r212)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 225, CPyStatic_globals);
        goto CPyL283;
    } else
        goto CPyL284;
CPyL194: ;
    CPyGen_SetStopIterationValue(cpy_r_r192);
    CPy_DECREF(cpy_r_r192);
    if (!0) goto CPyL206;
    CPy_Unreachable();
CPyL196: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL198;
    } else
        goto CPyL285;
CPyL197: ;
    CPy_Unreachable();
CPyL198: ;
    cpy_r_r213 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35;
    if (unlikely(cpy_r_r213.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__35' of 'decode_output_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r213.f0);
        CPy_INCREF(cpy_r_r213.f1);
        CPy_INCREF(cpy_r_r213.f2);
    }
    CPy_DecRef(cpy_r_r4);
    if (unlikely(cpy_r_r213.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL206;
    }
CPyL199: ;
    CPy_RestoreExcInfo(cpy_r_r213);
    CPy_DecRef(cpy_r_r213.f0);
    CPy_DecRef(cpy_r_r213.f1);
    CPy_DecRef(cpy_r_r213.f2);
    cpy_r_r214 = CPy_KeepPropagating();
    if (!cpy_r_r214) goto CPyL206;
    CPy_Unreachable();
CPyL201: ;
    cpy_r_r215 = cpy_r_r5 == 0;
    if (cpy_r_r215) goto CPyL286;
    cpy_r_r216 = cpy_r_r5 == 2;
    if (cpy_r_r216) {
        goto CPyL287;
    } else
        goto CPyL288;
CPyL203: ;
    cpy_r_r217 = cpy_r_r5 == 4;
    CPyTagged_DECREF(cpy_r_r5);
    if (cpy_r_r217) {
        goto CPyL166;
    } else
        goto CPyL289;
CPyL204: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r218 = 0;
    if (unlikely(!cpy_r_r218)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL206;
    }
    CPy_Unreachable();
CPyL206: ;
    cpy_r_r219 = NULL;
    return cpy_r_r219;
CPyL207: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    goto CPyL206;
CPyL208: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL206;
CPyL209: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL3;
CPyL210: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r10);
    goto CPyL206;
CPyL211: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r11);
    goto CPyL206;
CPyL212: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL114;
CPyL213: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL17;
CPyL214: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL114;
CPyL215: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL65;
CPyL216: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r32);
    goto CPyL65;
CPyL217: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_r33);
    goto CPyL26;
CPyL218: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL27;
CPyL219: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_r33);
    goto CPyL65;
CPyL220: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL33;
CPyL221: ;
    CPy_DecRef(cpy_r_r45);
    goto CPyL42;
CPyL222: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL37;
CPyL223: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL40;
CPyL224: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL56;
CPyL225: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL48;
CPyL226: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r45);
    goto CPyL56;
CPyL227: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL53;
CPyL228: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL56;
CPyL229: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL58;
CPyL230: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_arg);
    goto CPyL65;
CPyL231: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL62;
CPyL232: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL70;
CPyL233: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL73;
CPyL234: ;
    CPy_DecRef(cpy_r_r76);
    goto CPyL100;
CPyL235: ;
    CPy_DecRef(cpy_r_r76);
    CPy_DecRef(cpy_r_r77);
    goto CPyL100;
CPyL236: ;
    CPy_DecRef(cpy_r_r76);
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r80);
    goto CPyL100;
CPyL237: ;
    CPy_DecRef(cpy_r_r84);
    goto CPyL79;
CPyL238: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL81;
CPyL239: ;
    CPy_DecRef(cpy_r_r90);
    goto CPyL100;
CPyL240: ;
    CPy_DecRef(cpy_r_r96);
    goto CPyL87;
CPyL241: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL88;
CPyL242: ;
    CPy_DecRef(cpy_r_r102);
    goto CPyL100;
CPyL243: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL97;
CPyL244: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL102;
CPyL245: ;
    CPy_DecRef(cpy_r_r112);
    goto CPyL114;
CPyL246: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL109;
CPyL247: ;
    CPy_DecRef(cpy_r_r120);
    goto CPyL114;
CPyL248: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL112;
CPyL249: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL198;
CPyL250: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL117;
CPyL251: ;
    CPy_DecRef(cpy_r_r132);
    goto CPyL198;
CPyL252: ;
    CPy_DecRef(cpy_r_r132);
    CPy_DecRef(cpy_r_r133);
    goto CPyL198;
CPyL253: ;
    CPy_DecRef(cpy_r_r132);
    CPy_DecRef(cpy_r_r133);
    CPy_DecRef(cpy_r_r136);
    goto CPyL198;
CPyL254: ;
    CPy_DecRef(cpy_r_r132);
    CPy_DecRef(cpy_r_r133);
    CPy_DecRef(cpy_r_r136);
    CPy_DecRef(cpy_r_r137);
    goto CPyL198;
CPyL255: ;
    CPy_DecRef(cpy_r_r133);
    CPy_DecRef(cpy_r_r136);
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r138);
    goto CPyL198;
CPyL256: ;
    CPy_DecRef(cpy_r_r139);
    goto CPyL126;
CPyL257: ;
    CPy_DecRef(cpy_r_r136);
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r138);
    goto CPyL198;
CPyL258: ;
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r138);
    goto CPyL198;
CPyL259: ;
    CPy_DecRef(cpy_r_r138);
    goto CPyL198;
CPyL260: ;
    CPy_DecRef(cpy_r_r146);
    goto CPyL198;
CPyL261: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL133;
CPyL262: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL196;
CPyL263: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL140;
CPyL264: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL141;
CPyL265: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL143;
CPyL266: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL144;
CPyL267: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r164);
    goto CPyL198;
CPyL268: ;
    CPy_DecRef(cpy_r_r168);
    goto CPyL147;
CPyL269: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r171);
    goto CPyL198;
CPyL270: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r184);
    goto CPyL198;
CPyL271: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL161;
CPyL272: ;
    CPy_DecRef(cpy_r_r193);
    goto CPyL170;
CPyL273: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL165;
CPyL274: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL168;
CPyL275: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL184;
CPyL276: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL176;
CPyL277: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r193);
    goto CPyL184;
CPyL278: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL181;
CPyL279: ;
    CPy_DecRef(cpy_r_r192);
    goto CPyL184;
CPyL280: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL186;
CPyL281: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_arg);
    goto CPyL198;
CPyL282: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL190;
CPyL283: ;
    CPy_DecRef(cpy_r_r192);
    goto CPyL198;
CPyL284: ;
    CPy_DECREF(cpy_r_r4);
    goto CPyL194;
CPyL285: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL197;
CPyL286: ;
    CPyTagged_DECREF(cpy_r_r5);
    goto CPyL2;
CPyL287: ;
    CPyTagged_DECREF(cpy_r_r5);
    goto CPyL38;
CPyL288: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL203;
CPyL289: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL204;
}

PyObject *CPyPy_decode_output_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef_decode_output_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_output_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_decode_output_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_decode_output_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_decode_output_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.decode_output_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_decode_output_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_output_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_decode_output_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_decode_output_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_decode_output_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.decode_output_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_decode_output_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_output_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_decode_output_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_decode_output_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.decode_output_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_decode_output_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_output_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
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
    cpy_r_r1 = CPyDef_decode_output_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
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

PyObject *CPyPy_decode_output_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_decode_output_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.decode_output_gen", obj___mypyc_self__); 
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
    PyObject *retval = CPyDef_decode_output_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_output_gen___close(PyObject *cpy_r___mypyc_self__) {
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
    cpy_r_r1 = CPyStatics[31]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_decode_output_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[32]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp14 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp14);
    PyObject *__tmp15 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp15);
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

PyObject *CPyPy_decode_output_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_decode_output_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.decode_output_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_decode_output_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_output_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_decode_output_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_decode_output_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call.decode_output_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_decode_output_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_decode_output(PyObject *cpy_r_call, PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    cpy_r_r0 = CPyDef_decode_output_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_call);
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_call != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_call);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_call = cpy_r_call;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_data);
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_data);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_data = cpy_r_data;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r3 = CPyDef_decode_output_gen();
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___brownie_patch___call___decode_output_genObject *)cpy_r_r3)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_genObject *)cpy_r_r3)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___decode_output_genObject *)cpy_r_r3)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL9;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r5 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL10;
    }
    return cpy_r_r3;
CPyL7: ;
    cpy_r_r6 = NULL;
    return cpy_r_r6;
CPyL8: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL7;
CPyL9: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r3);
    goto CPyL7;
CPyL10: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL7;
}

PyObject *CPyPy_decode_output(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"call", "data", 0};
    static CPyArg_Parser parser = {"OO:decode_output", kwlist, 0};
    PyObject *obj_call;
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_call, &obj_data)) {
        return NULL;
    }
    PyObject *arg_call = obj_call;
    PyObject *arg_data;
    if (likely(PyBytes_Check(obj_data) || PyByteArray_Check(obj_data)))
        arg_data = obj_data;
    else {
        CPy_TypeError("bytes", obj_data); 
        goto fail;
    }
    PyObject *retval = CPyDef_decode_output(arg_call, arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__request_data_no_args_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    cpy_r_r0 = ((dank_mids___brownie_patch___call____request_data_no_args_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_request_data_no_args", "_request_data_no_args_gen", "__mypyc_env__", 228, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_request_data_no_args", "_request_data_no_args_env", "__mypyc_next_label__", 228, CPyStatic_globals);
        goto CPyL14;
    }
    CPyTagged_INCREF(cpy_r_r1);
    goto CPyL10;
CPyL2: ;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = cpy_r_type != cpy_r_r2;
    if (cpy_r_r3) {
        goto CPyL15;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r4 = ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->_call;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_request_data_no_args", "_request_data_no_args_env", "call", 229, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_INCREF(cpy_r_r4);
CPyL6: ;
    cpy_r_r5 = CPyStatics[6]; /* 'signature' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 229, CPyStatic_globals);
        goto CPyL14;
    }
    if (((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__ = -2;
    cpy_r_r7 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 229, CPyStatic_globals);
        goto CPyL16;
    }
    CPyGen_SetStopIterationValue(cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    if (!0) goto CPyL13;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r8 = cpy_r_r1 == 0;
    CPyTagged_DECREF(cpy_r_r1);
    if (cpy_r_r8) {
        goto CPyL2;
    } else
        goto CPyL17;
CPyL11: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r9 = 0;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL13: ;
    cpy_r_r10 = NULL;
    return cpy_r_r10;
CPyL14: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL13;
CPyL15: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL3;
CPyL16: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL13;
CPyL17: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL11;
}

PyObject *CPyPy__request_data_no_args_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef__request_data_no_args_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__request_data_no_args_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__request_data_no_args_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__request_data_no_args_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__request_data_no_args_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._request_data_no_args_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__request_data_no_args_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__request_data_no_args_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__request_data_no_args_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__request_data_no_args_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__request_data_no_args_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._request_data_no_args_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__request_data_no_args_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__request_data_no_args_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__request_data_no_args_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__request_data_no_args_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._request_data_no_args_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__request_data_no_args_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__request_data_no_args_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
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
    cpy_r_r1 = CPyDef__request_data_no_args_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
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

PyObject *CPyPy__request_data_no_args_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__request_data_no_args_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._request_data_no_args_gen", obj___mypyc_self__); 
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
    PyObject *retval = CPyDef__request_data_no_args_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__request_data_no_args_gen___close(PyObject *cpy_r___mypyc_self__) {
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
    cpy_r_r1 = CPyStatics[31]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef__request_data_no_args_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[32]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp16 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp16);
    PyObject *__tmp17 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp17);
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

PyObject *CPyPy__request_data_no_args_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__request_data_no_args_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._request_data_no_args_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__request_data_no_args_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__request_data_no_args_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__request_data_no_args_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__request_data_no_args_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._request_data_no_args_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__request_data_no_args_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__request_data_no_args(PyObject *cpy_r_call) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    cpy_r_r0 = CPyDef__request_data_no_args_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_call);
    if (((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->_call != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->_call);
    }
    ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->_call = cpy_r_call;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r2 = CPyDef__request_data_no_args_gen();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___brownie_patch___call____request_data_no_args_genObject *)cpy_r_r2)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____request_data_no_args_genObject *)cpy_r_r2)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call____request_data_no_args_genObject *)cpy_r_r2)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
        goto CPyL8;
    }
    if (((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r4 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
        goto CPyL9;
    }
    return cpy_r_r2;
CPyL6: ;
    cpy_r_r5 = NULL;
    return cpy_r_r5;
CPyL7: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL6;
CPyL8: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    goto CPyL6;
CPyL9: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL6;
}

PyObject *CPyPy__request_data_no_args(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"call", 0};
    static CPyArg_Parser parser = {"O:_request_data_no_args", kwlist, 0};
    PyObject *obj_call;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_call)) {
        return NULL;
    }
    PyObject *arg_call = obj_call;
    PyObject *retval = CPyDef__request_data_no_args(arg_call);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 228, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___encode_input(PyObject *cpy_r_abi, PyObject *cpy_r_signature, PyObject *cpy_r_args) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    tuple_T3OOO cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    cpy_r_r0 = CPyDef_format_input_but_cache_checksums(cpy_r_abi, cpy_r_args);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 243, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r1 = CPyStatics[13]; /* 'inputs' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_abi, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 244, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r3 = CPyStatic_globals;
    cpy_r_r4 = CPyStatics[48]; /* 'get_type_strings' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 244, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r6[1] = {cpy_r_r2};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = _PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 244, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r9 = CPyStatic___eth_abi_encode;
    if (unlikely(cpy_r_r9 == NULL)) {
        goto CPyL24;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"__eth_abi_encode\" was not set");
    cpy_r_r10 = 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 245, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_Unreachable();
CPyL8: ;
    PyObject *cpy_r_r11[2] = {cpy_r_r8, cpy_r_r0};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r12, 2, 0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 245, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r0);
    if (likely(PyBytes_Check(cpy_r_r13) || PyByteArray_Check(cpy_r_r13)))
        cpy_r_r14 = cpy_r_r13;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 245, CPyStatic_globals, "bytes", cpy_r_r13);
        goto CPyL14;
    }
    cpy_r_r15 = CPyStatics[49]; /* 'hex' */
    PyObject *cpy_r_r16[1] = {cpy_r_r14};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_VectorcallMethod(cpy_r_r15, cpy_r_r17, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 245, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_DECREF(cpy_r_r14);
    if (likely(PyUnicode_Check(cpy_r_r18)))
        cpy_r_r19 = cpy_r_r18;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 245, CPyStatic_globals, "str", cpy_r_r18);
        goto CPyL14;
    }
    cpy_r_r20 = PyUnicode_Concat(cpy_r_signature, cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 245, CPyStatic_globals);
        goto CPyL14;
    }
    return cpy_r_r20;
CPyL14: ;
    cpy_r_r21 = CPy_CatchError();
    cpy_r_r22 = CPyModule_builtins;
    cpy_r_r23 = CPyStatics[43]; /* 'Exception' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 246, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r25 = CPy_ExceptionMatches(cpy_r_r24);
    CPy_DecRef(cpy_r_r24);
    if (!cpy_r_r25) goto CPyL17;
    cpy_r_r26 = CPy_GetExcValue();
    CPy_RestoreExcInfo(cpy_r_r21);
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    return cpy_r_r26;
CPyL17: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL19;
    } else
        goto CPyL27;
CPyL18: ;
    CPy_Unreachable();
CPyL19: ;
    CPy_RestoreExcInfo(cpy_r_r21);
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    cpy_r_r27 = CPy_KeepPropagating();
    if (!cpy_r_r27) goto CPyL21;
    CPy_Unreachable();
CPyL21: ;
    cpy_r_r28 = NULL;
    return cpy_r_r28;
CPyL22: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL14;
CPyL23: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    goto CPyL14;
CPyL24: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    goto CPyL6;
CPyL25: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    goto CPyL14;
CPyL26: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL14;
CPyL27: ;
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    goto CPyL18;
}

PyObject *CPyPy___encode_input(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi", "signature", 0};
    static CPyArg_Parser parser = {"%OO:__encode_input", kwlist, 0};
    PyObject *obj_abi;
    PyObject *obj_signature;
    PyObject *obj_args;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_args, NULL, &obj_abi, &obj_signature)) {
        return NULL;
    }
    PyObject *arg_abi;
    if (likely(PyDict_Check(obj_abi)))
        arg_abi = obj_abi;
    else {
        CPy_TypeError("dict", obj_abi); 
        goto fail;
    }
    PyObject *arg_signature;
    if (likely(PyUnicode_Check(obj_signature)))
        arg_signature = obj_signature;
    else {
        CPy_TypeError("str", obj_signature); 
        goto fail;
    }
    PyObject *arg_args = obj_args;
    PyObject *retval = CPyDef___encode_input(arg_abi, arg_signature, arg_args);
    CPy_DECREF(obj_args);
    return retval;
fail: ;
    CPy_DECREF(obj_args);
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 241, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___decode_output(PyObject *cpy_r_hexstr, PyObject *cpy_r_abi) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_result;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    CPyPtr cpy_r_r21;
    int64_t cpy_r_r22;
    CPyTagged cpy_r_r23;
    char cpy_r_r24;
    tuple_T1O cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    tuple_T3OOO cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    cpy_r_r0 = CPyStatics[50]; /* 'outputs' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_abi, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 265, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[48]; /* 'get_type_strings' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 265, CPyStatic_globals);
        goto CPyL28;
    }
    PyObject *cpy_r_r5[1] = {cpy_r_r1};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 265, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_DECREF(cpy_r_r1);
    cpy_r_r8 = CPyStatic_HexBytes;
    if (unlikely(cpy_r_r8 == NULL)) {
        goto CPyL29;
    } else
        goto CPyL7;
CPyL5: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"HexBytes\" was not set");
    cpy_r_r9 = 0;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 266, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_Unreachable();
CPyL7: ;
    PyObject *cpy_r_r10[1] = {cpy_r_hexstr};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = _PyObject_Vectorcall(cpy_r_r8, cpy_r_r11, 1, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 266, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r13 = CPyStatic___eth_abi_decode;
    if (unlikely(cpy_r_r13 == NULL)) {
        goto CPyL31;
    } else
        goto CPyL11;
CPyL9: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"__eth_abi_decode\" was not set");
    cpy_r_r14 = 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 266, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_Unreachable();
CPyL11: ;
    PyObject *cpy_r_r15[2] = {cpy_r_r7, cpy_r_r12};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r13, cpy_r_r16, 2, 0);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 266, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r12);
    if (likely(PyTuple_Check(cpy_r_r17)))
        cpy_r_r18 = cpy_r_r17;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 266, CPyStatic_globals, "tuple", cpy_r_r17);
        goto CPyL20;
    }
    cpy_r_result = cpy_r_r18;
    cpy_r_r19 = CPyDef_format_output_but_cache_checksums(cpy_r_abi, cpy_r_result);
    CPy_DECREF(cpy_r_result);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 267, CPyStatic_globals);
        goto CPyL20;
    }
    if (likely(PyTuple_Check(cpy_r_r19)))
        cpy_r_r20 = cpy_r_r19;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 267, CPyStatic_globals, "tuple", cpy_r_r19);
        goto CPyL20;
    }
    cpy_r_result = cpy_r_r20;
    cpy_r_r21 = (CPyPtr)&((PyVarObject *)cpy_r_result)->ob_size;
    cpy_r_r22 = *(int64_t *)cpy_r_r21;
    cpy_r_r23 = cpy_r_r22 << 1;
    cpy_r_r24 = cpy_r_r23 == 2;
    if (!cpy_r_r24) goto CPyL18;
    PyObject *__tmp18;
    if (unlikely(!(PyTuple_Check(cpy_r_result) && PyTuple_GET_SIZE(cpy_r_result) == 1))) {
        __tmp18 = NULL;
        goto __LL19;
    }
    __tmp18 = PyTuple_GET_ITEM(cpy_r_result, 0);
    if (__tmp18 == NULL) goto __LL19;
    __tmp18 = cpy_r_result;
__LL19: ;
    if (unlikely(__tmp18 == NULL)) {
        CPy_TypeError("tuple[object]", cpy_r_result); cpy_r_r25 = (tuple_T1O) { NULL };
    } else {
        PyObject *__tmp20 = PyTuple_GET_ITEM(cpy_r_result, 0);
        CPy_INCREF(__tmp20);
        PyObject *__tmp21;
        __tmp21 = __tmp20;
        cpy_r_r25.f0 = __tmp21;
    }
    CPy_DECREF(cpy_r_result);
    if (unlikely(cpy_r_r25.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 268, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r26 = cpy_r_r25.f0;
    CPy_INCREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r25.f0);
    cpy_r_r27 = cpy_r_r26;
    goto CPyL19;
CPyL18: ;
    cpy_r_r27 = cpy_r_result;
CPyL19: ;
    return cpy_r_r27;
CPyL20: ;
    cpy_r_r28 = CPy_CatchError();
    cpy_r_r29 = CPyModule_builtins;
    cpy_r_r30 = CPyStatics[43]; /* 'Exception' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 269, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r32 = CPy_ExceptionMatches(cpy_r_r31);
    CPy_DecRef(cpy_r_r31);
    if (!cpy_r_r32) goto CPyL23;
    cpy_r_r33 = CPy_GetExcValue();
    CPy_RestoreExcInfo(cpy_r_r28);
    CPy_DecRef(cpy_r_r28.f0);
    CPy_DecRef(cpy_r_r28.f1);
    CPy_DecRef(cpy_r_r28.f2);
    return cpy_r_r33;
CPyL23: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL25;
    } else
        goto CPyL33;
CPyL24: ;
    CPy_Unreachable();
CPyL25: ;
    CPy_RestoreExcInfo(cpy_r_r28);
    CPy_DecRef(cpy_r_r28.f0);
    CPy_DecRef(cpy_r_r28.f1);
    CPy_DecRef(cpy_r_r28.f2);
    cpy_r_r34 = CPy_KeepPropagating();
    if (!cpy_r_r34) goto CPyL27;
    CPy_Unreachable();
CPyL27: ;
    cpy_r_r35 = NULL;
    return cpy_r_r35;
CPyL28: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL20;
CPyL29: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL5;
CPyL30: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL20;
CPyL31: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r12);
    goto CPyL9;
CPyL32: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r12);
    goto CPyL20;
CPyL33: ;
    CPy_DecRef(cpy_r_r28.f0);
    CPy_DecRef(cpy_r_r28.f1);
    CPy_DecRef(cpy_r_r28.f2);
    goto CPyL24;
}

PyObject *CPyPy___decode_output(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"hexstr", "abi", 0};
    static CPyArg_Parser parser = {"OO:__decode_output", kwlist, 0};
    PyObject *obj_hexstr;
    PyObject *obj_abi;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_hexstr, &obj_abi)) {
        return NULL;
    }
    PyObject *arg_hexstr = obj_hexstr;
    PyObject *arg_abi;
    if (likely(PyDict_Check(obj_abi)))
        arg_abi = obj_abi;
    else {
        CPy_TypeError("dict", obj_abi); 
        goto fail;
    }
    PyObject *retval = CPyDef___decode_output(arg_hexstr, arg_abi);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 263, CPyStatic_globals);
    return NULL;
}

char CPyDef___validate_output(PyObject *cpy_r_abi, PyObject *cpy_r_hexstr) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    int32_t cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    CPyPtr cpy_r_r24;
    CPyPtr cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject **cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_revert_str;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    char cpy_r_r46;
    PyObject **cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    int32_t cpy_r_r52;
    char cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    PyObject **cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    CPyTagged cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    int32_t cpy_r_r79;
    char cpy_r_r80;
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
    char cpy_r_r95;
    PyObject **cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    int32_t cpy_r_r101;
    char cpy_r_r102;
    char cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    char cpy_r_r106;
    PyObject **cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    int32_t cpy_r_r112;
    char cpy_r_r113;
    char cpy_r_r114;
    int32_t cpy_r_r115;
    char cpy_r_r116;
    char cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    char cpy_r_r120;
    PyObject **cpy_r_r122;
    PyObject *cpy_r_r123;
    tuple_T3OOO cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    char cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject **cpy_r_r134;
    PyObject *cpy_r_r135;
    tuple_T3OOO cpy_r_r136;
    char cpy_r_r137;
    char cpy_r_r138;
    char cpy_r_r139;
    cpy_r_r0 = CPyStatic_HexBytes;
    if (likely(cpy_r_r0 != NULL)) goto CPyL4;
    PyErr_SetString(PyExc_NameError, "value for final name \"HexBytes\" was not set");
    cpy_r_r1 = 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 275, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL4: ;
    PyObject *cpy_r_r2[1] = {cpy_r_hexstr};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = _PyObject_Vectorcall(cpy_r_r0, cpy_r_r3, 1, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 275, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r5 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r6 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r7 = CPyStatics[193]; /* 4 */
    cpy_r_r8 = PySlice_New(cpy_r_r5, cpy_r_r7, cpy_r_r6);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 275, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r9 = PyObject_GetItem(cpy_r_r4, cpy_r_r8);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 275, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r10 = CPyStatics[49]; /* 'hex' */
    PyObject *cpy_r_r11[1] = {cpy_r_r9};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_VectorcallMethod(cpy_r_r10, cpy_r_r12, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 275, CPyStatic_globals);
        goto CPyL96;
    }
    CPy_DECREF(cpy_r_r9);
    cpy_r_r14 = CPyStatics[51]; /* '0x08c379a0' */
    cpy_r_r15 = PyObject_RichCompare(cpy_r_r13, cpy_r_r14, 2);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 276, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r16 = PyObject_IsTrue(cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    cpy_r_r17 = cpy_r_r16 >= 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 276, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r18 = cpy_r_r16;
    if (cpy_r_r18) {
        goto CPyL98;
    } else
        goto CPyL29;
CPyL11: ;
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyStatics[52]; /* 'eth_abi' */
    cpy_r_r21 = CPyDict_GetItem(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 277, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r22 = CPyStatics[53]; /* 'string' */
    cpy_r_r23 = PyList_New(1);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 277, CPyStatic_globals);
        goto CPyL99;
    }
    cpy_r_r24 = (CPyPtr)&((PyListObject *)cpy_r_r23)->ob_item;
    cpy_r_r25 = *(CPyPtr *)cpy_r_r24;
    CPy_INCREF(cpy_r_r22);
    *(PyObject * *)cpy_r_r25 = cpy_r_r22;
    cpy_r_r26 = CPyStatic_HexBytes;
    if (unlikely(cpy_r_r26 == NULL)) {
        goto CPyL100;
    } else
        goto CPyL16;
CPyL14: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"HexBytes\" was not set");
    cpy_r_r27 = 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 277, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL16: ;
    PyObject *cpy_r_r28[1] = {cpy_r_hexstr};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r26, cpy_r_r29, 1, 0);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 277, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r31 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r32 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r33 = CPyStatics[193]; /* 4 */
    cpy_r_r34 = PySlice_New(cpy_r_r33, cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 277, CPyStatic_globals);
        goto CPyL102;
    }
    cpy_r_r35 = PyObject_GetItem(cpy_r_r30, cpy_r_r34);
    CPy_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 277, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r36 = CPyStatics[54]; /* 'decode_abi' */
    PyObject *cpy_r_r37[3] = {cpy_r_r21, cpy_r_r23, cpy_r_r35};
    cpy_r_r38 = (PyObject **)&cpy_r_r37;
    cpy_r_r39 = PyObject_VectorcallMethod(cpy_r_r36, cpy_r_r38, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 277, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r35);
    cpy_r_r40 = CPyStatics[194]; /* 0 */
    cpy_r_r41 = PyObject_GetItem(cpy_r_r39, cpy_r_r40);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 277, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_revert_str = cpy_r_r41;
    cpy_r_r42 = CPyStatics[55]; /* 'Call reverted: ' */
    cpy_r_r43 = PyObject_Str(cpy_r_revert_str);
    CPy_DECREF(cpy_r_revert_str);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 278, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r44 = CPyStr_Build(2, cpy_r_r42, cpy_r_r43);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 278, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r45 = CPyStatic_Revert;
    if (unlikely(cpy_r_r45 == NULL)) {
        goto CPyL104;
    } else
        goto CPyL26;
CPyL24: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"Revert\" was not set");
    cpy_r_r46 = 0;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 278, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL26: ;
    PyObject *cpy_r_r47[1] = {cpy_r_r44};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r48, 1, 0);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 278, CPyStatic_globals);
        goto CPyL105;
    }
    CPy_DECREF(cpy_r_r44);
    CPy_Raise(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 278, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL29: ;
    cpy_r_r50 = CPyStatics[56]; /* '0x4e487b71' */
    cpy_r_r51 = PyObject_RichCompare(cpy_r_r13, cpy_r_r50, 2);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 279, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r52 = PyObject_IsTrue(cpy_r_r51);
    CPy_DECREF(cpy_r_r51);
    cpy_r_r53 = cpy_r_r52 >= 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 279, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r54 = cpy_r_r52;
    if (cpy_r_r54) {
        goto CPyL106;
    } else
        goto CPyL58;
CPyL32: ;
    cpy_r_r55 = CPyStatic_HexBytes;
    if (likely(cpy_r_r55 != NULL)) goto CPyL35;
    PyErr_SetString(PyExc_NameError, "value for final name \"HexBytes\" was not set");
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 280, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL35: ;
    PyObject *cpy_r_r57[1] = {cpy_r_hexstr};
    cpy_r_r58 = (PyObject **)&cpy_r_r57;
    cpy_r_r59 = _PyObject_Vectorcall(cpy_r_r55, cpy_r_r58, 1, 0);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 280, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r60 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r61 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r62 = CPyStatics[193]; /* 4 */
    cpy_r_r63 = PySlice_New(cpy_r_r62, cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 280, CPyStatic_globals);
        goto CPyL107;
    }
    cpy_r_r64 = PyObject_GetItem(cpy_r_r59, cpy_r_r63);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 280, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r65 = CPyStatics[49]; /* 'hex' */
    PyObject *cpy_r_r66[1] = {cpy_r_r64};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = PyObject_VectorcallMethod(cpy_r_r65, cpy_r_r67, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 280, CPyStatic_globals);
        goto CPyL108;
    }
    CPy_DECREF(cpy_r_r64);
    cpy_r_r69 = (PyObject *)&PyLong_Type;
    cpy_r_r70 = CPyStatics[195]; /* 16 */
    PyObject *cpy_r_r71[2] = {cpy_r_r68, cpy_r_r70};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = _PyObject_Vectorcall(cpy_r_r69, cpy_r_r72, 2, 0);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 280, CPyStatic_globals);
        goto CPyL109;
    }
    CPy_DECREF(cpy_r_r68);
    if (likely(PyLong_Check(cpy_r_r73)))
        cpy_r_r74 = CPyTagged_FromObject(cpy_r_r73);
    else {
        CPy_TypeError("int", cpy_r_r73); cpy_r_r74 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r73);
    if (unlikely(cpy_r_r74 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 280, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r75 = CPyStatic_globals;
    cpy_r_r76 = CPyStatics[57]; /* 'SOLIDITY_ERROR_CODES' */
    cpy_r_r77 = CPyDict_GetItem(cpy_r_r75, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 281, CPyStatic_globals);
        goto CPyL110;
    }
    CPyTagged_INCREF(cpy_r_r74);
    cpy_r_r78 = CPyTagged_StealAsObject(cpy_r_r74);
    cpy_r_r79 = PySequence_Contains(cpy_r_r77, cpy_r_r78);
    CPy_DECREF(cpy_r_r77);
    CPy_DECREF(cpy_r_r78);
    cpy_r_r80 = cpy_r_r79 >= 0;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 281, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r81 = cpy_r_r79;
    if (!cpy_r_r81) goto CPyL47;
    cpy_r_r82 = CPyStatic_globals;
    cpy_r_r83 = CPyStatics[57]; /* 'SOLIDITY_ERROR_CODES' */
    cpy_r_r84 = CPyDict_GetItem(cpy_r_r82, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 282, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r85 = CPyTagged_StealAsObject(cpy_r_r74);
    cpy_r_r86 = PyObject_GetItem(cpy_r_r84, cpy_r_r85);
    CPy_DECREF(cpy_r_r84);
    CPy_DECREF(cpy_r_r85);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 282, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_revert_str = cpy_r_r86;
    goto CPyL50;
CPyL47: ;
    cpy_r_r87 = CPyStatics[58]; /* 'Panic (error code: ' */
    cpy_r_r88 = CPyTagged_Str(cpy_r_r74);
    CPyTagged_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 284, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r89 = CPyStatics[59]; /* ')' */
    cpy_r_r90 = CPyStr_Build(3, cpy_r_r87, cpy_r_r88, cpy_r_r89);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 284, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_revert_str = cpy_r_r90;
CPyL50: ;
    cpy_r_r91 = CPyStatics[55]; /* 'Call reverted: ' */
    cpy_r_r92 = PyObject_Str(cpy_r_revert_str);
    CPy_DECREF(cpy_r_revert_str);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 285, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r93 = CPyStr_Build(2, cpy_r_r91, cpy_r_r92);
    CPy_DECREF(cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 285, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r94 = CPyStatic_Revert;
    if (unlikely(cpy_r_r94 == NULL)) {
        goto CPyL111;
    } else
        goto CPyL55;
CPyL53: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"Revert\" was not set");
    cpy_r_r95 = 0;
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 285, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL55: ;
    PyObject *cpy_r_r96[1] = {cpy_r_r93};
    cpy_r_r97 = (PyObject **)&cpy_r_r96;
    cpy_r_r98 = _PyObject_Vectorcall(cpy_r_r94, cpy_r_r97, 1, 0);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 285, CPyStatic_globals);
        goto CPyL112;
    }
    CPy_DECREF(cpy_r_r93);
    CPy_Raise(cpy_r_r98);
    CPy_DECREF(cpy_r_r98);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 285, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL58: ;
    cpy_r_r99 = CPyStatics[60]; /* '0xc1b84b2f' */
    cpy_r_r100 = PyObject_RichCompare(cpy_r_r13, cpy_r_r99, 2);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 286, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r101 = PyObject_IsTrue(cpy_r_r100);
    CPy_DECREF(cpy_r_r100);
    cpy_r_r102 = cpy_r_r101 >= 0;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 286, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r103 = cpy_r_r101;
    if (!cpy_r_r103) goto CPyL67;
    cpy_r_r104 = CPyStatics[61]; /* 'Call reverted: execution reverted' */
    cpy_r_r105 = CPyStatic_Revert;
    if (likely(cpy_r_r105 != NULL)) goto CPyL64;
    PyErr_SetString(PyExc_NameError, "value for final name \"Revert\" was not set");
    cpy_r_r106 = 0;
    if (unlikely(!cpy_r_r106)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 287, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL64: ;
    PyObject *cpy_r_r107[1] = {cpy_r_r104};
    cpy_r_r108 = (PyObject **)&cpy_r_r107;
    cpy_r_r109 = _PyObject_Vectorcall(cpy_r_r105, cpy_r_r108, 1, 0);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 287, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Raise(cpy_r_r109);
    CPy_DECREF(cpy_r_r109);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 287, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL67: ;
    cpy_r_r110 = CPyStatics[50]; /* 'outputs' */
    cpy_r_r111 = CPyDict_GetItem(cpy_r_abi, cpy_r_r110);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 288, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r112 = PyObject_IsTrue(cpy_r_r111);
    CPy_DECREF(cpy_r_r111);
    cpy_r_r113 = cpy_r_r112 >= 0;
    if (unlikely(!cpy_r_r113)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 288, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r114 = cpy_r_r112;
    if (!cpy_r_r114) goto CPyL93;
    cpy_r_r115 = PyObject_IsTrue(cpy_r_hexstr);
    cpy_r_r116 = cpy_r_r115 >= 0;
    if (unlikely(!cpy_r_r116)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 273, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r117 = cpy_r_r115;
    if (cpy_r_r117) goto CPyL93;
    cpy_r_r118 = CPyStatics[62]; /* 'No data was returned - the call likely reverted' */
    cpy_r_r119 = CPyStatic_Revert;
    if (likely(cpy_r_r119 != NULL)) goto CPyL75;
    PyErr_SetString(PyExc_NameError, "value for final name \"Revert\" was not set");
    cpy_r_r120 = 0;
    if (unlikely(!cpy_r_r120)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 289, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL75: ;
    PyObject *cpy_r_r121[1] = {cpy_r_r118};
    cpy_r_r122 = (PyObject **)&cpy_r_r121;
    cpy_r_r123 = _PyObject_Vectorcall(cpy_r_r119, cpy_r_r122, 1, 0);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 289, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Raise(cpy_r_r123);
    CPy_DECREF(cpy_r_r123);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 289, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL78: ;
    cpy_r_r124 = CPy_CatchError();
    cpy_r_r125 = CPyModule_builtins;
    cpy_r_r126 = CPyStatics[20]; /* 'ValueError' */
    cpy_r_r127 = CPyObject_GetAttr(cpy_r_r125, cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 290, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r128 = CPy_ExceptionMatches(cpy_r_r127);
    CPy_DecRef(cpy_r_r127);
    if (!cpy_r_r128) goto CPyL89;
    cpy_r_r129 = CPy_GetExcValue();
    cpy_r_r130 = CPyStatic_globals;
    cpy_r_r131 = CPyStatics[63]; /* 'VirtualMachineError' */
    cpy_r_r132 = CPyDict_GetItem(cpy_r_r130, cpy_r_r131);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 292, CPyStatic_globals);
        goto CPyL85;
    }
    PyObject *cpy_r_r133[1] = {cpy_r_r129};
    cpy_r_r134 = (PyObject **)&cpy_r_r133;
    cpy_r_r135 = _PyObject_Vectorcall(cpy_r_r132, cpy_r_r134, 1, 0);
    CPy_DecRef(cpy_r_r132);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 292, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_Raise(cpy_r_r135);
    CPy_DecRef(cpy_r_r135);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 292, CPyStatic_globals);
        goto CPyL85;
    } else
        goto CPyL113;
CPyL84: ;
    CPy_Unreachable();
CPyL85: ;
    cpy_r_r136 = CPy_CatchError();
    CPy_Raise(cpy_r_r129);
    CPy_DecRef(cpy_r_r129);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 294, CPyStatic_globals);
        goto CPyL87;
    } else
        goto CPyL114;
CPyL86: ;
    CPy_Unreachable();
CPyL87: ;
    CPy_RestoreExcInfo(cpy_r_r136);
    CPy_DecRef(cpy_r_r136.f0);
    CPy_DecRef(cpy_r_r136.f1);
    CPy_DecRef(cpy_r_r136.f2);
    cpy_r_r137 = CPy_KeepPropagating();
    if (!cpy_r_r137) {
        goto CPyL91;
    } else
        goto CPyL115;
CPyL88: ;
    CPy_Unreachable();
CPyL89: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL91;
    } else
        goto CPyL116;
CPyL90: ;
    CPy_Unreachable();
CPyL91: ;
    CPy_RestoreExcInfo(cpy_r_r124);
    CPy_DecRef(cpy_r_r124.f0);
    CPy_DecRef(cpy_r_r124.f1);
    CPy_DecRef(cpy_r_r124.f2);
    cpy_r_r138 = CPy_KeepPropagating();
    if (!cpy_r_r138) goto CPyL94;
    CPy_Unreachable();
CPyL93: ;
    return 1;
CPyL94: ;
    cpy_r_r139 = 2;
    return cpy_r_r139;
CPyL95: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL78;
CPyL96: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL78;
CPyL97: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL78;
CPyL98: ;
    CPy_DECREF(cpy_r_r13);
    goto CPyL11;
CPyL99: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL78;
CPyL100: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r23);
    goto CPyL14;
CPyL101: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r23);
    goto CPyL78;
CPyL102: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r30);
    goto CPyL78;
CPyL103: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r35);
    goto CPyL78;
CPyL104: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL24;
CPyL105: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL78;
CPyL106: ;
    CPy_DECREF(cpy_r_r13);
    goto CPyL32;
CPyL107: ;
    CPy_DecRef(cpy_r_r59);
    goto CPyL78;
CPyL108: ;
    CPy_DecRef(cpy_r_r64);
    goto CPyL78;
CPyL109: ;
    CPy_DecRef(cpy_r_r68);
    goto CPyL78;
CPyL110: ;
    CPyTagged_DecRef(cpy_r_r74);
    goto CPyL78;
CPyL111: ;
    CPy_DecRef(cpy_r_r93);
    goto CPyL53;
CPyL112: ;
    CPy_DecRef(cpy_r_r93);
    goto CPyL78;
CPyL113: ;
    CPy_DecRef(cpy_r_r124.f0);
    CPy_DecRef(cpy_r_r124.f1);
    CPy_DecRef(cpy_r_r124.f2);
    CPy_DecRef(cpy_r_r129);
    goto CPyL84;
CPyL114: ;
    CPy_DecRef(cpy_r_r124.f0);
    CPy_DecRef(cpy_r_r124.f1);
    CPy_DecRef(cpy_r_r124.f2);
    CPy_DecRef(cpy_r_r136.f0);
    CPy_DecRef(cpy_r_r136.f1);
    CPy_DecRef(cpy_r_r136.f2);
    goto CPyL86;
CPyL115: ;
    CPy_DecRef(cpy_r_r124.f0);
    CPy_DecRef(cpy_r_r124.f1);
    CPy_DecRef(cpy_r_r124.f2);
    goto CPyL88;
CPyL116: ;
    CPy_DecRef(cpy_r_r124.f0);
    CPy_DecRef(cpy_r_r124.f1);
    CPy_DecRef(cpy_r_r124.f2);
    goto CPyL90;
}

PyObject *CPyPy___validate_output(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi", "hexstr", 0};
    static CPyArg_Parser parser = {"OO:__validate_output", kwlist, 0};
    PyObject *obj_abi;
    PyObject *obj_hexstr;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi, &obj_hexstr)) {
        return NULL;
    }
    PyObject *arg_abi;
    if (likely(PyDict_Check(obj_abi)))
        arg_abi = obj_abi;
    else {
        CPy_TypeError("dict", obj_abi); 
        goto fail;
    }
    PyObject *arg_hexstr = obj_hexstr;
    char retval = CPyDef___validate_output(arg_abi, arg_hexstr);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 273, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_format_input_but_cache_checksums(PyObject *cpy_r_abi, PyObject *cpy_r_inputs) {
    CPyTagged cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    CPyTagged cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    tuple_T3OOO cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    cpy_r_r0 = CPyObject_Size(cpy_r_inputs);
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 302, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r1 = cpy_r_r0 != 0;
    CPyTagged_DECREF(cpy_r_r0);
    if (!cpy_r_r1) goto CPyL12;
    cpy_r_r2 = CPyStatics[13]; /* 'inputs' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_abi, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 302, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r4 = CPyObject_Size(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 302, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r5 = cpy_r_r4 != 0;
    CPyTagged_DECREF(cpy_r_r4);
    if (cpy_r_r5) goto CPyL12;
    cpy_r_r6 = CPyStatics[64]; /* 'name' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_abi, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 303, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r8 = PyObject_Str(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 303, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r9 = CPyStatics[65]; /* ' requires no arguments' */
    cpy_r_r10 = CPyStr_Build(2, cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 303, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r11 = CPyModule_builtins;
    cpy_r_r12 = CPyStatics[36]; /* 'TypeError' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 303, CPyStatic_globals);
        goto CPyL34;
    }
    PyObject *cpy_r_r14[1] = {cpy_r_r10};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = _PyObject_Vectorcall(cpy_r_r13, cpy_r_r15, 1, 0);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 303, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_Raise(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 303, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r17 = CPyStatics[13]; /* 'inputs' */
    cpy_r_r18 = CPyDict_GetItem(cpy_r_abi, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 304, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r19 = CPyStatic__get_abi_types;
    if (unlikely(cpy_r_r19 == NULL)) {
        goto CPyL35;
    } else
        goto CPyL16;
CPyL14: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_get_abi_types\" was not set");
    cpy_r_r20 = 0;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 304, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_Unreachable();
CPyL16: ;
    PyObject *cpy_r_r21[1] = {cpy_r_r18};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r22, 1, 0);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 304, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_DECREF(cpy_r_r18);
    cpy_r_r24 = CPyDef__format_tuple_but_cache_checksums(cpy_r_r23, cpy_r_inputs);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 306, CPyStatic_globals);
        goto CPyL20;
    }
    return cpy_r_r24;
CPyL20: ;
    cpy_r_r25 = CPy_CatchError();
    cpy_r_r26 = CPyModule_builtins;
    cpy_r_r27 = CPyStatics[43]; /* 'Exception' */
    cpy_r_r28 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 307, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r29 = CPy_ExceptionMatches(cpy_r_r28);
    CPy_DecRef(cpy_r_r28);
    if (!cpy_r_r29) goto CPyL29;
    cpy_r_r30 = CPy_GetExcValue();
    cpy_r_r31 = PyObject_Type(cpy_r_r30);
    cpy_r_r32 = CPyStatics[64]; /* 'name' */
    cpy_r_r33 = CPyDict_GetItem(cpy_r_abi, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 308, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r34 = PyObject_Str(cpy_r_r33);
    CPy_DecRef(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 308, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r35 = CPyStatics[66]; /* ' ' */
    cpy_r_r36 = PyObject_Str(cpy_r_r30);
    CPy_DecRef(cpy_r_r30);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 308, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r37 = CPyStr_Build(3, cpy_r_r34, cpy_r_r35, cpy_r_r36);
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 308, CPyStatic_globals);
        goto CPyL39;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r37};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r31, cpy_r_r39, 1, 0);
    CPy_DecRef(cpy_r_r31);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 308, CPyStatic_globals);
        goto CPyL40;
    }
    CPy_DecRef(cpy_r_r37);
    CPy_Raise(cpy_r_r40);
    CPy_DecRef(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 308, CPyStatic_globals);
        goto CPyL31;
    } else
        goto CPyL41;
CPyL28: ;
    CPy_Unreachable();
CPyL29: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL31;
    } else
        goto CPyL42;
CPyL30: ;
    CPy_Unreachable();
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r25);
    CPy_DecRef(cpy_r_r25.f0);
    CPy_DecRef(cpy_r_r25.f1);
    CPy_DecRef(cpy_r_r25.f2);
    cpy_r_r41 = CPy_KeepPropagating();
    if (!cpy_r_r41) goto CPyL33;
    CPy_Unreachable();
CPyL33: ;
    cpy_r_r42 = NULL;
    return cpy_r_r42;
CPyL34: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL33;
CPyL35: ;
    CPy_DecRef(cpy_r_r18);
    goto CPyL14;
CPyL36: ;
    CPy_DecRef(cpy_r_r18);
    goto CPyL33;
CPyL37: ;
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r31);
    goto CPyL31;
CPyL38: ;
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r34);
    goto CPyL31;
CPyL39: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL31;
CPyL40: ;
    CPy_DecRef(cpy_r_r37);
    goto CPyL31;
CPyL41: ;
    CPy_DecRef(cpy_r_r25.f0);
    CPy_DecRef(cpy_r_r25.f1);
    CPy_DecRef(cpy_r_r25.f2);
    goto CPyL28;
CPyL42: ;
    CPy_DecRef(cpy_r_r25.f0);
    CPy_DecRef(cpy_r_r25.f1);
    CPy_DecRef(cpy_r_r25.f2);
    goto CPyL30;
}

PyObject *CPyPy_format_input_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi", "inputs", 0};
    static CPyArg_Parser parser = {"OO:format_input_but_cache_checksums", kwlist, 0};
    PyObject *obj_abi;
    PyObject *obj_inputs;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi, &obj_inputs)) {
        return NULL;
    }
    PyObject *arg_abi;
    if (likely(PyDict_Check(obj_abi)))
        arg_abi = obj_abi;
    else {
        CPy_TypeError("dict", obj_abi); 
        goto fail;
    }
    PyObject *arg_inputs;
    if (PyList_Check(obj_inputs))
        arg_inputs = obj_inputs;
    else {
        arg_inputs = NULL;
    }
    if (arg_inputs != NULL) goto __LL22;
    if (PyTuple_Check(obj_inputs))
        arg_inputs = obj_inputs;
    else {
        arg_inputs = NULL;
    }
    if (arg_inputs != NULL) goto __LL22;
    CPy_TypeError("union[list, tuple]", obj_inputs); 
    goto fail;
__LL22: ;
    PyObject *retval = CPyDef_format_input_but_cache_checksums(arg_abi, arg_inputs);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 300, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_format_output_but_cache_checksums(PyObject *cpy_r_abi, PyObject *cpy_r_outputs) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyStatics[50]; /* 'outputs' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_abi, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 315, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r2 = CPyStatic__get_abi_types;
    if (unlikely(cpy_r_r2 == NULL)) {
        goto CPyL13;
    } else
        goto CPyL4;
CPyL2: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_get_abi_types\" was not set");
    cpy_r_r3 = 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 315, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_Unreachable();
CPyL4: ;
    PyObject *cpy_r_r4[1] = {cpy_r_r1};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r5, 1, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 315, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_DECREF(cpy_r_r1);
    cpy_r_r7 = CPyDef__format_tuple_but_cache_checksums(cpy_r_r6, cpy_r_outputs);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 316, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r8 = CPyStatics[50]; /* 'outputs' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_abi, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 317, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r10 = CPyStatic_ReturnValue;
    if (unlikely(cpy_r_r10 == NULL)) {
        goto CPyL16;
    } else
        goto CPyL10;
CPyL8: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ReturnValue\" was not set");
    cpy_r_r11 = 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 317, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_Unreachable();
CPyL10: ;
    PyObject *cpy_r_r12[2] = {cpy_r_r7, cpy_r_r9};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r10, cpy_r_r13, 2, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 317, CPyStatic_globals);
        goto CPyL17;
    }
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r9);
    return cpy_r_r14;
CPyL12: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL13: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL2;
CPyL14: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL12;
CPyL15: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL12;
CPyL16: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r9);
    goto CPyL8;
CPyL17: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r9);
    goto CPyL12;
}

PyObject *CPyPy_format_output_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi", "outputs", 0};
    static CPyArg_Parser parser = {"OO:format_output_but_cache_checksums", kwlist, 0};
    PyObject *obj_abi;
    PyObject *obj_outputs;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi, &obj_outputs)) {
        return NULL;
    }
    PyObject *arg_abi;
    if (likely(PyDict_Check(obj_abi)))
        arg_abi = obj_abi;
    else {
        CPy_TypeError("dict", obj_abi); 
        goto fail;
    }
    PyObject *arg_outputs;
    if (PyList_Check(obj_outputs))
        arg_outputs = obj_outputs;
    else {
        arg_outputs = NULL;
    }
    if (arg_outputs != NULL) goto __LL23;
    if (PyTuple_Check(obj_outputs))
        arg_outputs = obj_outputs;
    else {
        arg_outputs = NULL;
    }
    if (arg_outputs != NULL) goto __LL23;
    CPy_TypeError("union[list, tuple]", obj_outputs); 
    goto fail;
__LL23: ;
    PyObject *retval = CPyDef_format_output_but_cache_checksums(arg_abi, arg_outputs);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 311, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__format_tuple_but_cache_checksums(PyObject *cpy_r_abi_types, PyObject *cpy_r_values) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    int32_t cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    int32_t cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    int32_t cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    int32_t cpy_r_r38;
    char cpy_r_r39;
    tuple_T3OOO cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    char cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    char cpy_r_r57;
    PyObject *cpy_r_r58;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r1 = CPyObject_Size(cpy_r_abi_types);
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 328, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r2 = CPyStatic__check_array;
    if (unlikely(cpy_r_r2 == NULL)) {
        goto CPyL47;
    } else
        goto CPyL5;
CPyL3: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_check_array\" was not set");
    cpy_r_r3 = 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 328, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r4 = CPyTagged_StealAsObject(cpy_r_r1);
    PyObject *cpy_r_r5[2] = {cpy_r_values, cpy_r_r4};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r6, 2, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 328, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL49;
CPyL6: ;
    CPy_DECREF(cpy_r_r4);
    cpy_r_r8 = PyObject_GetIter(cpy_r_abi_types);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 329, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r9 = PyObject_GetIter(cpy_r_values);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 329, CPyStatic_globals);
        goto CPyL50;
    }
CPyL8: ;
    cpy_r_r10 = PyIter_Next(cpy_r_r8);
    if (cpy_r_r10 == NULL) goto CPyL51;
    cpy_r_r11 = PyIter_Next(cpy_r_r9);
    if (cpy_r_r11 == NULL) goto CPyL52;
    cpy_r_r12 = CPyStatics[67]; /* 'is_array' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 331, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r14 = PyObject_IsTrue(cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    cpy_r_r15 = cpy_r_r14 >= 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 331, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r16 = cpy_r_r14;
    if (!cpy_r_r16) goto CPyL17;
    CPy_INCREF(cpy_r_r11);
    if (PyList_Check(cpy_r_r11))
        cpy_r_r17 = cpy_r_r11;
    else {
        cpy_r_r17 = NULL;
    }
    if (cpy_r_r17 != NULL) goto __LL24;
    if (PyTuple_Check(cpy_r_r11))
        cpy_r_r17 = cpy_r_r11;
    else {
        cpy_r_r17 = NULL;
    }
    if (cpy_r_r17 != NULL) goto __LL24;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 332, CPyStatic_globals, "union[list, tuple]", cpy_r_r11);
    goto CPyL53;
__LL24: ;
    cpy_r_r18 = CPyDef__format_array_but_cache_checksums(cpy_r_r10, cpy_r_r17);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 332, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r19 = PyList_Append(cpy_r_r0, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r20 = cpy_r_r19 >= 0;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 332, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL55;
CPyL17: ;
    cpy_r_r21 = CPyStatic_TupleType;
    if (unlikely(cpy_r_r21 == NULL)) {
        goto CPyL56;
    } else
        goto CPyL20;
CPyL18: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"TupleType\" was not set");
    cpy_r_r22 = 0;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 333, CPyStatic_globals);
        goto CPyL30;
    } else
        goto CPyL57;
CPyL19: ;
    CPy_Unreachable();
CPyL20: ;
    cpy_r_r23 = PyObject_IsInstance(cpy_r_r10, cpy_r_r21);
    cpy_r_r24 = cpy_r_r23 >= 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 333, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r25 = cpy_r_r23;
    if (!cpy_r_r25) goto CPyL26;
    cpy_r_r26 = CPyStatics[68]; /* 'components' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r26);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 334, CPyStatic_globals);
        goto CPyL54;
    }
    CPy_INCREF(cpy_r_r11);
    if (PyList_Check(cpy_r_r11))
        cpy_r_r28 = cpy_r_r11;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL25;
    if (PyTuple_Check(cpy_r_r11))
        cpy_r_r28 = cpy_r_r11;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL25;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 334, CPyStatic_globals, "union[list, tuple]", cpy_r_r11);
    goto CPyL58;
__LL25: ;
    cpy_r_r29 = CPyDef__format_tuple_but_cache_checksums(cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r27);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 334, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r30 = PyList_Append(cpy_r_r0, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    cpy_r_r31 = cpy_r_r30 >= 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 334, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL59;
CPyL26: ;
    cpy_r_r32 = CPyStatics[69]; /* 'to_type_str' */
    PyObject *cpy_r_r33[1] = {cpy_r_r10};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r34, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 336, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_r10);
    if (likely(PyUnicode_Check(cpy_r_r35)))
        cpy_r_r36 = cpy_r_r35;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 336, CPyStatic_globals, "str", cpy_r_r35);
        goto CPyL54;
    }
    cpy_r_r37 = CPyDef__format_single_but_cache_checksums(cpy_r_r36, cpy_r_r11);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 336, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r38 = PyList_Append(cpy_r_r0, cpy_r_r37);
    CPy_DECREF(cpy_r_r37);
    cpy_r_r39 = cpy_r_r38 >= 0;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 336, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL60;
CPyL30: ;
    cpy_r_r40 = CPy_CatchError();
    cpy_r_r41 = CPyModule_builtins;
    cpy_r_r42 = CPyStatics[43]; /* 'Exception' */
    cpy_r_r43 = CPyObject_GetAttr(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 337, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r44 = CPy_ExceptionMatches(cpy_r_r43);
    CPy_DecRef(cpy_r_r43);
    if (!cpy_r_r44) goto CPyL62;
    cpy_r_r45 = CPy_GetExcValue();
    cpy_r_r46 = PyObject_Type(cpy_r_r45);
    cpy_r_r47 = CPyStatics[70]; /* "'" */
    cpy_r_r48 = PyObject_Str(cpy_r_r11);
    CPy_DecRef(cpy_r_r11);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 338, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r49 = CPyStatics[71]; /* "' - " */
    cpy_r_r50 = PyObject_Str(cpy_r_r45);
    CPy_DecRef(cpy_r_r45);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 338, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r51 = CPyStr_Build(4, cpy_r_r47, cpy_r_r48, cpy_r_r49, cpy_r_r50);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 338, CPyStatic_globals);
        goto CPyL65;
    }
    PyObject *cpy_r_r52[1] = {cpy_r_r51};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = _PyObject_Vectorcall(cpy_r_r46, cpy_r_r53, 1, 0);
    CPy_DecRef(cpy_r_r46);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 338, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_DecRef(cpy_r_r51);
    CPy_Raise(cpy_r_r54);
    CPy_DecRef(cpy_r_r54);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 338, CPyStatic_globals);
        goto CPyL40;
    } else
        goto CPyL67;
CPyL37: ;
    CPy_Unreachable();
CPyL38: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL40;
    } else
        goto CPyL68;
CPyL39: ;
    CPy_Unreachable();
CPyL40: ;
    CPy_RestoreExcInfo(cpy_r_r40);
    CPy_DecRef(cpy_r_r40.f0);
    CPy_DecRef(cpy_r_r40.f1);
    CPy_DecRef(cpy_r_r40.f2);
    cpy_r_r55 = CPy_KeepPropagating();
    if (!cpy_r_r55) goto CPyL45;
    CPy_Unreachable();
CPyL42: ;
    cpy_r_r56 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 329, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r57 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 329, CPyStatic_globals);
        goto CPyL46;
    }
    return cpy_r_r0;
CPyL45: ;
    cpy_r_r58 = NULL;
    return cpy_r_r58;
CPyL46: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL45;
CPyL47: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    goto CPyL3;
CPyL48: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    goto CPyL45;
CPyL49: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL6;
CPyL50: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    goto CPyL45;
CPyL51: ;
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r9);
    goto CPyL42;
CPyL52: ;
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    goto CPyL42;
CPyL53: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    goto CPyL30;
CPyL54: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    goto CPyL30;
CPyL55: ;
    CPy_DECREF(cpy_r_r11);
    goto CPyL8;
CPyL56: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    goto CPyL18;
CPyL57: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL19;
CPyL58: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r27);
    goto CPyL30;
CPyL59: ;
    CPy_DECREF(cpy_r_r11);
    goto CPyL8;
CPyL60: ;
    CPy_DECREF(cpy_r_r11);
    goto CPyL8;
CPyL61: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL40;
CPyL62: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL38;
CPyL63: ;
    CPy_DecRef(cpy_r_r45);
    CPy_DecRef(cpy_r_r46);
    goto CPyL40;
CPyL64: ;
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r48);
    goto CPyL40;
CPyL65: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL40;
CPyL66: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL40;
CPyL67: ;
    CPy_DecRef(cpy_r_r40.f0);
    CPy_DecRef(cpy_r_r40.f1);
    CPy_DecRef(cpy_r_r40.f2);
    goto CPyL37;
CPyL68: ;
    CPy_DecRef(cpy_r_r40.f0);
    CPy_DecRef(cpy_r_r40.f1);
    CPy_DecRef(cpy_r_r40.f2);
    goto CPyL39;
}

PyObject *CPyPy__format_tuple_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_types", "values", 0};
    static CPyArg_Parser parser = {"OO:_format_tuple_but_cache_checksums", kwlist, 0};
    PyObject *obj_abi_types;
    PyObject *obj_values;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_types, &obj_values)) {
        return NULL;
    }
    PyObject *arg_abi_types = obj_abi_types;
    PyObject *arg_values;
    if (PyList_Check(obj_values))
        arg_values = obj_values;
    else {
        arg_values = NULL;
    }
    if (arg_values != NULL) goto __LL26;
    if (PyTuple_Check(obj_values))
        arg_values = obj_values;
    else {
        arg_values = NULL;
    }
    if (arg_values != NULL) goto __LL26;
    CPy_TypeError("union[list, tuple]", obj_values); 
    goto fail;
__LL26: ;
    PyObject *retval = CPyDef__format_tuple_but_cache_checksums(arg_abi_types, arg_values);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 324, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__format_array_but_cache_checksums(PyObject *cpy_r_abi_type, PyObject *cpy_r_values) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    CPyTagged cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    int32_t cpy_r_r31;
    char cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    int32_t cpy_r_r58;
    char cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    cpy_r_r0 = CPyStatics[72]; /* 'arrlist' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r2 = CPyStatics[196]; /* -1 */
    cpy_r_r3 = PyObject_GetItem(cpy_r_r1, cpy_r_r2);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r4 = CPyObject_Size(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r5 = cpy_r_r4 != 0;
    CPyTagged_DECREF(cpy_r_r4);
    if (!cpy_r_r5) goto CPyL8;
    cpy_r_r6 = CPyStatics[72]; /* 'arrlist' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r8 = CPyStatics[196]; /* -1 */
    cpy_r_r9 = PyObject_GetItem(cpy_r_r7, cpy_r_r8);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r10 = CPyStatics[194]; /* 0 */
    cpy_r_r11 = PyObject_GetItem(cpy_r_r9, cpy_r_r10);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r12 = cpy_r_r11;
    goto CPyL9;
CPyL8: ;
    cpy_r_r13 = Py_None;
    CPy_INCREF(cpy_r_r13);
    cpy_r_r12 = cpy_r_r13;
CPyL9: ;
    cpy_r_r14 = CPyStatic__check_array;
    if (unlikely(cpy_r_r14 == NULL)) {
        goto CPyL49;
    } else
        goto CPyL12;
CPyL10: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_check_array\" was not set");
    cpy_r_r15 = 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL12: ;
    PyObject *cpy_r_r16[2] = {cpy_r_values, cpy_r_r12};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = _PyObject_Vectorcall(cpy_r_r14, cpy_r_r17, 2, 0);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL50;
    } else
        goto CPyL51;
CPyL13: ;
    CPy_DECREF(cpy_r_r12);
    cpy_r_r19 = CPyStatics[73]; /* 'item_type' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 344, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r21 = CPyStatics[67]; /* 'is_array' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 345, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r23 = PyObject_IsTrue(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r24 = cpy_r_r23 >= 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 345, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r25 = cpy_r_r23;
    if (!cpy_r_r25) goto CPyL25;
    cpy_r_r26 = PyList_New(0);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 346, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r27 = PyObject_GetIter(cpy_r_values);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 346, CPyStatic_globals);
        goto CPyL53;
    }
CPyL19: ;
    cpy_r_r28 = PyIter_Next(cpy_r_r27);
    if (cpy_r_r28 == NULL) goto CPyL54;
    if (PyList_Check(cpy_r_r28))
        cpy_r_r29 = cpy_r_r28;
    else {
        cpy_r_r29 = NULL;
    }
    if (cpy_r_r29 != NULL) goto __LL27;
    if (PyTuple_Check(cpy_r_r28))
        cpy_r_r29 = cpy_r_r28;
    else {
        cpy_r_r29 = NULL;
    }
    if (cpy_r_r29 != NULL) goto __LL27;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 346, CPyStatic_globals, "union[list, tuple]", cpy_r_r28);
    goto CPyL55;
__LL27: ;
    cpy_r_r30 = CPyDef__format_array_but_cache_checksums(cpy_r_r20, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 346, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r31 = PyList_Append(cpy_r_r26, cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r32 = cpy_r_r31 >= 0;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 346, CPyStatic_globals);
        goto CPyL55;
    } else
        goto CPyL19;
CPyL23: ;
    cpy_r_r33 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 346, CPyStatic_globals);
        goto CPyL56;
    }
    return cpy_r_r26;
CPyL25: ;
    cpy_r_r34 = CPyStatic_TupleType;
    if (unlikely(cpy_r_r34 == NULL)) {
        goto CPyL57;
    } else
        goto CPyL28;
CPyL26: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"TupleType\" was not set");
    cpy_r_r35 = 0;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 347, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r36 = PyObject_IsInstance(cpy_r_r20, cpy_r_r34);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 347, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r38 = cpy_r_r36;
    if (!cpy_r_r38) goto CPyL39;
    cpy_r_r39 = CPyStatics[68]; /* 'components' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r20, cpy_r_r39);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 348, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r41 = PyList_New(0);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 349, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r42 = PyObject_GetIter(cpy_r_values);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 349, CPyStatic_globals);
        goto CPyL59;
    }
CPyL33: ;
    cpy_r_r43 = PyIter_Next(cpy_r_r42);
    if (cpy_r_r43 == NULL) goto CPyL60;
    if (PyList_Check(cpy_r_r43))
        cpy_r_r44 = cpy_r_r43;
    else {
        cpy_r_r44 = NULL;
    }
    if (cpy_r_r44 != NULL) goto __LL28;
    if (PyTuple_Check(cpy_r_r43))
        cpy_r_r44 = cpy_r_r43;
    else {
        cpy_r_r44 = NULL;
    }
    if (cpy_r_r44 != NULL) goto __LL28;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 349, CPyStatic_globals, "union[list, tuple]", cpy_r_r43);
    goto CPyL61;
__LL28: ;
    cpy_r_r45 = CPyDef__format_tuple_but_cache_checksums(cpy_r_r40, cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 349, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r46 = PyList_Append(cpy_r_r41, cpy_r_r45);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r47 = cpy_r_r46 >= 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 349, CPyStatic_globals);
        goto CPyL61;
    } else
        goto CPyL33;
CPyL37: ;
    cpy_r_r48 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 349, CPyStatic_globals);
        goto CPyL62;
    }
    return cpy_r_r41;
CPyL39: ;
    cpy_r_r49 = CPyStatics[69]; /* 'to_type_str' */
    PyObject *cpy_r_r50[1] = {cpy_r_r20};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = PyObject_VectorcallMethod(cpy_r_r49, cpy_r_r51, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 351, CPyStatic_globals);
        goto CPyL52;
    }
    CPy_DECREF(cpy_r_r20);
    cpy_r_r53 = PyList_New(0);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 352, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r54 = PyObject_GetIter(cpy_r_values);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 352, CPyStatic_globals);
        goto CPyL64;
    }
CPyL42: ;
    cpy_r_r55 = PyIter_Next(cpy_r_r54);
    if (cpy_r_r55 == NULL) goto CPyL65;
    CPy_INCREF(cpy_r_r52);
    if (likely(PyUnicode_Check(cpy_r_r52)))
        cpy_r_r56 = cpy_r_r52;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 352, CPyStatic_globals, "str", cpy_r_r52);
        goto CPyL66;
    }
    cpy_r_r57 = CPyDef__format_single_but_cache_checksums(cpy_r_r56, cpy_r_r55);
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 352, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r58 = PyList_Append(cpy_r_r53, cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    cpy_r_r59 = cpy_r_r58 >= 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 352, CPyStatic_globals);
        goto CPyL67;
    } else
        goto CPyL42;
CPyL46: ;
    cpy_r_r60 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 352, CPyStatic_globals);
        goto CPyL68;
    }
    return cpy_r_r53;
CPyL48: ;
    cpy_r_r61 = NULL;
    return cpy_r_r61;
CPyL49: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL10;
CPyL50: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL48;
CPyL51: ;
    CPy_DECREF(cpy_r_r18);
    goto CPyL13;
CPyL52: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL48;
CPyL53: ;
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r26);
    goto CPyL48;
CPyL54: ;
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r27);
    goto CPyL23;
CPyL55: ;
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r27);
    goto CPyL48;
CPyL56: ;
    CPy_DecRef(cpy_r_r26);
    goto CPyL48;
CPyL57: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL26;
CPyL58: ;
    CPy_DecRef(cpy_r_r40);
    goto CPyL48;
CPyL59: ;
    CPy_DecRef(cpy_r_r40);
    CPy_DecRef(cpy_r_r41);
    goto CPyL48;
CPyL60: ;
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r42);
    goto CPyL37;
CPyL61: ;
    CPy_DecRef(cpy_r_r40);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r42);
    goto CPyL48;
CPyL62: ;
    CPy_DecRef(cpy_r_r41);
    goto CPyL48;
CPyL63: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL48;
CPyL64: ;
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    goto CPyL48;
CPyL65: ;
    CPy_DECREF(cpy_r_r52);
    CPy_DECREF(cpy_r_r54);
    goto CPyL46;
CPyL66: ;
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    CPy_DecRef(cpy_r_r54);
    CPy_DecRef(cpy_r_r55);
    goto CPyL48;
CPyL67: ;
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    CPy_DecRef(cpy_r_r54);
    goto CPyL48;
CPyL68: ;
    CPy_DecRef(cpy_r_r53);
    goto CPyL48;
}

PyObject *CPyPy__format_array_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_type", "values", 0};
    static CPyArg_Parser parser = {"OO:_format_array_but_cache_checksums", kwlist, 0};
    PyObject *obj_abi_type;
    PyObject *obj_values;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_type, &obj_values)) {
        return NULL;
    }
    PyObject *arg_abi_type = obj_abi_type;
    PyObject *arg_values;
    if (PyList_Check(obj_values))
        arg_values = obj_values;
    else {
        arg_values = NULL;
    }
    if (arg_values != NULL) goto __LL29;
    if (PyTuple_Check(obj_values))
        arg_values = obj_values;
    else {
        arg_values = NULL;
    }
    if (arg_values != NULL) goto __LL29;
    CPy_TypeError("union[list, tuple]", obj_values); 
    goto fail;
__LL29: ;
    PyObject *retval = CPyDef__format_array_but_cache_checksums(arg_abi_type, arg_values);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 342, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__format_single_but_cache_checksums(PyObject *cpy_r_type_str, PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    int32_t cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    int32_t cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    char cpy_r_r34;
    char cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    int32_t cpy_r_r43;
    char cpy_r_r44;
    PyObject *cpy_r_r45;
    char cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    tuple_T5OOOOO cpy_r_r56;
    PyObject *cpy_r_r57;
    int32_t cpy_r_r58;
    char cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    char cpy_r_r64;
    PyObject **cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    int32_t cpy_r_r69;
    char cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    char cpy_r_r73;
    PyObject **cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    int32_t cpy_r_r78;
    char cpy_r_r79;
    char cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    PyObject **cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject **cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    cpy_r_r0 = CPyStatics[74]; /* 'uint' */
    cpy_r_r1 = PySequence_Contains(cpy_r_type_str, cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 357, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r3 = cpy_r_r1;
    if (!cpy_r_r3) goto CPyL7;
    cpy_r_r4 = CPyStatic_to_uint;
    if (likely(cpy_r_r4 != NULL)) goto CPyL5;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_uint\" was not set");
    cpy_r_r5 = 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 358, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL5: ;
    PyObject *cpy_r_r6[2] = {cpy_r_value, cpy_r_type_str};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r7, 2, 0);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 358, CPyStatic_globals);
        goto CPyL66;
    }
    return cpy_r_r8;
CPyL7: ;
    cpy_r_r9 = CPyStatics[75]; /* 'int' */
    cpy_r_r10 = PySequence_Contains(cpy_r_type_str, cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 359, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r12 = cpy_r_r10;
    if (!cpy_r_r12) goto CPyL14;
    cpy_r_r13 = CPyStatic_to_int;
    if (likely(cpy_r_r13 != NULL)) goto CPyL12;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_int\" was not set");
    cpy_r_r14 = 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 360, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL12: ;
    PyObject *cpy_r_r15[2] = {cpy_r_value, cpy_r_type_str};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r13, cpy_r_r16, 2, 0);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 360, CPyStatic_globals);
        goto CPyL66;
    }
    return cpy_r_r17;
CPyL14: ;
    cpy_r_r18 = CPyStatics[76]; /* 'fixed168x10' */
    cpy_r_r19 = PyUnicode_Compare(cpy_r_type_str, cpy_r_r18);
    cpy_r_r20 = cpy_r_r19 == -1;
    if (!cpy_r_r20) goto CPyL17;
    cpy_r_r21 = PyErr_Occurred();
    cpy_r_r22 = cpy_r_r21 != NULL;
    if (!cpy_r_r22) goto CPyL17;
    cpy_r_r23 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 361, CPyStatic_globals);
        goto CPyL66;
    }
CPyL17: ;
    cpy_r_r24 = cpy_r_r19 == 0;
    if (!cpy_r_r24) goto CPyL23;
    cpy_r_r25 = CPyStatic_to_decimal;
    if (likely(cpy_r_r25 != NULL)) goto CPyL21;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_decimal\" was not set");
    cpy_r_r26 = 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 362, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL21: ;
    PyObject *cpy_r_r27[1] = {cpy_r_value};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = _PyObject_Vectorcall(cpy_r_r25, cpy_r_r28, 1, 0);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 362, CPyStatic_globals);
        goto CPyL66;
    }
    return cpy_r_r29;
CPyL23: ;
    cpy_r_r30 = CPyStatics[77]; /* 'bool' */
    cpy_r_r31 = PyUnicode_Compare(cpy_r_type_str, cpy_r_r30);
    cpy_r_r32 = cpy_r_r31 == -1;
    if (!cpy_r_r32) goto CPyL26;
    cpy_r_r33 = PyErr_Occurred();
    cpy_r_r34 = cpy_r_r33 != NULL;
    if (!cpy_r_r34) goto CPyL26;
    cpy_r_r35 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 363, CPyStatic_globals);
        goto CPyL66;
    }
CPyL26: ;
    cpy_r_r36 = cpy_r_r31 == 0;
    if (!cpy_r_r36) goto CPyL32;
    cpy_r_r37 = CPyStatic_to_bool;
    if (likely(cpy_r_r37 != NULL)) goto CPyL30;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_bool\" was not set");
    cpy_r_r38 = 0;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 364, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL30: ;
    PyObject *cpy_r_r39[1] = {cpy_r_value};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r40, 1, 0);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 364, CPyStatic_globals);
        goto CPyL66;
    }
    return cpy_r_r41;
CPyL32: ;
    cpy_r_r42 = CPyStatics[78]; /* 'address' */
    cpy_r_r43 = PyUnicode_Compare(cpy_r_type_str, cpy_r_r42);
    cpy_r_r44 = cpy_r_r43 == -1;
    if (!cpy_r_r44) goto CPyL35;
    cpy_r_r45 = PyErr_Occurred();
    cpy_r_r46 = cpy_r_r45 != NULL;
    if (!cpy_r_r46) goto CPyL35;
    cpy_r_r47 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 365, CPyStatic_globals);
        goto CPyL66;
    }
CPyL35: ;
    cpy_r_r48 = cpy_r_r43 == 0;
    if (!cpy_r_r48) goto CPyL47;
    cpy_r_r49 = (PyObject *)&PyUnicode_Type;
    cpy_r_r50 = (PyObject *)&PyBytes_Type;
    cpy_r_r51 = CPyModule_builtins;
    cpy_r_r52 = CPyStatics[79]; /* 'bytearray' */
    cpy_r_r53 = CPyObject_GetAttr(cpy_r_r51, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 368, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r54 = (PyObject *)&PyLong_Type;
    cpy_r_r55 = (PyObject *)&PyBool_Type;
    CPy_INCREF(cpy_r_r49);
    CPy_INCREF(cpy_r_r50);
    CPy_INCREF(cpy_r_r54);
    CPy_INCREF(cpy_r_r55);
    cpy_r_r56.f0 = cpy_r_r49;
    cpy_r_r56.f1 = cpy_r_r50;
    cpy_r_r56.f2 = cpy_r_r53;
    cpy_r_r56.f3 = cpy_r_r54;
    cpy_r_r56.f4 = cpy_r_r55;
    cpy_r_r57 = PyTuple_New(5);
    if (unlikely(cpy_r_r57 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp30 = cpy_r_r56.f0;
    PyTuple_SET_ITEM(cpy_r_r57, 0, __tmp30);
    PyObject *__tmp31 = cpy_r_r56.f1;
    PyTuple_SET_ITEM(cpy_r_r57, 1, __tmp31);
    PyObject *__tmp32 = cpy_r_r56.f2;
    PyTuple_SET_ITEM(cpy_r_r57, 2, __tmp32);
    PyObject *__tmp33 = cpy_r_r56.f3;
    PyTuple_SET_ITEM(cpy_r_r57, 3, __tmp33);
    PyObject *__tmp34 = cpy_r_r56.f4;
    PyTuple_SET_ITEM(cpy_r_r57, 4, __tmp34);
    cpy_r_r58 = PyObject_IsInstance(cpy_r_value, cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    cpy_r_r59 = cpy_r_r58 >= 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 368, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r60 = cpy_r_r58;
    if (!cpy_r_r60) goto CPyL40;
    CPy_INCREF(cpy_r_value);
    cpy_r_r61 = cpy_r_value;
    goto CPyL42;
CPyL40: ;
    cpy_r_r62 = PyObject_Str(cpy_r_value);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 368, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r61 = cpy_r_r62;
CPyL42: ;
    cpy_r_r63 = CPyStatic_to_checksum_address;
    if (unlikely(cpy_r_r63 == NULL)) {
        goto CPyL67;
    } else
        goto CPyL45;
CPyL43: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_checksum_address\" was not set");
    cpy_r_r64 = 0;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 367, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL45: ;
    PyObject *cpy_r_r65[1] = {cpy_r_r61};
    cpy_r_r66 = (PyObject **)&cpy_r_r65;
    cpy_r_r67 = _PyObject_Vectorcall(cpy_r_r63, cpy_r_r66, 1, 0);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 367, CPyStatic_globals);
        goto CPyL68;
    }
    CPy_DECREF(cpy_r_r61);
    return cpy_r_r67;
CPyL47: ;
    cpy_r_r68 = CPyStatics[80]; /* 'byte' */
    cpy_r_r69 = PySequence_Contains(cpy_r_type_str, cpy_r_r68);
    cpy_r_r70 = cpy_r_r69 >= 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 370, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r71 = cpy_r_r69;
    if (!cpy_r_r71) goto CPyL54;
    cpy_r_r72 = CPyStatic_HexString;
    if (likely(cpy_r_r72 != NULL)) goto CPyL52;
    PyErr_SetString(PyExc_NameError, "value for final name \"HexString\" was not set");
    cpy_r_r73 = 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 371, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL52: ;
    PyObject *cpy_r_r74[2] = {cpy_r_value, cpy_r_type_str};
    cpy_r_r75 = (PyObject **)&cpy_r_r74;
    cpy_r_r76 = _PyObject_Vectorcall(cpy_r_r72, cpy_r_r75, 2, 0);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 371, CPyStatic_globals);
        goto CPyL66;
    }
    return cpy_r_r76;
CPyL54: ;
    cpy_r_r77 = CPyStatics[53]; /* 'string' */
    cpy_r_r78 = PySequence_Contains(cpy_r_type_str, cpy_r_r77);
    cpy_r_r79 = cpy_r_r78 >= 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 372, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r80 = cpy_r_r78;
    if (!cpy_r_r80) goto CPyL61;
    cpy_r_r81 = CPyStatic_to_string;
    if (likely(cpy_r_r81 != NULL)) goto CPyL59;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_string\" was not set");
    cpy_r_r82 = 0;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 373, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL59: ;
    PyObject *cpy_r_r83[1] = {cpy_r_value};
    cpy_r_r84 = (PyObject **)&cpy_r_r83;
    cpy_r_r85 = _PyObject_Vectorcall(cpy_r_r81, cpy_r_r84, 1, 0);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 373, CPyStatic_globals);
        goto CPyL66;
    }
    return cpy_r_r85;
CPyL61: ;
    cpy_r_r86 = CPyStatics[81]; /* 'Unknown type: ' */
    cpy_r_r87 = CPyStr_Build(2, cpy_r_r86, cpy_r_type_str);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 374, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r88 = CPyModule_builtins;
    cpy_r_r89 = CPyStatics[36]; /* 'TypeError' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 374, CPyStatic_globals);
        goto CPyL69;
    }
    PyObject *cpy_r_r91[1] = {cpy_r_r87};
    cpy_r_r92 = (PyObject **)&cpy_r_r91;
    cpy_r_r93 = _PyObject_Vectorcall(cpy_r_r90, cpy_r_r92, 1, 0);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 374, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_DECREF(cpy_r_r87);
    CPy_Raise(cpy_r_r93);
    CPy_DECREF(cpy_r_r93);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 374, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL66: ;
    cpy_r_r94 = NULL;
    return cpy_r_r94;
CPyL67: ;
    CPy_DecRef(cpy_r_r61);
    goto CPyL43;
CPyL68: ;
    CPy_DecRef(cpy_r_r61);
    goto CPyL66;
CPyL69: ;
    CPy_DecRef(cpy_r_r87);
    goto CPyL66;
}

PyObject *CPyPy__format_single_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"type_str", "value", 0};
    static CPyArg_Parser parser = {"OO:_format_single_but_cache_checksums", kwlist, 0};
    PyObject *obj_type_str;
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type_str, &obj_value)) {
        return NULL;
    }
    PyObject *arg_type_str;
    if (likely(PyUnicode_Check(obj_type_str)))
        arg_type_str = obj_type_str;
    else {
        CPy_TypeError("str", obj_type_str); 
        goto fail;
    }
    PyObject *arg_value = obj_value;
    PyObject *retval = CPyDef__format_single_but_cache_checksums(arg_type_str, arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 355, CPyStatic_globals);
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
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r35;
    PyObject **cpy_r_r36;
    PyObject **cpy_r_r37;
    PyObject **cpy_r_r38;
    PyObject **cpy_r_r39;
    void *cpy_r_r41;
    void *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
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
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
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
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
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
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    int32_t cpy_r_r122;
    char cpy_r_r123;
    PyObject *cpy_r_r124;
    char cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    char cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    int32_t cpy_r_r133;
    char cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject **cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    int32_t cpy_r_r144;
    char cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject **cpy_r_r152;
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
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    tuple_T2OO cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    tuple_T2OO cpy_r_r189;
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
    PyObject *cpy_r_r203;
    tuple_T2OO cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject **cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    int32_t cpy_r_r215;
    char cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    int32_t cpy_r_r222;
    char cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    int32_t cpy_r_r231;
    char cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    int32_t cpy_r_r244;
    char cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    int32_t cpy_r_r257;
    char cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    PyObject *cpy_r_r269;
    int32_t cpy_r_r270;
    char cpy_r_r271;
    PyObject *cpy_r_r272;
    PyObject *cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    int32_t cpy_r_r283;
    char cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    int32_t cpy_r_r292;
    char cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    PyObject *cpy_r_r304;
    int32_t cpy_r_r305;
    char cpy_r_r306;
    PyObject *cpy_r_r307;
    PyObject *cpy_r_r308;
    PyObject *cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject *cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    int32_t cpy_r_r318;
    char cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    PyObject *cpy_r_r322;
    PyObject *cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject *cpy_r_r330;
    int32_t cpy_r_r331;
    char cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    PyObject *cpy_r_r340;
    PyObject *cpy_r_r341;
    PyObject *cpy_r_r342;
    PyObject *cpy_r_r343;
    int32_t cpy_r_r344;
    char cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    PyObject *cpy_r_r348;
    PyObject *cpy_r_r349;
    PyObject *cpy_r_r350;
    PyObject *cpy_r_r351;
    PyObject *cpy_r_r352;
    PyObject *cpy_r_r353;
    PyObject *cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_r356;
    int32_t cpy_r_r357;
    char cpy_r_r358;
    PyObject *cpy_r_r359;
    PyObject *cpy_r_r360;
    PyObject *cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject *cpy_r_r369;
    int32_t cpy_r_r370;
    char cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    PyObject *cpy_r_r377;
    PyObject *cpy_r_r378;
    PyObject *cpy_r_r379;
    PyObject *cpy_r_r380;
    PyObject *cpy_r_r381;
    PyObject *cpy_r_r382;
    int32_t cpy_r_r383;
    char cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    PyObject *cpy_r_r390;
    PyObject *cpy_r_r391;
    PyObject **cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    int32_t cpy_r_r397;
    char cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject *cpy_r_r400;
    PyObject *cpy_r_r401;
    int32_t cpy_r_r402;
    char cpy_r_r403;
    PyObject *cpy_r_r404;
    PyObject *cpy_r_r405;
    PyObject *cpy_r_r406;
    int32_t cpy_r_r407;
    char cpy_r_r408;
    PyObject *cpy_r_r409;
    PyObject *cpy_r_r410;
    PyObject *cpy_r_r411;
    PyObject *cpy_r_r412;
    PyObject *cpy_r_r413;
    PyObject *cpy_r_r414;
    PyObject *cpy_r_r415;
    int32_t cpy_r_r416;
    char cpy_r_r417;
    PyObject *cpy_r_r418;
    PyObject *cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    PyObject *cpy_r_r423;
    PyObject **cpy_r_r425;
    PyObject *cpy_r_r426;
    PyObject *cpy_r_r427;
    PyObject *cpy_r_r428;
    int32_t cpy_r_r429;
    char cpy_r_r430;
    PyObject *cpy_r_r431;
    PyObject *cpy_r_r432;
    PyObject *cpy_r_r433;
    PyObject *cpy_r_r434;
    char cpy_r_r435;
    PyObject *cpy_r_r436;
    PyObject *cpy_r_r437;
    PyObject *cpy_r_r438;
    PyObject *cpy_r_r439;
    PyObject *cpy_r_r440;
    PyObject *cpy_r_r441;
    PyObject *cpy_r_r442;
    PyObject *cpy_r_r443;
    PyObject *cpy_r_r444;
    PyObject *cpy_r_r445;
    PyObject *cpy_r_r446;
    PyObject *cpy_r_r447;
    PyObject *cpy_r_r448;
    int32_t cpy_r_r449;
    char cpy_r_r450;
    PyObject *cpy_r_r451;
    PyObject *cpy_r_r452;
    PyObject *cpy_r_r453;
    PyObject *cpy_r_r454;
    char cpy_r_r455;
    PyObject *cpy_r_r456;
    PyObject *cpy_r_r457;
    PyObject *cpy_r_r458;
    PyObject *cpy_r_r459;
    PyObject *cpy_r_r460;
    PyObject *cpy_r_r461;
    PyObject *cpy_r_r462;
    PyObject *cpy_r_r463;
    PyObject *cpy_r_r464;
    PyObject *cpy_r_r465;
    PyObject *cpy_r_r466;
    PyObject *cpy_r_r467;
    PyObject *cpy_r_r468;
    int32_t cpy_r_r469;
    char cpy_r_r470;
    PyObject *cpy_r_r471;
    PyObject *cpy_r_r472;
    int32_t cpy_r_r473;
    char cpy_r_r474;
    PyObject *cpy_r_r475;
    PyObject *cpy_r_r476;
    int32_t cpy_r_r477;
    char cpy_r_r478;
    PyObject *cpy_r_r479;
    PyObject *cpy_r_r480;
    PyObject *cpy_r_r481;
    PyObject *cpy_r_r482;
    PyObject *cpy_r_r483;
    PyObject *cpy_r_r484;
    PyObject *cpy_r_r485;
    int32_t cpy_r_r486;
    char cpy_r_r487;
    tuple_T3OOO cpy_r_r488;
    PyObject *cpy_r_r489;
    PyObject *cpy_r_r490;
    PyObject *cpy_r_r491;
    char cpy_r_r492;
    PyObject *cpy_r_r493;
    PyObject *cpy_r_r494;
    PyObject *cpy_r_r495;
    int32_t cpy_r_r496;
    char cpy_r_r497;
    PyObject *cpy_r_r498;
    PyObject *cpy_r_r499;
    PyObject *cpy_r_r500;
    PyObject *cpy_r_r501;
    PyObject *cpy_r_r502;
    int32_t cpy_r_r503;
    char cpy_r_r504;
    char cpy_r_r505;
    char cpy_r_r506;
    char cpy_r_r507;
    PyObject *cpy_r_r508;
    PyObject *cpy_r_r509;
    PyObject *cpy_r_r510;
    PyObject *cpy_r_r511;
    PyObject *cpy_r_r512;
    PyObject *cpy_r_r513;
    PyObject *cpy_r_r514;
    PyObject *cpy_r_r515;
    PyObject **cpy_r_r517;
    PyObject *cpy_r_r518;
    PyObject *cpy_r_r519;
    PyObject *cpy_r_r520;
    int32_t cpy_r_r521;
    char cpy_r_r522;
    int32_t cpy_r_r523;
    char cpy_r_r524;
    char cpy_r_r525;
    PyObject *cpy_r_r526;
    PyObject *cpy_r_r527;
    PyObject *cpy_r_r528;
    PyObject *cpy_r_r529;
    PyObject *cpy_r_r530;
    PyObject *cpy_r_r531;
    PyObject *cpy_r_r532;
    PyObject *cpy_r_r533;
    char cpy_r_r534;
    PyObject **cpy_r_r536;
    PyObject *cpy_r_r537;
    int32_t cpy_r_r538;
    char cpy_r_r539;
    PyObject *cpy_r_r540;
    PyObject *cpy_r_r541;
    PyObject *cpy_r_r542;
    PyObject *cpy_r_r543;
    PyObject *cpy_r_r544;
    PyObject *cpy_r_r545;
    PyObject *cpy_r_r546;
    PyObject *cpy_r_r547;
    PyObject *cpy_r_r548;
    PyObject *cpy_r_r549;
    PyObject *cpy_r_r550;
    int32_t cpy_r_r551;
    char cpy_r_r552;
    PyObject *cpy_r_r553;
    PyObject *cpy_r_r554;
    PyObject *cpy_r_r555;
    PyObject *cpy_r_r556;
    PyObject *cpy_r_r557;
    PyObject *cpy_r_r558;
    PyObject *cpy_r_r559;
    PyObject *cpy_r_r560;
    PyObject *cpy_r_r561;
    PyObject *cpy_r_r562;
    PyObject *cpy_r_r563;
    int32_t cpy_r_r564;
    char cpy_r_r565;
    PyObject *cpy_r_r566;
    PyObject *cpy_r_r567;
    PyObject *cpy_r_r568;
    PyObject *cpy_r_r569;
    PyObject *cpy_r_r570;
    PyObject *cpy_r_r571;
    PyObject *cpy_r_r572;
    PyObject *cpy_r_r573;
    PyObject *cpy_r_r574;
    PyObject *cpy_r_r575;
    PyObject *cpy_r_r576;
    int32_t cpy_r_r577;
    char cpy_r_r578;
    PyObject *cpy_r_r579;
    PyObject *cpy_r_r580;
    PyObject *cpy_r_r581;
    PyObject *cpy_r_r582;
    PyObject *cpy_r_r583;
    PyObject *cpy_r_r584;
    PyObject *cpy_r_r585;
    PyObject *cpy_r_r586;
    PyObject *cpy_r_r587;
    PyObject *cpy_r_r588;
    PyObject *cpy_r_r589;
    int32_t cpy_r_r590;
    char cpy_r_r591;
    PyObject *cpy_r_r592;
    PyObject *cpy_r_r593;
    PyObject *cpy_r_r594;
    PyObject *cpy_r_r595;
    PyObject *cpy_r_r596;
    PyObject *cpy_r_r597;
    PyObject *cpy_r_r598;
    PyObject *cpy_r_r599;
    PyObject *cpy_r_r600;
    PyObject *cpy_r_r601;
    PyObject *cpy_r_r602;
    int32_t cpy_r_r603;
    char cpy_r_r604;
    char cpy_r_r605;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[82]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", -1, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_decimal;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[198]; /* (('decimal', 'decimal', 'decimal'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[84]; /* 'dank_mids/brownie_patch/call.py' */
    cpy_r_r13 = CPyStatics[85]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL219;
    cpy_r_r15 = CPyStatics[199]; /* ('BrokenProcessPool',) */
    cpy_r_r16 = CPyStatics[86]; /* 'concurrent.futures.process' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 2, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_concurrent___futures___process = cpy_r_r18;
    CPy_INCREF(CPyModule_concurrent___futures___process);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[200]; /* ('Logger', 'getLogger') */
    cpy_r_r20 = CPyStatics[89]; /* 'logging' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 3, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_logging = cpy_r_r22;
    CPy_INCREF(CPyModule_logging);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[201]; /* ('PicklingError',) */
    cpy_r_r24 = CPyStatics[90]; /* 'pickle' */
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 4, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_pickle = cpy_r_r26;
    CPy_INCREF(CPyModule_pickle);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatics[202]; /* ('MethodType', 'ModuleType') */
    cpy_r_r28 = CPyStatics[92]; /* 'types' */
    cpy_r_r29 = CPyStatic_globals;
    cpy_r_r30 = CPyImport_ImportFromMany(cpy_r_r28, cpy_r_r27, cpy_r_r27, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 5, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_types = cpy_r_r30;
    CPy_INCREF(CPyModule_types);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r31 = CPyStatics[203]; /* ('Any', 'Callable', 'Dict', 'Final', 'List', 'NewType',
                                    'Optional', 'Sequence', 'Tuple', 'TypeVar', 'Union') */
    cpy_r_r32 = CPyStatics[104]; /* 'typing' */
    cpy_r_r33 = CPyStatic_globals;
    cpy_r_r34 = CPyImport_ImportFromMany(cpy_r_r32, cpy_r_r31, cpy_r_r31, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 6, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_typing = cpy_r_r34;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r35 = (PyObject **)&CPyModule_brownie___convert___datatypes;
    cpy_r_r36 = (PyObject **)&CPyModule_brownie___convert___normalize;
    cpy_r_r37 = (PyObject **)&CPyModule_brownie___network___contract;
    cpy_r_r38 = (PyObject **)&CPyModule_eth_abi;
    cpy_r_r39 = (PyObject **)&CPyModule_hexbytes;
    PyObject **cpy_r_r40[5] = {cpy_r_r35, cpy_r_r36, cpy_r_r37, cpy_r_r38, cpy_r_r39};
    cpy_r_r41 = (void *)&cpy_r_r40;
    int64_t cpy_r_r42[5] = {20, 21, 22, 23, 24};
    cpy_r_r43 = (void *)&cpy_r_r42;
    cpy_r_r44 = CPyStatics[209]; /* (('brownie.convert.datatypes', 'brownie', 'brownie'),
                                    ('brownie.convert.normalize', 'brownie', 'brownie'),
                                    ('brownie.network.contract', 'brownie', 'brownie'),
                                    ('eth_abi', 'eth_abi', 'eth_abi'),
                                    ('hexbytes', 'hexbytes', 'hexbytes')) */
    cpy_r_r45 = CPyStatic_globals;
    cpy_r_r46 = CPyStatics[84]; /* 'dank_mids/brownie_patch/call.py' */
    cpy_r_r47 = CPyStatics[85]; /* '<module>' */
    cpy_r_r48 = CPyImport_ImportMany(cpy_r_r44, cpy_r_r41, cpy_r_r45, cpy_r_r46, cpy_r_r47, cpy_r_r43);
    if (!cpy_r_r48) goto CPyL219;
    cpy_r_r49 = CPyStatics[210]; /* ('AsyncProcessPoolExecutor',) */
    cpy_r_r50 = CPyStatics[110]; /* 'a_sync' */
    cpy_r_r51 = CPyStatic_globals;
    cpy_r_r52 = CPyImport_ImportFromMany(cpy_r_r50, cpy_r_r49, cpy_r_r49, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 25, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_a_sync = cpy_r_r52;
    CPy_INCREF(CPyModule_a_sync);
    CPy_DECREF(cpy_r_r52);
    cpy_r_r53 = CPyStatics[211]; /* ('chain',) */
    cpy_r_r54 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r55 = CPyStatic_globals;
    cpy_r_r56 = CPyImport_ImportFromMany(cpy_r_r54, cpy_r_r53, cpy_r_r53, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 26, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_brownie = cpy_r_r56;
    CPy_INCREF(CPyModule_brownie);
    CPy_DECREF(cpy_r_r56);
    cpy_r_r57 = CPyStatics[212]; /* ('ABIType',) */
    cpy_r_r58 = CPyStatics[107]; /* 'brownie.convert.normalize' */
    cpy_r_r59 = CPyStatic_globals;
    cpy_r_r60 = CPyImport_ImportFromMany(cpy_r_r58, cpy_r_r57, cpy_r_r57, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 27, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_brownie___convert___normalize = cpy_r_r60;
    CPy_INCREF(CPyModule_brownie___convert___normalize);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r61 = CPyStatics[213]; /* ('get_type_strings',) */
    cpy_r_r62 = CPyStatics[113]; /* 'brownie.convert.utils' */
    cpy_r_r63 = CPyStatic_globals;
    cpy_r_r64 = CPyImport_ImportFromMany(cpy_r_r62, cpy_r_r61, cpy_r_r61, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 28, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_brownie___convert___utils = cpy_r_r64;
    CPy_INCREF(CPyModule_brownie___convert___utils);
    CPy_DECREF(cpy_r_r64);
    cpy_r_r65 = CPyStatics[214]; /* ('VirtualMachineError',) */
    cpy_r_r66 = CPyStatics[114]; /* 'brownie.exceptions' */
    cpy_r_r67 = CPyStatic_globals;
    cpy_r_r68 = CPyImport_ImportFromMany(cpy_r_r66, cpy_r_r65, cpy_r_r65, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 29, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_brownie___exceptions = cpy_r_r68;
    CPy_INCREF(CPyModule_brownie___exceptions);
    CPy_DECREF(cpy_r_r68);
    cpy_r_r69 = CPyStatics[215]; /* ('ContractCall',) */
    cpy_r_r70 = CPyStatics[108]; /* 'brownie.network.contract' */
    cpy_r_r71 = CPyStatic_globals;
    cpy_r_r72 = CPyImport_ImportFromMany(cpy_r_r70, cpy_r_r69, cpy_r_r69, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 30, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_brownie___network___contract = cpy_r_r72;
    CPy_INCREF(CPyModule_brownie___network___contract);
    CPy_DECREF(cpy_r_r72);
    cpy_r_r73 = CPyStatics[216]; /* ('SOLIDITY_ERROR_CODES',) */
    cpy_r_r74 = CPyStatics[116]; /* 'brownie.project.compiler.solidity' */
    cpy_r_r75 = CPyStatic_globals;
    cpy_r_r76 = CPyImport_ImportFromMany(cpy_r_r74, cpy_r_r73, cpy_r_r73, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 31, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_brownie___project___compiler___solidity = cpy_r_r76;
    CPy_INCREF(CPyModule_brownie___project___compiler___solidity);
    CPy_DECREF(cpy_r_r76);
    cpy_r_r77 = CPyStatics[217]; /* ('InsufficientDataBytes',) */
    cpy_r_r78 = CPyStatics[117]; /* 'eth_abi.exceptions' */
    cpy_r_r79 = CPyStatic_globals;
    cpy_r_r80 = CPyImport_ImportFromMany(cpy_r_r78, cpy_r_r77, cpy_r_r77, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 32, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_eth_abi___exceptions = cpy_r_r80;
    CPy_INCREF(CPyModule_eth_abi___exceptions);
    CPy_DECREF(cpy_r_r80);
    cpy_r_r81 = CPyStatics[218]; /* ('HexStr',) */
    cpy_r_r82 = CPyStatics[119]; /* 'eth_typing' */
    cpy_r_r83 = CPyStatic_globals;
    cpy_r_r84 = CPyImport_ImportFromMany(cpy_r_r82, cpy_r_r81, cpy_r_r81, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 33, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_eth_typing = cpy_r_r84;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r84);
    cpy_r_r85 = CPyStatics[219]; /* ('Address',) */
    cpy_r_r86 = CPyStatics[121]; /* 'evmspec.data' */
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyImport_ImportFromMany(cpy_r_r86, cpy_r_r85, cpy_r_r85, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 34, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_evmspec___data = cpy_r_r88;
    CPy_INCREF(CPyModule_evmspec___data);
    CPy_DECREF(cpy_r_r88);
    cpy_r_r89 = CPyStatics[220]; /* ('BytesLike',) */
    cpy_r_r90 = CPyStatics[123]; /* 'hexbytes.main' */
    cpy_r_r91 = CPyStatic_globals;
    cpy_r_r92 = CPyImport_ImportFromMany(cpy_r_r90, cpy_r_r89, cpy_r_r89, cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 35, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_hexbytes___main = cpy_r_r92;
    CPy_INCREF(CPyModule_hexbytes___main);
    CPy_DECREF(cpy_r_r92);
    cpy_r_r93 = CPyStatics[221]; /* ('MULTICALL2_ADDRESSES',) */
    cpy_r_r94 = CPyStatics[125]; /* 'multicall.constants' */
    cpy_r_r95 = CPyStatic_globals;
    cpy_r_r96 = CPyImport_ImportFromMany(cpy_r_r94, cpy_r_r93, cpy_r_r93, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 36, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_multicall___constants = cpy_r_r96;
    CPy_INCREF(CPyModule_multicall___constants);
    CPy_DECREF(cpy_r_r96);
    cpy_r_r97 = CPyStatics[222]; /* ('BlockIdentifier',) */
    cpy_r_r98 = CPyStatics[127]; /* 'web3.types' */
    cpy_r_r99 = CPyStatic_globals;
    cpy_r_r100 = CPyImport_ImportFromMany(cpy_r_r98, cpy_r_r97, cpy_r_r97, cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 37, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_web3___types = cpy_r_r100;
    CPy_INCREF(CPyModule_web3___types);
    CPy_DECREF(cpy_r_r100);
    cpy_r_r101 = CPyStatics[223]; /* ('ENVIRONMENT_VARIABLES', 'exceptions') */
    cpy_r_r102 = CPyStatics[130]; /* 'dank_mids' */
    cpy_r_r103 = CPyStatic_globals;
    cpy_r_r104 = CPyImport_ImportFromMany(cpy_r_r102, cpy_r_r101, cpy_r_r101, cpy_r_r103);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 39, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_dank_mids = cpy_r_r104;
    CPy_INCREF(CPyModule_dank_mids);
    CPy_DECREF(cpy_r_r104);
    cpy_r_r105 = CPyStatics[224]; /* ('ContractMethod',) */
    cpy_r_r106 = CPyStatics[132]; /* 'dank_mids.brownie_patch.types' */
    cpy_r_r107 = CPyStatic_globals;
    cpy_r_r108 = CPyImport_ImportFromMany(cpy_r_r106, cpy_r_r105, cpy_r_r105, cpy_r_r107);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 40, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_dank_mids___brownie_patch___types = cpy_r_r108;
    CPy_INCREF(CPyModule_dank_mids___brownie_patch___types);
    CPy_DECREF(cpy_r_r108);
    cpy_r_r109 = CPyStatics[225]; /* ('lru_cache_lite_nonull',) */
    cpy_r_r110 = CPyStatics[134]; /* 'dank_mids.helpers.lru_cache' */
    cpy_r_r111 = CPyStatic_globals;
    cpy_r_r112 = CPyImport_ImportFromMany(cpy_r_r110, cpy_r_r109, cpy_r_r109, cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 41, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_dank_mids___helpers___lru_cache = cpy_r_r112;
    CPy_INCREF(CPyModule_dank_mids___helpers___lru_cache);
    CPy_DECREF(cpy_r_r112);
    cpy_r_r113 = CPyStatics[226]; /* ('DankWeb3',) */
    cpy_r_r114 = CPyStatics[136]; /* 'dank_mids.helpers._helpers' */
    cpy_r_r115 = CPyStatic_globals;
    cpy_r_r116 = CPyImport_ImportFromMany(cpy_r_r114, cpy_r_r113, cpy_r_r113, cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 42, CPyStatic_globals);
        goto CPyL219;
    }
    CPyModule_dank_mids___helpers____helpers = cpy_r_r116;
    CPy_INCREF(CPyModule_dank_mids___helpers____helpers);
    CPy_DECREF(cpy_r_r116);
    cpy_r_r117 = CPyStatic_globals;
    cpy_r_r118 = CPyStatics[128]; /* 'ENVIRONMENT_VARIABLES' */
    cpy_r_r119 = CPyDict_GetItem(cpy_r_r117, cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 45, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_ENVS = cpy_r_r119;
    CPy_INCREF(CPyStatic_ENVS);
    cpy_r_r120 = CPyStatic_globals;
    cpy_r_r121 = CPyStatics[137]; /* 'ENVS' */
    cpy_r_r122 = CPyDict_SetItem(cpy_r_r120, cpy_r_r121, cpy_r_r119);
    CPy_DECREF(cpy_r_r119);
    cpy_r_r123 = cpy_r_r122 >= 0;
    if (unlikely(!cpy_r_r123)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 45, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r124 = CPyStatic_ENVS;
    if (likely(cpy_r_r124 != NULL)) goto CPyL32;
    PyErr_SetString(PyExc_NameError, "value for final name \"ENVS\" was not set");
    cpy_r_r125 = 0;
    if (unlikely(!cpy_r_r125)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 46, CPyStatic_globals);
        goto CPyL219;
    }
    CPy_Unreachable();
CPyL32: ;
    cpy_r_r126 = CPyStatics[138]; /* 'OPERATION_MODE' */
    cpy_r_r127 = CPyObject_GetAttr(cpy_r_r124, cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 46, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r128 = CPyStatics[139]; /* 'application' */
    cpy_r_r129 = CPyObject_GetAttr(cpy_r_r127, cpy_r_r128);
    CPy_DECREF(cpy_r_r127);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 46, CPyStatic_globals);
        goto CPyL219;
    }
    if (unlikely(!PyBool_Check(cpy_r_r129))) {
        CPy_TypeError("bool", cpy_r_r129); cpy_r_r130 = 2;
    } else
        cpy_r_r130 = cpy_r_r129 == Py_True;
    if (unlikely(cpy_r_r130 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 46, CPyStatic_globals);
        goto CPyL220;
    }
    CPyStatic_APPLICATION_MODE = cpy_r_r130;
    cpy_r_r131 = CPyStatic_globals;
    cpy_r_r132 = CPyStatics[140]; /* 'APPLICATION_MODE' */
    cpy_r_r133 = CPyDict_SetItem(cpy_r_r131, cpy_r_r132, cpy_r_r129);
    CPy_DECREF(cpy_r_r129);
    cpy_r_r134 = cpy_r_r133 >= 0;
    if (unlikely(!cpy_r_r134)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 46, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r135 = CPyStatics[141]; /* '_T' */
    cpy_r_r136 = CPyStatic_globals;
    cpy_r_r137 = CPyStatics[102]; /* 'TypeVar' */
    cpy_r_r138 = CPyDict_GetItem(cpy_r_r136, cpy_r_r137);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 49, CPyStatic_globals);
        goto CPyL219;
    }
    PyObject *cpy_r_r139[1] = {cpy_r_r135};
    cpy_r_r140 = (PyObject **)&cpy_r_r139;
    cpy_r_r141 = _PyObject_Vectorcall(cpy_r_r138, cpy_r_r140, 1, 0);
    CPy_DECREF(cpy_r_r138);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 49, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r142 = CPyStatic_globals;
    cpy_r_r143 = CPyStatics[141]; /* '_T' */
    cpy_r_r144 = CPyDict_SetItem(cpy_r_r142, cpy_r_r143, cpy_r_r141);
    CPy_DECREF(cpy_r_r141);
    cpy_r_r145 = cpy_r_r144 >= 0;
    if (unlikely(!cpy_r_r145)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 49, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r146 = CPyStatics[142]; /* 'TypeStr' */
    cpy_r_r147 = (PyObject *)&PyUnicode_Type;
    cpy_r_r148 = CPyStatic_globals;
    cpy_r_r149 = CPyStatics[98]; /* 'NewType' */
    cpy_r_r150 = CPyDict_GetItem(cpy_r_r148, cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 50, CPyStatic_globals);
        goto CPyL219;
    }
    PyObject *cpy_r_r151[2] = {cpy_r_r146, cpy_r_r147};
    cpy_r_r152 = (PyObject **)&cpy_r_r151;
    cpy_r_r153 = _PyObject_Vectorcall(cpy_r_r150, cpy_r_r152, 2, 0);
    CPy_DECREF(cpy_r_r150);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 50, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r154 = CPyStatic_globals;
    cpy_r_r155 = CPyStatics[142]; /* 'TypeStr' */
    cpy_r_r156 = CPyDict_SetItem(cpy_r_r154, cpy_r_r155, cpy_r_r153);
    CPy_DECREF(cpy_r_r153);
    cpy_r_r157 = cpy_r_r156 >= 0;
    if (unlikely(!cpy_r_r157)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 50, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r158 = CPyStatic_globals;
    cpy_r_r159 = CPyStatics[97]; /* 'List' */
    cpy_r_r160 = CPyDict_GetItem(cpy_r_r158, cpy_r_r159);
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 51, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r161 = CPyStatic_globals;
    cpy_r_r162 = CPyStatics[142]; /* 'TypeStr' */
    cpy_r_r163 = CPyDict_GetItem(cpy_r_r161, cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 51, CPyStatic_globals);
        goto CPyL221;
    }
    cpy_r_r164 = PyObject_GetItem(cpy_r_r160, cpy_r_r163);
    CPy_DECREF(cpy_r_r160);
    CPy_DECREF(cpy_r_r163);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 51, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r165 = CPyStatic_globals;
    cpy_r_r166 = CPyStatics[143]; /* 'TypeStrs' */
    cpy_r_r167 = CPyDict_SetItem(cpy_r_r165, cpy_r_r166, cpy_r_r164);
    CPy_DECREF(cpy_r_r164);
    cpy_r_r168 = cpy_r_r167 >= 0;
    if (unlikely(!cpy_r_r168)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 51, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r169 = CPyStatic_globals;
    cpy_r_r170 = CPyStatics[103]; /* 'Union' */
    cpy_r_r171 = CPyDict_GetItem(cpy_r_r169, cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r172 = CPyStatic_globals;
    cpy_r_r173 = CPyStatics[97]; /* 'List' */
    cpy_r_r174 = CPyDict_GetItem(cpy_r_r172, cpy_r_r173);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL222;
    }
    cpy_r_r175 = CPyStatic_globals;
    cpy_r_r176 = CPyStatics[141]; /* '_T' */
    cpy_r_r177 = CPyDict_GetItem(cpy_r_r175, cpy_r_r176);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL223;
    }
    cpy_r_r178 = PyObject_GetItem(cpy_r_r174, cpy_r_r177);
    CPy_DECREF(cpy_r_r174);
    CPy_DECREF(cpy_r_r177);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL222;
    }
    cpy_r_r179 = CPyStatic_globals;
    cpy_r_r180 = CPyStatics[101]; /* 'Tuple' */
    cpy_r_r181 = CPyDict_GetItem(cpy_r_r179, cpy_r_r180);
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL224;
    }
    cpy_r_r182 = CPyStatic_globals;
    cpy_r_r183 = CPyStatics[141]; /* '_T' */
    cpy_r_r184 = CPyDict_GetItem(cpy_r_r182, cpy_r_r183);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL225;
    }
    cpy_r_r185 = (PyObject *)&_Py_EllipsisObject;
    CPy_INCREF(cpy_r_r185);
    cpy_r_r186.f0 = cpy_r_r184;
    cpy_r_r186.f1 = cpy_r_r185;
    cpy_r_r187 = PyTuple_New(2);
    if (unlikely(cpy_r_r187 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp35 = cpy_r_r186.f0;
    PyTuple_SET_ITEM(cpy_r_r187, 0, __tmp35);
    PyObject *__tmp36 = cpy_r_r186.f1;
    PyTuple_SET_ITEM(cpy_r_r187, 1, __tmp36);
    cpy_r_r188 = PyObject_GetItem(cpy_r_r181, cpy_r_r187);
    CPy_DECREF(cpy_r_r181);
    CPy_DECREF(cpy_r_r187);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL224;
    }
    cpy_r_r189.f0 = cpy_r_r178;
    cpy_r_r189.f1 = cpy_r_r188;
    cpy_r_r190 = PyTuple_New(2);
    if (unlikely(cpy_r_r190 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp37 = cpy_r_r189.f0;
    PyTuple_SET_ITEM(cpy_r_r190, 0, __tmp37);
    PyObject *__tmp38 = cpy_r_r189.f1;
    PyTuple_SET_ITEM(cpy_r_r190, 1, __tmp38);
    cpy_r_r191 = PyObject_GetItem(cpy_r_r171, cpy_r_r190);
    CPy_DECREF(cpy_r_r171);
    CPy_DECREF(cpy_r_r190);
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r192 = CPyStatic_globals;
    cpy_r_r193 = CPyStatics[144]; /* 'ListOrTuple' */
    cpy_r_r194 = CPyDict_SetItem(cpy_r_r192, cpy_r_r193, cpy_r_r191);
    CPy_DECREF(cpy_r_r191);
    cpy_r_r195 = cpy_r_r194 >= 0;
    if (unlikely(!cpy_r_r195)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r196 = CPyStatics[145]; /* 'AbiDict' */
    cpy_r_r197 = CPyStatic_globals;
    cpy_r_r198 = CPyStatics[95]; /* 'Dict' */
    cpy_r_r199 = CPyDict_GetItem(cpy_r_r197, cpy_r_r198);
    if (unlikely(cpy_r_r199 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 53, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r200 = (PyObject *)&PyUnicode_Type;
    cpy_r_r201 = CPyStatic_globals;
    cpy_r_r202 = CPyStatics[93]; /* 'Any' */
    cpy_r_r203 = CPyDict_GetItem(cpy_r_r201, cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 53, CPyStatic_globals);
        goto CPyL226;
    }
    CPy_INCREF(cpy_r_r200);
    cpy_r_r204.f0 = cpy_r_r200;
    cpy_r_r204.f1 = cpy_r_r203;
    cpy_r_r205 = PyTuple_New(2);
    if (unlikely(cpy_r_r205 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp39 = cpy_r_r204.f0;
    PyTuple_SET_ITEM(cpy_r_r205, 0, __tmp39);
    PyObject *__tmp40 = cpy_r_r204.f1;
    PyTuple_SET_ITEM(cpy_r_r205, 1, __tmp40);
    cpy_r_r206 = PyObject_GetItem(cpy_r_r199, cpy_r_r205);
    CPy_DECREF(cpy_r_r199);
    CPy_DECREF(cpy_r_r205);
    if (unlikely(cpy_r_r206 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 53, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r207 = CPyStatic_globals;
    cpy_r_r208 = CPyStatics[98]; /* 'NewType' */
    cpy_r_r209 = CPyDict_GetItem(cpy_r_r207, cpy_r_r208);
    if (unlikely(cpy_r_r209 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 53, CPyStatic_globals);
        goto CPyL227;
    }
    PyObject *cpy_r_r210[2] = {cpy_r_r196, cpy_r_r206};
    cpy_r_r211 = (PyObject **)&cpy_r_r210;
    cpy_r_r212 = _PyObject_Vectorcall(cpy_r_r209, cpy_r_r211, 2, 0);
    CPy_DECREF(cpy_r_r209);
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 53, CPyStatic_globals);
        goto CPyL227;
    }
    CPy_DECREF(cpy_r_r206);
    cpy_r_r213 = CPyStatic_globals;
    cpy_r_r214 = CPyStatics[145]; /* 'AbiDict' */
    cpy_r_r215 = CPyDict_SetItem(cpy_r_r213, cpy_r_r214, cpy_r_r212);
    CPy_DECREF(cpy_r_r212);
    cpy_r_r216 = cpy_r_r215 >= 0;
    if (unlikely(!cpy_r_r216)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 53, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r217 = CPyModule_decimal;
    cpy_r_r218 = CPyStatics[146]; /* 'Decimal' */
    cpy_r_r219 = CPyObject_GetAttr(cpy_r_r217, cpy_r_r218);
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 57, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_Decimal = cpy_r_r219;
    CPy_INCREF(CPyStatic_Decimal);
    cpy_r_r220 = CPyStatic_globals;
    cpy_r_r221 = CPyStatics[146]; /* 'Decimal' */
    cpy_r_r222 = CPyDict_SetItem(cpy_r_r220, cpy_r_r221, cpy_r_r219);
    CPy_DECREF(cpy_r_r219);
    cpy_r_r223 = cpy_r_r222 >= 0;
    if (unlikely(!cpy_r_r223)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 57, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r224 = CPyStatic_globals;
    cpy_r_r225 = CPyStatics[109]; /* 'hexbytes' */
    cpy_r_r226 = CPyDict_GetItem(cpy_r_r224, cpy_r_r225);
    if (unlikely(cpy_r_r226 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 58, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r227 = CPyStatics[147]; /* 'HexBytes' */
    cpy_r_r228 = CPyObject_GetAttr(cpy_r_r226, cpy_r_r227);
    CPy_DECREF(cpy_r_r226);
    if (unlikely(cpy_r_r228 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 58, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_HexBytes = cpy_r_r228;
    CPy_INCREF(CPyStatic_HexBytes);
    cpy_r_r229 = CPyStatic_globals;
    cpy_r_r230 = CPyStatics[147]; /* 'HexBytes' */
    cpy_r_r231 = CPyDict_SetItem(cpy_r_r229, cpy_r_r230, cpy_r_r228);
    CPy_DECREF(cpy_r_r228);
    cpy_r_r232 = cpy_r_r231 >= 0;
    if (unlikely(!cpy_r_r232)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 58, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r233 = CPyStatic_globals;
    cpy_r_r234 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r235 = CPyDict_GetItem(cpy_r_r233, cpy_r_r234);
    if (unlikely(cpy_r_r235 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r236 = CPyStatics[148]; /* 'network' */
    cpy_r_r237 = CPyObject_GetAttr(cpy_r_r235, cpy_r_r236);
    CPy_DECREF(cpy_r_r235);
    if (unlikely(cpy_r_r237 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r238 = CPyStatics[149]; /* 'contract' */
    cpy_r_r239 = CPyObject_GetAttr(cpy_r_r237, cpy_r_r238);
    CPy_DECREF(cpy_r_r237);
    if (unlikely(cpy_r_r239 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r240 = CPyStatics[150]; /* 'Contract' */
    cpy_r_r241 = CPyObject_GetAttr(cpy_r_r239, cpy_r_r240);
    CPy_DECREF(cpy_r_r239);
    if (unlikely(cpy_r_r241 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_Contract = cpy_r_r241;
    CPy_INCREF(CPyStatic_Contract);
    cpy_r_r242 = CPyStatic_globals;
    cpy_r_r243 = CPyStatics[150]; /* 'Contract' */
    cpy_r_r244 = CPyDict_SetItem(cpy_r_r242, cpy_r_r243, cpy_r_r241);
    CPy_DECREF(cpy_r_r241);
    cpy_r_r245 = cpy_r_r244 >= 0;
    if (unlikely(!cpy_r_r245)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r246 = CPyStatic_globals;
    cpy_r_r247 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r248 = CPyDict_GetItem(cpy_r_r246, cpy_r_r247);
    if (unlikely(cpy_r_r248 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r249 = CPyStatics[151]; /* 'convert' */
    cpy_r_r250 = CPyObject_GetAttr(cpy_r_r248, cpy_r_r249);
    CPy_DECREF(cpy_r_r248);
    if (unlikely(cpy_r_r250 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r251 = CPyStatics[152]; /* 'datatypes' */
    cpy_r_r252 = CPyObject_GetAttr(cpy_r_r250, cpy_r_r251);
    CPy_DECREF(cpy_r_r250);
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r253 = CPyStatics[153]; /* 'ReturnValue' */
    cpy_r_r254 = CPyObject_GetAttr(cpy_r_r252, cpy_r_r253);
    CPy_DECREF(cpy_r_r252);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_ReturnValue = cpy_r_r254;
    CPy_INCREF(CPyStatic_ReturnValue);
    cpy_r_r255 = CPyStatic_globals;
    cpy_r_r256 = CPyStatics[153]; /* 'ReturnValue' */
    cpy_r_r257 = CPyDict_SetItem(cpy_r_r255, cpy_r_r256, cpy_r_r254);
    CPy_DECREF(cpy_r_r254);
    cpy_r_r258 = cpy_r_r257 >= 0;
    if (unlikely(!cpy_r_r258)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r259 = CPyStatic_globals;
    cpy_r_r260 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r261 = CPyDict_GetItem(cpy_r_r259, cpy_r_r260);
    if (unlikely(cpy_r_r261 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r262 = CPyStatics[151]; /* 'convert' */
    cpy_r_r263 = CPyObject_GetAttr(cpy_r_r261, cpy_r_r262);
    CPy_DECREF(cpy_r_r261);
    if (unlikely(cpy_r_r263 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r264 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r265 = CPyObject_GetAttr(cpy_r_r263, cpy_r_r264);
    CPy_DECREF(cpy_r_r263);
    if (unlikely(cpy_r_r265 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r266 = CPyStatics[155]; /* 'HexString' */
    cpy_r_r267 = CPyObject_GetAttr(cpy_r_r265, cpy_r_r266);
    CPy_DECREF(cpy_r_r265);
    if (unlikely(cpy_r_r267 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_HexString = cpy_r_r267;
    CPy_INCREF(CPyStatic_HexString);
    cpy_r_r268 = CPyStatic_globals;
    cpy_r_r269 = CPyStatics[155]; /* 'HexString' */
    cpy_r_r270 = CPyDict_SetItem(cpy_r_r268, cpy_r_r269, cpy_r_r267);
    CPy_DECREF(cpy_r_r267);
    cpy_r_r271 = cpy_r_r270 >= 0;
    if (unlikely(!cpy_r_r271)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r272 = CPyStatic_globals;
    cpy_r_r273 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r274 = CPyDict_GetItem(cpy_r_r272, cpy_r_r273);
    if (unlikely(cpy_r_r274 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 62, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r275 = CPyStatics[151]; /* 'convert' */
    cpy_r_r276 = CPyObject_GetAttr(cpy_r_r274, cpy_r_r275);
    CPy_DECREF(cpy_r_r274);
    if (unlikely(cpy_r_r276 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 62, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r277 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r278 = CPyObject_GetAttr(cpy_r_r276, cpy_r_r277);
    CPy_DECREF(cpy_r_r276);
    if (unlikely(cpy_r_r278 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 62, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r279 = CPyStatics[156]; /* 'TupleType' */
    cpy_r_r280 = CPyObject_GetAttr(cpy_r_r278, cpy_r_r279);
    CPy_DECREF(cpy_r_r278);
    if (unlikely(cpy_r_r280 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 62, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_TupleType = cpy_r_r280;
    CPy_INCREF(CPyStatic_TupleType);
    cpy_r_r281 = CPyStatic_globals;
    cpy_r_r282 = CPyStatics[156]; /* 'TupleType' */
    cpy_r_r283 = CPyDict_SetItem(cpy_r_r281, cpy_r_r282, cpy_r_r280);
    CPy_DECREF(cpy_r_r280);
    cpy_r_r284 = cpy_r_r283 >= 0;
    if (unlikely(!cpy_r_r284)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 62, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r285 = CPyStatic_globals;
    cpy_r_r286 = CPyStatics[129]; /* 'exceptions' */
    cpy_r_r287 = CPyDict_GetItem(cpy_r_r285, cpy_r_r286);
    if (unlikely(cpy_r_r287 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 64, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r288 = CPyStatics[157]; /* 'Revert' */
    cpy_r_r289 = CPyObject_GetAttr(cpy_r_r287, cpy_r_r288);
    CPy_DECREF(cpy_r_r287);
    if (unlikely(cpy_r_r289 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 64, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_Revert = cpy_r_r289;
    CPy_INCREF(CPyStatic_Revert);
    cpy_r_r290 = CPyStatic_globals;
    cpy_r_r291 = CPyStatics[157]; /* 'Revert' */
    cpy_r_r292 = CPyDict_SetItem(cpy_r_r290, cpy_r_r291, cpy_r_r289);
    CPy_DECREF(cpy_r_r289);
    cpy_r_r293 = cpy_r_r292 >= 0;
    if (unlikely(!cpy_r_r293)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 64, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r294 = CPyStatic_globals;
    cpy_r_r295 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r296 = CPyDict_GetItem(cpy_r_r294, cpy_r_r295);
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 66, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r297 = CPyStatics[151]; /* 'convert' */
    cpy_r_r298 = CPyObject_GetAttr(cpy_r_r296, cpy_r_r297);
    CPy_DECREF(cpy_r_r296);
    if (unlikely(cpy_r_r298 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 66, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r299 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r300 = CPyObject_GetAttr(cpy_r_r298, cpy_r_r299);
    CPy_DECREF(cpy_r_r298);
    if (unlikely(cpy_r_r300 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 66, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r301 = CPyStatics[158]; /* 'to_bool' */
    cpy_r_r302 = CPyObject_GetAttr(cpy_r_r300, cpy_r_r301);
    CPy_DECREF(cpy_r_r300);
    if (unlikely(cpy_r_r302 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 66, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_to_bool = cpy_r_r302;
    CPy_INCREF(CPyStatic_to_bool);
    cpy_r_r303 = CPyStatic_globals;
    cpy_r_r304 = CPyStatics[158]; /* 'to_bool' */
    cpy_r_r305 = CPyDict_SetItem(cpy_r_r303, cpy_r_r304, cpy_r_r302);
    CPy_DECREF(cpy_r_r302);
    cpy_r_r306 = cpy_r_r305 >= 0;
    if (unlikely(!cpy_r_r306)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 66, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r307 = CPyStatic_globals;
    cpy_r_r308 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r309 = CPyDict_GetItem(cpy_r_r307, cpy_r_r308);
    if (unlikely(cpy_r_r309 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 67, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r310 = CPyStatics[151]; /* 'convert' */
    cpy_r_r311 = CPyObject_GetAttr(cpy_r_r309, cpy_r_r310);
    CPy_DECREF(cpy_r_r309);
    if (unlikely(cpy_r_r311 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 67, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r312 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r313 = CPyObject_GetAttr(cpy_r_r311, cpy_r_r312);
    CPy_DECREF(cpy_r_r311);
    if (unlikely(cpy_r_r313 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 67, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r314 = CPyStatics[159]; /* 'to_decimal' */
    cpy_r_r315 = CPyObject_GetAttr(cpy_r_r313, cpy_r_r314);
    CPy_DECREF(cpy_r_r313);
    if (unlikely(cpy_r_r315 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 67, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_to_decimal = cpy_r_r315;
    CPy_INCREF(CPyStatic_to_decimal);
    cpy_r_r316 = CPyStatic_globals;
    cpy_r_r317 = CPyStatics[159]; /* 'to_decimal' */
    cpy_r_r318 = CPyDict_SetItem(cpy_r_r316, cpy_r_r317, cpy_r_r315);
    CPy_DECREF(cpy_r_r315);
    cpy_r_r319 = cpy_r_r318 >= 0;
    if (unlikely(!cpy_r_r319)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 67, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r320 = CPyStatic_globals;
    cpy_r_r321 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r322 = CPyDict_GetItem(cpy_r_r320, cpy_r_r321);
    if (unlikely(cpy_r_r322 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 68, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r323 = CPyStatics[151]; /* 'convert' */
    cpy_r_r324 = CPyObject_GetAttr(cpy_r_r322, cpy_r_r323);
    CPy_DECREF(cpy_r_r322);
    if (unlikely(cpy_r_r324 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 68, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r325 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r326 = CPyObject_GetAttr(cpy_r_r324, cpy_r_r325);
    CPy_DECREF(cpy_r_r324);
    if (unlikely(cpy_r_r326 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 68, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r327 = CPyStatics[160]; /* 'to_int' */
    cpy_r_r328 = CPyObject_GetAttr(cpy_r_r326, cpy_r_r327);
    CPy_DECREF(cpy_r_r326);
    if (unlikely(cpy_r_r328 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 68, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_to_int = cpy_r_r328;
    CPy_INCREF(CPyStatic_to_int);
    cpy_r_r329 = CPyStatic_globals;
    cpy_r_r330 = CPyStatics[160]; /* 'to_int' */
    cpy_r_r331 = CPyDict_SetItem(cpy_r_r329, cpy_r_r330, cpy_r_r328);
    CPy_DECREF(cpy_r_r328);
    cpy_r_r332 = cpy_r_r331 >= 0;
    if (unlikely(!cpy_r_r332)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 68, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r333 = CPyStatic_globals;
    cpy_r_r334 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r335 = CPyDict_GetItem(cpy_r_r333, cpy_r_r334);
    if (unlikely(cpy_r_r335 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 69, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r336 = CPyStatics[151]; /* 'convert' */
    cpy_r_r337 = CPyObject_GetAttr(cpy_r_r335, cpy_r_r336);
    CPy_DECREF(cpy_r_r335);
    if (unlikely(cpy_r_r337 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 69, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r338 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r339 = CPyObject_GetAttr(cpy_r_r337, cpy_r_r338);
    CPy_DECREF(cpy_r_r337);
    if (unlikely(cpy_r_r339 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 69, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r340 = CPyStatics[161]; /* 'to_string' */
    cpy_r_r341 = CPyObject_GetAttr(cpy_r_r339, cpy_r_r340);
    CPy_DECREF(cpy_r_r339);
    if (unlikely(cpy_r_r341 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 69, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_to_string = cpy_r_r341;
    CPy_INCREF(CPyStatic_to_string);
    cpy_r_r342 = CPyStatic_globals;
    cpy_r_r343 = CPyStatics[161]; /* 'to_string' */
    cpy_r_r344 = CPyDict_SetItem(cpy_r_r342, cpy_r_r343, cpy_r_r341);
    CPy_DECREF(cpy_r_r341);
    cpy_r_r345 = cpy_r_r344 >= 0;
    if (unlikely(!cpy_r_r345)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 69, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r346 = CPyStatic_globals;
    cpy_r_r347 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r348 = CPyDict_GetItem(cpy_r_r346, cpy_r_r347);
    if (unlikely(cpy_r_r348 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 70, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r349 = CPyStatics[151]; /* 'convert' */
    cpy_r_r350 = CPyObject_GetAttr(cpy_r_r348, cpy_r_r349);
    CPy_DECREF(cpy_r_r348);
    if (unlikely(cpy_r_r350 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 70, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r351 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r352 = CPyObject_GetAttr(cpy_r_r350, cpy_r_r351);
    CPy_DECREF(cpy_r_r350);
    if (unlikely(cpy_r_r352 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 70, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r353 = CPyStatics[162]; /* 'to_uint' */
    cpy_r_r354 = CPyObject_GetAttr(cpy_r_r352, cpy_r_r353);
    CPy_DECREF(cpy_r_r352);
    if (unlikely(cpy_r_r354 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 70, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_to_uint = cpy_r_r354;
    CPy_INCREF(CPyStatic_to_uint);
    cpy_r_r355 = CPyStatic_globals;
    cpy_r_r356 = CPyStatics[162]; /* 'to_uint' */
    cpy_r_r357 = CPyDict_SetItem(cpy_r_r355, cpy_r_r356, cpy_r_r354);
    CPy_DECREF(cpy_r_r354);
    cpy_r_r358 = cpy_r_r357 >= 0;
    if (unlikely(!cpy_r_r358)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 70, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r359 = CPyStatic_globals;
    cpy_r_r360 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r361 = CPyDict_GetItem(cpy_r_r359, cpy_r_r360);
    if (unlikely(cpy_r_r361 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 71, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r362 = CPyStatics[151]; /* 'convert' */
    cpy_r_r363 = CPyObject_GetAttr(cpy_r_r361, cpy_r_r362);
    CPy_DECREF(cpy_r_r361);
    if (unlikely(cpy_r_r363 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 71, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r364 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r365 = CPyObject_GetAttr(cpy_r_r363, cpy_r_r364);
    CPy_DECREF(cpy_r_r363);
    if (unlikely(cpy_r_r365 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 71, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r366 = CPyStatics[163]; /* '_check_array' */
    cpy_r_r367 = CPyObject_GetAttr(cpy_r_r365, cpy_r_r366);
    CPy_DECREF(cpy_r_r365);
    if (unlikely(cpy_r_r367 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 71, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic__check_array = cpy_r_r367;
    CPy_INCREF(CPyStatic__check_array);
    cpy_r_r368 = CPyStatic_globals;
    cpy_r_r369 = CPyStatics[163]; /* '_check_array' */
    cpy_r_r370 = CPyDict_SetItem(cpy_r_r368, cpy_r_r369, cpy_r_r367);
    CPy_DECREF(cpy_r_r367);
    cpy_r_r371 = cpy_r_r370 >= 0;
    if (unlikely(!cpy_r_r371)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 71, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r372 = CPyStatic_globals;
    cpy_r_r373 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r374 = CPyDict_GetItem(cpy_r_r372, cpy_r_r373);
    if (unlikely(cpy_r_r374 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 72, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r375 = CPyStatics[151]; /* 'convert' */
    cpy_r_r376 = CPyObject_GetAttr(cpy_r_r374, cpy_r_r375);
    CPy_DECREF(cpy_r_r374);
    if (unlikely(cpy_r_r376 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 72, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r377 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r378 = CPyObject_GetAttr(cpy_r_r376, cpy_r_r377);
    CPy_DECREF(cpy_r_r376);
    if (unlikely(cpy_r_r378 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 72, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r379 = CPyStatics[164]; /* '_get_abi_types' */
    cpy_r_r380 = CPyObject_GetAttr(cpy_r_r378, cpy_r_r379);
    CPy_DECREF(cpy_r_r378);
    if (unlikely(cpy_r_r380 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 72, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic__get_abi_types = cpy_r_r380;
    CPy_INCREF(CPyStatic__get_abi_types);
    cpy_r_r381 = CPyStatic_globals;
    cpy_r_r382 = CPyStatics[164]; /* '_get_abi_types' */
    cpy_r_r383 = CPyDict_SetItem(cpy_r_r381, cpy_r_r382, cpy_r_r380);
    CPy_DECREF(cpy_r_r380);
    cpy_r_r384 = cpy_r_r383 >= 0;
    if (unlikely(!cpy_r_r384)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 72, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r385 = CPyStatic_globals;
    cpy_r_r386 = CPyStatics[165]; /* '__name__' */
    cpy_r_r387 = CPyDict_GetItem(cpy_r_r385, cpy_r_r386);
    if (unlikely(cpy_r_r387 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 75, CPyStatic_globals);
        goto CPyL219;
    }
    if (likely(PyUnicode_Check(cpy_r_r387)))
        cpy_r_r388 = cpy_r_r387;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "<module>", 75, CPyStatic_globals, "str", cpy_r_r387);
        goto CPyL219;
    }
    cpy_r_r389 = CPyStatic_globals;
    cpy_r_r390 = CPyStatics[88]; /* 'getLogger' */
    cpy_r_r391 = CPyDict_GetItem(cpy_r_r389, cpy_r_r390);
    if (unlikely(cpy_r_r391 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 75, CPyStatic_globals);
        goto CPyL228;
    }
    PyObject *cpy_r_r392[1] = {cpy_r_r388};
    cpy_r_r393 = (PyObject **)&cpy_r_r392;
    cpy_r_r394 = _PyObject_Vectorcall(cpy_r_r391, cpy_r_r393, 1, 0);
    CPy_DECREF(cpy_r_r391);
    if (unlikely(cpy_r_r394 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 75, CPyStatic_globals);
        goto CPyL228;
    }
    CPy_DECREF(cpy_r_r388);
    CPyStatic_logger = cpy_r_r394;
    CPy_INCREF(CPyStatic_logger);
    cpy_r_r395 = CPyStatic_globals;
    cpy_r_r396 = CPyStatics[166]; /* 'logger' */
    cpy_r_r397 = CPyDict_SetItem(cpy_r_r395, cpy_r_r396, cpy_r_r394);
    CPy_DECREF(cpy_r_r394);
    cpy_r_r398 = cpy_r_r397 >= 0;
    if (unlikely(!cpy_r_r398)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 75, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r399 = CPyDef___mypyc_lambda__0_obj();
    if (unlikely(cpy_r_r399 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 78, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_encode = cpy_r_r399;
    CPy_INCREF(CPyStatic_encode);
    cpy_r_r400 = CPyStatic_globals;
    cpy_r_r401 = CPyStatics[167]; /* 'encode' */
    cpy_r_r402 = CPyDict_SetItem(cpy_r_r400, cpy_r_r401, cpy_r_r399);
    CPy_DECREF(cpy_r_r399);
    cpy_r_r403 = cpy_r_r402 >= 0;
    if (unlikely(!cpy_r_r403)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 78, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r404 = CPyDef___mypyc_lambda__1_obj();
    if (unlikely(cpy_r_r404 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 97, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_decode = cpy_r_r404;
    CPy_INCREF(CPyStatic_decode);
    cpy_r_r405 = CPyStatic_globals;
    cpy_r_r406 = CPyStatics[168]; /* 'decode' */
    cpy_r_r407 = CPyDict_SetItem(cpy_r_r405, cpy_r_r406, cpy_r_r404);
    CPy_DECREF(cpy_r_r404);
    cpy_r_r408 = cpy_r_r407 >= 0;
    if (unlikely(!cpy_r_r408)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 97, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r409 = CPyStatic_globals;
    cpy_r_r410 = CPyStatics[120]; /* 'Address' */
    cpy_r_r411 = CPyDict_GetItem(cpy_r_r409, cpy_r_r410);
    if (unlikely(cpy_r_r411 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 118, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r412 = CPyStatics[169]; /* 'checksum' */
    cpy_r_r413 = CPyObject_GetAttr(cpy_r_r411, cpy_r_r412);
    CPy_DECREF(cpy_r_r411);
    if (unlikely(cpy_r_r413 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 118, CPyStatic_globals);
        goto CPyL219;
    }
    CPyStatic_to_checksum_address = cpy_r_r413;
    CPy_INCREF(CPyStatic_to_checksum_address);
    cpy_r_r414 = CPyStatic_globals;
    cpy_r_r415 = CPyStatics[170]; /* 'to_checksum_address' */
    cpy_r_r416 = CPyDict_SetItem(cpy_r_r414, cpy_r_r415, cpy_r_r413);
    CPy_DECREF(cpy_r_r413);
    cpy_r_r417 = cpy_r_r416 >= 0;
    if (unlikely(!cpy_r_r417)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 118, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r418 = CPyStatic_globals;
    cpy_r_r419 = CPyStatics[14]; /* '_get_coroutine_fn' */
    cpy_r_r420 = CPyDict_GetItem(cpy_r_r418, cpy_r_r419);
    if (unlikely(cpy_r_r420 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 136, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r421 = CPyStatic_globals;
    cpy_r_r422 = CPyStatics[133]; /* 'lru_cache_lite_nonull' */
    cpy_r_r423 = CPyDict_GetItem(cpy_r_r421, cpy_r_r422);
    if (unlikely(cpy_r_r423 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 136, CPyStatic_globals);
        goto CPyL229;
    }
    PyObject *cpy_r_r424[1] = {cpy_r_r420};
    cpy_r_r425 = (PyObject **)&cpy_r_r424;
    cpy_r_r426 = _PyObject_Vectorcall(cpy_r_r423, cpy_r_r425, 1, 0);
    CPy_DECREF(cpy_r_r423);
    if (unlikely(cpy_r_r426 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 136, CPyStatic_globals);
        goto CPyL229;
    }
    CPy_DECREF(cpy_r_r420);
    cpy_r_r427 = CPyStatic_globals;
    cpy_r_r428 = CPyStatics[14]; /* '_get_coroutine_fn' */
    cpy_r_r429 = CPyDict_SetItem(cpy_r_r427, cpy_r_r428, cpy_r_r426);
    CPy_DECREF(cpy_r_r426);
    cpy_r_r430 = cpy_r_r429 >= 0;
    if (unlikely(!cpy_r_r430)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 136, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r431 = CPyStatic_globals;
    cpy_r_r432 = CPyStatics[52]; /* 'eth_abi' */
    cpy_r_r433 = CPyDict_GetItem(cpy_r_r431, cpy_r_r432);
    if (unlikely(cpy_r_r433 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r434 = CPyStatics[167]; /* 'encode' */
    cpy_r_r435 = PyObject_HasAttr(cpy_r_r433, cpy_r_r434);
    CPy_DECREF(cpy_r_r433);
    if (!cpy_r_r435) goto CPyL145;
    cpy_r_r436 = CPyStatic_globals;
    cpy_r_r437 = CPyStatics[52]; /* 'eth_abi' */
    cpy_r_r438 = CPyDict_GetItem(cpy_r_r436, cpy_r_r437);
    if (unlikely(cpy_r_r438 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r439 = CPyStatics[167]; /* 'encode' */
    cpy_r_r440 = CPyObject_GetAttr(cpy_r_r438, cpy_r_r439);
    CPy_DECREF(cpy_r_r438);
    if (unlikely(cpy_r_r440 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r441 = cpy_r_r440;
    goto CPyL148;
CPyL145: ;
    cpy_r_r442 = CPyStatic_globals;
    cpy_r_r443 = CPyStatics[52]; /* 'eth_abi' */
    cpy_r_r444 = CPyDict_GetItem(cpy_r_r442, cpy_r_r443);
    if (unlikely(cpy_r_r444 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r445 = CPyStatics[171]; /* 'encode_abi' */
    cpy_r_r446 = CPyObject_GetAttr(cpy_r_r444, cpy_r_r445);
    CPy_DECREF(cpy_r_r444);
    if (unlikely(cpy_r_r446 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r441 = cpy_r_r446;
CPyL148: ;
    CPyStatic___eth_abi_encode = cpy_r_r441;
    CPy_INCREF(CPyStatic___eth_abi_encode);
    cpy_r_r447 = CPyStatic_globals;
    cpy_r_r448 = CPyStatics[172]; /* '__eth_abi_encode' */
    cpy_r_r449 = CPyDict_SetItem(cpy_r_r447, cpy_r_r448, cpy_r_r441);
    CPy_DECREF(cpy_r_r441);
    cpy_r_r450 = cpy_r_r449 >= 0;
    if (unlikely(!cpy_r_r450)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r451 = CPyStatic_globals;
    cpy_r_r452 = CPyStatics[52]; /* 'eth_abi' */
    cpy_r_r453 = CPyDict_GetItem(cpy_r_r451, cpy_r_r452);
    if (unlikely(cpy_r_r453 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 237, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r454 = CPyStatics[168]; /* 'decode' */
    cpy_r_r455 = PyObject_HasAttr(cpy_r_r453, cpy_r_r454);
    CPy_DECREF(cpy_r_r453);
    if (!cpy_r_r455) goto CPyL154;
    cpy_r_r456 = CPyStatic_globals;
    cpy_r_r457 = CPyStatics[52]; /* 'eth_abi' */
    cpy_r_r458 = CPyDict_GetItem(cpy_r_r456, cpy_r_r457);
    if (unlikely(cpy_r_r458 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 237, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r459 = CPyStatics[168]; /* 'decode' */
    cpy_r_r460 = CPyObject_GetAttr(cpy_r_r458, cpy_r_r459);
    CPy_DECREF(cpy_r_r458);
    if (unlikely(cpy_r_r460 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 237, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r461 = cpy_r_r460;
    goto CPyL157;
CPyL154: ;
    cpy_r_r462 = CPyStatic_globals;
    cpy_r_r463 = CPyStatics[52]; /* 'eth_abi' */
    cpy_r_r464 = CPyDict_GetItem(cpy_r_r462, cpy_r_r463);
    if (unlikely(cpy_r_r464 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 237, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r465 = CPyStatics[54]; /* 'decode_abi' */
    cpy_r_r466 = CPyObject_GetAttr(cpy_r_r464, cpy_r_r465);
    CPy_DECREF(cpy_r_r464);
    if (unlikely(cpy_r_r466 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 237, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r461 = cpy_r_r466;
CPyL157: ;
    CPyStatic___eth_abi_decode = cpy_r_r461;
    CPy_INCREF(CPyStatic___eth_abi_decode);
    cpy_r_r467 = CPyStatic_globals;
    cpy_r_r468 = CPyStatics[173]; /* '__eth_abi_decode' */
    cpy_r_r469 = CPyDict_SetItem(cpy_r_r467, cpy_r_r468, cpy_r_r461);
    CPy_DECREF(cpy_r_r461);
    cpy_r_r470 = cpy_r_r469 >= 0;
    if (unlikely(!cpy_r_r470)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 237, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r471 = CPyStatics[174]; /* '0xcA11bde05977b3631167028862bE2a173976CA11' */
    cpy_r_r472 = PySet_New(NULL);
    if (unlikely(cpy_r_r472 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 250, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r473 = PySet_Add(cpy_r_r472, cpy_r_r471);
    cpy_r_r474 = cpy_r_r473 >= 0;
    if (unlikely(!cpy_r_r474)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 250, CPyStatic_globals);
        goto CPyL230;
    }
    cpy_r_r475 = CPyStatic_globals;
    cpy_r_r476 = CPyStatics[11]; /* '_skip_proc_pool' */
    cpy_r_r477 = CPyDict_SetItem(cpy_r_r475, cpy_r_r476, cpy_r_r472);
    CPy_DECREF(cpy_r_r472);
    cpy_r_r478 = cpy_r_r477 >= 0;
    if (unlikely(!cpy_r_r478)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 250, CPyStatic_globals);
        goto CPyL219;
    }
CPyL161: ;
    if (!1) goto CPyL179;
    cpy_r_r479 = CPyStatic_globals;
    cpy_r_r480 = CPyStatics[111]; /* 'chain' */
    cpy_r_r481 = CPyDict_GetItem(cpy_r_r479, cpy_r_r480);
    if (unlikely(cpy_r_r481 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 254, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r482 = CPyStatics[175]; /* 'id' */
    cpy_r_r483 = CPyObject_GetAttr(cpy_r_r481, cpy_r_r482);
    CPy_DECREF(cpy_r_r481);
    if (unlikely(cpy_r_r483 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 254, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r484 = CPyStatic_globals;
    cpy_r_r485 = CPyStatics[176]; /* 'chainid' */
    cpy_r_r486 = CPyDict_SetItem(cpy_r_r484, cpy_r_r485, cpy_r_r483);
    CPy_DECREF(cpy_r_r483);
    cpy_r_r487 = cpy_r_r486 >= 0;
    if (unlikely(!cpy_r_r487)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 254, CPyStatic_globals);
    } else
        goto CPyL179;
CPyL165: ;
    cpy_r_r488 = CPy_CatchError();
    cpy_r_r489 = CPyModule_builtins;
    cpy_r_r490 = CPyStatics[43]; /* 'Exception' */
    cpy_r_r491 = CPyObject_GetAttr(cpy_r_r489, cpy_r_r490);
    if (unlikely(cpy_r_r491 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 256, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r492 = CPy_ExceptionMatches(cpy_r_r491);
    CPy_DecRef(cpy_r_r491);
    if (!cpy_r_r492) goto CPyL174;
    cpy_r_r493 = CPyStatic_globals;
    cpy_r_r494 = CPyStatics[177]; /* 'e' */
    cpy_r_r495 = CPy_GetExcValue();
    cpy_r_r496 = CPyDict_SetItem(cpy_r_r493, cpy_r_r494, cpy_r_r495);
    CPy_DecRef(cpy_r_r495);
    cpy_r_r497 = cpy_r_r496 >= 0;
    if (unlikely(!cpy_r_r497)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 256, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r498 = CPyStatics[178]; /* '429' */
    cpy_r_r499 = CPyStatic_globals;
    cpy_r_r500 = CPyStatics[177]; /* 'e' */
    cpy_r_r501 = CPyDict_GetItem(cpy_r_r499, cpy_r_r500);
    if (unlikely(cpy_r_r501 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 257, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r502 = PyObject_Str(cpy_r_r501);
    CPy_DecRef(cpy_r_r501);
    if (unlikely(cpy_r_r502 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 257, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r503 = PySequence_Contains(cpy_r_r502, cpy_r_r498);
    CPy_DecRef(cpy_r_r502);
    cpy_r_r504 = cpy_r_r503 >= 0;
    if (unlikely(!cpy_r_r504)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 257, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r505 = cpy_r_r503;
    cpy_r_r506 = cpy_r_r505 ^ 1;
    if (!cpy_r_r506) goto CPyL176;
    CPy_Reraise();
    if (!0) {
        goto CPyL177;
    } else
        goto CPyL231;
CPyL173: ;
    CPy_Unreachable();
CPyL174: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL177;
    } else
        goto CPyL232;
CPyL175: ;
    CPy_Unreachable();
CPyL176: ;
    CPy_RestoreExcInfo(cpy_r_r488);
    CPy_DecRef(cpy_r_r488.f0);
    CPy_DecRef(cpy_r_r488.f1);
    CPy_DecRef(cpy_r_r488.f2);
    goto CPyL161;
CPyL177: ;
    CPy_RestoreExcInfo(cpy_r_r488);
    CPy_DecRef(cpy_r_r488.f0);
    CPy_DecRef(cpy_r_r488.f1);
    CPy_DecRef(cpy_r_r488.f2);
    cpy_r_r507 = CPy_KeepPropagating();
    if (!cpy_r_r507) goto CPyL219;
    CPy_Unreachable();
CPyL179: ;
    cpy_r_r508 = CPyStatic_globals;
    cpy_r_r509 = CPyStatics[124]; /* 'MULTICALL2_ADDRESSES' */
    cpy_r_r510 = CPyDict_GetItem(cpy_r_r508, cpy_r_r509);
    if (unlikely(cpy_r_r510 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 259, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r511 = CPyStatic_globals;
    cpy_r_r512 = CPyStatics[176]; /* 'chainid' */
    cpy_r_r513 = CPyDict_GetItem(cpy_r_r511, cpy_r_r512);
    if (unlikely(cpy_r_r513 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 259, CPyStatic_globals);
        goto CPyL233;
    }
    cpy_r_r514 = CPyStatics[179]; /* 'get' */
    cpy_r_r515 = Py_None;
    PyObject *cpy_r_r516[3] = {cpy_r_r510, cpy_r_r513, cpy_r_r515};
    cpy_r_r517 = (PyObject **)&cpy_r_r516;
    cpy_r_r518 = PyObject_VectorcallMethod(cpy_r_r514, cpy_r_r517, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r518 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 259, CPyStatic_globals);
        goto CPyL234;
    }
    CPy_DECREF(cpy_r_r510);
    CPy_DECREF(cpy_r_r513);
    cpy_r_r519 = CPyStatic_globals;
    cpy_r_r520 = CPyStatics[180]; /* 'multicall2' */
    cpy_r_r521 = CPyDict_SetItem(cpy_r_r519, cpy_r_r520, cpy_r_r518);
    cpy_r_r522 = cpy_r_r521 >= 0;
    if (unlikely(!cpy_r_r522)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 259, CPyStatic_globals);
        goto CPyL235;
    }
    cpy_r_r523 = PyObject_IsTrue(cpy_r_r518);
    CPy_DECREF(cpy_r_r518);
    cpy_r_r524 = cpy_r_r523 >= 0;
    if (unlikely(!cpy_r_r524)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 259, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r525 = cpy_r_r523;
    if (!cpy_r_r525) goto CPyL193;
    cpy_r_r526 = CPyStatic_globals;
    cpy_r_r527 = CPyStatics[11]; /* '_skip_proc_pool' */
    cpy_r_r528 = CPyDict_GetItem(cpy_r_r526, cpy_r_r527);
    if (unlikely(cpy_r_r528 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 260, CPyStatic_globals);
        goto CPyL219;
    }
    if (likely(PySet_Check(cpy_r_r528)))
        cpy_r_r529 = cpy_r_r528;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "<module>", 260, CPyStatic_globals, "set", cpy_r_r528);
        goto CPyL219;
    }
    cpy_r_r530 = CPyStatic_globals;
    cpy_r_r531 = CPyStatics[180]; /* 'multicall2' */
    cpy_r_r532 = CPyDict_GetItem(cpy_r_r530, cpy_r_r531);
    if (unlikely(cpy_r_r532 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 260, CPyStatic_globals);
        goto CPyL236;
    }
    cpy_r_r533 = CPyStatic_to_checksum_address;
    if (unlikely(cpy_r_r533 == NULL)) {
        goto CPyL237;
    } else
        goto CPyL191;
CPyL189: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_checksum_address\" was not set");
    cpy_r_r534 = 0;
    if (unlikely(!cpy_r_r534)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 260, CPyStatic_globals);
        goto CPyL219;
    }
    CPy_Unreachable();
CPyL191: ;
    PyObject *cpy_r_r535[1] = {cpy_r_r532};
    cpy_r_r536 = (PyObject **)&cpy_r_r535;
    cpy_r_r537 = _PyObject_Vectorcall(cpy_r_r533, cpy_r_r536, 1, 0);
    if (unlikely(cpy_r_r537 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 260, CPyStatic_globals);
        goto CPyL238;
    }
    CPy_DECREF(cpy_r_r532);
    cpy_r_r538 = PySet_Add(cpy_r_r529, cpy_r_r537);
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r537);
    cpy_r_r539 = cpy_r_r538 >= 0;
    if (unlikely(!cpy_r_r539)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 260, CPyStatic_globals);
        goto CPyL219;
    }
CPyL193: ;
    cpy_r_r540 = CPyStatic_globals;
    cpy_r_r541 = CPyStatics[181]; /* 'format_input_but_cache_checksums' */
    cpy_r_r542 = CPyDict_GetItem(cpy_r_r540, cpy_r_r541);
    if (unlikely(cpy_r_r542 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 320, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r543 = CPyStatic_globals;
    cpy_r_r544 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r545 = CPyDict_GetItem(cpy_r_r543, cpy_r_r544);
    if (unlikely(cpy_r_r545 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 320, CPyStatic_globals);
        goto CPyL239;
    }
    cpy_r_r546 = CPyStatics[148]; /* 'network' */
    cpy_r_r547 = CPyObject_GetAttr(cpy_r_r545, cpy_r_r546);
    CPy_DECREF(cpy_r_r545);
    if (unlikely(cpy_r_r547 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 320, CPyStatic_globals);
        goto CPyL239;
    }
    cpy_r_r548 = CPyStatics[149]; /* 'contract' */
    cpy_r_r549 = CPyObject_GetAttr(cpy_r_r547, cpy_r_r548);
    CPy_DECREF(cpy_r_r547);
    if (unlikely(cpy_r_r549 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 320, CPyStatic_globals);
        goto CPyL239;
    }
    cpy_r_r550 = CPyStatics[182]; /* 'format_input' */
    cpy_r_r551 = PyObject_SetAttr(cpy_r_r549, cpy_r_r550, cpy_r_r542);
    CPy_DECREF(cpy_r_r549);
    CPy_DECREF(cpy_r_r542);
    cpy_r_r552 = cpy_r_r551 >= 0;
    if (unlikely(!cpy_r_r552)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 320, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r553 = CPyStatic_globals;
    cpy_r_r554 = CPyStatics[183]; /* 'format_output_but_cache_checksums' */
    cpy_r_r555 = CPyDict_GetItem(cpy_r_r553, cpy_r_r554);
    if (unlikely(cpy_r_r555 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 321, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r556 = CPyStatic_globals;
    cpy_r_r557 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r558 = CPyDict_GetItem(cpy_r_r556, cpy_r_r557);
    if (unlikely(cpy_r_r558 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 321, CPyStatic_globals);
        goto CPyL240;
    }
    cpy_r_r559 = CPyStatics[148]; /* 'network' */
    cpy_r_r560 = CPyObject_GetAttr(cpy_r_r558, cpy_r_r559);
    CPy_DECREF(cpy_r_r558);
    if (unlikely(cpy_r_r560 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 321, CPyStatic_globals);
        goto CPyL240;
    }
    cpy_r_r561 = CPyStatics[149]; /* 'contract' */
    cpy_r_r562 = CPyObject_GetAttr(cpy_r_r560, cpy_r_r561);
    CPy_DECREF(cpy_r_r560);
    if (unlikely(cpy_r_r562 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 321, CPyStatic_globals);
        goto CPyL240;
    }
    cpy_r_r563 = CPyStatics[184]; /* 'format_output' */
    cpy_r_r564 = PyObject_SetAttr(cpy_r_r562, cpy_r_r563, cpy_r_r555);
    CPy_DECREF(cpy_r_r562);
    CPy_DECREF(cpy_r_r555);
    cpy_r_r565 = cpy_r_r564 >= 0;
    if (unlikely(!cpy_r_r565)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 321, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r566 = CPyStatic_globals;
    cpy_r_r567 = CPyStatics[185]; /* '_format_array_but_cache_checksums' */
    cpy_r_r568 = CPyDict_GetItem(cpy_r_r566, cpy_r_r567);
    if (unlikely(cpy_r_r568 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 378, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r569 = CPyStatic_globals;
    cpy_r_r570 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r571 = CPyDict_GetItem(cpy_r_r569, cpy_r_r570);
    if (unlikely(cpy_r_r571 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 378, CPyStatic_globals);
        goto CPyL241;
    }
    cpy_r_r572 = CPyStatics[151]; /* 'convert' */
    cpy_r_r573 = CPyObject_GetAttr(cpy_r_r571, cpy_r_r572);
    CPy_DECREF(cpy_r_r571);
    if (unlikely(cpy_r_r573 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 378, CPyStatic_globals);
        goto CPyL241;
    }
    cpy_r_r574 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r575 = CPyObject_GetAttr(cpy_r_r573, cpy_r_r574);
    CPy_DECREF(cpy_r_r573);
    if (unlikely(cpy_r_r575 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 378, CPyStatic_globals);
        goto CPyL241;
    }
    cpy_r_r576 = CPyStatics[186]; /* '_format_array' */
    cpy_r_r577 = PyObject_SetAttr(cpy_r_r575, cpy_r_r576, cpy_r_r568);
    CPy_DECREF(cpy_r_r575);
    CPy_DECREF(cpy_r_r568);
    cpy_r_r578 = cpy_r_r577 >= 0;
    if (unlikely(!cpy_r_r578)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 378, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r579 = CPyStatic_globals;
    cpy_r_r580 = CPyStatics[187]; /* '_format_single_but_cache_checksums' */
    cpy_r_r581 = CPyDict_GetItem(cpy_r_r579, cpy_r_r580);
    if (unlikely(cpy_r_r581 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 379, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r582 = CPyStatic_globals;
    cpy_r_r583 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r584 = CPyDict_GetItem(cpy_r_r582, cpy_r_r583);
    if (unlikely(cpy_r_r584 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 379, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r585 = CPyStatics[151]; /* 'convert' */
    cpy_r_r586 = CPyObject_GetAttr(cpy_r_r584, cpy_r_r585);
    CPy_DECREF(cpy_r_r584);
    if (unlikely(cpy_r_r586 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 379, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r587 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r588 = CPyObject_GetAttr(cpy_r_r586, cpy_r_r587);
    CPy_DECREF(cpy_r_r586);
    if (unlikely(cpy_r_r588 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 379, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r589 = CPyStatics[188]; /* '_format_single' */
    cpy_r_r590 = PyObject_SetAttr(cpy_r_r588, cpy_r_r589, cpy_r_r581);
    CPy_DECREF(cpy_r_r588);
    CPy_DECREF(cpy_r_r581);
    cpy_r_r591 = cpy_r_r590 >= 0;
    if (unlikely(!cpy_r_r591)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 379, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r592 = CPyStatic_globals;
    cpy_r_r593 = CPyStatics[189]; /* '_format_tuple_but_cache_checksums' */
    cpy_r_r594 = CPyDict_GetItem(cpy_r_r592, cpy_r_r593);
    if (unlikely(cpy_r_r594 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 380, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r595 = CPyStatic_globals;
    cpy_r_r596 = CPyStatics[106]; /* 'brownie' */
    cpy_r_r597 = CPyDict_GetItem(cpy_r_r595, cpy_r_r596);
    if (unlikely(cpy_r_r597 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 380, CPyStatic_globals);
        goto CPyL243;
    }
    cpy_r_r598 = CPyStatics[151]; /* 'convert' */
    cpy_r_r599 = CPyObject_GetAttr(cpy_r_r597, cpy_r_r598);
    CPy_DECREF(cpy_r_r597);
    if (unlikely(cpy_r_r599 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 380, CPyStatic_globals);
        goto CPyL243;
    }
    cpy_r_r600 = CPyStatics[154]; /* 'normalize' */
    cpy_r_r601 = CPyObject_GetAttr(cpy_r_r599, cpy_r_r600);
    CPy_DECREF(cpy_r_r599);
    if (unlikely(cpy_r_r601 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 380, CPyStatic_globals);
        goto CPyL243;
    }
    cpy_r_r602 = CPyStatics[190]; /* '_format_tuple' */
    cpy_r_r603 = PyObject_SetAttr(cpy_r_r601, cpy_r_r602, cpy_r_r594);
    CPy_DECREF(cpy_r_r601);
    CPy_DECREF(cpy_r_r594);
    cpy_r_r604 = cpy_r_r603 >= 0;
    if (unlikely(!cpy_r_r604)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 380, CPyStatic_globals);
        goto CPyL219;
    }
    return 1;
CPyL219: ;
    cpy_r_r605 = 2;
    return cpy_r_r605;
CPyL220: ;
    CPy_DecRef(cpy_r_r129);
    goto CPyL219;
CPyL221: ;
    CPy_DecRef(cpy_r_r160);
    goto CPyL219;
CPyL222: ;
    CPy_DecRef(cpy_r_r171);
    goto CPyL219;
CPyL223: ;
    CPy_DecRef(cpy_r_r171);
    CPy_DecRef(cpy_r_r174);
    goto CPyL219;
CPyL224: ;
    CPy_DecRef(cpy_r_r171);
    CPy_DecRef(cpy_r_r178);
    goto CPyL219;
CPyL225: ;
    CPy_DecRef(cpy_r_r171);
    CPy_DecRef(cpy_r_r178);
    CPy_DecRef(cpy_r_r181);
    goto CPyL219;
CPyL226: ;
    CPy_DecRef(cpy_r_r199);
    goto CPyL219;
CPyL227: ;
    CPy_DecRef(cpy_r_r206);
    goto CPyL219;
CPyL228: ;
    CPy_DecRef(cpy_r_r388);
    goto CPyL219;
CPyL229: ;
    CPy_DecRef(cpy_r_r420);
    goto CPyL219;
CPyL230: ;
    CPy_DecRef(cpy_r_r472);
    goto CPyL219;
CPyL231: ;
    CPy_DecRef(cpy_r_r488.f0);
    CPy_DecRef(cpy_r_r488.f1);
    CPy_DecRef(cpy_r_r488.f2);
    goto CPyL173;
CPyL232: ;
    CPy_DecRef(cpy_r_r488.f0);
    CPy_DecRef(cpy_r_r488.f1);
    CPy_DecRef(cpy_r_r488.f2);
    goto CPyL175;
CPyL233: ;
    CPy_DecRef(cpy_r_r510);
    goto CPyL219;
CPyL234: ;
    CPy_DecRef(cpy_r_r510);
    CPy_DecRef(cpy_r_r513);
    goto CPyL219;
CPyL235: ;
    CPy_DecRef(cpy_r_r518);
    goto CPyL219;
CPyL236: ;
    CPy_DecRef(cpy_r_r529);
    goto CPyL219;
CPyL237: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r532);
    goto CPyL189;
CPyL238: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r532);
    goto CPyL219;
CPyL239: ;
    CPy_DecRef(cpy_r_r542);
    goto CPyL219;
CPyL240: ;
    CPy_DecRef(cpy_r_r555);
    goto CPyL219;
CPyL241: ;
    CPy_DecRef(cpy_r_r568);
    goto CPyL219;
CPyL242: ;
    CPy_DecRef(cpy_r_r581);
    goto CPyL219;
CPyL243: ;
    CPy_DecRef(cpy_r_r594);
    goto CPyL219;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___brownie_patch___call = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_decimal = Py_None;
    CPyModule_concurrent___futures___process = Py_None;
    CPyModule_logging = Py_None;
    CPyModule_pickle = Py_None;
    CPyModule_types = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_brownie___convert___datatypes = Py_None;
    CPyModule_brownie___convert___normalize = Py_None;
    CPyModule_brownie___network___contract = Py_None;
    CPyModule_eth_abi = Py_None;
    CPyModule_hexbytes = Py_None;
    CPyModule_a_sync = Py_None;
    CPyModule_brownie = Py_None;
    CPyModule_brownie___convert___utils = Py_None;
    CPyModule_brownie___exceptions = Py_None;
    CPyModule_brownie___project___compiler___solidity = Py_None;
    CPyModule_eth_abi___exceptions = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_evmspec___data = Py_None;
    CPyModule_hexbytes___main = Py_None;
    CPyModule_multicall___constants = Py_None;
    CPyModule_web3___types = Py_None;
    CPyModule_dank_mids = Py_None;
    CPyModule_dank_mids___brownie_patch___types = Py_None;
    CPyModule_dank_mids___helpers___lru_cache = Py_None;
    CPyModule_dank_mids___helpers____helpers = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[227];
const char * const CPyLit_Str[] = {
    "\005\031BROWNIE_ENCODER_PROCESSES\016__encode_input\003abi\tsignature\003run",
    "\004\031BROWNIE_DECODER_PROCESSES\017__decode_output\b_address\017_skip_proc_pool",
    "\005\027_skip_decoder_proc_pool\006inputs\021_get_coroutine_fn\nMethodType\tcoroutine",
    "\003\r_call_no_args\t__await__+Cannot use state override with `coroutine`.",
    "\004\nValueError\031BROWNIE_ENCODER_SEMAPHORE\t__aexit__\n__aenter__",
    "\006\fencode_input\026BROWNIE_CALL_SEMAPHORE\003eth\002to\004data\004call",
    "\003\025InsufficientDataBytes\rGeneratorExit\rStopIteration",
    "\004\025_request_data_no_args\f__contains__\016AttributeError\tTypeError",
    "\001\021BrokenProcessPool",
    "\0027Oh fuck, you broke the %s while decoding %s with abi %s\bcritical",
    "\005\f_max_workers\030AsyncProcessPoolExecutor\rPicklingError\tException\004args",
    "\0022 object has no attribute \'_skip_decoder_proc_pool\'\020DEBUG ME BRO: %s",
    "\a\005debug\020get_type_strings\003hex\aoutputs\n0x08c379a0\aeth_abi\006string",
    "\004\ndecode_abi\017Call reverted: \n0x4e487b71\024SOLIDITY_ERROR_CODES",
    "\004\023Panic (error code: \001)\n0xc1b84b2f!Call reverted: execution reverted",
    "\002/No data was returned - the call likely reverted\023VirtualMachineError",
    "\b\004name\026 requires no arguments\001 \bis_array\ncomponents\vto_type_str\001\'\004\' - ",
    "\t\aarrlist\titem_type\004uint\003int\vfixed168x10\004bool\aaddress\tbytearray\004byte",
    "\004\016Unknown type: \bbuiltins\adecimal\037dank_mids/brownie_patch/call.py",
    "\006\b<module>\032concurrent.futures.process\006Logger\tgetLogger\alogging\006pickle",
    "\t\nModuleType\005types\003Any\bCallable\004Dict\005Final\004List\aNewType\bOptional",
    "\a\bSequence\005Tuple\aTypeVar\005Union\006typing\031brownie.convert.datatypes\abrownie",
    "\004\031brownie.convert.normalize\030brownie.network.contract\bhexbytes\006a_sync",
    "\005\005chain\aABIType\025brownie.convert.utils\022brownie.exceptions\fContractCall",
    "\003!brownie.project.compiler.solidity\022eth_abi.exceptions\006HexStr",
    "\005\neth_typing\aAddress\fevmspec.data\tBytesLike\rhexbytes.main",
    "\004\024MULTICALL2_ADDRESSES\023multicall.constants\017BlockIdentifier\nweb3.types",
    "\004\025ENVIRONMENT_VARIABLES\nexceptions\tdank_mids\016ContractMethod",
    "\002\035dank_mids.brownie_patch.types\025lru_cache_lite_nonull",
    "\004\033dank_mids.helpers.lru_cache\bDankWeb3\032dank_mids.helpers._helpers\004ENVS",
    "\006\016OPERATION_MODE\vapplication\020APPLICATION_MODE\002_T\aTypeStr\bTypeStrs",
    "\a\vListOrTuple\aAbiDict\aDecimal\bHexBytes\anetwork\bcontract\bContract",
    "\a\aconvert\tdatatypes\vReturnValue\tnormalize\tHexString\tTupleType\006Revert",
    "\006\ato_bool\nto_decimal\006to_int\tto_string\ato_uint\f_check_array",
    "\006\016_get_abi_types\b__name__\006logger\006encode\006decode\bchecksum",
    "\004\023to_checksum_address\nencode_abi\020__eth_abi_encode\020__eth_abi_decode",
    "\006*0xcA11bde05977b3631167028862bE2a173976CA11\002id\achainid\001e\003429\003get",
    "\003\nmulticall2 format_input_but_cache_checksums\fformat_input",
    "\002!format_output_but_cache_checksums\rformat_output",
    "\002!_format_array_but_cache_checksums\r_format_array",
    "\002\"_format_single_but_cache_checksums\016_format_single",
    "\002!_format_tuple_but_cache_checksums\r_format_tuple",
    "",
};
const char * const CPyLit_Bytes[] = {
    "\001\020Unexpected error",
    "",
};
const char * const CPyLit_Int[] = {
    "\00510\0004\0000\00016\000-1",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    30, 3, 83, 83, 83, 1, 197, 1, 37, 2, 87, 88, 1, 42, 2, 15, 91, 11,
    93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 3, 105, 106, 106, 3,
    107, 106, 106, 3, 108, 106, 106, 3, 52, 52, 52, 3, 109, 109, 109, 5,
    204, 205, 206, 207, 208, 1, 41, 1, 111, 1, 112, 1, 48, 1, 63, 1, 115,
    1, 57, 1, 30, 1, 118, 1, 120, 1, 122, 1, 124, 1, 126, 2, 128, 129, 1,
    131, 1, 133, 1, 135
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___brownie_patch___call_internal = NULL;
CPyModule *CPyModule_dank_mids___brownie_patch___call;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_decimal;
CPyModule *CPyModule_concurrent___futures___process;
CPyModule *CPyModule_logging;
CPyModule *CPyModule_pickle;
CPyModule *CPyModule_types;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_brownie___convert___datatypes;
CPyModule *CPyModule_brownie___convert___normalize;
CPyModule *CPyModule_brownie___network___contract;
CPyModule *CPyModule_eth_abi;
CPyModule *CPyModule_hexbytes;
CPyModule *CPyModule_a_sync;
CPyModule *CPyModule_brownie;
CPyModule *CPyModule_brownie___convert___utils;
CPyModule *CPyModule_brownie___exceptions;
CPyModule *CPyModule_brownie___project___compiler___solidity;
CPyModule *CPyModule_eth_abi___exceptions;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_evmspec___data;
CPyModule *CPyModule_hexbytes___main;
CPyModule *CPyModule_multicall___constants;
CPyModule *CPyModule_web3___types;
CPyModule *CPyModule_dank_mids;
CPyModule *CPyModule_dank_mids___brownie_patch___types;
CPyModule *CPyModule_dank_mids___helpers___lru_cache;
CPyModule *CPyModule_dank_mids___helpers____helpers;
PyObject *CPyStatic_ENVS = NULL;
char CPyStatic_APPLICATION_MODE = 2;
PyObject *CPyStatic_Decimal = NULL;
PyObject *CPyStatic_HexBytes = NULL;
PyObject *CPyStatic_Contract = NULL;
PyObject *CPyStatic_ReturnValue = NULL;
PyObject *CPyStatic_HexString = NULL;
PyObject *CPyStatic_TupleType = NULL;
PyObject *CPyStatic_Revert = NULL;
PyObject *CPyStatic_to_bool = NULL;
PyObject *CPyStatic_to_decimal = NULL;
PyObject *CPyStatic_to_int = NULL;
PyObject *CPyStatic_to_string = NULL;
PyObject *CPyStatic_to_uint = NULL;
PyObject *CPyStatic__check_array = NULL;
PyObject *CPyStatic__get_abi_types = NULL;
PyObject *CPyStatic_logger = NULL;
PyObject *CPyStatic_encode = NULL;
PyObject *CPyStatic_decode = NULL;
PyObject *CPyStatic_to_checksum_address = NULL;
PyObject *CPyStatic___eth_abi_encode = NULL;
PyObject *CPyStatic___eth_abi_decode = NULL;
PyTypeObject *CPyType___mypyc_lambda__0_obj;
PyObject *CPyDef___mypyc_lambda__0_obj(void);
PyTypeObject *CPyType___mypyc_lambda__1_obj;
PyObject *CPyDef___mypyc_lambda__1_obj(void);
PyTypeObject *CPyType__get_coroutine_fn_env;
PyObject *CPyDef__get_coroutine_fn_env(void);
PyTypeObject *CPyType_coroutine__get_coroutine_fn_env;
PyObject *CPyDef_coroutine__get_coroutine_fn_env(void);
PyTypeObject *CPyType_coroutine__get_coroutine_fn_obj;
PyObject *CPyDef_coroutine__get_coroutine_fn_obj(void);
PyTypeObject *CPyType_coroutine__get_coroutine_fn_gen;
PyObject *CPyDef_coroutine__get_coroutine_fn_gen(void);
PyTypeObject *CPyType_encode_input_env;
PyObject *CPyDef_encode_input_env(void);
PyTypeObject *CPyType_encode_input_gen;
PyObject *CPyDef_encode_input_gen(void);
PyTypeObject *CPyType_decode_output_env;
PyObject *CPyDef_decode_output_env(void);
PyTypeObject *CPyType_decode_output_gen;
PyObject *CPyDef_decode_output_gen(void);
PyTypeObject *CPyType__request_data_no_args_env;
PyObject *CPyDef__request_data_no_args_env(void);
PyTypeObject *CPyType__request_data_no_args_gen;
PyObject *CPyDef__request_data_no_args_gen(void);
PyObject *CPyDef___mypyc_lambda__0_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__0_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__0_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args);
PyObject *CPyPy___mypyc_lambda__0_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__1_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__1_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__1_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_data);
PyObject *CPyPy___mypyc_lambda__1_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__patch_call(PyObject *cpy_r_call, PyObject *cpy_r_w3);
PyObject *CPyPy__patch_call(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_coroutine__get_coroutine_fn_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine__get_coroutine_fn_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_coroutine__get_coroutine_fn_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine__get_coroutine_fn_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_coroutine__get_coroutine_fn_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine__get_coroutine_fn_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine__get_coroutine_fn_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__get_coroutine_fn_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
PyObject *CPyPy_coroutine__get_coroutine_fn_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__get_coroutine_fn(PyObject *cpy_r_w3, CPyTagged cpy_r_len_inputs);
PyObject *CPyPy__get_coroutine_fn(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__call_no_args(PyObject *cpy_r_self);
PyObject *CPyPy__call_no_args(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_input_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy_encode_input_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_input_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_encode_input_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_input_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_encode_input_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_input_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_encode_input_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_input_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_encode_input_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_input_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_encode_input_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_input_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_encode_input_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_encode_input(PyObject *cpy_r_call, CPyTagged cpy_r_len_inputs, PyObject *cpy_r_get_request_data, PyObject *cpy_r_args);
PyObject *CPyPy_encode_input(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_output_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy_decode_output_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_output_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_decode_output_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_output_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_decode_output_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_output_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_decode_output_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_output_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_decode_output_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_output_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_decode_output_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_output_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_decode_output_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_decode_output(PyObject *cpy_r_call, PyObject *cpy_r_data);
PyObject *CPyPy_decode_output(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__request_data_no_args_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy__request_data_no_args_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__request_data_no_args_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__request_data_no_args_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__request_data_no_args_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy__request_data_no_args_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__request_data_no_args_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__request_data_no_args_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__request_data_no_args_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy__request_data_no_args_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__request_data_no_args_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__request_data_no_args_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__request_data_no_args_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__request_data_no_args_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__request_data_no_args(PyObject *cpy_r_call);
PyObject *CPyPy__request_data_no_args(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___encode_input(PyObject *cpy_r_abi, PyObject *cpy_r_signature, PyObject *cpy_r_args);
PyObject *CPyPy___encode_input(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___decode_output(PyObject *cpy_r_hexstr, PyObject *cpy_r_abi);
PyObject *CPyPy___decode_output(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___validate_output(PyObject *cpy_r_abi, PyObject *cpy_r_hexstr);
PyObject *CPyPy___validate_output(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_format_input_but_cache_checksums(PyObject *cpy_r_abi, PyObject *cpy_r_inputs);
PyObject *CPyPy_format_input_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_format_output_but_cache_checksums(PyObject *cpy_r_abi, PyObject *cpy_r_outputs);
PyObject *CPyPy_format_output_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__format_tuple_but_cache_checksums(PyObject *cpy_r_abi_types, PyObject *cpy_r_values);
PyObject *CPyPy__format_tuple_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__format_array_but_cache_checksums(PyObject *cpy_r_abi_type, PyObject *cpy_r_values);
PyObject *CPyPy__format_array_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__format_single_but_cache_checksums(PyObject *cpy_r_type_str, PyObject *cpy_r_value);
PyObject *CPyPy__format_single_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids___brownie_patch___call exports = {
    &CPyStatic_ENVS,
    &CPyStatic_APPLICATION_MODE,
    &CPyStatic_Decimal,
    &CPyStatic_HexBytes,
    &CPyStatic_Contract,
    &CPyStatic_ReturnValue,
    &CPyStatic_HexString,
    &CPyStatic_TupleType,
    &CPyStatic_Revert,
    &CPyStatic_to_bool,
    &CPyStatic_to_decimal,
    &CPyStatic_to_int,
    &CPyStatic_to_string,
    &CPyStatic_to_uint,
    &CPyStatic__check_array,
    &CPyStatic__get_abi_types,
    &CPyStatic_logger,
    &CPyStatic_encode,
    &CPyStatic_decode,
    &CPyStatic_to_checksum_address,
    &CPyStatic___eth_abi_encode,
    &CPyStatic___eth_abi_decode,
    &CPyType___mypyc_lambda__0_obj,
    &CPyDef___mypyc_lambda__0_obj,
    &CPyType___mypyc_lambda__1_obj,
    &CPyDef___mypyc_lambda__1_obj,
    &CPyType__get_coroutine_fn_env,
    &CPyDef__get_coroutine_fn_env,
    &CPyType_coroutine__get_coroutine_fn_env,
    &CPyDef_coroutine__get_coroutine_fn_env,
    &CPyType_coroutine__get_coroutine_fn_obj,
    &CPyDef_coroutine__get_coroutine_fn_obj,
    &CPyType_coroutine__get_coroutine_fn_gen,
    &CPyDef_coroutine__get_coroutine_fn_gen,
    &CPyType_encode_input_env,
    &CPyDef_encode_input_env,
    &CPyType_encode_input_gen,
    &CPyDef_encode_input_gen,
    &CPyType_decode_output_env,
    &CPyDef_decode_output_env,
    &CPyType_decode_output_gen,
    &CPyDef_decode_output_gen,
    &CPyType__request_data_no_args_env,
    &CPyDef__request_data_no_args_env,
    &CPyType__request_data_no_args_gen,
    &CPyDef__request_data_no_args_gen,
    &CPyDef___mypyc_lambda__0_obj_____get__,
    &CPyDef___mypyc_lambda__0_obj_____call__,
    &CPyDef___mypyc_lambda__1_obj_____get__,
    &CPyDef___mypyc_lambda__1_obj_____call__,
    &CPyDef__patch_call,
    &CPyDef_coroutine__get_coroutine_fn_obj_____get__,
    &CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__,
    &CPyDef_coroutine__get_coroutine_fn_gen_____next__,
    &CPyDef_coroutine__get_coroutine_fn_gen___send,
    &CPyDef_coroutine__get_coroutine_fn_gen_____iter__,
    &CPyDef_coroutine__get_coroutine_fn_gen___throw,
    &CPyDef_coroutine__get_coroutine_fn_gen___close,
    &CPyDef_coroutine__get_coroutine_fn_gen_____await__,
    &CPyDef_coroutine__get_coroutine_fn_obj_____call__,
    &CPyDef__get_coroutine_fn,
    &CPyDef__call_no_args,
    &CPyDef_encode_input_gen_____mypyc_generator_helper__,
    &CPyDef_encode_input_gen_____next__,
    &CPyDef_encode_input_gen___send,
    &CPyDef_encode_input_gen_____iter__,
    &CPyDef_encode_input_gen___throw,
    &CPyDef_encode_input_gen___close,
    &CPyDef_encode_input_gen_____await__,
    &CPyDef_encode_input,
    &CPyDef_decode_output_gen_____mypyc_generator_helper__,
    &CPyDef_decode_output_gen_____next__,
    &CPyDef_decode_output_gen___send,
    &CPyDef_decode_output_gen_____iter__,
    &CPyDef_decode_output_gen___throw,
    &CPyDef_decode_output_gen___close,
    &CPyDef_decode_output_gen_____await__,
    &CPyDef_decode_output,
    &CPyDef__request_data_no_args_gen_____mypyc_generator_helper__,
    &CPyDef__request_data_no_args_gen_____next__,
    &CPyDef__request_data_no_args_gen___send,
    &CPyDef__request_data_no_args_gen_____iter__,
    &CPyDef__request_data_no_args_gen___throw,
    &CPyDef__request_data_no_args_gen___close,
    &CPyDef__request_data_no_args_gen_____await__,
    &CPyDef__request_data_no_args,
    &CPyDef___encode_input,
    &CPyDef___decode_output,
    &CPyDef___validate_output,
    &CPyDef_format_input_but_cache_checksums,
    &CPyDef_format_output_but_cache_checksums,
    &CPyDef__format_tuple_but_cache_checksums,
    &CPyDef__format_array_but_cache_checksums,
    &CPyDef__format_single_but_cache_checksums,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit_call__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids.brownie_patch.call__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids.brownie_patch.call__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids___brownie_patch___call(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids___brownie_patch___call, "dank_mids.brownie_patch.call__mypyc.init_dank_mids___brownie_patch___call", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids___brownie_patch___call", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
