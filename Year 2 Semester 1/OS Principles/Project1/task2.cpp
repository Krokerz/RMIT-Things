#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <pthread.h>

std::string source;
std::string dest;
std::ifstream inStream;
std::ofstream outStream;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
bool inLoop = true;
bool outLoop = true;
std::queue<std::string> queue;

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
    inStream.open(source);
    
    int errNum = 0;

    for (int i = 0; i < numThreads; i++) {
        errNum = pthread_create(&readers.at(i), NULL, readSource, NULL);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_create reader #" << i << std::endl;
            return EXIT_FAILURE;
        }
    }

    numThreads--; // To account for main thread also executing

    std::vector<pthread_t> writers(numThreads);
    outStream.open(dest);

    for (int i = 0; i < numThreads; i++) {
        errNum = pthread_create(&writers.at(i), NULL, writeDest, NULL);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_create writer #" << i << std::endl;
            return EXIT_FAILURE;
        }
    }

    writeDest(NULL); // "return EXIT_SUCCESS" not called because writeDest has "pthread_exit(NULL)"
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
    std::string temp;
    int errNum = 0;

    while (inLoop) {
        errNum = pthread_mutex_lock(&lock);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_mutex_lock reader" << std::endl;
            inLoop = false;
        }
        else {
            if (inStream >> temp) {
                queue.push(temp);
            }
            else {
                inLoop = false;
            }

            errNum = pthread_mutex_unlock(&lock);

            if (errNum) {
                std::cout << "Error #" << errNum << " | From pthread_mutex_unlock reader" << std::endl;
                inLoop = false;
            }
        }
    }

    pthread_exit(NULL);
}

void* writeDest(void *arg) {
    int errNum = 0;

    while (outLoop) {
        errNum = pthread_mutex_lock(&lock);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_mutex_lock writer" << std::endl;
            outLoop = false;
        }
        else {
            if (!queue.empty()) {
                outStream << queue.front();
                queue.pop();
            }
            else if (!inLoop) {
                outLoop = false;
            }

            errNum = pthread_mutex_unlock(&lock);

            if (errNum) {
                std::cout << "Error #" << errNum << " | From pthread_mutex_unlock writer" << std::endl;
                outLoop = false;
            }
        }
    }

    pthread_exit(NULL);
}