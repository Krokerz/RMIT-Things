#include <iostream>
#include <vector>
#include <stdexcept>
#include <filesystem>
#include <pthread.h>
#include "task1.h"

int main(int argc, char* *argv) {
    int numFiles = 0;

    try {
        if (argc < 4) {
            throw std::logic_error("Not enough arguments");
        }

        // Checking inputted num (argv[1])
        numFiles = std::stoi(argv[1]);

        if ((numFiles > 10) || (numFiles < 1)) {
            throw std::out_of_range("The first argument must be a digit between 1 - 10");
        }

        // Checking inputted source (argv[2])
        if (!std::filesystem::is_directory(std::filesystem::status(argv[2]))) {
            throw std::logic_error("The source is not a directory");
        }

        // Checking inputted dest (argv[3])
        if (!std::filesystem::is_directory(std::filesystem::status(argv[3]))) {
            throw std::logic_error("The destination is not a directory");
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    source = argv[2];
    dest = argv[3];

    std::vector<int> nums;

    for (int i = 1; i <= numFiles; i++) {
        nums.push_back(i);
    }

    numFiles--; // To account for main thread also executing fileCopier

    std::vector<pthread_t> threads(numFiles);

    // pthread_attr_t threadAttr;
    // pthread_attr_init(threadAttr);

    int errNum = 0;

    for (int i = 0; i < numFiles; i++) {
        errNum = pthread_create(&threads.at(i), NULL, fileCopier, &nums.at(i));

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_create #" << i << std::endl;
            return EXIT_FAILURE;
        }
    }

    fileCopier(&nums.at(numFiles)); // "return EXIT_SUCCESS" not called because fileCopier has "pthread_exit(NULL)"
}

void* fileCopier (void* arg) {
    std::string query = "cp ";
    query += source + "/source";
    query += std::to_string(*static_cast<int*>(arg));
    query += ".txt " + dest;

    system(query.c_str());

    pthread_exit(NULL);
}