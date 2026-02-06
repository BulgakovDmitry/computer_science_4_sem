#ifndef ANIMALS_H
#define ANIMALS_H

#include <stddef.h>

typedef struct Animal Animal;

typedef struct AnimalVTable {
    void (*voice)(Animal *self);
    void (*destroy)(Animal *self); 
} AnimalVTable;

struct Animal {
    AnimalVTable v; 
    char *name;
};

typedef struct Cat {
    Animal base;
} Cat;

typedef struct Dog {
    Animal base;
} Dog;

int cat_init(Cat *c, const char *name);
int dog_init(Dog *d, const char *name);

void cat_start_snoring(Cat *c);
void dog_bite(Dog *d);

#endif
