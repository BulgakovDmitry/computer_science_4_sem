#include <stdio.h>

#include "dog.h"
#include "cat.h"

int main(void) {
  struct RuntimeClassDescriptor* class_Object =
      runtime_class_create_descriptor(NULL, "Object", sizeof(struct RuntimeObjectInstance));

  struct RuntimeClassDescriptor* class_Animal =
      runtime_class_create_descriptor(class_Object, "Animal", sizeof(struct AnimalBaseFields));

  struct RuntimeClassDescriptor* class_Dog =
      runtime_class_create_descriptor(class_Animal, "Dog", sizeof(struct DogObjectInstance));

  runtime_class_add_method(class_Dog, "ctor", dog_constructor);
  runtime_class_add_method(class_Dog, "dtor", dog_destructor);
  runtime_class_add_method(class_Dog, "voice", dog_make_voice);
  runtime_class_add_method(class_Dog, "bite", dog_bite_action);

  struct RuntimeClassDescriptor* class_Cat =
      runtime_class_create_descriptor(class_Animal, "Cat", sizeof(struct CatObjectInstance));

  runtime_class_add_method(class_Cat, "ctor", cat_constructor);
  runtime_class_add_method(class_Cat, "dtor", cat_destructor);
  runtime_class_add_method(class_Cat, "voice", cat_make_voice);
  runtime_class_add_method(class_Cat, "scratch", cat_scratch_action);

  struct RuntimeObjectInstance* dog_instance = runtime_object_create_instance(class_Dog);
  struct RuntimeObjectInstance* cat_instance = runtime_object_create_instance(class_Cat);

  runtime_object_send_message(dog_instance, dog_instance->class_descriptor, "ctor", dog_instance);
  runtime_object_send_message(cat_instance, cat_instance->class_descriptor, "ctor", cat_instance);

  runtime_object_send_message(dog_instance, dog_instance->class_descriptor, "voice", NULL);
  runtime_object_send_message(cat_instance, cat_instance->class_descriptor, "voice", NULL);

  runtime_object_send_message(dog_instance, dog_instance->class_descriptor, "bite", NULL);
  runtime_object_send_message(cat_instance, cat_instance->class_descriptor, "scratch", NULL);

  runtime_object_send_message(dog_instance, dog_instance->class_descriptor, "dtor", dog_instance);
  runtime_object_send_message(cat_instance, cat_instance->class_descriptor, "dtor", cat_instance);

  runtime_class_destroy_descriptor(class_Dog);
  runtime_class_destroy_descriptor(class_Cat);
  runtime_class_destroy_descriptor(class_Animal);
  runtime_class_destroy_descriptor(class_Object);

  return 0;
}