#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char *str;
	str = (char *)malloc(15);
	strcpy (str, "samplestext");
	printf("String = %s , Address = %u\n", str, str);

	str = (char *) realloc(str,25);
	strcat(str,"xyz");
	printf("String = %s , Address = %u\n",str , str);

	free(str);

	return(0);

}

