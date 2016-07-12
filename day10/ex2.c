#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include "../engine/engine2d.h"

void putTile(int ey, int sy, int ex, int sx, 
				int width, char *ptrBuf)
{

	int ix, iy;
	for(iy=ey; iy<sy; iy++) {
		for(ix=ex; ix<sx; ix++) {
			if(pstr[ (iy*8) +ix ] ==0) {
				putchar('.');
			}
			else {
				putchar('@');
			}
		}
		printf("\r\n");
	}

}
struct timespec work_timer;
double acc_tick, last_tick;
int nCount = 0;
int main() {
	set_conio_terminal_mode();
	acc_tick = 0;
	last_tick = 0;
	//putTile(6,10,4,8,pstr);
	int bLoop = 1;
	while(bLoop) {
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
			}

		}

		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec +
			(double)(work_timer.tv_nsec *1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		acc_tick += delta_tick;
		if(acc_tick > 1.0) {
			acc_tick = 0;
			nCount++;
			system("clear");
			putTile(nCount,nCount+4,0,8,8,pstr);


				//printf("%d \r\n", nCount);
				

		}
	}
}


