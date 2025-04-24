#include <Python.h>

PyMODINIT_FUNC
PyInit_overloaded(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("e6672d9bb5f5e6f1d9d6__mypyc"))) return NULL;
    Py_DECREF(tmp);
    void *init_func = PyCapsule_Import("e6672d9bb5f5e6f1d9d6__mypyc.init_dank_mids___brownie_patch___overloaded", 0);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_overloaded(); }
