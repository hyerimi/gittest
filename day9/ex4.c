#include <stdio.h>


int main()
{	
	int test = 0x00000001; //0001, 0010, 0100, 1000
	test = test << 1;
	printf("%x \r\n",test);
	test = test << 1;
	printf("%x \r\n",test);
	test = test << 1;
	printf("%x \r\n",test);
	test = test << 1;
	printf("%x \r\n",test);


	return 0;
}
