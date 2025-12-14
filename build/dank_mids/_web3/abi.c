#include <Python.h>

PyMODINIT_FUNC
PyInit_abi(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("521ed8d33dbb3a698d71__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids____web3___abi");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "521ed8d33dbb3a698d71__mypyc.init_dank_mids____web3___abi");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_abi(); }
