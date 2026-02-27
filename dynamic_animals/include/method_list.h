#pragma once

#include <stdlib.h>
#include <stdarg.h>

typedef void (*MethodFunctionPointer)(void*);

struct SelectorFunctionPair {
  const char* selector_name;
  MethodFunctionPointer function;
};

struct MethodDispatchTable {
  size_t used_count;
  struct SelectorFunctionPair entries[10];
};