#include <stdio.h>
#include <stdlib.h>

#include "../mapEditor/map.h"

void map_drawTile_trn(_S_MAP_OBJECT *pObj, int posx, int posy, _S_MAP_OBJECT *pTarget)
{
	for(int iy=0; iy < pObj->m_header.m_nHeight; iy++) {
		for(int ix=0; ix < pObj->m_header.m_nWidth; ix++) {
			if(pObj->m_pBuf[iy*pObj->m_header.m_nWidth +ix] != 0) {
			map_PutTile(pTarget,-ix + posx, iy + posy,
					pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
			}
		}
	}
}

int main()
{
	_S_MAP_OBJECT screenBuf;
	map_init(&screenBuf);
	map_new(&screenBuf,16,16);

	_S_MAP_OBJECT humanObj;
	map_init(&humanObj);
	map_load(&humanObj,"human.dat");
	puts("\r\n---------------------------");

	map_drawTile_trn(&humanObj,5,5,&screenBuf);

	map_dump(&screenBuf,Default_Tilepalette);


	return 0;
}
