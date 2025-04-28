#include <Python.h>

PyMODINIT_FUNC
PyInit__weaklist(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("c6c6c8f11e2c85534eef__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___helpers____weaklist");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "c6c6c8f11e2c85534eef__mypyc.init_dank_mids___helpers____weaklist");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__weaklist(); }
