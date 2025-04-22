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
#include "__native__weaklist.h"
#include "__native_internal__weaklist.h"

static int
WeakList_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static Py_ssize_t CPyDunder___len__WeakList(PyObject *self) {
    CPyTagged retval = CPyDef_WeakList_____len__(self);
    if (retval == CPY_INT_TAG) {
        return -1;
    }
    Py_ssize_t val = CPyTagged_AsSsize_t(retval);
    CPyTagged_DECREF(retval);
    if (PyErr_Occurred()) return -1;
    return val;
}
static PyMappingMethods WeakList_as_mapping = {
    .mp_length = CPyDunder___len__WeakList,
};
static int CPyDunder___contains__WeakList(PyObject *self, PyObject *obj_item) {
    PyObject *arg_item = obj_item;
    char val = CPyDef_WeakList_____contains__(self, arg_item);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PySequenceMethods WeakList_as_sequence = {
    .sq_contains = CPyDunder___contains__WeakList,
};
static int CPyDunder___bool__WeakList(PyObject *self) {
    char val = CPyDef_WeakList_____bool__(self);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PyNumberMethods WeakList_as_number = {
    .nb_bool = CPyDunder___bool__WeakList,
};
static PyObject *WeakList_setup(PyTypeObject *type);
PyObject *CPyDef_WeakList(PyObject *cpy_r_data);

static PyObject *
WeakList_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_WeakList) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = WeakList_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_WeakList_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
WeakList_traverse(dank_mids___helpers____weaklist___WeakListObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->__refs);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
WeakList_clear(dank_mids___helpers____weaklist___WeakListObject *self)
{
    Py_CLEAR(self->__refs);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
WeakList_dealloc(dank_mids___helpers____weaklist___WeakListObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, WeakList_dealloc)
    WeakList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem WeakList_vtable[10];
static bool
CPyDef_WeakList_trait_vtable_setup(void)
{
    CPyVTableItem WeakList_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_WeakList_____init__,
        (CPyVTableItem)CPyDef_WeakList_____repr__,
        (CPyVTableItem)CPyDef_WeakList_____len__,
        (CPyVTableItem)CPyDef_WeakList_____bool__,
        (CPyVTableItem)CPyDef_WeakList_____contains__,
        (CPyVTableItem)CPyDef_WeakList_____iter__,
        (CPyVTableItem)CPyDef_WeakList___append,
        (CPyVTableItem)CPyDef_WeakList___extend,
        (CPyVTableItem)CPyDef_WeakList___remove,
        (CPyVTableItem)CPyDef_WeakList____gc_callback,
    };
    memcpy(WeakList_vtable, WeakList_vtable_scratch, sizeof(WeakList_vtable));
    return 1;
}

static PyObject *
WeakList_get__refs(dank_mids___helpers____weaklist___WeakListObject *self, void *closure);
static int
WeakList_set__refs(dank_mids___helpers____weaklist___WeakListObject *self, PyObject *value, void *closure);

static PyGetSetDef WeakList_getseters[] = {
    {"_refs",
     (getter)WeakList_get__refs, (setter)WeakList_set__refs,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef WeakList_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_WeakList_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__repr__",
     (PyCFunction)CPyPy_WeakList_____repr__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__len__",
     (PyCFunction)CPyPy_WeakList_____len__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__bool__",
     (PyCFunction)CPyPy_WeakList_____bool__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__contains__",
     (PyCFunction)CPyPy_WeakList_____contains__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_WeakList_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"append",
     (PyCFunction)CPyPy_WeakList___append,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"extend",
     (PyCFunction)CPyPy_WeakList___extend,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"remove",
     (PyCFunction)CPyPy_WeakList___remove,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"_gc_callback",
     (PyCFunction)CPyPy_WeakList____gc_callback,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_WeakList_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "WeakList",
    .tp_new = WeakList_new,
    .tp_dealloc = (destructor)WeakList_dealloc,
    .tp_traverse = (traverseproc)WeakList_traverse,
    .tp_clear = (inquiry)WeakList_clear,
    .tp_getset = WeakList_getseters,
    .tp_methods = WeakList_methods,
    .tp_init = WeakList_init,
    .tp_iter = CPyDef_WeakList_____iter__,
    .tp_repr = CPyDef_WeakList_____repr__,
    .tp_as_mapping = &WeakList_as_mapping,
    .tp_as_sequence = &WeakList_as_sequence,
    .tp_as_number = &WeakList_as_number,
    .tp_basicsize = sizeof(dank_mids___helpers____weaklist___WeakListObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_WeakList_template = &CPyType_WeakList_template_;

static PyObject *
WeakList_setup(PyTypeObject *type)
{
    dank_mids___helpers____weaklist___WeakListObject *self;
    self = (dank_mids___helpers____weaklist___WeakListObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = WeakList_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_WeakList(PyObject *cpy_r_data)
{
    PyObject *self = WeakList_setup(CPyType_WeakList);
    if (self == NULL)
        return NULL;
    char res = CPyDef_WeakList_____init__(self, cpy_r_data);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
WeakList_get__refs(dank_mids___helpers____weaklist___WeakListObject *self, void *closure)
{
    if (unlikely(self->__refs == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_refs' of 'WeakList' undefined");
        return NULL;
    }
    CPy_INCREF(self->__refs);
    PyObject *retval = self->__refs;
    return retval;
}

static int
WeakList_set__refs(dank_mids___helpers____weaklist___WeakListObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'WeakList' object attribute '_refs' cannot be deleted");
        return -1;
    }
    if (self->__refs != NULL) {
        CPy_DECREF(self->__refs);
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
    self->__refs = tmp;
    return 0;
}

static PyObject *__iter___3_WeakList_env_setup(PyTypeObject *type);
PyObject *CPyDef___iter___3_WeakList_env(void);

static PyObject *
__iter___3_WeakList_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___iter___3_WeakList_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __iter___3_WeakList_env_setup(type);
}

static int
__iter___3_WeakList_env_traverse(dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_self);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->___mypyc_temp__0);
    Py_VISIT(self->___mypyc_temp__3);
    Py_VISIT(self->_r);
    Py_VISIT(self->_obj);
    return 0;
}

static int
__iter___3_WeakList_env_clear(dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_self);
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
    Py_CLEAR(self->___mypyc_temp__3);
    Py_CLEAR(self->_r);
    Py_CLEAR(self->_obj);
    return 0;
}

static void
__iter___3_WeakList_env_dealloc(dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __iter___3_WeakList_env_dealloc)
    __iter___3_WeakList_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __iter___3_WeakList_env_vtable[1];
static bool
CPyDef___iter___3_WeakList_env_trait_vtable_setup(void)
{
    CPyVTableItem __iter___3_WeakList_env_vtable_scratch[] = {
        NULL
    };
    memcpy(__iter___3_WeakList_env_vtable, __iter___3_WeakList_env_vtable_scratch, sizeof(__iter___3_WeakList_env_vtable));
    return 1;
}

static PyMethodDef __iter___3_WeakList_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___iter___3_WeakList_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__iter___WeakList_env",
    .tp_new = __iter___3_WeakList_env_new,
    .tp_dealloc = (destructor)__iter___3_WeakList_env_dealloc,
    .tp_traverse = (traverseproc)__iter___3_WeakList_env_traverse,
    .tp_clear = (inquiry)__iter___3_WeakList_env_clear,
    .tp_methods = __iter___3_WeakList_env_methods,
    .tp_basicsize = sizeof(dank_mids___helpers____weaklist_____iter___3_WeakList_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType___iter___3_WeakList_env_template = &CPyType___iter___3_WeakList_env_template_;

static PyObject *
__iter___3_WeakList_env_setup(PyTypeObject *type)
{
    dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *self;
    self = (dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __iter___3_WeakList_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__1 = CPY_INT_TAG;
    self->___mypyc_temp__2 = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef___iter___3_WeakList_env(void)
{
    PyObject *self = __iter___3_WeakList_env_setup(CPyType___iter___3_WeakList_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *__iter___3_WeakList_gen_setup(PyTypeObject *type);
PyObject *CPyDef___iter___3_WeakList_gen(void);

static PyObject *
__iter___3_WeakList_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___iter___3_WeakList_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __iter___3_WeakList_gen_setup(type);
}

static int
__iter___3_WeakList_gen_traverse(dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
__iter___3_WeakList_gen_clear(dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
__iter___3_WeakList_gen_dealloc(dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __iter___3_WeakList_gen_dealloc)
    __iter___3_WeakList_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __iter___3_WeakList_gen_vtable[6];
static bool
CPyDef___iter___3_WeakList_gen_trait_vtable_setup(void)
{
    CPyVTableItem __iter___3_WeakList_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef___iter___3_WeakList_gen_____next__,
        (CPyVTableItem)CPyDef___iter___3_WeakList_gen___send,
        (CPyVTableItem)CPyDef___iter___3_WeakList_gen_____iter__,
        (CPyVTableItem)CPyDef___iter___3_WeakList_gen___throw,
        (CPyVTableItem)CPyDef___iter___3_WeakList_gen___close,
    };
    memcpy(__iter___3_WeakList_gen_vtable, __iter___3_WeakList_gen_vtable_scratch, sizeof(__iter___3_WeakList_gen_vtable));
    return 1;
}

static PyMethodDef __iter___3_WeakList_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy___iter___3_WeakList_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy___iter___3_WeakList_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy___iter___3_WeakList_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy___iter___3_WeakList_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy___iter___3_WeakList_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy___iter___3_WeakList_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___iter___3_WeakList_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__iter___WeakList_gen",
    .tp_new = __iter___3_WeakList_gen_new,
    .tp_dealloc = (destructor)__iter___3_WeakList_gen_dealloc,
    .tp_traverse = (traverseproc)__iter___3_WeakList_gen_traverse,
    .tp_clear = (inquiry)__iter___3_WeakList_gen_clear,
    .tp_methods = __iter___3_WeakList_gen_methods,
    .tp_iter = CPyDef___iter___3_WeakList_gen_____iter__,
    .tp_iternext = CPyDef___iter___3_WeakList_gen_____next__,
    .tp_basicsize = sizeof(dank_mids___helpers____weaklist_____iter___3_WeakList_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType___iter___3_WeakList_gen_template = &CPyType___iter___3_WeakList_gen_template_;

static PyObject *
__iter___3_WeakList_gen_setup(PyTypeObject *type)
{
    dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *self;
    self = (dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __iter___3_WeakList_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef___iter___3_WeakList_gen(void)
{
    PyObject *self = __iter___3_WeakList_gen_setup(CPyType___iter___3_WeakList_gen);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dank_mids.helpers._weaklist",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_dank_mids___helpers____weaklist(void)
{
    PyObject* modname = NULL;
    if (CPyModule_dank_mids___helpers____weaklist_internal) {
        Py_INCREF(CPyModule_dank_mids___helpers____weaklist_internal);
        return CPyModule_dank_mids___helpers____weaklist_internal;
    }
    CPyModule_dank_mids___helpers____weaklist_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_dank_mids___helpers____weaklist_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_dank_mids___helpers____weaklist_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_dank_mids___helpers____weaklist_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType___iter___3_WeakList_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___iter___3_WeakList_env_template, NULL, modname);
    if (unlikely(!CPyType___iter___3_WeakList_env))
        goto fail;
    CPyType___iter___3_WeakList_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___iter___3_WeakList_gen_template, NULL, modname);
    if (unlikely(!CPyType___iter___3_WeakList_gen))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_dank_mids___helpers____weaklist_internal;
    fail:
    Py_CLEAR(CPyModule_dank_mids___helpers____weaklist_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_ref);
    CPyStatic_ref = NULL;
    CPy_XDECREF(CPyStatic__call_ref);
    CPyStatic__call_ref = NULL;
    Py_CLEAR(CPyType_WeakList);
    Py_CLEAR(CPyType___iter___3_WeakList_env);
    Py_CLEAR(CPyType___iter___3_WeakList_gen);
    return NULL;
}

char CPyDef_WeakList_____init__(PyObject *cpy_r_self, PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    if (cpy_r_data != NULL) goto CPyL8;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_data = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = PyDict_New();
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__init__", 17, CPyStatic_globals);
        goto CPyL9;
    }
    if (((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs != NULL) {
        CPy_DECREF(((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs);
    }
    ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs = cpy_r_r1;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__init__", 17, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_data != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL10;
    cpy_r_r5 = CPyDef_WeakList___extend(cpy_r_self, cpy_r_data);
    CPy_DECREF(cpy_r_data);
    if (unlikely(cpy_r_r5 == 2)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__init__", 19, CPyStatic_globals);
        goto CPyL7;
    }
CPyL6: ;
    return 1;
CPyL7: ;
    cpy_r_r6 = 2;
    return cpy_r_r6;
CPyL8: ;
    CPy_INCREF(cpy_r_data);
    goto CPyL2;
CPyL9: ;
    CPy_DecRef(cpy_r_data);
    goto CPyL7;
CPyL10: ;
    CPy_DECREF(cpy_r_data);
    goto CPyL6;
}

PyObject *CPyPy_WeakList_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"data", 0};
    PyObject *obj_data = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O", "__init__", kwlist, &obj_data)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    PyObject *arg_data;
    if (obj_data == NULL) {
        arg_data = NULL;
        goto __LL1;
    }
    arg_data = obj_data;
    if (arg_data != NULL) goto __LL1;
    if (obj_data == Py_None)
        arg_data = obj_data;
    else {
        arg_data = NULL;
    }
    if (arg_data != NULL) goto __LL1;
    CPy_TypeError("object or None", obj_data); 
    goto fail;
__LL1: ;
    char retval = CPyDef_WeakList_____init__(arg_self, arg_data);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__init__", 15, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WeakList_____repr__(PyObject *cpy_r_self) {
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
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    cpy_r_r0 = PyObject_Type(cpy_r_self);
    cpy_r_r1 = CPyStatics[3]; /* '__name__' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__repr__", 23, CPyStatic_globals);
        goto CPyL8;
    }
    if (likely(PyUnicode_Check(cpy_r_r2)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeErrorTraceback("dank_mids/helpers/_weaklist.py", "__repr__", 23, CPyStatic_globals, "str", cpy_r_r2);
        goto CPyL8;
    }
    cpy_r_r4 = CPyStatics[4]; /* '([' */
    cpy_r_r5 = CPyStatics[5]; /* ', ' */
    cpy_r_r6 = CPyModule_builtins;
    cpy_r_r7 = CPyStatics[6]; /* 'repr' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__repr__", 23, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r9 = CPyModule_builtins;
    cpy_r_r10 = CPyStatics[7]; /* 'map' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__repr__", 23, CPyStatic_globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r12[2] = {cpy_r_r8, cpy_r_self};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r11, cpy_r_r13, 2, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__repr__", 23, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r8);
    cpy_r_r15 = PyUnicode_Join(cpy_r_r5, cpy_r_r14);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__repr__", 23, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r16 = CPyStatics[8]; /* '])' */
    cpy_r_r17 = CPyStr_Build(4, cpy_r_r3, cpy_r_r4, cpy_r_r15, cpy_r_r16);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__repr__", 23, CPyStatic_globals);
        goto CPyL8;
    }
    return cpy_r_r17;
CPyL8: ;
    cpy_r_r18 = NULL;
    return cpy_r_r18;
CPyL9: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r8);
    goto CPyL8;
}

PyObject *CPyPy_WeakList_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WeakList_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__repr__", 21, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_WeakList_____len__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    int64_t cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_r3;
    cpy_r_r0 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__len__", "WeakList", "_refs", 26, CPyStatic_globals);
        goto CPyL2;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = PyDict_Size(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 << 1;
    return cpy_r_r2;
CPyL2: ;
    cpy_r_r3 = CPY_INT_TAG;
    return cpy_r_r3;
}

PyObject *CPyPy_WeakList_____len__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__len__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    CPyTagged retval = CPyDef_WeakList_____len__(arg_self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__len__", 25, CPyStatic_globals);
    return NULL;
}

char CPyDef_WeakList_____bool__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    int64_t cpy_r_r1;
    CPyTagged cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    cpy_r_r0 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__bool__", "WeakList", "_refs", 29, CPyStatic_globals);
        goto CPyL2;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = PyDict_Size(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 << 1;
    cpy_r_r3 = cpy_r_r2 != 0;
    return cpy_r_r3;
CPyL2: ;
    cpy_r_r4 = 2;
    return cpy_r_r4;
}

PyObject *CPyPy_WeakList_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__bool__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    char retval = CPyDef_WeakList_____bool__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__bool__", 28, CPyStatic_globals);
    return NULL;
}

char CPyDef_WeakList_____contains__(PyObject *cpy_r_self, PyObject *cpy_r_item) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_ref;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    cpy_r_r0 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__contains__", "WeakList", "_refs", 32, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyTagged_Id(cpy_r_item);
    cpy_r_r2 = CPyTagged_StealAsObject(cpy_r_r1);
    cpy_r_r3 = CPyDict_GetWithNone(cpy_r_r0, cpy_r_r2);
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__contains__", 32, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_ref = cpy_r_r3;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_ref == cpy_r_r4;
    if (cpy_r_r5) {
        goto CPyL8;
    } else
        goto CPyL4;
CPyL3: ;
    cpy_r_r6 = 0;
    goto CPyL6;
CPyL4: ;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_ref, 0, 0, 0);
    CPy_DECREF(cpy_r_ref);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__contains__", 33, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r8 = cpy_r_r7 == cpy_r_item;
    CPy_DECREF(cpy_r_r7);
    cpy_r_r6 = cpy_r_r8;
CPyL6: ;
    return cpy_r_r6;
CPyL7: ;
    cpy_r_r9 = 2;
    return cpy_r_r9;
CPyL8: ;
    CPy_DECREF(cpy_r_ref);
    goto CPyL3;
}

PyObject *CPyPy_WeakList_____contains__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"item", 0};
    static CPyArg_Parser parser = {"O:__contains__", kwlist, 0};
    PyObject *obj_item;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_item)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    PyObject *arg_item = obj_item;
    char retval = CPyDef_WeakList_____contains__(arg_self, arg_item);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__contains__", 31, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    int64_t cpy_r_r9;
    CPyTagged cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    CPyTagged cpy_r_r15;
    tuple_T3CIO cpy_r_r16;
    CPyTagged cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    CPyTagged cpy_r_r40;
    char cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    char cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    cpy_r_r0 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_gen", "__mypyc_env__", 35, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "__mypyc_next_label__", 35, CPyStatic_globals);
        goto CPyL46;
    }
    CPyTagged_INCREF(cpy_r_r1);
    goto CPyL41;
CPyL2: ;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = cpy_r_type != cpy_r_r2;
    if (cpy_r_r3) {
        goto CPyL47;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r4 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_self;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "self", 36, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_INCREF(cpy_r_r4);
CPyL6: ;
    cpy_r_r5 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_r4)->__refs;
    if (unlikely(cpy_r_r5 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '_refs' of 'WeakList' undefined");
    } else {
        CPy_INCREF(cpy_r_r5);
    }
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 36, CPyStatic_globals);
        goto CPyL46;
    }
CPyL7: ;
    CPy_INCREF(cpy_r_r5);
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__0 != NULL) {
        CPy_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__0);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__0 = cpy_r_r5;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", -1, CPyStatic_globals);
        goto CPyL48;
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__1 = 0;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", -1, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r8 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__0;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "__mypyc_temp__0", 36, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_INCREF(cpy_r_r8);
CPyL10: ;
    cpy_r_r9 = PyDict_Size(cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r10 = cpy_r_r9 << 1;
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__2 = cpy_r_r10;
    cpy_r_r11 = 1;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", -1, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r12 = CPyDict_GetValuesIter(cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 36, CPyStatic_globals);
        goto CPyL46;
    }
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__3 != NULL) {
        CPy_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__3);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__3 = cpy_r_r12;
    cpy_r_r13 = 1;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", -1, CPyStatic_globals);
        goto CPyL46;
    }
CPyL13: ;
    cpy_r_r14 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__3;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "__mypyc_temp__3", 36, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_INCREF(cpy_r_r14);
CPyL14: ;
    cpy_r_r15 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__1;
    if (unlikely(cpy_r_r15 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "__mypyc_temp__1", 36, CPyStatic_globals);
        goto CPyL49;
    }
CPyL15: ;
    cpy_r_r16 = CPyDict_NextValue(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    cpy_r_r17 = cpy_r_r16.f1;
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__1 = cpy_r_r17;
    cpy_r_r18 = 1;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 36, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r19 = cpy_r_r16.f0;
    if (!cpy_r_r19) goto CPyL51;
    cpy_r_r20 = cpy_r_r16.f2;
    CPy_INCREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r16.f2);
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_r != NULL) {
        CPy_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_r);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_r = cpy_r_r20;
    cpy_r_r21 = 1;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 36, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r22 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_r;
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "r", 37, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_INCREF(cpy_r_r22);
CPyL19: ;
    cpy_r_r23 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r24 = cpy_r_r22 != cpy_r_r23;
    CPy_DECREF(cpy_r_r22);
    if (!cpy_r_r24) goto CPyL34;
    cpy_r_r25 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_r;
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "r", 38, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_INCREF(cpy_r_r25);
CPyL21: ;
    cpy_r_r26 = CPyStatic__call_ref;
    if (unlikely(cpy_r_r26 == NULL)) {
        goto CPyL52;
    } else
        goto CPyL24;
CPyL22: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_call_ref\" was not set");
    cpy_r_r27 = 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 38, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_Unreachable();
CPyL24: ;
    PyObject *cpy_r_r28[1] = {cpy_r_r25};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r26, cpy_r_r29, 1, 0);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 38, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_r25);
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_obj != NULL) {
        CPy_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_obj);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_obj = cpy_r_r30;
    cpy_r_r31 = 1;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 38, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r32 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_obj;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "obj", 39, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_INCREF(cpy_r_r32);
CPyL27: ;
    cpy_r_r33 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r34 = cpy_r_r32 != cpy_r_r33;
    CPy_DECREF(cpy_r_r32);
    if (!cpy_r_r34) goto CPyL34;
    cpy_r_r35 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_obj;
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "obj", 40, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_INCREF(cpy_r_r35);
CPyL29: ;
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__ = 2;
    cpy_r_r36 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 40, CPyStatic_globals);
        goto CPyL54;
    }
    return cpy_r_r35;
CPyL31: ;
    cpy_r_r37 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r38 = cpy_r_type != cpy_r_r37;
    if (cpy_r_r38) {
        goto CPyL55;
    } else
        goto CPyL34;
CPyL32: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 40, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_Unreachable();
CPyL34: ;
    cpy_r_r39 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__0;
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "__mypyc_temp__0", 36, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_INCREF(cpy_r_r39);
CPyL35: ;
    cpy_r_r40 = ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_temp__2;
    if (unlikely(cpy_r_r40 == CPY_INT_TAG)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "__iter__", "__iter___WeakList_env", "__mypyc_temp__2", 36, CPyStatic_globals);
        goto CPyL56;
    }
CPyL36: ;
    cpy_r_r41 = CPyDict_CheckSize(cpy_r_r39, cpy_r_r40);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 36, CPyStatic_globals);
        goto CPyL46;
    } else
        goto CPyL13;
CPyL37: ;
    cpy_r_r42 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 36, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r43 = Py_None;
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__ = -2;
    cpy_r_r44 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r44)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
        goto CPyL45;
    }
    CPyGen_SetStopIterationValue(cpy_r_r43);
    if (!0) goto CPyL45;
    CPy_Unreachable();
CPyL41: ;
    cpy_r_r45 = cpy_r_r1 == 0;
    if (cpy_r_r45) goto CPyL57;
    cpy_r_r46 = cpy_r_r1 == 2;
    CPyTagged_DECREF(cpy_r_r1);
    if (cpy_r_r46) {
        goto CPyL31;
    } else
        goto CPyL58;
CPyL43: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r47 = 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_Unreachable();
CPyL45: ;
    cpy_r_r48 = NULL;
    return cpy_r_r48;
CPyL46: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL45;
CPyL47: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL3;
CPyL48: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    goto CPyL45;
CPyL49: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r14);
    goto CPyL45;
CPyL50: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16.f2);
    goto CPyL45;
CPyL51: ;
    CPy_DECREF(cpy_r_r16.f2);
    goto CPyL37;
CPyL52: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r25);
    goto CPyL22;
CPyL53: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r25);
    goto CPyL45;
CPyL54: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL45;
CPyL55: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL32;
CPyL56: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r39);
    goto CPyL45;
CPyL57: ;
    CPyTagged_DECREF(cpy_r_r1);
    goto CPyL2;
CPyL58: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL43;
}

PyObject *CPyPy___iter___3_WeakList_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___iter___3_WeakList_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy___iter___3_WeakList_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___iter___3_WeakList_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.__iter___WeakList_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___iter___3_WeakList_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___iter___3_WeakList_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy___iter___3_WeakList_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___iter___3_WeakList_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.__iter___WeakList_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef___iter___3_WeakList_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___iter___3_WeakList_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy___iter___3_WeakList_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___iter___3_WeakList_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.__iter___WeakList_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___iter___3_WeakList_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___iter___3_WeakList_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
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
    cpy_r_r1 = CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
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

PyObject *CPyPy___iter___3_WeakList_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___iter___3_WeakList_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.__iter___WeakList_gen", obj___mypyc_self__); 
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
    PyObject *retval = CPyDef___iter___3_WeakList_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___iter___3_WeakList_gen___close(PyObject *cpy_r___mypyc_self__) {
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
    cpy_r_r1 = CPyStatics[9]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef___iter___3_WeakList_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[10]; /* 'StopIteration' */
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

PyObject *CPyPy___iter___3_WeakList_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___iter___3_WeakList_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.__iter___WeakList_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___iter___3_WeakList_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WeakList_____iter__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    cpy_r_r0 = CPyDef___iter___3_WeakList_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_self);
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_self != NULL) {
        CPy_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_self);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->_self = cpy_r_self;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r2 = CPyDef___iter___3_WeakList_gen();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_r0);
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *)cpy_r_r2)->___mypyc_env__ != NULL) {
        CPy_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *)cpy_r_r2)->___mypyc_env__);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_genObject *)cpy_r_r2)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
        goto CPyL8;
    }
    if (((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((dank_mids___helpers____weaklist_____iter___3_WeakList_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r4 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
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

PyObject *CPyPy_WeakList_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WeakList_____iter__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "__iter__", 35, CPyStatic_globals);
    return NULL;
}

char CPyDef_WeakList___append(PyObject *cpy_r_self, PyObject *cpy_r_item) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyTagged cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    cpy_r_r0 = CPyStatics[11]; /* '_gc_callback' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "append", 44, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r2 = CPyStatic_ref;
    if (unlikely(cpy_r_r2 == NULL)) {
        goto CPyL9;
    } else
        goto CPyL4;
CPyL2: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ref\" was not set");
    cpy_r_r3 = 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "append", 44, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_Unreachable();
CPyL4: ;
    PyObject *cpy_r_r4[2] = {cpy_r_item, cpy_r_r1};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r5, 2, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "append", 44, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r1);
    cpy_r_r7 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "append", "WeakList", "_refs", 44, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_INCREF(cpy_r_r7);
CPyL6: ;
    cpy_r_r8 = CPyTagged_Id(cpy_r_item);
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_r8);
    cpy_r_r10 = CPyDict_SetItem(cpy_r_r7, cpy_r_r9, cpy_r_r6);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r6);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "append", 44, CPyStatic_globals);
        goto CPyL8;
    }
    return 1;
CPyL8: ;
    cpy_r_r12 = 2;
    return cpy_r_r12;
CPyL9: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL2;
CPyL10: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL8;
CPyL11: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL8;
}

PyObject *CPyPy_WeakList___append(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"item", 0};
    static CPyArg_Parser parser = {"O:append", kwlist, 0};
    PyObject *obj_item;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_item)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    PyObject *arg_item = obj_item;
    char retval = CPyDef_WeakList___append(arg_self, arg_item);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "append", 42, CPyStatic_globals);
    return NULL;
}

char CPyDef_WeakList___extend(PyObject *cpy_r_self, PyObject *cpy_r_items) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    CPyTagged cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    tuple_T2IO cpy_r_r12;
    PyObject *cpy_r_r13;
    int32_t cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    int32_t cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    cpy_r_r0 = CPyStatics[11]; /* '_gc_callback' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 47, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r2 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "extend", "WeakList", "_refs", 48, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_INCREF(cpy_r_r2);
CPyL2: ;
    cpy_r_r3 = PyList_New(0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 48, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r4 = PyObject_GetIter(cpy_r_items);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 48, CPyStatic_globals);
        goto CPyL16;
    }
CPyL4: ;
    cpy_r_r5 = PyIter_Next(cpy_r_r4);
    if (cpy_r_r5 == NULL) goto CPyL17;
    cpy_r_r6 = CPyTagged_Id(cpy_r_r5);
    cpy_r_r7 = CPyStatic_ref;
    if (unlikely(cpy_r_r7 == NULL)) {
        goto CPyL18;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ref\" was not set");
    cpy_r_r8 = 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 48, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL8: ;
    PyObject *cpy_r_r9[2] = {cpy_r_r5, cpy_r_r1};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = _PyObject_Vectorcall(cpy_r_r7, cpy_r_r10, 2, 0);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 48, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_DECREF(cpy_r_r5);
    cpy_r_r12.f0 = cpy_r_r6;
    cpy_r_r12.f1 = cpy_r_r11;
    cpy_r_r13 = PyTuple_New(2);
    if (unlikely(cpy_r_r13 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp4 = CPyTagged_StealAsObject(cpy_r_r12.f0);
    PyTuple_SET_ITEM(cpy_r_r13, 0, __tmp4);
    PyObject *__tmp5 = cpy_r_r12.f1;
    PyTuple_SET_ITEM(cpy_r_r13, 1, __tmp5);
    cpy_r_r14 = PyList_Append(cpy_r_r3, cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    cpy_r_r15 = cpy_r_r14 >= 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 48, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL4;
CPyL10: ;
    cpy_r_r16 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 48, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r17 = CPyDict_UpdateFromAny(cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r3);
    cpy_r_r18 = cpy_r_r17 >= 0;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 48, CPyStatic_globals);
        goto CPyL13;
    }
    return 1;
CPyL13: ;
    cpy_r_r19 = 2;
    return cpy_r_r19;
CPyL14: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL13;
CPyL15: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL13;
CPyL16: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    goto CPyL13;
CPyL17: ;
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r4);
    goto CPyL10;
CPyL18: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    goto CPyL6;
CPyL19: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    goto CPyL13;
CPyL20: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL13;
CPyL21: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    goto CPyL13;
}

PyObject *CPyPy_WeakList___extend(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"items", 0};
    static CPyArg_Parser parser = {"O:extend", kwlist, 0};
    PyObject *obj_items;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_items)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    PyObject *arg_items = obj_items;
    char retval = CPyDef_WeakList___extend(arg_self, arg_items);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "extend", 46, CPyStatic_globals);
    return NULL;
}

char CPyDef_WeakList___remove(PyObject *cpy_r_self, PyObject *cpy_r_item) {
    CPyTagged cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_ref;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    int32_t cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    cpy_r_r0 = CPyTagged_Id(cpy_r_item);
    cpy_r_r1 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "remove", "WeakList", "_refs", 52, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_INCREF(cpy_r_r1);
CPyL1: ;
    CPyTagged_INCREF(cpy_r_r0);
    cpy_r_r2 = CPyTagged_StealAsObject(cpy_r_r0);
    cpy_r_r3 = CPyDict_GetWithNone(cpy_r_r1, cpy_r_r2);
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "remove", 52, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_ref = cpy_r_r3;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_ref == cpy_r_r4;
    if (cpy_r_r5) goto CPyL14;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_ref, 0, 0, 0);
    CPy_DECREF(cpy_r_ref);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "remove", 53, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r7 = cpy_r_r6 == cpy_r_item;
    CPy_DECREF(cpy_r_r6);
    cpy_r_r8 = cpy_r_r7 ^ 1;
    if (cpy_r_r8) {
        goto CPyL15;
    } else
        goto CPyL9;
CPyL5: ;
    cpy_r_r9 = CPyStatics[12]; /* 'list.remove(x): x not in list' */
    cpy_r_r10 = CPyModule_builtins;
    cpy_r_r11 = CPyStatics[13]; /* 'ValueError' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "remove", 54, CPyStatic_globals);
        goto CPyL12;
    }
    PyObject *cpy_r_r13[1] = {cpy_r_r9};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "remove", 54, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_Raise(cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(!0)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "remove", 54, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_Unreachable();
CPyL9: ;
    cpy_r_r16 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "remove", "WeakList", "_refs", 55, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_INCREF(cpy_r_r16);
CPyL10: ;
    cpy_r_r17 = CPyTagged_StealAsObject(cpy_r_r0);
    cpy_r_r18 = PyObject_DelItem(cpy_r_r16, cpy_r_r17);
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "remove", 55, CPyStatic_globals);
        goto CPyL12;
    }
    return 1;
CPyL12: ;
    cpy_r_r20 = 2;
    return cpy_r_r20;
CPyL13: ;
    CPyTagged_DecRef(cpy_r_r0);
    goto CPyL12;
CPyL14: ;
    CPyTagged_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_ref);
    goto CPyL5;
CPyL15: ;
    CPyTagged_DECREF(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_WeakList___remove(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"item", 0};
    static CPyArg_Parser parser = {"O:remove", kwlist, 0};
    PyObject *obj_item;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_item)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    PyObject *arg_item = obj_item;
    char retval = CPyDef_WeakList___remove(arg_self, arg_item);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "remove", 50, CPyStatic_globals);
    return NULL;
}

char CPyDef_WeakList____gc_callback(PyObject *cpy_r_self, PyObject *cpy_r_item) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    cpy_r_r0 = ((dank_mids___helpers____weaklist___WeakListObject *)cpy_r_self)->__refs;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("dank_mids/helpers/_weaklist.py", "_gc_callback", "WeakList", "_refs", 59, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyTagged_Id(cpy_r_item);
    cpy_r_r2 = CPyStatics[14]; /* 'pop' */
    cpy_r_r3 = CPyTagged_StealAsObject(cpy_r_r1);
    cpy_r_r4 = Py_None;
    PyObject *cpy_r_r5[3] = {cpy_r_r0, cpy_r_r3, cpy_r_r4};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r6, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "_gc_callback", 59, CPyStatic_globals);
        goto CPyL4;
    } else
        goto CPyL5;
CPyL2: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r3);
    return 1;
CPyL3: ;
    cpy_r_r8 = 2;
    return cpy_r_r8;
CPyL4: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r3);
    goto CPyL3;
CPyL5: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL2;
}

PyObject *CPyPy_WeakList____gc_callback(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"item", 0};
    static CPyArg_Parser parser = {"O:_gc_callback", kwlist, 0};
    PyObject *obj_item;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_item)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WeakList))
        arg_self = obj_self;
    else {
        CPy_TypeError("dank_mids.helpers._weaklist.WeakList", obj_self); 
        goto fail;
    }
    PyObject *arg_item = obj_item;
    char retval = CPyDef_WeakList____gc_callback(arg_self, arg_item);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "_gc_callback", 57, CPyStatic_globals);
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
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    int32_t cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    CPyPtr cpy_r_r48;
    CPyPtr cpy_r_r49;
    PyObject *cpy_r_r50;
    tuple_T2OO cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    int32_t cpy_r_r56;
    char cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    int32_t cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    int32_t cpy_r_r72;
    char cpy_r_r73;
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
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    int32_t cpy_r_r90;
    char cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    int32_t cpy_r_r94;
    char cpy_r_r95;
    char cpy_r_r96;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[15]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", -1, CPyStatic_globals);
        goto CPyL32;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_weakref;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[42]; /* (('weakref', 'weakref', 'weakref'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[17]; /* 'dank_mids/helpers/_weaklist.py' */
    cpy_r_r13 = CPyStatics[18]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL32;
    cpy_r_r15 = CPyStatics[43]; /* ('Any', 'Callable', 'Dict', 'Final', 'Generic', 'Iterable',
                                   'Iterator', 'Optional', 'TypeVar') */
    cpy_r_r16 = CPyStatics[28]; /* 'typing' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 2, CPyStatic_globals);
        goto CPyL32;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[29]; /* '_T' */
    cpy_r_r20 = CPyStatic_globals;
    cpy_r_r21 = CPyStatics[27]; /* 'TypeVar' */
    cpy_r_r22 = CPyDict_GetItem(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 5, CPyStatic_globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r23[1] = {cpy_r_r19};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = _PyObject_Vectorcall(cpy_r_r22, cpy_r_r24, 1, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 5, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyStatics[29]; /* '_T' */
    cpy_r_r28 = CPyDict_SetItem(cpy_r_r26, cpy_r_r27, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 5, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r30 = CPyModule_weakref;
    cpy_r_r31 = CPyStatics[30]; /* 'ReferenceType' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 7, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r33 = CPyStatic_globals;
    cpy_r_r34 = CPyStatics[29]; /* '_T' */
    cpy_r_r35 = CPyDict_GetItem(cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 7, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r36 = PyObject_GetItem(cpy_r_r32, cpy_r_r35);
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 7, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyStatics[31]; /* 'Ref' */
    cpy_r_r39 = CPyDict_SetItem(cpy_r_r37, cpy_r_r38, cpy_r_r36);
    CPy_DECREF(cpy_r_r36);
    cpy_r_r40 = cpy_r_r39 >= 0;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 7, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r41 = CPyStatic_globals;
    cpy_r_r42 = CPyStatics[20]; /* 'Callable' */
    cpy_r_r43 = CPyDict_GetItem(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 8, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r44 = CPyStatic_globals;
    cpy_r_r45 = CPyStatics[19]; /* 'Any' */
    cpy_r_r46 = CPyDict_GetItem(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 8, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r47 = PyList_New(1);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 8, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r48 = (CPyPtr)&((PyListObject *)cpy_r_r47)->ob_item;
    cpy_r_r49 = *(CPyPtr *)cpy_r_r48;
    *(PyObject * *)cpy_r_r49 = cpy_r_r46;
    cpy_r_r50 = Py_None;
    CPy_INCREF(cpy_r_r50);
    cpy_r_r51.f0 = cpy_r_r47;
    cpy_r_r51.f1 = cpy_r_r50;
    cpy_r_r52 = PyTuple_New(2);
    if (unlikely(cpy_r_r52 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp6 = cpy_r_r51.f0;
    PyTuple_SET_ITEM(cpy_r_r52, 0, __tmp6);
    PyObject *__tmp7 = cpy_r_r51.f1;
    PyTuple_SET_ITEM(cpy_r_r52, 1, __tmp7);
    cpy_r_r53 = PyObject_GetItem(cpy_r_r43, cpy_r_r52);
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 8, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r54 = CPyStatic_globals;
    cpy_r_r55 = CPyStatics[32]; /* 'GCCallback' */
    cpy_r_r56 = CPyDict_SetItem(cpy_r_r54, cpy_r_r55, cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 8, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r58 = CPyModule_weakref;
    cpy_r_r59 = CPyStatics[33]; /* 'ref' */
    cpy_r_r60 = CPyObject_GetAttr(cpy_r_r58, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 10, CPyStatic_globals);
        goto CPyL32;
    }
    CPyStatic_ref = cpy_r_r60;
    CPy_INCREF(CPyStatic_ref);
    cpy_r_r61 = CPyStatic_globals;
    cpy_r_r62 = CPyStatics[33]; /* 'ref' */
    cpy_r_r63 = CPyDict_SetItem(cpy_r_r61, cpy_r_r62, cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r64 = cpy_r_r63 >= 0;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 10, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r65 = CPyModule_weakref;
    cpy_r_r66 = CPyStatics[33]; /* 'ref' */
    cpy_r_r67 = CPyObject_GetAttr(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 11, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r68 = CPyStatics[34]; /* '__call__' */
    cpy_r_r69 = CPyObject_GetAttr(cpy_r_r67, cpy_r_r68);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 11, CPyStatic_globals);
        goto CPyL32;
    }
    CPyStatic__call_ref = cpy_r_r69;
    CPy_INCREF(CPyStatic__call_ref);
    cpy_r_r70 = CPyStatic_globals;
    cpy_r_r71 = CPyStatics[35]; /* '_call_ref' */
    cpy_r_r72 = CPyDict_SetItem(cpy_r_r70, cpy_r_r71, cpy_r_r69);
    CPy_DECREF(cpy_r_r69);
    cpy_r_r73 = cpy_r_r72 >= 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 11, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r74 = CPyStatic_globals;
    cpy_r_r75 = CPyStatics[23]; /* 'Generic' */
    cpy_r_r76 = CPyDict_GetItem(cpy_r_r74, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 14, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r77 = CPyStatic_globals;
    cpy_r_r78 = CPyStatics[29]; /* '_T' */
    cpy_r_r79 = CPyDict_GetItem(cpy_r_r77, cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 14, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r80 = PyObject_GetItem(cpy_r_r76, cpy_r_r79);
    CPy_DECREF(cpy_r_r76);
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 14, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r81 = PyTuple_Pack(1, cpy_r_r80);
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 14, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r82 = CPyStatics[36]; /* 'dank_mids.helpers._weaklist' */
    cpy_r_r83 = (PyObject *)CPyType_WeakList_template;
    cpy_r_r84 = CPyType_FromTemplate(cpy_r_r83, cpy_r_r81, cpy_r_r82);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 14, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r85 = CPyDef_WeakList_trait_vtable_setup();
    if (unlikely(cpy_r_r85 == 2)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", -1, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r86 = CPyStatics[37]; /* '__mypyc_attrs__' */
    cpy_r_r87 = CPyStatics[38]; /* '_refs' */
    cpy_r_r88 = CPyStatics[39]; /* '__dict__' */
    cpy_r_r89 = PyTuple_Pack(2, cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 14, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r90 = PyObject_SetAttr(cpy_r_r84, cpy_r_r86, cpy_r_r89);
    CPy_DECREF(cpy_r_r89);
    cpy_r_r91 = cpy_r_r90 >= 0;
    if (unlikely(!cpy_r_r91)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 14, CPyStatic_globals);
        goto CPyL37;
    }
    CPyType_WeakList = (PyTypeObject *)cpy_r_r84;
    CPy_INCREF(CPyType_WeakList);
    cpy_r_r92 = CPyStatic_globals;
    cpy_r_r93 = CPyStatics[40]; /* 'WeakList' */
    cpy_r_r94 = CPyDict_SetItem(cpy_r_r92, cpy_r_r93, cpy_r_r84);
    CPy_DECREF(cpy_r_r84);
    cpy_r_r95 = cpy_r_r94 >= 0;
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("dank_mids/helpers/_weaklist.py", "<module>", 14, CPyStatic_globals);
        goto CPyL32;
    }
    return 1;
CPyL32: ;
    cpy_r_r96 = 2;
    return cpy_r_r96;
CPyL33: ;
    CPy_DecRef(cpy_r_r32);
    goto CPyL32;
CPyL34: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL32;
CPyL35: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r46);
    goto CPyL32;
CPyL36: ;
    CPy_DecRef(cpy_r_r76);
    goto CPyL32;
CPyL37: ;
    CPy_DecRef(cpy_r_r84);
    goto CPyL32;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_dank_mids___helpers____weaklist = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_weakref = Py_None;
    CPyModule_typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[44];
const char * const CPyLit_Str[] = {
    "\t\b__name__\002([\002, \004repr\003map\002])\rGeneratorExit\rStopIteration\f_gc_callback",
    "\005\035list.remove(x): x not in list\nValueError\003pop\bbuiltins\aweakref",
    "\006\036dank_mids/helpers/_weaklist.py\b<module>\003Any\bCallable\004Dict\005Final",
    "\b\aGeneric\bIterable\bIterator\bOptional\aTypeVar\006typing\002_T\rReferenceType",
    "\006\003Ref\nGCCallback\003ref\b__call__\t_call_ref\033dank_mids.helpers._weaklist",
    "\004\017__mypyc_attrs__\005_refs\b__dict__\bWeakList",
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
const int CPyLit_Tuple[] = {3, 3, 16, 16, 16, 1, 41, 9, 19, 20, 21, 22, 23, 24, 25, 26, 27};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_dank_mids___helpers____weaklist_internal = NULL;
CPyModule *CPyModule_dank_mids___helpers____weaklist;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_weakref;
CPyModule *CPyModule_typing;
PyObject *CPyStatic_ref = NULL;
PyObject *CPyStatic__call_ref = NULL;
PyTypeObject *CPyType_WeakList;
PyObject *CPyDef_WeakList(PyObject *cpy_r_data);
PyTypeObject *CPyType___iter___3_WeakList_env;
PyObject *CPyDef___iter___3_WeakList_env(void);
PyTypeObject *CPyType___iter___3_WeakList_gen;
PyObject *CPyDef___iter___3_WeakList_gen(void);
char CPyDef_WeakList_____init__(PyObject *cpy_r_self, PyObject *cpy_r_data);
PyObject *CPyPy_WeakList_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_WeakList_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_WeakList_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_WeakList_____len__(PyObject *cpy_r_self);
PyObject *CPyPy_WeakList_____len__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WeakList_____bool__(PyObject *cpy_r_self);
PyObject *CPyPy_WeakList_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WeakList_____contains__(PyObject *cpy_r_self, PyObject *cpy_r_item);
PyObject *CPyPy_WeakList_____contains__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy___iter___3_WeakList_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___iter___3_WeakList_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___iter___3_WeakList_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___iter___3_WeakList_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy___iter___3_WeakList_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___iter___3_WeakList_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___iter___3_WeakList_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___iter___3_WeakList_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy___iter___3_WeakList_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___iter___3_WeakList_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___iter___3_WeakList_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WeakList_____iter__(PyObject *cpy_r_self);
PyObject *CPyPy_WeakList_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WeakList___append(PyObject *cpy_r_self, PyObject *cpy_r_item);
PyObject *CPyPy_WeakList___append(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WeakList___extend(PyObject *cpy_r_self, PyObject *cpy_r_items);
PyObject *CPyPy_WeakList___extend(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WeakList___remove(PyObject *cpy_r_self, PyObject *cpy_r_item);
PyObject *CPyPy_WeakList___remove(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WeakList____gc_callback(PyObject *cpy_r_self, PyObject *cpy_r_item);
PyObject *CPyPy_WeakList____gc_callback(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_dank_mids___helpers____weaklist exports = {
    &CPyStatic_ref,
    &CPyStatic__call_ref,
    &CPyType_WeakList,
    &CPyDef_WeakList,
    &CPyType___iter___3_WeakList_env,
    &CPyDef___iter___3_WeakList_env,
    &CPyType___iter___3_WeakList_gen,
    &CPyDef___iter___3_WeakList_gen,
    &CPyDef_WeakList_____init__,
    &CPyDef_WeakList_____repr__,
    &CPyDef_WeakList_____len__,
    &CPyDef_WeakList_____bool__,
    &CPyDef_WeakList_____contains__,
    &CPyDef___iter___3_WeakList_gen_____mypyc_generator_helper__,
    &CPyDef___iter___3_WeakList_gen_____next__,
    &CPyDef___iter___3_WeakList_gen___send,
    &CPyDef___iter___3_WeakList_gen_____iter__,
    &CPyDef___iter___3_WeakList_gen___throw,
    &CPyDef___iter___3_WeakList_gen___close,
    &CPyDef_WeakList_____iter__,
    &CPyDef_WeakList___append,
    &CPyDef_WeakList___extend,
    &CPyDef_WeakList___remove,
    &CPyDef_WeakList____gc_callback,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit__weaklist__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "dank_mids.helpers._weaklist__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "dank_mids.helpers._weaklist__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_dank_mids___helpers____weaklist(void);
    capsule = PyCapsule_New((void *)CPyInit_dank_mids___helpers____weaklist, "dank_mids.helpers._weaklist__mypyc.init_dank_mids___helpers____weaklist", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_dank_mids___helpers____weaklist", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
