#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#include "tank.h"

void Tank_Draw(_S_TANK *pObj, _S_MAP_OBJECT *pBuff) 
{
	map_drawTile_trn(pObj->m_pBody, pObj->m_nXpos,pObj->m_nYpos,pBuff);
}

void Tank_init(_S_TANK *pObj, _S_MAP_OBJECT *pBody, int x, int y)
{
	pObj->m_pBody = pBody;
	pObj->m_nYpos = y;
	pObj->m_nXpos = x;
	
	//pObj->fpApply = Tank_Apply;
	pObj->fpDraw = Tank_Draw;
}

void Tank_Apply(_S_TANK *pObj, _S_MAP_OBJECT *pBuff)
{
	int width = pBuff->m_header.m_nWidth;
	if(pObj->m_nXpos < width-3)
		pObj->m_nXpos++;

	
	/*
	switch(pObj->nFSM_1) {
		case 0:
			if(pObj->m_nXpos <= width-3){
				pObj->m_nXpos++;
			}	
			else if(pObj->m_nXpos > width-3) 
			{
				pObj->nFSM_1 = 1;
			}
		case 1:
			if(pObj->m_nXpos >= -2) {
				pObj->m_nXpos --;
			}
			else if(pObj->m_nXpos < -2)
			{	
				pObj->nFSM_1 = 0;
			}	
		
	}
	*/
}


