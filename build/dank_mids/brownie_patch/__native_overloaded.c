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
#include "__native_overloaded.h"
#include "__native_internal_overloaded.h"

static PyObject *_patch_overloaded_method_env_setup(PyTypeObject *type);
PyObject *CPyDef__patch_overloaded_method_env(void);

static PyObject *
_patch_overloaded_method_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__patch_overloaded_method_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _patch_overloaded_method_env_setup(type);
}

static int
_patch_overloaded_method_env_traverse(dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_call);
    Py_VISIT(self->_coroutine);
    Py_VISIT(self->_w3);
    return 0;
}

static int
_patch_overloaded_method_env_clear(dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_call);
    Py_CLEAR(self->_coroutine);
    Py_CLEAR(self->_w3);
    return 0;
}

static void
_patch_overloaded_method_env_dealloc(dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _patch_overloaded_method_env_dealloc)
    _patch_overloaded_method_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _patch_overloaded_method_env_vtable[1];
static bool
CPyDef__patch_overloaded_method_env_trait_vtable_setup(void)
{
    CPyVTableItem _patch_overloaded_method_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_patch_overloaded_method_env_vtable, _patch_overloaded_method_env_vtable_scratch, sizeof(_patch_overloaded_method_env_vtable));
    return 1;
}

static PyMethodDef _patch_overloaded_method_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__patch_overloaded_method_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_patch_overloaded_method_env",
    .tp_new = _patch_overloaded_method_env_new,
    .tp_dealloc = (destructor)_patch_overloaded_method_env_dealloc,
    .tp_traverse = (traverseproc)_patch_overloaded_method_env_traverse,
    .tp_clear = (inquiry)_patch_overloaded_method_env_clear,
    .tp_methods = _patch_overloaded_method_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__patch_overloaded_method_env_template = &CPyType__patch_overloaded_method_env_template_;

static PyObject *
_patch_overloaded_method_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *self;
    self = (dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _patch_overloaded_method_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__patch_overloaded_method_env(void)
{
    PyObject *self = _patch_overloaded_method_env_setup(CPyType__patch_overloaded_method_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *coroutine__patch_overloaded_method_env_setup(PyTypeObject *type);
PyObject *CPyDef_coroutine__patch_overloaded_method_env(void);

static PyObject *
coroutine__patch_overloaded_method_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_coroutine__patch_overloaded_method_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return coroutine__patch_overloaded_method_env_setup(type);
}

static int
coroutine__patch_overloaded_method_env_traverse(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *self, visitproc visit, void *arg)
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
    Py_VISIT(self->_fn);
    Py_VISIT(self->___mypyc_temp__0.f0);
    Py_VISIT(self->___mypyc_temp__0.f1);
    Py_VISIT(self->___mypyc_temp__0.f2);
    Py_VISIT(self->_e);
    Py_VISIT(self->_exc_str);
    Py_VISIT(self->_match_on.f0);
    Py_VISIT(self->_match_on.f1);
    Py_VISIT(self->___mypyc_temp__1.f0);
    Py_VISIT(self->___mypyc_temp__1.f1);
    Py_VISIT(self->___mypyc_temp__2);
    Py_VISIT(self->_s);
    if (CPyTagged_CheckLong(self->_breakpoint)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_breakpoint));
    }
    Py_VISIT(self->_kwargs);
    Py_VISIT(self->___mypyc_temp__3);
    Py_VISIT(self->___mypyc_temp__4);
    Py_VISIT(self->___mypyc_temp__7);
    Py_VISIT(self->_k);
    Py_VISIT(self->_v);
    Py_VISIT(self->___mypyc_temp__8);
    Py_VISIT(self->___mypyc_temp__9.f0);
    Py_VISIT(self->___mypyc_temp__9.f1);
    Py_VISIT(self->___mypyc_temp__9.f2);
    return 0;
}

static int
coroutine__patch_overloaded_method_env_clear(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *self)
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
    Py_CLEAR(self->_fn);
    Py_CLEAR(self->___mypyc_temp__0.f0);
    Py_CLEAR(self->___mypyc_temp__0.f1);
    Py_CLEAR(self->___mypyc_temp__0.f2);
    Py_CLEAR(self->_e);
    Py_CLEAR(self->_exc_str);
    Py_CLEAR(self->_match_on.f0);
    Py_CLEAR(self->_match_on.f1);
    Py_CLEAR(self->___mypyc_temp__1.f0);
    Py_CLEAR(self->___mypyc_temp__1.f1);
    Py_CLEAR(self->___mypyc_temp__2);
    Py_CLEAR(self->_s);
    if (CPyTagged_CheckLong(self->_breakpoint)) {
        CPyTagged __tmp = self->_breakpoint;
        self->_breakpoint = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_kwargs);
    Py_CLEAR(self->___mypyc_temp__3);
    Py_CLEAR(self->___mypyc_temp__4);
    Py_CLEAR(self->___mypyc_temp__7);
    Py_CLEAR(self->_k);
    Py_CLEAR(self->_v);
    Py_CLEAR(self->___mypyc_temp__8);
    Py_CLEAR(self->___mypyc_temp__9.f0);
    Py_CLEAR(self->___mypyc_temp__9.f1);
    Py_CLEAR(self->___mypyc_temp__9.f2);
    return 0;
}

static void
coroutine__patch_overloaded_method_env_dealloc(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, coroutine__patch_overloaded_method_env_dealloc)
    coroutine__patch_overloaded_method_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem coroutine__patch_overloaded_method_env_vtable[1];
static bool
CPyDef_coroutine__patch_overloaded_method_env_trait_vtable_setup(void)
{
    CPyVTableItem coroutine__patch_overloaded_method_env_vtable_scratch[] = {
        NULL
    };
    memcpy(coroutine__patch_overloaded_method_env_vtable, coroutine__patch_overloaded_method_env_vtable_scratch, sizeof(coroutine__patch_overloaded_method_env_vtable));
    return 1;
}

static PyMethodDef coroutine__patch_overloaded_method_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_coroutine__patch_overloaded_method_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "coroutine__patch_overloaded_method_env",
    .tp_new = coroutine__patch_overloaded_method_env_new,
    .tp_dealloc = (destructor)coroutine__patch_overloaded_method_env_dealloc,
    .tp_traverse = (traverseproc)coroutine__patch_overloaded_method_env_traverse,
    .tp_clear = (inquiry)coroutine__patch_overloaded_method_env_clear,
    .tp_methods = coroutine__patch_overloaded_method_env_methods,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_coroutine__patch_overloaded_method_env_template = &CPyType_coroutine__patch_overloaded_method_env_template_;

static PyObject *
coroutine__patch_overloaded_method_env_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *self;
    self = (dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = coroutine__patch_overloaded_method_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__0 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->_match_on = (tuple_T2OO) { NULL, NULL };
    self->___mypyc_temp__1 = (tuple_T2OO) { NULL, NULL };
    self->_breakpoint = CPY_INT_TAG;
    self->___mypyc_temp__5 = CPY_INT_TAG;
    self->___mypyc_temp__6 = CPY_INT_TAG;
    self->___mypyc_temp__9 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_env(void)
{
    PyObject *self = coroutine__patch_overloaded_method_env_setup(CPyType_coroutine__patch_overloaded_method_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get__coroutine__patch_overloaded_method_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_coroutine__patch_overloaded_method_obj_____get__(self, instance, owner);
}
PyMemberDef coroutine__patch_overloaded_method_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
static PyObject *coroutine__patch_overloaded_method_obj_setup(PyTypeObject *type);
PyObject *CPyDef_coroutine__patch_overloaded_method_obj(void);

static PyObject *
coroutine__patch_overloaded_method_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_coroutine__patch_overloaded_method_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return coroutine__patch_overloaded_method_obj_setup(type);
}

static int
coroutine__patch_overloaded_method_obj_traverse(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject))));
    return 0;
}

static int
coroutine__patch_overloaded_method_obj_clear(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject))));
    return 0;
}

static void
coroutine__patch_overloaded_method_obj_dealloc(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, coroutine__patch_overloaded_method_obj_dealloc)
    coroutine__patch_overloaded_method_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem coroutine__patch_overloaded_method_obj_vtable[2];
static bool
CPyDef_coroutine__patch_overloaded_method_obj_trait_vtable_setup(void)
{
    CPyVTableItem coroutine__patch_overloaded_method_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_obj_____call__,
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_obj_____get__,
    };
    memcpy(coroutine__patch_overloaded_method_obj_vtable, coroutine__patch_overloaded_method_obj_vtable_scratch, sizeof(coroutine__patch_overloaded_method_obj_vtable));
    return 1;
}

static PyObject *
coroutine__patch_overloaded_method_obj_get___3_mypyc_env__(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *self, void *closure);
static int
coroutine__patch_overloaded_method_obj_set___3_mypyc_env__(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *self, PyObject *value, void *closure);

static PyGetSetDef coroutine__patch_overloaded_method_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)coroutine__patch_overloaded_method_obj_get___3_mypyc_env__, (setter)coroutine__patch_overloaded_method_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef coroutine__patch_overloaded_method_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_coroutine__patch_overloaded_method_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "coroutine__patch_overloaded_method_obj",
    .tp_new = coroutine__patch_overloaded_method_obj_new,
    .tp_dealloc = (destructor)coroutine__patch_overloaded_method_obj_dealloc,
    .tp_traverse = (traverseproc)coroutine__patch_overloaded_method_obj_traverse,
    .tp_clear = (inquiry)coroutine__patch_overloaded_method_obj_clear,
    .tp_getset = coroutine__patch_overloaded_method_obj_getseters,
    .tp_methods = coroutine__patch_overloaded_method_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__coroutine__patch_overloaded_method_obj,
    .tp_members = coroutine__patch_overloaded_method_obj_members,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
};
static PyTypeObject *CPyType_coroutine__patch_overloaded_method_obj_template = &CPyType_coroutine__patch_overloaded_method_obj_template_;

static PyObject *
coroutine__patch_overloaded_method_obj_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *self;
    self = (dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = coroutine__patch_overloaded_method_obj_vtable;
    self->vectorcall = CPyPy_coroutine__patch_overloaded_method_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_obj(void)
{
    PyObject *self = coroutine__patch_overloaded_method_obj_setup(CPyType_coroutine__patch_overloaded_method_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
coroutine__patch_overloaded_method_obj_get___3_mypyc_env__(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'coroutine__patch_overloaded_method_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
coroutine__patch_overloaded_method_obj_set___3_mypyc_env__(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'coroutine__patch_overloaded_method_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType__patch_overloaded_method_env))
        tmp = value;
    else {
        CPy_TypeError("dank_mids.brownie_patch.overloaded._patch_overloaded_method_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyAsyncMethods coroutine__patch_overloaded_method_gen_as_async = {
    .am_await = CPyDef_coroutine__patch_overloaded_method_gen_____await__,
};
static PyObject *coroutine__patch_overloaded_method_gen_setup(PyTypeObject *type);
PyObject *CPyDef_coroutine__patch_overloaded_method_gen(void);

static PyObject *
coroutine__patch_overloaded_method_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_coroutine__patch_overloaded_method_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return coroutine__patch_overloaded_method_gen_setup(type);
}

static int
coroutine__patch_overloaded_method_gen_traverse(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
coroutine__patch_overloaded_method_gen_clear(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
coroutine__patch_overloaded_method_gen_dealloc(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, coroutine__patch_overloaded_method_gen_dealloc)
    coroutine__patch_overloaded_method_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem coroutine__patch_overloaded_method_gen_vtable[7];
static bool
CPyDef_coroutine__patch_overloaded_method_gen_trait_vtable_setup(void)
{
    CPyVTableItem coroutine__patch_overloaded_method_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_gen_____next__,
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_gen___send,
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_gen_____iter__,
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_gen___throw,
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_gen___close,
        (CPyVTableItem)CPyDef_coroutine__patch_overloaded_method_gen_____await__,
    };
    memcpy(coroutine__patch_overloaded_method_gen_vtable, coroutine__patch_overloaded_method_gen_vtable_scratch, sizeof(coroutine__patch_overloaded_method_gen_vtable));
    return 1;
}

static PyMethodDef coroutine__patch_overloaded_method_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy_coroutine__patch_overloaded_method_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_coroutine__patch_overloaded_method_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "coroutine__patch_overloaded_method_gen",
    .tp_new = coroutine__patch_overloaded_method_gen_new,
    .tp_dealloc = (destructor)coroutine__patch_overloaded_method_gen_dealloc,
    .tp_traverse = (traverseproc)coroutine__patch_overloaded_method_gen_traverse,
    .tp_clear = (inquiry)coroutine__patch_overloaded_method_gen_clear,
    .tp_methods = coroutine__patch_overloaded_method_gen_methods,
    .tp_iter = CPyDef_coroutine__patch_overloaded_method_gen_____iter__,
    .tp_iternext = CPyDef_coroutine__patch_overloaded_method_gen_____next__,
    .tp_as_async = &coroutine__patch_overloaded_method_gen_as_async,
    .tp_basicsize = sizeof(dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_coroutine__patch_overloaded_method_gen_template = &CPyType_coroutine__patch_overloaded_method_gen_template_;

static PyObject *
coroutine__patch_overloaded_method_gen_setup(PyTypeObject *type)
{
    dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *self;
    self = (dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = coroutine__patch_overloaded_method_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_gen(void)
{
    PyObject *self = coroutine__patch_overloaded_method_gen_setup(CPyType_coroutine__patch_overloaded_method_gen);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {"_patch_overloaded_method", (PyCFunction)CPyPy__patch_overloaded_method, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids.brownie_patch.overloaded",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids___brownie_patch___overloaded(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids___brownie_patch___overloaded_internal) {
        Py_INCREF(CPyModule_dank_mids___brownie_patch___overloaded_internal);
        return CPyModule_dank_mids___brownie_patch___overloaded_internal;
    }
    CPyModule_dank_mids___brownie_patch___overloaded_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids___brownie_patch___overloaded_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids___brownie_patch___overloaded_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids___brownie_patch___overloaded_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType__patch_overloaded_method_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__patch_overloaded_method_env_template, NULL, modname);
    if (unlikely(!CPyType__patch_overloaded_method_env))
        goto fail;
    CPyType_coroutine__patch_overloaded_method_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_coroutine__patch_overloaded_method_env_template, NULL, modname);
    if (unlikely(!CPyType_coroutine__patch_overloaded_method_env))
        goto fail;
    CPyType_coroutine__patch_overloaded_method_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_coroutine__patch_overloaded_method_obj_template, NULL, modname);
    if (unlikely(!CPyType_coroutine__patch_overloaded_method_obj))
        goto fail;
    CPyType_coroutine__patch_overloaded_method_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_coroutine__patch_overloaded_method_gen_template, NULL, modname);
    if (unlikely(!CPyType_coroutine__patch_overloaded_method_gen))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids___brownie_patch___overloaded_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids___brownie_patch___overloaded_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType__patch_overloaded_method_env);
    Py_CLEAR(CPyType_coroutine__patch_overloaded_method_env);
    Py_CLEAR(CPyType_coroutine__patch_overloaded_method_obj);
    Py_CLEAR(CPyType_coroutine__patch_overloaded_method_gen);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy_coroutine__patch_overloaded_method_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    tuple_T3OOO cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
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
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    tuple_T2OO cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    tuple_T2OO cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    char cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    int32_t cpy_r_r49;
    char cpy_r_r50;
    char cpy_r_r51;
    char cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    CPyTagged cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    CPyTagged cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject **cpy_r_r74;
    PyObject *cpy_r_r75;
    tuple_T3OOO cpy_r_r76;
    char cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    char cpy_r_r87;
    PyObject *cpy_r_r88;
    char cpy_r_r89;
    char cpy_r_r90;
    PyObject *cpy_r_r91;
    int64_t cpy_r_r92;
    CPyTagged cpy_r_r93;
    char cpy_r_r94;
    PyObject *cpy_r_r95;
    char cpy_r_r96;
    PyObject *cpy_r_r97;
    CPyTagged cpy_r_r98;
    tuple_T4CIOO cpy_r_r99;
    CPyTagged cpy_r_r100;
    char cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    char cpy_r_r107;
    char cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    char cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    int32_t cpy_r_r116;
    char cpy_r_r117;
    PyObject *cpy_r_r118;
    CPyTagged cpy_r_r119;
    char cpy_r_r120;
    char cpy_r_r121;
    PyObject *cpy_r_r122;
    char cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    int32_t cpy_r_r132;
    char cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    char cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    char cpy_r_r143;
    PyObject *cpy_r_r144;
    char cpy_r_r145;
    tuple_T3OOO cpy_r_r146;
    char cpy_r_r147;
    PyObject **cpy_r_r148;
    PyObject *cpy_r_r149;
    char cpy_r_r150;
    char cpy_r_r151;
    tuple_T3OOO cpy_r_r152;
    char cpy_r_r153;
    tuple_T3OOO cpy_r_r154;
    tuple_T3OOO cpy_r_r155;
    char cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    char cpy_r_r160;
    char cpy_r_r161;
    char cpy_r_r162;
    char cpy_r_r163;
    PyObject *cpy_r_r164;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_gen", "__mypyc_env__", 24, CPyStatic_globals);
        goto CPyL153;
    }
    CPy_INCREF(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_next_label__;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_next_label__", 24, CPyStatic_globals);
        goto CPyL154;
    }
    CPyTagged_INCREF(cpy_r_r3);
CPyL2: ;
    cpy_r_r4 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_env__;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_env__", 24, CPyStatic_globals);
        goto CPyL155;
    }
    CPy_INCREF(cpy_r_r4);
    goto CPyL148;
CPyL3: ;
    cpy_r_r5 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r6 = cpy_r_type != cpy_r_r5;
    if (cpy_r_r6) {
        goto CPyL156;
    } else
        goto CPyL6;
CPyL4: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL152;
    }
    CPy_Unreachable();
CPyL6: ;
    cpy_r_r7 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_self;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "self", 45, CPyStatic_globals);
        goto CPyL157;
    }
    CPy_INCREF(cpy_r_r7);
CPyL7: ;
    cpy_r_r8 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "args", 45, CPyStatic_globals);
        goto CPyL158;
    }
    CPy_INCREF(cpy_r_r8);
CPyL8: ;
    cpy_r_r9 = CPyStatics[3]; /* '_get_fn_from_args' */
    cpy_r_r10 = CPyObject_CallMethodObjArgs(cpy_r_r7, cpy_r_r9, cpy_r_r8, NULL);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 45, CPyStatic_globals);
        goto CPyL157;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_fn != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_fn);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_fn = cpy_r_r10;
    cpy_r_r11 = 1;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 45, CPyStatic_globals);
        goto CPyL157;
    } else
        goto CPyL159;
CPyL10: ;
    cpy_r_r12 = CPy_CatchError();
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__0.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__0.f0);
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__0.f1);
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__0.f2);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__0 = cpy_r_r12;
    cpy_r_r13 = 1;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL160;
    }
    cpy_r_r14 = CPyModule_builtins;
    cpy_r_r15 = CPyStatics[4]; /* 'ValueError' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 46, CPyStatic_globals);
        goto CPyL160;
    }
    cpy_r_r17 = CPy_ExceptionMatches(cpy_r_r16);
    CPy_DecRef(cpy_r_r16);
    if (!cpy_r_r17) goto CPyL161;
    cpy_r_r18 = CPy_GetExcValue();
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_e != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_e);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_e = cpy_r_r18;
    cpy_r_r19 = 1;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 46, CPyStatic_globals);
        goto CPyL160;
    }
    cpy_r_r20 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_e;
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "e", 47, CPyStatic_globals);
        goto CPyL160;
    }
    CPy_INCREF(cpy_r_r20);
CPyL15: ;
    cpy_r_r21 = PyObject_Str(cpy_r_r20);
    CPy_DecRef(cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 47, CPyStatic_globals);
        goto CPyL160;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_exc_str != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_exc_str);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_exc_str = cpy_r_r21;
    cpy_r_r22 = 1;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 47, CPyStatic_globals);
        goto CPyL160;
    }
    cpy_r_r23 = CPyStatics[5]; /* "Contract has more than one function '." */
    cpy_r_r24 = ((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "_patch_overloaded_method_env", "call", 49, CPyStatic_globals);
        goto CPyL160;
    }
    CPy_INCREF(cpy_r_r24);
CPyL18: ;
    cpy_r_r25 = CPyStatics[6]; /* '_name' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    CPy_DecRef(cpy_r_r24);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 49, CPyStatic_globals);
        goto CPyL160;
    }
    cpy_r_r27 = PyObject_Str(cpy_r_r26);
    CPy_DecRef(cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 49, CPyStatic_globals);
        goto CPyL160;
    }
    cpy_r_r28 = CPyStr_Build(2, cpy_r_r23, cpy_r_r27);
    CPy_DecRef(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 49, CPyStatic_globals);
        goto CPyL160;
    }
    cpy_r_r29 = CPyStatics[7]; /* ('You must explicitly declare which function you are '
                                  'calling, e.g. .') */
    cpy_r_r30 = ((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r4)->_call;
    if (unlikely(cpy_r_r30 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'call' of '_patch_overloaded_method_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r30);
    }
    CPy_DecRef(cpy_r_r4);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 50, CPyStatic_globals);
        goto CPyL162;
    }
CPyL22: ;
    cpy_r_r31 = CPyStatics[6]; /* '_name' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    CPy_DecRef(cpy_r_r30);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 50, CPyStatic_globals);
        goto CPyL162;
    }
    cpy_r_r33 = PyObject_Str(cpy_r_r32);
    CPy_DecRef(cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 50, CPyStatic_globals);
        goto CPyL162;
    }
    cpy_r_r34 = CPyStr_Build(2, cpy_r_r29, cpy_r_r33);
    CPy_DecRef(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 50, CPyStatic_globals);
        goto CPyL162;
    }
    cpy_r_r35.f0 = cpy_r_r28;
    cpy_r_r35.f1 = cpy_r_r34;
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_match_on.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_match_on.f0);
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_match_on.f1);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_match_on = cpy_r_r35;
    cpy_r_r36 = 1;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 48, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r37 = 1;
    cpy_r_r38 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_match_on;
    if (unlikely(cpy_r_r38.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "match_on", 52, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF(cpy_r_r38.f0);
    CPy_INCREF(cpy_r_r38.f1);
CPyL27: ;
    CPy_INCREF(cpy_r_r38.f0);
    CPy_INCREF(cpy_r_r38.f1);
    cpy_r_r39 = PyTuple_New(2);
    if (unlikely(cpy_r_r39 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = cpy_r_r38.f0;
    PyTuple_SET_ITEM(cpy_r_r39, 0, __tmp1);
    PyObject *__tmp2 = cpy_r_r38.f1;
    PyTuple_SET_ITEM(cpy_r_r39, 1, __tmp2);
    cpy_r_r40 = PyObject_GetIter(cpy_r_r39);
    CPy_DecRef(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 52, CPyStatic_globals);
        goto CPyL163;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__1.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__1.f0);
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__1.f1);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__1 = cpy_r_r38;
    cpy_r_r41 = 1;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL164;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__2 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__2);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__2 = cpy_r_r40;
    cpy_r_r42 = 1;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL62;
    }
CPyL30: ;
    cpy_r_r43 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__2;
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__2", 52, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF(cpy_r_r43);
CPyL31: ;
    cpy_r_r44 = PyIter_Next(cpy_r_r43);
    CPy_DecRef(cpy_r_r43);
    if (cpy_r_r44 == NULL) goto CPyL39;
    if (likely(PyUnicode_Check(cpy_r_r44)))
        cpy_r_r45 = cpy_r_r44;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 52, CPyStatic_globals, "str", cpy_r_r44);
        goto CPyL62;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_s != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_s);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_s = cpy_r_r45;
    cpy_r_r46 = 1;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 52, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r47 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_s;
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "s", 52, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF(cpy_r_r47);
CPyL35: ;
    cpy_r_r48 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_exc_str;
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "exc_str", 52, CPyStatic_globals);
        goto CPyL165;
    }
    CPy_INCREF(cpy_r_r48);
CPyL36: ;
    cpy_r_r49 = PySequence_Contains(cpy_r_r48, cpy_r_r47);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_r47);
    cpy_r_r50 = cpy_r_r49 >= 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 52, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r51 = cpy_r_r49;
    cpy_r_r52 = cpy_r_r51 ^ 1;
    if (!cpy_r_r52) goto CPyL30;
    cpy_r_r37 = 0;
    goto CPyL40;
CPyL39: ;
    cpy_r_r53 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 52, CPyStatic_globals);
        goto CPyL62;
    }
CPyL40: ;
    if (!cpy_r_r37) goto CPyL58;
    cpy_r_r54 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_exc_str;
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "exc_str", 53, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF(cpy_r_r54);
CPyL42: ;
    cpy_r_r55 = CPyStatics[8]; /* '(*args)' */
    cpy_r_r56 = CPyStatics[9]; /* 'find' */
    cpy_r_r57 = CPyObject_CallMethodObjArgs(cpy_r_r54, cpy_r_r56, cpy_r_r55, NULL);
    CPy_DecRef(cpy_r_r54);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 53, CPyStatic_globals);
        goto CPyL62;
    }
    if (likely(PyLong_Check(cpy_r_r57)))
        cpy_r_r58 = CPyTagged_FromObject(cpy_r_r57);
    else {
        CPy_TypeError("int", cpy_r_r57); cpy_r_r58 = CPY_INT_TAG;
    }
    CPy_DecRef(cpy_r_r57);
    if (unlikely(cpy_r_r58 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 53, CPyStatic_globals);
        goto CPyL62;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_breakpoint != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_breakpoint);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_breakpoint = cpy_r_r58;
    cpy_r_r59 = 1;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 53, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r60 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_exc_str;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "exc_str", 54, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF(cpy_r_r60);
CPyL46: ;
    cpy_r_r61 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_breakpoint;
    if (unlikely(cpy_r_r61 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "breakpoint", 54, CPyStatic_globals);
        goto CPyL166;
    }
    CPyTagged_INCREF(cpy_r_r61);
CPyL47: ;
    cpy_r_r62 = CPyStr_GetSlice(cpy_r_r60, 0, cpy_r_r61);
    CPy_DecRef(cpy_r_r60);
    CPyTagged_DecRef(cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 54, CPyStatic_globals);
        goto CPyL62;
    }
    if (likely(PyUnicode_Check(cpy_r_r62)))
        cpy_r_r63 = cpy_r_r62;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 54, CPyStatic_globals, "str", cpy_r_r62);
        goto CPyL62;
    }
    cpy_r_r64 = CPyStatics[10]; /* '.coroutine' */
    cpy_r_r65 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_exc_str;
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "exc_str", 54, CPyStatic_globals);
        goto CPyL167;
    }
    CPy_INCREF(cpy_r_r65);
CPyL50: ;
    cpy_r_r66 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_breakpoint;
    if (unlikely(cpy_r_r66 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "breakpoint", 54, CPyStatic_globals);
        goto CPyL168;
    }
    CPyTagged_INCREF(cpy_r_r66);
CPyL51: ;
    cpy_r_r67 = CPyStr_GetSlice(cpy_r_r65, cpy_r_r66, 9223372036854775806LL);
    CPy_DecRef(cpy_r_r65);
    CPyTagged_DecRef(cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 54, CPyStatic_globals);
        goto CPyL167;
    }
    if (likely(PyUnicode_Check(cpy_r_r67)))
        cpy_r_r68 = cpy_r_r67;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 54, CPyStatic_globals, "str", cpy_r_r67);
        goto CPyL167;
    }
    cpy_r_r69 = CPyStr_Build(3, cpy_r_r63, cpy_r_r64, cpy_r_r68);
    CPy_DecRef(cpy_r_r63);
    CPy_DecRef(cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 54, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r70 = CPyModule_builtins;
    cpy_r_r71 = CPyStatics[4]; /* 'ValueError' */
    cpy_r_r72 = CPyObject_GetAttr(cpy_r_r70, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 54, CPyStatic_globals);
        goto CPyL169;
    }
    PyObject *cpy_r_r73[1] = {cpy_r_r69};
    cpy_r_r74 = (PyObject **)&cpy_r_r73;
    cpy_r_r75 = _PyObject_Vectorcall(cpy_r_r72, cpy_r_r74, 1, 0);
    CPy_DecRef(cpy_r_r72);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 54, CPyStatic_globals);
        goto CPyL169;
    }
    CPy_DecRef(cpy_r_r69);
    CPy_Raise(cpy_r_r75);
    CPy_DecRef(cpy_r_r75);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 54, CPyStatic_globals);
        goto CPyL62;
    } else
        goto CPyL170;
CPyL57: ;
    CPy_Unreachable();
CPyL58: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL62;
    } else
        goto CPyL171;
CPyL59: ;
    CPy_Unreachable();
CPyL60: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL62;
    } else
        goto CPyL172;
CPyL61: ;
    CPy_Unreachable();
CPyL62: ;
    cpy_r_r76 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r76.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__0' of 'coroutine__patch_overloaded_method_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r76.f0);
        CPy_INCREF(cpy_r_r76.f1);
        CPy_INCREF(cpy_r_r76.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r76.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL152;
    }
CPyL63: ;
    CPy_RestoreExcInfo(cpy_r_r76);
    CPy_DecRef(cpy_r_r76.f0);
    CPy_DecRef(cpy_r_r76.f1);
    CPy_DecRef(cpy_r_r76.f2);
    cpy_r_r77 = CPy_KeepPropagating();
    if (!cpy_r_r77) goto CPyL152;
    CPy_Unreachable();
CPyL65: ;
    cpy_r_r78 = CPyStatics[11]; /* 'block_identifier' */
    cpy_r_r79 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_block_identifier;
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "block_identifier", 57, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r79);
CPyL66: ;
    cpy_r_r80 = CPyStatics[12]; /* 'decimals' */
    cpy_r_r81 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_decimals;
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "decimals", 57, CPyStatic_globals);
        goto CPyL173;
    }
    CPy_INCREF(cpy_r_r81);
CPyL67: ;
    cpy_r_r82 = CPyStatics[13]; /* 'override' */
    cpy_r_r83 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_override;
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "override", 57, CPyStatic_globals);
        goto CPyL174;
    }
    CPy_INCREF(cpy_r_r83);
CPyL68: ;
    cpy_r_r84 = CPyDict_Build(3, cpy_r_r78, cpy_r_r79, cpy_r_r80, cpy_r_r81, cpy_r_r82, cpy_r_r83);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r81);
    CPy_DECREF(cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 57, CPyStatic_globals);
        goto CPyL154;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_kwargs != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_kwargs);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_kwargs = cpy_r_r84;
    cpy_r_r85 = 1;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 57, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r86 = PyDict_New();
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL154;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__3 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__3);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__3 = cpy_r_r86;
    cpy_r_r87 = 1;
    if (unlikely(!cpy_r_r87)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r88 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_kwargs;
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "kwargs", 58, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r88);
CPyL73: ;
    CPy_INCREF(cpy_r_r88);
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__4 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__4);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__4 = cpy_r_r88;
    cpy_r_r89 = 1;
    if (unlikely(!cpy_r_r89)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL175;
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__5 = 0;
    cpy_r_r90 = 1;
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r91 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__4;
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__4", 58, CPyStatic_globals);
        goto CPyL175;
    }
    CPy_INCREF(cpy_r_r91);
CPyL76: ;
    cpy_r_r92 = PyDict_Size(cpy_r_r91);
    CPy_DECREF(cpy_r_r91);
    cpy_r_r93 = cpy_r_r92 << 1;
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__6 = cpy_r_r93;
    cpy_r_r94 = 1;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r95 = CPyDict_GetItemsIter(cpy_r_r88);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL154;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__7 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__7);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__7 = cpy_r_r95;
    cpy_r_r96 = 1;
    if (unlikely(!cpy_r_r96)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL154;
    }
CPyL79: ;
    cpy_r_r97 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__7;
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__7", 58, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r97);
CPyL80: ;
    cpy_r_r98 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__5;
    if (unlikely(cpy_r_r98 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__5", 58, CPyStatic_globals);
        goto CPyL176;
    }
CPyL81: ;
    cpy_r_r99 = CPyDict_NextItem(cpy_r_r97, cpy_r_r98);
    CPy_DECREF(cpy_r_r97);
    cpy_r_r100 = cpy_r_r99.f1;
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__5 = cpy_r_r100;
    cpy_r_r101 = 1;
    if (unlikely(!cpy_r_r101)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r102 = cpy_r_r99.f0;
    if (!cpy_r_r102) goto CPyL178;
    cpy_r_r103 = cpy_r_r99.f2;
    CPy_INCREF(cpy_r_r103);
    cpy_r_r104 = cpy_r_r99.f3;
    CPy_INCREF(cpy_r_r104);
    CPy_DECREF(cpy_r_r99.f2);
    CPy_DECREF(cpy_r_r99.f3);
    if (likely(PyUnicode_Check(cpy_r_r103)))
        cpy_r_r105 = cpy_r_r103;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals, "str", cpy_r_r103);
        goto CPyL179;
    }
    if (PyLong_Check(cpy_r_r104))
        cpy_r_r106 = cpy_r_r104;
    else {
        cpy_r_r106 = NULL;
    }
    if (cpy_r_r106 != NULL) goto __LL3;
    if (PyUnicode_Check(cpy_r_r104))
        cpy_r_r106 = cpy_r_r104;
    else {
        cpy_r_r106 = NULL;
    }
    if (cpy_r_r106 != NULL) goto __LL3;
    if (PyBytes_Check(cpy_r_r104) || PyByteArray_Check(cpy_r_r104))
        cpy_r_r106 = cpy_r_r104;
    else {
        cpy_r_r106 = NULL;
    }
    if (cpy_r_r106 != NULL) goto __LL3;
    if (cpy_r_r104 == Py_None)
        cpy_r_r106 = cpy_r_r104;
    else {
        cpy_r_r106 = NULL;
    }
    if (cpy_r_r106 != NULL) goto __LL3;
    if (PyDict_Check(cpy_r_r104))
        cpy_r_r106 = cpy_r_r104;
    else {
        cpy_r_r106 = NULL;
    }
    if (cpy_r_r106 != NULL) goto __LL3;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals, "union[int, str, bytes, None, dict]", cpy_r_r104);
    goto CPyL180;
__LL3: ;
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_k != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_k);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_k = cpy_r_r105;
    cpy_r_r107 = 1;
    if (unlikely(!cpy_r_r107)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL181;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_v != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_v);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_v = cpy_r_r106;
    cpy_r_r108 = 1;
    if (unlikely(!cpy_r_r108)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r109 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_v;
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "v", 58, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r109);
CPyL88: ;
    cpy_r_r110 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r111 = cpy_r_r109 != cpy_r_r110;
    CPy_DECREF(cpy_r_r109);
    if (!cpy_r_r111) goto CPyL94;
    cpy_r_r112 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_k;
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "k", 58, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r112);
CPyL90: ;
    cpy_r_r113 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_v;
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "v", 58, CPyStatic_globals);
        goto CPyL182;
    }
    CPy_INCREF(cpy_r_r113);
CPyL91: ;
    if (PyLong_Check(cpy_r_r113))
        cpy_r_r114 = cpy_r_r113;
    else {
        cpy_r_r114 = NULL;
    }
    if (cpy_r_r114 != NULL) goto __LL4;
    if (PyUnicode_Check(cpy_r_r113))
        cpy_r_r114 = cpy_r_r113;
    else {
        cpy_r_r114 = NULL;
    }
    if (cpy_r_r114 != NULL) goto __LL4;
    if (PyBytes_Check(cpy_r_r113) || PyByteArray_Check(cpy_r_r113))
        cpy_r_r114 = cpy_r_r113;
    else {
        cpy_r_r114 = NULL;
    }
    if (cpy_r_r114 != NULL) goto __LL4;
    if (PyDict_Check(cpy_r_r113))
        cpy_r_r114 = cpy_r_r113;
    else {
        cpy_r_r114 = NULL;
    }
    if (cpy_r_r114 != NULL) goto __LL4;
    CPy_TypeErrorTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals, "union[int, str, bytes, dict]", cpy_r_r113);
    goto CPyL182;
__LL4: ;
    cpy_r_r115 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__3;
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL183;
    }
    CPy_INCREF(cpy_r_r115);
CPyL93: ;
    cpy_r_r116 = CPyDict_SetItem(cpy_r_r115, cpy_r_r112, cpy_r_r114);
    CPy_DECREF(cpy_r_r115);
    CPy_DECREF(cpy_r_r112);
    CPy_DECREF(cpy_r_r114);
    cpy_r_r117 = cpy_r_r116 >= 0;
    if (unlikely(!cpy_r_r117)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL154;
    }
CPyL94: ;
    cpy_r_r118 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__4;
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__4", 58, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r118);
CPyL95: ;
    cpy_r_r119 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__6;
    if (unlikely(cpy_r_r119 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__6", 58, CPyStatic_globals);
        goto CPyL184;
    }
CPyL96: ;
    cpy_r_r120 = CPyDict_CheckSize(cpy_r_r118, cpy_r_r119);
    CPy_DECREF(cpy_r_r118);
    if (unlikely(!cpy_r_r120)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL154;
    } else
        goto CPyL79;
CPyL97: ;
    cpy_r_r121 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r121)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r122 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__3;
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r122);
CPyL99: ;
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_kwargs != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_kwargs);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_kwargs = cpy_r_r122;
    cpy_r_r123 = 1;
    if (unlikely(!cpy_r_r123)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 58, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r124 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_fn;
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "fn", 59, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r124);
CPyL101: ;
    cpy_r_r125 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_args;
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "args", 59, CPyStatic_globals);
        goto CPyL185;
    }
    CPy_INCREF(cpy_r_r125);
CPyL102: ;
    cpy_r_r126 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->_kwargs;
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "kwargs", 59, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_INCREF(cpy_r_r126);
CPyL103: ;
    cpy_r_r127 = CPyStatics[14]; /* 'coroutine' */
    cpy_r_r128 = CPyObject_GetAttr(cpy_r_r124, cpy_r_r127);
    CPy_DECREF(cpy_r_r124);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r129 = PyList_New(0);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r130 = CPyList_Extend(cpy_r_r129, cpy_r_r125);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL189;
    } else
        goto CPyL190;
CPyL106: ;
    cpy_r_r131 = PyDict_New();
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r132 = CPyDict_UpdateInDisplay(cpy_r_r131, cpy_r_r126);
    CPy_DECREF(cpy_r_r126);
    cpy_r_r133 = cpy_r_r132 >= 0;
    if (unlikely(!cpy_r_r133)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r134 = PyList_AsTuple(cpy_r_r129);
    CPy_DECREF(cpy_r_r129);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL192;
    }
    cpy_r_r135 = PyObject_Call(cpy_r_r128, cpy_r_r134, cpy_r_r131);
    CPy_DECREF(cpy_r_r128);
    CPy_DECREF(cpy_r_r134);
    CPy_DECREF(cpy_r_r131);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r136 = CPy_GetCoro(cpy_r_r135);
    CPy_DECREF(cpy_r_r135);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL154;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__8 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__8);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__8 = cpy_r_r136;
    cpy_r_r137 = 1;
    if (unlikely(!cpy_r_r137)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r138 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__8;
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r138);
CPyL113: ;
    cpy_r_r139 = CPyIter_Next(cpy_r_r138);
    CPy_DECREF(cpy_r_r138);
    if (cpy_r_r139 == NULL) {
        goto CPyL193;
    } else
        goto CPyL116;
CPyL114: ;
    cpy_r_r140 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r141 = cpy_r_r140;
    goto CPyL145;
CPyL116: ;
    cpy_r_r142 = cpy_r_r139;
CPyL117: ;
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_next_label__ = 2;
    cpy_r_r143 = 1;
    if (unlikely(!cpy_r_r143)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL195;
    } else
        goto CPyL196;
CPyL118: ;
    return cpy_r_r142;
CPyL119: ;
    cpy_r_r144 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r145 = cpy_r_type != cpy_r_r144;
    if (!cpy_r_r145) goto CPyL122;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL123;
    } else
        goto CPyL197;
CPyL121: ;
    CPy_Unreachable();
CPyL122: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL140;
CPyL123: ;
    cpy_r_r146 = CPy_CatchError();
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__9.f0 != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__9.f0);
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__9.f1);
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__9.f2);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__9 = cpy_r_r146;
    cpy_r_r147 = 1;
    if (unlikely(!cpy_r_r147)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r148 = (PyObject **)&cpy_r_r1;
    cpy_r_r149 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__8;
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_INCREF(cpy_r_r149);
CPyL125: ;
    cpy_r_r150 = CPy_YieldFromErrorHandle(cpy_r_r149, cpy_r_r148);
    CPy_DecRef(cpy_r_r149);
    if (unlikely(cpy_r_r150 == 2)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL198;
    }
    if (cpy_r_r150) goto CPyL132;
    if (cpy_r_r1 != NULL) goto CPyL130;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r151 = 0;
    if (unlikely(!cpy_r_r151)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL137;
    } else
        goto CPyL199;
CPyL129: ;
    CPy_Unreachable();
CPyL130: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r142 = cpy_r_r1;
    cpy_r_r152 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__9;
    if (unlikely(cpy_r_r152.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL200;
    }
    CPy_INCREF(cpy_r_r152.f0);
    CPy_INCREF(cpy_r_r152.f1);
    CPy_INCREF(cpy_r_r152.f2);
CPyL131: ;
    CPy_RestoreExcInfo(cpy_r_r152);
    CPy_DecRef(cpy_r_r152.f0);
    CPy_DecRef(cpy_r_r152.f1);
    CPy_DecRef(cpy_r_r152.f2);
    goto CPyL117;
CPyL132: ;
    if (cpy_r_r1 != NULL) goto CPyL135;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r153 = 0;
    if (unlikely(!cpy_r_r153)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL137;
    } else
        goto CPyL201;
CPyL134: ;
    CPy_Unreachable();
CPyL135: ;
    cpy_r_r141 = cpy_r_r1;
    cpy_r_r154 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__9;
    if (unlikely(cpy_r_r154.f0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL202;
    }
    CPy_INCREF(cpy_r_r154.f0);
    CPy_INCREF(cpy_r_r154.f1);
    CPy_INCREF(cpy_r_r154.f2);
CPyL136: ;
    CPy_RestoreExcInfo(cpy_r_r154);
    CPy_DecRef(cpy_r_r154.f0);
    CPy_DecRef(cpy_r_r154.f1);
    CPy_DecRef(cpy_r_r154.f2);
    goto CPyL145;
CPyL137: ;
    cpy_r_r155 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__9;
    if (unlikely(cpy_r_r155.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__9' of 'coroutine__patch_overloaded_method_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r155.f0);
        CPy_INCREF(cpy_r_r155.f1);
        CPy_INCREF(cpy_r_r155.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r155.f0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", -1, CPyStatic_globals);
        goto CPyL152;
    }
CPyL138: ;
    CPy_RestoreExcInfo(cpy_r_r155);
    CPy_DecRef(cpy_r_r155.f0);
    CPy_DecRef(cpy_r_r155.f1);
    CPy_DecRef(cpy_r_r155.f2);
    cpy_r_r156 = CPy_KeepPropagating();
    if (!cpy_r_r156) goto CPyL152;
    CPy_Unreachable();
CPyL140: ;
    cpy_r_r157 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_temp__8;
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_env", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL203;
    }
    CPy_INCREF(cpy_r_r157);
CPyL141: ;
    cpy_r_r158 = CPyIter_Send(cpy_r_r157, cpy_r_arg);
    CPy_DECREF(cpy_r_r157);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r158 == NULL) goto CPyL204;
    cpy_r_r142 = cpy_r_r158;
    goto CPyL117;
CPyL143: ;
    cpy_r_r159 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r159 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r141 = cpy_r_r159;
CPyL145: ;
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r160 = 1;
    CPy_DECREF(cpy_r_r2);
    if (unlikely(!cpy_r_r160)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 59, CPyStatic_globals);
        goto CPyL205;
    }
    CPyGen_SetStopIterationValue(cpy_r_r141);
    CPy_DECREF(cpy_r_r141);
    if (!0) goto CPyL152;
    CPy_Unreachable();
CPyL148: ;
    cpy_r_r161 = cpy_r_r3 == 0;
    if (cpy_r_r161) {
        goto CPyL206;
    } else
        goto CPyL207;
CPyL149: ;
    cpy_r_r162 = cpy_r_r3 == 2;
    CPyTagged_DECREF(cpy_r_r3);
    if (cpy_r_r162) {
        goto CPyL119;
    } else
        goto CPyL208;
CPyL150: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r163 = 0;
    if (unlikely(!cpy_r_r163)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL152;
    }
    CPy_Unreachable();
CPyL152: ;
    cpy_r_r164 = NULL;
    return cpy_r_r164;
CPyL153: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL152;
CPyL154: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL152;
CPyL155: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r3);
    goto CPyL152;
CPyL156: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r4);
    goto CPyL4;
CPyL157: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL10;
CPyL158: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r7);
    goto CPyL10;
CPyL159: ;
    CPy_DECREF(cpy_r_r4);
    goto CPyL65;
CPyL160: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL62;
CPyL161: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL60;
CPyL162: ;
    CPy_DecRef(cpy_r_r28);
    goto CPyL62;
CPyL163: ;
    CPy_DecRef(cpy_r_r38.f0);
    CPy_DecRef(cpy_r_r38.f1);
    goto CPyL62;
CPyL164: ;
    CPy_DecRef(cpy_r_r40);
    goto CPyL62;
CPyL165: ;
    CPy_DecRef(cpy_r_r47);
    goto CPyL62;
CPyL166: ;
    CPy_DecRef(cpy_r_r60);
    goto CPyL62;
CPyL167: ;
    CPy_DecRef(cpy_r_r63);
    goto CPyL62;
CPyL168: ;
    CPy_DecRef(cpy_r_r63);
    CPy_DecRef(cpy_r_r65);
    goto CPyL62;
CPyL169: ;
    CPy_DecRef(cpy_r_r69);
    goto CPyL62;
CPyL170: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL57;
CPyL171: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL59;
CPyL172: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL61;
CPyL173: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r79);
    goto CPyL152;
CPyL174: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r81);
    goto CPyL152;
CPyL175: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r88);
    goto CPyL152;
CPyL176: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r97);
    goto CPyL152;
CPyL177: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r99.f2);
    CPy_DecRef(cpy_r_r99.f3);
    goto CPyL152;
CPyL178: ;
    CPy_DECREF(cpy_r_r99.f2);
    CPy_DECREF(cpy_r_r99.f3);
    goto CPyL97;
CPyL179: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r104);
    goto CPyL152;
CPyL180: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r105);
    goto CPyL152;
CPyL181: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r106);
    goto CPyL152;
CPyL182: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r112);
    goto CPyL152;
CPyL183: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r112);
    CPy_DecRef(cpy_r_r114);
    goto CPyL152;
CPyL184: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r118);
    goto CPyL152;
CPyL185: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r124);
    goto CPyL152;
CPyL186: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r124);
    CPy_DecRef(cpy_r_r125);
    goto CPyL152;
CPyL187: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r126);
    goto CPyL152;
CPyL188: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r128);
    goto CPyL152;
CPyL189: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r129);
    goto CPyL152;
CPyL190: ;
    CPy_DECREF(cpy_r_r130);
    goto CPyL106;
CPyL191: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r129);
    CPy_DecRef(cpy_r_r131);
    goto CPyL152;
CPyL192: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r131);
    goto CPyL152;
CPyL193: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL114;
CPyL194: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL152;
CPyL195: ;
    CPy_DecRef(cpy_r_r142);
    goto CPyL123;
CPyL196: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL118;
CPyL197: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL121;
CPyL198: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL137;
CPyL199: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL129;
CPyL200: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r142);
    goto CPyL137;
CPyL201: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL134;
CPyL202: ;
    CPy_DecRef(cpy_r_r141);
    goto CPyL137;
CPyL203: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_arg);
    goto CPyL152;
CPyL204: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL143;
CPyL205: ;
    CPy_DecRef(cpy_r_r141);
    goto CPyL152;
CPyL206: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL3;
CPyL207: ;
    CPy_DECREF(cpy_r_r4);
    goto CPyL149;
CPyL208: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL150;
}

PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__patch_overloaded_method_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.overloaded.coroutine__patch_overloaded_method_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_coroutine__patch_overloaded_method_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__patch_overloaded_method_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.overloaded.coroutine__patch_overloaded_method_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__patch_overloaded_method_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.overloaded.coroutine__patch_overloaded_method_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
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
    cpy_r_r1 = CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
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

PyObject *CPyPy_coroutine__patch_overloaded_method_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__patch_overloaded_method_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.overloaded.coroutine__patch_overloaded_method_gen", obj___mypyc_self__); 
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
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_gen___close(PyObject *cpy_r___mypyc_self__) {
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
    cpy_r_r1 = CPyStatics[15]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_coroutine__patch_overloaded_method_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[16]; /* 'StopIteration' */
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

PyObject *CPyPy_coroutine__patch_overloaded_method_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__patch_overloaded_method_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.overloaded.coroutine__patch_overloaded_method_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_coroutine__patch_overloaded_method_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.brownie_patch.overloaded.coroutine__patch_overloaded_method_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_coroutine__patch_overloaded_method_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override) {
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
    cpy_r_r0 = ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "coroutine", "coroutine__patch_overloaded_method_obj", "__mypyc_env__", 24, CPyStatic_globals);
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
    cpy_r_r4 = CPyDef_coroutine__patch_overloaded_method_env();
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL22;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_INCREF(cpy_r_self);
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_self != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_self);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_self = cpy_r_self;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_INCREF(cpy_r_args);
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_args != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_args);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_args = cpy_r_args;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL23;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_block_identifier != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_block_identifier);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_block_identifier = cpy_r_block_identifier;
    cpy_r_r8 = 1;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL24;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_decimals != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_decimals);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_decimals = cpy_r_decimals;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL25;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_override != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_override);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->_override = cpy_r_override;
    cpy_r_r10 = 1;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r11 = CPyDef_coroutine__patch_overloaded_method_gen();
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_INCREF(cpy_r_r4);
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *)cpy_r_r11)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *)cpy_r_r11)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject *)cpy_r_r11)->___mypyc_env__ = cpy_r_r4;
    cpy_r_r12 = 1;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
        goto CPyL27;
    }
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject *)cpy_r_r4)->___mypyc_next_label__ = 0;
    cpy_r_r13 = 1;
    CPy_DECREF(cpy_r_r4);
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
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

PyObject *CPyPy_coroutine__patch_overloaded_method_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    if (PyLong_Check(obj_block_identifier))
        arg_block_identifier = obj_block_identifier;
    else {
        arg_block_identifier = NULL;
    }
    if (arg_block_identifier != NULL) goto __LL7;
    if (PyUnicode_Check(obj_block_identifier))
        arg_block_identifier = obj_block_identifier;
    else {
        arg_block_identifier = NULL;
    }
    if (arg_block_identifier != NULL) goto __LL7;
    if (PyBytes_Check(obj_block_identifier) || PyByteArray_Check(obj_block_identifier))
        arg_block_identifier = obj_block_identifier;
    else {
        arg_block_identifier = NULL;
    }
    if (arg_block_identifier != NULL) goto __LL7;
    if (obj_block_identifier == Py_None)
        arg_block_identifier = obj_block_identifier;
    else {
        arg_block_identifier = NULL;
    }
    if (arg_block_identifier != NULL) goto __LL7;
    CPy_TypeError("union[int, str, bytes, None]", obj_block_identifier); 
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
    PyObject *retval = CPyDef_coroutine__patch_overloaded_method_obj_____call__(arg___mypyc_self__, arg_self, arg_args, arg_block_identifier, arg_decimals, arg_override);
    CPy_DECREF(obj_args);
    return retval;
fail: ;
    CPy_DECREF(obj_args);
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "coroutine", 24, CPyStatic_globals);
    return NULL;
}

char CPyDef__patch_overloaded_method(PyObject *cpy_r_call, PyObject *cpy_r_w3) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    int32_t cpy_r_r16;
    char cpy_r_r17;
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
    tuple_T2OO cpy_r_r33;
    PyObject *cpy_r_r34;
    int32_t cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    int32_t cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    int32_t cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    CPyTagged cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject **cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    int32_t cpy_r_r70;
    char cpy_r_r71;
    char cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject **cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    int32_t cpy_r_r82;
    char cpy_r_r83;
    char cpy_r_r84;
    cpy_r_r0 = CPyDef__patch_overloaded_method_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 12, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_call);
    if (((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r0)->_call != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r0)->_call);
    }
    ((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r0)->_call = cpy_r_call;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 12, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r2 = CPyDef_coroutine__patch_overloaded_method_obj();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 24, CPyStatic_globals);
        goto CPyL40;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *)cpy_r_r2)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *)cpy_r_r2)->___mypyc_env__);
    }
    ((dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject *)cpy_r_r2)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 24, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r4 = ((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r0)->_call;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", "_patch_overloaded_method_env", "call", 23, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_INCREF(cpy_r_r4);
CPyL5: ;
    cpy_r_r5 = CPyStatic_globals;
    cpy_r_r6 = CPyStatics[17]; /* 'wraps' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 23, CPyStatic_globals);
        goto CPyL42;
    }
    PyObject *cpy_r_r8[1] = {cpy_r_r4};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r7, cpy_r_r9, 1, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 23, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_DECREF(cpy_r_r4);
    PyObject *cpy_r_r11[1] = {cpy_r_r2};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = _PyObject_Vectorcall(cpy_r_r10, cpy_r_r12, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 24, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r2);
    CPy_INCREF(cpy_r_r13);
    cpy_r_r14 = CPyStatic_globals;
    cpy_r_r15 = CPyStatics[14]; /* 'coroutine' */
    cpy_r_r16 = CPyDict_SetItem(cpy_r_r14, cpy_r_r15, cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    cpy_r_r17 = cpy_r_r16 >= 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 24, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r18 = ((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r0)->_call;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", "_patch_overloaded_method_env", "call", 61, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_INCREF(cpy_r_r18);
CPyL10: ;
    cpy_r_r19 = CPyStatics[18]; /* '__dict__' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 61, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r21 = CPyStatics[19]; /* 'methods' */
    cpy_r_r22 = PyObject_GetItem(cpy_r_r20, cpy_r_r21);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 61, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r23 = CPyStatics[20]; /* 'values' */
    cpy_r_r24 = CPyObject_CallMethodObjArgs(cpy_r_r22, cpy_r_r23, NULL);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 61, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r25 = PyObject_GetIter(cpy_r_r24);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 61, CPyStatic_globals);
        goto CPyL43;
    }
CPyL14: ;
    cpy_r_r26 = PyIter_Next(cpy_r_r25);
    if (cpy_r_r26 == NULL) goto CPyL44;
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyStatics[21]; /* 'ContractCall' */
    cpy_r_r29 = CPyDict_GetItem(cpy_r_r27, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 62, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r30 = CPyStatic_globals;
    cpy_r_r31 = CPyStatics[22]; /* 'ContractTx' */
    cpy_r_r32 = CPyDict_GetItem(cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 62, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r33.f0 = cpy_r_r29;
    cpy_r_r33.f1 = cpy_r_r32;
    cpy_r_r34 = PyTuple_New(2);
    if (unlikely(cpy_r_r34 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp10 = cpy_r_r33.f0;
    PyTuple_SET_ITEM(cpy_r_r34, 0, __tmp10);
    PyObject *__tmp11 = cpy_r_r33.f1;
    PyTuple_SET_ITEM(cpy_r_r34, 1, __tmp11);
    cpy_r_r35 = PyObject_IsInstance(cpy_r_r26, cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r36 = cpy_r_r35 >= 0;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 62, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r37 = cpy_r_r35;
    if (!cpy_r_r37) goto CPyL47;
    cpy_r_r38 = CPyStatics[23]; /* '_address' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 63, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r40 = CPyStatic_globals;
    cpy_r_r41 = CPyStatics[24]; /* '_skip_proc_pool' */
    cpy_r_r42 = CPyDict_GetItem(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 63, CPyStatic_globals);
        goto CPyL48;
    }
    if (likely(PySet_Check(cpy_r_r42)))
        cpy_r_r43 = cpy_r_r42;
    else {
        CPy_TypeErrorTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 63, CPyStatic_globals, "set", cpy_r_r42);
        goto CPyL48;
    }
    cpy_r_r44 = PySet_Contains(cpy_r_r43, cpy_r_r39);
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r39);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 63, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r46 = cpy_r_r44;
    cpy_r_r47 = CPyStatics[25]; /* '_skip_decoder_proc_pool' */
    cpy_r_r48 = cpy_r_r46 ? Py_True : Py_False;
    cpy_r_r49 = PyObject_SetAttr(cpy_r_r26, cpy_r_r47, cpy_r_r48);
    cpy_r_r50 = cpy_r_r49 >= 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 63, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r51 = CPyStatics[26]; /* 'abi' */
    cpy_r_r52 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 64, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r53 = CPyStatics[27]; /* 'inputs' */
    cpy_r_r54 = PyObject_GetItem(cpy_r_r52, cpy_r_r53);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 64, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r55 = CPyObject_Size(cpy_r_r54);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r55 == CPY_INT_TAG)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 64, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r56 = CPyStatic_globals;
    cpy_r_r57 = CPyStatics[28]; /* '_get_coroutine_fn' */
    cpy_r_r58 = CPyDict_GetItem(cpy_r_r56, cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 64, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r59 = CPyTagged_StealAsObject(cpy_r_r55);
    PyObject *cpy_r_r60[2] = {cpy_r_w3, cpy_r_r59};
    cpy_r_r61 = (PyObject **)&cpy_r_r60;
    cpy_r_r62 = _PyObject_Vectorcall(cpy_r_r58, cpy_r_r61, 2, 0);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 64, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_DECREF(cpy_r_r59);
    cpy_r_r63 = CPyStatic_globals;
    cpy_r_r64 = CPyStatics[29]; /* 'MethodType' */
    cpy_r_r65 = CPyDict_GetItem(cpy_r_r63, cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 64, CPyStatic_globals);
        goto CPyL51;
    }
    PyObject *cpy_r_r66[2] = {cpy_r_r62, cpy_r_r26};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = _PyObject_Vectorcall(cpy_r_r65, cpy_r_r67, 2, 0);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 64, CPyStatic_globals);
        goto CPyL51;
    }
    CPy_DECREF(cpy_r_r62);
    cpy_r_r69 = CPyStatics[14]; /* 'coroutine' */
    cpy_r_r70 = PyObject_SetAttr(cpy_r_r26, cpy_r_r69, cpy_r_r68);
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r68);
    cpy_r_r71 = cpy_r_r70 >= 0;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 64, CPyStatic_globals);
        goto CPyL52;
    } else
        goto CPyL14;
CPyL32: ;
    cpy_r_r72 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 61, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r73 = ((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r0)->_call;
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AttributeError("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", "_patch_overloaded_method_env", "call", 69, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_INCREF(cpy_r_r73);
CPyL34: ;
    cpy_r_r74 = CPyStatic_globals;
    cpy_r_r75 = CPyStatics[29]; /* 'MethodType' */
    cpy_r_r76 = CPyDict_GetItem(cpy_r_r74, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 69, CPyStatic_globals);
        goto CPyL53;
    }
    PyObject *cpy_r_r77[2] = {cpy_r_r13, cpy_r_r73};
    cpy_r_r78 = (PyObject **)&cpy_r_r77;
    cpy_r_r79 = _PyObject_Vectorcall(cpy_r_r76, cpy_r_r78, 2, 0);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 69, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r73);
    cpy_r_r80 = ((dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject *)cpy_r_r0)->_call;
    if (unlikely(cpy_r_r80 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'call' of '_patch_overloaded_method_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r80);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 69, CPyStatic_globals);
        goto CPyL54;
    }
CPyL37: ;
    cpy_r_r81 = CPyStatics[14]; /* 'coroutine' */
    cpy_r_r82 = PyObject_SetAttr(cpy_r_r80, cpy_r_r81, cpy_r_r79);
    CPy_DECREF(cpy_r_r80);
    CPy_DECREF(cpy_r_r79);
    cpy_r_r83 = cpy_r_r82 >= 0;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 69, CPyStatic_globals);
        goto CPyL39;
    }
    return 1;
CPyL39: ;
    cpy_r_r84 = 2;
    return cpy_r_r84;
CPyL40: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL39;
CPyL41: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    goto CPyL39;
CPyL42: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    goto CPyL39;
CPyL43: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    goto CPyL39;
CPyL44: ;
    CPy_DECREF(cpy_r_r25);
    goto CPyL32;
CPyL45: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r26);
    goto CPyL39;
CPyL46: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r29);
    goto CPyL39;
CPyL47: ;
    CPy_DECREF(cpy_r_r26);
    goto CPyL14;
CPyL48: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r39);
    goto CPyL39;
CPyL49: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r55);
    goto CPyL39;
CPyL50: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r59);
    goto CPyL39;
CPyL51: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r62);
    goto CPyL39;
CPyL52: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r25);
    goto CPyL39;
CPyL53: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r73);
    goto CPyL39;
CPyL54: ;
    CPy_DecRef(cpy_r_r79);
    goto CPyL39;
}

PyObject *CPyPy__patch_overloaded_method(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"call", "w3", 0};
    static CPyArg_Parser parser = {"OO:_patch_overloaded_method", kwlist, 0};
    PyObject *obj_call;
    PyObject *obj_w3;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_call, &obj_w3)) {
        return NULL;
    }
    PyObject *arg_call = obj_call;
    PyObject *arg_w3 = obj_w3;
    char retval = CPyDef__patch_overloaded_method(arg_call, arg_w3);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "_patch_overloaded_method", 12, CPyStatic_globals);
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
    char cpy_r_r37;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[30]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", -1, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[47]; /* ('wraps',) */
    cpy_r_r6 = CPyStatics[31]; /* 'functools' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", 1, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_functools = cpy_r_r8;
    CPy_INCREF(CPyModule_functools);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[48]; /* ('MethodType',) */
    cpy_r_r10 = CPyStatics[32]; /* 'types' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", 2, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_types = cpy_r_r12;
    CPy_INCREF(CPyModule_types);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[49]; /* ('Any', 'Dict', 'Optional', 'Union') */
    cpy_r_r14 = CPyStatics[37]; /* 'typing' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", 3, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_typing = cpy_r_r16;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[50]; /* ('Contract',) */
    cpy_r_r18 = CPyStatics[39]; /* 'brownie' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", 5, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_brownie = cpy_r_r20;
    CPy_INCREF(CPyModule_brownie);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[51]; /* ('ContractCall', 'ContractTx', 'OverloadedMethod') */
    cpy_r_r22 = CPyStatics[41]; /* 'brownie.network.contract' */
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", 6, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_brownie___network___contract = cpy_r_r24;
    CPy_INCREF(CPyModule_brownie___network___contract);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[52]; /* ('_get_coroutine_fn', '_skip_proc_pool') */
    cpy_r_r26 = CPyStatics[42]; /* 'dank_mids.brownie_patch.call' */
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyImport_ImportFromMany(cpy_r_r26, cpy_r_r25, cpy_r_r25, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", 7, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_dank_mids___brownie_patch___call = cpy_r_r28;
    CPy_INCREF(CPyModule_dank_mids___brownie_patch___call);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r29 = CPyStatics[53]; /* ('ContractMethod',) */
    cpy_r_r30 = CPyStatics[44]; /* 'dank_mids.brownie_patch.types' */
    cpy_r_r31 = CPyStatic_globals;
    cpy_r_r32 = CPyImport_ImportFromMany(cpy_r_r30, cpy_r_r29, cpy_r_r29, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", 8, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_dank_mids___brownie_patch___types = cpy_r_r32;
    CPy_INCREF(CPyModule_dank_mids___brownie_patch___types);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r33 = CPyStatics[54]; /* ('DankWeb3',) */
    cpy_r_r34 = CPyStatics[46]; /* 'dank_mids.helpers._helpers' */
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyImport_ImportFromMany(cpy_r_r34, cpy_r_r33, cpy_r_r33, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("dank_mids/brownie_patch/overloaded.py", "<module>", 9, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_dank_mids___helpers____helpers = cpy_r_r36;
    CPy_INCREF(CPyModule_dank_mids___helpers____helpers);
    CPy_DECREF(cpy_r_r36);
    return 1;
CPyL12: ;
    cpy_r_r37 = 2;
    return cpy_r_r37;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___brownie_patch___overloaded = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_functools = Py_None;
    CPyModule_types = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_brownie = Py_None;
    CPyModule_brownie___network___contract = Py_None;
    CPyModule_dank_mids___brownie_patch___call = Py_None;
    CPyModule_dank_mids___brownie_patch___types = Py_None;
    CPyModule_dank_mids___helpers____helpers = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[55];
const char * const CPyLit_Str[] = {
    "\003\021_get_fn_from_args\nValueError&Contract has more than one function \'.",
    "\001\005_name",
    "\001BYou must explicitly declare which function you are calling, e.g. .",
    "\a\a(*args)\004find\n.coroutine\020block_identifier\bdecimals\boverride\tcoroutine",
    "\006\rGeneratorExit\rStopIteration\005wraps\b__dict__\amethods\006values",
    "\004\fContractCall\nContractTx\b_address\017_skip_proc_pool",
    "\005\027_skip_decoder_proc_pool\003abi\006inputs\021_get_coroutine_fn\nMethodType",
    "\t\bbuiltins\tfunctools\005types\003Any\004Dict\bOptional\005Union\006typing\bContract",
    "\003\abrownie\020OverloadedMethod\030brownie.network.contract",
    "\002\034dank_mids.brownie_patch.call\016ContractMethod",
    "\003\035dank_mids.brownie_patch.types\bDankWeb3\032dank_mids.helpers._helpers",
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
    8, 1, 17, 1, 29, 4, 33, 34, 35, 36, 1, 38, 3, 21, 22, 40, 2, 28, 24,
    1, 43, 1, 45
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___brownie_patch___overloaded_internal = NULL;
CPyModule *CPyModule_dank_mids___brownie_patch___overloaded;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_types;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_brownie;
CPyModule *CPyModule_brownie___network___contract;
CPyModule *CPyModule_dank_mids___brownie_patch___call;
CPyModule *CPyModule_dank_mids___brownie_patch___types;
CPyModule *CPyModule_dank_mids___helpers____helpers;
PyTypeObject *CPyType__patch_overloaded_method_env;
PyObject *CPyDef__patch_overloaded_method_env(void);
PyTypeObject *CPyType_coroutine__patch_overloaded_method_env;
PyObject *CPyDef_coroutine__patch_overloaded_method_env(void);
PyTypeObject *CPyType_coroutine__patch_overloaded_method_obj;
PyObject *CPyDef_coroutine__patch_overloaded_method_obj(void);
PyTypeObject *CPyType_coroutine__patch_overloaded_method_gen;
PyObject *CPyDef_coroutine__patch_overloaded_method_gen(void);
PyObject *CPyDef_coroutine__patch_overloaded_method_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_coroutine__patch_overloaded_method_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__patch_overloaded_method_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_coroutine__patch_overloaded_method_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__patch_overloaded_method_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_coroutine__patch_overloaded_method_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__patch_overloaded_method_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine__patch_overloaded_method_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__patch_overloaded_method_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_coroutine__patch_overloaded_method_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_coroutine__patch_overloaded_method_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
PyObject *CPyPy_coroutine__patch_overloaded_method_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__patch_overloaded_method(PyObject *cpy_r_call, PyObject *cpy_r_w3);
PyObject *CPyPy__patch_overloaded_method(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids___brownie_patch___overloaded exports = {
    &CPyType__patch_overloaded_method_env,
    &CPyDef__patch_overloaded_method_env,
    &CPyType_coroutine__patch_overloaded_method_env,
    &CPyDef_coroutine__patch_overloaded_method_env,
    &CPyType_coroutine__patch_overloaded_method_obj,
    &CPyDef_coroutine__patch_overloaded_method_obj,
    &CPyType_coroutine__patch_overloaded_method_gen,
    &CPyDef_coroutine__patch_overloaded_method_gen,
    &CPyDef_coroutine__patch_overloaded_method_obj_____get__,
    &CPyDef_coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__,
    &CPyDef_coroutine__patch_overloaded_method_gen_____next__,
    &CPyDef_coroutine__patch_overloaded_method_gen___send,
    &CPyDef_coroutine__patch_overloaded_method_gen_____iter__,
    &CPyDef_coroutine__patch_overloaded_method_gen___throw,
    &CPyDef_coroutine__patch_overloaded_method_gen___close,
    &CPyDef_coroutine__patch_overloaded_method_gen_____await__,
    &CPyDef_coroutine__patch_overloaded_method_obj_____call__,
    &CPyDef__patch_overloaded_method,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit_overloaded__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids.brownie_patch.overloaded__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids.brownie_patch.overloaded__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids___brownie_patch___overloaded(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids___brownie_patch___overloaded, "dank_mids.brownie_patch.overloaded__mypyc.init_dank_mids___brownie_patch___overloaded", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids___brownie_patch___overloaded", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
