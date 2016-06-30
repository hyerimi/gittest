
#include <stdio.h>

int main ()
{
	printf("hello vt100\r\n");
	printf("\x1b[31m");
	printf("hello vt100\r\n");
	printf("\x1b[1;31m");
	printf("hello vt100\r\n");
	printf("\x1b[0;33m");
	printf("hello vt100\r\n");
	printf("\x1b[32m");
	printf("hello vt100\r\n");
	printf("\x1b[34m");
	printf("hello vt100\r\n");
	printf("\x1b[2;34m");
	printf("hello vt100\r\n");
	printf("\x1b[0;35m");
	printf("hello vt100\r\n");


	return 0;

}	
