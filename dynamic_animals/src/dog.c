#include "dog.h"

void dog_constructor(void* instance) {
  assert(instance);
  printf("i am Bobik\n");
  ((struct DogObjectInstance*)instance)->animal_base.name  = "Bobik";
  ((struct DogObjectInstance*)instance)->animal_base.sound = "Gaw";
  ((struct DogObjectInstance*)instance)->teeth_count = 2;
}

void dog_destructor(void* instance) {
  if (instance != NULL) {
    free(instance);
  }
}

void dog_make_voice(void* instance) {
  (void)instance;
  printf("Gaw Gaw\n");
}

void dog_bite_action(void* instance) {
  (void)instance;
  printf("bites\n");
}