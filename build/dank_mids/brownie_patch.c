#include <Python.h>

PyMODINIT_FUNC
PyInit_brownie_patch(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("d8ded57d9da9d768aa92__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___brownie_patch");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "d8ded57d9da9d768aa92__mypyc.init_dank_mids___brownie_patch");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_brownie_patch(); }
