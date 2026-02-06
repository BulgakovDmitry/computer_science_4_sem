#include "animals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void cat_voice(Animal *self) {
    printf("%s says: Meow!\n", self && self->name ? self->name : "(null)");
}

static void cat_destroy(Animal *self) {
    if (!self) return;
    free(self->name);
    self->name = NULL;

    self->v.voice = NULL;
    self->v.destroy = NULL;
}

static void dog_voice(Animal *self) {
    printf("%s says: Woof!\n", self && self->name ? self->name : "(null)");
}

static void dog_destroy(Animal *self) {
    if (!self) return;
    free(self->name);
    self->name = NULL;

    self->v.voice = NULL;
    self->v.destroy = NULL;
}

int cat_init(Cat *c, const char *name) {
    if (!c) return 0;
    c->base.v.voice = cat_voice;
    c->base.v.destroy = cat_destroy;

    c->base.name = strdup(name ? name : "");
    if (!c->base.name) {
        c->base.v.voice = NULL;
        c->base.v.destroy = NULL;
        return 0;
    }
    return 1;
}

int dog_init(Dog *d, const char *name) {
    if (!d) return 0;
    d->base.v.voice = dog_voice;
    d->base.v.destroy = dog_destroy;

    d->base.name = strdup(name ? name : "");
    if (!d->base.name) {
        d->base.v.voice = NULL;
        d->base.v.destroy = NULL;
        return 0;
    }
    return 1;
}

void cat_start_snoring(Cat *c) {
    const char *nm = (c && c->base.name) ? c->base.name : "(null)";
    printf("cat %s scratched!\n", nm);
}

void dog_bite(Dog *d) {
    const char *nm = (d && d->base.name) ? d->base.name : "(null)";
    printf("dog %s bites!\n", nm);
}
