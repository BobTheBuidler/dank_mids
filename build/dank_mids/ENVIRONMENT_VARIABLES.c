#include <Python.h>

PyMODINIT_FUNC
PyInit_ENVIRONMENT_VARIABLES(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("4ac53595a35a9893ab3b__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___ENVIRONMENT_VARIABLES");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "4ac53595a35a9893ab3b__mypyc.init_dank_mids___ENVIRONMENT_VARIABLES");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_ENVIRONMENT_VARIABLES(); }
