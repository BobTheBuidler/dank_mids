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
#include "__native_lru_cache.h"
#include "__native_internal_lru_cache.h"

static PyObject *lru_cache_lite_env_setup(PyTypeObject *type);
PyObject *CPyDef_lru_cache_lite_env(void);

static PyObject *
lru_cache_lite_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_lru_cache_lite_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return lru_cache_lite_env_setup(type);
}

static int
lru_cache_lite_env_traverse(dank_mids___helpers___lru_cache___lru_cache_lite_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_func);
    Py_VISIT(self->_cache);
    Py_VISIT(self->_cache_miss);
    Py_VISIT(self->_lru_cache_lite_wrap);
    return 0;
}

static int
lru_cache_lite_env_clear(dank_mids___helpers___lru_cache___lru_cache_lite_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_func);
    Py_CLEAR(self->_cache);
    Py_CLEAR(self->_cache_miss);
    Py_CLEAR(self->_lru_cache_lite_wrap);
    return 0;
}

static void
lru_cache_lite_env_dealloc(dank_mids___helpers___lru_cache___lru_cache_lite_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, lru_cache_lite_env_dealloc)
    lru_cache_lite_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem lru_cache_lite_env_vtable[1];
static bool
CPyDef_lru_cache_lite_env_trait_vtable_setup(void)
{
    CPyVTableItem lru_cache_lite_env_vtable_scratch[] = {
        NULL
    };
    memcpy(lru_cache_lite_env_vtable, lru_cache_lite_env_vtable_scratch, sizeof(lru_cache_lite_env_vtable));
    return 1;
}

static PyMethodDef lru_cache_lite_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_lru_cache_lite_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "lru_cache_lite_env",
    .tp_new = lru_cache_lite_env_new,
    .tp_dealloc = (destructor)lru_cache_lite_env_dealloc,
    .tp_traverse = (traverseproc)lru_cache_lite_env_traverse,
    .tp_clear = (inquiry)lru_cache_lite_env_clear,
    .tp_methods = lru_cache_lite_env_methods,
    .tp_basicsize = sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_lru_cache_lite_env_template = &CPyType_lru_cache_lite_env_template_;

static PyObject *
lru_cache_lite_env_setup(PyTypeObject *type)
{
    dank_mids___helpers___lru_cache___lru_cache_lite_envObject *self;
    self = (dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = lru_cache_lite_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_lru_cache_lite_env(void)
{
    PyObject *self = lru_cache_lite_env_setup(CPyType_lru_cache_lite_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get__lru_cache_lite_wrap_lru_cache_lite_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____get__(self, instance, owner);
}
PyMemberDef lru_cache_lite_wrap_lru_cache_lite_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
static PyObject *lru_cache_lite_wrap_lru_cache_lite_obj_setup(PyTypeObject *type);
PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj(void);

static PyObject *
lru_cache_lite_wrap_lru_cache_lite_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_lru_cache_lite_wrap_lru_cache_lite_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return lru_cache_lite_wrap_lru_cache_lite_obj_setup(type);
}

static int
lru_cache_lite_wrap_lru_cache_lite_obj_traverse(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject))));
    return 0;
}

static int
lru_cache_lite_wrap_lru_cache_lite_obj_clear(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject))));
    return 0;
}

static void
lru_cache_lite_wrap_lru_cache_lite_obj_dealloc(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, lru_cache_lite_wrap_lru_cache_lite_obj_dealloc)
    lru_cache_lite_wrap_lru_cache_lite_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem lru_cache_lite_wrap_lru_cache_lite_obj_vtable[2];
static bool
CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_trait_vtable_setup(void)
{
    CPyVTableItem lru_cache_lite_wrap_lru_cache_lite_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____call__,
        (CPyVTableItem)CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____get__,
    };
    memcpy(lru_cache_lite_wrap_lru_cache_lite_obj_vtable, lru_cache_lite_wrap_lru_cache_lite_obj_vtable_scratch, sizeof(lru_cache_lite_wrap_lru_cache_lite_obj_vtable));
    return 1;
}

static PyObject *
lru_cache_lite_wrap_lru_cache_lite_obj_get___3_mypyc_env__(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *self, void *closure);
static int
lru_cache_lite_wrap_lru_cache_lite_obj_set___3_mypyc_env__(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *self, PyObject *value, void *closure);

static PyGetSetDef lru_cache_lite_wrap_lru_cache_lite_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)lru_cache_lite_wrap_lru_cache_lite_obj_get___3_mypyc_env__, (setter)lru_cache_lite_wrap_lru_cache_lite_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef lru_cache_lite_wrap_lru_cache_lite_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_lru_cache_lite_wrap_lru_cache_lite_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "lru_cache_lite_wrap_lru_cache_lite_obj",
    .tp_new = lru_cache_lite_wrap_lru_cache_lite_obj_new,
    .tp_dealloc = (destructor)lru_cache_lite_wrap_lru_cache_lite_obj_dealloc,
    .tp_traverse = (traverseproc)lru_cache_lite_wrap_lru_cache_lite_obj_traverse,
    .tp_clear = (inquiry)lru_cache_lite_wrap_lru_cache_lite_obj_clear,
    .tp_getset = lru_cache_lite_wrap_lru_cache_lite_obj_getseters,
    .tp_methods = lru_cache_lite_wrap_lru_cache_lite_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__lru_cache_lite_wrap_lru_cache_lite_obj,
    .tp_members = lru_cache_lite_wrap_lru_cache_lite_obj_members,
    .tp_basicsize = sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
};
static PyTypeObject *CPyType_lru_cache_lite_wrap_lru_cache_lite_obj_template = &CPyType_lru_cache_lite_wrap_lru_cache_lite_obj_template_;

static PyObject *
lru_cache_lite_wrap_lru_cache_lite_obj_setup(PyTypeObject *type)
{
    dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *self;
    self = (dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = lru_cache_lite_wrap_lru_cache_lite_obj_vtable;
    self->vectorcall = CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj(void)
{
    PyObject *self = lru_cache_lite_wrap_lru_cache_lite_obj_setup(CPyType_lru_cache_lite_wrap_lru_cache_lite_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
lru_cache_lite_wrap_lru_cache_lite_obj_get___3_mypyc_env__(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'lru_cache_lite_wrap_lru_cache_lite_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
lru_cache_lite_wrap_lru_cache_lite_obj_set___3_mypyc_env__(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'lru_cache_lite_wrap_lru_cache_lite_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType_lru_cache_lite_env))
        tmp = value;
    else {
        CPy_TypeError("dank_mids.helpers.lru_cache.lru_cache_lite_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *lru_cache_lite_nonull_env_setup(PyTypeObject *type);
PyObject *CPyDef_lru_cache_lite_nonull_env(void);

static PyObject *
lru_cache_lite_nonull_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_lru_cache_lite_nonull_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return lru_cache_lite_nonull_env_setup(type);
}

static int
lru_cache_lite_nonull_env_traverse(dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_func);
    Py_VISIT(self->_cache);
    Py_VISIT(self->_lru_cache_lite_wrap);
    return 0;
}

static int
lru_cache_lite_nonull_env_clear(dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_func);
    Py_CLEAR(self->_cache);
    Py_CLEAR(self->_lru_cache_lite_wrap);
    return 0;
}

static void
lru_cache_lite_nonull_env_dealloc(dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, lru_cache_lite_nonull_env_dealloc)
    lru_cache_lite_nonull_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem lru_cache_lite_nonull_env_vtable[1];
static bool
CPyDef_lru_cache_lite_nonull_env_trait_vtable_setup(void)
{
    CPyVTableItem lru_cache_lite_nonull_env_vtable_scratch[] = {
        NULL
    };
    memcpy(lru_cache_lite_nonull_env_vtable, lru_cache_lite_nonull_env_vtable_scratch, sizeof(lru_cache_lite_nonull_env_vtable));
    return 1;
}

static PyMethodDef lru_cache_lite_nonull_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_lru_cache_lite_nonull_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "lru_cache_lite_nonull_env",
    .tp_new = lru_cache_lite_nonull_env_new,
    .tp_dealloc = (destructor)lru_cache_lite_nonull_env_dealloc,
    .tp_traverse = (traverseproc)lru_cache_lite_nonull_env_traverse,
    .tp_clear = (inquiry)lru_cache_lite_nonull_env_clear,
    .tp_methods = lru_cache_lite_nonull_env_methods,
    .tp_basicsize = sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_lru_cache_lite_nonull_env_template = &CPyType_lru_cache_lite_nonull_env_template_;

static PyObject *
lru_cache_lite_nonull_env_setup(PyTypeObject *type)
{
    dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *self;
    self = (dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = lru_cache_lite_nonull_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_lru_cache_lite_nonull_env(void)
{
    PyObject *self = lru_cache_lite_nonull_env_setup(CPyType_lru_cache_lite_nonull_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get__lru_cache_lite_wrap_lru_cache_lite_nonull_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__(self, instance, owner);
}
PyMemberDef lru_cache_lite_wrap_lru_cache_lite_nonull_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
static PyObject *lru_cache_lite_wrap_lru_cache_lite_nonull_obj_setup(PyTypeObject *type);
PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj(void);

static PyObject *
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return lru_cache_lite_wrap_lru_cache_lite_nonull_obj_setup(type);
}

static int
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_traverse(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    Py_VISIT(*((PyObject **)((char *)self + sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject))));
    return 0;
}

static int
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_clear(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject))));
    return 0;
}

static void
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_dealloc(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, lru_cache_lite_wrap_lru_cache_lite_nonull_obj_dealloc)
    lru_cache_lite_wrap_lru_cache_lite_nonull_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem lru_cache_lite_wrap_lru_cache_lite_nonull_obj_vtable[2];
static bool
CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_trait_vtable_setup(void)
{
    CPyVTableItem lru_cache_lite_wrap_lru_cache_lite_nonull_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__,
        (CPyVTableItem)CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__,
    };
    memcpy(lru_cache_lite_wrap_lru_cache_lite_nonull_obj_vtable, lru_cache_lite_wrap_lru_cache_lite_nonull_obj_vtable_scratch, sizeof(lru_cache_lite_wrap_lru_cache_lite_nonull_obj_vtable));
    return 1;
}

static PyObject *
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_get___3_mypyc_env__(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *self, void *closure);
static int
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_set___3_mypyc_env__(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *self, PyObject *value, void *closure);

static PyGetSetDef lru_cache_lite_wrap_lru_cache_lite_nonull_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)lru_cache_lite_wrap_lru_cache_lite_nonull_obj_get___3_mypyc_env__, (setter)lru_cache_lite_wrap_lru_cache_lite_nonull_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef lru_cache_lite_wrap_lru_cache_lite_nonull_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "lru_cache_lite_wrap_lru_cache_lite_nonull_obj",
    .tp_new = lru_cache_lite_wrap_lru_cache_lite_nonull_obj_new,
    .tp_dealloc = (destructor)lru_cache_lite_wrap_lru_cache_lite_nonull_obj_dealloc,
    .tp_traverse = (traverseproc)lru_cache_lite_wrap_lru_cache_lite_nonull_obj_traverse,
    .tp_clear = (inquiry)lru_cache_lite_wrap_lru_cache_lite_nonull_obj_clear,
    .tp_getset = lru_cache_lite_wrap_lru_cache_lite_nonull_obj_getseters,
    .tp_methods = lru_cache_lite_wrap_lru_cache_lite_nonull_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__lru_cache_lite_wrap_lru_cache_lite_nonull_obj,
    .tp_members = lru_cache_lite_wrap_lru_cache_lite_nonull_obj_members,
    .tp_basicsize = sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject),
    .tp_weaklistoffset = sizeof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
};
static PyTypeObject *CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_template = &CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_template_;

static PyObject *
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_setup(PyTypeObject *type)
{
    dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *self;
    self = (dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = lru_cache_lite_wrap_lru_cache_lite_nonull_obj_vtable;
    self->vectorcall = CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj(void)
{
    PyObject *self = lru_cache_lite_wrap_lru_cache_lite_nonull_obj_setup(CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_get___3_mypyc_env__(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'lru_cache_lite_wrap_lru_cache_lite_nonull_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
lru_cache_lite_wrap_lru_cache_lite_nonull_obj_set___3_mypyc_env__(dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'lru_cache_lite_wrap_lru_cache_lite_nonull_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType_lru_cache_lite_nonull_env))
        tmp = value;
    else {
        CPy_TypeError("dank_mids.helpers.lru_cache.lru_cache_lite_nonull_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {"lru_cache_lite", (PyCFunction)CPyPy_lru_cache_lite, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"lru_cache_lite_nonull", (PyCFunction)CPyPy_lru_cache_lite_nonull, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids.helpers.lru_cache",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids___helpers___lru_cache(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids___helpers___lru_cache_internal) {
        Py_INCREF(CPyModule_dank_mids___helpers___lru_cache_internal);
        return CPyModule_dank_mids___helpers___lru_cache_internal;
    }
    CPyModule_dank_mids___helpers___lru_cache_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids___helpers___lru_cache_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids___helpers___lru_cache_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids___helpers___lru_cache_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType_lru_cache_lite_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_lru_cache_lite_env_template, NULL, modname);
    if (unlikely(!CPyType_lru_cache_lite_env))
        goto fail;
    CPyType_lru_cache_lite_wrap_lru_cache_lite_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_lru_cache_lite_wrap_lru_cache_lite_obj_template, NULL, modname);
    if (unlikely(!CPyType_lru_cache_lite_wrap_lru_cache_lite_obj))
        goto fail;
    CPyType_lru_cache_lite_nonull_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_lru_cache_lite_nonull_env_template, NULL, modname);
    if (unlikely(!CPyType_lru_cache_lite_nonull_env))
        goto fail;
    CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_template, NULL, modname);
    if (unlikely(!CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids___helpers___lru_cache_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids___helpers___lru_cache_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_lru_cache_lite_env);
    Py_CLEAR(CPyType_lru_cache_lite_wrap_lru_cache_lite_obj);
    Py_CLEAR(CPyType_lru_cache_lite_nonull_env);
    Py_CLEAR(CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj);
    return NULL;
}

PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_retval;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = ((dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", "lru_cache_lite_wrap_lru_cache_lite_obj", "__mypyc_env__", 41, CPyStatic_globals);
        goto CPyL15;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", "lru_cache_lite_env", "cache", 42, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache_miss;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", "lru_cache_lite_env", "cache_miss", 42, CPyStatic_globals);
        goto CPyL17;
    }
    CPy_INCREF(cpy_r_r2);
CPyL3: ;
    cpy_r_r3 = CPyDict_Get(cpy_r_r1, cpy_r_args, cpy_r_r2);
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 42, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_retval = cpy_r_r3;
    cpy_r_r4 = ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache_miss;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", "lru_cache_lite_env", "cache_miss", 43, CPyStatic_globals);
        goto CPyL18;
    }
    CPy_INCREF(cpy_r_r4);
CPyL5: ;
    cpy_r_r5 = cpy_r_retval == cpy_r_r4;
    CPy_DECREF(cpy_r_r4);
    if (cpy_r_r5) {
        goto CPyL19;
    } else
        goto CPyL20;
CPyL6: ;
    cpy_r_r6 = ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_func;
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", "lru_cache_lite_env", "func", 44, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_INCREF(cpy_r_r6);
CPyL7: ;
    cpy_r_r7 = PyList_New(0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 44, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r8 = CPyList_Extend(cpy_r_r7, cpy_r_args);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 44, CPyStatic_globals);
        goto CPyL22;
    } else
        goto CPyL23;
CPyL9: ;
    cpy_r_r9 = PyList_AsTuple(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 44, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r10 = PyDict_New();
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 44, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r11 = PyObject_Call(cpy_r_r6, cpy_r_r9, cpy_r_r10);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 44, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_retval = cpy_r_r11;
    cpy_r_r12 = ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache;
    if (unlikely(cpy_r_r12 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'cache' of 'lru_cache_lite_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r12);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 45, CPyStatic_globals);
        goto CPyL25;
    }
CPyL13: ;
    cpy_r_r13 = CPyDict_SetItem(cpy_r_r12, cpy_r_args, cpy_r_retval);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 45, CPyStatic_globals);
        goto CPyL25;
    }
CPyL14: ;
    return cpy_r_retval;
CPyL15: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL16: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL15;
CPyL17: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL15;
CPyL18: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_retval);
    goto CPyL15;
CPyL19: ;
    CPy_DECREF(cpy_r_retval);
    goto CPyL6;
CPyL20: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL14;
CPyL21: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r6);
    goto CPyL15;
CPyL22: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL15;
CPyL23: ;
    CPy_DECREF(cpy_r_r8);
    goto CPyL9;
CPyL24: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r9);
    goto CPyL15;
CPyL25: ;
    CPy_DecRef(cpy_r_retval);
    goto CPyL15;
}

PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:__call__", kwlist, 0};
    PyObject *obj_args;
    if (!CPyArg_ParseStackAndKeywords(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_args, NULL)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_args = obj_args;
    PyObject *retval = CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____call__(arg___mypyc_self__, arg_args);
    CPy_DECREF(obj_args);
    return retval;
fail: ;
    CPy_DECREF(obj_args);
    CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 41, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_lru_cache_lite(PyObject *cpy_r_func) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    int32_t cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    cpy_r_r0 = CPyDef_lru_cache_lite_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 11, CPyStatic_globals);
        goto CPyL17;
    }
    CPy_INCREF(cpy_r_func);
    if (((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_func != NULL) {
        CPy_DECREF(((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_func);
    }
    ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_func = cpy_r_func;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 11, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r2 = PyDict_New();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 37, CPyStatic_globals);
        goto CPyL18;
    }
    if (((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache != NULL) {
        CPy_DECREF(((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache);
    }
    ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache = cpy_r_r2;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 37, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[3]; /* 'object' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 38, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r6, 0, 0, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 38, CPyStatic_globals);
        goto CPyL18;
    }
    if (((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache_miss != NULL) {
        CPy_DECREF(((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache_miss);
    }
    ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache_miss = cpy_r_r7;
    cpy_r_r8 = 1;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 38, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r9 = CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj();
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 41, CPyStatic_globals);
        goto CPyL18;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *)cpy_r_r9)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *)cpy_r_r9)->___mypyc_env__);
    }
    ((dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject *)cpy_r_r9)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r10 = 1;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 41, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r11 = ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_func;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite", "lru_cache_lite_env", "func", 40, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_INCREF(cpy_r_r11);
CPyL10: ;
    cpy_r_r12 = CPyStatic_globals;
    cpy_r_r13 = CPyStatics[4]; /* 'wraps' */
    cpy_r_r14 = CPyDict_GetItem(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 40, CPyStatic_globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r11};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r14, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 40, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_DECREF(cpy_r_r11);
    PyObject *cpy_r_r18[1] = {cpy_r_r9};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = _PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 1, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 41, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_DECREF(cpy_r_r9);
    CPy_INCREF(cpy_r_r20);
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyStatics[5]; /* 'lru_cache_lite_wrap' */
    cpy_r_r23 = CPyDict_SetItem(cpy_r_r21, cpy_r_r22, cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r24 = cpy_r_r23 >= 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 41, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r25 = ((dank_mids___helpers___lru_cache___lru_cache_lite_envObject *)cpy_r_r0)->_cache;
    if (unlikely(cpy_r_r25 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'cache' of 'lru_cache_lite_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r25);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 48, CPyStatic_globals);
        goto CPyL22;
    }
CPyL15: ;
    cpy_r_r26 = CPyStatics[6]; /* 'cache' */
    cpy_r_r27 = PyObject_SetAttr(cpy_r_r20, cpy_r_r26, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r28 = cpy_r_r27 >= 0;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 48, CPyStatic_globals);
        goto CPyL22;
    }
    return cpy_r_r20;
CPyL17: ;
    cpy_r_r29 = NULL;
    return cpy_r_r29;
CPyL18: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL17;
CPyL19: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r9);
    goto CPyL17;
CPyL20: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r11);
    goto CPyL17;
CPyL21: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r20);
    goto CPyL17;
CPyL22: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL17;
}

PyObject *CPyPy_lru_cache_lite(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"func", 0};
    static CPyArg_Parser parser = {"O:lru_cache_lite", kwlist, 0};
    PyObject *obj_func;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_func)) {
        return NULL;
    }
    PyObject *arg_func = obj_func;
    PyObject *retval = CPyDef_lru_cache_lite(arg_func);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite", 11, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_retval;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    int32_t cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    cpy_r_r0 = ((dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", "lru_cache_lite_wrap_lru_cache_lite_nonull_obj", "__mypyc_env__", 89, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_cache;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", "lru_cache_lite_nonull_env", "cache", 90, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = CPyDict_GetWithNone(cpy_r_r1, cpy_r_args);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 90, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_retval = cpy_r_r2;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_retval == cpy_r_r3;
    if (cpy_r_r4) {
        goto CPyL15;
    } else
        goto CPyL16;
CPyL4: ;
    cpy_r_r5 = ((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_func;
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", "lru_cache_lite_nonull_env", "func", 92, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_INCREF(cpy_r_r5);
CPyL5: ;
    cpy_r_r6 = PyList_New(0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 92, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r7 = CPyList_Extend(cpy_r_r6, cpy_r_args);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 92, CPyStatic_globals);
        goto CPyL18;
    } else
        goto CPyL19;
CPyL7: ;
    cpy_r_r8 = PyList_AsTuple(cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 92, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r9 = PyDict_New();
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 92, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r10 = PyObject_Call(cpy_r_r5, cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 92, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_retval = cpy_r_r10;
    cpy_r_r11 = ((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_cache;
    if (unlikely(cpy_r_r11 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'cache' of 'lru_cache_lite_nonull_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r11);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 93, CPyStatic_globals);
        goto CPyL21;
    }
CPyL11: ;
    cpy_r_r12 = CPyDict_SetItem(cpy_r_r11, cpy_r_args, cpy_r_retval);
    CPy_DECREF(cpy_r_r11);
    cpy_r_r13 = cpy_r_r12 >= 0;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 93, CPyStatic_globals);
        goto CPyL21;
    }
CPyL12: ;
    return cpy_r_retval;
CPyL13: ;
    cpy_r_r14 = NULL;
    return cpy_r_r14;
CPyL14: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL13;
CPyL15: ;
    CPy_DECREF(cpy_r_retval);
    goto CPyL4;
CPyL16: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL12;
CPyL17: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    goto CPyL13;
CPyL18: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    goto CPyL13;
CPyL19: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL7;
CPyL20: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r8);
    goto CPyL13;
CPyL21: ;
    CPy_DecRef(cpy_r_retval);
    goto CPyL13;
}

PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:__call__", kwlist, 0};
    PyObject *obj_args;
    if (!CPyArg_ParseStackAndKeywords(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_args, NULL)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_args = obj_args;
    PyObject *retval = CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__(arg___mypyc_self__, arg_args);
    CPy_DECREF(obj_args);
    return retval;
fail: ;
    CPy_DECREF(obj_args);
    CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_wrap", 89, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_lru_cache_lite_nonull(PyObject *cpy_r_func) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    int32_t cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    cpy_r_r0 = CPyDef_lru_cache_lite_nonull_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 52, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_INCREF(cpy_r_func);
    if (((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_func != NULL) {
        CPy_DECREF(((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_func);
    }
    ((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_func = cpy_r_func;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 52, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r2 = PyDict_New();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 86, CPyStatic_globals);
        goto CPyL15;
    }
    if (((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_cache != NULL) {
        CPy_DECREF(((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_cache);
    }
    ((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_cache = cpy_r_r2;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 86, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r4 = CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj();
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 89, CPyStatic_globals);
        goto CPyL15;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *)cpy_r_r4)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *)cpy_r_r4)->___mypyc_env__);
    }
    ((dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject *)cpy_r_r4)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 89, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r6 = ((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_func;
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", "lru_cache_lite_nonull_env", "func", 88, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_INCREF(cpy_r_r6);
CPyL7: ;
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyStatics[4]; /* 'wraps' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 88, CPyStatic_globals);
        goto CPyL17;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_r6};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 88, CPyStatic_globals);
        goto CPyL17;
    }
    CPy_DECREF(cpy_r_r6);
    PyObject *cpy_r_r13[1] = {cpy_r_r4};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 89, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_DECREF(cpy_r_r4);
    CPy_INCREF(cpy_r_r15);
    cpy_r_r16 = CPyStatic_globals;
    cpy_r_r17 = CPyStatics[5]; /* 'lru_cache_lite_wrap' */
    cpy_r_r18 = CPyDict_SetItem(cpy_r_r16, cpy_r_r17, cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 89, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r20 = ((dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject *)cpy_r_r0)->_cache;
    if (unlikely(cpy_r_r20 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'cache' of 'lru_cache_lite_nonull_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r20);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 96, CPyStatic_globals);
        goto CPyL19;
    }
CPyL12: ;
    cpy_r_r21 = CPyStatics[6]; /* 'cache' */
    cpy_r_r22 = PyObject_SetAttr(cpy_r_r15, cpy_r_r21, cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 96, CPyStatic_globals);
        goto CPyL19;
    }
    return cpy_r_r15;
CPyL14: ;
    cpy_r_r24 = NULL;
    return cpy_r_r24;
CPyL15: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL14;
CPyL16: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    goto CPyL14;
CPyL17: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    goto CPyL14;
CPyL18: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r15);
    goto CPyL14;
CPyL19: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL14;
}

PyObject *CPyPy_lru_cache_lite_nonull(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"func", 0};
    static CPyArg_Parser parser = {"O:lru_cache_lite_nonull", kwlist, 0};
    PyObject *obj_func;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_func)) {
        return NULL;
    }
    PyObject *arg_func = obj_func;
    PyObject *retval = CPyDef_lru_cache_lite_nonull(arg_func);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "lru_cache_lite_nonull", 52, CPyStatic_globals);
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
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    int32_t cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    CPyPtr cpy_r_r42;
    CPyPtr cpy_r_r43;
    CPyPtr cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    int32_t cpy_r_r47;
    char cpy_r_r48;
    char cpy_r_r49;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[7]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", -1, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[20]; /* ('wraps',) */
    cpy_r_r6 = CPyStatics[8]; /* 'functools' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 1, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_functools = cpy_r_r8;
    CPy_INCREF(CPyModule_functools);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[21]; /* ('Callable', 'Dict', 'TypeVar') */
    cpy_r_r10 = CPyStatics[12]; /* 'typing' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 2, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[22]; /* ('ParamSpec',) */
    cpy_r_r14 = CPyStatics[14]; /* 'typing_extensions' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 4, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_typing_extensions = cpy_r_r16;
    CPy_INCREF(CPyModule_typing_extensions);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[15]; /* '__P' */
    cpy_r_r18 = CPyStatic_globals;
    cpy_r_r19 = CPyStatics[13]; /* 'ParamSpec' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 7, CPyStatic_globals);
        goto CPyL15;
    }
    PyObject *cpy_r_r21[1] = {cpy_r_r17};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = _PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 7, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r24 = CPyStatic_globals;
    cpy_r_r25 = CPyStatics[15]; /* '__P' */
    cpy_r_r26 = CPyDict_SetItem(cpy_r_r24, cpy_r_r25, cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 7, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r28 = CPyStatics[16]; /* '__T' */
    cpy_r_r29 = CPyStatic_globals;
    cpy_r_r30 = CPyStatics[11]; /* 'TypeVar' */
    cpy_r_r31 = CPyDict_GetItem(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 8, CPyStatic_globals);
        goto CPyL15;
    }
    PyObject *cpy_r_r32[1] = {cpy_r_r28};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = _PyObject_Vectorcall(cpy_r_r31, cpy_r_r33, 1, 0);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 8, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyStatics[16]; /* '__T' */
    cpy_r_r37 = CPyDict_SetItem(cpy_r_r35, cpy_r_r36, cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r38 = cpy_r_r37 >= 0;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 8, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r39 = CPyStatics[17]; /* 'lru_cache_lite' */
    cpy_r_r40 = CPyStatics[18]; /* 'lru_cache_lite_nonull' */
    cpy_r_r41 = PyList_New(2);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 100, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r42 = (CPyPtr)&((PyListObject *)cpy_r_r41)->ob_item;
    cpy_r_r43 = *(CPyPtr *)cpy_r_r42;
    CPy_INCREF(cpy_r_r39);
    *(PyObject * *)cpy_r_r43 = cpy_r_r39;
    CPy_INCREF(cpy_r_r40);
    cpy_r_r44 = cpy_r_r43 + 8;
    *(PyObject * *)cpy_r_r44 = cpy_r_r40;
    cpy_r_r45 = CPyStatic_globals;
    cpy_r_r46 = CPyStatics[19]; /* '__all__' */
    cpy_r_r47 = CPyDict_SetItem(cpy_r_r45, cpy_r_r46, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    cpy_r_r48 = cpy_r_r47 >= 0;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("dank_mids/helpers/lru_cache.py", "<module>", 100, CPyStatic_globals);
        goto CPyL15;
    }
    return 1;
CPyL15: ;
    cpy_r_r49 = 2;
    return cpy_r_r49;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___helpers___lru_cache = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_functools = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_typing_extensions = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[23];
const char * const CPyLit_Str[] = {
    "\a\006object\005wraps\023lru_cache_lite_wrap\005cache\bbuiltins\tfunctools\bCallable",
    "\a\004Dict\aTypeVar\006typing\tParamSpec\021typing_extensions\003__P\003__T",
    "\003\016lru_cache_lite\025lru_cache_lite_nonull\a__all__",
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
const int CPyLit_Tuple[] = {3, 1, 4, 3, 9, 10, 11, 1, 13};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___helpers___lru_cache_internal = NULL;
CPyModule *CPyModule_dank_mids___helpers___lru_cache;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_typing_extensions;
PyTypeObject *CPyType_lru_cache_lite_env;
PyObject *CPyDef_lru_cache_lite_env(void);
PyTypeObject *CPyType_lru_cache_lite_wrap_lru_cache_lite_obj;
PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj(void);
PyTypeObject *CPyType_lru_cache_lite_nonull_env;
PyObject *CPyDef_lru_cache_lite_nonull_env(void);
PyTypeObject *CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj;
PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj(void);
PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args);
PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_lru_cache_lite(PyObject *cpy_r_func);
PyObject *CPyPy_lru_cache_lite(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args);
PyObject *CPyPy_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_lru_cache_lite_nonull(PyObject *cpy_r_func);
PyObject *CPyPy_lru_cache_lite_nonull(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids___helpers___lru_cache exports = {
    &CPyType_lru_cache_lite_env,
    &CPyDef_lru_cache_lite_env,
    &CPyType_lru_cache_lite_wrap_lru_cache_lite_obj,
    &CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj,
    &CPyType_lru_cache_lite_nonull_env,
    &CPyDef_lru_cache_lite_nonull_env,
    &CPyType_lru_cache_lite_wrap_lru_cache_lite_nonull_obj,
    &CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj,
    &CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____get__,
    &CPyDef_lru_cache_lite_wrap_lru_cache_lite_obj_____call__,
    &CPyDef_lru_cache_lite,
    &CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__,
    &CPyDef_lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__,
    &CPyDef_lru_cache_lite_nonull,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit_lru_cache__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids.helpers.lru_cache__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids.helpers.lru_cache__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids___helpers___lru_cache(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids___helpers___lru_cache, "dank_mids.helpers.lru_cache__mypyc.init_dank_mids___helpers___lru_cache", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids___helpers___lru_cache", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
