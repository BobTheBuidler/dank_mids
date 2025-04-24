#include <Python.h>

PyMODINIT_FUNC
PyInit__eth_utils(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("38b311ae8b2cdc7b228c__mypyc"))) return NULL;
    Py_DECREF(tmp);
    void *init_func = PyCapsule_Import("38b311ae8b2cdc7b228c__mypyc.init_dank_mids____eth_utils", 0);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__eth_utils(); }
