/* The purpose of this program is to understand the concept behind fork
 * -we are using a global variable and local variable 
 * -After fork the pid is incremented and the global and local variables as well */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int glob = 6; /* the global variable */
int main() {
	int var;
	pid_t pid; 

	var = 88;
	printf("Before Fork\n");

	if((pid = fork())<0){ /*pid is assigned the value of forked process */
		perror("fork"); /* handle the error */
	}
	else if (pid ==0){ /* if the process is forked */
			glob++;
			var++;
			printf("pid =%d, glob=%d,var=%d\n",getpid(),glob,var);
			exit(0);

	}
	else{
		printf ("pid = %d, glob=%d, var=%d\n", getpid (), glob, var);
		exit(0);
	}
}

