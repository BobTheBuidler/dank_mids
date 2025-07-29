#include <Python.h>

PyMODINIT_FUNC
PyInit__logging(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("54f21a262a241d48537c__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids____logging");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "54f21a262a241d48537c__mypyc.init_dank_mids____logging");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__logging(); }
