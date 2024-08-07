#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <pthread.h>

std::string source = "";
std::string dest = "";
std::queue<std::string> queue = {};

int argNumChecker(char *arg);
void* readSource(void *arg);
void* writeDest(void *arg);

int main(int argc, char** argv) {
    int numThreads = 0;

    try {
        numThreads = argNumChecker(argv[1]);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    source = argv[2];
    dest = argv[3];

    std::vector<pthread_t> readers(numThreads);
    std::ifstream inputStream(source);

    for (int i = 0; i < numThreads; i++) {
        pthread_create(&readers.at(i), NULL, readSource, &inputStream);
    }

    numThreads--;

    std::vector<pthread_t> writers(numThreads);
    std::ofstream outputStream(dest);

    for (int i = 0; i < numThreads; i++) {
        pthread_create(&writers.at(i), NULL, writeDest, &outputStream);
    }

    writeDest(NULL);

    return EXIT_SUCCESS;
}

int argNumChecker(char *arg) {
    // std::cout << "strlen: " << strlen(arg) << std::endl;

    for (int i = 0; i < strlen(arg); i++) {
        if (!isdigit(arg[i])) {
            throw std::invalid_argument("The first argument must be a digit between 2 - 10");
        }   
    }

    int out = std::stoi(arg);

    if ((out > 10) || (out < 2)) {
        throw std::invalid_argument("The first argument must be a digit between 2 - 10");
    }

    return out;
}

void* readSource(void *arg) {
    std::ifstream stream = 
    while () {

    }

    pthread_exit(EXIT_SUCCESS);
}

void* writeDest(void *arg) {

    while () {

    }

    pthread_exit(EXIT_SUCCESS);
}