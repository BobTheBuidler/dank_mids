#include <Python.h>

PyMODINIT_FUNC
PyInit_ENVIRONMENT_VARIABLES(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("27078baed46c2b030b63__mypyc"))) return NULL;
    Py_DECREF(tmp);
    void *init_func = PyCapsule_Import("27078baed46c2b030b63__mypyc.init_dank_mids___ENVIRONMENT_VARIABLES", 0);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_ENVIRONMENT_VARIABLES(); }
