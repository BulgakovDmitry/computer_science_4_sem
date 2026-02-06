#include <stdio.h>
#include "cat.h"
#include "stdlib.h"
#include "assert.h"

Cat* create_cat() {
    Cat* cat = calloc(1, sizeof(Cat));
    cat->name = "Murka";
    cat->voice_sound = "Meow";
    return cat;
}

Cat* create_cat_with_name(const char* cat_name) {
    Cat* cat = calloc(1, sizeof(Cat));
    cat->name = cat_name;
    cat->voice_sound = "Meow";
    return cat;
}

void destroy_cat(Cat* cat) {
    if (!cat) return;
    if (cat->name) cat->name = NULL;
    if (cat->voice_sound) cat->voice_sound = NULL;
    free(cat);
}

void cat_voice(const Cat* cat) {
    assert(cat); 
    printf("cat %s: %s\n", cat->name, cat->voice_sound);
}




