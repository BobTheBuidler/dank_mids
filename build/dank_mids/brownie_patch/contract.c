#include <Python.h>

PyMODINIT_FUNC
PyInit_contract(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("e5dc2d3094077f64daf3__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___brownie_patch___contract");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "e5dc2d3094077f64daf3__mypyc.init_dank_mids___brownie_patch___contract");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_contract(); }
