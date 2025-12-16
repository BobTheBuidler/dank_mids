#include <Python.h>

PyMODINIT_FUNC
PyInit_batch_size(void)
{
    PyObject *tmp;
<<<<<<< HEAD
    if (!(tmp = PyImport_ImportModule("0bf4c1c413ed1d8eb97f__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___helpers___batch_size");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "0bf4c1c413ed1d8eb97f__mypyc.init_dank_mids___helpers___batch_size");
=======
<<<<<<< HEAD
    if (!(tmp = PyImport_ImportModule("6486cd47b6f59329387b__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___helpers___batch_size");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "6486cd47b6f59329387b__mypyc.init_dank_mids___helpers___batch_size");
=======
    if (!(tmp = PyImport_ImportModule("e533ac94cbe235f69297__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_dank_mids___helpers___batch_size");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "e533ac94cbe235f69297__mypyc.init_dank_mids___helpers___batch_size");
>>>>>>> chore: extract _RequestEvent to its own module
>>>>>>> chore: extract _RequestEvent to its own module
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_batch_size(); }
