#include <stdio.h>
#include <string.h>

struct _S_PLAYER {
	char m_szName[128];
	int m_nHp;
};

int main()
{
	
	struct _S_PLAYER player[] = {
		{"john snow",300},
		{"sansa stak",200},
		{"seosai ranerster",250}
	};
	
	for(int i=0; i<3; i++) {
		printf("name : %s, hp : %d \r\n",player[i].m_szName,player[i].m_nHp);
		}

	return 0;
}
