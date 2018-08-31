#include <stdio.h>
#include <time.h>

int main() {
	clock_t start,end;
	double cpu_time_used;
	start = clock();
	printf("Hello World");
	end = clock();
	cpu_time_used = ((double) (end-start));
	printf("%g",cpu_time_used);



}
