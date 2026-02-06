#include "animals.hpp"

int main() {
    Cat cat("Murka");
    Dog dog("Bobic");
    
    cat.voice();
    dog.voice();

    dog.bite();
    cat.start_snoring();
    
    return 0;
}