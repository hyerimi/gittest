#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <stdio.h>
#include "../engine2d.h"

struct termios orig_termios;

void reset_terminal_mode()
{
	tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
	struct termios new_termios;

	/* take two copies - one for now, one for later */
	tcgetattr(0, &orig_termios);
	memcpy(&new_termios, &orig_termios, sizeof(new_termios));

	/* register cleanup handler, and set the new terminal mode */
	atexit(reset_terminal_mode);
	cfmakeraw(&new_termios);
	tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit()
{
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return select(1, &fds, NULL, NULL, &tv);
}

int getch()
{
	int r;
	unsigned char c;
	if ((r = read(0, &c, sizeof(c))) < 0) {
		return r;
	} else {
		return c;
	}
}

int main()
{
	set_conio_terminal_mode();
	int nCount=0;
	int bLoop=1;
	int xpos,ypos;
	xpos = 0;ypos = 1;
	char cmd;
	while(bLoop) {
//		scanf("%c", &cmd);
		if(kbhit() != 0) {
			cmd = getch();
			switch(cmd) {
				case 'u' :
				ypos -=1;
				break;
				case 'd' :
				ypos +=1;
				break;
				case 'r' :
				xpos +=1;
				break;
				case 'l' :
				xpos -=1;
				break;
				case 'q' :
				bLoop = 0;
				break;
			}
			printf("%d \r\n",(int)cmd);
		}
		
		printf("%d \r",nCount);
		nCount++;
		nCount %=10;
		
		system("clear");
		drawMyBox(3+xpos,3+ypos,44,5);
		drawMyBox(5+xpos,1+ypos,43,1);
		drawMyBox(2+xpos,3+ypos,43,0);
		drawMyBox(2+xpos,4+ypos,43,0);
		drawMyBox(2+xpos,5+ypos,43,0);
		drawMyBox(2+xpos,6+ypos,43,0);
		drawMyBox(9+xpos,3+ypos,43,0);
		drawMyBox(9+xpos,4+ypos,43,0);
		drawMyBox(9+xpos,5+ypos,43,0);
		drawMyBox(9+xpos,6+ypos,43,0);
		drawMyBox(4+xpos,9+ypos,41,0);
		drawMyBox(4+xpos,10+ypos,41,0);
		drawMyBox(4+xpos,11+ypos,41,0);
		drawMyBox(4+xpos,12+ypos,41,0);
		drawMyBox(7+xpos,9+ypos,41,0);
		drawMyBox(7+xpos,10+ypos,41,0);
		drawMyBox(7+xpos,11+ypos,41,0);
		drawMyBox(7+xpos,12+ypos,41,0);
		drawMyBox(4+xpos,5+ypos,41,0);
		drawMyBox(5+xpos,6+ypos,41,0);
		drawMyBox(6+xpos,5+ypos,41,0);
		drawMyBox(nCount,5,42,3);
		gotoxy(0,20);
		printf("------------------------------------------------");

	}

	reset_terminal_mode();
	return 0;
}
