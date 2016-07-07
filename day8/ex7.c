#include <stdio.h>


typedef struct {
	int m_nHp;
	char m_szName[128];
} _S_player;   //별명

/*
 c++용
class _S_Player {
};
*/


//typedef struct _S_PLAYER _S_player;

int main()
{
	_S_player player = {
		100,
		"player1",
	};
	
	puts(player.m_szName);

	return 0;
}
