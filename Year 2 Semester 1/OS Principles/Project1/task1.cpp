#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

unsigned int argNumChecker(char *argv);

int main(int argc, char** argv) {
    unsigned int numFiles = 0;

    try {
        numFiles = argNumChecker(argv[1]);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    

    return EXIT_SUCCESS;
}

unsigned int argNumChecker(char *arg) {
    std::cout << "strlen: " << strlen(arg) << std::endl;

    for (int i = 0; i < strlen(arg); i++) {
        if (!isdigit(arg[i])) {
            throw std::invalid_argument("The first argument must be a digit between 1 - 10");
        }    
    }

    unsigned int out = std::stoi(arg);

    if (out > 10) {
        throw std::invalid_argument("The first argument must be a digit between 1 - 10");
    }

    return out;
}