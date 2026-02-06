#include "cat.h"
#include "dog.h"

int main() {
    Cat* cat1 = create_cat_with_name("Marusia");
    Cat* cat2 = create_cat();

    cat_voice(cat1);
    cat_voice(cat2);

    Dog* dog1 = create_dog_with_name("Sharik");
    Dog* dog2 = create_dog();

    dog_voice(dog1);
    dog_voice(dog2);

    destroy_cat(cat1);
    destroy_cat(cat2);
    destroy_dog(dog1);
    destroy_dog(dog2);

    return 0;
}