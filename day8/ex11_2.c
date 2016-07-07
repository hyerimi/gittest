#include <stdio.h>

typedef struct {
	char m_szName[32];
	int m_nHp;
} _S_PLAYER;

int main() {
		
	_S_PLAYER player;
	
	FILE *pf = fopen("test.dat","rb");

	fread(&player,sizeof(_S_PLAYER),1,pf);   //번지,크기,갯수,포인터
	
	fclose(pf);
	
	puts(player.m_szName);

	return 0;
}
