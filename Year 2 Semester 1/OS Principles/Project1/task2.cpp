#include <iostream>
#include <vector>
#include <stdexcept>
#include "task2.h"

int main(int argc, char* *argv) {
    int numThreads = 0;

    try {
        if (argc < 4) {
            throw std::logic_error("Not enough arguments");
        }

        // Checking inputted num (argv[1])
        numThreads = std::stoi(argv[1]);

        if ((numThreads > 10) || (numThreads < 2)) {
            throw std::out_of_range("The first argument must be a digit between 2 - 10");
        }

        // Checking inputted source (argv[2])
        inStream.open(argv[2]);

        if (inStream.fail()) {
            throw std::runtime_error("Unable to open source file");
        }

        // Checking inputted dest (argv[3])
        outStream.open(argv[3]);

        if (outStream.fail()) {
            throw std::runtime_error("Unable to open destination file");
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    source = argv[2];
    dest = argv[3];

    std::vector<pthread_t> readers(numThreads);
    
    int errNum = 0;

    for (int i = 0; i < numThreads; i++) {
        errNum = pthread_create(&readers.at(i), NULL, readSource, NULL);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_create reader #" << i << std::endl;
            return EXIT_FAILURE;
        }
    }

    std::vector<pthread_t> writers(numThreads);

    for (int i = 0; i < numThreads; i++) {
        errNum = pthread_create(&writers.at(i), NULL, writeDest, NULL);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_create writer #" << i << std::endl;
            return EXIT_FAILURE;
        }
    }

    int errNum2 = 0;

    for (int i = 0; i < numThreads; i++) {
        errNum = pthread_join(readers.at(i), NULL);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_join reader #" << i << std::endl;
            return EXIT_FAILURE;
        }

        errNum2 = pthread_join(writers.at(i), NULL);

        if (errNum2) {
            std::cout << "Error #" << errNum << " | From pthread_join writer #" << i << std::endl;
            return EXIT_FAILURE;
        }
    }

    inStream.close();
    outStream.close();

    return EXIT_SUCCESS;
}


//  -- MULTIPLE LOCKS VERSION -- // DEPRECATED
// void* readSource(void *arg) {
//     std::string temp;
//     int errNum = 0;

//     while (inLoop) {
//         errNum = pthread_mutex_lock(&inLock);

//         if (errNum) {
//             std::cout << "Error #" << errNum << " | From pthread_mutex_lock reader" << std::endl;
//             inLoop = false;
//         }
//         else {
//             while (queueSize >= MAX_QUEUE_SIZE) {
//                 pthread_cond_wait(&inCond, &inLock);
//             }

//             if (getline(inStream, temp)) {
//                 pthread_mutex_lock(&qLock);

//                 queue.push(temp);
//                 queueSize++;

//                 pthread_mutex_unlock(&qLock);
//             }
//             else {
//                 inLoop = false;
//             }

//             pthread_cond_broadcast(&outCond);

//             errNum = pthread_mutex_unlock(&inLock);

//             if (errNum) {
//                 std::cout << "Error #" << errNum << " | From pthread_mutex_unlock reader" << std::endl;
//                 inLoop = false;
//             }
//         }
//     }
// }

// void* writeDest(void *arg) {
//     int errNum = 0;

//     while (outLoop) {
//         errNum = pthread_mutex_lock(&outLock);

//         if (errNum) {
//             std::cout << "Error #" << errNum << " | From pthread_mutex_lock writer" << std::endl;
//             outLoop = false;
//         }
//         else {
//             while (queue.empty() && inLoop) {
//                 pthread_cond_wait(&outCond, &outLock);
//             }

//             if (queue.empty() && !inLoop) {
//                 outLoop = false;
//             }
//             else {
//                 pthread_mutex_lock(&qLock);

//                 outStream << queue.front() << '\n';
//                 queue.pop();
//                 queueSize--;

//                 pthread_mutex_unlock(&qLock);
//             }

//             pthread_cond_broadcast(&inCond);

//             errNum = pthread_mutex_unlock(&outLock);

//             if (errNum) {
//                 std::cout << "Error #" << errNum << " | From pthread_mutex_unlock writer" << std::endl;
//                 outLoop = false;
//             }
//         }
//     }
// }

// -- SINGLE LOCK VERSION --
void* readSource(void *arg) {
    std::string temp;
    int errNum = 0;

    errNum = pthread_mutex_lock(&qLock);

    if (errNum) {
        std::cout << "Error #" << errNum << " | From pthread_mutex_lock reader" << std::endl;
        inLoop = false;
    }

    errNum = 1;

    while (inLoop) {
        if (errNum != 1) {
            errNum = pthread_mutex_lock(&qLock);

            if (errNum) {
                std::cout << "Error #" << errNum << " | From pthread_mutex_lock reader" << std::endl;
                inLoop = false;
            }
        }
        else {
            errNum = 0;
        }

        while (queueSize >= MAX_QUEUE_SIZE) {
            full = true;
            pthread_cond_wait(&outCond, &qLock);
        }

        if (getline(inStream, temp)) {
            queue.push(temp);
            queueSize++;
        }
        else {
            inLoop = false;
        }

        if (empty) {
            empty = false;
            pthread_cond_broadcast(&outCond);
        }

        errNum = pthread_mutex_unlock(&qLock);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_mutex_unlock reader" << std::endl;
            inLoop = false;
        }
    }

    return NULL;
}

void* writeDest(void *arg) {
    int errNum = 0;

    errNum = pthread_mutex_lock(&qLock);

    if (errNum) {
        std::cout << "Error #" << errNum << " | From pthread_mutex_lock writer" << std::endl;
        outLoop = false;
    }

    errNum = 1;

    while (outLoop) {
        if (errNum != 1) {
            errNum = pthread_mutex_lock(&qLock);

            if (errNum) {
                std::cout << "Error #" << errNum << " | From pthread_mutex_lock writer" << std::endl;
                outLoop = false;
            }
        }
        else {
            errNum = 0;
        }

        while (queue.empty() && inLoop) {
            empty = true;
            pthread_cond_wait(&outCond, &qLock);
        }

        if (queue.empty() && !inLoop) {
            outLoop = false;
        }
        else {
            outStream << queue.front() << '\n';
            queue.pop();
            queueSize--;

            if (full) {
                full = false;
                pthread_cond_broadcast(&outCond);
            }
        }

        errNum = pthread_mutex_unlock(&qLock);

        if (errNum) {
            std::cout << "Error #" << errNum << " | From pthread_mutex_unlock writer" << std::endl;
            outLoop = false;
        }
    }

    return NULL;
}