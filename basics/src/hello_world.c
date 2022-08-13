#include <Python.h>

void hello_world() {
    puts("Hello World!");
    Py_RETURN_NONE;
}

static char HelloWorldFunctionDocs[] =
    "prints 'Hello World!' to the screen, from C.";

static PyModuleDef MethodTable[] = {
    {"hello_world", (PyCFunction) hello_world, METH_NOARGS, HelloWorldFunctionDocs},
    {NULL,NULL,0,NULL}
};

static char HelloWorldModuleDocs[] =
    "module documentation for 'Hello World'";

static struct PyModuleDef HelloWorld = {
    PyModuleDef_HEAD_INIT,
    "hello_world",
    HelloWorldModuleDocs,
    -1,
    MethodTable
};

// PyInit_<name>
PyMODINIT_FUNC PyInit_hello_world() {
    return PyModule_Create(&HelloWorld);
}
