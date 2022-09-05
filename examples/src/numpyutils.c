#include <Python.h>
#include <numpy/arrayobject.h>

PyObject* np_iter(PyObject* self, PyArrayObject* array) {
    if (array->nd > 1) {
        PyErr_SetString(PyExc_ValueError, "array must be 1-dimensional");
        return NULL;
    }
    if (array->descr->type_num != PyArray_DOUBLE) {
        PyErr_SetString(PyExc_ValueError, "array elements must of type(float)");
        return NULL;
    }

    double sum = 0;

    for (int i = 0; i < array->dimensions[0]; i++ ) {
        sum += *(double *)(array->data + i*array->strides[0]);
    }

    return PyFloat_FromDouble(sum);
}

static PyMethodDef NumpyUtilsMethodTable[] = {
    {"np_iter", (PyCFunction) np_iter, METH_O, NULL},
    {NULL, NULL, 0, NULL}
};

static char NumpyUtilsModuleDocs[] =
    "module for numpy demo";

static struct PyModuleDef NumpyUtils = {
    PyModuleDef_HEAD_INIT,
    "numpy_utils",
    NumpyUtilsModuleDocs,
    -1,
    NumpyUtilsMethodTable,
};

PyMODINIT_FUNC PyInit_numpy_utils() {
    return PyModule_Create(&NumpyUtils);
}

