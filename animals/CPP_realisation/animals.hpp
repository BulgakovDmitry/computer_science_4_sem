#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
public:
    virtual ~Animal() = default;
    Animal(const std::string& name) : name(name) {}
    virtual void voice() const = 0; 
};

class Cat final : public Animal {    
public:
    Cat(const std::string& name) : Animal(name) {}
    void voice() const override {
        std::cout << name << " says: Meow!" << std::endl;
    }
    void start_snoring() const {
        std::cout << "cat " << name << " scratched!" << std::endl;
    }
};

class Dog final : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {} 
    void voice() const override {
        std::cout << name << " says: Woof!" << std::endl;
    }
    void bite() const {
        std::cout << "dog " << name << " bites!" << std::endl;
    }
};

#endif // ANIMALS_HPP