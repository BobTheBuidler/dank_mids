#include <Python.h>

PyMODINIT_FUNC
PyInit_types(void)
{
    PyObject *tmp;
<<<<<<< HEAD
    if (!(tmp = PyImport_ImportModule("6486cd47b6f59329387b__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___brownie_patch___types");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "6486cd47b6f59329387b__mypyc.init_dank_mids___brownie_patch___types");
=======
    if (!(tmp = PyImport_ImportModule("e533ac94cbe235f69297__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___brownie_patch___types");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "e533ac94cbe235f69297__mypyc.init_dank_mids___brownie_patch___types");
>>>>>>> chore: extract _RequestEvent to its own module
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_types(); }
