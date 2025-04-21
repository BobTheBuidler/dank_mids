#include <Python.h>

PyMODINIT_FUNC
PyInit_call(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("09f9aecb699d55c89e25__mypyc"))) return NULL;
    Py_DECREF(tmp);
    void *init_func = PyCapsule_Import("09f9aecb699d55c89e25__mypyc.init_dank_mids___brownie_patch___call", 0);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_call(); }
