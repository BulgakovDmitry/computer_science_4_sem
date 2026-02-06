#ifndef DOG_H
#define DOG_H

typedef struct Dog {
    const char* name;
    const char* voice_sound;
}Dog;

Dog* create_dog();
Dog* create_dog_with_name(const char* dog_name);
void destroy_dog(Dog* dog);
void dog_voice(const Dog* dog);

#endif // DOG_H