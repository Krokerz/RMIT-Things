#include <iostream>
#include <string>
#include "CreatureAge.h"

int main() {
    int age;
    std::string species;

    std::cout << "Please enter the species: ";
    std::cin >> species;
    std::cout << std::endl;

    std::cout << "Please enter the age: ";
    std::cin >> age;
    std::cout << std::endl;

    std::cout << CreatureAgeFunc(species, age) << std::endl;

    return EXIT_SUCCESS;
}

