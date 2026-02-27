#ifndef INCLUDE_MY_PY_INT_OBJ
#define INCLUDE_MY_PY_INT_OBJ

#include "my_py_var.h"

typedef struct My_py_int_obj  {
    My_py_var obj;
	int value;
} My_py_int_obj;

#endif //INCLUDE_MY_PY_INT_OBJ