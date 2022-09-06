#include <Python.h>

PyObject* args_sum(PyObject* self, PyObject* args) {
    PyObject* iter = PyObject_GetIter(args);
    PyObject* item;

    long res_i = 0;
    double res_f = 0;

    while (item = PyIter_Next(iter)) {
        if (PyLong_Check(item)) {
            long val_i = PyLong_AsLong(item);
            res_i += val_i;
        }
        else if (PyFloat_Check(item)) {
            double val_f = PyFloat_AsDouble(item);
            res_f += val_f;
        }
        Py_DECREF(item);
    }
    Py_DECREF(iter);

    if (!res_f) {
        return PyLong_FromLong(res_i);
    }
    else {
        double result = res_f + res_i;
        return PyFloat_FromDouble(result);
    }
}

static PyMethodDef MethodTable[] = {
    {"args_sum", (PyCFunction) args_sum, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static char ArgsKwargsModuleDocs[] =
    "module for args and kwargs demo";

static struct PyModuleDef ArgsKwargs = {
    PyModuleDef_HEAD_INIT,
    "args_kwargs",
    ArgsKwargsModuleDocs,
    -1,
    MethodTable,
};

PyMODINIT_FUNC PyInit_args_kwargs() {
    return PyModule_Create(&ArgsKwargs);
}

