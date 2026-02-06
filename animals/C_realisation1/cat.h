#ifndef CAT_H
#define CAT_H 

typedef struct Cat {
    const char* name;
    const char* voice_sound;
}Cat;

Cat* create_cat();
Cat* create_cat_with_name(const char* cat_name);
void destroy_cat(Cat* cat);
void cat_voice(const Cat* cat);

#endif // CAT_H
