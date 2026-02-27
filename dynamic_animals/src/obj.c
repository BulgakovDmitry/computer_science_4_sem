#include "class_obj.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void dispatch_table_init(struct MethodDispatchTable* table) {
  assert(table);
  table->used_count = 0;
  for (size_t i = 0; i < 10; ++i) {
    table->entries[i].selector_name = NULL;
    table->entries[i].function = NULL;
  }
}

struct RuntimeClassDescriptor* runtime_class_create_descriptor(
    struct RuntimeClassDescriptor* parent_class,
    const char* class_name,
    size_t instance_size_bytes) {
  struct RuntimeClassDescriptor* new_class =
      (struct RuntimeClassDescriptor*)malloc(sizeof(struct RuntimeClassDescriptor));
  if (!new_class) {
    return NULL;
  }

  new_class->class_name = class_name;
  new_class->parent_class = parent_class;
  new_class->instance_size_bytes = instance_size_bytes;
  dispatch_table_init(&new_class->dispatch_table);

  return new_class;
}

void runtime_class_add_method(
    struct RuntimeClassDescriptor* class_descriptor,
    const char* selector_name,
    MethodFunctionPointer function) {
  assert(class_descriptor);
  assert(selector_name);
  assert(function);

  if (class_descriptor->dispatch_table.used_count >= 10) {
    fprintf(stderr, "Method table overflow for class '%s'\n",
            class_descriptor->class_name ? class_descriptor->class_name : "<unnamed>");
    abort();
  }

  const size_t idx = class_descriptor->dispatch_table.used_count;
  class_descriptor->dispatch_table.entries[idx].selector_name = selector_name;
  class_descriptor->dispatch_table.entries[idx].function = function;
  class_descriptor->dispatch_table.used_count++;
}

struct RuntimeObjectInstance* runtime_object_create_instance(
    struct RuntimeClassDescriptor* class_descriptor) {
  assert(class_descriptor);

  struct RuntimeObjectInstance* object_instance =
      (struct RuntimeObjectInstance*)malloc(class_descriptor->instance_size_bytes);
  if (!object_instance) {
    return NULL;
  }

  object_instance->class_descriptor = class_descriptor;
  return object_instance;
}

void runtime_class_destroy_descriptor(struct RuntimeClassDescriptor* class_descriptor) {
  free(class_descriptor);
}

void runtime_object_send_message(
    struct RuntimeObjectInstance* object_instance,
    struct RuntimeClassDescriptor* starting_class,
    const char* selector_name,
    void* argument) {
  (void)object_instance; 

  assert(starting_class);
  assert(selector_name);

  const size_t count = starting_class->dispatch_table.used_count;
  for (size_t i = 0; i < count; ++i) {
    const char* sel = starting_class->dispatch_table.entries[i].selector_name;
    if (sel && strcmp(selector_name, sel) == 0) {
      starting_class->dispatch_table.entries[i].function(argument);
      return;
    }
  }

  if (starting_class->parent_class) {
    runtime_object_send_message(NULL, starting_class->parent_class, selector_name, argument);
    return;
  }

  fprintf(stderr, "Selector '%s' was not found (starting from class '%s')\n",
          selector_name,
          starting_class->class_name ? starting_class->class_name : "<unnamed>");
}