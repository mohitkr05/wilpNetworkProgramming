/* The purpose of this program is to 
 * a) demonstrate the use of external variable environ that is provided by the kernel to display all the environment variables
 * b) Iterate among the passed arguments one by one, provided in form or argument count and argument character
 */
#include <stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[]){
	int i;
	char **ptr;
	extern char **environ; /*The operating system also makes available to every running program an external global variable*/

        /* Iterate through the passed arguments , max limit is the argument count */
	for (i = 0 ; i < argc ; i++){
	printf ("argv[%d]:%s\n",i,argv[i]);
	}

	/* Print all the environment strings */

	for (ptr = environ; *ptr !=0 ; ptr++) { /* loop from starting memory location specified by the environment pointer and keep going till memory is specified */
		printf("%s\n",*ptr);
	}

	exit(0);


}
