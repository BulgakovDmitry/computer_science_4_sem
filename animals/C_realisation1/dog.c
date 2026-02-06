#include <stdio.h>
#include "dog.h"
#include "stdlib.h"
#include "assert.h"

Dog* create_dog() {
    Dog* dog = calloc(1, sizeof(Dog));
    dog->name = "Bobik";
    dog->voice_sound = "Gaaav";
    return dog;
}

Dog* create_dog_with_name(const char* dog_name) {
    Dog* dog = calloc(1, sizeof(Dog));
    dog->name = dog_name;
    dog->voice_sound = "Gaaav";
    return dog;
}

void destroy_dog(Dog* dog) {
    if (!dog) return;
    if (dog->name) dog->name = NULL;
    if (dog->voice_sound) dog->voice_sound = NULL;
    free(dog);
}

void dog_voice(const Dog* dog) {
    assert(dog); 
    printf("dog %s: %s\n", dog->name, dog->voice_sound);
}




