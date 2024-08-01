#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

int value = 0;						/* Global */

void* runner ( void* param) {
    value = 5;
    pthread_exit ( 0 ) ;
}

int main() {
    int pid ;						/* Locals to main() */
    pthread_t tid ;
    pthread_attr_t attr ;

    pid = fork() ;
    if ( pid == 0 ) {				 	/* Child process */
        pthread_attr_init( &attr );			/* attr = Thread Attributes */
        pthread_create( &tid , &attr , runner , NULL );	/* (tid,attr) = runner() */
        pthread_join (tid , NULL) ;			/* Wait indefinitely for tid to finish */
        printf("CHILD: v = %d\n", value ); 		/**** LINE C ****/
    } else if (pid >0) {				/* PARENT, pid = Child pid */
        wait (NULL) ;					/*  Wait for child process to die */
        printf("PARENT: v = %d\n", value ) ; 		/*** LINE P ***/
    }
    return EXIT_SUCCESS;
}

