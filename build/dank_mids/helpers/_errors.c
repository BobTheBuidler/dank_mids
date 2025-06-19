#include <Python.h>

PyMODINIT_FUNC
PyInit__errors(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("428e411ea874af5ab525__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___helpers____errors");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "428e411ea874af5ab525__mypyc.init_dank_mids___helpers____errors");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__errors(); }
