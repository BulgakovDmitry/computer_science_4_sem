#ifndef INCLUDE_MY_PY_VAR
#define INCLUDE_MY_PY_VAR

#include "my_py_obj.h"

typedef struct My_py_var {
    My_py_obj* obj;
    char* name;
} My_py_var;

#endif // INCLUDE_MY_PY_VAR