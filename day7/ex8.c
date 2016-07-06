#include <stdio.h>

int main () 
{
	int ary[5] = {10, 20, 30, 40, 50};
	void *vp = ary;
	void **vpp;

	printf("%d", *(ary+2));
	//printf("%d", *((int *)ary+2));
	//printf("%d",ary[2]);


	return 0;
}


//포인터변수 vp를 사용하여 세 번째 배열요소값 30 출력
