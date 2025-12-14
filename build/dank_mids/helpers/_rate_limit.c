#include <Python.h>

PyMODINIT_FUNC
PyInit__rate_limit(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("9e8e2bd62adbcef60f26__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___helpers____rate_limit");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "9e8e2bd62adbcef60f26__mypyc.init_dank_mids___helpers____rate_limit");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__rate_limit(); }
