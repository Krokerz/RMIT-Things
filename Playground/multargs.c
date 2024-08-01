#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("no args given");
    }
    else if (strcmp(argv[1], "hello") == 0) {
        printf("hi");
    }
    else if (strcmp(argv[1], "hi") == 0) {
        printf("hello");
    }
    else if (strcmp(argv[1], "num") == 0) {
        printf("num of args: %d", argc);
    }
    else {
        printf("somethin else");
    }
}