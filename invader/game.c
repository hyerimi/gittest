#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#include "plane.h"
#include "bullet.h"
#include "alien.h"

struct timespec work_timer;
double acc_tick, last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gPlayerModel;
_S_MAP_OBJECT gBulletModel;
_S_MAP_OBJECT gAlienModel;

_S_Plane gPlayerObject;
_S_BULLET_OBJECT gBulletObjects[32];
_S_ALIEN_OBJECT gAlienObjects[6];

int main()
{

	for(int i=0; i<2; i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],40,24);
	}

	map_init(&gPlayerModel);
	map_load(&gPlayerModel,"plane1.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	double TablePosition[] = {0,5,10,15,20,25};

	for(int i=0; i<6; i++)
	{
		_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos = TablePosition[i];
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;
	} 
	Plane_init(&gPlayerObject,&gPlayerModel,20,20);	
	for(int i=0; i<sizeof(gBulletObjects)/sizeof(_S_BULLET_OBJECT); i++)
	{
		bullet_init(&gBulletObjects[i],0,0,0,&gBulletModel);
	}
	system("clear");

	set_conio_terminal_mode();
	acc_tick=last_tick=0;


	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간 입력	
	if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}
			else if(ch == 'j') {

				double vx, vy, c;	
				for(int i=0; i<8; i++)
				{
					_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
					pObj->m_fXpos = TablePosition[i];
					vx = gPlayerObject.m_fXpos - gAlienObjects[i].m_fXpos;
					vy = gPlayerObject.m_fYpos - gAlienObjects[i].m_fYpos;
					c = sqrt(vx*vx + vy*vy);
					vx /= c;
					vy /= c;
					for(int i=0; i<32; i++) {
						_S_BULLET_OBJECT *pObj = &gBulletObjects[i];
						if(pObj->m_nFSM == 0) {
							pObj->pfFire(&gBulletObjects[i],gAlienObjects[i].m_fXpos,gAlienObjects[i].m_fYpos,10.0,vx,vy,5.0);
						break;
						
						}

					}
				}				
			}	
			gPlayerObject.pfApply(&gPlayerObject,delta_tick,ch);
		}
		for(int i=0; i<6; i++) {
			_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
			pObj->pfApply(pObj,delta_tick);
		} 
		for(int i=0; i<sizeof(gBulletObjects)/sizeof(_S_BULLET_OBJECT);i++) {
			_S_BULLET_OBJECT *pObj = &gBulletObjects[i];
			gBulletObjects->pfApply(pObj,delta_tick); 
		} 

		//타이밍계산
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			//puts("tick...\r");
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			gPlayerObject.pfDraw(&gPlayerObject,&gScreenBuf[1]);

			for(int i=0; i<sizeof(gBulletObjects)/sizeof(_S_BULLET_OBJECT); i++) {
				_S_BULLET_OBJECT *pObj = &gBulletObjects[i];
				gBulletObjects->pfDraw(pObj,&gScreenBuf[1]);	
			} 
			for(int i=0; i<6; i++) {
				_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			} 
			map_dump(&gScreenBuf[1],Default_Tilepalette);
			acc_tick = 0;
		}
	}
	return 0;
}
