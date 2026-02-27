#pragma once

#include "method_list.h"

#include <stddef.h>

struct RuntimeClassDescriptor {
  struct RuntimeClassDescriptor* parent_class;
  const char* class_name;
  size_t instance_size_bytes;
  struct MethodDispatchTable dispatch_table;
};

struct RuntimeObjectInstance {
  struct RuntimeClassDescriptor* class_descriptor;
};

struct RuntimeClassDescriptor* runtime_class_create_descriptor(
    struct RuntimeClassDescriptor* parent_class,
    const char* class_name,
    size_t instance_size_bytes);

void runtime_class_add_method(
    struct RuntimeClassDescriptor* class_descriptor,
    const char* selector_name,
    MethodFunctionPointer function);

void runtime_class_destroy_descriptor(struct RuntimeClassDescriptor* class_descriptor);

struct RuntimeObjectInstance* runtime_object_create_instance(
    struct RuntimeClassDescriptor* class_descriptor);

void runtime_object_send_message(
    struct RuntimeObjectInstance* object_instance,
    struct RuntimeClassDescriptor* starting_class,
    const char* selector_name,
    void* argument);