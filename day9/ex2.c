#include <stdio.h>
#include "ex2_2.h"
//void foo();

extern int nCount;

int main()
{
	nCount = 10;
	foo();
	foo();

	return 0;
}
