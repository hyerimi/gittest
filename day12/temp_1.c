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

#include "plane.h"
#include "bullet.h"

struct timespec work_timer;
double acc_tick, last_tick;
int bLoop = 1;
int xpos, ypos;

_S_MAP_OBJECT gScreenBuffer;
_S_MAP_OBJECT gMap;
_S_MAP_OBJECT planeObj;
_S_MAP_OBJECT gF22bullet;

//게임오브젝트 선언
_S_Plane gPlayerPlane;
_S_BULLET_OBJECT g_bullets[32];

int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	system("clear");
	map_init(&gScreenBuffer);
	map_new(&gScreenBuffer,35,16);
	
	map_init(&gMap);
	map_new(&gMap,35,16);

	map_init(&planeObj);
	map_load(&planeObj,"plane1.dat");
	xpos = 17; ypos = 10; 	
	
	map_init(&gF22bullet);
	map_load(&gF22bullet,"bullet.dat");

	Plane_init(&gPlayerPlane,&planeObj,17,10);
	
	for(int i=0; i< sizeof(g_bullets)/sizeof(_S_BULLET_OBJECT); i++)
	{
		bullet_init(&g_bullets[i],0,0,0,&gF22bullet); //중요
	}

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
				for(int i=0; i<sizeof(g_bullets)/sizeof(_S_BULLET_OBJECT); i++) {
					_S_BULLET_OBJECT *pObj = &g_bullets[i];
					if(pObj->m_nFSM == 0) { //슬립상태라면...
						bullet_fire(pObj,gPlayerPlane.m_nXpos,gPlayerPlane.m_nYpos,10,5.0);
						break;
					}
				}

			}
			Plane_Apply(&gPlayerPlane,delta_tick,ch);

		}
		for(int i=0; i<sizeof(g_bullets)/sizeof(_S_BULLET_OBJECT); i++) {
			_S_BULLET_OBJECT *pObj = &g_bullets[i];
			bullet_apply(pObj,delta_tick);
		}

		//타이밍계산
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			
			map_drawTile(&gMap,0,0,&gScreenBuffer);//맵클리어
			//map_drawTile_trn(&planeObj,xpos,ypos,&gScreenBuffer);
			Plane_Draw(&gPlayerPlane,&gScreenBuffer);
			for(int i=0; i<sizeof(g_bullets)/sizeof(_S_BULLET_OBJECT); i++) {
				_S_BULLET_OBJECT *pObj = &g_bullets[i];
				bullet_draw(pObj,&gScreenBuffer);
			}

			gotoxy(0,0);
			puts("-----------------------------------\r");
			map_dump(&gScreenBuffer,Default_Tilepalette);
			puts("-----------------------------------\r");

			puts("move : w,a,s,d \r");
			puts("fire : j \r");
			puts("quit : q \r");
			acc_tick = 0;
		}
	}
	return 0;
}
