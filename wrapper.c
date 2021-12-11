#include "Python.h"

float calc_bmi(float, float);

float calc_appropriate_weight(float);

static PyObject *check_calc_bmi(PyObject *self, PyObject *args) {
  float x, y, g;

  if (!PyArg_ParseTuple(args, "ff", &x, &y)) {
    return NULL;
  }
  g = calc_bmi(x, y);
  return Py_BuildValue("f", g);
}

static PyObject *check_calc_appropriate_weight(PyObject *self, PyObject *args) {
  float x, y;

  if (!PyArg_ParseTuple(args, "f", &x)) {
    return NULL;
  }

  y = calc_appropriate_weight(x);
  return Py_BuildValue("f", y);
}

static PyMethodDef medicalcheck[] = {
        {"calc_bmi",                check_calc_bmi,                METH_VARARGS},
        {"calc_appropriate_weight", check_calc_appropriate_weight, METH_VARARGS},
        {NULL,                      NULL,                          0, NULL},
};

static PyModuleDef medical_check_module = {
        PyModuleDef_HEAD_INIT,
        "medicalcheck",
        NULL,
        -1,
        medicalcheck,
};

PyMODINIT_FUNC PyInit_medicalcheck(void) {
  return PyModule_Create(&medical_check_module);
}