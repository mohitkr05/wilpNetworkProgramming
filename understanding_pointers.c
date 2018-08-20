#include <stdio.h>
#include <stdlib.h>

int main(){

	int a = 30 ;
	int *p;
	int **pp;
	p = &a;
	pp = &p;
	printf("Address of a = %u\n",&a);
	printf("What is p = %u\n",p);
	printf("Value at p = %u\n",*p);
	printf("What is value of pp = %u\n",pp);
	printf("Value at pp = %u\n",*pp);
	printf("value at value of *pp = %u\n",**pp);
	
	return (0);
}
