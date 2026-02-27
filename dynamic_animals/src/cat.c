#include "cat.h"

void cat_constructor(void* instance) {
  assert(instance);
  printf("i am Murka\n");

  struct CatObjectInstance* cat_instance = (struct CatObjectInstance*)instance;
  cat_instance->animal_base.name = "Murka";
  cat_instance->animal_base.sound = "Meow";
  cat_instance->claws_count = 1;
}

void cat_destructor(void* instance) {
  if (instance != NULL) {
    free(instance);
  }
}

void cat_make_voice(void* instance) {
  (void)instance;
  printf("Meow Meow\n");
}

void cat_scratch_action(void* instance) {
  (void)instance;
  printf("scratch.. scratch...\n");
}