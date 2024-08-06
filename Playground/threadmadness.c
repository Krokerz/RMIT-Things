#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int num = 1;
uint64_t parentid = 0;

// void sup1(int *num) {
//     printf("i am thread #%d\n", *num);
//     (*num)++;
// }

void* sup2(void *arg) {
    uint64_t temp;
    pthread_threadid_np(NULL, &temp);

    for (int i = 0; i < 2; i++) {
        printf("i am thread #%llu\n", temp);
        printf("diff: %llu\n", temp - parentid);
        num++;
    }

    if (!(temp - parentid)) {
        printf("num: %d\n", num); //fucking threads being concurrent smh, givin wrong outputs
    }

    pthread_exit(0);

    return NULL;
}

int main() {
    pthread_t thread;
    pthread_threadid_np(NULL, &parentid);

    pthread_create(&thread, NULL, sup2, NULL);
    pthread_create(&thread, NULL, sup2, NULL);
    pthread_create(&thread, NULL, sup2, NULL);
    sup2(NULL);

    // printf("%d", num);

    return 0;
}