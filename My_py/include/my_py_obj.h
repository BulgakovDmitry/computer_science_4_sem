#ifndef INCLUDE_MY_OY_OBJ_H
#define INCLUDE_MY_OY_OBJ_H

#include <stdlib.h>

typedef struct My_py_obj_type My_py_obj_type;

typedef struct My_py_obj {
    size_t ref_count;
    My_py_obj_type* obj_type;
} My_py_obj;


typedef struct My_py_obj_type  {
    char* name;
	size_t size;
	My_py_obj* (*alloc)(int size);
	void (*dealloc)();
} My_py_obj_type;

#endif //INCLUDE_MY_OY_OBJ_H