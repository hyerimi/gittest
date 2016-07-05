#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//add 10,20
	//sub 5,2
	//mul 4,3
	//div 8,2
	
	char strCmd[128];

	printf("원하는 연산 add,sub,mul,div을 입력하세요. ex)add 10,20 \r\n");

	gets(strCmd);
	//scanf("%s",strCmd);
	char *ptrTemp;
	char *pCmd;
	int a,b;	
	
	ptrTemp = strtok(strCmd," ");
	
	pCmd = strdup(ptrTemp);

	a = atoi( strtok(NULL,",") );
	b = atoi( strtok(NULL,",") );

	if(strcmp(pCmd,"add") == 0) {
		printf("덧셈결과 = %d \r\n",a+b);
	}

	else if(strcmp(pCmd,"sub") == 0) {
		printf("뺄셈결과 = %d \r\n",a-b);
	}
	else if(strcmp(pCmd,"mul") == 0) {
		printf("곱셈결과 = %d \r\n",a*b);
	}
	else if(strcmp(pCmd,"div") == 0) {
		printf("나눗셈결과 = %d \r\n",a/b);
	}
	return 0;
}
