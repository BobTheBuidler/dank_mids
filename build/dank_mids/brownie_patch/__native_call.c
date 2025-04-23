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
PyMemberDef __mypyc_lambda__0_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject) + sizeof(PyObject *), 0, NULL},
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
__mypyc_lambda__0_obj_traverse(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject))));
    return 0;
}

static int
__mypyc_lambda__0_obj_clear(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject *self)
{
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject))));
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
    .tp_members = __mypyc_lambda__0_obj_members,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
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
PyMemberDef __mypyc_lambda__1_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
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
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject))));
    return 0;
}

static int
__mypyc_lambda__1_obj_clear(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject *self)
{
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject))));
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
    .tp_members = __mypyc_lambda__1_obj_members,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
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
PyMemberDef coroutine__get_coroutine_fn_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
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
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject))));
    return 0;
}

static int
coroutine__get_coroutine_fn_obj_clear(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject))));
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
    .tp_members = coroutine__get_coroutine_fn_obj_members,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
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


static PyObject *_format_array_but_cache_checksums_env_setup(PyTypeObject *type);
PyObject *CPyDef__format_array_but_cache_checksums_env(void);

static PyObject *
_format_array_but_cache_checksums_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__format_array_but_cache_checksums_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _format_array_but_cache_checksums_env_setup(type);
}

static int
_format_array_but_cache_checksums_env_traverse(dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_components);
    Py_VISIT(self->_item_type);
    Py_VISIT(self->_type_str);
    Py_VISIT(self->_abi_type);
    Py_VISIT(self->_values);
    return 0;
}

static int
_format_array_but_cache_checksums_env_clear(dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_components);
    Py_CLEAR(self->_item_type);
    Py_CLEAR(self->_type_str);
    Py_CLEAR(self->_abi_type);
    Py_CLEAR(self->_values);
    return 0;
}

static void
_format_array_but_cache_checksums_env_dealloc(dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _format_array_but_cache_checksums_env_dealloc)
    _format_array_but_cache_checksums_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _format_array_but_cache_checksums_env_vtable[1];
static bool
CPyDef__format_array_but_cache_checksums_env_trait_vtable_setup(void)
{
    CPyVTableItem _format_array_but_cache_checksums_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_format_array_but_cache_checksums_env_vtable, _format_array_but_cache_checksums_env_vtable_scratch, sizeof(_format_array_but_cache_checksums_env_vtable));
    return 1;
}

static PyMethodDef _format_array_but_cache_checksums_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__format_array_but_cache_checksums_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_format_array_but_cache_checksums_env",
    .tp_new = _format_array_but_cache_checksums_env_new,
    .tp_dealloc = (destructor)_format_array_but_cache_checksums_env_dealloc,
    .tp_traverse = (traverseproc)_format_array_but_cache_checksums_env_traverse,
    .tp_clear = (inquiry)_format_array_but_cache_checksums_env_clear,
    .tp_methods = _format_array_but_cache_checksums_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__format_array_but_cache_checksums_env_template = &CPyType__format_array_but_cache_checksums_env_template_;

static PyObject *
_format_array_but_cache_checksums_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *self;
    self = (dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _format_array_but_cache_checksums_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__format_array_but_cache_checksums_env(void)
{
    PyObject *self = _format_array_but_cache_checksums_env_setup(CPyType__format_array_but_cache_checksums_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get____mypyc_lambda__2__format_array_but_cache_checksums_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__(self, instance, owner);
}
PyMemberDef __mypyc_lambda__2__format_array_but_cache_checksums_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
static PyObject *__mypyc_lambda__2__format_array_but_cache_checksums_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj(void);

static PyObject *
__mypyc_lambda__2__format_array_but_cache_checksums_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__2__format_array_but_cache_checksums_obj_setup(type);
}

static int
__mypyc_lambda__2__format_array_but_cache_checksums_obj_traverse(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject))));
    return 0;
}

static int
__mypyc_lambda__2__format_array_but_cache_checksums_obj_clear(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject))));
    return 0;
}

static void
__mypyc_lambda__2__format_array_but_cache_checksums_obj_dealloc(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__2__format_array_but_cache_checksums_obj_dealloc)
    __mypyc_lambda__2__format_array_but_cache_checksums_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__2__format_array_but_cache_checksums_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__2__format_array_but_cache_checksums_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__,
    };
    memcpy(__mypyc_lambda__2__format_array_but_cache_checksums_obj_vtable, __mypyc_lambda__2__format_array_but_cache_checksums_obj_vtable_scratch, sizeof(__mypyc_lambda__2__format_array_but_cache_checksums_obj_vtable));
    return 1;
}

static PyObject *
__mypyc_lambda__2__format_array_but_cache_checksums_obj_get___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *self, void *closure);
static int
__mypyc_lambda__2__format_array_but_cache_checksums_obj_set___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *self, PyObject *value, void *closure);

static PyGetSetDef __mypyc_lambda__2__format_array_but_cache_checksums_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)__mypyc_lambda__2__format_array_but_cache_checksums_obj_get___3_mypyc_env__, (setter)__mypyc_lambda__2__format_array_but_cache_checksums_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__2__format_array_but_cache_checksums_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__2__format_array_but_cache_checksums_obj",
    .tp_new = __mypyc_lambda__2__format_array_but_cache_checksums_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__2__format_array_but_cache_checksums_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__2__format_array_but_cache_checksums_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__2__format_array_but_cache_checksums_obj_clear,
    .tp_getset = __mypyc_lambda__2__format_array_but_cache_checksums_obj_getseters,
    .tp_methods = __mypyc_lambda__2__format_array_but_cache_checksums_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__2__format_array_but_cache_checksums_obj,
    .tp_members = __mypyc_lambda__2__format_array_but_cache_checksums_obj_members,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
};
static PyTypeObject *CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj_template = &CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj_template_;

static PyObject *
__mypyc_lambda__2__format_array_but_cache_checksums_obj_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *self;
    self = (dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__2__format_array_but_cache_checksums_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj(void)
{
    PyObject *self = __mypyc_lambda__2__format_array_but_cache_checksums_obj_setup(CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
__mypyc_lambda__2__format_array_but_cache_checksums_obj_get___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of '__mypyc_lambda__2__format_array_but_cache_checksums_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
__mypyc_lambda__2__format_array_but_cache_checksums_obj_set___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'__mypyc_lambda__2__format_array_but_cache_checksums_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType__format_array_but_cache_checksums_env))
        tmp = value;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._format_array_but_cache_checksums_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *CPyDunder___get____mypyc_lambda__3__format_array_but_cache_checksums_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__(self, instance, owner);
}
PyMemberDef __mypyc_lambda__3__format_array_but_cache_checksums_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
static PyObject *__mypyc_lambda__3__format_array_but_cache_checksums_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj(void);

static PyObject *
__mypyc_lambda__3__format_array_but_cache_checksums_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__3__format_array_but_cache_checksums_obj_setup(type);
}

static int
__mypyc_lambda__3__format_array_but_cache_checksums_obj_traverse(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject))));
    return 0;
}

static int
__mypyc_lambda__3__format_array_but_cache_checksums_obj_clear(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject))));
    return 0;
}

static void
__mypyc_lambda__3__format_array_but_cache_checksums_obj_dealloc(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__3__format_array_but_cache_checksums_obj_dealloc)
    __mypyc_lambda__3__format_array_but_cache_checksums_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__3__format_array_but_cache_checksums_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__3__format_array_but_cache_checksums_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__,
    };
    memcpy(__mypyc_lambda__3__format_array_but_cache_checksums_obj_vtable, __mypyc_lambda__3__format_array_but_cache_checksums_obj_vtable_scratch, sizeof(__mypyc_lambda__3__format_array_but_cache_checksums_obj_vtable));
    return 1;
}

static PyObject *
__mypyc_lambda__3__format_array_but_cache_checksums_obj_get___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *self, void *closure);
static int
__mypyc_lambda__3__format_array_but_cache_checksums_obj_set___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *self, PyObject *value, void *closure);

static PyGetSetDef __mypyc_lambda__3__format_array_but_cache_checksums_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)__mypyc_lambda__3__format_array_but_cache_checksums_obj_get___3_mypyc_env__, (setter)__mypyc_lambda__3__format_array_but_cache_checksums_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__3__format_array_but_cache_checksums_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__3__format_array_but_cache_checksums_obj",
    .tp_new = __mypyc_lambda__3__format_array_but_cache_checksums_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__3__format_array_but_cache_checksums_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__3__format_array_but_cache_checksums_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__3__format_array_but_cache_checksums_obj_clear,
    .tp_getset = __mypyc_lambda__3__format_array_but_cache_checksums_obj_getseters,
    .tp_methods = __mypyc_lambda__3__format_array_but_cache_checksums_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__3__format_array_but_cache_checksums_obj,
    .tp_members = __mypyc_lambda__3__format_array_but_cache_checksums_obj_members,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
};
static PyTypeObject *CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj_template = &CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj_template_;

static PyObject *
__mypyc_lambda__3__format_array_but_cache_checksums_obj_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *self;
    self = (dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__3__format_array_but_cache_checksums_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj(void)
{
    PyObject *self = __mypyc_lambda__3__format_array_but_cache_checksums_obj_setup(CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
__mypyc_lambda__3__format_array_but_cache_checksums_obj_get___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of '__mypyc_lambda__3__format_array_but_cache_checksums_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
__mypyc_lambda__3__format_array_but_cache_checksums_obj_set___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'__mypyc_lambda__3__format_array_but_cache_checksums_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType__format_array_but_cache_checksums_env))
        tmp = value;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._format_array_but_cache_checksums_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *CPyDunder___get____mypyc_lambda__4__format_array_but_cache_checksums_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__(self, instance, owner);
}
PyMemberDef __mypyc_lambda__4__format_array_but_cache_checksums_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
static PyObject *__mypyc_lambda__4__format_array_but_cache_checksums_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj(void);

static PyObject *
__mypyc_lambda__4__format_array_but_cache_checksums_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__4__format_array_but_cache_checksums_obj_setup(type);
}

static int
__mypyc_lambda__4__format_array_but_cache_checksums_obj_traverse(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject))));
    return 0;
}

static int
__mypyc_lambda__4__format_array_but_cache_checksums_obj_clear(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject))));
    return 0;
}

static void
__mypyc_lambda__4__format_array_but_cache_checksums_obj_dealloc(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__4__format_array_but_cache_checksums_obj_dealloc)
    __mypyc_lambda__4__format_array_but_cache_checksums_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__4__format_array_but_cache_checksums_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__4__format_array_but_cache_checksums_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__,
    };
    memcpy(__mypyc_lambda__4__format_array_but_cache_checksums_obj_vtable, __mypyc_lambda__4__format_array_but_cache_checksums_obj_vtable_scratch, sizeof(__mypyc_lambda__4__format_array_but_cache_checksums_obj_vtable));
    return 1;
}

static PyObject *
__mypyc_lambda__4__format_array_but_cache_checksums_obj_get___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *self, void *closure);
static int
__mypyc_lambda__4__format_array_but_cache_checksums_obj_set___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *self, PyObject *value, void *closure);

static PyGetSetDef __mypyc_lambda__4__format_array_but_cache_checksums_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)__mypyc_lambda__4__format_array_but_cache_checksums_obj_get___3_mypyc_env__, (setter)__mypyc_lambda__4__format_array_but_cache_checksums_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__4__format_array_but_cache_checksums_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__4__format_array_but_cache_checksums_obj",
    .tp_new = __mypyc_lambda__4__format_array_but_cache_checksums_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__4__format_array_but_cache_checksums_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__4__format_array_but_cache_checksums_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__4__format_array_but_cache_checksums_obj_clear,
    .tp_getset = __mypyc_lambda__4__format_array_but_cache_checksums_obj_getseters,
    .tp_methods = __mypyc_lambda__4__format_array_but_cache_checksums_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__4__format_array_but_cache_checksums_obj,
    .tp_members = __mypyc_lambda__4__format_array_but_cache_checksums_obj_members,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
};
static PyTypeObject *CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj_template = &CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj_template_;

static PyObject *
__mypyc_lambda__4__format_array_but_cache_checksums_obj_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *self;
    self = (dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__4__format_array_but_cache_checksums_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj(void)
{
    PyObject *self = __mypyc_lambda__4__format_array_but_cache_checksums_obj_setup(CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
__mypyc_lambda__4__format_array_but_cache_checksums_obj_get___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of '__mypyc_lambda__4__format_array_but_cache_checksums_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
__mypyc_lambda__4__format_array_but_cache_checksums_obj_set___3_mypyc_env__(dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'__mypyc_lambda__4__format_array_but_cache_checksums_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType__format_array_but_cache_checksums_env))
        tmp = value;
    else {
        CPy_TypeError("dank_mids.brownie_patch.call._format_array_but_cache_checksums_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
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
    CPyType__format_array_but_cache_checksums_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__format_array_but_cache_checksums_env_template, NULL, modname);
    if (unlikely(!CPyType__format_array_but_cache_checksums_env))
        goto fail;
    CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj))
        goto fail;
    CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj))
        goto fail;
    CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj))
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
    CPy_XDECREF(CPyStatic_encode);
    CPyStatic_encode = NULL;
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
    Py_CLEAR(CPyType__format_array_but_cache_checksums_env);
    Py_CLEAR(CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj);
    Py_CLEAR(CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj);
    Py_CLEAR(CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj);
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
    CPyPtr cpy_r_r15;
    CPyPtr cpy_r_r16;
    CPyPtr cpy_r_r17;
    CPyPtr cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r3 = CPyStatics[4]; /* 'BROWNIE_ENCODER_PROCESSES' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r5 = CPyStatic_globals;
    cpy_r_r6 = CPyStatics[5]; /* '__encode_input' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r8 = CPyStatics[6]; /* 'abi' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_self, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r10 = CPyStatics[7]; /* 'signature' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_self, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r12 = CPyStatics[8]; /* 'run' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r14 = PyList_New(3);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r15 = (CPyPtr)&((PyListObject *)cpy_r_r14)->ob_item;
    cpy_r_r16 = *(CPyPtr *)cpy_r_r15;
    *(PyObject * *)cpy_r_r16 = cpy_r_r7;
    cpy_r_r17 = cpy_r_r16 + 8;
    *(PyObject * *)cpy_r_r17 = cpy_r_r9;
    cpy_r_r18 = cpy_r_r16 + 16;
    *(PyObject * *)cpy_r_r18 = cpy_r_r11;
    cpy_r_r19 = CPyList_Extend(cpy_r_r14, cpy_r_args);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL18;
    } else
        goto CPyL19;
CPyL8: ;
    cpy_r_r20 = PyList_AsTuple(cpy_r_r14);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r21 = PyDict_New();
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r22 = PyObject_Call(cpy_r_r13, cpy_r_r20, cpy_r_r21);
    CPy_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
        goto CPyL12;
    }
    return cpy_r_r22;
CPyL12: ;
    cpy_r_r23 = NULL;
    return cpy_r_r23;
CPyL13: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL12;
CPyL14: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r7);
    goto CPyL12;
CPyL15: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r9);
    goto CPyL12;
CPyL16: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r11);
    goto CPyL12;
CPyL17: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r13);
    goto CPyL12;
CPyL18: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    goto CPyL12;
CPyL19: ;
    CPy_DECREF(cpy_r_r19);
    goto CPyL8;
CPyL20: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL12;
CPyL21: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r20);
    goto CPyL12;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 66, CPyStatic_globals);
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
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 85, CPyStatic_globals);
        goto CPyL6;
    }
    cpy_r_r3 = CPyStatics[9]; /* 'BROWNIE_DECODER_PROCESSES' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 85, CPyStatic_globals);
        goto CPyL6;
    }
    cpy_r_r5 = CPyStatic_globals;
    cpy_r_r6 = CPyStatics[10]; /* '__decode_output' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 85, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r8 = CPyStatics[6]; /* 'abi' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_self, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 85, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r10 = CPyStatics[8]; /* 'run' */
    cpy_r_r11 = CPyObject_CallMethodObjArgs(cpy_r_r4, cpy_r_r10, cpy_r_r7, cpy_r_data, cpy_r_r9, NULL);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 85, CPyStatic_globals);
        goto CPyL6;
    }
    return cpy_r_r11;
CPyL6: ;
    cpy_r_r12 = NULL;
    return cpy_r_r12;
CPyL7: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL6;
CPyL8: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r7);
    goto CPyL6;
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
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef___mypyc_lambda__1_obj_____call__(arg___mypyc_self__, arg_self, arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 85, CPyStatic_globals);
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
    cpy_r_r0 = CPyStatics[11]; /* '_address' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_call, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 119, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[12]; /* '_skip_proc_pool' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 119, CPyStatic_globals);
        goto CPyL19;
    }
    if (likely(PySet_Check(cpy_r_r4)))
        cpy_r_r5 = cpy_r_r4;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 119, CPyStatic_globals, "set", cpy_r_r4);
        goto CPyL19;
    }
    cpy_r_r6 = PySet_Contains(cpy_r_r5, cpy_r_r1);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r1);
    cpy_r_r7 = cpy_r_r6 >= 0;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 119, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r8 = cpy_r_r6;
    cpy_r_r9 = CPyStatics[13]; /* '_skip_decoder_proc_pool' */
    cpy_r_r10 = cpy_r_r8 ? Py_True : Py_False;
    cpy_r_r11 = PyObject_SetAttr(cpy_r_call, cpy_r_r9, cpy_r_r10);
    cpy_r_r12 = cpy_r_r11 >= 0;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 119, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r13 = CPyStatics[6]; /* 'abi' */
    cpy_r_r14 = CPyObject_GetAttr(cpy_r_call, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 120, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r15 = CPyStatics[14]; /* 'inputs' */
    cpy_r_r16 = PyObject_GetItem(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 120, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r17 = CPyObject_Size(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 120, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r18 = CPyStatic_globals;
    cpy_r_r19 = CPyStatics[15]; /* '_get_coroutine_fn' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 120, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r21 = CPyTagged_StealAsObject(cpy_r_r17);
    PyObject *cpy_r_r22[2] = {cpy_r_w3, cpy_r_r21};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = _PyObject_Vectorcall(cpy_r_r20, cpy_r_r23, 2, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 120, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(cpy_r_r21);
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyStatics[16]; /* 'MethodType' */
    cpy_r_r27 = CPyDict_GetItem(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 120, CPyStatic_globals);
        goto CPyL22;
    }
    PyObject *cpy_r_r28[2] = {cpy_r_r24, cpy_r_call};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 2, 0);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 120, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r24);
    cpy_r_r31 = CPyStatics[17]; /* 'coroutine' */
    cpy_r_r32 = PyObject_SetAttr(cpy_r_call, cpy_r_r31, cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r33 = cpy_r_r32 >= 0;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 120, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyStatics[18]; /* '_call_no_args' */
    cpy_r_r36 = CPyDict_GetItem(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 121, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyStatics[16]; /* 'MethodType' */
    cpy_r_r39 = CPyDict_GetItem(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 121, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r40[2] = {cpy_r_r36, cpy_r_call};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = _PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 2, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 121, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r36);
    cpy_r_r43 = CPyStatics[19]; /* '__await__' */
    cpy_r_r44 = PyObject_SetAttr(cpy_r_call, cpy_r_r43, cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 121, CPyStatic_globals);
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_patch_call", 109, CPyStatic_globals);
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
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject **cpy_r_r55;
    PyObject *cpy_r_r56;
    char cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    char cpy_r_r68;
    tuple_T3OOO cpy_r_r69;
    char cpy_r_r70;
    PyObject **cpy_r_r71;
    PyObject *cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    tuple_T3OOO cpy_r_r75;
    char cpy_r_r76;
    tuple_T3OOO cpy_r_r77;
    tuple_T3OOO cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    CPyTagged cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    CPyPtr cpy_r_r92;
    CPyPtr cpy_r_r93;
    CPyPtr cpy_r_r94;
    CPyPtr cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    char cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    char cpy_r_r107;
    PyObject *cpy_r_r108;
    char cpy_r_r109;
    tuple_T3OOO cpy_r_r110;
    char cpy_r_r111;
    PyObject **cpy_r_r112;
    PyObject *cpy_r_r113;
    char cpy_r_r114;
    char cpy_r_r115;
    tuple_T3OOO cpy_r_r116;
    char cpy_r_r117;
    tuple_T3OOO cpy_r_r118;
    tuple_T3OOO cpy_r_r119;
    char cpy_r_r120;
    PyObject *cpy_r_r121;
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
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    char cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject **cpy_r_r139;
    PyObject *cpy_r_r140;
    char cpy_r_r141;
    char cpy_r_r142;
    PyObject *cpy_r_r143;
    char cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    char cpy_r_r150;
    PyObject *cpy_r_r151;
    char cpy_r_r152;
    tuple_T3OOO cpy_r_r153;
    char cpy_r_r154;
    PyObject **cpy_r_r155;
    PyObject *cpy_r_r156;
    char cpy_r_r157;
    char cpy_r_r158;
    tuple_T3OOO cpy_r_r159;
    char cpy_r_r160;
    tuple_T3OOO cpy_r_r161;
    tuple_T3OOO cpy_r_r162;
    char cpy_r_r163;
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
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
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
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    PyObject **cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    PyObject *cpy_r_r427;
    PyObject *cpy_r_r428;
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
    char cpy_r_r440;
    PyObject *cpy_r_r441;
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
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_gen", "__mypyc_env__", 131, CPyStatic_globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r22);
CPyL1: ;
    cpy_r_r23 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__;
    if (unlikely(cpy_r_r23 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_next_label__", 131, CPyStatic_globals);
        goto CPyL484;
    }
    CPyTagged_INCREF(cpy_r_r23);
CPyL2: ;
    cpy_r_r24 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_env__;
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_env__", 131, CPyStatic_globals);
        goto CPyL485;
    }
    CPy_INCREF(cpy_r_r24);
    goto CPyL470;
CPyL3: ;
    cpy_r_r25 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r26 = cpy_r_type != cpy_r_r25;
    if (cpy_r_r26) {
        goto CPyL486;
    } else
        goto CPyL6;
CPyL4: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL482;
    }
    CPy_Unreachable();
CPyL6: ;
    cpy_r_r27 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_override;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "override", 138, CPyStatic_globals);
        goto CPyL487;
    }
    CPy_INCREF(cpy_r_r27);
CPyL7: ;
    cpy_r_r28 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r29 = cpy_r_r27 != cpy_r_r28;
    if (!cpy_r_r29) goto CPyL488;
    if (likely(cpy_r_r27 != Py_None))
        cpy_r_r30 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "coroutine", 138, CPyStatic_globals, "dict", cpy_r_r27);
        goto CPyL487;
    }
    cpy_r_r31 = PyDict_Size(cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r32 = cpy_r_r31 << 1;
    cpy_r_r33 = cpy_r_r32 != 0;
    if (cpy_r_r33) {
        goto CPyL489;
    } else
        goto CPyL14;
CPyL10: ;
    cpy_r_r34 = CPyStatics[20]; /* 'Cannot use state override with `coroutine`.' */
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[21]; /* 'ValueError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 139, CPyStatic_globals);
        goto CPyL482;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r34};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 1, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 139, CPyStatic_globals);
        goto CPyL482;
    }
    CPy_Raise(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 139, CPyStatic_globals);
        goto CPyL482;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r41 = CPyStatic_globals;
    cpy_r_r42 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r43 = CPyDict_GetItem(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL487;
    }
    cpy_r_r44 = CPyStatics[22]; /* 'BROWNIE_ENCODER_SEMAPHORE' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL487;
    }
    cpy_r_r46 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_block_identifier;
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "block_identifier", 140, CPyStatic_globals);
        goto CPyL490;
    }
    CPy_INCREF(cpy_r_r46);
CPyL17: ;
    cpy_r_r47 = PyObject_GetItem(cpy_r_r45, cpy_r_r46);
    CPy_DECREF(cpy_r_r45);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL487;
    }
    cpy_r_r48 = PyObject_Type(cpy_r_r47);
    cpy_r_r49 = CPyStatics[23]; /* '__aexit__' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL491;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0 = cpy_r_r50;
    cpy_r_r51 = 1;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL491;
    }
    cpy_r_r52 = CPyStatics[24]; /* '__aenter__' */
    cpy_r_r53 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r52);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL492;
    }
    PyObject *cpy_r_r54[1] = {cpy_r_r47};
    cpy_r_r55 = (PyObject **)&cpy_r_r54;
    cpy_r_r56 = _PyObject_Vectorcall(cpy_r_r53, cpy_r_r55, 1, 0);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL492;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1 = cpy_r_r47;
    cpy_r_r57 = 1;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL493;
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__2 = 1;
    cpy_r_r58 = 1;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL493;
    }
    cpy_r_r59 = CPy_GetCoro(cpy_r_r56);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL487;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3 = cpy_r_r59;
    cpy_r_r60 = 1;
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL487;
    }
    cpy_r_r61 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3;
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL487;
    }
    CPy_INCREF(cpy_r_r61);
CPyL27: ;
    cpy_r_r62 = CPyIter_Next(cpy_r_r61);
    CPy_DECREF(cpy_r_r61);
    if (cpy_r_r62 == NULL) {
        goto CPyL494;
    } else
        goto CPyL30;
CPyL28: ;
    cpy_r_r63 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL495;
    }
    cpy_r_r64 = cpy_r_r63;
    CPy_DECREF(cpy_r_r64);
    goto CPyL59;
CPyL30: ;
    cpy_r_r65 = cpy_r_r62;
CPyL31: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 2;
    cpy_r_r66 = 1;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL496;
    } else
        goto CPyL497;
CPyL32: ;
    return cpy_r_r65;
CPyL33: ;
    cpy_r_r67 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r68 = cpy_r_type != cpy_r_r67;
    if (!cpy_r_r68) goto CPyL36;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL37;
    } else
        goto CPyL498;
CPyL35: ;
    CPy_Unreachable();
CPyL36: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL54;
CPyL37: ;
    cpy_r_r69 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4 = cpy_r_r69;
    cpy_r_r70 = 1;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL499;
    }
    cpy_r_r71 = (PyObject **)&cpy_r_r1;
    cpy_r_r72 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3;
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL499;
    }
    CPy_INCREF(cpy_r_r72);
CPyL39: ;
    cpy_r_r73 = CPy_YieldFromErrorHandle(cpy_r_r72, cpy_r_r71);
    CPy_DecRef(cpy_r_r72);
    if (unlikely(cpy_r_r73 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL499;
    }
    if (cpy_r_r73) goto CPyL46;
    if (cpy_r_r1 == NULL) {
        goto CPyL500;
    } else
        goto CPyL44;
CPyL42: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r74 = 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL51;
    } else
        goto CPyL501;
CPyL43: ;
    CPy_Unreachable();
CPyL44: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r65 = cpy_r_r1;
    cpy_r_r75 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4;
    if (unlikely(cpy_r_r75.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL502;
    }
    CPy_INCREF(cpy_r_r75.f0);
    CPy_INCREF(cpy_r_r75.f1);
    CPy_INCREF(cpy_r_r75.f2);
CPyL45: ;
    CPy_RestoreExcInfo(cpy_r_r75);
    CPy_DecRef(cpy_r_r75.f0);
    CPy_DecRef(cpy_r_r75.f1);
    CPy_DecRef(cpy_r_r75.f2);
    goto CPyL31;
CPyL46: ;
    if (cpy_r_r1 == NULL) {
        goto CPyL503;
    } else
        goto CPyL49;
CPyL47: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r76 = 0;
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL51;
    } else
        goto CPyL504;
CPyL48: ;
    CPy_Unreachable();
CPyL49: ;
    cpy_r_r64 = cpy_r_r1;
    CPy_DecRef(cpy_r_r64);
    cpy_r_r77 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4;
    if (unlikely(cpy_r_r77.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL505;
    }
    CPy_INCREF(cpy_r_r77.f0);
    CPy_INCREF(cpy_r_r77.f1);
    CPy_INCREF(cpy_r_r77.f2);
CPyL50: ;
    CPy_RestoreExcInfo(cpy_r_r77);
    CPy_DecRef(cpy_r_r77.f0);
    CPy_DecRef(cpy_r_r77.f1);
    CPy_DecRef(cpy_r_r77.f2);
    goto CPyL59;
CPyL51: ;
    cpy_r_r78 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__4;
    if (unlikely(cpy_r_r78.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__4' of 'coroutine__get_coroutine_fn_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r78.f0);
        CPy_INCREF(cpy_r_r78.f1);
        CPy_INCREF(cpy_r_r78.f2);
    }
    CPy_DecRef(cpy_r_r22);
    if (unlikely(cpy_r_r78.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL482;
    }
CPyL52: ;
    CPy_RestoreExcInfo(cpy_r_r78);
    CPy_DecRef(cpy_r_r78.f0);
    CPy_DecRef(cpy_r_r78.f1);
    CPy_DecRef(cpy_r_r78.f2);
    cpy_r_r79 = CPy_KeepPropagating();
    if (!cpy_r_r79) goto CPyL482;
    CPy_Unreachable();
CPyL54: ;
    cpy_r_r80 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__3;
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL506;
    }
    CPy_INCREF(cpy_r_r80);
CPyL55: ;
    cpy_r_r81 = CPyIter_Send(cpy_r_r80, cpy_r_arg);
    CPy_DECREF(cpy_r_r80);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r81 == NULL) goto CPyL507;
    cpy_r_r65 = cpy_r_r81;
    goto CPyL31;
CPyL57: ;
    cpy_r_r82 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL495;
    }
    cpy_r_r64 = cpy_r_r82;
    CPy_DECREF(cpy_r_r64);
CPyL59: ;
    cpy_r_r83 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 141, CPyStatic_globals);
        goto CPyL508;
    }
    CPy_INCREF(cpy_r_r83);
CPyL60: ;
    cpy_r_r84 = ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r24)->_len_inputs;
    if (unlikely(cpy_r_r84 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "_get_coroutine_fn_env", "len_inputs", 141, CPyStatic_globals);
        goto CPyL509;
    }
    CPyTagged_INCREF(cpy_r_r84);
CPyL61: ;
    cpy_r_r85 = ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r24)->_get_request_data;
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "_get_coroutine_fn_env", "get_request_data", 141, CPyStatic_globals);
        goto CPyL510;
    }
    CPy_INCREF(cpy_r_r85);
CPyL62: ;
    cpy_r_r86 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_args;
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "args", 141, CPyStatic_globals);
        goto CPyL511;
    }
    CPy_INCREF(cpy_r_r86);
CPyL63: ;
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyStatics[25]; /* 'encode_input' */
    cpy_r_r89 = CPyDict_GetItem(cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL512;
    }
    cpy_r_r90 = PyList_New(3);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL513;
    }
    cpy_r_r91 = CPyTagged_StealAsObject(cpy_r_r84);
    cpy_r_r92 = (CPyPtr)&((PyListObject *)cpy_r_r90)->ob_item;
    cpy_r_r93 = *(CPyPtr *)cpy_r_r92;
    *(PyObject * *)cpy_r_r93 = cpy_r_r83;
    cpy_r_r94 = cpy_r_r93 + 8;
    *(PyObject * *)cpy_r_r94 = cpy_r_r91;
    cpy_r_r95 = cpy_r_r93 + 16;
    *(PyObject * *)cpy_r_r95 = cpy_r_r85;
    cpy_r_r96 = CPyList_Extend(cpy_r_r90, cpy_r_r86);
    CPy_DECREF(cpy_r_r86);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL514;
    } else
        goto CPyL515;
CPyL66: ;
    cpy_r_r97 = PyList_AsTuple(cpy_r_r90);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL516;
    }
    cpy_r_r98 = PyDict_New();
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL517;
    }
    cpy_r_r99 = PyObject_Call(cpy_r_r89, cpy_r_r97, cpy_r_r98);
    CPy_DECREF(cpy_r_r89);
    CPy_DECREF(cpy_r_r97);
    CPy_DECREF(cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL508;
    }
    cpy_r_r100 = CPy_GetCoro(cpy_r_r99);
    CPy_DECREF(cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL508;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5 = cpy_r_r100;
    cpy_r_r101 = 1;
    if (unlikely(!cpy_r_r101)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL508;
    }
    cpy_r_r102 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5;
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL508;
    }
    CPy_INCREF(cpy_r_r102);
CPyL72: ;
    cpy_r_r103 = CPyIter_Next(cpy_r_r102);
    CPy_DECREF(cpy_r_r102);
    if (cpy_r_r103 == NULL) {
        goto CPyL518;
    } else
        goto CPyL75;
CPyL73: ;
    cpy_r_r104 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL519;
    }
    cpy_r_r105 = cpy_r_r104;
    goto CPyL104;
CPyL75: ;
    cpy_r_r106 = cpy_r_r103;
CPyL76: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 4;
    cpy_r_r107 = 1;
    if (unlikely(!cpy_r_r107)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL520;
    } else
        goto CPyL521;
CPyL77: ;
    return cpy_r_r106;
CPyL78: ;
    cpy_r_r108 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r109 = cpy_r_type != cpy_r_r108;
    if (!cpy_r_r109) goto CPyL81;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL82;
    } else
        goto CPyL522;
CPyL80: ;
    CPy_Unreachable();
CPyL81: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL99;
CPyL82: ;
    cpy_r_r110 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6 = cpy_r_r110;
    cpy_r_r111 = 1;
    if (unlikely(!cpy_r_r111)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL523;
    }
    cpy_r_r112 = (PyObject **)&cpy_r_r3;
    cpy_r_r113 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5;
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL523;
    }
    CPy_INCREF(cpy_r_r113);
CPyL84: ;
    cpy_r_r114 = CPy_YieldFromErrorHandle(cpy_r_r113, cpy_r_r112);
    CPy_DecRef(cpy_r_r113);
    if (unlikely(cpy_r_r114 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL523;
    }
    if (cpy_r_r114) goto CPyL91;
    if (cpy_r_r3 == NULL) {
        goto CPyL524;
    } else
        goto CPyL89;
CPyL87: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r115 = 0;
    if (unlikely(!cpy_r_r115)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL96;
    } else
        goto CPyL525;
CPyL88: ;
    CPy_Unreachable();
CPyL89: ;
    CPy_INCREF(cpy_r_r3);
    cpy_r_r106 = cpy_r_r3;
    cpy_r_r116 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6;
    if (unlikely(cpy_r_r116.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__6", -1, CPyStatic_globals);
        goto CPyL526;
    }
    CPy_INCREF(cpy_r_r116.f0);
    CPy_INCREF(cpy_r_r116.f1);
    CPy_INCREF(cpy_r_r116.f2);
CPyL90: ;
    CPy_RestoreExcInfo(cpy_r_r116);
    CPy_DecRef(cpy_r_r116.f0);
    CPy_DecRef(cpy_r_r116.f1);
    CPy_DecRef(cpy_r_r116.f2);
    goto CPyL76;
CPyL91: ;
    if (cpy_r_r3 == NULL) {
        goto CPyL527;
    } else
        goto CPyL94;
CPyL92: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r117 = 0;
    if (unlikely(!cpy_r_r117)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL96;
    } else
        goto CPyL528;
CPyL93: ;
    CPy_Unreachable();
CPyL94: ;
    cpy_r_r105 = cpy_r_r3;
    cpy_r_r118 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6;
    if (unlikely(cpy_r_r118.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__6", -1, CPyStatic_globals);
        goto CPyL529;
    }
    CPy_INCREF(cpy_r_r118.f0);
    CPy_INCREF(cpy_r_r118.f1);
    CPy_INCREF(cpy_r_r118.f2);
CPyL95: ;
    CPy_RestoreExcInfo(cpy_r_r118);
    CPy_DecRef(cpy_r_r118.f0);
    CPy_DecRef(cpy_r_r118.f1);
    CPy_DecRef(cpy_r_r118.f2);
    goto CPyL104;
CPyL96: ;
    cpy_r_r119 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__6;
    if (unlikely(cpy_r_r119.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__6", -1, CPyStatic_globals);
        goto CPyL295;
    }
    CPy_INCREF(cpy_r_r119.f0);
    CPy_INCREF(cpy_r_r119.f1);
    CPy_INCREF(cpy_r_r119.f2);
CPyL97: ;
    CPy_RestoreExcInfo(cpy_r_r119);
    CPy_DecRef(cpy_r_r119.f0);
    CPy_DecRef(cpy_r_r119.f1);
    CPy_DecRef(cpy_r_r119.f2);
    cpy_r_r120 = CPy_KeepPropagating();
    if (!cpy_r_r120) {
        goto CPyL295;
    } else
        goto CPyL530;
CPyL98: ;
    CPy_Unreachable();
CPyL99: ;
    cpy_r_r121 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__5;
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL531;
    }
    CPy_INCREF(cpy_r_r121);
CPyL100: ;
    cpy_r_r122 = CPyIter_Send(cpy_r_r121, cpy_r_arg);
    CPy_DECREF(cpy_r_r121);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r122 == NULL) goto CPyL532;
    cpy_r_r106 = cpy_r_r122;
    goto CPyL76;
CPyL102: ;
    cpy_r_r123 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL519;
    }
    cpy_r_r105 = cpy_r_r123;
CPyL104: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_data);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_data = cpy_r_r105;
    cpy_r_r124 = 1;
    if (unlikely(!cpy_r_r124)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 141, CPyStatic_globals);
        goto CPyL519;
    }
    cpy_r_r125 = CPyStatic_globals;
    cpy_r_r126 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r127 = CPyDict_GetItem(cpy_r_r125, cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL519;
    }
    cpy_r_r128 = CPyStatics[26]; /* 'BROWNIE_CALL_SEMAPHORE' */
    cpy_r_r129 = CPyObject_GetAttr(cpy_r_r127, cpy_r_r128);
    CPy_DECREF(cpy_r_r127);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL519;
    }
    cpy_r_r130 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_block_identifier;
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "block_identifier", 142, CPyStatic_globals);
        goto CPyL533;
    }
    CPy_INCREF(cpy_r_r130);
CPyL108: ;
    cpy_r_r131 = PyObject_GetItem(cpy_r_r129, cpy_r_r130);
    CPy_DECREF(cpy_r_r129);
    CPy_DECREF(cpy_r_r130);
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL519;
    }
    cpy_r_r132 = PyObject_Type(cpy_r_r131);
    cpy_r_r133 = CPyStatics[23]; /* '__aexit__' */
    cpy_r_r134 = CPyObject_GetAttr(cpy_r_r132, cpy_r_r133);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL534;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7 = cpy_r_r134;
    cpy_r_r135 = 1;
    if (unlikely(!cpy_r_r135)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL534;
    }
    cpy_r_r136 = CPyStatics[24]; /* '__aenter__' */
    cpy_r_r137 = CPyObject_GetAttr(cpy_r_r132, cpy_r_r136);
    CPy_DECREF(cpy_r_r132);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL535;
    }
    PyObject *cpy_r_r138[1] = {cpy_r_r131};
    cpy_r_r139 = (PyObject **)&cpy_r_r138;
    cpy_r_r140 = _PyObject_Vectorcall(cpy_r_r137, cpy_r_r139, 1, 0);
    CPy_DECREF(cpy_r_r137);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL535;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8 = cpy_r_r131;
    cpy_r_r141 = 1;
    if (unlikely(!cpy_r_r141)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL536;
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__9 = 1;
    cpy_r_r142 = 1;
    if (unlikely(!cpy_r_r142)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL536;
    }
    cpy_r_r143 = CPy_GetCoro(cpy_r_r140);
    CPy_DECREF(cpy_r_r140);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL519;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10 = cpy_r_r143;
    cpy_r_r144 = 1;
    if (unlikely(!cpy_r_r144)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL519;
    }
    cpy_r_r145 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10;
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL519;
    }
    CPy_INCREF(cpy_r_r145);
CPyL118: ;
    cpy_r_r146 = CPyIter_Next(cpy_r_r145);
    CPy_DECREF(cpy_r_r145);
    if (cpy_r_r146 == NULL) {
        goto CPyL537;
    } else
        goto CPyL121;
CPyL119: ;
    cpy_r_r147 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL538;
    }
    cpy_r_r148 = cpy_r_r147;
    CPy_DECREF(cpy_r_r148);
    goto CPyL150;
CPyL121: ;
    cpy_r_r149 = cpy_r_r146;
CPyL122: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 6;
    cpy_r_r150 = 1;
    if (unlikely(!cpy_r_r150)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL539;
    } else
        goto CPyL540;
CPyL123: ;
    return cpy_r_r149;
CPyL124: ;
    cpy_r_r151 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r152 = cpy_r_type != cpy_r_r151;
    if (!cpy_r_r152) goto CPyL127;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL128;
    } else
        goto CPyL541;
CPyL126: ;
    CPy_Unreachable();
CPyL127: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL145;
CPyL128: ;
    cpy_r_r153 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11.f2);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11 = cpy_r_r153;
    cpy_r_r154 = 1;
    if (unlikely(!cpy_r_r154)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL542;
    }
    cpy_r_r155 = (PyObject **)&cpy_r_r5;
    cpy_r_r156 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10;
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL542;
    }
    CPy_INCREF(cpy_r_r156);
CPyL130: ;
    cpy_r_r157 = CPy_YieldFromErrorHandle(cpy_r_r156, cpy_r_r155);
    CPy_DecRef(cpy_r_r156);
    if (unlikely(cpy_r_r157 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL542;
    }
    if (cpy_r_r157) goto CPyL137;
    if (cpy_r_r5 == NULL) {
        goto CPyL543;
    } else
        goto CPyL135;
CPyL133: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r158 = 0;
    if (unlikely(!cpy_r_r158)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL142;
    } else
        goto CPyL544;
CPyL134: ;
    CPy_Unreachable();
CPyL135: ;
    CPy_INCREF(cpy_r_r5);
    cpy_r_r149 = cpy_r_r5;
    cpy_r_r159 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11;
    if (unlikely(cpy_r_r159.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL545;
    }
    CPy_INCREF(cpy_r_r159.f0);
    CPy_INCREF(cpy_r_r159.f1);
    CPy_INCREF(cpy_r_r159.f2);
CPyL136: ;
    CPy_RestoreExcInfo(cpy_r_r159);
    CPy_DecRef(cpy_r_r159.f0);
    CPy_DecRef(cpy_r_r159.f1);
    CPy_DecRef(cpy_r_r159.f2);
    goto CPyL122;
CPyL137: ;
    if (cpy_r_r5 == NULL) {
        goto CPyL546;
    } else
        goto CPyL140;
CPyL138: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r160 = 0;
    if (unlikely(!cpy_r_r160)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL142;
    } else
        goto CPyL547;
CPyL139: ;
    CPy_Unreachable();
CPyL140: ;
    cpy_r_r148 = cpy_r_r5;
    CPy_DecRef(cpy_r_r148);
    cpy_r_r161 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11;
    if (unlikely(cpy_r_r161.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL548;
    }
    CPy_INCREF(cpy_r_r161.f0);
    CPy_INCREF(cpy_r_r161.f1);
    CPy_INCREF(cpy_r_r161.f2);
CPyL141: ;
    CPy_RestoreExcInfo(cpy_r_r161);
    CPy_DecRef(cpy_r_r161.f0);
    CPy_DecRef(cpy_r_r161.f1);
    CPy_DecRef(cpy_r_r161.f2);
    goto CPyL150;
CPyL142: ;
    cpy_r_r162 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__11;
    if (unlikely(cpy_r_r162.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL295;
    }
    CPy_INCREF(cpy_r_r162.f0);
    CPy_INCREF(cpy_r_r162.f1);
    CPy_INCREF(cpy_r_r162.f2);
CPyL143: ;
    CPy_RestoreExcInfo(cpy_r_r162);
    CPy_DecRef(cpy_r_r162.f0);
    CPy_DecRef(cpy_r_r162.f1);
    CPy_DecRef(cpy_r_r162.f2);
    cpy_r_r163 = CPy_KeepPropagating();
    if (!cpy_r_r163) {
        goto CPyL295;
    } else
        goto CPyL549;
CPyL144: ;
    CPy_Unreachable();
CPyL145: ;
    cpy_r_r164 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__10;
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL550;
    }
    CPy_INCREF(cpy_r_r164);
CPyL146: ;
    cpy_r_r165 = CPyIter_Send(cpy_r_r164, cpy_r_arg);
    CPy_DECREF(cpy_r_r164);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r165 == NULL) goto CPyL551;
    cpy_r_r149 = cpy_r_r165;
    goto CPyL122;
CPyL148: ;
    cpy_r_r166 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL538;
    }
    cpy_r_r148 = cpy_r_r166;
    CPy_DECREF(cpy_r_r148);
CPyL150: ;
    cpy_r_r167 = ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r24)->_w3;
    if (unlikely(cpy_r_r167 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'w3' of '_get_coroutine_fn_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r167);
    }
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL552;
    }
CPyL151: ;
    cpy_r_r168 = CPyStatics[27]; /* 'eth' */
    cpy_r_r169 = CPyObject_GetAttr(cpy_r_r167, cpy_r_r168);
    CPy_DECREF(cpy_r_r167);
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL552;
    }
    cpy_r_r170 = CPyStatics[28]; /* 'to' */
    cpy_r_r171 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 143, CPyStatic_globals);
        goto CPyL553;
    }
    CPy_INCREF(cpy_r_r171);
CPyL153: ;
    cpy_r_r172 = CPyStatics[11]; /* '_address' */
    cpy_r_r173 = CPyObject_GetAttr(cpy_r_r171, cpy_r_r172);
    CPy_DECREF(cpy_r_r171);
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL553;
    }
    cpy_r_r174 = CPyStatics[29]; /* 'data' */
    cpy_r_r175 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_data;
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "data", 143, CPyStatic_globals);
        goto CPyL554;
    }
    CPy_INCREF(cpy_r_r175);
CPyL155: ;
    cpy_r_r176 = CPyDict_Build(2, cpy_r_r170, cpy_r_r173, cpy_r_r174, cpy_r_r175);
    CPy_DECREF(cpy_r_r173);
    CPy_DECREF(cpy_r_r175);
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL553;
    }
    cpy_r_r177 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_block_identifier;
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "block_identifier", 143, CPyStatic_globals);
        goto CPyL555;
    }
    CPy_INCREF(cpy_r_r177);
CPyL157: ;
    cpy_r_r178 = CPyStatics[30]; /* 'call' */
    cpy_r_r179 = CPyObject_CallMethodObjArgs(cpy_r_r169, cpy_r_r178, cpy_r_r176, cpy_r_r177, NULL);
    CPy_DECREF(cpy_r_r169);
    CPy_DECREF(cpy_r_r176);
    CPy_DECREF(cpy_r_r177);
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL552;
    }
    cpy_r_r180 = CPy_GetCoro(cpy_r_r179);
    CPy_DECREF(cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL552;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12 = cpy_r_r180;
    cpy_r_r181 = 1;
    if (unlikely(!cpy_r_r181)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL552;
    }
    cpy_r_r182 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12;
    if (unlikely(cpy_r_r182 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL552;
    }
    CPy_INCREF(cpy_r_r182);
CPyL161: ;
    cpy_r_r183 = CPyIter_Next(cpy_r_r182);
    CPy_DECREF(cpy_r_r182);
    if (cpy_r_r183 == NULL) {
        goto CPyL556;
    } else
        goto CPyL164;
CPyL162: ;
    cpy_r_r184 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r185 = cpy_r_r184;
    goto CPyL193;
CPyL164: ;
    cpy_r_r186 = cpy_r_r183;
CPyL165: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 8;
    cpy_r_r187 = 1;
    if (unlikely(!cpy_r_r187)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL557;
    } else
        goto CPyL558;
CPyL166: ;
    return cpy_r_r186;
CPyL167: ;
    cpy_r_r188 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r189 = cpy_r_type != cpy_r_r188;
    if (!cpy_r_r189) goto CPyL170;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL171;
    } else
        goto CPyL559;
CPyL169: ;
    CPy_Unreachable();
CPyL170: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL188;
CPyL171: ;
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
        goto CPyL560;
    }
    cpy_r_r192 = (PyObject **)&cpy_r_r7;
    cpy_r_r193 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12;
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL560;
    }
    CPy_INCREF(cpy_r_r193);
CPyL173: ;
    cpy_r_r194 = CPy_YieldFromErrorHandle(cpy_r_r193, cpy_r_r192);
    CPy_DecRef(cpy_r_r193);
    if (unlikely(cpy_r_r194 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL560;
    }
    if (cpy_r_r194) goto CPyL180;
    if (cpy_r_r7 != NULL) goto CPyL178;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r195 = 0;
    if (unlikely(!cpy_r_r195)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL185;
    } else
        goto CPyL561;
CPyL177: ;
    CPy_Unreachable();
CPyL178: ;
    CPy_INCREF(cpy_r_r7);
    cpy_r_r186 = cpy_r_r7;
    cpy_r_r196 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13;
    if (unlikely(cpy_r_r196.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL562;
    }
    CPy_INCREF(cpy_r_r196.f0);
    CPy_INCREF(cpy_r_r196.f1);
    CPy_INCREF(cpy_r_r196.f2);
CPyL179: ;
    CPy_RestoreExcInfo(cpy_r_r196);
    CPy_DecRef(cpy_r_r196.f0);
    CPy_DecRef(cpy_r_r196.f1);
    CPy_DecRef(cpy_r_r196.f2);
    goto CPyL165;
CPyL180: ;
    if (cpy_r_r7 != NULL) goto CPyL183;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r197 = 0;
    if (unlikely(!cpy_r_r197)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL185;
    } else
        goto CPyL563;
CPyL182: ;
    CPy_Unreachable();
CPyL183: ;
    cpy_r_r185 = cpy_r_r7;
    cpy_r_r198 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13;
    if (unlikely(cpy_r_r198.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL564;
    }
    CPy_INCREF(cpy_r_r198.f0);
    CPy_INCREF(cpy_r_r198.f1);
    CPy_INCREF(cpy_r_r198.f2);
CPyL184: ;
    CPy_RestoreExcInfo(cpy_r_r198);
    CPy_DecRef(cpy_r_r198.f0);
    CPy_DecRef(cpy_r_r198.f1);
    CPy_DecRef(cpy_r_r198.f2);
    goto CPyL193;
CPyL185: ;
    cpy_r_r199 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__13;
    if (unlikely(cpy_r_r199.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL194;
    }
    CPy_INCREF(cpy_r_r199.f0);
    CPy_INCREF(cpy_r_r199.f1);
    CPy_INCREF(cpy_r_r199.f2);
CPyL186: ;
    CPy_RestoreExcInfo(cpy_r_r199);
    CPy_DecRef(cpy_r_r199.f0);
    CPy_DecRef(cpy_r_r199.f1);
    CPy_DecRef(cpy_r_r199.f2);
    cpy_r_r200 = CPy_KeepPropagating();
    if (!cpy_r_r200) {
        goto CPyL194;
    } else
        goto CPyL565;
CPyL187: ;
    CPy_Unreachable();
CPyL188: ;
    cpy_r_r201 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__12;
    if (unlikely(cpy_r_r201 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r201);
CPyL189: ;
    cpy_r_r202 = CPyIter_Send(cpy_r_r201, cpy_r_arg);
    CPy_DECREF(cpy_r_r201);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r202 == NULL) goto CPyL567;
    cpy_r_r186 = cpy_r_r202;
    goto CPyL165;
CPyL191: ;
    cpy_r_r203 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r185 = cpy_r_r203;
CPyL193: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output = cpy_r_r185;
    cpy_r_r204 = 1;
    if (unlikely(!cpy_r_r204)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 143, CPyStatic_globals);
    } else
        goto CPyL568;
CPyL194: ;
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
        goto CPyL569;
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__9 = 0;
    cpy_r_r207 = 1;
    if (unlikely(!cpy_r_r207)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL569;
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
        goto CPyL570;
    }
    CPy_INCREF(cpy_r_r212);
CPyL197: ;
    cpy_r_r213 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8;
    if (unlikely(cpy_r_r213 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL571;
    }
    CPy_INCREF(cpy_r_r213);
CPyL198: ;
    PyObject *cpy_r_r214[4] = {cpy_r_r213, cpy_r_r209, cpy_r_r210, cpy_r_r211};
    cpy_r_r215 = (PyObject **)&cpy_r_r214;
    cpy_r_r216 = _PyObject_Vectorcall(cpy_r_r212, cpy_r_r215, 4, 0);
    CPy_DecRef(cpy_r_r212);
    if (unlikely(cpy_r_r216 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL572;
    }
    CPy_DecRef(cpy_r_r213);
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    cpy_r_r217 = CPy_GetCoro(cpy_r_r216);
    CPy_DecRef(cpy_r_r216);
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL569;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15 = cpy_r_r217;
    cpy_r_r218 = 1;
    if (unlikely(!cpy_r_r218)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL569;
    }
    cpy_r_r219 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15;
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL569;
    }
    CPy_INCREF(cpy_r_r219);
CPyL202: ;
    cpy_r_r220 = CPyIter_Next(cpy_r_r219);
    CPy_DecRef(cpy_r_r219);
    if (cpy_r_r220 == NULL) {
        goto CPyL573;
    } else
        goto CPyL205;
CPyL203: ;
    cpy_r_r221 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r221 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL240;
    }
    cpy_r_r222 = cpy_r_r221;
    goto CPyL234;
CPyL205: ;
    cpy_r_r223 = cpy_r_r220;
CPyL206: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 10;
    cpy_r_r224 = 1;
    if (unlikely(!cpy_r_r224)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL574;
    } else
        goto CPyL575;
CPyL207: ;
    return cpy_r_r223;
CPyL208: ;
    cpy_r_r225 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r226 = cpy_r_type != cpy_r_r225;
    if (!cpy_r_r226) goto CPyL211;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL212;
    } else
        goto CPyL576;
CPyL210: ;
    CPy_Unreachable();
CPyL211: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL229;
CPyL212: ;
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
        goto CPyL577;
    }
    cpy_r_r229 = (PyObject **)&cpy_r_r9;
    cpy_r_r230 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15;
    if (unlikely(cpy_r_r230 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL577;
    }
    CPy_INCREF(cpy_r_r230);
CPyL214: ;
    cpy_r_r231 = CPy_YieldFromErrorHandle(cpy_r_r230, cpy_r_r229);
    CPy_DecRef(cpy_r_r230);
    if (unlikely(cpy_r_r231 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL577;
    }
    if (cpy_r_r231) goto CPyL221;
    if (cpy_r_r9 != NULL) goto CPyL219;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r232 = 0;
    if (unlikely(!cpy_r_r232)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL226;
    } else
        goto CPyL578;
CPyL218: ;
    CPy_Unreachable();
CPyL219: ;
    CPy_INCREF(cpy_r_r9);
    cpy_r_r223 = cpy_r_r9;
    cpy_r_r233 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16;
    if (unlikely(cpy_r_r233.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__16", -1, CPyStatic_globals);
        goto CPyL579;
    }
    CPy_INCREF(cpy_r_r233.f0);
    CPy_INCREF(cpy_r_r233.f1);
    CPy_INCREF(cpy_r_r233.f2);
CPyL220: ;
    CPy_RestoreExcInfo(cpy_r_r233);
    CPy_DecRef(cpy_r_r233.f0);
    CPy_DecRef(cpy_r_r233.f1);
    CPy_DecRef(cpy_r_r233.f2);
    goto CPyL206;
CPyL221: ;
    if (cpy_r_r9 != NULL) goto CPyL224;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r234 = 0;
    if (unlikely(!cpy_r_r234)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL226;
    } else
        goto CPyL580;
CPyL223: ;
    CPy_Unreachable();
CPyL224: ;
    cpy_r_r222 = cpy_r_r9;
    cpy_r_r235 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16;
    if (unlikely(cpy_r_r235.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__16", -1, CPyStatic_globals);
        goto CPyL581;
    }
    CPy_INCREF(cpy_r_r235.f0);
    CPy_INCREF(cpy_r_r235.f1);
    CPy_INCREF(cpy_r_r235.f2);
CPyL225: ;
    CPy_RestoreExcInfo(cpy_r_r235);
    CPy_DecRef(cpy_r_r235.f0);
    CPy_DecRef(cpy_r_r235.f1);
    CPy_DecRef(cpy_r_r235.f2);
    goto CPyL234;
CPyL226: ;
    cpy_r_r236 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__16;
    if (unlikely(cpy_r_r236.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__16", -1, CPyStatic_globals);
        goto CPyL240;
    }
    CPy_INCREF(cpy_r_r236.f0);
    CPy_INCREF(cpy_r_r236.f1);
    CPy_INCREF(cpy_r_r236.f2);
CPyL227: ;
    CPy_RestoreExcInfo(cpy_r_r236);
    CPy_DecRef(cpy_r_r236.f0);
    CPy_DecRef(cpy_r_r236.f1);
    CPy_DecRef(cpy_r_r236.f2);
    cpy_r_r237 = CPy_KeepPropagating();
    if (!cpy_r_r237) {
        goto CPyL240;
    } else
        goto CPyL582;
CPyL228: ;
    CPy_Unreachable();
CPyL229: ;
    cpy_r_r238 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__15;
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL583;
    }
    CPy_INCREF(cpy_r_r238);
CPyL230: ;
    cpy_r_r239 = CPyIter_Send(cpy_r_r238, cpy_r_arg);
    CPy_DECREF(cpy_r_r238);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r239 == NULL) goto CPyL584;
    cpy_r_r223 = cpy_r_r239;
    goto CPyL206;
CPyL232: ;
    cpy_r_r240 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL240;
    }
    cpy_r_r222 = cpy_r_r240;
CPyL234: ;
    cpy_r_r241 = PyObject_IsTrue(cpy_r_r222);
    CPy_DECREF(cpy_r_r222);
    cpy_r_r242 = cpy_r_r241 >= 0;
    if (unlikely(!cpy_r_r242)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL240;
    }
    cpy_r_r243 = cpy_r_r241;
    if (cpy_r_r243) goto CPyL238;
    CPy_Reraise();
    if (!0) {
        goto CPyL240;
    } else
        goto CPyL585;
CPyL237: ;
    CPy_Unreachable();
CPyL238: ;
    cpy_r_r244 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14;
    if (unlikely(cpy_r_r244.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL244;
    }
    CPy_INCREF(cpy_r_r244.f0);
    CPy_INCREF(cpy_r_r244.f1);
    CPy_INCREF(cpy_r_r244.f2);
CPyL239: ;
    CPy_RestoreExcInfo(cpy_r_r244);
    CPy_DECREF(cpy_r_r244.f0);
    CPy_DECREF(cpy_r_r244.f1);
    CPy_DECREF(cpy_r_r244.f2);
    goto CPyL243;
CPyL240: ;
    cpy_r_r245 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__14;
    if (unlikely(cpy_r_r245.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL244;
    }
    CPy_INCREF(cpy_r_r245.f0);
    CPy_INCREF(cpy_r_r245.f1);
    CPy_INCREF(cpy_r_r245.f2);
CPyL241: ;
    CPy_RestoreExcInfo(cpy_r_r245);
    CPy_DECREF(cpy_r_r245.f0);
    CPy_DECREF(cpy_r_r245.f1);
    CPy_DECREF(cpy_r_r245.f2);
    cpy_r_r246 = CPy_KeepPropagating();
    if (!cpy_r_r246) {
        goto CPyL244;
    } else
        goto CPyL586;
CPyL242: ;
    CPy_Unreachable();
CPyL243: ;
    tuple_T3OOO __tmp3 = { NULL, NULL, NULL };
    cpy_r_r247 = __tmp3;
    cpy_r_r13 = cpy_r_r247;
    goto CPyL245;
CPyL244: ;
    cpy_r_r248 = CPy_CatchError();
    cpy_r_r13 = cpy_r_r248;
CPyL245: ;
    cpy_r_r249 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__9;
    if (unlikely(cpy_r_r249 == 2)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL587;
    }
CPyL246: ;
    if (!cpy_r_r249) goto CPyL588;
CPyL247: ;
    cpy_r_r250 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r251 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__7;
    if (unlikely(cpy_r_r251 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__7", -1, CPyStatic_globals);
        goto CPyL587;
    }
    CPy_INCREF(cpy_r_r251);
CPyL248: ;
    cpy_r_r252 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__8;
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL589;
    }
    CPy_INCREF(cpy_r_r252);
CPyL249: ;
    PyObject *cpy_r_r253[4] = {cpy_r_r252, cpy_r_r250, cpy_r_r250, cpy_r_r250};
    cpy_r_r254 = (PyObject **)&cpy_r_r253;
    cpy_r_r255 = _PyObject_Vectorcall(cpy_r_r251, cpy_r_r254, 4, 0);
    CPy_DECREF(cpy_r_r251);
    if (unlikely(cpy_r_r255 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL590;
    }
    CPy_DECREF(cpy_r_r252);
    cpy_r_r256 = CPy_GetCoro(cpy_r_r255);
    CPy_DECREF(cpy_r_r255);
    if (unlikely(cpy_r_r256 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL587;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17 = cpy_r_r256;
    cpy_r_r257 = 1;
    if (unlikely(!cpy_r_r257)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL587;
    }
    cpy_r_r258 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17;
    if (unlikely(cpy_r_r258 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__17", -1, CPyStatic_globals);
        goto CPyL587;
    }
    CPy_INCREF(cpy_r_r258);
CPyL253: ;
    cpy_r_r259 = CPyIter_Next(cpy_r_r258);
    CPy_DECREF(cpy_r_r258);
    if (cpy_r_r259 == NULL) {
        goto CPyL591;
    } else
        goto CPyL256;
CPyL254: ;
    cpy_r_r260 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r260 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL288;
    }
    cpy_r_r261 = cpy_r_r260;
    CPy_DECREF(cpy_r_r261);
    goto CPyL285;
CPyL256: ;
    cpy_r_r262 = cpy_r_r259;
CPyL257: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 12;
    cpy_r_r263 = 1;
    if (unlikely(!cpy_r_r263)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL592;
    } else
        goto CPyL593;
CPyL258: ;
    return cpy_r_r262;
CPyL259: ;
    cpy_r_r264 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r265 = cpy_r_type != cpy_r_r264;
    if (!cpy_r_r265) goto CPyL262;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL263;
    } else
        goto CPyL594;
CPyL261: ;
    CPy_Unreachable();
CPyL262: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL280;
CPyL263: ;
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
        goto CPyL595;
    }
    cpy_r_r268 = (PyObject **)&cpy_r_r11;
    cpy_r_r269 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17;
    if (unlikely(cpy_r_r269 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__17", -1, CPyStatic_globals);
        goto CPyL595;
    }
    CPy_INCREF(cpy_r_r269);
CPyL265: ;
    cpy_r_r270 = CPy_YieldFromErrorHandle(cpy_r_r269, cpy_r_r268);
    CPy_DecRef(cpy_r_r269);
    if (unlikely(cpy_r_r270 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL595;
    }
    if (cpy_r_r270) goto CPyL272;
    if (cpy_r_r11 != NULL) goto CPyL270;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r271 = 0;
    if (unlikely(!cpy_r_r271)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL277;
    } else
        goto CPyL596;
CPyL269: ;
    CPy_Unreachable();
CPyL270: ;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r262 = cpy_r_r11;
    cpy_r_r272 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18;
    if (unlikely(cpy_r_r272.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__18", -1, CPyStatic_globals);
        goto CPyL597;
    }
    CPy_INCREF(cpy_r_r272.f0);
    CPy_INCREF(cpy_r_r272.f1);
    CPy_INCREF(cpy_r_r272.f2);
CPyL271: ;
    CPy_RestoreExcInfo(cpy_r_r272);
    CPy_DecRef(cpy_r_r272.f0);
    CPy_DecRef(cpy_r_r272.f1);
    CPy_DecRef(cpy_r_r272.f2);
    goto CPyL257;
CPyL272: ;
    if (cpy_r_r11 != NULL) goto CPyL275;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r273 = 0;
    if (unlikely(!cpy_r_r273)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL277;
    } else
        goto CPyL598;
CPyL274: ;
    CPy_Unreachable();
CPyL275: ;
    cpy_r_r261 = cpy_r_r11;
    CPy_DecRef(cpy_r_r261);
    cpy_r_r274 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18;
    if (unlikely(cpy_r_r274.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__18", -1, CPyStatic_globals);
        goto CPyL277;
    }
    CPy_INCREF(cpy_r_r274.f0);
    CPy_INCREF(cpy_r_r274.f1);
    CPy_INCREF(cpy_r_r274.f2);
CPyL276: ;
    CPy_RestoreExcInfo(cpy_r_r274);
    CPy_DecRef(cpy_r_r274.f0);
    CPy_DecRef(cpy_r_r274.f1);
    CPy_DecRef(cpy_r_r274.f2);
    goto CPyL285;
CPyL277: ;
    cpy_r_r275 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__18;
    if (unlikely(cpy_r_r275.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__18", -1, CPyStatic_globals);
        goto CPyL288;
    }
    CPy_INCREF(cpy_r_r275.f0);
    CPy_INCREF(cpy_r_r275.f1);
    CPy_INCREF(cpy_r_r275.f2);
CPyL278: ;
    CPy_RestoreExcInfo(cpy_r_r275);
    CPy_DecRef(cpy_r_r275.f0);
    CPy_DecRef(cpy_r_r275.f1);
    CPy_DecRef(cpy_r_r275.f2);
    cpy_r_r276 = CPy_KeepPropagating();
    if (!cpy_r_r276) {
        goto CPyL288;
    } else
        goto CPyL599;
CPyL279: ;
    CPy_Unreachable();
CPyL280: ;
    cpy_r_r277 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__17;
    if (unlikely(cpy_r_r277 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__17", -1, CPyStatic_globals);
        goto CPyL600;
    }
    CPy_INCREF(cpy_r_r277);
CPyL281: ;
    cpy_r_r278 = CPyIter_Send(cpy_r_r277, cpy_r_arg);
    CPy_DECREF(cpy_r_r277);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r278 == NULL) goto CPyL601;
    cpy_r_r262 = cpy_r_r278;
    goto CPyL257;
CPyL283: ;
    cpy_r_r279 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r279 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 142, CPyStatic_globals);
        goto CPyL288;
    }
    cpy_r_r261 = cpy_r_r279;
    CPy_DECREF(cpy_r_r261);
CPyL285: ;
    if (cpy_r_r13.f0 == NULL) goto CPyL602;
    CPy_Reraise();
    if (!0) {
        goto CPyL288;
    } else
        goto CPyL603;
CPyL287: ;
    CPy_Unreachable();
CPyL288: ;
    if (cpy_r_r13.f0 == NULL) goto CPyL293;
    if (cpy_r_r13.f0 != NULL) goto CPyL292;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r280 = 0;
    if (unlikely(!cpy_r_r280)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL295;
    } else
        goto CPyL604;
CPyL291: ;
    CPy_Unreachable();
CPyL292: ;
    CPy_RestoreExcInfo(cpy_r_r13);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
CPyL293: ;
    cpy_r_r281 = CPy_KeepPropagating();
    if (!cpy_r_r281) {
        goto CPyL295;
    } else
        goto CPyL605;
CPyL294: ;
    CPy_Unreachable();
CPyL295: ;
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
        goto CPyL606;
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__2 = 0;
    cpy_r_r284 = 1;
    if (unlikely(!cpy_r_r284)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL606;
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
        goto CPyL607;
    }
    CPy_INCREF(cpy_r_r289);
CPyL298: ;
    cpy_r_r290 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1;
    if (unlikely(cpy_r_r290 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__1", -1, CPyStatic_globals);
        goto CPyL608;
    }
    CPy_INCREF(cpy_r_r290);
CPyL299: ;
    PyObject *cpy_r_r291[4] = {cpy_r_r290, cpy_r_r286, cpy_r_r287, cpy_r_r288};
    cpy_r_r292 = (PyObject **)&cpy_r_r291;
    cpy_r_r293 = _PyObject_Vectorcall(cpy_r_r289, cpy_r_r292, 4, 0);
    CPy_DECREF(cpy_r_r289);
    if (unlikely(cpy_r_r293 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL609;
    }
    CPy_DECREF(cpy_r_r290);
    CPy_DECREF(cpy_r_r286);
    CPy_DECREF(cpy_r_r287);
    CPy_DECREF(cpy_r_r288);
    cpy_r_r294 = CPy_GetCoro(cpy_r_r293);
    CPy_DECREF(cpy_r_r293);
    if (unlikely(cpy_r_r294 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL606;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20 = cpy_r_r294;
    cpy_r_r295 = 1;
    if (unlikely(!cpy_r_r295)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL606;
    }
    cpy_r_r296 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20;
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__20", -1, CPyStatic_globals);
        goto CPyL606;
    }
    CPy_INCREF(cpy_r_r296);
CPyL303: ;
    cpy_r_r297 = CPyIter_Next(cpy_r_r296);
    CPy_DECREF(cpy_r_r296);
    if (cpy_r_r297 == NULL) {
        goto CPyL610;
    } else
        goto CPyL306;
CPyL304: ;
    cpy_r_r298 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r298 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL341;
    }
    cpy_r_r299 = cpy_r_r298;
    goto CPyL335;
CPyL306: ;
    cpy_r_r300 = cpy_r_r297;
CPyL307: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 14;
    cpy_r_r301 = 1;
    if (unlikely(!cpy_r_r301)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL611;
    } else
        goto CPyL612;
CPyL308: ;
    return cpy_r_r300;
CPyL309: ;
    cpy_r_r302 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r303 = cpy_r_type != cpy_r_r302;
    if (!cpy_r_r303) goto CPyL312;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL313;
    } else
        goto CPyL613;
CPyL311: ;
    CPy_Unreachable();
CPyL312: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL330;
CPyL313: ;
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
        goto CPyL614;
    }
    cpy_r_r306 = (PyObject **)&cpy_r_r15;
    cpy_r_r307 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20;
    if (unlikely(cpy_r_r307 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__20", -1, CPyStatic_globals);
        goto CPyL614;
    }
    CPy_INCREF(cpy_r_r307);
CPyL315: ;
    cpy_r_r308 = CPy_YieldFromErrorHandle(cpy_r_r307, cpy_r_r306);
    CPy_DecRef(cpy_r_r307);
    if (unlikely(cpy_r_r308 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL614;
    }
    if (cpy_r_r308) goto CPyL322;
    if (cpy_r_r15 != NULL) goto CPyL320;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r309 = 0;
    if (unlikely(!cpy_r_r309)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL327;
    } else
        goto CPyL615;
CPyL319: ;
    CPy_Unreachable();
CPyL320: ;
    CPy_INCREF(cpy_r_r15);
    cpy_r_r300 = cpy_r_r15;
    cpy_r_r310 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21;
    if (unlikely(cpy_r_r310.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__21", -1, CPyStatic_globals);
        goto CPyL616;
    }
    CPy_INCREF(cpy_r_r310.f0);
    CPy_INCREF(cpy_r_r310.f1);
    CPy_INCREF(cpy_r_r310.f2);
CPyL321: ;
    CPy_RestoreExcInfo(cpy_r_r310);
    CPy_DecRef(cpy_r_r310.f0);
    CPy_DecRef(cpy_r_r310.f1);
    CPy_DecRef(cpy_r_r310.f2);
    goto CPyL307;
CPyL322: ;
    if (cpy_r_r15 != NULL) goto CPyL325;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r311 = 0;
    if (unlikely(!cpy_r_r311)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL327;
    } else
        goto CPyL617;
CPyL324: ;
    CPy_Unreachable();
CPyL325: ;
    cpy_r_r299 = cpy_r_r15;
    cpy_r_r312 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21;
    if (unlikely(cpy_r_r312.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__21", -1, CPyStatic_globals);
        goto CPyL618;
    }
    CPy_INCREF(cpy_r_r312.f0);
    CPy_INCREF(cpy_r_r312.f1);
    CPy_INCREF(cpy_r_r312.f2);
CPyL326: ;
    CPy_RestoreExcInfo(cpy_r_r312);
    CPy_DecRef(cpy_r_r312.f0);
    CPy_DecRef(cpy_r_r312.f1);
    CPy_DecRef(cpy_r_r312.f2);
    goto CPyL335;
CPyL327: ;
    cpy_r_r313 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__21;
    if (unlikely(cpy_r_r313.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__21", -1, CPyStatic_globals);
        goto CPyL341;
    }
    CPy_INCREF(cpy_r_r313.f0);
    CPy_INCREF(cpy_r_r313.f1);
    CPy_INCREF(cpy_r_r313.f2);
CPyL328: ;
    CPy_RestoreExcInfo(cpy_r_r313);
    CPy_DecRef(cpy_r_r313.f0);
    CPy_DecRef(cpy_r_r313.f1);
    CPy_DecRef(cpy_r_r313.f2);
    cpy_r_r314 = CPy_KeepPropagating();
    if (!cpy_r_r314) {
        goto CPyL341;
    } else
        goto CPyL619;
CPyL329: ;
    CPy_Unreachable();
CPyL330: ;
    cpy_r_r315 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__20;
    if (unlikely(cpy_r_r315 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__20", -1, CPyStatic_globals);
        goto CPyL620;
    }
    CPy_INCREF(cpy_r_r315);
CPyL331: ;
    cpy_r_r316 = CPyIter_Send(cpy_r_r315, cpy_r_arg);
    CPy_DECREF(cpy_r_r315);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r316 == NULL) goto CPyL621;
    cpy_r_r300 = cpy_r_r316;
    goto CPyL307;
CPyL333: ;
    cpy_r_r317 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r317 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL341;
    }
    cpy_r_r299 = cpy_r_r317;
CPyL335: ;
    cpy_r_r318 = PyObject_IsTrue(cpy_r_r299);
    CPy_DECREF(cpy_r_r299);
    cpy_r_r319 = cpy_r_r318 >= 0;
    if (unlikely(!cpy_r_r319)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL341;
    }
    cpy_r_r320 = cpy_r_r318;
    if (cpy_r_r320) goto CPyL339;
    CPy_Reraise();
    if (!0) {
        goto CPyL341;
    } else
        goto CPyL622;
CPyL338: ;
    CPy_Unreachable();
CPyL339: ;
    cpy_r_r321 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19;
    if (unlikely(cpy_r_r321.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__19", -1, CPyStatic_globals);
        goto CPyL345;
    }
    CPy_INCREF(cpy_r_r321.f0);
    CPy_INCREF(cpy_r_r321.f1);
    CPy_INCREF(cpy_r_r321.f2);
CPyL340: ;
    CPy_RestoreExcInfo(cpy_r_r321);
    CPy_DECREF(cpy_r_r321.f0);
    CPy_DECREF(cpy_r_r321.f1);
    CPy_DECREF(cpy_r_r321.f2);
    goto CPyL344;
CPyL341: ;
    cpy_r_r322 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__19;
    if (unlikely(cpy_r_r322.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__19", -1, CPyStatic_globals);
        goto CPyL345;
    }
    CPy_INCREF(cpy_r_r322.f0);
    CPy_INCREF(cpy_r_r322.f1);
    CPy_INCREF(cpy_r_r322.f2);
CPyL342: ;
    CPy_RestoreExcInfo(cpy_r_r322);
    CPy_DECREF(cpy_r_r322.f0);
    CPy_DECREF(cpy_r_r322.f1);
    CPy_DECREF(cpy_r_r322.f2);
    cpy_r_r323 = CPy_KeepPropagating();
    if (!cpy_r_r323) {
        goto CPyL345;
    } else
        goto CPyL623;
CPyL343: ;
    CPy_Unreachable();
CPyL344: ;
    tuple_T3OOO __tmp4 = { NULL, NULL, NULL };
    cpy_r_r324 = __tmp4;
    cpy_r_r19 = cpy_r_r324;
    goto CPyL346;
CPyL345: ;
    cpy_r_r325 = CPy_CatchError();
    cpy_r_r19 = cpy_r_r325;
CPyL346: ;
    cpy_r_r326 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__2;
    if (unlikely(cpy_r_r326 == 2)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL624;
    }
CPyL347: ;
    if (!cpy_r_r326) goto CPyL625;
CPyL348: ;
    cpy_r_r327 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r328 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__0;
    if (unlikely(cpy_r_r328 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__0", -1, CPyStatic_globals);
        goto CPyL624;
    }
    CPy_INCREF(cpy_r_r328);
CPyL349: ;
    cpy_r_r329 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__1;
    if (unlikely(cpy_r_r329 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__1", -1, CPyStatic_globals);
        goto CPyL626;
    }
    CPy_INCREF(cpy_r_r329);
CPyL350: ;
    PyObject *cpy_r_r330[4] = {cpy_r_r329, cpy_r_r327, cpy_r_r327, cpy_r_r327};
    cpy_r_r331 = (PyObject **)&cpy_r_r330;
    cpy_r_r332 = _PyObject_Vectorcall(cpy_r_r328, cpy_r_r331, 4, 0);
    CPy_DECREF(cpy_r_r328);
    if (unlikely(cpy_r_r332 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL627;
    }
    CPy_DECREF(cpy_r_r329);
    cpy_r_r333 = CPy_GetCoro(cpy_r_r332);
    CPy_DECREF(cpy_r_r332);
    if (unlikely(cpy_r_r333 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL624;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22 = cpy_r_r333;
    cpy_r_r334 = 1;
    if (unlikely(!cpy_r_r334)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL624;
    }
    cpy_r_r335 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22;
    if (unlikely(cpy_r_r335 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__22", -1, CPyStatic_globals);
        goto CPyL624;
    }
    CPy_INCREF(cpy_r_r335);
CPyL354: ;
    cpy_r_r336 = CPyIter_Next(cpy_r_r335);
    CPy_DECREF(cpy_r_r335);
    if (cpy_r_r336 == NULL) {
        goto CPyL628;
    } else
        goto CPyL357;
CPyL355: ;
    cpy_r_r337 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r337 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL629;
    }
    cpy_r_r338 = cpy_r_r337;
    CPy_DECREF(cpy_r_r338);
    goto CPyL386;
CPyL357: ;
    cpy_r_r339 = cpy_r_r336;
CPyL358: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 16;
    cpy_r_r340 = 1;
    if (unlikely(!cpy_r_r340)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL630;
    } else
        goto CPyL631;
CPyL359: ;
    return cpy_r_r339;
CPyL360: ;
    cpy_r_r341 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r342 = cpy_r_type != cpy_r_r341;
    if (!cpy_r_r342) goto CPyL363;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL364;
    } else
        goto CPyL632;
CPyL362: ;
    CPy_Unreachable();
CPyL363: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL381;
CPyL364: ;
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
        goto CPyL633;
    }
    cpy_r_r345 = (PyObject **)&cpy_r_r17;
    cpy_r_r346 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22;
    if (unlikely(cpy_r_r346 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__22", -1, CPyStatic_globals);
        goto CPyL633;
    }
    CPy_INCREF(cpy_r_r346);
CPyL366: ;
    cpy_r_r347 = CPy_YieldFromErrorHandle(cpy_r_r346, cpy_r_r345);
    CPy_DecRef(cpy_r_r346);
    if (unlikely(cpy_r_r347 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL633;
    }
    if (cpy_r_r347) goto CPyL373;
    if (cpy_r_r17 == NULL) {
        goto CPyL634;
    } else
        goto CPyL371;
CPyL369: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r348 = 0;
    if (unlikely(!cpy_r_r348)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL378;
    } else
        goto CPyL635;
CPyL370: ;
    CPy_Unreachable();
CPyL371: ;
    CPy_INCREF(cpy_r_r17);
    cpy_r_r339 = cpy_r_r17;
    cpy_r_r349 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23;
    if (unlikely(cpy_r_r349.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__23", -1, CPyStatic_globals);
        goto CPyL636;
    }
    CPy_INCREF(cpy_r_r349.f0);
    CPy_INCREF(cpy_r_r349.f1);
    CPy_INCREF(cpy_r_r349.f2);
CPyL372: ;
    CPy_RestoreExcInfo(cpy_r_r349);
    CPy_DecRef(cpy_r_r349.f0);
    CPy_DecRef(cpy_r_r349.f1);
    CPy_DecRef(cpy_r_r349.f2);
    goto CPyL358;
CPyL373: ;
    if (cpy_r_r17 == NULL) {
        goto CPyL637;
    } else
        goto CPyL376;
CPyL374: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r350 = 0;
    if (unlikely(!cpy_r_r350)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL378;
    } else
        goto CPyL638;
CPyL375: ;
    CPy_Unreachable();
CPyL376: ;
    cpy_r_r338 = cpy_r_r17;
    CPy_DecRef(cpy_r_r338);
    cpy_r_r351 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__23;
    if (unlikely(cpy_r_r351.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__23", -1, CPyStatic_globals);
        goto CPyL639;
    }
    CPy_INCREF(cpy_r_r351.f0);
    CPy_INCREF(cpy_r_r351.f1);
    CPy_INCREF(cpy_r_r351.f2);
CPyL377: ;
    CPy_RestoreExcInfo(cpy_r_r351);
    CPy_DecRef(cpy_r_r351.f0);
    CPy_DecRef(cpy_r_r351.f1);
    CPy_DecRef(cpy_r_r351.f2);
    goto CPyL386;
CPyL378: ;
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
        goto CPyL389;
    }
CPyL379: ;
    CPy_RestoreExcInfo(cpy_r_r352);
    CPy_DecRef(cpy_r_r352.f0);
    CPy_DecRef(cpy_r_r352.f1);
    CPy_DecRef(cpy_r_r352.f2);
    cpy_r_r353 = CPy_KeepPropagating();
    if (!cpy_r_r353) {
        goto CPyL389;
    } else
        goto CPyL640;
CPyL380: ;
    CPy_Unreachable();
CPyL381: ;
    cpy_r_r354 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__22;
    if (unlikely(cpy_r_r354 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__22", -1, CPyStatic_globals);
        goto CPyL641;
    }
    CPy_INCREF(cpy_r_r354);
CPyL382: ;
    cpy_r_r355 = CPyIter_Send(cpy_r_r354, cpy_r_arg);
    CPy_DECREF(cpy_r_r354);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r355 == NULL) goto CPyL642;
    cpy_r_r339 = cpy_r_r355;
    goto CPyL358;
CPyL384: ;
    cpy_r_r356 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r356 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 140, CPyStatic_globals);
        goto CPyL629;
    }
    cpy_r_r338 = cpy_r_r356;
    CPy_DECREF(cpy_r_r338);
CPyL386: ;
    if (cpy_r_r19.f0 == NULL) {
        goto CPyL396;
    } else
        goto CPyL643;
CPyL387: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL389;
    } else
        goto CPyL644;
CPyL388: ;
    CPy_Unreachable();
CPyL389: ;
    if (cpy_r_r19.f0 == NULL) goto CPyL394;
    if (cpy_r_r19.f0 != NULL) goto CPyL393;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r357 = 0;
    if (unlikely(!cpy_r_r357)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL482;
    }
    CPy_Unreachable();
CPyL393: ;
    CPy_RestoreExcInfo(cpy_r_r19);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
CPyL394: ;
    cpy_r_r358 = CPy_KeepPropagating();
    if (!cpy_r_r358) goto CPyL482;
    CPy_Unreachable();
CPyL396: ;
    cpy_r_r359 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r359 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 145, CPyStatic_globals);
        goto CPyL645;
    }
    CPy_INCREF(cpy_r_r359);
CPyL397: ;
    cpy_r_r360 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output;
    if (unlikely(cpy_r_r360 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "output", 145, CPyStatic_globals);
        goto CPyL646;
    }
    CPy_INCREF(cpy_r_r360);
CPyL398: ;
    if (likely(PyBytes_Check(cpy_r_r360) || PyByteArray_Check(cpy_r_r360)))
        cpy_r_r361 = cpy_r_r360;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals, "bytes", cpy_r_r360);
        goto CPyL646;
    }
    cpy_r_r362 = CPyDef_decode_output(cpy_r_r359, cpy_r_r361);
    CPy_DECREF(cpy_r_r359);
    CPy_DECREF(cpy_r_r361);
    if (unlikely(cpy_r_r362 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals);
        goto CPyL645;
    }
    cpy_r_r363 = CPy_GetCoro(cpy_r_r362);
    CPy_DECREF(cpy_r_r362);
    if (unlikely(cpy_r_r363 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals);
        goto CPyL645;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24 = cpy_r_r363;
    cpy_r_r364 = 1;
    if (unlikely(!cpy_r_r364)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL645;
    }
    cpy_r_r365 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24;
    if (unlikely(cpy_r_r365 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__24", -1, CPyStatic_globals);
        goto CPyL645;
    }
    CPy_INCREF(cpy_r_r365);
CPyL403: ;
    cpy_r_r366 = CPyIter_Next(cpy_r_r365);
    CPy_DECREF(cpy_r_r365);
    if (cpy_r_r366 == NULL) {
        goto CPyL647;
    } else
        goto CPyL406;
CPyL404: ;
    cpy_r_r367 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r367 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals);
        goto CPyL436;
    }
    cpy_r_r368 = cpy_r_r367;
    goto CPyL435;
CPyL406: ;
    cpy_r_r369 = cpy_r_r366;
CPyL407: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = 18;
    cpy_r_r370 = 1;
    if (unlikely(!cpy_r_r370)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals);
        goto CPyL648;
    } else
        goto CPyL649;
CPyL408: ;
    return cpy_r_r369;
CPyL409: ;
    cpy_r_r371 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r372 = cpy_r_type != cpy_r_r371;
    if (!cpy_r_r372) goto CPyL412;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals);
        goto CPyL413;
    } else
        goto CPyL650;
CPyL411: ;
    CPy_Unreachable();
CPyL412: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL430;
CPyL413: ;
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
        goto CPyL651;
    }
    cpy_r_r375 = (PyObject **)&cpy_r_r21;
    cpy_r_r376 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24;
    if (unlikely(cpy_r_r376 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__24", -1, CPyStatic_globals);
        goto CPyL651;
    }
    CPy_INCREF(cpy_r_r376);
CPyL415: ;
    cpy_r_r377 = CPy_YieldFromErrorHandle(cpy_r_r376, cpy_r_r375);
    CPy_DecRef(cpy_r_r376);
    if (unlikely(cpy_r_r377 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals);
        goto CPyL651;
    }
    if (cpy_r_r377) goto CPyL422;
    if (cpy_r_r21 != NULL) goto CPyL420;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r378 = 0;
    if (unlikely(!cpy_r_r378)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL427;
    } else
        goto CPyL652;
CPyL419: ;
    CPy_Unreachable();
CPyL420: ;
    CPy_INCREF(cpy_r_r21);
    cpy_r_r369 = cpy_r_r21;
    cpy_r_r379 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25;
    if (unlikely(cpy_r_r379.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__25", -1, CPyStatic_globals);
        goto CPyL653;
    }
    CPy_INCREF(cpy_r_r379.f0);
    CPy_INCREF(cpy_r_r379.f1);
    CPy_INCREF(cpy_r_r379.f2);
CPyL421: ;
    CPy_RestoreExcInfo(cpy_r_r379);
    CPy_DecRef(cpy_r_r379.f0);
    CPy_DecRef(cpy_r_r379.f1);
    CPy_DecRef(cpy_r_r379.f2);
    goto CPyL407;
CPyL422: ;
    if (cpy_r_r21 != NULL) goto CPyL425;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r380 = 0;
    if (unlikely(!cpy_r_r380)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL427;
    } else
        goto CPyL654;
CPyL424: ;
    CPy_Unreachable();
CPyL425: ;
    cpy_r_r368 = cpy_r_r21;
    cpy_r_r381 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25;
    if (unlikely(cpy_r_r381.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__25", -1, CPyStatic_globals);
        goto CPyL655;
    }
    CPy_INCREF(cpy_r_r381.f0);
    CPy_INCREF(cpy_r_r381.f1);
    CPy_INCREF(cpy_r_r381.f2);
CPyL426: ;
    CPy_RestoreExcInfo(cpy_r_r381);
    CPy_DecRef(cpy_r_r381.f0);
    CPy_DecRef(cpy_r_r381.f1);
    CPy_DecRef(cpy_r_r381.f2);
    goto CPyL435;
CPyL427: ;
    cpy_r_r382 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__25;
    if (unlikely(cpy_r_r382.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__25", -1, CPyStatic_globals);
        goto CPyL436;
    }
    CPy_INCREF(cpy_r_r382.f0);
    CPy_INCREF(cpy_r_r382.f1);
    CPy_INCREF(cpy_r_r382.f2);
CPyL428: ;
    CPy_RestoreExcInfo(cpy_r_r382);
    CPy_DecRef(cpy_r_r382.f0);
    CPy_DecRef(cpy_r_r382.f1);
    CPy_DecRef(cpy_r_r382.f2);
    cpy_r_r383 = CPy_KeepPropagating();
    if (!cpy_r_r383) {
        goto CPyL436;
    } else
        goto CPyL656;
CPyL429: ;
    CPy_Unreachable();
CPyL430: ;
    cpy_r_r384 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_temp__24;
    if (unlikely(cpy_r_r384 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "__mypyc_temp__24", -1, CPyStatic_globals);
        goto CPyL657;
    }
    CPy_INCREF(cpy_r_r384);
CPyL431: ;
    cpy_r_r385 = CPyIter_Send(cpy_r_r384, cpy_r_arg);
    CPy_DECREF(cpy_r_r384);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r385 == NULL) goto CPyL658;
    cpy_r_r369 = cpy_r_r385;
    goto CPyL407;
CPyL433: ;
    cpy_r_r386 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r386 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals);
        goto CPyL436;
    }
    cpy_r_r368 = cpy_r_r386;
CPyL435: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded = cpy_r_r368;
    cpy_r_r387 = 1;
    if (unlikely(!cpy_r_r387)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 145, CPyStatic_globals);
    } else
        goto CPyL455;
CPyL436: ;
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
        goto CPyL452;
    }
    cpy_r_r390 = CPyStatic_globals;
    cpy_r_r391 = CPyStatics[31]; /* 'InsufficientDataBytes' */
    cpy_r_r392 = CPyDict_GetItem(cpy_r_r390, cpy_r_r391);
    if (unlikely(cpy_r_r392 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 146, CPyStatic_globals);
        goto CPyL452;
    }
    cpy_r_r393 = CPy_ExceptionMatches(cpy_r_r392);
    CPy_DecRef(cpy_r_r392);
    if (!cpy_r_r393) goto CPyL450;
    cpy_r_r394 = CPy_GetExcValue();
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_e != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_e);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_e = cpy_r_r394;
    cpy_r_r395 = 1;
    if (unlikely(!cpy_r_r395)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 146, CPyStatic_globals);
        goto CPyL452;
    }
    cpy_r_r396 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_e;
    if (unlikely(cpy_r_r396 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "e", 147, CPyStatic_globals);
        goto CPyL452;
    }
    CPy_INCREF(cpy_r_r396);
CPyL441: ;
    cpy_r_r397 = PyObject_Str(cpy_r_r396);
    CPy_DecRef(cpy_r_r396);
    if (unlikely(cpy_r_r397 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 147, CPyStatic_globals);
        goto CPyL452;
    }
    cpy_r_r398 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r398 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 147, CPyStatic_globals);
        goto CPyL659;
    }
    CPy_INCREF(cpy_r_r398);
CPyL443: ;
    cpy_r_r399 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_self;
    if (unlikely(cpy_r_r399 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "self", 147, CPyStatic_globals);
        goto CPyL660;
    }
    CPy_INCREF(cpy_r_r399);
CPyL444: ;
    cpy_r_r400 = CPyStatics[11]; /* '_address' */
    cpy_r_r401 = CPyObject_GetAttr(cpy_r_r399, cpy_r_r400);
    CPy_DecRef(cpy_r_r399);
    if (unlikely(cpy_r_r401 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 147, CPyStatic_globals);
        goto CPyL660;
    }
    cpy_r_r402 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_output;
    if (unlikely(cpy_r_r402 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "output", 147, CPyStatic_globals);
        goto CPyL661;
    }
    CPy_INCREF(cpy_r_r402);
CPyL446: ;
    cpy_r_r403 = CPyStatic_globals;
    cpy_r_r404 = CPyStatics[31]; /* 'InsufficientDataBytes' */
    cpy_r_r405 = CPyDict_GetItem(cpy_r_r403, cpy_r_r404);
    if (unlikely(cpy_r_r405 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 147, CPyStatic_globals);
        goto CPyL662;
    }
    PyObject *cpy_r_r406[4] = {cpy_r_r397, cpy_r_r398, cpy_r_r401, cpy_r_r402};
    cpy_r_r407 = (PyObject **)&cpy_r_r406;
    cpy_r_r408 = _PyObject_Vectorcall(cpy_r_r405, cpy_r_r407, 4, 0);
    CPy_DecRef(cpy_r_r405);
    if (unlikely(cpy_r_r408 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 147, CPyStatic_globals);
        goto CPyL662;
    }
    CPy_DecRef(cpy_r_r397);
    CPy_DecRef(cpy_r_r398);
    CPy_DecRef(cpy_r_r401);
    CPy_DecRef(cpy_r_r402);
    CPy_Raise(cpy_r_r408);
    CPy_DecRef(cpy_r_r408);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 147, CPyStatic_globals);
        goto CPyL452;
    } else
        goto CPyL663;
CPyL449: ;
    CPy_Unreachable();
CPyL450: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL452;
    } else
        goto CPyL664;
CPyL451: ;
    CPy_Unreachable();
CPyL452: ;
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
        goto CPyL482;
    }
CPyL453: ;
    CPy_RestoreExcInfo(cpy_r_r409);
    CPy_DecRef(cpy_r_r409.f0);
    CPy_DecRef(cpy_r_r409.f1);
    CPy_DecRef(cpy_r_r409.f2);
    cpy_r_r410 = CPy_KeepPropagating();
    if (!cpy_r_r410) goto CPyL482;
    CPy_Unreachable();
CPyL455: ;
    cpy_r_r411 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decimals;
    if (unlikely(cpy_r_r411 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "decimals", 149, CPyStatic_globals);
        goto CPyL665;
    }
    CPy_INCREF(cpy_r_r411);
CPyL456: ;
    cpy_r_r412 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r413 = cpy_r_r411 == cpy_r_r412;
    CPy_DECREF(cpy_r_r411);
    if (!cpy_r_r413) goto CPyL459;
    cpy_r_r414 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded;
    if (unlikely(cpy_r_r414 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "decoded", 149, CPyStatic_globals);
        goto CPyL665;
    }
    CPy_INCREF(cpy_r_r414);
CPyL458: ;
    cpy_r_r415 = cpy_r_r414;
    goto CPyL467;
CPyL459: ;
    cpy_r_r416 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decoded;
    if (unlikely(cpy_r_r416 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "decoded", 149, CPyStatic_globals);
        goto CPyL665;
    }
    CPy_INCREF(cpy_r_r416);
CPyL460: ;
    cpy_r_r417 = ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->_decimals;
    if (unlikely(cpy_r_r417 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_env", "decimals", 149, CPyStatic_globals);
        goto CPyL666;
    }
    CPy_INCREF(cpy_r_r417);
CPyL461: ;
    if (likely(PyLong_Check(cpy_r_r417)))
        cpy_r_r418 = CPyTagged_FromObject(cpy_r_r417);
    else {
        CPy_TypeError("int", cpy_r_r417); cpy_r_r418 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r417);
    if (unlikely(cpy_r_r418 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 149, CPyStatic_globals);
        goto CPyL666;
    }
    cpy_r_r419 = CPyStatic_globals;
    cpy_r_r420 = CPyStatics[32]; /* 'Decimal' */
    cpy_r_r421 = CPyDict_GetItem(cpy_r_r419, cpy_r_r420);
    if (unlikely(cpy_r_r421 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 149, CPyStatic_globals);
        goto CPyL667;
    }
    cpy_r_r422 = CPyTagged_StealAsObject(cpy_r_r418);
    PyObject *cpy_r_r423[1] = {cpy_r_r422};
    cpy_r_r424 = (PyObject **)&cpy_r_r423;
    cpy_r_r425 = _PyObject_Vectorcall(cpy_r_r421, cpy_r_r424, 1, 0);
    CPy_DECREF(cpy_r_r421);
    if (unlikely(cpy_r_r425 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 149, CPyStatic_globals);
        goto CPyL668;
    }
    CPy_DECREF(cpy_r_r422);
    cpy_r_r426 = CPyStatics[189]; /* 10 */
    cpy_r_r427 = CPyNumber_Power(cpy_r_r426, cpy_r_r425);
    CPy_DECREF(cpy_r_r425);
    if (unlikely(cpy_r_r427 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 149, CPyStatic_globals);
        goto CPyL666;
    }
    cpy_r_r428 = PyNumber_TrueDivide(cpy_r_r416, cpy_r_r427);
    CPy_DECREF(cpy_r_r416);
    CPy_DECREF(cpy_r_r427);
    if (unlikely(cpy_r_r428 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 149, CPyStatic_globals);
        goto CPyL665;
    }
    cpy_r_r415 = cpy_r_r428;
CPyL467: ;
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r22)->___mypyc_next_label__ = -2;
    cpy_r_r429 = 1;
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!cpy_r_r429)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 149, CPyStatic_globals);
        goto CPyL669;
    }
    CPyGen_SetStopIterationValue(cpy_r_r415);
    CPy_DECREF(cpy_r_r415);
    if (!0) goto CPyL482;
    CPy_Unreachable();
CPyL470: ;
    cpy_r_r430 = cpy_r_r23 == 0;
    if (cpy_r_r430) goto CPyL670;
    cpy_r_r431 = cpy_r_r23 == 2;
    if (cpy_r_r431) {
        goto CPyL671;
    } else
        goto CPyL672;
CPyL472: ;
    cpy_r_r432 = cpy_r_r23 == 4;
    if (cpy_r_r432) {
        goto CPyL673;
    } else
        goto CPyL674;
CPyL473: ;
    cpy_r_r433 = cpy_r_r23 == 6;
    if (cpy_r_r433) {
        goto CPyL675;
    } else
        goto CPyL676;
CPyL474: ;
    cpy_r_r434 = cpy_r_r23 == 8;
    if (cpy_r_r434) {
        goto CPyL677;
    } else
        goto CPyL678;
CPyL475: ;
    cpy_r_r435 = cpy_r_r23 == 10;
    if (cpy_r_r435) {
        goto CPyL679;
    } else
        goto CPyL680;
CPyL476: ;
    cpy_r_r436 = cpy_r_r23 == 12;
    if (cpy_r_r436) {
        goto CPyL681;
    } else
        goto CPyL682;
CPyL477: ;
    cpy_r_r437 = cpy_r_r23 == 14;
    if (cpy_r_r437) {
        goto CPyL683;
    } else
        goto CPyL684;
CPyL478: ;
    cpy_r_r438 = cpy_r_r23 == 16;
    if (cpy_r_r438) {
        goto CPyL685;
    } else
        goto CPyL686;
CPyL479: ;
    cpy_r_r439 = cpy_r_r23 == 18;
    CPyTagged_DECREF(cpy_r_r23);
    if (cpy_r_r439) {
        goto CPyL409;
    } else
        goto CPyL687;
CPyL480: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r440 = 0;
    if (unlikely(!cpy_r_r440)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL482;
    }
    CPy_Unreachable();
CPyL482: ;
    cpy_r_r441 = NULL;
    return cpy_r_r441;
CPyL483: ;
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
    goto CPyL482;
CPyL484: ;
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
    goto CPyL482;
CPyL485: ;
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
    goto CPyL482;
CPyL486: ;
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
CPyL487: ;
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
    goto CPyL482;
CPyL488: ;
    CPy_DECREF(cpy_r_r27);
    goto CPyL14;
CPyL489: ;
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
CPyL490: ;
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
    CPy_DecRef(cpy_r_r45);
    goto CPyL482;
CPyL491: ;
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
    CPy_DecRef(cpy_r_r47);
    CPy_DecRef(cpy_r_r48);
    goto CPyL482;
CPyL492: ;
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
    CPy_DecRef(cpy_r_r47);
    goto CPyL482;
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
    CPy_DecRef(cpy_r_r56);
    goto CPyL482;
CPyL494: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL28;
CPyL495: ;
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
    goto CPyL482;
CPyL496: ;
    CPy_DecRef(cpy_r_r65);
    goto CPyL37;
CPyL497: ;
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
    goto CPyL32;
CPyL498: ;
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
    goto CPyL35;
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
    CPy_DecRef(cpy_r_r24);
    goto CPyL51;
CPyL500: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL42;
CPyL501: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL43;
CPyL502: ;
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
    CPy_DecRef(cpy_r_r65);
    goto CPyL51;
CPyL503: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL47;
CPyL504: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL48;
CPyL505: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL51;
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
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_arg);
    goto CPyL482;
CPyL507: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL57;
CPyL508: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL295;
CPyL509: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r83);
    goto CPyL295;
CPyL510: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r83);
    CPyTagged_DecRef(cpy_r_r84);
    goto CPyL295;
CPyL511: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r83);
    CPyTagged_DecRef(cpy_r_r84);
    CPy_DecRef(cpy_r_r85);
    goto CPyL295;
CPyL512: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r83);
    CPyTagged_DecRef(cpy_r_r84);
    CPy_DecRef(cpy_r_r85);
    CPy_DecRef(cpy_r_r86);
    goto CPyL295;
CPyL513: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r83);
    CPyTagged_DecRef(cpy_r_r84);
    CPy_DecRef(cpy_r_r85);
    CPy_DecRef(cpy_r_r86);
    CPy_DecRef(cpy_r_r89);
    goto CPyL295;
CPyL514: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r89);
    CPy_DecRef(cpy_r_r90);
    goto CPyL295;
CPyL515: ;
    CPy_DECREF(cpy_r_r96);
    goto CPyL66;
CPyL516: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r89);
    goto CPyL295;
CPyL517: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r89);
    CPy_DecRef(cpy_r_r97);
    goto CPyL295;
CPyL518: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL73;
CPyL519: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL295;
CPyL520: ;
    CPy_DecRef(cpy_r_r106);
    goto CPyL82;
CPyL521: ;
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
    goto CPyL77;
CPyL522: ;
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
    goto CPyL80;
CPyL523: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL96;
CPyL524: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL87;
CPyL525: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL88;
CPyL526: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r106);
    goto CPyL96;
CPyL527: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL92;
CPyL528: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL93;
CPyL529: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r105);
    goto CPyL96;
CPyL530: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL98;
CPyL531: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_arg);
    goto CPyL295;
CPyL532: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL102;
CPyL533: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r129);
    goto CPyL295;
CPyL534: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r131);
    CPy_DecRef(cpy_r_r132);
    goto CPyL295;
CPyL535: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r131);
    goto CPyL295;
CPyL536: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r140);
    goto CPyL295;
CPyL537: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL119;
CPyL538: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL295;
CPyL539: ;
    CPy_DecRef(cpy_r_r149);
    goto CPyL128;
CPyL540: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL123;
CPyL541: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    goto CPyL126;
CPyL542: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL142;
CPyL543: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL133;
CPyL544: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL134;
CPyL545: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r149);
    goto CPyL142;
CPyL546: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL138;
CPyL547: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL139;
CPyL548: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    goto CPyL142;
CPyL549: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL144;
CPyL550: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_arg);
    goto CPyL295;
CPyL551: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL148;
CPyL552: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL194;
CPyL553: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r169);
    goto CPyL194;
CPyL554: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r169);
    CPy_DecRef(cpy_r_r173);
    goto CPyL194;
CPyL555: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r169);
    CPy_DecRef(cpy_r_r176);
    goto CPyL194;
CPyL556: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL162;
CPyL557: ;
    CPy_DecRef(cpy_r_r186);
    goto CPyL171;
CPyL558: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL166;
CPyL559: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL169;
CPyL560: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL185;
CPyL561: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL177;
CPyL562: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r186);
    goto CPyL185;
CPyL563: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL182;
CPyL564: ;
    CPy_DecRef(cpy_r_r185);
    goto CPyL185;
CPyL565: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL187;
CPyL566: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_arg);
    goto CPyL194;
CPyL567: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL191;
CPyL568: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL243;
CPyL569: ;
    CPy_XDecRef(cpy_r_r9);
    goto CPyL240;
CPyL570: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    goto CPyL240;
CPyL571: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    CPy_DecRef(cpy_r_r212);
    goto CPyL240;
CPyL572: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    CPy_DecRef(cpy_r_r213);
    goto CPyL240;
CPyL573: ;
    CPy_XDecRef(cpy_r_r9);
    goto CPyL203;
CPyL574: ;
    CPy_DecRef(cpy_r_r223);
    goto CPyL212;
CPyL575: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL207;
CPyL576: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL210;
CPyL577: ;
    CPy_XDecRef(cpy_r_r9);
    goto CPyL226;
CPyL578: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL218;
CPyL579: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r223);
    goto CPyL226;
CPyL580: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL223;
CPyL581: ;
    CPy_DecRef(cpy_r_r222);
    goto CPyL226;
CPyL582: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL228;
CPyL583: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_arg);
    goto CPyL240;
CPyL584: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL232;
CPyL585: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL237;
CPyL586: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL242;
CPyL587: ;
    CPy_XDecRef(cpy_r_r11);
    goto CPyL288;
CPyL588: ;
    CPy_XDECREF(cpy_r_r11);
    goto CPyL285;
CPyL589: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r251);
    goto CPyL288;
CPyL590: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r252);
    goto CPyL288;
CPyL591: ;
    CPy_XDECREF(cpy_r_r11);
    goto CPyL254;
CPyL592: ;
    CPy_DecRef(cpy_r_r262);
    goto CPyL263;
CPyL593: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL258;
CPyL594: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL261;
CPyL595: ;
    CPy_XDecRef(cpy_r_r11);
    goto CPyL277;
CPyL596: ;
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL269;
CPyL597: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r262);
    goto CPyL277;
CPyL598: ;
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL274;
CPyL599: ;
    CPy_XDecRef(cpy_r_r13.f0);
    CPy_XDecRef(cpy_r_r13.f1);
    CPy_XDecRef(cpy_r_r13.f2);
    CPy_XDecRef(cpy_r_r15);
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL279;
CPyL600: ;
    CPy_XDecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_arg);
    goto CPyL288;
CPyL601: ;
    CPy_XDECREF(cpy_r_r11);
    goto CPyL283;
CPyL602: ;
    CPy_XDECREF(cpy_r_r15);
    goto CPyL344;
CPyL603: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL287;
CPyL604: ;
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL291;
CPyL605: ;
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL294;
CPyL606: ;
    CPy_XDecRef(cpy_r_r15);
    goto CPyL341;
CPyL607: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r287);
    CPy_DecRef(cpy_r_r288);
    goto CPyL341;
CPyL608: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r287);
    CPy_DecRef(cpy_r_r288);
    CPy_DecRef(cpy_r_r289);
    goto CPyL341;
CPyL609: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r287);
    CPy_DecRef(cpy_r_r288);
    CPy_DecRef(cpy_r_r290);
    goto CPyL341;
CPyL610: ;
    CPy_XDECREF(cpy_r_r15);
    goto CPyL304;
CPyL611: ;
    CPy_DecRef(cpy_r_r300);
    goto CPyL313;
CPyL612: ;
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL308;
CPyL613: ;
    CPy_XDECREF(cpy_r_r15);
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL311;
CPyL614: ;
    CPy_XDecRef(cpy_r_r15);
    goto CPyL327;
CPyL615: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL319;
CPyL616: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r300);
    goto CPyL327;
CPyL617: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL324;
CPyL618: ;
    CPy_DecRef(cpy_r_r299);
    goto CPyL327;
CPyL619: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL329;
CPyL620: ;
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_arg);
    goto CPyL341;
CPyL621: ;
    CPy_XDECREF(cpy_r_r15);
    goto CPyL333;
CPyL622: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL338;
CPyL623: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL343;
CPyL624: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL389;
CPyL625: ;
    CPy_XDECREF(cpy_r_r17);
    goto CPyL386;
CPyL626: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r328);
    goto CPyL389;
CPyL627: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r329);
    goto CPyL389;
CPyL628: ;
    CPy_XDECREF(cpy_r_r17);
    goto CPyL355;
CPyL629: ;
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    goto CPyL389;
CPyL630: ;
    CPy_DecRef(cpy_r_r339);
    goto CPyL364;
CPyL631: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL359;
CPyL632: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL362;
CPyL633: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    goto CPyL378;
CPyL634: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL369;
CPyL635: ;
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    CPy_DecRef(cpy_r_r22);
    goto CPyL370;
CPyL636: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r339);
    goto CPyL378;
CPyL637: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL374;
CPyL638: ;
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    CPy_DecRef(cpy_r_r22);
    goto CPyL375;
CPyL639: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL378;
CPyL640: ;
    CPy_XDecRef(cpy_r_r19.f0);
    CPy_XDecRef(cpy_r_r19.f1);
    CPy_XDecRef(cpy_r_r19.f2);
    goto CPyL380;
CPyL641: ;
    CPy_XDecRef(cpy_r_r17);
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_arg);
    goto CPyL389;
CPyL642: ;
    CPy_XDECREF(cpy_r_r17);
    goto CPyL384;
CPyL643: ;
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL387;
CPyL644: ;
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    goto CPyL388;
CPyL645: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL436;
CPyL646: ;
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r359);
    goto CPyL436;
CPyL647: ;
    CPy_XDECREF(cpy_r_r21);
    goto CPyL404;
CPyL648: ;
    CPy_DecRef(cpy_r_r369);
    goto CPyL413;
CPyL649: ;
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL408;
CPyL650: ;
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL411;
CPyL651: ;
    CPy_XDecRef(cpy_r_r21);
    goto CPyL427;
CPyL652: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL419;
CPyL653: ;
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r369);
    goto CPyL427;
CPyL654: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL424;
CPyL655: ;
    CPy_DecRef(cpy_r_r368);
    goto CPyL427;
CPyL656: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL429;
CPyL657: ;
    CPy_XDecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_arg);
    goto CPyL436;
CPyL658: ;
    CPy_XDECREF(cpy_r_r21);
    goto CPyL433;
CPyL659: ;
    CPy_DecRef(cpy_r_r397);
    goto CPyL452;
CPyL660: ;
    CPy_DecRef(cpy_r_r397);
    CPy_DecRef(cpy_r_r398);
    goto CPyL452;
CPyL661: ;
    CPy_DecRef(cpy_r_r397);
    CPy_DecRef(cpy_r_r398);
    CPy_DecRef(cpy_r_r401);
    goto CPyL452;
CPyL662: ;
    CPy_DecRef(cpy_r_r397);
    CPy_DecRef(cpy_r_r398);
    CPy_DecRef(cpy_r_r401);
    CPy_DecRef(cpy_r_r402);
    goto CPyL452;
CPyL663: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL449;
CPyL664: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL451;
CPyL665: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL482;
CPyL666: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r416);
    goto CPyL482;
CPyL667: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r416);
    CPyTagged_DecRef(cpy_r_r418);
    goto CPyL482;
CPyL668: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r416);
    CPy_DecRef(cpy_r_r422);
    goto CPyL482;
CPyL669: ;
    CPy_DecRef(cpy_r_r415);
    goto CPyL482;
CPyL670: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL3;
CPyL671: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL33;
CPyL672: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL472;
CPyL673: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL78;
CPyL674: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL473;
CPyL675: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL124;
CPyL676: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r24);
    goto CPyL474;
CPyL677: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL167;
CPyL678: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL475;
CPyL679: ;
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL208;
CPyL680: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL476;
CPyL681: ;
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL259;
CPyL682: ;
    CPy_XDECREF(cpy_r_r11);
    CPy_XDECREF(cpy_r_r13.f0);
    CPy_XDECREF(cpy_r_r13.f1);
    CPy_XDECREF(cpy_r_r13.f2);
    goto CPyL477;
CPyL683: ;
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL309;
CPyL684: ;
    CPy_XDECREF(cpy_r_r15);
    goto CPyL478;
CPyL685: ;
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL360;
CPyL686: ;
    CPy_XDECREF(cpy_r_r17);
    CPy_XDECREF(cpy_r_r19.f0);
    CPy_XDECREF(cpy_r_r19.f1);
    CPy_XDECREF(cpy_r_r19.f2);
    goto CPyL479;
CPyL687: ;
    CPy_XDECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    goto CPyL480;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
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
    cpy_r_r1 = CPyStatics[33]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_coroutine__get_coroutine_fn_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[34]; /* 'StopIteration' */
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
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "coroutine", "coroutine__get_coroutine_fn_obj", "__mypyc_env__", 131, CPyStatic_globals);
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
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL22;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_INCREF(cpy_r_self);
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_self != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_self);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_self = cpy_r_self;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_INCREF(cpy_r_args);
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_args != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_args);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_args = cpy_r_args;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL23;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_block_identifier != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_block_identifier);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_block_identifier = cpy_r_block_identifier;
    cpy_r_r8 = 1;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL24;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_decimals != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_decimals);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_decimals = cpy_r_decimals;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL25;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_override != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_override);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->_override = cpy_r_override;
    cpy_r_r10 = 1;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r11 = CPyDef_coroutine__get_coroutine_fn_gen();
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_INCREF(cpy_r_r4);
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *)cpy_r_r11)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *)cpy_r_r11)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject *)cpy_r_r11)->___mypyc_env__ = cpy_r_r4;
    cpy_r_r12 = 1;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
        goto CPyL27;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject *)cpy_r_r4)->___mypyc_next_label__ = 0;
    cpy_r_r13 = 1;
    CPy_DECREF(cpy_r_r4);
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "coroutine", 131, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__get_coroutine_fn(PyObject *cpy_r_w3, CPyTagged cpy_r_len_inputs) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    CPyTagged cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_coroutine;
    PyObject *cpy_r_r24;
    cpy_r_r0 = CPyDef__get_coroutine_fn_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 125, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_INCREF(cpy_r_w3);
    if (((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_w3 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_w3);
    }
    ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_w3 = cpy_r_w3;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 125, CPyStatic_globals);
        goto CPyL20;
    }
    CPyTagged_INCREF(cpy_r_len_inputs);
    if (((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_len_inputs != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_len_inputs);
    }
    ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_len_inputs = cpy_r_len_inputs;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 125, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r3 = CPyStatic_globals;
    cpy_r_r4 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 126, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r6 = CPyStatics[35]; /* 'OPERATION_MODE' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 126, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r8 = CPyStatics[36]; /* 'application' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 126, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r10 = PyObject_IsTrue(cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 126, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r12 = cpy_r_r10;
    if (cpy_r_r12) goto CPyL10;
    cpy_r_r13 = ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_len_inputs;
    if (unlikely(cpy_r_r13 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", "_get_coroutine_fn_env", "len_inputs", 126, CPyStatic_globals);
        goto CPyL20;
    }
    CPyTagged_INCREF(cpy_r_r13);
CPyL9: ;
    cpy_r_r14 = cpy_r_r13 != 0;
    CPyTagged_DECREF(cpy_r_r13);
    if (!cpy_r_r14) goto CPyL14;
CPyL10: ;
    cpy_r_r15 = CPyStatic_encode;
    if (unlikely(cpy_r_r15 == NULL)) {
        goto CPyL21;
    } else
        goto CPyL13;
CPyL11: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"encode\" was not set");
    cpy_r_r16 = 0;
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 127, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_Unreachable();
CPyL13: ;
    CPy_INCREF(cpy_r_r15);
    if (((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data);
    }
    ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data = cpy_r_r15;
    cpy_r_r17 = 1;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 127, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL16;
CPyL14: ;
    cpy_r_r18 = CPyStatic_globals;
    cpy_r_r19 = CPyStatics[37]; /* '_request_data_no_args' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 129, CPyStatic_globals);
        goto CPyL20;
    }
    if (((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data);
    }
    ((dank_mids___brownie_patch___call____get_coroutine_fn_envObject *)cpy_r_r0)->_get_request_data = cpy_r_r20;
    cpy_r_r21 = 1;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 129, CPyStatic_globals);
        goto CPyL20;
    }
CPyL16: ;
    cpy_r_r22 = CPyDef_coroutine__get_coroutine_fn_obj();
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 131, CPyStatic_globals);
        goto CPyL20;
    }
    if (((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *)cpy_r_r22)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *)cpy_r_r22)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject *)cpy_r_r22)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r23 = 1;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 131, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_coroutine = cpy_r_r22;
    return cpy_r_coroutine;
CPyL19: ;
    cpy_r_r24 = NULL;
    return cpy_r_r24;
CPyL20: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL19;
CPyL21: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL11;
CPyL22: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL19;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_get_coroutine_fn", 125, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__call_no_args(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[17]; /* 'coroutine' */
    cpy_r_r1 = CPyObject_CallMethodObjArgs(cpy_r_self, cpy_r_r0, NULL);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_call_no_args", 156, CPyStatic_globals);
        goto CPyL3;
    }
    cpy_r_r2 = CPyStatics[19]; /* '__await__' */
    cpy_r_r3 = CPyObject_CallMethodObjArgs(cpy_r_r1, cpy_r_r2, NULL);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_call_no_args", 156, CPyStatic_globals);
        goto CPyL3;
    }
    return cpy_r_r3;
CPyL3: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_call_no_args", 154, CPyStatic_globals);
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
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    int32_t cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    CPyTagged cpy_r_r30;
    CPyTagged cpy_r_r31;
    char cpy_r_r32;
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
    CPyPtr cpy_r_r44;
    CPyPtr cpy_r_r45;
    CPyPtr cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    CPyPtr cpy_r_r56;
    CPyPtr cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    char cpy_r_r69;
    PyObject *cpy_r_r70;
    char cpy_r_r71;
    tuple_T3OOO cpy_r_r72;
    char cpy_r_r73;
    PyObject **cpy_r_r74;
    PyObject *cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    tuple_T3OOO cpy_r_r78;
    char cpy_r_r79;
    tuple_T3OOO cpy_r_r80;
    tuple_T3OOO cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    char cpy_r_r86;
    tuple_T3OOO cpy_r_r87;
    char cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    tuple_T2OO cpy_r_r95;
    PyObject *cpy_r_r96;
    char cpy_r_r97;
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
    CPyPtr cpy_r_r109;
    CPyPtr cpy_r_r110;
    CPyPtr cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    char cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    char cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
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
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject **cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    int32_t cpy_r_r153;
    char cpy_r_r154;
    CPyTagged cpy_r_r155;
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
    CPyPtr cpy_r_r168;
    CPyPtr cpy_r_r169;
    CPyPtr cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    char cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    char cpy_r_r183;
    CPyTagged cpy_r_r184;
    char cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    CPyPtr cpy_r_r197;
    CPyPtr cpy_r_r198;
    CPyPtr cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    char cpy_r_r208;
    tuple_T3OOO cpy_r_r209;
    tuple_T3OOO cpy_r_r210;
    char cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    int32_t cpy_r_r216;
    char cpy_r_r217;
    char cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    char cpy_r_r221;
    char cpy_r_r222;
    char cpy_r_r223;
    char cpy_r_r224;
    PyObject *cpy_r_r225;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((dank_mids___brownie_patch___call___encode_input_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_gen", "__mypyc_env__", 159, CPyStatic_globals);
        goto CPyL175;
    }
    CPy_INCREF(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_next_label__", 159, CPyStatic_globals);
        goto CPyL176;
    }
    CPyTagged_INCREF(cpy_r_r3);
    goto CPyL170;
CPyL2: ;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_type != cpy_r_r4;
    if (cpy_r_r5) {
        goto CPyL177;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL174;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r6 = 0;
    cpy_r_r7 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 161, CPyStatic_globals);
        goto CPyL176;
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
        goto CPyL176;
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28 = 0;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL176;
    }
CPyL8: ;
    cpy_r_r10 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__27;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__27", 161, CPyStatic_globals);
        goto CPyL176;
    }
    CPy_INCREF(cpy_r_r10);
CPyL9: ;
    cpy_r_r11 = (CPyPtr)&((PyVarObject *)cpy_r_r10)->ob_size;
    cpy_r_r12 = *(int64_t *)cpy_r_r11;
    CPy_DECREF(cpy_r_r10);
    cpy_r_r13 = cpy_r_r12 << 1;
    cpy_r_r14 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28;
    if (unlikely(cpy_r_r14 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__28", 161, CPyStatic_globals);
        goto CPyL176;
    }
CPyL10: ;
    cpy_r_r15 = (Py_ssize_t)cpy_r_r14 < (Py_ssize_t)cpy_r_r13;
    if (!cpy_r_r15) goto CPyL25;
    cpy_r_r16 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__27;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__27", 161, CPyStatic_globals);
        goto CPyL176;
    }
    CPy_INCREF(cpy_r_r16);
CPyL12: ;
    cpy_r_r17 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28;
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__28", 161, CPyStatic_globals);
        goto CPyL178;
    }
CPyL13: ;
    cpy_r_r18 = CPySequenceTuple_GetItem(cpy_r_r16, cpy_r_r17);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 161, CPyStatic_globals);
        goto CPyL176;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg = cpy_r_r18;
    cpy_r_r19 = 1;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 161, CPyStatic_globals);
        goto CPyL176;
    }
    cpy_r_r20 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg;
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "arg", 161, CPyStatic_globals);
        goto CPyL176;
    }
    CPy_INCREF(cpy_r_r20);
CPyL16: ;
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyStatics[38]; /* 'Contract' */
    cpy_r_r23 = CPyDict_GetItem(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 161, CPyStatic_globals);
        goto CPyL179;
    }
    cpy_r_r24 = PyObject_IsInstance(cpy_r_r20, cpy_r_r23);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r25 = cpy_r_r24 >= 0;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 161, CPyStatic_globals);
        goto CPyL176;
    }
    cpy_r_r26 = cpy_r_r24;
    if (!cpy_r_r26) goto CPyL20;
    if (cpy_r_r26) {
        goto CPyL22;
    } else
        goto CPyL23;
CPyL20: ;
    cpy_r_r27 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_arg;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "arg", 161, CPyStatic_globals);
        goto CPyL176;
    }
    CPy_INCREF(cpy_r_r27);
CPyL21: ;
    cpy_r_r28 = CPyStatics[39]; /* '__contains__' */
    cpy_r_r29 = PyObject_HasAttr(cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r27);
    if (!cpy_r_r29) goto CPyL23;
CPyL22: ;
    cpy_r_r6 = 1;
    goto CPyL25;
CPyL23: ;
    cpy_r_r30 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28;
    if (unlikely(cpy_r_r30 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__28", 161, CPyStatic_globals);
        goto CPyL176;
    }
CPyL24: ;
    cpy_r_r31 = cpy_r_r30 + 2;
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__28 = cpy_r_r31;
    cpy_r_r32 = 1;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 161, CPyStatic_globals);
        goto CPyL176;
    } else
        goto CPyL8;
CPyL25: ;
    if (cpy_r_r6) {
        goto CPyL180;
    } else
        goto CPyL38;
CPyL26: ;
    cpy_r_r33 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 163, CPyStatic_globals);
        goto CPyL181;
    }
    CPy_INCREF(cpy_r_r33);
CPyL27: ;
    cpy_r_r34 = CPyStatics[6]; /* 'abi' */
    cpy_r_r35 = CPyObject_GetAttr(cpy_r_r33, cpy_r_r34);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL181;
    }
    cpy_r_r36 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 163, CPyStatic_globals);
        goto CPyL182;
    }
    CPy_INCREF(cpy_r_r36);
CPyL29: ;
    cpy_r_r37 = CPyStatics[7]; /* 'signature' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL182;
    }
    cpy_r_r39 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 163, CPyStatic_globals);
        goto CPyL183;
    }
    CPy_INCREF(cpy_r_r39);
CPyL31: ;
    cpy_r_r40 = CPyStatic_globals;
    cpy_r_r41 = CPyStatics[5]; /* '__encode_input' */
    cpy_r_r42 = CPyDict_GetItem(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r43 = PyList_New(2);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r44 = (CPyPtr)&((PyListObject *)cpy_r_r43)->ob_item;
    cpy_r_r45 = *(CPyPtr *)cpy_r_r44;
    *(PyObject * *)cpy_r_r45 = cpy_r_r35;
    cpy_r_r46 = cpy_r_r45 + 8;
    *(PyObject * *)cpy_r_r46 = cpy_r_r38;
    cpy_r_r47 = CPyList_Extend(cpy_r_r43, cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL186;
    } else
        goto CPyL187;
CPyL34: ;
    cpy_r_r48 = PyList_AsTuple(cpy_r_r43);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r49 = PyDict_New();
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r50 = PyObject_Call(cpy_r_r42, cpy_r_r48, cpy_r_r49);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL181;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r50;
    cpy_r_r51 = 1;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 163, CPyStatic_globals);
        goto CPyL181;
    } else
        goto CPyL159;
CPyL38: ;
    cpy_r_r52 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 166, CPyStatic_globals);
        goto CPyL190;
    }
    CPy_INCREF(cpy_r_r52);
CPyL39: ;
    cpy_r_r53 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 166, CPyStatic_globals);
        goto CPyL191;
    }
    CPy_INCREF(cpy_r_r53);
CPyL40: ;
    cpy_r_r54 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_get_request_data;
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "get_request_data", 166, CPyStatic_globals);
        goto CPyL192;
    }
    CPy_INCREF(cpy_r_r54);
CPyL41: ;
    cpy_r_r55 = PyList_New(1);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r56 = (CPyPtr)&((PyListObject *)cpy_r_r55)->ob_item;
    cpy_r_r57 = *(CPyPtr *)cpy_r_r56;
    *(PyObject * *)cpy_r_r57 = cpy_r_r52;
    cpy_r_r58 = CPyList_Extend(cpy_r_r55, cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL194;
    } else
        goto CPyL195;
CPyL43: ;
    cpy_r_r59 = PyList_AsTuple(cpy_r_r55);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r60 = PyDict_New();
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r61 = PyObject_Call(cpy_r_r54, cpy_r_r59, cpy_r_r60);
    CPy_DECREF(cpy_r_r54);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL190;
    }
    cpy_r_r62 = CPy_GetCoro(cpy_r_r61);
    CPy_DECREF(cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL190;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29 = cpy_r_r62;
    cpy_r_r63 = 1;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL190;
    }
    cpy_r_r64 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__29", -1, CPyStatic_globals);
        goto CPyL190;
    }
    CPy_INCREF(cpy_r_r64);
CPyL49: ;
    cpy_r_r65 = CPyIter_Next(cpy_r_r64);
    CPy_DECREF(cpy_r_r64);
    if (cpy_r_r65 == NULL) {
        goto CPyL198;
    } else
        goto CPyL52;
CPyL50: ;
    cpy_r_r66 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r67 = cpy_r_r66;
    goto CPyL81;
CPyL52: ;
    cpy_r_r68 = cpy_r_r65;
CPyL53: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__ = 2;
    cpy_r_r69 = 1;
    if (unlikely(!cpy_r_r69)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL199;
    } else
        goto CPyL200;
CPyL54: ;
    return cpy_r_r68;
CPyL55: ;
    cpy_r_r70 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r71 = cpy_r_type != cpy_r_r70;
    if (!cpy_r_r71) goto CPyL58;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL59;
    } else
        goto CPyL201;
CPyL57: ;
    CPy_Unreachable();
CPyL58: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL76;
CPyL59: ;
    cpy_r_r72 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30.f2);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30 = cpy_r_r72;
    cpy_r_r73 = 1;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL202;
    }
    cpy_r_r74 = (PyObject **)&cpy_r_r1;
    cpy_r_r75 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__29", -1, CPyStatic_globals);
        goto CPyL202;
    }
    CPy_INCREF(cpy_r_r75);
CPyL61: ;
    cpy_r_r76 = CPy_YieldFromErrorHandle(cpy_r_r75, cpy_r_r74);
    CPy_DecRef(cpy_r_r75);
    if (unlikely(cpy_r_r76 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL202;
    }
    if (cpy_r_r76) goto CPyL68;
    if (cpy_r_r1 != NULL) goto CPyL66;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r77 = 0;
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL73;
    } else
        goto CPyL203;
CPyL65: ;
    CPy_Unreachable();
CPyL66: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r68 = cpy_r_r1;
    cpy_r_r78 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r78.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__30", -1, CPyStatic_globals);
        goto CPyL204;
    }
    CPy_INCREF(cpy_r_r78.f0);
    CPy_INCREF(cpy_r_r78.f1);
    CPy_INCREF(cpy_r_r78.f2);
CPyL67: ;
    CPy_RestoreExcInfo(cpy_r_r78);
    CPy_DecRef(cpy_r_r78.f0);
    CPy_DecRef(cpy_r_r78.f1);
    CPy_DecRef(cpy_r_r78.f2);
    goto CPyL53;
CPyL68: ;
    if (cpy_r_r1 != NULL) goto CPyL71;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r79 = 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL73;
    } else
        goto CPyL205;
CPyL70: ;
    CPy_Unreachable();
CPyL71: ;
    cpy_r_r67 = cpy_r_r1;
    cpy_r_r80 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r80.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__30", -1, CPyStatic_globals);
        goto CPyL206;
    }
    CPy_INCREF(cpy_r_r80.f0);
    CPy_INCREF(cpy_r_r80.f1);
    CPy_INCREF(cpy_r_r80.f2);
CPyL72: ;
    CPy_RestoreExcInfo(cpy_r_r80);
    CPy_DecRef(cpy_r_r80.f0);
    CPy_DecRef(cpy_r_r80.f1);
    CPy_DecRef(cpy_r_r80.f2);
    goto CPyL81;
CPyL73: ;
    cpy_r_r81 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r81.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__30", -1, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_r81.f0);
    CPy_INCREF(cpy_r_r81.f1);
    CPy_INCREF(cpy_r_r81.f2);
CPyL74: ;
    CPy_RestoreExcInfo(cpy_r_r81);
    CPy_DecRef(cpy_r_r81.f0);
    CPy_DecRef(cpy_r_r81.f1);
    CPy_DecRef(cpy_r_r81.f2);
    cpy_r_r82 = CPy_KeepPropagating();
    if (!cpy_r_r82) {
        goto CPyL82;
    } else
        goto CPyL207;
CPyL75: ;
    CPy_Unreachable();
CPyL76: ;
    cpy_r_r83 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__29", -1, CPyStatic_globals);
        goto CPyL208;
    }
    CPy_INCREF(cpy_r_r83);
CPyL77: ;
    cpy_r_r84 = CPyIter_Send(cpy_r_r83, cpy_r_arg);
    CPy_DECREF(cpy_r_r83);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r84 == NULL) goto CPyL209;
    cpy_r_r68 = cpy_r_r84;
    goto CPyL53;
CPyL79: ;
    cpy_r_r85 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r67 = cpy_r_r85;
CPyL81: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r67;
    cpy_r_r86 = 1;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 166, CPyStatic_globals);
    } else
        goto CPyL159;
CPyL82: ;
    cpy_r_r87 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31.f2);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31 = cpy_r_r87;
    cpy_r_r88 = 1;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r89 = CPyModule_builtins;
    cpy_r_r90 = CPyStatics[40]; /* 'AttributeError' */
    cpy_r_r91 = CPyObject_GetAttr(cpy_r_r89, cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 167, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r92 = CPyModule_builtins;
    cpy_r_r93 = CPyStatics[41]; /* 'TypeError' */
    cpy_r_r94 = CPyObject_GetAttr(cpy_r_r92, cpy_r_r93);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 167, CPyStatic_globals);
        goto CPyL210;
    }
    cpy_r_r95.f0 = cpy_r_r91;
    cpy_r_r95.f1 = cpy_r_r94;
    cpy_r_r96 = PyTuple_New(2);
    if (unlikely(cpy_r_r96 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp10 = cpy_r_r95.f0;
    PyTuple_SET_ITEM(cpy_r_r96, 0, __tmp10);
    PyObject *__tmp11 = cpy_r_r95.f1;
    PyTuple_SET_ITEM(cpy_r_r96, 1, __tmp11);
    cpy_r_r97 = CPy_ExceptionMatches(cpy_r_r96);
    CPy_DecRef(cpy_r_r96);
    if (!cpy_r_r97) goto CPyL98;
    cpy_r_r98 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 169, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_INCREF(cpy_r_r98);
CPyL87: ;
    cpy_r_r99 = CPyStatics[6]; /* 'abi' */
    cpy_r_r100 = CPyObject_GetAttr(cpy_r_r98, cpy_r_r99);
    CPy_DecRef(cpy_r_r98);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r101 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 169, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r101);
CPyL89: ;
    cpy_r_r102 = CPyStatics[7]; /* 'signature' */
    cpy_r_r103 = CPyObject_GetAttr(cpy_r_r101, cpy_r_r102);
    CPy_DecRef(cpy_r_r101);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r104 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 169, CPyStatic_globals);
        goto CPyL212;
    }
    CPy_INCREF(cpy_r_r104);
CPyL91: ;
    cpy_r_r105 = CPyStatic_globals;
    cpy_r_r106 = CPyStatics[5]; /* '__encode_input' */
    cpy_r_r107 = CPyDict_GetItem(cpy_r_r105, cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL213;
    }
    cpy_r_r108 = PyList_New(2);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL214;
    }
    cpy_r_r109 = (CPyPtr)&((PyListObject *)cpy_r_r108)->ob_item;
    cpy_r_r110 = *(CPyPtr *)cpy_r_r109;
    *(PyObject * *)cpy_r_r110 = cpy_r_r100;
    cpy_r_r111 = cpy_r_r110 + 8;
    *(PyObject * *)cpy_r_r111 = cpy_r_r103;
    cpy_r_r112 = CPyList_Extend(cpy_r_r108, cpy_r_r104);
    CPy_DecRef(cpy_r_r104);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL215;
    } else
        goto CPyL216;
CPyL94: ;
    cpy_r_r113 = PyList_AsTuple(cpy_r_r108);
    CPy_DecRef(cpy_r_r108);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL217;
    }
    cpy_r_r114 = PyDict_New();
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL218;
    }
    cpy_r_r115 = PyObject_Call(cpy_r_r107, cpy_r_r113, cpy_r_r114);
    CPy_DecRef(cpy_r_r107);
    CPy_DecRef(cpy_r_r113);
    CPy_DecRef(cpy_r_r114);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL156;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r115;
    cpy_r_r116 = 1;
    if (unlikely(!cpy_r_r116)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 169, CPyStatic_globals);
        goto CPyL156;
    } else
        goto CPyL154;
CPyL98: ;
    cpy_r_r117 = CPyStatic_globals;
    cpy_r_r118 = CPyStatics[42]; /* 'BrokenProcessPool' */
    cpy_r_r119 = CPyDict_GetItem(cpy_r_r117, cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 171, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r120 = CPy_ExceptionMatches(cpy_r_r119);
    CPy_DecRef(cpy_r_r119);
    if (!cpy_r_r120) goto CPyL132;
    cpy_r_r121 = CPyStatic_globals;
    cpy_r_r122 = CPyStatics[43]; /* 'logger' */
    cpy_r_r123 = CPyDict_GetItem(cpy_r_r121, cpy_r_r122);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 172, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r124 = CPyStatics[44]; /* 'Oh fuck, you broke the %s while decoding %s with abi %s' */
    cpy_r_r125 = CPyStatic_globals;
    cpy_r_r126 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r127 = CPyDict_GetItem(cpy_r_r125, cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 172, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r128 = CPyStatics[4]; /* 'BROWNIE_ENCODER_PROCESSES' */
    cpy_r_r129 = CPyObject_GetAttr(cpy_r_r127, cpy_r_r128);
    CPy_DecRef(cpy_r_r127);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 172, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r130 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data;
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "data", 172, CPyStatic_globals);
        goto CPyL220;
    }
    CPy_INCREF(cpy_r_r130);
CPyL104: ;
    cpy_r_r131 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 172, CPyStatic_globals);
        goto CPyL221;
    }
    CPy_INCREF(cpy_r_r131);
CPyL105: ;
    cpy_r_r132 = CPyStatics[6]; /* 'abi' */
    cpy_r_r133 = CPyObject_GetAttr(cpy_r_r131, cpy_r_r132);
    CPy_DecRef(cpy_r_r131);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 172, CPyStatic_globals);
        goto CPyL221;
    }
    cpy_r_r134 = CPyStatics[45]; /* 'critical' */
    cpy_r_r135 = CPyObject_CallMethodObjArgs(cpy_r_r123, cpy_r_r134, cpy_r_r124, cpy_r_r129, cpy_r_r130, cpy_r_r133, NULL);
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r129);
    CPy_DecRef(cpy_r_r130);
    CPy_DecRef(cpy_r_r133);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 172, CPyStatic_globals);
        goto CPyL156;
    } else
        goto CPyL222;
CPyL107: ;
    cpy_r_r136 = CPyStatic_globals;
    cpy_r_r137 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r138 = CPyDict_GetItem(cpy_r_r136, cpy_r_r137);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 174, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r139 = CPyStatics[4]; /* 'BROWNIE_ENCODER_PROCESSES' */
    cpy_r_r140 = CPyObject_GetAttr(cpy_r_r138, cpy_r_r139);
    CPy_DecRef(cpy_r_r138);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 174, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r141 = CPyStatics[46]; /* '_max_workers' */
    cpy_r_r142 = CPyObject_GetAttr(cpy_r_r140, cpy_r_r141);
    CPy_DecRef(cpy_r_r140);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 174, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r143 = CPyStatic_globals;
    cpy_r_r144 = CPyStatics[47]; /* 'AsyncProcessPoolExecutor' */
    cpy_r_r145 = CPyDict_GetItem(cpy_r_r143, cpy_r_r144);
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 174, CPyStatic_globals);
        goto CPyL223;
    }
    PyObject *cpy_r_r146[1] = {cpy_r_r142};
    cpy_r_r147 = (PyObject **)&cpy_r_r146;
    cpy_r_r148 = _PyObject_Vectorcall(cpy_r_r145, cpy_r_r147, 1, 0);
    CPy_DecRef(cpy_r_r145);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 174, CPyStatic_globals);
        goto CPyL223;
    }
    CPy_DecRef(cpy_r_r142);
    cpy_r_r149 = CPyStatic_globals;
    cpy_r_r150 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r151 = CPyDict_GetItem(cpy_r_r149, cpy_r_r150);
    if (unlikely(cpy_r_r151 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 174, CPyStatic_globals);
        goto CPyL224;
    }
    cpy_r_r152 = CPyStatics[4]; /* 'BROWNIE_ENCODER_PROCESSES' */
    cpy_r_r153 = PyObject_SetAttr(cpy_r_r151, cpy_r_r152, cpy_r_r148);
    CPy_DecRef(cpy_r_r151);
    CPy_DecRef(cpy_r_r148);
    cpy_r_r154 = cpy_r_r153 >= 0;
    if (unlikely(!cpy_r_r154)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 174, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r155 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_len_inputs;
    if (unlikely(cpy_r_r155 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "len_inputs", 175, CPyStatic_globals);
        goto CPyL156;
    }
    CPyTagged_INCREF(cpy_r_r155);
CPyL115: ;
    cpy_r_r156 = cpy_r_r155 != 0;
    CPyTagged_DecRef(cpy_r_r155);
    if (!cpy_r_r156) goto CPyL128;
    cpy_r_r157 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 175, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_INCREF(cpy_r_r157);
CPyL117: ;
    cpy_r_r158 = CPyStatics[6]; /* 'abi' */
    cpy_r_r159 = CPyObject_GetAttr(cpy_r_r157, cpy_r_r158);
    CPy_DecRef(cpy_r_r157);
    if (unlikely(cpy_r_r159 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r160 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 175, CPyStatic_globals);
        goto CPyL225;
    }
    CPy_INCREF(cpy_r_r160);
CPyL119: ;
    cpy_r_r161 = CPyStatics[7]; /* 'signature' */
    cpy_r_r162 = CPyObject_GetAttr(cpy_r_r160, cpy_r_r161);
    CPy_DecRef(cpy_r_r160);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL225;
    }
    cpy_r_r163 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 175, CPyStatic_globals);
        goto CPyL226;
    }
    CPy_INCREF(cpy_r_r163);
CPyL121: ;
    cpy_r_r164 = CPyStatic_globals;
    cpy_r_r165 = CPyStatics[5]; /* '__encode_input' */
    cpy_r_r166 = CPyDict_GetItem(cpy_r_r164, cpy_r_r165);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL227;
    }
    cpy_r_r167 = PyList_New(2);
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL228;
    }
    cpy_r_r168 = (CPyPtr)&((PyListObject *)cpy_r_r167)->ob_item;
    cpy_r_r169 = *(CPyPtr *)cpy_r_r168;
    *(PyObject * *)cpy_r_r169 = cpy_r_r159;
    cpy_r_r170 = cpy_r_r169 + 8;
    *(PyObject * *)cpy_r_r170 = cpy_r_r162;
    cpy_r_r171 = CPyList_Extend(cpy_r_r167, cpy_r_r163);
    CPy_DecRef(cpy_r_r163);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL229;
    } else
        goto CPyL230;
CPyL124: ;
    cpy_r_r172 = PyList_AsTuple(cpy_r_r167);
    CPy_DecRef(cpy_r_r167);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r173 = PyDict_New();
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL232;
    }
    cpy_r_r174 = PyObject_Call(cpy_r_r166, cpy_r_r172, cpy_r_r173);
    CPy_DecRef(cpy_r_r166);
    CPy_DecRef(cpy_r_r172);
    CPy_DecRef(cpy_r_r173);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r175 = cpy_r_r174;
    goto CPyL131;
CPyL128: ;
    cpy_r_r176 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 175, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_INCREF(cpy_r_r176);
CPyL129: ;
    cpy_r_r177 = CPyStatics[7]; /* 'signature' */
    cpy_r_r178 = CPyObject_GetAttr(cpy_r_r176, cpy_r_r177);
    CPy_DecRef(cpy_r_r176);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r175 = cpy_r_r178;
CPyL131: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r175;
    cpy_r_r179 = 1;
    if (unlikely(!cpy_r_r179)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 175, CPyStatic_globals);
        goto CPyL156;
    } else
        goto CPyL154;
CPyL132: ;
    cpy_r_r180 = CPyStatic_globals;
    cpy_r_r181 = CPyStatics[48]; /* 'PicklingError' */
    cpy_r_r182 = CPyDict_GetItem(cpy_r_r180, cpy_r_r181);
    if (unlikely(cpy_r_r182 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 176, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r183 = CPy_ExceptionMatches(cpy_r_r182);
    CPy_DecRef(cpy_r_r182);
    if (!cpy_r_r183) goto CPyL152;
    cpy_r_r184 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_len_inputs;
    if (unlikely(cpy_r_r184 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "len_inputs", 177, CPyStatic_globals);
        goto CPyL156;
    }
    CPyTagged_INCREF(cpy_r_r184);
CPyL135: ;
    cpy_r_r185 = cpy_r_r184 != 0;
    CPyTagged_DecRef(cpy_r_r184);
    if (!cpy_r_r185) goto CPyL148;
    cpy_r_r186 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 177, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_INCREF(cpy_r_r186);
CPyL137: ;
    cpy_r_r187 = CPyStatics[6]; /* 'abi' */
    cpy_r_r188 = CPyObject_GetAttr(cpy_r_r186, cpy_r_r187);
    CPy_DecRef(cpy_r_r186);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r189 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 177, CPyStatic_globals);
        goto CPyL233;
    }
    CPy_INCREF(cpy_r_r189);
CPyL139: ;
    cpy_r_r190 = CPyStatics[7]; /* 'signature' */
    cpy_r_r191 = CPyObject_GetAttr(cpy_r_r189, cpy_r_r190);
    CPy_DecRef(cpy_r_r189);
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL233;
    }
    cpy_r_r192 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r192 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "args", 177, CPyStatic_globals);
        goto CPyL234;
    }
    CPy_INCREF(cpy_r_r192);
CPyL141: ;
    cpy_r_r193 = CPyStatic_globals;
    cpy_r_r194 = CPyStatics[5]; /* '__encode_input' */
    cpy_r_r195 = CPyDict_GetItem(cpy_r_r193, cpy_r_r194);
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL235;
    }
    cpy_r_r196 = PyList_New(2);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL236;
    }
    cpy_r_r197 = (CPyPtr)&((PyListObject *)cpy_r_r196)->ob_item;
    cpy_r_r198 = *(CPyPtr *)cpy_r_r197;
    *(PyObject * *)cpy_r_r198 = cpy_r_r188;
    cpy_r_r199 = cpy_r_r198 + 8;
    *(PyObject * *)cpy_r_r199 = cpy_r_r191;
    cpy_r_r200 = CPyList_Extend(cpy_r_r196, cpy_r_r192);
    CPy_DecRef(cpy_r_r192);
    if (unlikely(cpy_r_r200 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL237;
    } else
        goto CPyL238;
CPyL144: ;
    cpy_r_r201 = PyList_AsTuple(cpy_r_r196);
    CPy_DecRef(cpy_r_r196);
    if (unlikely(cpy_r_r201 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL239;
    }
    cpy_r_r202 = PyDict_New();
    if (unlikely(cpy_r_r202 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL240;
    }
    cpy_r_r203 = PyObject_Call(cpy_r_r195, cpy_r_r201, cpy_r_r202);
    CPy_DecRef(cpy_r_r195);
    CPy_DecRef(cpy_r_r201);
    CPy_DecRef(cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r204 = cpy_r_r203;
    goto CPyL151;
CPyL148: ;
    cpy_r_r205 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_call;
    if (unlikely(cpy_r_r205 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "call", 177, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_INCREF(cpy_r_r205);
CPyL149: ;
    cpy_r_r206 = CPyStatics[7]; /* 'signature' */
    cpy_r_r207 = CPyObject_GetAttr(cpy_r_r205, cpy_r_r206);
    CPy_DecRef(cpy_r_r205);
    if (unlikely(cpy_r_r207 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r204 = cpy_r_r207;
CPyL151: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data = cpy_r_r204;
    cpy_r_r208 = 1;
    if (unlikely(!cpy_r_r208)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 177, CPyStatic_globals);
        goto CPyL156;
    } else
        goto CPyL154;
CPyL152: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL156;
    } else
        goto CPyL241;
CPyL153: ;
    CPy_Unreachable();
CPyL154: ;
    cpy_r_r209 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31;
    if (unlikely(cpy_r_r209.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "__mypyc_temp__31", -1, CPyStatic_globals);
        goto CPyL181;
    }
    CPy_INCREF(cpy_r_r209.f0);
    CPy_INCREF(cpy_r_r209.f1);
    CPy_INCREF(cpy_r_r209.f2);
CPyL155: ;
    CPy_RestoreExcInfo(cpy_r_r209);
    CPy_DecRef(cpy_r_r209.f0);
    CPy_DecRef(cpy_r_r209.f1);
    CPy_DecRef(cpy_r_r209.f2);
    goto CPyL159;
CPyL156: ;
    cpy_r_r210 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_temp__31;
    if (unlikely(cpy_r_r210.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__31' of 'encode_input_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r210.f0);
        CPy_INCREF(cpy_r_r210.f1);
        CPy_INCREF(cpy_r_r210.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r210.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", -1, CPyStatic_globals);
        goto CPyL174;
    }
CPyL157: ;
    CPy_RestoreExcInfo(cpy_r_r210);
    CPy_DecRef(cpy_r_r210.f0);
    CPy_DecRef(cpy_r_r210.f1);
    CPy_DecRef(cpy_r_r210.f2);
    cpy_r_r211 = CPy_KeepPropagating();
    if (!cpy_r_r211) goto CPyL174;
    CPy_Unreachable();
CPyL159: ;
    cpy_r_r212 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data;
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "data", 179, CPyStatic_globals);
        goto CPyL181;
    }
    CPy_INCREF(cpy_r_r212);
CPyL160: ;
    cpy_r_r213 = CPyModule_builtins;
    cpy_r_r214 = CPyStatics[49]; /* 'Exception' */
    cpy_r_r215 = CPyObject_GetAttr(cpy_r_r213, cpy_r_r214);
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 179, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r216 = PyObject_IsInstance(cpy_r_r212, cpy_r_r215);
    CPy_DECREF(cpy_r_r212);
    CPy_DECREF(cpy_r_r215);
    cpy_r_r217 = cpy_r_r216 >= 0;
    if (unlikely(!cpy_r_r217)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 179, CPyStatic_globals);
        goto CPyL181;
    }
    cpy_r_r218 = cpy_r_r216;
    if (!cpy_r_r218) goto CPyL166;
    cpy_r_r219 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data;
    if (unlikely(cpy_r_r219 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'data' of 'encode_input_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r219);
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 180, CPyStatic_globals);
        goto CPyL174;
    }
CPyL164: ;
    CPy_Raise(cpy_r_r219);
    CPy_DECREF(cpy_r_r219);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 180, CPyStatic_globals);
        goto CPyL174;
    }
    CPy_Unreachable();
CPyL166: ;
    cpy_r_r220 = ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->_data;
    if (unlikely(cpy_r_r220 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "encode_input", "encode_input_env", "data", 181, CPyStatic_globals);
        goto CPyL181;
    }
    CPy_INCREF(cpy_r_r220);
CPyL167: ;
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r221 = 1;
    CPy_DECREF(cpy_r_r2);
    if (unlikely(!cpy_r_r221)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 181, CPyStatic_globals);
        goto CPyL243;
    }
    CPyGen_SetStopIterationValue(cpy_r_r220);
    CPy_DECREF(cpy_r_r220);
    if (!0) goto CPyL174;
    CPy_Unreachable();
CPyL170: ;
    cpy_r_r222 = cpy_r_r3 == 0;
    if (cpy_r_r222) goto CPyL244;
    cpy_r_r223 = cpy_r_r3 == 2;
    CPyTagged_DECREF(cpy_r_r3);
    if (cpy_r_r223) {
        goto CPyL55;
    } else
        goto CPyL245;
CPyL172: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r224 = 0;
    if (unlikely(!cpy_r_r224)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL174;
    }
    CPy_Unreachable();
CPyL174: ;
    cpy_r_r225 = NULL;
    return cpy_r_r225;
CPyL175: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL174;
CPyL176: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL174;
CPyL177: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL3;
CPyL178: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r16);
    goto CPyL174;
CPyL179: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r20);
    goto CPyL174;
CPyL180: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL26;
CPyL181: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL174;
CPyL182: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r35);
    goto CPyL174;
CPyL183: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r38);
    goto CPyL174;
CPyL184: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r38);
    CPy_DecRef(cpy_r_r39);
    goto CPyL174;
CPyL185: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r38);
    CPy_DecRef(cpy_r_r39);
    CPy_DecRef(cpy_r_r42);
    goto CPyL174;
CPyL186: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_r43);
    goto CPyL174;
CPyL187: ;
    CPy_DECREF(cpy_r_r47);
    goto CPyL34;
CPyL188: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r42);
    goto CPyL174;
CPyL189: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_r48);
    goto CPyL174;
CPyL190: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL82;
CPyL191: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r52);
    goto CPyL82;
CPyL192: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    goto CPyL82;
CPyL193: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    CPy_DecRef(cpy_r_r54);
    goto CPyL82;
CPyL194: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r54);
    CPy_DecRef(cpy_r_r55);
    goto CPyL82;
CPyL195: ;
    CPy_DECREF(cpy_r_r58);
    goto CPyL43;
CPyL196: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r54);
    goto CPyL82;
CPyL197: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r54);
    CPy_DecRef(cpy_r_r59);
    goto CPyL82;
CPyL198: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL50;
CPyL199: ;
    CPy_DecRef(cpy_r_r68);
    goto CPyL59;
CPyL200: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL54;
CPyL201: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL57;
CPyL202: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL73;
CPyL203: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL65;
CPyL204: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r68);
    goto CPyL73;
CPyL205: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL70;
CPyL206: ;
    CPy_DecRef(cpy_r_r67);
    goto CPyL73;
CPyL207: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL75;
CPyL208: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_arg);
    goto CPyL82;
CPyL209: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL79;
CPyL210: ;
    CPy_DecRef(cpy_r_r91);
    goto CPyL156;
CPyL211: ;
    CPy_DecRef(cpy_r_r100);
    goto CPyL156;
CPyL212: ;
    CPy_DecRef(cpy_r_r100);
    CPy_DecRef(cpy_r_r103);
    goto CPyL156;
CPyL213: ;
    CPy_DecRef(cpy_r_r100);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r104);
    goto CPyL156;
CPyL214: ;
    CPy_DecRef(cpy_r_r100);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r107);
    goto CPyL156;
CPyL215: ;
    CPy_DecRef(cpy_r_r107);
    CPy_DecRef(cpy_r_r108);
    goto CPyL156;
CPyL216: ;
    CPy_DecRef(cpy_r_r112);
    goto CPyL94;
CPyL217: ;
    CPy_DecRef(cpy_r_r107);
    goto CPyL156;
CPyL218: ;
    CPy_DecRef(cpy_r_r107);
    CPy_DecRef(cpy_r_r113);
    goto CPyL156;
CPyL219: ;
    CPy_DecRef(cpy_r_r123);
    goto CPyL156;
CPyL220: ;
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r129);
    goto CPyL156;
CPyL221: ;
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r129);
    CPy_DecRef(cpy_r_r130);
    goto CPyL156;
CPyL222: ;
    CPy_DecRef(cpy_r_r135);
    goto CPyL107;
CPyL223: ;
    CPy_DecRef(cpy_r_r142);
    goto CPyL156;
CPyL224: ;
    CPy_DecRef(cpy_r_r148);
    goto CPyL156;
CPyL225: ;
    CPy_DecRef(cpy_r_r159);
    goto CPyL156;
CPyL226: ;
    CPy_DecRef(cpy_r_r159);
    CPy_DecRef(cpy_r_r162);
    goto CPyL156;
CPyL227: ;
    CPy_DecRef(cpy_r_r159);
    CPy_DecRef(cpy_r_r162);
    CPy_DecRef(cpy_r_r163);
    goto CPyL156;
CPyL228: ;
    CPy_DecRef(cpy_r_r159);
    CPy_DecRef(cpy_r_r162);
    CPy_DecRef(cpy_r_r163);
    CPy_DecRef(cpy_r_r166);
    goto CPyL156;
CPyL229: ;
    CPy_DecRef(cpy_r_r166);
    CPy_DecRef(cpy_r_r167);
    goto CPyL156;
CPyL230: ;
    CPy_DecRef(cpy_r_r171);
    goto CPyL124;
CPyL231: ;
    CPy_DecRef(cpy_r_r166);
    goto CPyL156;
CPyL232: ;
    CPy_DecRef(cpy_r_r166);
    CPy_DecRef(cpy_r_r172);
    goto CPyL156;
CPyL233: ;
    CPy_DecRef(cpy_r_r188);
    goto CPyL156;
CPyL234: ;
    CPy_DecRef(cpy_r_r188);
    CPy_DecRef(cpy_r_r191);
    goto CPyL156;
CPyL235: ;
    CPy_DecRef(cpy_r_r188);
    CPy_DecRef(cpy_r_r191);
    CPy_DecRef(cpy_r_r192);
    goto CPyL156;
CPyL236: ;
    CPy_DecRef(cpy_r_r188);
    CPy_DecRef(cpy_r_r191);
    CPy_DecRef(cpy_r_r192);
    CPy_DecRef(cpy_r_r195);
    goto CPyL156;
CPyL237: ;
    CPy_DecRef(cpy_r_r195);
    CPy_DecRef(cpy_r_r196);
    goto CPyL156;
CPyL238: ;
    CPy_DecRef(cpy_r_r200);
    goto CPyL144;
CPyL239: ;
    CPy_DecRef(cpy_r_r195);
    goto CPyL156;
CPyL240: ;
    CPy_DecRef(cpy_r_r195);
    CPy_DecRef(cpy_r_r201);
    goto CPyL156;
CPyL241: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL153;
CPyL242: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r212);
    goto CPyL174;
CPyL243: ;
    CPy_DecRef(cpy_r_r220);
    goto CPyL174;
CPyL244: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL2;
CPyL245: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL172;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
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
    cpy_r_r1 = CPyStatics[33]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_encode_input_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[34]; /* 'StopIteration' */
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
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_INCREF(cpy_r_call);
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_call != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_call);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_call = cpy_r_call;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL10;
    }
    CPyTagged_INCREF(cpy_r_len_inputs);
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_len_inputs != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_len_inputs);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_len_inputs = cpy_r_len_inputs;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_get_request_data);
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_get_request_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_get_request_data);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_get_request_data = cpy_r_get_request_data;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_args);
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_args != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_args);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->_args = cpy_r_args;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r5 = CPyDef_encode_input_gen();
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___brownie_patch___call___encode_input_genObject *)cpy_r_r5)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___encode_input_genObject *)cpy_r_r5)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___encode_input_genObject *)cpy_r_r5)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
        goto CPyL11;
    }
    if (((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___encode_input_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r7 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "encode_input", 159, CPyStatic_globals);
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
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject **cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    char cpy_r_r49;
    tuple_T3OOO cpy_r_r50;
    char cpy_r_r51;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    char cpy_r_r55;
    tuple_T3OOO cpy_r_r56;
    char cpy_r_r57;
    tuple_T3OOO cpy_r_r58;
    tuple_T3OOO cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    char cpy_r_r64;
    tuple_T3OOO cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
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
    PyObject **cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    int32_t cpy_r_r103;
    char cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    char cpy_r_r111;
    tuple_T3OOO cpy_r_r112;
    tuple_T3OOO cpy_r_r113;
    char cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    int32_t cpy_r_r119;
    char cpy_r_r120;
    char cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    char cpy_r_r124;
    tuple_T3OOO cpy_r_r125;
    char cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    char cpy_r_r130;
    PyObject *cpy_r_r131;
    char cpy_r_r132;
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
    int32_t cpy_r_r145;
    char cpy_r_r146;
    int32_t cpy_r_r147;
    char cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    int32_t cpy_r_r152;
    char cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    char cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    char cpy_r_r163;
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
    PyObject *cpy_r_r177;
    int32_t cpy_r_r178;
    char cpy_r_r179;
    char cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    int32_t cpy_r_r184;
    char cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    char cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    char cpy_r_r196;
    PyObject *cpy_r_r197;
    char cpy_r_r198;
    tuple_T3OOO cpy_r_r199;
    char cpy_r_r200;
    PyObject **cpy_r_r201;
    PyObject *cpy_r_r202;
    char cpy_r_r203;
    char cpy_r_r204;
    tuple_T3OOO cpy_r_r205;
    char cpy_r_r206;
    tuple_T3OOO cpy_r_r207;
    tuple_T3OOO cpy_r_r208;
    char cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    tuple_T3OOO cpy_r_r213;
    char cpy_r_r214;
    tuple_T3OOO cpy_r_r215;
    char cpy_r_r216;
    char cpy_r_r217;
    char cpy_r_r218;
    char cpy_r_r219;
    char cpy_r_r220;
    PyObject *cpy_r_r221;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = NULL;
    cpy_r_r3 = cpy_r_r2;
    cpy_r_r4 = ((dank_mids___brownie_patch___call___decode_output_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_gen", "__mypyc_env__", 184, CPyStatic_globals);
        goto CPyL195;
    }
    CPy_INCREF(cpy_r_r4);
CPyL1: ;
    cpy_r_r5 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__;
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_next_label__", 184, CPyStatic_globals);
        goto CPyL196;
    }
    CPyTagged_INCREF(cpy_r_r5);
    goto CPyL189;
CPyL2: ;
    cpy_r_r6 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r7 = cpy_r_type != cpy_r_r6;
    if (cpy_r_r7) {
        goto CPyL197;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
        goto CPyL194;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r8 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 185, CPyStatic_globals);
        goto CPyL196;
    }
    CPy_INCREF(cpy_r_r8);
CPyL6: ;
    cpy_r_r9 = CPyStatics[6]; /* 'abi' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 185, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r11 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 185, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_INCREF(cpy_r_r11);
CPyL8: ;
    if (likely(PyDict_Check(cpy_r_r10)))
        cpy_r_r12 = cpy_r_r10;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "decode_output", 185, CPyStatic_globals, "dict", cpy_r_r10);
        goto CPyL199;
    }
    cpy_r_r13 = CPyDef___validate_output(cpy_r_r12, cpy_r_r11);
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r13 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 185, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r14 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 187, CPyStatic_globals);
        goto CPyL200;
    }
    CPy_INCREF(cpy_r_r14);
CPyL11: ;
    cpy_r_r15 = CPyStatics[13]; /* '_skip_decoder_proc_pool' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 187, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r17 = PyObject_IsTrue(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r18 = cpy_r_r17 >= 0;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 187, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r19 = cpy_r_r17;
    if (cpy_r_r19) goto CPyL201;
    cpy_r_r20 = CPyStatics[188]; /* b'Unexpected error' */
    cpy_r_r21 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 187, CPyStatic_globals);
        goto CPyL200;
    }
    CPy_INCREF(cpy_r_r21);
CPyL15: ;
    cpy_r_r22 = PySequence_Contains(cpy_r_r21, cpy_r_r20);
    CPy_DECREF(cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 187, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r24 = cpy_r_r22;
    if (cpy_r_r24) {
        goto CPyL201;
    } else
        goto CPyL23;
CPyL17: ;
    cpy_r_r25 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 189, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r25);
CPyL18: ;
    cpy_r_r26 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 189, CPyStatic_globals);
        goto CPyL202;
    }
    CPy_INCREF(cpy_r_r26);
CPyL19: ;
    cpy_r_r27 = CPyStatics[6]; /* 'abi' */
    cpy_r_r28 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 189, CPyStatic_globals);
        goto CPyL202;
    }
    if (likely(PyDict_Check(cpy_r_r28)))
        cpy_r_r29 = cpy_r_r28;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "decode_output", 189, CPyStatic_globals, "dict", cpy_r_r28);
        goto CPyL202;
    }
    cpy_r_r30 = CPyDef___decode_output(cpy_r_r25, cpy_r_r29);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 189, CPyStatic_globals);
        goto CPyL104;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded = cpy_r_r30;
    cpy_r_r31 = 1;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 189, CPyStatic_globals);
        goto CPyL104;
    } else
        goto CPyL93;
CPyL23: ;
    cpy_r_r32 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 192, CPyStatic_globals);
        goto CPyL203;
    }
    CPy_INCREF(cpy_r_r32);
CPyL24: ;
    cpy_r_r33 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 192, CPyStatic_globals);
        goto CPyL204;
    }
    CPy_INCREF(cpy_r_r33);
CPyL25: ;
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyStatics[50]; /* 'decode' */
    cpy_r_r36 = CPyDict_GetItem(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
        goto CPyL205;
    }
    PyObject *cpy_r_r37[2] = {cpy_r_r32, cpy_r_r33};
    cpy_r_r38 = (PyObject **)&cpy_r_r37;
    cpy_r_r39 = _PyObject_Vectorcall(cpy_r_r36, cpy_r_r38, 2, 0);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
        goto CPyL205;
    }
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r40 = CPy_GetCoro(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
        goto CPyL203;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32 = cpy_r_r40;
    cpy_r_r41 = 1;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL203;
    }
    cpy_r_r42 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32;
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__32", -1, CPyStatic_globals);
        goto CPyL203;
    }
    CPy_INCREF(cpy_r_r42);
CPyL30: ;
    cpy_r_r43 = CPyIter_Next(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    if (cpy_r_r43 == NULL) {
        goto CPyL206;
    } else
        goto CPyL33;
CPyL31: ;
    cpy_r_r44 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r45 = cpy_r_r44;
    goto CPyL62;
CPyL33: ;
    cpy_r_r46 = cpy_r_r43;
CPyL34: ;
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ = 2;
    cpy_r_r47 = 1;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
        goto CPyL207;
    } else
        goto CPyL208;
CPyL35: ;
    return cpy_r_r46;
CPyL36: ;
    cpy_r_r48 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r49 = cpy_r_type != cpy_r_r48;
    if (!cpy_r_r49) goto CPyL39;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
        goto CPyL40;
    } else
        goto CPyL209;
CPyL38: ;
    CPy_Unreachable();
CPyL39: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL57;
CPyL40: ;
    cpy_r_r50 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33.f2);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33 = cpy_r_r50;
    cpy_r_r51 = 1;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL210;
    }
    cpy_r_r52 = (PyObject **)&cpy_r_r1;
    cpy_r_r53 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__32", -1, CPyStatic_globals);
        goto CPyL210;
    }
    CPy_INCREF(cpy_r_r53);
CPyL42: ;
    cpy_r_r54 = CPy_YieldFromErrorHandle(cpy_r_r53, cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    if (unlikely(cpy_r_r54 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
        goto CPyL210;
    }
    if (cpy_r_r54) goto CPyL49;
    if (cpy_r_r1 != NULL) goto CPyL47;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r55 = 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL211;
CPyL46: ;
    CPy_Unreachable();
CPyL47: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r46 = cpy_r_r1;
    cpy_r_r56 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33;
    if (unlikely(cpy_r_r56.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__33", -1, CPyStatic_globals);
        goto CPyL212;
    }
    CPy_INCREF(cpy_r_r56.f0);
    CPy_INCREF(cpy_r_r56.f1);
    CPy_INCREF(cpy_r_r56.f2);
CPyL48: ;
    CPy_RestoreExcInfo(cpy_r_r56);
    CPy_DecRef(cpy_r_r56.f0);
    CPy_DecRef(cpy_r_r56.f1);
    CPy_DecRef(cpy_r_r56.f2);
    goto CPyL34;
CPyL49: ;
    if (cpy_r_r1 != NULL) goto CPyL52;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r57 = 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL213;
CPyL51: ;
    CPy_Unreachable();
CPyL52: ;
    cpy_r_r45 = cpy_r_r1;
    cpy_r_r58 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33;
    if (unlikely(cpy_r_r58.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__33", -1, CPyStatic_globals);
        goto CPyL214;
    }
    CPy_INCREF(cpy_r_r58.f0);
    CPy_INCREF(cpy_r_r58.f1);
    CPy_INCREF(cpy_r_r58.f2);
CPyL53: ;
    CPy_RestoreExcInfo(cpy_r_r58);
    CPy_DecRef(cpy_r_r58.f0);
    CPy_DecRef(cpy_r_r58.f1);
    CPy_DecRef(cpy_r_r58.f2);
    goto CPyL62;
CPyL54: ;
    cpy_r_r59 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__33;
    if (unlikely(cpy_r_r59.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__33", -1, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_INCREF(cpy_r_r59.f0);
    CPy_INCREF(cpy_r_r59.f1);
    CPy_INCREF(cpy_r_r59.f2);
CPyL55: ;
    CPy_RestoreExcInfo(cpy_r_r59);
    CPy_DecRef(cpy_r_r59.f0);
    CPy_DecRef(cpy_r_r59.f1);
    CPy_DecRef(cpy_r_r59.f2);
    cpy_r_r60 = CPy_KeepPropagating();
    if (!cpy_r_r60) {
        goto CPyL63;
    } else
        goto CPyL215;
CPyL56: ;
    CPy_Unreachable();
CPyL57: ;
    cpy_r_r61 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__32;
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__32", -1, CPyStatic_globals);
        goto CPyL216;
    }
    CPy_INCREF(cpy_r_r61);
CPyL58: ;
    cpy_r_r62 = CPyIter_Send(cpy_r_r61, cpy_r_arg);
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r62 == NULL) goto CPyL217;
    cpy_r_r46 = cpy_r_r62;
    goto CPyL34;
CPyL60: ;
    cpy_r_r63 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r45 = cpy_r_r63;
CPyL62: ;
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded = cpy_r_r45;
    cpy_r_r64 = 1;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 192, CPyStatic_globals);
    } else
        goto CPyL93;
CPyL63: ;
    cpy_r_r65 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34.f2);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34 = cpy_r_r65;
    cpy_r_r66 = 1;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r67 = CPyStatic_globals;
    cpy_r_r68 = CPyStatics[42]; /* 'BrokenProcessPool' */
    cpy_r_r69 = CPyDict_GetItem(cpy_r_r67, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 194, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r70 = CPy_ExceptionMatches(cpy_r_r69);
    CPy_DecRef(cpy_r_r69);
    if (!cpy_r_r70) goto CPyL86;
    cpy_r_r71 = CPyStatic_globals;
    cpy_r_r72 = CPyStatics[43]; /* 'logger' */
    cpy_r_r73 = CPyDict_GetItem(cpy_r_r71, cpy_r_r72);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r74 = CPyStatics[44]; /* 'Oh fuck, you broke the %s while decoding %s with abi %s' */
    cpy_r_r75 = CPyStatic_globals;
    cpy_r_r76 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r77 = CPyDict_GetItem(cpy_r_r75, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL218;
    }
    cpy_r_r78 = CPyStatics[9]; /* 'BROWNIE_DECODER_PROCESSES' */
    cpy_r_r79 = CPyObject_GetAttr(cpy_r_r77, cpy_r_r78);
    CPy_DecRef(cpy_r_r77);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL218;
    }
    cpy_r_r80 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 196, CPyStatic_globals);
        goto CPyL219;
    }
    CPy_INCREF(cpy_r_r80);
CPyL70: ;
    cpy_r_r81 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 196, CPyStatic_globals);
        goto CPyL220;
    }
    CPy_INCREF(cpy_r_r81);
CPyL71: ;
    cpy_r_r82 = CPyStatics[6]; /* 'abi' */
    cpy_r_r83 = CPyObject_GetAttr(cpy_r_r81, cpy_r_r82);
    CPy_DecRef(cpy_r_r81);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL220;
    }
    cpy_r_r84 = CPyStatics[45]; /* 'critical' */
    cpy_r_r85 = CPyObject_CallMethodObjArgs(cpy_r_r73, cpy_r_r84, cpy_r_r74, cpy_r_r79, cpy_r_r80, cpy_r_r83, NULL);
    CPy_DecRef(cpy_r_r73);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r80);
    CPy_DecRef(cpy_r_r83);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 196, CPyStatic_globals);
        goto CPyL90;
    } else
        goto CPyL221;
CPyL73: ;
    cpy_r_r86 = CPyStatic_globals;
    cpy_r_r87 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r88 = CPyDict_GetItem(cpy_r_r86, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r89 = CPyStatics[9]; /* 'BROWNIE_DECODER_PROCESSES' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r89);
    CPy_DecRef(cpy_r_r88);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r91 = CPyStatics[46]; /* '_max_workers' */
    cpy_r_r92 = CPyObject_GetAttr(cpy_r_r90, cpy_r_r91);
    CPy_DecRef(cpy_r_r90);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r93 = CPyStatic_globals;
    cpy_r_r94 = CPyStatics[47]; /* 'AsyncProcessPoolExecutor' */
    cpy_r_r95 = CPyDict_GetItem(cpy_r_r93, cpy_r_r94);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL222;
    }
    PyObject *cpy_r_r96[1] = {cpy_r_r92};
    cpy_r_r97 = (PyObject **)&cpy_r_r96;
    cpy_r_r98 = _PyObject_Vectorcall(cpy_r_r95, cpy_r_r97, 1, 0);
    CPy_DecRef(cpy_r_r95);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL222;
    }
    CPy_DecRef(cpy_r_r92);
    cpy_r_r99 = CPyStatic_globals;
    cpy_r_r100 = CPyStatics[3]; /* 'ENVS' */
    cpy_r_r101 = CPyDict_GetItem(cpy_r_r99, cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL223;
    }
    cpy_r_r102 = CPyStatics[9]; /* 'BROWNIE_DECODER_PROCESSES' */
    cpy_r_r103 = PyObject_SetAttr(cpy_r_r101, cpy_r_r102, cpy_r_r98);
    CPy_DecRef(cpy_r_r101);
    CPy_DecRef(cpy_r_r98);
    cpy_r_r104 = cpy_r_r103 >= 0;
    if (unlikely(!cpy_r_r104)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 197, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_r105 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 198, CPyStatic_globals);
        goto CPyL90;
    }
    CPy_INCREF(cpy_r_r105);
CPyL81: ;
    cpy_r_r106 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 198, CPyStatic_globals);
        goto CPyL224;
    }
    CPy_INCREF(cpy_r_r106);
CPyL82: ;
    cpy_r_r107 = CPyStatics[6]; /* 'abi' */
    cpy_r_r108 = CPyObject_GetAttr(cpy_r_r106, cpy_r_r107);
    CPy_DecRef(cpy_r_r106);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 198, CPyStatic_globals);
        goto CPyL224;
    }
    if (likely(PyDict_Check(cpy_r_r108)))
        cpy_r_r109 = cpy_r_r108;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "decode_output", 198, CPyStatic_globals, "dict", cpy_r_r108);
        goto CPyL224;
    }
    cpy_r_r110 = CPyDef___decode_output(cpy_r_r105, cpy_r_r109);
    CPy_DecRef(cpy_r_r105);
    CPy_DecRef(cpy_r_r109);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 198, CPyStatic_globals);
        goto CPyL90;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded = cpy_r_r110;
    cpy_r_r111 = 1;
    if (unlikely(!cpy_r_r111)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 198, CPyStatic_globals);
        goto CPyL90;
    } else
        goto CPyL88;
CPyL86: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL90;
    } else
        goto CPyL225;
CPyL87: ;
    CPy_Unreachable();
CPyL88: ;
    cpy_r_r112 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34;
    if (unlikely(cpy_r_r112.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__34", -1, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r112.f0);
    CPy_INCREF(cpy_r_r112.f1);
    CPy_INCREF(cpy_r_r112.f2);
CPyL89: ;
    CPy_RestoreExcInfo(cpy_r_r112);
    CPy_DecRef(cpy_r_r112.f0);
    CPy_DecRef(cpy_r_r112.f1);
    CPy_DecRef(cpy_r_r112.f2);
    goto CPyL93;
CPyL90: ;
    cpy_r_r113 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__34;
    if (unlikely(cpy_r_r113.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__34", -1, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r113.f0);
    CPy_INCREF(cpy_r_r113.f1);
    CPy_INCREF(cpy_r_r113.f2);
CPyL91: ;
    CPy_RestoreExcInfo(cpy_r_r113);
    CPy_DecRef(cpy_r_r113.f0);
    CPy_DecRef(cpy_r_r113.f1);
    CPy_DecRef(cpy_r_r113.f2);
    cpy_r_r114 = CPy_KeepPropagating();
    if (!cpy_r_r114) {
        goto CPyL104;
    } else
        goto CPyL226;
CPyL92: ;
    CPy_Unreachable();
CPyL93: ;
    cpy_r_r115 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded;
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "decoded", 200, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r115);
CPyL94: ;
    cpy_r_r116 = CPyModule_builtins;
    cpy_r_r117 = CPyStatics[49]; /* 'Exception' */
    cpy_r_r118 = CPyObject_GetAttr(cpy_r_r116, cpy_r_r117);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 200, CPyStatic_globals);
        goto CPyL227;
    }
    cpy_r_r119 = PyObject_IsInstance(cpy_r_r115, cpy_r_r118);
    CPy_DECREF(cpy_r_r115);
    CPy_DECREF(cpy_r_r118);
    cpy_r_r120 = cpy_r_r119 >= 0;
    if (unlikely(!cpy_r_r120)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 200, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r121 = cpy_r_r119;
    if (!cpy_r_r121) goto CPyL100;
    cpy_r_r122 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded;
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "decoded", 201, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r122);
CPyL98: ;
    CPy_Raise(cpy_r_r122);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 201, CPyStatic_globals);
        goto CPyL104;
    } else
        goto CPyL228;
CPyL99: ;
    CPy_Unreachable();
CPyL100: ;
    cpy_r_r123 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_decoded;
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "decoded", 202, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r123);
CPyL101: ;
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ = -2;
    cpy_r_r124 = 1;
    if (unlikely(!cpy_r_r124)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 202, CPyStatic_globals);
        goto CPyL229;
    } else
        goto CPyL230;
CPyL102: ;
    CPyGen_SetStopIterationValue(cpy_r_r123);
    CPy_DECREF(cpy_r_r123);
    if (!0) goto CPyL194;
    CPy_Unreachable();
CPyL104: ;
    cpy_r_r125 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35.f2);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35 = cpy_r_r125;
    cpy_r_r126 = 1;
    if (unlikely(!cpy_r_r126)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r127 = CPyStatic_globals;
    cpy_r_r128 = CPyStatics[31]; /* 'InsufficientDataBytes' */
    cpy_r_r129 = CPyDict_GetItem(cpy_r_r127, cpy_r_r128);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 203, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r130 = CPy_ExceptionMatches(cpy_r_r129);
    CPy_DecRef(cpy_r_r129);
    if (cpy_r_r130) {
        goto CPyL232;
    } else
        goto CPyL124;
CPyL107: ;
    cpy_r_r131 = CPy_GetExcValue();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e = cpy_r_r131;
    cpy_r_r132 = 1;
    if (unlikely(!cpy_r_r132)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 203, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r133 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e;
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "e", 205, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_INCREF(cpy_r_r133);
CPyL109: ;
    cpy_r_r134 = CPyStatics[51]; /* 'args' */
    cpy_r_r135 = CPyObject_GetAttr(cpy_r_r133, cpy_r_r134);
    CPy_DecRef(cpy_r_r133);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r136 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 205, CPyStatic_globals);
        goto CPyL233;
    }
    CPy_INCREF(cpy_r_r136);
CPyL111: ;
    cpy_r_r137 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 205, CPyStatic_globals);
        goto CPyL234;
    }
    CPy_INCREF(cpy_r_r137);
CPyL112: ;
    cpy_r_r138 = CPyStatics[11]; /* '_address' */
    cpy_r_r139 = CPyObject_GetAttr(cpy_r_r137, cpy_r_r138);
    CPy_DecRef(cpy_r_r137);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL234;
    }
    cpy_r_r140 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 205, CPyStatic_globals);
        goto CPyL235;
    }
    CPy_INCREF(cpy_r_r140);
CPyL114: ;
    cpy_r_r141 = PyList_New(0);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL236;
    }
    cpy_r_r142 = CPyList_Extend(cpy_r_r141, cpy_r_r135);
    CPy_DecRef(cpy_r_r135);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL237;
    } else
        goto CPyL238;
CPyL116: ;
    cpy_r_r143 = PyList_Append(cpy_r_r141, cpy_r_r136);
    CPy_DecRef(cpy_r_r136);
    cpy_r_r144 = cpy_r_r143 >= 0;
    if (unlikely(!cpy_r_r144)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL239;
    }
    cpy_r_r145 = PyList_Append(cpy_r_r141, cpy_r_r139);
    CPy_DecRef(cpy_r_r139);
    cpy_r_r146 = cpy_r_r145 >= 0;
    if (unlikely(!cpy_r_r146)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL240;
    }
    cpy_r_r147 = PyList_Append(cpy_r_r141, cpy_r_r140);
    CPy_DecRef(cpy_r_r140);
    cpy_r_r148 = cpy_r_r147 >= 0;
    if (unlikely(!cpy_r_r148)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL241;
    }
    cpy_r_r149 = PyList_AsTuple(cpy_r_r141);
    CPy_DecRef(cpy_r_r141);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r150 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e;
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "e", 205, CPyStatic_globals);
        goto CPyL242;
    }
    CPy_INCREF(cpy_r_r150);
CPyL121: ;
    cpy_r_r151 = CPyStatics[51]; /* 'args' */
    cpy_r_r152 = PyObject_SetAttr(cpy_r_r150, cpy_r_r151, cpy_r_r149);
    CPy_DecRef(cpy_r_r150);
    CPy_DecRef(cpy_r_r149);
    cpy_r_r153 = cpy_r_r152 >= 0;
    if (unlikely(!cpy_r_r153)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 205, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_Reraise();
    if (!0) {
        goto CPyL186;
    } else
        goto CPyL243;
CPyL123: ;
    CPy_Unreachable();
CPyL124: ;
    cpy_r_r154 = CPyModule_builtins;
    cpy_r_r155 = CPyStatics[40]; /* 'AttributeError' */
    cpy_r_r156 = CPyObject_GetAttr(cpy_r_r154, cpy_r_r155);
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 207, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r157 = CPy_ExceptionMatches(cpy_r_r156);
    CPy_DecRef(cpy_r_r156);
    if (!cpy_r_r157) goto CPyL244;
    cpy_r_r158 = CPy_GetExcValue();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e = cpy_r_r158;
    cpy_r_r159 = 1;
    if (unlikely(!cpy_r_r159)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 207, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r160 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e;
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "e", 209, CPyStatic_globals);
        goto CPyL231;
    }
    CPy_INCREF(cpy_r_r160);
CPyL128: ;
    cpy_r_r161 = PyObject_Str(cpy_r_r160);
    CPy_DecRef(cpy_r_r160);
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 209, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r162 = CPyStatics[52]; /* " object has no attribute '_skip_decoder_proc_pool'" */
    cpy_r_r163 = CPyStr_Endswith(cpy_r_r161, cpy_r_r162);
    CPy_DecRef(cpy_r_r161);
    if (cpy_r_r163) {
        goto CPyL132;
    } else
        goto CPyL245;
CPyL130: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL186;
    } else
        goto CPyL246;
CPyL131: ;
    CPy_Unreachable();
CPyL132: ;
    cpy_r_r164 = CPyStatic_globals;
    cpy_r_r165 = CPyStatics[43]; /* 'logger' */
    cpy_r_r166 = CPyDict_GetItem(cpy_r_r164, cpy_r_r165);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 211, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r167 = CPyStatics[53]; /* 'DEBUG ME BRO: %s' */
    cpy_r_r168 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_e;
    if (unlikely(cpy_r_r168 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "e", 211, CPyStatic_globals);
        goto CPyL247;
    }
    CPy_INCREF(cpy_r_r168);
CPyL134: ;
    cpy_r_r169 = CPyStatics[54]; /* 'debug' */
    cpy_r_r170 = CPyObject_CallMethodObjArgs(cpy_r_r166, cpy_r_r169, cpy_r_r167, cpy_r_r168, NULL);
    CPy_DecRef(cpy_r_r166);
    CPy_DecRef(cpy_r_r168);
    if (unlikely(cpy_r_r170 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 211, CPyStatic_globals);
        goto CPyL231;
    } else
        goto CPyL248;
CPyL135: ;
    cpy_r_r171 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 212, CPyStatic_globals);
        goto CPyL231;
    }
    CPy_INCREF(cpy_r_r171);
CPyL136: ;
    cpy_r_r172 = CPyStatics[11]; /* '_address' */
    cpy_r_r173 = CPyObject_GetAttr(cpy_r_r171, cpy_r_r172);
    CPy_DecRef(cpy_r_r171);
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 212, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r174 = CPyStatic_globals;
    cpy_r_r175 = CPyStatics[12]; /* '_skip_proc_pool' */
    cpy_r_r176 = CPyDict_GetItem(cpy_r_r174, cpy_r_r175);
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 212, CPyStatic_globals);
        goto CPyL249;
    }
    if (likely(PySet_Check(cpy_r_r176)))
        cpy_r_r177 = cpy_r_r176;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "decode_output", 212, CPyStatic_globals, "set", cpy_r_r176);
        goto CPyL249;
    }
    cpy_r_r178 = PySet_Contains(cpy_r_r177, cpy_r_r173);
    CPy_DecRef(cpy_r_r177);
    CPy_DecRef(cpy_r_r173);
    cpy_r_r179 = cpy_r_r178 >= 0;
    if (unlikely(!cpy_r_r179)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 212, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r180 = cpy_r_r178;
    cpy_r_r181 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 212, CPyStatic_globals);
        goto CPyL231;
    }
    CPy_INCREF(cpy_r_r181);
CPyL141: ;
    cpy_r_r182 = CPyStatics[13]; /* '_skip_decoder_proc_pool' */
    cpy_r_r183 = cpy_r_r180 ? Py_True : Py_False;
    cpy_r_r184 = PyObject_SetAttr(cpy_r_r181, cpy_r_r182, cpy_r_r183);
    CPy_DecRef(cpy_r_r181);
    cpy_r_r185 = cpy_r_r184 >= 0;
    if (unlikely(!cpy_r_r185)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 212, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r186 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "call", 213, CPyStatic_globals);
        goto CPyL231;
    }
    CPy_INCREF(cpy_r_r186);
CPyL143: ;
    cpy_r_r187 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->_data;
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "data", 213, CPyStatic_globals);
        goto CPyL250;
    }
    CPy_INCREF(cpy_r_r187);
CPyL144: ;
    cpy_r_r188 = CPyDef_decode_output(cpy_r_r186, cpy_r_r187);
    CPy_DecRef(cpy_r_r186);
    CPy_DecRef(cpy_r_r187);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r189 = CPy_GetCoro(cpy_r_r188);
    CPy_DecRef(cpy_r_r188);
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL231;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36 = cpy_r_r189;
    cpy_r_r190 = 1;
    if (unlikely(!cpy_r_r190)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r191 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36;
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__36", -1, CPyStatic_globals);
        goto CPyL231;
    }
    CPy_INCREF(cpy_r_r191);
CPyL148: ;
    cpy_r_r192 = CPyIter_Next(cpy_r_r191);
    CPy_DecRef(cpy_r_r191);
    if (cpy_r_r192 == NULL) {
        goto CPyL251;
    } else
        goto CPyL151;
CPyL149: ;
    cpy_r_r193 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r194 = cpy_r_r193;
    goto CPyL180;
CPyL151: ;
    cpy_r_r195 = cpy_r_r192;
CPyL152: ;
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ = 4;
    cpy_r_r196 = 1;
    if (unlikely(!cpy_r_r196)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL252;
    } else
        goto CPyL253;
CPyL153: ;
    return cpy_r_r195;
CPyL154: ;
    cpy_r_r197 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r198 = cpy_r_type != cpy_r_r197;
    if (!cpy_r_r198) goto CPyL157;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL158;
    } else
        goto CPyL254;
CPyL156: ;
    CPy_Unreachable();
CPyL157: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL175;
CPyL158: ;
    cpy_r_r199 = CPy_CatchError();
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37.f0);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37.f1);
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37.f2);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37 = cpy_r_r199;
    cpy_r_r200 = 1;
    if (unlikely(!cpy_r_r200)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL255;
    }
    cpy_r_r201 = (PyObject **)&cpy_r_r3;
    cpy_r_r202 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36;
    if (unlikely(cpy_r_r202 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__36", -1, CPyStatic_globals);
        goto CPyL255;
    }
    CPy_INCREF(cpy_r_r202);
CPyL160: ;
    cpy_r_r203 = CPy_YieldFromErrorHandle(cpy_r_r202, cpy_r_r201);
    CPy_DecRef(cpy_r_r202);
    if (unlikely(cpy_r_r203 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL255;
    }
    if (cpy_r_r203) goto CPyL167;
    if (cpy_r_r3 != NULL) goto CPyL165;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r204 = 0;
    if (unlikely(!cpy_r_r204)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL172;
    } else
        goto CPyL256;
CPyL164: ;
    CPy_Unreachable();
CPyL165: ;
    CPy_INCREF(cpy_r_r3);
    cpy_r_r195 = cpy_r_r3;
    cpy_r_r205 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37;
    if (unlikely(cpy_r_r205.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__37", -1, CPyStatic_globals);
        goto CPyL257;
    }
    CPy_INCREF(cpy_r_r205.f0);
    CPy_INCREF(cpy_r_r205.f1);
    CPy_INCREF(cpy_r_r205.f2);
CPyL166: ;
    CPy_RestoreExcInfo(cpy_r_r205);
    CPy_DecRef(cpy_r_r205.f0);
    CPy_DecRef(cpy_r_r205.f1);
    CPy_DecRef(cpy_r_r205.f2);
    goto CPyL152;
CPyL167: ;
    if (cpy_r_r3 != NULL) goto CPyL170;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r206 = 0;
    if (unlikely(!cpy_r_r206)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL172;
    } else
        goto CPyL258;
CPyL169: ;
    CPy_Unreachable();
CPyL170: ;
    cpy_r_r194 = cpy_r_r3;
    cpy_r_r207 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37;
    if (unlikely(cpy_r_r207.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__37", -1, CPyStatic_globals);
        goto CPyL259;
    }
    CPy_INCREF(cpy_r_r207.f0);
    CPy_INCREF(cpy_r_r207.f1);
    CPy_INCREF(cpy_r_r207.f2);
CPyL171: ;
    CPy_RestoreExcInfo(cpy_r_r207);
    CPy_DecRef(cpy_r_r207.f0);
    CPy_DecRef(cpy_r_r207.f1);
    CPy_DecRef(cpy_r_r207.f2);
    goto CPyL180;
CPyL172: ;
    cpy_r_r208 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__37;
    if (unlikely(cpy_r_r208.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__37", -1, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_INCREF(cpy_r_r208.f0);
    CPy_INCREF(cpy_r_r208.f1);
    CPy_INCREF(cpy_r_r208.f2);
CPyL173: ;
    CPy_RestoreExcInfo(cpy_r_r208);
    CPy_DecRef(cpy_r_r208.f0);
    CPy_DecRef(cpy_r_r208.f1);
    CPy_DecRef(cpy_r_r208.f2);
    cpy_r_r209 = CPy_KeepPropagating();
    if (!cpy_r_r209) {
        goto CPyL186;
    } else
        goto CPyL260;
CPyL174: ;
    CPy_Unreachable();
CPyL175: ;
    cpy_r_r210 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__36;
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__36", -1, CPyStatic_globals);
        goto CPyL261;
    }
    CPy_INCREF(cpy_r_r210);
CPyL176: ;
    cpy_r_r211 = CPyIter_Send(cpy_r_r210, cpy_r_arg);
    CPy_DECREF(cpy_r_r210);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r211 == NULL) goto CPyL262;
    cpy_r_r195 = cpy_r_r211;
    goto CPyL152;
CPyL178: ;
    cpy_r_r212 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r194 = cpy_r_r212;
CPyL180: ;
    cpy_r_r213 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35;
    if (unlikely(cpy_r_r213.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "decode_output", "decode_output_env", "__mypyc_temp__35", -1, CPyStatic_globals);
        goto CPyL263;
    }
    CPy_INCREF(cpy_r_r213.f0);
    CPy_INCREF(cpy_r_r213.f1);
    CPy_INCREF(cpy_r_r213.f2);
CPyL181: ;
    CPy_RestoreExcInfo(cpy_r_r213);
    CPy_DECREF(cpy_r_r213.f0);
    CPy_DECREF(cpy_r_r213.f1);
    CPy_DECREF(cpy_r_r213.f2);
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_next_label__ = -2;
    cpy_r_r214 = 1;
    if (unlikely(!cpy_r_r214)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 213, CPyStatic_globals);
        goto CPyL263;
    } else
        goto CPyL264;
CPyL182: ;
    CPyGen_SetStopIterationValue(cpy_r_r194);
    CPy_DECREF(cpy_r_r194);
    if (!0) goto CPyL194;
    CPy_Unreachable();
CPyL184: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL186;
    } else
        goto CPyL265;
CPyL185: ;
    CPy_Unreachable();
CPyL186: ;
    cpy_r_r215 = ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r4)->___mypyc_temp__35;
    if (unlikely(cpy_r_r215.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__35' of 'decode_output_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r215.f0);
        CPy_INCREF(cpy_r_r215.f1);
        CPy_INCREF(cpy_r_r215.f2);
    }
    CPy_DecRef(cpy_r_r4);
    if (unlikely(cpy_r_r215.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", -1, CPyStatic_globals);
        goto CPyL194;
    }
CPyL187: ;
    CPy_RestoreExcInfo(cpy_r_r215);
    CPy_DecRef(cpy_r_r215.f0);
    CPy_DecRef(cpy_r_r215.f1);
    CPy_DecRef(cpy_r_r215.f2);
    cpy_r_r216 = CPy_KeepPropagating();
    if (!cpy_r_r216) goto CPyL194;
    CPy_Unreachable();
CPyL189: ;
    cpy_r_r217 = cpy_r_r5 == 0;
    if (cpy_r_r217) goto CPyL266;
    cpy_r_r218 = cpy_r_r5 == 2;
    if (cpy_r_r218) {
        goto CPyL267;
    } else
        goto CPyL268;
CPyL191: ;
    cpy_r_r219 = cpy_r_r5 == 4;
    CPyTagged_DECREF(cpy_r_r5);
    if (cpy_r_r219) {
        goto CPyL154;
    } else
        goto CPyL269;
CPyL192: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r220 = 0;
    if (unlikely(!cpy_r_r220)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
        goto CPyL194;
    }
    CPy_Unreachable();
CPyL194: ;
    cpy_r_r221 = NULL;
    return cpy_r_r221;
CPyL195: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    goto CPyL194;
CPyL196: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL194;
CPyL197: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL3;
CPyL198: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r10);
    goto CPyL194;
CPyL199: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r11);
    goto CPyL194;
CPyL200: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL104;
CPyL201: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL17;
CPyL202: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL104;
CPyL203: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL63;
CPyL204: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r32);
    goto CPyL63;
CPyL205: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_r33);
    goto CPyL63;
CPyL206: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL31;
CPyL207: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL40;
CPyL208: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL35;
CPyL209: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL38;
CPyL210: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL54;
CPyL211: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL46;
CPyL212: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r46);
    goto CPyL54;
CPyL213: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL51;
CPyL214: ;
    CPy_DecRef(cpy_r_r45);
    goto CPyL54;
CPyL215: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL56;
CPyL216: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_arg);
    goto CPyL63;
CPyL217: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL60;
CPyL218: ;
    CPy_DecRef(cpy_r_r73);
    goto CPyL90;
CPyL219: ;
    CPy_DecRef(cpy_r_r73);
    CPy_DecRef(cpy_r_r79);
    goto CPyL90;
CPyL220: ;
    CPy_DecRef(cpy_r_r73);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r80);
    goto CPyL90;
CPyL221: ;
    CPy_DecRef(cpy_r_r85);
    goto CPyL73;
CPyL222: ;
    CPy_DecRef(cpy_r_r92);
    goto CPyL90;
CPyL223: ;
    CPy_DecRef(cpy_r_r98);
    goto CPyL90;
CPyL224: ;
    CPy_DecRef(cpy_r_r105);
    goto CPyL90;
CPyL225: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL87;
CPyL226: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL92;
CPyL227: ;
    CPy_DecRef(cpy_r_r115);
    goto CPyL104;
CPyL228: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL99;
CPyL229: ;
    CPy_DecRef(cpy_r_r123);
    goto CPyL104;
CPyL230: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL102;
CPyL231: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL186;
CPyL232: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL107;
CPyL233: ;
    CPy_DecRef(cpy_r_r135);
    goto CPyL186;
CPyL234: ;
    CPy_DecRef(cpy_r_r135);
    CPy_DecRef(cpy_r_r136);
    goto CPyL186;
CPyL235: ;
    CPy_DecRef(cpy_r_r135);
    CPy_DecRef(cpy_r_r136);
    CPy_DecRef(cpy_r_r139);
    goto CPyL186;
CPyL236: ;
    CPy_DecRef(cpy_r_r135);
    CPy_DecRef(cpy_r_r136);
    CPy_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r140);
    goto CPyL186;
CPyL237: ;
    CPy_DecRef(cpy_r_r136);
    CPy_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r140);
    CPy_DecRef(cpy_r_r141);
    goto CPyL186;
CPyL238: ;
    CPy_DecRef(cpy_r_r142);
    goto CPyL116;
CPyL239: ;
    CPy_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r140);
    CPy_DecRef(cpy_r_r141);
    goto CPyL186;
CPyL240: ;
    CPy_DecRef(cpy_r_r140);
    CPy_DecRef(cpy_r_r141);
    goto CPyL186;
CPyL241: ;
    CPy_DecRef(cpy_r_r141);
    goto CPyL186;
CPyL242: ;
    CPy_DecRef(cpy_r_r149);
    goto CPyL186;
CPyL243: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL123;
CPyL244: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL184;
CPyL245: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL130;
CPyL246: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL131;
CPyL247: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r166);
    goto CPyL186;
CPyL248: ;
    CPy_DecRef(cpy_r_r170);
    goto CPyL135;
CPyL249: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r173);
    goto CPyL186;
CPyL250: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r186);
    goto CPyL186;
CPyL251: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL149;
CPyL252: ;
    CPy_DecRef(cpy_r_r195);
    goto CPyL158;
CPyL253: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL153;
CPyL254: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL156;
CPyL255: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL172;
CPyL256: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL164;
CPyL257: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r195);
    goto CPyL172;
CPyL258: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL169;
CPyL259: ;
    CPy_DecRef(cpy_r_r194);
    goto CPyL172;
CPyL260: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL174;
CPyL261: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_arg);
    goto CPyL186;
CPyL262: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL178;
CPyL263: ;
    CPy_DecRef(cpy_r_r194);
    goto CPyL186;
CPyL264: ;
    CPy_DECREF(cpy_r_r4);
    goto CPyL182;
CPyL265: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL185;
CPyL266: ;
    CPyTagged_DECREF(cpy_r_r5);
    goto CPyL2;
CPyL267: ;
    CPyTagged_DECREF(cpy_r_r5);
    goto CPyL36;
CPyL268: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL191;
CPyL269: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL192;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
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
    cpy_r_r1 = CPyStatics[33]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_decode_output_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[34]; /* 'StopIteration' */
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
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_call);
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_call != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_call);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_call = cpy_r_call;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_data);
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_data != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_data);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->_data = cpy_r_data;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r3 = CPyDef_decode_output_gen();
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___brownie_patch___call___decode_output_genObject *)cpy_r_r3)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call___decode_output_genObject *)cpy_r_r3)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call___decode_output_genObject *)cpy_r_r3)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
        goto CPyL9;
    }
    if (((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call___decode_output_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r5 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "decode_output", 184, CPyStatic_globals);
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
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_request_data_no_args", "_request_data_no_args_gen", "__mypyc_env__", 216, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_request_data_no_args", "_request_data_no_args_env", "__mypyc_next_label__", 216, CPyStatic_globals);
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
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r4 = ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->_call;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_request_data_no_args", "_request_data_no_args_env", "call", 217, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_INCREF(cpy_r_r4);
CPyL6: ;
    cpy_r_r5 = CPyStatics[7]; /* 'signature' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 217, CPyStatic_globals);
        goto CPyL14;
    }
    if (((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__ = -2;
    cpy_r_r7 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 217, CPyStatic_globals);
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
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
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
    cpy_r_r1 = CPyStatics[33]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef__request_data_no_args_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[34]; /* 'StopIteration' */
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
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_call);
    if (((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->_call != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->_call);
    }
    ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->_call = cpy_r_call;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r2 = CPyDef__request_data_no_args_gen();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___brownie_patch___call____request_data_no_args_genObject *)cpy_r_r2)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____request_data_no_args_genObject *)cpy_r_r2)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call____request_data_no_args_genObject *)cpy_r_r2)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
        goto CPyL8;
    }
    if (((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___call____request_data_no_args_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r4 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_request_data_no_args", 216, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___encode_input(PyObject *cpy_r_abi, PyObject *cpy_r_signature, PyObject *cpy_r_args) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    tuple_T3OOO cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    CPy_INCREF(cpy_r_args);
    if (PyList_Check(cpy_r_args))
        cpy_r_r0 = cpy_r_args;
    else {
        cpy_r_r0 = NULL;
    }
    if (cpy_r_r0 != NULL) goto __LL18;
    if (unlikely(!(PyTuple_Check(cpy_r_args) && PyTuple_GET_SIZE(cpy_r_args) == 1))) {
        cpy_r_r0 = NULL;
        goto __LL19;
    }
    cpy_r_r0 = PyTuple_GET_ITEM(cpy_r_args, 0);
    if (cpy_r_r0 == NULL) goto __LL19;
    cpy_r_r0 = cpy_r_args;
__LL19: ;
    if (cpy_r_r0 != NULL) goto __LL18;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 227, CPyStatic_globals, "union[list, tuple[object]]", cpy_r_args);
    goto CPyL11;
__LL18: ;
    cpy_r_r1 = CPyDef_format_input_but_cache_checksums(cpy_r_abi, cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 227, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r2 = CPyStatics[14]; /* 'inputs' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_abi, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 228, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r4 = CPyStatic_globals;
    cpy_r_r5 = CPyStatics[55]; /* 'get_type_strings' */
    cpy_r_r6 = CPyDict_GetItem(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 228, CPyStatic_globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r7[1] = {cpy_r_r3};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 1, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 228, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_DECREF(cpy_r_r3);
    cpy_r_r10 = CPyStatic_globals;
    cpy_r_r11 = CPyStatics[56]; /* '__eth_abi_encode' */
    cpy_r_r12 = CPyDict_GetItem(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 229, CPyStatic_globals);
        goto CPyL21;
    }
    PyObject *cpy_r_r13[2] = {cpy_r_r9, cpy_r_r1};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 2, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 229, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r1);
    cpy_r_r16 = CPyStatics[57]; /* 'hex' */
    cpy_r_r17 = CPyObject_CallMethodObjArgs(cpy_r_r15, cpy_r_r16, NULL);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 229, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r18 = PyNumber_Add(cpy_r_signature, cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 229, CPyStatic_globals);
        goto CPyL11;
    }
    return cpy_r_r18;
CPyL11: ;
    cpy_r_r19 = CPy_CatchError();
    cpy_r_r20 = CPyModule_builtins;
    cpy_r_r21 = CPyStatics[49]; /* 'Exception' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 230, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r23 = CPy_ExceptionMatches(cpy_r_r22);
    CPy_DecRef(cpy_r_r22);
    if (!cpy_r_r23) goto CPyL14;
    cpy_r_r24 = CPy_GetExcValue();
    CPy_RestoreExcInfo(cpy_r_r19);
    CPy_DecRef(cpy_r_r19.f0);
    CPy_DecRef(cpy_r_r19.f1);
    CPy_DecRef(cpy_r_r19.f2);
    return cpy_r_r24;
CPyL14: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL16;
    } else
        goto CPyL22;
CPyL15: ;
    CPy_Unreachable();
CPyL16: ;
    CPy_RestoreExcInfo(cpy_r_r19);
    CPy_DecRef(cpy_r_r19.f0);
    CPy_DecRef(cpy_r_r19.f1);
    CPy_DecRef(cpy_r_r19.f2);
    cpy_r_r25 = CPy_KeepPropagating();
    if (!cpy_r_r25) goto CPyL18;
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r26 = NULL;
    return cpy_r_r26;
CPyL19: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL11;
CPyL20: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    goto CPyL11;
CPyL21: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r9);
    goto CPyL11;
CPyL22: ;
    CPy_DecRef(cpy_r_r19.f0);
    CPy_DecRef(cpy_r_r19.f1);
    CPy_DecRef(cpy_r_r19.f2);
    goto CPyL15;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__encode_input", 225, CPyStatic_globals);
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
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_result;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    CPyTagged cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    tuple_T3OOO cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    cpy_r_r0 = CPyStatics[58]; /* 'outputs' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_abi, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 249, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[55]; /* 'get_type_strings' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 249, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r5[1] = {cpy_r_r1};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 249, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r1);
    cpy_r_r8 = CPyStatic_globals;
    cpy_r_r9 = CPyStatics[59]; /* 'HexBytes' */
    cpy_r_r10 = CPyDict_GetItem(cpy_r_r8, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 250, CPyStatic_globals);
        goto CPyL24;
    }
    PyObject *cpy_r_r11[1] = {cpy_r_hexstr};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = _PyObject_Vectorcall(cpy_r_r10, cpy_r_r12, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 250, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r14 = CPyStatic_globals;
    cpy_r_r15 = CPyStatics[60]; /* '__eth_abi_decode' */
    cpy_r_r16 = CPyDict_GetItem(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 250, CPyStatic_globals);
        goto CPyL25;
    }
    PyObject *cpy_r_r17[2] = {cpy_r_r7, cpy_r_r13};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = _PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 2, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 250, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r13);
    cpy_r_result = cpy_r_r19;
    if (PyList_Check(cpy_r_result))
        cpy_r_r20 = cpy_r_result;
    else {
        cpy_r_r20 = NULL;
    }
    if (cpy_r_r20 != NULL) goto __LL20;
    if (unlikely(!(PyTuple_Check(cpy_r_result) && PyTuple_GET_SIZE(cpy_r_result) == 1))) {
        cpy_r_r20 = NULL;
        goto __LL21;
    }
    cpy_r_r20 = PyTuple_GET_ITEM(cpy_r_result, 0);
    if (cpy_r_r20 == NULL) goto __LL21;
    cpy_r_r20 = cpy_r_result;
__LL21: ;
    if (cpy_r_r20 != NULL) goto __LL20;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 251, CPyStatic_globals, "union[list, tuple[object]]", cpy_r_result);
    goto CPyL15;
__LL20: ;
    cpy_r_r21 = CPyDef_format_output_but_cache_checksums(cpy_r_abi, cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 251, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_result = cpy_r_r21;
    cpy_r_r22 = CPyObject_Size(cpy_r_result);
    if (unlikely(cpy_r_r22 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 252, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r23 = cpy_r_r22 == 2;
    CPyTagged_DECREF(cpy_r_r22);
    if (!cpy_r_r23) goto CPyL14;
    cpy_r_r24 = CPyStatics[190]; /* 0 */
    cpy_r_r25 = PyObject_GetItem(cpy_r_result, cpy_r_r24);
    CPy_DECREF(cpy_r_result);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 253, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_result = cpy_r_r25;
CPyL14: ;
    return cpy_r_result;
CPyL15: ;
    cpy_r_r26 = CPy_CatchError();
    cpy_r_r27 = CPyModule_builtins;
    cpy_r_r28 = CPyStatics[49]; /* 'Exception' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_r27, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 255, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r30 = CPy_ExceptionMatches(cpy_r_r29);
    CPy_DecRef(cpy_r_r29);
    if (!cpy_r_r30) goto CPyL18;
    cpy_r_r31 = CPy_GetExcValue();
    CPy_RestoreExcInfo(cpy_r_r26);
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    return cpy_r_r31;
CPyL18: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL20;
    } else
        goto CPyL27;
CPyL19: ;
    CPy_Unreachable();
CPyL20: ;
    CPy_RestoreExcInfo(cpy_r_r26);
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    cpy_r_r32 = CPy_KeepPropagating();
    if (!cpy_r_r32) goto CPyL22;
    CPy_Unreachable();
CPyL22: ;
    cpy_r_r33 = NULL;
    return cpy_r_r33;
CPyL23: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL15;
CPyL24: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL15;
CPyL25: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r13);
    goto CPyL15;
CPyL26: ;
    CPy_DecRef(cpy_r_result);
    goto CPyL15;
CPyL27: ;
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    goto CPyL19;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__decode_output", 247, CPyStatic_globals);
    return NULL;
}

char CPyDef___validate_output(PyObject *cpy_r_abi, PyObject *cpy_r_hexstr) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
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
    int32_t cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    CPyPtr cpy_r_r23;
    CPyPtr cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
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
    PyObject *cpy_r_revert_str;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    int32_t cpy_r_r51;
    char cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject **cpy_r_r58;
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
    PyObject **cpy_r_r70;
    PyObject *cpy_r_r71;
    CPyTagged cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    int32_t cpy_r_r77;
    char cpy_r_r78;
    char cpy_r_r79;
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
    PyObject **cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    int32_t cpy_r_r100;
    char cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
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
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject **cpy_r_r123;
    PyObject *cpy_r_r124;
    tuple_T3OOO cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    char cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject **cpy_r_r135;
    PyObject *cpy_r_r136;
    tuple_T3OOO cpy_r_r137;
    char cpy_r_r138;
    char cpy_r_r139;
    char cpy_r_r140;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[59]; /* 'HexBytes' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 261, CPyStatic_globals);
        goto CPyL64;
    }
    PyObject *cpy_r_r3[1] = {cpy_r_hexstr};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 1, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 261, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r6 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r7 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r8 = CPyStatics[191]; /* 4 */
    cpy_r_r9 = PySlice_New(cpy_r_r6, cpy_r_r8, cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 261, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r10 = PyObject_GetItem(cpy_r_r5, cpy_r_r9);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 261, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r11 = CPyStatics[57]; /* 'hex' */
    cpy_r_r12 = CPyObject_CallMethodObjArgs(cpy_r_r10, cpy_r_r11, NULL);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 261, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r13 = CPyStatics[61]; /* '0x08c379a0' */
    cpy_r_r14 = PyObject_RichCompare(cpy_r_r12, cpy_r_r13, 2);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 262, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r15 = PyObject_IsTrue(cpy_r_r14);
    CPy_DECREF(cpy_r_r14);
    cpy_r_r16 = cpy_r_r15 >= 0;
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 262, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r17 = cpy_r_r15;
    if (cpy_r_r17) {
        goto CPyL83;
    } else
        goto CPyL23;
CPyL9: ;
    cpy_r_r18 = CPyStatic_globals;
    cpy_r_r19 = CPyStatics[62]; /* 'eth_abi' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 263, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r21 = CPyStatics[63]; /* 'string' */
    cpy_r_r22 = PyList_New(1);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 263, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r23 = (CPyPtr)&((PyListObject *)cpy_r_r22)->ob_item;
    cpy_r_r24 = *(CPyPtr *)cpy_r_r23;
    CPy_INCREF(cpy_r_r21);
    *(PyObject * *)cpy_r_r24 = cpy_r_r21;
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyStatics[59]; /* 'HexBytes' */
    cpy_r_r27 = CPyDict_GetItem(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 263, CPyStatic_globals);
        goto CPyL85;
    }
    PyObject *cpy_r_r28[1] = {cpy_r_hexstr};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 1, 0);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 263, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r31 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r32 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r33 = CPyStatics[191]; /* 4 */
    cpy_r_r34 = PySlice_New(cpy_r_r33, cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 263, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r35 = PyObject_GetItem(cpy_r_r30, cpy_r_r34);
    CPy_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 263, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r36 = CPyStatics[64]; /* 'decode_abi' */
    cpy_r_r37 = CPyObject_CallMethodObjArgs(cpy_r_r20, cpy_r_r36, cpy_r_r22, cpy_r_r35, NULL);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 263, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r38 = CPyStatics[190]; /* 0 */
    cpy_r_r39 = PyObject_GetItem(cpy_r_r37, cpy_r_r38);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 263, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_revert_str = cpy_r_r39;
    cpy_r_r40 = CPyStatics[65]; /* 'Call reverted: ' */
    cpy_r_r41 = PyObject_Str(cpy_r_revert_str);
    CPy_DECREF(cpy_r_revert_str);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 264, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r42 = CPyStr_Build(2, cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 264, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r43 = CPyStatic_globals;
    cpy_r_r44 = CPyStatics[66]; /* 'Revert' */
    cpy_r_r45 = CPyDict_GetItem(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 264, CPyStatic_globals);
        goto CPyL87;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 264, CPyStatic_globals);
        goto CPyL87;
    }
    CPy_DECREF(cpy_r_r42);
    CPy_Raise(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 264, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL23: ;
    cpy_r_r49 = CPyStatics[67]; /* '0x4e487b71' */
    cpy_r_r50 = PyObject_RichCompare(cpy_r_r12, cpy_r_r49, 2);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 265, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r51 = PyObject_IsTrue(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    cpy_r_r52 = cpy_r_r51 >= 0;
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 265, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r53 = cpy_r_r51;
    if (cpy_r_r53) {
        goto CPyL88;
    } else
        goto CPyL48;
CPyL26: ;
    cpy_r_r54 = CPyStatic_globals;
    cpy_r_r55 = CPyStatics[59]; /* 'HexBytes' */
    cpy_r_r56 = CPyDict_GetItem(cpy_r_r54, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 266, CPyStatic_globals);
        goto CPyL64;
    }
    PyObject *cpy_r_r57[1] = {cpy_r_hexstr};
    cpy_r_r58 = (PyObject **)&cpy_r_r57;
    cpy_r_r59 = _PyObject_Vectorcall(cpy_r_r56, cpy_r_r58, 1, 0);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 266, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r60 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r61 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r62 = CPyStatics[191]; /* 4 */
    cpy_r_r63 = PySlice_New(cpy_r_r62, cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 266, CPyStatic_globals);
        goto CPyL89;
    }
    cpy_r_r64 = PyObject_GetItem(cpy_r_r59, cpy_r_r63);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 266, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r65 = CPyStatics[57]; /* 'hex' */
    cpy_r_r66 = CPyObject_CallMethodObjArgs(cpy_r_r64, cpy_r_r65, NULL);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 266, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r67 = (PyObject *)&PyLong_Type;
    cpy_r_r68 = CPyStatics[192]; /* 16 */
    PyObject *cpy_r_r69[2] = {cpy_r_r66, cpy_r_r68};
    cpy_r_r70 = (PyObject **)&cpy_r_r69;
    cpy_r_r71 = _PyObject_Vectorcall(cpy_r_r67, cpy_r_r70, 2, 0);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 266, CPyStatic_globals);
        goto CPyL90;
    }
    CPy_DECREF(cpy_r_r66);
    if (likely(PyLong_Check(cpy_r_r71)))
        cpy_r_r72 = CPyTagged_FromObject(cpy_r_r71);
    else {
        CPy_TypeError("int", cpy_r_r71); cpy_r_r72 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 266, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r73 = CPyStatic_globals;
    cpy_r_r74 = CPyStatics[68]; /* 'SOLIDITY_ERROR_CODES' */
    cpy_r_r75 = CPyDict_GetItem(cpy_r_r73, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 267, CPyStatic_globals);
        goto CPyL91;
    }
    CPyTagged_INCREF(cpy_r_r72);
    cpy_r_r76 = CPyTagged_StealAsObject(cpy_r_r72);
    cpy_r_r77 = PySequence_Contains(cpy_r_r75, cpy_r_r76);
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r76);
    cpy_r_r78 = cpy_r_r77 >= 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 267, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r79 = cpy_r_r77;
    if (!cpy_r_r79) goto CPyL39;
    cpy_r_r80 = CPyStatic_globals;
    cpy_r_r81 = CPyStatics[68]; /* 'SOLIDITY_ERROR_CODES' */
    cpy_r_r82 = CPyDict_GetItem(cpy_r_r80, cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 268, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r83 = CPyTagged_StealAsObject(cpy_r_r72);
    cpy_r_r84 = PyObject_GetItem(cpy_r_r82, cpy_r_r83);
    CPy_DECREF(cpy_r_r82);
    CPy_DECREF(cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 268, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_revert_str = cpy_r_r84;
    goto CPyL42;
CPyL39: ;
    cpy_r_r85 = CPyStatics[69]; /* 'Panic (error code: ' */
    cpy_r_r86 = CPyTagged_Str(cpy_r_r72);
    CPyTagged_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 270, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r87 = CPyStatics[70]; /* ')' */
    cpy_r_r88 = CPyStr_Build(3, cpy_r_r85, cpy_r_r86, cpy_r_r87);
    CPy_DECREF(cpy_r_r86);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 270, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_revert_str = cpy_r_r88;
CPyL42: ;
    cpy_r_r89 = CPyStatics[65]; /* 'Call reverted: ' */
    cpy_r_r90 = PyObject_Str(cpy_r_revert_str);
    CPy_DECREF(cpy_r_revert_str);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 271, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r91 = CPyStr_Build(2, cpy_r_r89, cpy_r_r90);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 271, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r92 = CPyStatic_globals;
    cpy_r_r93 = CPyStatics[66]; /* 'Revert' */
    cpy_r_r94 = CPyDict_GetItem(cpy_r_r92, cpy_r_r93);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 271, CPyStatic_globals);
        goto CPyL92;
    }
    PyObject *cpy_r_r95[1] = {cpy_r_r91};
    cpy_r_r96 = (PyObject **)&cpy_r_r95;
    cpy_r_r97 = _PyObject_Vectorcall(cpy_r_r94, cpy_r_r96, 1, 0);
    CPy_DECREF(cpy_r_r94);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 271, CPyStatic_globals);
        goto CPyL92;
    }
    CPy_DECREF(cpy_r_r91);
    CPy_Raise(cpy_r_r97);
    CPy_DECREF(cpy_r_r97);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 271, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL48: ;
    cpy_r_r98 = CPyStatics[71]; /* '0xc1b84b2f' */
    cpy_r_r99 = PyObject_RichCompare(cpy_r_r12, cpy_r_r98, 2);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 272, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r100 = PyObject_IsTrue(cpy_r_r99);
    CPy_DECREF(cpy_r_r99);
    cpy_r_r101 = cpy_r_r100 >= 0;
    if (unlikely(!cpy_r_r101)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 272, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r102 = cpy_r_r100;
    if (!cpy_r_r102) goto CPyL55;
    cpy_r_r103 = CPyStatics[72]; /* 'Call reverted: execution reverted' */
    cpy_r_r104 = CPyStatic_globals;
    cpy_r_r105 = CPyStatics[66]; /* 'Revert' */
    cpy_r_r106 = CPyDict_GetItem(cpy_r_r104, cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 273, CPyStatic_globals);
        goto CPyL64;
    }
    PyObject *cpy_r_r107[1] = {cpy_r_r103};
    cpy_r_r108 = (PyObject **)&cpy_r_r107;
    cpy_r_r109 = _PyObject_Vectorcall(cpy_r_r106, cpy_r_r108, 1, 0);
    CPy_DECREF(cpy_r_r106);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 273, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Raise(cpy_r_r109);
    CPy_DECREF(cpy_r_r109);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 273, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL55: ;
    cpy_r_r110 = CPyStatics[58]; /* 'outputs' */
    cpy_r_r111 = CPyDict_GetItem(cpy_r_abi, cpy_r_r110);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 274, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r112 = PyObject_IsTrue(cpy_r_r111);
    CPy_DECREF(cpy_r_r111);
    cpy_r_r113 = cpy_r_r112 >= 0;
    if (unlikely(!cpy_r_r113)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 274, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r114 = cpy_r_r112;
    if (!cpy_r_r114) goto CPyL79;
    cpy_r_r115 = PyObject_IsTrue(cpy_r_hexstr);
    cpy_r_r116 = cpy_r_r115 >= 0;
    if (unlikely(!cpy_r_r116)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 259, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r117 = cpy_r_r115;
    if (cpy_r_r117) goto CPyL79;
    cpy_r_r118 = CPyStatics[73]; /* 'No data was returned - the call likely reverted' */
    cpy_r_r119 = CPyStatic_globals;
    cpy_r_r120 = CPyStatics[66]; /* 'Revert' */
    cpy_r_r121 = CPyDict_GetItem(cpy_r_r119, cpy_r_r120);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 275, CPyStatic_globals);
        goto CPyL64;
    }
    PyObject *cpy_r_r122[1] = {cpy_r_r118};
    cpy_r_r123 = (PyObject **)&cpy_r_r122;
    cpy_r_r124 = _PyObject_Vectorcall(cpy_r_r121, cpy_r_r123, 1, 0);
    CPy_DECREF(cpy_r_r121);
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 275, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Raise(cpy_r_r124);
    CPy_DECREF(cpy_r_r124);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 275, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL64: ;
    cpy_r_r125 = CPy_CatchError();
    cpy_r_r126 = CPyModule_builtins;
    cpy_r_r127 = CPyStatics[21]; /* 'ValueError' */
    cpy_r_r128 = CPyObject_GetAttr(cpy_r_r126, cpy_r_r127);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 276, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r129 = CPy_ExceptionMatches(cpy_r_r128);
    CPy_DecRef(cpy_r_r128);
    if (!cpy_r_r129) goto CPyL75;
    cpy_r_r130 = CPy_GetExcValue();
    cpy_r_r131 = CPyStatic_globals;
    cpy_r_r132 = CPyStatics[74]; /* 'VirtualMachineError' */
    cpy_r_r133 = CPyDict_GetItem(cpy_r_r131, cpy_r_r132);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 278, CPyStatic_globals);
        goto CPyL71;
    }
    PyObject *cpy_r_r134[1] = {cpy_r_r130};
    cpy_r_r135 = (PyObject **)&cpy_r_r134;
    cpy_r_r136 = _PyObject_Vectorcall(cpy_r_r133, cpy_r_r135, 1, 0);
    CPy_DecRef(cpy_r_r133);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 278, CPyStatic_globals);
        goto CPyL71;
    }
    CPy_Raise(cpy_r_r136);
    CPy_DecRef(cpy_r_r136);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 278, CPyStatic_globals);
        goto CPyL71;
    } else
        goto CPyL93;
CPyL70: ;
    CPy_Unreachable();
CPyL71: ;
    cpy_r_r137 = CPy_CatchError();
    CPy_Raise(cpy_r_r130);
    CPy_DecRef(cpy_r_r130);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 280, CPyStatic_globals);
        goto CPyL73;
    } else
        goto CPyL94;
CPyL72: ;
    CPy_Unreachable();
CPyL73: ;
    CPy_RestoreExcInfo(cpy_r_r137);
    CPy_DecRef(cpy_r_r137.f0);
    CPy_DecRef(cpy_r_r137.f1);
    CPy_DecRef(cpy_r_r137.f2);
    cpy_r_r138 = CPy_KeepPropagating();
    if (!cpy_r_r138) {
        goto CPyL77;
    } else
        goto CPyL95;
CPyL74: ;
    CPy_Unreachable();
CPyL75: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL77;
    } else
        goto CPyL96;
CPyL76: ;
    CPy_Unreachable();
CPyL77: ;
    CPy_RestoreExcInfo(cpy_r_r125);
    CPy_DecRef(cpy_r_r125.f0);
    CPy_DecRef(cpy_r_r125.f1);
    CPy_DecRef(cpy_r_r125.f2);
    cpy_r_r139 = CPy_KeepPropagating();
    if (!cpy_r_r139) goto CPyL80;
    CPy_Unreachable();
CPyL79: ;
    return 1;
CPyL80: ;
    cpy_r_r140 = 2;
    return cpy_r_r140;
CPyL81: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL64;
CPyL82: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL64;
CPyL83: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL9;
CPyL84: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL64;
CPyL85: ;
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r22);
    goto CPyL64;
CPyL86: ;
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r30);
    goto CPyL64;
CPyL87: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL64;
CPyL88: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL26;
CPyL89: ;
    CPy_DecRef(cpy_r_r59);
    goto CPyL64;
CPyL90: ;
    CPy_DecRef(cpy_r_r66);
    goto CPyL64;
CPyL91: ;
    CPyTagged_DecRef(cpy_r_r72);
    goto CPyL64;
CPyL92: ;
    CPy_DecRef(cpy_r_r91);
    goto CPyL64;
CPyL93: ;
    CPy_DecRef(cpy_r_r125.f0);
    CPy_DecRef(cpy_r_r125.f1);
    CPy_DecRef(cpy_r_r125.f2);
    CPy_DecRef(cpy_r_r130);
    goto CPyL70;
CPyL94: ;
    CPy_DecRef(cpy_r_r125.f0);
    CPy_DecRef(cpy_r_r125.f1);
    CPy_DecRef(cpy_r_r125.f2);
    CPy_DecRef(cpy_r_r137.f0);
    CPy_DecRef(cpy_r_r137.f1);
    CPy_DecRef(cpy_r_r137.f2);
    goto CPyL72;
CPyL95: ;
    CPy_DecRef(cpy_r_r125.f0);
    CPy_DecRef(cpy_r_r125.f1);
    CPy_DecRef(cpy_r_r125.f2);
    goto CPyL74;
CPyL96: ;
    CPy_DecRef(cpy_r_r125.f0);
    CPy_DecRef(cpy_r_r125.f1);
    CPy_DecRef(cpy_r_r125.f2);
    goto CPyL76;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__validate_output", 259, CPyStatic_globals);
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
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject **cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    tuple_T3OOO cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    cpy_r_r0 = CPyObject_Size(cpy_r_inputs);
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 288, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r1 = cpy_r_r0 != 0;
    CPyTagged_DECREF(cpy_r_r0);
    if (!cpy_r_r1) goto CPyL12;
    cpy_r_r2 = CPyStatics[14]; /* 'inputs' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_abi, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 288, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r4 = CPyObject_Size(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 288, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r5 = cpy_r_r4 != 0;
    CPyTagged_DECREF(cpy_r_r4);
    if (cpy_r_r5) goto CPyL12;
    cpy_r_r6 = CPyStatics[75]; /* 'name' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_abi, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 289, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r8 = PyObject_Str(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 289, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r9 = CPyStatics[76]; /* ' requires no arguments' */
    cpy_r_r10 = CPyStr_Build(2, cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 289, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r11 = CPyModule_builtins;
    cpy_r_r12 = CPyStatics[41]; /* 'TypeError' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 289, CPyStatic_globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r14[1] = {cpy_r_r10};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = _PyObject_Vectorcall(cpy_r_r13, cpy_r_r15, 1, 0);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 289, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_Raise(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 289, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r17 = CPyStatics[14]; /* 'inputs' */
    cpy_r_r18 = CPyDict_GetItem(cpy_r_abi, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 290, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyStatics[77]; /* '_get_abi_types' */
    cpy_r_r21 = CPyDict_GetItem(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 290, CPyStatic_globals);
        goto CPyL33;
    }
    PyObject *cpy_r_r22[1] = {cpy_r_r18};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = _PyObject_Vectorcall(cpy_r_r21, cpy_r_r23, 1, 0);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 290, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_DECREF(cpy_r_r18);
    cpy_r_r25 = CPyDef__format_tuple_but_cache_checksums(cpy_r_r24, cpy_r_inputs);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 292, CPyStatic_globals);
        goto CPyL18;
    }
    return cpy_r_r25;
CPyL18: ;
    cpy_r_r26 = CPy_CatchError();
    cpy_r_r27 = CPyModule_builtins;
    cpy_r_r28 = CPyStatics[49]; /* 'Exception' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_r27, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 293, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r30 = CPy_ExceptionMatches(cpy_r_r29);
    CPy_DecRef(cpy_r_r29);
    if (!cpy_r_r30) goto CPyL27;
    cpy_r_r31 = CPy_GetExcValue();
    cpy_r_r32 = PyObject_Type(cpy_r_r31);
    cpy_r_r33 = CPyStatics[75]; /* 'name' */
    cpy_r_r34 = CPyDict_GetItem(cpy_r_abi, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 294, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r35 = PyObject_Str(cpy_r_r34);
    CPy_DecRef(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 294, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r36 = CPyStatics[78]; /* ' ' */
    cpy_r_r37 = PyObject_Str(cpy_r_r31);
    CPy_DecRef(cpy_r_r31);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 294, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r38 = CPyStr_Build(3, cpy_r_r35, cpy_r_r36, cpy_r_r37);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 294, CPyStatic_globals);
        goto CPyL36;
    }
    PyObject *cpy_r_r39[1] = {cpy_r_r38};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = _PyObject_Vectorcall(cpy_r_r32, cpy_r_r40, 1, 0);
    CPy_DecRef(cpy_r_r32);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 294, CPyStatic_globals);
        goto CPyL37;
    }
    CPy_DecRef(cpy_r_r38);
    CPy_Raise(cpy_r_r41);
    CPy_DecRef(cpy_r_r41);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 294, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL38;
CPyL26: ;
    CPy_Unreachable();
CPyL27: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL29;
    } else
        goto CPyL39;
CPyL28: ;
    CPy_Unreachable();
CPyL29: ;
    CPy_RestoreExcInfo(cpy_r_r26);
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    cpy_r_r42 = CPy_KeepPropagating();
    if (!cpy_r_r42) goto CPyL31;
    CPy_Unreachable();
CPyL31: ;
    cpy_r_r43 = NULL;
    return cpy_r_r43;
CPyL32: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL31;
CPyL33: ;
    CPy_DecRef(cpy_r_r18);
    goto CPyL31;
CPyL34: ;
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r32);
    goto CPyL29;
CPyL35: ;
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_r35);
    goto CPyL29;
CPyL36: ;
    CPy_DecRef(cpy_r_r32);
    goto CPyL29;
CPyL37: ;
    CPy_DecRef(cpy_r_r38);
    goto CPyL29;
CPyL38: ;
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    goto CPyL26;
CPyL39: ;
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    goto CPyL28;
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
    if (unlikely(!(PyTuple_Check(obj_inputs) && PyTuple_GET_SIZE(obj_inputs) == 1))) {
        arg_inputs = NULL;
        goto __LL23;
    }
    arg_inputs = PyTuple_GET_ITEM(obj_inputs, 0);
    if (arg_inputs == NULL) goto __LL23;
    arg_inputs = obj_inputs;
__LL23: ;
    if (arg_inputs != NULL) goto __LL22;
    CPy_TypeError("union[list, tuple[object]]", obj_inputs); 
    goto fail;
__LL22: ;
    PyObject *retval = CPyDef_format_input_but_cache_checksums(arg_abi, arg_inputs);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_input_but_cache_checksums", 286, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_format_output_but_cache_checksums(PyObject *cpy_r_abi, PyObject *cpy_r_outputs) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
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
    cpy_r_r0 = CPyStatics[58]; /* 'outputs' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_abi, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 299, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[77]; /* '_get_abi_types' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 299, CPyStatic_globals);
        goto CPyL9;
    }
    PyObject *cpy_r_r5[1] = {cpy_r_r1};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 299, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_DECREF(cpy_r_r1);
    cpy_r_r8 = CPyDef__format_tuple_but_cache_checksums(cpy_r_r7, cpy_r_outputs);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 300, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r9 = CPyStatics[58]; /* 'outputs' */
    cpy_r_r10 = CPyDict_GetItem(cpy_r_abi, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 301, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[79]; /* 'ReturnValue' */
    cpy_r_r13 = CPyDict_GetItem(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 301, CPyStatic_globals);
        goto CPyL11;
    }
    PyObject *cpy_r_r14[2] = {cpy_r_r8, cpy_r_r10};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = _PyObject_Vectorcall(cpy_r_r13, cpy_r_r15, 2, 0);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 301, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r10);
    return cpy_r_r16;
CPyL8: ;
    cpy_r_r17 = NULL;
    return cpy_r_r17;
CPyL9: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL8;
CPyL11: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    goto CPyL8;
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
    if (arg_outputs != NULL) goto __LL24;
    if (unlikely(!(PyTuple_Check(obj_outputs) && PyTuple_GET_SIZE(obj_outputs) == 1))) {
        arg_outputs = NULL;
        goto __LL25;
    }
    arg_outputs = PyTuple_GET_ITEM(obj_outputs, 0);
    if (arg_outputs == NULL) goto __LL25;
    arg_outputs = obj_outputs;
__LL25: ;
    if (arg_outputs != NULL) goto __LL24;
    CPy_TypeError("union[list, tuple[object]]", obj_outputs); 
    goto fail;
__LL24: ;
    PyObject *retval = CPyDef_format_output_but_cache_checksums(arg_abi, arg_outputs);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "format_output_but_cache_checksums", 297, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__format_tuple_but_cache_checksums(PyObject *cpy_r_abi_types, PyObject *cpy_r_values) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
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
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    int32_t cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    int32_t cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    int32_t cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
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
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 311, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r1 = CPyObject_Size(cpy_r_abi_types);
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 312, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[80]; /* '_check_array' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 312, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r5 = CPyTagged_StealAsObject(cpy_r_r1);
    PyObject *cpy_r_r6[2] = {cpy_r_values, cpy_r_r5};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r7, 2, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 312, CPyStatic_globals);
        goto CPyL44;
    } else
        goto CPyL45;
CPyL4: ;
    CPy_DECREF(cpy_r_r5);
    cpy_r_r9 = PyObject_GetIter(cpy_r_abi_types);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 313, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r10 = PyObject_GetIter(cpy_r_values);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 313, CPyStatic_globals);
        goto CPyL46;
    }
CPyL6: ;
    cpy_r_r11 = PyIter_Next(cpy_r_r9);
    if (cpy_r_r11 == NULL) goto CPyL47;
    cpy_r_r12 = PyIter_Next(cpy_r_r10);
    if (cpy_r_r12 == NULL) goto CPyL48;
    cpy_r_r13 = CPyStatics[81]; /* 'is_array' */
    cpy_r_r14 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 315, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r15 = PyObject_IsTrue(cpy_r_r14);
    CPy_DECREF(cpy_r_r14);
    cpy_r_r16 = cpy_r_r15 >= 0;
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 315, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r17 = cpy_r_r15;
    if (!cpy_r_r17) goto CPyL15;
    CPy_INCREF(cpy_r_r12);
    if (PyList_Check(cpy_r_r12))
        cpy_r_r18 = cpy_r_r12;
    else {
        cpy_r_r18 = NULL;
    }
    if (cpy_r_r18 != NULL) goto __LL26;
    if (unlikely(!(PyTuple_Check(cpy_r_r12) && PyTuple_GET_SIZE(cpy_r_r12) == 1))) {
        cpy_r_r18 = NULL;
        goto __LL27;
    }
    cpy_r_r18 = PyTuple_GET_ITEM(cpy_r_r12, 0);
    if (cpy_r_r18 == NULL) goto __LL27;
    cpy_r_r18 = cpy_r_r12;
__LL27: ;
    if (cpy_r_r18 != NULL) goto __LL26;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 316, CPyStatic_globals, "union[list, tuple[object]]", cpy_r_r12);
    goto CPyL49;
__LL26: ;
    cpy_r_r19 = CPyDef__format_array_but_cache_checksums(cpy_r_r11, cpy_r_r18);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 316, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r20 = PyList_Append(cpy_r_r0, cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    cpy_r_r21 = cpy_r_r20 >= 0;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 316, CPyStatic_globals);
        goto CPyL50;
    } else
        goto CPyL51;
CPyL15: ;
    cpy_r_r22 = CPyStatic_globals;
    cpy_r_r23 = CPyStatics[82]; /* 'TupleType' */
    cpy_r_r24 = CPyDict_GetItem(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 317, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r25 = PyObject_IsInstance(cpy_r_r11, cpy_r_r24);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 317, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r27 = cpy_r_r25;
    if (!cpy_r_r27) goto CPyL22;
    cpy_r_r28 = CPyStatics[83]; /* 'components' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r28);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 318, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_INCREF(cpy_r_r12);
    if (PyList_Check(cpy_r_r12))
        cpy_r_r30 = cpy_r_r12;
    else {
        cpy_r_r30 = NULL;
    }
    if (cpy_r_r30 != NULL) goto __LL28;
    if (unlikely(!(PyTuple_Check(cpy_r_r12) && PyTuple_GET_SIZE(cpy_r_r12) == 1))) {
        cpy_r_r30 = NULL;
        goto __LL29;
    }
    cpy_r_r30 = PyTuple_GET_ITEM(cpy_r_r12, 0);
    if (cpy_r_r30 == NULL) goto __LL29;
    cpy_r_r30 = cpy_r_r12;
__LL29: ;
    if (cpy_r_r30 != NULL) goto __LL28;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 318, CPyStatic_globals, "union[list, tuple[object]]", cpy_r_r12);
    goto CPyL52;
__LL28: ;
    cpy_r_r31 = CPyDef__format_tuple_but_cache_checksums(cpy_r_r29, cpy_r_r30);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 318, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r32 = PyList_Append(cpy_r_r0, cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    cpy_r_r33 = cpy_r_r32 >= 0;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 318, CPyStatic_globals);
        goto CPyL50;
    } else
        goto CPyL53;
CPyL22: ;
    cpy_r_r34 = CPyStatics[84]; /* 'to_type_str' */
    cpy_r_r35 = CPyObject_CallMethodObjArgs(cpy_r_r11, cpy_r_r34, NULL);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 320, CPyStatic_globals);
        goto CPyL50;
    }
    if (likely(PyUnicode_Check(cpy_r_r35)))
        cpy_r_r36 = cpy_r_r35;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 320, CPyStatic_globals, "str", cpy_r_r35);
        goto CPyL50;
    }
    cpy_r_r37 = CPyDef__format_single_but_cache_checksums(cpy_r_r36, cpy_r_r12);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 320, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r38 = PyList_Append(cpy_r_r0, cpy_r_r37);
    CPy_DECREF(cpy_r_r37);
    cpy_r_r39 = cpy_r_r38 >= 0;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 320, CPyStatic_globals);
        goto CPyL50;
    } else
        goto CPyL54;
CPyL26: ;
    cpy_r_r40 = CPy_CatchError();
    cpy_r_r41 = CPyModule_builtins;
    cpy_r_r42 = CPyStatics[49]; /* 'Exception' */
    cpy_r_r43 = CPyObject_GetAttr(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 321, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r44 = CPy_ExceptionMatches(cpy_r_r43);
    CPy_DecRef(cpy_r_r43);
    if (!cpy_r_r44) goto CPyL56;
    cpy_r_r45 = CPy_GetExcValue();
    cpy_r_r46 = PyObject_Type(cpy_r_r45);
    cpy_r_r47 = CPyStatics[85]; /* "'" */
    cpy_r_r48 = PyObject_Str(cpy_r_r12);
    CPy_DecRef(cpy_r_r12);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 322, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r49 = CPyStatics[86]; /* "' - " */
    cpy_r_r50 = PyObject_Str(cpy_r_r45);
    CPy_DecRef(cpy_r_r45);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 322, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r51 = CPyStr_Build(4, cpy_r_r47, cpy_r_r48, cpy_r_r49, cpy_r_r50);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 322, CPyStatic_globals);
        goto CPyL59;
    }
    PyObject *cpy_r_r52[1] = {cpy_r_r51};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = _PyObject_Vectorcall(cpy_r_r46, cpy_r_r53, 1, 0);
    CPy_DecRef(cpy_r_r46);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 322, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_DecRef(cpy_r_r51);
    CPy_Raise(cpy_r_r54);
    CPy_DecRef(cpy_r_r54);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 322, CPyStatic_globals);
        goto CPyL36;
    } else
        goto CPyL61;
CPyL33: ;
    CPy_Unreachable();
CPyL34: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL36;
    } else
        goto CPyL62;
CPyL35: ;
    CPy_Unreachable();
CPyL36: ;
    CPy_RestoreExcInfo(cpy_r_r40);
    CPy_DecRef(cpy_r_r40.f0);
    CPy_DecRef(cpy_r_r40.f1);
    CPy_DecRef(cpy_r_r40.f2);
    cpy_r_r55 = CPy_KeepPropagating();
    if (!cpy_r_r55) goto CPyL41;
    CPy_Unreachable();
CPyL38: ;
    cpy_r_r56 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 313, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r57 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 313, CPyStatic_globals);
        goto CPyL42;
    }
    return cpy_r_r0;
CPyL41: ;
    cpy_r_r58 = NULL;
    return cpy_r_r58;
CPyL42: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL41;
CPyL43: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    goto CPyL41;
CPyL44: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    goto CPyL41;
CPyL45: ;
    CPy_DECREF(cpy_r_r8);
    goto CPyL4;
CPyL46: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r9);
    goto CPyL41;
CPyL47: ;
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    goto CPyL38;
CPyL48: ;
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r11);
    goto CPyL38;
CPyL49: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r11);
    goto CPyL26;
CPyL50: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    goto CPyL26;
CPyL51: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL6;
CPyL52: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r29);
    goto CPyL26;
CPyL53: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL6;
CPyL54: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL6;
CPyL55: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL36;
CPyL56: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL34;
CPyL57: ;
    CPy_DecRef(cpy_r_r45);
    CPy_DecRef(cpy_r_r46);
    goto CPyL36;
CPyL58: ;
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r48);
    goto CPyL36;
CPyL59: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL36;
CPyL60: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL36;
CPyL61: ;
    CPy_DecRef(cpy_r_r40.f0);
    CPy_DecRef(cpy_r_r40.f1);
    CPy_DecRef(cpy_r_r40.f2);
    goto CPyL33;
CPyL62: ;
    CPy_DecRef(cpy_r_r40.f0);
    CPy_DecRef(cpy_r_r40.f1);
    CPy_DecRef(cpy_r_r40.f2);
    goto CPyL35;
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
    if (arg_values != NULL) goto __LL30;
    if (unlikely(!(PyTuple_Check(obj_values) && PyTuple_GET_SIZE(obj_values) == 1))) {
        arg_values = NULL;
        goto __LL31;
    }
    arg_values = PyTuple_GET_ITEM(obj_values, 0);
    if (arg_values == NULL) goto __LL31;
    arg_values = obj_values;
__LL31: ;
    if (arg_values != NULL) goto __LL30;
    CPy_TypeError("union[list, tuple[object]]", obj_values); 
    goto fail;
__LL30: ;
    PyObject *retval = CPyDef__format_tuple_but_cache_checksums(arg_abi_types, arg_values);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_tuple_but_cache_checksums", 308, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    cpy_r_r0 = ((dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "<lambda>", "__mypyc_lambda__2__format_array_but_cache_checksums_obj", "__mypyc_env__", 330, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_item_type;
    if (unlikely(cpy_r_r1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'item_type' of '_format_array_but_cache_checksums_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r1);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 330, CPyStatic_globals);
        goto CPyL6;
    }
CPyL2: ;
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[87]; /* '_format_array' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 330, CPyStatic_globals);
        goto CPyL7;
    }
    PyObject *cpy_r_r5[2] = {cpy_r_r1, cpy_r_v};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 2, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 330, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_DECREF(cpy_r_r1);
    if (likely(PyList_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 330, CPyStatic_globals, "list", cpy_r_r7);
        goto CPyL6;
    }
    return cpy_r_r8;
CPyL6: ;
    cpy_r_r9 = NULL;
    return cpy_r_r9;
CPyL7: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL6;
}

PyObject *CPyPy___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"v", 0};
    static CPyArg_Parser parser = {"O:__call__", kwlist, 0};
    PyObject *obj_v;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_v)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_v = obj_v;
    PyObject *retval = CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__(arg___mypyc_self__, arg_v);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 330, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    cpy_r_r0 = ((dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "<lambda>", "__mypyc_lambda__3__format_array_but_cache_checksums_obj", "__mypyc_env__", 333, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_components;
    if (unlikely(cpy_r_r1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'components' of '_format_array_but_cache_checksums_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r1);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 333, CPyStatic_globals);
        goto CPyL6;
    }
CPyL2: ;
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[88]; /* '_format_tuple' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 333, CPyStatic_globals);
        goto CPyL7;
    }
    PyObject *cpy_r_r5[2] = {cpy_r_r1, cpy_r_v};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 2, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 333, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_DECREF(cpy_r_r1);
    if (likely(PyList_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 333, CPyStatic_globals, "list", cpy_r_r7);
        goto CPyL6;
    }
    return cpy_r_r8;
CPyL6: ;
    cpy_r_r9 = NULL;
    return cpy_r_r9;
CPyL7: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL6;
}

PyObject *CPyPy___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"v", 0};
    static CPyArg_Parser parser = {"O:__call__", kwlist, 0};
    PyObject *obj_v;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_v)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_v = obj_v;
    PyObject *retval = CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__(arg___mypyc_self__, arg_v);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 333, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = ((dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "<lambda>", "__mypyc_lambda__4__format_array_but_cache_checksums_obj", "__mypyc_env__", 336, CPyStatic_globals);
        goto CPyL5;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_type_str;
    if (unlikely(cpy_r_r1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'type_str' of '_format_array_but_cache_checksums_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r1);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 336, CPyStatic_globals);
        goto CPyL5;
    }
CPyL2: ;
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[89]; /* '_format_single' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 336, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r5[2] = {cpy_r_r1, cpy_r_v};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 2, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 336, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r1);
    return cpy_r_r7;
CPyL5: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
CPyL6: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL5;
}

PyObject *CPyPy___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"v", 0};
    static CPyArg_Parser parser = {"O:__call__", kwlist, 0};
    PyObject *obj_v;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_v)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_v = obj_v;
    PyObject *retval = CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__(arg___mypyc_self__, arg_v);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<lambda>", 336, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__format_array_but_cache_checksums(PyObject *cpy_r_abi_type, PyObject *cpy_r_values) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPyTagged cpy_r_r5;
    char cpy_r_r6;
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
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    int32_t cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
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
    int32_t cpy_r_r43;
    char cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    char cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject **cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    PyObject *cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject **cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    cpy_r_r0 = CPyDef__format_array_but_cache_checksums_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 326, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r1 = CPyStatics[90]; /* 'arrlist' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r3 = CPyStatics[193]; /* -1 */
    cpy_r_r4 = PyObject_GetItem(cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r5 = CPyObject_Size(cpy_r_r4);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r6 = cpy_r_r5 != 0;
    CPyTagged_DECREF(cpy_r_r5);
    if (!cpy_r_r6) goto CPyL9;
    cpy_r_r7 = CPyStatics[90]; /* 'arrlist' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r9 = CPyStatics[193]; /* -1 */
    cpy_r_r10 = PyObject_GetItem(cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r11 = CPyStatics[190]; /* 0 */
    cpy_r_r12 = PyObject_GetItem(cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r13 = cpy_r_r12;
    goto CPyL10;
CPyL9: ;
    cpy_r_r14 = Py_None;
    CPy_INCREF(cpy_r_r14);
    cpy_r_r13 = cpy_r_r14;
CPyL10: ;
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[80]; /* '_check_array' */
    cpy_r_r17 = CPyDict_GetItem(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL48;
    }
    PyObject *cpy_r_r18[2] = {cpy_r_values, cpy_r_r13};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = _PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 2, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 327, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL49;
CPyL12: ;
    CPy_DECREF(cpy_r_r13);
    cpy_r_r21 = CPyStatics[91]; /* 'item_type' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 328, CPyStatic_globals);
        goto CPyL47;
    }
    if (((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_item_type != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_item_type);
    }
    ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_item_type = cpy_r_r22;
    cpy_r_r23 = 1;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 328, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r24 = ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_item_type;
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", "_format_array_but_cache_checksums_env", "item_type", 329, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_INCREF(cpy_r_r24);
CPyL15: ;
    cpy_r_r25 = CPyStatics[81]; /* 'is_array' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 329, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r27 = PyObject_IsTrue(cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r28 = cpy_r_r27 >= 0;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 329, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r29 = cpy_r_r27;
    if (!cpy_r_r29) goto CPyL24;
    cpy_r_r30 = CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj();
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 330, CPyStatic_globals);
        goto CPyL47;
    }
    if (((dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *)cpy_r_r30)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *)cpy_r_r30)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject *)cpy_r_r30)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r31 = 1;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 330, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r32 = CPyModule_builtins;
    cpy_r_r33 = CPyStatics[92]; /* 'map' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 330, CPyStatic_globals);
        goto CPyL50;
    }
    PyObject *cpy_r_r35[2] = {cpy_r_r30, cpy_r_values};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = _PyObject_Vectorcall(cpy_r_r34, cpy_r_r36, 2, 0);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 330, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_DECREF(cpy_r_r30);
    cpy_r_r38 = PySequence_List(cpy_r_r37);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 330, CPyStatic_globals);
        goto CPyL46;
    }
    return cpy_r_r38;
CPyL24: ;
    cpy_r_r39 = ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_item_type;
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", "_format_array_but_cache_checksums_env", "item_type", 331, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_INCREF(cpy_r_r39);
CPyL25: ;
    cpy_r_r40 = CPyStatic_globals;
    cpy_r_r41 = CPyStatics[82]; /* 'TupleType' */
    cpy_r_r42 = CPyDict_GetItem(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 331, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r43 = PyObject_IsInstance(cpy_r_r39, cpy_r_r42);
    CPy_DECREF(cpy_r_r39);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r44 = cpy_r_r43 >= 0;
    if (unlikely(!cpy_r_r44)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 331, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r45 = cpy_r_r43;
    if (!cpy_r_r45) goto CPyL37;
    cpy_r_r46 = ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_item_type;
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", "_format_array_but_cache_checksums_env", "item_type", 332, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_INCREF(cpy_r_r46);
CPyL29: ;
    cpy_r_r47 = CPyStatics[83]; /* 'components' */
    cpy_r_r48 = CPyObject_GetAttr(cpy_r_r46, cpy_r_r47);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 332, CPyStatic_globals);
        goto CPyL47;
    }
    if (((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_components != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_components);
    }
    ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_components = cpy_r_r48;
    cpy_r_r49 = 1;
    if (unlikely(!cpy_r_r49)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 332, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r50 = CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj();
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 333, CPyStatic_globals);
        goto CPyL47;
    }
    if (((dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *)cpy_r_r50)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *)cpy_r_r50)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject *)cpy_r_r50)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r51 = 1;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 333, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r52 = CPyModule_builtins;
    cpy_r_r53 = CPyStatics[92]; /* 'map' */
    cpy_r_r54 = CPyObject_GetAttr(cpy_r_r52, cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 333, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r55[2] = {cpy_r_r50, cpy_r_values};
    cpy_r_r56 = (PyObject **)&cpy_r_r55;
    cpy_r_r57 = _PyObject_Vectorcall(cpy_r_r54, cpy_r_r56, 2, 0);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 333, CPyStatic_globals);
        goto CPyL52;
    }
    CPy_DECREF(cpy_r_r50);
    cpy_r_r58 = PySequence_List(cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 333, CPyStatic_globals);
        goto CPyL46;
    }
    return cpy_r_r58;
CPyL37: ;
    cpy_r_r59 = ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_item_type;
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", "_format_array_but_cache_checksums_env", "item_type", 335, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_INCREF(cpy_r_r59);
CPyL38: ;
    cpy_r_r60 = CPyStatics[84]; /* 'to_type_str' */
    cpy_r_r61 = CPyObject_CallMethodObjArgs(cpy_r_r59, cpy_r_r60, NULL);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 335, CPyStatic_globals);
        goto CPyL47;
    }
    if (((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_type_str != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_type_str);
    }
    ((dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject *)cpy_r_r0)->_type_str = cpy_r_r61;
    cpy_r_r62 = 1;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 335, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r63 = CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj();
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 336, CPyStatic_globals);
        goto CPyL47;
    }
    if (((dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *)cpy_r_r63)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *)cpy_r_r63)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject *)cpy_r_r63)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r64 = 1;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 336, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r65 = CPyModule_builtins;
    cpy_r_r66 = CPyStatics[92]; /* 'map' */
    cpy_r_r67 = CPyObject_GetAttr(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 336, CPyStatic_globals);
        goto CPyL53;
    }
    PyObject *cpy_r_r68[2] = {cpy_r_r63, cpy_r_values};
    cpy_r_r69 = (PyObject **)&cpy_r_r68;
    cpy_r_r70 = _PyObject_Vectorcall(cpy_r_r67, cpy_r_r69, 2, 0);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 336, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_r63);
    cpy_r_r71 = PySequence_List(cpy_r_r70);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 336, CPyStatic_globals);
        goto CPyL46;
    }
    return cpy_r_r71;
CPyL46: ;
    cpy_r_r72 = NULL;
    return cpy_r_r72;
CPyL47: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL46;
CPyL48: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    goto CPyL46;
CPyL49: ;
    CPy_DECREF(cpy_r_r20);
    goto CPyL12;
CPyL50: ;
    CPy_DecRef(cpy_r_r30);
    goto CPyL46;
CPyL51: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r39);
    goto CPyL46;
CPyL52: ;
    CPy_DecRef(cpy_r_r50);
    goto CPyL46;
CPyL53: ;
    CPy_DecRef(cpy_r_r63);
    goto CPyL46;
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
    if (arg_values != NULL) goto __LL32;
    if (unlikely(!(PyTuple_Check(obj_values) && PyTuple_GET_SIZE(obj_values) == 1))) {
        arg_values = NULL;
        goto __LL33;
    }
    arg_values = PyTuple_GET_ITEM(obj_values, 0);
    if (arg_values == NULL) goto __LL33;
    arg_values = obj_values;
__LL33: ;
    if (arg_values != NULL) goto __LL32;
    CPy_TypeError("union[list, tuple[object]]", obj_values); 
    goto fail;
__LL32: ;
    PyObject *retval = CPyDef__format_array_but_cache_checksums(arg_abi_type, arg_values);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_array_but_cache_checksums", 326, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__format_single_but_cache_checksums(PyObject *cpy_r_type_str, PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    int32_t cpy_r_r11;
    char cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    int32_t cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject **cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    int32_t cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject **cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    int32_t cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    char cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    tuple_T5OOOOO cpy_r_r60;
    PyObject *cpy_r_r61;
    int32_t cpy_r_r62;
    char cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject **cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    int32_t cpy_r_r74;
    char cpy_r_r75;
    char cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject **cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    int32_t cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject **cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject **cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    cpy_r_r0 = CPyStatics[93]; /* 'uint' */
    cpy_r_r1 = PySequence_Contains(cpy_r_type_str, cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 341, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r3 = cpy_r_r1;
    if (!cpy_r_r3) goto CPyL5;
    cpy_r_r4 = CPyStatic_globals;
    cpy_r_r5 = CPyStatics[94]; /* 'to_uint' */
    cpy_r_r6 = CPyDict_GetItem(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 342, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r7[2] = {cpy_r_value, cpy_r_type_str};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 2, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 342, CPyStatic_globals);
        goto CPyL52;
    }
    return cpy_r_r9;
CPyL5: ;
    cpy_r_r10 = CPyStatics[95]; /* 'int' */
    cpy_r_r11 = PySequence_Contains(cpy_r_type_str, cpy_r_r10);
    cpy_r_r12 = cpy_r_r11 >= 0;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 343, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r13 = cpy_r_r11;
    if (!cpy_r_r13) goto CPyL10;
    cpy_r_r14 = CPyStatic_globals;
    cpy_r_r15 = CPyStatics[96]; /* 'to_int' */
    cpy_r_r16 = CPyDict_GetItem(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 344, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r17[2] = {cpy_r_value, cpy_r_type_str};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = _PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 2, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 344, CPyStatic_globals);
        goto CPyL52;
    }
    return cpy_r_r19;
CPyL10: ;
    cpy_r_r20 = CPyStatics[97]; /* 'fixed168x10' */
    cpy_r_r21 = PyUnicode_Compare(cpy_r_type_str, cpy_r_r20);
    cpy_r_r22 = cpy_r_r21 == -1;
    if (!cpy_r_r22) goto CPyL13;
    cpy_r_r23 = PyErr_Occurred();
    cpy_r_r24 = cpy_r_r23 != NULL;
    if (!cpy_r_r24) goto CPyL13;
    cpy_r_r25 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 345, CPyStatic_globals);
        goto CPyL52;
    }
CPyL13: ;
    cpy_r_r26 = cpy_r_r21 == 0;
    if (!cpy_r_r26) goto CPyL17;
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyStatics[98]; /* 'to_decimal' */
    cpy_r_r29 = CPyDict_GetItem(cpy_r_r27, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 346, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r30[1] = {cpy_r_value};
    cpy_r_r31 = (PyObject **)&cpy_r_r30;
    cpy_r_r32 = _PyObject_Vectorcall(cpy_r_r29, cpy_r_r31, 1, 0);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 346, CPyStatic_globals);
        goto CPyL52;
    }
    return cpy_r_r32;
CPyL17: ;
    cpy_r_r33 = CPyStatics[99]; /* 'bool' */
    cpy_r_r34 = PyUnicode_Compare(cpy_r_type_str, cpy_r_r33);
    cpy_r_r35 = cpy_r_r34 == -1;
    if (!cpy_r_r35) goto CPyL20;
    cpy_r_r36 = PyErr_Occurred();
    cpy_r_r37 = cpy_r_r36 != NULL;
    if (!cpy_r_r37) goto CPyL20;
    cpy_r_r38 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 347, CPyStatic_globals);
        goto CPyL52;
    }
CPyL20: ;
    cpy_r_r39 = cpy_r_r34 == 0;
    if (!cpy_r_r39) goto CPyL24;
    cpy_r_r40 = CPyStatic_globals;
    cpy_r_r41 = CPyStatics[100]; /* 'to_bool' */
    cpy_r_r42 = CPyDict_GetItem(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 348, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r43[1] = {cpy_r_value};
    cpy_r_r44 = (PyObject **)&cpy_r_r43;
    cpy_r_r45 = _PyObject_Vectorcall(cpy_r_r42, cpy_r_r44, 1, 0);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 348, CPyStatic_globals);
        goto CPyL52;
    }
    return cpy_r_r45;
CPyL24: ;
    cpy_r_r46 = CPyStatics[101]; /* 'address' */
    cpy_r_r47 = PyUnicode_Compare(cpy_r_type_str, cpy_r_r46);
    cpy_r_r48 = cpy_r_r47 == -1;
    if (!cpy_r_r48) goto CPyL27;
    cpy_r_r49 = PyErr_Occurred();
    cpy_r_r50 = cpy_r_r49 != NULL;
    if (!cpy_r_r50) goto CPyL27;
    cpy_r_r51 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 349, CPyStatic_globals);
        goto CPyL52;
    }
CPyL27: ;
    cpy_r_r52 = cpy_r_r47 == 0;
    if (!cpy_r_r52) goto CPyL37;
    cpy_r_r53 = (PyObject *)&PyUnicode_Type;
    cpy_r_r54 = (PyObject *)&PyBytes_Type;
    cpy_r_r55 = CPyModule_builtins;
    cpy_r_r56 = CPyStatics[102]; /* 'bytearray' */
    cpy_r_r57 = CPyObject_GetAttr(cpy_r_r55, cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 352, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r58 = (PyObject *)&PyLong_Type;
    cpy_r_r59 = (PyObject *)&PyBool_Type;
    CPy_INCREF(cpy_r_r53);
    CPy_INCREF(cpy_r_r54);
    CPy_INCREF(cpy_r_r58);
    CPy_INCREF(cpy_r_r59);
    cpy_r_r60.f0 = cpy_r_r53;
    cpy_r_r60.f1 = cpy_r_r54;
    cpy_r_r60.f2 = cpy_r_r57;
    cpy_r_r60.f3 = cpy_r_r58;
    cpy_r_r60.f4 = cpy_r_r59;
    cpy_r_r61 = PyTuple_New(5);
    if (unlikely(cpy_r_r61 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp34 = cpy_r_r60.f0;
    PyTuple_SET_ITEM(cpy_r_r61, 0, __tmp34);
    PyObject *__tmp35 = cpy_r_r60.f1;
    PyTuple_SET_ITEM(cpy_r_r61, 1, __tmp35);
    PyObject *__tmp36 = cpy_r_r60.f2;
    PyTuple_SET_ITEM(cpy_r_r61, 2, __tmp36);
    PyObject *__tmp37 = cpy_r_r60.f3;
    PyTuple_SET_ITEM(cpy_r_r61, 3, __tmp37);
    PyObject *__tmp38 = cpy_r_r60.f4;
    PyTuple_SET_ITEM(cpy_r_r61, 4, __tmp38);
    cpy_r_r62 = PyObject_IsInstance(cpy_r_value, cpy_r_r61);
    CPy_DECREF(cpy_r_r61);
    cpy_r_r63 = cpy_r_r62 >= 0;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 352, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r64 = cpy_r_r62;
    if (!cpy_r_r64) goto CPyL32;
    CPy_INCREF(cpy_r_value);
    cpy_r_r65 = cpy_r_value;
    goto CPyL34;
CPyL32: ;
    cpy_r_r66 = PyObject_Str(cpy_r_value);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 352, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r65 = cpy_r_r66;
CPyL34: ;
    cpy_r_r67 = CPyStatic_globals;
    cpy_r_r68 = CPyStatics[103]; /* 'to_checksum_address' */
    cpy_r_r69 = CPyDict_GetItem(cpy_r_r67, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 351, CPyStatic_globals);
        goto CPyL53;
    }
    PyObject *cpy_r_r70[1] = {cpy_r_r65};
    cpy_r_r71 = (PyObject **)&cpy_r_r70;
    cpy_r_r72 = _PyObject_Vectorcall(cpy_r_r69, cpy_r_r71, 1, 0);
    CPy_DECREF(cpy_r_r69);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 351, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_r65);
    return cpy_r_r72;
CPyL37: ;
    cpy_r_r73 = CPyStatics[104]; /* 'byte' */
    cpy_r_r74 = PySequence_Contains(cpy_r_type_str, cpy_r_r73);
    cpy_r_r75 = cpy_r_r74 >= 0;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 354, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r76 = cpy_r_r74;
    if (!cpy_r_r76) goto CPyL42;
    cpy_r_r77 = CPyStatic_globals;
    cpy_r_r78 = CPyStatics[105]; /* 'HexString' */
    cpy_r_r79 = CPyDict_GetItem(cpy_r_r77, cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 355, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r80[2] = {cpy_r_value, cpy_r_type_str};
    cpy_r_r81 = (PyObject **)&cpy_r_r80;
    cpy_r_r82 = _PyObject_Vectorcall(cpy_r_r79, cpy_r_r81, 2, 0);
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 355, CPyStatic_globals);
        goto CPyL52;
    }
    return cpy_r_r82;
CPyL42: ;
    cpy_r_r83 = CPyStatics[63]; /* 'string' */
    cpy_r_r84 = PySequence_Contains(cpy_r_type_str, cpy_r_r83);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 356, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r86 = cpy_r_r84;
    if (!cpy_r_r86) goto CPyL47;
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyStatics[106]; /* 'to_string' */
    cpy_r_r89 = CPyDict_GetItem(cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 357, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r90[1] = {cpy_r_value};
    cpy_r_r91 = (PyObject **)&cpy_r_r90;
    cpy_r_r92 = _PyObject_Vectorcall(cpy_r_r89, cpy_r_r91, 1, 0);
    CPy_DECREF(cpy_r_r89);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 357, CPyStatic_globals);
        goto CPyL52;
    }
    return cpy_r_r92;
CPyL47: ;
    cpy_r_r93 = CPyStatics[107]; /* 'Unknown type: ' */
    cpy_r_r94 = CPyStr_Build(2, cpy_r_r93, cpy_r_type_str);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 358, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r95 = CPyModule_builtins;
    cpy_r_r96 = CPyStatics[41]; /* 'TypeError' */
    cpy_r_r97 = CPyObject_GetAttr(cpy_r_r95, cpy_r_r96);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 358, CPyStatic_globals);
        goto CPyL54;
    }
    PyObject *cpy_r_r98[1] = {cpy_r_r94};
    cpy_r_r99 = (PyObject **)&cpy_r_r98;
    cpy_r_r100 = _PyObject_Vectorcall(cpy_r_r97, cpy_r_r99, 1, 0);
    CPy_DECREF(cpy_r_r97);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 358, CPyStatic_globals);
        goto CPyL54;
    }
    CPy_DECREF(cpy_r_r94);
    CPy_Raise(cpy_r_r100);
    CPy_DECREF(cpy_r_r100);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 358, CPyStatic_globals);
        goto CPyL52;
    }
    CPy_Unreachable();
CPyL52: ;
    cpy_r_r101 = NULL;
    return cpy_r_r101;
CPyL53: ;
    CPy_DecRef(cpy_r_r65);
    goto CPyL52;
CPyL54: ;
    CPy_DecRef(cpy_r_r94);
    goto CPyL52;
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
    CPy_AddTraceback("dank_mids/brownie_patch/call.py", "_format_single_but_cache_checksums", 339, CPyStatic_globals);
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
    PyObject **cpy_r_r29;
    PyObject **cpy_r_r30;
    PyObject **cpy_r_r31;
    void *cpy_r_r33;
    void *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
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
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject **cpy_r_r127;
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
    PyObject **cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    int32_t cpy_r_r143;
    char cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    int32_t cpy_r_r154;
    char cpy_r_r155;
    PyObject *cpy_r_r156;
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
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    tuple_T2OO cpy_r_r173;
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
    PyObject *cpy_r_r187;
    tuple_T2OO cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject **cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    int32_t cpy_r_r199;
    char cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject **cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    int32_t cpy_r_r213;
    char cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    int32_t cpy_r_r218;
    char cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    int32_t cpy_r_r223;
    char cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    int32_t cpy_r_r232;
    char cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject **cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    int32_t cpy_r_r245;
    char cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
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
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    int32_t cpy_r_r265;
    char cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
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
    PyObject *cpy_r_r283;
    PyObject *cpy_r_r284;
    int32_t cpy_r_r285;
    char cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    int32_t cpy_r_r289;
    char cpy_r_r290;
    PyObject *cpy_r_r291;
    PyObject *cpy_r_r292;
    int32_t cpy_r_r293;
    char cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    int32_t cpy_r_r302;
    char cpy_r_r303;
    tuple_T3OOO cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    PyObject *cpy_r_r307;
    char cpy_r_r308;
    PyObject *cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    int32_t cpy_r_r312;
    char cpy_r_r313;
    PyObject *cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    PyObject *cpy_r_r318;
    int32_t cpy_r_r319;
    char cpy_r_r320;
    char cpy_r_r321;
    char cpy_r_r322;
    char cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    int32_t cpy_r_r335;
    char cpy_r_r336;
    int32_t cpy_r_r337;
    char cpy_r_r338;
    char cpy_r_r339;
    PyObject *cpy_r_r340;
    PyObject *cpy_r_r341;
    PyObject *cpy_r_r342;
    PyObject *cpy_r_r343;
    PyObject *cpy_r_r344;
    PyObject *cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    PyObject *cpy_r_r348;
    PyObject *cpy_r_r349;
    PyObject **cpy_r_r351;
    PyObject *cpy_r_r352;
    int32_t cpy_r_r353;
    char cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_r356;
    PyObject *cpy_r_r357;
    PyObject *cpy_r_r358;
    PyObject *cpy_r_r359;
    PyObject *cpy_r_r360;
    PyObject *cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    int32_t cpy_r_r366;
    char cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject *cpy_r_r369;
    PyObject *cpy_r_r370;
    PyObject *cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    PyObject *cpy_r_r377;
    PyObject *cpy_r_r378;
    int32_t cpy_r_r379;
    char cpy_r_r380;
    PyObject *cpy_r_r381;
    PyObject *cpy_r_r382;
    PyObject *cpy_r_r383;
    PyObject *cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    PyObject *cpy_r_r390;
    PyObject *cpy_r_r391;
    int32_t cpy_r_r392;
    char cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    PyObject *cpy_r_r397;
    PyObject *cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject *cpy_r_r400;
    PyObject *cpy_r_r401;
    PyObject *cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    int32_t cpy_r_r405;
    char cpy_r_r406;
    PyObject *cpy_r_r407;
    PyObject *cpy_r_r408;
    PyObject *cpy_r_r409;
    PyObject *cpy_r_r410;
    PyObject *cpy_r_r411;
    PyObject *cpy_r_r412;
    PyObject *cpy_r_r413;
    PyObject *cpy_r_r414;
    PyObject *cpy_r_r415;
    PyObject *cpy_r_r416;
    PyObject *cpy_r_r417;
    int32_t cpy_r_r418;
    char cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    PyObject *cpy_r_r423;
    PyObject *cpy_r_r424;
    int32_t cpy_r_r425;
    char cpy_r_r426;
    PyObject *cpy_r_r427;
    PyObject *cpy_r_r428;
    PyObject *cpy_r_r429;
    PyObject *cpy_r_r430;
    PyObject *cpy_r_r431;
    int32_t cpy_r_r432;
    char cpy_r_r433;
    PyObject *cpy_r_r434;
    PyObject *cpy_r_r435;
    PyObject *cpy_r_r436;
    PyObject *cpy_r_r437;
    PyObject *cpy_r_r438;
    int32_t cpy_r_r439;
    char cpy_r_r440;
    char cpy_r_r441;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[108]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", -1, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[194]; /* ('BrokenProcessPool',) */
    cpy_r_r6 = CPyStatics[109]; /* 'concurrent.futures.process' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 1, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_concurrent___futures___process = cpy_r_r8;
    CPy_INCREF(CPyModule_concurrent___futures___process);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[195]; /* ('Decimal',) */
    cpy_r_r10 = CPyStatics[110]; /* 'decimal' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 2, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_decimal = cpy_r_r12;
    CPy_INCREF(CPyModule_decimal);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[196]; /* ('getLogger',) */
    cpy_r_r14 = CPyStatics[112]; /* 'logging' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 3, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_logging = cpy_r_r16;
    CPy_INCREF(CPyModule_logging);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[197]; /* ('PicklingError',) */
    cpy_r_r18 = CPyStatics[113]; /* 'pickle' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 4, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_pickle = cpy_r_r20;
    CPy_INCREF(CPyModule_pickle);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[198]; /* ('MethodType',) */
    cpy_r_r22 = CPyStatics[114]; /* 'types' */
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 5, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_types = cpy_r_r24;
    CPy_INCREF(CPyModule_types);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[199]; /* ('Any', 'Callable', 'Dict', 'Final', 'List', 'NewType',
                                    'Optional', 'Sequence', 'Tuple', 'TypeVar', 'Union') */
    cpy_r_r26 = CPyStatics[126]; /* 'typing' */
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyImport_ImportFromMany(cpy_r_r26, cpy_r_r25, cpy_r_r25, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 6, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_typing = cpy_r_r28;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r29 = (PyObject **)&CPyModule_brownie___convert___normalize;
    cpy_r_r30 = (PyObject **)&CPyModule_brownie___network___contract;
    cpy_r_r31 = (PyObject **)&CPyModule_eth_abi;
    PyObject **cpy_r_r32[3] = {cpy_r_r29, cpy_r_r30, cpy_r_r31};
    cpy_r_r33 = (void *)&cpy_r_r32;
    int64_t cpy_r_r34[3] = {20, 21, 22};
    cpy_r_r35 = (void *)&cpy_r_r34;
    cpy_r_r36 = CPyStatics[203]; /* (('brownie.convert.normalize', 'brownie', 'brownie'),
                                    ('brownie.network.contract', 'brownie', 'brownie'),
                                    ('eth_abi', 'eth_abi', 'eth_abi')) */
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyStatics[130]; /* 'dank_mids/brownie_patch/call.py' */
    cpy_r_r39 = CPyStatics[131]; /* '<module>' */
    cpy_r_r40 = CPyImport_ImportMany(cpy_r_r36, cpy_r_r33, cpy_r_r37, cpy_r_r38, cpy_r_r39, cpy_r_r35);
    if (!cpy_r_r40) goto CPyL154;
    cpy_r_r41 = CPyStatics[204]; /* ('AsyncProcessPoolExecutor',) */
    cpy_r_r42 = CPyStatics[132]; /* 'a_sync' */
    cpy_r_r43 = CPyStatic_globals;
    cpy_r_r44 = CPyImport_ImportFromMany(cpy_r_r42, cpy_r_r41, cpy_r_r41, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 23, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_a_sync = cpy_r_r44;
    CPy_INCREF(CPyModule_a_sync);
    CPy_DECREF(cpy_r_r44);
    cpy_r_r45 = CPyStatics[205]; /* ('chain',) */
    cpy_r_r46 = CPyStatics[128]; /* 'brownie' */
    cpy_r_r47 = CPyStatic_globals;
    cpy_r_r48 = CPyImport_ImportFromMany(cpy_r_r46, cpy_r_r45, cpy_r_r45, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 24, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_brownie = cpy_r_r48;
    CPy_INCREF(CPyModule_brownie);
    CPy_DECREF(cpy_r_r48);
    cpy_r_r49 = CPyStatics[206]; /* ('ReturnValue',) */
    cpy_r_r50 = CPyStatics[134]; /* 'brownie.convert.datatypes' */
    cpy_r_r51 = CPyStatic_globals;
    cpy_r_r52 = CPyImport_ImportFromMany(cpy_r_r50, cpy_r_r49, cpy_r_r49, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 25, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_brownie___convert___datatypes = cpy_r_r52;
    CPy_INCREF(CPyModule_brownie___convert___datatypes);
    CPy_DECREF(cpy_r_r52);
    cpy_r_r53 = CPyStatics[207]; /* ('ABIType', 'HexString', 'TupleType', '_check_array',
                                    '_get_abi_types', 'to_bool', 'to_decimal', 'to_int',
                                    'to_string', 'to_uint') */
    cpy_r_r54 = CPyStatics[127]; /* 'brownie.convert.normalize' */
    cpy_r_r55 = CPyStatic_globals;
    cpy_r_r56 = CPyImport_ImportFromMany(cpy_r_r54, cpy_r_r53, cpy_r_r53, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 26, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_brownie___convert___normalize = cpy_r_r56;
    CPy_INCREF(CPyModule_brownie___convert___normalize);
    CPy_DECREF(cpy_r_r56);
    cpy_r_r57 = CPyStatics[208]; /* ('get_type_strings',) */
    cpy_r_r58 = CPyStatics[136]; /* 'brownie.convert.utils' */
    cpy_r_r59 = CPyStatic_globals;
    cpy_r_r60 = CPyImport_ImportFromMany(cpy_r_r58, cpy_r_r57, cpy_r_r57, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 38, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_brownie___convert___utils = cpy_r_r60;
    CPy_INCREF(CPyModule_brownie___convert___utils);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r61 = CPyStatics[209]; /* ('VirtualMachineError',) */
    cpy_r_r62 = CPyStatics[137]; /* 'brownie.exceptions' */
    cpy_r_r63 = CPyStatic_globals;
    cpy_r_r64 = CPyImport_ImportFromMany(cpy_r_r62, cpy_r_r61, cpy_r_r61, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 39, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_brownie___exceptions = cpy_r_r64;
    CPy_INCREF(CPyModule_brownie___exceptions);
    CPy_DECREF(cpy_r_r64);
    cpy_r_r65 = CPyStatics[210]; /* ('Contract', 'ContractCall') */
    cpy_r_r66 = CPyStatics[129]; /* 'brownie.network.contract' */
    cpy_r_r67 = CPyStatic_globals;
    cpy_r_r68 = CPyImport_ImportFromMany(cpy_r_r66, cpy_r_r65, cpy_r_r65, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 40, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_brownie___network___contract = cpy_r_r68;
    CPy_INCREF(CPyModule_brownie___network___contract);
    CPy_DECREF(cpy_r_r68);
    cpy_r_r69 = CPyStatics[211]; /* ('SOLIDITY_ERROR_CODES',) */
    cpy_r_r70 = CPyStatics[139]; /* 'brownie.project.compiler.solidity' */
    cpy_r_r71 = CPyStatic_globals;
    cpy_r_r72 = CPyImport_ImportFromMany(cpy_r_r70, cpy_r_r69, cpy_r_r69, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 41, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_brownie___project___compiler___solidity = cpy_r_r72;
    CPy_INCREF(CPyModule_brownie___project___compiler___solidity);
    CPy_DECREF(cpy_r_r72);
    cpy_r_r73 = CPyStatics[212]; /* ('InsufficientDataBytes',) */
    cpy_r_r74 = CPyStatics[140]; /* 'eth_abi.exceptions' */
    cpy_r_r75 = CPyStatic_globals;
    cpy_r_r76 = CPyImport_ImportFromMany(cpy_r_r74, cpy_r_r73, cpy_r_r73, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 42, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_eth_abi___exceptions = cpy_r_r76;
    CPy_INCREF(CPyModule_eth_abi___exceptions);
    CPy_DECREF(cpy_r_r76);
    cpy_r_r77 = CPyStatics[213]; /* ('HexStr',) */
    cpy_r_r78 = CPyStatics[142]; /* 'eth_typing' */
    cpy_r_r79 = CPyStatic_globals;
    cpy_r_r80 = CPyImport_ImportFromMany(cpy_r_r78, cpy_r_r77, cpy_r_r77, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 43, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_eth_typing = cpy_r_r80;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r80);
    cpy_r_r81 = CPyStatics[214]; /* ('Address',) */
    cpy_r_r82 = CPyStatics[144]; /* 'evmspec.data' */
    cpy_r_r83 = CPyStatic_globals;
    cpy_r_r84 = CPyImport_ImportFromMany(cpy_r_r82, cpy_r_r81, cpy_r_r81, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 44, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_evmspec___data = cpy_r_r84;
    CPy_INCREF(CPyModule_evmspec___data);
    CPy_DECREF(cpy_r_r84);
    cpy_r_r85 = CPyStatics[215]; /* ('HexBytes',) */
    cpy_r_r86 = CPyStatics[145]; /* 'hexbytes' */
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyImport_ImportFromMany(cpy_r_r86, cpy_r_r85, cpy_r_r85, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 45, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_hexbytes = cpy_r_r88;
    CPy_INCREF(CPyModule_hexbytes);
    CPy_DECREF(cpy_r_r88);
    cpy_r_r89 = CPyStatics[216]; /* ('BytesLike',) */
    cpy_r_r90 = CPyStatics[147]; /* 'hexbytes.main' */
    cpy_r_r91 = CPyStatic_globals;
    cpy_r_r92 = CPyImport_ImportFromMany(cpy_r_r90, cpy_r_r89, cpy_r_r89, cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 46, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_hexbytes___main = cpy_r_r92;
    CPy_INCREF(CPyModule_hexbytes___main);
    CPy_DECREF(cpy_r_r92);
    cpy_r_r93 = CPyStatics[217]; /* ('MULTICALL2_ADDRESSES',) */
    cpy_r_r94 = CPyStatics[149]; /* 'multicall.constants' */
    cpy_r_r95 = CPyStatic_globals;
    cpy_r_r96 = CPyImport_ImportFromMany(cpy_r_r94, cpy_r_r93, cpy_r_r93, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 47, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_multicall___constants = cpy_r_r96;
    CPy_INCREF(CPyModule_multicall___constants);
    CPy_DECREF(cpy_r_r96);
    cpy_r_r97 = CPyStatics[218]; /* ('BlockIdentifier',) */
    cpy_r_r98 = CPyStatics[151]; /* 'web3.types' */
    cpy_r_r99 = CPyStatic_globals;
    cpy_r_r100 = CPyImport_ImportFromMany(cpy_r_r98, cpy_r_r97, cpy_r_r97, cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 48, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_web3___types = cpy_r_r100;
    CPy_INCREF(CPyModule_web3___types);
    CPy_DECREF(cpy_r_r100);
    cpy_r_r101 = CPyStatics[219]; /* ('ENVIRONMENT_VARIABLES',) */
    cpy_r_r102 = CPyStatics[220]; /* ('ENVS',) */
    cpy_r_r103 = CPyStatics[153]; /* 'dank_mids' */
    cpy_r_r104 = CPyStatic_globals;
    cpy_r_r105 = CPyImport_ImportFromMany(cpy_r_r103, cpy_r_r101, cpy_r_r102, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 50, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_dank_mids = cpy_r_r105;
    CPy_INCREF(CPyModule_dank_mids);
    CPy_DECREF(cpy_r_r105);
    cpy_r_r106 = CPyStatics[221]; /* ('ContractMethod',) */
    cpy_r_r107 = CPyStatics[155]; /* 'dank_mids.brownie_patch.types' */
    cpy_r_r108 = CPyStatic_globals;
    cpy_r_r109 = CPyImport_ImportFromMany(cpy_r_r107, cpy_r_r106, cpy_r_r106, cpy_r_r108);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 51, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_dank_mids___brownie_patch___types = cpy_r_r109;
    CPy_INCREF(CPyModule_dank_mids___brownie_patch___types);
    CPy_DECREF(cpy_r_r109);
    cpy_r_r110 = CPyStatics[222]; /* ('Revert',) */
    cpy_r_r111 = CPyStatics[156]; /* 'dank_mids.exceptions' */
    cpy_r_r112 = CPyStatic_globals;
    cpy_r_r113 = CPyImport_ImportFromMany(cpy_r_r111, cpy_r_r110, cpy_r_r110, cpy_r_r112);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 52, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_dank_mids___exceptions = cpy_r_r113;
    CPy_INCREF(CPyModule_dank_mids___exceptions);
    CPy_DECREF(cpy_r_r113);
    cpy_r_r114 = CPyStatics[223]; /* ('lru_cache_lite_nonull',) */
    cpy_r_r115 = CPyStatics[158]; /* 'dank_mids.helpers.lru_cache' */
    cpy_r_r116 = CPyStatic_globals;
    cpy_r_r117 = CPyImport_ImportFromMany(cpy_r_r115, cpy_r_r114, cpy_r_r114, cpy_r_r116);
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 53, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_dank_mids___helpers___lru_cache = cpy_r_r117;
    CPy_INCREF(CPyModule_dank_mids___helpers___lru_cache);
    CPy_DECREF(cpy_r_r117);
    cpy_r_r118 = CPyStatics[224]; /* ('DankWeb3',) */
    cpy_r_r119 = CPyStatics[160]; /* 'dank_mids.helpers._helpers' */
    cpy_r_r120 = CPyStatic_globals;
    cpy_r_r121 = CPyImport_ImportFromMany(cpy_r_r119, cpy_r_r118, cpy_r_r118, cpy_r_r120);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 54, CPyStatic_globals);
        goto CPyL154;
    }
    CPyModule_dank_mids___helpers____helpers = cpy_r_r121;
    CPy_INCREF(CPyModule_dank_mids___helpers____helpers);
    CPy_DECREF(cpy_r_r121);
    cpy_r_r122 = CPyStatics[161]; /* '_T' */
    cpy_r_r123 = CPyStatic_globals;
    cpy_r_r124 = CPyStatics[124]; /* 'TypeVar' */
    cpy_r_r125 = CPyDict_GetItem(cpy_r_r123, cpy_r_r124);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 57, CPyStatic_globals);
        goto CPyL154;
    }
    PyObject *cpy_r_r126[1] = {cpy_r_r122};
    cpy_r_r127 = (PyObject **)&cpy_r_r126;
    cpy_r_r128 = _PyObject_Vectorcall(cpy_r_r125, cpy_r_r127, 1, 0);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 57, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r129 = CPyStatic_globals;
    cpy_r_r130 = CPyStatics[161]; /* '_T' */
    cpy_r_r131 = CPyDict_SetItem(cpy_r_r129, cpy_r_r130, cpy_r_r128);
    CPy_DECREF(cpy_r_r128);
    cpy_r_r132 = cpy_r_r131 >= 0;
    if (unlikely(!cpy_r_r132)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 57, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r133 = CPyStatics[162]; /* 'TypeStr' */
    cpy_r_r134 = (PyObject *)&PyUnicode_Type;
    cpy_r_r135 = CPyStatic_globals;
    cpy_r_r136 = CPyStatics[120]; /* 'NewType' */
    cpy_r_r137 = CPyDict_GetItem(cpy_r_r135, cpy_r_r136);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 58, CPyStatic_globals);
        goto CPyL154;
    }
    PyObject *cpy_r_r138[2] = {cpy_r_r133, cpy_r_r134};
    cpy_r_r139 = (PyObject **)&cpy_r_r138;
    cpy_r_r140 = _PyObject_Vectorcall(cpy_r_r137, cpy_r_r139, 2, 0);
    CPy_DECREF(cpy_r_r137);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 58, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r141 = CPyStatic_globals;
    cpy_r_r142 = CPyStatics[162]; /* 'TypeStr' */
    cpy_r_r143 = CPyDict_SetItem(cpy_r_r141, cpy_r_r142, cpy_r_r140);
    CPy_DECREF(cpy_r_r140);
    cpy_r_r144 = cpy_r_r143 >= 0;
    if (unlikely(!cpy_r_r144)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 58, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r145 = CPyStatic_globals;
    cpy_r_r146 = CPyStatics[119]; /* 'List' */
    cpy_r_r147 = CPyDict_GetItem(cpy_r_r145, cpy_r_r146);
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r148 = CPyStatic_globals;
    cpy_r_r149 = CPyStatics[162]; /* 'TypeStr' */
    cpy_r_r150 = CPyDict_GetItem(cpy_r_r148, cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL155;
    }
    cpy_r_r151 = PyObject_GetItem(cpy_r_r147, cpy_r_r150);
    CPy_DECREF(cpy_r_r147);
    CPy_DECREF(cpy_r_r150);
    if (unlikely(cpy_r_r151 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r152 = CPyStatic_globals;
    cpy_r_r153 = CPyStatics[163]; /* 'TypeStrs' */
    cpy_r_r154 = CPyDict_SetItem(cpy_r_r152, cpy_r_r153, cpy_r_r151);
    CPy_DECREF(cpy_r_r151);
    cpy_r_r155 = cpy_r_r154 >= 0;
    if (unlikely(!cpy_r_r155)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 59, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r156 = CPyStatic_globals;
    cpy_r_r157 = CPyStatics[125]; /* 'Union' */
    cpy_r_r158 = CPyDict_GetItem(cpy_r_r156, cpy_r_r157);
    if (unlikely(cpy_r_r158 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r159 = CPyStatic_globals;
    cpy_r_r160 = CPyStatics[119]; /* 'List' */
    cpy_r_r161 = CPyDict_GetItem(cpy_r_r159, cpy_r_r160);
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r162 = CPyStatic_globals;
    cpy_r_r163 = CPyStatics[161]; /* '_T' */
    cpy_r_r164 = CPyDict_GetItem(cpy_r_r162, cpy_r_r163);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL157;
    }
    cpy_r_r165 = PyObject_GetItem(cpy_r_r161, cpy_r_r164);
    CPy_DECREF(cpy_r_r161);
    CPy_DECREF(cpy_r_r164);
    if (unlikely(cpy_r_r165 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r166 = CPyStatic_globals;
    cpy_r_r167 = CPyStatics[123]; /* 'Tuple' */
    cpy_r_r168 = CPyDict_GetItem(cpy_r_r166, cpy_r_r167);
    if (unlikely(cpy_r_r168 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL158;
    }
    cpy_r_r169 = CPyStatic_globals;
    cpy_r_r170 = CPyStatics[161]; /* '_T' */
    cpy_r_r171 = CPyDict_GetItem(cpy_r_r169, cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL159;
    }
    cpy_r_r172 = PyObject_GetItem(cpy_r_r168, cpy_r_r171);
    CPy_DECREF(cpy_r_r168);
    CPy_DECREF(cpy_r_r171);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL158;
    }
    cpy_r_r173.f0 = cpy_r_r165;
    cpy_r_r173.f1 = cpy_r_r172;
    cpy_r_r174 = PyTuple_New(2);
    if (unlikely(cpy_r_r174 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp39 = cpy_r_r173.f0;
    PyTuple_SET_ITEM(cpy_r_r174, 0, __tmp39);
    PyObject *__tmp40 = cpy_r_r173.f1;
    PyTuple_SET_ITEM(cpy_r_r174, 1, __tmp40);
    cpy_r_r175 = PyObject_GetItem(cpy_r_r158, cpy_r_r174);
    CPy_DECREF(cpy_r_r158);
    CPy_DECREF(cpy_r_r174);
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r176 = CPyStatic_globals;
    cpy_r_r177 = CPyStatics[164]; /* 'ListOrTuple' */
    cpy_r_r178 = CPyDict_SetItem(cpy_r_r176, cpy_r_r177, cpy_r_r175);
    CPy_DECREF(cpy_r_r175);
    cpy_r_r179 = cpy_r_r178 >= 0;
    if (unlikely(!cpy_r_r179)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 60, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r180 = CPyStatics[165]; /* 'AbiDict' */
    cpy_r_r181 = CPyStatic_globals;
    cpy_r_r182 = CPyStatics[117]; /* 'Dict' */
    cpy_r_r183 = CPyDict_GetItem(cpy_r_r181, cpy_r_r182);
    if (unlikely(cpy_r_r183 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r184 = (PyObject *)&PyUnicode_Type;
    cpy_r_r185 = CPyStatic_globals;
    cpy_r_r186 = CPyStatics[115]; /* 'Any' */
    cpy_r_r187 = CPyDict_GetItem(cpy_r_r185, cpy_r_r186);
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL160;
    }
    CPy_INCREF(cpy_r_r184);
    cpy_r_r188.f0 = cpy_r_r184;
    cpy_r_r188.f1 = cpy_r_r187;
    cpy_r_r189 = PyTuple_New(2);
    if (unlikely(cpy_r_r189 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp41 = cpy_r_r188.f0;
    PyTuple_SET_ITEM(cpy_r_r189, 0, __tmp41);
    PyObject *__tmp42 = cpy_r_r188.f1;
    PyTuple_SET_ITEM(cpy_r_r189, 1, __tmp42);
    cpy_r_r190 = PyObject_GetItem(cpy_r_r183, cpy_r_r189);
    CPy_DECREF(cpy_r_r183);
    CPy_DECREF(cpy_r_r189);
    if (unlikely(cpy_r_r190 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r191 = CPyStatic_globals;
    cpy_r_r192 = CPyStatics[120]; /* 'NewType' */
    cpy_r_r193 = CPyDict_GetItem(cpy_r_r191, cpy_r_r192);
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL161;
    }
    PyObject *cpy_r_r194[2] = {cpy_r_r180, cpy_r_r190};
    cpy_r_r195 = (PyObject **)&cpy_r_r194;
    cpy_r_r196 = _PyObject_Vectorcall(cpy_r_r193, cpy_r_r195, 2, 0);
    CPy_DECREF(cpy_r_r193);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL161;
    }
    CPy_DECREF(cpy_r_r190);
    cpy_r_r197 = CPyStatic_globals;
    cpy_r_r198 = CPyStatics[165]; /* 'AbiDict' */
    cpy_r_r199 = CPyDict_SetItem(cpy_r_r197, cpy_r_r198, cpy_r_r196);
    CPy_DECREF(cpy_r_r196);
    cpy_r_r200 = cpy_r_r199 >= 0;
    if (unlikely(!cpy_r_r200)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 61, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r201 = CPyStatic_globals;
    cpy_r_r202 = CPyStatics[166]; /* '__name__' */
    cpy_r_r203 = CPyDict_GetItem(cpy_r_r201, cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 64, CPyStatic_globals);
        goto CPyL154;
    }
    if (likely(PyUnicode_Check(cpy_r_r203)))
        cpy_r_r204 = cpy_r_r203;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "<module>", 64, CPyStatic_globals, "str", cpy_r_r203);
        goto CPyL154;
    }
    cpy_r_r205 = CPyStatic_globals;
    cpy_r_r206 = CPyStatics[111]; /* 'getLogger' */
    cpy_r_r207 = CPyDict_GetItem(cpy_r_r205, cpy_r_r206);
    if (unlikely(cpy_r_r207 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 64, CPyStatic_globals);
        goto CPyL162;
    }
    PyObject *cpy_r_r208[1] = {cpy_r_r204};
    cpy_r_r209 = (PyObject **)&cpy_r_r208;
    cpy_r_r210 = _PyObject_Vectorcall(cpy_r_r207, cpy_r_r209, 1, 0);
    CPy_DECREF(cpy_r_r207);
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 64, CPyStatic_globals);
        goto CPyL162;
    }
    CPy_DECREF(cpy_r_r204);
    cpy_r_r211 = CPyStatic_globals;
    cpy_r_r212 = CPyStatics[43]; /* 'logger' */
    cpy_r_r213 = CPyDict_SetItem(cpy_r_r211, cpy_r_r212, cpy_r_r210);
    CPy_DECREF(cpy_r_r210);
    cpy_r_r214 = cpy_r_r213 >= 0;
    if (unlikely(!cpy_r_r214)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 64, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r215 = CPyDef___mypyc_lambda__0_obj();
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 66, CPyStatic_globals);
        goto CPyL154;
    }
    CPyStatic_encode = cpy_r_r215;
    CPy_INCREF(CPyStatic_encode);
    cpy_r_r216 = CPyStatic_globals;
    cpy_r_r217 = CPyStatics[167]; /* 'encode' */
    cpy_r_r218 = CPyDict_SetItem(cpy_r_r216, cpy_r_r217, cpy_r_r215);
    CPy_DECREF(cpy_r_r215);
    cpy_r_r219 = cpy_r_r218 >= 0;
    if (unlikely(!cpy_r_r219)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 66, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r220 = CPyDef___mypyc_lambda__1_obj();
    if (unlikely(cpy_r_r220 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 85, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r221 = CPyStatic_globals;
    cpy_r_r222 = CPyStatics[50]; /* 'decode' */
    cpy_r_r223 = CPyDict_SetItem(cpy_r_r221, cpy_r_r222, cpy_r_r220);
    CPy_DECREF(cpy_r_r220);
    cpy_r_r224 = cpy_r_r223 >= 0;
    if (unlikely(!cpy_r_r224)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 85, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r225 = CPyStatic_globals;
    cpy_r_r226 = CPyStatics[143]; /* 'Address' */
    cpy_r_r227 = CPyDict_GetItem(cpy_r_r225, cpy_r_r226);
    if (unlikely(cpy_r_r227 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 106, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r228 = CPyStatics[168]; /* 'checksum' */
    cpy_r_r229 = CPyObject_GetAttr(cpy_r_r227, cpy_r_r228);
    CPy_DECREF(cpy_r_r227);
    if (unlikely(cpy_r_r229 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 106, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r230 = CPyStatic_globals;
    cpy_r_r231 = CPyStatics[103]; /* 'to_checksum_address' */
    cpy_r_r232 = CPyDict_SetItem(cpy_r_r230, cpy_r_r231, cpy_r_r229);
    CPy_DECREF(cpy_r_r229);
    cpy_r_r233 = cpy_r_r232 >= 0;
    if (unlikely(!cpy_r_r233)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 106, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r234 = CPyStatic_globals;
    cpy_r_r235 = CPyStatics[15]; /* '_get_coroutine_fn' */
    cpy_r_r236 = CPyDict_GetItem(cpy_r_r234, cpy_r_r235);
    if (unlikely(cpy_r_r236 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 124, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r237 = CPyStatic_globals;
    cpy_r_r238 = CPyStatics[157]; /* 'lru_cache_lite_nonull' */
    cpy_r_r239 = CPyDict_GetItem(cpy_r_r237, cpy_r_r238);
    if (unlikely(cpy_r_r239 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 124, CPyStatic_globals);
        goto CPyL163;
    }
    PyObject *cpy_r_r240[1] = {cpy_r_r236};
    cpy_r_r241 = (PyObject **)&cpy_r_r240;
    cpy_r_r242 = _PyObject_Vectorcall(cpy_r_r239, cpy_r_r241, 1, 0);
    CPy_DECREF(cpy_r_r239);
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 124, CPyStatic_globals);
        goto CPyL163;
    }
    CPy_DECREF(cpy_r_r236);
    cpy_r_r243 = CPyStatic_globals;
    cpy_r_r244 = CPyStatics[15]; /* '_get_coroutine_fn' */
    cpy_r_r245 = CPyDict_SetItem(cpy_r_r243, cpy_r_r244, cpy_r_r242);
    CPy_DECREF(cpy_r_r242);
    cpy_r_r246 = cpy_r_r245 >= 0;
    if (unlikely(!cpy_r_r246)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 124, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r247 = CPyStatic_globals;
    cpy_r_r248 = CPyStatics[62]; /* 'eth_abi' */
    cpy_r_r249 = CPyDict_GetItem(cpy_r_r247, cpy_r_r248);
    if (unlikely(cpy_r_r249 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 221, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r250 = CPyStatics[167]; /* 'encode' */
    cpy_r_r251 = PyObject_HasAttr(cpy_r_r249, cpy_r_r250);
    CPy_DECREF(cpy_r_r249);
    if (!cpy_r_r251) goto CPyL76;
    cpy_r_r252 = CPyStatic_globals;
    cpy_r_r253 = CPyStatics[62]; /* 'eth_abi' */
    cpy_r_r254 = CPyDict_GetItem(cpy_r_r252, cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 221, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r255 = CPyStatics[167]; /* 'encode' */
    cpy_r_r256 = CPyObject_GetAttr(cpy_r_r254, cpy_r_r255);
    CPy_DECREF(cpy_r_r254);
    if (unlikely(cpy_r_r256 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 221, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r257 = cpy_r_r256;
    goto CPyL79;
CPyL76: ;
    cpy_r_r258 = CPyStatic_globals;
    cpy_r_r259 = CPyStatics[62]; /* 'eth_abi' */
    cpy_r_r260 = CPyDict_GetItem(cpy_r_r258, cpy_r_r259);
    if (unlikely(cpy_r_r260 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 221, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r261 = CPyStatics[169]; /* 'encode_abi' */
    cpy_r_r262 = CPyObject_GetAttr(cpy_r_r260, cpy_r_r261);
    CPy_DECREF(cpy_r_r260);
    if (unlikely(cpy_r_r262 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 221, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r257 = cpy_r_r262;
CPyL79: ;
    cpy_r_r263 = CPyStatic_globals;
    cpy_r_r264 = CPyStatics[56]; /* '__eth_abi_encode' */
    cpy_r_r265 = CPyDict_SetItem(cpy_r_r263, cpy_r_r264, cpy_r_r257);
    CPy_DECREF(cpy_r_r257);
    cpy_r_r266 = cpy_r_r265 >= 0;
    if (unlikely(!cpy_r_r266)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 221, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r267 = CPyStatic_globals;
    cpy_r_r268 = CPyStatics[62]; /* 'eth_abi' */
    cpy_r_r269 = CPyDict_GetItem(cpy_r_r267, cpy_r_r268);
    if (unlikely(cpy_r_r269 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 222, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r270 = CPyStatics[50]; /* 'decode' */
    cpy_r_r271 = PyObject_HasAttr(cpy_r_r269, cpy_r_r270);
    CPy_DECREF(cpy_r_r269);
    if (!cpy_r_r271) goto CPyL85;
    cpy_r_r272 = CPyStatic_globals;
    cpy_r_r273 = CPyStatics[62]; /* 'eth_abi' */
    cpy_r_r274 = CPyDict_GetItem(cpy_r_r272, cpy_r_r273);
    if (unlikely(cpy_r_r274 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 222, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r275 = CPyStatics[50]; /* 'decode' */
    cpy_r_r276 = CPyObject_GetAttr(cpy_r_r274, cpy_r_r275);
    CPy_DECREF(cpy_r_r274);
    if (unlikely(cpy_r_r276 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 222, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r277 = cpy_r_r276;
    goto CPyL88;
CPyL85: ;
    cpy_r_r278 = CPyStatic_globals;
    cpy_r_r279 = CPyStatics[62]; /* 'eth_abi' */
    cpy_r_r280 = CPyDict_GetItem(cpy_r_r278, cpy_r_r279);
    if (unlikely(cpy_r_r280 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 222, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r281 = CPyStatics[64]; /* 'decode_abi' */
    cpy_r_r282 = CPyObject_GetAttr(cpy_r_r280, cpy_r_r281);
    CPy_DECREF(cpy_r_r280);
    if (unlikely(cpy_r_r282 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 222, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r277 = cpy_r_r282;
CPyL88: ;
    cpy_r_r283 = CPyStatic_globals;
    cpy_r_r284 = CPyStatics[60]; /* '__eth_abi_decode' */
    cpy_r_r285 = CPyDict_SetItem(cpy_r_r283, cpy_r_r284, cpy_r_r277);
    CPy_DECREF(cpy_r_r277);
    cpy_r_r286 = cpy_r_r285 >= 0;
    if (unlikely(!cpy_r_r286)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 222, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r287 = CPyStatics[170]; /* '0xcA11bde05977b3631167028862bE2a173976CA11' */
    cpy_r_r288 = PySet_New(NULL);
    if (unlikely(cpy_r_r288 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r289 = PySet_Add(cpy_r_r288, cpy_r_r287);
    cpy_r_r290 = cpy_r_r289 >= 0;
    if (unlikely(!cpy_r_r290)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL164;
    }
    cpy_r_r291 = CPyStatic_globals;
    cpy_r_r292 = CPyStatics[12]; /* '_skip_proc_pool' */
    cpy_r_r293 = CPyDict_SetItem(cpy_r_r291, cpy_r_r292, cpy_r_r288);
    CPy_DECREF(cpy_r_r288);
    cpy_r_r294 = cpy_r_r293 >= 0;
    if (unlikely(!cpy_r_r294)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 234, CPyStatic_globals);
        goto CPyL154;
    }
CPyL92: ;
    if (!1) goto CPyL110;
    cpy_r_r295 = CPyStatic_globals;
    cpy_r_r296 = CPyStatics[133]; /* 'chain' */
    cpy_r_r297 = CPyDict_GetItem(cpy_r_r295, cpy_r_r296);
    if (unlikely(cpy_r_r297 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 238, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r298 = CPyStatics[171]; /* 'id' */
    cpy_r_r299 = CPyObject_GetAttr(cpy_r_r297, cpy_r_r298);
    CPy_DECREF(cpy_r_r297);
    if (unlikely(cpy_r_r299 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 238, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r300 = CPyStatic_globals;
    cpy_r_r301 = CPyStatics[172]; /* 'chainid' */
    cpy_r_r302 = CPyDict_SetItem(cpy_r_r300, cpy_r_r301, cpy_r_r299);
    CPy_DECREF(cpy_r_r299);
    cpy_r_r303 = cpy_r_r302 >= 0;
    if (unlikely(!cpy_r_r303)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 238, CPyStatic_globals);
    } else
        goto CPyL110;
CPyL96: ;
    cpy_r_r304 = CPy_CatchError();
    cpy_r_r305 = CPyModule_builtins;
    cpy_r_r306 = CPyStatics[49]; /* 'Exception' */
    cpy_r_r307 = CPyObject_GetAttr(cpy_r_r305, cpy_r_r306);
    if (unlikely(cpy_r_r307 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 240, CPyStatic_globals);
        goto CPyL108;
    }
    cpy_r_r308 = CPy_ExceptionMatches(cpy_r_r307);
    CPy_DecRef(cpy_r_r307);
    if (!cpy_r_r308) goto CPyL105;
    cpy_r_r309 = CPyStatic_globals;
    cpy_r_r310 = CPyStatics[173]; /* 'e' */
    cpy_r_r311 = CPy_GetExcValue();
    cpy_r_r312 = CPyDict_SetItem(cpy_r_r309, cpy_r_r310, cpy_r_r311);
    CPy_DecRef(cpy_r_r311);
    cpy_r_r313 = cpy_r_r312 >= 0;
    if (unlikely(!cpy_r_r313)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 240, CPyStatic_globals);
        goto CPyL108;
    }
    cpy_r_r314 = CPyStatics[174]; /* '429' */
    cpy_r_r315 = CPyStatic_globals;
    cpy_r_r316 = CPyStatics[173]; /* 'e' */
    cpy_r_r317 = CPyDict_GetItem(cpy_r_r315, cpy_r_r316);
    if (unlikely(cpy_r_r317 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 241, CPyStatic_globals);
        goto CPyL108;
    }
    cpy_r_r318 = PyObject_Str(cpy_r_r317);
    CPy_DecRef(cpy_r_r317);
    if (unlikely(cpy_r_r318 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 241, CPyStatic_globals);
        goto CPyL108;
    }
    cpy_r_r319 = PySequence_Contains(cpy_r_r318, cpy_r_r314);
    CPy_DecRef(cpy_r_r318);
    cpy_r_r320 = cpy_r_r319 >= 0;
    if (unlikely(!cpy_r_r320)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 241, CPyStatic_globals);
        goto CPyL108;
    }
    cpy_r_r321 = cpy_r_r319;
    cpy_r_r322 = cpy_r_r321 ^ 1;
    if (!cpy_r_r322) goto CPyL107;
    CPy_Reraise();
    if (!0) {
        goto CPyL108;
    } else
        goto CPyL165;
CPyL104: ;
    CPy_Unreachable();
CPyL105: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL108;
    } else
        goto CPyL166;
CPyL106: ;
    CPy_Unreachable();
CPyL107: ;
    CPy_RestoreExcInfo(cpy_r_r304);
    CPy_DecRef(cpy_r_r304.f0);
    CPy_DecRef(cpy_r_r304.f1);
    CPy_DecRef(cpy_r_r304.f2);
    goto CPyL92;
CPyL108: ;
    CPy_RestoreExcInfo(cpy_r_r304);
    CPy_DecRef(cpy_r_r304.f0);
    CPy_DecRef(cpy_r_r304.f1);
    CPy_DecRef(cpy_r_r304.f2);
    cpy_r_r323 = CPy_KeepPropagating();
    if (!cpy_r_r323) goto CPyL154;
    CPy_Unreachable();
CPyL110: ;
    cpy_r_r324 = CPyStatic_globals;
    cpy_r_r325 = CPyStatics[148]; /* 'MULTICALL2_ADDRESSES' */
    cpy_r_r326 = CPyDict_GetItem(cpy_r_r324, cpy_r_r325);
    if (unlikely(cpy_r_r326 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 243, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r327 = CPyStatic_globals;
    cpy_r_r328 = CPyStatics[172]; /* 'chainid' */
    cpy_r_r329 = CPyDict_GetItem(cpy_r_r327, cpy_r_r328);
    if (unlikely(cpy_r_r329 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 243, CPyStatic_globals);
        goto CPyL167;
    }
    cpy_r_r330 = CPyStatics[175]; /* 'get' */
    cpy_r_r331 = Py_None;
    cpy_r_r332 = CPyObject_CallMethodObjArgs(cpy_r_r326, cpy_r_r330, cpy_r_r329, cpy_r_r331, NULL);
    CPy_DECREF(cpy_r_r326);
    CPy_DECREF(cpy_r_r329);
    if (unlikely(cpy_r_r332 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 243, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r333 = CPyStatic_globals;
    cpy_r_r334 = CPyStatics[176]; /* 'multicall2' */
    cpy_r_r335 = CPyDict_SetItem(cpy_r_r333, cpy_r_r334, cpy_r_r332);
    cpy_r_r336 = cpy_r_r335 >= 0;
    if (unlikely(!cpy_r_r336)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 243, CPyStatic_globals);
        goto CPyL168;
    }
    cpy_r_r337 = PyObject_IsTrue(cpy_r_r332);
    CPy_DECREF(cpy_r_r332);
    cpy_r_r338 = cpy_r_r337 >= 0;
    if (unlikely(!cpy_r_r338)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 243, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r339 = cpy_r_r337;
    if (!cpy_r_r339) goto CPyL122;
    cpy_r_r340 = CPyStatic_globals;
    cpy_r_r341 = CPyStatics[12]; /* '_skip_proc_pool' */
    cpy_r_r342 = CPyDict_GetItem(cpy_r_r340, cpy_r_r341);
    if (unlikely(cpy_r_r342 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 244, CPyStatic_globals);
        goto CPyL154;
    }
    if (likely(PySet_Check(cpy_r_r342)))
        cpy_r_r343 = cpy_r_r342;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/call.py", "<module>", 244, CPyStatic_globals, "set", cpy_r_r342);
        goto CPyL154;
    }
    cpy_r_r344 = CPyStatic_globals;
    cpy_r_r345 = CPyStatics[176]; /* 'multicall2' */
    cpy_r_r346 = CPyDict_GetItem(cpy_r_r344, cpy_r_r345);
    if (unlikely(cpy_r_r346 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 244, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r347 = CPyStatic_globals;
    cpy_r_r348 = CPyStatics[103]; /* 'to_checksum_address' */
    cpy_r_r349 = CPyDict_GetItem(cpy_r_r347, cpy_r_r348);
    if (unlikely(cpy_r_r349 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 244, CPyStatic_globals);
        goto CPyL170;
    }
    PyObject *cpy_r_r350[1] = {cpy_r_r346};
    cpy_r_r351 = (PyObject **)&cpy_r_r350;
    cpy_r_r352 = _PyObject_Vectorcall(cpy_r_r349, cpy_r_r351, 1, 0);
    CPy_DECREF(cpy_r_r349);
    if (unlikely(cpy_r_r352 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 244, CPyStatic_globals);
        goto CPyL170;
    }
    CPy_DECREF(cpy_r_r346);
    cpy_r_r353 = PySet_Add(cpy_r_r343, cpy_r_r352);
    CPy_DECREF(cpy_r_r343);
    CPy_DECREF(cpy_r_r352);
    cpy_r_r354 = cpy_r_r353 >= 0;
    if (unlikely(!cpy_r_r354)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 244, CPyStatic_globals);
        goto CPyL154;
    }
CPyL122: ;
    cpy_r_r355 = CPyStatic_globals;
    cpy_r_r356 = CPyStatics[177]; /* 'format_input_but_cache_checksums' */
    cpy_r_r357 = CPyDict_GetItem(cpy_r_r355, cpy_r_r356);
    if (unlikely(cpy_r_r357 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 304, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r358 = CPyStatic_globals;
    cpy_r_r359 = CPyStatics[128]; /* 'brownie' */
    cpy_r_r360 = CPyDict_GetItem(cpy_r_r358, cpy_r_r359);
    if (unlikely(cpy_r_r360 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 304, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r361 = CPyStatics[178]; /* 'network' */
    cpy_r_r362 = CPyObject_GetAttr(cpy_r_r360, cpy_r_r361);
    CPy_DECREF(cpy_r_r360);
    if (unlikely(cpy_r_r362 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 304, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r363 = CPyStatics[179]; /* 'contract' */
    cpy_r_r364 = CPyObject_GetAttr(cpy_r_r362, cpy_r_r363);
    CPy_DECREF(cpy_r_r362);
    if (unlikely(cpy_r_r364 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 304, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r365 = CPyStatics[180]; /* 'format_input' */
    cpy_r_r366 = PyObject_SetAttr(cpy_r_r364, cpy_r_r365, cpy_r_r357);
    CPy_DECREF(cpy_r_r364);
    CPy_DECREF(cpy_r_r357);
    cpy_r_r367 = cpy_r_r366 >= 0;
    if (unlikely(!cpy_r_r367)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 304, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r368 = CPyStatic_globals;
    cpy_r_r369 = CPyStatics[181]; /* 'format_output_but_cache_checksums' */
    cpy_r_r370 = CPyDict_GetItem(cpy_r_r368, cpy_r_r369);
    if (unlikely(cpy_r_r370 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 305, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r371 = CPyStatic_globals;
    cpy_r_r372 = CPyStatics[128]; /* 'brownie' */
    cpy_r_r373 = CPyDict_GetItem(cpy_r_r371, cpy_r_r372);
    if (unlikely(cpy_r_r373 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 305, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r374 = CPyStatics[178]; /* 'network' */
    cpy_r_r375 = CPyObject_GetAttr(cpy_r_r373, cpy_r_r374);
    CPy_DECREF(cpy_r_r373);
    if (unlikely(cpy_r_r375 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 305, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r376 = CPyStatics[179]; /* 'contract' */
    cpy_r_r377 = CPyObject_GetAttr(cpy_r_r375, cpy_r_r376);
    CPy_DECREF(cpy_r_r375);
    if (unlikely(cpy_r_r377 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 305, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r378 = CPyStatics[182]; /* 'format_output' */
    cpy_r_r379 = PyObject_SetAttr(cpy_r_r377, cpy_r_r378, cpy_r_r370);
    CPy_DECREF(cpy_r_r377);
    CPy_DECREF(cpy_r_r370);
    cpy_r_r380 = cpy_r_r379 >= 0;
    if (unlikely(!cpy_r_r380)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 305, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r381 = CPyStatic_globals;
    cpy_r_r382 = CPyStatics[183]; /* '_format_array_but_cache_checksums' */
    cpy_r_r383 = CPyDict_GetItem(cpy_r_r381, cpy_r_r382);
    if (unlikely(cpy_r_r383 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 364, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r384 = CPyStatic_globals;
    cpy_r_r385 = CPyStatics[128]; /* 'brownie' */
    cpy_r_r386 = CPyDict_GetItem(cpy_r_r384, cpy_r_r385);
    if (unlikely(cpy_r_r386 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 364, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r387 = CPyStatics[184]; /* 'convert' */
    cpy_r_r388 = CPyObject_GetAttr(cpy_r_r386, cpy_r_r387);
    CPy_DECREF(cpy_r_r386);
    if (unlikely(cpy_r_r388 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 364, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r389 = CPyStatics[185]; /* 'normalize' */
    cpy_r_r390 = CPyObject_GetAttr(cpy_r_r388, cpy_r_r389);
    CPy_DECREF(cpy_r_r388);
    if (unlikely(cpy_r_r390 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 364, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r391 = CPyStatics[87]; /* '_format_array' */
    cpy_r_r392 = PyObject_SetAttr(cpy_r_r390, cpy_r_r391, cpy_r_r383);
    CPy_DECREF(cpy_r_r390);
    CPy_DECREF(cpy_r_r383);
    cpy_r_r393 = cpy_r_r392 >= 0;
    if (unlikely(!cpy_r_r393)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 364, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r394 = CPyStatic_globals;
    cpy_r_r395 = CPyStatics[186]; /* '_format_single_but_cache_checksums' */
    cpy_r_r396 = CPyDict_GetItem(cpy_r_r394, cpy_r_r395);
    if (unlikely(cpy_r_r396 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 365, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r397 = CPyStatic_globals;
    cpy_r_r398 = CPyStatics[128]; /* 'brownie' */
    cpy_r_r399 = CPyDict_GetItem(cpy_r_r397, cpy_r_r398);
    if (unlikely(cpy_r_r399 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 365, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r400 = CPyStatics[184]; /* 'convert' */
    cpy_r_r401 = CPyObject_GetAttr(cpy_r_r399, cpy_r_r400);
    CPy_DECREF(cpy_r_r399);
    if (unlikely(cpy_r_r401 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 365, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r402 = CPyStatics[185]; /* 'normalize' */
    cpy_r_r403 = CPyObject_GetAttr(cpy_r_r401, cpy_r_r402);
    CPy_DECREF(cpy_r_r401);
    if (unlikely(cpy_r_r403 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 365, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r404 = CPyStatics[89]; /* '_format_single' */
    cpy_r_r405 = PyObject_SetAttr(cpy_r_r403, cpy_r_r404, cpy_r_r396);
    CPy_DECREF(cpy_r_r403);
    CPy_DECREF(cpy_r_r396);
    cpy_r_r406 = cpy_r_r405 >= 0;
    if (unlikely(!cpy_r_r406)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 365, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r407 = CPyStatic_globals;
    cpy_r_r408 = CPyStatics[187]; /* '_format_tuple_but_cache_checksums' */
    cpy_r_r409 = CPyDict_GetItem(cpy_r_r407, cpy_r_r408);
    if (unlikely(cpy_r_r409 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 366, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r410 = CPyStatic_globals;
    cpy_r_r411 = CPyStatics[128]; /* 'brownie' */
    cpy_r_r412 = CPyDict_GetItem(cpy_r_r410, cpy_r_r411);
    if (unlikely(cpy_r_r412 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 366, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r413 = CPyStatics[184]; /* 'convert' */
    cpy_r_r414 = CPyObject_GetAttr(cpy_r_r412, cpy_r_r413);
    CPy_DECREF(cpy_r_r412);
    if (unlikely(cpy_r_r414 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 366, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r415 = CPyStatics[185]; /* 'normalize' */
    cpy_r_r416 = CPyObject_GetAttr(cpy_r_r414, cpy_r_r415);
    CPy_DECREF(cpy_r_r414);
    if (unlikely(cpy_r_r416 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 366, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r417 = CPyStatics[88]; /* '_format_tuple' */
    cpy_r_r418 = PyObject_SetAttr(cpy_r_r416, cpy_r_r417, cpy_r_r409);
    CPy_DECREF(cpy_r_r416);
    CPy_DECREF(cpy_r_r409);
    cpy_r_r419 = cpy_r_r418 >= 0;
    if (unlikely(!cpy_r_r419)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 366, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r420 = CPyStatic_globals;
    cpy_r_r421 = CPyStatics[183]; /* '_format_array_but_cache_checksums' */
    cpy_r_r422 = CPyDict_GetItem(cpy_r_r420, cpy_r_r421);
    if (unlikely(cpy_r_r422 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 368, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r423 = CPyStatic_globals;
    cpy_r_r424 = CPyStatics[87]; /* '_format_array' */
    cpy_r_r425 = CPyDict_SetItem(cpy_r_r423, cpy_r_r424, cpy_r_r422);
    CPy_DECREF(cpy_r_r422);
    cpy_r_r426 = cpy_r_r425 >= 0;
    if (unlikely(!cpy_r_r426)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 368, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r427 = CPyStatic_globals;
    cpy_r_r428 = CPyStatics[187]; /* '_format_tuple_but_cache_checksums' */
    cpy_r_r429 = CPyDict_GetItem(cpy_r_r427, cpy_r_r428);
    if (unlikely(cpy_r_r429 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 369, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r430 = CPyStatic_globals;
    cpy_r_r431 = CPyStatics[88]; /* '_format_tuple' */
    cpy_r_r432 = CPyDict_SetItem(cpy_r_r430, cpy_r_r431, cpy_r_r429);
    CPy_DECREF(cpy_r_r429);
    cpy_r_r433 = cpy_r_r432 >= 0;
    if (unlikely(!cpy_r_r433)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 369, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r434 = CPyStatic_globals;
    cpy_r_r435 = CPyStatics[186]; /* '_format_single_but_cache_checksums' */
    cpy_r_r436 = CPyDict_GetItem(cpy_r_r434, cpy_r_r435);
    if (unlikely(cpy_r_r436 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 370, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r437 = CPyStatic_globals;
    cpy_r_r438 = CPyStatics[89]; /* '_format_single' */
    cpy_r_r439 = CPyDict_SetItem(cpy_r_r437, cpy_r_r438, cpy_r_r436);
    CPy_DECREF(cpy_r_r436);
    cpy_r_r440 = cpy_r_r439 >= 0;
    if (unlikely(!cpy_r_r440)) {
        CPy_AddTraceback("dank_mids/brownie_patch/call.py", "<module>", 370, CPyStatic_globals);
        goto CPyL154;
    }
    return 1;
CPyL154: ;
    cpy_r_r441 = 2;
    return cpy_r_r441;
CPyL155: ;
    CPy_DecRef(cpy_r_r147);
    goto CPyL154;
CPyL156: ;
    CPy_DecRef(cpy_r_r158);
    goto CPyL154;
CPyL157: ;
    CPy_DecRef(cpy_r_r158);
    CPy_DecRef(cpy_r_r161);
    goto CPyL154;
CPyL158: ;
    CPy_DecRef(cpy_r_r158);
    CPy_DecRef(cpy_r_r165);
    goto CPyL154;
CPyL159: ;
    CPy_DecRef(cpy_r_r158);
    CPy_DecRef(cpy_r_r165);
    CPy_DecRef(cpy_r_r168);
    goto CPyL154;
CPyL160: ;
    CPy_DecRef(cpy_r_r183);
    goto CPyL154;
CPyL161: ;
    CPy_DecRef(cpy_r_r190);
    goto CPyL154;
CPyL162: ;
    CPy_DecRef(cpy_r_r204);
    goto CPyL154;
CPyL163: ;
    CPy_DecRef(cpy_r_r236);
    goto CPyL154;
CPyL164: ;
    CPy_DecRef(cpy_r_r288);
    goto CPyL154;
CPyL165: ;
    CPy_DecRef(cpy_r_r304.f0);
    CPy_DecRef(cpy_r_r304.f1);
    CPy_DecRef(cpy_r_r304.f2);
    goto CPyL104;
CPyL166: ;
    CPy_DecRef(cpy_r_r304.f0);
    CPy_DecRef(cpy_r_r304.f1);
    CPy_DecRef(cpy_r_r304.f2);
    goto CPyL106;
CPyL167: ;
    CPy_DecRef(cpy_r_r326);
    goto CPyL154;
CPyL168: ;
    CPy_DecRef(cpy_r_r332);
    goto CPyL154;
CPyL169: ;
    CPy_DecRef(cpy_r_r343);
    goto CPyL154;
CPyL170: ;
    CPy_DecRef(cpy_r_r343);
    CPy_DecRef(cpy_r_r346);
    goto CPyL154;
CPyL171: ;
    CPy_DecRef(cpy_r_r357);
    goto CPyL154;
CPyL172: ;
    CPy_DecRef(cpy_r_r370);
    goto CPyL154;
CPyL173: ;
    CPy_DecRef(cpy_r_r383);
    goto CPyL154;
CPyL174: ;
    CPy_DecRef(cpy_r_r396);
    goto CPyL154;
CPyL175: ;
    CPy_DecRef(cpy_r_r409);
    goto CPyL154;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___brownie_patch___call = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_concurrent___futures___process = Py_None;
    CPyModule_decimal = Py_None;
    CPyModule_logging = Py_None;
    CPyModule_pickle = Py_None;
    CPyModule_types = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_brownie___convert___normalize = Py_None;
    CPyModule_brownie___network___contract = Py_None;
    CPyModule_eth_abi = Py_None;
    CPyModule_a_sync = Py_None;
    CPyModule_brownie = Py_None;
    CPyModule_brownie___convert___datatypes = Py_None;
    CPyModule_brownie___convert___utils = Py_None;
    CPyModule_brownie___exceptions = Py_None;
    CPyModule_brownie___project___compiler___solidity = Py_None;
    CPyModule_eth_abi___exceptions = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_evmspec___data = Py_None;
    CPyModule_hexbytes = Py_None;
    CPyModule_hexbytes___main = Py_None;
    CPyModule_multicall___constants = Py_None;
    CPyModule_web3___types = Py_None;
    CPyModule_dank_mids = Py_None;
    CPyModule_dank_mids___brownie_patch___types = Py_None;
    CPyModule_dank_mids___exceptions = Py_None;
    CPyModule_dank_mids___helpers___lru_cache = Py_None;
    CPyModule_dank_mids___helpers____helpers = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[225];
const char * const CPyLit_Str[] = {
    "\006\004ENVS\031BROWNIE_ENCODER_PROCESSES\016__encode_input\003abi\tsignature\003run",
    "\004\031BROWNIE_DECODER_PROCESSES\017__decode_output\b_address\017_skip_proc_pool",
    "\005\027_skip_decoder_proc_pool\006inputs\021_get_coroutine_fn\nMethodType\tcoroutine",
    "\003\r_call_no_args\t__await__+Cannot use state override with `coroutine`.",
    "\004\nValueError\031BROWNIE_ENCODER_SEMAPHORE\t__aexit__\n__aenter__",
    "\006\fencode_input\026BROWNIE_CALL_SEMAPHORE\003eth\002to\004data\004call",
    "\004\025InsufficientDataBytes\aDecimal\rGeneratorExit\rStopIteration",
    "\004\016OPERATION_MODE\vapplication\025_request_data_no_args\bContract",
    "\005\f__contains__\016AttributeError\tTypeError\021BrokenProcessPool\006logger",
    "\0027Oh fuck, you broke the %s while decoding %s with abi %s\bcritical",
    "\005\f_max_workers\030AsyncProcessPoolExecutor\rPicklingError\tException\006decode",
    "\002\004args2 object has no attribute \'_skip_decoder_proc_pool\'",
    "\006\020DEBUG ME BRO: %s\005debug\020get_type_strings\020__eth_abi_encode\003hex\aoutputs",
    "\006\bHexBytes\020__eth_abi_decode\n0x08c379a0\aeth_abi\006string\ndecode_abi",
    "\004\017Call reverted: \006Revert\n0x4e487b71\024SOLIDITY_ERROR_CODES",
    "\004\023Panic (error code: \001)\n0xc1b84b2f!Call reverted: execution reverted",
    "\002/No data was returned - the call likely reverted\023VirtualMachineError",
    "\006\004name\026 requires no arguments\016_get_abi_types\001 \vReturnValue\f_check_array",
    "\a\bis_array\tTupleType\ncomponents\vto_type_str\001\'\004\' - \r_format_array",
    "\b\r_format_tuple\016_format_single\aarrlist\titem_type\003map\004uint\ato_uint\003int",
    "\a\006to_int\vfixed168x10\nto_decimal\004bool\ato_bool\aaddress\tbytearray",
    "\006\023to_checksum_address\004byte\tHexString\tto_string\016Unknown type: \bbuiltins",
    "\a\032concurrent.futures.process\adecimal\tgetLogger\alogging\006pickle\005types\003Any",
    "\t\bCallable\004Dict\005Final\004List\aNewType\bOptional\bSequence\005Tuple\aTypeVar",
    "\004\005Union\006typing\031brownie.convert.normalize\abrownie",
    "\003\030brownie.network.contract\037dank_mids/brownie_patch/call.py\b<module>",
    "\005\006a_sync\005chain\031brownie.convert.datatypes\aABIType\025brownie.convert.utils",
    "\003\022brownie.exceptions\fContractCall!brownie.project.compiler.solidity",
    "\006\022eth_abi.exceptions\006HexStr\neth_typing\aAddress\fevmspec.data\bhexbytes",
    "\004\tBytesLike\rhexbytes.main\024MULTICALL2_ADDRESSES\023multicall.constants",
    "\004\017BlockIdentifier\nweb3.types\025ENVIRONMENT_VARIABLES\tdank_mids",
    "\003\016ContractMethod\035dank_mids.brownie_patch.types\024dank_mids.exceptions",
    "\003\025lru_cache_lite_nonull\033dank_mids.helpers.lru_cache\bDankWeb3",
    "\006\032dank_mids.helpers._helpers\002_T\aTypeStr\bTypeStrs\vListOrTuple\aAbiDict",
    "\004\b__name__\006encode\bchecksum\nencode_abi",
    "\006*0xcA11bde05977b3631167028862bE2a173976CA11\002id\achainid\001e\003429\003get",
    "\004\nmulticall2 format_input_but_cache_checksums\anetwork\bcontract",
    "\003\fformat_input!format_output_but_cache_checksums\rformat_output",
    "\003!_format_array_but_cache_checksums\aconvert\tnormalize",
    "\002\"_format_single_but_cache_checksums!_format_tuple_but_cache_checksums",
    "",
};
const char * const CPyLit_Bytes[] = {
    "\001\020Unexpected error",
    "",
};
const char * const CPyLit_Int[] = {
    "\00510\0000\0004\00016\000-1",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    31, 1, 42, 1, 32, 1, 111, 1, 48, 1, 16, 11, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 3, 127, 128, 128, 3, 129, 128, 128, 3,
    62, 62, 62, 3, 200, 201, 202, 1, 47, 1, 133, 1, 79, 10, 135, 105, 82,
    80, 77, 100, 98, 96, 106, 94, 1, 55, 1, 74, 2, 38, 138, 1, 68, 1, 31,
    1, 141, 1, 143, 1, 59, 1, 146, 1, 148, 1, 150, 1, 152, 1, 3, 1, 154,
    1, 66, 1, 157, 1, 159
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___brownie_patch___call_internal = NULL;
CPyModule *CPyModule_dank_mids___brownie_patch___call;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_concurrent___futures___process;
CPyModule *CPyModule_decimal;
CPyModule *CPyModule_logging;
CPyModule *CPyModule_pickle;
CPyModule *CPyModule_types;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_brownie___convert___normalize;
CPyModule *CPyModule_brownie___network___contract;
CPyModule *CPyModule_eth_abi;
CPyModule *CPyModule_a_sync;
CPyModule *CPyModule_brownie;
CPyModule *CPyModule_brownie___convert___datatypes;
CPyModule *CPyModule_brownie___convert___utils;
CPyModule *CPyModule_brownie___exceptions;
CPyModule *CPyModule_brownie___project___compiler___solidity;
CPyModule *CPyModule_eth_abi___exceptions;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_evmspec___data;
CPyModule *CPyModule_hexbytes;
CPyModule *CPyModule_hexbytes___main;
CPyModule *CPyModule_multicall___constants;
CPyModule *CPyModule_web3___types;
CPyModule *CPyModule_dank_mids;
CPyModule *CPyModule_dank_mids___brownie_patch___types;
CPyModule *CPyModule_dank_mids___exceptions;
CPyModule *CPyModule_dank_mids___helpers___lru_cache;
CPyModule *CPyModule_dank_mids___helpers____helpers;
PyObject *CPyStatic_encode = NULL;
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
PyTypeObject *CPyType__format_array_but_cache_checksums_env;
PyObject *CPyDef__format_array_but_cache_checksums_env(void);
PyTypeObject *CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj;
PyObject *CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj(void);
PyTypeObject *CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj;
PyObject *CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj(void);
PyTypeObject *CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj;
PyObject *CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj(void);
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
PyObject *CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v);
PyObject *CPyPy___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v);
PyObject *CPyPy___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v);
PyObject *CPyPy___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__format_array_but_cache_checksums(PyObject *cpy_r_abi_type, PyObject *cpy_r_values);
PyObject *CPyPy__format_array_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__format_single_but_cache_checksums(PyObject *cpy_r_type_str, PyObject *cpy_r_value);
PyObject *CPyPy__format_single_but_cache_checksums(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids___brownie_patch___call exports = {
    &CPyStatic_encode,
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
    &CPyType__format_array_but_cache_checksums_env,
    &CPyDef__format_array_but_cache_checksums_env,
    &CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj,
    &CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj,
    &CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj,
    &CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj,
    &CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj,
    &CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj,
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
    &CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__,
    &CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__,
    &CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__,
    &CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__,
    &CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__,
    &CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__,
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
