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
#include "game.h"

/*
struct timespec work_timer;
double acc_tick, last_tick, fire_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[3];

_S_MAP_OBJECT gPlayerModel;
_S_MAP_OBJECT gBulletModel;
_S_MAP_OBJECT gAlienModel;

_S_Plane gPlayerObject;
_S_BULLET_OBJECT gBulletObjects[6];
_S_ALIEN_OBJECT gAlienObjects[6];
*/

int main()
{



	/*for(int i=0; i<2; i++)
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
*/

	while(bLoop) {
	    if(nFSM == 0)
	    {
	        switch(nStep) {
    		    case 0:
    		        game_init();
    			    puts(">>>Press any key to start<<< (exit : press 'q')");
    			    nStep = 1;
    			    break;
    		    case 1:
    			    //사용자 입력처리

    			    if(kbhit() != 0) {
    			        if(nStep == 1){
    			            system("clear");
    		            }
    				    char ch = getch();
    				    nFSM = 1;
    				    nStep = 0;
                        if(ch == 'q') {
							nFSM = 0;
							bLoop = 0;
                            puts("====== Bye Bye ~ \r");
                        }
    			    }
    			    break;
    		}
    	}
    	else if(nFSM == 1)
    	{
    	    game_play();
    	}
    }
    return 0;
}
