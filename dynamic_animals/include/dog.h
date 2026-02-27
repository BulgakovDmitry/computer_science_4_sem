#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "animal.h"
#include <string.h>

struct DogObjectInstance {
  struct AnimalBaseFields animal_base;
  int teeth_count;
};

void dog_constructor(void* instance);
void dog_destructor(void* instance);
void dog_make_voice(void* instance);
void dog_bite_action(void* instance);