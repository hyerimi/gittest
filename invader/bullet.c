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

#include "bullet.h"

void bullet_apply(_S_BULLET_OBJECT *pObj, double deltatick)
{
	switch(pObj->m_nFSM) {
		case 0:
		break;
		case 1:
		if(pObj->m_nStep == 0) {
			pObj->m_nStep++;
			pObj->m_faccLifrtime = 0;
		}
		else {
			pObj->m_faccLifrtime += deltatick; //수명처리
			if(pObj->m_faccLifrtime > pObj->m_fLifeLimit) {
				pObj->m_nStep = 0;
				pObj->m_nFSM = 0;
			}
			pObj->m_fYpos += deltatick * (pObj->m_fSpeed * pObj->m_fvy);
			pObj->m_fXpos += deltatick * (pObj->m_fSpeed * pObj->m_fvx);
		}
		break;
	}
}

void bullet_draw(_S_BULLET_OBJECT *pObj, _S_MAP_OBJECT *pMapbuf)
{
	switch(pObj->m_nFSM) {
	case 0:
	break;
	case 1:
	map_drawTile_trn(pObj->m_pBody,
		(int)(pObj->m_fXpos + pObj->m_fCenterX),
		(int)(pObj->m_fYpos + pObj->m_fCenterY),
		pMapbuf);
	break;
	}
}

void bullet_fire(_S_BULLET_OBJECT *pObj, int x, int y, double speed, double vx, double vy, double lifelimit )
{
	pObj->m_nFSM = 1;
	pObj->m_nStep = 0;
	pObj->m_fXpos = (double)x;
	pObj->m_fYpos = (double)y;
	pObj->m_fvx = vx;
	pObj->m_fvy = vy;
	pObj->m_fSpeed = speed;
	pObj->m_fLifeLimit = lifelimit;
}

void bullet_init(_S_BULLET_OBJECT *pObj, double x, double y, double speed,
 _S_MAP_OBJECT *pBody)
{
	pObj->m_nFSM = 0; //0: sleep, 1:active
	pObj->m_nStep = 0;
	pObj->m_fSpeed = speed;
	pObj->m_fXpos = x;
	pObj->m_fYpos = y;
	pObj->m_pBody = pBody;
	pObj->m_fCenterX = 0 - (pBody->m_header.m_nWidth/2);
	pObj->m_fCenterY = 0 - (pBody->m_header.m_nHeight/2);
	pObj->pfApply = bullet_apply;
	pObj->pfDraw = bullet_draw;
	pObj->pfFire = bullet_fire;
}

/*
double getDistance(_S_BULLET_OBJECT *pObj, _S_Plane *pPlane)
{
	
	double bullet_pos_x = pObj->m_fXpos;
	double bullet_pos_y = pObj->m_fYpos;

	double target_pos_x = pPlane.m_fXpos;
	double target_pos_y = pPlane.m_fYpos;

	double vx = target_pos_x - bullet_pos_x;
	double vy = target_pos_y - bullet_pos_y;
	double dist = sqrt(vx*vx + vy*vy);
	return dist;
}
void getDirection(_S_BULLET_OBJECT *pObj, _S_Plane *pPlane, double *_vx, double *_vy)
{

	double bullet_pos_x = pObj->m_fXpos;
	double bullet_pos_y = pObj->m_fYpos;

	double target_pos_x = pPlane.m_fXpos;
	double target_pos_y = pPlane.m_fYpos;

	double vx = target_pos_x - bullet_pos_x;
	double vy = target_pos_y - bullet_pos_y;
	double dist = sqrt(vx*vx + vy*vy);
	vx /= dist;
	vy /= dist;

	*_vx = vx;
	*_vy = vy;
} 
*/
