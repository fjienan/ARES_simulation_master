// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ares_comm:srv/Execute.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ares_comm/srv/detail/execute__struct.h"
#include "ares_comm/srv/detail/execute__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ares_comm__srv__execute__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ares_comm.srv._execute.Execute_Request", full_classname_dest, 38) == 0);
  }
  ares_comm__srv__Execute_Request * ros_message = _ros_message;
  {  // func_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "func_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->func_id = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // arg1
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->arg1 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // arg2
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->arg2 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // arg3
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg3");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->arg3 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // request_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "request_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->request_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ares_comm__srv__execute__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Execute_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ares_comm.srv._execute");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Execute_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ares_comm__srv__Execute_Request * ros_message = (ares_comm__srv__Execute_Request *)raw_ros_message;
  {  // func_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->func_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "func_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->arg1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->arg2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg3
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->arg3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // request_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->request_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "request_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "ares_comm/srv/detail/execute__struct.h"
// already included above
// #include "ares_comm/srv/detail/execute__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ares_comm__srv__execute__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ares_comm.srv._execute.Execute_Response", full_classname_dest, 39) == 0);
  }
  ares_comm__srv__Execute_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // value
    PyObject * field = PyObject_GetAttrString(_pymsg, "value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->value = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ares_comm__srv__execute__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Execute_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ares_comm.srv._execute");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Execute_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ares_comm__srv__Execute_Response * ros_message = (ares_comm__srv__Execute_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // value
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
