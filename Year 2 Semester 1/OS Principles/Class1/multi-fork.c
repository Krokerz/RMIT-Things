// How many processes are created?? 2^n so 2^3 = 8

#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("%d*\n",getpid());
	fork();

	printf("%d**\n",getpid());
	fork();

	printf("%d***\n",getpid());
	fork();
	
	printf("%d****\n",getpid());

	// output is unorderly... speed reasons maybe?

	return 0;
}
