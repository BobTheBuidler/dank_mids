#include <Python.h>

PyMODINIT_FUNC
PyInit_batch_size(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("d3671565f89b6cb0ec69__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___helpers___batch_size");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "d3671565f89b6cb0ec69__mypyc.init_dank_mids___helpers___batch_size");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_batch_size(); }
