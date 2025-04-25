#include <Python.h>

PyMODINIT_FUNC
PyInit_lru_cache(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("a6bf1912b3ebbb452765__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___helpers___lru_cache");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "a6bf1912b3ebbb452765__mypyc.init_dank_mids___helpers___lru_cache");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_lru_cache(); }
