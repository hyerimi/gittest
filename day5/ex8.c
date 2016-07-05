#include <stdio.h>

int main()
{
	int num[] = {3,6,4,5,7};
	int *pNum = num;
	int max = -9999999;
	int min = 99999999; 

	printf("%d , %d \r\n",*(pNum+1),num[1]);
	
	int sum = 0;
		
	for(int i=0; i<sizeof(num)/sizeof(int); i++)
		{
			printf("%d, \r\n",*(pNum+i));
			sum += *(pNum +i);
	
		if(max < *(pNum+i)) {
			max = *(pNum+i);
		}

		if(min > *(pNum +i)) {
			min = *(pNum +i);
		}
	}
	
	printf("합계 : %d \r\n",sum);
	printf("최대값 : %d \r\n",max);
	printf("최소값 : %d \r\n",min);

	return 0;
}
