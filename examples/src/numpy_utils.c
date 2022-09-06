#include <string.h>

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

PyObject* np_create(PyObject* self, PyObject* args) {

    Py_ssize_t length = PyTuple_Size(args);
    npy_intp dimensions[1] = {length};

    PyArrayObject* array = (PyArrayObject*) PyArray_SimpleNew(1, dimensions, NPY_LONG);

    PyObject* iter = PyObject_GetIter(args);
    PyObject* item;
    double _item;

    long i = 0;
    long *arr = (long*) array->data;
    while (item = PyIter_Next(iter)) {
        _item = PyLong_AsLong(item);
        arr[i] = _item;
        Py_DECREF(item);
        i += 1;
    }
    Py_DECREF(iter);
    return PyArray_Return(array);
}

static PyMethodDef NumpyUtilsMethodTable[] = {
    {"np_iter", (PyCFunction) np_iter, METH_O, NULL},
    {"np_create", (PyCFunction) np_create, METH_VARARGS, NULL},
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
    import_array();
    return PyModule_Create(&NumpyUtils);
}

