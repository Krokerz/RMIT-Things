#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <pthread.h>

std::string source = "";
std::string dest = "";

int argNumChecker(char *argv);
void* fileCopier(void *arg);

int main(int argc, char** argv) {
    int numFiles = 0;

    try {
        numFiles = argNumChecker(argv[1]);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    source = argv[2];
    dest = argv[3];

    std::vector<int> nums = {};

    for (int i = 1; i <= numFiles; i++) {
        nums.push_back(i);
    }

    numFiles--; // To account for "fileCopier(&nums.at(numFiles));" after for loop

    std::vector<pthread_t> threads(numFiles);

    // pthread_attr_t threadAttr;
    // pthread_attr_init(threadAttr);

    for (int i = 0; i < numFiles; i++) {
        pthread_create(&threads.at(i), NULL, fileCopier, &nums.at(i));
    }

    fileCopier(&nums.at(numFiles));

    return EXIT_SUCCESS;
}

int argNumChecker(char *arg) {
    // std::cout << "strlen: " << strlen(arg) << std::endl;

    for (int i = 0; i < strlen(arg); i++) {
        if (!isdigit(arg[i])) {
            throw std::invalid_argument("The first argument must be a digit between 1 - 10");
        }   
    }

    int out = std::stoi(arg);

    if ((out > 10) || (out < 1)) {
        throw std::invalid_argument("The first argument must be a digit between 1 - 10");
    }

    return out;
}

void* fileCopier (void* arg) {
    std::string query = "cp ";
    query += source + "/source";
    query += std::to_string(*(int*)arg);
    query += ".txt " + dest;
 
    // std::cout << query << std::endl;

    system(query.c_str());

    pthread_exit(EXIT_SUCCESS);
}