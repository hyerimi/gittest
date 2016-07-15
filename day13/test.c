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
#include "tank.h"
#include "testBul.h"

struct timespec work_timer;
double acc_tick, last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];
_S_MAP_OBJECT gPlayer;
_S_MAP_OBJECT gTank;

_S_Plane gPlayerObject;
_S_TANK gTankObject;

_S_MAP_OBJECT gBulletModel;
_S_BULLET_OBJECT gBulletObject[32];

int main()
{
	
	for(int i=0; i<2; i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],45,20);
	}
	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet.dat");

	map_init(&gTank);
	map_load(&gTank,"tank.dat");

	Tank_init(&gTankObject,&gTank,9,2);

	map_init(&gPlayer);
	map_load(&gPlayer,"plane1.dat");

	Plane_init(&gPlayerObject,&gPlayer,19,14);
	
	for(int i=0; i<sizeof(gBulletObject)/sizeof(_S_BULLET_OBJECT); i++)
	{
		bullet_init(&gBulletObject[i],0,0,0,&gBulletModel);
	}
		
	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	
	system("clear");


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
				double vx,vy,c;
				vx = gPlayerObject.m_nXpos - gTankObject.m_nXpos;
				vy = gPlayerObject.m_nYpos - gTankObject.m_nYpos;
				c = sqrt(vx*vx + vy*vy);
				vx /= c;
				vy /= c;
				for(int i=0; i<sizeof(gBulletObject)/sizeof(_S_BULLET_OBJECT); i++){
					_S_BULLET_OBJECT *pObj = &gBulletObject[i];
					if(pObj->m_nFSM == 0) {
						bullet_fire(pObj,(gTankObject.m_nXpos)+2,(gTankObject.m_nYpos)+4,10,vx,vy,5.0);
						break;
						
					}
				}

			}
			//Plane_Apply(&gPlayerObject,delta_tick,ch);

			gPlayerObject.fpApply(&gPlayerObject,delta_tick,ch);
	
		}
		for(int i=0; i<sizeof(gBulletObject)/sizeof(_S_BULLET_OBJECT); i++){
			_S_BULLET_OBJECT *pObj = &gBulletObject[i];
			bullet_apply(pObj,delta_tick);
		}

	
		//타이밍계산
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			//puts("tick...\r");
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);

			gTankObject.fpDraw(&gTankObject,&gScreenBuf[1]);
			gPlayerObject.fpDraw(&gPlayerObject,&gScreenBuf[1]);
					//Plane_Draw(&gPlayerObject,&gScreenBuf[1]);
			Tank_Apply(&gTankObject, &gScreenBuf[1]);
			for(int i=0; i<sizeof(gBulletObject)/sizeof(_S_BULLET_OBJECT); i++){
					_S_BULLET_OBJECT *pObj = &gBulletObject[i];
					bullet_draw(pObj,&gScreenBuf[1]);
			}

			map_dump(&gScreenBuf[1],Default_Tilepalette);
			acc_tick = 0;
		}
	}
	return 0;
}
