#ifndef TASK2_H
#define TASK2_H

#include <string>
#include <queue>
#include <fstream>
#include <pthread.h>

#define MAX_QUEUE_SIZE 20

std::string source;
std::string dest;
std::ifstream inStream;
std::ofstream outStream;
pthread_mutex_t qLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t inLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t outLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t inCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t outCond = PTHREAD_COND_INITIALIZER;
bool inLoop = true;
bool outLoop = true;
bool full = false;
bool empty = false;
std::queue<std::string> queue;
unsigned int queueSize = 0;

void* readSource(void *arg);
void* writeDest(void *arg);

#endif