#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "animal.h"

struct CatObjectInstance {
  struct AnimalBaseFields animal_base;
  int claws_count;
};

void cat_constructor(void* instance);
void cat_destructor(void* instance);
void cat_make_voice(void* instance);
void cat_scratch_action(void* instance);