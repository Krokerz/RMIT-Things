#include "CreatureAge.h"

std::string CreatureAgeFunc(std::string species, int age) {
    int maxAge;
    std::string output;

    for (unsigned int i = 0; i < species.size(); i++) {
        species.at(i) = tolower(species.at(i));
    }

    if (species == "dwarf") {
        maxAge = DWARF;
    }
    else if (species == "elf") {
        maxAge = ELF;
    }
    else if (species == "goblin") {
        maxAge = GOBLIN;
    }
    else {
        output = "Creature unknown";
        return output;
    }

    if ((age < 0) || (age > maxAge)) {
        output = "This age cannot exist. Please retry.";
    }
    else if (age < (maxAge / 2.0)) {
        output = "For a " + species + ", this creature is young.";
    }
    else if ((maxAge % 2 == 0) && (age == (maxAge / 2))) {
        output = "This creature is perfectly middle-aged.";
    }
    else {
        output = "This creature is elderly and needs care.";
    }

    return output;
}