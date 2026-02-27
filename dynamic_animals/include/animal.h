#pragma once

#include "class_obj.h"

struct AnimalBaseFields {
  struct RuntimeObjectInstance base_object;
  const char* name;
  const char* sound;
};