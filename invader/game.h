#ifndef __GAME_H__
#define __GAME_H__

struct timespec work_timer;
double acc_tick, last_tick, fire_tick;
int bLoop = 1;
int nFSM = 0;
int nStep = 0;

_S_MAP_OBJECT gScreenBuf[3];

_S_MAP_OBJECT gPlayerModel;
_S_MAP_OBJECT gBulletModel;
_S_MAP_OBJECT gAlienModel;

_S_Plane gPlayerObject;
_S_BULLET_OBJECT gBulletObjects[6];
_S_ALIEN_OBJECT gAlienObjects[6];

void game_init()
{
	for(int i=0; i<2; i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],40,24);
	}

	map_init(&gScreenBuf[2]);
    map_load(&gScreenBuf[2],"ending.dat");

	map_init(&gPlayerModel);
	map_load(&gPlayerModel,"plane1.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

    system("clear");

	double TablePosition[] = {0,5,10,15,20,25};

	for(int i=0; i<6; i++)
	{
		_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos =TablePosition[i];
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

}

void game_play()
{
clock_gettime(CLOCK_MONOTONIC,&work_timer);
 		double cur_tick = work_timer.tv_sec +
 			(double)(work_timer.tv_nsec * 1e-9);
 		double delta_tick = cur_tick - last_tick;
 		last_tick = cur_tick;
    if(kbhit() != 0) {
		char ch = getch();
        if(ch == 'q') {
            nFSM = 0;
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
        fire_tick += delta_tick;
        		if(fire_tick > 0.1) {
        			double vx, vy, c;
        			for(int i=0; i<6; i++)
        			{
        				_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
        				vx = gPlayerObject.m_fXpos - pObj->m_fXpos;
        				vy = gPlayerObject.m_fYpos - pObj->m_fYpos;
        				c = sqrt(vx*vx + vy*vy);
        				vx /= c;
        				vy /= c;
        				for(int i=0; i<6; i++) {
        					_S_BULLET_OBJECT *pObj = &gBulletObjects[i];
        					if(pObj->m_nFSM == 0) {
        						pObj->pfFire(&gBulletObjects[i],gAlienObjects[i].m_fXpos,gAlienObjects[i].m_fYpos,10.0,vx,vy,5.0);
        						break;
        					}
        				}
        			}
        		}
            for(int i=0;i<6;i++) {
			    if(gBulletObjects[i].m_nFSM != 0)
                {
                    double bullet_pos_x = gBulletObjects[i].m_fXpos;
                    double bullet_pos_y = gBulletObjects[i].m_fYpos;

                    double target_pos_x = gPlayerObject.m_fXpos;
                    double target_pos_y = gPlayerObject.m_fYpos;

                    double vx = target_pos_x - bullet_pos_x;
                    double vy = target_pos_y - bullet_pos_y;
                    double dist = sqrt(vx*vx + vy*vy);

                    if(gBulletObjects[i].m_nFSM != 0) {
                        if(dist < 1.0) {
                            bLoop = 0;
                            system("clear");
                            map_dump(&gScreenBuf[2],Default_Tilepalete);
                            sleep(2);
                            bLoop = 1;
                            nFSM = 0;
                            nStep = 0;

                        }
                    }
                }
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
            	//gBulletObjects[i].pfDraw(pObj,&gScreenBuf[1]);
				gBulletObjects->pfDraw(pObj,&gScreenBuf[1]);
            }

			for(int i=0; i<6; i++) {
				_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			}
			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

}

#endif
