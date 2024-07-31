#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include <wait.h>

int value = 5;
                            
int main ( ) {
pid_t pid ;
/* fork a child process */
pid = fork ( ) ;
if (pid == 0) {                         	/* child */
value += 15;
return EXIT_SUCCESS;
} else if ( pid >0) {           		/* parent process */
wait (NULL) ;
printf ( "PARENT: value = %d\n" , value ) ;    	/* line A */
return EXIT_SUCCESS;
}
}
