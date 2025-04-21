#include <Python.h>

PyMODINIT_FUNC
PyInit_types(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("dank_mids.brownie_patch.types__mypyc"))) return NULL;
    Py_DECREF(tmp);
    void *init_func = PyCapsule_Import("dank_mids.brownie_patch.types__mypyc.init_dank_mids___brownie_patch___types", 0);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_types(); }
