#include "animals.h"
#include <stdio.h>

int main(void) {
    Cat cat;
    Dog dog;

    if (!cat_init(&cat, "Murka")) {
        puts("cat_init failed");
        return 1;
    }
    if (!dog_init(&dog, "Bobic")) {
        puts("dog_init failed");
        ((Animal*)&cat)->v.destroy((Animal*)&cat);
        return 1;
    }

    Animal *a = (Animal*)&cat;
    Animal *b = (Animal*)&dog;

    a->v.voice(a);
    b->v.voice(b);

    dog_bite(&dog);
    cat_start_snoring(&cat);

    b->v.destroy(b);
    a->v.destroy(a);

    return 0;
}
