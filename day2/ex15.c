#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

int main()
{
	system("clear");

	int i;
	while(i<10) {
		gotoxy(0,i);
		printf("+");
		i++;
	}





	gotoxy(0,20);
	printf("=================================");
	return 0;
}
