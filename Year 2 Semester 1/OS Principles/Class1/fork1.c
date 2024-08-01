#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
                            
int main() {
    pid_t pid;
    int value = 5;

    /* fork a child process */
    pid = fork();
    printf("PID: %d\n", pid);
    if (pid == 0) {                         	/* child */
        value += 15;
    }
    else if (pid > 0) {           		/* parent process */
        wait(NULL);
        printf("PARENT: value = %d\n", value);    	/* line A */
    }

    return EXIT_SUCCESS;
}
