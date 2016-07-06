#include <stdio.h>

void str_prn(char **ptr_ary, int count)
{
	for(int i=0; i<count; i++) {
		printf("%s\n", ptr_ary[i]);
	}
}
/*int print_array(char **ary) {
		for(int i=0; i<4; i++) {
		puts(ary[i]);
	}	
}	*/


int main()
{
	char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};

	/*print_array(ptr_ary); */

	int count;

	count =sizeof(ptr_ary)/sizeof(ptr_ary[0]);
	str_prn(ptr_ary, count);

	return 0;
}
