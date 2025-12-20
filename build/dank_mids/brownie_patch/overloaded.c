#include <Python.h>

PyMODINIT_FUNC
PyInit_overloaded(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("e7b95fc71f7e12c4f724__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___brownie_patch___overloaded");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "e7b95fc71f7e12c4f724__mypyc.init_dank_mids___brownie_patch___overloaded");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_overloaded(); }
