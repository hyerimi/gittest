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

int main()
{
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
