#include <sys/types.h>  /*used for derived types that should be used whenever appropriate, such as clock, sizes, offset, ppointer difference, size, time etc */
#include <unistd.h> /* provides access to the POSIX operating system API, such as fork,pipe,I/O */
#include <stdio.h>  /* standard i/o */
#include <stdlib.h> /* standard library */

/* Function to read from pipe , takes an integer file argument */

void read_from_pipe (int file)
{
	FILE *stream;
	int c;
	stream = fdopen (file , "r");
	while ((c = fgetc (stream)) != EOF)
		putchar (c);
	fclose(stream);
}

void write_to_pipe (int file)
{
	FILE *stream;
	stream = fdopen (file,"w");
	fprintf (stream, "hello, world!\n");
	fprintf (stream, "goodbye, world!\n");
	fclose (stream);
}

int main (void){
	pid_t pid;
	int mypipe[2];

	/* create the pipe */
	if (pipe (mypipe)){
		fprintf (stderr , "Pipe Failed\n");
		return EXIT_FAILURE;
	}
	pid = fork (); /*create child process */
	printf("%d",getpid());
	if (pid == (pid_t) 0) /* check if process id is 0 */
	{
		/* This is a child process, close other end first */
		close (mypipe[1]);
		read_from_pipe(mypipe[0]);
		return EXIT_SUCCESS;
	}
	else if (pid < (pid_t) 0){
		fprintf (stderr , "Fork Failed \n");
		return EXIT_FAILURE;
	}
	else {
		/* this is the parent process */
		close(mypipe[0]);
		write_to_pipe (mypipe[1]);
		return EXIT_SUCCESS;
	}
}

