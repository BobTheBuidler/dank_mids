#include <Python.h>

PyMODINIT_FUNC
PyInit__weaklist(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("27078baed46c2b030b63__mypyc"))) return NULL;
    Py_DECREF(tmp);
    void *init_func = PyCapsule_Import("27078baed46c2b030b63__mypyc.init_dank_mids___helpers____weaklist", 0);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__weaklist(); }
